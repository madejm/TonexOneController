/* Local-browser test support. This directory is intentionally absent from the
 * ESP-IDF EMBED_FILES list, so it is never included in pedal firmware. */
(function () {
    if (!new URLSearchParams(window.location.search).has('test')) {
        return;
    }

    'use strict';

    const TONEX_GLOBAL_LAST = 118;
    const INT_FS_COUNT = 4;
    const EXT_FS_COUNT = 9;
    const presetNames = Array.from({length: 20}, (_, index) => `Test preset ${index + 1}`);
    const backups = [
        {slot: 0, name: 'Clean Test Rig', character: 'Clean', type: 'Compressor', amp: 'Blackface', cab: '1x12'},
        {slot: 1, name: 'Drive Test Rig', character: 'Crunch', type: 'Overdrive', amp: 'British 800', cab: '4x12'}
    ];
    const state = {
        preset: 0,
        parameters: Object.fromEntries(Array.from({length: TONEX_GLOBAL_LAST}, (_, index) => [index, {
            Val: 0, Min: 0, Max: 100, NAME: `Test parameter ${index}`
        }]))
    };
    const config = {
        CMD: 'GETCONFIG', BT_MODE: 0, BT_CHOC_EN: 0, BT_MD1_EN: 0, BT_CUST_EN: 0,
        BT_CUST_NAME: 'TONEX ONE', BT_PERIPH_NAME: 'TONEX ONE', TOGGLE_BYPASS: 0,
        LOOP_AROUND: 0, S_MIDI_EN: 0, S_MIDI_CH: 1, FOOTSW_MODE: 0, BT_MIDI_CC: 0,
        WIFI_MODE: 0, WIFI_POWER: 0, WIFI_SSID: '', WIFI_PW: '', MDNS_NAME: 'tonex-one',
        SCREEN_ROT: 0, PRESET_SLOT: 0, HIGH_TCH_SNS: 0, DISABLE_BPM: 0,
        EXTFS_PS_LAYOUT: 0, PRESET_ORDER: Array.from({length: 20}, (_, index) => index),
        PRESET_COLORS: Array.from({length: 20}, () => '#303030'),
        PC_MAP: Array.from({length: 128}, () => 0)
    };

    for (let index = 1; index <= EXT_FS_COUNT; index++) {
        Object.assign(config, {
            [`EXTFS_ES${index}_SW`]: 0, [`EXTFS_ES${index}_CC`]: 255,
            [`EXTFS_ES${index}_V1`]: 0, [`EXTFS_ES${index}_V2`]: 0,
            [`EXTFS_ES${index}_CC_ALT`]: 255, [`EXTFS_ES${index}_V1_ALT`]: 0,
            [`EXTFS_ES${index}_V2_ALT`]: 0
        });
    }
    for (let index = 1; index <= INT_FS_COUNT; index++) {
        Object.assign(config, {
            [`INTFS_ES${index}_SW`]: 0, [`INTFS_ES${index}_CC`]: 255,
            [`INTFS_ES${index}_V1`]: 0, [`INTFS_ES${index}_V2`]: 0,
            [`INTFS_ES${index}_CC_ALT`]: 255, [`INTFS_ES${index}_V1_ALT`]: 0,
            [`INTFS_ES${index}_V2_ALT`]: 0
        });
    }

    const jsonResponse = body => new Response(JSON.stringify(body), {
        headers: {'Content-Type': 'application/json'}
    });

    const originalFetch = window.fetch.bind(window);
    window.fetch = (input, options = {}) => {
        const url = new URL(typeof input === 'string' ? input : input.url, window.location.href);
        if (url.pathname !== '/api/preset-backups') return originalFetch(input, options);

        const method = (options.method || 'GET').toUpperCase();
        const slot = url.searchParams.get('slot');
        if (method === 'GET' && slot === null) return Promise.resolve(jsonResponse({backups}));
        if (method === 'GET') {
            const backup = backups.find(item => item.slot === Number(slot));
            if (!backup || !backup.fullDetails) {
                return Promise.resolve(new Response(
                    'Import a TXP first to create an exportable test backup.', {status: 404}));
            }
            return Promise.resolve(new Response(backup.fullDetails));
        }
        if (method === 'POST') {
            const nextSlot = backups.reduce((maximum, backup) => Math.max(maximum, backup.slot), -1) + 1;
            backups.push({slot: nextSlot, name: `Imported test preset ${nextSlot + 1}`,
                character: 'Imported', type: '', amp: '', cab: '', fullDetails: options.body});
            return Promise.resolve(jsonResponse({slot: nextSlot}));
        }
        if (method === 'DELETE') {
            const index = backups.findIndex(backup => backup.slot === Number(slot));
            if (index < 0) return Promise.resolve(new Response('Backup not found.', {status: 404}));
            backups.splice(index, 1);
            return Promise.resolve(jsonResponse({}));
        }
        return Promise.resolve(new Response('Unsupported test backup request.', {status: 405}));
    };

    class TestWebSocket {
        constructor() {
            this.readyState = TestWebSocket.CONNECTING;
            setTimeout(() => {
                this.readyState = TestWebSocket.OPEN;
                if (this.onopen) this.onopen({});
            }, 0);
        }

        send(payload) {
            const request = JSON.parse(payload);
            const emit = response => setTimeout(() => {
                if (this.onmessage) this.onmessage({data: JSON.stringify(response)});
            }, 0);
            switch (request.CMD) {
                    case 'GETMODELLERDATA':
                        emit({CMD: 'GETMODELLERDATA', MAX_PRESETS: 20, START_PRESET: 1,
                            MODELLER_TYPE: AMP_MODELLER_TONEX_ONE, HARDWARE_PLATFORM: 0});
                        break;
                    case 'GETSYNCCOMPLETE': emit({CMD: 'GETSYNCCOMPLETE', SYNC: 1}); break;
                    case 'GETCONFIG': emit(config); break;
                    case 'GETPRESETNAMES':
                        emit({CMD: 'GETPRESETNAMES', PRESET_NAMES: Object.fromEntries(presetNames.entries())});
                        break;
                    case 'GETPARAMS': emit({CMD: 'GETPARAMS', ALL: Boolean(request.ALL), PARAMS: state.parameters}); break;
                    case 'GETPRESET': emit({CMD: 'GETPRESET', INDEX: state.preset}); break;
                    case 'SETPRESET': state.preset = request.PRESET; emit({CMD: 'GETPRESET', INDEX: state.preset}); break;
                    case 'SETPARAM': if (state.parameters[request.INDEX]) state.parameters[request.INDEX].Val = request.VALUE; break;
                    case 'SETCONFIG':
                    case 'SETWIFI': Object.assign(config, request); break;
                    case 'SETPRESETORDER': config.PRESET_ORDER = request.PRESET_ORDER; break;
                    case 'SETPCMAP': config.PC_MAP = request.MAP; break;
            }
        }

        close() {
            this.readyState = TestWebSocket.CLOSED;
            if (this.onclose) this.onclose({});
        }
    }

    TestWebSocket.CONNECTING = 0;
    TestWebSocket.OPEN = 1;
    TestWebSocket.CLOSED = 3;
    window.WebSocket = TestWebSocket;
}());
