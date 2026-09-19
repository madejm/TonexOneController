/* TONEX version-3 TXP import. No external runtime dependencies.
 * Port of TonexTXPConversion.swift, recovered from TONEX Editor 1.13.1.
 * Produces a full-preset BODY; ESP32 supplies the USB header, CRC and framing.
 */
const TonexTXP = (() => {
    "use strict";
    // Standard Blowfish P-array and S-boxes: fractional hexadecimal digits of pi.
    const initialHex =
        "243f6a8885a308d313198a2e03707344a4093822299f31d0082efa98ec4e6c89452821e638d01377be5466cf34e90c6cc0ac29b7c97c50dd3f84d5b5b5470917" +
        "9216d5d98979fb1bd1310ba698dfb5ac2ffd72dbd01adfb7b8e1afed6a267e96ba7c9045f12c7f9924a19947b3916cf70801f2e2858efc16636920d871574e69" +
        "a458fea3f4933d7e0d95748f728eb658718bcd5882154aee7b54a41dc25a59b59c30d5392af26013c5d1b023286085f0ca417918b8db38ef8e79dcb0603a180e" +
        "6c9e0e8bb01e8a3ed71577c1bd314b2778af2fda55605c60e65525f3aa55ab945748986263e8144055ca396a2aab10b6b4cc5c341141e8cea15486af7c72e993" +
        "b3ee1411636fbc2a2ba9c55d741831f6ce5c3e169b87931eafd6ba336c24cf5c7a325381289586773b8f48986b4bb9afc4bfe81b6628219361d809ccfb21a991" +
        "487cac605dec8032ef845d5de98575b1dc262302eb651b8823893e81d396acc50f6d6ff383f442392e0b4482a484200469c8f04a9e1f9b5e21c66842f6e96c9a" +
        "670c9c61abd388f06a51a0d2d8542f68960fa728ab5133a36eef0b6c137a3be4ba3bf0507efb2a98a1f1651d39af017666ca593e82430e888cee8619456f9fb4" +
        "7d84a5c33b8b5ebee06f75d885c12073401a449f56c16aa64ed3aa62363f77061bfedf72429b023d37d0d724d00a1248db0fead349f1c09b075372c980991b7b" +
        "25d479d8f6e8def7e3fe501ab6794c3b976ce0bd04c006bac1a94fb6409f60c45e5c9ec2196a246368fb6faf3e6c53b51339b2eb3b52ec6f6dfc511f9b30952c" +
        "cc814544af5ebd09bee3d004de334afd660f2807192e4bb3c0cba85745c8740fd20b5f39b9d3fbdb5579c0bd1a60320ad6a100c6402c7279679f25fefb1fa3cc" +
        "8ea5e9f8db3222f83c7516dffd616b152f501ec8ad0552ab323db5fafd23876053317b483e00df829e5c57bbca6f8ca01a87562edf1769dbd542a8f6287effc3" +
        "ac6732c68c4f5573695b27b0bbca58c8e1ffa35db8f011a010fa3d98fd2183b84afcb56c2dd1d35b9a53e479b6f84565d28e49bc4bfb9790e1ddf2daa4cb7e33" +
        "62fb1341cee4c6e8ef20cada36774c01d07e9efe2bf11fb495dbda4dae909198eaad8e716b93d5a0d08ed1d0afc725e08e3c5b2f8e7594b78ff6e2fbf2122b64" +
        "8888b812900df01c4fad5ea0688fc31cd1cff191b3a8c1ad2f2f2218be0e1777ea752dfe8b021fa1e5a0cc0fb56f74e818acf3d6ce89e299b4a84fe0fd13e0b7" +
        "7cc43b81d2ada8d9165fa2668095770593cc7314211a1477e6ad206577b5fa86c75442f5fb9d35cfebcdaf0c7b3e89a0d6411bd3ae1e7e4900250e2d2071b35e" +
        "226800bb57b8e0af2464369bf009b91e5563911d59dfa6aa78c14389d95a537f207d5ba202e5b9c5832603766295cfa911c819684e734a41b3472dca7b14a94a" +
        "1b5100529a532915d60f573fbc9bc6e42b60a47681e6740008ba6fb5571be91ff296ec6b2a0dd915b6636521e7b9f9b6ff34052ec585566453b02d5da99f8fa1" +
        "08ba47996e85076a4b7a70e9b5b32944db75092ec4192623ad6ea6b049a7df7d9cee60b88fedb266ecaa8c71699a17ff5664526cc2b19ee1193602a575094c29" +
        "a0591340e4183a3e3f54989a5b429d656b8fe4d699f73fd6a1d29c07efe830f54d2d38e6f0255dc14cdd20868470eb266382e9c6021ecc5e09686b3f3ebaefc9" +
        "3c9718146b6a70a1687f358452a0e286b79c5305aa5007373e07841c7fdeae5c8e7d44ec5716f2b8b03ada37f0500c0df01c1f040200b3ffae0cf51a3cb574b2" +
        "25837a58dc0921bdd19113f97ca92ff69432477322f547013ae5e58137c2dadcc8b576349af3dda7a94461460fd0030eecc8c73ea4751e41e238cd993bea0e2f" +
        "3280bba1183eb3314e548b384f6db9086f420d03f60a04bf2cb8129024977c795679b072bcaf89afde9a771fd9930810b38bae12dccf3f2e5512721f2e6b7124" +
        "501adde69f84cd877a5847187408da17bc9f9abce94b7d8cec7aec3adb851dfa63094366c464c3d2ef1c18473215d908dd433b3724c2ba1612a14d432a65c451" +
        "50940002133ae4dd71dff89e10314e5581ac77d65f11199b043556f1d7a3c76b3c11183b5924a509f28fe6ed97f1fbfa9ebabf2c1e153c6e86e34570eae96fb1" +
        "860e5e0a5a3e2ab3771fe71c4e3d06fa2965dcb999e71d0f803e89d65266c8252e4cc9789c10b36ac6150eba94e2ea78a5fc3c531e0a2df4f2f74ea7361d2b3d" +
        "1939260f19c279605223a708f71312b6ebadfe6eeac31f66e3bc4595a67bc883b17f37d1018cff28c332ddefbe6c5aa56558218568ab9802eecea50fdb2f953b" +
        "2aef7dad5b6e2f841521b62829076170ecdd4775619f151013cca830eb61bd960334fe1eaa0363cfb5735c904c70a239d59e9e0bcbaade14eecc86bc60622ca7" +
        "9cab5cabb2f3846e648b1eaf19bdf0caa02369b9655abb5040685a323c2ab4b3319ee9d5c021b8f79b540b19875fa09995f7997e623d7da8f837889a97e32d77" +
        "11ed935f166812810e358829c7e61fd696dedfa17858ba9957f584a51b2272639b83c3ff1ac24696cdb30aeb532e30548fd948e46dbc312858ebf2ef34c6ffea" +
        "fe28ed61ee7c3c735d4a14d9e864b7e342105d14203e13e045eee2b6a3aaabeadb6c4f15facb4fd0c742f442ef6abbb5654f3b1d41cd2105d81e799e86854dc7" +
        "e44b476a3d816250cf62a1f25b8d2646fc8883a0c1c7b6a37f1524c369cb749247848a0b5692b285095bbf00ad19489d1462b17423820e0058428d2a0c55f5ea" +
        "1dadf43e233f70613372f0928d937e41d65fecf16c223bdb7cde3759cbee74604085f2a7ce77326ea607808419f8509ee8efd85561d99735a969a7aac50c06c2" +
        "5a04abfc800bcadc9e447a2ec3453484fdd567050e1e9ec9db73dbd3105588cd675fda79e3674340c5c43465713e38d83d28f89ef16dff20153e21e78fb03d4a" +
        "e6e39f2bdb83adf7e93d5a68948140f7f64c261c94692934411520f77602d4f7bcf46b2ed4a20068d40824713320f46a43b7d4b7500061af1e39f62e97244546" +
        "14214f74bf8b88404d95fc1d96b591af70f4ddd366a02f45bfbc09ec03bd97857fac6dd031cb850496eb27b355fd3941da2547e6abca0a9a28507825530429f4" +
        "0a2c86dae9b66dfb68dc1462d7486900680ec0a427a18dee4f3ffea2e887ad8cb58ce0067af4d6b6aace1e7cd3375fecce78a399406b2a4220fe9e35d9f385b9" +
        "ee39d7ab3b124e8b1dc9faf74b6d185626a36631eae397b23a6efa74dd5b43326841e7f7ca7820fbfb0af54ed8feb397454056acba48952755533a3a20838d87" +
        "fe6ba9b7d096954b55a867bca1159a58cca9296399e1db33a62a4a563f3125f95ef47e1c9029317cfdf8e80204272f7080bb155c05282ce395c11548e4c66d22" +
        "48c1133fc70f86dc07f9c9ee41041f0f404779a45d886e17325f51ebd59bc0d1f2bcc18f41113564257b7834602a9c60dff8e8a31f636c1b0e12b4c202e1329e" +
        "af664fd1cad181156b2395e0333e92e13b240b62eebeb92285b2a20ee6ba0d99de720c8c2da2f728d012784595b794fd647d0862e7ccf5f05449a36f877d48fa" +
        "c39dfd27f33e8d1e0a476341992eff743a6f6eabf4f8fd37a812dc60a1ebddf8991be14cdb6e6b0dc67b55106d672c372765d43bdcd0e804f1290dc7cc00ffa3" +
        "b5390f92690fed0b667b9ffbcedb7d9ca091cf0bd9155ea3bb132f88515bad247b9479bf763bd6eb37392eb3cc1159798026e297f42e312d6842ada7c66a2b3b" +
        "12754ccc782ef11c6a124237b79251e706a1bbe64bfb63501a6b101811caedfa3d25bdd8e2e1c3c9444216590a121386d90cec6ed5abea2a64af674eda86a85f" +
        "bebfe98864e4c3fe9dbc8057f0f7c08660787bf86003604dd1fd8346f6381fb07745ae04d736fccc83426b33f01eab71b08041873c005e5f77a057bebde8ae24" +
        "55464299bf582e614e58f48ff2ddfda2f474ef388789bdc25366f9c3c8b38e74b475f25546fcd9b97aeb26618b1ddf84846a0e79915f95e2466e598e20b45770" +
        "8cd55591c902de4cb90bace1bb8205d011a862487574a99eb77f19b6e0a9dc09662d09a1c4324633e85a1f0209f0be8c4a99a0251d6efe101ab93d1d0ba5a4df" +
        "a186f20f2868f169dcb7da83573906fea1e2ce9b4fcd7f5250115e01a70683faa002b5c40de6d0279af88c27773f8641c3604c0661a806b5f0177a28c0f586e0" +
        "006058aa30dc7d6211e69ed72338ea6353c2dd94c2c21634bbcbee5690bcb6deebfc7da1ce591d766f05e4094b7c018839720a3d7c927c2486e3725f724d9db9" +
        "1ac15bb4d39eb8fced54557808fca5b5d83d7cd34dad0fc41e50ef5eb161e6f8a28514d96c51133c6fd5c7e756e14ec4362abfceddc6c837d79a323492638212" +
        "670efa8e406000e03a39ce37d3faf5cfabc277375ac52d1b5cb0679e4fa33742d382274099bc9bbed5118e9dbf0f7315d62d1c7ec700c47bb78c1b6b21a19045" +
        "b26eb1be6a366eb45748ab2fbc946e79c6a376d26549c2c8530ff8ee468dde7dd5730a1d4cd04dc62939bbdba9ba4650ac9526e8be5ee304a1fad5f06a2d519a" +
        "63ef8ce29a86ee22c089c2b843242ef6a51e03aa9cf2d0a483c061ba9be96a4d8fe51550ba645bd62826a2f9a73a3ae14ba99586ef5562e9c72fefd3f752f7da" +
        "3f046f6977fa0a5980e4a91587b086019b09e6ad3b3ee593e990fd5a9e34d7972cf0b7d9022b8b5196d5ac3a017da67dd1cf3ed67c7d2d281f9f25cfadf2b89b" +
        "5ad6b4725a88f54ce029ac71e019a5e647b0acfded93fa9be8d3c48d283b57ccf8d5662979132e28785f0191ed756055f7960e44e3d35e8c15056dd488f46dba" +
        "03a161250564f0bdc3eb9e153c9057a297271aeca93a072a1b3f6d9b1e6321f5f59c66fb26dcf3197533d928b155fdf5035634828aba3cbb28517711c20ad9f8" +
        "abcc5167ccad925f4de817513830dc8e379d58629320f991ea7a90c2fb3e7bce5121ce64774fbe32a8b6e37ec3293d4648de53696413e680a2ae0810dd6db224" +
        "69852dfd09072166b39a460a6445c0dd586cdecf1c20c8ae5bbef7dd1b588d40ccd2017f6bb4e3bbdda26a7e3a59ff453e350a44bcb4cdd572eacea8fa6484bb" +
        "8d6612aebf3c6f47d29be463542f5d9eaec2771bf64e6370740e0d8de75b1357f8721671af537d5d4040cb084eb4e2cc34d2466a0115af84e1b0042895983a1d" +
        "06b89fb4ce6ea0486f3f3b823520ab82011a1d4b277227f8611560b1e7933fdcbb3a792b344525bda08839e151ce794b2f32c9b7a01fbac9e01cc87ebcc7d1f6" +
        "cf0111c3a1e8aac71a908749d44fbd9ad0dadecbd50ada380339c32ac69136678df9317ce0b12b4ff79e59b743f5bb3af2d519ff27d9459cbf97222c15e6fc2a" +
        "0f91fc719b941525fae59361ceb69cebc2a8645912baa8d1b6c1075ee3056a0c10d25065cb03a442e0ec6e0e1698db3b4c98a0be3278e9649f1f9532e0d392df" +
        "d3a0342b8971f21e1b0a74414ba3348cc5be7120c37632d8df359f8d9b992f2ee60b6f470fe3f11de54cda541edad891ce6279cfcd3e7e6f1618b166fd2c1d05" +
        "848fd2c5f6fb2299f523f357a632762393a8353156cccd02acf081625a75ebb56e16369788d273ccde96629281b949d04c50901b71c65614e6c6c7bd327a140a" +
        "45e1d006c3f27b9ac9aa53fd62a80f00bb25bfe235bdd2f671126905b2040222b6cbcf7ccd769c2b53113ec01640e3d338abbd602547adf0ba38209cf746ce76" +
        "77afa1c52075606085cbfe4e8ae88dd87aaaf9b04cf9aa7e1948c25c02fb8a8c01c36ae4d6ebe1f990d4f869a65cdea03f09252dc208e69fb74e6132ce77e25b" +
        "578fdfe33ac372e6";
    // USB order. TXP word 97 is unused; integer words need numeric float conversion.
    const parameterRules = [
        ["integer", 19, 1],
        ["integer", 20, 1],
        ["real", 21, -100, 0],
        ["real", 22, 5, 500],
        ["real", 23, -100, -20],
        ["integer", 14, 1],
        ["integer", 15, 1],
        ["real", 16, -40, 0],
        ["real", 17, -30, 10],
        ["real", 18, 1, 51],
        ["integer", 6, 1],
        ["real", 7, 0, 10],
        ["real", 8, 75, 600],
        ["real", 9, 0, 10],
        ["real", 10, 0.2, 3],
        ["real", 11, 150, 5000],
        ["real", 12, 0, 10],
        ["real", 13, 1000, 4000],
        ["integer", 0, 1],
        ["modelSwitch"],
        ["real", 2, 0, 10],
        ["real", 3, 0, 10],
        ["real", 1, 0, 100],
        ["constant", 1],
        ["integer", 98, 2],
        ["integer", 99, 39],
        ["real", 107, 0, 10],
        ["integer", 100, 2],
        ["real", 101, 0, 10],
        ["real", 102, 0, 10],
        ["integer", 103, 2],
        ["real", 104, 0, 10],
        ["real", 105, 0, 10],
        ["real", 106, -100, 100],
        ["real", 4, 0, 10],
        ["real", 5, 0, 10],
        ["integer", 24, 1],
        ["integer", 25, 1],
        ["integer", 26, 5],
        ["real", 27, 0, 10],
        ["real", 28, 0, 500],
        ["real", 29, -10, 10],
        ["real", 30, 0, 100],
        ["real", 31, 0, 10],
        ["real", 32, 0, 500],
        ["real", 33, -10, 10],
        ["real", 34, 0, 100],
        ["real", 35, 0, 10],
        ["real", 36, 0, 500],
        ["real", 37, -10, 10],
        ["real", 38, 0, 100],
        ["real", 39, 0, 10],
        ["real", 40, 0, 500],
        ["real", 41, -10, 10],
        ["real", 42, 0, 100],
        ["real", 43, 0, 10],
        ["real", 44, 0, 500],
        ["real", 45, -10, 10],
        ["real", 46, 0, 100],
        ["real", 47, 0, 10],
        ["real", 48, 0, 500],
        ["real", 49, -10, 10],
        ["real", 50, 0, 100],
        ["integer", 51, 1],
        ["integer", 52, 1],
        ["integer", 53, 4],
        ["integer", 54, 1],
        ["integer", 55, 17],
        ["real", 56, 0.1, 10],
        ["real", 57, 0, 100],
        ["real", 58, 0, 10],
        ["integer", 59, 1],
        ["integer", 60, 17],
        ["real", 61, 0.1, 10],
        ["real", 62, 0, 10],
        ["real", 63, 0, 100],
        ["real", 64, 0, 10],
        ["integer", 65, 1],
        ["integer", 66, 17],
        ["real", 67, 0.1, 10],
        ["real", 68, 0, 100],
        ["real", 69, 0, 10],
        ["integer", 70, 1],
        ["integer", 71, 17],
        ["real", 72, 0.1, 10],
        ["real", 73, 0, 100],
        ["real", 74, 0, 100],
        ["real", 75, 0, 10],
        ["integer", 76, 1],
        ["integer", 77, 17],
        ["real", 78, 0, 400],
        ["real", 79, 0, 300],
        ["real", 80, 0, 100],
        ["real", 81, 0, 10],
        ["integer", 82, 1],
        ["integer", 83, 1],
        ["integer", 84, 1],
        ["integer", 85, 1],
        ["integer", 86, 17],
        ["real", 87, 0, 1000],
        ["real", 88, 0, 100],
        ["integer", 89, 1],
        ["real", 90, 0, 100],
        ["integer", 91, 1],
        ["integer", 92, 17],
        ["real", 93, 0, 1000],
        ["real", 94, 0, 100],
        ["integer", 95, 1],
        ["real", 96, 0, 100],
    ];
    const word = (bytes, offset) => new DataView(bytes.buffer, bytes.byteOffset, bytes.byteLength).getUint32(offset, true);
    const real = (bytes, offset) => new DataView(bytes.buffer, bytes.byteOffset, bytes.byteLength).getFloat32(offset, true);
    const le = value => [value & 255, (value >>> 8) & 255, (value >>> 16) & 255, value >>> 24];
    const byte = value => value < 128 ? [value] : [0x80, value];
    const list = (tag, values) => [tag, values.length, ...values.flat()];
    const blob = bytes => [0xBC, ...(bytes.length < 128 ? [bytes.length] : [0x81, bytes.length & 255, bytes.length >>> 8]), ...bytes];
    function float(value) {
        const bytes = new Uint8Array(4);
        new DataView(bytes.buffer).setFloat32(0, value, true);
        return [0x88, ...bytes];
    }
    function bounded(value, minimum, maximum) {
        if (Number.isNaN(value)) throw new Error("Invalid TXP parameter (NaN).");
        return Math.min(Math.max(value, minimum), maximum);
    }
    function string(bytes, offset, capacity) {
        const content = new Uint8Array(capacity);
        let length = 0;
        while (length < capacity - 1 && bytes[offset + length] !== 0) {
            content[length] = bytes[offset + length];
            length++;
        }
        return {content, length};
    }
    function detail(bytes, offset, capacity) {
        const {content, length} = string(bytes, offset, capacity);
        return list(0xB9, [blob(content), byte(length)]);
    }

    function decrypt(text) {
        if (text.endsWith("\0")) text = text.slice(0, -1);
        const dot = text.indexOf(".");
        // Version 3 is exactly 29,829 plaintext bytes plus three padding bytes.
        if (dot < 1 || !/^\d+$/.test(text.slice(0, dot)) || Number(text.slice(0, dot)) !== 29832) {
            throw new Error("Unsupported TXP size; only version-3 presets are supported.");
        }
        const encoded = text.slice(dot + 1);
        if (encoded.length !== 39776) throw new Error("Invalid TXP encoded length.");
        const alphabet = ".ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+";
        const decoded = new Uint8Array(29832);
        let bits = 0, bitCount = 0, cursor = 0;
        for (const character of encoded) {
            const value = alphabet.indexOf(character);
            if (value < 0) throw new Error("Invalid TXP encoding.");
            bits |= value << bitCount;
            bitCount += 6;
            if (bitCount >= 8) {
                decoded[cursor++] = bits & 255;
                bits >>>= 8;
                bitCount -= 8;
            }
        }

        const state = Uint32Array.from(initialHex.match(/.{8}/g), hex => parseInt(hex, 16));
        const p = state.subarray(0, 18), s = state.subarray(18);
        const f = x => ((((s[x >>> 24] + s[256 + ((x >>> 16) & 255)]) >>> 0) ^ s[512 + ((x >>> 8) & 255)]) + s[768 + (x & 255)]) >>> 0;
        function block(left, right, decrypting) {
            for (let round = 0; round < 16; round++) {
                left = (left ^ p[decrypting ? 17 - round : round]) >>> 0;
                right = (right ^ f(left)) >>> 0;
                [left, right] = [right, left];
            }
            [left, right] = [right, left];
            right = (right ^ p[decrypting ? 1 : 16]) >>> 0;
            left = (left ^ p[decrypting ? 0 : 17]) >>> 0;
            return [left, right];
        }
        // Includes the terminating NUL, matching the editor's key length.
        const key = new TextEncoder().encode("532b3c9a-5d45-4b9e-86d2-56cbc18daaca\0");
        let keyIndex = 0;
        for (let i = 0; i < p.length; i++) {
            let value = 0;
            for (let j = 0; j < 4; j++) {
                value = (value << 8) | key[keyIndex];
                keyIndex = (keyIndex + 1) % key.length;
            }
            p[i] = (p[i] ^ value) >>> 0;
        }
        let left = 0, right = 0;
        for (let i = 0; i < state.length; i += 2) {
            [left, right] = block(left, right, false);
            state[i] = left;
            state[i + 1] = right;
        }
        const view = new DataView(decoded.buffer);
        // TONEX encrypts little-endian UInt32 pairs (not conventional BE bytes).
        for (let i = 0; i < decoded.length; i += 8) {
            [left, right] = block(view.getUint32(i, true), view.getUint32(i + 4, true), true);
            view.setUint32(i, left, true);
            view.setUint32(i + 4, right, true);
        }
        if (!decoded.subarray(29829).every(value => value === 3)) throw new Error("Invalid TXP encryption padding.");
        return decoded.subarray(0, 29829);
    }

    function unpackModel(file, offset) {
        const model = new Uint8Array(0x36C8);
        for (const [destination, count] of [[0,5],[8,4],[0xC,4],[0x10,16],[0x20,4],[0x24,1],[0x25,17],[0x38,4],[0x3C,17],[0x50,0x144C],[0x149C,8192],[0x349C,0x22B]]) {
            model.set(file.subarray(offset, offset + count), destination);
            offset += count;
        }
        return model;
    }
    function assetType(model) {
        const type = [1, 2, 2, 4, 4, 3][word(model, 0xC)];
        if (type === undefined) throw new Error("Unsupported TXP tone-model type.");
        return type;
    }
    function asset(model) {
        const type = assetType(model), fileType = word(model, 0xC);
        const payload = new Uint8Array(13768);
        const copy = (source, destination, count) => payload.set(model.subarray(source, source + count), destination);
        function text(source, destination, capacity) {
            const {content, length} = string(model, source, capacity);
            payload.set(content, destination);
            payload.set(le(length), destination + Math.ceil(capacity / 4) * 4);
        }
        function choice(source, names) {
            let end = source;
            while (end < model.length && model[end] !== 0) end++;
            const index = names.indexOf(new TextDecoder().decode(model.subarray(source, end)));
            return index < 0 ? names.length : index;
        }
        if (type === 1) {
            payload[0] = choice(0x356B, ["STOMP - OVERDRIVE", "STOMP - DISTORTION", "STOMP - FUZZ", "STOMP - EQ"]);
            text(0x35AD, 4, 33);
            copy(0x50, 0x2C, 5196);
            copy(0x149C, 0x1478, 8192);
            text(0x35D7, 0x3478, 65);
        } else if (type === 2 || type === 4) {
            payload[0] = choice(0x356B, ["CLEAN", "DRIVE", "HI-GAIN", "FUZZY"]);
            text(0x358C, 4, 33);
            copy(0x50, 0x2C, 5196);
            text(0x35CE, 0x1478, 9);
            payload[0x1488] = (fileType === 1 || fileType === 4) ? 1 : 0;
            text(0x35AD, 0x148C, 33);
            text(0x35D7, 0x14B4, 65);
            if (type === 2) {
                if (word(model, 8) === 1) payload.set(float(16).slice(1), 0x14FC);
                else copy(0x149C, 0x14FC, 8192);
            } else {
                const base = 0x14FC;
                payload[base] = choice(0x3618, ["4X12", "2X12", "1X12", "8X10", "4X10", "3X10", "2X10", "1X10", "1X8", "1X6", "2X15", "1X15", "1X18"]);
                text(0x3622, base + 4, 33);
                copy(0x149C, base + 0x2C, 8192);
                text(0x3643, base + 0x202C, 17);
                text(0x3654, base + 0x2044, 17);
                text(0x3665, base + 0x205C, 33);
                text(0x3686, base + 0x2084, 65);
            }
        } else {
            text(0x3622, 0, 33);
            copy(0x149C, 0x28, 8192);
        }
        const identifier = [];
        for (let offset = 0x10; offset < 0x20; offset += 4) identifier.push(...model.slice(offset, offset + 4).reverse());
        const opaque = list(0xB9, [blob(model.subarray(0x34BD, 0x34DE)), [0]]);
        const metadata = list(0xB9, [
            [word(model, 0x20) === 1 ? 1 : 0], [model[0x24] === 0 ? 0 : 1], [word(model, 0x38) === 1 ? 1 : 0],
            detail(model, 0x25, 17), detail(model, 0x3C, 17), detail(model, 0x34DE, 11), opaque,
            detail(model, 0x34E9, 65), detail(model, 0x352A, 65)
        ]);
        return list(0xB9, [blob(identifier), detail(model, 0x349C, 33), [type], blob(payload), metadata]);
    }
    function emptyAsset() {
        const zero = new Uint8Array(65);
        const metadata = list(0xB9, [[0], [0], [0], ...[17,17,11,33,65,65].map(capacity => detail(zero, 0, capacity))]);
        return list(0xB9, [blob(zero.subarray(0,16)), detail(zero,0,33), [0], blob(new Uint8Array(13768)), metadata]);
    }
    function parameters(file, offset, modelType) {
        return list(0xBA, parameterRules.map(([kind, index, minimum, maximum]) => {
            let value;
            if (kind === "integer") value = Math.min(Math.fround(word(file, offset + index * 4)), minimum);
            else if (kind === "real") value = bounded(real(file, offset + index * 4), Math.fround(minimum), Math.fround(maximum));
            else if (kind === "modelSwitch") value = modelType === 1 || modelType === 2 ? 1 : 0;
            else value = index;
            return float(value);
        }));
    }
    function convert(text, presetIndex) {
        if (!Number.isInteger(presetIndex) || presetIndex < 0 || presetIndex >= 20) throw new Error("Invalid TONEX ONE slot.");
        const file = decrypt(text);
        if (file[0] !== 46 || file[1] !== 116 || file[2] !== 120 || file[3] !== 112 || file[4] !== 0 || word(file, 5) !== 3) {
            throw new Error("Unsupported TXP file; only version-3 presets are supported.");
        }
        const model = unpackModel(file, 25), type = assetType(model), separate = file[14040] !== 0;
        const details = [detail(file,28089,33), detail(file,28122,11)];
        for (let i = 0; i < 10; i++) details.push(detail(file,28133 + i * 33,33));
        details.push(detail(file,28463,65));
        const banks = [0,1,2].map(bank => parameters(file,28532 + bank * 432,type));
        const settings = list(0xB9, [detail(file,28056,33), list(0xBA, [float(Math.min(file[29828],1)), float(bounded(real(file,28528),40,240))]), list(0xBA,banks), list(0xB9,details)]);
        const full = list(0xB9, [settings, asset(model), [separate ? 1 : 0], separate ? asset(unpackModel(file,14041)) : emptyAsset()]);
        const body = new Uint8Array(list(0xB9, [[1], byte(presetIndex), full]));
        if (body.length > 32757) throw new Error("Converted preset exceeds the controller's buffer.");
        return body;
    }

    class BodyReader {
        constructor(bytes) { this.bytes = bytes; this.offset = 0; }
        take(count) {
            if (count < 0 || this.offset + count > this.bytes.length) throw new Error('Truncated full-preset body.');
            const value = this.bytes.slice(this.offset, this.offset + count);
            this.offset += count;
            return value;
        }
        raw() { return this.take(1)[0]; }
        byte() { const value = this.raw(); return value === 0x80 ? this.raw() : value; }
        list(tag, count) {
            if (this.raw() !== tag || this.raw() !== count) throw new Error('Unexpected full-preset list.');
        }
        blob(expected) {
            if (this.raw() !== 0xBC) throw new Error('Expected full-preset byte buffer.');
            const prefix = this.raw();
            const count = prefix === 0x80 ? this.raw() :
                (prefix === 0x81 || prefix === 0x82) ? this.raw() | (this.raw() << 8) : prefix;
            if (count !== expected) throw new Error('Unexpected full-preset byte-buffer length.');
            return this.take(count);
        }
        detail(capacity, preserveBuffer = false) {
            this.list(0xB9, 2);
            const buffer = this.blob(capacity);
            this.byte();
            if (preserveBuffer) return buffer;
            const zero = buffer.indexOf(0);
            return zero < 0 ? buffer : buffer.slice(0, zero);
        }
        float() {
            if (this.raw() !== 0x88) throw new Error('Expected full-preset float.');
            const value = new DataView(this.take(4).buffer).getFloat32(0, true);
            if (!Number.isFinite(value)) throw new Error('Invalid full-preset parameter.');
            return value;
        }
    }

    function writeBytes(destination, offset, source, capacity = source.length) {
        destination.set(source.slice(0, capacity), offset);
    }
    function writeWord(destination, offset, value) { destination.set(le(value >>> 0), offset); }
    function exportInteger(value) {
        const rounded = Math.fround(value + 0.5);
        return rounded <= 0 ? 0 : rounded >= 4294967295 ? 4294967295 : Math.trunc(rounded);
    }
    function exportModel(reader, inactive) {
        reader.list(0xB9, 5);
        const identifier = reader.blob(16), name = reader.detail(33), type = reader.byte();
        const payload = reader.blob(13768);
        reader.list(0xB9, 9);
        const instrument = reader.byte(), licensed = reader.byte(), category = reader.byte();
        const instrumentName = reader.detail(17), categoryName = reader.detail(17), date = reader.detail(11);
        const opaque = reader.detail(33, true), description = reader.detail(65), comment = reader.detail(65);
        if (inactive) return new Uint8Array(14015);
        if (type < 1 || type > 4) throw new Error('Unsupported hardware asset type.');
        const model = new Uint8Array(0x36C8);
        const text = (source, destination, capacity) => writeBytes(model, destination, payload.slice(source, source + capacity), capacity);
        const copy = (source, destination, count) => writeBytes(model, destination, payload.slice(source, source + count));
        const choice = (value, names, destination, capacity) => {
            if (value >= names.length) throw new Error('Unsupported model subtype.');
            writeBytes(model, destination, new TextEncoder().encode(names[value]), capacity);
        };
        writeBytes(model, 0, new TextEncoder().encode('.txm\0'));
        writeWord(model, 8, 2);
        const fileType = type === 1 ? 0 : type === 2 ? (payload[0x1488] === 1 ? 1 : 2) :
            type === 3 ? 5 : (payload[0x1488] === 1 ? 4 : 3);
        writeWord(model, 0xC, fileType);
        for (let offset = 0; offset < 16; offset += 4) writeBytes(model, 0x10 + offset, identifier.slice(offset, offset + 4).reverse());
        writeWord(model, 0x20, instrument <= 1 ? instrument : 0);
        model[0x24] = licensed;
        writeBytes(model, 0x25, instrumentName, 17);
        writeWord(model, 0x38, category <= 1 ? category : 0);
        writeBytes(model, 0x3C, categoryName, 17);
        writeBytes(model, 0x349C, name, 33);
        writeBytes(model, 0x34BD, opaque, 33);
        writeBytes(model, 0x34DE, date, 11);
        writeBytes(model, 0x34E9, description, 65);
        writeBytes(model, 0x352A, comment, 65);
        if (type === 1) {
            choice(payload[0], ['STOMP - OVERDRIVE','STOMP - DISTORTION','STOMP - FUZZ','STOMP - EQ','STOMP - OTHER'], 0x356B, 33);
            text(4, 0x35AD, 33); copy(44, 0x50, 5196); copy(5240, 0x149C, 8192); text(0x3478, 0x35D7, 65);
        } else if (type === 2 || type === 4) {
            choice(payload[0], ['CLEAN','DRIVE','HI-GAIN','FUZZY','OTHER'], 0x356B, 33);
            text(4, 0x358C, 33); copy(44, 0x50, 5196); text(0x1478, 0x35CE, 9); text(0x148C, 0x35AD, 33); text(0x14B4, 0x35D7, 65);
            if (type === 2) copy(5372, 0x149C, 8192);
            else {
                const base = 0x14FC;
                choice(payload[base], ['4X12','2X12','1X12','8X10','4X10','3X10','2X10','1X10','1X8','1X6','2X15','1X15','1X18','OTHER'], 0x3618, 10);
                text(base + 4, 0x3622, 33); copy(base + 44, 0x149C, 8192); text(base + 0x202C, 0x3643, 17);
                text(base + 0x2044, 0x3654, 17); text(base + 0x205C, 0x3665, 33); text(base + 0x2084, 0x3686, 65);
            }
        } else { text(0, 0x3622, 33); copy(40, 0x149C, 8192); }
        const fields = [[0,5],[8,4],[0xC,4],[0x10,16],[0x20,4],[0x24,1],[0x25,17],[0x38,4],[0x3C,17],[0x50,0x144C],[0x149C,8192],[0x349C,0x22B]];
        const packed = new Uint8Array(14015); let cursor = 0;
        for (const [offset, count] of fields) { packed.set(model.slice(offset, offset + count), cursor); cursor += count; }
        return packed;
    }

    function plaintextFromBody(body) {
        const reader = new BodyReader(body), file = new Uint8Array(29829);
        reader.list(0xB9, 3); reader.byte(); reader.byte(); reader.list(0xB9, 4); reader.list(0xB9, 4);
        writeBytes(file, 0, new TextEncoder().encode('.txp\0')); writeWord(file, 5, 3);
        writeBytes(file, 28056, reader.detail(33), 33);
        reader.list(0xBA, 2);
        const presetFlag = reader.float();
        if (presetFlag !== 0 && presetFlag !== 1) throw new Error('Unsupported preset flag.');
        file[29828] = presetFlag;
        new DataView(file.buffer).setFloat32(28528, reader.float(), true);
        reader.list(0xBA, 3);
        for (let bank = 0; bank < 3; bank++) {
            reader.list(0xBA, 109); const values = Array.from({length:109}, () => reader.float());
            const offset = 28532 + bank * 432;
            parameterRules.forEach(([kind, index], usbIndex) => {
                if (kind === 'integer') writeWord(file, offset + index * 4, exportInteger(values[usbIndex]));
                if (kind === 'real') new DataView(file.buffer).setFloat32(offset + index * 4, values[usbIndex], true);
            });
            writeWord(file, offset + 97 * 4, exportInteger(values[23]));
            if (values[23] !== 1) writeWord(file, offset + 98 * 4, 2);
        }
        reader.list(0xB9, 13);
        let metadataOffset = 28089;
        for (const capacity of [33,11,33,33,33,33,33,33,33,33,33,33,65]) { writeBytes(file, metadataOffset, reader.detail(capacity), capacity); metadataOffset += capacity; }
        writeBytes(file, 25, exportModel(reader, false));
        const separate = reader.byte(); if (separate > 1) throw new Error('Unsupported separate-model flag.');
        file[14040] = separate;
        const second = exportModel(reader, separate === 0); if (separate) writeBytes(file, 14041, second);
        if (reader.offset !== body.length) throw new Error('Trailing full-preset data.');
        return file;
    }

    function encode(plaintext) {
        const source = new Uint8Array(plaintext.length + 3); source.set(plaintext); source.fill(3, plaintext.length);
        const state = Uint32Array.from(initialHex.match(/.{8}/g), hex => parseInt(hex, 16));
        const p = state.subarray(0, 18), s = state.subarray(18);
        const f = x => ((((s[x >>> 24] + s[256 + ((x >>> 16) & 255)]) >>> 0) ^ s[512 + ((x >>> 8) & 255)]) + s[768 + (x & 255)]) >>> 0;
        function block(left, right, decrypting) { for (let round = 0; round < 16; round++) { left = (left ^ p[decrypting ? 17-round : round]) >>> 0; right = (right ^ f(left)) >>> 0; [left,right] = [right,left]; } [left,right] = [right,left]; return [(left ^ p[decrypting ? 0 : 17]) >>> 0, (right ^ p[decrypting ? 1 : 16]) >>> 0]; }
        const key = new TextEncoder().encode('532b3c9a-5d45-4b9e-86d2-56cbc18daaca\0'); let keyIndex = 0;
        for (let i = 0; i < 18; i++) { let value = 0; for (let j = 0; j < 4; j++) { value = (value << 8) | key[keyIndex]; keyIndex = (keyIndex + 1) % key.length; } p[i] = (p[i] ^ value) >>> 0; }
        let left = 0, right = 0; for (let i = 0; i < state.length; i += 2) { [left,right] = block(left,right,false); state[i] = left; state[i+1] = right; }
        const view = new DataView(source.buffer); for (let i = 0; i < source.length; i += 8) { [left,right] = block(view.getUint32(i,true),view.getUint32(i+4,true),false); view.setUint32(i,left,true); view.setUint32(i+4,right,true); }
        const alphabet = '.ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+'; let output = '29832.'; let bits = 0, count = 0;
        for (const value of source) { bits |= value << count; count += 8; while (count >= 6) { output += alphabet[bits & 63]; bits >>>= 6; count -= 6; } }
        if (count) output += alphabet[bits & 63];
        return output;
    }

    function exportFile(body) { return encode(plaintextFromBody(body)); }
    return {convert, exportFile};
})();
