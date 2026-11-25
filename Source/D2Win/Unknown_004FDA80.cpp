struct Obj004FDA80 { unsigned short wValue00; };
// 0x004FDA80
extern "C" __declspec(dllexport) int __fastcall sub_004FDA80(Obj004FDA80* pObj) {
    unsigned short wValue = pObj->wValue00;
    if (wValue < 0x100) {
        return wValue == 0xFF;
    }
    return 0;
}

#pragma pack(push, 1)
struct d2data_0072DF0C_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

extern "C" struct d2data_0072DF0C_t gData_0072DF0C; // 0x0072DF0C

extern "C" struct d2data_0072DF0C_t gData_0072DF0C = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x0072DF0C
