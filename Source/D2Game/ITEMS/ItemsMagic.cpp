#include "D2GameEvents.h"
#include "D2ObjectIds.h"
#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2SkillIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2GameRecords.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2Txt.h"
#include "D2TxtTables.h"
#include "D2ItemsWorld.h"
#include "D2UnitData.h"
#include "D2LevelTxt.h"
#include "D2AnimData.h"
#include "D2Path.h"
#include "D2ItemModes.h"
#include "D2Records.h"
#include "D2SetsTxt.h"
#include "D2GameAux.h"
#include "D2BookDataTbl.h"
#include "D2LanguageNames.h"
#include "FogApi.h"
#include "D2CommonApi.h"

#define IFLAG_TARGETING 4

#define UPDATEUI_CLOSEALL 17

#define UPDATEUI_OPENCUBE 21

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

struct D2ItemsTxt;

struct D2MonStatsTxt;

struct D2BooksTxt;


struct D2CurseStrc;

struct D2SkillsTxt;


union D2SeedStrc;

struct D2UnitStrc;

struct D2GameStrc;

struct D2DataTablesStrc;

struct D2DamageStrc;

struct D2AnimSeqTxt;

struct D2ItemStatCostTxt;


#include "D2GameFuncs.h"
#include "D2CommonApi2.h"
#include "D2CommonApi3.h"
#include "D2ClientApi.h"




extern D2pSpellTblStrc gaPSpellTable[]; // 0x00741790

void __fastcall D2GAME_PACKETS_SendPacketSize06(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId); // 0x0053B3D0



typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc*, int, D2StatListStrc*);


extern D2DataTablesStrc* sgptDataTables; // 0x00744304






void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10





extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0









enum D2C_Y09SkillConstants
{
    SKILLSFLAGINDEX_AURA = 5,
    SKILLSFLAGINDEX_IMMEDIATE = 15,
};

extern unsigned int gdwBitMasks[]; // 0x006CE268




extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09







typedef void (__fastcall* RemoveCallback)(D2UnitStrc*,int,D2StatListStrc*);


#define UNIT_PLAYER 0

#define UNIT_MONSTER 1

#define UNIT_ITEM 4

#define UNIT_INVALID 6

#define MONSTATS2FLAGINDEX_SMALL 10

#define MONSTATS2FLAGINDEX_LARGE 11

struct D2MonStats2Txt;




enum D2C_J10SkillItemConstants
{
    MONTYPEFLAG_UNIQUE_CHAMPION = 12,
    DAMAGERESULTFLAG_GETHIT = 4,
    DAMAGEHITFLAG_0x20 = 0x20,
    SKILLSFLAGINDEX_ITEMTGTDO = 29,
};


void __fastcall D2GAME_PACKETS_SendPacketSize06(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId); // 0x0053B3D0


static inline int GetUnitType(D2UnitStrc* unit) { return unit?unit->dwUnitType:UNIT_INVALID; }

struct D2AiControlStrc;

struct D2ActiveRoomStrc;

struct D2DynamicPathStrc;

struct D2SkillStrc;

struct D2StatListStrc;


enum D2C_G4Constants
{
    AISPECIALSTATE_NONE = 0,
    AISPECIALSTATE_DIMVISION = 10,
    AISPECIALSTATE_TERROR = 11,
    AISPECIALSTATE_TAUNT = 12,
    UNITFLAG_SKSRVDOFUNC = 0x40,
    UNITFLAGEX_TELEPORTED = 0x10000,
    UNITEVENTFLAG_IN_CALLBACK = 1,
    UNITEVENTFLAG_SHOULD_BE_FREED = 2,
    ITEMDROPFLAG_STAFFMODUSEILVL = 0x20,
    COLLIDE_MASK_PLAYER_FLYING = 0x804,
};












static short __stdcall ITEMS_RollMagicAffixesNew(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefixes, int nPreferredAffixIndex, int nAutoMagicGroup); // 0x005C1560





struct D2ModeChangeStrc;










enum D2C_SkillItemConstants
{
    UNITEVENT_13 = 13,
};



struct D2AffixIndexAndPtrStrc
{
    int nIndex;
    D2MagicAffixTxt* pAffix;
};


static inline int ClampLevel(int v) { if (v <= 1) return 1; if (v >= 99) return 99; return v; }

struct D2AiCmdStrc;

struct D2StaticPathStrc;



struct D2MagicAffixTxt;



struct D2RareAffixIndexAndPtrStrc;

struct D2SetItemsTxt;


D2PoolSystemStrc* __fastcall GFXUTIL_GetNextRosterInfo(D2UnitStrc*); // 0x004DC0B0




int __fastcall ITEMS_ApplyLegacyLowQuality(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C2AF0

int __fastcall ITEMS_ApplyLowQuality(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C2D40

static int ITEMMODS_HasAffixWithGroup(D2UnitStrc* pItem, int nGroup);

// noinline: ITEMS_RollMagicAffixesNew (0x005C1560) calls ITEMS_AddPotentialMagicAffix (0x005C0D00); the image calls it out of line there.
#include "D2LowQualityItemDataTbl.h"

// Kept noinline: ITEMS_RollMagicAffixesNew (0x005C1560) calls it out of line in the image; without it the compiler inlines it there.
// 0x005C0D00
static __declspec(noinline) int __stdcall ITEMS_AddPotentialMagicAffix(int nAffixId, D2MagicAffixTxt* pRecord, D2MagicAffixIndexAndPtrStrc* pAffixes, int nCount)
{
    if (nCount < 0x1FF)
    {
        pAffixes[nCount].pMagicAffixRecord = pRecord;
        pAffixes[nCount].nAffixId = nAffixId;
        ++nCount;
    }

    return nCount;
}

// 0x005C0D20
static D2MagicAffixIndexAndPtrStrc* __stdcall ITEMS_GetPotentialMagicAffix(int nCount, D2MagicAffixIndexAndPtrStrc* pAffixes, int nIndex)
{
    if (nIndex >= nCount)
    {
        return 0;
    }
    return &pAffixes[nIndex];
}

// Out of line as in the original: ITEMS_ApplyLegacyLowQuality (0x5C2AF0) and ITEMS_ApplyLowQuality (0x5C2D40) call it (0x5C2CAF, 0x5C2CD6, 0x5C2F11, 0x5C2F38).
// Kept noinline: ITEMS_ApplyLegacyLowQuality (0x005C2AF0) and ITEMS_ApplyLowQuality (0x005C2D40) call it out of line in the image; without it the compiler inlines it there.
// 0x005C0D40
static __declspec(noinline) int __stdcall SKILLITEM_PercentWithMinimum(int nValue, int nPercent, int nMin)
{
    const int nResult = nValue * nPercent / 100;
    if (nResult < nMin)
    {
        return nMin;
    }
    return nResult;
}

static inline unsigned int RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005C0D70
void __stdcall ITEMS_AssignLegacyStaffMods(D2UnitStrc* pItem, int nItemLevel, int nClassFirstSkillId)
{
    int nSkills[3] = { -1, -1, -1 };
    int nRoll = RollSeed(ITEMS_GetItemSeed(pItem)) % 100;
    int nSkillCount;
    if (nRoll > 90)
        nSkillCount = 3;
    else if (nRoll > 70)
        nSkillCount = 2;
    else if (nRoll > 30)
        nSkillCount = 1;
    else
        return;
    int nBaseTier = 1;
    if (nItemLevel > 24)
        nBaseTier = 4;
    else if (nItemLevel > 18)
        nBaseTier = 3;
    else if (nItemLevel > 11)
        nBaseTier = 2;
    for (int i = 0; i < nSkillCount; ++i)
    {
        nRoll = RollSeed(ITEMS_GetItemSeed(pItem)) % 100;
        int nTier = nBaseTier;
        if (nRoll > 80)
            nTier = nBaseTier + 1;
        else if (nRoll <= 30)
        {
            if (nRoll > 10)
                nTier = nBaseTier - 1;
            else
                nTier = nBaseTier - 2;
        }
        nItemLevel = nTier;
        if (nItemLevel < 1)
            nItemLevel = 1;
        int nSkillId;
        do
        {
            const int nSkillRoll = RollSeed(ITEMS_GetItemSeed(pItem)) % 5;
            nSkillId = nClassFirstSkillId + 5 * (nItemLevel - 1) + nSkillRoll;
        }
        while (nSkillId == SKILL_POISONDAGGER || nSkillId == nSkills[0] || nSkillId == nSkills[1] || nSkillId == nSkills[2]);
        nSkills[i] = nSkillId;
        nItemLevel = 1;
        nRoll = RollSeed(ITEMS_GetItemSeed(pItem)) % 100;
        if (nRoll >= 90)
            nItemLevel = 3;
        else if (nRoll >= 60)
            nItemLevel = 2;
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pItem, 0, 0x40);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(GFXUTIL_GetNextRosterInfo(pItem), 0x40, 0, 4, GAME_GetUnitGUID(pItem));
            D2COMMON_10475_PostStatToStatList(pItem, pStatList, 1);
        }
        if (pStatList)
            STATLIST_SetStatIfListIsValid(pStatList, STAT_ITEM_SINGLESKILL, nItemLevel, nSkillId);
    }
}


static inline D2SkillsTxt* GetSkillsRecord(int nSkill)
{
    if (nSkill >= 0 && nSkill < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkill];
    return 0;
}

// 0x005C0F90
void __stdcall ITEMS_AssignModernStaffMods(D2UnitStrc* pUnit, int nItemLvl, int nClassFirstSkillId, int nItemDropLvl)
{
    int skillIds[3] = { -1, -1, -1 };
    int nRand = nItemDropLvl + RollSeed(ITEMS_GetItemSeed(pUnit)) % 100;
    int nCount = 0;
    if (nRand > 90)
    {
        nCount = 3;
    }
    else if (nRand > 70)
    {
        nCount = 2;
    }
    else if (nRand > 30 || nItemDropLvl)
    {
        nCount = 1;
    }
    else
    {
        return;
    }

    int nBase = 1;
    if (nItemLvl > 36 && ITEMS_GetItemFormat(pUnit) >= 100u)
    {
        nBase = 5;
    }
    else if (nItemLvl > 24)
    {
        nBase = 4;
    }
    else if (nItemLvl > 18)
    {
        nBase = 3;
    }
    else if (nItemLvl > 11)
    {
        nBase = 2;
    }

    for (int j = 0; j < nCount; ++j)
    {
        nRand = RollSeed(ITEMS_GetItemSeed(pUnit)) % 100;
        int nBaseLayer = 0;
        if (nRand > 80)
        {
            nBaseLayer = nBase + 1;
        }
        else if (nRand > 30)
        {
            nBaseLayer = nBase;
        }
        else if (nRand > 10)
        {
            nBaseLayer = nBase - 1;
        }
        else
        {
            nBaseLayer = nBase - 2;
        }

        if (nBaseLayer < 1)
        {
            nBaseLayer = 1;
        }

        if (ITEMS_GetItemQuality(pUnit) == 1 && nBaseLayer >= 4)
        {
            nBaseLayer = 4;
        }

        int nSkillId;
        int nTries = 6;
        do
        {
            const int nRoll = RollSeed(ITEMS_GetItemSeed(pUnit)) % 5;
            nSkillId = nRoll + 5 * (nBaseLayer - 1) + nClassFirstSkillId;

            D2SkillsTxt* pSkillsTxtRecord = GetSkillsRecord(nSkillId);
            if (!pSkillsTxtRecord || pSkillsTxtRecord->nITypeA[0] <= 0 || ITEMSIsA(pUnit, pSkillsTxtRecord->nITypeA[0]))
            {
                if (nSkillId != skillIds[0] && nSkillId != skillIds[1] && nSkillId != skillIds[2])
                {
                    skillIds[j] = nSkillId;
                    break;
                }
                --nTries;
            }
            else
            {
                --nTries;
            }
        }
        while (nTries > 0);

        int nValue = 1;
        if (ITEMS_GetItemFormat(pUnit) < 100u || ITEMS_GetItemQuality(pUnit) != 1)
        {
            nRand = nItemDropLvl / 2 + RollSeed(ITEMS_GetItemSeed(pUnit)) % 100;
            if (nRand >= 90)
            {
                nValue = 3;
            }
            else if (nRand >= 60)
            {
                nValue = 2;
            }
        }

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pUnit, 0, 0x40u);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(GFXUTIL_GetNextRosterInfo(pUnit), 0x40u, 0, 4, GAME_GetUnitGUID(pUnit));
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        }

        if (pStatList)
        {
            STATLIST_SetStatIfListIsValid(pStatList, STAT_ITEM_SINGLESKILL, nValue, nSkillId);
        }
    }
}

// 0x005C1260
void __fastcall ITEMS_AssignStaffModsForFormat(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    const int nClassId = ITEMS_GetStaffMods(pItem);
    if (nClassId < 0 || nClassId >= NUMBER_OF_PLAYERCLASSES)
    {
        return;
    }

    if (SKILLS_GetPlayerSkillCount(nClassId) <= 0)
    {
        return;
    }

    const int nSkillId = SKILLS_GetClassSkillId(nClassId, 0);
    const int nItemLevel = pItemDrop->nItemLvl;
    if (!ITEMS_GetItemFormat(pItem))
    {
        ITEMS_AssignLegacyStaffMods(pItem, nItemLevel, nSkillId);
    }
    else
    {
        ITEMS_AssignModernStaffMods(pItem, nItemLevel, nSkillId, pItemDrop->dwFlags2 & ITEMDROPFLAG_STAFFMODUSEILVL ? pItemDrop->nItemLvl : 0);
    }
}

// 0x005C12F0
short __stdcall ITEMS_RollMagicAffixesOld(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex)
{
    D2AffixIndexAndPtrStrc tAffixes[512];
    D2MagicAffixDataTbl* pTable = DATATBLS_GetMagicAffixDataTables();
    if (!pTable) return 0;
    D2MagicAffixTxt* pRecord;
    int nCount;
    if (bPrefix) { pRecord = pTable->pMagicPrefix; nCount = pTable->pAutoMagic - pRecord; }
    else { pRecord = pTable->pMagicSuffix; nCount = pTable->pMagicPrefix - pRecord; }
    if (!pRecord) return 0;
    const int nFirstIndex = pRecord - pTable->pMagicAffixTxt;
    int nIndex = -1;
    int nMax = 0;
    const unsigned int nRoll = RollSeed(ITEMS_GetItemSeed(pItem));
    const unsigned short nFormat = ITEMS_GetItemFormat(pItem);
    if ((nRoll & 1) || bForceAffixRoll)
    {
        int nLevel = ITEMS_GetItemLevel(pItem) + 2;
        nLevel = D2_MIN(D2_MAX(nLevel, 1), 99);
        for (int i = 0; i < nCount; ++i)
        {
            if ((!bRequireSpawnableAffix || pRecord[i].bSpawnable) && (pRecord[i].wVersion < 100 || nFormat >= 100) && pRecord[i].nLevel <= nLevel && ITEMMODS_CanItemHaveMagicAffix(pItem, &pRecord[i]) && nMax < 511)
            {
                tAffixes[nMax].pAffix = &pRecord[i];
                tAffixes[nMax].nIndex = nFirstIndex + i;
                ++nMax;
            }
        }
        if (nMax <= 0) return 0;
        const int nRandom = SEED_RollInRange(ITEMS_GetItemSeed(pItem), 0, nMax);
        if (nRandom >= nMax) return 0;
        D2AffixIndexAndPtrStrc* pAffix = &tAffixes[nRandom];
        if (!pAffix) return 0;
        nIndex = pAffix->nIndex;
        if (nPreferredAffixIndex > 0)
        {
            nPreferredAffixIndex += nFirstIndex;
            if (nPreferredAffixIndex > 0)
            {
                for (int i = 0; i < nMax; ++i)
                {
                    D2AffixIndexAndPtrStrc* pCurrent = &tAffixes[i];
                    if (pCurrent->nIndex == nPreferredAffixIndex - 1)
                    {
                        nIndex = pCurrent->nIndex;
                        pAffix = pCurrent;
                        goto ApplyProperties;
                    }
                }
                nIndex = -1;
            }
        }
ApplyProperties:
        if (bAssignProperties) ITEMMODS_AssignProperty(0, 0, pItem, pAffix->pAffix, 0, 0);
    }
    return nIndex + 1;
}

unsigned short __fastcall ITEMS_RollMagicAffixes(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return ITEMS_RollMagicAffixesNew(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefix, nPreferredAffixIndex, 0);
    }

    return ITEMS_RollMagicAffixesOld(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefix, nPreferredAffixIndex);
}

short __fastcall ITEMS_RollMagicAffixes(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefixes, int nPreferredAffixIndex, int nAutoMagicGroup)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return ITEMS_RollMagicAffixesNew(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefixes, nPreferredAffixIndex, nAutoMagicGroup);
    }

    return ITEMS_RollMagicAffixesOld(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefixes, nPreferredAffixIndex);
}

// 0x005C1500
static int ITEMMODS_HasAffixWithGroup(D2UnitStrc* pItem, int nGroup)
{
    for (int i = 0; i < 3; ++i)
    {
        D2MagicAffixTxt* pAffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(pItem, i));
        if (!pAffix)
        {
            break;
        }

        if (pAffix->dwGroup == nGroup)
        {
            return 1;
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        D2MagicAffixTxt* pAffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(pItem, i));
        if (!pAffix)
        {
            break;
        }

        if (pAffix->dwGroup == nGroup)
        {
            return 1;
        }
    }

    return 0;
}

static inline int GetClassId(D2UnitStrc* pItem)
{
    if (!pItem) return -1;
    return pItem->dwClassId;
}

// 0x005C1560
static short __stdcall ITEMS_RollMagicAffixesNew(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefixes, int nPreferredAffixIndex, int nAutoMagicGroup)
{
    D2MagicAffixDataTbl* pTables = DATATBLS_GetMagicAffixDataTables();
    if (!pTables)
        return 0;

    D2MagicAffixTxt* pBegin;
    D2MagicAffixTxt* pEnd;
    int nCount;
    if (nAutoMagicGroup)
    {
        pBegin = pTables->pAutoMagic;
        pEnd = &pTables->pMagicAffixTxt[pTables->nMagicAffixTxtRecordCount];
        nCount = pEnd - pBegin;
    }
    else if (bPrefixes)
    {
        pBegin = pTables->pMagicPrefix;
        pEnd = pTables->pAutoMagic;
        nCount = pEnd - pBegin;
    }
    else
    {
        pBegin = pTables->pMagicSuffix;
        pEnd = pTables->pMagicPrefix;
        nCount = pEnd - pBegin;
    }

    if (!pBegin)
        return 0;
    const int nOffset = pBegin - pTables->pMagicAffixTxt;
    int nRolledAffixId = -1;
    int nPotentialCount = 0;
    D2SeedStrc* pSeed = ITEMS_GetItemSeed(pItem);
    unsigned __int64 nSeed = 0x6AC690C5ui64 * pSeed->nLowSeed + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    const unsigned short nFormat = ITEMS_GetItemFormat(pItem);
    int nTotalFrequency = 0;
    const int nQualityLevel = ITEMS_GetItemQlvl(pItem);
    if (((unsigned int)nSeed & 1) || bForceAffixRoll)
    {
        D2MagicAffixTxt* pRolledRecord;

        int nLevel = ITEMS_GetItemLevel(pItem);
        D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(GetClassId(pItem));
        if (!pItemsTxt)
            return 0;
        nLevel = D2_MAX(nLevel, nQualityLevel);
        const int nMagicLevel = pItemsTxt->nMagicLevel;
        if (nMagicLevel)
            nLevel += nMagicLevel;
        else
        {
            const int nDistance = 99 - (nQualityLevel / 2);
            if (nLevel < nDistance)
                nLevel -= (nQualityLevel / 2);
            else
                nLevel = 2 * nLevel - (nQualityLevel / 2) - nDistance;
        }
        nLevel = D2_MIN(D2_MAX(nLevel, 1), 99);

        D2MagicAffixIndexAndPtrStrc tAffixes[512];
        for (int i = 0; i < nCount; ++i)
        {
            D2MagicAffixTxt* pAffix = &pBegin[i];
            if (bRequireSpawnableAffix && !pAffix->bSpawnable)
                continue;
            if (pAffix->wVersion >= 100 && nFormat < 100)
                continue;
            int bPreferred;
            if (nPreferredAffixIndex > 0 && nPreferredAffixIndex - 1 == i)
                bPreferred = 1;
            else
            {
                bPreferred = 0;
                if (pAffix->nLevel > nLevel)
                    continue;
                if (pAffix->nMaxLevel && pAffix->nMaxLevel < nLevel)
                    continue;
            }
            if (!pAffix->bRare)
            {
                switch (ITEMS_GetItemQuality(pItem))
                {
                case ITEMQUAL_RARE:
                case ITEMQUAL_CRAFT:
                case ITEMQUAL_TEMPERED:
                    continue;
                }
            }
            if (!ITEMMODS_CanItemHaveMagicAffix(pItem, pAffix))
                continue;
            if (nAutoMagicGroup && nAutoMagicGroup != pAffix->dwGroup)
                continue;
            if (!pAffix->nFrequency)
                continue;
            if (pAffix->nClass != 255 && ITEMS_GetClassOfClassSpecificItem(pItem) != 7 && pAffix->nClass != ITEMS_GetClassOfClassSpecificItem(pItem))
                continue;
            if (ITEMMODS_HasAffixWithGroup(pItem, pAffix->dwGroup))
                continue;
            if (bPreferred)
            {
                nRolledAffixId = i + nOffset;
                pRolledRecord = pAffix;
                break;
            }
            nPotentialCount = ITEMS_AddPotentialMagicAffix(i + nOffset, pAffix, tAffixes, nPotentialCount);
            if (nMagicLevel)
                nTotalFrequency += pAffix->nFrequency * pAffix->nLevel;
            else
                nTotalFrequency += pAffix->nFrequency;
        }

        if (nRolledAffixId < 0)
        {
            if (nPotentialCount <= 0)
                return 0;
            int nRoll = SEED_RollInRange(ITEMS_GetItemSeed(pItem), 0, nTotalFrequency + 1);
            D2MagicAffixIndexAndPtrStrc* pRolled = 0;
            for (int i = 0; i < nPotentialCount; ++i)
            {
                pRolled = ITEMS_GetPotentialMagicAffix(nPotentialCount, tAffixes, i);
                if (!pRolled)
                    return 0;
                const D2MagicAffixTxt* pRecord = pRolled->pMagicAffixRecord;
                if (nMagicLevel)
                    nRoll -= pRecord->nFrequency * pRecord->nLevel;
                else
                    nRoll -= pRecord->nFrequency;
                if (nRoll < 0)
                    break;
            }
            if (!pRolled)
                return 0;
            nRolledAffixId = pRolled->nAffixId;
            pRolledRecord = pRolled->pMagicAffixRecord;
        }
        if (bAssignProperties)
            ITEMMODS_AssignProperty(0, 0, pItem, pRolledRecord, 0, 0);
    }
    return nRolledAffixId + 1;
}

// 0x005C19A0
static unsigned short __stdcall SKILLITEM_RollRareAffixLegacy(D2UnitStrc* pItem, int bPrefix)
{
    D2RareAffixIndexAndPtrStrc tAffixes[512];

    D2RareAffixDataTbl* pRareAffixDataTbl = DATATBLS_GetRareAffixDataTables();
    D2RareAffixTxt* pRareAffixTxtRecord = 0;
    if (bPrefix)
    {
        pRareAffixTxtRecord = pRareAffixDataTbl->pRarePrefix;
    }
    else
    {
        pRareAffixTxtRecord = pRareAffixDataTbl->pRareSuffix;
    }

    if (!pRareAffixTxtRecord)
    {
        return 0;
    }

    const int nAffixIndex = pRareAffixTxtRecord - pRareAffixDataTbl->pRareAffixTxt;
    int nCount = 0;
    if (bPrefix)
    {
        nCount = &pRareAffixDataTbl->pRareAffixTxt[pRareAffixDataTbl->nRareAffixTxtRecordCount] - pRareAffixDataTbl->pRarePrefix;
    }
    else
    {
        nCount = pRareAffixDataTbl->pRarePrefix - pRareAffixDataTbl->pRareSuffix;
    }

    int nMax = 0;
    for (int i = 0; i < nCount; ++i)
    {
        if (ITEMMODS_CanItemHaveRareAffix(pItem, &pRareAffixTxtRecord[i]) && nMax < 511)
        {
            tAffixes[nMax].pRareAffixRecord = &pRareAffixTxtRecord[i];
            tAffixes[nMax].nIndex = nAffixIndex + i;
            ++nMax;
        }
    }

    if (!nMax)
    {
        return 0;
    }

    const int nIndex = SEED_RollInRange(ITEMS_GetItemSeed(pItem), 0, nMax);
    if (nIndex >= nMax)
    {
        return 0;
    }

    D2RareAffixIndexAndPtrStrc* pAffix = &tAffixes[nIndex];
    if (!pAffix)
    {
        return 0;
    }

    return pAffix->nIndex + 1;
}

// 0x005C1AB0
static unsigned short __stdcall SKILLITEM_RollRareAffix(D2UnitStrc* pItem, int bPrefix)
{
    D2RareAffixIndexAndPtrStrc tAffixes[512];

    D2RareAffixDataTbl* pRareAffixDataTbl = DATATBLS_GetRareAffixDataTables();
    D2RareAffixTxt* pRareAffixTxtRecord = 0;
    if (bPrefix)
    {
        pRareAffixTxtRecord = pRareAffixDataTbl->pRarePrefix;
    }
    else
    {
        pRareAffixTxtRecord = pRareAffixDataTbl->pRareSuffix;
    }

    if (!pRareAffixTxtRecord)
    {
        return 0;
    }

    const int nAffixIndex = pRareAffixTxtRecord - pRareAffixDataTbl->pRareAffixTxt;
    int nCount = 0;
    if (bPrefix)
    {
        nCount = &pRareAffixDataTbl->pRareAffixTxt[pRareAffixDataTbl->nRareAffixTxtRecordCount] - pRareAffixDataTbl->pRarePrefix;
    }
    else
    {
        nCount = pRareAffixDataTbl->pRarePrefix - pRareAffixDataTbl->pRareSuffix;
    }

    int nMax = 0;
    for (int i = 0; i < nCount; ++i)
    {
        if (ITEMMODS_CanItemHaveRareAffix(pItem, &pRareAffixTxtRecord[i]) && nMax < 511)
        {
            tAffixes[nMax].pRareAffixRecord = &pRareAffixTxtRecord[i];
            tAffixes[nMax].nIndex = nAffixIndex + i;
            ++nMax;
        }
    }

    if (!nMax)
    {
        return 0;
    }

    const int nIndex = SEED_RollInRange(ITEMS_GetItemSeed(pItem), 0, nMax);
    if (nIndex >= nMax)
    {
        return 0;
    }

    D2RareAffixIndexAndPtrStrc* pAffix = &tAffixes[nIndex];
    if (!pAffix)
    {
        return 0;
    }

    return pAffix->nIndex + 1;
}

// 0x005C1BC0
unsigned short __fastcall ITEMS_RollTemperedItemAffix(D2UnitStrc* pItem, int bPrefix)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return SKILLITEM_RollRareAffix(pItem, bPrefix);
    }

    return SKILLITEM_RollRareAffixLegacy(pItem, bPrefix);
}

static inline unsigned short D2GAME_RollRareAffixInline(D2UnitStrc* pItem, int bPrefix)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return SKILLITEM_RollRareAffix(pItem, bPrefix);
    }

    return SKILLITEM_RollRareAffixLegacy(pItem, bPrefix);
}

static __forceinline void ITEMS_ApplyRareAffixesInline(D2UnitStrc* pItem)
{
    ITEMS_SetItemFlag(pItem, 0x10, 0);

    for (int nAffixSlot = 0; nAffixSlot < 3; ++nAffixSlot)
    {
        if (D2MagicAffixTxt* pPrefixRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(pItem, nAffixSlot)))
        {
            ITEMMODS_AssignProperty(0, 0, pItem, pPrefixRecord, 0, 0);
        }

        if (D2MagicAffixTxt* pSuffixRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(pItem, nAffixSlot)))
        {
            ITEMMODS_AssignProperty(0, 0, pItem, pSuffixRecord, 0, 0);
        }
    }
}

static inline unsigned int sub_RareSeedRoll(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int sub_RareSeedRollLimited(D2SeedStrc* pSeed, int nMax)
{
    if (nMax > 0)
    {
        if ((nMax - 1) & nMax)
        {
            return sub_RareSeedRoll(pSeed) % nMax;
        }
        else
        {
            return sub_RareSeedRoll(pSeed) & (nMax - 1);
        }
    }

    return 0;
}

// 0x005C1BF0
static int __stdcall ITEMS_RollRareItemNew(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem)
{
    int bSuffixesDone = 0;
    int bPrefixesDone = 0;

    const unsigned short nRarePrefix = D2GAME_RollRareAffixInline(pItem, 1);
    const unsigned short nRareSuffix = D2GAME_RollRareAffixInline(pItem, 0);
    if (!nRarePrefix || !nRareSuffix)
    {
        return 0;
    }

    ITEMS_AssignRarePrefix(pItem, nRarePrefix);
    ITEMS_AssignRareSuffix(pItem, nRareSuffix);

    int nPrefixes = 0;
    int nSuffixes = 0;
    D2SeedStrc* pSeed = ITEMS_GetItemSeed(pItem);

    int nAffixCount = 0;
    if (ITEMS_GetItemType(pItem) == ITEMTYPE_JEWEL)
    {
        nAffixCount = SEED_RollInRange(pSeed, 3, 2);
    }
    else
    {
        nAffixCount = gnRareAffixCounts[sub_RareSeedRollLimited(pSeed, 8)];
    }

    for (int i = 0; i < nAffixCount; ++i)
    {
        if (bPrefixesDone && bSuffixesDone)
        {
            break;
        }

        int bSuffix;
        if (bPrefixesDone)
        {
            bSuffix = 1;
        }
        else if (bSuffixesDone)
        {
            bSuffix = 0;
        }
        else
        {
            bSuffix = sub_RareSeedRoll(pSeed) & 1;
        }

        if (!bSuffix)
        {
            D2_ASSERT(nPrefixes < 3, 0x31D);

            const unsigned short nPrefix = ITEMS_RollMagicAffixesNew(pItem, 1, 1, 0, 1, pItemDrop->nPrefix[nPrefixes], 0);
            if (nPrefix > 0)
            {
                ITEMS_AssignPrefix(pItem, nPrefix, nPrefixes);
                ++nPrefixes;
                if (nPrefixes >= 3)
                {
                    bPrefixesDone = 1;
                }
            }
            else
            {
                bPrefixesDone = 1;
                --i;
            }
        }
        else
        {
            D2_ASSERT(nSuffixes < 3, 0x32E);

            const unsigned short nSuffix = ITEMS_RollMagicAffixesNew(pItem, 1, 1, 0, 0, pItemDrop->nSuffix[nSuffixes], 0);
            if (nSuffix > 0)
            {
                ITEMS_AssignSuffix(pItem, nSuffix, nSuffixes);
                ++nSuffixes;
                if (nSuffixes >= 3)
                {
                    bSuffixesDone = 1;
                }
            }
            else
            {
                bSuffixesDone = 1;
                --i;
            }
        }
    }

    if (!nPrefixes && !nSuffixes)
    {
        return 0;
    }

    ITEMS_ApplyRareAffixesInline(pItem);
    ITEMS_AssignStaffModsForFormat(pItem, pItemDrop);
    return 1;
}

static int __stdcall ITEMS_RollLegacyRareItem(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem); // 0x005C1E80

static __forceinline bool ITEMS_HasAffixOrGroupInline(D2UnitStrc* pItem, unsigned short nAffix, int bPrefix)
{
    for (int nAffixSlot = 0; nAffixSlot < 3; ++nAffixSlot)
    {
        const unsigned short nSlotAffix = bPrefix ? ITEMS_GetPrefixId(pItem, nAffixSlot) : ITEMS_GetSuffixId(pItem, nAffixSlot);
        if (D2MagicAffixTxt* pSlotRecord = DATATBLS_GetMagicAffixTxtRecord(nSlotAffix))
        {
            D2MagicAffixTxt* pAffixRecord = DATATBLS_GetMagicAffixTxtRecord(nAffix);
            if (nAffix == nSlotAffix || pAffixRecord->dwGroup == pSlotRecord->dwGroup)
            {
                return true;
            }
        }
    }

    return false;
}

static inline short ITEMS_RollMagicAffixesInline(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return ITEMS_RollMagicAffixesNew(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefix, nPreferredAffixIndex, 0);
    }

    return ITEMS_RollMagicAffixesOld(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefix, nPreferredAffixIndex);
}

// 0x005C1E80
static int __stdcall ITEMS_RollLegacyRareItem(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem)
{
    const unsigned short nRarePrefix = D2GAME_RollRareAffixInline(pItem, 1);
    const unsigned short nRareSuffix = D2GAME_RollRareAffixInline(pItem, 0);
    if (!nRarePrefix || !nRareSuffix)
    {
        return 0;
    }

    ITEMS_AssignRarePrefix(pItem, nRarePrefix);
    ITEMS_AssignRareSuffix(pItem, nRareSuffix);

    int nPrefixes = 0;
    int nSuffixes = 0;
    D2SeedStrc* pSeed = ITEMS_GetItemSeed(pItem);

    unsigned int nAffixCount = 0;
    if (ITEMS_GetItemType(pItem) == ITEMTYPE_JEWEL)
    {
        nAffixCount = SEED_RollInRange(pSeed, 3, 2);
    }
    else
    {
        nAffixCount = SEED_RollInRange(pSeed, 4, 3);
    }

    for (unsigned int i = 0; i < nAffixCount; ++i)
    {
        int bSuffix = sub_RareSeedRoll(pSeed) & 1;
        if (nPrefixes == 3)
        {
            bSuffix = 1;
        }
        else if (nSuffixes == 3)
        {
            bSuffix = 0;
        }

        if (!bSuffix)
        {
            int nAttempt = 0;
            while (1)
            {
                const unsigned short nPrefix = ITEMS_RollMagicAffixesInline(pItem, 1, 1, 0, 1, 0);
                if (nPrefix <= 0)
                {
                    break;
                }

                if (ITEMS_HasAffixOrGroupInline(pItem, nPrefix, 1))
                {
                    if (nAttempt++ > 250)
                    {
                        ITEMS_AssignPrefix(pItem, 0, nPrefixes);
                        break;
                    }
                }
                else
                {
                    ITEMS_AssignPrefix(pItem, nPrefix, nPrefixes);
                    ++nPrefixes;
                    break;
                }
            }
        }
        else
        {
            int nAttempt = 0;
            while (1)
            {
                const unsigned short nSuffix = ITEMS_RollMagicAffixesInline(pItem, 1, 1, 0, 0, 0);
                if (nSuffix <= 0)
                {
                    break;
                }

                if (ITEMS_HasAffixOrGroupInline(pItem, nSuffix, 0))
                {
                    if (nAttempt++ > 250)
                    {
                        ITEMS_AssignSuffix(pItem, 0, nSuffixes);
                        break;
                    }
                }
                else
                {
                    ITEMS_AssignSuffix(pItem, nSuffix, nSuffixes);
                    ++nSuffixes;
                    break;
                }
            }
        }
    }

    if (!nPrefixes && !nSuffixes)
    {
        return 0;
    }

    ITEMS_ApplyRareAffixesInline(pItem);
    ITEMS_AssignStaffModsForFormat(pItem, pItemDrop);
    return 1;
}

// 0x005C21A0
int __fastcall D2GAME_RollRareItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (!ITEMS_CanBeRare(pItem))
    {
        return 0;
    }

    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return ITEMS_RollRareItemNew(pItemDrop, pItem);
    }

    return ITEMS_RollLegacyRareItem(pItemDrop, pItem);
}

// 0x005C21D0
int __fastcall ITEMS_RollCraftedItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    const unsigned short nRarePrefix = D2GAME_RollRareAffixInline(pItem, 1);
    const unsigned short nRareSuffix = D2GAME_RollRareAffixInline(pItem, 0);
    if (!nRarePrefix || !nRareSuffix)
    {
        return 0;
    }

    ITEMS_AssignRarePrefix(pItem, nRarePrefix);
    ITEMS_AssignRareSuffix(pItem, nRareSuffix);

    int nPrefixes = 0;
    int nSuffixes = 0;
    D2SeedStrc* pSeed = ITEMS_GetItemSeed(pItem);

    const int nItemLvl = pItemDrop->nItemLvl;
    int nMinAffixes = 1;
    if (nItemLvl > 30)
    {
        nMinAffixes = 2;
    }
    if (nItemLvl > 50)
    {
        nMinAffixes = 3;
    }
    if (nItemLvl > 70)
    {
        nMinAffixes = 4;
    }

    unsigned int nAffixCount = sub_RareSeedRollLimited(pSeed, 5);
    if ((unsigned int)nMinAffixes > nAffixCount)
    {
        nAffixCount = nMinAffixes;
    }

    for (unsigned int i = 0; i < nAffixCount; ++i)
    {
        int bSuffix = sub_RareSeedRoll(pSeed) & 1;
        if (nPrefixes == 3)
        {
            bSuffix = 1;
        }
        else if (nSuffixes == 3)
        {
            bSuffix = 0;
        }

        if (!bSuffix)
        {
            int nAttempt = 0;
            while (1)
            {
                const unsigned short nPrefix = ITEMS_RollMagicAffixesInline(pItem, 1, 1, 0, 1, pItemDrop->nPrefix[nPrefixes]);
                if (ITEMS_HasAffixOrGroupInline(pItem, nPrefix, 1))
                {
                    if (nAttempt++ > 250)
                    {
                        ITEMS_AssignPrefix(pItem, 0, nPrefixes);
                        break;
                    }
                }
                else
                {
                    ITEMS_AssignPrefix(pItem, nPrefix, nPrefixes);
                    ++nPrefixes;
                    break;
                }
            }
        }
        else
        {
            int nAttempt = 0;
            while (1)
            {
                const unsigned short nSuffix = ITEMS_RollMagicAffixesInline(pItem, 1, 1, 0, 0, pItemDrop->nSuffix[nSuffixes]);
                if (ITEMS_HasAffixOrGroupInline(pItem, nSuffix, 0))
                {
                    if (nAttempt++ > 250)
                    {
                        ITEMS_AssignSuffix(pItem, 0, nSuffixes);
                        break;
                    }
                }
                else
                {
                    ITEMS_AssignSuffix(pItem, nSuffix, nSuffixes);
                    ++nSuffixes;
                    break;
                }
            }
        }
    }

    ITEMS_ApplyRareAffixesInline(pItem);
    ITEMS_AssignStaffModsForFormat(pItem, pItemDrop);
    return 1;
}


struct D2BookDataTbl;


// 0x005C2540
int __fastcall ITEMS_FindBookRecordIndex(D2UnitStrc* pItem, int bScroll)
{
    D2BookDataTbl* pBookDataTbl = DATATBLS_GetBookDataTables();
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pBookDataTbl)
    {
        return -1;
    }

    if (!pItemsTxtRecord)
    {
        return pBookDataTbl->nBooksTxtRecordCount;
    }

    if (!pBookDataTbl->pBooksTxt)
    {
        return pBookDataTbl->nBooksTxtRecordCount;
    }

    int nIndex = -1;
    for (int i = 0; i < pBookDataTbl->nBooksTxtRecordCount; ++i)
    {
        if (bScroll)
        {
            if (pItemsTxtRecord->dwCode == pBookDataTbl->pBooksTxt[i].dwScrollSpellCode)
            {
                nIndex = i;
                break;
            }
        }
        else if (pItemsTxtRecord->dwCode == pBookDataTbl->pBooksTxt[i].dwBookSpellCode)
        {
            nIndex = i;
            break;
        }
    }

    if (nIndex < 0)
    {
        nIndex = pBookDataTbl->nBooksTxtRecordCount;
    }
    return nIndex;
}

// 0x005C25C0
static int __stdcall ITEMS_RollSetItemRecord(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem)
{
    int nLegibleSets = 0;
    int nAccumulatedRarity = 0;
    int nIndex = -1;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem ? pItem->dwClassId : -1);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const unsigned short nItemFormat = ITEMS_GetItemFormat(pItem);
    const unsigned int dwCode = pItemsTxtRecord->dwCode;
    const int nItemLevel = ITEMS_GetItemLevel(pItem);
    int rarityData[512];

    D2SetItemsTxt* pSetItemsTxtRecord = sgptDataTables->pSetItemsTxt;
    const int nCount = sgptDataTables->nSetItemsTxtRecordCount;
    int i = 0;
    if (nCount <= 0)
    {
        return 0;
    }

    do
    {
        if ((pSetItemsTxtRecord->wVersion < 100 || nItemFormat >= 100) && pSetItemsTxtRecord->wLvl <= nItemLevel
            && dwCode == pSetItemsTxtRecord->dwItemCode
            && (pSetItemsTxtRecord->nSetId != 29 || pItemDrop->dwFlags2 & 1))
        {
            if ((unsigned int)pItemDrop->nItemIndex > 0 && pItemDrop->nItemIndex - 1 == i)
            {
                nIndex = i;
            }

            rarityData[2 * nLegibleSets] = i;
            rarityData[2 * nLegibleSets + 1] = pSetItemsTxtRecord->dwRarity;
            if (!pSetItemsTxtRecord->dwRarity)
            {
                rarityData[2 * nLegibleSets + 1] = 1;
            }

            nAccumulatedRarity += rarityData[2 * nLegibleSets + 1];
            ++nLegibleSets;
        }
        ++i;
        ++pSetItemsTxtRecord;
    }
    while (i < nCount);

    int nFileIndex = nIndex;
    if (nIndex < 0)
    {
        if (!nAccumulatedRarity)
        {
            return 0;
        }

        int nChance = ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nAccumulatedRarity);
        int nCounter = 0;
        while (nCounter < nLegibleSets)
        {
            if (nChance < rarityData[2 * nCounter + 1])
            {
                if (nCounter < 0)
                {
                    return 0;
                }

                nFileIndex = rarityData[2 * nCounter];
                goto LBL_SET;
            }

            nChance -= rarityData[2 * nCounter + 1];
            ++nCounter;
        }

        return 0;
    }

LBL_SET:
    ITEMS_SetFileIndex(pItem, nFileIndex);
    ITEMS_SetItemFlag(pItem, 0x10, 0);
    ITEMMODS_AssignProperty(4, 0, pItem, 0, 0, 0);
    return 1;
}

static inline unsigned __int64 SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0) return 0;
    if (nMax & (nMax - 1)) return (unsigned int)SEED_RollRandomNumberInline(pSeed) % nMax;
    return (nMax - 1) & (unsigned int)SEED_RollRandomNumberInline(pSeed);
}

// 0x005C2740
int __stdcall ITEMS_RollLegacySetItem(D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxt) return 0;
    const unsigned int nSavedSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(pItem));
    const unsigned short nFormat = ITEMS_GetItemFormat(pItem);
    const int nDurability = STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0);
    const int nMaxDurability = STATLIST_GetUnitBaseStat(pItem, STAT_MAXDURABILITY, 0);
    int nNew = 2 * nDurability;
    if (nNew >= 255) nNew = 255;
    STATLIST_SetUnitStat(pItem, STAT_DURABILITY, nNew, 0);
    nNew = 2 * nMaxDurability;
    if (nNew >= 255) nNew = 255;
    STATLIST_SetUnitStat(pItem, STAT_MAXDURABILITY, nNew, 0);
    D2SetsTxt* pSets = sgptDataTables->pSetsTxt;
    int i = 0;
    for (; i < sgptDataTables->nSetsTxtRecordCount; ++i)
    {
        if (pSets[i].wVersion >= 100) break;
    }
    const int nCount = i;
    const unsigned int nStart = SEED_RollLimitedRandomNumberInline(ITEMS_GetItemSeed(pItem), nCount);
    int nFileIndex = -1;
    for (i = 0; i < nCount; ++i)
    {
        D2SetsTxt* pSet = &pSets[(i + nStart) % nCount];
        if (pSet->wVersion < 100 || nFormat >= 100)
        {
            for (int j = 0; j < pSet->nSetItems; ++j)
            {
                if (pItemsTxt->dwCode == pSet->pSetItem[j]->dwItemCode)
                {
                    nFileIndex = pSet->pSetItem[j]->wSetItemId;
                    break;
                }
            }
        }
    }
    if (nFileIndex != -1)
    {
        ITEMS_SetFileIndex(pItem, nFileIndex);
        ITEMS_SetItemFlag(pItem, 0x10, 0);
        ITEMMODS_AssignProperty(4, 0, pItem, 0, 0, 0);
        return 1;
    }
    SEED_InitLowSeed(ITEMS_GetItemSeed(pItem), nSavedSeed);
    return 0;
}

// 0x005C2940
int __fastcall ITEMS_RollSetItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return ITEMS_RollSetItemRecord(pItemDrop, pItem);
    }

    return ITEMS_RollLegacySetItem(pItem);
}

static inline unsigned int ITEMS_RollItemSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int ITEMS_RollItemSeedLimited(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return ITEMS_RollItemSeed(pSeed) % nMax;
    }

    return ITEMS_RollItemSeed(pSeed) & (nMax - 1);
}

// 0x005C2970
static int __stdcall ITEMS_RollSuperiorItemRecord(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    D2QualityItemDataTbl* pQualityItemDataTbl = DATATBLS_GetQualityItemDataTables();
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pQualityItemDataTbl)
    {
        return 0;
    }

    if (!pItemsTxtRecord)
    {
        return 0;
    }

    int nCount = pQualityItemDataTbl->nQualityItemsTxtRecordCount;
    unsigned char bRecordChecked[10] = {};
    if (ITEMS_CheckIfThrowable(pItem) || pItemsTxtRecord->nNoDurability)
    {
        nCount = 4;
    }

    while (1)
    {
        const unsigned int nFileIndex = ITEMS_RollItemSeedLimited(ITEMS_GetItemSeed(pItem), nCount);
        if (bRecordChecked[nFileIndex])
        {
            continue;
        }

        D2QualityItemsTxt* pQualityItemsTxtRecord = DATATBLS_GetQualityItemsTxtRecord(nFileIndex);
        if (!pQualityItemsTxtRecord)
        {
            return 0;
        }

        if (ITEMMODS_CanItemBeHighQuality(pItem, pQualityItemsTxtRecord))
        {
            ITEMS_SetFileIndex(pItem, nFileIndex);
            ITEMMODS_AssignProperty(1, 0, pItem, pQualityItemsTxtRecord, 0, 0);
            ITEMS_AssignStaffModsForFormat(pItem, pItemDrop);
            return 1;
        }

        bRecordChecked[nFileIndex] = 1;

        int bAllChecked = 1;
        for (int i = 0; i < nCount; ++i)
        {
            if (!bRecordChecked[i])
            {
                bAllChecked = 0;
                break;
            }
        }

        if (bAllChecked)
        {
            return 0;
        }
    }
}

// 0x005C2AD0
int __fastcall ITEMS_RollSuperiorItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    ITEMS_GetItemFormat(pItem);
    return ITEMS_RollSuperiorItemRecord(pItem, pItemDrop);
}

// 0x005C2AF0
int __fastcall ITEMS_ApplyLegacyLowQuality(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    D2LowQualityItemDataTbl* pLowQualityItemDataTbl = DATATBLS_GetLowQualityItemDataTables();
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pLowQualityItemDataTbl)
    {
        return 0;
    }

    if (!pItemsTxtRecord)
    {
        return 0;
    }

    ITEMS_SetFileIndex(pItem, SEED_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), pLowQualityItemDataTbl->nLowQualityItemsTxtRecordCount));

    int nResult = 0;
    if (ITEMS_HasDurability(pItem))
    {
        if (D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId))
        {
            unsigned int nMaxDurability = pTxt->nDurability / 3;
            if (!nMaxDurability)
            {
                nMaxDurability = 1;
            }

            const unsigned int nHalf = nMaxDurability / 2;
            unsigned int nDurability = ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nHalf) + nHalf;
            if (!nDurability)
            {
                nDurability = 1;
            }

            STATLIST_SetUnitStat(pItem, STAT_DURABILITY, nDurability, 0);
            STATLIST_SetUnitStat(pItem, STAT_MAXDURABILITY, nMaxDurability, 0);
        }
    }

    if (ITEMSIsA(pItem, 0x2D))
    {
        int nMaxDamage = 75 * STATLIST_GetUnitBaseStat(pItem, STAT_MAXDAMAGE, 0) / 100;
        if (nMaxDamage < 2)
        {
            nMaxDamage = 2;
        }
        STATLIST_SetUnitStat(pItem, STAT_MAXDAMAGE, nMaxDamage, 0);

        int nMinDamage = 75 * STATLIST_GetUnitBaseStat(pItem, STAT_MINDAMAGE, 0) / 100;
        if (nMinDamage < 1)
        {
            nMinDamage = 1;
        }
        STATLIST_SetUnitStat(pItem, STAT_MINDAMAGE, nMinDamage, 0);

        int nMaxSecondaryDamage = 75 * STATLIST_GetUnitBaseStat(pItem, STAT_SECONDARY_MAXDAMAGE, 0) / 100;
        if (nMaxSecondaryDamage < 2)
        {
            nMaxSecondaryDamage = 2;
        }
        STATLIST_SetUnitStat(pItem, STAT_SECONDARY_MAXDAMAGE, nMaxSecondaryDamage, 0);

        int nMinSecondaryDamage = 75 * STATLIST_GetUnitBaseStat(pItem, STAT_SECONDARY_MINDAMAGE, 0) / 100;
        if (nMinSecondaryDamage < 1)
        {
            nMinSecondaryDamage = 1;
        }
        STATLIST_SetUnitStat(pItem, STAT_SECONDARY_MINDAMAGE, nMinSecondaryDamage, 0);

        if (ITEMS_CheckIfThrowable(pItem))
        {
            const int nMinThrowDamage = SKILLITEM_PercentWithMinimum(STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROW_MINDAMAGE, 0), 75, 2);
            STATLIST_SetUnitStat(pItem, STAT_ITEM_THROW_MINDAMAGE, nMinThrowDamage, 0);

            const int nMaxThrowDamage = SKILLITEM_PercentWithMinimum(STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROW_MAXDAMAGE, 0), 75, 1);
            STATLIST_SetUnitStat(pItem, STAT_ITEM_THROW_MAXDAMAGE, nMaxThrowDamage, 0);
        }
        nResult = 1;
    }
    else if (ITEMSIsA(pItem, 0x32))
    {
        int nArmorClass = 75 * STATLIST_GetUnitBaseStat(pItem, STAT_ARMORCLASS, 0) / 100;
        if (nArmorClass <= 0)
        {
            nArmorClass = 1;
        }
        STATLIST_SetUnitStat(pItem, STAT_ARMORCLASS, nArmorClass, 0);
        nResult = 1;
    }

    return nResult;
}

// 0x005C2D40
int __fastcall ITEMS_ApplyLowQuality(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    D2LowQualityItemDataTbl* pLowQualityItemDataTbl = DATATBLS_GetLowQualityItemDataTables();
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pLowQualityItemDataTbl)
    {
        return 0;
    }

    if (!pItemsTxtRecord)
    {
        return 0;
    }

    ITEMS_SetFileIndex(pItem, SEED_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), pLowQualityItemDataTbl->nLowQualityItemsTxtRecordCount));

    int nResult = 0;
    if (ITEMS_HasDurability(pItem))
    {
        if (D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId))
        {
            int nMaxDurability = 33 * pTxt->nDurability / 100;
            if (nMaxDurability < 1)
            {
                nMaxDurability = 1;
            }

            const unsigned int nHalf = (unsigned int)nMaxDurability / 2;
            unsigned int nDurability = ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nHalf) + nHalf;
            if (!nDurability)
            {
                nDurability = 1;
            }

            STATLIST_SetUnitStat(pItem, STAT_DURABILITY, nDurability, 0);
            STATLIST_SetUnitStat(pItem, STAT_MAXDURABILITY, nMaxDurability, 0);
        }
    }

    if (ITEMSIsA(pItem, 0x2D))
    {
        int nMaxDamage = 75 * STATLIST_GetUnitBaseStat(pItem, STAT_MAXDAMAGE, 0) / 100;
        if (nMaxDamage < 2)
        {
            nMaxDamage = 2;
        }
        STATLIST_SetUnitStat(pItem, STAT_MAXDAMAGE, nMaxDamage, 0);

        int nMinDamage = 75 * STATLIST_GetUnitBaseStat(pItem, STAT_MINDAMAGE, 0) / 100;
        if (nMinDamage < 1)
        {
            nMinDamage = 1;
        }
        STATLIST_SetUnitStat(pItem, STAT_MINDAMAGE, nMinDamage, 0);

        int nMaxSecondaryDamage = 75 * STATLIST_GetUnitBaseStat(pItem, STAT_SECONDARY_MAXDAMAGE, 0) / 100;
        if (nMaxSecondaryDamage < 2)
        {
            nMaxSecondaryDamage = 2;
        }
        STATLIST_SetUnitStat(pItem, STAT_SECONDARY_MAXDAMAGE, nMaxSecondaryDamage, 0);

        int nMinSecondaryDamage = 75 * STATLIST_GetUnitBaseStat(pItem, STAT_SECONDARY_MINDAMAGE, 0) / 100;
        if (nMinSecondaryDamage < 1)
        {
            nMinSecondaryDamage = 1;
        }
        STATLIST_SetUnitStat(pItem, STAT_SECONDARY_MINDAMAGE, nMinSecondaryDamage, 0);

        if (ITEMS_CheckIfThrowable(pItem))
        {
            const int nMinThrowDamage = SKILLITEM_PercentWithMinimum(STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROW_MINDAMAGE, 0), 75, 2);
            STATLIST_SetUnitStat(pItem, STAT_ITEM_THROW_MINDAMAGE, nMinThrowDamage, 0);

            const int nMaxThrowDamage = SKILLITEM_PercentWithMinimum(STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROW_MAXDAMAGE, 0), 75, 1);
            STATLIST_SetUnitStat(pItem, STAT_ITEM_THROW_MAXDAMAGE, nMaxThrowDamage, 0);
        }
        nResult = 1;
    }
    else if (ITEMSIsA(pItem, 0x32))
    {
        int nArmorClass = 75 * STATLIST_GetUnitBaseStat(pItem, STAT_ARMORCLASS, 0) / 100;
        if (nArmorClass <= 0)
        {
            nArmorClass = 1;
        }
        STATLIST_SetUnitStat(pItem, STAT_ARMORCLASS, nArmorClass, 0);
        nResult = 1;
    }

    ITEMS_AssignStaffModsForFormat(pItem, pItemDrop);
    return nResult;
}

// 0x005C2FB0
int __fastcall ITEMS_ApplyLowQualityForFormat(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return ITEMS_ApplyLowQuality(pItem, pItemDrop);
    }

    return ITEMS_ApplyLegacyLowQuality(pItem, pItemDrop);
}

// 0x005C2FE0
int __cdecl sub_005C2FE0_Return43()
{
    return 43;
}

// 0x005C2FF0
void __fastcall SKILLS_DamagePaladinCaster(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwClassId == PCLASS_PALADIN)
    {
        const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);

        D2DamageStrc damage;
        memset(&damage, 0x00, sizeof(damage));

        damage.dwHitFlags |= 0x1000;
        damage.wResultFlags |= 4;
        damage.dwPhysDamage = nMaxHp / 8;
        damage.dwDmgTotal = nMaxHp / 8;

        SUNITDMG_ExecuteEvents(pGame, pUnit, pUnit, 0, &damage);
        SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pUnit, &damage);
    }
}


extern "C" void __cdecl SKILLITEM_pSpell08_ExperienceElixir(); // 0x005BF060
extern "C" void __cdecl SKILLITEM_pSpell09_AntidoteThawingPotion(); // 0x005BEF90
extern "C" void __cdecl sub_005BE3F0(); // 0x005BE3F0
extern "C" void __cdecl sub_005BE7B0(); // 0x005BE7B0
extern "C" void __cdecl sub_005BEAC0(); // 0x005BEAC0

extern "C" const int gData_006E3014[8]; // 0x006E3014

extern "C" const int gData_006E3014[8] = { 3, 4, 4, 5, 5, 5, 6, 6 }; // 0x006E3014
#pragma comment(linker, "/alternatename:?gnRareAffixCounts@@3QBHB=_gData_006E3014")
