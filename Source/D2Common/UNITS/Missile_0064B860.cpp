#include "D2Common.h"
#include "D2StatIds.h"

#include "D2Win32Base.h"

#include "D2StormLink.h"

#include "D2CmpCache.h"

#include "D2Unicode.h"

#include "D2Drlg.h"

#include "D2DrlgRooms.h"

#include "D2DrlgTiles.h"

#include "D2Path.h"

#include "D2Win32Types.h"

#include "D2TxtTables.h"

#include "D2Structs.h"

#include "D2DataTbls.h"

#include "D2Txt.h"

#include "D2Skills.h"
#include "D2MissileData.h"


extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430

void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0

int __fastcall SKILLS_CalculateDamageBonusByLevel(int nLevel, int* pLevelDamage);                           // 0x00644B70

int __stdcall SKILLS_GetSpecialParamValue(D2UnitStrc* pUnit, int nParamId, int nSkillId, int nSkillLevel);  // 0x00646460

int __stdcall MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel); // 0x0064B7C0

extern unsigned int gdwBitMasks[]; // 0x006CE268

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

enum NumericGroups
{
    N_m90 = -90,
    N_m48 = -48,
    N_m44 = -44,
    N_m40 = -40,
    N_m36 = -36,
    N_m32 = -32,
    N_m28 = -28,
    N_m24 = -24,
    N_m20 = -20,
    N_m16 = -16,
    N_m12 = -12,
    N_m8 = -8,
    N_m4 = -4,
    N_m1 = -1,
    N_0 = 0,
    N_1 = 1,
    N_2 = 2,
    N_3 = 3,
    N_4 = 4,
    N_5 = 5,
    N_6 = 6,
    N_7 = 7,
    N_8 = 8,
    N_9 = 9,
    N_10 = 10,
    N_11 = 11,
    N_12 = 12,
    N_16 = 16,
    N_17 = 17,
    N_18 = 18,
    N_20 = 20,
    N_21 = 21,
    N_22 = 22,
    N_23 = 23,
    N_24 = 24,
    N_25 = 25,
    N_28 = 28,
    N_31 = 31,
    N_32 = 32,
    N_36 = 36,
    N_40 = 40,
    N_44 = 44,
    N_48 = 48,
    N_49 = 49,
    N_50 = 50,
    N_51 = 51,
    N_52 = 52,
    N_53 = 53,
    N_54 = 54,
    N_55 = 55,
    N_56 = 56,
    N_57 = 57,
    N_58 = 58,
    N_59 = 59,
    N_60 = 60,
    N_62 = 62,
    N_64 = 64,
    N_68 = 68,
    N_72 = 72,
    N_76 = 76,
    N_80 = 80,
    N_84 = 84,
    N_88 = 88,
    N_92 = 92,
    N_96 = 96,
    N_100 = 100,
    N_101 = 101,
    N_103 = 103,
    N_104 = 104,
    N_106 = 106,
    N_108 = 108,
    N_112 = 112,
    N_116 = 116,
    N_120 = 120,
    N_121 = 121,
    N_122 = 122,
    N_124 = 124,
    N_127 = 127,
    N_128 = 128,
    N_141 = 141,
    N_159 = 159,
    N_160 = 160,
    N_228 = 228,
    N_255 = 255,
    N_256 = 256,
    N_301 = 301,
    N_302 = 302,
    N_303 = 303,
    N_315 = 315,
    N_316 = 316,
    N_317 = 317,
    N_326 = 326,
    N_329 = 329,
    N_330 = 330,
    N_331 = 331,
    N_332 = 332,
    N_337 = 337,
    N_404 = 404,
    N_420 = 420,
    N_421 = 421,
    N_476 = 476,
    N_512 = 512,
    N_1024 = 1024,
    N_2916 = 2916,
    N_2924 = 2924,
    N_1374389535 = 1374389535,
    N_1791398085 = 1791398085,
};

struct Unit
{
    int type;
    int classId;
    char padding_seedLow[N_32 - N_4 - sizeof(int)];
    unsigned int f_20;
    unsigned int f_24;
    char padding_inventory[N_96 - N_36 - sizeof(unsigned int)];
    void* inventory;
};

struct MissileRecord
{
    char padding_flags[N_5];
    unsigned char flags;
    char padding_element[N_228 - N_5 - sizeof(unsigned char)];
    unsigned char element;
    char padding_sourceDamage[N_301 - N_228 - sizeof(unsigned char)];
    unsigned char sourceDamage;
    unsigned char originDamage;
    unsigned char hitFlags;
    char padding_skill[N_404 - N_303 - sizeof(unsigned char)];
    short skill;
    char padding_tail[N_420 - N_404 - sizeof(short)];
};

struct SkillRecord
{
    char padding_sourceDamage[N_421];
    unsigned char sourceDamage;
    char padding_element[N_476 - N_421 - sizeof(unsigned char)];
    unsigned char element;
};

struct DataTables
{
    char padding_missiles[N_2916];
    MissileRecord* missiles;
    char padding_missileCount[N_2924 - N_2916 - sizeof(MissileRecord*)];
    int missileCount;
};

struct Damage
{
    int flags;
    int physicalMin;
    int physicalMax;
    int fireMin;
    int fireMax;
    int fireLength;
    int lightMin;
    int lightMax;
    int magicMin;
    int magicMax;
    int coldMin;
    int coldMax;
    int coldLength;
    int poisonMin;
    int poisonMax;
    int poisonLength;
    int poisonCount;
    int lifeMin;
    int lifeMax;
    int manaMin;
    int manaMax;
    int staminaMin;
    int staminaMax;
    int stunLength;
    int burnMin;
    int burnMax;
    int burnLength;
    int demonBonus;
    int undeadBonus;
    int armorReduction;
    int percent;
};

extern "C" int __stdcall sub_00625480_GetStat(Unit*, int, unsigned short); // 0x00625480

extern "C" int __stdcall sub_00625500_GetBaseStat(Unit*, int, unsigned short); // 0x00625500

extern "C" short __stdcall sub_00629860_GetStrengthFactor(Unit*); // 0x00629860

extern "C" short __stdcall sub_006298A0_GetDexterityFactor(Unit*); // 0x006298A0

extern "C" int __stdcall MISSILE_GetElementalLength(Unit*, Unit*, int, int); // 0x0064B2A0

extern "C" DataTables* gVar_00744304; // 0x00744304

struct D2MissileDataStrc0064A280
{
    unsigned int unk0x00;
    unsigned int unk0x04;
    unsigned short unk0x08;
    short nSkill;
};

struct D2MissileUnitStrc0064A280
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MissileDataStrc0064A280* pMissileData;
};

// __forceinline: 0x64A470 inlines this lookup; with plain inline it stays a call there
__forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

static inline unsigned int GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit) return 0xFFFFFFFFu;
    return pUnit->dwUnitId;
}

static inline int GetUnitType(D2UnitStrc* pUnit)
{
    if (!pUnit) return 6;
    return pUnit->dwUnitType;
}











unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

int __stdcall MISSILE_GetSpecialParamValue(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned char nParamId, int nMissileId, int nLevel); // 0x0064B340

extern D2DataTablesStrc* gpDataTables_00744304; // 0x00744304

static inline D2MissilesTxt* GetMissileRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < gpDataTables_00744304->nMissilesTxtRecordCount)
        return &gpDataTables_00744304->pMissilesTxt[nMissileId];
    return 0;
}


int __stdcall D2Common_11033(int nLevel, int nParam, int nMax); // 0x00645B20
extern void* gpfnMissileCalcFunctions[]; // 0x00745828
extern int gnMissileCalcFunctionCount; // 0x00745848
static int sub_0044BE50(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }
    return nType;
}
static unsigned int MISSILE_GetLevel(D2UnitStrc* pMissile)
{
    D2MissileDataStrc* pMissileData = sub_0044BE50(pMissile) == 3 ? pMissile->pMissileData : 0;
    if (!pMissileData)
    {
        return 0;
    }

    return pMissileData->nLevel;
}





static __forceinline unsigned int RollPercent(Unit* unit)
{
    unsigned __int64 next = (unsigned __int64)unit->f_24
        + (unsigned __int64)unit->f_20 * 1791398085u;
    unit->f_24 = (unsigned int)(next >> 32);
    unit->f_20 = (unsigned int)next;
    return (unsigned int)next % 100u;
}

// build: symbol ?MISSILE_CheckCritical@* 0x0064A850
static int __stdcall MISSILE_CheckCritical(Unit* unit, Unit* item)
{
    int chance = sub_00625480_GetStat(unit, 337, 0);
    if ((int)RollPercent(unit) < chance)
        return 1;
    chance = sub_00625500_GetBaseStat(unit, 141, 0);
    if (chance)
    {
        if ((int)RollPercent(unit) < chance)
            return 1;
    }
    if (item)
    {
        chance = sub_00645830_GetItemBonus(unit, item, 0, 2);
        if (chance)
        {
            if ((int)RollPercent(unit) < chance)
                return 1;
        }
    }
    return 0;
}

// build: symbol ?MISSILE_AddElements@* 0x0064A930
static void MISSILE_AddElements(Damage* damage, Unit* unit, int shift)
{
    damage->fireMin += sub_00625480_GetStat(unit, 48, 0) << shift;
    damage->fireMax += sub_00625480_GetStat(unit, 49, 0) << shift;
    damage->lightMin += sub_00625480_GetStat(unit, 50, 0) << shift;
    damage->lightMax += sub_00625480_GetStat(unit, 51, 0) << shift;
    damage->magicMin += sub_00625480_GetStat(unit, 52, 0) << shift;
    damage->magicMax += sub_00625480_GetStat(unit, 53, 0) << shift;
    damage->coldMin += sub_00625480_GetStat(unit, 54, 0) << shift;
    damage->coldMax += sub_00625480_GetStat(unit, 55, 0) << shift;
    damage->coldLength += sub_00625480_GetStat(unit, 56, 0);
    damage->poisonMin += sub_00625480_GetStat(unit, 57, 0);
    damage->poisonMax += sub_00625480_GetStat(unit, 58, 0);
    int length = sub_00625480_GetStat(unit, 101, 0);
    if (length > 0)
        damage->poisonLength += length;
    else
    {
        damage->poisonLength += sub_00625480_GetStat(unit, 59, 0);
        damage->poisonCount += sub_00625480_GetStat(unit, 326, 0);
    }
    damage->lifeMin += sub_00625480_GetStat(unit, 60, 0);
    damage->manaMin += sub_00625480_GetStat(unit, 62, 0);
    damage->burnMin += sub_00625480_GetStat(unit, 316, 0);
    damage->burnMax += sub_00625480_GetStat(unit, 317, 0);
    damage->burnLength += sub_00625480_GetStat(unit, 315, 0);
}

// build: symbol ?MISSILE_ScaleElements@* 0x0064AA60
static void MISSILE_ScaleElements(Damage* damage, int factor)
{
    if (factor != 128)
    {
        damage->fireMin = damage->fireMin * factor / 128;
        damage->fireMax = damage->fireMax * factor / 128;
        damage->lightMin = damage->lightMin * factor / 128;
        damage->lightMax = damage->lightMax * factor / 128;
        damage->magicMin = damage->magicMin * factor / 128;
        damage->magicMax = damage->magicMax * factor / 128;
        damage->coldMin = damage->coldMin * factor / 128;
        damage->coldMax = damage->coldMax * factor / 128;
        damage->coldLength = damage->coldLength * factor / 128;
        damage->poisonMin = damage->poisonMin * factor / 128;
        damage->poisonMax = damage->poisonMax * factor / 128;
        damage->poisonCount = damage->poisonCount * factor / 128;
        damage->lifeMin = damage->lifeMin * factor / 128;
        damage->manaMin = damage->manaMin * factor / 128;
        damage->burnMin = damage->burnMin * factor / 128;
        damage->burnMax = damage->burnMax * factor / 128;
        damage->burnLength = damage->burnLength * factor / 128;
    }
}

static int sub_0064ABA0_ElementBonus(Unit* unit, int kind, int amount)
{
    int bonus;
    switch (kind)
    {
    case 1:
        bonus = sub_00625480_GetStat(unit, 329, 0);
        if (bonus) return sub_00483360_Ratio(amount, bonus, 100);
        break;
    case 2:
        bonus = sub_00625480_GetStat(unit, 330, 0);
        if (bonus) return sub_00483360_Ratio(amount, bonus, 100);
        break;
    case 4:
    case 12:
        bonus = sub_00625480_GetStat(unit, 331, 0);
        if (bonus) return sub_00483360_Ratio(amount, bonus, 100);
        break;
    case 5:
        bonus = sub_00625480_GetStat(unit, 332, 0);
        if (bonus) return sub_00483360_Ratio(amount, bonus, 100);
        break;
    }
    return 0;
}

// build: symbol ?MISSILE_GetSkill@* 0x0064A280
int __stdcall MISSILE_GetSkill(D2MissileUnitStrc0064A280* pMissile)
{
    if (pMissile && pMissile->dwUnitType == 3 && pMissile->pMissileData)
    {
        return pMissile->pMissileData->nSkill;
    }

    return 0;
}

static inline MissileRecord* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < gVar_00744304->missileCount)
    {
        return &gVar_00744304->missiles[nMissileId];
    }

    return 0;
}


// 0x0064B860
void __stdcall MISSILE_CalculateDamageData(Damage* pMissileDamageData, Unit* pOwner, Unit* pOrigin, Unit* pMissile, int nLevel)
{
    memset(pMissileDamageData, 0, sizeof(Damage));
    if (!pOwner) return;
    if (!pMissile) return;
    if (pMissile->type != 3) return;
    int missileId = pMissile->classId;
    MissileRecord* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(missileId);
    if (!pMissilesTxtRecord) return;

    int sourceDamage, originDamage, element;
    int physicalMin, physicalMax, elementMin, elementMax, elementLength;
    if (pMissilesTxtRecord->skill <= 0 && !(pMissilesTxtRecord->flags & gVar_006CE284))
    {
        sourceDamage = pMissilesTxtRecord->sourceDamage;
        originDamage = pMissilesTxtRecord->originDamage;
        physicalMin = sub_0064AF20_GetMissilePhysicalMin(pMissile, pOwner, missileId, nLevel);
        physicalMax = sub_0064AFF0_GetMissilePhysicalMax(pMissile, pOwner, missileId, nLevel);
        element = pMissilesTxtRecord->element;
        elementMin = sub_0064B100_GetMissileElementMin(pMissile, pOwner, missileId, nLevel);
        elementMax = sub_0064B1D0_GetMissileElementMax(pMissile, pOwner, missileId, nLevel);
        elementLength = MISSILE_GetElementalLength(pMissile, pOwner, missileId, nLevel);
        if (pMissilesTxtRecord->flags & gVar_006CE268)
        {
            elementMin += sub_0064ABA0_ElementBonus(pOwner, element, elementMin);
            elementMax += sub_0064ABA0_ElementBonus(pOwner, element, elementMax);
        }
    }
    else
    {
        int skill = pMissilesTxtRecord->skill;
        if (pMissilesTxtRecord->flags & gVar_006CE284)
        {
            skill = MISSILE_GetSkill((D2MissileUnitStrc0064A280*)pMissile);
            if (skill <= 0) skill = pMissilesTxtRecord->skill;
        }
        SkillRecord* pSkillsTxtRecord = sub_0045C4B0_GetSkillRecord(skill);
        if (!pSkillsTxtRecord) return;
        originDamage = 0;
        sourceDamage = pSkillsTxtRecord->sourceDamage;
        if (pMissilesTxtRecord->sourceDamage == 255) sourceDamage = 0;
        physicalMin = sub_00647BC0_GetSkillPhysicalMin(pOwner, skill, nLevel, 0);
        physicalMax = sub_00647D00_GetSkillPhysicalMax(pOwner, skill, nLevel, 0);
        element = pSkillsTxtRecord->element;
        elementMin = sub_00644D50_GetSkillElementMin(pOwner, skill, nLevel, 1);
        elementMax = sub_00644E40_GetSkillElementMax(pOwner, skill, nLevel, 1);
        elementLength = sub_00644F20_GetSkillElementLength(pOwner, skill, nLevel, 1);
    }
    if (pMissilesTxtRecord->hitFlags & 1) pMissileDamageData->flags |= 0x100;
    if (pMissilesTxtRecord->hitFlags & 2) pMissileDamageData->flags |= 0x200;
    if (pMissilesTxtRecord->hitFlags & 4) pMissileDamageData->flags |= 0x400;

    int sourceMin = 0;
    int sourceMax = 0;
    int percent = 0;
    int itemBonus = 0, maximumPercent = 0;
    Unit* item = 0;
    if (sourceDamage)
    {
        pMissileDamageData->flags |= 1;
        if (pOwner->type == 0)
            item = sub_00623990_GetWeaponSlot(pOwner, 1);
        else if (pOwner->type == 1 && pOwner->inventory)
            item = sub_00622830_GetWeapon(pOwner);
        if (MISSILE_CheckCritical(pOwner, item)) pMissileDamageData->flags |= 2;
        int bonus = 0;
        if (item && item->type == 4)
        {
            if ((pMissilesTxtRecord->flags & gVar_006CE280) && sub_006289C0_IsWeapon(item))
                sourceDamage /= 2;
            bonus = sub_00645830_GetItemBonus(pOwner, item, 0, 1);
            int strengthFactor = sub_00629860_GetStrengthFactor(item);
            if (strengthFactor)
                bonus += sub_00625480_GetStat(pOwner, 0, 0) * strengthFactor / 100;
            int dexterityFactor = sub_006298A0_GetDexterityFactor(item);
            if (dexterityFactor)
                bonus += sub_00625480_GetStat(pOwner, 2, 0) * dexterityFactor / 100;
            if (sub_0062BA80_UsesThrowDamage(item))
            {
                sourceMin = sub_00625480_GetStat(pOwner, 159, 0) << 8;
                sourceMax = sub_00625480_GetStat(pOwner, 160, 0) << 8;
            }
            else if (pOwner->inventory && sub_0063D340_GetWeaponMode(pOwner, pOwner->inventory) == 2)
            {
                sourceMin = sub_00625480_GetStat(pOwner, 23, 0) << 8;
                sourceMax = sub_00625480_GetStat(pOwner, 24, 0) << 8;
            }
            else
            {
                sourceMin = sub_00625480_GetStat(pOwner, 21, 0) << 8;
                sourceMax = sub_00625480_GetStat(pOwner, 22, 0) << 8;
            }
            if (sub_00629BB0_IsItemType(item, 57)) pMissileDamageData->undeadBonus += 50;
        }
        else
        {
            if (pOwner->type == 1 && sub_0063EE90_UsesDexterity(pOwner))
                percent = sub_00625480_GetStat(pOwner, 2, 0);
            sourceMin = sub_00625480_GetStat(pOwner, 21, 0) << 8;
            sourceMax = sub_00625480_GetStat(pOwner, 22, 0) << 8;
        }
        sourceMin = sourceMin * sourceDamage / 128;
        sourceMax = sourceMax * sourceDamage / 128;
        percent += sub_00625480_GetStat(pOwner, 25, 0) + bonus;
        itemBonus = sub_00625480_GetStat(pOwner, 18, 0);
        maximumPercent = sub_00625480_GetStat(pOwner, 17, 0);
        const int nDemonBonus = sub_00625480_GetStat(pOwner, 121, 0);
        pMissileDamageData->demonBonus += nDemonBonus;
        const int nUndeadBonus = sub_00625480_GetStat(pOwner, 122, 0);
        pMissileDamageData->undeadBonus += nUndeadBonus;
        const int nArmorReduction = sub_00625480_GetStat(pOwner, 120, 0);
        pMissileDamageData->armorReduction += nArmorReduction;
        if (sub_00625480_GetStat(pOwner, 103, 0)) pMissileDamageData->flags |= 0x100;
        if (sub_00625480_GetStat(pOwner, 104, 0)) pMissileDamageData->flags |= 0x200;
        if (sub_00625480_GetStat(pOwner, 106, 0)) pMissileDamageData->flags |= 0x400;
    }
    else if (originDamage && pOrigin)
    {
        if (MISSILE_CheckCritical(pOrigin, 0)) pMissileDamageData->flags |= 2;
        sourceMin = sub_00625480_GetStat(pOrigin, 21, 0) * originDamage / 128;
        sourceMax = sub_00625480_GetStat(pOrigin, 22, 0) * originDamage / 128;
        percent = sub_00625480_GetStat(pOrigin, 25, 0);
        itemBonus = sub_00625480_GetStat(pOrigin, 18, 0);
        maximumPercent = sub_00625480_GetStat(pOrigin, 17, 0);
        const int nDemonBonus = sub_00625480_GetStat(pOrigin, 121, 0);
        pMissileDamageData->demonBonus += nDemonBonus;
        const int nUndeadBonus = sub_00625480_GetStat(pOrigin, 122, 0);
        pMissileDamageData->undeadBonus += nUndeadBonus;
        const int nArmorReduction = sub_00625480_GetStat(pOrigin, 120, 0);
        pMissileDamageData->armorReduction += nArmorReduction;
    }
    percent += sub_00625480_GetStat(pMissile, 25, 0);
    if (itemBonus > maximumPercent) percent += itemBonus;
    else percent += maximumPercent;
    if (percent <= -90) percent = -90;
    pMissileDamageData->percent = percent;
    pMissileDamageData->physicalMin = sourceMin + physicalMin;
    pMissileDamageData->physicalMax = sourceMax + physicalMax;
    if (element)
    {
        switch (element)
        {
        case 1: pMissileDamageData->fireMin = elementMin; pMissileDamageData->fireMax = elementMax; pMissileDamageData->fireLength = elementLength; break;
        case 2: pMissileDamageData->lightMin = elementMin; pMissileDamageData->lightMax = elementMax; break;
        case 3: pMissileDamageData->magicMin = elementMin; pMissileDamageData->magicMax = elementMax; break;
        case 4: case 12: pMissileDamageData->coldMin = elementMin; pMissileDamageData->coldMax = elementMax; pMissileDamageData->coldLength = elementLength; break;
        case 5: pMissileDamageData->poisonMin = elementMin; pMissileDamageData->poisonMax = elementMax; pMissileDamageData->poisonLength = elementLength; break;
        case 6: pMissileDamageData->lifeMin = elementMin; pMissileDamageData->lifeMax = elementMax; break;
        case 7: pMissileDamageData->manaMin = elementMin; pMissileDamageData->manaMax = elementMax; break;
        case 8: pMissileDamageData->staminaMin = elementMin; pMissileDamageData->staminaMax = elementMax; break;
        case 9: pMissileDamageData->stunLength = elementLength; break;
        case 11: pMissileDamageData->burnMin = elementMin; pMissileDamageData->burnMax = elementMax; pMissileDamageData->burnLength = elementLength; break;
        }
    }
    if (sourceDamage)
    {
        sub_00623C80_BeginWeapon(pOwner, 1);
        MISSILE_AddElements(pMissileDamageData, pOwner, 8);
        MISSILE_ScaleElements(pMissileDamageData, sourceDamage);
        sub_00622E90_EndWeapon(pOwner, 1);
    }
    else if (originDamage && pOrigin)
    {
        MISSILE_AddElements(pMissileDamageData, pOrigin, 0);
        MISSILE_ScaleElements(pMissileDamageData, originDamage);
    }
}

