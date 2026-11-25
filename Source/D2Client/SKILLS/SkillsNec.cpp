typedef unsigned int DWORD;

extern "C" void* __fastcall sub_004648F0_GetTargetUnit(void* pUnit); // 0x004648F0
extern "C" int __stdcall ITEMS_IsMetalItem(int nItemId); // 0x00629CC0
extern "C" int __stdcall ITEMS_CheckItemFlag(void* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
extern "C" void* __stdcall UNITS_GetRoom(void* pUnit); // 0x00620BB0
extern "C" void* __stdcall STATLIST_GetOwner(void* pUnit, int* pStatNotDynamic); // 0x00625820

// 0x004F3F50
int __fastcall SKILLSNEC_CheckNecromancerSkill(void* pUnit, int nArg1, int nArg2)
{
    void* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (!pTarget)
        return 0;
    if (*(int*)pTarget != 4)
        return 0;
    if (!ITEMS_IsMetalItem(*(int*)((char*)pTarget + 4)))
        return 0;
    if (*(int*)((char*)pTarget + 0x10) != 3)
        return 0;
    if (!ITEMS_CheckItemFlag(pTarget, 0x10, 0x22C, ".\\SKILLS\\SkillsNec.cpp"))
        return 0;
    if (!UNITS_GetRoom(pTarget))
        return 0;
    return !STATLIST_GetOwner(pTarget, 0);
}

#pragma pack(push, 1)
struct d2data_0072D994_t
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

extern "C" struct d2data_0072D994_t gData_0072D994; // 0x0072D994

extern "C" struct d2data_0072D994_t gData_0072D994 = {
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
}; // 0x0072D994
