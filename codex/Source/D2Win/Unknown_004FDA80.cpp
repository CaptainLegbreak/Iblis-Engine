struct Obj004FDA80 { unsigned short wValue00; };
// 0x004FDA80
extern "C" __declspec(dllexport) int __fastcall sub_004FDA80(Obj004FDA80* pObj) {
    unsigned short wValue = pObj->wValue00;
    if (wValue < 0x100) {
        return wValue == 0xFF;
    }
    return 0;
}

#include "gen/data/Source/D2Win/Unknown_004FDA80.inc"
