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
#include "D2GameAux.h"
#include "D2LanguageNames.h"

#define IFLAG_TARGETING 4

#define UPDATEUI_CLOSEALL 17

#define UPDATEUI_OPENCUBE 21

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

struct D2ItemsTxt;

struct D2MonStatsTxt;

struct D2BooksTxt;


struct D2CurseStrc;

struct D2SkillsTxt;

struct Unit005A0180;

union D2SeedStrc;

struct D2UnitStrc;

struct D2GameStrc;

struct D2DataTablesStrc;

struct D2DamageStrc;

struct D2AnimSeqTxt;

struct D2ItemStatCostTxt;

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

int __stdcall ITEMS_GetSpellIcon(D2UnitStrc* pItem); // 0x0062BB20

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x005678A0

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

void __fastcall D2GAME_ITEMS_Identify_6FC49670(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00562590



extern D2pSpellTblStrc gaPSpellTable[]; // 0x00741790

void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId); // 0x0053B3D0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80

D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex); // 0x006374B0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc*, int, D2StatListStrc*);

enum D2C_Z09ItemConstants
{
    EVENTTYPE_REMOVESTATE = 0x0C,
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __stdcall ITEMMODS_EvaluateItemFormula(D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int nCalc); // 0x00627C20

int __fastcall SKILLS_RemoveStatesInGroup(D2UnitStrc* pUnit, int nStateId, int a3); // 0x0056C740

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

int __stdcall D2COMMON_10473(D2StatListStrc* pStatList); // 0x00626090

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __fastcall SKILLS_RemoveStateAndRefreshPassives(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900

void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0

void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __fastcall SKILLITEM_pSpell09_StaminaPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId); // 0x005BEDA0

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060

D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554D00

void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190

void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo); // 0x0053CAB0

void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID); // 0x00554120

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

int __fastcall SKILLITEM_CastSkillOnTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2UnitStrc* pTargetUnit, int a5); // 0x005FDCA0

int __fastcall SKILLITEM_CastSkillOnPosition(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int a6); // 0x005FDD60

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

int __fastcall ITEMMODE_UseStoredItemAtCoordinates(D2GameStrc* ptGame, D2UnitStrc* hUnit, int itemId, int x, int y, int* status); // 0x0055E170

int __fastcall ITEMMODE_UseBeltItem(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nItemGUID, int nX, int nY, int* pItemStatus, int bUseOnMerc); // 0x00562390

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0

void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0

int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster); // 0x0063E940

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0

int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pHireling); // 0x0063EE90

D2StatListStrc* __fastcall SKILLS_ApplyStateEffect(D2CurseStrc* pCurse); // 0x0056E970

enum D2C_Y09SkillConstants
{
    SKILLSFLAGINDEX_AURA = 5,
    SKILLSFLAGINDEX_IMMEDIATE = 15,
    EVENTTYPE_PERIODICSTATS = 9,
};

extern unsigned int gdwBitMasks[]; // 0x006CE268

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

int __fastcall SKILL_ComputePeriodicRate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x0056CD50

int __fastcall sub_0056F7F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5, int a6, int a7); // 0x0056F7F0

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

int __fastcall SKILLITEM_CalculateOpenWoundsHpRegen(int nLevel, const int* pValues); // 0x005BFDA0

extern "C" int __fastcall sub_005A0180(Unit005A0180* pUnit, unsigned short wMask); // 0x005A0180

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

int __fastcall MONSTER_GetHpBonus(int nPlayerCount); // 0x005738F0

int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60

typedef void (__fastcall* RemoveCallback)(D2UnitStrc*,int,D2StatListStrc*);

int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc*); // 0x0044BE50

int __fastcall GAME_GetUnitGUID(D2UnitStrc*); // 0x00451F50

int __fastcall SKILLS_SharePotionLifeWithBloodGolem(D2GameStrc*,D2UnitStrc*,int); // 0x005C6870

unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc*); // 0x005805D0

void __fastcall SUNITMSG_QueueLifeUpdate(D2UnitStrc*,unsigned char); // 0x00571A10

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

void __fastcall SKILLS_ApplyDimVisionToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel); // 0x005C39C0

void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150

#define UNIT_PLAYER 0

#define UNIT_MONSTER 1

#define UNIT_ITEM 4

#define UNIT_INVALID 6

#define MONSTATS2FLAGINDEX_SMALL 10

#define MONSTATS2FLAGINDEX_LARGE 11

struct D2MonStats2Txt;

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0

static void SKILLITEM_ClearTargetingItems(D2UnitStrc* pUnit);

int __fastcall SKILLITEM_pSpell_Handler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY);

enum D2C_J10SkillItemConstants
{
    MONTYPEFLAG_UNIQUE_CHAMPION = 12,
    DAMAGERESULTFLAG_GETHIT = 4,
    DAMAGEHITFLAG_0x20 = 0x20,
    SKILLSFLAGINDEX_ITEMTGTDO = 29,
};

int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc* pSeed, int nMax);                                     // 0x00472210

int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                   // 0x0045C3E0

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0

void __fastcall AIUTIL_ApplyTerrorCurseState(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId, int nDuration, int nParam); // 0x005DDD00

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* room); // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int level); // 0x006427F0

int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char act); // 0x0061AB70

void __fastcall PLAYER_RemoveTownPortal(D2GameStrc* game,D2UnitStrc* unit); // 0x00535430

int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* game,D2UnitStrc* unit,D2ActiveRoomStrc* room,int x,int y,int level,D2UnitStrc** out,int object,int permanent); // 0x0056D130

void __fastcall sub_00553380_SendEvent(D2UnitStrc* unit,int event,D2UnitStrc* other); // 0x00553380

void __fastcall PLAYER_SetUniqueIdInPlayerData(D2UnitStrc* unit,int id); // 0x005353B0

void __fastcall OBJECTS_SetUnitIdInTimerArg(D2UnitStrc* unit,int id); // 0x00552AF0

D2UnitStrc* __fastcall SUNIT_GetPortalOwner(D2GameStrc* game,D2UnitStrc* unit); // 0x00553720

void __fastcall ACT5Q5_OnPortalOpened(D2GameStrc* game,D2UnitStrc* unit); // 0x0058CF00

D2ClientStrc* __fastcall sub_005531C0_GetClient(D2UnitStrc* unit,const char* file,int line,int type,int id); // 0x005531C0

void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc* client,unsigned char code); // 0x0053B3D0

int __stdcall ITEMS_GetBonusLifeBasedOnClass(D2UnitStrc*, int); // 0x0062A5D0

int __stdcall ITEMS_GetBonusManaBasedOnClass(D2UnitStrc*, int); // 0x0062A620

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



D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY);            // 0x00463740

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0

void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00

int __fastcall SKILLS_CreateMissileSpread(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSubMissiles, int nMissileId, int nSkillId, int nSkillLevel, int a7); // 0x005C7040

int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId);                       // 0x005D3CF0

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

D2AnimSeqTxt* __stdcall DATATBLS_GetMonSeqTxtRecordFromUnit(D2UnitStrc* pUnit);                             // 0x006633B0

int __stdcall DATATBLS_GetSeqFramePointsCount(D2UnitStrc* pUnit);                                          // 0x006633D0

void __stdcall DATATBLS_GetSequenceEvent(D2AnimSeqTxt* pMonSeqTxt, int nSeqFramePoint, int* pEvent);        // 0x006634C0

struct D2ModeChangeStrc;

D2AiControlStrc* __fastcall AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit); // 0x00541860

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nType, int nGUID); // 0x00552F60

void __fastcall SUNIT_SetAlignment(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0

void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00573780

void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int nFlag1, int nFlag2); // 0x0058F030

void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A4850

int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pMode, int a3); // 0x005A7C20

void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pMode); // 0x005A7E60

void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNode); // 0x005B1900

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

void __fastcall AIUTIL_SetOwnerGUIDAndType(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x005DD330

void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00620210

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pPath, unsigned char nStep); // 0x00649070

int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180

void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nPattern, int nMask); // 0x0064EC10

enum D2C_SkillItemConstants
{
    UNITEVENT_13 = 13,
};

int __fastcall SKILLITEM_TimerCallback_ReanimateMonster(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage, int nGUID1, int nGUID2); // 0x005C07A0

D2UnitEventStrc* __fastcall SUNITEVENT_Register(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEvent, int nGUID1, int nGUID2, D2UnitEventCallbackFunction pCallback, unsigned int nQueueNo, int a8); // 0x005C0AD0

struct D2AiCmdStrc;

struct D2StaticPathStrc;

unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc*, int, int, int, unsigned short); // 0x0064D9B0

struct D2MagicAffixTxt;


struct D2RareAffixIndexAndPtrStrc;

struct D2SetItemsTxt;


static inline int GetItemType(D2UnitStrc* pItem)
{
    int nType = 6;
    if (pItem)
    {
        nType = pItem->dwUnitType;
    }
    return nType;
}

// 0x005BF670
int __fastcall SKILLITEM_EventFunc06_AttackerTakesDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    int bCanBeAttacked = 0;
    if (pAttacker && pUnit)
    {
        bCanBeAttacked = (pUnit->dwFlags >> 2) & 1;
    }
    if (!bCanBeAttacked)
    {
        return 0;
    }

    const int nDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nDamage <= 0)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags |= 0x4021;
    damage.dwPhysDamage = nDamage << 8;
    damage.dwHitClass = 0x8D;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, &damage);
    return 1;
}

static inline D2ItemStatCostTxt* GetItemStatCost(int nStat)
{
    if (nStat >= 0 && nStat < sgptDataTables->nItemStatCostTxtRecordCount)
        return &sgptDataTables->pItemStatCostTxt[nStat];
    return 0;
}

// 0x005BF720
int __fastcall SKILLITEM_EventFunc10_AttackerTakesLightDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    int bCanBeAttacked = 0;
    if (pAttacker && pUnit)
    {
        bCanBeAttacked = (pUnit->dwFlags >> 2) & 1;
    }
    if (!bCanBeAttacked)
    {
        return 0;
    }

    const int nDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nDamage <= 0)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags |= 0x4021;
    damage.dwLtngDamage = nDamage << 8;
    damage.dwHitClass = 0x4D;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, &damage);
    return 1;
}

// 0x005BF7D0
int __fastcall SKILLITEM_EventFunc11_ApplyFireDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    int bCanBeAttacked = 0;
    if (pAttacker && pUnit)
    {
        bCanBeAttacked = (pUnit->dwFlags >> 2) & 1;
    }
    if (!bCanBeAttacked)
    {
        return 0;
    }

    const int nDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nDamage <= 0)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags |= 0x4021;
    damage.dwFireDamage = nDamage << 8;
    damage.dwHitClass = 0x2D;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, &damage);
    return 1;
}

static inline D2ItemStatCostTxt* SKILLS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId < 0)
    {
        return 0;
    }

    if (nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pItemStatCostTxt[nStatId];
}

// 0x005BFA10
int __fastcall SKILLITEM_EventFunc08_Howl(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_UNIQUE_CHAMPION))
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    if (sub_00472210_SeedRollMasked(&pAttacker->pSeed, 128) >= nChance)
    {
        return 0;
    }

    AIUTIL_ApplyTerrorCurseState(pGame, pAttacker, pUnit, SKILL_HOWL, 20, 20);
    return 1;
}

// 0x005BEDA0
int __fastcall SKILLITEM_pSpell09_StaminaPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const int nState = pItemsTxtRecord->wState;
    if (nState <= 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    const int nLength = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxtRecord->dwLen);
    if (nLength <= 0)
    {
        return 0;
    }

    SKILLS_RemoveStatesInGroup(pUnit, nState, 0);

    int nRemaining = 0;
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (pStatList)
    {
        nRemaining = D2COMMON_10473(pStatList) - pGame->dwGameFrame;
    }

    const int nEndFrame = pGame->dwGameFrame + nRemaining + nLength;

    if (!pStatList)
    {
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        const int nUnitType = !pUnit ? UNIT_INVALID : pUnit->dwUnitType;

        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, 0, nUnitType, nUnitGUID);
        if (!pStatList)
        {
            return 0;
        }

        STATLIST_SetState(pStatList, nState);
        STATES_ToggleState(pUnit, nState, 1);
        STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRefreshPassives);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    }

    if (nEndFrame)
    {
        D2COMMON_10476(pStatList, nEndFrame);
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nEndFrame, 0, 0);
    }

    for (int i = 0; i < 3; ++i)
    {
        const int nStatId = pItemsTxtRecord->wStat[i];
// build: symbol ?PLAYER_GetItemStatCostTxtRecord@* 0x0045C4F0
        if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount && PLAYER_GetItemStatCostTxtRecord(nStatId))
        {
            const int nValue = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxtRecord->dwCalc[i]);
            if (nValue)
            {
                STATLIST_SetStat(pStatList, nStatId, nValue, 0);
                if (nStatId == STAT_STAMINARECOVERYBONUS && nValue > 0)
                {
                    const int nMaxStamina = STATLIST_UnitGetStatValue(pUnit, STAT_MAXSTAMINA, 0);
                    if (STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0) < nMaxStamina)
                    {
                        STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina + 0x100, 0);
                    }
                }
            }
        }
    }

    return 1;
}

// 0x005BF240
int __fastcall SKILLITEM_pSpell_Handler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY)
{
    if (!pUnit)
    {
        return 0;
    }

    const int nUnitType = pUnit->dwUnitType;
    if (nUnitType != UNIT_PLAYER && nUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    const int nItemType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nItemType == UNIT_ITEM)
    {
        int nPSpell = -1;
        int nSkillId = -1;

        if (ITEMSIsA(pItem, ITEMTYPE_BOOK) || ITEMSIsA(pItem, ITEMTYPE_SCROLL))
        {
            D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
            if (pBooksTxtRecord)
            {
                nPSpell = pBooksTxtRecord->dwPSpell;
                nSkillId = pBooksTxtRecord->dwBookSkillId;
            }
        }

        if (nPSpell <= 0)
        {
            const int nClassId = pItem->dwClassId;
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
            if (pItemsTxtRecord)
            {
                nPSpell = pItemsTxtRecord->dwPspell;
            }

            if (nPSpell <= 0)
            {
                return 0;
            }
        }

// build: symbol ?gnPSpellTableCount@* 0x0074178C
        if (nPSpell >= gnPSpellTableCount)
        {
            return 0;
        }

        if (gaPSpellTable[nPSpell].pfSpellPrepare && !ITEMS_CheckItemFlag(pItem, IFLAG_TARGETING, 1130, ".\\SKILLS\\SkillItem.cpp"))
        {
            if (!gaPSpellTable[nPSpell].pfSpellPrepare(pGame, pUnit, pItem, 0, nX, nY, nSkillId))
            {
                SKILLITEM_ClearTargetingItems(pUnit);
                const unsigned int nItemGUID = pItem->dwUnitId;
                const int nItemType = pItem->dwUnitType;
                D2GAME_PACKETS_SendPacketSize06_6FC3C850(UnitGetClient(pUnit, ".\\SKILLS\\SkillItem.cpp", 1135), 0x7C, nItemType, nItemGUID);
            }

            return 0;
        }

        if (!gaPSpellTable[nPSpell].pfSpellDo)
        {
            return 0;
        }

        ITEMS_SetItemFlag(pItem, IFLAG_TARGETING, 1);

        const int nResult = gaPSpellTable[nPSpell].pfSpellDo(pGame, pUnit, pItem, pTarget, nX, nY, nSkillId);
        if (!nResult)
        {
            SKILLITEM_ClearTargetingItems(pUnit);
            const unsigned int nItemGUID = pItem->dwUnitId;
            const int nItemType = pItem->dwUnitType;
            D2GAME_PACKETS_SendPacketSize06_6FC3C850(UnitGetClient(pUnit, ".\\SKILLS\\SkillItem.cpp", 1151), 0x7C, nItemType, nItemGUID);
        }

        return nResult;
    }

    return 0;
}

// 0x005BF3D0
int __fastcall SKILLS_SrvDo113_Scroll_Book(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!pUnit->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pInvItem;
    D2UnitStrc* pItem;
    for (pInvItem = INVENTORY_GetFirstItem(pUnit->pInventory); pInvItem; pInvItem = INVENTORY_GetNextItem(pInvItem))
    {
        pItem = INVENTORY_UnitIsItem(pInvItem);
        if (ITEMSIsA(pItem, ITEMTYPE_BOOK))
        {
            D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
            if (pBooksTxtRecord && pBooksTxtRecord->dwBookSkillId == nSkillId && STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) > 0)
            {
                break;
            }
        }
        else if (ITEMSIsA(pItem, ITEMTYPE_SCROLL))
        {
            D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
            if (pBooksTxtRecord && pBooksTxtRecord->dwScrollSkillId == nSkillId)
            {
                break;
            }
        }
    }

    if (pInvItem)
    {
        switch (INVENTORY_GetItemNodePage(pInvItem))
        {
        case 1:
        {
            int nUnused;
            ITEMMODE_UseStoredItemAtCoordinates(pGame, pUnit, !pItem ? -1 : pItem->dwUnitId, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), &nUnused);
            return 1;
        }
        case 2:
        {
            int nUnused;
            ITEMMODE_UseBeltItem(pGame, pUnit, !pItem ? -1 : pItem->dwUnitId, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), &nUnused, 0);
            return 1;
        }
        }
    }

    return 0;
}

// 0x005BF880
int __fastcall SKILLITEM_EventFunc12_ApplyColdDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    int bCanBeAttacked = 0;
    if (pAttacker && pUnit)
    {
        bCanBeAttacked = (pUnit->dwFlags >> 2) & 1;
    }
    if (!bCanBeAttacked)
    {
        return 0;
    }

    const int nDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nDamage <= 0)
    {
        return 0;
    }

    const int nDefenderLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    const int nAttackerLevel = STATLIST_UnitGetStatValue(pAttacker, STAT_LEVEL, 0);
    int nLength = 25;
    if (nAttackerLevel > nDefenderLevel)
    {
        const int nLevelDiff = nAttackerLevel - nDefenderLevel;
        nLength += 10 * nLevelDiff;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags |= 0x4021;
    damage.dwColdLen = nLength;
    damage.dwColdDamage = nDamage << 8;
    damage.dwHitClass = 0x3D;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, &damage);
    return 1;
}

// 0x005BFAA0
int __fastcall SKILLITEM_EventFunc09_Stupidity(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker)
    {
        goto ReturnZero;
    }

    if (!pUnit)
    {
        goto ReturnZero;
    }

    if ((!pUnit ? 6 : pUnit->dwUnitType) != UNIT_MONSTER)
    {
ReturnZero:
        return 0;
    }

    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (!nValue)
    {
        return 0;
    }

    const int nAttackerLevel = STATLIST_UnitGetStatValue(pAttacker, STAT_LEVEL, 0);
    int nChance = 5 * (nAttackerLevel + 4 * nValue - STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) + 6);
    if (nEvent == 6 && nChance > 0)
    {
        nChance /= 3;
    }

    nChance = D2_MIN(D2_MAX(nChance, 1), 99);

    const int nRoll = SEED_RollLimitedRandomNumber(&pAttacker->pSeed, 100);
    if (nRoll >= nChance)
    {
        return 0;
    }

    int nLevel = (nChance - nRoll) / 5 + 1;
    nLevel = D2_MIN(D2_MAX(nLevel, 1), 20);

    SKILLS_ApplyDimVisionToTarget(pGame, pAttacker, pUnit, nLevel);
    return 1;
}

// 0x005BFDA0
int __fastcall SKILLITEM_CalculateOpenWoundsHpRegen(int nLevel, const int* pValues)
{
    if (nLevel <= 1 || !pValues)
    {
        return 0;
    }

    if (nLevel > 60)
    {
        return (pValues[4] * (nLevel - 60)) + 15 * (pValues[1] + pValues[2] + pValues[3]) + 14 * pValues[0];
    }

    if (nLevel > 45)
    {
        return (pValues[3] * (nLevel - 45)) + 15 * (pValues[1] + pValues[2]) + 14 * pValues[0];
    }

    if (nLevel > 30)
    {
        return 15 * pValues[1] + pValues[2] * (nLevel - 30) + 14 * pValues[0];
    }

    if (nLevel > 15)
    {
        return pValues[1] * (nLevel - 15) + 14 * pValues[0];
    }

    return pValues[0] * (nLevel - 1);
}

// 0x005C0130
int __fastcall SKILLITEM_EventFunc17_ManaAfterKill(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit || pAttacker->dwUnitType != UNIT_PLAYER)
        return 0;
    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (!nValue)
        return 0;
    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pAttacker);
    int nMana = STATLIST_UnitGetStatValue(pAttacker, STAT_MANA, 0);
    if (nMana >= nMaxMana)
        return 0;
    nMana += nValue << 8;
    nMana = nMana > 0 ? nMana : 0;
    STATLIST_SetUnitStat(pAttacker, STAT_MANA, nMana < nMaxMana ? nMana : nMaxMana, 0);
    UNITS_SetOverlay(pAttacker, 152, 0);
    return 1;
}

// 0x005C01D0
int __fastcall SKILLITEM_EventFunc28_HealAfterKill(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (!nValue)
    {
        return 0;
    }

    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pAttacker);
    int nHitpoints = STATLIST_UnitGetStatValue(pAttacker, STAT_HITPOINTS, 0);
    if (nHitpoints >= nMaxHp)
    {
        return 0;
    }

    nHitpoints += nValue << 8;
    nHitpoints = nHitpoints > 0 ? nHitpoints : 0;
    STATLIST_SetUnitStat(pAttacker, STAT_HITPOINTS, nHitpoints < nMaxHp ? nHitpoints : nMaxHp, 0);
    UNITS_SetOverlay(pAttacker, 151, 0);
    return 1;
}

// 0x005C0260
int __fastcall SKILLITEM_EventFunc18_HealAfterDemonKill(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit || !MONSTERS_IsDemon(pUnit))
    {
        return 0;
    }

    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (!nValue)
    {
        return 0;
    }

    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pAttacker);
    int nHitpoints = STATLIST_UnitGetStatValue(pAttacker, STAT_HITPOINTS, 0);
    if (nHitpoints >= nMaxHp)
    {
        return 0;
    }

    nHitpoints += nValue << 8;
    nHitpoints = nHitpoints > 0 ? nHitpoints : 0;
    STATLIST_SetUnitStat(pAttacker, STAT_HITPOINTS, nHitpoints < nMaxHp ? nHitpoints : nMaxHp, 0);
    UNITS_SetOverlay(pAttacker, 151, 0);
    return 1;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005BF510
void __fastcall SKILLITEM_ActivateAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int a5, int nSkillId, int nSkillLevel)
{
    if (!pUnit)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || !(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
        || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_PERIODICSTATS, a5);
    const int nExpireFrame = SKILL_ComputePeriodicRate(pGame, pUnit, pSkillsTxtRecord, nSkillId, nSkillLevel);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_PERIODICSTATS, nExpireFrame, a5, nSkillId);

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_IMMEDIATE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_IMMEDIATE & 7])
    {
        sub_0056F7F0(pGame, pUnit, nSkillId, nSkillLevel, 1, 1, 0);
    }
}

// 0x005BF5D0
void __fastcall SKILLITEM_DeactivateAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int a4, int nSkillId)
{
    if (!pUnit)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || !(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
        || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 0);

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
    if (pStatList)
    {
        D2Common_10474(pUnit, pStatList);
        STATLIST_FreeStatList(pStatList);
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_PERIODICSTATS, a4);
}

// 0x005C0310
int __fastcall SKILLITEM_EventFunc19_Slow(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    int nSlowValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (!nSlowValue)
    {
        return 0;
    }

    const int nUnitType = pUnit->dwUnitType;
    if (nUnitType == UNIT_PLAYER)
    {
        if (nSlowValue >= 50)
        {
            nSlowValue = 50;
        }
    }
    else if (nUnitType == UNIT_MONSTER)
    {
        if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 12))
        {
            if (nSlowValue >= 50)
            {
                nSlowValue = 50;
            }
        }
        else if (MONSTERS_IsBoss(0, pUnit))
        {
            if (nSlowValue >= 50)
            {
                nSlowValue = 50;
            }
        }
        else if (MONSTERS_GetHirelingTypeId(pUnit))
        {
            if (nSlowValue >= 50)
            {
                nSlowValue = 50;
            }
        }
        else if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 2))
        {
            if (nSlowValue >= 75)
            {
                nSlowValue = 75;
            }
        }
        else
        {
            if (nSlowValue >= 90)
            {
                nSlowValue = 90;
            }
        }
    }
    else
    {
        return 0;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pAttacker;
    curse.pTarget = pUnit;
    curse.nSkill = 0;
    curse.nSkillLevel = 1;
    curse.nDuration = 750;
    curse.nStat = STAT_VELOCITYPERCENT;
    curse.nStatValue = -nSlowValue;
    curse.nState = STATE_SLOWED;

    D2StatListStrc* pStatList = SKILLS_ApplyStateEffect(&curse);
    if (!pStatList)
    {
        return 0;
    }

    STATLIST_SetStatValue(pStatList, STAT_ATTACKRATE, -nSlowValue, 0);
    STATLIST_SetStatValue(pStatList, STAT_OTHER_ANIMRATE, -nSlowValue, 0);
    UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\SkillItem.cpp", 2186);
    return 1;
}

// 0x005C05A0
int __fastcall SKILLITEM_EventFunc21_SkillOnGetHit(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker)
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    const int nLayer = (unsigned short)nSkillId;
    const int nTriggeredSkillId = nLayer >> sgptDataTables->nStuff;
    const int nTriggeredSkillLevel = nLayer & sgptDataTables->nShiftedStuff;
    if (!pDamage)
    {
        return 0;
    }

    if (!(pDamage->wResultFlags & DAMAGERESULTFLAG_GETHIT))
    {
        return 0;
    }

    if (ITEMS_RollLimitedRandomNumber(&pAttacker->pSeed, 100) >= nChance)
    {
        return 0;
    }

    if (!sub_0045C4B0_GetSkillsTxtRecord(nTriggeredSkillId))
    {
        return 0;
    }

    if (!pUnit)
    {
        SKILLITEM_CastSkillOnPosition(pAttacker, nTriggeredSkillId, nTriggeredSkillLevel, D2COMMON_10175_PathGetFirstPointX(pAttacker->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pAttacker->pDynamicPath), 0);
    }
    else
    {
        SKILLITEM_CastSkillOnTarget(pAttacker, nTriggeredSkillId, nTriggeredSkillLevel, pUnit, 0);
    }

    return 1;
}

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }

    return pUnit->dwUnitType;
}

// build: symbol ?UNITS_GetWeaponClass@* 0x00623C60
static inline int UNITS_GetWeaponClass(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

// 0x005BF960
int __stdcall SKILLITEM_EventFunc07_Knockback(D2UnitStrc* pUnit, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned int nStatLayer, int nUnused)
{
    if (!pUnit || !pDefender || !pDamage)
    {
        return 0;
    }

    if (STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, nStatLayer >> 16, nStatLayer) <= 0)
    {
        return 0;
    }

    int nChance = 64;
    if (sub_0044BE50(pDefender) == UNIT_MONSTER)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(UNITS_GetWeaponClass(pDefender));
        if (pMonStats2TxtRecord)
        {
            if (pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_LARGE >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_LARGE & 7])
            {
                nChance = 32;
            }
            else if (pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_SMALL >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_SMALL & 7])
            {
                nChance = 128;
            }
        }
    }

    if ((int)(SEED_RollRandomNumber(&pUnit->pSeed) & 127) >= nChance)
    {
        return 0;
    }

    pDamage->wResultFlags |= 8;
    return 1;
}

// 0x005BFC60
int __fastcall SKILLITEM_EventFunc14_Freeze(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nValue <= 0)
    {
        return 0;
    }

    int nAttackerLevel = STATLIST_UnitGetStatValue(pAttacker, STAT_LEVEL, 0);
    const int nUnitLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);

    int nBonus = nValue - 1;
    if (nBonus < 0)
    {
        nBonus = 0;
    }

    if (nEvent == 6)
    {
        nAttackerLevel -= nEvent;
    }

    int nChance = 5 * (4 * nBonus - nUnitLevel + nAttackerLevel + 10);
    if (nEvent == 6)
    {
        nChance /= 3;
    }

    int nPercent = D2_MIN(D2_MAX(nChance, 0), 100);

    const unsigned __int64 lSeed = (unsigned __int64)pAttacker->pSeed.nHighSeed + (unsigned __int64)pAttacker->pSeed.nLowSeed * 0x6AC690C5;
    pAttacker->pSeed.nLowSeed = (unsigned int)lSeed;
    pAttacker->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    const int nRoll = (int)((unsigned int)lSeed % 100);
    if (nRoll >= nPercent)
    {
        return 0;
    }

    int nLength = 2 * (nPercent - nRoll) + 25;
    nLength = D2_MIN(D2_MAX(nLength, 25), 250);

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.dwFrzLen = nLength;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    return 1;
}

// 0x005C0770
int __fastcall SKILLITEM_EventFunc29_RestInPeace(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (pAttacker && pUnit)
    {
        STATES_ToggleState(pUnit, STATE_RESTINPEACE, 1);
        return 1;
    }

    return 0;
}

static inline int GetUnitTypeChecked(const D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }
    return nType;
}

// 0x005BFBB0
int __fastcall SKILLITEM_EventFunc13_DamageToMana(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || GetUnitTypeChecked(pAttacker) != 0)
    {
        return 0;
    }
    if (!pDamage)
    {
        return 0;
    }

    if (pDamage->dwDmgTotal <= 0)
    {
        return 0;
    }
    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nValue <= 0)
        return 0;
    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pAttacker);
    int nMana = STATLIST_UnitGetStatValue(pAttacker, STAT_MANA, 0);
    if (nMana >= nMaxMana)
        return 0;
    int nNewMana = DATATBLS_ApplyRatio(pDamage->dwDmgTotal, nValue, 100) + nMana;
    nNewMana = nNewMana > 0 ? nNewMana : 0;
    STATLIST_SetUnitStat(pAttacker, STAT_MANA, nNewMana < nMaxMana ? nNewMana : nMaxMana, 0);
    UNITS_SetOverlay(pAttacker, 152, 0);
    return 1;
}

// 0x005C09E0
int __fastcall SKILLITEM_EventFunc31_Reanimate(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit || sub_0044BE50(pUnit) != UNIT_MONSTER)
    {
        return 0;
    }

    if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_UNIQUE_CHAMPION))
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    if (ITEMS_RollLimitedRandomNumber(&pAttacker->pSeed, 100) >= nChance)
    {
        return 0;
    }

    while (pAttacker)
    {
        if (sub_0044BE50(pAttacker) == UNIT_PLAYER)
        {
            const int nOwnerId = pAttacker->dwUnitId;
            // volatile only makes these reloads come from the stack copies of the register parameters, as the original does
            D2UnitStrc* pEventUnit = static_cast<D2UnitStrc* const volatile&>(pUnit);
            D2GameStrc* pOwnerGame = static_cast<D2GameStrc* const volatile&>(pGame);
            SUNITEVENT_Register(pOwnerGame, pEventUnit, UNITEVENT_13, static_cast<unsigned short>(nSkillId), nOwnerId, SKILLITEM_TimerCallback_ReanimateMonster, 0, nOwnerId);
            return 1;
        }

        pAttacker = AIGENERAL_GetMinionOwner(pAttacker);
    }

    return 0;
}

static inline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005BFE60
int __fastcall SKILLITEM_EventFunc15_OpenWounds(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    if ((int)(ITEMS_RollRandomNumber(&pAttacker->pSeed) % 100) >= nChance)
    {
        return 0;
    }

    int nLevel = STATLIST_UnitGetStatValue(pAttacker, STAT_LEVEL, 0);
    if (nLevel <= 1)
    {
        nLevel = 1;
    }

    const int nValues[] = { 9, 18, 27, 36, 45 };
    int nHpRegen = SKILLITEM_CalculateOpenWoundsHpRegen(nLevel, nValues) + 40;
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        nHpRegen /= 4;
        if (nEvent == 6)
        {
            nHpRegen /= 2;
        }
    }
    else if (pUnit->dwUnitType == UNIT_MONSTER && sub_005A0180((Unit005A0180*)pUnit, 0x0C))
    {
        nHpRegen /= 2;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pAttacker;
    curse.pTarget = pUnit;
    curse.nSkill = 0;
    curse.nSkillLevel = 1;
    curse.nDuration = 200;
    curse.nStat = 74;
    curse.nStatValue = -nHpRegen;
    curse.nState = 62;
    SKILLS_ApplyStateEffect(&curse);
    return 1;
}

// 0x005BFFC0
int __fastcall SKILLITEM_EventFunc16_CrushingBlow(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    if ((int)(ITEMS_RollRandomNumber(&pAttacker->pSeed) % 100) >= nChance)
    {
        return 0;
    }

    int nDivisor = 4;
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        nDivisor = 10;
    }
    else if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        if (MONSTERS_GetHirelingTypeId(pUnit))
        {
            nDivisor = 10;
        }
        else
        {
            if (MONSTERS_IsBoss(0, pUnit) || sub_005A0180((Unit005A0180*)pUnit, 2))
            {
                nDivisor = 8;
            }

            int nPlayerCount = STATLIST_UnitGetStatValue(pUnit, STAT_MONSTER_PLAYERCOUNT, 0);
            if (nPlayerCount < 1)
            {
                nPlayerCount = 1;
            }

            const int nHpBonus = MONSTER_GetHpBonus(nPlayerCount);
            if (nHpBonus)
            {
                nDivisor += DATATBLS_ApplyRatio(nDivisor, nHpBonus, 100);
            }
        }
    }

    if (nEvent == 6)
    {
        nDivisor *= 2;
    }

    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    int nCrushingBlowHp = nHitpoints / nDivisor;

    int nDamageResist = STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGERESIST, 0);
    if (nDamageResist >= 100)
    {
        nDamageResist = 100;
    }

    if (nDamageResist > 0)
    {
        nCrushingBlowHp -= DATATBLS_ApplyRatio(nCrushingBlowHp, nDamageResist, 100);
    }

    int nNewHp = nHitpoints - nCrushingBlowHp;
    nNewHp = nNewHp > 0 ? nNewHp : 0;
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nNewHp, 0);

    if (nNewHp <= 0 && pDamage)
    {
        pDamage->wResultFlags |= 2;
    }

    if (nCrushingBlowHp > 0)
    {
        UNITS_SetOverlay(pUnit, 147, 0);
    }

    return 1;
}

// 0x005BE130
int __fastcall SKILLITEM_pSpell01_Initializer(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    ITEMS_SetItemFlag(pItem, 4, 1);

    const int nSpellIcon = ITEMS_GetSpellIcon(pItem);
    if (nSpellIcon >= 0)
    {
        D2GAME_PACKETS_SendPacket0x3F_6FC3EDC0(UnitGetClient(pUnit, ".\\SKILLS\\SkillItem.cpp", 64), pItem, nSpellIcon, 0, 1, nSkillId);
    }

    return 1;
}

// 0x005BE180
static int SKILLITEM_InventoryContainsItem(D2UnitStrc* pTarget, D2UnitStrc* pUnit)
{
    if (!pUnit->pInventory)
    {
        return 0;
    }

    for (D2UnitStrc* pInvItem = INVENTORY_GetFirstItem(pUnit->pInventory); pInvItem; pInvItem = INVENTORY_GetNextItem(pInvItem))
    {
        if (INVENTORY_UnitIsItem(pInvItem) == pTarget)
        {
            return 1;
        }
    }

    return 0;
}

static inline unsigned int SEED_RollRandomNumber32(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x005C0470
int __fastcall SKILLITEM_EventFunc20_SkillOnAttackHitKill(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker)
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    const int nLayer = (unsigned short)nSkillId;
    const int nTriggeredSkillId = nLayer >> sgptDataTables->nStuff;
    const int nTriggeredSkillLevel = nLayer & sgptDataTables->nShiftedStuff;
    if (pDamage && !(pDamage->dwHitFlags & DAMAGEHITFLAG_0x20))
    {
        return 0;
    }

    if ((int)(SEED_RollRandomNumber32(&pAttacker->pSeed) % 100) >= nChance)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nTriggeredSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_ITEMTGTDO >> 3] & gdwBitMasks[SKILLSFLAGINDEX_ITEMTGTDO & 7])
    {
        if (pUnit)
        {
            SKILLITEM_CastSkillOnTarget(pUnit, nTriggeredSkillId, nTriggeredSkillLevel, pUnit, 0);
            return 1;
        }
    }
    else
    {
        if (pUnit)
        {
            SKILLITEM_CastSkillOnTarget(pAttacker, nTriggeredSkillId, nTriggeredSkillLevel, pUnit, 1);
            return 1;
        }

        SKILLITEM_CastSkillOnPosition(pAttacker, nTriggeredSkillId, nTriggeredSkillLevel, D2COMMON_10175_PathGetFirstPointX(pAttacker->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pAttacker->pDynamicPath), 1);
    }

    return 1;
}

// 0x005BE1C0
static void SKILLITEM_ClearTargetingItems(D2UnitStrc* pUnit)
{
    if (!pUnit->pInventory)
    {
        return;
    }

    for (D2UnitStrc* i = INVENTORY_GetFirstItem(pUnit->pInventory); i; i = INVENTORY_GetNextItem(i))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(i);
        if (ITEMS_CheckItemFlag(pItem, IFLAG_TARGETING, 119, ".\\SKILLS\\SkillItem.cpp"))
        {
            ITEMS_SetItemFlag(pItem, IFLAG_TARGETING, 0);
            D2GAME_PACKETS_SendPacket0x3F_6FC3EDC0(UnitGetClient(pUnit, ".\\SKILLS\\SkillItem.cpp", 122), pItem, -1, 1, 0, -1);
        }
    }
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005C0670
int __fastcall SKILLITEM_EventFunc30_SkillOnDeathLevelup(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker)
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    const int nLayer = (unsigned short)nSkillId;
    const int nTriggeredSkillId = nLayer >> sgptDataTables->nStuff;
    const int nTriggeredSkillLevel = nLayer & sgptDataTables->nShiftedStuff;
    if ((int)(SEED_RollRandomNumber32(&pAttacker->pSeed) % 100) >= nChance)
    {
        return 0;
    }

    if (!SKILLS_GetSkillsTxtRecord(nTriggeredSkillId))
    {
        return 0;
    }

    if (!pUnit)
    {
        SKILLITEM_CastSkillOnPosition(pAttacker, nTriggeredSkillId, nTriggeredSkillLevel, D2COMMON_10175_PathGetFirstPointX(pAttacker->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pAttacker->pDynamicPath), 0);
    }
    else
    {
        SKILLITEM_CastSkillOnTarget(pAttacker, nTriggeredSkillId, nTriggeredSkillLevel, pUnit, 0);
    }

    return 1;
}

// 0x005BE230
int __fastcall SKILLITEM_pSpell01_IdentifyItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    if (D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
    {
        return 0;
    }

    if (ITEMS_CheckItemFlag(pTarget, 0x10, 147, ".\\SKILLS\\SkillItem.cpp"))
    {
        return 0;
    }

    if (!SKILLITEM_InventoryContainsItem(pTarget, pUnit))
    {
        return 0;
    }

    D2GAME_ITEMS_Identify_6FC49670(pGame, pUnit, pTarget);
    return 1;
}

inline int UNIT_GetUnitType(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : UNIT_INVALID;
}

static inline int sub_GetUnitTypeChecked(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitType;
    }
    return 6;
}

static inline int sub_GetUnitGUIDChecked(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitId;
    }
    return -1;
}

// 0x005C07A0
int __fastcall SKILLITEM_TimerCallback_ReanimateMonster(D2GameStrc* pGame, int nUnusedRegister, D2UnitStrc* pCorpse, int nUnused1, int nUnused2, int nMonsterId, int nOwnerGUID)
{
    D2UnitStrc* pOwner = 0;
    if (UNIT_GetUnitType(pCorpse) == 1)
    {
        pOwner = SUNIT_GetServerUnit(pGame, 0, nOwnerGUID);
    }

    if (!pOwner)
    {
        return 0;
    }

    if (!D2COMMON_11017_CheckUnitIfConsumeable(pCorpse, 0) || nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return 0;
    }

    const int nX = CLIENTS_GetUnitX(pCorpse);
    const int nY = CLIENTS_GetUnitY(pCorpse);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pCorpse);
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!pRoom)
        return 0;
    D2MonStats2Txt* pMonStats2 = UNITS_GetMonStats2TxtRecordFromMonsterId(nMonsterId);
    if (!pMonStats2)
        return 0;
    COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pCorpse), CLIENTS_GetUnitX(pCorpse), CLIENTS_GetUnitY(pCorpse), PATH_GetUnitCollisionPattern(pCorpse), 0x8000);
    D2UnitStrc* pPet = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, 1, -1, 74);
    if (!pPet)
        return 0;
    pPet->dwFlags |= 0x0402000E;
    AITHINK_ExecuteAiFn(pGame, pPet, AIGENERAL_GetAiControlFromUnit(pPet), 0);
    MONSTER_UpdateAiCallbackEvent(pGame, pPet);
    AIGENERAL_SetOwnerData(pGame, pPet, sub_GetUnitGUIDChecked(pOwner), sub_GetUnitTypeChecked(pOwner), 0, 0);
    AIUTIL_SetOwnerGUIDAndType(pPet, pOwner);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPet, 2, 0);
    EVENT_SetEvent(pGame, pPet, 2, pGame->dwGameFrame + 25, 0, 0);
    SUNIT_SetAlignment(pPet, 2, 0);
    pPet->dwFlags |= 0x80000000;
    STATES_ToggleState(pPet, 96, 1);
    D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pPet, 21, 0);
    EVENT_SetEvent(pGame, pPet, 7, pGame->dwGameFrame + 1500, 0, 0);
    D2GAME_UpdateSummonAI_6FC401F0(pGame, pPet, 0, pOwner->dwNodeIndex);
    D2Common_10214(pPet);
    if (pMonStats2->nResurrectMode == 14)
    {
        D2ModeChangeStrc modeChange;
        MONSTERMODE_GetModeChangeInfo(pPet, 14, &modeChange);
        UNITS_SetUsedSkill(pPet, SKILLS_GetSkillById(pPet, SKILL_SKELETONRAISE, -1));
        PATH_SetStepNum(pPet->pDynamicPath, 1);
        modeChange.pTargetUnit = 0;
        modeChange.nX = nX;
        modeChange.nY = nY;
        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 0);
    }
    STATES_ToggleState(pPet, 118, 1);
    STATES_ToggleState(pCorpse, 173, 1);
    return 1;
}

// 0x005BE290
int __fastcall SKILLITEM_pSpell02_CastPortal(D2GameStrc* game,D2UnitStrc* unit,D2UnitStrc* item,int unused1,int unused2,int unused3,int unused4)
{
 if(GetUnitType(unit)!=0) return 0;
 unit->dwFlags|=0x40;
 D2ActiveRoomStrc* room=UNITS_GetRoom(unit);
 unsigned char act=DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(room));
 int town=DUNGEON_GetTownLevelIdFromActNo(act);
 if(DUNGEON_IsRoomInTown(room) || DUNGEON_GetLevelIdFromRoom(room)==LEVEL_PANDEMONIUMFINALE) {
  sub_00553380_SendEvent(unit,24,unit);return 0;
 }
 PLAYER_RemoveTownPortal(game,unit);
 D2UnitStrc* portal=0;
 int result=D2GAME_CreatePortalObject_6FD13DF0(game,unit,room,CLIENTS_GetUnitX(unit),CLIENTS_GetUnitY(unit),town,&portal,59,0);
 sub_00553380_SendEvent(unit,7,0);
 if(result) {
  PLAYER_SetUniqueIdInPlayerData(unit,!portal?-1:portal->dwUnitId);
  if(portal) {
   OBJECTS_SetUnitIdInTimerArg(portal,unit->dwUnitId);
   D2UnitStrc* other=SUNIT_GetPortalOwner(game,portal);
   if(other) {
    OBJECTS_SetUnitIdInTimerArg(other,unit->dwUnitId);
    ACT5Q5_OnPortalOpened(game,other);
   }
   ACT5Q5_OnPortalOpened(game,portal);
  }
 }
 if(item) {
  const int nItemId = item->dwUnitId;
  const int nItemType = GetItemType(item);
  D2ClientStrc* client=sub_005531C0_GetClient(unit,".\\SKILLS\\SkillItem.cpp",218,nItemType,nItemId);
  D2GAME_PACKETS_SendPacketSize06_6FC3C850(client,124);
 }
 return result;
}

// 0x005BE3F0
int __fastcall SKILLITEM_pSpell03_Potion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int a4, int a5, int a6, int a7)
{
    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxt) return 0;
    const int nLength = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxt->dwLen);
    const int nState = pItemsTxt->wState;
    D2StatListStrc* pStatList = 0;
    int nOldLength = 0;
    if (nLength > 0)
    {
        if (nState <= 0 || nState >= sgptDataTables->nStatesTxtRecordCount) return 0;
        pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
        if (pStatList) nOldLength = D2COMMON_10473(pStatList) - pGame->dwGameFrame;
    }
    int nResult = 0;
    int bUpdateLife = 0;
    for (int i = 0; i < 3; ++i)
    {
        D2SeedStrc* pSeed = &pUnit->pSeed;
        const int nStat = pItemsTxt->wStat[i];
        if (nStat < 0 || nStat >= sgptDataTables->nItemStatCostTxtRecordCount) break;
        D2ItemStatCostTxt* pCost = GetItemStatCost(nStat);
        if (!pCost) continue;
        int nValue = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxt->dwCalc[i]);
        switch (nStat)
        {
        case 74: nValue <<= 8;
        case 6:
        {
            nValue = ITEMS_GetBonusLifeBasedOnClass(pUnit, nValue);
            const int nVitality = STATLIST_UnitGetStatValue(pUnit, STAT_VITALITY, 0);
            if (nVitality > 0)
            {
                const unsigned int nChance = (unsigned int)ITEMS_RollLimitedRandomNumber(pSeed, nVitality) >> 1;
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < (int)nChance) nValue += nValue;
            }
            break;
        }
        case 26: nValue <<= 8;
        case 8:
        {
            nValue = ITEMS_GetBonusManaBasedOnClass(pUnit, nValue);
            const int nEnergy = STATLIST_UnitGetStatValue(pUnit, STAT_ENERGY, 0);
            if (nEnergy > 0)
            {
                const unsigned int nChance = (unsigned int)ITEMS_RollLimitedRandomNumber(pSeed, nEnergy) >> 1;
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < (int)nChance) nValue += nValue;
            }
            break;
        }
        }
        nValue <<= pCost->nValShift;
        if (nValue <= 0) continue;
        switch (nStat)
        {
        case 6: bUpdateLife = 1;
        case 74:
            if (!GAME_GetUnitTypeOrInvalid(pUnit))
                nValue = SKILLS_SharePotionLifeWithBloodGolem(pGame, pUnit, nValue);
            break;
        }
        if (nLength <= 0)
        {
            const int nCurrent = STATLIST_UnitGetStatValue(pUnit, nStat, 0);
            const int nMaxStat = pCost->wMaxStat;
            if (nMaxStat < sgptDataTables->nItemStatCostTxtRecordCount)
            {
                const int nMaxValue = STATLIST_UnitGetStatValue(pUnit, nMaxStat, 0);
                if (nCurrent + nValue > nMaxValue)
                    nValue = nMaxValue - nCurrent;
            }
            STATLIST_AddUnitStat(pUnit, nStat, nValue, 0);
            nResult = 1;
        }
        else
        {
            const int nExpireFrame = pGame->dwGameFrame + nOldLength + nLength;
            if (!pStatList)
            {
                pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, GAME_GetUnitTypeOrInvalid(pUnit), GAME_GetUnitGUID(pUnit));
                if (!pStatList) continue;
                STATLIST_SetState(pStatList, nState);
                STATES_ToggleState(pUnit, nState, 1);
                if (GAME_GetUnitTypeOrInvalid(pUnit))
                {
                    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 3, 0);
                    EVENT_SetEvent(pGame, pUnit, 3, pGame->dwGameFrame + 1, 0, 0);
                }
                STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRefreshPassives);
                D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
            }
            D2COMMON_10476(pStatList, nExpireFrame);
            const int nTotalValue = STATLIST_GetStatValue(pStatList, nStat, 0) * nOldLength + nValue;
            if (i == 0) EVENT_SetEvent(pGame, pUnit, 12, nExpireFrame, 0, 0);
            const int nTotalLength = nLength + nOldLength;
            if (nTotalLength > 0) STATLIST_SetStat(pStatList, nStat, nTotalValue / nTotalLength, 0);
            nResult = 1;
        }
    }
    if (bUpdateLife && pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        const unsigned char nOldLife = STATLIST_UnitGetStatValue(pUnit, STAT_LAST_SENT_HP_PCT, 0);
        const unsigned char nNewLife = MONSTERMODE_GetHpPercent128(pUnit);
        int nDifference = nOldLife - nNewLife;
        if (nDifference < 0) nDifference = -nDifference;
        if (nDifference > 4)
        {
            SUNITMSG_QueueLifeUpdate(pUnit, nNewLife);
            STATLIST_SetUnitStat(pUnit, STAT_LAST_SENT_HP_PCT, nNewLife, 0);
        }
    }

    return nResult;
}

// 0x005BE7B0
int __fastcall SKILLITEM_pSpell04_ApplyPotionStats(D2GameStrc* game,D2UnitStrc* unit,D2UnitStrc* item,D2UnitStrc* target,int x,int y,int skillId)
{
 D2ItemsTxt* record=DATATBLS_GetItemsTxtRecord(!item ? -1:item->dwClassId);
 if(!record)return 0;
 int duration=ITEMMODS_EvaluateItemFormula(unit,item,record->dwLen);
 int state=record->wState;
 D2StatListStrc* list=0;
 int remaining=0;
 if(duration>0){
  if(state<=0 || state>=sgptDataTables->nStatesTxtRecordCount)return 0;
  list=STATLIST_GetStatListFromUnitAndState(unit,state);
  if(list)remaining=D2COMMON_10473(list)-game->dwGameFrame;
 }
 int changed=0,updateLife=0;
 for(int i=0;i<3;++i){
  int stat=record->wStat[i];
  if(stat<0 || stat>=sgptDataTables->nItemStatCostTxtRecordCount)break;
  D2ItemStatCostTxt* cost=&sgptDataTables->pItemStatCostTxt[stat];
  if(!cost)continue;
  int value=ITEMMODS_EvaluateItemFormula(unit,item,record->dwCalc[i]);
  if(stat==26 || stat==74)value<<=8;
  value=value<<cost->nValShift;
  if(value<=0)continue;
  switch(stat){
   case 6:updateLife=1;
   case 74:if(!GAME_GetUnitTypeOrInvalid(unit))value=SKILLS_SharePotionLifeWithBloodGolem(game,unit,value);break;
  }
  if(duration<=0){
   const int current=STATLIST_UnitGetStatValue(unit,stat,0);
   if(cost->wMaxStat<sgptDataTables->nItemStatCostTxtRecordCount){
    int maximum=STATLIST_UnitGetStatValue(unit,cost->wMaxStat,0);
    if(current+value>maximum)value=maximum-current;
   }
   STATLIST_AddUnitStat(unit,stat,value,0);
   changed=1;
  }else{
   int expiry=game->dwGameFrame+remaining+duration;
   if(!list){
    int const nUnitGUID = GAME_GetUnitGUID(unit);
    list=STATLIST_AllocStatList(game->pMemoryPool,2,expiry,GAME_GetUnitTypeOrInvalid(unit),nUnitGUID);
    if(!list)continue;
    STATLIST_SetState(list,state);
    STATES_ToggleState(unit,state,1);
    if(GAME_GetUnitTypeOrInvalid(unit)){
     sub_00540E60(game,unit,3,0);
     EVENT_SetEvent(game,unit,3,game->dwGameFrame+1,0,0);
    }
    STATLIST_SetStatRemoveCallback(list,SKILLS_RemoveStateAndRefreshPassives);
    D2COMMON_10475_PostStatToStatList(unit,list,1);
   }
   D2COMMON_10476(list,expiry);
   int total=STATLIST_GetStatValue(list,stat,0)*remaining+value;
   if(i==0)EVENT_SetEvent(game,unit,12,expiry,0,0);
   if(duration+remaining>0)STATLIST_SetStat(list,stat,total/(duration+remaining),0);
   changed=1;
  }
 }
 if(updateLife && unit && unit->dwUnitType==UNIT_PLAYER){
  unsigned char previous=(unsigned char)STATLIST_UnitGetStatValue(unit,STAT_LAST_SENT_HP_PCT,0);
  unsigned char life=MONSTERMODE_GetHpPercent128(unit);
  int difference=(int)previous-(int)life;
  if(difference<0)difference=-difference;
  if(difference>4){
   SUNITMSG_QueueLifeUpdate(unit,life);
   STATLIST_SetUnitStat(unit,STAT_LAST_SENT_HP_PCT,life,0);
  }
 }
 return changed;
}


// 0x005BEAC0
int __fastcall SKILLITEM_pSpell05_RejuvPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const int nLength = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxtRecord->dwLen);
    const int nState = pItemsTxtRecord->wState;

    D2StatListStrc* pStatList = 0;
    int nRemainingDuration = 0;
    if (nLength > 0)
    {
        if (nState <= 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
        {
            return 0;
        }

        pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
        if (pStatList)
        {
            nRemainingDuration = D2COMMON_10473(pStatList) - pGame->dwGameFrame;
        }
    }

    int nResult = 0;
    int bAffectsHitpoints = 0;

    for (int i = 0; i < 3; ++i)
    {
        const int nStatId = pItemsTxtRecord->wStat[i];
        D2ItemStatCostTxt* pItemStatCostTxtRecord = SKILLS_GetItemStatCostTxtRecord(nStatId);
        if (pItemStatCostTxtRecord && pItemStatCostTxtRecord->wMaxStat < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            const int nPercentage = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxtRecord->dwCalc[i]);
            if (nPercentage > 0)
            {
                const int nMaxValue = STATLIST_UnitGetStatValue(pUnit, pItemStatCostTxtRecord->wMaxStat, 0);
                int nAddValue = DATATBLS_ApplyRatio(nMaxValue, nPercentage, 100);
                if (nPercentage == 100)
                {
                    nAddValue = nMaxValue;
                }

                switch (nStatId)
                {
                case 6:
                    bAffectsHitpoints = 1;
                case 74:
                    if (!GAME_GetUnitTypeOrInvalid(pUnit))
                    {
                        nAddValue = SKILLS_SharePotionLifeWithBloodGolem(pGame, pUnit, nAddValue);
                    }
                    break;
                }

                if (nLength <= 0)
                {
                    const int nOldValue = STATLIST_UnitGetStatValue(pUnit, nStatId, 0);
                    if (nOldValue + nAddValue > nMaxValue)
                    {
                        nAddValue = nMaxValue - nOldValue;
                    }

                    STATLIST_AddUnitStat(pUnit, nStatId, nAddValue, 0);
                    nResult = 1;
                }
                else
                {
                    const int nExpireFrame = pGame->dwGameFrame + nRemainingDuration + nLength;
                    if (!pStatList)
                    {
                        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, GAME_GetUnitTypeOrInvalid(pUnit), GAME_GetUnitGUID(pUnit));
                        if (!pStatList)
                        {
                            continue;
                        }

                        STATLIST_SetState(pStatList, nState);
                        STATES_ToggleState(pUnit, nState, 1);

                        if (GAME_GetUnitTypeOrInvalid(pUnit))
                        {
                            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 3, 0);
                            EVENT_SetEvent(pGame, pUnit, 3, pGame->dwGameFrame + 1, 0, 0);
                        }

                        STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRefreshPassives);
                        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
                    }

                    D2COMMON_10476(pStatList, nExpireFrame);

                    const int nTimeDependentValue = nAddValue + nRemainingDuration * STATLIST_GetStatValue(pStatList, nStatId, 0);
                    if (!i)
                    {
                        EVENT_SetEvent(pGame, pUnit, 12, nExpireFrame, 0, 0);
                    }

                    if (nRemainingDuration + nLength > 0)
                    {
                        STATLIST_SetStatIfListIsValid(pStatList, nStatId, nTimeDependentValue / (nRemainingDuration + nLength), 0);
                    }

                    nResult = 1;
                }
            }
        }
    }

    if (bAffectsHitpoints && pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        const unsigned char nNewSentHpPct = MONSTERMODE_GetHpPercent128(pUnit);
        SUNITMSG_QueueLifeUpdate(pUnit, nNewSentHpPct);
        STATLIST_SetUnitStat(pUnit, STAT_LAST_SENT_HP_PCT, nNewSentHpPct, 0);
    }

    return nResult;
}

// 0x005BEF90
int __fastcall SKILLITEM_pSpell06_AntidoteThawingPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    int nResult = 0;
    for (int i = 0; i < 2; ++i)
    {
        const int nCurseState = pItemsTxtRecord->wCurseState[i];
        if (nCurseState > 0 && nCurseState < sgptDataTables->nStatesTxtRecordCount)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nCurseState);
            if (pStatList)
            {
                D2Common_10474(pUnit, pStatList);
                STATLIST_FreeStatList(pStatList);
            }

            if (STATES_CheckState(pUnit, nCurseState))
            {
                STATES_ToggleState(pUnit, nCurseState, 0);
            }

            nResult = 1;
        }
    }

    if (SKILLITEM_pSpell09_StaminaPotion(pGame, pUnit, pItem, pTarget, nX, nY, nSkillId))
    {
        nResult = 1;
    }

    return nResult;
}

// 0x005BF0C0
int __fastcall SKILLITEM_pSpell07_OpenCube(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    if (PLAYER_IsBusy(pUnit))
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pUnit);
        if (!pInteractUnit || pInteractUnit->dwUnitType != UNIT_OBJECT || pInteractUnit->dwClassId != OBJECT_STASH)
        {
            return 0;
        }

        SUNIT_ResetInteractInfo(pUnit);
        sub_6FC4B830(pGame, pUnit);
        D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pUnit, ".\\SKILLS\\SkillItem.cpp", 947), UPDATEUI_CLOSEALL);
    }

    SUNIT_SetInteractInfo(pUnit, UNIT_ITEM, !pItem ? -1 : pItem->dwUnitId);
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pUnit, ".\\SKILLS\\SkillItem.cpp", 961), UPDATEUI_OPENCUBE);
    sub_6FC4B830(pGame, pUnit);
    return 0;
}

// 0x005BF060
int __fastcall SKILLITEM_pSpell08_AddItemValueToStat(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    const int nStatId = ITEMS_GetFileIndex(pItem);
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        const int nValue = STATLIST_UnitGetStatValue(pItem, STAT_VALUE, 0);
        if (nValue)
        {
            STATLIST_AddUnitStat(pUnit, nStatId, nValue, 0);
            return 1;
        }
    }

    return 0;
}

// 0x005BF170
int __fastcall SKILLITEM_pSpell10_CastFireBallOnTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    if (!DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId))
    {
        return 0;
    }

    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTargetUnit)
    {
        return SKILLITEM_CastSkillOnTarget(pUnit, SKILL_FIREBALL, 1, pTargetUnit, 0);
    }

    return SKILLITEM_CastSkillOnPosition(pUnit, SKILL_FIREBALL, 1, D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath), 0);
}

// 0x005BF1F0
int __fastcall SKILLITEM_pSpell11_CastFireBallToCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, unsigned short nX, unsigned short nY, int nSkillId)
{
    if (!DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId))
    {
        return 0;
    }

    return SKILLITEM_CastSkillOnPosition(pUnit, SKILL_FIREBALL, 1, nX, nY, 0);
}

#define SKILLITEM_ROLL_SEED(pSeed, lSeed) \
    (lSeed = (pSeed)->nHighSeed + 0x6AC690C5i64 * (pSeed)->nLowSeed, \
     (pSeed)->nHighSeed = (unsigned int)(lSeed >> 32), \
     (pSeed)->nLowSeed = (unsigned int)lSeed, \
     (unsigned int)lSeed)

#define SHIFT 0

#define INVALID_UNIT 6

struct D2InventoryStrc;


// 0x005C32A0
int __fastcall SKILLS_SrvSt20_IronGolem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (pTarget->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    if (pTarget->dwAnimMode != IMODE_ONGROUND)
    {
        return 0;
    }

    if (!ITEMS_IsMetalItem(pTarget->dwClassId))
    {
        return 0;
    }

    if (!ITEMS_CheckItemFlag(pTarget, 0x10, 256, ".\\SKILLS\\SkillNec.cpp"))
    {
        return 0;
    }

    return !STATLIST_GetOwner(pTarget, 0);
}

int __fastcall SKILLS_SrvSt22_PsychicHammer(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D30F0

static inline D2MonStatsTxt* GetMonStatsTxtRecord(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nId];
    return 0;
}

static inline int GetMonsterBaseId(int nId)
{
    D2MonStatsTxt* pRecord = GetMonStatsTxtRecord(nId);
    if (!pRecord)
        return nId;
    return pRecord->nBaseId;
}

static inline int ValidateMonsterId(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount)
        return nId;
    return -1;
}

// 0x005FD350
int __fastcall MONSTERSPAWN_CanSpawnAtSpawnerExit(int nMonsterId, D2ActiveRoomStrc* pRoom, int nX, int nY, int nFlag)
{
    switch (ValidateMonsterId(GetMonsterBaseId(nMonsterId)))
    {
    case 206:
    {
        D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY + 3);
        if (!pTargetRoom)
            return 0;
        if (COLLISION_CheckMaskWithSize(pTargetRoom, nX, nY + 3, 2, 0x3C01))
            return 0;
        break;
    }
    case 228:
        nY += 2;
        pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
        if (!pRoom)
            return 0;
        if (COLLISION_CheckMaskWithSize(pRoom, nX, nY, 2, 0x3C01))
            return 0;
        break;
    case 298:
        if (!nFlag)
        {
            pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
            if (!pRoom)
                return 0;
            if (COLLISION_CheckMaskWithSize(pRoom, nX, nY, 2, 0x3C01))
                return 0;
        }
        break;
    case 334:
    {
        int nAdjustedX = nX - 2;
        int nAdjustedY = nY - 2;
        D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtPoint(pRoom, nAdjustedX, nAdjustedY);
        if (!pTargetRoom)
            return 0;
        if (COLLISION_CheckMaskWithSize(pTargetRoom, nAdjustedX, nAdjustedY, 2, 0x1C0))
            return 0;
        break;
    }
    case 528:
    {
        nX += 2;
        nY += 4;
        D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
        if (!pTargetRoom)
            return 0;
        if (COLLISION_CheckMaskWithSize(pTargetRoom, nX, nY, 2, 0x3C01))
            return 0;
        break;
    }
    }
    return 1;
}

#include "gen/data/Source/D2Game/SKILLS/SkillItem.inc"
