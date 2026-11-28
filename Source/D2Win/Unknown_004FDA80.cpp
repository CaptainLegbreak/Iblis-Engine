struct Obj004FDA80 { unsigned short wValue00; };
// 0x004FDA80
extern "C" __declspec(dllexport) int __fastcall sub_004FDA80_IsColorCodePrefix(Obj004FDA80* pObj) {
    unsigned short wValue = pObj->wValue00;
    if (wValue < 0x100) {
        return wValue == 0xFF;
    }
    return 0;
}

extern "C" const char* gData_0072DF0C[15] = { // 0x0072DF0C
    "English",
    "Spanish",
    "German",
    "French",
    "Portuguese",
    "Italian",
    "Japanese",
    "Korean",
    "Simplified Chinese",
    "Traditional Chinese",
    "Polish",
    "Russian",
    "English with Korean Chat",
    "Unknown",
    "14"
};
