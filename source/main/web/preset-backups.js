function presetBackupStatus(message) {
    document.getElementById('preset-backup-status').textContent = message;
}

let presetBackupImportBusy = false;
let presetBackupImportProgressHideTimer;

function showPresetBackupImportProgress() {
    const container = document.getElementById('preset-backup-import-progress-container');
    clearTimeout(presetBackupImportProgressHideTimer);
    container.hidden = false;
    requestAnimationFrame(() => container.classList.add('is-visible'));
}

function hidePresetBackupImportProgress() {
    const container = document.getElementById('preset-backup-import-progress-container');
    clearTimeout(presetBackupImportProgressHideTimer);
    presetBackupImportProgressHideTimer = setTimeout(() => {
        container.classList.remove('is-visible');
        presetBackupImportProgressHideTimer = setTimeout(() => {
            container.hidden = true;
        }, 300);
    }, 2000);
}

function setPresetBackupImportProgress(completed, total) {
    const progress = document.getElementById('preset-backup-import-progress');
    const percent = total === 0 ? 0 : Math.round((completed * 100) / total);
    progress.style.width = `${percent}%`;
    progress.textContent = `${percent}%`;
    progress.parentElement.setAttribute('aria-valuenow', percent);
}

async function importPresetBackupFiles(files) {
    if (presetBackupImportBusy) return;
    const txpFiles = Array.from(files).filter(file => /\.txp$/i.test(file.name));
    if (txpFiles.length === 0) {
        presetBackupStatus('Select one or more .txp files.');
        return;
    }

    presetBackupImportBusy = true;
    document.getElementById('preset-backup-import-button').disabled = true;
    showPresetBackupImportProgress();
    setPresetBackupImportProgress(0, txpFiles.length);
    let processed = 0;
    let saved = 0;
    const failures = [];
    try {
        for (const file of txpFiles) {
            try {
                if (file.size === 0 || file.size > 40000) throw new Error('Unsupported TXP size.');
                presetBackupStatus(`Importing ${file.name} (${processed + 1}/${txpFiles.length})…`);
                const fullDetails = TonexTXP.convert(await file.text(), 0);
                const response = await fetch('/api/preset-backups', {
                    method: 'POST',
                    headers: {'Content-Type': 'application/octet-stream'},
                    body: fullDetails,
                    cache: 'no-store'
                });
                if (!response.ok) throw new Error(await response.text());
                await response.json();
                saved++;
            } catch (error) {
                failures.push(`${file.name}: ${error.message}`);
            } finally {
                processed++;
                setPresetBackupImportProgress(processed, txpFiles.length);
            }
        }
        await refreshPresetBackups();
        presetBackupStatus(failures.length === 0 ?
            `Imported ${saved} preset backup${saved === 1 ? '' : 's'}.` :
            `Imported ${saved}/${txpFiles.length}. ${failures.join(' ')}`);
    } finally {
        presetBackupImportBusy = false;
        document.getElementById('preset-backup-import-button').disabled = false;
        hidePresetBackupImportProgress();
    }
}

function setupPresetBackupImportControls() {
    const input = document.getElementById('preset-backup-import-input');
    const button = document.getElementById('preset-backup-import-button');
    const list = document.getElementById('preset-backup-list');
    if (!input || !button || !list || list.dataset.importControlsReady) return;
    list.dataset.importControlsReady = 'true';
    button.onclick = () => {
        input.value = '';
        input.click();
    };
    input.onchange = () => importPresetBackupFiles(input.files);
    const isFileDrop = event => Array.from(event.dataTransfer?.types || []).includes('Files');
    list.addEventListener('dragover', event => {
        if (!isFileDrop(event)) return;
        event.preventDefault();
        if (!presetBackupImportBusy) list.classList.add('preset-drop-target');
    });
    list.addEventListener('dragleave', event => {
        if (!list.contains(event.relatedTarget)) list.classList.remove('preset-drop-target');
    });
    list.addEventListener('drop', event => {
        if (!isFileDrop(event)) return;
        event.preventDefault();
        list.classList.remove('preset-drop-target');
        importPresetBackupFiles(event.dataTransfer.files);
    });
}

function presetBackupDetail(label, value) {
    if (!value) return null;
    const item = document.createElement('div');
    item.className = 'small text-secondary';
    item.textContent = `${label}: ${value}`;
    return item;
}

async function exportPresetBackup(backup) {
    try {
        presetBackupStatus(`Creating ${backup.name || 'preset'}.txp…`);
        const response = await fetch(`/api/preset-backups?slot=${backup.slot}`, {cache: 'no-store'});
        if (!response.ok) throw new Error(await response.text());
        const txp = TonexTXP.exportFile(new Uint8Array(await response.arrayBuffer()));
        const link = document.createElement('a');
        link.href = URL.createObjectURL(new Blob([txp], {type: 'application/octet-stream'}));
        link.download = `${(backup.name || 'preset').replace(/[\\/:*?"<>|]/g, '_')}.txp`;
        link.click();
        setTimeout(() => URL.revokeObjectURL(link.href), 0);
        presetBackupStatus(`Exported ${link.download}.`);
    } catch (error) {
        presetBackupStatus(error.message);
        alert(error.message);
    }
}

async function deletePresetBackup(backup) {
    if (!window.confirm(`Delete backup “${backup.name || 'preset'}”?`)) return;
    try {
        const response = await fetch(`/api/preset-backups?slot=${backup.slot}`, {
            method: 'DELETE', cache: 'no-store'
        });
        if (!response.ok) throw new Error(await response.text());
        presetBackupStatus(`Deleted ${backup.name || 'preset'}.`);
        await refreshPresetBackups();
    } catch (error) {
        presetBackupStatus(error.message);
        alert(error.message);
    }
}

function createPresetBackupRow(backup) {
    const row = document.createElement('div');
    row.className = 'row align-items-center border-bottom py-2';

    const details = document.createElement('div');
    details.className = 'col';
    const name = document.createElement('div');
    name.className = 'fw-semibold';
    name.textContent = backup.name || 'Unnamed preset';
    details.appendChild(name);
    for (const [label, value] of [['Character', backup.character], ['Type', backup.type],
                                  ['Amp', backup.amp], ['Cab', backup.cab]]) {
        const detail = presetBackupDetail(label, value);
        if (detail) details.appendChild(detail);
    }

    const menuContainer = document.createElement('div');
    menuContainer.className = 'col-auto dropdown';
    const menuButton = document.createElement('button');
    menuButton.className = 'btn btn-dark dropdown-toggle';
    menuButton.type = 'button';
    menuButton.textContent = '...';
    menuButton.setAttribute('data-bs-toggle', 'dropdown');
    menuButton.setAttribute('aria-expanded', 'false');
    const menu = document.createElement('ul');
    menu.className = 'dropdown-menu dropdown-menu-end';
    const exportButton = document.createElement('button');
    exportButton.className = 'dropdown-item';
    exportButton.type = 'button';
    exportButton.textContent = 'Export as TXP';
    exportButton.onclick = () => exportPresetBackup(backup);
    const deleteButton = document.createElement('button');
    deleteButton.className = 'dropdown-item text-danger';
    deleteButton.type = 'button';
    deleteButton.textContent = 'Delete';
    deleteButton.onclick = () => deletePresetBackup(backup);
    for (const button of [exportButton, deleteButton]) {
        const item = document.createElement('li');
        item.appendChild(button);
        menu.appendChild(item);
    }
    menuContainer.append(menuButton, menu);
    row.append(details, menuContainer);
    menuButton.dropdown = new bootstrap.Dropdown(menuButton);
    return row;
}

async function refreshPresetBackups() {
    const list = document.getElementById('preset-backup-list');
    if (!list) return;
    setupPresetBackupImportControls();
    presetBackupStatus('Loading backups…');
    try {
        const response = await fetch('/api/preset-backups', {cache: 'no-store'});
        if (!response.ok) throw new Error(await response.text());
        const {backups} = await response.json();
        list.replaceChildren(...backups.map(createPresetBackupRow));
        if (backups.length === 0) {
            const empty = document.createElement('p');
            empty.className = 'text-secondary';
            empty.textContent = 'No preset backups yet.';
            list.appendChild(empty);
        }
        presetBackupStatus('');
    } catch (error) {
        list.replaceChildren();
        presetBackupStatus(error.message);
    }
}
