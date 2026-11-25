#include "D2MissileIds.h"
#include "D2GameClient.h"
#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2MonsterIds.h"
#include "D2MonModes.h"
#include "D2ItemModes.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2StatIds.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2UnitData.h"
#include "D2TxtTables.h"
#include "D2ItemsWorld.h"
#include "D2LevelTxt.h"
#include "D2LanguageNames.h"
#include "D2MonStatsInit.h"

#define UNITFLAG_TARGETABLE 0x00000002

#define UNITFLAG_ISVALIDTARGET 0x00000008

#define STAT_ITEM_ARMOR_PERCENT 16

#define STAT_SECONDARY_MINDAMAGE 23

#define STAT_SECONDARY_MAXDAMAGE 24

#define UNIT_ALIGNMENT_EVIL 0

#define UNIT_ALIGNMENT_GOOD 2

#define EVENTTYPE_AITHINK 2

#define EVENTTYPE_MONUMOD 7

#define MONTYPEFLAG_RESURRECTED 8

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNITFLAG_NOXP 0x04000000

#define PARTYSCREENTYPE_HOSTILE 3

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2StaticPathStrc;

struct D2ModeChangeStrc;

union D2SeedStrc;

struct D2MonsterDataStrc;

struct D2MonStatsTxt;

struct D2UnitStrc;

struct D2DamageStrc;

struct D2MissileStrc;

struct D2GameStrc;

struct D2CoordStrc;

struct D2DataTablesStrc;

struct D2ClientStrc;

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc*, int);

void __stdcall MISSILE_AllocMissileData(D2UnitStrc* pMissile); // 0x0064A100

void __fastcall D2GAME_DeleteTimersOnUnit_6FC34A30(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540F30

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStat, int nLayer); // 0x00625480

void __fastcall MONSTERUNIQUE_ApplyMonsterPenalty(D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A0E80

void __fastcall MONSTERUNIQUE_CastLightUniqueMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A29A0

void __fastcall MONSTERUNIQUE_ApplyElementalDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A3040

void __fastcall SKILLS_CreateMissileRing(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nVelocity); // 0x0056D400

D2UnitStrc* __fastcall SKILLS_CreateMissileAtOffset(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity); // 0x0056ECB0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

void __fastcall AIGENERAL_FreeMinionList(D2UnitStrc* pUnit); // 0x0058F160

void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030

void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60

int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0

int __fastcall SUNITDMG_SetMissileDamageFlagsForNearbyUnits(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nSize, D2DamageStrc* pDamage, int a7, int a8, int(__fastcall* pfCallback)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*), int a10); // 0x0057E090

D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30

extern const int gnBugLightningXOffsets[]; // 0x006E21A8

extern const int gnBugLightningYOffsets[]; // 0x006E2198

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, unsigned char bAllowNeighborRooms); // 0x00555DA0

void __fastcall D2GAME_DropItem_6FC52260(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00558AA0

D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAddToGame); // 0x0055A2A0

void __fastcall ITEMMODE_CompactBeltColumn(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX); // 0x0055EDC0

void __fastcall ITEMMODE_RemoveBeltItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00561E70

void __fastcall AIGENERAL_SetAiControlParam(D2UnitStrc* pMonster, int nIndex, int nParamValue); // 0x0058EC00

int __fastcall AIGENERAL_GetAiControlParam(D2UnitStrc* pUnit, int nIndex); // 0x0058EC50

int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBeltSlot(D2InventoryStrc* pInventory, int nSlotId); // 0x0063C7F0

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

typedef void(__fastcall* PartyCommandFunc)(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure);

typedef int(__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern PartyCommandFunc gpfnPartyCommands[10]; // 0x006E2218

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags); // 0x0055B300

void __fastcall PLAYERPETS_RemovePet(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetGUID, int a4); // 0x005750E0

void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int nFlags); // 0x0057DBF0

void __fastcall SUNITDMG_DistributeExperience(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0057E990

unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

void __fastcall FRIENDLY_OpenHostility(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x005A60E0

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760

void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

struct D2MissilesTxt;

void __fastcall QUESTSFX_Bloodraven(D2GameStrc*, D2UnitStrc*); // 0x005DFD90

void __fastcall QUESTSFX_SpawnMephistoDeathControlMissile(D2GameStrc*, D2UnitStrc*); // 0x005DFDB0

void __fastcall QUESTSFX_Andariel(D2GameStrc*, D2UnitStrc*); // 0x005DFE00

void __fastcall QUESTSFX_SpawnRadamentDeathMissile(D2GameStrc*, D2UnitStrc*); // 0x005DFE20

void __fastcall QUESTSFX_Izual(D2GameStrc*, D2UnitStrc*); // 0x005E0020

void __fastcall QUESTSFX_ShenkTheOverseer(D2GameStrc*, D2UnitStrc*); // 0x005E0040

void __fastcall QUESTSFX_OnQuestCompleteModeChange(D2GameStrc*, D2UnitStrc*); // 0x005E0060

void __fastcall QUESTSFX_UberPrimeEvil(D2GameStrc*, D2UnitStrc*); // 0x005E0070

extern const unsigned int gdwBitMasks[]; // 0x006CE268

int __fastcall sub_005A0180_CheckMonsterFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pPath); // 0x00648A10

int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210

int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nLowSeed); // 0x00650E40

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2SkillsTxt;

typedef void(__fastcall* CurseCallbackFunc)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel);

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

void __fastcall SKILLS_ApplyCurseAroundTarget(D2GameStrc* pGame, int nFlags, D2UnitStrc* pUnit, int nSkillLevel, int nRange, CurseCallbackFunc pfCurse); // 0x0056DBC0

void __fastcall MONSTERUNIQUE_CurseCallback_ApplyAmplifyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel); // 0x005A23D0

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

struct D2ActiveRoomStrc;

typedef void (__fastcall* UModInitFunc)(D2UnitStrc* pUnit, int nUMod, int bUnique);

typedef void (__fastcall* MinionCallbackFunc)(D2UnitStrc* pUnit, void* pArg1, void* pArg2);

extern UModInitFunc gpfnUModInitFunctions[];                                                         // 0x0073C008

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0

int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode);                              // 0x0046C140

int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit);                                                  // 0x00451F50

int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId);                // 0x005436B0

void __fastcall QUESTS_SetJadeFigurineBoss(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00544E80

void __fastcall QUESTS_MonsterSpawn(D2GameStrc* pGame, D2UnitStrc* pUnit);                                  // 0x00545B50

D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId); // 0x00547BB0

int __fastcall MONSTERREGION_FindSpawnLocation(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int nClassId, int* pX, int* pY, int bAvoidWarps); // 0x0054DC40

void __fastcall MONSTER_ToggleSummonerFlag(D2UnitStrc* pUnit, int nFlag, int bSet);                         // 0x00573570

void __fastcall AIGENERAL_AllocMinionList(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMinion);       // 0x0058F100

void __fastcall AIUTIL_SetOwnerGUIDAndType(D2UnitStrc* pUnit, D2UnitStrc* pOwner);                          // 0x005DD330

void __fastcall AIGENERAL_ExecuteCallbackOnMinions(D2UnitStrc* pUnit, void* pArg1, void* pArg2, MinionCallbackFunc pfnCallback); // 0x0058F380

void __fastcall sub_005A0200(D2UnitStrc* pUnit, short nBossHcIdx);                             // 0x005A0200

void __fastcall MONSTERUNIQUE_UMod30_AuraEnchanted(D2UnitStrc* pUnit, int nUMod, int bUnique);              // 0x005A1650

void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnitInCoordList(D2GameStrc* pGame, D2RoomCoordListStrc* pRoomCoordList, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a6, short nFlags); // 0x005B2F70

D2UnitStrc* __fastcall MONSTERSPAWN_SpawnInCoordList(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int nX, int nY, int nMonsterId, int nAnimMode, int a8, short nFlags); // 0x005B3040

int __stdcall D2Common_11063(D2ActiveRoomStrc* pRoom, int nMonsterId);                                       // 0x0063EC70

D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId);                          // 0x006556E0

int __fastcall MONSTERUNIQUE_GetUModCount(unsigned char* pUMods); // 0x005A0260

extern "C" __int64 __stdcall _alldiv(__int64 a, __int64 b); // 0x00684240

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

static void MONSTERUNIQUE_AddLifePercent(D2UnitStrc* pUnit, int nPercent); // 0x005A0D20

D2UnitStrc* __fastcall D2GAME_SpawnSuperUnique_6FC6F690(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSuperUnique); // 0x005A49B0

struct D2AuraEnchantStrc;

struct D2MonLvlTxt;

struct D2MonUModTxt;

struct D2AuraEnchantStrc
{
    int nLevel;
    int nLevelAdd;
    int nMul;
    int nDiv;
    int nSkillId;
};

extern D2AuraEnchantStrc gaAuraEnchantTable[8]; // 0x0073BF68

void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0

void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags); // 0x005701B0

enum D2C_H16ElemConstants
{
    MONLVL_DM = 6,
};

#define MONTYPEFLAG_LIGHTNINGUNIQUE 0x100

int __fastcall SKILLS_ApplyAreaDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0

void __fastcall MISSMODE_FillDamageParams(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005A89A0

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

int __fastcall MONSTERUNIQUE_GetMonUModConstant(int nIndex); // 0x005A00F0

// 0x005A0030
int __fastcall MONSTERUNIQUE_GetMonLvlTxtRecordCount()
{
    return sgptDataTables->nMonLvlTxtRecordCount;
}

// 0x005A0040
D2MonUModTxt* __fastcall MONSTERUNIQUE_GetMonUModTxtRecord(int nUMod)
{
    if (nUMod >= sgptDataTables->nMonUModTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMonUModTxt[nUMod];
}

// 0x005A0060
int __fastcall MONSTERUNIQUE_GetMonUModTxtRecordCount()
{
    return sgptDataTables->nMonUModTxtRecordCount;
}

static inline D2MonsterDataStrc* CLIENT_GetMonsterDataInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }

    return 0;
}

// 0x005A0220
static inline int MONSTERUNIQUE_GetMonsterField18(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = CLIENT_GetMonsterDataInline(pUnit);
    if (!pMonsterData)
    {
        return 0;
    }

    return pMonsterData->dwDurielFlag;
}

// 0x005A0240
static inline void MONSTERUNIQUE_SetMonsterField18(D2UnitStrc* pUnit, int nValue)
{
    D2MonsterDataStrc* pMonsterData = CLIENT_GetMonsterDataInline(pUnit);
    if (pMonsterData)
    {
        pMonsterData->dwDurielFlag = nValue;
    }
}

int __fastcall sub_M117_Emit_005A0220(D2UnitStrc* pUnit, int nValue)
{
    MONSTERUNIQUE_SetMonsterField18(pUnit, nValue);
    return MONSTERUNIQUE_GetMonsterField18(pUnit);
}

static inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x005A0070
int __fastcall MONSTERUNIQUE_MONSTERUNIQUE_CheckMonType(D2UnitStrc* pUnit, int nMonType)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
    if (pMonStatsTxtRecord && pMonStatsTxtRecord->wMonType >= 0 && pMonStatsTxtRecord->wMonType < sgptDataTables->nMonTypeTxtRecordCount
        && nMonType >= 0 && nMonType < sgptDataTables->nMonTypeTxtRecordCount)
    {
        return gdwBitMasks[pMonStatsTxtRecord->wMonType & 31] & sgptDataTables->pMonTypeNest[(pMonStatsTxtRecord->wMonType >> 5) + nMonType * sgptDataTables->nMonTypeIndex];
    }

    return 0;
}

// 0x005A00F0
int __fastcall MONSTERUNIQUE_GetMonUModConstant(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nMonUModTxtRecordCount)
    {
        D2MonUModTxt* pMonUModTxtRecord = &sgptDataTables->pMonUModTxt[nIndex];
        if (pMonUModTxtRecord)
        {
            return pMonUModTxtRecord->dwConstants;
        }
    }

    return 0;
}


struct Data005A0180 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned short wUnknown14;
    unsigned short wFlags16;
};

struct Unit005A0180 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data005A0180* pData;
};

#pragma pack(push, 1)
struct Data004AC780 { unsigned char bUnknown00[0x14]; unsigned short wValue14; };

#pragma pack(pop)
struct Unit004AC780 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data004AC780* pData;
};

struct Data005A01E0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned short wUnknown24;
    short sValue26;
};

struct Unit005A01E0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data005A01E0* pData;
};

#pragma pack(push, 1)
struct Data005A0200 { unsigned char bUnknown00[0x26]; unsigned short wValue26; };

#pragma pack(pop)
struct Unit005A0200 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data005A0200* pData;
};
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0


static inline D2MonsterDataStrc* MonsterDataOf(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}

static inline unsigned char* UModsOf(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nMonUmod;
    }
    return 0;
}


static inline void SetMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag, int bSet)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
    {
        return;
    }

    if (bSet)
    {
        pMonsterData->nTypeFlag |= nFlag;
    }
    else
    {
        pMonsterData->nTypeFlag &= ~nFlag;
    }
}

static inline int CountUMods(unsigned char* pUMods)
{
    int nIndex = 0;
    while (nIndex < 9 && pUMods[nIndex])
    {
        ++nIndex;
    }
    return nIndex;
}

static inline int CountUModsTo(unsigned char* pUMods)
{
    for (int i = 0; i < 9; ++i)
    {
        if (!pUMods[i])
        {
            return i;
        }
    }
    return 9;
}

static inline int TestMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData && (pUnit->pMonsterData->nTypeFlag & nFlag))
    {
        return 1;
    }
    return 0;
}

static inline unsigned char* UModsOfData(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = 0;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        pMonsterData = pUnit->pMonsterData;
    }

    if (!pMonsterData)
    {
        return 0;
    }
    return pMonsterData->nMonUmod;
}

static inline void InitUMod(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    UModInitFunc pfnInit = gpfnUModInitFunctions[nUMod];
    if (pfnInit)
    {
        pfnInit(pUnit, nUMod, bUnique);
    }
}

static inline D2MonStatsTxt* MonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}


static inline D2MonStatsTxt* MonStatsTxtRecordOrNull(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return 0;
    }
    return &sgptDataTables->pMonStatsTxt[nMonsterId];
}

static inline unsigned int TestMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MonStatsTxtRecordOrNull(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }
    return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

static inline D2MonUModTxt* MonUModTxtRecord(int nUMod)
{
    if (!(nUMod < sgptDataTables->nMonUModTxtRecordCount))
        return 0;
    return &sgptDataTables->pMonUModTxt[nUMod];
}


static inline unsigned int RollRandomInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static inline int RollLimitedInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if (((unsigned int)nMax - 1) & (unsigned int)nMax)
    {
        return RollRandomInline(pSeed) % nMax;
    }

    return RollRandomInline(pSeed) & (nMax - 1);
}

#define MONTYPEFLAG_CHAMPION 4

#define MONSTERUNIQUE_UMOD_COUNT 9

struct D2MonsterRegionStrc;

struct D2SuperUniquesTxt;

int __stdcall sub_O05_EmitArg_AddUMod(D2UnitStrc* pUnit, int nValue);

static inline D2MonUModTxt* sub_M433_GetMonUModTxtRecord(int nUMod)
{
    if (nUMod >= sgptDataTables->nMonUModTxtRecordCount)
    {
        return 0;
    }
    return &sgptDataTables->pMonUModTxt[nUMod];
}

// 0x005A0280
int __fastcall MONSTERUNIQUE_GetChampionUMod(D2UnitStrc* pUnit)
{
    const unsigned int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    D2MonsterDataStrc* pMonsterData = (nUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
    {
        return 0;
    }

    if (!(pMonsterData->nTypeFlag & MONTYPEFLAG_CHAMPION))
    {
        return 0;
    }

    for (int i = 0; i < MONSTERUNIQUE_UMOD_COUNT; ++i)
    {
        if (!pMonsterData->nMonUmod[i])
        {
            return 0;
        }

        D2MonUModTxt* pMonUModTxtRecord = sub_M433_GetMonUModTxtRecord(pMonsterData->nMonUmod[i]);
        if (!pMonUModTxtRecord)
        {
            return 0;
        }

        if (pMonUModTxtRecord->nChampion)
        {
            return pMonsterData->nMonUmod[i];
        }
    }

    return 0;
}

void __fastcall MONSTERUNIQUE_PromoteToUnique(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A4940

// 0x005A02E0
static void __stdcall MONSTERUNIQUE_AddUMod(int nUMod, D2UnitStrc* pUnit)
{
    const unsigned int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != 1)
    {
        return;
    }

    if (D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData)
    {
        int nIndex = 0;
        while (nIndex < 9 && pMonsterData->nMonUmod[nIndex])
        {
            ++nIndex;
        }

        if (nIndex < 9)
        {
            pMonsterData->nMonUmod[nIndex] = (unsigned char)nUMod;
        }
    }
}

// 0x005A0320
static void __stdcall MONSTERUNIQUE_MarkUnique(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == 1)
    {
        D2MonsterRegionStrc* pMonsterRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pGame->pMonReg, MONSTER_GetLevelId(pUnit));
        if (pMonsterRegion && !TestMonTypeFlag(pUnit, 8))
        {
            ++pMonsterRegion->dwUniqueCount;
        }

        SetMonTypeFlag(pUnit, 8, 1);
    }
}

static inline int GetUnitType(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

// 0x005A0380
int __fastcall MONSTERUNIQUE_HasMonsterFlag(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = 0;
    if (GetUnitType(pUnit) == 1)
    {
        pMonsterData = pUnit->pMonsterData;
    }
    if (!pMonsterData)
    {
        return 0;
    }
    return pMonsterData->nMonUmod[0] != 0;
}

short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit); // 0x005A01E0

// 0x005A03A0
int __fastcall MONSTERUNIQUE_GetSuperUniqueBossHcIdx(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    D2MonsterDataStrc* pMonsterData = (nType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData || !(pMonsterData->nTypeFlag & MONTYPEFLAG_SUPERUNIQUE))
    {
        return -1;
    }

    return MONSTERUNIQUE_GetBossHcIdx(pUnit);
}

// 0x005A03E0
static int __stdcall MONSTERUNIQUE_CanAssignUMod(D2UnitStrc* pUnit, D2MonUModTxt* pMonUModTxtRecord, int bExpansion)
{
    if (!pMonUModTxtRecord->nEnabled)
    {
        return 0;
    }

    if (!bExpansion && pMonUModTxtRecord->wVersion >= 100)
    {
        return 0;
    }

    for (int i = 0; i < 2; ++i)
    {
        const short nExcludeMonType = pMonUModTxtRecord->wExclude[i];
        if (nExcludeMonType <= 0)
        {
            break;
        }

        if (sub_005A0070(pUnit, nExcludeMonType))
        {
            return 0;
        }
    }

    switch (pMonUModTxtRecord->nFPick)
    {
    case 1:
        if (!sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, 4))
        {
            return 0;
        }
        break;

    case 2:
        if (pUnit)
        {
            if (TestMonStatsFlag(pUnit->dwClassId, 1))
            {
                return 0;
            }

            if (TestMonStatsFlag(pUnit->dwClassId, 17))
            {
                return 0;
            }
        }
        break;

    case 3:
        if (!sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, 2))
        {
            return 0;
        }
        break;
    }

    return 1;
}

// 0x005A0500
static int MONSTERUNIQUE_RollChampionUMod(D2UnitStrc* pUnit, D2GameStrc* pGame)
{
    int aPicks[512];
    int nPickCount = 0;

    if (!pGame)
    {
        return 0;
    }

    const unsigned char nDifficulty = pGame->nDifficulty;
    if (nDifficulty >= 3)
    {
        return 0;
    }

    const int bExpansion = pGame->bExpansion;
    int nTotal = 0;
    const int nRecords = sgptDataTables->nMonUModTxtRecordCount;
    D2MonUModTxt* pMonUModTxtRecord = MonUModTxtRecord(0);
    if (!pMonUModTxtRecord)
    {
        return 0;
    }

    for (int i = 0; i < nRecords; ++i, ++pMonUModTxtRecord)
    {
        const short nPick = pMonUModTxtRecord->wCPick[nDifficulty];
        if (nPick > 0 && pMonUModTxtRecord->nChampion && MONSTERUNIQUE_CanAssignUMod(pUnit, pMonUModTxtRecord, bExpansion))
        {
            nTotal += nPick;
            aPicks[2 * nPickCount] = i;
            aPicks[2 * nPickCount + 1] = nPick;
            ++nPickCount;
            if (nPickCount >= 256)
            {
                break;
            }
        }
    }

    int nRand = SEED_RollLimitedRandomNumber(&pUnit->pSeed, nTotal);
    for (int i = 0; i < nPickCount; ++i)
    {
        if (nRand < aPicks[2 * i + 1])
        {
            return aPicks[2 * i];
        }
        nRand -= aPicks[2 * i + 1];
    }

    return 0;
}

// 0x005A0600
static int __stdcall MONSTERUNIQUE_RollNonChampionUMod(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pUsedUMods)
{
    int aPicks[512];

    if (!pGame || pGame->nDifficulty >= 3)
    {
        return 0;
    }

    const unsigned char nDifficulty = pGame->nDifficulty;

    const int bExpansion = pGame->bExpansion;
    int nPickCount = 0;
    int nTotal = 0;
    const int nRecords = sgptDataTables->nMonUModTxtRecordCount;
    D2MonUModTxt* pMonUModTxtRecord = MonUModTxtRecord(0);
    for (int i = 0; i < nRecords; ++i, ++pMonUModTxtRecord)
    {
        const short nPick = pMonUModTxtRecord->wUPick[nDifficulty];
        if (nPick > 0 && !pMonUModTxtRecord->nChampion && MONSTERUNIQUE_CanAssignUMod(pUnit, pMonUModTxtRecord, bExpansion) && !pUsedUMods[i])
        {
            nTotal += nPick;
            aPicks[2 * nPickCount] = i;
            aPicks[2 * nPickCount + 1] = nPick;
            ++nPickCount;
            if (nPickCount >= 256)
            {
                break;
            }
        }
    }

    int nRand = RollLimitedInline(&pUnit->pSeed, nTotal);
    for (int i = 0; i < nPickCount; ++i)
    {
        if (nRand < aPicks[2 * i + 1])
        {
            return aPicks[2 * i];
        }
        nRand -= aPicks[2 * i + 1];
    }

    return 0;
}

// 0x005A0120
unsigned char* __fastcall MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
    {
        return 0;
    }
    return pMonsterData->nMonUmod;
}

// 0x005A0260
int __fastcall MONSTERUNIQUE_GetUModCount(unsigned char* pUMods)
{
    int nCount;
    for (nCount = 0; nCount < 9; nCount++, pUMods++)
    {
        if (!*pUMods)
        {
            return nCount;
        }
    }
    return 9;
}

// 0x005A0760
static void __stdcall MONSTERUNIQUE_AssignRandomUMods(D2GameStrc* pGame, D2UnitStrc* pUnit, int bAllowChampion)
{
    unsigned char bUModUsageTable[256];

    if (!pGame || pGame->nDifficulty >= 3)
    {
        return;
    }

    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != 1)
    {
        return;
    }

    unsigned char* pUMods = MONSTERUNIQUE_GetUMods(pUnit);
    if (!pUMods)
    {
        return;
    }

    const int nIndex = MONSTERUNIQUE_GetUModCount(pUMods);
    if (nIndex >= 8)
    {
        return;
    }

    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (!pSeed)
    {
        return;
    }

    if (bAllowChampion)
    {
        int nChance;
        if (sgptDataTables->nMonUModTxtRecordCount <= 0)
        {
            nChance = 0;
        }
        else
        {
            D2MonUModTxt* pRecord = sgptDataTables->pMonUModTxt;
            if (!pRecord)
            {
                nChance = 0;
            }
            else
            {
                nChance = pRecord->dwConstants;
            }
        }
        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < nChance)
        {
            SetMonTypeFlag(pUnit, 4, 1);
            MONSTERUNIQUE_AddUMod(MONSTERUNIQUE_RollChampionUMod(pUnit, pGame), pUnit);
            return;
        }
    }

    int nRandCount = SEED_RollLimitedRandomNumber(pSeed, 1) + 1;
    nRandCount += pGame->nDifficulty;
    if (nRandCount + nIndex >= 9)
    {
        nRandCount = 9 - nIndex;
    }

    memset(bUModUsageTable, 0, sgptDataTables->nMonUModTxtRecordCount);
    for (int i = 0; i < nIndex; ++i)
    {
        bUModUsageTable[pUMods[i]] = 1;
    }

    pUMods += nIndex;
    while (nRandCount)
    {
        const int nUMod = MONSTERUNIQUE_RollNonChampionUMod(pGame, pUnit, bUModUsageTable);
        if (!nUMod)
        {
            break;
        }

        *pUMods = nUMod;
        --nRandCount;
        ++pUMods;
        bUModUsageTable[nUMod] = 1;
    }
}

// 0x005A11F0
void __fastcall MONSTERUNIQUE_UMod37_Fanatic(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && bUnique)
    {
        STATLIST_SetUnitStat(pUnit, STAT_ITEM_ARMOR_PERCENT, -70, 0);
        MONSTERUNIQUE_ApplyMonsterPenalty(pUnit, nUMod, bUnique);
    }
}

static inline D2MonsterDataStrc* MONSTERUNIQUE_GetMonsterData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        return pUnit->pMonsterData;
    return 0;
}







enum { MONTYPEFLAG_POSSESSED = 0x20 };

// 0x005A1230
void __fastcall MONSTERUNIQUE_UMod38_Possessed(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    if (!pUnit || nUnitType != UNIT_MONSTER || !bUnique)
        return;

    D2MonsterDataStrc* pMonsterData = MONSTERUNIQUE_GetMonsterData(pUnit);
    if (pMonsterData)
        pMonsterData->nTypeFlag |= MONTYPEFLAG_POSSESSED;

    MONSTERUNIQUE_AddLifePercent(pUnit, 100);
    MONSTERUNIQUE_ApplyMonsterPenalty(pUnit, nUMod, bUnique);
}

int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit);                                                             // 0x00463860

int __fastcall CUNIT_ValidateMonsterId(int nMonsterId);                                              // 0x00463900
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty);                   // 0x00611D30
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010

// 0x005A1280
void __fastcall MONSTERUNIQUE_UModChampion(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame || !bUnique)
    {
        return;
    }

    MONSTERUNIQUE_AddLifePercent(pUnit, -75);

    int nDamage = 300;
    int nToHit = nDamage;
    D2DifficultyLevelsTxt* pRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    if (pRecord)
    {
        nDamage = pRecord->dwChampionDmgBonus * 300 / 100;
        nToHit = nDamage;
        if (CUNIT_ValidateMonsterId(CUNIT_GetMonsterBaseId(pUnit)) == 0x76)
        {
            nDamage /= 2;
        }
    }

    STATLIST_AddUnitStat(pUnit, STAT_DAMAGEPERCENT, nDamage, 0);
    STATLIST_AddUnitStat(pUnit, STAT_ITEM_TOHIT_PERCENT, nToHit, 0);
}

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010

// 0x005A1330
void __fastcall MONSTERUNIQUE_UMod41_AlwaysRun(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
        if (pGame)
        {
            EVENT_SetEvent(pGame, pUnit, 7, pGame->dwGameFrame + 75, 0, 0);
        }
    }
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}


static inline int MONSTERUNIQUE_ApplyPercentage(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
        return 0;
    if (nValue <= 0x100000)
    {
        if (nMultiplier <= 0x10000)
            return (int)((unsigned int)nMultiplier * (unsigned int)nValue) / nDivisor;
        if (nDivisor <= (nMultiplier >> 4))
            return (int)((unsigned int)nValue * (unsigned int)(nMultiplier / nDivisor));
    }
    else if (nDivisor <= (nValue >> 4))
    {
        return (int)((unsigned int)nMultiplier * (unsigned int)(nValue / nDivisor));
    }
    return (int)(nMultiplier * (__int64)nValue / nDivisor);
}

// 0x005A1370
int __fastcall MONSTERUNIQUE_UMod8_Resistant(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (pUnit && (!pUnit ? 6 : pUnit->dwUnitType) == 1 && bUnique)
    {
        if (nUMod == 28)
        {
            int nDefense = 2 * STATLIST_UnitGetStatValue(pUnit, 31, 0);
            STATLIST_SetUnitStat(pUnit, 31, nDefense, 0);
        }

        int nImmunities = 0;
        int nFireResist = STATLIST_UnitGetStatValue(pUnit, 39, 0);
        int nLightResist = STATLIST_UnitGetStatValue(pUnit, 41, 0);
        int nColdResist = STATLIST_UnitGetStatValue(pUnit, 43, 0);
        int nPoisonResist = STATLIST_UnitGetStatValue(pUnit, 45, 0);
        int nDamageResist = STATLIST_UnitGetStatValue(pUnit, 36, 0);
        int nMagicResist = STATLIST_UnitGetStatValue(pUnit, 37, 0);

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
                    STATLIST_SetUnitStat(pUnit, 43, nNewColdResist, 0);
                    if (nNewColdResist >= 100) ++nImmunities;
                }
                if (nImmunities < 2)
                {
                    if (nFireResist < 100)
                    {
                        int nNewFireResist = nFireResist + 40;
                        STATLIST_SetUnitStat(pUnit, 39, nNewFireResist, 0);
                        if (nNewFireResist >= 100) ++nImmunities;
                    }
                    if (nImmunities < 2)
                    {
                        if (nLightResist < 100)
                        {
                            int nNewLightResist = nLightResist + 40;
                            STATLIST_SetUnitStat(pUnit, 41, nNewLightResist, 0);
                            if (nNewLightResist >= 100) return nImmunities + 1;
                        }
                    }
                }
            }
            else if (nUMod == 9) STATLIST_SetUnitStat(pUnit, 39, nFireResist + 75, 0);
            else if (nUMod == 18) STATLIST_SetUnitStat(pUnit, 43, nColdResist + 75, 0);
            else if (nUMod == 17) STATLIST_SetUnitStat(pUnit, 41, nLightResist + 75, 0);
            else if (nUMod == 23) STATLIST_SetUnitStat(pUnit, 45, nPoisonResist + 75, 0);
            else if (nUMod == 25) STATLIST_SetUnitStat(pUnit, 37, nMagicResist + 20, 0);
            else if (nUMod == 27)
            {
                if (nColdResist < 75)
                {
                    int nNewColdResist = nColdResist + 20;
                    STATLIST_SetUnitStat(pUnit, 43, nNewColdResist, 0);
                    if (nNewColdResist >= 100) ++nImmunities;
                }
                if (nImmunities < 2)
                {
                    if (nFireResist < 75)
                    {
                        int nNewFireResist = nFireResist + 20;
                        STATLIST_SetUnitStat(pUnit, 39, nNewFireResist, 0);
                        if (nNewFireResist >= 100) ++nImmunities;
                    }
                    if (nImmunities < 2)
                    {
                        if (nLightResist < 75)
                        {
                            int nNewLightResist = nLightResist + 20;
                            STATLIST_SetUnitStat(pUnit, 41, nNewLightResist, 0);
                            if (nNewLightResist >= 100) return nImmunities + 1;
                        }
                    }
                }
            }
            else if (nUMod == 28) STATLIST_SetUnitStat(pUnit, 36, nDamageResist + 50, 0);
        }
    }
}

// 0x005A0140
unsigned short __fastcall MONSTERUNIQUE_GetNameSeed(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
    {
        return 5382;
    }
    return pMonsterData->wNameSeed;
}

// 0x005A0160
extern "C" __declspec(dllexport) void __fastcall sub_005A0160(Unit004AC780* pUnit, unsigned short wValue) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        pUnit->pData->wValue14 = wValue;
    }
}

// 0x005A0180
extern "C" __declspec(dllexport) int __fastcall sub_005A0180(Unit005A0180* pUnit, unsigned short wMask) {
    Data005A0180* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return 0;
    }
    return (unsigned short)(pData->wFlags16 & wMask) != 0;
}

// 0x005A01B0
void __fastcall MONSTERUNIQUE_ToggleMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag, int bSet)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
    {
        return;
    }

    if (bSet)
    {
        pMonsterData->nTypeFlag |= nFlag;
    }
    else
    {
        pMonsterData->nTypeFlag &= ~nFlag;
    }
}

// 0x005A01E0
short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
    {
        return -1;
    }
    return pMonsterData->wBossHcIdx;
}

// 0x005A0200
extern "C" __declspec(dllexport) void __fastcall sub_005A0200(Unit005A0200* pUnit, unsigned short wValue) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        pUnit->pData->wValue26 = wValue;
    }
}

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
void __fastcall AIUTIL_ToggleAiControlFlag0x20(D2UnitStrc* pUnit, int bSet); // 0x005DD250

// 0x005A1600
void __fastcall MONSTERUNIQUE_UMod26_Teleport(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER && bUnique)
    {
        D2GAME_SetSkills_6FD14C60(pUnit, SKILL_MONTELEPORT, 1, 1);
        SKILLS_SetSkillMode(SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_MONTELEPORT), 4);
        AIUTIL_ToggleAiControlFlag0x20(pUnit, 1);
    }
}

// 0x005A1650
void __fastcall MONSTERUNIQUE_UMod30_AuraEnchanted(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if ((!pUnit ? 6 : pUnit->dwUnitType) != 1 || !bUnique)
    {
        return;
    }

    int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    if (nLevel <= 0)
    {
        nLevel = 1;
    }

    int nCount = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (gaAuraEnchantTable[i].nLevel <= nLevel)
        {
            ++nCount;
        }
    }

    if (!nCount)
    {
        nCount = 1;
    }

    const unsigned short wNameSeed = MONSTERUNIQUE_GetNameSeed(pUnit);
    D2SeedStrc tSeed;
    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, wNameSeed);
    int nIndex = SEED_RollLimitedRandomNumber(&tSeed, nCount);
    if (MONSTERUNIQUE_GetBossHcIdx(pUnit) == 37)
    {
        nIndex = 5;
    }

    if (pUnit->dwClassId == 0x2C0)
    {
        D2GAME_SetSkills_6FD14C60(pUnit, SKILL_CONVICTION, 20, 1);
        D2GAME_AssignSkill_6FD13800(pUnit, 0, SKILL_CONVICTION, -1);
        return;
    }

    int nSkillLevel = (gaAuraEnchantTable[nIndex].nLevelAdd + nLevel) * gaAuraEnchantTable[nIndex].nMul / gaAuraEnchantTable[nIndex].nDiv;
    nSkillLevel = D2_MIN(D2_MAX(nSkillLevel, 1), 99);

    D2GAME_SetSkills_6FD14C60(pUnit, gaAuraEnchantTable[nIndex].nSkillId, nSkillLevel, 1);
    D2GAME_AssignSkill_6FD13800(pUnit, 0, gaAuraEnchantTable[nIndex].nSkillId, -1);
}

static inline D2MissilesTxt* MONUNIQUE_GetMissilesTxtRecord_Inline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nMissileId];
    return 0;
}

static inline D2MonLvlTxt* MONUNIQUE_GetMonLvlTxtRecord_Inline(int nLevel)
{
    if (nLevel >= 0 && nLevel < sgptDataTables->nMonLvlTxtRecordCount)
        return &sgptDataTables->pMonLvlTxt[nLevel];
    return 0;
}

static inline int MONUNIQUE_GetMonUModConstant_Inline(int nIndex)
{
    if (nIndex < 0 || nIndex >= sgptDataTables->nMonUModTxtRecordCount)
        return 0;
    D2MonUModTxt* pRecord = &sgptDataTables->pMonUModTxt[nIndex];
    if (!pRecord)
        return (int)pRecord;
    return pRecord->dwConstants;
}

static inline unsigned int MONUNIQUE_RollSeed_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

#define STAT_LEVEL 12

#define UNIT_MONSTER 1

struct D2DifficultyLevelsTxt;

struct D2CurseStrc;


D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010

D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0

int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);

D2StatListStrc* __fastcall SKILLS_ApplyStateEffect(D2CurseStrc* pCurse); // 0x0056E970

int __stdcall DATATBLS_CalculateMonsterStatsByLevel(int nMonsterId, int nGameType, int nDifficulty, int nLevel, short nFlags, D2MonStatsInitStrc* pMonStatsInit); // 0x006538A0

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

static __forceinline int sub_A17E0_GetUModConstant(int nUMod)
{
    if (nUMod >= sgptDataTables->nMonUModTxtRecordCount)
    {
        return 0;
    }

    D2MonUModTxt* pMonUModTxtRecord = &sgptDataTables->pMonUModTxt[nUMod];
    if (!pMonUModTxtRecord)
    {
        return 0;
    }
    return pMonUModTxtRecord->dwConstants;
}

// 0x005A17E0
void __fastcall MONSTERUNIQUE_UMod5_Strong(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    int nDamage;
    int nToHit;
    if (bUnique)
    {
        nDamage = sub_A17E0_GetUModConstant(15);
        nToHit = sub_A17E0_GetUModConstant(13);
    }
    else
    {
        nDamage = sub_A17E0_GetUModConstant(14);
        nToHit = sub_A17E0_GetUModConstant(12);
    }

    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    if (pDifficultyLevelsTxtRecord)
    {
        nDamage = nDamage * pDifficultyLevelsTxtRecord->dwChampionDmgBonus / 100;
        nToHit = nToHit * pDifficultyLevelsTxtRecord->dwChampionDmgBonus / 100;

        const int nMonsterId = sub_00463860_GetMonsterId(pUnit);
        if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount && nMonsterId == MONSTER_WILLOWISP1)
        {
            nDamage /= 2;
        }
    }

    STATLIST_AddUnitStat(pUnit, STAT_DAMAGEPERCENT, nDamage, 0);
    STATLIST_AddUnitStat(pUnit, STAT_ITEM_TOHIT_PERCENT, nToHit, 0);
}


// 0x005A1910
void __fastcall MONSTERUNIQUE_UMod6_Fast(D2UnitStrc* pUnit, int nUnused1, int nUnused2)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->nVelocity > 0)
        {
            const int nValue = 0x800 / pMonStatsTxtRecord->nVelocity - 0x80;
            STATLIST_AddUnitStat(pUnit, STAT_VELOCITYPERCENT, D2_MIN(D2_MAX(nValue, 10), 100), 0);
        }
    }
}

inline D2MonLvlTxt* DATATBLS_GetMonLvlTxtRecord_Inline(int nLevel)
{
    if (nLevel >= 0 && nLevel < sgptDataTables->nMonLvlTxtRecordCount)
    {
        return &sgptDataTables->pMonLvlTxt[nLevel];
    }

    return 0;
}

// 0x005A1990
void __fastcall MONSTERUNIQUE_UMod9_FireEnchanted(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    const int nDifficulty = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    const int nGameType = pGame->nGameType || pGame->dwGameType;
    const int nStatLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    const int nLevel = D2_MIN(D2_MAX(nStatLevel, 1), sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = DATATBLS_GetMonLvlTxtRecord_Inline(nLevel);
    if (!pMonLvlTxtRecord)
    {
        return;
    }

    const int nDamage = pMonLvlTxtRecord->nValues[MONLVL_DM + nGameType][nDifficulty];
    int nMinDamage;
    int nMaxDamage;
    if (bUnique)
    {
        nMinDamage = MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 28) * nDamage / 100;
        nMaxDamage = MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 31) * nDamage / 100;
    }
    else
    {
        nMinDamage = MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 16) * nDamage / 100;
        nMaxDamage = MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 19) * nDamage / 100;
    }

    STATLIST_AddUnitStat(pUnit, STAT_FIREMINDAM, nMinDamage, 0);
    STATLIST_AddUnitStat(pUnit, STAT_FIREMAXDAM, nMaxDamage, 0);
    MONSTERUNIQUE_UMod8_Resistant(pUnit, nUMod, bUnique);
}

// 0x005A1B00
void __fastcall MONSTERUNIQUE_UMod17_LightningEnchanted(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    const int nDifficulty = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    const int nGameType = pGame->nGameType || pGame->dwGameType;
    const int nStatLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    const int nLevel = D2_MIN(D2_MAX(nStatLevel, 1), sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = DATATBLS_GetMonLvlTxtRecord_Inline(nLevel);
    if (!pMonLvlTxtRecord)
    {
        return;
    }

    const int nDamage = pMonLvlTxtRecord->nValues[MONLVL_DM + nGameType][nDifficulty];
    int nMinDamage;
    int nMaxDamage;
    if (bUnique)
    {
        nMinDamage = MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 28) * nDamage / 100;
        nMaxDamage = MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 31) * nDamage / 100;
    }
    else
    {
        nMinDamage = MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 16) * nDamage / 100;
        nMaxDamage = MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 19) * nDamage / 100;
    }

    STATLIST_AddUnitStat(pUnit, STAT_LIGHTMINDAM, nMinDamage, 0);
    STATLIST_AddUnitStat(pUnit, STAT_LIGHTMAXDAM, nMaxDamage, 0);
    MONSTERUNIQUE_UMod8_Resistant(pUnit, nUMod, bUnique);
}

// 0x005A1C70
void __fastcall MONSTERUNIQUE_UMod18_ColdEnchanted(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    const int nDifficulty = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    const int nGameType = pGame->nGameType || pGame->dwGameType;
    int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    nLevel = D2_MIN(D2_MAX(nLevel, 1), sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = DATATBLS_GetMonLvlTxtRecord_Inline(nLevel);
    if (!pMonLvlTxtRecord)
    {
        return;
    }

    const int nDamage = pMonLvlTxtRecord->nValues[MONLVL_DM + nGameType][nDifficulty];
    int nMinDamage;
    int nMaxDamage;
    if (bUnique)
    {
        nMinDamage = MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 28) * nDamage / 100;
        nMaxDamage = MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 31) * nDamage / 100;
    }
    else
    {
        nMinDamage = MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 16) * nDamage / 100;
        nMaxDamage = MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 19) * nDamage / 100;
    }

    STATLIST_AddUnitStat(pUnit, STAT_COLDMINDAM, nMinDamage, 0);
    STATLIST_AddUnitStat(pUnit, STAT_COLDMAXDAM, nMaxDamage, 0);
    STATLIST_AddUnitStat(pUnit, STAT_COLDLENGTH, 5 * nLevel + 100, 0);
    MONSTERUNIQUE_UMod8_Resistant(pUnit, nUMod, bUnique);
}

// 0x005A1E00
void __fastcall MONSTERUNIQUE_UMod23_PoisonEnchanted(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    const int nDifficulty = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    const int nGameType = pGame->nGameType || pGame->dwGameType;
    int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    nLevel = D2_MIN(D2_MAX(nLevel, 1), sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = DATATBLS_GetMonLvlTxtRecord_Inline(nLevel);
    if (!pMonLvlTxtRecord)
    {
        return;
    }

    const int nDamage = pMonLvlTxtRecord->nValues[MONLVL_DM + nGameType][nDifficulty];
    int nMinDamage;
    int nMaxDamage;
    if (bUnique)
    {
        nMinDamage = MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 28) * nDamage / 100;
        nMaxDamage = MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 31) * nDamage / 100;
    }
    else
    {
        nMinDamage = MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 16) * nDamage / 100;
        nMaxDamage = MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 19) * nDamage / 100;
    }

    STATLIST_AddUnitStat(pUnit, STAT_POISONMINDAM, nMinDamage, 0);
    STATLIST_AddUnitStat(pUnit, STAT_POISONMAXDAM, nMaxDamage, 0);
    STATLIST_AddUnitStat(pUnit, STAT_POISONLENGTH, 2 * (5 * nLevel + 150), 0);
    MONSTERUNIQUE_UMod8_Resistant(pUnit, nUMod, bUnique);
}

// 0x005A1F90
void __fastcall MONSTERUNIQUE_UMod25_ManaSteal(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    const int nDifficulty = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    const int nGameType = pGame->nGameType || pGame->dwGameType;
    const int nStatLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    const int nLevel = D2_MIN(D2_MAX(nStatLevel, 1), sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = DATATBLS_GetMonLvlTxtRecord_Inline(nLevel);
    if (!pMonLvlTxtRecord)
    {
        return;
    }

    const int nDamage = pMonLvlTxtRecord->nValues[MONLVL_DM + nGameType][nDifficulty];
    int nMinDamage;
    int nMaxDamage;
    if (bUnique)
    {
        nMinDamage = MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 28) * nDamage / 100;
        nMaxDamage = MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 31) * nDamage / 100;
    }
    else
    {
        nMinDamage = MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 16) * nDamage / 100;
        nMaxDamage = MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 19) * nDamage / 100;
    }

    STATLIST_AddUnitStat(pUnit, STAT_MANADRAINMINDAM, nMinDamage << 8, 0);
    STATLIST_AddUnitStat(pUnit, STAT_MANADRAINMAXDAM, nMaxDamage << 8, 0);
    MONSTERUNIQUE_UMod8_Resistant(pUnit, nUMod, bUnique);
}

// 0x005A2100
void __fastcall MONSTERUNIQUE_InitializeUMod(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    UModInitFunc pCallback = gpfnUModInitFunctions[nUMod];
    if (pCallback)
    {
        pCallback(pUnit, nUMod, bUnique);
    }
}

// 0x005A21D0
static void __stdcall MONSTERUNIQUE_ApplyElementalDamageStats(D2UnitStrc* pUnit, int nMinDamageStatId, int nMaxDamageStatId, int nLengthStatId, D2GameStrc* pGame)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MISSILE)
    {
        D2MissilesTxt* pMissilesTxtRecord = MONUNIQUE_GetMissilesTxtRecord_Inline(pUnit->dwClassId);
        if (!pMissilesTxtRecord || pMissilesTxtRecord->nMissileFlags[1] & gdwBitMasks[5])
            return;
    }

    const int nDifficulty = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    const int nGameType = pGame->nGameType || pGame->dwGameType;
    const int nStatLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    const int nLevel = D2_MIN(D2_MAX(nStatLevel, 1), sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = MONUNIQUE_GetMonLvlTxtRecord_Inline(nLevel);
    if (!pMonLvlTxtRecord)
        return;

    const int nDamage = pMonLvlTxtRecord->nValues[MONLVL_DM + nGameType][nDifficulty];
    const int nMinDamage = MONUNIQUE_GetMonUModConstant_Inline(28) * nDamage / 100;
    const int nMaxDamage = MONUNIQUE_GetMonUModConstant_Inline(31) * nDamage / 100;

    D2StatListStrc* pStatList = 0;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 1);
        STATLIST_SetStat(pStatList, nMinDamageStatId, nMinDamage, 0);
        STATLIST_SetStat(pStatList, nMaxDamageStatId, nMaxDamage, 0);
    }
    else
    {
        STATLIST_SetUnitStat(pUnit, nMinDamageStatId, nMinDamage, 0);
        STATLIST_SetUnitStat(pUnit, nMaxDamageStatId, nMaxDamage, 0);
    }

    if (nLengthStatId == -1)
        return;

    const int nLength = STATLIST_UnitGetStatValue(pUnit, nLengthStatId, 0) + 40;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        STATLIST_SetStat(pStatList, nLengthStatId, nLength, 0);
    else
        STATLIST_SetUnitStat(pUnit, nLengthStatId, nLength, 0);
}

// 0x005A23D0
void __fastcall MONSTERUNIQUE_CurseCallback_ApplyAmplifyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel)
{
    if (!sub_00554200(pGame, pUnit, pTarget))
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(SKILL_AMPLIFYDAMAGE);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->wAuraStat[0] < -1 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return;
    }

    if (pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    D2CurseStrc curse = {};

    curse.pTarget = pTarget;
    curse.pUnit = pUnit;
    curse.nSkill = SKILL_AMPLIFYDAMAGE;
    curse.nSkillLevel = nSkillLevel;
    curse.nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, SKILL_AMPLIFYDAMAGE, nSkillLevel);
    curse.nStat = pSkillsTxtRecord->wAuraStat[0];
    curse.nStatValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[0], SKILL_AMPLIFYDAMAGE, nSkillLevel);
    curse.nState = pSkillsTxtRecord->wAuraTargetState;
    curse.pStateRemoveCallback = 0;

    D2StatListStrc* pStatList = SKILLS_ApplyStateEffect(&curse);
    if (!pStatList)
    {
        return;
    }

    for (int i = 1; i < 6; ++i)
    {
        if (pSkillsTxtRecord->wAuraStat[i] >= 0 && pSkillsTxtRecord->wAuraStat[i] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            const int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], SKILL_AMPLIFYDAMAGE, nSkillLevel);
            if (nValue)
            {
                STATLIST_SetStatIfListIsValid(pStatList, pSkillsTxtRecord->wAuraStat[i], nValue, 0);
            }
        }
    }
}

// 0x005A2530
void __fastcall MONSTERUNIQUE_CastAmplifyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!bUnique)
    {
        return;
    }

    if (((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) & 3) < 1)
    {
        return;
    }

    int nSkillLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) / 5 + 1;
    if (nSkillLevel < 1)
    {
        nSkillLevel = 1;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(SKILL_AMPLIFYDAMAGE);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, SKILL_AMPLIFYDAMAGE, nSkillLevel);
    SKILLS_ApplyCurseAroundTarget(pGame, 3, pUnit, nSkillLevel, D2_MIN(D2_MAX(nRange, 1), 40), MONSTERUNIQUE_CurseCallback_ApplyAmplifyDamage);
}

// 0x005A25F0
void __fastcall MONSTERUNIQUE_FireEnchantedModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int nUMod, int bUnique)
{
    if (bUnique && (!pBoss || pBoss->dwAnimMode == MONMODE_DEATH))
    {
        EVENT_SetEvent(pGame, pBoss, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 4, 0, 0);
    }
}

static inline int ApplyRatio_Inline(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
    {
        return 0;
    }

    if (nValue > 0x100000)
    {
        if (nDivisor > (nValue >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nMultiplier * (nValue / nDivisor);
    }

    if (nMultiplier > 0x10000)
    {
        if (nDivisor <= (nMultiplier >> 4))
        {
            return nValue * (nMultiplier / nDivisor);
        }
        return (int)(nValue * (__int64)nMultiplier / nDivisor);
    }

    return nMultiplier * nValue / nDivisor;
}

// 0x005A2620
void __fastcall MONSTERUNIQUE_CastCorpseExplode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nX = CLIENTS_GetUnitXInline(pUnit);
    const int nY = CLIENTS_GetUnitYInline(pUnit);
    D2UnitStrc* pMissile = SKILLS_CreateMissileAtOffset(pGame, MISSILE_MONSTERCORPSEEXPLODE, pUnit, 0, 1, 0, 0, nX, nY, 1);
    if (!pMissile) return;
    int nGameType;
    if (pGame->nGameType || pGame->dwGameType) nGameType = 1;
    else nGameType = 0;
    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    const int nMonsterId = pUnit->dwClassId;
    DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, nGameType, pGame->nDifficulty, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 1, &monStatsInit);
    D2DifficultyLevelsTxt* pDifficulty = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    if (!pDifficulty) return;
    int nDamage = DATATBLS_ApplyRatio(monStatsInit.nMaxHP, pDifficulty->nMonsterCEDamagePercent, 100);
    if (pGame->nDifficulty == 0) nDamage += nDamage / -4;
    else if (pGame->nDifficulty == 1) nDamage += nDamage / -3;
    else if (pGame->nDifficulty == 2) nDamage /= 8;
    const int nMinDamage = ApplyRatio_Inline(nDamage, 60, 100);
    const int nRoll = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nDamage - nMinDamage) + nMinDamage;
    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.dwPhysDamage = nRoll << 6;
    damage.dwFireDamage = nRoll << 6;
    SUNITDMG_SetMissileDamageFlagsForNearbyUnits(pGame, pMissile, nX, nY, pGame->nDifficulty + 4, &damage, 0, 0, 0, 0x581);
}

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                    // 0x006442A0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                            // 0x00621F20

// 0x005A2910
void __fastcall MONSTERUNIQUE_CastNova(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!bUnique)
    {
        return;
    }

    int nSkillLevel = 1;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (pOwner)
    {
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pOwner, SKILL_SHADOWWARRIOR);
        if (pSkill)
        {
            nSkillLevel = SKILLS_GetSkillLevel(pOwner, pSkill, 1) / 2 + 1;
        }
    }

    nSkillLevel = D2_MIN(D2_MAX(nSkillLevel, 1), 15);
    if (UNITS_GetCurrentLifePercentage(pUnit) > 10)
    {
        nSkillLevel = 1;
    }

    SKILLS_CreateMissileRing(pGame, pUnit, pUnit, MISSILE_NOVA, 0, nSkillLevel, DATATBLS_GetMissileVelocityFromMissilesTxt(MISSILE_NOVA, 0));
}

// 0x005A3E70
void __fastcall MONSTERUNIQUE_SuicideModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int nUMod, int bUnique)
{
    if (pBoss)
    {
        const int nMode = pBoss->dwAnimMode;
        if (nMode == MONMODE_GETHIT)
        {
            D2ModeChangeStrc modeChange;
            MONSTERMODE_GetModeChangeInfo(pBoss, MONMODE_DEATH, &modeChange);
            D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
            EVENT_SetEvent(pGame, pBoss, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 4, 0, 0);
            return;
        }

        if (nMode != MONMODE_DEATH && nMode != MONMODE_DEAD)
        {
            return;
        }
    }

    EVENT_SetEvent(pGame, pBoss, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 4, 0, 0);
}

// 0x005A2C20
void __fastcall MONSTERUNIQUE_CastCorpsePoisonCloud(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    if (nLevel <= 1)
    {
        nLevel = 1;
    }

    SKILLS_CreateMissileAtOffset(pGame, MISSILE_CORPSEPOISONCLOUD, pUnit, 0, nLevel, 0, 0, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 1);
}

static D2MissilesTxt* SKILLS_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    }

    return 0;
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static D2MonsterDataStrc* MONSTERUNIQUE_GetMonsterDataInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }

    return 0;
}

void __fastcall MONSTERUNIQUE_MinionCallback_KillMinion(D2UnitStrc* pUnit, void* pGameArg, void* pUnused); // 0x005A2CC0

// 0x005A2D10
void __fastcall MONSTERUNIQUE_KillMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (pUnit && pUnit->dwAnimMode != MONMODE_DEATH)
    {
        return;
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        return;
    }

    AIGENERAL_ExecuteCallbackOnMinions(pUnit, pGame, 0, MONSTERUNIQUE_MinionCallback_KillMinion);
    AIGENERAL_SetOwnerData(pGame, pOwner, -1, UNIT_MONSTER, 0, 0);
    if (pOwner == pUnit || pOwner->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pOwner, MONMODE_DEATH, &modeChange);
    D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}


// 0x005A09E0
static D2UnitStrc* __stdcall MONSTERUNIQUE_SpawnUniqueMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int nX, int nY, int nUnitGUID, int nClassId, int bAvoidWarps)
{
    if (!nX && !nY)
    {
        if (!MONSTERREGION_FindSpawnLocation(pGame, pRoom, pRoomCoordList, nClassId, &nX, &nY, bAvoidWarps))
        {
            return 0;
        }
    }

    D2UnitStrc* pMonster = 0;
    if (pRoomCoordList)
    {
        pMonster = MONSTERSPAWN_SpawnInCoordList(pGame, pRoom, pRoomCoordList, nX, nY, nClassId, 1, -1, 64);
    }
    else if (nUnitGUID == -1)
    {
        pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nClassId, 1, nUnitGUID, 64);
        if (!pMonster)
        {
            pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nClassId, 1, 5, 64);
        }
    }
    else
    {
        pMonster = MONSTERSPAWN_SpawnWithUnitId(pGame, pRoom, nX, nY, nClassId, 1, nUnitGUID, -1, 98);
        if (!pMonster)
        {
            pMonster = MONSTERSPAWN_SpawnWithUnitId(pGame, pRoom, nX, nY, nClassId, 1, nUnitGUID, 5, 98);
            if (!pMonster)
            {
                if (MONSTERREGION_FindSpawnLocation(pGame, pRoom, 0, nClassId, &nX, &nY, 0))
                {
                    pMonster = MONSTERSPAWN_SpawnWithUnitId(pGame, pRoom, nX, nY, nClassId, 1, nUnitGUID, -1, 98);
                }

                if (!pMonster)
                {
                    D2CoordStrc tCoord;
                    tCoord.nX = nX;
                    tCoord.nY = nY;
                    D2ActiveRoomStrc* pTargetRoom;
                    D2Common_10136(pRoom, &tCoord, 1, 0x3C01, &pTargetRoom);
                    if (!pTargetRoom)
                    {
                        return 0;
                    }

                    pMonster = MONSTERSPAWN_SpawnWithUnitId(pGame, pTargetRoom, tCoord.nX, tCoord.nY, nClassId, 1, nUnitGUID, -1, 98);
                }
            }
        }
    }

    if (!pMonster)
    {
        return 0;
    }

    MONSTERUNIQUE_MarkUnique(pGame, pMonster);
    SetMonTypeFlag(pMonster, 1, 1);
    QUESTS_SetJadeFigurineBoss(pGame, pMonster);
    AIGENERAL_SetOwnerData(pGame, pMonster, !pMonster ? -1 : pMonster->dwUnitId, 1, 1, 0);
    return pMonster;
}

// 0x005A0BB0
static int MONSTERUNIQUE_GetMinionId(D2UnitStrc* pUnit)
{
    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    D2MonStatsTxt* pMonStatsTxtRecord = MonStatsTxtRecord(nClassId);
    if (pMonStatsTxtRecord && pMonStatsTxtRecord->wMinion[0] >= 0 && pMonStatsTxtRecord->wMinion[0] < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return pMonStatsTxtRecord->wMinion[0];
    }

    return nClassId;
}

// 0x005A2BD0
void __fastcall MONSTERUNIQUE_CastColdUniqueMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!bUnique)
    {
        return;
    }

    int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) / 2;
    if (nLevel <= 1)
    {
        nLevel = 1;
    }

    SKILLS_CreateMissileRing(pGame, pUnit, pUnit, MISSILE_COLDUNIQUE, 0, nLevel, DATATBLS_GetMissileVelocityFromMissilesTxt(MISSILE_FROSTNOVA, 0));
}

inline int D2Clamp(int v, int low, int high)
{
    return (v < low) ? low : (high < v) ? high : v;
}

// 0x005A2D80
void __fastcall MONSTERUNIQUE_AddSecondaryDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    int nMinDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
    int nMaxDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0);
    if (nMaxDamage > 0 && (!pUnit || pUnit->dwClassId != MONSTER_ROGUEHIRE))
    {
        nMinDamage += STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MINDAMAGE, 0) - 1;
        nMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MAXDAMAGE, 0) - 1;
        if (nMinDamage < 0)
        {
            nMinDamage = 0;
        }
        if (nMaxDamage < 0)
        {
            nMaxDamage = 0;
        }

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 1);
        STATLIST_SetStat(pStatList, STAT_MINDAMAGE, nMinDamage, 0);
        STATLIST_SetStat(pStatList, STAT_MAXDAMAGE, nMaxDamage, 0);
    }
}

// 0x005A2E00
void __fastcall MONSTERUNIQUE_AddRogueHireMissileSecondaryDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MISSILE)
    {
        return;
    }

    int nMinDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
    int nMaxDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0);
    if (nMaxDamage <= 0)
    {
        return;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (!pOwner || pOwner->dwClassId != MONSTER_ROGUEHIRE)
    {
        return;
    }

    nMinDamage += (STATLIST_UnitGetStatValue(pOwner, STAT_SECONDARY_MINDAMAGE, 0) << 8) - 256;
    nMaxDamage += (STATLIST_UnitGetStatValue(pOwner, STAT_SECONDARY_MAXDAMAGE, 0) << 8) - 256;

    if (nMinDamage < 0)
    {
        nMinDamage = 0;
    }

    if (nMaxDamage < 0)
    {
        nMaxDamage = 0;
    }

    STATLIST_SetUnitStat(pUnit, STAT_MINDAMAGE, nMinDamage, 0);
    STATLIST_SetUnitStat(pUnit, STAT_MAXDAMAGE, nMaxDamage, 0);
}

// 0x005A2EB0
void __fastcall MONSTERUNIQUE_ScarabModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int nUMod, int bUnique)
{
    if (!pBoss || pBoss->dwAnimMode == MONMODE_GETHIT || pBoss->dwAnimMode == MONMODE_DEATH)
    {
        EVENT_SetEvent(pGame, pBoss, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 2, 0, 0);
    }
}

// 0x005A2EE0
void __fastcall MONSTERUNIQUE_CastBugLightningMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    D2MissileStrc missileParams = {};

    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitXInline(pUnit);
    missileParams.nY = CLIENTS_GetUnitYInline(pUnit);
    missileParams.nSkillLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    missileParams.nMissile = MISSILE_BUGLIGHTNING;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;

    for (int i = 0; i < 4; ++i)
    {
        const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
        const int nUnitY = CLIENTS_GetUnitYInline(pUnit);
        const int nX = gnBugLightningXOffsets[i] + nUnitX;
        const int nY = gnBugLightningYOffsets[i] + nUnitY;

        for (int j = 0; j < 2; ++j)
        {
            missileParams.nInitArg = j;
            missileParams.nTargetX = nX;
            missileParams.nTargetY = nY;
            MISSILES_CreateMissileFromParams(pGame, &missileParams);
        }
    }
}

// 0x005A30B0
void __fastcall MONSTERUNIQUE_ApplyMissileElementalDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (bUnique && pUnit && pUnit->dwUnitType == UNIT_MISSILE)
    {
        MONSTERUNIQUE_ApplyElementalDamage(pGame, pUnit, nUMod, bUnique);
    }
}

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecordFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[pUnit->dwClassId];
    }
    return 0;
}

// 0x005A3EF0
void __fastcall MONSTERUNIQUE_CastSuicideExplodeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecordFromUnit(pUnit);
    const int nDifficulty = pGame->nDifficulty;
    const int nColdLength = pMonStatsTxtRecord->wAiParam[0][nDifficulty];

    int nGameType;
    if (pGame->nGameType || pGame->dwGameType)
    {
        nGameType = 1;
    }
    else
    {
        nGameType = 0;
    }

    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    DATATBLS_CalculateMonsterStatsByLevel(!pUnit ? -1 : pUnit->dwClassId, nGameType, nDifficulty, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 8, &monStatsInit);

    const int nDamage = (RollLimitedInline(&pUnit->pSeed, monStatsInit.nA1MaxD - monStatsInit.nA1MinD) + monStatsInit.nA1MinD) << 8;

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags |= 8;
    damage.dwPhysDamage = nDamage;

    D2UnitStrc* pMissile;
    if (nColdLength == 1)
    {
        damage.dwFireDamage = nDamage;
        pMissile = SKILLS_CreateMissileAtOffset(pGame, MISSILE_SUICIDEFIREEXPLODE, pUnit, 0, 1, 0, 0, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 1);
    }
    else if (nColdLength >= 2)
    {
        damage.dwColdDamage = nDamage;
        damage.dwColdLen = nColdLength;
        pMissile = SKILLS_CreateMissileAtOffset(pGame, MISSILE_SUICIDEICEEXPLODE, pUnit, 0, 1, 0, 0, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 1);
    }
    else
    {
        pMissile = SKILLS_CreateMissileAtOffset(pGame, MISSILE_SUICIDECORPSEEXPLODE, pUnit, 0, 1, 0, 0, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 1);
    }

    const int nX = CLIENTS_GetUnitXInline(pUnit);
    const int nY = CLIENTS_GetUnitYInline(pUnit);
    if (pMissile)
    {
        SUNITDMG_SetMissileDamageFlagsForNearbyUnits(pGame, pMissile, nX, nY, pMonStatsTxtRecord->wAiParam[3][pGame->nDifficulty], &damage, 0, 0, 0, 0x581);
    }
}

D2UnitStrc* __fastcall MONSTERSPAWN_SpawnLevelVariantAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B2490

void __fastcall MONSTERUNIQUE_CreatePainWorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique);

// 0x005A4200
void __fastcall MONSTERUNIQUE_CreatePainWorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!pUnit || pUnit->dwAnimMode == MONMODE_DEATH)
    {
        MONSTERSPAWN_SpawnLevelVariantAtUnit(pGame, pUnit, MONSTER_PAINWORM1, MONMODE_NEUTRAL, 1, 0);
        STATES_ToggleState(pUnit, STATE_CORPSE_NODRAW, 1);
    }
}

void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00573780

void __fastcall MONSTERUNIQUE_UpdateAiAndScheduleUModEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A4230

// 0x005A4230
void __fastcall MONSTERUNIQUE_UpdateAiAndScheduleUModEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (SUNIT_IsDead(pUnit))
    {
        return;
    }

    MONSTER_UpdateAiCallbackEvent(pGame, pUnit);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 75, 0, 0);
}

typedef void(__fastcall* MONUMODFUNC)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique);

extern MONUMODFUNC gpfnSrvUModCallbacks[][6]; // 0x0073C0B8

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag); // 0x005A0180

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
    {
        return 0;
    }
    return (unsigned short)(pMonsterData->nTypeFlag & nFlag) != 0;
}

// 0x005A4270
static void __stdcall MONSTERUNIQUE_ExecuteUModCallbacks(D2GameStrc* pGame, D2UnitStrc* pMissile, int nCallbackIndex, D2UnitStrc* pUnit)
{
    const int bUnique = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 0x08);

    unsigned char* pUMods = MONSTERUNIQUE_GetUMods(pUnit);
    if (!pUMods || *pUMods == 0)
    {
        return;
    }

    if (nCallbackIndex != 5)
    {
        for (int i = 0; i < 9; ++i)
        {
            MONUMODFUNC pUModFunc = gpfnSrvUModCallbacks[pUMods[i]][nCallbackIndex];
            if (pUModFunc)
            {
                pUModFunc(pGame, pUnit, pUMods[i], bUnique);
            }
        }
    }
    else
    {
        for (int i = 0; i < 9; ++i)
        {
            MONUMODFUNC pUModFunc = gpfnSrvUModCallbacks[pUMods[i]][nCallbackIndex];
            if (pUModFunc)
            {
                pUModFunc(pGame, pMissile, pUMods[i], bUnique);
            }
        }
    }
}







// 0x005A4350
void __fastcall MONSTERUNIQUE_ExecuteUModModeStartCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    MONSTERUNIQUE_ExecuteUModCallbacks(pGame, 0, 0, pUnit);
}







// 0x005A4360
void __fastcall MONSTERUNIQUE_ExecuteUModModeChangeCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    MONSTERUNIQUE_ExecuteUModCallbacks(pGame, 0, 1, pUnit);
}







// 0x005A4370
void __fastcall MONSTERUNIQUE_EventExecuteUModCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    MONSTERUNIQUE_ExecuteUModCallbacks(pGame, 0, 2, pUnit);
}







// 0x005A4390
void __fastcall MONSTERUNIQUE_ExecuteUModSuccessfulHitCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    MONSTERUNIQUE_ExecuteUModCallbacks(pGame, 0, 3, pUnit);
}







// 0x005A43A0
void __fastcall MONSTERUNIQUE_ExecuteUModDamagedCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    MONSTERUNIQUE_ExecuteUModCallbacks(pGame, 0, 4, pUnit);
}







// 0x005A43B0
void __fastcall MONSTERUNIQUE_OwnerMissileHook(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMissile)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pMissile)
    {
        MONSTERUNIQUE_ExecuteUModCallbacks(pGame, pMissile, 5, pUnit);
    }
}

// 0x005A3AA0
void __fastcall MONSTERUNIQUE_KillUnitOrRemovePet(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (SUNIT_IsDead(pUnit))
    {
        return;
    }

    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 3, 0, 0);
        return;
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
    {
        PLAYERPETS_RemovePet(pGame, pOwner, !pUnit ? -1 : pUnit->dwUnitId, 1);
        return;
    }

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_DEATH, &modeChange);
    D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}

// 0x005A30E0
void __fastcall MONSTERUNIQUE_StealBeltItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!bUnique)
    {
        return;
    }

    if ((int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < 30)
    {
        return;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget || pTarget->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2InventoryStrc* pInventory = pTarget->pInventory;
    for (int i = 0; i < 16; ++i)
    {
        D2UnitStrc* pBeltItem = INVENTORY_GetItemFromBeltSlot(pInventory, i);
        if (pBeltItem)
        {
            if (pBeltItem->dwUnitType == UNIT_ITEM && pBeltItem->dwAnimMode == IMODE_INBELT && !INVENTORY_GetCursorItem(pInventory))
            {
                D2UnitStrc* pDupeItem = ITEMS_Duplicate(pGame, pBeltItem, pTarget, 1);
                D2CoordStrc pCoord;
                UNITS_GetCoords(pTarget, &pCoord);

                D2CoordStrc pReturnCoords;
                D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pTarget), &pCoord, &pReturnCoords, 1, 1);
                D2_ASSERT(pRoom, 2762);

                ITEMS_SetItemFlag(pDupeItem, IFLAG_INSTORE, 1);
                D2GAME_DropItem_6FC52260(pGame, pTarget, pDupeItem, pRoom, pReturnCoords.nX, pReturnCoords.nY);
                const int nX = CLIENTS_GetUnitX(pBeltItem);
                ITEMMODE_RemoveBeltItem(pGame, pTarget, pBeltItem);
                ITEMMODE_CompactBeltColumn(pGame, pTarget, nX);
            }
            return;
        }
    }
}

// 0x005A3250
void __fastcall MONSTERUNIQUE_QuestCompleteModeChange(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused1, int nUnused2)
{
    switch (!pUnit ? -1 : (unsigned int)pUnit->dwClassId)
    {
    case 156:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_Andariel(pGame, pUnit);
        break;
    case 229:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_SpawnRadamentDeathMissile(pGame, pUnit);
        break;
    case 242:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_SpawnMephistoDeathControlMissile(pGame, pUnit);
        break;
    case 256:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_Izual(pGame, pUnit);
        break;
    case 267:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_Bloodraven(pGame, pUnit);
        break;
    case 540:
    case 541:
    case 542:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_OnQuestCompleteModeChange(pGame, pUnit);
        break;
    case 479:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_ShenkTheOverseer(pGame, pUnit);
        break;
    case 704:
    case 705:
    case 709:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_UberPrimeEvil(pGame, pUnit);
        break;
    }
}

static inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

static int sub_005A3610_IsWideMissile(int nMissileId)
{
    if (nMissileId < 0x3F)
    {
        return 0;
    }
    if (nMissileId > 0x42)
    {
        return 0;
    }
    return 1;
}

// 0x005A3490
void __fastcall MONSTERUNIQUE_CastQueenPoisonCloudMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitXInline(pUnit);
    missileParams.nY = CLIENTS_GetUnitYInline(pUnit);
    missileParams.nSkillLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    missileParams.nMissile = MISSILE_QUEENPOISONCLOUD;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;

    const int nXOffsets[] = { 0, 1, 0, -1 };
    const int nYOffsets[] = { -1, 0, 1, 0 };

    for (int j = 0; j < 4; ++j)
    {
        const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
        const int nUnitY = CLIENTS_GetUnitYInline(pUnit);
        const int nTargetX = nXOffsets[j] + nUnitX;
        const int nTargetY = nYOffsets[j] + nUnitY;

        for (int i = 0; i < 2; ++i)
        {
            missileParams.nInitArg = i;
            missileParams.nTargetX = nTargetX;
            missileParams.nTargetY = nTargetY;
            MISSILES_CreateMissileFromParams(pGame, &missileParams);
        }
    }
}

// 0x005A3610
void __fastcall MONSTERUNIQUE_CreateMultishotMissiles(D2GameStrc* pGame, D2UnitStrc* pMissile, int nUnused, int nArg)
{
    if (!nArg || !pMissile || pMissile->dwUnitType != UNIT_MISSILE)
    {
        return;
    }

    const int nMissileId = pMissile->dwClassId;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(nMissileId);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->nMissileFlags[12 >> 3] & gdwBitMasks[12 & 7])
    {
        return;
    }

    if (sub_005A0180_CheckMonsterFlag(pOwner, 0x80))
    {
        return;
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pOwner);
    int nY;
    if (!pTarget)
    {
        nArg = D2COMMON_10175_PathGetFirstPointX(pPath);
        nY = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    else
    {
        nArg = CLIENTS_GetUnitX(pTarget);
        nY = CLIENTS_GetUnitY(pTarget);
    }

    D2SeedStrc tSeed;
    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, 0x53454953);
    tSeed.nHighSeed = pOwner->dwUnitId;

    int nDeltaX = CLIENTS_GetUnitX(pOwner) - nArg;
    int nDeltaY = CLIENTS_GetUnitY(pOwner) - nY;
    if (nDeltaX < 0)
    {
        nDeltaX = -1;
    }
    else if (nDeltaX > 0)
    {
        nDeltaX = 1;
    }

    if (nDeltaY < 0)
    {
        nDeltaY = -1;
    }
    else if (nDeltaY > 0)
    {
        nDeltaY = 1;
    }

    if (sub_005A3610_IsWideMissile(nMissileId))
    {
        nDeltaY = 0;
        nDeltaX = 0;
    }

    if (pOwner->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pOwner->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nTypeFlag |= 0x80;
        }
    }

    SKILLS_CreateMissileAtOffset(pGame, nMissileId, pOwner, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), 0, 0, nArg - nDeltaY, nY + nDeltaX, 0);
    SKILLS_CreateMissileAtOffset(pGame, nMissileId, pOwner, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), 0, 0, nArg + nDeltaY, nY - nDeltaX, 0);

    if (pOwner->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pOwner->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nTypeFlag &= ~0x80;
        }
    }
}

// 0x005A37D0
void __fastcall MONSTERUNIQUE_LightningEnchantedModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int nUMod, int bUnique)
{
    if (bUnique && pBoss && pBoss->dwAnimMode == MONMODE_GETHIT)
    {
        EVENT_SetEvent(pGame, pBoss, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 2, 0, 0);
    }
}

// 0x005A3800
void __fastcall MONSTERUNIQUE_ColdEnchantedModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int nUMod, int bUnique)
{
    if ((bUnique || nUMod != 18) && (!pBoss || pBoss->dwAnimMode == MONMODE_DEATH))
    {
        EVENT_SetEvent(pGame, pBoss, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 4, 0, 0);
    }
}

// 0x005A2840
void __fastcall MONSTERUNIQUE_CastCorpseExplode2(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nX = CLIENTS_GetUnitXInline(pUnit);
    const int nY = CLIENTS_GetUnitYInline(pUnit);

    D2UnitStrc* pMissile = SKILLS_CreateMissileAtOffset(pGame, MISSILE_MONSTERCORPSEEXPLODE, pUnit, 0, 1, 0, 0, nX, nY, 1);
    if (!pMissile)
    {
        return;
    }

    D2DamageStrc damage = {};
    damage.dwPhysDamage = 0x6400;
    damage.dwFireDamage = 0x6400;
    SUNITDMG_SetMissileDamageFlagsForNearbyUnits(pGame, pMissile, nX, nY, 6, &damage, 0, 0, 0, 0x583);
}

// 0x005A29A0
void __fastcall MONSTERUNIQUE_CastLightUniqueMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    static const int nYOffsets[] = { -1, 0, 1, 0 };                                                       // 0x006E2178
    static const int nXOffsets[] = { 0, 1, 0, -1 };                                                       // 0x006E2188

    if (!bUnique)
    {
        return;
    }

    D2MonsterDataStrc* pMonsterData = MONSTERUNIQUE_GetMonsterDataInline(pUnit);
    const int nLastFrame = !pMonsterData ? 0 : pMonsterData->dwDurielFlag;

    int nFrameDiff = pGame->dwGameFrame - nLastFrame;
    if (nFrameDiff < 0)
    {
        nFrameDiff = -nFrameDiff;
    }

    if (nFrameDiff < 10)
    {
        pMonsterData = MONSTERUNIQUE_GetMonsterDataInline(pUnit);
        if (pMonsterData)
        {
            pMonsterData->nTypeFlag &= ~MONTYPEFLAG_LIGHTNINGUNIQUE;
        }
        return;
    }

    pMonsterData = MONSTERUNIQUE_GetMonsterDataInline(pUnit);
    if (pMonsterData)
    {
        pMonsterData->dwDurielFlag = pGame->dwGameFrame;
    }

    pMonsterData = MONSTERUNIQUE_GetMonsterDataInline(pUnit);
    if (pMonsterData)
    {
        pMonsterData->nTypeFlag |= MONTYPEFLAG_LIGHTNINGUNIQUE;
    }

    int nSkillLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) / 2;
    if (nSkillLevel < 1)
    {
        nSkillLevel = 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = UNITS_GetXPositionInline(pUnit);
    missileParams.nY = UNITS_GetYPositionInline(pUnit);
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = MISSILE_LIGHTUNIQUE;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;

    const int nBaseX = UNITS_GetXPositionInline(pUnit);
    const int nBaseY = UNITS_GetYPositionInline(pUnit);
    for (int i = 0; i < 4; ++i)
    {
        const int nX = nBaseX + nXOffsets[i];
        const int nY = nBaseY + nYOffsets[i];
        for (int j = 0; j < 2; ++j)
        {
            missileParams.nInitArg = j;
            missileParams.nTargetX = nX;
            missileParams.nTargetY = nY;
            MISSILES_CreateMissileFromParams(pGame, &missileParams);
        }
    }
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

// 0x005A2BA0
void __fastcall MONSTERUNIQUE_CastLightUniqueMissileIfNotGetHit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (bUnique && (!pUnit || pUnit->dwAnimMode != MONMODE_GETHIT))
    {
        MONSTERUNIQUE_CastLightUniqueMissile(pGame, pUnit, nUMod, bUnique);
    }
}

static inline int MONSTERUNIQUE_GetClassIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

// 0x005A3B50
void __fastcall MONSTERUNIQUE_SetTrapDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    int nLevel = 2;
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
    if (nLevelId)
    {
        nLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pGame->nDifficulty, pGame->bExpansion);
        nLevel = MAX(nLevel, 1);
    }

    const int nToHit = MIN(nLevel + 50, 90);
    STATLIST_SetUnitStat(pUnit, STAT_LEVEL, nLevel, 0);
    STATLIST_SetUnitStat(pUnit, STAT_TOHIT, nToHit, 0);

    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    D2_ASSERT(nUnitType == UNIT_MONSTER, 3138);

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 1);
    switch (MONSTERUNIQUE_GetClassIdInline(pUnit))
    {
    case MONSTER_TRAP_FIREBOLT:
    {
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MINDAMAGE, 0, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MAXDAMAGE, 0, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_FIREMINDAM, nLevel >> 1, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_FIREMAXDAM, 3 * nLevel >> 1, 0);
        break;
    }
    case MONSTER_TRAP_HORZMISSILE:
    case MONSTER_TRAP_VERTMISSILE:
    {
        const int nMinDamage = MIN(nLevel, (nLevel >> 1) + 1);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MINDAMAGE, nMinDamage, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MAXDAMAGE, nLevel, 0);
        break;
    }
    case MONSTER_TRAP_POISONCLOUD:
    {
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MINDAMAGE, 0, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MAXDAMAGE, 0, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_POISONMINDAM, nLevel, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_POISONMAXDAM, 2 * nLevel, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_POISONLENGTH, 2 * nLevel, 0);
        break;
    }
    case MONSTER_TRAP_LIGHTNING:
    case MONSTER_TRAP_NOVA:
    {
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MINDAMAGE, 0, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MAXDAMAGE, 0, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_LIGHTMINDAM, nLevel >> 1, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_LIGHTMAXDAM, 3 * nLevel >> 1, 0);
        break;
    }
    }
}

// 0x005A3840
void __fastcall MONSTERUNIQUE_ScheduleSelfResurrection(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (pUnit && pUnit->dwAnimMode != MONMODE_DEATH)
    {
        return;
    }

    if (STATLIST_GetUnitAlignment(pUnit) != UNIT_ALIGNMENT_EVIL)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecordFromUnit(pUnit);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_MONUMOD, 0);

    if ((int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < pMonStatsTxtRecord->wAiParam[7][pGame->nDifficulty])
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 10 * pMonStatsTxtRecord->wAiParam[0][pGame->nDifficulty] + 1, 0, 0);
    }
}

// 0x005A3910
void __fastcall MONSTERUNIQUE_TrySelfResurrection(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecordFromUnit(pUnit);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);

    if (!SUNIT_IsDead(pUnit) || STATES_CheckStateMaskUdeadOnUnit(pUnit))
    {
        return;
    }

    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData && pUnit->pMonsterData->nTypeFlag & MONTYPEFLAG_RESURRECTED)
    {
        return;
    }

    if (STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_GOOD)
    {
        return;
    }

    if (COLLISION_CheckMaskWithPattern(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 1, COLLIDE_MASK_MONSTER_PATH))
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 10 * pMonStatsTxtRecord->wAiParam[0][pGame->nDifficulty] + 1, 0, 0);
    }
    else if (AIGENERAL_GetAiControlParam(pUnit, 1) < 2 && D2COMMON_11017_CheckUnitIfConsumeable(pUnit, 0))
    {
        if (STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_EVIL)
        {
            AITACTICS_UseSkill(pGame, pUnit, MONMODE_SKILL1, SKILL_SELF_RESURRECT, 0, 0, 0);
            if (pUnit)
            {
                pUnit->dwFlags &= 0xFBFDFFFF;
            }
            const int nParam = AIGENERAL_GetAiControlParam(pUnit, 1);
            AIGENERAL_SetAiControlParam(pUnit, 1, nParam + 1);
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
            EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, pGame->dwGameFrame + 51, 0, 0);
        }
    }
}

// 0x005A0930
static void __stdcall MONSTERUNIQUE_TransferUMods(D2UnitStrc* pOwner, D2UnitStrc* pMinion, int bFromStart)
{
    unsigned char* pOwnerUMods = UModsOfData(pOwner);
    unsigned char* pMinionUMods = UModsOfData(pMinion);
    if (!pOwnerUMods || !pMinionUMods)
    {
        return;
    }

    int nIndex = 0;
    if (!bFromStart)
    {
        nIndex = CountUModsTo(pMinionUMods);
    }
    pMinionUMods += nIndex;
    while (nIndex < 9)
    {
        const unsigned char nOwnerUMod = *pOwnerUMods;
        if (!nOwnerUMod)
        {
            break;
        }

        D2MonUModTxt* pMonUModTxtRecord = MonUModTxtRecord(nOwnerUMod);
        if (!pMonUModTxtRecord)
        {
            break;
        }

        if (pMonUModTxtRecord->nXfer)
        {
            *pMinionUMods = nOwnerUMod;
            ++pMinionUMods;
        }

        ++nIndex;
        ++pOwnerUMods;
    }
}

// 0x005A0C00
static void __stdcall MONSTERUNIQUE_SpawnMinionGroup(D2GameStrc* pGame, D2RoomCoordListStrc* pRoomCoordList, D2UnitStrc* pUnit, int nMinGroup, int nMaxGroup)
{
    if (TestMonTypeFlag(pUnit, 4))
    {
        return;
    }

    const int nMinionId = MONSTERUNIQUE_GetMinionId(pUnit);
    if (nMinionId < 0 || nMinionId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return;
    }

    const int nMinionCount = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMaxGroup - nMinGroup + 1) + nMinGroup;
    for (int i = 0; i < nMinionCount; ++i)
    {
        D2UnitStrc* pMinion;
        if (pRoomCoordList)
        {
            pMinion = MONSTERSPAWN_SpawnAtUnitInCoordList(pGame, pRoomCoordList, pUnit, nMinionId, 1, 3, 64);
        }
        else
        {
            pMinion = MONSTERSPAWN_SpawnAtUnit(pGame, pUnit, nMinionId, 1, 3, 64);
        }

        if (pMinion)
        {
            MONSTERUNIQUE_TransferUMods(pUnit, pMinion, 0);
            AIGENERAL_SetOwnerData(pGame, pMinion, GAME_GetUnitGUID(pUnit), 1, 0, 0);
            AIGENERAL_AllocMinionList(pGame, pUnit, pMinion);
            AIUTIL_SetOwnerGUIDAndType(pMinion, pUnit);
            SetMonTypeFlag(pMinion, 0x10, 1);
        }
    }
}

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010

// 0x005A0CE0
void __fastcall MONSTERUNIQUE_UMod1_RandomName(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (pUnit && bUnique)
    {
        const unsigned int nRand = SEED_RollRandomNumber(&pUnit->pSeed);
        if (pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
        {
            pUnit->pMonsterData->wNameSeed = nRand;
        }
    }
}

// 0x005A0D20
static void MONSTERUNIQUE_AddLifePercent(D2UnitStrc* pUnit, int nPercentage)
{
    int nHitpoints = STATLIST_GetMaxLifeFromUnit(pUnit);
    int nBonus;
    if (nHitpoints > 0x100000)
    {
        if (100 > (nHitpoints >> 4))
        {
            nBonus = (int)(nHitpoints * (__int64)nPercentage / 100);
        }
        else
        {
            nBonus = nPercentage * (nHitpoints / 100);
        }
    }
    else if (nPercentage > 0x10000)
    {
        if (100 > (nPercentage >> 4))
        {
            nBonus = (int)(nHitpoints * (__int64)nPercentage / 100);
        }
        else
        {
            nBonus = nHitpoints * (nPercentage / 100);
        }
    }
    else
    {
        nBonus = nPercentage * nHitpoints / 100;
    }

    nHitpoints += nBonus;
    STATLIST_SetUnitStat(pUnit, STAT_MAXHP, nHitpoints, 0);
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nHitpoints, 0);
}

// 0x005A0DC0
void __fastcall MONSTERUNIQUE_UMod2_HealthBonus(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    const unsigned char nDifficulty = pGame->nDifficulty;
    if (nDifficulty >= 3)
    {
        return;
    }

    if (!bUnique)
    {
        MONSTERUNIQUE_AddLifePercent(pUnit, MONSTERUNIQUE_GetMonUModConstant(nDifficulty + 1));
    }
    else
    {
        int nIndex;
        if (sub_005A0180((Unit005A0180*)pUnit, 4))
        {
            nIndex = nDifficulty + 4;
        }
        else
        {
            nIndex = nDifficulty + 7;
        }
        MONSTERUNIQUE_AddLifePercent(pUnit, MONSTERUNIQUE_GetMonUModConstant(nIndex));
        STATLIST_SetUnitStat(pUnit, STAT_HPREGEN, 0, 0);
    }
}

// 0x005A0E40
void __fastcall MONSTERUNIQUE_IncreaseMonsterLevelAndExperience(D2UnitStrc* pUnit, void* unused, void* context)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        const int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
        STATLIST_SetUnitStat(pUnit, STAT_LEVEL, nLevel + 3, 0);
        const int nExperience = STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
        STATLIST_SetUnitStat(pUnit, STAT_EXPERIENCE, 5 * nExperience, 0);
    }
}

int __fastcall CUNIT_ValidateMonsterId(int nMonsterId); // 0x00463900

static inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static __forceinline int MONSTERUNIQUE_GetUModConstantInline(int nUMod)
{
    if (nUMod >= sgptDataTables->nMonUModTxtRecordCount)
    {
        return 0;
    }
    D2MonUModTxt* pMonUModTxtRecord = &sgptDataTables->pMonUModTxt[nUMod];
    if (!pMonUModTxtRecord)
    {
        return 0;
    }
    return pMonUModTxtRecord->dwConstants;
}

// 0x005A0E80
void __fastcall MONSTERUNIQUE_ApplyMonsterPenalty(D2UnitStrc* pUnit, int nMode, int bApply)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != 1)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(pUnit->dwClassId);
    if (!pMonStatsTxtRecord || !bApply)
    {
        return;
    }

    const int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    STATLIST_SetUnitStat(pUnit, STAT_LEVEL, nLevel + -1, 0);
    const unsigned int nExperience = STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
    STATLIST_SetUnitStat(pUnit, STAT_EXPERIENCE, nExperience - 2 * (nExperience / 5), 0);

    int nDamage = MONSTERUNIQUE_GetUModConstantInline(11);
    int nToHit = MONSTERUNIQUE_GetUModConstantInline(10);

    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    if (pDifficultyLevelsTxtRecord)
    {
        nDamage = nDamage * pDifficultyLevelsTxtRecord->dwChampionDmgBonus / 100;
        nToHit = nToHit * pDifficultyLevelsTxtRecord->dwChampionDmgBonus / 100;
        if (CUNIT_ValidateMonsterId(sub_00463860_GetMonsterId(pUnit)) == 118)
        {
            nDamage /= 2;
        }
    }

    STATLIST_AddUnitStat(pUnit, STAT_DAMAGEPERCENT, nDamage, 0);
    STATLIST_AddUnitStat(pUnit, STAT_ITEM_TOHIT_PERCENT, nToHit, 0);

    if (pMonStatsTxtRecord->nVelocity <= 0 || nMode == 36)
    {
        return;
    }

    switch (nMode)
    {
    case 36:
        STATLIST_AddUnitStat(pUnit, STAT_VELOCITYPERCENT, -33, 0);
        break;

    case 37:
    {
        int nVelocity = 0x800 / pMonStatsTxtRecord->nVelocity;
        nVelocity -= 0x80;
        nVelocity = D2_MIN(D2_MAX(nVelocity, 10), 100);
        STATLIST_AddUnitStat(pUnit, STAT_VELOCITYPERCENT, nVelocity, 0);
        break;
    }

    default:
        STATLIST_AddUnitStat(pUnit, STAT_VELOCITYPERCENT, 20, 0);
        break;
    }
}

extern "C" D2MonLvlTxt* __fastcall MISSILES_GetMonLvlTxtRecord(int nLevel); // 0x005A0000

inline D2MonsterDataStrc* MONSTER_GetMonsterData_Inline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }

    return 0;
}

// 0x005A1080
void __fastcall MONSTERUNIQUE_UMod36_Ghostly(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame || !bUnique)
    {
        return;
    }

    D2MonsterDataStrc* pMonsterData = MONSTER_GetMonsterData_Inline(pUnit);
    if (pMonsterData)
    {
        pMonsterData->nTypeFlag |= 0x40;
    }

    STATLIST_SetUnitStat(pUnit, STAT_DAMAGERESIST, 80, 0);
    MONSTERUNIQUE_ApplyMonsterPenalty(pUnit, nUMod, bUnique);

    bUnique = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    const int nGameType = pGame->nGameType || pGame->dwGameType;
    const int nStatLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    D2MonLvlTxt* pMonLvlTxtRecord = MISSILES_GetMonLvlTxtRecord(D2_MIN(D2_MAX(nStatLevel, 1), sgptDataTables->nMonLvlTxtRecordCount - 1));
    if (!pMonLvlTxtRecord)
    {
        return;
    }

    const int nDamage = pMonLvlTxtRecord->nValues[MONLVL_DM + nGameType][bUnique];
    const int nMaxDamage = MONSTERUNIQUE_GetMonUModConstant(bUnique + 25) * nDamage / 100;
    STATLIST_AddUnitStat(pUnit, STAT_COLDMINDAM, MONSTERUNIQUE_GetMonUModConstant(bUnique + 22) * nDamage / 100, 0);
    STATLIST_AddUnitStat(pUnit, STAT_COLDMAXDAM, nMaxDamage, 0);
    STATLIST_AddUnitStat(pUnit, STAT_COLDLENGTH, 150, 0);
}

// 0x005A2120
static void __stdcall MONSTERUNIQUE_SpawnMinions(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, D2UnitStrc* pUnit, int bSpawnMinions, int nMinGroup, int nMaxGroup)
{
    if (bSpawnMinions)
    {
        MONSTERUNIQUE_SpawnMinionGroup(pGame, pRoomCoordList, pUnit, nMinGroup, nMaxGroup);
    }

    for (int i = 0; i < 4; ++i)
    {
// build: symbol ?gnBaseUMods@* 0x006E2168
        const int nUMod = gnBaseUMods[i];
        InitUMod(pUnit, nUMod, 1);
        AIGENERAL_ExecuteCallbackOnMinions(pUnit, (void*)nUMod, 0, (MinionCallbackFunc)MONSTERUNIQUE_InitializeUMod);
    }

    unsigned char* pUMods = UModsOf(pUnit);
    if (pUMods)
    {
        for (int i = 0; i < 9; ++i)
        {
            const int nUMod = pUMods[i];
            if (!nUMod)
            {
                break;
            }

            InitUMod(pUnit, nUMod, 1);
            AIGENERAL_ExecuteCallbackOnMinions(pUnit, (void*)nUMod, 0, (MinionCallbackFunc)MONSTERUNIQUE_InitializeUMod);
        }
    }
}

// 0x005A43E0
D2UnitStrc* __fastcall MONSTERUNIQUE_SpawnUniqueGroup(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int nClassId, int bAllowChampion, unsigned short nX, unsigned short nY, int bAvoidWarps)
{
    D2UnitStrc* pMonster = MONSTERUNIQUE_SpawnUniqueMonster(pGame, pRoom, pRoomCoordList, nX, nY, -1, nClassId, bAvoidWarps);
    if (!pMonster)
    {
        return 0;
    }

    MONSTERUNIQUE_AssignRandomUMods(pGame, pMonster, bAllowChampion);
    MONSTERUNIQUE_SpawnMinions(pGame, pRoom, pRoomCoordList, pMonster, 1, 3, 6);
    return pMonster;
}

// 0x005A3A80
void __fastcall MONSTERUNIQUE_ApplyShatterState(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!pUnit || pUnit->dwAnimMode == MONMODE_DEATH)
    {
        STATES_ToggleState(pUnit, STATE_SHATTER, 1);
    }
}

// 0x005A2CC0
void __fastcall MONSTERUNIQUE_MinionCallback_KillMinion(D2UnitStrc* pUnit, void* pGameArg, void* pUnused)
{
    D2GameStrc* pGame = (D2GameStrc*)pGameArg;
    AIGENERAL_FreeMinionList(pUnit);
    AIGENERAL_SetOwnerData(pGame, pUnit, -1, 1, 0, 0);

    if (pUnit && pUnit->dwAnimMode != MONMODE_DEATH)
    {
        D2ModeChangeStrc modeChange;
        MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_DEATH, &modeChange);
        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
    }
}

static inline void SetBossIndex(D2UnitStrc* pUnit, short nIndex)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->wBossHcIdx = nIndex;
        }
    }
}

// 0x005A4440
D2UnitStrc* __fastcall MONSTERUNIQUE_RestoreUniqueMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nClassId, int nUnitGUID, unsigned short nNameSeed, int bChampion, int bSuperUnique, short nBossHcIdx, unsigned char* pUMods)
{
    D2UnitStrc* pMonster = MONSTERUNIQUE_SpawnUniqueMonster(pGame, pRoom, 0, nX, nY, nUnitGUID, nClassId, 1);
    if (!pMonster)
    {
        return pMonster;
    }

    const int nUnitType = pMonster ? pMonster->dwUnitType : UNIT_INVALID;
    if (nUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pMonster->pMonsterData;
        unsigned char* pMonUMods = pMonsterData ? pMonsterData->nMonUmod : 0;
        if (pMonUMods)
        {
            SetMonTypeFlag(pMonster, 4, bChampion);

            int bAuraEnchanted = 0;
            for (int i = 0; i < 9; ++i)
            {
                pMonUMods[i] = pUMods[i];
                if (pUMods[i] == 30)
                {
                    bAuraEnchanted = 1;
                }
            }

            MONSTERUNIQUE_SpawnMinions(pGame, pRoom, 0, pMonster, 0, 0, 0);

            pMonsterData = MonsterDataOf(pMonster);
            if (pMonsterData)
            {
                pMonsterData->wNameSeed = nNameSeed;
            }

            if (bAuraEnchanted)
            {
                MONSTERUNIQUE_UMod30_AuraEnchanted(pMonster, 30, 1);
            }

            if (bSuperUnique)
            {
                SetMonTypeFlag(pMonster, 2, 1);
                SetBossIndex(pMonster, nBossHcIdx);

                switch (nBossHcIdx)
                {
                case 6:
                    STATES_ToggleState(pMonster, 0x76, 1);
                    QUESTS_CreateChainRecord(pGame, pMonster, 5);
                    break;
                case 60:
                    QUESTS_CreateChainRecord(pGame, pMonster, 34);
                    break;
                case 42:
                    STATES_ToggleState(pMonster, 0x76, 1);
                    QUESTS_CreateChainRecord(pGame, pMonster, 31);
                    break;
                case 43:
                case 44:
                case 45:
                    QUESTS_CreateChainRecord(pGame, pMonster, 35);
                    break;
                case 26:
                case 27:
                case 29:
                    QUESTS_CreateChainRecord(pGame, pMonster, 19);
                    break;
                case 39:
                    QUESTS_CreateChainRecord(pGame, pMonster, 4);
                    break;
                case 36:
                case 37:
                case 38:
                    QUESTS_CreateChainRecord(pGame, pMonster, 23);
                    break;
                }
            }
        }
    }

    return pMonster;
}

#define MONTYPEFLAG_MINION 0x10
#define MONSTERDATA_UMODS_OFFSET 0x1C

// 0x005A46E0
D2UnitStrc* __fastcall MONSTERUNIQUE_RestoreMinion(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nClassId, int nUnitGUID, unsigned char* pUMods)
{
    D2UnitStrc* pMonster = MONSTERSPAWN_SpawnWithUnitId(pGame, pRoom, nX, nY, nClassId, 1, nUnitGUID, -1, 98);
    if (!pMonster)
    {
        pMonster = MONSTERSPAWN_SpawnWithUnitId(pGame, pRoom, nX, nY, nClassId, 1, nUnitGUID, 4, 98);
        if (!pMonster && MONSTERREGION_FindSpawnLocation(pGame, pRoom, 0, nClassId, &nX, &nY, 1))
        {
            pMonster = MONSTERSPAWN_SpawnWithUnitId(pGame, pRoom, nX, nY, nClassId, 1, nUnitGUID, -1, 98);
        }
    }

    if (!pMonster)
    {
        return 0;
    }

    unsigned char* pMonUMods = 0;
    if (pMonster->dwUnitType == UNIT_MONSTER)
    {
        pMonUMods = (unsigned char*)pMonster->pMonsterData;
    }
    pMonUMods = !pMonUMods ? 0 : pMonUMods + MONSTERDATA_UMODS_OFFSET;
    for (int i = 0; i < 9; ++i)
    {
        pMonUMods[i] = pUMods[i];
    }

    SetMonTypeFlag(pMonster, MONTYPEFLAG_MINION, 1);

    int nBaseUMods[4] = { 1, 2, 3, 4 };
    for (int i = 0; i < 4; ++i)
    {
        InitUMod(pMonster, nBaseUMods[i], 0);
    }

    for (int i = 0; i < 9; ++i)
    {
        InitUMod(pMonster, pMonUMods[i], 0);
    }

    return pMonster;
}

// 0x005A4850
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != 1)
    {
        return;
    }

    unsigned char* pUMods = UModsOf(pUnit);
    if (!pUMods)
    {
        return;
    }

    if (bUnique)
    {
        MONSTERUNIQUE_MarkUnique(pGame, pUnit);
    }

    const int nIndex = CountUMods(pUMods);
    if (nIndex < 9)
    {
        pUMods[nIndex] = nUMod;
        InitUMod(pUnit, nUMod, bUnique);
    }
}

// 0x005A48C0
void __fastcall MONSTERUNIQUE_PromoteToChampion(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nUMod)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != 1)
    {
        return;
    }

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    unsigned char* pUMods = pMonsterData ? pMonsterData->nMonUmod : 0;
    if (!pUMods || TestMonTypeFlag(pUnit, 4))
    {
        return;
    }

    MONSTERUNIQUE_MarkUnique(pGame, pUnit);
    SetMonTypeFlag(pUnit, 4 | 1, 1);

    const int nIndex = MONSTERUNIQUE_GetUModCount(pUMods);
    if (nIndex < 9)
    {
        pUMods[nIndex] = nUMod;
        MONSTERUNIQUE_SpawnMinions(pGame, UNITS_GetRoom(pUnit), 0, pUnit, 1, 0, 0);
    }
}

static inline unsigned char* PromoteGetUMods(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        return pMonsterData ? pMonsterData->nMonUmod : 0;
    }
    return 0;
}

static inline void PromoteSetTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == 1 && pUnit->pMonsterData)
        pUnit->pMonsterData->nTypeFlag |= nFlag;
}

// 0x005A4940
void __fastcall MONSTERUNIQUE_PromoteToUnique(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != 1)
    {
        return;
    }

    unsigned char* pUMods = PromoteGetUMods(pUnit);
    if (!pUMods)
    {
        return;
    }

    PromoteSetTypeFlag(pUnit, 1);
    MONSTERUNIQUE_MarkUnique(pGame, pUnit);
    MONSTERUNIQUE_AssignRandomUMods(pGame, pUnit, 1);
    MONSTERUNIQUE_SpawnMinions(pGame, UNITS_GetRoom(pUnit), 0, pUnit, 0, 0, 0);
    pUnit->dwFlags |= 0x800;
    MONSTER_ToggleSummonerFlag(pUnit, 1, 1);
}

// 0x005A3040
void __fastcall MONSTERUNIQUE_ApplyElementalDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!bUnique)
        return;

    const unsigned int nRand = MONUNIQUE_RollSeed_Inline(&pUnit->pSeed) % 5;
// build: symbol ?gnUniqueElementalStats@* 0x006E21B8
    MONSTERUNIQUE_ApplyElementalDamageStats(pUnit, gnUniqueElementalStats[nRand][0], gnUniqueElementalStats[nRand][1], gnUniqueElementalStats[nRand][2], pGame);
}

#include "gen/data/Source/D2Game/MONSTER/MonsterUnique.inc"
