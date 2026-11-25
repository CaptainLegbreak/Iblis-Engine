#include "D2ObjectIds.h"
#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2SkillIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2PlayerModes.h"
#include "D2MonModes.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2Drlg.h"
#include "D2GameTypes.h"
#include "D2ItemsWorld.h"
#include "D2GameAux.h"
#include "D2Txt.h"
#include "D2LevelTxt.h"
#include "D2GameObjs.h"
#include "D2GameRecords.h"
#include "D2Skills.h"
#include "D2Primitives.h"

#define MONSTATSFLAGINDEX_NOAURA 27


#define DAMAGERESULTFLAG_SUCCESSFULHIT 1


#define STATE_BLOODMANA 114

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }


#define SKILLSFLAGINDEX_AURA 5

#define SKILLSFLAGINDEX_PERIODIC 6

#define EVENTTYPE_PERIODICSTATS 9

struct D2SkillListStrc;

struct D2UnitFindArgStrc;

struct D2StaticPathStrc;

struct D2DrlgCoordsStrc;

struct D2AuraCallbackStrc;

struct D2SkillsTxt;

struct D2_6FD106F0_Strc;

struct D2_6FD10880_Strc;

struct D2MonStatsTxt;

struct D2CharStatsTxt;

struct D2StatesTxt;


struct D2PetTypeTxt;

struct D2ObjectDataStrc;

struct D2MonsterDataStrc;

struct D2MissilesTxt;


struct D2ActiveRoomStrc;

struct D2CoordStrc;

struct D2UnitStrc;

struct D2GameStrc;

struct D2DamageStrc;

struct D2DataTablesStrc;

struct D2MissileStrc;

struct D2UnitFindDataStrc;

struct D2ItemDropStrc;

union D2SeedStrc;

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2); // 0x006492A0

int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740

D2UnitStrc* __fastcall PLAYER_GetWeaponForSkill(D2UnitStrc* pUnit); // 0x00535BC0

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0

int __fastcall SKILLS_ConsumeItemQuantity(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0056C310

void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0

void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0

int __fastcall SUNITDMG_ApplyBlockOrDodge(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4, int a5); // 0x0057DFB0

void __fastcall D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x005A5560

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0

unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

int __stdcall D2Common_11024(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType, int* pHasThrowBonus); // 0x00645720

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void __fastcall SKILLS_ApplyDamageToTarget(D2GameStrc* pGame, D2UnitStrc* pAttackerArg, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nUnused); // 0x0056B9C0

int __fastcall SKILLS_CanUseWeaponAmmo(D2UnitStrc* pUnit); // 0x0056C4E0

void __fastcall PLRMODE_HandleDepletedWeapons(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00580310

void __fastcall PLRMODE_BreakDepletedWeapons(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00580380

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int nFlags); // 0x0057DBF0

int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int bUseConvertedMode); // 0x0064F380

D2UnitStrc* __fastcall SKILLS_CreateMissileFromOrigin(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056EE90

D2UnitStrc* __fastcall SKILLS_CreateMissileAtOffset(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056ECB0

void __fastcall SKILLS_ApplyWeaponBonusToMissile(D2UnitStrc* pUnit, D2UnitStrc* pMissile, D2UnitStrc* pWeapon); // 0x0056C600

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

int __fastcall sub_0056F7F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5, int a6, int a7); // 0x0056F7F0

int __fastcall SKILLS_SchedulePeriodicStat(D2GameStrc* pGame, D2UnitStrc* pUnit, int a5, int nSkillId, int nSkillLevel, int a6); // 0x0056CE70

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

struct D2_6FD106F0_Strc
{
    D2UnitStrc* pUnit;
    int nDistance;
    int nX;
    int nY;
    int (__fastcall* pCallback)(D2GameStrc*, D2UnitStrc*);
};

struct D2_6FD10880_Strc
{
    D2UnitStrc* unk0x00;
    unsigned int unk0x04;
    D2UnitStrc* unk0x08;
    unsigned int unk0x0C;
    unsigned int unk0x10;
    int unk0x14;
};

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0

int __stdcall ITEMMODS_GetItemCharges(D2UnitStrc* pItem, int nSkillId, int nSkillLevel, int* pCharges, D2StatListStrc** ppStatList); // 0x0065C820

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

void __stdcall STATLIST_SetBaseStat2(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer, D2UnitStrc* pItem); // 0x00627220

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6); // 0x0053D130

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

int __fastcall D2GAME_SKILLS_BloodMana_6FD025E0(D2UnitStrc* pUnit, int nManaCost); // 0x005D2B60

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern const int gnMissilePatternSignX[4]; // 0x006E1510

extern const int gnMissilePatternSignY[4]; // 0x006E14E4

extern const int gnMissilePatternOffsets1[7]; // 0x006E14F4

extern const int gnMissilePatternOffsets2[7]; // 0x006E14C8

extern const int gnMissilePatternXOffsets[8]; // 0x006E14A8

extern const int gnMissilePatternYOffsets[8]; // 0x006E1488

void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData); // 0x0065AA00

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010

void __fastcall PLAYERPETS_UpdatePetLimits(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00575900

D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList); // 0x00643910

D2SkillStrc* __stdcall SKILLS_GetNextSkill(D2SkillStrc* pSkill); // 0x006438F0

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

void __stdcall SKILLS_RefreshSkill(D2UnitStrc* pUnit, int nSkillId); // 0x00646D60

void __fastcall SUNIT_RewindAnimationByPercentage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nArg); // 0x00553B10

int __fastcall AIUTIL_CanUnitSwitchAi(D2UnitStrc* pUnit, int nArg); // 0x005DD480

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

void __fastcall AIGENERAL_DetachOwnedMinions(D2UnitStrc* pUnit); // 0x0058F260

void __fastcall AIGENERAL_FreeMinionList(D2UnitStrc* pUnit); // 0x0058F160

typedef int (__stdcall* FARPROC)();


extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

int __fastcall SKILLDESC_GetSkillParamByLevel(int nSkillId, int nSkillLevel); // 0x004E6CA0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0

void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, void* pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950

int __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData); // 0x0065AC70

typedef void (__fastcall* SKILLS_AREAEFFECTFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel, int nParam);

int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0

void __fastcall PLAYERPETS_RemovePet(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetGUID, int a4); // 0x005750E0

int __fastcall PLAYERPETS_GetPetTypeFromPetGUID(D2UnitStrc* player, int petId); // 0x00574A20

extern "C" D2PetTypeTxt* __fastcall sub_00478A20_GetPetTypeTxtRecord(int petType); // 0x00478A20

void __stdcall SKILLS_SetParam1(D2SkillStrc* skill, int value); // 0x00644560

extern const unsigned char gnPetFlag_006CE274; // 0x006CE274

typedef char H15_CheckSkillsTxtSize[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];

typedef char H15_CheckUnitFlags[(int)&((D2UnitStrc*)0)->dwFlags == 0xC4 ? 1 : -1];

typedef char H15_CheckSkillsCount[(int)&((D2DataTablesStrc*)0)->nSkillsTxtRecordCount == 0xBA0 ? 1 : -1];

enum
{
    UNITFLAG_TARGETABLE = 0x00000002,
    SKILLSFLAGINDEX_INTOWN = 8,
    SKILLSFLAGINDEX_TARGETABLEONLY = 20,
    SKILLSFLAGINDEX_TARGETCORPSE = 24,
    SKILLSFLAGINDEX_TARGETALLY = 26,
};

extern unsigned int gdwBitMasks[]; // 0x006CE268

int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200

int __fastcall SUNIT_CanPetBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int nSkillId); // 0x005542C0

int __fastcall SUNIT_CanAllyBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId); // 0x00554D20

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10

void __fastcall PLRMODE_ChangeModeToCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0

int __stdcall SKILLS_GetSkillInfo(D2SkillStrc* pSkill, int* pOwnerGUID, int* pSkillId, int* pSkillLevel, int* pCharges); // 0x00643B00

void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocationEx(D2DrlgActStrc* pAct, int nLevelId, int a3, int* pX, int* pY, int nUnitSize); // 0x0061B060

void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

int __fastcall QUESTS_PortalCheck(D2GameStrc* pGame, D2CoordStrc* pCoord, int nLevel, D2ActiveRoomStrc** ppRoom); // 0x00545830

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesEx(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, int nUnitSize, unsigned int nMask, int nFieldSize); // 0x0064E7E0

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

void __stdcall UNITS_SetObjectPortalFlags(D2UnitStrc* pUnit, unsigned char nPortalFlag); // 0x00622300

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

void __fastcall SUNIT_LinkPortalCoordinates(D2UnitStrc* pFirst, D2UnitStrc* pSecond); // 0x00553590

void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x00621CE0

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0

int __fastcall SKILLS_SchedulePeriodicSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5); // 0x0056CDA0

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00

void __fastcall SKILLS_RemoveStateAndRefreshPassives(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900

unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem); // 0x006289C0

int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int a2); // 0x00558200

D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3); // 0x00558D90

int __fastcall ITEMMODE_EquipCursorItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int a5, int* pUnused); // 0x005606B0

typedef int (__fastcall *SkillCallback)(D2GameStrc*, D2UnitStrc*, int, int);

extern const SkillCallback gpSkillCallbacks_007322B0[]; // 0x007322B0

extern "C" D2StatesTxt* __fastcall GAME_GetStatesTxtRecord(int nStateId); // 0x00452040

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190

void __stdcall SKILLS_RemoveSkill(D2UnitStrc* pUnit, int nSkillId, const char* szFile, int nLine); // 0x006470F0

D2SkillStrc* __stdcall SKILLS_AddSkill(D2UnitStrc* pUnit, int nSkillId); // 0x00647110

int __fastcall SKILLS_ConsumeWeaponOrAmmoQuantity(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0056C3F0

void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280

unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064D800


int __stdcall SKILLS_GetHighestSkillLevelById(D2UnitStrc* pUnit, int nSkillId); // 0x00644AA0

int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bAddWeaponDamage); // 0x00647BC0

int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bAddWeaponDamage); // 0x00647D00

int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0

int __stdcall D2COMMON_11021(D2UnitStrc* pUnit); // 0x00645680

int __stdcall UNITFINDS_TestUnit(D2UnitStrc* pUnit, D2UnitFindArgStrc* pArg); // 0x0065AA40

void __fastcall SUNITEVENT_Unregister(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimerQueueNo, int a4); // 0x005C0B50

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0

void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0

void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0

static void __stdcall D2GAME_SKILLS_SetDelay_6FD11C00(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDelay); // 0x0056EF90

D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0057D690

void __fastcall SKILLS_ApplyAuraStatsToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6CC0

void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int nUnused); // 0x00621E40

void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0

void __fastcall D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned short nSkillId, unsigned char nSkillLevel, unsigned char bRemove); // 0x0053C4A0

void __fastcall D2GAME_UpdatePlayerItems_6FC4BB90(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x0055FDE0

void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag); // 0x00644F20

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

void __fastcall SKILLS_AddElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nElementalType, int nDamage, int nElementalLength, int* pStatId, int* pElementalType); // 0x0056C8E0

#define D2_MIN(a,b) ((a) < (b) ? (a) : (b))

#define D2_MAX(a,b) ((a) > (b) ? (a) : (b))

struct D2SkillStrc;

struct D2StatListStrc;


int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill);                                            // 0x00643AD0

void __stdcall sub_006272B0_UnitStatListCall(D2UnitStrc* pUnit, int nType, int nValue, int n0);             // 0x006272B0

static int __stdcall SKILLS_ConsumeItemSkillCharge(D2GameStrc*, D2SkillStrc*, int, D2UnitStrc*);

int __fastcall SKILLS_ConsumeSkillMana(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId, int nSkillLevel);


#define SKILLSRVDO_SHAPESHIFT 116


#define SKILLSFLAGINDEX_IMMEDIATE 15

int __stdcall STATES_IsUnitShapeShifted(D2UnitStrc* pUnit); // 0x0063A400

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140

int __fastcall SUNITDMG_ApplyDamageBonuses(D2UnitStrc* pUnit, int bGetStats, D2UnitStrc* pItem, int nMinDmg, int nMaxDmg, int nDamagePercent, int nDamage, unsigned char nSrcDam); // 0x0057B420

int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0

void __stdcall STATLIST_SetSkillId(D2StatListStrc* pStatList, int nSkillId); // 0x006260D0

void __stdcall STATLIST_SetSkillLevel(D2StatListStrc* pStatList, int nSkillLevel); // 0x006260F0

void __fastcall D2GAME_PACKETS_SendPacket0x23_6FC3DC60(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, unsigned char a4, unsigned short a5, int a6); // 0x0053C590

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

struct D2CurseStrc;

struct D2MonStats2Txt;

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

void __fastcall EVENT_SetEvent(D2GameStrc*, D2UnitStrc*, int, int, int, int); // 0x005417D0

void __stdcall STATLIST_SetExpireFrame(D2StatListStrc*, int); // 0x00625310

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc*, int); // 0x00625760

D2SkillStrc* __stdcall STATLIST_GetSkillId(D2StatListStrc*); // 0x006260E0

int __stdcall STATLIST_GetSkillLevel(D2StatListStrc*); // 0x00626100

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc*); // 0x0064C040

extern "C" const char gszSkillsSourceFile; // 0x006DAB88

static void __stdcall SKILLS_StartAssignedAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId);

void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags);


enum D2C_ElemTypes
{
    ELEMTYPE_NONE = 0,
    ELEMTYPE_FIRE = 1,
    ELEMTYPE_LTNG = 2,
    ELEMTYPE_MAGIC = 3,
    ELEMTYPE_COLD = 4,
    ELEMTYPE_POIS = 5,
    ELEMTYPE_LIFE = 6,
    ELEMTYPE_MANA = 7,
    ELEMTYPE_STAMINA = 8,
    ELEMTYPE_STUN = 9,
    ELEMTYPE_RAND = 10,
    ELEMTYPE_BURN = 11,
    ELEMTYPE_FREEZE = 12,
};

extern const int gnRandomElemTypes[4]; // 0x006E1278

typedef void (__fastcall* CurseCallbackFunc)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int);

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

typedef char SkillsRecordSize[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];

typedef int (__fastcall* SkillStartFunc)(D2GameStrc*, D2UnitStrc*, int, int);

extern SkillStartFunc gpfnSkillSrvStartFunctions[]; // 0x00732140

int __fastcall SKILLS_HasManaOrChargesForUsedSkill(D2UnitStrc* pUnit); // 0x0056C160

int __stdcall D2Common_11026(int nX, int nY, D2UnitStrc* pUnit, int nCollisionMask); // 0x00645950

int __fastcall SKILLS_StartUsedSkill(D2GameStrc* pGame, D2UnitStrc* pUnit);

D2StatListStrc* __fastcall SKILLS_ApplyStateEffect(D2CurseStrc* pCurse); // 0x0056E970

static int __stdcall SKILLS_CheckUsedSkillTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId);


#define SKILLSRVDOFN_COUNT 191

#define EVENTFN_COUNT 50

#define EVENTTYPE_AITHINK 2

#define UNITFLAG_NOTC 0x00020000

#define UNITFLAG_ISREVIVE 0x80000000

struct D2PortalFlagsStrc;

struct D2SummonArgStrc;

struct D2ModeChangeStrc;

struct D2PetTypeSkillListStrc
{
    char unk0x00[0xBC];
    int nSkillCount;
    short wSkillIds[15];
    unsigned short unk0xDE;
};

typedef int (__fastcall* AURACALLBACK)(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

typedef int (__fastcall* SkillDoFunc)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

typedef int (__fastcall* D2UnitEventCallbackFunction)(D2GameStrc* pGame, int nEvent, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2DamageStrc* pDamage, int a6, int a7);

typedef int (__fastcall* UNITFINDTEST)(D2UnitStrc* pUnit, D2UnitFindArgStrc* pUnitFindArg);

extern SkillDoFunc gpfnSkillSrvDoFunctions[SKILLSRVDOFN_COUNT]; // 0x007322B0

extern const D2UnitEventCallbackFunction gpfnSkillEventCallbacks[EVENTFN_COUNT]; // 0x007325B0

void __fastcall SKILLS_IterateAuraTargets(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, AURACALLBACK pCallback, void* pCallbackArgs, int bCheckMonAuraFlag, const char* szFile, int nLine); // 0x0056B7E0

int __fastcall SKILLS_AuraCallback_ApplyAreaDamage(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x0056BA90

int __fastcall SKILLS_AuraCallback_FindClosestTarget(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x0056BB20

int __fastcall SKILLS_AuraCallback_CountTargets(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x0056BC70

int __fastcall SKILLS_AuraCallback_FindNextTarget(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x0056BCD0

int __fastcall SKILLS_UnitFindTest_Corpse(D2UnitStrc* pUnit, D2UnitFindArgStrc* pArg); // 0x0056E370

void __fastcall D2GAME_STATES_SendUnitStates_6FCC58E0(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00570E30

void __fastcall D2GAME_STATES_SendUnitStateUpdates_6FCC5BE0(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005711D0

void __fastcall PLAYERPETS_SetPetLimit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int nBaseMax); // 0x00575850

void __fastcall ITEMS_ScheduleQuantityReplenishment(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00558580

int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00

int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem); // 0x0062E6F0

int __stdcall ITEMS_CanItemBeUsedForThrowSkill(D2UnitStrc* pItem); // 0x0062A310

int __stdcall D2GAME_Transmogrify_6FC4A660(D2UnitStrc* pItem); // 0x00563FE0

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10

D2UnitEventStrc* __fastcall SUNITEVENT_Register(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEvent, int nGUID1, int nGUID2, D2UnitEventCallbackFunction pCallback, unsigned int nQueueNo, int a8); // 0x005C0AD0

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870

D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, unsigned char bAllowNeighborRooms); // 0x00555DA0

D2UnitStrc* __fastcall D2GAME_CreateLinkPortal_6FD13B20(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPortal, int nDestLevel, int nSourceLevel); // 0x0056CF40

void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0

struct D2PortalFlagsStrc
{
    unsigned char nFlags;
};

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesWithField(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighboringRooms); // 0x0064E810

unsigned int __fastcall SUNIT_GetTrackedSummonGUID(D2UnitStrc* hUnit); // 0x00554070

void __fastcall SUNIT_SetTrackedSummonGUID(D2UnitStrc* pUnit, int nUnitGUID); // 0x00554040

void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030

void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00573780

void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode); // 0x00553570

void __fastcall StartModeID(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SkillStrc* pSkill, int nMode, int nUnitType, int nTargetGUID, int bAllowReEnter); // 0x00580A70

int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20

void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60

#define UNITFLAG_SKSRVDOFUNC 0x00000040


unsigned int __stdcall sub_006417F0(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0

D2UnitStrc* __fastcall sub_0059FA30(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30

int __fastcall SKILLS_DrainTargetDurability(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillLevel); // 0x0056C2D0

void __fastcall SUNITDMG_FillDamageValues(D2GameStrc* pGame,D2UnitStrc* pAttacker,D2UnitStrc* pDefender,D2DamageStrc* pDamage,int nWeapon,unsigned char nSrcDam); // 0x0057B7D0

void __fastcall sub_005D3AC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005D3AC0

void __fastcall SKILLS_ApplyProgressiveLeechAndElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005D3BA0

void __fastcall SKILLS_ReleaseProgressiveCharges(D2GameStrc* pGame, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005D5220

unsigned int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400

typedef int (__fastcall* SKILLDOFUNC)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

typedef int (__fastcall* SKILLSTARTFUNC)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

extern SKILLSTARTFUNC gpSkillSrvStartFnTable_00732140[];                                                    // 0x00732140

D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId);                          // 0x0046ACE0

void __stdcall STATLIST_SetListExpireFrame(D2StatListStrc* pStatList, int nExpireFrame);                                // 0x006260B0

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0

#define EVENTTYPE_REMOVESTATE 12

#define SKILLSFLAGINDEX_DECQUANT 0

#define SKILLSFLAGINDEX_LOB 1

#define SKILLSFLAGINDEX2_USEMANAONDO (32 + 5)

#define SKILLS_CHECK_FLAG(pRecord, nIndex) ((pRecord)->nFlags[(nIndex) >> 3] & gdwBitMasks[(nIndex) & 7])

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60

int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0

#define MONTYPEFLAG_UNIQUE 8

#define EVENTTYPE_REMOVESTATE 0x0C

#define UNITFLAG_DOUPDATE 1

#define D2_MIN(a,b) ((a)<(b)?(a):(b))

#define D2_MAX(a,b) ((a)>(b)?(a):(b))

struct D2ServerCallbacks;


int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0

void __fastcall PLAYERSTATS_OnPlayerLeveledUp(void* pUnused, D2UnitStrc* pUnit, int nArg); // 0x00570850

typedef void (__fastcall* LevelCallback)(unsigned int, int);

struct D2ServerCallbacks
{
    char unk_00[44];
    LevelCallback levelUp;
};

extern D2ServerCallbacks* gpServerCallbacks; // 0x00883D50

unsigned int __stdcall DATATBLS_GetCurrentLevelFromExp(int nClass, unsigned int dwExperience); // 0x00611860

unsigned int __stdcall DATATBLS_GetLevelThreshold(int nClass, unsigned int dwLevel); // 0x00611800

int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc*); // 0x00625D60

void __fastcall sub_00536850_UpdateLevel(D2GameStrc*,D2UnitStrc*,int); // 0x00536850

void __fastcall D2GAME_UpdatePlayerVitals(D2GameStrc*,D2UnitStrc*); // 0x0055F500

int __stdcall UNITS_GetPlayerName(D2UnitStrc*,int,int); // 0x00622150

static void sub_00570A50_SpendStatPointsOnStrength(D2UnitStrc* pUnit, int nValue);

static void sub_00570B30_SpendStatPointsOnDexterity(D2UnitStrc* pUnit, int nValue);

extern const unsigned int gdwInvBitMasks[]; // 0x006CE2E8

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize); // 0x00410E40

int __stdcall BITMANIP_GetSize(D2BitBufferStrc*); // 0x00410E90

void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits); // 0x00410EB0

int __stdcall sub_004111A0_GetLowestSetBit(unsigned int); // 0x004111A0

unsigned int* __stdcall D2COMMON_10494_STATES_GetStatFlags(D2UnitStrc*); // 0x0063A100

int __stdcall STATLIST_GetBaseStatsData(D2StatListStrc*, D2StatStrc*, int); // 0x00625C90

void __fastcall SCMD_SendRawPacket(D2ClientStrc*, const void*, int); // 0x0053E8D0

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static inline int SKILLS_IsInRangeY(int nY, int nDistance, const D2DrlgCoordsStrc& drlgCoords)
{
    return nY + nDistance >= drlgCoords.nSubtileY || nY - nDistance <= drlgCoords.nSubtileY + drlgCoords.nSubtileHeight;
}

// 0x0056B6C0
void __fastcall SKILLS_ClampVitalsAndUpdateAnimRate(D2UnitStrc* pUnit)
{
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) > nMaxHp)
    {
        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nMaxHp, 0);
    }

    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) > nMaxMana)
    {
        STATLIST_SetUnitStat(pUnit, STAT_MANA, nMaxMana, 0);
    }

    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0) > nMaxStamina)
    {
        STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina, 0);
    }

    UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\Skills.cpp", 267);
}

struct D2UnkCallRecordStrc;

struct D2UnkCallRecordStrc
{
    void* pArg1;
    void* pArg2;
    int nZero;
    int nArg4;
};

// 0x0056B740
int __fastcall SKILLS_ApplyAuraToSelf(void* pArg1, void* pArg2, int (__fastcall* pfnCallback)(D2UnkCallRecordStrc*), int nArg4)
{
    D2UnkCallRecordStrc record;
    record.pArg1 = pArg1;
    record.pArg2 = pArg2;
    record.nArg4 = nArg4;
    record.nZero = 0;
    return pfnCallback(&record);
}

// 0x0056B770
static int SKILLS_IsRoomInRange(D2ActiveRoomStrc* pRoom, int nX, int nY, int nDistance)
{
    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);
    if (nX + nDistance >= drlgCoords.nSubtileX)
    {
        return SKILLS_IsInRangeY(nY, nDistance, drlgCoords);
    }
    if (nX - nDistance <= drlgCoords.nSubtileX + drlgCoords.nSubtileWidth)
    {
        return SKILLS_IsInRangeY(nY, nDistance, drlgCoords);
    }
    return 0;
}

// 0x0056B7E0
void __fastcall SKILLS_IterateAuraTargets(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int (__fastcall* pCallback)(D2AuraCallbackStrc*, D2UnitStrc*), void* pCallbackArgs, int bCheckMonAuraFlag, const char* szFile, int nLine)
{
    if (!pGame || !pUnit || !pCallback || nAuraRange <= 0)
    {
        return;
    }

    D2ActiveRoomStrc* pCurrentRoom = UNITS_GetRoom(pUnit);
    if (!pCurrentRoom)
    {
        return;
    }

    if (!nX || !nY)
    {
        nX = CLIENTS_GetUnitX(pUnit);
        nY = CLIENTS_GetUnitY(pUnit);
    }

    if (!nAuraFilter)
    {
        nAuraFilter = 0x583;
    }

    D2AuraCallbackStrc auraCallback;
    auraCallback.pArgs = pCallbackArgs;
    auraCallback.pGame = pGame;
    auraCallback.pOwner = pUnit;
    auraCallback.nCounter = 0;
    const int nAuraRangeSq = nAuraRange * nAuraRange;

    D2ActiveRoomStrc** ppRoomList;
    int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pCurrentRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        if (!(nAuraFilter & 0x2000) || !DUNGEON_IsRoomInTown(ppRoomList[i]))
        {
            if (SKILLS_IsRoomInRange(ppRoomList[i], nX, nY, nAuraRange))
            {
                D2UnitStrc* pTarget = ppRoomList[i]->pUnitFirst;
                while (pTarget)
                {
                    D2UnitStrc* pNextTarget = pTarget->ptRoomNext;
                    if (pTarget != pUnit && nAuraRangeSq >= PATH_ComputeSquaredDistance(nX, nY, UNITS_GetUnitXPosition(pTarget), UNITS_GetUnitYPosition(pTarget)) && sub_6FD0FA00(pUnit, pTarget, nAuraFilter))
                    {
// build: symbol ?MONSTERUNIQUE_CheckMonStatsFlag@* 0x00457490
                        if (!bCheckMonAuraFlag || pTarget->dwUnitType != UNIT_MONSTER || !MONSTERUNIQUE_CheckMonStatsFlag(pTarget->dwClassId, MONSTATSFLAGINDEX_NOAURA))
                        {
                            if (pCallback(&auraCallback, pTarget))
                            {
                                auraCallback.nCounter += 1;
                            }
                        }
                    }
                    pTarget = pNextTarget;
                }
            }
        }
    }
}

// 0x0056B9C0
void __fastcall SKILLS_ApplyDamageToTarget(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nUnused)
{
    if (!pAttacker)
    {
        return;
    }

    if (!pUnit)
    {
        return;
    }

    if (pAttacker->dwUnitType == UNIT_MISSILE)
    {
        D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pAttacker);
        if (pOwner)
        {
            pAttacker = pOwner;
        }
    }

    if ((pDamage->wResultFlags == 0) & 1)
    {
        return;
    }

    const int nBlockFlags = SUNITDMG_ApplyBlockOrDodge(pGame, pAttacker, pUnit, 1, 0);
    if (nBlockFlags & 2)
    {
        pDamage->wResultFlags |= 0x100;
    }

    if (nBlockFlags & 4)
    {
        pDamage->wResultFlags |= 0x80;
    }

    if (nBlockFlags & 0x10)
    {
        pDamage->wResultFlags |= 0x8000;
    }

    if (nBlockFlags & 1)
    {
        pDamage->wResultFlags |= 0x10;
    }

    if (nBlockFlags)
    {
        pDamage->wResultFlags &= ~DAMAGERESULTFLAG_SUCCESSFULHIT;
    }

    if (pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT && !STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        pDamage->wResultFlags |= 4;
    }

    D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(pAttacker, pUnit, pDamage);

    if (pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, pDamage);
    }

    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, pDamage);
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x0056BA90
int __fastcall SKILLS_AuraCallback_ApplyAreaDamage(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2DamageStrc damage = *(D2DamageStrc*)pAuraCallback->pArgs;
    SKILLS_ApplyDamageToTarget(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, &damage, 0);
    return 1;
}

// 0x0056BAD0
int __fastcall SKILLS_ApplyAreaDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter)
{
    if (!nAuraFilter)
    {
        nAuraFilter = 0x8583;
    }

    if (pUnit)
    {
        SKILLS_IterateAuraTargets(pGame, pUnit, nX, nY, nAuraRange, nAuraFilter, SKILLS_AuraCallback_ApplyAreaDamage, pDamage, 0, ".\\SKILLS\\Skills.cpp", 539);
    }

    return 1;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

// 0x0056BB20
int __fastcall SKILLS_AuraCallback_FindClosestTarget(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2_6FD106F0_Strc* pArgs = (D2_6FD106F0_Strc*)pAuraCallback->pArgs;

    if (!pArgs->pCallback || pArgs->pCallback(pAuraCallback->pGame, pUnit))
    {
        const int nXDiff = CLIENTS_GetUnitXInline(pUnit) - pArgs->nX;
        const int nYDiff = CLIENTS_GetUnitYInline(pUnit) - pArgs->nY;

        const int nDistance = nXDiff * nXDiff + nYDiff * nYDiff;
        if (nDistance < pArgs->nDistance)
        {
            pArgs->nDistance = nDistance;
            pArgs->pUnit = pUnit;
        }

        return 1;
    }

    return 0;
}

// 0x0056BBC0
D2UnitStrc* __fastcall SKILLS_FindAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nAuraRange, int (__fastcall* pCallback)(D2GameStrc*, D2UnitStrc*))
{
    D2_6FD106F0_Strc arg;
    arg.pUnit = 0;
    arg.nDistance = 0x7FFFFFFF;
    arg.nX = CLIENTS_GetUnitXInline(pUnit);
    arg.nY = CLIENTS_GetUnitYInline(pUnit);
    arg.pCallback = pCallback;

    SKILLS_IterateAuraTargets(pGame, pUnit, 0, 0, nAuraRange, 0x8783, SKILLS_AuraCallback_FindClosestTarget, &arg, 0, ".\\SKILLS\\Skills.cpp", 696);

    return arg.pUnit;
}

// 0x0056BC70
int __fastcall SKILLS_AuraCallback_CountTargets(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    ++*(int*)pAuraCallback->pArgs;
    return 1;
}

// 0x0056BC80
int __fastcall SKILLS_CountAuraTargets(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter)
{
    int nSkillId = 0;

    SKILLS_IterateAuraTargets(pGame, pUnit, nX, nY, nAuraRange, nAuraFilter | 0xA783, SKILLS_AuraCallback_CountTargets, &nSkillId, 0, ".\\SKILLS\\Skills.cpp", 736);

    return nSkillId;
}

// 0x0056BCD0
int __fastcall SKILLS_AuraCallback_FindNextTarget(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2_6FD10880_Strc* pArgs = (D2_6FD10880_Strc*)pAuraCallback->pArgs;

    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;

    if ((unsigned int)nUnitGUID <= pArgs->unk0x10 || (unsigned int)nUnitGUID >= pArgs->unk0x04)
    {
        if ((unsigned int)nUnitGUID <= pArgs->unk0x0C)
        {
            pArgs->unk0x0C = nUnitGUID;
            pArgs->unk0x08 = pUnit;
        }
        ++pArgs->unk0x14;
    }
    else
    {
        pArgs->unk0x04 = nUnitGUID;
        pArgs->unk0x00 = pUnit;
        ++pArgs->unk0x14;
    }

    return 1;
}

// 0x0056BD10
D2UnitStrc* __fastcall SKILLS_FindNextAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int a7, int* a8)
{
    D2_6FD10880_Strc args;
    args.unk0x0C = a7;
    args.unk0x10 = a7;
    args.unk0x00 = 0;
    args.unk0x04 = -1;
    args.unk0x08 = 0;
    args.unk0x14 = 0;
    SKILLS_IterateAuraTargets(pGame, pUnit, nX, nY, nAuraRange, nAuraFilter | 0xA783, SKILLS_AuraCallback_FindNextTarget, &args, 0, ".\\SKILLS\\Skills.cpp", 803);

    D2UnitStrc* pResult = args.unk0x00;
    if (!pResult)
    {
        pResult = args.unk0x08;
    }

    if (a8)
    {
        *a8 = args.unk0x14;
    }

    return pResult;
}

// 0x0056BD90
void __fastcall SKILLS_UpdatePetLimitForSkill(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId)
{
    if (!pPlayer || pPlayer->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    if ((signed char)pSkillsTxtRecord->nPetType <= 0 || (signed char)pSkillsTxtRecord->nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        return;
    }

    D2PetTypeSkillListStrc* pPetTypeTxtRecord = (D2PetTypeSkillListStrc*)sub_00478A20_GetPetTypeTxtRecord((signed char)pSkillsTxtRecord->nPetType);
    if (!pPetTypeTxtRecord)
    {
        return;
    }

    int nMax = 0;
    for (int i = 0; i < pPetTypeTxtRecord->nSkillCount; ++i)
    {
        const int nPetSkillId = pPetTypeTxtRecord->wSkillIds[i];
        D2SkillsTxt* pPetSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nPetSkillId);
        if (pPetSkillsTxtRecord)
        {
            D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, nPetSkillId);
            if (pSkill)
            {
                const int nLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 1);
                int nPetMax = 0;
                if (nLevel > 0)
                {
                    nPetMax = SKILLS_EvaluateSkillFormula(pPlayer, pPetSkillsTxtRecord->dwPetMax, nPetSkillId, nLevel);
                    if (nPetMax < 1)
                    {
                        nPetMax = 1;
                    }
                }

                if (nPetMax > nMax)
                {
                    nMax = nPetMax;
                }
            }
        }
    }

    PLAYERPETS_SetPetLimit(pGame, pPlayer, (signed char)pSkillsTxtRecord->nPetType, nMax);
}

// 0x0056BEC0
static int __stdcall SKILLS_ConsumeItemSkillCharge(D2GameStrc* pGame, D2SkillStrc* pSkill, int nOwnerGUID, D2UnitStrc* pPlayer)
{
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nOwnerGUID);
    if (!pItem) return 0;
    int nChargeSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 898);
    int nChargeSkillLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 0);
    int nCharges = 0;
    D2StatListStrc* pStatList = 0;
    if (!ITEMMODS_GetItemCharges(pItem, nChargeSkillId, nChargeSkillLevel, &nCharges, &pStatList) || nCharges <= 0)
        return 0;
    nChargeSkillId = (nChargeSkillId << sgptDataTables->nStuff) + (nChargeSkillLevel & sgptDataTables->nShiftedStuff);
    const int nStatValue = STATLIST_GetStatValue(pStatList, STAT_ITEM_CHARGED_SKILL, nChargeSkillId);
    if (!nStatValue) return 0;
    const int nMaxCharges = nStatValue >> 8;
    --nCharges;
    if (nMaxCharges <= 0 || nMaxCharges > 255) return 0;
    nCharges = D2_MIN(D2_MAX(nCharges, 0), nMaxCharges);
    nChargeSkillLevel = (nCharges & 0xFF) + (nMaxCharges << 8);
    STATLIST_SetBaseStat2(pStatList, STAT_ITEM_CHARGED_SKILL, nChargeSkillLevel, nChargeSkillId, pItem);
    D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pPlayer, ".\\SKILLS\\Skills.cpp", 933), pItem, 1, STAT_ITEM_CHARGED_SKILL, nChargeSkillLevel, nChargeSkillId);
    return 1;
}

static inline int SKILLS_IsPlayerInline(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwUnitType == UNIT_PLAYER;
}

// 0x0056BFE0
int __fastcall SKILLS_ConsumeSkillMana(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_IsPlayerInline(pPlayer))
    {
        return 1;
    }
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pPlayer);
    if (pSkill && SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 955) == nSkillId)
    {
        const int nOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pSkill);
        if (nOwnerGUID != -1)
        {
            return SKILLS_ConsumeItemSkillCharge(pGame, pSkill, nOwnerGUID, pPlayer);
        }
    }
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    if (!pSkillsTxtRecord->wMana && !pSkillsTxtRecord->wLevelMana)
    {
        return 0;
    }
    const int nLevelBonus = nSkillLevel - 1 < 0 ? 0 : nSkillLevel - 1;
    int nManaCost = (pSkillsTxtRecord->wMana + nLevelBonus * pSkillsTxtRecord->wLevelMana) << pSkillsTxtRecord->nManaShift;
    const int nMinManaCost = pSkillsTxtRecord->wMinMana << 8;
    if (nMinManaCost > nManaCost)
    {
        nManaCost = nMinManaCost;
    }
    if (STATES_CheckState(pPlayer, STATE_BLOOD_MANA))
    {
        return D2GAME_SKILLS_BloodMana_6FD025E0(pPlayer, nManaCost);
    }
    if (STATLIST_UnitGetStatValue(pPlayer, STAT_MANA, 0) < nManaCost)
    {
        return 0;
    }
    sub_006272B0_UnitStatListCall(pPlayer, STAT_MANA, -nManaCost, 0);
    return 1;
}

// 0x0056C110
int __fastcall D2GAME_SKILLMANA_AuraConsume_6FD10C90(D2UnitStrc* pUnit, int nManaCost)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_PLAYER)
    {
        return 1;
    }

    if (STATES_CheckState(pUnit, STATE_BLOODMANA))
    {
        return D2GAME_SKILLS_BloodMana_6FD025E0(pUnit, nManaCost);
    }

    if (STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) < nManaCost)
    {
        return 0;
    }

    STATLIST_AddUnitStat(pUnit, STAT_MANA, -nManaCost, 0);
    return 1;
}

// 0x0056C160
int __fastcall SKILLS_HasManaOrChargesForUsedSkill(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_PLAYER)
    {
        return 1;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (SKILLS_GetOwnerGUIDFromSkill(pSkill) != -1)
    {
        return pSkill->nCharges > 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1) - 1;
    if (nSkillLevel < 0)
    {
        nSkillLevel = 0;
    }

    const int nManaCost = (pSkillsTxtRecord->wMana + nSkillLevel * pSkillsTxtRecord->wLevelMana) << (unsigned char)pSkillsTxtRecord->nManaShift;
    if (pSkillsTxtRecord->wSrvDoFunc == SKILLSRVDO_SHAPESHIFT && STATES_IsUnitShapeShifted(pUnit))
    {
        return 1;
    }

    return STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) >= nManaCost;
}

static inline D2CharStatsTxt* DATATBLS_GetCharStatsTxtRecord(int nClassId)
{
    if (nClassId >= 0 && nClassId < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClassId];
    }

    return 0;
}

static inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static inline int MONSTERS_GetBaseIdFromMonsterId(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nBaseId;
    }

    return nMonsterId;
}

// 0x0056C210
D2UnitFindDataStrc* __fastcall SKILLS_AllocUnitSearch(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSize, int nX, int nY)
{
    D2UnitFindDataStrc* pUnitFindData = (D2UnitFindDataStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2UnitFindDataStrc), ".\\SKILLS\\Skills.cpp", 1099, 0);

    D2UnitFindArgStrc unitFindArg = {};
    unitFindArg.nFlags = 0x583;
    unitFindArg.pUnit = pUnit;
    unitFindArg.nX = nX;
    unitFindArg.nY = nY;
    unitFindArg.nSize = nSize;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, pUnitFindData, pRoom, nX, nY, nSize, 0, &unitFindArg);
    UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(pUnitFindData);

    return pUnitFindData;
}

// 0x0056C2A0
void __fastcall SKILLS_FreeUnitSearch(D2GameStrc* pGame, D2UnitFindDataStrc* pUnitFindData)
{
    UNITFINDS_FreeUnitFindData(pUnitFindData);
    FOG_FreeServerMemory(pGame->pMemoryPool, pUnitFindData, ".\\SKILLS\\Skills.cpp", 0x465, 0);
}

// 0x0056C2D0
int __fastcall SKILLS_DrainTargetDurability(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}

// 0x0056C310
int __fastcall SKILLS_ConsumeItemQuantity(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (pItem)
    {
        int bNoQuantity = 0;
        int nQuantity = STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) - 1;
        if (nQuantity < 0)
        {
            bNoQuantity = 1;
            nQuantity = 0;
        }

        STATLIST_SetUnitStat(pItem, STAT_QUANTITY, nQuantity, 0);
        ITEMS_ScheduleQuantityReplenishment(pGame, pItem);

        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\SKILLS\\Skills.cpp", 1350), pItem, 1, STAT_QUANTITY, nQuantity, 0);

        const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
        if (STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0) != nMaxDurability)
        {
            STATLIST_SetUnitStat(pItem, STAT_DURABILITY, nMaxDurability, 0);
            D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\SKILLS\\Skills.cpp", 1356), pItem, 1, STAT_DURABILITY, nMaxDurability, 0);
        }

        PLRMODE_HandleDepletedWeapons(pGame, pUnit);

        if (!bNoQuantity)
        {
            return nQuantity + 1;
        }
    }

    return 0;
}

// 0x0056C3F0
int __fastcall SKILLS_ConsumeWeaponOrAmmoQuantity(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        D2UnitStrc* pWeapon = PLAYER_GetWeaponForSkill(pUnit);
        int bNoBow = 1;

        if (ITEMSIsA(pWeapon, ITEMTYPE_BOW) || ITEMSIsA(pWeapon, ITEMTYPE_CROSSBOW))
        {
            bNoBow = 0;
        }

        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
        if (pItem && (!bNoBow || pItem == pWeapon) && (ITEMS_CheckIfStackable(pItem) || ITEMS_CheckIfThrowable(pItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROWABLE, 0)))
        {
            return SKILLS_ConsumeItemQuantity(pGame, pUnit, pItem);
        }

        pItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
        if (pItem && (!bNoBow || pItem == pWeapon) && (ITEMS_CheckIfStackable(pItem) || ITEMS_CheckIfThrowable(pItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROWABLE, 0)))
        {
            return SKILLS_ConsumeItemQuantity(pGame, pUnit, pItem);
        }
    }

    return 0;
}

// 0x0056C4E0
int __fastcall SKILLS_CanUseWeaponAmmo(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 1;
    }

    D2UnitStrc* pWeapon = PLAYER_GetWeaponForSkill(pUnit);
    if (!pWeapon)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int bNoAmmoItem = 1;
    if (ITEMS_GetAmmoType(pWeapon))
    {
        bNoAmmoItem = 0;
        if (!SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 1600) && STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, STAT_ITEM_MAGICARROW, 0))
        {
            return 1;
        }
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2UnitStrc* pRightArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
    if (pRightArmItem && (!bNoAmmoItem || pRightArmItem == pWeapon) && (ITEMS_CheckIfStackable(pRightArmItem) || ITEMS_CheckIfThrowable(pRightArmItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pRightArmItem, STAT_ITEM_THROWABLE, 0)))
    {
        return ITEMS_CanItemBeUsedForThrowSkill(pRightArmItem);
    }

    D2UnitStrc* pLeftArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
    if (pLeftArmItem && (!bNoAmmoItem || pLeftArmItem == pWeapon) && (ITEMS_CheckIfStackable(pLeftArmItem) || ITEMS_CheckIfThrowable(pLeftArmItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pLeftArmItem, STAT_ITEM_THROWABLE, 0)))
    {
        return ITEMS_CanItemBeUsedForThrowSkill(pLeftArmItem);
    }

    return 0;
}

// 0x0056C600
void __fastcall SKILLS_ApplyWeaponBonusToMissile(D2UnitStrc* pUnit, D2UnitStrc* pMissile, D2UnitStrc* pWeapon)
{
    if (pUnit && pMissile && pWeapon)
    {
        const int nToHit = STATLIST_UnitGetStatValue(pMissile, STAT_TOHIT, 0);
        const int nToHitBonus = D2Common_11024(pUnit, pWeapon, 0, 0, 0);
        STATLIST_SetUnitStat(pMissile, STAT_TOHIT, nToHitBonus + nToHit, 0);
        const int nDamageBonus = D2Common_11024(pUnit, pWeapon, 0, 1, 0);
        STATLIST_AddUnitStat(pMissile, STAT_DAMAGEPERCENT, nDamageBonus, 0);
    }
}

struct D2ClientStrc;

// 0x0056C670
static D2UnitStrc* __stdcall SKILLS_GetOtherHandItem(D2InventoryStrc* pInventory, int nBodyLoc)
{
    if (nBodyLoc == BODYLOC_LARM)
    {
        return INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
    }
    return INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
}

// 0x0056C6A0
void __fastcall SKILLS_HandleTransmogrify(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (pUnit)
    {
        pUnit->dwFlagEx &= 0xFFFFFFBF;
    }

    if (pItem && D2GAME_Transmogrify_6FC4A660(pItem))
    {
        SUNIT_AttachSound(pUnit, 4, pUnit);
    }

    D2GAME_PACKETS_SendPacket0x3F_6FC3EDC0(UnitGetClient(pUnit, ".\\SKILLS\\Skills.cpp", 1711), 0, 0xFF, 1, 0, 0xFFFF);
}

static inline D2SkillsTxt* GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static inline int GetClassId(D2UnitStrc* pUnit)
{
    int nClassId = -1;
    if (pUnit)
    {
        nClassId = pUnit->dwClassId;
    }
    return nClassId;
}

// 0x0056C700
int __fastcall D2GAME_CheckSkillIfUnitsClassSkill_6FD11B50(D2UnitStrc* pUnit, int nSkillId)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord(nSkillId);
        if (pSkillsTxtRecord)
            return pSkillsTxtRecord->nCharClass == GetClassId(pUnit);
    }
    return 0;
}

D2UnitStrc* __fastcall sub_K11_Emit0056C670(D2InventoryStrc* pInventory, int nBodyLoc)
{
    return SKILLS_GetOtherHandItem(pInventory, nBodyLoc + 1);
}

static inline D2StatesTxt* STATES_GetStatesTxtRecordInline(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }

    return 0;
}

// 0x0056E780
int __fastcall SKILLS_IterateTargetsAroundTarget(D2GameStrc* pGame, unsigned int nFlags, D2UnitStrc* pUnit, int nDistance, int (__fastcall* pCallback)(D2UnitStrc*, void*), void* pArgs)
{
    if (!pCallback)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    const int nDistanceSq = nDistance * nDistance;
    D2ActiveRoomStrc** ppRoomList;
    int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (int i = 0; i < nNumRooms; ++i)
    {
        if (!(nFlags & 0x2000) || !DUNGEON_IsRoomInTown(ppRoomList[i]))
        {
            if (SKILLS_IsRoomInRange(ppRoomList[i], nX, nY, nDistance))
            {
                for (D2UnitStrc* j = ppRoomList[i]->pUnitFirst; j; j = j->ptRoomNext)
                {
                    if (nDistanceSq >= PATH_ComputeSquaredDistance(nX, nY, UNITS_GetUnitXPosition(j), UNITS_GetUnitYPosition(j)) && sub_6FD0FA00(pUnit, j, nFlags))
                    {
                        pCallback(j, pArgs);
                    }
                }
            }
        }
    }

    return 1;
}

inline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x0056E900
void __fastcall SKILLS_RemoveStateAndRefreshPassives(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    SUNITEVENT_Unregister(SUNIT_GetGameFromUnit(pUnit), pUnit, 1, nState);

    if (!SUNIT_IsDead(pUnit) || !STATES_CheckStateMaskStayDeathOnUnitByStateId(pUnit, nState))
    {
        STATES_ToggleState(pUnit, nState, 0);
        UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\Skills.cpp", 1157);
        SKILLS_RefreshPassiveSkills(pUnit);

        if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        {
            PLAYERPETS_UpdatePetLimits(SUNIT_GetGameFromUnit(pUnit), pUnit);
        }
    }
}

// 0x0056DE40
void __fastcall SKILLS_RefreshPassivesAndPetLimits(D2UnitStrc* pUnit)
{
    SKILLS_RefreshPassiveSkills(pUnit);
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        PLAYERPETS_UpdatePetLimits(SUNIT_GetGameFromUnit(pUnit), pUnit);
    }
}

// 0x0056DE70
D2SkillStrc* __fastcall SKILLS_AddSkillAndRefresh(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = SKILLS_AddSkill(pUnit, nSkillId);
    SKILLS_RefreshPassiveSkills(pUnit);
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        PLAYERPETS_UpdatePetLimits(SUNIT_GetGameFromUnit(pUnit), pUnit);
    return pSkill;
}

// 0x00570360
void __fastcall SKILLS_ResetSkillsAndRefundPoints(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    const int nClassId = pUnit->dwClassId;
    const int nSkillCount = SKILLS_GetPlayerSkillCount(nClassId);
    int nSkillPoints = 0;
    for (int i = 0; i < nSkillCount; ++i)
    {
        const int nSkillId = SKILLS_GetClassSkillId(nClassId, i);
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
        if (pSkill)
        {
            nSkillPoints += SKILLS_GetSkillLevel(pUnit, pSkill, 0);
            D2GAME_SetSkills_6FD14C60(pUnit, nSkillId, 0, 1);
            D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(UnitGetClient(pUnit, ".\\SKILLS\\Skills.cpp", 4257), pUnit, nSkillId, 0, 1);
        }
    }

    STATLIST_AddUnitStat(pUnit, STAT_SKILLPTS, nSkillPoints, 0);
    D2GAME_UpdatePlayerVitals_6FC4B240(pGame, pUnit);
    D2GAME_UpdatePlayerItems_6FC4BB90(pGame, pUnit, 1);
}

static inline unsigned int sub_0056CBA0_GetUnitType(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

static inline int sub_0056CBA0_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

// 0x0056DEB0
void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        SKILLS_AssignSkill(pUnit, nSkillId, nSkillLevel, bRemove, ".\\SKILLS\\Skills.cpp", 4394);
        SKILLS_RefreshPassiveSkills(pUnit);
        if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        {
            PLAYERPETS_UpdatePetLimits(SUNIT_GetGameFromUnit(pUnit), pUnit);
        }
    }
}

// 0x0056DF10
void __fastcall SKILLS_RemoveSkillAndRefresh(D2UnitStrc* pUnit, int nSkillId)
{
    SKILLS_RemoveSkill(pUnit, nSkillId, ".\\SKILLS\\Skills.cpp", 4405);
    SKILLS_RefreshPassiveSkills(pUnit);
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        PLAYERPETS_UpdatePetLimits(SUNIT_GetGameFromUnit(pUnit), pUnit);
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_H15(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static inline int UNIT_HasFlag_H15(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

// 0x0056DF50
int __fastcall SKILLS_IsActiveSkill(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = UNITS_GetRightSkill(pUnit);
    if (pSkill && SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 4416) == nSkillId)
        return 1;
    pSkill = UNITS_GetLeftSkill(pUnit);
    if (pSkill && SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 4419) == nSkillId)
        return 1;
    return 0;
}

inline int SKILL_ComputePeriodicRate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel)
{
    int nDelay = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPerDelay, nSkillId, nSkillLevel);
    if (nDelay <= 5)
    {
        nDelay = 5;
    }

    return (pGame->dwGameFrame + nDelay - 1) / nDelay * nDelay + 1;
}

// 0x0056EDE0
D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY)
{
    if (!pUnit)
    {
        return 0;
    }

    if (!nX && !nY)
    {
        D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY);
        if (!nX && !nY)
        {
            return 0;
        }
    }

    if (sub_006417F0(pUnit, nX, nY) > 100)
    {
        return 0;
    }

    D2MissileStrc missileParams = {};
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.dwFlags = 1;
    missileParams.pOwner = pUnit;
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.nMissile = nMissileId;

    return sub_0059FA30(pGame, &missileParams);
}

// 0x0056EF90
static void __stdcall D2GAME_SKILLS_SetDelay_6FD11C00(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDelay)
{
    const int nExpireFrame = nDelay + pGame->dwGameFrame;
    if (pUnit && !pUnit->dwUnitType && nDelay)
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_SKILLDELAY);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
            if (!pStatList)
            {
                return;
            }

            STATLIST_SetState(pStatList, STATE_SKILLDELAY);
            STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRefreshPassives);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
            STATES_ToggleState(pUnit, 0x79, 1);
        }

        D2COMMON_10476(pStatList, nExpireFrame);
        EVENT_SetEvent(pGame, pUnit, 12, nExpireFrame, 0, 0);
    }
}

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnitInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x0056F020
void __fastcall SKILLS_ApplySkillDelay(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        const int nSkillDelay = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwDelay, nSkillId, nSkillLevel);
        if (nSkillDelay > 0)
        {
            D2GAME_SKILLS_SetDelay_6FD11C00(pGame, pUnit, nSkillDelay);
        }
    }
}

// 0x0056C740
int __fastcall SKILLS_RemoveStatesInGroup(D2UnitStrc* pUnit, int nStateId, int a3)
{
    D2StatesTxt* pStatesTxtRecord = STATES_GetStatesTxtRecordInline(nStateId);
    if (!pStatesTxtRecord || !pStatesTxtRecord->wGroup)
    {
        return 0;
    }

    int nResult = 0;
    const int nGroup = (short)pStatesTxtRecord->wGroup;
    const int nCount = sgptDataTables->nStatesTxtRecordCount;
    for (int i = 0; i < nCount; ++i)
    {
        if (i != nStateId || a3)
        {
            if ((short)STATES_GetStatesTxtRecordInline(i)->wGroup == nGroup && STATES_CheckState(pUnit, i))
            {
                nResult = 1;
                STATES_ToggleState(pUnit, i, 0);

                D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, i);
                if (pStatList)
                {
                    D2Common_10474(pUnit, pStatList);
                    STATLIST_FreeStatList(pStatList);
                }
            }
        }
    }

    return nResult;
}

// 0x0056C840
void __fastcall SKILLS_SetElementalDurationFromSkill(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nLength, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    switch (pSkillsTxtRecord->nEType)
    {
    case ELEMTYPE_COLD:
        pDamage->dwColdLen = nLength;
        break;
    case ELEMTYPE_POIS:
        pDamage->dwPoisLen = nLength;
        break;
    case ELEMTYPE_STUN:
        pDamage->dwStunLen = nLength;
        break;
    case ELEMTYPE_BURN:
        pDamage->dwBurnLen = nLength;
        break;
    case ELEMTYPE_FREEZE:
        pDamage->dwFrzLen = nLength;
        break;
    }
}

// 0x0056C8E0
void __fastcall SKILLS_AddElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nElementalType, int nDamage, int nLength, int* pResistStatId, int* pElementalType)
{
    if (nElementalType == ELEMTYPE_RAND)
    {
        nElementalType = gnRandomElemTypes[ITEMS_RollRandomNumber(&pUnit->pSeed) & 3];
        if (nLength <= 0)
        {
            nLength = 50;
        }

        if (pElementalType)
        {
            *pElementalType = nElementalType;
        }
    }

    int nResStatId = -1;
    switch (nElementalType)
    {
    case ELEMTYPE_FIRE:
        pDamage->dwFireDamage += nDamage;
        pDamage->dwHitClass = 0x20;
        nResStatId = STAT_FIRERESIST;
        break;

    case ELEMTYPE_LTNG:
        pDamage->dwLtngDamage += nDamage;
        pDamage->dwHitClass = 0x40;
        nResStatId = STAT_LIGHTRESIST;
        break;

    case ELEMTYPE_MAGIC:
        pDamage->dwMagDamage += nDamage;
        nResStatId = STAT_MAGICRESIST;
        break;

    case ELEMTYPE_COLD:
        pDamage->dwColdDamage += nDamage;
        pDamage->dwColdLen = nLength;
        pDamage->dwHitClass = 0x30;
        nResStatId = STAT_COLDRESIST;
        break;

    case ELEMTYPE_POIS:
        pDamage->dwPoisDamage += nDamage;
        pDamage->dwPoisLen = nLength;
        pDamage->dwHitClass = 0x50;
        nResStatId = STAT_POISONRESIST;
        break;

    case ELEMTYPE_LIFE:
        pDamage->dwLifeLeech += nDamage;
        break;

    case ELEMTYPE_MANA:
        pDamage->dwManaLeech += nDamage;
        break;

    case ELEMTYPE_STAMINA:
        pDamage->dwStamLeech += nDamage;
        break;

    case ELEMTYPE_STUN:
        pDamage->dwStunLen += nDamage + nLength;
        pDamage->dwHitClass = 0x60;
        break;

    case ELEMTYPE_BURN:
        pDamage->dwBurnDamage += nDamage;
        pDamage->dwBurnLen = nLength;
        break;

    case ELEMTYPE_FREEZE:
        pDamage->dwColdDamage += nDamage;
        pDamage->dwFrzLen = nLength;
        pDamage->dwHitClass = 0x30;
        nResStatId = STAT_COLDRESIST;
        break;

    default:
        pDamage->dwPhysDamage += nDamage;
        break;
    }

    if (pResistStatId)
    {
        *pResistStatId = nResStatId;
    }
}

// 0x0056CA40
int __fastcall SKILLS_SrvSt01_Attack_LeftHandSwing(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    pUnit->nSeqCurrentFramePrecise = UNITS_GetFrameBonus(pUnit) << 8;
    if (STATES_CheckStateMaskOnUnit(pUnit, 38))
    {
        return sub_6FD00370(pGame, pUnit, nSkillLevel);
    }

    if (!COMPOSIT_IsWeaponBowOrXBow(pUnit) || SKILLS_CanUseWeaponAmmo(pUnit))
    {
        return 1;
    }

    PLRMODE_HandleDepletedWeapons(pGame, pUnit);
    PLRMODE_BreakDepletedWeapons(pGame, pUnit);
    return 0;
}

// 0x0056CAB0
int __fastcall SKILLS_SrvSt65_Throw_LeftHandThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_CanUseWeaponAmmo(pUnit))
    {
        PLRMODE_HandleDepletedWeapons(pGame, pUnit);
        PLRMODE_BreakDepletedWeapons(pGame, pUnit);
        return 0;
    }

    return 1;
}

// 0x0056CAF0
int __fastcall SKILLS_SrvSt02_Kick(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = 9;
    damage.dwHitFlags = 2;
    damage.dwPhysDamage = pSkillsTxtRecord->dwMinDam << pSkillsTxtRecord->nToHitShift;
    damage.dwHitClass = 1;
    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 128);
    return 1;
}

// 0x0056CBA0
int __fastcall SKILLS_SrvSt03_Unsummon(D2GameStrc* game, D2UnitStrc* unit, int skillId, int skillLevel)
{
    D2UnitStrc* target = SUNIT_GetTargetUnit(game, unit);
    if (!target)
        return 0;
    if (sub_0056CBA0_GetUnitType(target) != 1)
        return 0;
    if (!unit)
        return 0;
    if (unit->dwUnitType != UNIT_PLAYER)
        return 0;
    if (AIGENERAL_GetMinionOwner(target) != unit)
        return 0;
    D2PetTypeTxt* petType = sub_00478A20_GetPetTypeTxtRecord(PLAYERPETS_GetPetTypeFromPetGUID(unit, target->dwUnitId));
    if (!petType)
        return 0;
    if (!(petType->nPetFlags[0] & gnPetFlag_006CE274))
        return 0;
    D2SkillStrc* skill = UNITS_GetUsedSkill(unit);
    if (!skill)
        return 0;
    SKILLS_SetParam1(skill, sub_0056CBA0_GetUnitId(target));
    return 1;
}

static inline SkillCallback GetSkillCallback(short nIndex)
{
    if (nIndex < 0)
        return 0;
    if (nIndex >= 191)
        return 0;
    return gpSkillCallbacks_007322B0[nIndex];
}

// 0x0056CC20
int __fastcall SKILLS_SrvDo004_Unsummon(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return 0;

    PLAYERPETS_RemovePet(pGame, pUnit, SKILLS_GetParam1(pSkill), 1);
    return 1;
}

// 0x0056CC60
static int __stdcall SKILLS_CheckUsedSkillTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 1;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_H15(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETABLEONLY >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETABLEONLY & 7])
    {
        if (!SUNIT_AreUnitsHostile(pGame, pUnit, pTarget) && !SUNIT_CanPetBeTargetedBySkill(pGame, pUnit, pTarget, nSkillId) && !SUNIT_CanAllyBeTargetedBySkill(pGame, pUnit, pTarget, nSkillId))
        {
            return 0;
        }
    }

    if (!UNIT_HasFlag_H15(pTarget, UNITFLAG_TARGETABLE))
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
    }
    else
    {
        if (pTarget->dwUnitType == UNIT_MONSTER && pTarget->dwAnimMode == MONMODE_DEAD)
        {
            if (!(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETCORPSE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETCORPSE & 7]))
            {
                UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
            }
        }
        else
        {
            if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETCORPSE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETCORPSE & 7])
            {
                UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
            }
        }
    }

    return 1;
}

static inline int UNITS_HasBeenDeletedInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    return (pUnit->dwFlagEx >> 8) & 1;
}

static inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }
    return 0;
}

// 0x0056FAF0
int __fastcall SKILLS_StartUsedSkill(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 0xBFF);
    if (!SKILLS_CheckUsedSkillTarget(pGame, pUnit, nSkillId))
    {
        if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        {
            PLRMODE_ChangeModeToCoords(pGame, pUnit, 0, PLRMODE_TOWNNEUTRAL, 0, 0, 1);
        }
        return 0;
    }

    int nOwnerGUID;
    int nInfoSkillId;
    int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    int nCharges;
    if (SKILLS_GetSkillInfo(pSkill, &nOwnerGUID, &nInfoSkillId, &nSkillLevel, &nCharges) && !nCharges)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_H15(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTargetUnit && !(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETALLY >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETALLY & 7]) && SUNIT_CanAllyBeTargetedBySkill(pGame, pUnit, pTargetUnit, nSkillId))
    {
        return 0;
    }

    if (!(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_INTOWN >> 3] & gdwBitMasks[SKILLSFLAGINDEX_INTOWN & 7]))
    {
        if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
        {
            UNITS_SetUsedSkill(pUnit, 0);
            int nType = UNIT_INVALID;
            if (pUnit)
            {
                nType = pUnit->dwUnitType;
            }
            switch (nType)
            {
            case UNIT_PLAYER:
                PLRMODE_ChangeModeToCoords(pGame, pUnit, 0, PLRMODE_TOWNNEUTRAL, 0, 0, 1);
                break;
            case UNIT_MONSTER:
                return 0;
            }
            return 0;
        }
    }

    const int nResult = sub_6FD12950(pGame, pUnit, nSkillId, nSkillLevel, 0);
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && !nResult)
    {
        PLRMODE_ChangeModeToCoords(pGame, pUnit, 0, PLRMODE_TOWNNEUTRAL, 0, 0, 1);
    }
    return nResult;
}

// 0x0056CDA0
int __fastcall SKILLS_SchedulePeriodicSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_PERIODIC >> 3] & gdwBitMasks[SKILLSFLAGINDEX_PERIODIC & 7] || pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
    {
        const int nExpireFrame = SKILL_ComputePeriodicRate(pGame, pUnit, pSkillsTxtRecord, nSkillId, nSkillLevel);
        if (a5)
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_PERIODICSKILLS, -1);
            EVENT_SetEvent(pGame, pUnit, EVENTTYPE_PERIODICSKILLS, nExpireFrame, -1, 0);
        }
        else
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_PERIODICSKILLS, nSkillId);
            EVENT_SetEvent(pGame, pUnit, EVENTTYPE_PERIODICSKILLS, nExpireFrame, nSkillId, nSkillLevel);
        }

        return 1;
    }

    return 0;
}

inline int I12_SummonGetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int I12_SummonGetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x0056CE70
int __fastcall SKILLS_SchedulePeriodicStat(D2GameStrc* pGame, D2UnitStrc* pUnit, int a5, int nSkillId, int nSkillLevel, int a6)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_PERIODIC >> 3] & gdwBitMasks[SKILLSFLAGINDEX_PERIODIC & 7] || pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
    {
        const int nExpireFrame = SKILL_ComputePeriodicRate(pGame, pUnit, pSkillsTxtRecord, nSkillId, nSkillLevel);
        if (a6)
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_PERIODICSKILLS, -1);
            EVENT_SetEvent(pGame, pUnit, EVENTTYPE_PERIODICSKILLS, nExpireFrame, -1, 0);
        }
        else
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_PERIODICSTATS, a5);
            EVENT_SetEvent(pGame, pUnit, EVENTTYPE_PERIODICSTATS, nExpireFrame, a5, nSkillId);
        }

        return 1;
    }

    return 0;
}

// 0x0056FC50
void __fastcall SKILLS_ExecuteUsedSkill(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (pSkill)
    {
        const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 3235);
        const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
        sub_0056F7F0(pGame, pUnit, nSkillId, nSkillLevel, 1, 0, 0);
        SKILLS_SchedulePeriodicSkill(pGame, pUnit, nSkillId, nSkillLevel, 0);
    }
}

// 0x0056D2C0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        *pX = UNITS_GetUnitXPosition(pTarget);
        *pY = UNITS_GetUnitYPosition(pTarget);
    }
    else
    {
        D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
        *pX = D2COMMON_10175_PathGetFirstPointX(pDynamicPath);
        *pY = D2COMMON_10176_PathGetFirstPointY(pDynamicPath);
    }

    return *pX && *pY;
}

// 0x0056ECB0
D2UnitStrc* __fastcall SKILLS_CreateMissileAtOffset(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity)
{
    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = nX + UNITS_GetUnitXPosition(pUnit);
    missileParams.nY = nY + UNITS_GetUnitYPosition(pUnit);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;

    if (nTargetX && nTargetY)
    {
        missileParams.nTargetX = nTargetX;
        missileParams.nTargetY = nTargetY;
    }
    else if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &missileParams.nTargetX, &missileParams.nTargetY))
    {
        return 0;
    }

    if (missileParams.nTargetX && missileParams.nTargetY)
    {
        if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            const int nToHit = STATLIST_UnitGetStatValue(pUnit, STAT_TOHIT, 0);
            if (nToHit)
            {
                missileParams.nAttBonus = nToHit;
                missileParams.dwFlags |= 0x1000;
            }
        }

        if (!bCheckItemQuantity || pUnit->dwUnitType || SKILLS_ConsumeWeaponOrAmmoQuantity(pGame, pUnit) > 0)
        {
            return MISSILES_CreateMissileFromParams(pGame, &missileParams);
        }
    }
    return 0;
}

// 0x0056EE90
D2UnitStrc* __fastcall SKILLS_CreateMissileFromOrigin(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bSkipCheck)
{
    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x420;
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nX = nX + UNITS_GetUnitXPosition(pUnit);
    missileParams.nY = nY + UNITS_GetUnitYPosition(pUnit);
    missileParams.nMissile = nMissileId;

    if (nTargetX && nTargetY)
    {
        missileParams.nTargetX = nTargetX;
        missileParams.nTargetY = nTargetY;
    }
    else if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &missileParams.nTargetX, &missileParams.nTargetY))
    {
        return 0;
    }

    if (!bSkipCheck || pUnit->dwUnitType != UNIT_PLAYER || SKILLS_ConsumeWeaponOrAmmoQuantity(pGame, pUnit) > 0)
    {
        return MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }
    return 0;
}

// 0x0056F070
int __fastcall SKILLS_SrvDo001_Attack_LeftHandSwing(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2UnitStrc* pWeapon = PLAYER_GetWeaponForSkill(pUnit);
    if (pWeapon && ITEMS_GetItemType(pWeapon) == ITEMTYPE_MISSILE_POTION)
    {
        return 0;
    }

    if (COMPOSIT_IsWeaponBowOrXBow(pUnit))
    {
        const int nItemType = D2COMMON_11039_CheckWeaponIsMissileBased(pUnit, &nSkillLevel);
        if (nItemType != ITEMTYPE_BOW)
        {
            SKILLS_CreateMissileAtOffset(pGame, nItemType, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
        }
        else
        {
            SKILLS_CreateMissileAtOffset(pGame, ITEMTYPE_BOW, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
        }
        return 1;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2DamageStrc damage = {};
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, STATLIST_UnitGetStatValue(pUnit, STAT_PROGRESSIVE_TOHIT, 0), 0);
    damage.dwHitFlags |= 2;
    sub_005D3AC0(pUnit, &damage);
    SUNITDMG_FillDamageValues(pGame, pUnit, pTarget, &damage, 0, 128);
    SKILLS_ApplyProgressiveLeechAndElementalDamage(pUnit, &damage);
    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 128);

    if (STATES_CheckStateMaskOnUnit(pUnit, 38))
    {
        return SKILLS_DrainTargetDurability(pGame, pUnit, nSkillLevel);
    }

    D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
    if (pDamage)
    {
        SKILLS_ReleaseProgressiveCharges(pGame, pUnit, pDamage);
    }

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}

// 0x0056F460
int __fastcall SKILLS_SrvDo003_Throw(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2UnitStrc* pWeapon = 0;
    int nBodyLoc;
    int bIsLeftHandItem;
    if (INVENTORY_GetEquippedWeapon(pInventory, &pWeapon, &nBodyLoc, &bIsLeftHandItem))
    {
        if (!bIsLeftHandItem)
        {
            if (nBodyLoc == 5)
            {
                pWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
            }
            else
            {
                pWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
            }
        }

        if (!ITEMS_CheckIfThrowable(pWeapon) && !STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, STAT_ITEM_THROWABLE, 0))
        {
            return 0;
        }
    }

    if (!pWeapon)
    {
        return 0;
    }

    pUnit->dwFlags |= 0x40;
    const int nMissileType = ITEMS_GetMissileType(pWeapon);

    D2UnitStrc* pMissile;
    if (ITEMSIsA(pWeapon, 38))
    {
        pMissile = SKILLS_CreateMissileFromOrigin(pGame, nMissileType, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }
    else
    {
        pMissile = SKILLS_CreateMissileAtOffset(pGame, nMissileType, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }

    SKILLS_ApplyWeaponBonusToMissile(pUnit, pMissile, pWeapon);
    return 1;
}

static inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x0056F550
int __fastcall SKILLS_SrvDo005_LeftHandThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2UnitStrc* pWeapon = 0;
    int nBodyLoc;
    int bIsLeftHandItem;
    if (INVENTORY_GetEquippedWeapon(pInventory, &pWeapon, &nBodyLoc, &bIsLeftHandItem))
    {
        if (bIsLeftHandItem)
        {
            if (nBodyLoc == 5)
            {
                pWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
            }
            else
            {
                pWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
            }
        }

        if (!ITEMS_CheckIfThrowable(pWeapon) && !STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, STAT_ITEM_THROWABLE, 0))
        {
            return 0;
        }
    }

    if (!pWeapon)
    {
        return 0;
    }

    pUnit->dwFlags |= 0x40;
    const int nMissileType = ITEMS_GetMissileType(pWeapon);

    D2UnitStrc* pMissile;
    if (ITEMSIsA(pWeapon, 38))
    {
        pMissile = SKILLS_CreateMissileFromOrigin(pGame, nMissileType, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }
    else
    {
        pMissile = SKILLS_CreateMissileAtOffset(pGame, nMissileType, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }

    SKILLS_ApplyWeaponBonusToMissile(pUnit, pMissile, pWeapon);
    return 1;
}

// 0x0056F7F0
int __fastcall SKILLS_ExecuteSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyCosts, int bSkipSkillCheck, int bItemEffect)
{
    if (!pGame || !pUnit)
    {
        return 0;
    }

    int nResult = 0;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int bLivingUnit;
    if (pUnit->dwUnitType == UNIT_PLAYER || pUnit->dwUnitType == UNIT_MONSTER)
    {
        bLivingUnit = 1;
        D2SkillStrc* pUsedSkill = UNITS_GetUsedSkill(pUnit);
        if (pUsedSkill && !(SKILLS_GetFlags(pUsedSkill) & 1) && !SKILLS_CHECK_FLAG(pSkillsTxtRecord, SKILLSFLAGINDEX_INTOWN))
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
            if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
            {
                UNITS_SetUsedSkill(pUnit, 0);

                if (pUnit->dwUnitType == UNIT_PLAYER)
                {
                    PLRMODE_ChangeModeToCoords(pGame, pUnit, 0, PLRMODE_TOWNNEUTRAL, 0, 0, 1);
                }

                return 0;
            }
        }

        if (!bSkipSkillCheck && (!pUsedSkill || SKILLS_GetSkillIdFromSkill(pUsedSkill, ".\\SKILLS\\Skills.cpp", 2887) != nSkillId || SKILLS_GetSkillLevel(pUnit, pUsedSkill, 1) <= 0))
        {
            D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
            if (!pSkill || SKILLS_GetSkillLevel(pUnit, pSkill, 1) <= 0)
            {
                return 0;
            }
        }
    }
    else
    {
        bLivingUnit = 0;
    }

    if (pSkillsTxtRecord->wSrvDoFunc < 0 || pSkillsTxtRecord->wSrvDoFunc >= 191
        || bLivingUnit && SKILLS_CHECK_FLAG(pSkillsTxtRecord, SKILLSFLAGINDEX2_USEMANAONDO) && !SKILLS_HasManaOrChargesForUsedSkill(pUnit))
    {
        return 0;
    }

    int nDoFunc = pSkillsTxtRecord->wSrvDoFunc;
    if (bItemEffect && bSkipSkillCheck && pSkillsTxtRecord->wItemEffect > 1)
    {
        nDoFunc = pSkillsTxtRecord->wItemEffect;
    }

    SKILLDOFUNC pDoFunc = gpfnSkillSrvDoFunctions[nDoFunc];
    if (pDoFunc)
    {
        nResult = pDoFunc(pGame, pUnit, nSkillId, nSkillLevel);
    }

    if (pSkillsTxtRecord->wSrvMissile >= 0 && sub_0046ACE0(pSkillsTxtRecord->wSrvMissile))
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;

        int nX = 0;
        int nY = 0;
        int nTargetX = 0;
        int nTargetY = 0;
        if (bSkipSkillCheck && bItemEffect)
        {
            D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY);
            if (nX && nY)
            {
                nTargetX = nX;
                nTargetY = nY;
                nX -= CLIENTS_GetUnitX(pUnit);
                nY -= CLIENTS_GetUnitY(pUnit);
                nTargetX += nX;
                nTargetY += nY;
            }
        }

        if (SKILLS_CHECK_FLAG(pSkillsTxtRecord, SKILLSFLAGINDEX_LOB))
        {
            SKILLS_CreateMissileFromOrigin(pGame, pSkillsTxtRecord->wSrvMissile, pUnit, nSkillId, nSkillLevel, nX, nY, nTargetX, nTargetY, 0);
        }
        else
        {
            SKILLS_CreateMissileAtOffset(pGame, pSkillsTxtRecord->wSrvMissile, pUnit, nSkillId, nSkillLevel, nX, nY, nTargetX, nTargetY, 0);
        }

        nResult = 1;
    }

    if (!nResult)
    {
        return 0;
    }

    if (bApplyCosts)
    {
        if (bLivingUnit)
        {
            if (!gpSkillSrvStartFnTable_00732140[pSkillsTxtRecord->wSrvStartFunc] || SKILLS_CHECK_FLAG(pSkillsTxtRecord, SKILLSFLAGINDEX2_USEMANAONDO))
            {
                SKILLS_ConsumeSkillMana(pGame, pUnit, nSkillId, nSkillLevel);
            }

            if (SKILLS_CHECK_FLAG(pSkillsTxtRecord, SKILLSFLAGINDEX_DECQUANT))
            {
                SKILLS_ConsumeWeaponOrAmmoQuantity(pGame, pUnit);
            }
        }

        const int nDelay = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwDelay, nSkillId, nSkillLevel);
        if (nDelay > 0 && pUnit->dwUnitType == UNIT_PLAYER)
        {
            if (pSkillsTxtRecord->nAnim == PLRMODE_SEQUENCE)
            {
                if (!(pUnit->dwSeqFrame & 0xFFFFFF00))
                {
                    D2GAME_SKILLS_SetDelay_6FD11C00(pGame, pUnit, nDelay);
                }
            }
            else
            {
                D2GAME_SKILLS_SetDelay_6FD11C00(pGame, pUnit, nDelay);
            }
        }
    }

    return nResult;
}

// 0x0056FCB0
void __fastcall SKILLS_EventCallback_PeriodicSkillAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillIdArg, int a4)
{
    if (nSkillIdArg == -1)
    {
        D2SkillStrc* pSkill = UNITS_GetRightSkill(pUnit);
        if (pSkill)
        {
            const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 0xCBB);
            const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
            D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
            if (pSkillsTxtRecord && pSkillsTxtRecord->nFlags[5 >> 3] & gdwBitMasks[5 & 7] && !SUNIT_IsDead(pUnit))
            {
                sub_0056F7F0(pGame, pUnit, nSkillId, nSkillLevel, 1, 0, 0);
                SKILLS_SchedulePeriodicSkill(pGame, pUnit, nSkillId, nSkillLevel, 1);
                return;
            }
        }

        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 8, -1);
    }
    else if (nSkillIdArg > 0)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillIdArg);
        if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 8, nSkillIdArg);
            return;
        }

        if (!STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 8, nSkillIdArg);
            return;
        }

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
        if (!pStatList)
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 8, nSkillIdArg);
            return;
        }

        const int nSkillLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
        if (SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillIdArg) && nSkillIdArg == STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0))
        {
            sub_0056F7F0(pGame, pUnit, nSkillIdArg, nSkillLevel, 1, 0, 0);
            SKILLS_SchedulePeriodicSkill(pGame, pUnit, nSkillIdArg, nSkillLevel, 0);
        }
        else
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 8, nSkillIdArg);
        }
    }
}

// 0x0056FE40
void __fastcall SKILLS_EventCallback_ItemAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 9, a3);
        return;
    }

    if (SUNIT_IsDead(pUnit))
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 9, a3);
        return;
    }

    const int nAura = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_AURA, nSkillId);
    if (nAura <= 0)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 9, a3);
        return;
    }

    sub_0056F7F0(pGame, pUnit, nSkillId, nAura, 1, 1, 0);
    SKILLS_SchedulePeriodicStat(pGame, pUnit, a3, nSkillId, nAura, 0);
}

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x0056FF10
static void __stdcall SKILLS_StartAssignedAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord && pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
    {
        if (pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
        {
            D2SkillStrc* pHighestLevelSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
            if (pHighestLevelSkill)
            {
                const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pHighestLevelSkill, 1);
                if (nSkillLevel > 0)
                {
                    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_IMMEDIATE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_IMMEDIATE & 7])
                    {
                        sub_0056F7F0(pGame, pUnit, nSkillId, nSkillLevel, 1, 0, 0);
                    }
                    else
                    {
                        STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);

                        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
                        if (!pStatList)
                        {
                            pStatList = STATLIST_AllocStatList(!pUnit ? 0 : pUnit->pMemoryPool, 0, 0, !pUnit ? UNIT_INVALID : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
                        }

                        if (pStatList)
                        {
                            STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
                            STATLIST_SetSkillId(pStatList, nSkillId);
                            STATLIST_SetSkillLevel(pStatList, nSkillLevel);
                            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
                            STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
                            STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);
                        }
                    }

                    SKILLS_SchedulePeriodicSkill(pGame, pUnit, nSkillId, nSkillLevel, 1);
                }
            }
        }
    }
}

// 0x00570080
int __fastcall SKILLS_TryIncreaseSkillLevel(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        int nRequiredSkillPoints = 1;
        if (pSkillsTxtRecord->dwSkPoints != -1)
        {
            int nSkillLevel = 0;

            D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
            if (pSkill)
            {
                nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
            }

            nRequiredSkillPoints = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwSkPoints, nSkillId, nSkillLevel);
        }

        if (STATLIST_GetUnitBaseStat(pUnit, STAT_SKILLPTS, 0) >= nRequiredSkillPoints)
        {
            STATLIST_AddUnitStat(pUnit, STAT_SKILLPTS, -nRequiredSkillPoints, 0);

            D2SkillStrc* pSkill = SKILLS_AddSkill(pUnit, nSkillId);
            SKILLS_RefreshPassiveSkills(pUnit);

            if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
            {
                PLAYERPETS_UpdatePetLimits(SUNIT_GetGameFromUnit(pUnit), pUnit);
            }

            if (!pSkill)
            {
                STATLIST_AddUnitStat(pUnit, STAT_SKILLPTS, nRequiredSkillPoints, 0);
            }
            else
            {
                const int nLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 0);
                D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(UnitGetClient(pUnit, ".\\SKILLS\\Skills.cpp", 3443), pUnit, nSkillId, nLevel, 0);

                const int nPassiveState = SKILLS_GetPassiveState(nSkillId);
                if (nPassiveState)
                {
                    STATES_ToggleState(pUnit, nPassiveState, 1);
                }

                SKILLS_RefreshSkill(pUnit, nSkillId);
                return 1;
            }
        }
    }

    return 0;
}

// 0x0056CF40
D2UnitStrc* __fastcall D2GAME_CreateLinkPortal_6FD13B20(D2GameStrc* pGame, int nUnused, D2UnitStrc* pPortal, int nDestLevel, int nSourceLevel)
{
    const unsigned char nAct = DRLG_GetActNoFromLevelId(nDestLevel);
    int nX;
    int nY;
    D2ActiveRoomStrc* pRoom = DUNGEON_FindActSpawnLocationEx(pGame->pAct[nAct], nDestLevel, 11, &nX, &nY, 3);
    D2ActiveRoomStrc* pDestinationRoom = pRoom;

    sub_6FC385A0(pGame, pRoom);

    if (!pRoom)
    {
        DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pPortal), 2, !pPortal ? -1 : pPortal->dwUnitId);
        SUNIT_RemoveUnit(pGame, pPortal);
        return 0;
    }

    D2CoordStrc coords;
    coords.nX = nX;
    coords.nY = nY;

    if (QUESTS_PortalCheck(pGame, &coords, nSourceLevel, &pRoom))
    {
        pRoom = sub_00463740_FindRoomAtPoint(pRoom, coords.nX, coords.nY);
    }

    if (!pRoom)
    {
        pRoom = pDestinationRoom;
        coords.nX = nX;
        coords.nY = nY;
    }

    pRoom = COLLISION_GetFreeCoordinatesEx(pRoom, &coords, 3, 0xBE11u, 5);
    if (!pRoom)
    {
        pRoom = DUNGEON_FindActSpawnLocationEx(pGame->pAct[nAct], nDestLevel, 11, &nX, &nY, 3);
        if (!pRoom)
        {
            pRoom = pDestinationRoom;
            D2_ASSERT(pDestinationRoom, 0xE08);
        }
    }

    nX = coords.nX;
    nY = coords.nY;

    D2UnitStrc* pLinkPortal = SUNIT_AllocUnitData(2, !pPortal ? -1 : pPortal->dwClassId, coords.nX, coords.nY, pGame, pRoom, 1, 2, 0);
    if (!pLinkPortal)
    {
        DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pPortal), 2, !pPortal ? -1 : pPortal->dwUnitId);
        SUNIT_RemoveUnit(pGame, pPortal);
        return 0;
    }

    const int eLevelIdLocal = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPortal));
    D2_ASSERT(eLevelIdLocal <= 255, 0xE2B);

    pLinkPortal->pObjectData->InteractType = eLevelIdLocal;
    const unsigned char nPortalFlags = UNITS_GetObjectPortalFlags(pLinkPortal) | 3;
    UNITS_SetObjectPortalFlags(pLinkPortal, nPortalFlags);
    UNITS_ChangeAnimMode(pLinkPortal, 2);
    SUNIT_LinkPortalCoordinates(pPortal, pLinkPortal);
    UNITS_StoreOwner(pPortal, pLinkPortal);
    UNITS_StoreOwner(pLinkPortal, pPortal);

    return pLinkPortal;
}

// 0x0056D130
int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* hRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm)
{
    D2_ASSERT(hRoom, 0xE42);

    if (ppSourceUnit)
    {
        *ppSourceUnit = 0;
    }

    if (pUnit && DUNGEON_IsRoomInTown(hRoom))
    {
        if ((nDestLevel != LEVEL_MOOMOOFARM && nDestLevel != LEVEL_PANDEMONIUMFINALE && nDestLevel != LEVEL_PANDEMONIUMRUN1 && nDestLevel != LEVEL_PANDEMONIUMRUN2 && nDestLevel != LEVEL_PANDEMONIUMRUN3) || nObjectId != OBJECT_PERMANENT_TOWN_PORTAL)
        {
            SUNIT_AttachSound(pUnit, 0x18, pUnit);
            return 0;
        }
    }

    const unsigned char bAct = DRLG_GetActNoFromLevelId(nDestLevel);
    const int nSourceLevel = DUNGEON_GetLevelIdFromRoom(hRoom);

    D2_ASSERT(bAct == DRLG_GetActNoFromLevelId(nSourceLevel), 0xE5C);

    D2CoordStrc coords;
    coords.nX = nX;
    coords.nY = nY;

    if (!bPerm)
    {
        if (!COLLISION_GetFreeCoordinatesWithField(hRoom, &coords, &coords, 3, 0x3E01, 0xC01, 0))
        {
            return 0;
        }
    }

    const int nTargetX = coords.nX;
    const int nTargetY = coords.nY;

    D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtPoint(hRoom, nTargetX, nTargetY);
    if (!pTargetRoom)
    {
        return 0;
    }

    D2UnitStrc* pPortal = SUNIT_AllocUnitData(2, nObjectId, nTargetX, nTargetY, pGame, pTargetRoom, 1, 1, 0);
    if (ppSourceUnit)
    {
        *ppSourceUnit = pPortal;
    }

    UNITS_ChangeAnimMode(pPortal, 1);

    D2UnitStrc* pLinkPortal = D2GAME_CreateLinkPortal_6FD13B20(pGame, pUnit, pPortal, nDestLevel, nSourceLevel);
    if (!pLinkPortal)
    {
        return 0;
    }

    D2PortalFlagsStrc portalFlags;
    portalFlags.nFlags = UNITS_GetObjectPortalFlags(pLinkPortal) | 3;
    UNITS_SetObjectPortalFlags(pLinkPortal, portalFlags.nFlags);
    DUNGEON_ToggleHasPortalFlag(pTargetRoom, 0);
    DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pLinkPortal), 0);
    return 1;
}

// 0x0056D370
void __fastcall SKILLS_EnlargeVector(int* pX, int* pY)
{
    int nDistance = *pX * *pX + *pY * *pY;
    if (nDistance < 4)
    {
        *pX <<= 2;
        *pY <<= 2;
        nDistance = *pX * *pX + *pY * *pY;
    }

    if (nDistance < 16)
    {
        *pX <<= 1;
        *pY <<= 1;
    }
}

// 0x0056D3B0
void __fastcall SKILLS_MakeShortPerpendicularVector(int* pX, int* pY)
{
    int nX = *pY;
    int nY = -*pX;
    while (nX * nX + nY * nY > 3)
    {
        nX /= 2;
        nY /= 2;
    }

    *pX = nX;
    *pY = nY;
}

// 0x0056D400
void __fastcall SKILLS_CreateMissileRing(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* a3, int nMissileId, int nSkillId, int nSkillLevel, int nVelocity)
{
    static const int xOffsets[64] = // 0x006E1288
    {
        30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2, 0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24,
        -26, -27, -28, -29, -29, -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2, 0, 2, 5,
        8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29
    };

    static const int yOffsets[64] = // 0x006E1388
    {
        0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29, 30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11,
        8, 5, 2, 0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29, -30, -29, -29, -28, -27,
        -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2
    };

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 3;
    missileParams.nX = CLIENTS_GetUnitXInline(a3);
    missileParams.nY = CLIENTS_GetUnitYInline(a3);
    missileParams.nMissile = nMissileId;
    missileParams.pOwner = pOwner;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;

    if (nVelocity)
    {
        missileParams.nVelocity = nVelocity;
        missileParams.dwFlags |= 4;
    }

    for (int i = 0; i < 64; ++i)
    {
        missileParams.nTargetX = xOffsets[i];
        missileParams.nTargetY = yOffsets[i];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }
}

// 0x0056D4E0
void __fastcall SKILLS_CreateMissilePattern(D2GameStrc* pGame, int nMissiles, D2MissileStrc* pMissileParams)
{
    D2_ASSERT((nMissiles - 1) / 5 <= 7, 0xF0D);

    pMissileParams->nTargetX = 14;
    pMissileParams->nTargetY = -14;
    MISSILES_CreateMissileFromParams(pGame, pMissileParams);

    int nSubMissiles = nMissiles - 1;
    for (int j = 0; j < 7 && nSubMissiles; ++j)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (nSubMissiles <= 0)
            {
                break;
            }

            pMissileParams->nTargetX = gnMissilePatternOffsets1[j] * gnMissilePatternSignX[i];
            pMissileParams->nTargetY = gnMissilePatternOffsets2[j] * gnMissilePatternSignY[i];
            MISSILES_CreateMissileFromParams(pGame, pMissileParams);

            pMissileParams->nTargetX = gnMissilePatternOffsets2[j] * gnMissilePatternSignX[i];
            pMissileParams->nTargetY = gnMissilePatternOffsets1[j] * gnMissilePatternSignY[i];
            MISSILES_CreateMissileFromParams(pGame, pMissileParams);
            nSubMissiles -= 2;
        }

        pMissileParams->nTargetX = gnMissilePatternXOffsets[j];
        pMissileParams->nTargetY = gnMissilePatternYOffsets[j];
        MISSILES_CreateMissileFromParams(pGame, pMissileParams);
        nSubMissiles -= 1;
    }
}

// 0x0056D5F0
int __fastcall SKILLS_SpawnItemInFreeHand(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pRightArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
        D2UnitStrc* pLeftArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
        int nBodyLoc;
        int bEquip = 0;
        if (!pRightArmItem && !pLeftArmItem)
        {
            nBodyLoc = BODYLOC_RARM;
            bEquip = 1;
        }
        else if (!pRightArmItem && pLeftArmItem && !ITEMS_CheckWeaponIfTwoHanded(pLeftArmItem) && !ITEMSIsA(pLeftArmItem, ITEMTYPE_WEAPON))
        {
            nBodyLoc = BODYLOC_RARM;
            bEquip = 1;
        }
        else if (!pLeftArmItem && pRightArmItem && !ITEMS_CheckWeaponIfTwoHanded(pRightArmItem) && !ITEMSIsA(pRightArmItem, ITEMTYPE_WEAPON))
        {
            nBodyLoc = BODYLOC_LARM;
            bEquip = 1;
        }

        if (bEquip)
        {
            D2ItemDropStrc itemDrop;
            memset(&itemDrop, 0, sizeof(itemDrop));
            itemDrop.pUnit = pUnit;
            itemDrop.pGame = pGame;
            itemDrop.wItemFormat = pGame->wItemFormat;
            itemDrop.nId = DATATBLS_GetItemIdFromItemCode(dwItemCode);
            D2_ASSERT(itemDrop.nId != -1, 0xF4C);

            itemDrop.nSpawnType = 4;
            itemDrop.nX = 0;
            itemDrop.nY = 0;
            itemDrop.pRoom = 0;
            itemDrop.wUnitInitFlags = 1;
            itemDrop.nQuality = 2;
            itemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pUnit, 0);

            D2UnitStrc* pNewItem = D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
            D2_ASSERT(pNewItem, 0xF55);

            {
                int nUnused;
                ITEMMODE_EquipCursorItem(pGame, pUnit, pNewItem->dwUnitId, nBodyLoc, 0, &nUnused);
            }
            return 1;
        }
    }

    return 0;
}

// 0x0056D790
void __fastcall SKILLS_EventCallback_ActiveState(D2GameStrc* game, D2UnitStrc* unit, int skill, int level)
{
    if (skill <= 0)
        return;
    if (skill >= sgptDataTables->nSkillsTxtRecordCount)
        return;
    D2SkillsTxt* record = &sgptDataTables->pSkillsTxt[skill];
    if (!record)
        return;
    const short state = record->nAuraState;
    if (state < 0)
        return;
    if (state >= sgptDataTables->nStatesTxtRecordCount)
        return;
    D2StatesTxt* states = GAME_GetStatesTxtRecord(state);
    if (!states)
        return;
    SkillCallback callback = GetSkillCallback(states->callback);
    if (!callback)
        return;
    callback(game, unit, skill, level);
}

// 0x0056D810
void __fastcall SKILLS_ExecuteServerDoFunction(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDoFunc, int nSkillId, int nSkillLevel)
{
    if (nDoFunc >= 0 && nDoFunc < SKILLSRVDOFN_COUNT && gpfnSkillSrvDoFunctions[nDoFunc])
    {
        gpfnSkillSrvDoFunctions[nDoFunc](pGame, pUnit, nSkillId, nSkillLevel);
    }
}

// 0x0056D840
static void SKILLS_RemoveTrackedSummon(D2GameStrc* pGame, D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 4008);

    D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, SUNIT_GetTrackedSummonGUID(hUnit));
    if (pPet)
    {
        if (UNITS_HasBeenDeletedInline(pPet))
        {
            SUNIT_RemoveUnit(pGame, pPet);
            SUNIT_SetTrackedSummonGUID(hUnit, -1);
            return;
        }

        pPet->dwFlags |= 0x4000000u;

        SUNITDMG_KillMonster(pGame, pPet, hUnit, 1);
    }

    SUNIT_SetTrackedSummonGUID(hUnit, -1);
}

// 0x0056D8D0
static void __stdcall SKILLS_RegisterSummonedPet(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg, D2UnitStrc* pPet)
{
    if (!(pSummonArg->dwFlags & 8) && pPet)
    {
        pPet->dwFlags |= UNITFLAG_ISREVIVE;
    }

    if (pSummonArg->dwFlags & 2)
    {
        SKILLS_RemoveTrackedSummon(pGame, pSummonArg->pOwner);
        SUNIT_SetTrackedSummonGUID(pSummonArg->pOwner, !pPet ? -1 : pPet->dwUnitId);
    }

    int nPetMax = pSummonArg->nPetMax;
    if (nPetMax < 1)
    {
        nPetMax = 1;
    }
    sub_6FC7D7A0(pGame, pSummonArg->pOwner, pPet, pSummonArg->nPetType, nPetMax);
}

// 0x0056D940
D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg)
{
    int nX;
    int nY;
    if (pSummonArg->dwFlags & 1)
    {
        nX = pSummonArg->pPosition.nX;
        nY = pSummonArg->pPosition.nY;
    }
    else
    {
        D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pSummonArg->pOwner, &nX, &nY);
    }

    D2ActiveRoomStrc* pOwnerRoom = UNITS_GetRoom(pSummonArg->pOwner);
    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(pOwnerRoom, nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    D2UnitStrc* hPet = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, pSummonArg->nHcIdx, pSummonArg->nMonMode, -1, 66);
    if (!hPet)
    {
        if (pSummonArg->dwFlags & 4)
        {
            return 0;
        }

        hPet = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, pSummonArg->nHcIdx, pSummonArg->nMonMode, 4, 66);
        if (!hPet)
        {
            return 0;
        }
    }

    SKILLS_RegisterSummonedPet(pGame, pSummonArg, hPet);

    if (hPet)
    {
        hPet->dwFlags |= UNITFLAG_NOTC;
    }

    D2UnitStrc* pOwner = pSummonArg->pOwner;
    int nOwnerType = UNIT_INVALID;
    if (pOwner)
    {
        nOwnerType = pOwner->dwUnitType;
    }
    AIGENERAL_SetOwnerData(pGame, hPet, !pOwner ? -1 : pOwner->dwUnitId, nOwnerType, 0, 0);

    D2_ASSERT(!STATES_CheckState(hPet, STATE_UNINTERRUPTABLE), 4108);

    AITHINK_ExecuteAiFn(pGame, hPet, AIGENERAL_GetAiControlFromUnit(hPet), pSummonArg->nAiSpecialState);
    MONSTER_UpdateAiCallbackEvent(pGame, hPet);
    D2GAME_EVENTS_Delete_6FC34840(pGame, hPet, EVENTTYPE_AITHINK, 0);
    EVENT_SetEvent(pGame, hPet, EVENTTYPE_AITHINK, pGame->dwGameFrame + 25, 0, 0);

    return hPet;
}

// 0x0056DAB0
D2UnitStrc* __fastcall OBJMODE_DropItemWithCodeAndQuality(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwCode, int nItemQuality)
{
    const int nItemId = DATATBLS_GetItemIdFromItemCode(dwCode);
    if (nItemId != -1)
    {
        D2CoordStrc pCoord;
        UNITS_GetCoords(pUnit, &pCoord);

        D2CoordStrc pReturnCoords;
        D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pUnit), &pCoord, &pReturnCoords, 1, 1);
        if (pRoom)
        {
            D2ItemDropStrc itemDrop = {};
            itemDrop.pUnit = pUnit;
            itemDrop.pSeed = 0;
            itemDrop.pGame = pGame;
            itemDrop.nSpawnType = ITEMSPAWN_GROUND;
            itemDrop.wItemFormat = pGame->wItemFormat;
            itemDrop.nId = nItemId;
            itemDrop.nX = pReturnCoords.nX;
            itemDrop.nY = pReturnCoords.nY;
            itemDrop.nQuality = nItemQuality;
            itemDrop.pRoom = pRoom;
            itemDrop.wUnitInitFlags = 1;
            itemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pUnit, 0);

            return D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
        }
    }

    return 0;
}

// 0x0056DBC0
void __fastcall SKILLS_ApplyCurseAroundTarget(D2GameStrc* pGame, int nFlags, D2UnitStrc* pUnit, int nSkillLevel, int nRange, CurseCallbackFunc pfCurse)
{
    D2_ASSERT(pfCurse, 0x1047);
    int nX;
    int nY;
    if (D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        D2UnitFindArgStrc findArg = {};
        findArg.nFlags = nFlags;
        findArg.pUnit = pUnit;
        findArg.nX = nX;
        findArg.nY = nY;
        findArg.nSize = nRange;
        D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
        if (pRoom)
        {
            D2UnitFindDataStrc findData;
            UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, &findData, pRoom, nX, nY, nRange, 0, &findArg);
            UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&findData);
            D2_ASSERT(!IsBadCodePtr((FARPROC)pfCurse), 0x1061);
            for (int i = 0; i < findData.nIndex; ++i)
                pfCurse(pGame, pUnit, findData.pUnitsArray[i], nSkillLevel);
            UNITFINDS_FreeUnitFindData(&findData);
        }
    }
}

// 0x0056DCC0
void __fastcall SKILLS_ApplyAreaEffect(D2GameStrc* pGame, D2EffectStrc* pEffect)
{
    D2_ASSERT(pEffect, 4280);
    D2_ASSERT(pEffect->pfAreaEffect, 4281);

    int nParam = pEffect->nParam;
    if (!nParam)
    {
        nParam = SKILLDESC_GetSkillParamByLevel(pEffect->nSkillId, pEffect->nSkillLevel);
    }

    D2UnitFindArgStrc unitFindArg = {};
    unitFindArg.nFlags = pEffect->nFlags;
    unitFindArg.pUnit = pEffect->pUnit;
    unitFindArg.nX = pEffect->nX;
    unitFindArg.nY = pEffect->nY;
    unitFindArg.nSize = nParam;

    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pEffect->pUnit), pEffect->nX, pEffect->nY);
    if (pRoom)
    {
        D2UnitFindDataStrc unitFindData;
        UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, &unitFindData, pRoom, pEffect->nX, pEffect->nY, nParam, 0, &unitFindArg);
        unitFindData.nFlags = pEffect->nFlags;
        UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&unitFindData);

        D2_ASSERT(!IsBadCodePtr((FARPROC)pEffect->pfAreaEffect), 4315);

        for (int i = 0; i < unitFindData.nIndex; ++i)
        {
            ((SKILLS_AREAEFFECTFN)pEffect->pfAreaEffect)(pGame, pEffect->pUnit, unitFindData.pUnitsArray[i], pEffect->nSkillLevel, pEffect->unk0x1C);
        }

        UNITFINDS_FreeUnitFindData(&unitFindData);
    }
}

struct D2Unk0056DCC0Strc;

struct D2Unk0056DCC0Strc
{
    int nUnk0x00;
    int nUnk0x04;
    int nUnk0x08;
    int f_C;
    int f_10;
    int nUnk0x14;
    int nUnk0x18;
    int nUnk0x1C;
    void* pUnk0x20;
};

void __fastcall sub_0056DCC0(D2GameStrc* pGame, D2Unk0056DCC0Strc* pRecord); // 0x0056DCC0

// 0x0056DDE0
void __fastcall SKILLS_ApplyAreaEffectAtCoordinates(D2GameStrc* pGame, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, void* pArg8)
{
    D2Unk0056DCC0Strc record = {};
    record.nUnk0x00 = nArg2;
    record.f_C = nArg3;
    record.f_10 = nArg4;
    record.nUnk0x04 = nArg5;
    record.nUnk0x08 = nArg6;
    record.nUnk0x18 = nArg7;
    record.pUnk0x20 = pArg8;
    sub_0056DCC0(pGame, &record);
}

// 0x0056DFA0
void __fastcall D2GAME_RefreshPassiveSkills_6FD14CC0(D2UnitStrc* pUnit)
{
    if (pUnit->pSkills)
    {
        for (D2SkillStrc* i = SKILLS_GetFirstSkillFromSkillList(pUnit->pSkills); i; i = SKILLS_GetNextSkill(i))
        {
            const int nSkillId = SKILLS_GetSkillIdFromSkill(i, ".\\SKILLS\\Skills.cpp", 0x1153);
            const int nPassiveState = SKILLS_GetPassiveState(nSkillId);
            if (nPassiveState > 0)
            {
                STATES_ToggleState(pUnit, nPassiveState, 1);
                SKILLS_RefreshSkill(pUnit, nSkillId);
            }
        }
    }
}

// 0x0056E000
static void __stdcall SKILLS_FillMonSkillInfo(D2UnitStrc* pOwner, int nSkillId, D2MonSkillInfoStrc* pMonSkillInfo)
{
    const int nSkillLevel = SKILLS_GetHighestSkillLevelById(pOwner, nSkillId);
    pMonSkillInfo->nMinDamage = SKILLS_GetMinPhysDamage(pOwner, nSkillId, nSkillLevel, 1) >> 8;
    pMonSkillInfo->nMaxDamage = SKILLS_GetMaxPhysDamage(pOwner, nSkillId, nSkillLevel, 1) >> 8;
    pMonSkillInfo->nToHit = SKILLS_GetToHitFactor(pOwner, nSkillId, nSkillLevel);
}

// 0x0056E050
void __fastcall SKILLS_FillMinionSkillDamage(D2UnitStrc* pUnit, int nUnused, D2MonSkillInfoStrc* pMonSkillInfo)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (pOwner)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
            if (pMonStatsTxtRecord && pMonStatsTxtRecord->wSkillDamage > 0 && pMonStatsTxtRecord->wSkillDamage <= sgptDataTables->nSkillsTxtRecordCount)
            {
                SKILLS_FillMonSkillInfo(pOwner, pMonStatsTxtRecord->wSkillDamage, pMonSkillInfo);
            }
        }
    }
}

inline D2StatesTxt* DATATBLS_GetStatesTxtRecord(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
        return &sgptDataTables->pStatesTxt[nState];
    return 0;
}

// 0x0056E970
D2StatListStrc* __fastcall SKILLS_ApplyStateEffect(D2CurseStrc* pCurse)
{
    D2UnitStrc* pTarget = pCurse->pTarget;
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pTarget);
    const int nState = pCurse->nState;
    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecord(nState);
    if (!pStatesTxtRecord)
        return 0;
    if (pTarget && pTarget->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = 0;
        if (pTarget->dwClassId >= 0 && pTarget->dwClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[pTarget->dwClassId];
        }
        if (!pMonStatsTxtRecord || (pMonStatsTxtRecord->nMonStatsFlags[1] & (unsigned char)gdwBitMasks[0]))
            return 0;
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pTarget->dwClassId);
        if (!pMonStats2TxtRecord || !(pMonStats2TxtRecord->nFlags[1] & (unsigned char)gdwBitMasks[1]))
            return 0;
    }
    const int bCurse = STATES_CheckStateMaskCurseByStateId(nState);
    if (bCurse)
    {
        const int nResistance = STATLIST_UnitGetStatValue(pTarget, STAT_CURSE_RESISTANCE, 0);
        if (nResistance >= 100)
            return 0;
        if (nResistance)
        {
            const int nDuration = pCurse->nDuration;
            pCurse->nDuration = nDuration - DATATBLS_ApplyRatio(nDuration, nResistance, 100);
        }
        if (STATES_CheckState(pTarget, STATE_ATTRACT))
            return 0;
    }
    unsigned int nFlags = 0;
    D2StatListStrc* pStatList;
    if (bCurse)
    {
        nFlags = 0x20;
        pStatList = STATLIST_GetStatListFromUnitAndFlag(pTarget, 0x20);
    }
    else
        pStatList = STATLIST_GetStatListFromUnitAndState(pTarget, nState);
    if (pStatList)
    {
        if (STATLIST_GetState(pStatList) == pCurse->nState && pCurse->nSkill == (int)STATLIST_GetSkillId(pStatList))
        {
            const int nSkillLevel = STATLIST_GetSkillLevel(pStatList);
            if (pCurse->nSkillLevel == nSkillLevel)
            {
                if (pCurse->nDuration)
                {
                    const int nExpireFrame = pGame->dwGameFrame + pCurse->nDuration;
                    STATLIST_SetExpireFrame(pStatList, nExpireFrame);
                    EVENT_SetEvent(pGame, pTarget, 12, nExpireFrame, 0, 0);
                }
                return pStatList;
            }
            if (pCurse->nSkillLevel < nSkillLevel)
                return 0;
        }
        D2Common_10474(pTarget, pStatList);
        STATLIST_FreeStatList(pStatList);
    }
    UNITROOM_RefreshUnit(pTarget);
    STATES_ToggleState(pTarget, nState, 1);
    int nExpireFrame = 0;
    if (pCurse->nDuration)
    {
        nExpireFrame = pGame->dwGameFrame + pCurse->nDuration;
        nFlags |= 2;
        EVENT_SetEvent(pGame, pCurse->pTarget, 12, nExpireFrame, 0, 0);
    }
    if (STATES_CheckStateMaskExpByStateId(nState))
        nFlags |= 0x800;
    if (pStatesTxtRecord->nStateFlags[0] & (unsigned char)gdwBitMasks[1])
        nFlags |= 8;
    pStatList = STATLIST_AllocStatList(!pTarget ? 0 : pTarget->pMemoryPool, nFlags, nExpireFrame, !pCurse->pUnit ? 6 : pCurse->pUnit->dwUnitType, !pCurse->pUnit ? -1 : pCurse->pUnit->dwUnitId);
    STATLIST_SetState(pStatList, nState);
    STATLIST_SetSkillId(pStatList, pCurse->nSkill);
    STATLIST_SetSkillLevel(pStatList, pCurse->nSkillLevel);
    if (pCurse->nStat != -1)
        STATLIST_SetStat(pStatList, pCurse->nStat, pCurse->nStatValue, 0);
    D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
    if (!pCurse->pStateRemoveCallback)
    {
        STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRefreshPassives);
        return pStatList;
    }
    STATLIST_SetStatRemoveCallback(pStatList, pCurse->pStateRemoveCallback);
    return pStatList;
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecordForceInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x0056EBE0
void __fastcall SKILLS_ApplyStateFromSkillParams(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, int nStatId, int nState, StatListRemoveCallback pfRemoveStatCallback)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordForceInline(nSkillId);

    D2CurseStrc tCurse = {};
    tCurse.pUnit = pUnit;
    tCurse.nDuration = pSkillsTxtRecord->dwParam[1] * nSkillLevel;
    tCurse.nSkillLevel = nSkillLevel;
    tCurse.pTarget = pTarget;
    tCurse.nStatValue = (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[2] + pSkillsTxtRecord->dwParam[0];
    tCurse.nSkill = nSkillId;
    tCurse.nStat = nStatId;
    tCurse.nState = nState;
    tCurse.pStateRemoveCallback = pfRemoveStatCallback;
    D2_ASSERT(!pfRemoveStatCallback || !IsBadCodePtr((FARPROC)pfRemoveStatCallback), 0x52B);
    SKILLS_ApplyStateEffect(&tCurse);
}

// 0x0056F640
int __fastcall SKILLS_StartSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bSkipMana)
{
    if (!pGame || !pUnit || !UNITS_GetRoom(pUnit))
        return 0;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordForceInline(nSkillId);
    if (!pSkillsTxtRecord)
        return 0;
    if (!bSkipMana && !SKILLS_HasManaOrChargesForUsedSkill(pUnit))
        return 0;
    if (!(pSkillsTxtRecord->nFlags[1] & gdwBitMasks[0]))
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
        {
            UNITS_SetUsedSkill(pUnit, 0);
            if ((!pUnit ? 6 : pUnit->dwUnitType) == 0)
                PLRMODE_ChangeModeToCoords(pGame, pUnit, 0, 5, 0, 0, 1);
            return 0;
        }
    }
    int nX;
    int nY;
    if (pSkillsTxtRecord->nLineOfSight && D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        int nCollisionMask;
        switch (pSkillsTxtRecord->nLineOfSight)
        {
        case 1: nCollisionMask = 4; break;
        case 2: nCollisionMask = 0x1C09; break;
        case 3: nCollisionMask = 0x180; break;
        case 4: nCollisionMask = 0x804; break;
        case 5: nCollisionMask = 0x805; break;
        default: return 0;
        }
        if (!D2Common_11026(nX, nY, pUnit, nCollisionMask))
            return 0;
    }
    if (pSkillsTxtRecord->wSrvStartFunc < 0 || pSkillsTxtRecord->wSrvStartFunc >= 91)
        return 0;
    SkillStartFunc pStart = gpfnSkillSrvStartFunctions[pSkillsTxtRecord->wSrvStartFunc];
    int nResult;
    if (!pStart)
    {
        nResult = 1;
    }
    else
    {
        nResult = pStart(pGame, pUnit, nSkillId, nSkillLevel);
        if (nResult && !(pSkillsTxtRecord->nFlags[4] & gdwBitMasks[5]) && !bSkipMana)
            SKILLS_ConsumeSkillMana(pGame, pUnit, nSkillId, nSkillLevel);
    }
    if (nResult && (pSkillsTxtRecord->nFlags[0] & gdwBitMasks[6]))
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 8, 0);
    return nResult;
}

// 0x005701B0
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags)
{
    if (nSkillId == SKILL_LEFTHANDSWING)
    {
        return;
    }

    if (!a2 && STATES_CheckState(pUnit, STATE_NOMANAREGEN))
    {
        STATES_ToggleState(pUnit, STATE_NOMANAREGEN, 0);
    }

    D2SkillStrc* pSkill = sub_006439B0_SkillFindByOwner(pUnit, nSkillId, nFlags);
    if (!pSkill)
    {
        return;
    }

    D2SkillStrc* pRightSkill = 0;
    if (a2)
    {
        SKILLS_SetLeftActiveSkill(pUnit, nSkillId, nFlags);
    }
    else
    {
        pRightSkill = UNITS_GetRightSkill(pUnit);
        SKILLS_SetRightActiveSkill(pUnit, nSkillId, nFlags);
    }

    nFlags = -1;
    SKILLS_GetSkillInfo(pSkill, &nFlags, 0, 0, 0);
    if ((!pUnit ? UNIT_INVALID : pUnit->dwUnitType) == UNIT_PLAYER)
    {
        D2GAME_PACKETS_SendPacket0x23_6FC3DC60(UnitGetClient(pUnit, &gszSkillsSourceFile, 3499), (!pUnit ? UNIT_INVALID : pUnit->dwUnitType), !pUnit ? -1 : pUnit->dwUnitId, a2, nSkillId, nFlags);
    }

    if (!a2)
    {
        if (pRightSkill)
        {
            D2SkillsTxt* pRightSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pRightSkill, &gszSkillsSourceFile, 3507));
            if (pRightSkillsTxtRecord && pRightSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
            {
                if (pRightSkillsTxtRecord->nAuraState >= 0 || pRightSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
                {
                    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pRightSkillsTxtRecord->nAuraState);
                    if (pStatList)
                    {
                        D2Common_10474(pUnit, pStatList);
                        STATLIST_FreeStatList(pStatList);
                    }

                    STATES_ToggleState(pUnit, pRightSkillsTxtRecord->nAuraState, 0);
                }

                D2GAME_EVENTS_Delete_6FC34840(SUNIT_GetGameFromUnit(pUnit), pUnit, EVENTTYPE_PERIODICSKILLS, -1);
            }
        }

        if (SKILLS_GetSkillsTxtRecordForceInline(nSkillId)->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
        {
            SKILLS_StartAssignedAura(SUNIT_GetGameFromUnit(pUnit), pUnit, nSkillId);
        }
    }
}

// 0x0056E0C0
int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
        return 0;

    const int nLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 1);
    const int nMinDamage = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    const int nMaxDamage = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    const int nDamage = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMaxDamage - nMinDamage) + nMinDamage;
    SKILLS_AddElementalDamage(pUnit, pDamage, pSkillsTxtRecord->nEType, nDamage, nLength, 0, 0);
    return nDamage;
}

// 0x0056E170
void __fastcall D2GAME_RollPhysicalDamage_6FD14EC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        const int nMinDamage = SKILLS_GetMinPhysDamage(pUnit, nSkillId, nSkillLevel, 0);
        const int nMaxDamage = SKILLS_GetMaxPhysDamage(pUnit, nSkillId, nSkillLevel, 0);
        const int nDamage = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMaxDamage - nMinDamage) + nMinDamage;
        pDamage->dwPhysDamage += nDamage;
    }
}

// 0x0056E1E0
int __fastcall SKILLS_GetCrossbowClassFlag(D2UnitStrc* pUnit)
{
    int nWeaponClassId = 0;
    COMPOSIT_GetWeaponClassId(pUnit, pUnit->pInventory, &nWeaponClassId, -1, 1);
    return nWeaponClassId == 7 ? 0x1F : 0;
}


// 0x00570420
void __fastcall SKILLS_StunMonster(D2GameStrc* pGame, D2UnitStrc* pUnused, D2UnitStrc* pUnit, int nDelay)
{
    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        return;
    }

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && !MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_UNIQUE) && !MONSTERS_IsBoss(0, pUnit))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nDelay);
        int nFrame = pGame->dwGameFrame;
        if (!pStatList)
        {
            const int nUnitGUID = pUnit->dwUnitId;
            const int nUnitType = pUnit->dwUnitType;
            nFrame += 100;
            pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nFrame, nUnitType, nUnitGUID);
            if (pStatList)
            {
                EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nFrame, 0, 0);
                STATLIST_SetState(pStatList, STATE_STUNNED);
                STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRefreshPassives);
                D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
                STATES_ToggleState(pUnit, STATE_STUNNED, 1);
            }
        }
        else
        {
            nFrame += nDelay;
            D2COMMON_10476(pStatList, nFrame);
            EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nFrame, 0, 0);
        }

        D2ModeChangeStrc modeChange;
        MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_NEUTRAL, &modeChange);
        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
        pUnit->dwFlags &= ~UNITFLAG_DOUPDATE;
    }
}

static inline int sub_0056F1F0_DrainTargetItemDurability(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}

// 0x0056F1F0
int __fastcall SKILLS_SrvDo002_Kick_PowerStrike_MonIceSpear_Impale_Bash_Stun_Concentrate_BearSmite_Vengeance_Berserk_FireClaws(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget;

    if (pSkillsTxtRecord->wSrvOverlay > 0 && pSkillsTxtRecord->wSrvOverlay <= sgptDataTables->nOverlayTxtRecordCount)
    {
        pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (!pTarget)
        {
            return 0;
        }

        D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
        if (!pDamage)
        {
            return 1;
        }

        if (pDamage->wResultFlags & 1)
        {
            UNITS_SetOverlay(pTarget, pSkillsTxtRecord->wSrvOverlay, 0);
        }
    }

    if (pSkillsTxtRecord->wAuraTargetState >= 0 && pSkillsTxtRecord->wAuraTargetState < sgptDataTables->nStatesTxtRecordCount)
    {
        pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (!pTarget)
        {
            return 0;
        }

        D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
        if (!pDamage)
        {
            return 1;
        }

        if (pDamage->wResultFlags & 1)
        {
            const int nFormula = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
            const int nLength = nFormula < 1 ? 1 : nFormula;

            const int nExpireFrame = pGame->dwGameFrame + nLength;
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pTarget, pSkillsTxtRecord->wAuraTargetState);
            if (!pStatList)
            {
                pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2u, nExpireFrame, !pTarget ? 6 : pTarget->dwUnitType, !pTarget ? -1 : pTarget->dwUnitId);
                if (!pStatList)
                {
                    return 1;
                }
            }

            EVENT_SetEvent(pGame, pTarget, 0xC, nExpireFrame, 0, 0);
            STATES_ToggleState(pTarget, pSkillsTxtRecord->wAuraTargetState, 1);
            STATLIST_SetState(pStatList, pSkillsTxtRecord->wAuraTargetState);
            D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
            STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRefreshPassives);
            SKILLS_ApplyAuraStatsToStatList(pTarget, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
        }
    }

    if (pSkillsTxtRecord->nAuraState > 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
        if (!pStatList)
        {
            const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
            const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;

            pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 4u, 0, nUnitType, nUnitGUID);
            if (!pStatList)
            {
                return 1;
            }

            STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
            STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRefreshPassives);
        }

        STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);
        SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    return sub_0056F1F0_DrainTargetItemDurability(pGame, pUnit);
}

// 0x00570530
void __fastcall SKILLS_StatRemoveCallback_ResetAiAndRefresh(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        return;
    }

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == 1)
    {
        AITHINK_ExecuteAiFn(pGame, pUnit, AIGENERAL_GetAiControlFromUnitInline(pUnit), 0);
    }

    SKILLS_RemoveStateAndRefreshPassives(pUnit, nState, pStatList);
}

// 0x0056E210
void __fastcall SKILLS_RewindUnitAnimation(D2UnitStrc* pUnit, int nArg)
{
    SUNIT_RewindAnimationByPercentage(SUNIT_GetGameFromUnit(pUnit), pUnit, nArg);
}

// 0x0056E230
int __fastcall SKILLS_StartBasicAttack(D2GameStrc* ptGame, D2UnitStrc* pUnit, D2UnitStrc* hTarget)
{
    D2_ASSERT(pUnit, 4625);
    D2_ASSERT(hTarget, 4626);
    D2_ASSERT(ptGame, 4627);

    SUNIT_SetCombatMode(ptGame, pUnit, 1);
    UNITS_SetUsedSkill(pUnit, 0);

    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, SKILL_ATTACK, -1);
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        StartModeID(ptGame, pUnit, pSkill, PLRMODE_ATTACK1, !hTarget ? UNIT_INVALID : hTarget->dwUnitType, !hTarget ? -1 : hTarget->dwUnitId, 1);
        break;

    case UNIT_MONSTER:
    {
        D2ModeChangeStrc tModeChange;
        MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_ATTACK1, &tModeChange);
        tModeChange.pTargetUnit = hTarget;
        D2GAME_ModeChange_6FC65220(ptGame, &tModeChange, 1);
        break;
    }
    }

    return 1;
}

// 0x0056E2F0
int __fastcall SKILLS_CanSwitchAi(D2UnitStrc* pUnit, int nAiSpecialState)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        const int nBaseId = MONSTERS_GetBaseIdFromMonsterId(pUnit->dwClassId);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount && nBaseId == MONSTER_IMP1 && STATES_CheckState(pUnit, STATE_ATTACHED))
        {
            return 0;
        }
    }

    return AIUTIL_CanUnitSwitchAi(pUnit, nAiSpecialState) != 0;
}

// 0x0056E370
int __fastcall SKILLS_UnitFindTest_Corpse(D2UnitStrc* pUnit, D2UnitFindArgStrc* pArg)
{
    if (D2COMMON_11021(pUnit))
    {
        return UNITFINDS_TestUnit(pUnit, pArg);
    }

    return 0;
}

// 0x0056E390
D2UnitStrc* __fastcall SKILLS_FindCorpseNearTarget(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel)
{
    if (pUnit && nSkillLevel > 0 && pTarget)
    {
        const int nX = CLIENTS_GetUnitX(pTarget);
        const int nY = CLIENTS_GetUnitY(pTarget);

        D2UnitFindArgStrc unitFindArg = {};
        unitFindArg.nFlags = 0x1002;
        unitFindArg.nX = nX;
        unitFindArg.nY = nY;
        unitFindArg.nSize = 10;

        D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);

        D2UnitFindDataStrc unitFindData;
        UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, &unitFindData, UNITS_GetRoom(pTarget), nX, nY, 10, SKILLS_UnitFindTest_Corpse, &unitFindArg);
        UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&unitFindData);

        D2UnitStrc* pResult = 0;
        if (unitFindData.nIndex)
        {
            pResult = *unitFindData.pUnitsArray;
        }

        UNITFINDS_FreeUnitFindData(&unitFindData);
        return pResult;
    }

    return 0;
}

// 0x0056E450
int __fastcall SKILLS_IsMissileTargetPositionClear(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissileId);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    nMissileId = 0;
    int nY = 0;
    D2_ASSERT(pMissilesTxtRecord, 4737);

    if (pRoom)
    {
        D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nMissileId, &nY);
        if (nMissileId && nY)
        {
            return !COLLISION_CheckMaskWithSizeXY(pRoom, nMissileId, nY, pMissilesTxtRecord->nSize, pMissilesTxtRecord->nSize, 5);
        }
    }
    return 0;
}

// 0x0056E510
int __fastcall SKILLS_GetMeleeSearchRange(D2UnitStrc* pUnit)
{
    return UNITS_GetMeleeRange(pUnit) + 4;
}

// 0x0056E520
void __fastcall SKILLS_ApplyAttackRateModifier(D2UnitStrc* pUnit, int nAttackRate)
{
    D2StatListStrc* pStatList = STATLIST_AllocStatList(0, 4, 0, !pUnit ? UNIT_INVALID : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    if (pStatList)
    {
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStat(pStatList, STAT_ATTACKRATE, nAttackRate, 0);
        UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\Skills.cpp", 0x12AB);
    }
}

// 0x0056E580
void __fastcall SKILLS_ClearMonsterMinionOwnership(D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (pOwner && pOwner->dwUnitType == UNIT_MONSTER)
    {
        if (pOwner == pUnit)
        {
            AIGENERAL_DetachOwnedMinions(pUnit);
        }
        else
        {
            AIGENERAL_FreeMinionList(pUnit);
        }
    }
}

// 0x0056E5B0
int __fastcall SKILLS_GetBaseWalkVelocity(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            D2CharStatsTxt* pCharStatsTxtRecord = DATATBLS_GetCharStatsTxtRecord(pUnit->dwClassId);
            if (pCharStatsTxtRecord)
            {
                return pCharStatsTxtRecord->nWalkSpeed << 8;
            }
        }
        else if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
            if (pMonStatsTxtRecord)
            {
                return pMonStatsTxtRecord->nVelocity << 8;
            }
        }
    }

    return 0x600;
}

int __fastcall AIGENERAL_GetMinionSpawnClassId(D2UnitStrc* pUnit); // 0x0058F710

int __stdcall MONSTERS_GetSpawnMode_XY(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7); // 0x0063EA70

// 0x0056E620
int __fastcall D2GAME_GetSummonIdFromSkill(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7)
{
    int nMonsterId = MONSTERS_GetSpawnMode_XY(pUnit, nArg2, nArg3, nArg4, nArg5, nArg6, nArg7);
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return nMonsterId;
    }

    nMonsterId = AIGENERAL_GetMinionSpawnClassId(pUnit);
    if (nMonsterId > 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return nMonsterId;
    }

    return -1;
}

// 0x0056E680
unsigned short __fastcall SKILLS_SetDamageResultFlagsFromSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage, int a8)
{
    if (!(pSkillsTxtRecord->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT))
    {
        pDamage->wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), a8);
        if (pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
        {
            pDamage->wResultFlags |= pSkillsTxtRecord->wResultFlags;
        }
    }
    else
    {
        pDamage->wResultFlags = pSkillsTxtRecord->wResultFlags;
    }

    return pDamage->wResultFlags;
}

// 0x0056E6F0
unsigned short __fastcall SKILLS_SetDamageResultFlags(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, unsigned short wResultFlags, int a5, D2DamageStrc* pDamage, int a7)
{
    if (!(wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT))
    {
        pDamage->wResultFlags = SUNITDMG_GetResultFlags(pGame, pOwner, pUnit, a5, a7);
        if (pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
        {
            pDamage->wResultFlags |= wResultFlags;
        }
    }
    else
    {
        pDamage->wResultFlags = wResultFlags;
    }

    return pDamage->wResultFlags;
}

// 0x0056E740
D2UnitEventStrc* __fastcall SKILLS_RegisterUnitEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEventType, int a4, int a5, int nEventFunc, int a7, int a8)
{
    if (nEventFunc >= 0 && nEventFunc < EVENTFN_COUNT && gpfnSkillEventCallbacks[nEventFunc])
    {
        return SUNITEVENT_Register(pGame, pUnit, nUnitEventType, a4, a5, gpfnSkillEventCallbacks[nEventFunc], a7, a8);
    }

    return 0;
}

#include "gen/data/Source/D2Game/SKILLS/Skills.inc"
