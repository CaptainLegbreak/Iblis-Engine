#include "D2StatIds.h"

#include "D2Client.h"
#include "D2ClientFuncs.h"

#include "D2Structs.h"

#include "D2Txt.h"

#include "D2UnitData.h"

#include "D2SkillIds.h"

#include "D2DataTbls.h"

#include "D2LevelTxt.h"

#include "D2Unicode.h"
#include "D2CommonApi.h"
#include "D2CommonApi2.h"
#include "D2CommonApi3.h"
#include "D2LangApi.h"
#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2MonModes.h"
#include "D2Path.h"
#include "D2GameTypes.h"
#include "D2Constants.h"
#include "D2ClientTypes.h"
#include "D2ClientGame.h"
#include "D2WinApi2.h"

#define UNIT_MONSTER 1

#define MONTYPEFLAG_CHAMPION 4

struct D2GfxLightStrc;

union D2SeedStrc;

struct D2MonStats2Txt;



D2GfxLightStrc* __fastcall DLIGHTMAP_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160

int __fastcall DLIGHTMAP_GetLightSize(D2GfxLightStrc* pLight); // 0x00474350




void __fastcall VIEW_SpawnMissileAtObject173(D2UnitStrc* pUnit);                                                            // 0x0046B710

void __fastcall VIEW_SpawnMissileNearObject(D2UnitStrc* pUnit);                                                            // 0x0046B850










typedef void (__fastcall* UMODCALLBACK)(D2UnitStrc* pUnit, int nUMod, int bUnique);

extern const int gaUModList[4];                                                                     // 0x006DA4C8

extern UMODCALLBACK gpfnUModCallbacks[];                                                            // 0x00724D78

static inline unsigned __int64 SEED_RollLocalSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline int GetUnitType(D2UnitStrc* unit)
{
    return !unit ? 6 : unit->dwUnitType;
}



#define NULL 0

extern "C" char* __cdecl strcpy(char*, const char*);

#pragma intrinsic(strcpy)

struct D2HoverModeStrc
{
    int nMode;
    unsigned short wStringId;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

Unicode gwszNameSeparator[2]; // 0x007C0C58

extern const D2HoverModeStrc gaHoverModes[];                                                       // 0x006DA488

int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                        // 0x0045C390

void __cdecl INV_FormatArgs(Unicode* pDest, const Unicode* pFormat, ...);                          // 0x0048BE80



Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320


static D2MonsterDataStrc* CLIENT_GetMonsterData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}

static int sub_0044BE50(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
        nType = pUnit->dwUnitType;
    return nType;
}

static int MONSTERS_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    D2MonsterDataStrc* pMonsterData = sub_0044BE50(pUnit) == 1 ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
        return 0;
    if (pMonsterData->nTypeFlag & nFlag)
        return 1;
    return 0;
}

static inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return NULL;
}

// 0x004AC730
D2MonsterDataStrc* __fastcall MONUNIQUE_MonsterDataOf(D2UnitStrc* pUnit)
{
    if (sub_0044BE50(pUnit) == 1)
        return pUnit->pMonsterData;
    return 0;
}

// 0x004AC740
unsigned char* __fastcall MONUNIQUE_GetMonUmods(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = CLIENT_GetMonsterData(pUnit);
    if (!pMonsterData)
    {
        return 0;
    }
    return pMonsterData->nMonUmod;
}

// 0x004AC760
unsigned short __fastcall MONUNIQUE_GetMonsterDataWord14(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = MONUNIQUE_MonsterDataOf(pUnit);
    if (!pMonsterData)
        return 0;
    return pMonsterData->wNameSeed;
}

// 0x004AC780
void __fastcall MONUNIQUE_SetNameSeed(D2UnitStrc* pUnit, unsigned short nValue)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
        pUnit->pMonsterData->wNameSeed = nValue;
}

// 0x004AC7A0
void __fastcall MONUNIQUE_SetBossHcIdx(D2UnitStrc* pUnit, unsigned short wSuperUniqueId)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
        pUnit->pMonsterData->wBossHcIdx = wSuperUniqueId;
}

// 0x004AC7C0
short __fastcall MONUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = MONUNIQUE_MonsterDataOf(pUnit);
    if (!pMonsterData)
        return 0;
    return pMonsterData->wBossHcIdx;
}

// 0x004AC7E0
int __fastcall MONUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    D2MonsterDataStrc* pMonsterData = MONUNIQUE_MonsterDataOf(pUnit);
    if (!pMonsterData)
        return 0;
    return (unsigned short)(pMonsterData->nTypeFlag & nFlag) != 0;
}

// 0x004AC810
void __fastcall MONUNIQUE_ToggleMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag, int bSet)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData)
        {
            if (bSet)
            {
                pMonsterData->nTypeFlag |= nFlag;
            }
            else
            {
                pMonsterData->nTypeFlag &= ~nFlag;
            }
        }
    }
}

// 0x004AC840
void __fastcall sub_004AC840_SetTypeFlag100(D2UnitStrc* pUnit, int bSet)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData)
        {
            if (bSet)
                pMonsterData->nTypeFlag |= 0x100;
            else
                pMonsterData->nTypeFlag &= ~0x100;
        }
    }
}

// 0x004AC870
void __fastcall MONUNIQUE_SetMonsterHoverName(D2UnitStrc* pUnit, int nMode, int bShow)
{
    Unicode wszName[300];

    if (!bShow)
    {
        return;
    }

    for (int k = 0; k < 300; ++k)
    {
        wszName[k] = 0;
    }
    char szSpace[8];
    strcpy(szSpace, " ");
    sub_00526320_ToUnicode(gwszNameSeparator, szSpace, 2);

    D2SeedStrc* pSeed = &pUnit->pSeed;
    unsigned short nNameSeed = MONUNIQUE_GetMonsterDataWord14(pUnit);
    D2MonsterDataStrc* pMonsterData = (pUnit && sub_0044BE50(pUnit) == 1) ? pUnit->pMonsterData : NULL;
    if (pMonsterData && (pMonsterData->nTypeFlag & 2))
    {
        D2SuperUniquesTxt* pSuperUniquesTxtRecord = DATATBLS_GetSuperUniquesTxtRecord(MONUNIQUE_GetBossHcIdx(pUnit));
        if (!pSuperUniquesTxtRecord)
        {
            return;
        }

        unsigned short wNameStr = pSuperUniquesTxtRecord->wNameStr;
        if (!wNameStr)
        {
            wNameStr = 0x1506;
        }
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(wNameStr));
        return;
    }

    int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    if (MONSTER_IsChampionMonster(pUnit))
    {
        int i = 0;
        for (; i < 4; ++i)
        {
            if (gaHoverModes[i].nMode == nMode)
            {
                break;
            }
        }

        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nClassId);
        INV_FormatArgs(wszName, D2LANG_GetStringFromTblIndex(0x2B40), D2LANG_GetStringFromTblIndex(gaHoverModes[i].wStringId), D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr), 0);
        MONSTERS_SetMonsterNameInMonsterData(pUnit, wszName);
        return;
    }

    SEED_InitLowSeed(pSeed, nNameSeed);
    if (nMode == 12)
    {
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0xC27));
        return;
    }

    switch (nClassId)
    {
    case 0x9C:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0xBCD));
        return;

    case 0xD3:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0xBEE));
        return;

    case 0xF2:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0xBF6));
        return;

    case 0x100:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0x3F6));
        return;

    case 0xF3:
    case 0x14D:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0xBF4));
        return;

    case 0x220:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0xBF5));
        return;

    case 0x2C3:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0x2B92));
        return;

    case 0x2C4:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0xBEE));
        return;

    case 0x2C0:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0xBF6));
        return;

    case 0x2C2:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0x3F6));
        return;

    case 0x2C1:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0xBF4));
        return;

    case 0x2C5:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0xBF5));
        return;

    default:
        INV_FormatArgs(wszName, D2LANG_GetStringFromTblIndex(0x6B9), DATATBLS_RollRandomUniquePrefixString(pUnit), DATATBLS_RollRandomUniqueSuffixString(pUnit), 0);
        if (SEED_RollLimitedRandomNumber(pSeed, 100) < 50)
        {
            INV_FormatArgs(wszName, D2LANG_GetStringFromTblIndex(0x6BA), DATATBLS_RollRandomUniquePrefixString(pUnit), DATATBLS_RollRandomUniqueSuffixString(pUnit), DATATBLS_RollRandomUniqueAppellationString(pUnit), 0);
        }
        MONSTERS_SetMonsterNameInMonsterData(pUnit, wszName);
        return;
    }
}

// 0x004ACC70
void __fastcall MONUNIQUE_InitUModLight(D2UnitStrc* pUnit, int nUnused, int bInit)
{
    if (!bInit)
    {
        return;
    }

    CUNIT_FreeLight(pUnit);

    D2GfxLightStrc* pLight;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData && (pUnit->pMonsterData->nTypeFlag & MONTYPEFLAG_CHAMPION))
    {
        const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
        D2SeedStrc seed;
        seed.nHighSeed = (unsigned int)(lSeed >> 32);
        seed.nLowSeed = (unsigned int)lSeed;
        const int nBlue = (int)lSeed;
        const int nGreen = (int)SEED_RollLocalSeed(&seed);
        const int nRed = (int)SEED_RollLocalSeed(&seed);
        pUnit->pSeed = seed;
        pLight = DLIGHTMAP_MakeLightEntry(pUnit, 0, 7, 0xFF, nRed, nGreen, nBlue);
    }
    else
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(!pUnit ? -1 : pUnit->dwClassId);
        if (!pMonStats2TxtRecord)
        {
            return;
        }

        pLight = DLIGHTMAP_MakeLightEntry(pUnit, 0, 7, 0xFF, pMonStats2TxtRecord->nLight_R, pMonStats2TxtRecord->nLight_G, pMonStats2TxtRecord->nLight_B);
    }

    pUnit->pLight = pLight;
    CUNIT_SetStartLight(pUnit, DLIGHTMAP_GetLightSize(pLight));
}

// 0x004ACD50
void __fastcall MONUNIQUE_ClearDurielFlag(D2UnitStrc* unit, void* unused, int unusedStack)
{
    if (GetUnitType(unit) == 1)
    {
        D2MonsterDataStrc* data = unit->pMonsterData;
        if (data)
            data->dwDurielFlag = 0;
    }
}

// 0x004ACD70
void __fastcall MONUNIQUE_AssignTeleportSkill(D2UnitStrc* pUnit, int nUnused, int bAssign)
{
    if (bAssign)
    {
        SKILLS_AssignSkill(pUnit, SKILL_MONTELEPORT, 1, 1, ".\\UNIT\\MonUnique.cpp", 0x157);
        SKILLS_SetSkillMode(SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_MONTELEPORT), 4);
    }
}

// 0x004ACDB0
int __fastcall MONUNIQUE_ApplyResistantMod(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (bUnique)
    {
        if (nUMod == 28)
        {
            int nDefense = 2 * STATLIST_UnitGetStatValue(pUnit, STAT_ARMORCLASS, 0);
            STATLIST_SetUnitStat(pUnit, STAT_ARMORCLASS, nDefense, 0);
        }

        int nImmunities = 0;
        int nFireResist = STATLIST_UnitGetStatValue(pUnit, STAT_FIRERESIST, 0);
        int nLightResist = STATLIST_UnitGetStatValue(pUnit, STAT_LIGHTRESIST, 0);
        int nColdResist = STATLIST_UnitGetStatValue(pUnit, STAT_COLDRESIST, 0);
        int nPoisonResist = STATLIST_UnitGetStatValue(pUnit, STAT_POISONRESIST, 0);
        int nDamageResist = STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGERESIST, 0);
        int nMagicResist = STATLIST_UnitGetStatValue(pUnit, STAT_MAGICRESIST, 0);

        if (nFireResist >= 100) ++nImmunities;
        if (nLightResist >= 100) ++nImmunities;
        if (nColdResist >= 100) ++nImmunities;
        if (nPoisonResist >= 100) ++nImmunities;
        if (nDamageResist >= 100) ++nImmunities;
        if (nMagicResist >= 100) ++nImmunities;

        if (nImmunities < 2)
        {
            if (nUMod == 8)
            {
                if (nColdResist < 100)
                {
                    int nNewColdResist = nColdResist + 40;
                    STATLIST_SetUnitStat(pUnit, STAT_COLDRESIST, nNewColdResist, 0);
                    if (nNewColdResist >= 100) ++nImmunities;
                }
                if (nImmunities < 2)
                {
                    if (nFireResist < 100)
                    {
                        int nNewFireResist = nFireResist + 40;
                        STATLIST_SetUnitStat(pUnit, STAT_FIRERESIST, nNewFireResist, 0);
                        if (nNewFireResist >= 100) ++nImmunities;
                    }
                    if (nImmunities < 2)
                    {
                        if (nLightResist < 100)
                        {
                            int nNewLightResist = nLightResist + 40;
                            STATLIST_SetUnitStat(pUnit, STAT_LIGHTRESIST, nNewLightResist, 0);
                            if (nNewLightResist >= 100) return nImmunities + 1;
                        }
                    }
                }
            }
            else if (nUMod == 9) STATLIST_SetUnitStat(pUnit, STAT_FIRERESIST, nFireResist + 75, 0);
            else if (nUMod == 18) STATLIST_SetUnitStat(pUnit, STAT_COLDRESIST, nColdResist + 75, 0);
            else if (nUMod == 17) STATLIST_SetUnitStat(pUnit, STAT_LIGHTRESIST, nLightResist + 75, 0);
            else if (nUMod == 23) STATLIST_SetUnitStat(pUnit, STAT_POISONRESIST, nPoisonResist + 75, 0);
            else if (nUMod == 25) STATLIST_SetUnitStat(pUnit, STAT_MAGICRESIST, nMagicResist + 20, 0);
            else if (nUMod == 27)
            {
                if (nColdResist < 75)
                {
                    int nNewColdResist = nColdResist + 20;
                    STATLIST_SetUnitStat(pUnit, STAT_COLDRESIST, nNewColdResist, 0);
                    if (nNewColdResist >= 100) ++nImmunities;
                }
                if (nImmunities < 2)
                {
                    if (nFireResist < 75)
                    {
                        int nNewFireResist = nFireResist + 20;
                        STATLIST_SetUnitStat(pUnit, STAT_FIRERESIST, nNewFireResist, 0);
                        if (nNewFireResist >= 100) ++nImmunities;
                    }
                    if (nImmunities < 2)
                    {
                        if (nLightResist < 75)
                        {
                            int nNewLightResist = nLightResist + 20;
                            STATLIST_SetUnitStat(pUnit, STAT_LIGHTRESIST, nNewLightResist, 0);
                            if (nNewLightResist >= 100) return nImmunities + 1;
                        }
                    }
                }
            }
            else if (nUMod == 28) STATLIST_SetUnitStat(pUnit, STAT_DAMAGERESIST, nDamageResist + 50, 0);
        }
    }
}

// 0x004AD020
void __fastcall MONUNIQUE_ApplyUMods(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = sub_0044BE50(pUnit) == 1 ? pUnit->pMonsterData : 0;
    if (pMonsterData)
    {
        unsigned char* pUMods = pMonsterData->nMonUmod;
        if (pUMods && *pUMods)
        {
        const int bUnique = MONSTERS_CheckMonTypeFlag(pUnit, 8);

        for (int j = 0; j < 4; ++j)
        {
            const int nUMod = gaUModList[j];
            if (gpfnUModCallbacks[nUMod])
                gpfnUModCallbacks[nUMod](pUnit, nUMod, bUnique);
        }

        for (int i = 0; i < 9; ++i)
        {
            const int nUMod = pUMods[i];
            if (gpfnUModCallbacks[nUMod])
                gpfnUModCallbacks[nUMod](pUnit, nUMod, bUnique);
        }
        }
    }
}

extern unsigned short gwUniqueModNameIds[];                                                       // 0x00725188



extern "C" unsigned short* __fastcall sub_005267E0(unsigned short* pDst, const unsigned short* pSrc);     // 0x005267E0

int __fastcall UNICODE_StrLen(const Unicode* pString); // 0x00526800

struct D2UModCallbacksStrc
{
    UMODCALLBACK pCallbacks[5];
};

extern D2UModCallbacksStrc gaUModCallbacks[]; // 0x00724E28

static unsigned char* MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = sub_0044BE50(pUnit) == 1 ? pUnit->pMonsterData : 0;
    if (pMonsterData)
        return pMonsterData->nMonUmod;
    return 0;
}



D2UnitStrc* __fastcall MISSILE_SubmitMissileRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00


void __fastcall VIEW_SpawnMissileAtObject173(D2UnitStrc* pUnit);                                                            // 0x0046B710






void __fastcall VIEW_SpawnMissileNearObject(D2UnitStrc* pUnit);                                                            // 0x0046B850












extern D2DataTablesStrc* sgptDataTables; // 0x00744304

static inline unsigned __int64 SEED_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

void __fastcall VIEW_SpawnAroundUnit(D2UnitStrc* pUnit, int nMonsterId, int nCount); // 0x0046C320

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

static int GetUnitPathX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static int GetUnitPathY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540


__forceinline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

extern "C" int __fastcall sub_004AC7E0(D2UnitStrc* pUnit, unsigned short wMask); // 0x004AC7E0




extern "C" int __stdcall sub_0064A280(D2UnitStrc* pMissile); // 0x0064A280

extern "C" int __stdcall sub_0064A210(D2UnitStrc* pMissile); // 0x0064A210

static D2MonStatsTxt* GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}



extern const unsigned int gdwBitMasks[32]; // 0x006CE268

// 0x004AD0C0
void __fastcall NPCMENU_StateOverlayBurst(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!bFlag)
    {
        return;
    }

    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &bFlag, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode)
    {
        return;
    }
    if (bFlag != 4)
    {
        return;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    MISSILE_SubmitMissileRequest(pUnit, 0x52, nX, nY, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x52, nX + 1, nY + 1, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x52, nX + 1, nY - 1, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x52, nX - 1, nY + 1, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x52, nX - 1, nY - 1, 0, 1);
    sub_004B9A00(0x99A, pUnit, 0, 0, 0);
}

// 0x004AD1A0
void __fastcall NPCMENU_StateOverlayCross(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!bFlag)
    {
        return;
    }

    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode)
    {
        return;
    }
    if (nFrame != 4)
    {
        return;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    MISSILE_SubmitMissileRequest(pUnit, 0x75, nX, nY, 0, 1);
    const int nYPlus = nY + 1;
    const int nXPlus = nX + 1;
    MISSILE_SubmitMissileRequest(pUnit, 0x75, nXPlus, nYPlus, 0, 1);
    bFlag = nY - 1;
    MISSILE_SubmitMissileRequest(pUnit, 0x75, nXPlus, bFlag, 0, 1);
    const int nXMinus = nX - 1;
    MISSILE_SubmitMissileRequest(pUnit, 0x75, nXMinus, nYPlus, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x75, nXMinus, bFlag, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x52, nX, nY, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x52, nXPlus, nYPlus, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x52, nXPlus, bFlag, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x52, nXMinus, nYPlus, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x52, nXMinus, bFlag, 0, 1);
    sub_004B9A00(0x99A, pUnit, 0, 0, 0);
}

// 0x004AD2F0
void __fastcall NPCMENU_HandleUnitClassEvent(D2UnitStrc* pUnit, int nUnused, int nUnused2)
{
    if (!pUnit)
    {
        return;
    }

    switch ((unsigned int)pUnit->dwClassId)
    {
    case 0x9C:
        if (pUnit->dwAnimMode == 0)
        {
            VIEW_SpawnAndarielDeath(pUnit);
        }
        break;

    case 0x2D:
        if (pUnit->dwAnimMode == 0)
        {
            VIEW_SpawnMissileAtObject173(pUnit);
        }
        break;

    case 0xE5:
        if (pUnit->dwAnimMode == 0)
        {
            VIEW_PlayerRequestAtUnit15B(pUnit);
        }
        break;

    case 0xD3:
        if (pUnit->dwAnimMode == 0)
        {
            VIEW_PlayerRequestAtUnit16B(pUnit);
        }
        break;

    case 0xF2:
        if (pUnit->dwAnimMode == 0)
        {
            VIEW_SpawnMephistoDeath(pUnit);
        }
        break;

    case 0xF3:
        if (pUnit->dwAnimMode == 0)
        {
            UI_SetTimerUnitId(pUnit);
        }
        break;

    case 0x100:
        if (pUnit->dwAnimMode == 0)
        {
            VIEW_SpawnIzualDeath(pUnit);
        }
        break;

    case 0x16E:
        if (pUnit->dwAnimMode == 0)
        {
            VIEW_SpawnMissileNearObject(pUnit);
        }
        break;

    case 0x11C:
        if (pUnit->dwAnimMode == 0x0E)
        {
            VIEW_PlayerRequestAtUnit161(pUnit);
        }
        break;

    case 0x10B:
        if (pUnit->dwAnimMode == 0)
        {
            VIEW_SpawnBrDeathControl(pUnit);
        }
        break;

    case 0x1DF:
        if (pUnit->dwAnimMode == 0)
        {
            VIEW_UnitRequest25A(pUnit);
        }
        break;

    case 0x220:
        if (pUnit->dwAnimMode == 0)
        {
            VIEW_RequestAtMonster220(pUnit);
        }
        break;

    case 0x21C:
    case 0x21D:
    case 0x21E:
        if (pUnit->dwAnimMode == 0)
        {
            VIEW_SpawnMissileAtObject(pUnit);
        }
        break;
    }
}

// 0x004AD510
void __fastcall NPCMENU_StateStartEffect(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!bFlag && nState == 0x12)
    {
        return;
    }

    if (nState == 0x2A)
    {
        if (!pUnit || !pUnit->dwAnimMode)
        {
            SKILLS_StartUnitEffect(pUnit, pUnit, 0x5A, -1, 0, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), DATATBLS_GetMissileVelocityFromMissilesTxt(MISSILE_NOVA, 0));
        }
    }

    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &bFlag, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode)
    {
        return;
    }
    if (bFlag != 4)
    {
        return;
    }

    if (nState == 0x0A)
    {
        MISSILE_SubmitOwnerRequest(pUnit, 0x9B, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0));
        return;
    }
    if (nState == 0x12)
    {
        SKILLS_StartUnitEffect(pUnit, pUnit, 0xC2, -1, 0, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), DATATBLS_GetMissileVelocityFromMissilesTxt(MISSILE_FROSTNOVA, 0));
    }
}

// 0x004AD5F0
void __fastcall NPCMENU_StateDurielDeath(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
        return;

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
        return;

    if (pUnit->dwAnimMode == MONMODE_DEATH)
    {
        int nFrame;
        int nFrameCount;
        UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
        if (nFrame == 13)
        {
            GFX_RemoveOverlays(pUnit);
            GFX_AddUnitOverlay(pUnit, 0x34, 5, 0, 0, 0, 0, 0);
            GFX_AddUnitOverlay(pUnit, 0x9C, 5, 0, 0, 0, 0, 0);
            pUnit->nActionFrame = 0;
        }
    }
    else if (pUnit->dwAnimMode == MONMODE_DEAD)
    {
        if ((unsigned int)SEED_RollRandomNumberForceInline(&pUnit->pSeed) % 100 == 0 && (int)pMonsterData->dwDurielFlag < 100)
        {
            CLIENTS_GetUnitX(pUnit);
            CLIENTS_GetUnitY(pUnit);
            VIEW_SpawnAroundUnit(pUnit, MONSTER_MAGGOT, 4);
            pMonsterData->dwDurielFlag += 4;
        }
    }
}

// 0x004AD6E0
static void __stdcall NPCMENU_StateMissileBurst(int nSkillLevel, D2UnitStrc* pUnit, int nMissile)
{
    if (!nSkillLevel)
        nSkillLevel = 1;
    if (nMissile == MISSILE_LIGHTUNIQUE)
    {
        if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER || !pUnit->pMonsterData || !(pUnit->pMonsterData->nTypeFlag & 0x100))
            return;
    }
    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x21;
    tMissile.pOwner = pUnit;
    tMissile.nX = GetUnitPathX(pUnit);
    tMissile.nY = GetUnitPathY(pUnit);
    tMissile.nSkill = 0;
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nMissile = nMissile;
    if (nMissile != MISSILE_QUEENPOISONCLOUD)
        tMissile.pInitFunc = SKILLDESC_InitCappedChargedPath;
    int anDX[4] = { 0, 1, 0, -1 };
    int anDY[4] = { -1, 0, 1, 0 };
    for (int i = 0; i < 4; ++i)
    {
        const int nUnitX = GetUnitPathX(pUnit);
        const int nUnitY = GetUnitPathY(pUnit);
        const int nX = anDX[i] + nUnitX;
        const int nY = anDY[i] + nUnitY;
        for (int j = 0; j < 2; ++j)
        {
            tMissile.nInitArg = j;
            tMissile.nTargetX = nX;
            tMissile.nTargetY = nY;
            MISSILE_CreateClientMissile(&tMissile);
        }
    }
}

// 0x004AD890
void __fastcall NPCMENU_StateBurstOnFrame(D2UnitStrc* pUnit, int nState, int bSet)
{
    if (!bSet)
        return;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &bSet, &nFrameCount);
    if (!pUnit || pUnit->dwAnimMode != 3 || bSet != 2)
        return;
    const int nLevel = STATLIST_UnitGetStatValue(pUnit, 0xC, 0) >> 1;
    NPCMENU_StateMissileBurst(nLevel, pUnit, MISSILE_LIGHTUNIQUE);
}

// 0x004AD8E0
void __fastcall NPCMENU_StateBurst(D2UnitStrc* pUnit, int nState, int bSet)
{
    if (!bSet)
        return;
    if (pUnit && pUnit->dwAnimMode == 3)
        return;
    const int nLevel = STATLIST_UnitGetStatValue(pUnit, 0xC, 0) >> 1;
    NPCMENU_StateMissileBurst(nLevel, pUnit, MISSILE_LIGHTUNIQUE);
}

// 0x004AD920
void __fastcall NPCMENU_StateBurstNeutral(D2UnitStrc* pUnit, int nState, int bSet)
{
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode != 3 && pUnit->dwAnimMode)
        return;
    if (nFrameNo != 2)
        return;
    const int nLevel = STATLIST_UnitGetStatValue(pUnit, 0xC, 0);
    NPCMENU_StateMissileBurst(nLevel, pUnit, MISSILE_BUGLIGHTNING);
}

// 0x004AD970
void __fastcall NPCMENU_StateMissileSplit(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!bFlag || !pUnit || pUnit->dwUnitType != UNIT_MISSILE)
    {
        return;
    }

    const int nMissileId = pUnit->dwClassId;
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pUnit);
    if (!pOwner)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissileId);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->nMissileFlags[12 >> 3] & gdwBitMasks[12 & 7])
    {
        return;
    }

    if (sub_004AC7E0(pOwner, 0x80))
    {
        return;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pOwner);
    int nX;

    if (!pTarget)
    {
        nX = D2COMMON_10175_PathGetFirstPointX(pPath);
        bFlag = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    else
    {
        nX = CLIENTS_GetUnitX(pTarget);
        bFlag = CLIENTS_GetUnitY(pTarget);
    }

    D2SeedStrc tSeed;
    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, 'SEIS');
    tSeed.nHighSeed = pOwner->dwUnitId;

    int nDX = CLIENTS_GetUnitX(pOwner) - nX;
    int nDY = CLIENTS_GetUnitY(pOwner) - bFlag;

    if (nDX < 0)
    {
        nDX = -1;
    }
    else if (nDX > 0)
    {
        nDX = 1;
    }

    if (nDY < 0)
    {
        nDY = -1;
    }
    else if (nDY > 0)
    {
        nDY = 1;
    }

    switch (nMissileId)
    {
    case MISSILE_MUMMY1:
    case 63 + 1:
    case 63 + 2:
    case MISSILE_MUMMY4:
        nDY = 0;
        nDX = 0;
        break;
    }

    if (pOwner->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pOwner->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nTypeFlag |= 0x80;
        }
    }

    MISSILE_SubmitOwnerRequest(pOwner, nMissileId, nX - nDY, bFlag + nDX, sub_0064A280(pUnit), sub_0064A210(pUnit));
    MISSILE_SubmitOwnerRequest(pOwner, nMissileId, nX + nDY, bFlag - nDX, sub_0064A280(pUnit), sub_0064A210(pUnit));

    if (pOwner->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pOwner->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nTypeFlag &= ~0x80;
        }
    }
}

// 0x004ADB20
void __fastcall NPCMENU_StateOverlayAtPath(D2UnitStrc* pUnit, int nState, int bFlag)
{
    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode)
    {
        return;
    }
    if (nFrame != 4)
    {
        return;
    }
    MISSILE_SubmitOwnerRequest(pUnit, 0x2A, GetUnitPathX(pUnit), GetUnitPathY(pUnit), 0, 1);
}

// 0x004ADBC0
void __fastcall NPCMENU_StateMonOverlay(D2UnitStrc* pUnit, int nState, int bFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = pUnit ? GetMonStatsTxtRecord(pUnit->dwClassId) : 0;
    const int nLevel = pMonStatsTxtRecord->wAiParam[0][GAME_GetDifficulty()];

    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode)
    {
        return;
    }
    if (nFrame != 4)
    {
        return;
    }

    if (nLevel == 1)
    {
        MISSILE_SubmitOwnerRequest(pUnit, 0x1AB, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
    }
    else if (nLevel >= 2)
    {
        MISSILE_SubmitOwnerRequest(pUnit, 0x1AC, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
    }
    MISSILE_SubmitOwnerRequest(pUnit, 0x1AA, GetUnitPathX(pUnit), GetUnitPathY(pUnit), 0, 1);
}

// 0x004ADCE0
void __fastcall NPCMENU_StateRequests(D2UnitStrc* pUnit)
{
    int nX = GetUnitPathX(pUnit);
    int nY = GetUnitPathY(pUnit);
    MISSILE_SubmitMissileRequest(pUnit, 0x75, nX, nY, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x221, nX, nY, 0, 1);
    sub_004B9A00(0x99A, pUnit, 0, 0, 0);
}

// 0x004ADD80
void __fastcall NPCMENU_StateRequestsCallback(D2UnitStrc* pUnit, int nState, int bFlag)
{
    NPCMENU_StateRequests(pUnit);
}

// 0x004ADD90
void __stdcall MONSTER_RunUModCallbacks(D2UnitStrc* pUnit, D2UnitStrc* pArgument, int nMode)
{
    unsigned char* pUMods = MONSTERUNIQUE_GetUMods(pUnit);
    if (!pUMods)
    {
        return;
    }

    const int bUnique = MONSTERS_CheckMonTypeFlag(pUnit, 8);
    if (nMode != 4)
    {
        for (int i = 0; i < 9; ++i)
        {
            const int nUMod = pUMods[i];
            UMODCALLBACK pfnCallback = gaUModCallbacks[nUMod].pCallbacks[nMode];
            if (pfnCallback)
            {
                pfnCallback(pUnit, nUMod, bUnique);
            }
        }
    }
    else
    {
        for (int i = 0; i < 9; ++i)
        {
            const int nUMod = pUMods[i];
            UMODCALLBACK pfnCallback = gaUModCallbacks[nUMod].pCallbacks[nMode];
            if (pfnCallback)
            {
                pfnCallback(pArgument, nUMod, bUnique);
            }
        }
    }
}

// 0x004ADE40
void __fastcall MONSTER_RunUModCommandCallbacks(D2UnitStrc* pUnit)
{
    MONSTER_RunUModCallbacks(pUnit, 0, 0);
}

// 0x004ADE50
void __fastcall MONSTER_RunUModUpdateCallbacks(D2UnitStrc* pUnit)
{
    MONSTER_RunUModCallbacks(pUnit, 0, 1);
}

// 0x004ADE60
void __fastcall MONSTER_RunUModFrameCallbacks(D2UnitStrc* pUnit)
{
    MONSTER_RunUModCallbacks(pUnit, 0, 2);
}

// 0x004ADE70
void __fastcall MONSTER_RunUModHitCallbacks(D2UnitStrc* pUnit)
{
    MONSTER_RunUModCallbacks(pUnit, 0, 3);
}

// 0x004ADE80
void __fastcall MONSTER_RunUModMissileCallbacks(D2UnitStrc* pUnit, D2UnitStrc* pMissile)
{
    if (pUnit && pMissile && pUnit->dwUnitType == UNIT_MONSTER)
    {
        MONSTER_RunUModCallbacks(pUnit, pMissile, 4);
    }
}

// 0x004ADEA0
void __fastcall MONSTER_GetMonsterName(D2UnitStrc* pUnit, Unicode* wszName, int nLength, unsigned short nNameId)
{
    wszName->wChar = 0;

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return;
    }

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
    {
        return;
    }

    unsigned char* pUniqueMods = pMonsterData->nMonUmod;
    if (!pUniqueMods)
    {
        return;
    }

    if (MONSTER_IsMinionMonster(pUnit))
    {
        if (nNameId)
        {
            sub_005267E0((unsigned short*)wszName, (const unsigned short*)D2LANG_GetStringFromTblIndex(nNameId));
            Unicode::strcat(wszName, D2LANG_GetStringFromTblIndex(3995));
            Unicode::strcat(wszName, D2LANG_GetStringFromTblIndex(3221));
        }
        else
        {
            sub_005267E0((unsigned short*)wszName, (const unsigned short*)D2LANG_GetStringFromTblIndex(3221));
        }
        return;
    }

    const int nOldFont = D2Win_10127_SetFont(6);
    int nWidth = 0;
    int nCount = 0;
    int nTextLength = 0;
    if (nNameId)
    {
        nCount = 1;
        Unicode::strcat(wszName, D2LANG_GetStringFromTblIndex(nNameId));
        nTextLength = UNICODE_StrLen(D2LANG_GetStringFromTblIndex(nNameId));
        nWidth = D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(nNameId));
    }

    switch (pUnit->dwClassId)
    {
    case 704:
    case 704 + 1:
    case 704 + 2:
    case 704 + 3:
    case 704 + 4:
    case 704 + 5:
        return;
    }

    for (int i = 0; i < 9; ++i)
    {
        const int nMod = pUniqueMods[i];
        if (!gwUniqueModNameIds[nMod])
        {
            continue;
        }

        if (nCount && nTextLength + 1 < nLength - 1)
        {
            Unicode::strcat(wszName, gwszNameSeparator);
            ++nTextLength;
            nWidth += D2Win_10121_GetTextWidth(gwszNameSeparator);
        }

        if (nTextLength < nLength - 1)
        {
            const Unicode* wszMod = D2LANG_GetStringFromTblIndex(gwUniqueModNameIds[nMod]);
            if (UNICODE_StrLen(wszMod) + nTextLength < nLength - 1)
            {
                nTextLength += UNICODE_StrLen(wszMod);
                nWidth += D2Win_10121_GetTextWidth(wszMod);
                Unicode::strcat(wszName, wszMod);
                ++nCount;
            }
        }

        if (nWidth > 480)
        {
            D2Win_10127_SetFont(nOldFont);
            return;
        }
    }

    D2Win_10127_SetFont(nOldFont);
}

#pragma pack(push, 1)
struct d2data_00724D3C_t
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

extern "C" struct d2data_00724D3C_t gData_00724D3C; // 0x00724D3C

extern "C" struct d2data_00724D3C_t gData_00724D3C = {
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
}; // 0x00724D3C

extern const D2HoverModeStrc gaHoverModes[5] = {
    { 16, 0xC94 },
    { 36, 0x2B4C },
    { 37, 0x2B4D },
    { 38, 0x2B4E },
    { 39, 0x2B4F }
}; // 0x006DA488

extern const int gaUModList[4] = { 1, 2, 3, 4 }; // 0x006DA4C8

extern UMODCALLBACK gpfnUModCallbacks[44] = {
    0, (UMODCALLBACK)&MONUNIQUE_SetMonsterHoverName, 0, (UMODCALLBACK)&MONUNIQUE_InitUModLight, 0, 0, 0, 0, (UMODCALLBACK)&MONUNIQUE_ApplyResistantMod, (UMODCALLBACK)&MONUNIQUE_ApplyResistantMod, 0, (UMODCALLBACK)&MONUNIQUE_ClearDurielFlag, (UMODCALLBACK)&MONUNIQUE_SetMonsterHoverName, 0, 0, 0,
    (UMODCALLBACK)&MONUNIQUE_SetMonsterHoverName, (UMODCALLBACK)&MONUNIQUE_ApplyResistantMod, (UMODCALLBACK)&MONUNIQUE_ApplyResistantMod, 0, 0, 0, 0, (UMODCALLBACK)&MONUNIQUE_ApplyResistantMod, 0, (UMODCALLBACK)&MONUNIQUE_ApplyResistantMod, (UMODCALLBACK)&MONUNIQUE_AssignTeleportSkill, (UMODCALLBACK)&MONUNIQUE_ApplyResistantMod, (UMODCALLBACK)&MONUNIQUE_ApplyResistantMod, 0, 0, 0,
    0, 0, 0, 0, (UMODCALLBACK)&MONUNIQUE_SetMonsterHoverName, (UMODCALLBACK)&MONUNIQUE_SetMonsterHoverName, (UMODCALLBACK)&MONUNIQUE_SetMonsterHoverName, (UMODCALLBACK)&MONUNIQUE_SetMonsterHoverName
}; // 0x00724D78

extern D2UModCallbacksStrc gaUModCallbacks[43] = {
    { { 0 } },
    { { 0 } },
    { { 0 } },
    { { 0 } },
    { { 0 } },
    { { 0 } },
    { { 0 } },
    { { 0 } },
    { { 0 } },
    { { 0, 0, (void (__fastcall *)(D2UnitStrc*, int, int))&NPCMENU_StateOverlayCross } },
    { { 0, 0, (void (__fastcall *)(D2UnitStrc*, int, int))&NPCMENU_StateStartEffect } },
    { { 0, 0, (void (__fastcall *)(D2UnitStrc*, int, int))&NPCMENU_StateDurielDeath } },
    { { 0 } },
    { { 0 } },
    { { 0 } },
    { { 0 } },
    { { 0 } },
    { { 0, 0, (void (__fastcall *)(D2UnitStrc*, int, int))&NPCMENU_StateBurstOnFrame, (void (__fastcall *)(D2UnitStrc*, int, int))&NPCMENU_StateBurst } },
    { { 0, 0, (void (__fastcall *)(D2UnitStrc*, int, int))&NPCMENU_StateStartEffect } },
    { { 0 } },
    { { 0, 0, (void (__fastcall *)(D2UnitStrc*, int, int))&NPCMENU_StateBurstNeutral } },
    { { 0 } },
    { { 0, (void (__fastcall *)(D2UnitStrc*, int, int))&NPCMENU_HandleUnitClassEvent } },
    { { (void (__fastcall *)(D2UnitStrc*, int, int))&NPCMENU_StateBurstOnFrame } },
    { { 0 } },
    { { 0 } },
    { { 0 } },
    { { 0 } },
    { { 0 } },
    { { 0, 0, 0, 0, (void (__fastcall *)(D2UnitStrc*, int, int))&NPCMENU_StateMissileSplit } },
    { { 0 } },
    { { 0, 0, (void (__fastcall *)(D2UnitStrc*, int, int))&NPCMENU_StateOverlayBurst } },
    { { 0, 0, (void (__fastcall *)(D2UnitStrc*, int, int))&NPCMENU_StateOverlayAtPath } },
    { { 0, 0, (void (__fastcall *)(D2UnitStrc*, int, int))&NPCMENU_StateMonOverlay } },
    { { 0 } },
    { { 0 } },
    { { 0 } },
    { { 0 } },
    { { 0 } },
    { { 0 } },
    { { 0, 0, (void (__fastcall *)(D2UnitStrc*, int, int))&NPCMENU_StateRequestsCallback } },
    { { 0 } },
    { { 0, 0, (void (__fastcall *)(D2UnitStrc*, int, int))&NPCMENU_StateStartEffect } }
}; // 0x00724E28

extern unsigned short gwUniqueModNameIds[44] = {
    0, 0, 0, 0, 0, 0xC85, 0xC86, 0xC87, 0xC88, 0xC89, 0, 0, 0, 0, 0, 0,
    0, 0xC8B, 0xC8A, 0, 0, 0, 0, 0, 0xC91, 0xC8C, 0xC8E, 0xC8D, 0xC8F, 0xC90, 0xC92
}; // 0x00725188
