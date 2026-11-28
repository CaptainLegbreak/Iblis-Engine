#include "D2LanguageNames.h"

#include "D2CommonApi.h"
typedef unsigned int DWORD;

extern "C" void* __fastcall CUNIT_GetPathTargetUnit(void* pUnit); // 0x004648F0
extern "C" int __stdcall ITEMS_CheckItemFlag(void* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
extern "C" void* __stdcall UNITS_GetRoom(void* pUnit); // 0x00620BB0
extern "C" void* __stdcall STATLIST_GetOwner(void* pUnit, int* pStatNotDynamic); // 0x00625820

// 0x004F3F50
int __fastcall SKILLSNEC_CheckNecromancerSkill(void* pUnit, int nArg1, int nArg2)
{
    void* pTarget = CUNIT_GetPathTargetUnit(pUnit);
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


