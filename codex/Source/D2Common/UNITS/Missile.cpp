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

struct Data0064A190;

struct Unit0064A190;

struct D2MissileDataStrc;
struct D2MissileStreamStrc;

struct D2MissilesTxt;

struct B24Roster;

struct B24MissileData;

struct B24Unit;

struct Data0064A210;

struct Unit0064A210;

struct Data0064A280;

struct Unit0064A280;

struct Data0064A300;

struct Unit0064A300;

struct Data0064A380;

struct Unit0064A380;

struct Data0064A3B0;

struct Unit0064A3B0;

struct Unit0064A3E0;

struct Data0064A4E0;

struct Unit0064A4E0;

struct Data0064A510;

struct Unit0064A510;

struct Data0064A540;

struct Unit0064A540;

struct Data0064A570;

struct Unit0064A570;

struct Data0064A640;

struct Unit0064A640;

struct Data0064A6D0;

struct Unit0064A6D0;

struct Data0064A6F0;

struct Unit0064A6F0;

struct TargetData;

struct UnitView;

struct SlotPair;

struct Node32;

struct Queue32;

struct Node24;

struct Queue24;

struct MissileRecord;

struct DataTables;

struct Damage;

struct D2StatStrc;

struct D2MissileDamageDataStrc;

struct Data0064A190 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwValue14;
};

struct Unit0064A190 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A190* pData;
};


typedef unsigned char U8;

typedef unsigned short U16;

struct B24Roster
{
    U8 pad0[0x4];
    int value;
    unsigned int key;
    U8 padAfterKey[0x24];
    B24Roster* next;
};

typedef char B24RosterValue[(OFFSET(B24Roster,value)==0x4)?1:-1];

typedef char B24RosterKey[(OFFSET(B24Roster,key)==0x8)?1:-1];

typedef char B24RosterNext[(OFFSET(B24Roster,next)==0x30)?1:-1];

struct B24MissileData
{
    U8 pad0[0xC];
    short nLevel;
};

struct B24Unit
{
    unsigned int type;
    U8 pad4[0x10];
    B24MissileData* missileData;
};

typedef char B24MissileLevel[(OFFSET(B24MissileData,nLevel)==0xC)?1:-1];

typedef char B24UnitData[(OFFSET(B24Unit,missileData)==0x14)?1:-1];

extern "C" U8 gB24Selection;

extern "C" U8* gB24PackedState;

extern "C" int gB24Dirty;

extern "C" B24Roster* gB24Roster;

extern "C" int gB24MinX;

extern "C" int gB24MaxX;

extern "C" int gB24MinY;

extern "C" int gB24MaxY;

extern "C" int gB24RowCount;

extern "C" unsigned int gB24SelectedKey;

extern "C" U8 gB24Rows[];

struct Data0064A210 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    short sValue0C;
};

struct Unit0064A210 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A210* pData;
};

struct Data0064A280 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned short wUnknown08;
    short sValue0A;
};

struct Unit0064A280 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A280* pData;
};

struct Data0064A300 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned short wUnknown0C;
    short sValue0E;
};

struct Unit0064A300 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A300* pData;
};

struct Data0064A380 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    short sValue10;
};

struct Unit0064A380 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A380* pData;
};

struct Data0064A3B0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned short wUnknown0C;
    short sValue0E;
    short sValue10;
};

struct Unit0064A3B0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A3B0* pData;
};

struct Unit0064A3E0 {
    int nType;
    unsigned int dwValue04;
};

struct Data0064A4E0 {
    unsigned int dwUnknown00;
    unsigned short wValue04;
};

struct Unit0064A4E0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A4E0* pData;
};

struct Data0064A510 {
    unsigned int dwUnknown00;
    short sValue04;
};

struct Unit0064A510 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A510* pData;
};

struct Data0064A540 {
    unsigned int dwUnknown00;
    unsigned short wUnknown04;
    unsigned short wValue06;
};

struct Unit0064A540 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A540* pData;
};

struct Data0064A570 {
    unsigned int dwUnknown00;
    unsigned short wUnknown04;
    short sValue06;
};

struct Unit0064A570 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A570* pData;
};

struct Data0064A640 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    short sValue08;
};

struct Unit0064A640 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A640* pData;
};

#pragma pack(push, 1)

struct Data0064A6D0 { unsigned char bUnknown00[0x30]; unsigned int dwValue30; };

#pragma pack(pop)

struct Unit0064A6D0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A6D0* pData;
};

struct Data0064A6F0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwValue30;
};

struct Unit0064A6F0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A6F0* pData;
};

typedef unsigned int U32;

typedef char check_pointer_width[sizeof(void*)==4?1:-1];

struct TargetData
{
    char gap0[0x2C];
    int value;
};

typedef char check_TargetData_value[OFFSET(TargetData,value)==0x2C?1:-1];

typedef char check_TargetData_size[sizeof(TargetData)==0x30?1:-1];

struct UnitView
{
    U32 kind;
    char gap4[0x10];
    TargetData* data;
};

typedef char check_UnitView_kind[OFFSET(UnitView,kind)==0x0?1:-1];

typedef char check_UnitView_data[OFFSET(UnitView,data)==0x14?1:-1];

typedef char check_UnitView_size[sizeof(UnitView)==0x18?1:-1];

struct SlotPair
{
    U32 first;
    U32 second;
};

typedef char check_SlotPair_first[OFFSET(SlotPair,first)==0x0?1:-1];

typedef char check_SlotPair_second[OFFSET(SlotPair,second)==0x4?1:-1];

typedef char check_SlotPair_size[sizeof(SlotPair)==0x8?1:-1];

struct Node32
{
    char gap0[0x4];
    SlotPair* slots;
    U32 slotIndex;
    char gapC[0xC];
    Node32* next;
    Node32* previous;
};

typedef char check_Node32_slots[OFFSET(Node32,slots)==0x4?1:-1];

typedef char check_Node32_slotIndex[OFFSET(Node32,slotIndex)==0x8?1:-1];

typedef char check_Node32_next[OFFSET(Node32,next)==0x18?1:-1];

typedef char check_Node32_previous[OFFSET(Node32,previous)==0x1C?1:-1];

typedef char check_Node32_size[sizeof(Node32)==0x20?1:-1];

struct Queue32
{
    char gap0[0x4];
    U32 count;
    Node32* head;
    Node32* tail;
    Node32* freeHead;
    Node32* freeTail;
    Node32* array;
};

typedef char check_Queue32_count[OFFSET(Queue32,count)==0x4?1:-1];

typedef char check_Queue32_head[OFFSET(Queue32,head)==0x8?1:-1];

typedef char check_Queue32_tail[OFFSET(Queue32,tail)==0xC?1:-1];

typedef char check_Queue32_freeHead[OFFSET(Queue32,freeHead)==0x10?1:-1];

typedef char check_Queue32_freeTail[OFFSET(Queue32,freeTail)==0x14?1:-1];

typedef char check_Queue32_array[OFFSET(Queue32,array)==0x18?1:-1];

typedef char check_Queue32_size[sizeof(Queue32)==0x1C?1:-1];

struct Node24
{
    char gap0[0x10];
    Node24* next;
    Node24* previous;
};

typedef char check_Node24_next[OFFSET(Node24,next)==0x10?1:-1];

typedef char check_Node24_previous[OFFSET(Node24,previous)==0x14?1:-1];

typedef char check_Node24_size[sizeof(Node24)==0x18?1:-1];

struct Queue24
{
    char gap0[0x8];
    Node24* head;
    Node24* tail;
    char gap10[0x8];
    Node24* array;
};

typedef char check_Queue24_head[OFFSET(Queue24,head)==0x8?1:-1];

typedef char check_Queue24_tail[OFFSET(Queue24,tail)==0xC?1:-1];

typedef char check_Queue24_array[OFFSET(Queue24,array)==0x18?1:-1];

typedef char check_Queue24_size[sizeof(Queue24)==0x1C?1:-1];




struct D2MissileDamageDataStrc
{
    int nFlags;
    int nMinDamage;
    int nMaxDamage;
    int nFireMinDamage;
    int nFireMaxDamage;
    int nFireLength;
    int nLightMinDamage;
    int nLightMaxDamage;
    int nMagicMinDamage;
    int nMagicMaxDamage;
    int nColdMinDamage;
    int nColdMaxDamage;
    int nColdLength;
    int nPoisonMinDamage;
    int nPoisonMaxDamage;
    int nPoisonLength;
    int nPoisonCount;
    int nLifeDrainMinDamage;
    int nLifeDrainMaxDamage;
    int nManaDrainMinDamage;
    int nManaDrainMaxDamage;
    int nStaminaDrainMinDamage;
    int nStaminaDrainMaxDamage;
    int nStunLength;
    int nBurningMin;
    int nBurningMax;
    int nBurnLength;
    int nDemonDamagePercent;
    int nUndeadDamagePercent;
    int nDamageTargetAC;
    int nDamagePercent;
};


void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize); // 0x006261D0

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330

void __stdcall MISSILE_SetActivateFrame(D2UnitStrc* pMissile, int nActivateFrame); // 0x0064A5F0

void __stdcall MISSILE_SetAnimSpeed(D2UnitStrc* pMissile, int nAnimSpeed); // 0x0064A690

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

int __stdcall MISSILE_GetSpecialParamValue(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned char nParamId, int nMissileId, int nLevel); // 0x0064B340

extern D2DataTablesStrc* gpDataTables_00744304; // 0x00744304

int __stdcall D2Common_11033(int nLevel, int nParam, int nMax); // 0x00645B20

extern void* gpfnMissileCalcFunctions[]; // 0x00745828

extern int gnMissileCalcFunctionCount; // 0x00745848




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

// 0x0064A100
void __stdcall MISSILE_AllocMissileData(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && !pMissile->pMissileData)
    {
        D2MissileDataStrc* pMissileData = (D2MissileDataStrc*)sub_0040B430(pMissile->pMemoryPool, sizeof(D2MissileDataStrc), ".\\UNITS\\Missile.cpp", 34, 0);
        memset(pMissileData, 0x00, sizeof(D2MissileDataStrc));
        pMissileData->dwOwnerGUID = D2UnitInvalidGUID;
        pMissile->pMissileData = pMissileData;
    }
}

// 0x0064A150
void __stdcall MISSILE_FreeMissileData(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        sub_0040B480(pMissile->pMemoryPool, pMissile->pMissileData, ".\\UNITS\\Missile.cpp", 62, 0);
        pMissile->pMissileData = 0;
    }
}

// 0x0064A190
unsigned int __stdcall MISSILE_GetFlags(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        return pMissile->pMissileData->fFlags;
    }
    return 0;
}


// 0x0064A1C0
void __stdcall MISSILE_SetFlags(D2UnitStrc* pMissile, unsigned int dwFlags)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        pMissile->pMissileData->fFlags = dwFlags;
    }
}

// build: symbol @ROSTER_GetPetType@* 0x00479180
extern "C" int __fastcall ROSTER_GetPetType(unsigned int key)
{
    B24Roster* node = gB24Roster;
    while (node)
    {
        if (node->key == key)
            return node->value;
        node = node->next;
    }
    return 0;
}

extern "C" int __cdecl sub_004B1D70_FindSelectedRow()
{
    int count = gB24RowCount;
    int index = 0;
    int found = 0;
    if (count > 0)
    {
        unsigned int key = gB24SelectedKey;
        const U8* row = gB24Rows;
        do
        {
            if (found)
                break;
            if (*(const unsigned int*)row == key)
                found = 1;
            else
            {
                index += 1;
                row += 0x16;
            }
        } while (index < count);
        if (found == 1)
            return index;
    }
    return 0;
}

// 0x0064A1E0
extern "C" void __stdcall MISSILE_SetMissileLevel(B24Unit* unit, int level)
{
    if (unit && unit->type == 3 && unit->missileData)
        unit->missileData->nLevel = (short)level;
}

// 0x0064A210
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        return pMissile->pMissileData->nLevel;
    }
    return 0;
}

// 0x0064A240
void __stdcall MISSILE_SetSkill(D2UnitStrc* pMissile, int nSkill)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        nSkill = nSkill > 0 ? nSkill : 0;
        if (nSkill >= 32767)
        {
            nSkill = 32767;
        }
        pMissile->pMissileData->nSkill = nSkill;
    }
}

// 0x0064A280
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        return pMissile->pMissileData->nSkill;
    }
    return 0;
}

// 0x0064A2B0
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        nTotalFrames = D2_MIN(D2_MAX(nTotalFrames, -32768), 32767);
        pMissile->pMissileData->nTotalFrames = nTotalFrames;
    }
}

// 0x0064A300
int __stdcall MISSILE_GetTotalFrames(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        return pMissile->pMissileData->nTotalFrames;
    }
    return 0;
}

// 0x0064A330
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        nCurrentFrame = D2_MIN(D2_MAX(nCurrentFrame, -32768), 32767);
        pMissile->pMissileData->nCurrentFrame = nCurrentFrame;
    }
}

// 0x0064A380
int __stdcall MISSILE_GetCurrentFrame(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        return pMissile->pMissileData->nCurrentFrame;
    }
    return 0;
}

// 0x0064A3B0
int __stdcall MISSILE_GetRemainingFrames(D2UnitStrc* pMissile)
{
    D2MissileDataStrc* pMissileData = (pMissile && pMissile->dwUnitType == UNIT_MISSILE) ? pMissile->pMissileData : 0;
    if (pMissileData)
    {
        return pMissileData->nTotalFrames - pMissileData->nCurrentFrame;
    }
    return 0;
}

// 0x0064A3E0
int __stdcall MISSILE_GetClassId(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE)
    {
        return pMissile->dwClassId;
    }
    return 0;
}

// 0x0064A400
void __stdcall MISSILE_SetOwner(D2UnitStrc* pMissile, D2UnitStrc* pOwner)
{
    D2MissilesTxt* pMissilesTxtRecord = 0;
    if (pMissile && (!pMissile ? 6 : pMissile->dwUnitType) == 3)
    {
        pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(pMissile->dwClassId);
        if (pMissilesTxtRecord && pMissilesTxtRecord->nMissileFlags[0 >> 3] & gdwBitMasks[0 & 7])
        {
            D2MissileDataStrc* pMissileData = pMissile->pMissileData;
            if (pMissileData)
            {
                if (pOwner)
                {
                    pMissileData->nOwnerType = pOwner->dwUnitType;
                    pMissileData->dwOwnerGUID = pOwner->dwUnitId;
                }
                else
                {
                    pMissileData->dwOwnerGUID = -1;
                }
            }
        }
    }
}

// 0x0064A470
int __stdcall MISSILE_CheckUnitIfOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pMissile && pUnit && pMissile->dwUnitType == UNIT_MISSILE)
    {
        D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(pMissile->dwClassId);
        if (pMissilesTxtRecord && pMissilesTxtRecord->nMissileFlags[0 >> 3] & gdwBitMasks[0 & 7])
        {
            D2MissileDataStrc* pData = pMissile->pMissileData;
            if (pData && pData->nOwnerType == GetUnitType(pUnit) && pData->dwOwnerGUID == GetUnitId(pUnit))
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x0064A4E0
void __stdcall MISSILE_SetStreamMissile(D2UnitStrc* pMissile, int nStreamMissile)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        pMissile->pMissileData->nStreamMissile = nStreamMissile;
    }
}

// 0x0064A510
int __stdcall MISSILE_GetStreamMissile(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        return pMissile->pMissileData->nStreamMissile;
    }
    return -1;
}

// 0x0064A540
void __stdcall MISSILE_SetStreamRange(D2UnitStrc* pMissile, short nStreamRange)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        pMissile->pMissileData->nStreamRange = nStreamRange;
    }
}

// 0x0064A570
int __stdcall MISSILE_GetStreamRange(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        return pMissile->pMissileData->nStreamRange;
    }
    return 0;
}

// 0x0064A5A0
int __stdcall MISSILE_GetHitClass(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE)
    {
        D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(pMissile->dwClassId);
        if (pMissilesTxtRecord)
        {
            return pMissilesTxtRecord->nHitClass;
        }
    }
    return 0;
}

// 0x0064A5F0
void __stdcall MISSILE_SetActivateFrame(D2UnitStrc* pMissile, int nActivateFrame)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        nActivateFrame = D2_MIN(D2_MAX(nActivateFrame, -32768), 32767);
        pMissile->pMissileData->nActivateFrame = nActivateFrame;
    }
}

// 0x0064A640
int __stdcall MISSILE_GetActivateFrame(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        return pMissile->pMissileData->nActivateFrame;
    }
    return 0;
}

// 0x0064A670
int __stdcall MISSILE_GetAnimSpeed(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE)
    {
        return pMissile->wAnimSpeed;
    }
    return 0;
}

// 0x0064A690
void __stdcall MISSILE_SetAnimSpeed(D2UnitStrc* pMissile, int nAnimSpeed)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE)
    {
        pMissile->wAnimSpeed = D2_MIN(D2_MAX(nAnimSpeed, -32768), 32767);
    }
}

// 0x0064A6D0
void __fastcall MISSILE_SetStream(D2UnitStrc* pMissile, D2MissileStreamStrc* pStream)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        pMissile->pMissileData->pStream = pStream;
    }
}

// 0x0064A6F0
D2MissileStreamStrc* __fastcall MISSILE_GetStream(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        return (D2MissileStreamStrc*)pMissile->pMissileData->pStream;
    }
    return 0;
}

// 0x0064A710
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        pMissile->pMissileData->nTargetX = nTargetX;
    }
}

struct B25MissileData
{
    unsigned char pad0[0x28];
    int targetStatus;
};

struct B25MissileUnit
{
    unsigned int type;
    unsigned char pad4[0x10];
    B25MissileData* data;
};

// 0x0064A730
extern "C" int __stdcall MISSILE_GetMissileTargetStatus(B25MissileUnit* unit)
{
    if (unit && unit->type == 3 && unit->data)
        return unit->data->targetStatus;
    return 0;
}

// 0x0064A7F0
void __stdcall MISSILE_GetHomeType(D2UnitStrc* pMissile, int* nHomeType, int* nHomeGUID)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE)
    {
        D2MissileDataStrc* pMissileData = pMissile->pMissileData;
        if (!pMissileData)
        {
            *nHomeType = 0;
            *nHomeGUID = D2UnitInvalidGUID;
        }
        else
        {
            *nHomeType = pMissileData->nHomeType;
            *nHomeGUID = pMissileData->dwHomeGUID;
        }
    }
    else
    {
        *nHomeType = 0;
        *nHomeGUID = D2UnitInvalidGUID;
    }
}

// 0x0064A760
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        pMissile->pMissileData->nTargetY = nTargetY;
    }
}

// 0x0064A780
extern "C" int __stdcall MISSILE_targetValue(UnitView* unit)
{
    if (unit && unit->kind == 3)
    {
        TargetData* data = unit->data;
        if (data)
            return data->value;
    }
    return 0;
}

// 0x0064A7B0
void __stdcall MISSILE_SetHomeType(D2UnitStrc* pMissile, D2UnitStrc* pTarget)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE)
    {
        D2MissileDataStrc* pMissileData = pMissile->pMissileData;
        if (pMissileData)
        {
            if (pTarget)
            {
                pMissileData->nHomeType = pTarget->dwUnitType;
                pMissileData->dwHomeGUID = pTarget->dwUnitId;
            }
            else
            {
                pMissileData->nHomeType = 0;
                pMissileData->dwHomeGUID = -1;
            }
        }
    }
}

static __forceinline unsigned int RollPercent(Unit* unit)
{
    unsigned __int64 next = (unsigned __int64)unit->f_24
        + (unsigned __int64)unit->f_20 * 1791398085u;
    unit->f_24 = (unsigned int)(next >> 32);
    unit->f_20 = (unsigned int)next;
    return (unsigned int)next % 100u;
}

// 0x0064A850
static int __stdcall MISSILE_CheckCritical(Unit* item, Unit* unit)
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

// 0x0064A930
static void MISSILE_AddElements(int shift, Unit* unit, Damage* damage)
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

// 0x0064AA60
static void MISSILE_ScaleElements(int factor, Damage* damage)
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

// 0x0064ABA0
static int sub_0064ABA0_ElementBonus(int amount, int kind, Unit* unit)
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

inline unsigned int MISSILE_GetFlagsInline(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        return pMissile->pMissileData->fFlags;
    }

    return 0;
}

inline void MISSILE_SetFlagsInline(D2UnitStrc* pMissile, unsigned int dwFlags)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        pMissile->pMissileData->fFlags = dwFlags;
    }
}

// 0x0064AC60
void __stdcall MISSILE_SetDamageStats(D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2MissileDamageDataStrc* pMissileDamageData, int nLevel)
{
    D2StatStrc pStat[128];

    const int nType = pMissile ? pMissile->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MISSILE)
    {
        unsigned int dwFlags = MISSILE_GetFlagsInline(pMissile);
        if (pMissileDamageData->nFlags & 1)
        {
            dwFlags |= 1;
        }
        if (pMissileDamageData->nFlags & 4)
        {
            dwFlags |= 2;
        }
        MISSILE_SetFlagsInline(pMissile, dwFlags);

        STATLIST_SetUnitStat(pMissile, STAT_LEVEL, nLevel, 0);
        STATLIST_SetUnitStat(pMissile, STAT_MINDAMAGE, pMissileDamageData->nMinDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_MAXDAMAGE, pMissileDamageData->nMaxDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_FIREMINDAM, pMissileDamageData->nFireMinDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_FIREMAXDAM, pMissileDamageData->nFireMaxDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_FIRELENGTH, pMissileDamageData->nFireLength, 0);
        STATLIST_SetUnitStat(pMissile, STAT_LIGHTMINDAM, pMissileDamageData->nLightMinDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_LIGHTMAXDAM, pMissileDamageData->nLightMaxDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_MAGICMINDAM, pMissileDamageData->nMagicMinDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_MAGICMAXDAM, pMissileDamageData->nMagicMaxDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_COLDMINDAM, pMissileDamageData->nColdMinDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_COLDMAXDAM, pMissileDamageData->nColdMaxDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_COLDLENGTH, pMissileDamageData->nColdLength, 0);
        STATLIST_SetUnitStat(pMissile, STAT_POISONMINDAM, pMissileDamageData->nPoisonMinDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_POISONMAXDAM, pMissileDamageData->nPoisonMaxDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_POISONLENGTH, pMissileDamageData->nPoisonLength, 0);
        STATLIST_SetUnitStat(pMissile, STAT_POISON_COUNT, pMissileDamageData->nPoisonCount, 0);
        STATLIST_SetUnitStat(pMissile, STAT_LIFEDRAINMINDAM, pMissileDamageData->nLifeDrainMinDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_LIFEDRAINMAXDAM, pMissileDamageData->nLifeDrainMaxDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_MANADRAINMINDAM, pMissileDamageData->nManaDrainMinDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_MANADRAINMAXDAM, pMissileDamageData->nManaDrainMaxDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_STAMDRAINMINDAM, pMissileDamageData->nStaminaDrainMinDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_STAMDRAINMAXDAM, pMissileDamageData->nStaminaDrainMaxDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_STUNLENGTH, pMissileDamageData->nStunLength, 0);
        STATLIST_SetUnitStat(pMissile, STAT_BURNINGMIN, pMissileDamageData->nBurningMin, 0);
        STATLIST_SetUnitStat(pMissile, STAT_BURNINGMAX, pMissileDamageData->nBurningMax, 0);
        STATLIST_SetUnitStat(pMissile, STAT_FIRELENGTH, pMissileDamageData->nBurnLength, 0);
        STATLIST_SetUnitStat(pMissile, STAT_ITEM_DEMONDAMAGE_PERCENT, pMissileDamageData->nDemonDamagePercent, 0);
        STATLIST_SetUnitStat(pMissile, STAT_ITEM_UNDEADDAMAGE_PERCENT, pMissileDamageData->nUndeadDamagePercent, 0);
        STATLIST_SetUnitStat(pMissile, STAT_ITEM_DAMAGETARGETAC, pMissileDamageData->nDamageTargetAC, 0);
        STATLIST_SetUnitStat(pMissile, STAT_DAMAGEPERCENT, pMissileDamageData->nDamagePercent, 0);

        if (pMissileDamageData->nFlags & 0x100)
        {
            STATLIST_SetUnitStat(pMissile, STAT_SKILL_BYPASS_UNDEAD, 1, 0);
        }

        if (pMissileDamageData->nFlags & 0x200)
        {
            STATLIST_SetUnitStat(pMissile, STAT_SKILL_BYPASS_DEMONS, 1, 0);
        }

        if (pMissileDamageData->nFlags & 0x400)
        {
            STATLIST_SetUnitStat(pMissile, STAT_SKILL_BYPASS_BEASTS, 1, 0);
        }

        if (pMissileDamageData->nFlags & 2)
        {
            STATLIST_SetUnitStat(pMissile, STAT_ITEM_DEADLYSTRIKE, 1, 0);
        }

        if (pOwner)
        {
            const int nStats = STATLIST_CopyStats(pOwner, STAT_DAMAGE_VS_MONTYPE, pStat, 128);
            for (int i = 0; i < nStats; ++i)
            {
                STATLIST_SetUnitStat(pMissile, STAT_DAMAGE_VS_MONTYPE, pStat[i].nValue, pStat[i].nLayer);
            }
        }
    }
}

// 0x0064AF20
int __stdcall MISSILE_GetMinDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel)
{
    if (pMissile && pMissile->dwUnitType != UNIT_MISSILE)
    {
        return 0;
    }

    if (nMissileId < 0 && pMissile)
    {
        nMissileId = pMissile->dwClassId;
    }

    int nMissileIdLevel = nLevel;
    if (nLevel <= 0 && pMissile)
    {
        if (pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
        {
            nMissileIdLevel = pMissile->pMissileData->nLevel;
        }
        else
        {
            nMissileIdLevel = 0;
        }
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(nMissileId);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    int nDamage = pMissilesTxtRecord->dwMinDamage + SKILLS_CalculateDamageBonusByLevel(nMissileIdLevel, pMissilesTxtRecord->dwMinLevDam);
    if (pMissilesTxtRecord->dwDmgSymPerCalc != -1)
    {
        const int nPercentage = MISSILE_EvaluateMissileFormula(pMissile, pOwner, pMissilesTxtRecord->dwDmgSymPerCalc, nMissileId, nMissileIdLevel);
        if (nPercentage)
        {
            nDamage += DATATBLS_ApplyRatio(nDamage, nPercentage, 100);
        }
    }

    return nDamage << pMissilesTxtRecord->nHitShift;
}

// 0x0064AFF0
int __stdcall MISSILE_GetMaxDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel)
{
    if (pMissile && pMissile->dwUnitType != UNIT_MISSILE)
    {
        return 0;
    }

    if (nMissileId < 0 && pMissile)
    {
        nMissileId = pMissile->dwClassId;
    }

    int nMissileIdLevel = nLevel;
    if (nLevel <= 0 && pMissile)
    {
        if (pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
        {
            nMissileIdLevel = pMissile->pMissileData->nLevel;
        }
        else
        {
            nMissileIdLevel = 0;
        }
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(nMissileId);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    int nDamage = pMissilesTxtRecord->dwMaxDamage + SKILLS_CalculateDamageBonusByLevel(nMissileIdLevel, pMissilesTxtRecord->dwMaxLevDam);
    if (pMissilesTxtRecord->dwDmgSymPerCalc != -1)
    {
        const int nPercentage = MISSILE_EvaluateMissileFormula(pMissile, pOwner, pMissilesTxtRecord->dwDmgSymPerCalc, nMissileId, nMissileIdLevel);
        if (nPercentage)
        {
            nDamage += DATATBLS_ApplyRatio(nDamage, nPercentage, 100);
        }
    }

    return nDamage << pMissilesTxtRecord->nHitShift;
}

// 0x0064B0C0
unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(nMissileId);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    return pMissilesTxtRecord->nElemType;
}

// 0x0064B100
int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel)
{
    if (pMissile && pMissile->dwUnitType != UNIT_MISSILE)
    {
        return 0;
    }

    if (nMissileId < 0 && pMissile)
    {
        nMissileId = pMissile->dwClassId;
    }

    int nMissileIdLevel = nLevel;
    if (nLevel <= 0 && pMissile)
    {
        if (pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
        {
            nMissileIdLevel = pMissile->pMissileData->nLevel;
        }
        else
        {
            nMissileIdLevel = 0;
        }
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(nMissileId);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    int nDamage = pMissilesTxtRecord->dwElemMin + SKILLS_CalculateDamageBonusByLevel(nMissileIdLevel, pMissilesTxtRecord->dwMinElemLev);
    if (pMissilesTxtRecord->dwElemDmgSymPerCalc != -1)
    {
        const int nPercentage = MISSILE_EvaluateMissileFormula(pMissile, pOwner, pMissilesTxtRecord->dwElemDmgSymPerCalc, nMissileId, nMissileIdLevel);
        if (nPercentage)
        {
            nDamage += DATATBLS_ApplyRatio(nDamage, nPercentage, 100);
        }
    }

    return nDamage << pMissilesTxtRecord->nHitShift;
}

// 0x0064B1D0
int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel)
{
    if (pMissile && pMissile->dwUnitType != UNIT_MISSILE)
    {
        return 0;
    }

    if (nMissileId < 0 && pMissile)
    {
        nMissileId = pMissile->dwClassId;
    }

    int nMissileIdLevel = nLevel;
    if (nLevel <= 0 && pMissile)
    {
        if (pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
        {
            nMissileIdLevel = pMissile->pMissileData->nLevel;
        }
        else
        {
            nMissileIdLevel = 0;
        }
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(nMissileId);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    int nDamage = pMissilesTxtRecord->dwElemMax + SKILLS_CalculateDamageBonusByLevel(nMissileIdLevel, pMissilesTxtRecord->dwMaxElemLev);
    if (pMissilesTxtRecord->dwElemDmgSymPerCalc != -1)
    {
        const int nPercentage = MISSILE_EvaluateMissileFormula(pMissile, pOwner, pMissilesTxtRecord->dwElemDmgSymPerCalc, nMissileId, nMissileIdLevel);
        if (nPercentage)
        {
            nDamage += DATATBLS_ApplyRatio(nDamage, nPercentage, 100);
        }
    }

    return nDamage << pMissilesTxtRecord->nHitShift;
}

static inline D2MissilesTxt* GetMissileRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < gpDataTables_00744304->nMissilesTxtRecordCount)
        return &gpDataTables_00744304->pMissilesTxt[nMissileId];
    return 0;
}

// 0x0064B2A0
int __stdcall MISSILE_GetElementalLength(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel)
{
    D2MissilesTxt* pRecord = GetMissileRecord(nMissileId);
    if (!pRecord)
        return 0;
    if (nLevel <= 0)
        return pRecord->nElementLength;

    int nBonus;
    if (nLevel > 16)
        nBonus = 7 * pRecord->nElementLengthPerLevel[0] + 8 * pRecord->nElementLengthPerLevel[1] + (nLevel - 16) * pRecord->nElementLengthPerLevel[2];
    else if (nLevel > 8)
        nBonus = 7 * pRecord->nElementLengthPerLevel[0] + (nLevel - 8) * pRecord->nElementLengthPerLevel[1];
    else
        nBonus = (nLevel - 1) * pRecord->nElementLengthPerLevel[0];
    return pRecord->nElementLength + nBonus;
}

static int sub_0044BE50(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }
    return nType;
}

static unsigned int MISSILE_GetLevelInline(D2UnitStrc* pMissile)
{
    D2MissileDataStrc* pMissileData = sub_0044BE50(pMissile) == 3 ? pMissile->pMissileData : 0;
    if (!pMissileData)
    {
        return 0;
    }

    return pMissileData->nLevel;
}

// 0x0064B340
int __stdcall MISSILE_GetSpecialParamValue(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned char nParamId, int nMissileId, int nLevel)
{
    int nResult;
    {
    if (pMissile && pMissile->dwUnitType != UNIT_MISSILE)
    {
        nResult = 0;
        goto Done;
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(nMissileId);
    if (!pMissilesTxtRecord)
    {
        nResult = 0;
        goto Done;
    }

    switch (nParamId)
    {
    case 0: nResult = pMissilesTxtRecord->dwParam[0];
    goto Done;
    case 1: nResult = pMissilesTxtRecord->dwParam[1];
    goto Done;
    case 2: nResult = pMissilesTxtRecord->dwParam[2];
    goto Done;
    case 3: nResult = pMissilesTxtRecord->dwParam[3];
    goto Done;
    case 4: nResult = pMissilesTxtRecord->dwParam[4];
    goto Done;
    case 5: nResult = pMissilesTxtRecord->dwCltParam[0];
    goto Done;
    case 6: nResult = pMissilesTxtRecord->dwCltParam[1];
    goto Done;
    case 7: nResult = pMissilesTxtRecord->dwCltParam[2];
    goto Done;
    case 8: nResult = pMissilesTxtRecord->dwCltParam[3];
    goto Done;
    case 9: nResult = pMissilesTxtRecord->dwCltParam[4];
    goto Done;
    case 10: nResult = pMissilesTxtRecord->dwHitPar[0];
    goto Done;
    case 11: nResult = pMissilesTxtRecord->dwHitPar[1];
    goto Done;
    case 12: nResult = pMissilesTxtRecord->dwHitPar[2];
    goto Done;
    case 13: nResult = pMissilesTxtRecord->dwCltHitPar[0];
    goto Done;
    case 14: nResult = pMissilesTxtRecord->dwCltHitPar[1];
    goto Done;
    case 15: nResult = pMissilesTxtRecord->dwCltHitPar[2];
    goto Done;
    case 16: nResult = pMissilesTxtRecord->dwDmgParam[0];
    goto Done;
    case 17: nResult = pMissilesTxtRecord->dwDmgParam[1];
    goto Done;
    case 18: nResult = nLevel;
    goto Done;
    case 19: nResult = MISSILE_GetMinElemDamage(pMissile, pOwner, nMissileId, nLevel) >> 8;
    goto Done;
    case 20: nResult = MISSILE_GetMaxElemDamage(pMissile, pOwner, nMissileId, nLevel) >> 8;
    goto Done;
    case 21: nResult = MISSILE_GetElementalLength(pMissile, pOwner, nMissileId, nLevel);
    goto Done;
    case 22: nResult = MISSILE_GetMinElemDamage(pMissile, pOwner, nMissileId, nLevel);
    goto Done;
    case 23: nResult = MISSILE_GetMaxElemDamage(pMissile, pOwner, nMissileId, nLevel);
    goto Done;
    case 24: nResult = MISSILE_GetMinDamage(pMissile, pOwner, nMissileId, nLevel) >> 8;
    goto Done;
    case 25: nResult = MISSILE_GetMaxDamage(pMissile, pOwner, nMissileId, nLevel) >> 8;
    goto Done;
    case 26: nResult = MISSILE_GetMinDamage(pMissile, pOwner, nMissileId, nLevel);
    goto Done;
    case 27: nResult = MISSILE_GetMaxDamage(pMissile, pOwner, nMissileId, nLevel);
    goto Done;
    case 28: nResult = pMissilesTxtRecord->wLevRange * nLevel + pMissilesTxtRecord->wRange;
    goto Done;
    case 29: nResult = pMissilesTxtRecord->dwParam[0] + (nLevel - 1) * pMissilesTxtRecord->dwParam[1];
    goto Done;
    case 30: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwParam[0], pMissilesTxtRecord->dwParam[1]);
    goto Done;
    case 31: nResult = pMissilesTxtRecord->dwParam[2] + (nLevel - 1) * pMissilesTxtRecord->dwParam[3];
    goto Done;
    case 32: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwParam[2], pMissilesTxtRecord->dwParam[3]);
    goto Done;
    case 33: nResult = pMissilesTxtRecord->dwCltParam[0] + (nLevel - 1) * pMissilesTxtRecord->dwCltParam[1];
    goto Done;
    case 34: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwCltParam[0], pMissilesTxtRecord->dwCltParam[1]);
    goto Done;
    case 35: nResult = pMissilesTxtRecord->dwCltParam[2] + (nLevel - 1) * pMissilesTxtRecord->dwCltParam[3];
    goto Done;
    case 36: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwCltParam[2], pMissilesTxtRecord->dwCltParam[3]);
    goto Done;
    case 37: nResult = pMissilesTxtRecord->dwHitPar[0] + (nLevel - 1) * pMissilesTxtRecord->dwHitPar[1];
    goto Done;
    case 38: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwHitPar[0], pMissilesTxtRecord->dwHitPar[1]);
    goto Done;
    case 39: nResult = pMissilesTxtRecord->dwCltHitPar[0] + (nLevel - 1) * pMissilesTxtRecord->dwCltHitPar[1];
    goto Done;
    case 40: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->dwCltHitPar[1]);
    goto Done;
    case 41: nResult = pMissilesTxtRecord->dwDmgParam[0] + (nLevel - 1) * pMissilesTxtRecord->dwDmgParam[1];
    goto Done;
    case 42: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwDmgParam[0], pMissilesTxtRecord->dwDmgParam[1]);
    goto Done;
    }

    nResult = 0;
    }
Done:
    return nResult;
}

// 0x0064B6E0
int __fastcall MISSILE_GetCalcParamValue(int nParamId, void* pUserData)
{
    D2MissileCalcStrc* pMissileCalc = (D2MissileCalcStrc*)pUserData;
    if (!pMissileCalc)
    {
        return 0;
    }

    return MISSILE_GetSpecialParamValue(pMissileCalc->pMissile, pMissileCalc->pOwner, nParamId, pMissileCalc->nMissileId, pMissileCalc->nMissileLevel);
}

// 0x0064B700
int __fastcall MISSILE_GetMinimum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

// 0x0064B710
int __fastcall MISSILE_GetMaximum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}

// 0x0064B720
int __fastcall MISSILE_GetRandomNumberInRange(int nMin, int nMax, int nUnused, void* pUserData)
{
    D2UnitStrc* pMissile = (D2UnitStrc*)pUserData;
    if (!pMissile)
    {
        return 0;
    }
    if (nMin >= nMax)
    {
        return nMin;
    }
    return nMin + ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, nMax - nMin + 1);
}

// 0x0064B760
int __fastcall MISSILE_GetSpecialParamValueForSkillMissile(int nSkillId, int nParamId, int nUnused, void* pUserData)
{
    D2MissileCalcStrc* pMissileCalc = (D2MissileCalcStrc*)pUserData;
    if (!pMissileCalc)
    {
        return 0;
    }

    int nSkillLevel = 0;
    if (pMissileCalc->pOwner)
    {
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pMissileCalc->pOwner, nSkillId);
        if (pSkill)
        {
            nSkillLevel = SKILLS_GetSkillLevel(pMissileCalc->pOwner, pSkill, 1);
        }
    }

    return SKILLS_GetSpecialParamValue(pMissileCalc->pOwner, nParamId, nSkillId, nSkillLevel);
}

static inline MissileRecord* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < gVar_00744304->missileCount)
    {
        return &gVar_00744304->missiles[nMissileId];
    }

    return 0;
}

// 0x0064B7C0
int __stdcall MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel)
{
    D2MissileCalcStrc pMissileCalc;
    if (pMissile)
    {
        const int nType = sub_0044BE50(pMissile);
        if (nType != 3)
        {
            return 0;
        }

        if (nMissileId < 0)
        {
            nMissileId = pMissile->dwClassId;
        }

        if (nLevel < 0)
        {
            nLevel = MISSILE_GetLevelInline(pMissile);
        }
    }

    if (!sgptDataTables->pMissCode)
    {
        return 0;
    }

    if (nCalc >= sgptDataTables->nMissCodeSize)
    {
        return 0;
    }

    pMissileCalc.pMissile = pMissile;
    pMissileCalc.pOwner = pOwner;
    pMissileCalc.nMissileId = nMissileId;
    pMissileCalc.nMissileLevel = nLevel;

    return DATATBLS_CalcEvaluateExpression((char*)sgptDataTables->pMissCode + nCalc, sgptDataTables->nMissCodeSize - nCalc, MISSILE_GetCalcParamValue, gpfnMissileCalcFunctions, gnMissileCalcFunctionCount, &pMissileCalc);
}

extern "C" void __stdcall MISSILE_CalculateDamageData(Damage* damage, Unit* owner, Unit* origin, Unit* missile, int level)
{
    memset(damage, 0, 124);
    if (!owner) return;
    if (!missile) return;
    if (missile->type != 3) return;
    int missileId = missile->classId;
    if (missileId < 0) return;
    if (missileId >= gVar_00744304->missileCount) return;
    MissileRecord* record = &gVar_00744304->missiles[missileId];
    if (!record) return;

    int sourceDamage, originDamage, element;
    int physicalMin, physicalMax, elementMin, elementMax, elementLength;
    if (record->skill > 0 || (record->flags & gVar_006CE284))
    {
        int skill = record->skill;
        if (record->flags & gVar_006CE284)
        {
            int missileSkill = MISSILE_GetSkill((D2UnitStrc*)missile);
            if (missileSkill > 0) skill = missileSkill;
        }
        SkillRecord* skillRecord = sub_0045C4B0_GetSkillRecord(skill);
        if (!skillRecord) return;
        sourceDamage = skillRecord->sourceDamage;
        originDamage = 0;
        if (record->sourceDamage == 255) sourceDamage = 0;
        physicalMin = sub_00647BC0_GetSkillPhysicalMin(owner, skill, level, 0);
        physicalMax = sub_00647D00_GetSkillPhysicalMax(owner, skill, level, 0);
        element = skillRecord->element;
        elementMin = sub_00644D50_GetSkillElementMin(owner, skill, level, 1);
        elementMax = sub_00644E40_GetSkillElementMax(owner, skill, level, 1);
        elementLength = sub_00644F20_GetSkillElementLength(owner, skill, level, 1);
    }
    else
    {
        sourceDamage = record->sourceDamage;
        originDamage = record->originDamage;
        physicalMin = sub_0064AF20_GetMissilePhysicalMin(missile, owner, missileId, level);
        physicalMax = sub_0064AFF0_GetMissilePhysicalMax(missile, owner, missileId, level);
        element = record->element;
        elementMin = sub_0064B100_GetMissileElementMin(missile, owner, missileId, level);
        elementMax = sub_0064B1D0_GetMissileElementMax(missile, owner, missileId, level);
        elementLength = MISSILE_GetElementalLength(missile, owner, missileId, level);
        if (record->flags & gVar_006CE268)
        {
            elementMin += sub_0064ABA0_ElementBonus(elementMin, element, owner);
            elementMax += sub_0064ABA0_ElementBonus(elementMax, element, owner);
        }
    }
    if (record->hitFlags & 1) damage->flags |= 256;
    if (record->hitFlags & 2) damage->flags |= 512;
    if (record->hitFlags & 4) damage->flags |= 1024;

    int sourceMin = 0, sourceMax = 0, percent = 0;
    int itemBonus = 0, maximumPercent = 0;
    Unit* item = 0;
    if (sourceDamage)
    {
        damage->flags |= 1;
        if (owner->type == 0)
            item = sub_00623990_GetWeaponSlot(owner, 1);
        else if (owner->type == 1 && owner->inventory)
            item = sub_00622830_GetWeapon(owner);
        if (MISSILE_CheckCritical(item, owner)) damage->flags |= 2;
        itemBonus = 0;
        if (item && item->type == 4)
        {
            if ((record->flags & gVar_006CE280) && sub_006289C0_IsWeapon(item))
                sourceDamage /= 2;
            itemBonus = sub_00645830_GetItemBonus(owner, item, 0, 1);
            int strengthFactor = sub_00629860_GetStrengthFactor(item);
            if (strengthFactor)
                itemBonus += sub_00625480_GetStat(owner, 0, 0) * strengthFactor / 100;
            int dexterityFactor = sub_006298A0_GetDexterityFactor(item);
            if (dexterityFactor)
                itemBonus += sub_00625480_GetStat(owner, 2, 0) * dexterityFactor / 100;
            if (sub_0062BA80_UsesThrowDamage(item))
            {
                sourceMin = sub_00625480_GetStat(owner, 159, 0) << 8;
                sourceMax = sub_00625480_GetStat(owner, 160, 0) << 8;
            }
            else if (owner->inventory && sub_0063D340_GetWeaponMode(owner, owner->inventory) == 2)
            {
                sourceMin = sub_00625480_GetStat(owner, 23, 0) << 8;
                sourceMax = sub_00625480_GetStat(owner, 24, 0) << 8;
            }
            else
            {
                sourceMin = sub_00625480_GetStat(owner, 21, 0) << 8;
                sourceMax = sub_00625480_GetStat(owner, 22, 0) << 8;
            }
            if (sub_00629BB0_IsItemType(item, 57)) damage->undeadBonus += 50;
        }
        else
        {
            if (owner->type == 1 && sub_0063EE90_UsesDexterity(owner))
                percent = sub_00625480_GetStat(owner, 2, 0);
            sourceMin = sub_00625480_GetStat(owner, 21, 0) << 8;
            sourceMax = sub_00625480_GetStat(owner, 22, 0) << 8;
        }
        sourceMin = sourceMin * sourceDamage / 128;
        sourceMax = sourceMax * sourceDamage / 128;
        percent += sub_00625480_GetStat(owner, 25, 0) + itemBonus;
        itemBonus = sub_00625480_GetStat(owner, 18, 0);
        maximumPercent = sub_00625480_GetStat(owner, 17, 0);
        damage->demonBonus += sub_00625480_GetStat(owner, 121, 0);
        damage->undeadBonus += sub_00625480_GetStat(owner, 122, 0);
        damage->armorReduction += sub_00625480_GetStat(owner, 120, 0);
        if (sub_00625480_GetStat(owner, 103, 0)) damage->flags |= 256;
        if (sub_00625480_GetStat(owner, 104, 0)) damage->flags |= 512;
        if (sub_00625480_GetStat(owner, 106, 0)) damage->flags |= 1024;
    }
    else if (originDamage && origin)
    {
        if (MISSILE_CheckCritical(0, origin)) damage->flags |= 2;
        sourceMin = sub_00625480_GetStat(origin, 21, 0) * originDamage / 128;
        sourceMax = sub_00625480_GetStat(origin, 22, 0) * originDamage / 128;
        percent = sub_00625480_GetStat(origin, 25, 0);
        itemBonus = sub_00625480_GetStat(origin, 18, 0);
        maximumPercent = sub_00625480_GetStat(origin, 17, 0);
        damage->demonBonus += sub_00625480_GetStat(origin, 121, 0);
        damage->undeadBonus += sub_00625480_GetStat(origin, 122, 0);
        damage->armorReduction += sub_00625480_GetStat(origin, 120, 0);
    }
    percent += sub_00625480_GetStat(missile, 25, 0);
    if (itemBonus > maximumPercent) percent += itemBonus;
    else percent += maximumPercent;
    if (percent <= -90) percent = -90;
    damage->percent = percent;
    damage->physicalMin = sourceMin + physicalMin;
    damage->physicalMax = sourceMax + physicalMax;
    if (element)
    {
        switch (element)
        {
        case 1: damage->fireMin = elementMin; damage->fireMax = elementMax; damage->fireLength = elementLength; break;
        case 2: damage->lightMin = elementMin; damage->lightMax = elementMax; break;
        case 3: damage->magicMin = elementMin; damage->magicMax = elementMax; break;
        case 4: case 12: damage->coldMin = elementMin; damage->coldMax = elementMax; damage->coldLength = elementLength; break;
        case 5: damage->poisonMin = elementMin; damage->poisonMax = elementMax; damage->poisonLength = elementLength; break;
        case 6: damage->lifeMin = elementMin; damage->lifeMax = elementMax; break;
        case 7: damage->manaMin = elementMin; damage->manaMax = elementMax; break;
        case 8: damage->staminaMin = elementMin; damage->staminaMax = elementMax; break;
        case 9: damage->stunLength = elementLength; break;
        case 11: damage->burnMin = elementMin; damage->burnMax = elementMax; damage->burnLength = elementLength; break;
        }
    }
    if (sourceDamage)
    {
        sub_00623C80_BeginWeapon(owner, 1);
        MISSILE_AddElements(8, owner, damage);
        MISSILE_ScaleElements(sourceDamage, damage);
        sub_00622E90_EndWeapon(owner, 1);
    }
    else if (originDamage && origin)
    {
        MISSILE_AddElements(0, origin, damage);
        MISSILE_ScaleElements(originDamage, damage);
    }
}

void __stdcall MISSILE_CalculateDamageData(Damage* pMissileDamageData, Unit* pOwner, Unit* pOrigin, Unit* pMissile, int nLevel); // 0x0064B860

#include "gen/data/Source/D2Common/UNITS/Missile.inc"
