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

#include "gen/data/Source/D2Client/SKILLS/SkillsNec.inc"
