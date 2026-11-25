#include "D2ItemTypes.h"
#include "D2Txt.h"
#include "D2Path.h"
#include "D2ItemsWorld.h"
#include "D2GameRecords.h"
#include "D2DataTbls.h"
#include "D2GameAux.h"
struct D2UnitStrc;


struct D2RareAffixDataTbl
{
    int nRareAffixTxtRecordCount;
    D2RareAffixTxt* pRareAffixTxt;
    D2RareAffixTxt* pRareSuffix;
    D2RareAffixTxt* pRarePrefix;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

short __stdcall ITEMS_RollMagicAffixesOld(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex); // 0x005C12F0
void __fastcall ITEMS_AssignStaffModsForFormat(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop);               // 0x005C1260
void __stdcall ITEMS_AssignPrefix(D2UnitStrc* pItem, unsigned short nPrefix, int nPrefixNo);               // 0x00627EF0
void __stdcall ITEMS_AssignSuffix(D2UnitStrc* pItem, unsigned short nSuffix, int nSuffixNo);               // 0x00627FB0
void __stdcall ITEMS_AssignRarePrefix(D2UnitStrc* pItem, unsigned short nPrefix);                           // 0x00628010
void __stdcall ITEMS_AssignRareSuffix(D2UnitStrc* pItem, unsigned short nSuffix);                           // 0x00628070
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
int __stdcall ITEMS_CanBeRare(D2UnitStrc* pItem);                                                           // 0x0062E990
D2RareAffixDataTbl* __fastcall DATATBLS_GetRareAffixDataTables();                                           // 0x00634250
int __stdcall ITEMMODS_CanItemHaveRareAffix(D2UnitStrc* pItem, const D2RareAffixTxt* pRareAffixTxtRecord); // 0x0065E710
extern const int gnRareAffixCounts[];                                                              // 0x006E3014
extern "C" void __stdcall sub_00627EF0(D2UnitStrc* pItem, unsigned short nPrefix, int nPrefixNo);        // 0x00627EF0
extern "C" void __stdcall sub_00627FB0(D2UnitStrc* pItem, unsigned short nSuffix, int nSuffixNo);        // 0x00627FB0
extern "C" void __stdcall sub_00628070(D2UnitStrc* pItem, unsigned short nSuffix);                       // 0x00628070
D2MagicAffixDataTbl* __stdcall DATATBLS_GetMagicAffixDataTables(); // 0x00633ED0
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem); // 0x00627D90
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem); // 0x0062A670
unsigned char __stdcall ITEMS_GetItemQlvl(const D2UnitStrc* hItem); // 0x00628740
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem); // 0x006281E0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nClassId); // 0x006335F0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
int __stdcall ITEMMODS_CanItemHaveMagicAffix(D2UnitStrc* pItem, const D2MagicAffixTxt* pMagicAffixTxtRecord); // 0x0065E620
int __stdcall ITEMS_GetClassOfClassSpecificItem(D2UnitStrc* pItem); // 0x0062C0B0
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280
void __stdcall ITEMMODS_AssignProperty(int nMode, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pProperty, int nSet, int nUnused); // 0x0065FEC0
unsigned short __stdcall ITEMS_GetPrefixId(D2UnitStrc* pItem, int nPrefixNo); // 0x00627EC0
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80
D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex); // 0x00633EE0

// Out of line as in the original: it takes arguments in eax, ecx and edx, a convention the compiler gives only a static whose callers are all in this object.
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

// 0x005C1500
static int ITEMMODS_HasAffixWithGroup(D2UnitStrc* pItem, int nGroup)
{
    for (int i = 0; i < 3; ++i)
    {
        D2MagicAffixTxt* pAffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(pItem, i));
        if (!pAffix) break;
        if (pAffix->dwGroup == nGroup) return 1;
    }
    for (int i = 0; i < 3; ++i)
    {
        D2MagicAffixTxt* pAffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(pItem, i));
        if (!pAffix) break;
        if (pAffix->dwGroup == nGroup) return 1;
    }
    return 0;
}

static inline D2MagicAffixIndexAndPtrStrc* GetPotentialMagicAffix(D2MagicAffixIndexAndPtrStrc* pAffixes, int nIndex, int nCount)
{
    if (nIndex >= nCount) return 0;
    return pAffixes;
}
#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))
static inline int GetClassId(D2UnitStrc* pItem)
{
    if (!pItem) return -1;
    return pItem->dwClassId;
}

static short __stdcall ITEMS_RollMagicAffixesNew(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefixes, int nPreferredAffixIndex, int nAutoMagicGroup);

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
            int nRoll = sub_00472280(ITEMS_GetItemSeed(pItem), 0, nTotalFrequency + 1);
            D2MagicAffixIndexAndPtrStrc* pRolled = 0;
            for (int i = 0; i < nPotentialCount; ++i)
            {
                pRolled = GetPotentialMagicAffix(&tAffixes[i], i, nPotentialCount);
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

short __fastcall ITEMS_RollMagicAffixes(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return ITEMS_RollMagicAffixesNew(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefix, nPreferredAffixIndex, 0);
    }

    return ITEMS_RollMagicAffixesOld(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefix, nPreferredAffixIndex);
}

short __fastcall ITEMS_RollMagicAffixes(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefixes, int nPreferredAffixIndex, int nAutoMagicGroup); // 0x005C1940

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

unsigned short __stdcall SKILLITEM_RollRareAffixLegacy(D2UnitStrc* pItem, int bPrefix); // 0x005C19A0

unsigned short __stdcall SKILLITEM_RollRareAffix(D2UnitStrc* pItem, int bPrefix); // 0x005C1AB0

static inline unsigned short D2GAME_RollRareAffixInline(D2UnitStrc* pItem, int bPrefix)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return SKILLITEM_RollRareAffix(pItem, bPrefix);
    }

    return SKILLITEM_RollRareAffixLegacy(pItem, bPrefix);
}

static inline bool ITEMS_HasAffixOrGroupInline(D2UnitStrc* pItem, unsigned short nAffix, int bPrefix)
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

static inline void ITEMS_ApplyRareAffixesInline(D2UnitStrc* pItem)
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

int __stdcall sub_005C1BF0_RollRareItemNew(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem); // 0x005C1BF0

int __stdcall ITEMS_RollLegacyRareItem(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem); // 0x005C1E80

int __fastcall D2GAME_RollRareItem_6FC53360(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C21A0

int __fastcall ITEMS_RollCraftedItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C21D0
