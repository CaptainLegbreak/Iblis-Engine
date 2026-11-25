#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2ClientGame.h"
#include "D2StormLink.h"
#include "D2ClientTypes.h"
#include "D2PlayerModes.h"
#include "D2Drlg.h"

struct D2SkillStrc;

struct D2UnitStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2GfxLightStrc;

struct D2GameStrc;

struct D2StaticPathStrc;

struct D2MonStatsTxt;

struct D2ItemStatCostTxt;

struct D2PacketBufferStrc;


struct D2MsgFilterStrc;

struct D2PlayerDataStrc;

struct D2ClientUnitViewStrc;

union D2SeedStrc;

struct D2PlayerCmdStrc;

struct D2SkillsTxt;

struct D2StringRefStrc;

struct D2MsgFilterStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pUnit04;
    D2UnitStrc* pUnit08;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

static inline void PLAYER_ReleaseRoomLight(D2UnitStrc* pUnit); // 0x00460FF0

extern unsigned int gdwBitMasks[]; // 0x006CE268

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

int __cdecl GAME_GetConnectionType(); // 0x0044DB30

void __cdecl GAME_ResetMouseButtons(); // 0x0044DA70

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

void __cdecl AUTOMAP_UpdateAutomapLayout(); // 0x00457520

void __cdecl AUTOMAP_PaintAutomap(); // 0x00459700

void __cdecl AUTOMAP_DrawGameInfoLines(); // 0x00459E90

void __cdecl AUTOMAP_DrawStringLine(); // 0x00459FF0

void __cdecl AUTOMAP_DrawLevelName(); // 0x0045A050

void __cdecl AUTOMAP_DrawVersionLine(); // 0x0045A0A0

void __cdecl AUTOMAP_DrawLocalIpLine(); // 0x0045A120

void __cdecl AUTOMAP_DrawDifficultyLine(); // 0x0045A190

void __cdecl AUTOMAP_DrawAutomapUnits(); // 0x0045AC90

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

D2PacketBufferStrc* __fastcall sub_00464770_GetPacketBuffer(void* pArg); // 0x00464770

void __fastcall sub_004647A0_SetPacketBuffer(void* pArg, D2PacketBufferStrc* pBuffer); // 0x004647A0

void __fastcall D2GFX_SetViewMatrixAdjust(int nOffset); // 0x004F52A0

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

extern void* gpGlobal_007A0634; // 0x007A0634

extern D2ViewStrc* gpClientView; // 0x007A0640

extern int gnScreenWidth; // 0x0071146C

extern int gnAutomapTextY; // 0x007A51BC

extern int gnAutomapOriginY; // 0x007A5208

extern int gnAutomapOriginX; // 0x007A520C

extern int gnPanelSlideMode; // 0x007A5210

extern int gnAutomapHeight_007A521C; // 0x007A521C

extern int gnAutomapWidth; // 0x007A5220

extern int gbPlayerCommandPending; // 0x007A5264

struct D2ClientUnitViewStrc
{
    int dwUnitType;
    int unk0x04[4];
    D2PlayerDataStrc* pPlayerData;
};

D2GfxLightStrc* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* pValue); // 0x00643A00

void __fastcall DLIGHTMAP_ReleaseLight(D2GfxLightStrc* pLight); // 0x004743D0

extern int gbOkCancelAccepted; // 0x007A5258

extern int gbOkCancelCancelled; // 0x007A525C

typedef void (__fastcall* STATLIST_CallbackFn)(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOther, int nLayer_StatId, int nPreviousValue, int nNewValue);

int gnInTown;                                                                                      // 0x007A5260

void __fastcall PLAYER_HandleStatChanged(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOther, int nLayer_StatId, int nPreviousValue, int nNewValue); // 0x004609F0

void __cdecl PLAYER_RefreshAdjacentPlayers(); // 0x004608C0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

void __fastcall GFX_AddAiTargetUnit(D2UnitStrc* pUnit); // 0x0046C6E0

D2GfxLightStrc* __fastcall DLIGHTMAP_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160

int __fastcall DLIGHTMAP_GetLightSize(D2GfxLightStrc* pLight); // 0x00474350

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

void __stdcall UNITS_AllocPlayerData(D2UnitStrc* pUnit); // 0x00621F90

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, STATLIST_CallbackFn pfCallback, D2GameStrc* pGame); // 0x00626D40

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0

void __stdcall SKILLS_InitSkillList(D2UnitStrc* pUnit); // 0x00647EE0

void __stdcall PATH_SetDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x006488A0

void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask); // 0x00648C30

int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce); // 0x00649560

void __stdcall PATH_AllocDynamicPath(void* pMemPool, D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitStrc* pUnit, int bSetFlag); // 0x00649D00

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern int gnStringCount; // 0x00711EF0

extern D2StringRefStrc gaStringRefs[]; // 0x00711DDC

void __fastcall UNITSND_PlayPlayerSpeech(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0

extern "C" int __fastcall sub_004D9FC0(D2UnitStrc* unit,D2SkillStrc* skill); // 0x004D9FC0

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140

void __cdecl UI_CancelCursorItemUse(); // 0x00453EC0

void __fastcall GFX_ClearPendingAction(D2UnitStrc* pUnit); // 0x0045C470

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

D2UnitStrc* __fastcall SELECT_GetSkillTarget(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pX, int* pY, unsigned int dwFlags, int bForce); // 0x00467880

int __cdecl sub_00468830(); // 0x00468830

void __fastcall MSG_SendDword(char nHeader, int nArg); // 0x00478680

int __stdcall D2Common_11016(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00645460

int gnFilterMsgState; // 0x007A526C

extern void* gpDrlgAct_007A0634;                                                                            // 0x007A0634

unsigned int gdwLastClampTick; // 0x007A5268

void __cdecl GAME_SetClickHandled(); // 0x0044BEF0

int __cdecl sub_0044DA90(); // 0x0044DA90

int __cdecl GAME_GetCurrentTime(); // 0x0044DAA0

unsigned int __cdecl GAME_GetInteractDeadline(); // 0x0044DAC0

void __fastcall GAME_SetInteractDeadline(int nValue); // 0x0044DAD0

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

void __fastcall AUTOMAP_ScreenToMap(int* pX, int* pY);                                                             // 0x0045AFF0

int __stdcall PLAYER_IsPendingMode(int nArg1, int nArg2);                                             // 0x00461D60

int __fastcall CUNIT_CanUseSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                            // 0x00464600

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820

int __fastcall CUNIT_IsHostileTo(D2UnitStrc* pUnit, D2UnitStrc* pOther);                           // 0x00465C60

void __cdecl SELECT_ClearSelection();                                                                                // 0x00466FE0

D2UnitStrc* __cdecl SELECT_GetSelectedUnit();                                                             // 0x00467A10

void __fastcall SELECT_RefreshHoverUnit(D2UnitStrc* pUnit);                                                            // 0x00467A70

D2UnitStrc* __fastcall SELECT_GetSkillTarget(D2SkillStrc* pSkill, D2UnitStrc* pUnit, int* pnX, int* pnY, unsigned char nFlags, int bArg); // 0x00467880

int __fastcall DLIGHTMAP_GetDistance(int nDX, int nDY);                                                  // 0x00474080

void __fastcall MSG_SendFourDwords(char nCommand, int nUnitType, int nUnitId, int nX, int nY);         // 0x00478700

int __cdecl INV_GetScreenHeightMinusPanel();                                                                                 // 0x00454970

int __fastcall MONSTERUNIQUE_CheckMonStatsFlag(int nMonsterId, int nFlag);                                   // 0x00457490

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

void __fastcall PLAYER_SetPlayerMode(int nMode, D2UnitStrc* pUnit, int nArg1, int nArg2);             // 0x00460780

int __fastcall PLAYER_IsInAuraRange(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pRange, int* pDistance); // 0x00461AC0

int __fastcall PLAYER_FilterCommandMessage(D2PlayerCmdStrc* pCmd);                                           // 0x00462930

void __fastcall CUNIT_SetPlayerUnit(D2UnitStrc* pUnit); // 0x00463D90

void __fastcall CUNIT_MarkUnitDead(D2UnitStrc* pUnit);                                                            // 0x00464810

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0

void __fastcall CUNIT_FreeLight(D2UnitStrc* pUnit);                                                  // 0x00464930

void __fastcall CUNIT_SetUnitPosition(D2UnitStrc* pUnit, int nX, int nY, int nFlags);                // 0x004654C0

void __fastcall CUNIT_RemoveInventoryUnits(D2UnitStrc* pUnit, int nArg);                                                  // 0x00466CB0

void __fastcall VIEW_SetPetEntryValue(D2UnitStrc* pOwner, D2UnitStrc* pRecord, int nValue);            // 0x00467410

int __cdecl sub_00468740();                                                                                 // 0x00468740

void __fastcall sub_0046BF30_CheckThroneLevel(D2ActiveRoomStrc* pRoom);                                     // 0x0046BF30

void __fastcall GFX_RemoveAiTargetUnit(D2UnitStrc* pUnit);                                                            // 0x0046C700

void __fastcall GFX_FreeGfxData(D2UnitStrc* pUnit);                                                            // 0x0046EC10

void __fastcall GFX_PruneGfxNodes(D2UnitStrc* pUnit);                                              // 0x0046ECE0

void __fastcall GFX_FillGfxEntries(D2UnitStrc* pUnit, unsigned char nValue); // 0x0046F020

void __fastcall sub_00473C90_SetGlobal(int nValue);                                                         // 0x00473C90

D2ClientEntryStrc* __fastcall ROSTERPETS_FindEntry(int nKey);                                             // 0x00478E40

int __fastcall ROSTERPETS_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny);                       // 0x00478F20

void __fastcall UNITMODE_SetUnitMode(D2UnitStrc* pUnit, int nArg);                                         // 0x00480E70

void __fastcall UNITMODE_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nA, int nB, int nC); // 0x004804E0

void __fastcall UNITMODE_DoUnitAction(int nMode, D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3);                // 0x00481030

void __fastcall NPCMENU_RefreshNpcEntries(D2UnitStrc* pUnit);                                                            // 0x004B3E10

void __cdecl ITEM_ResetWeaponClasses();                                                                                // 0x004C1E30

int __fastcall SKILLS_DoUsedSkill(D2UnitStrc* pUnit); // 0x004C68F0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0

int __stdcall DUNGEON_CheckLOSDraw(D2ActiveRoomStrc* pRoom);                                                        // 0x0061AA40

void __stdcall DUNGEON_UpdatePops(D2ActiveRoomStrc* pRoom, int nX, int nY, int bChanged);              // 0x0061ACD0

int __stdcall DUNGEON_GetPortalFlagFromLevelId(int nLevelId);                                               // 0x0061AE30

void __stdcall DUNGEON_InitRoomTileAnimation(void* pAct, D2ActiveRoomStrc* pNextRoom, D2ActiveRoomStrc* pRoom);              // 0x0061AF10

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0

void __stdcall UNITS_GetRunAndWalkSpeedForPlayer(D2UnitStrc* pUnit, int nClassId, int* pSpeed, int* pBase);        // 0x00620E40

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510

int __stdcall UNITS_IsCurrentRoomInvalid(D2UnitStrc* pUnit);                                                // 0x00620F50

void __stdcall UNITS_FreePlayerData(void* pMemPool, D2UnitStrc* pPlayer);                                   // 0x00622060

void __stdcall UNITS_SetPlayerPortalFlags(D2UnitStrc* pUnit, int nPortalFlags);                             // 0x006221E0

int __stdcall UNITS_GetPlayerPortalFlags(D2UnitStrc* pUnit);                                                // 0x00622230

int __stdcall UNITS_TestCollisionBetweenInteractingUnits(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, unsigned int nCollisionMask); // 0x00622B50

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);                // 0x00622C40

int __stdcall UNITS_IsInMovingModeEx(D2UnitStrc* pUnit);                                                    // 0x00622DC0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0

int __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                                  // 0x00640E90

int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                          // 0x00643860

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480

int __stdcall UNITS_IsObjectInInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject);                        // 0x00623660

void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath);                                             // 0x00648730

void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);                       // 0x00648B90

void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory);                                        // 0x0063AC40

int __stdcall sub_00641530(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                                      // 0x00641530

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                   // 0x006439B0

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0

void __stdcall PATH_FreeDynamicPath(void* pMemPool, D2DynamicPathStrc* pDynamicPath);                      // 0x00648460

int __stdcall PATH_GetLastPointX(D2DynamicPathStrc* pPath);                                            // 0x00648A40

int __stdcall PATH_GetLastPointY(D2DynamicPathStrc* pPath);                                            // 0x00648A60

D2ActiveRoomStrc* __stdcall PATH_GetNextRoom(D2DynamicPathStrc* pDynamicPath);                              // 0x00648AA0

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0

int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit);                                              // 0x00649180

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                          // 0x00649970

void __stdcall D2Common_10228(D2UnitStrc* pUnit);                                                           // 0x00649F50

void __stdcall PATH_SetUnitDeadCollision(D2UnitStrc* pUnit, int nArg);                                                   // 0x00649F70

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370

unsigned short __stdcall COLLISION_CheckMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D870

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

void __fastcall AUTOMAP_SetUnitLightRadius(D2UnitStrc* pUnit, int nValue); // 0x00460930

void __fastcall AUTOMAP_SetUnitLightColor(D2UnitStrc* pUnit, int nValue); // 0x004609A0

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0

void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280

void __stdcall D2Common_10954(D2UnitStrc* pUnit, int nOwnerGUID, int nSkillId, int nSkillLevel, int nCharges, int bFreeMemory); // 0x00647530

static void __stdcall PLAYER_SetModeAndSync(int bSync, D2UnitStrc* pUnit, int nState); // 0x00460830

void __fastcall PLAYER_FreeClientPlayer(D2UnitStrc* pUnit); // 0x00460D50

static void PLAYER_UpdateRoomPosition(D2UnitStrc* pUnit); // 0x00460DE0

static void PLAYER_UpdateRoomState(D2UnitStrc* pUnit); // 0x00460E70

struct D2ActiveRoomStrc;

struct D2ClientRecordStrc;

struct D2DrlgActStrc;

struct D2MonsterDataStrc;

struct D2SkillRefStrc;

struct D2ClientEntryStrc;

struct D2UnitTargetStrc;

int __fastcall CUNIT_CanUseSkill(D2UnitStrc* pUnit, int nArg); // 0x00464600

void __stdcall DUNGEON_InitRoomTileAnimation(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom1, D2ActiveRoomStrc* pRoom2); // 0x0061AF10

void __stdcall UNITS_GetRunAndWalkSpeedForPlayer(int nUnused, int nCharId, int* pWalkSpeed, int* pRunSpeed); // 0x00620E40

int __cdecl GAME_GetLeftClickState(); // 0x0044BF00

int __cdecl GAME_GetRightClickState(); // 0x0044BF10

void __cdecl GAME_ResetMouseState(); // 0x0044DA40

int __fastcall UI_CloseUIVars(int, int); // 0x00456300

void __fastcall CUNIT_UpdateAttackableFlag(D2UnitStrc*); // 0x004647D0

int __fastcall sub_004804A0_SetPathTargetPos(D2UnitStrc*, int, int); // 0x004804A0

int __fastcall UNITMODE_SetPathTargetUnit(D2UnitStrc*, int, int); // 0x00480780

void __fastcall UNITMODE_InteractWithUnit(unsigned short, int); // 0x00480930

void __fastcall UNITMODE_SetModeOverlay(D2UnitStrc*, int); // 0x00480D20

void __fastcall UNITMODE_MoveToPosition(D2UnitStrc*, int, int, int); // 0x00480EF0

int __fastcall SKILLS_StartSkillOnUnit(D2UnitStrc*, D2SkillRefStrc*); // 0x004C6EB0

int __fastcall SKILLS_StartSkillAtPos(D2UnitStrc*, D2SkillRefStrc*); // 0x004C6F40

void __fastcall UNITSND_UpdateUnitSound(D2UnitStrc*, int, int); // 0x004CC5B0

void __stdcall UNITS_SetUsedSkill(D2UnitStrc*, D2SkillStrc*); // 0x00620210

int __stdcall STATES_IsUnitShapeShifted(D2UnitStrc*); // 0x0063A400

int __stdcall INVENTORY_GetEquippedShield(D2InventoryStrc*, D2UnitStrc**); // 0x0063C8F0

void __stdcall PATH_SetType(D2DynamicPathStrc*, int); // 0x00648CF0

void __stdcall PATH_ResetToPreviousType(D2DynamicPathStrc*); // 0x00648DC0

void __stdcall PATH_SetDist(D2DynamicPathStrc*, unsigned char); // 0x00648E40

int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc*, D2InventoryStrc*, int*, int, int); // 0x0064F380

void __stdcall PATH_RecacheRoomIfNeeded(D2DynamicPathStrc*); // 0x00650590

extern "C" const char gszPlayerCpp[]; // 0x006D6A34

static int __stdcall PLAYER_ClampTarget(D2UnitStrc* pUnit, D2PlayerCmdStrc* pCmd); // 0x004623C0

int __fastcall CUNIT_CanUseSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                            // 0x00464600

static void __stdcall PLAYER_SendCommand(int bTarget, D2PlayerCmdStrc* pCmd); // 0x00461700

static void PLAYER_PlaceOnFreeCoords(D2UnitStrc* pUnit); // 0x00460F10

static void PLAYER_ResetPlayerState(D2UnitStrc* pUnit); // 0x00461010

static int __stdcall PLAYER_RefreshSkillRef(int* pUseState, D2UnitStrc* pUnit, D2SkillRefStrc* pRef); // 0x00461180

static void __stdcall PLAYER_ReleaseUsedSkill(int bKeep, D2UnitStrc* pUnit); // 0x004611F0

static int __stdcall PLAYER_CheckSkillUse(D2SkillStrc** ppSkill, int* pUseState, D2UnitStrc* pUnit); // 0x004610C0

static int __stdcall PLAYER_WalkTo(int nMode, D2UnitStrc* pUnit, int nX, int nY); // 0x00461840

static void PLAYER_InteractWithTarget(D2PlayerCmdStrc* pCmd, int nTargetId); // 0x004619E0

void __fastcall PLAYER_InteractWithUnitTarget(D2UnitStrc* pUnit); // 0x00461A70

static void PLAYER_ResumeWalk(D2PlayerCmdStrc* pCmd); // 0x00462370

static int PLAYER_IsSkillFlagSet(D2SkillStrc* pSkill); // 0x00462560

static int PLAYER_CmdLeftSkill(D2PlayerCmdStrc* pCmd); // 0x004629A0

static int PLAYER_CmdLeftSkillMove(D2PlayerCmdStrc* pCmd); // 0x00462A20

static int PLAYER_UpdatePetCommand(D2PlayerCmdStrc* pCmd); // 0x00462B40

static int PLAYER_CmdRightSkill(D2PlayerCmdStrc* pCmd); // 0x00462BA0

static int PLAYER_CmdRightSkillMove(D2PlayerCmdStrc* pCmd); // 0x00462C20

static void __stdcall PLAYER_RequestSkillString(D2UnitStrc* pUnit, int nIndex); // 0x00461070

static int PLAYER_CheckCommandSkill(D2PlayerCmdStrc* pCmd, int* pUseState); // 0x00461160

static inline int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit); // 0x0045ADF0

static inline int __fastcall UNITS_GetYPosition(D2UnitStrc* pUnit); // 0x0045AE20

static void __stdcall PLAYER_OperateObject(int nObjectId, D2PlayerCmdStrc* pCmd); // 0x00461890

static int PLAYER_ApproachForAura(D2PlayerCmdStrc* pCmd, int nArg1, int nArg2); // 0x00461B40

static void __stdcall PLAYER_UseSkillOnTarget(int nArg1, int nArg2, D2PlayerCmdStrc* pCmd); // 0x00461C70

static void __stdcall PLAYER_InteractWithUnit(int nUnitType, int nUnitId, D2PlayerCmdStrc* pCmd); // 0x00461DC0

static int PLAYER_PrepareCommand(D2PlayerCmdStrc* pCmd); // 0x004621D0

static void PLAYER_ExecuteCommand(D2PlayerCmdStrc* pCmd); // 0x004625B0

D2UnitStrc* gpEmitUnit_E06;

D2PlayerCmdStrc* gpEmitCmd_E06;

D2SkillRefStrc* gpEmitRef_E06;

int gnEmitArg_E06;

D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0

void __fastcall GFX_RefreshUnitGfx(D2UnitStrc* pUnit, int nArg);                                          // 0x00470610

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

int gbPlayerCommandPending;                                                                                     // 0x007A5264

inline D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

int __stdcall DRLG_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0

int __fastcall MONSTERUNIQUE_CheckMonStatsFlag(int nMonsterId, int nFlag); // 0x00457490

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

// 0x0045C460
int __fastcall DATATBLS_GetMonStatsTxtRecordCount()
{
    return sgptDataTables->nMonStatsTxtRecordCount;
}

// 0x0045C4F0
D2ItemStatCostTxt* __fastcall PLAYER_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x00460760
void __fastcall PLAYER_SetInteractState(D2ClientUnitViewStrc* pUnit, int nState)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
        pUnit->pPlayerData->nState = nState;
}

// 0x00460780
void __fastcall PLAYER_SetPlayerMode(int nMode, D2ClientUnitViewStrc* pUnit, int nArg1, int nArg2)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
    {
        pUnit->pPlayerData->nState = 1;
        pUnit->pPlayerData->nMode = nMode;
        pUnit->pPlayerData->nArg1 = nArg1;
        pUnit->pPlayerData->nArg2 = nArg2;
    }
}

// 0x004607D0
int __fastcall PLAYER_GetInteractMode(D2ClientUnitViewStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
        return pUnit->pPlayerData->nMode;
    return 0;
}

// 0x004607F0
int __fastcall PLAYER_GetInteractFirstArg(D2ClientUnitViewStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
        return pUnit->pPlayerData->nArg1;
    return 0;
}

// 0x00460810
int __fastcall PLAYER_GetInteractSecondArg(D2ClientUnitViewStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
        return pUnit->pPlayerData->nArg2;
    return 0;
}

// 0x00460830
static void __stdcall PLAYER_SetModeAndSync(int bSync, D2UnitStrc* pUnit, int nState)
{
    UNITMODE_SetUnitMode(pUnit, nState);
    if (!bSync)
        return;

    if (pUnit != sub_00463DE0_GetPlayerUnit())
        return;

    int nX;
    UNIT_GETX(pUnit, nX);
    int nY;
    UNIT_GETY(pUnit, nY);
    if (nX && nY)
        UNITMODE_SetPosition(pUnit, nX, nY, 0, 0, 0);
}

// 0x00460BF0
void __fastcall PLAYER_InitClientPlayer(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    GFX_AddAiTargetUnit(pUnit);
    PATH_AllocDynamicPath(0, pRoom, nX, nY, pUnit, 1);
    if (!pUnit->pInventory)
    {
        pUnit->pInventory = INVENTORY_AllocInventory(0, pUnit);
    }

    pUnit->pSkills = SKILLS_AllocSkillList(0);
    SKILLS_InitSkillList(pUnit);
    STATLIST_AllocStatListEx(pUnit, 0, PLAYER_HandleStatChanged, 0);
    STATLIST_SetUnitStat(pUnit, STAT_ATTACKRATE, 100, 0);
    STATLIST_SetUnitStat(pUnit, STAT_VELOCITYPERCENT, 100, 0);
    STATLIST_SetUnitStat(pUnit, STAT_OTHER_ANIMRATE, 100, 0);
    gnInTown = DUNGEON_IsRoomInTown(pRoom);
    UNITS_ChangeAnimMode(pUnit, 5);
    pUnit->dwFlags &= ~0x20;
    pUnit->dwFlags |= 0xE;
    if (pUnit->dwAnimMode == 0x11 || pUnit->dwAnimMode == 0)
    {
        PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
        sub_00649190_SetPathMode(pUnit, 5);
        PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, 0x8000);
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!DUNGEON_GetActNoFromRoom(pRoom))
    {
        D2GfxLightStrc* pLight = DLIGHTMAP_MakeLightEntry(pUnit, pPlayer && pUnit != pPlayer, 0xD, 0xFF, 0xFF, 0xFF, 0xFF);
        if (pLight)
        {
            pUnit->pLight = pLight;
            sub_00464CF0(pUnit, DLIGHTMAP_GetLightSize(pLight));
        }
    }

    UNITS_AllocPlayerData(pUnit);
    if (pUnit != pPlayer)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        D2SeedStrc* pSeed = &pUnit->pSeed;
        unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
        pSeed->nLowSeed = (unsigned int)lSeed;
        pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
        PATH_SetDirection(pPath, (unsigned int)lSeed & 0x3F);
    }

    PLAYER_RefreshAdjacentPlayers();
}

// 0x004608C0
void __cdecl PLAYER_RefreshAdjacentPlayers()
{
    if (!sub_00463DE0_GetPlayerUnit())
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = CUNIT_GetPlayerRoom();
    if (!pRoom)
    {
        return;
    }

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        for (D2UnitStrc* pUnit = ppRoomList[i]->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
        {
            if ((pUnit ? pUnit->dwUnitType : UNIT_INVALID) == UNIT_MONSTER && STATES_CheckState(pUnit, STATE_DOPPLEZON))
            {
                GFX_RefreshUnitGfx(pUnit, 0);
            }
        }
    }
}

void __fastcall sub_M115_Emit_00460FF0(D2UnitStrc* pUnit)
{
    PLAYER_ReleaseRoomLight(pUnit);
}

// 0x004609F0
void __fastcall PLAYER_HandleStatChanged(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOther, int nLayer_StatId, int nPreviousValue, int nNewValue)
{
    if (!pOwner)
    {
        return;
    }

    int nStatId = (unsigned int)nLayer_StatId >> 16;
    switch (nStatId)
    {
    case 89:
        AUTOMAP_SetUnitLightRadius(pOwner, nNewValue);
        break;

    case 90:
        AUTOMAP_SetUnitLightColor(pOwner, nNewValue);
        break;

    case 97:
    case 107:
        if ((!pOwner ? 6 : pOwner->dwUnitType) == 0)
        {
            int nSkillId = (unsigned short)nLayer_StatId;
            D2SkillStrc* pSkill = SKILLS_GetSkillById(pOwner, nSkillId, -1);
            if (!nNewValue)
            {
                if (pSkill && SKILLS_GetSkillLevel(pOwner, pSkill, 0) <= 0)
                {
                    SKILLS_RemoveSkill(pOwner, nSkillId, ".\\UNIT\\Player.cpp", 221);
                }
            }
            else if (!pSkill)
            {
                D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                if (nStatId == 97 || (pSkillsTxtRecord && pSkillsTxtRecord->nCharClass == (!pOwner ? -1 : pOwner->dwClassId)))
                {
                    SKILLS_AssignSkill(pOwner, nSkillId, 0, 0, ".\\UNIT\\Player.cpp", 232);
                }
            }
        }
        break;

    case 204:
        if ((!pOwner ? 6 : pOwner->dwUnitType) == 0)
        {
            int nLayer = (unsigned short)nLayer_StatId;
            int nSkillId = nLayer >> sgptDataTables->nStuff;
            int nSkillLevel = nLayer & sgptDataTables->nShiftedStuff;
            if (pOther)
            {
                int nOwnerGUID = pOther->dwUnitId;
                int nCharges = STATLIST_UnitGetStatValue(pOther, nStatId, nLayer) & 0xFF;
                if (nCharges > 0 && STATLIST_GetOwner(pOther, 0) == pOwner)
                {
                    D2Common_10954(pOwner, nOwnerGUID, nSkillId, nSkillLevel, nCharges, 0);
                }
                else
                {
                    D2Common_10954(pOwner, nOwnerGUID, nSkillId, nSkillLevel, 0, 1);
                }
            }
        }
        break;
    }
}

// 0x00460D50
void __fastcall PLAYER_FreeClientPlayer(D2UnitStrc* pUnit)
{
    GFX_RemoveAiTargetUnit(pUnit);
    GFX_FreeGfxData(pUnit);
    if (gpDrlgAct_007A0634)
    {
        D2Common_10228(pUnit);
        UNITROOM_RemoveUnitFromRoom(pUnit);
    }
    PATH_FreeDynamicPath(0, pUnit->pDynamicPath);
    pUnit->pDynamicPath = 0;
    CUNIT_RemoveInventoryUnits(pUnit, 0);
    INVENTORY_FreeInventory(pUnit->pInventory);
    pUnit->pInventory = 0;
    D2GfxLightStrc* pResource = D2Common_10958(pUnit, 0);
    if (pResource)
        DLIGHTMAP_ReleaseLight(pResource);
    CUNIT_FreeLight(pUnit);
    if (pUnit == sub_00463DD0_GetPlayerUnit())
        CUNIT_SetPlayerUnit(0);
    UNITS_FreePlayerData(0, pUnit);
    PLAYER_RefreshAdjacentPlayers();
}

// 0x00460DE0
static void PLAYER_UpdateRoomPosition(D2UnitStrc* pUnit)
{
    int nX;
    UNIT_GETX(pUnit, nX);
    int nY;
    UNIT_GETY(pUnit, nY);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    DUNGEON_UpdatePops(pRoom, nX, nY, UNITS_IsCurrentRoomInvalid(pUnit));
}

// 0x00460E70
static void PLAYER_UpdateRoomState(D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return;

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    int nPortalFlags = UNITS_GetPlayerPortalFlags(pUnit);
    nPortalFlags |= DUNGEON_GetPortalFlagFromLevelId(nLevelId);
    UNITS_SetPlayerPortalFlags(pUnit, nPortalFlags);
    DUNGEON_InitRoomTileAnimation(gpDrlgAct_007A0634, PATH_GetNextRoom(pUnit->pDynamicPath), UNITS_GetRoom(pUnit));
    const int bInTown = DUNGEON_IsRoomInTown(pRoom) != 0;
    if (gnInTown != bInTown && !bInTown)
        NPCMENU_RefreshNpcEntries(pUnit);
    gnInTown = bInTown;
    sub_00473C90_SetGlobal(DUNGEON_CheckLOSDraw(pRoom));
    sub_0046BF30_CheckThroneLevel(pRoom);
}

static inline int PLAYER_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    if (pUnit->pDynamicPath)
        return PATH_GetXPosition(pUnit->pDynamicPath);
    return 0;
}

static inline int PLAYER_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    if (pUnit->pDynamicPath)
        return PATH_GetYPosition(pUnit->pDynamicPath);
    return 0;
}

// 0x00460F10
static void PLAYER_PlaceOnFreeCoords(D2UnitStrc* pUnit)
{
    const int nMode = !pUnit ? 0 : pUnit->dwAnimMode;
    switch (nMode)
    {
    case 1:
    case 5:
        break;
    default:
        return;
    }

    D2CoordStrc tCoords;
    tCoords.nX = PLAYER_GetUnitXInline(pUnit);
    tCoords.nY = PLAYER_GetUnitYInline(pUnit);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return;

    if (!COLLISION_CheckMaskWithPattern(pRoom, tCoords.nX, tCoords.nY, PATH_GetUnitCollisionPattern(pUnit), 0xC01))
        return;

    COLLISION_GetFreeCoordinates(pRoom, &tCoords, UNITS_GetUnitSizeX(pUnit), 0xC01, 1);
    CUNIT_SetUnitPosition(pUnit, tCoords.nX, tCoords.nY, 0);
}

// 0x00460FF0
static inline void PLAYER_ReleaseRoomLight(D2UnitStrc* pUnit)
{
    D2GfxLightStrc* pLight = D2Common_10958(pUnit, 0);
    if (pLight)
        DLIGHTMAP_ReleaseLight(pLight);
}

// 0x00461010
static void PLAYER_ResetPlayerState(D2UnitStrc* pUnit)
{
    ITEM_ResetWeaponClasses();
    PATH_SetUnitDeadCollision(pUnit, 0);
    CUNIT_MarkUnitDead(pUnit);
    if (pUnit)
        pUnit->dwFlags &= ~4;
    if (!STATES_CheckState(pUnit, STATE_PLAYERBODY) && pUnit)
        pUnit->dwFlags &= ~2;
    GFX_PruneGfxNodes(pUnit);
    GFX_FillGfxEntries(pUnit, 0);
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, 0, 0);
}

// 0x00461070
static void __stdcall PLAYER_RequestSkillString(D2UnitStrc* pUnit, int nIndex)
{
    D2_ASSERT(gnStringCount > nIndex, 0x2CB);
    const unsigned short nStringId = gaStringRefs[nIndex].nStringId;
    if (nStringId)
        UNITSND_PlayPlayerSpeech(pUnit, nStringId);
}

// 0x004610C0
static int __stdcall PLAYER_CheckSkillUse(D2SkillStrc** ppSkill, int* pUseState, D2UnitStrc* pUnit)
{
    if (pUnit != sub_00463DD0_GetPlayerUnit())
        return 1;

    if (!ppSkill || !*ppSkill)
        return 0;

    int nUseState = sub_004D9FC0(pUnit, *ppSkill);
    if (pUseState)
        *pUseState = nUseState;

    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(*ppSkill);
    if (!pSkillsTxt)
        return 0;

    if (nUseState > 0 && (nUseState <= 2 || nUseState == 4)
        && (pSkillsTxt->nFlags[3] & gdwBitMasks[4]))
    {
        *ppSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_ATTACK);
        nUseState = sub_004D9FC0(pUnit, *ppSkill);
    }

    if (nUseState == 5 || nUseState == 0)
        return 1;

    PLAYER_RequestSkillString(pUnit, nUseState);
    return 0;
}

// 0x00461160
static inline int PLAYER_CheckCommandSkill(D2PlayerCmdStrc* pCmd, int* pUseState)
{
    return PLAYER_CheckSkillUse(&pCmd->pSkill, pUseState, pCmd->pPlayer);
}

// 0x00461180
static int __stdcall PLAYER_RefreshSkillRef(int* pUseState, D2UnitStrc* pUnit, D2SkillRefStrc* pRef)
{
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pRef->nSkillId, pRef->nOwnerGUID);
    if (!pSkill)
        return 1;

    if (!PLAYER_CheckSkillUse(&pSkill, pUseState, pUnit))
        return 0;

    const int nOldSkillId = pRef->nSkillId;
    pRef->nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNIT\\Player.cpp", 0x32C);
    if (pRef->nSkillId != nOldSkillId)
        pRef->nOwnerGUID = -1;
    return 1;
}

// 0x004611F0
static void __stdcall PLAYER_ReleaseUsedSkill(int bKeep, D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return;

    const int nFlags = SKILLS_GetFlags(pSkill);
    if (nFlags & 1)
    {
        SKILLS_SetFlags(pSkill, nFlags | 2);
        SKILLS_DoUsedSkill(pUnit);
        return;
    }

    if (bKeep)
        return;

    const int bFlag = pUnit ? (pUnit->dwFlags >> 6) & 1 : 0;
    if (!bFlag)
        SKILLS_DoUsedSkill(pUnit);
}

// 0x00461250
int __fastcall PLAYER_ApplyUnitCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int bForce)
{
    D2GfxLightStrc* pResource = D2Common_10958(pUnit, 0);
    if (pResource) DLIGHTMAP_ReleaseLight(pResource);
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (nCommand != 19)
    {
        PLAYER_ReleaseUsedSkill(pUnit == pPlayer, pUnit);
        UNITS_SetUsedSkill(pUnit, 0);
    }
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (pUnit->dwAnimMode == 19)
    {
        if (!bForce) return 1;
        PATH_RecacheRoomIfNeeded(pPath);
    }
    PATH_ResetToPreviousType(pPath);
    int nNeutralMode;
    int nMoveMode;
    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        nNeutralMode = 5;
        nMoveMode = 6;
    }
    else
    {
        nNeutralMode = 1;
        nMoveMode = 2;
    }
    switch (nCommand)
    {
    case 22:
        if (PLAYER_RefreshSkillRef(0, pUnit, (D2SkillRefStrc*)pTarget) && SKILLS_StartSkillOnUnit(pUnit, (D2SkillRefStrc*)pTarget)) return 1;
        PLAYER_SetModeAndSync(1, pUnit, nNeutralMode);
        return 0;
    case 21:
        if (PLAYER_RefreshSkillRef(0, pUnit, (D2SkillRefStrc*)pTarget) && SKILLS_StartSkillAtPos(pUnit, (D2SkillRefStrc*)pTarget)) return 1;
        PLAYER_SetModeAndSync(1, pUnit, nNeutralMode);
        return 0;
    case 1:
        if (sub_004804A0_SetPathTargetPos(pUnit, pTarget->nParam1, pTarget->nParam2))
        {
            UNITMODE_SetUnitMode(pUnit, nMoveMode);
            return 1;
        }
        PLAYER_SetModeAndSync(1, pUnit, nNeutralMode);
        return 0;
    case 0:
        if (UNITMODE_SetPathTargetUnit(pUnit, pTarget->nParam1, pTarget->nParam2))
        {
            UNITMODE_SetUnitMode(pUnit, nMoveMode);
            return 1;
        }
        PLAYER_SetModeAndSync(1, pUnit, nNeutralMode);
        return 0;
    case 23:
        if (sub_004804A0_SetPathTargetPos(pUnit, pTarget->nParam1, pTarget->nParam2))
        {
            UNITMODE_SetUnitMode(pUnit, 3);
            return 1;
        }
        PLAYER_SetModeAndSync(1, pUnit, nNeutralMode);
        return 0;
    case 24:
        if (UNITMODE_SetPathTargetUnit(pUnit, pTarget->nParam1, pTarget->nParam2))
        {
            UNITMODE_SetUnitMode(pUnit, 3);
            return 1;
        }
        PLAYER_SetModeAndSync(1, pUnit, nNeutralMode);
        return 0;
    case 6:
        pUnit->dwLastHitClass = pTarget->nParam3;
        UNITMODE_SetUnitMode(pUnit, 4);
        UNITMODE_SetPosition(pUnit, (unsigned short)pTarget->nParam1, (unsigned short)pTarget->nParam2, 1, 0, 0);
        return 1;
    case 19:
    {
        pUnit->dwLastHitClass = pTarget->nParam3;
        UNITMODE_SetModeOverlay(pUnit, 19);
        if (STATES_IsUnitShapeShifted(pUnit))
            UNITSND_UpdateUnitSound(pUnit, 3, 1);
        else
            UNITSND_UpdateUnitSound(pUnit, 19, 1);
        UNITMODE_SetPosition(pUnit, (unsigned short)pTarget->nParam1, (unsigned short)pTarget->nParam2, 1, 0, 0);
        return 1;
    }
    case 20:
        pUnit->dwLastHitClass = pTarget->nParam3;
        PATH_RecacheRoomIfNeeded(pPath);
        PATH_SetType(pPath, 11);
        PATH_SetDist(pPath, 5);
        D2COMMON_10170_PathSetTargetPos(pPath, pTarget->nParam1, pTarget->nParam2);
        D2Common_10142(pPath, pUnit, 0);
        UNITMODE_SetUnitMode(pUnit, 19);
        return 1;
    case 18:
    {
        pUnit->dwLastHitClass = pTarget->nParam3;
        if (INVENTORY_GetEquippedShield(pUnit->pInventory, 0))
            UNITMODE_SetUnitMode(pUnit, 9);
        else
        {
            int nWeaponClass;
            COMPOSIT_GetWeaponClassId(pUnit, pUnit->pInventory, &nWeaponClass, -1, 1);
            if (nWeaponClass == 13) UNITMODE_SetUnitMode(pUnit, 9);
        }
        UNITMODE_SetPosition(pUnit, (unsigned short)pTarget->nParam1, (unsigned short)pTarget->nParam2, 1, 0, 0);
        return 1;
    }
    case 8:
        if (sub_00463DD0_GetPlayerUnit() == pUnit) UI_CloseUIVars(1, 0);
        pUnit->dwLastHitClass = pTarget->nParam3;
        if (SELECT_GetSelectedUnit() == pUnit)
        {
            if (!(GAME_GetLeftClickState() & 8) && !(GAME_GetRightClickState() & 8)) SELECT_ClearSelection();
            else
            {
                GAME_ResetMouseState();
                SELECT_RefreshHoverUnit(0);
            }
        }
        UNITMODE_SetPosition(pUnit, (unsigned short)pTarget->nParam1, (unsigned short)pTarget->nParam2, 0, 0, 0);
        UNITMODE_SetUnitMode(pUnit, 0);
        PLAYER_ResetPlayerState(pUnit);
        GFX_ClearPendingAction(pUnit);
        return 1;
    case 9:
        UNITMODE_SetUnitMode(pUnit, 17);
        PLAYER_ResetPlayerState(pUnit);
        return 1;
    case 7:
    {
        int bDead = CUNIT_IsDeadOrDying(pUnit);
        CUNIT_UpdateAttackableFlag(pUnit);
        pUnit->dwFlags |= 2;
        UNITMODE_SetUnitMode(pUnit, nNeutralMode);
        if (pTarget) UNITMODE_MoveToPosition(pUnit, pTarget->nParam1, pTarget->nParam2, bDead);
        return 1;
    }
    case 2:
        UNITMODE_InteractWithUnit((unsigned short)pTarget->nParam1, pTarget->nParam2);
        return 1;
    case 25:
        UNITMODE_SetUnitMode(pUnit, 13);
        UNITMODE_SetPosition(pUnit, (unsigned short)pTarget->nParam1, (unsigned short)pTarget->nParam2, 0, 0, 0);
        return 1;
    default:
        D2_ASSERT(0, 0x432);
    }
}

// 0x00461700
static void __stdcall PLAYER_SendCommand(int bTarget, D2PlayerCmdStrc* pCmd)
{
    if (sub_00468740() > INV_GetScreenHeightMinusPanel())
        return;

    if (bTarget == 1)
    {
        D2UnitStrc* pTarget = pCmd->pTarget;
        int nType;
        if (!pTarget)
        {
            nType = 6;
        }
        else
        {
            nType = pTarget->dwUnitType;
        }
        const int nId = !(pCmd->pTarget) ? -1 : (pCmd->pTarget)->dwUnitId;
        if (pCmd->dwFlags & 1)
        {
            if (pCmd->dwFlags & 0x20)
            {
                if (pCmd->dwFlags & 8)
                    UNITMODE_DoUnitAction(0xA, pCmd->pPlayer, nType, nId, 0);
                else
                    UNITMODE_DoUnitAction(7, pCmd->pPlayer, nType, nId, 0);
            }
            else
            {
                if (pCmd->dwFlags & 8)
                    UNITMODE_DoUnitAction(9, pCmd->pPlayer, nType, nId, 0);
                else
                    UNITMODE_DoUnitAction(6, pCmd->pPlayer, nType, nId, 0);
            }
        }
        if (pCmd->dwFlags & 2)
        {
            if (pCmd->dwFlags & 0x20)
            {
                if (pCmd->dwFlags & 8)
                    UNITMODE_DoUnitAction(0x11, pCmd->pPlayer, nType, nId, 0);
                else
                    UNITMODE_DoUnitAction(0xE, pCmd->pPlayer, nType, nId, 0);
            }
            else
            {
                if (pCmd->dwFlags & 8)
                    UNITMODE_DoUnitAction(0x10, pCmd->pPlayer, nType, nId, 0);
                else
                    UNITMODE_DoUnitAction(0xD, pCmd->pPlayer, nType, nId, 0);
            }
        }
        return;
    }

    if (pCmd->dwFlags & 1)
    {
        if (pCmd->dwFlags & 8)
            UNITMODE_DoUnitAction(8, pCmd->pPlayer, pCmd->nX, pCmd->nY, 0);
        else
            UNITMODE_DoUnitAction(5, pCmd->pPlayer, pCmd->nX, pCmd->nY, 0);
    }
    if (pCmd->dwFlags & 2)
    {
        if (pCmd->dwFlags & 8)
            UNITMODE_DoUnitAction(0xF, pCmd->pPlayer, pCmd->nX, pCmd->nY, 0);
        else
            UNITMODE_DoUnitAction(0xC, pCmd->pPlayer, pCmd->nX, pCmd->nY, 0);
    }
}

static inline int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static inline int __fastcall UNITS_GetYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

void __fastcall sub_00461A70_InteractWithUnit(D2UnitStrc* pUnit)
{
    D2PlayerCmdStrc tCmd;
    tCmd.pTarget = pUnit;
    tCmd.pPlayer = sub_00463DD0_GetPlayerUnit();
    tCmd.nMode = 2;
    PLAYER_InteractWithTarget(&tCmd, !pUnit ? -1 : pUnit->dwUnitId);
}

// 0x00461840
static int __stdcall PLAYER_WalkTo(int nMode, D2UnitStrc* pUnit, int nX, int nY)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
    if (!D2Common_10142(pPath, pUnit, 0))
        return 0;

    const int nTargetX = PATH_GetLastPointX(pPath);
    const int nTargetY = PATH_GetLastPointY(pPath);
    UNITMODE_DoUnitAction(nMode, pUnit, nTargetX, nTargetY, 0);
    return 1;
}

// 0x00461890
static void __stdcall PLAYER_OperateObject(int nObjectIdArg, D2PlayerCmdStrc* pCmd)
{
    const int nObjectId = nObjectIdArg;
    D2UnitStrc* pObject = CUNIT_FindClientUnit(nObjectId, 2);
    if (!pObject)
        return;

    D2_ASSERT(DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId), 0x4C4);
    int bSetMode = 1;
    if ((!pObject ? -1 : pObject->dwClassId) == 0x3B && STATES_CheckState(sub_00463DD0_GetPlayerUnit(), STATE_JUST_PORTALED))
        bSetMode = 0;

    if (UNITS_IsObjectInInteractRange(pCmd->pPlayer, pCmd->pTarget) && !UNITS_TestCollisionBetweenInteractingUnits(pCmd->pPlayer, pCmd->pTarget, 0x804))
    {
        if (bSetMode)
            UNITMODE_DoUnitAction(0x13, pCmd->pPlayer, 2, nObjectId, 0);
        return;
    }

    int nY = UNITS_GetYPosition(pCmd->pTarget);
    int nX = UNITS_GetXPosition(pCmd->pTarget);
    PLAYER_WalkTo(pCmd->nArg, pCmd->pPlayer, nX, nY);
    if (bSetMode)
        PLAYER_SetPlayerMode(0x13, pCmd->pPlayer, 2, nObjectId);
}

// 0x004619E0
static void PLAYER_InteractWithTarget(D2PlayerCmdStrc* pCmd, int nTargetId)
{
    switch (sub_00641530(pCmd->pTarget, pCmd->pPlayer))
    {
    case 0:
    case 1:
    case 2:
        if (!UNITS_TestCollisionBetweenInteractingUnits(pCmd->pTarget, pCmd->pPlayer, 0x804))
        {
            UNITMODE_DoUnitAction(0x13, pCmd->pPlayer, 0, nTargetId, 0);
            return;
        }
        break;
    }

    UNITMODE_DoUnitAction(pCmd->nMode, pCmd->pPlayer, 0, nTargetId, 0);
    D2UnitStrc* pPlayer = pCmd->pPlayer;
    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER && pPlayer->pPlayerData)
    {
        pPlayer->pPlayerData->nState = 1;
        pPlayer->pPlayerData->nMode = 0x13;
        pPlayer->pPlayerData->nArg1 = 0;
        pPlayer->pPlayerData->nArg2 = nTargetId;
    }
}

// 0x00461A70
void __fastcall PLAYER_InteractWithUnitTarget(D2UnitStrc* pUnit)
{
    D2PlayerCmdStrc tCmd;
    tCmd.pTarget = pUnit;
    tCmd.pPlayer = sub_00463DD0_GetPlayerUnit();
    tCmd.nMode = 2;
    PLAYER_InteractWithTarget(&tCmd, !pUnit ? -1 : pUnit->dwUnitId);
}

// 0x00461AC0
int __fastcall PLAYER_IsInAuraRange(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pRange, int* pDistance)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer || !pSkill || !pTarget)
    {
        return 0;
    }
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    *pRange = SKILLS_EvaluateSkillFormula(pPlayer, pSkillsTxtRecord->dwAuraRangeCalc, pSkillsTxtRecord->nSkillId,
        SKILLS_GetSkillLevel(pPlayer, pSkill, 1));
    *pDistance = DRLG_UnitEdgeDistance(pPlayer, pTarget);
    return *pDistance <= *pRange;
}

// 0x00461B40
static int PLAYER_ApproachForAura(D2PlayerCmdStrc* pCmd, int nArg1, int nArg2)
{
    int nDelta;
    int nDistance;
    {
        int nRange = 0;
        nDistance = 0;
        D2_ASSERT(pCmd->pTarget, 0x52F);
        D2_ASSERT(pCmd->pPlayer, 0x530);
        if (pCmd->dwFlags & 0x20)
        {
            PLAYER_SendCommand(1, pCmd);
            return 1;
        }

        if (PLAYER_IsInAuraRange(pCmd->pSkill, pCmd->pTarget, &nRange, &nDistance))
        {
            PLAYER_SendCommand(1, pCmd);
            return 1;
        }

        if (pCmd->dwFlags & 1)
            PLAYER_SetPlayerMode(6, pCmd->pPlayer, nArg1, nArg2);
        if (pCmd->dwFlags & 2)
            PLAYER_SetPlayerMode(0xD, pCmd->pPlayer, nArg1, nArg2);

        nDelta = nDistance - nRange;
    }
    D2_ASSERT(nDelta > 0, 0x548);
    D2_ASSERT(nDistance, 0x549);
    {
        const int nPlayerX = CLIENTS_GetUnitX(pCmd->pPlayer);
        const int nPlayerY = CLIENTS_GetUnitY(pCmd->pPlayer);
        const int nDX = CLIENTS_GetUnitX(pCmd->pTarget) - nPlayerX;
        const int nStepY = (CLIENTS_GetUnitY(pCmd->pTarget) - nPlayerY) * nDelta / nDistance;
        PLAYER_WalkTo(pCmd->nArg, pCmd->pPlayer, nDX * nDelta / nDistance + nPlayerX, nPlayerY + nStepY);
    }
    return 1;
}

// 0x00461C70
static void __stdcall PLAYER_UseSkillOnTarget(int nArg1, int nArg2, D2PlayerCmdStrc* pCmd)
{
    if (!PLAYER_CheckCommandSkill(pCmd, 0))
        return;

    const int nResult = D2Common_11016(pCmd->pPlayer, pCmd->pSkill);
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nArg2, nArg1);
    if (!pUnit)
        return;

    if (UNITS_IsInMeleeRange(pCmd->pPlayer, pCmd->pTarget, UNITS_IsInMovingModeEx(pUnit)))
    {
        PLAYER_SendCommand(1, pCmd);
        return;
    }

    D2SkillStrc* pSkill = pCmd->pSkill;
    if (pSkill)
    {
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (pSkillsTxt && pSkillsTxt->wSrvDoFunc == 0x13)
        {
            PLAYER_ApproachForAura(pCmd, nArg1, nArg2);
            return;
        }
    }

    switch (nResult)
    {
    default:
        PLAYER_SendCommand(1, pCmd);
        return;

    case 1:
    case 4:
        if (!(pCmd->dwFlags & 0x20))
        {
            UNITMODE_DoUnitAction(pCmd->nMode, pCmd->pPlayer, nArg1, nArg2, 0);
            if (pCmd->dwFlags & 1)
                PLAYER_SetPlayerMode(6, pCmd->pPlayer, nArg1, nArg2);
            if (pCmd->dwFlags & 2)
                PLAYER_SetPlayerMode(0xD, pCmd->pPlayer, nArg1, nArg2);
            return;
        }

        PLAYER_SendCommand(0, pCmd);
        return;
    }
}

static inline int PLAYER_GetValue1(D2UnitStrc* pUnit)
{
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    if (nUnitType == UNIT_PLAYER)
        return pUnit->pPlayerData->nArg1;
    return 0;
}

static inline int PLAYER_GetValue2(D2UnitStrc* pUnit)
{
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    if (nUnitType == UNIT_PLAYER)
        return pUnit->pPlayerData->nArg2;
    return 0;
}

// 0x00462370
static void PLAYER_ResumeWalk(D2PlayerCmdStrc* pCmd)
{
    D2UnitStrc* pPlayer = pCmd->pPlayer;
    if (!pPlayer || pPlayer->dwUnitType != UNIT_PLAYER)
        return;

    if (CUNIT_GetPathTargetUnit(pPlayer))
        return;

    int nMode;
    switch (pPlayer->dwAnimMode)
    {
    case PLRMODE_WALK:
    case PLRMODE_TOWNWALK:
        nMode = 1;
        break;
    case PLRMODE_RUN:
        nMode = 3;
        break;
    default:
        return;
    }
    PLAYER_WalkTo(nMode, pPlayer, pCmd->nX, pCmd->nY);
}

void __stdcall sub_E06_Emit_00461C70(int nArg1, int nArg2, D2PlayerCmdStrc* pCmd)
{
    PLAYER_UseSkillOnTarget(nArg1, nArg2, pCmd);
    PLAYER_UseSkillOnTarget(0, nArg2, pCmd);
}

static inline D2MonStatsTxt* E06_GetMonStatsTxtRecord(int nClassId)
{
    if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nClassId];
    return 0;
}

// 0x00461DC0
static void __stdcall PLAYER_InteractWithUnit(int nUnitType, int nUnitId, D2PlayerCmdStrc* pCmd)
{
    D2UnitStrc* pPlayerUnit = sub_00463DD0_GetPlayerUnit();
    int nRange;
    D2UnitStrc* pTarget = pCmd->pTarget;
    D2UnitStrc* pUnit = pCmd->pTarget;
    if (pTarget)
    {
        switch (pTarget->dwUnitType)
        {
        case UNIT_OBJECT:
        {
            if (pCmd->dwFlags & 8)
                return;
            DATATBLS_GetObjectsTxtRecord(!pUnit ? -1 : pUnit->dwClassId);
            int bSetMode = 1;
            if (pCmd->pTarget && pCmd->pTarget->dwClassId == 0x3B && STATES_CheckState(pPlayerUnit, STATE_JUST_PORTALED))
                bSetMode = 0;
            if (!UNITS_IsObjectInInteractRange(pCmd->pPlayer, pCmd->pTarget) || UNITS_TestCollisionBetweenInteractingUnits(pCmd->pPlayer, pCmd->pTarget, 0x804))
            {
                if (PLAYER_IsPendingMode(nUnitType, nUnitId))
                    return;
                const int nY = CLIENTS_GetUnitY(pCmd->pTarget);
                PLAYER_WalkTo(pCmd->nArg, pCmd->pPlayer, CLIENTS_GetUnitX(pCmd->pTarget), nY);
                if (bSetMode)
                {
                    PLAYER_SetPlayerMode(0x13, pCmd->pPlayer, nUnitType, nUnitId);
                    GAME_SetClickHandled();
                }
                return;
            }
            if (bSetMode)
            {
                UNITMODE_DoUnitAction(0x13, pCmd->pPlayer, nUnitType, nUnitId, 0);
                GAME_SetClickHandled();
            }
            return;
        }
        case UNIT_ITEM:
        {
            if (pCmd->dwFlags & 8)
                return;
            if (sub_00641530(pTarget, pCmd->pPlayer) > 4 || UNITS_TestCollisionBetweenInteractingUnits(pCmd->pPlayer, pCmd->pTarget, 0x804))
            {
                if (PLAYER_IsPendingMode(nUnitType, nUnitId))
                    return;
                UNITMODE_DoUnitAction(pCmd->nMode, pCmd->pPlayer, nUnitType, nUnitId, 0);
                PLAYER_SetPlayerMode(0x13, pCmd->pPlayer, nUnitType, nUnitId);
                GAME_SetClickHandled();
                return;
            }
            UNITMODE_DoUnitAction(0x13, pCmd->pPlayer, nUnitType, nUnitId, 0);
            GAME_SetClickHandled();
            return;
        }
        case UNIT_PLAYER:
        {
            if (sub_00641530(pTarget, pCmd->pPlayer) <= 4 && !UNITS_TestCollisionBetweenInteractingUnits(pCmd->pPlayer, pCmd->pTarget, 0x804))
            {
                UNITMODE_DoUnitAction(0x13, pCmd->pPlayer, nUnitType, nUnitId, 0);
                return;
            }
            UNITMODE_DoUnitAction(pCmd->nMode, pCmd->pPlayer, nUnitType, nUnitId, 0);
            PLAYER_SetPlayerMode(0x13, pCmd->pPlayer, nUnitType, nUnitId);
            return;
        }
        case UNIT_TILE:
        {
            if (GAME_GetCurrentTime() < GAME_GetInteractDeadline())
                return;
            if (sub_00641530(pCmd->pTarget, pCmd->pPlayer) > 4)
            {
                UNITMODE_DoUnitAction(pCmd->nMode, pCmd->pPlayer, nUnitType, nUnitId, 0);
                PLAYER_SetPlayerMode(0x13, pCmd->pPlayer, nUnitType, nUnitId);
            }
            else
            {
                UNITMODE_DoUnitAction(0x13, pCmd->pPlayer, nUnitType, nUnitId, 0);
            }
            GAME_SetInteractDeadline(GAME_GetCurrentTime() + 0x1F4);
            return;
        }
        case UNIT_MONSTER:
        {
            D2MonStatsTxt* pMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(!pUnit ? -1 : pUnit->dwClassId);
            if (pMonStatsTxt && (pMonStatsTxt->nMonStatsFlags[1] & gdwBitMasks[1]))
            {
                nRange = 2;
            }
            else
            {
                nRange = 5;
            }
            goto check_range;
        }
        }
    }

    nRange = 5;
check_range:
    if (pTarget && pTarget->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxt = E06_GetMonStatsTxtRecord(!pUnit ? -1 : pUnit->dwClassId);
        if (pMonStatsTxt && (pMonStatsTxt->nMonStatsFlags[1] & gdwBitMasks[1]) && (pMonStatsTxt->nMonStatsFlags[1] & gdwBitMasks[0]))
        {
            if (pTarget->pDynamicPath)
                D2Common_10153(pTarget->pDynamicPath);
            pUnit = pCmd->pTarget;
            const int nId = !pUnit ? -1 : pUnit->dwUnitId;
            const int nType = !pCmd->pTarget ? 6 : pCmd->pTarget->dwUnitType;
            const int nY = CLIENTS_GetUnitY(pUnit);
            MSG_SendFourDwords(0x59, nType, nId, CLIENTS_GetUnitX(pCmd->pTarget), nY);
            pUnit = pCmd->pTarget;
            if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
                pUnit->pMonsterData->nClientFlags |= 1;
            UNITMODE_SetUnitMode(pCmd->pTarget, 1);
        }
    }

    if (sub_00641530(pCmd->pTarget, pCmd->pPlayer) > nRange)
    {
        UNITMODE_DoUnitAction(pCmd->nMode, pCmd->pPlayer, nUnitType, nUnitId, 0);
        D2UnitStrc* pPlayer = pCmd->pPlayer;
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER && pPlayer->pPlayerData)
        {
            pPlayer->pPlayerData->nState = 1;
            pPlayer->pPlayerData->nMode = 0x13;
            pPlayer->pPlayerData->nArg1 = nUnitType;
            pPlayer->pPlayerData->nArg2 = nUnitId;
        }
        return;
    }

    UNITMODE_DoUnitAction(0x13, pCmd->pPlayer, nUnitType, nUnitId, 0);
}

int __stdcall sub_M135_Emit_00461160A(D2PlayerCmdStrc* pCmd, int* pUseState)
{
    return PLAYER_CheckCommandSkill(pCmd, pUseState) + 0x3131;
}

int __stdcall sub_M135_Emit_00461160B(int nSkip, D2PlayerCmdStrc* pCmd)
{
    if (!PLAYER_CheckCommandSkill(pCmd, 0))
        return nSkip;
    return 0x3133;
}

static inline int E06_GetPlayerMode(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
        return pUnit->pPlayerData->nMode;
    return 0;
}

static inline int E06_GetPlayerModeArg1(D2UnitStrc* pUnit)
{
    return pUnit ? (pUnit->dwUnitType == UNIT_PLAYER ? (pUnit->pPlayerData ? pUnit->pPlayerData->nArg1 : 0) : 0) : 0;
}

static inline int E06_GetPlayerModeArg2(D2UnitStrc* pUnit)
{
    return pUnit ? (pUnit->dwUnitType == UNIT_PLAYER ? (pUnit->pPlayerData ? pUnit->pPlayerData->nArg2 : 0) : 0) : 0;
}

static inline void E06_ClearPlayerMode(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
    {
        pUnit->pPlayerData->nState = 0;
        pUnit->pPlayerData->nMode = 0;
        pUnit->pPlayerData->nArg1 = 0;
        pUnit->pPlayerData->nArg2 = 0;
    }
}

// 0x00461D60
int __stdcall PLAYER_IsPendingMode(int nValue1, int nValue2)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nUnitType = !pPlayer ? 6 : pPlayer->dwUnitType;
    if (!pPlayer || nUnitType != UNIT_PLAYER)
        return 0;

    D2PlayerDataStrc* pPlayerData = pPlayer->pPlayerData;
    if (!pPlayerData || pPlayerData->nMode != 19)
        return 0;

    const int nFirst = PLAYER_GetValue1(pPlayer);
    const int nSecond = PLAYER_GetValue2(pPlayer);
    if (nFirst == nValue1 && nSecond == nValue2)
        return 1;
    return 0;
}

int __cdecl sub_E06_Emit_004621D0(D2PlayerCmdStrc* pCmd)
{
    if (!PLAYER_PrepareCommand(pCmd))
    {
        return 0;
    }
    return pCmd->nMode;
}

static inline D2MonStatsTxt* E06_GetUnitMonStatsTxt(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;
    const int nClassId = pUnit->dwClassId;
    if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nClassId];
    return 0;
}

// 0x004621D0
static int PLAYER_PrepareCommand(D2PlayerCmdStrc* pCmd)
{
    const int nResult = D2Common_11016(pCmd->pPlayer, pCmd->pSkill);
    if (pCmd->pSkill && (pCmd->dwFlags & 2) && nResult != 1)
    {
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pCmd->pSkill);
        if (!pSkillsTxt)
            return 0;

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pCmd->pPlayer);
        if (!(pSkillsTxt->nFlags[1] & gdwBitMasks[0]) && DUNGEON_IsRoomInTown(pRoom))
        {
            UNITSND_PlayPlayerSpeech(pCmd->pPlayer, 0x18);
            return 0;
        }

        if (pSkillsTxt->nFlags[0] & gdwBitMasks[4])
            return 0;
    }

    if (pCmd->dwFlags & 0x40)
    {
        pCmd->nArg = 3;
        pCmd->nMode = 4;
    }
    else
    {
        pCmd->nArg = 1;
        pCmd->nMode = 2;
    }

    const int nMode = E06_GetPlayerMode(pCmd->pPlayer);
    if (nMode)
    {
        if (nMode == 0x13)
        {
            const int nModeArg1 = E06_GetPlayerModeArg1(pCmd->pPlayer);
            const int nModeArg2 = E06_GetPlayerModeArg2(pCmd->pPlayer);
            if (CUNIT_FindClientUnit(nModeArg2, nModeArg1))
                GFX_ClearPendingAction(pCmd->pPlayer);
        }
        else
        {
            E06_ClearPlayerMode(pCmd->pPlayer);
        }
    }

    if (!pCmd->pSkill)
        return 0;

    int bForce = (pCmd->dwFlags >> 5) & 1;
    if ((pCmd->dwFlags & 2) && !pCmd->pTarget)
        bForce = 1;
    pCmd->pTarget = SELECT_GetSkillTarget(pCmd->pSkill, pCmd->pTarget, &pCmd->nX, &pCmd->nY, pCmd->dwFlags, bForce);
    if (sub_00468830() == 6)
    {
        UI_CancelCursorItemUse();
        return 1;
    }
    if (sub_00468830() == 8)
        MSG_SendDword(0x4C, -1);
    return 1;
}

inline int ClampTarget_GetX(D2UnitStrc* pUnit)
{
    int nResult;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nResult = pUnit->pStaticPath->nXPos;
        break;
    default:
        nResult = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
        break;
    }
    return nResult;
}

inline int ClampTarget_GetY(D2UnitStrc* pUnit)
{
    int nResult;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nResult = pUnit->pStaticPath->nYPos;
        break;
    default:
        nResult = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
        break;
    }
    return nResult;
}

// 0x004623C0
static int __stdcall PLAYER_ClampTarget(D2UnitStrc* pUnit, D2PlayerCmdStrc* pCmd)
{
    int nX = ClampTarget_GetX(pUnit);
    int nY = ClampTarget_GetY(pUnit);
    int nDX;
    int nDY;
    nDX = pCmd->nX - nX;
    nDY = pCmd->nY - nY;
    if (E06_ABS(nDX) >= 0x100 || E06_ABS(nDY) >= 0x100)
        return 0;
    if (E06_ABS(nDX) < 1 && E06_ABS(nDY) < 1)
        return 0;

    int nDistance = DLIGHTMAP_GetDistance(nDX, nDY);
    if (nDistance <= 1)
        nDistance = 1;

    int nRange;
    if (pCmd->dwFlags & 4)
    {
        nRange = 3;
        if (pCmd->dwFlags & 0x40)
            nRange = 5;
        else
        {
            if (pCmd->dwFlags & 8)
                nRange = (((unsigned char)pCmd->dwFlags >> 6) & 1) | 4;
            else if (pCmd->dwFlags & 0x10)
                nRange = 0;
        }
    }
    else
    {
        nRange = 3;
        if (pCmd->dwFlags & 8)
            nRange = (((unsigned char)pCmd->dwFlags >> 6) & 1) | 4;
        else if (pCmd->dwFlags & 0x10)
            nRange = 0;
    }

    if (nDistance < nRange)
    {
        const float fScale = (float)nRange / nDistance;
        nDX = (int)(nDX * fScale);
        nDY = (int)(nDY * fScale);
    }

    pCmd->nX = nX + nDX;
    pCmd->nY = nY + nDY;
    const unsigned int dwTick = sub_0044DA90();
    if (pUnit->dwUnitType == UNIT_PLAYER && (pCmd->dwFlags & 8))
    {
        const unsigned int nAnimMode = pUnit->dwAnimMode;
        switch (nAnimMode)
        {
        case 2:
        case 3:
        case 6:
            if (dwTick - gdwLastClampTick < 7)
                return 0;
            break;
        }
    }

    gdwLastClampTick = dwTick;
    return 1;
}

// 0x00462560
static int PLAYER_IsSkillFlagSet(D2SkillStrc* pSkill)
{
    if (pSkill)
    {
        const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNIT\\Player.cpp", 0x75A);
        D2SkillsTxt* pSkillsTxt = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
        if (pSkillsTxt->nFlags[1] & gdwBitMasks[0])
            return 1;
    }
    return 0;
}

inline D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

// 0x004625B0
static void PLAYER_ExecuteCommand(D2PlayerCmdStrc* pCmd)
{
    if (!PLAYER_PrepareCommand(pCmd))
        return;

    D2UnitStrc* pPlayer = pCmd->pPlayer;
    unsigned int dwFlags = pCmd->dwFlags;
    D2UnitStrc* pTarget = pCmd->pTarget;
    D2SkillStrc** ppSkill = &pCmd->pSkill;
    int bAuraTarget = 0;
    const int nResult = D2Common_11016(pPlayer, *ppSkill);
    D2SkillsTxt* pSkillsTxt = 0;
    if (*ppSkill)
    {
        pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(*ppSkill);
        if (!pSkillsTxt)
            goto no_target;
    }

    if (!pTarget)
        goto no_target;

    if (!pSkillsTxt)
        goto with_target;

    if ((pCmd->dwFlags & 2) && nResult != 1)
    {
        switch (pTarget->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
            if (!(pSkillsTxt->nFlags[3] & gdwBitMasks[3]))
                goto no_target;
            bAuraTarget = 1;
            break;
        case UNIT_TILE:
            dwFlags |= 0x100;
            goto no_target;
        }
    }

    if (pTarget->dwUnitType != UNIT_MONSTER || !CUNIT_IsDeadOrDying(pTarget) || (pSkillsTxt->nFlags[3] & gdwBitMasks[0]))
        goto with_target;

no_target:
    {
        const unsigned int bNoTarget = dwFlags & 0x20;
        if (bNoTarget || ((dwFlags & 2) && nResult != 1))
        {
            int nUseState = 0;
            if (!PLAYER_CheckSkillUse(ppSkill, &nUseState, pCmd->pPlayer))
                return;
            D2SkillStrc* pSkill = *ppSkill;
            if (pSkill && !SKILLS_GetSkillIdFromSkill(pSkill, gszPlayerCpp, 0x7AF) && nUseState == 1 && !bNoTarget)
            {
                if (!PLAYER_ClampTarget(pCmd->pPlayer, pCmd))
                    return;
                PLAYER_WalkTo(pCmd->nArg, pPlayer, pCmd->nX, pCmd->nY);
                SELECT_RefreshHoverUnit(0);
                return;
            }
            PLAYER_SendCommand(0, pCmd);
            SELECT_RefreshHoverUnit(0);
            return;
        }

        if (!PLAYER_ClampTarget(pCmd->pPlayer, pCmd))
            return;
        PLAYER_WalkTo(pCmd->nArg, pPlayer, pCmd->nX, pCmd->nY);
        SELECT_RefreshHoverUnit(0);
        return;
    }

with_target:
    {
        const int nTargetType = pTarget->dwUnitType;
        const int nTargetId = pTarget->dwUnitId;
        if (!bAuraTarget)
        {
            switch (nTargetType)
            {
            case 2:
            case 4:
            case 5:
                if ((dwFlags & 2) && nResult != 1) return;
                break;
            }
        }

        if (SKILLS_GetSkillModeFromUnit(pPlayer, *ppSkill))
        {
            D2SkillStrc* pSkill = *ppSkill;
            if (pSkill)
            {
                D2SkillsTxt* pTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
                if (pTxt && (pTxt->nFlags[3] & gdwBitMasks[3]))
                {
                    if (!PLAYER_CheckSkillUse(ppSkill, 0, pCmd->pPlayer))
                        return;
                    PLAYER_SendCommand(1, pCmd);
                    return;
                }
            }

            int bAttackable = (pTarget->dwFlags >> 2) & 1;
            if (bAttackable)
            {
                if (!(pSkillsTxt->nFlags[3] & gdwBitMasks[1]) && !(pSkillsTxt->nFlags[3] & gdwBitMasks[2]))
                    bAttackable = CUNIT_IsHostileTo(pPlayer, pTarget);
                if (bAttackable)
                {
                    if (nTargetType == 2)
                    {
                        if (dwFlags & 0x20)
                            return;
                        PLAYER_OperateObject(nTargetId, pCmd);
                        return;
                    }

                    if (nTargetType == 0)
                    {
                        if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)) && DUNGEON_IsRoomInTown(UNITS_GetRoom(pPlayer)))
                        {
                            PLAYER_InteractWithTarget(pCmd, nTargetId);
                            return;
                        }
                        PLAYER_UseSkillOnTarget(0, nTargetId, pCmd);
                        return;
                    }

                    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
                    {
                        if (!PLAYER_IsSkillFlagSet(*ppSkill))
                            return;
                        PLAYER_UseSkillOnTarget(nTargetType, nTargetId, pCmd);
                        return;
                    }
                    PLAYER_UseSkillOnTarget(nTargetType, nTargetId, pCmd);
                    return;
                }
            }

            if (dwFlags & 0x20)
            {
                if (!PLAYER_CheckSkillUse(ppSkill, 0, pCmd->pPlayer))
                    return;
                PLAYER_SendCommand(0, pCmd);
                return;
            }
        }

        if (dwFlags & 0x20)
            return;

        if (nTargetType != 1)
        {
            PLAYER_InteractWithUnit(nTargetType, nTargetId, pCmd);
            return;
        }

        if (!(dwFlags & 4))
            return;

        D2MonStatsTxt* pMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(pTarget->dwClassId);
        if (pMonStatsTxt && (pMonStatsTxt->nMonStatsFlags[1] & gdwBitMasks[1]))
        {
            PLAYER_InteractWithUnit(1, nTargetId, pCmd);
            return;
        }

        UNITMODE_DoUnitAction(pCmd->nMode, pPlayer, 1, nTargetId, 0);
    }
}

// 0x00462920
void __cdecl PLAYER_ClearCommandPending()
{
    gbPlayerCommandPending = 0;
}

// 0x00462930
int __fastcall PLAYER_FilterCommandMessage(D2MsgFilterStrc* pMsg)
{
    const unsigned int dwFlags = pMsg->dwFlags;
    if (dwFlags & 0x10)
    {
        gnFilterMsgState = 0;
        return 0;
    }
    if (dwFlags & 4)
    {
        gnFilterMsgState = (pMsg->pUnit08 != 0) + 1;
        return 1;
    }
    if (dwFlags & 8)
    {
        if (!gnFilterMsgState)
        {
            return 0;
        }
        if (pMsg->pUnit08)
        {
            const int nType = pMsg->pUnit08->dwUnitType;
            if (nType < 0)
            {
                return 0;
            }
            if (nType > 1 && nType != 5)
            {
                return 0;
            }
            if (pMsg->pUnit04)
            {
                const int nMode = pMsg->pUnit04->dwAnimMode;
                if (nMode == 2 || nMode == 3 || nMode == 6)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

// 0x004629A0
static int PLAYER_CmdLeftSkill(D2PlayerCmdStrc* pCmd)
{
    if (!PLAYER_FilterCommandMessage(pCmd))
        return 1;

    pCmd->pSkill = UNITS_GetLeftSkill(pCmd->pPlayer);
    if (CUNIT_CanUseSkill(pCmd->pPlayer, pCmd->pSkill))
    {
        pCmd->dwFlags |= 0x80;
        PLAYER_ExecuteCommand(pCmd);
        return 1;
    }

    if (sub_00468830() == 6)
        UI_CancelCursorItemUse();
    else if (sub_00468830() == 8)
        MSG_SendDword(0x4C, -1);

    D2UnitStrc* pItem = INVENTORY_GetCursorItem(pCmd->pPlayer->pInventory);
    if (!pItem)
        return 1;

    MSG_SendDword(0x17, pItem->dwUnitId);
    return 0;
}

// 0x00462A20
static int PLAYER_CmdLeftSkillMove(D2PlayerCmdStrc* pCmd)
{
    int bChanged = 0;
    if (!PLAYER_FilterCommandMessage(pCmd))
        return 1;

    pCmd->pSkill = UNITS_GetLeftSkill(pCmd->pPlayer);
    if (!CUNIT_CanUseSkill(pCmd->pPlayer, pCmd->pSkill))
        return 1;

    D2UnitStrc* pPlayer = pCmd->pPlayer;
    int nSpeed;
    int nBase;
    UNITS_GetRunAndWalkSpeedForPlayer(pPlayer, !pPlayer ? -1 : pPlayer->dwClassId, &nSpeed, &nBase);
    nSpeed <<= 8;
    D2DynamicPathStrc* pPath = pCmd->pPlayer->pDynamicPath;
    const int nVelocity = STATLIST_UnitGetStatValue(pCmd->pPlayer, STAT_VELOCITYPERCENT, 0) * nSpeed / 100;
    if (PATH_GetVelocity(pPath) == nVelocity)
    {
        if (pCmd->dwFlags & 0x40)
            bChanged = 1;
    }
    else
    {
        if (!(pCmd->dwFlags & 0x40))
            bChanged = 1;
    }

    if (pCmd->pTarget)
    {
        D2UnitStrc* pCurrent = CUNIT_GetPathTargetUnit(pCmd->pPlayer);
        if (pCmd->pTarget != pCurrent || bChanged)
        {
            PATH_SetTargetUnit(pPath, pCmd->pTarget);
            pCmd->dwFlags |= 0x80;
            PLAYER_ExecuteCommand(pCmd);
            return 1;
        }
    }
    else if (!(pCmd->dwFlags & 0x20))
    {
        if (E06_GetPlayerMode(pCmd->pPlayer))
            return 1;
        pCmd->dwFlags |= 0x80;
    }

    PLAYER_ExecuteCommand(pCmd);
    return 1;
}

// 0x00462B40
static int PLAYER_UpdatePetCommand(D2PlayerCmdStrc* pCmd)
{
    PLAYER_FilterCommandMessage(pCmd);
    const int nPetId = ROSTERPETS_FindPetIdByOwner(pCmd->pPlayer, 7, 0);
    if (nPetId != -1)
    {
        D2UnitStrc* pPet = CUNIT_FindClientUnit(nPetId, 1);
        if (pPet && ROSTERPETS_FindEntry(nPetId)->nValue == 2)
            VIEW_SetPetEntryValue(pCmd->pPlayer, pPet, 0);
    }
    PLAYER_ResumeWalk(pCmd);
    return 0;
}

// 0x00462BA0
static int PLAYER_CmdRightSkill(D2PlayerCmdStrc* pCmd)
{
    if (!PLAYER_FilterCommandMessage(pCmd))
        return 1;

    pCmd->pSkill = UNITS_GetRightSkill(pCmd->pPlayer);
    if (!CUNIT_CanUseSkill(pCmd->pPlayer, pCmd->pSkill))
        return 1;

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pCmd->pSkill, ".\\UNIT\\Player.cpp", 0x9DD);
    D2SkillsTxt* pSkillsTxt = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    switch (pSkillsTxt->nAuraTargetState)
    {
    case 1:
        if (!(pCmd->dwFlags & 0x40))
            pCmd->dwFlags |= 0x80;
        break;
    }
    PLAYER_ExecuteCommand(pCmd);
    return 1;
}

// 0x00462C20
static int PLAYER_CmdRightSkillMove(D2PlayerCmdStrc* pCmd)
{
    if (!PLAYER_FilterCommandMessage(pCmd))
        return 1;

    pCmd->pSkill = UNITS_GetRightSkill(pCmd->pPlayer);
    if (!CUNIT_CanUseSkill(pCmd->pPlayer, pCmd->pSkill))
        return 1;

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pCmd->pSkill, ".\\UNIT\\Player.cpp", 0x9FD);
    D2SkillsTxt* pSkillsTxt = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    switch (pSkillsTxt->nAuraTargetState)
    {
    case 1:
        if (!(pCmd->dwFlags & 0x40))
            pCmd->dwFlags |= 0x80;
        break;
    }
    PLAYER_ExecuteCommand(pCmd);
    return 1;
}

// 0x00462CA0
static int sub_00462CA0_UpdatePetCommandNoWalk(D2PlayerCmdStrc* pCmd)
{
    PLAYER_FilterCommandMessage(pCmd);
    const int nPetId = ROSTERPETS_FindPetIdByOwner(pCmd->pPlayer, 7, 0);
    if (nPetId != -1)
    {
        D2UnitStrc* pPet = CUNIT_FindClientUnit(nPetId, 1);
        if (pPet && ROSTERPETS_FindEntry(nPetId)->nValue == 2)
            VIEW_SetPetEntryValue(pCmd->pPlayer, pPet, 0);
    }
    return 0;
}

int __fastcall PLAYER_PlayerCommand(int nCommand, int nX, int nY, unsigned char nKeyFlags); // 0x00462D00
void sub_E06_Emit_Player1()
{
    PLAYER_SetModeAndSync(1, gpEmitUnit_E06, gnEmitArg_E06);
    PLAYER_UpdateRoomPosition(gpEmitUnit_E06);
    PLAYER_UpdateRoomState(gpEmitUnit_E06);
    PLAYER_PlaceOnFreeCoords(gpEmitUnit_E06);
    PLAYER_ResetPlayerState(gpEmitUnit_E06);
    PLAYER_RefreshSkillRef(0, gpEmitUnit_E06, gpEmitRef_E06);
    PLAYER_ReleaseUsedSkill(gnEmitArg_E06 == 1, gpEmitUnit_E06);
}

// 0x00462D00
int __fastcall PLAYER_PlayerCommand(int nCommand, int nX, int nY, unsigned char nKeyFlags)
{
    if (GAME_GetUIVarState(9))
        return 0;

    if (gbPlayerCommandPending && (nX || nY))
        return 0;

    gbPlayerCommandPending = 1;
    AUTOMAP_ScreenToMap(&nX, &nY);
    D2PlayerCmdStrc tCmd = {};
    tCmd.dwFlags = 0;
    tCmd.pPlayer = sub_00463DD0_GetPlayerUnit();
    tCmd.pTarget = SELECT_GetSelectedUnit();
    tCmd.nX = nX;
    tCmd.nY = nY;
    if (tCmd.pTarget)
    {
        switch (tCmd.pTarget->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
            tCmd.nX = CLIENTS_GetUnitX(tCmd.pTarget);
            tCmd.nY = CLIENTS_GetUnitY(tCmd.pTarget);
            break;
        }
    }

    if ((nKeyFlags & 8) && STATLIST_UnitGetStatValue(tCmd.pPlayer, STAT_STAMINA, 0))
        tCmd.dwFlags |= 0x40;
    if (nKeyFlags & 4)
        tCmd.dwFlags |= 0x20;

    switch (nCommand)
    {
    case 0:
        if (tCmd.pTarget)
            SELECT_RefreshHoverUnit(tCmd.pTarget);
        else
            SELECT_ClearSelection();
        tCmd.dwFlags |= 5;
        return PLAYER_CmdLeftSkill(&tCmd);
    case 1:
        tCmd.dwFlags |= 9;
        return PLAYER_CmdLeftSkillMove(&tCmd);
    case 2:
        SELECT_ClearSelection();
        tCmd.dwFlags |= 0x11;
        return PLAYER_UpdatePetCommand(&tCmd);
    case 3:
        if (tCmd.pTarget)
            SELECT_RefreshHoverUnit(tCmd.pTarget);
        else
            SELECT_ClearSelection();
        tCmd.dwFlags |= 6;
        return PLAYER_CmdRightSkill(&tCmd);
    case 4:
        tCmd.dwFlags |= 0xA;
        return PLAYER_CmdRightSkillMove(&tCmd);
    case 5:
        SELECT_ClearSelection();
        tCmd.dwFlags |= 0x12;
        return sub_00462CA0_UpdatePetCommandNoWalk(&tCmd);
    }
    return 1;
}

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
struct D2PlayerModeInfoStrc
{
    int nType;
    int nSeqMode;
    int nDoneMode;
};

extern D2PlayerModeInfoStrc gaPlayerModeInfo[]; // 0x00711E00
struct D2DynamicPathStrc;
struct D2RoomStrc;
int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
void __stdcall sub_00650C60_UpdatePath(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3); // 0x00650C60
void __stdcall sub_0063E510_FillInventoryTables(D2UnitStrc* pUnit, unsigned char* pTableA, unsigned char* pTableB); // 0x0063E510
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc*); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc*); // 0x00648A10
D2UnitStrc* __stdcall sub_00643A00_GetRelatedUnit(D2UnitStrc*, int); // 0x00643A00
struct D2InventoryStrc;
extern D2PlayerModeInfoStrc gaPlayerModeInfo[];                                                    // 0x00711E00
extern "C" int __fastcall UNITMODE_UpdateUnitPath(D2UnitStrc* unit); // 0x004807C0
void __fastcall SKILLS_RunStateActiveFuncs(D2UnitStrc* pUnit);                                                            // 0x004C72F0
void __fastcall UNITSND_UpdateFootsteps(D2UnitStrc* pUnit);                                                            // 0x004CAF60
void __stdcall UNITS_SetCurrentRoomInvalid(D2UnitStrc* pUnit, int a2);                                      // 0x00620FA0
int __stdcall UNITS_IsAtEndOfFrameCycle(D2UnitStrc* pUnit);                                                 // 0x006217C0
void __stdcall UNITS_StopSequence(D2UnitStrc* pUnit);                                                       // 0x00623E00
int __stdcall STATES_CheckStateMaskActiveOnUnit(D2UnitStrc* pUnit);                                                              // 0x0063A340
void __stdcall D2COMMON_10193_PATH_AdjustDirection(D2DynamicPathStrc* pDynamicPath);                        // 0x00648640
D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath); // 0x00648BF0
enum D2PlayerModes
{
    PLAYER_MODE_WALK = 2,
    PLAYER_MODE_RUN = 3,
    PLAYER_MODE_6 = 6,
};


// 0x004630E0
int __fastcall sub_004630E0_GetPlayerTableA(unsigned char* pTable, unsigned int nSize)
{
    unsigned char aOther[16];
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (nSize < sizeof(aOther) || !pPlayer)
        return 0;
    memset(pTable, 0xFF, sizeof(aOther));
    sub_0063E510_FillInventoryTables(pPlayer, pTable, aOther);
    return 1;
}

// 0x00463130
int __fastcall sub_00463130_GetPlayerTableB(unsigned char* pTable, unsigned int nSize)
{
    unsigned char aOther[16];
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (nSize < sizeof(aOther) || !pPlayer)
        return 0;
    memset(pTable, 0xFF, sizeof(aOther));
    sub_0063E510_FillInventoryTables(pPlayer, aOther, pTable);
    return 1;
}

// 0x00463180
void __fastcall AUTOMAP_UpdatePathAndMove(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3)
{
    int nMode = pUnit->dwAnimMode;
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2UnitStrc* pTargetUnit = 0;
    int bMove = 0;
    int nX = 0;
    int nY = 0;
    if (nMode >= PLAYER_MODE_WALK && (nMode <= PLAYER_MODE_RUN || nMode == PLAYER_MODE_6))
    {
        bMove = 1;
        pTargetUnit = CUNIT_GetPathTargetUnit(pUnit);
        if (!pTargetUnit)
        {
            ITEM_GetTargetPosition(pUnit, &nX, &nY);
        }
    }
    sub_00650C60_UpdatePath(pPath, pUnit, nArg1, nArg2, nArg3);
    if (bMove)
    {
        D2UnitTargetStrc tTarget;
        memset(&tTarget, 0, sizeof(tTarget));
        if (pTargetUnit)
        {
            tTarget.nParam1 = pTargetUnit->dwUnitType;
            tTarget.nParam2 = pTargetUnit->dwUnitId;
            PLAYER_ApplyUnitCommand(nMode == PLAYER_MODE_RUN ? 0x18 : 0, pUnit, &tTarget, 0);
        }
        else
        {
            tTarget.nParam1 = nX;
            tTarget.nParam2 = nY;
            PLAYER_ApplyUnitCommand(nMode == PLAYER_MODE_RUN ? 0x17 : 1, pUnit, &tTarget, 0);
        }
    }
}

inline int UNITS_GetUnitTypeInline(D2UnitStrc* unit)
{
    int type = 6;
    if (unit) type = unit->dwUnitType;
    return type;
}

inline int UNITS_GetUnitIdInline(D2UnitStrc* unit)
{
    if (!unit)
        return -1;
    return unit->dwUnitId;
}

// 0x00463260
static void sub_00463260_UpdateStoredUnit(D2UnitStrc* unit)
{
    if (unit != sub_00463DE0_GetPlayerUnit())
        return;
    if (STATLIST_UnitGetStatValue(unit, STAT_STAMINA, 0))
        return;
    D2DynamicPathStrc* path = unit->pDynamicPath;
    int args[7] = {};
    D2UnitStrc* target = CUNIT_GetPathTargetUnit(unit);
    if (PATH_GetTargetUnit(path))
    {
        args[0] = UNITS_GetUnitTypeInline(target);
        args[1] = UNITS_GetUnitIdInline(target);
        PLAYER_ApplyUnitCommand(0, unit, (D2UnitTargetStrc*)args, 0);
        return;
    }
    args[0] = D2COMMON_10175_PathGetFirstPointX(path);
    args[1] = D2COMMON_10176_PathGetFirstPointY(path);
    D2UnitStrc* related = sub_00643A00_GetRelatedUnit(unit, 0);
    if (related)
        DLIGHTMAP_ReleaseLight((D2GfxLightStrc*)related);
    int const tArg1 = unit == sub_00463DD0_GetPlayerUnit();
    PLAYER_ReleaseUsedSkill(tArg1, unit);
    UNITS_SetUsedSkill(unit, 0);
    path = unit->pDynamicPath;
    if ((unit ? unit->dwAnimMode : 0) == 19)
        return;
    else
    {

        PATH_ResetToPreviousType(path);
        int idle, move;
        if (DUNGEON_IsRoomInTown(UNITS_GetRoom(unit)))
        {
            idle = 5;
            move = 6;
        }
        else
        {
            idle = 1;
            move = 2;
        }
        if (sub_004804A0_SetPathTargetPos(unit, args[0], args[1]))
            UNITMODE_SetUnitMode(unit, move);
        else
            PLAYER_SetModeAndSync(1, unit, idle);
    }
}

static inline int PLAYER_UnitHasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

static inline void PLAYER_SetPlayerState(D2UnitStrc* pUnit, int nState)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
        pUnit->pPlayerData->nState = nState;
}

static inline int PLAYER_GetPlayerMode(D2UnitStrc* pUnit)
{
    if (pUnit && (!pUnit ? 6 : pUnit->dwUnitType) == 0 && pUnit->pPlayerData)
        return pUnit->pPlayerData->nMode;
    return 0;
}

static inline D2PlayerDataStrc* PLAYER_GetPlayerData(D2UnitStrc* pUnit)
{
    return (pUnit && pUnit->dwUnitType == UNIT_PLAYER) ? pUnit->pPlayerData : 0;
}

static inline int PLAYER_IsLocalPlayer(D2UnitStrc* pUnit)
{
    return pUnit == sub_00463DD0_GetPlayerUnit();
}

static inline int PLAYER_QueueMoveInline(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int bForce)
{
    void* pResource = D2Common_10958(pUnit, 0);
    if (pResource) DLIGHTMAP_ReleaseLight((D2GfxLightStrc*)pResource);
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (nCommand != 19)
    {
        const int bKeep = pUnit == pPlayer;
        PLAYER_ReleaseUsedSkill(bKeep, pUnit);
        UNITS_SetUsedSkill(pUnit, 0);
    }
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (pUnit->dwAnimMode == 19)
    {
        if (!bForce) return 1;
        PATH_RecacheRoomIfNeeded(pPath);
    }
    PATH_ResetToPreviousType(pPath);
    int nNeutralMode;
    int nMoveMode;
    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        nNeutralMode = 5;
        nMoveMode = 6;
    }
    else
    {
        nNeutralMode = 1;
        nMoveMode = 2;
    }
    switch (nCommand)
    {
    case 22:
        if (PLAYER_RefreshSkillRef(0, pUnit, (D2SkillRefStrc*)pTarget) && SKILLS_StartSkillOnUnit(pUnit, (D2SkillRefStrc*)pTarget)) return 1;
        PLAYER_SetModeAndSync(1, pUnit, nNeutralMode);
        return 0;
    case 21:
        if (PLAYER_RefreshSkillRef(0, pUnit, (D2SkillRefStrc*)pTarget) && SKILLS_StartSkillAtPos(pUnit, (D2SkillRefStrc*)pTarget)) return 1;
        PLAYER_SetModeAndSync(1, pUnit, nNeutralMode);
        return 0;
    case 1:
        if (sub_004804A0_SetPathTargetPos(pUnit, pTarget->nParam1, pTarget->nParam2))
        {
            UNITMODE_SetUnitMode(pUnit, nMoveMode);
            return 1;
        }
        PLAYER_SetModeAndSync(1, pUnit, nNeutralMode);
        return 0;
    case 0:
        if (UNITMODE_SetPathTargetUnit(pUnit, pTarget->nParam1, pTarget->nParam2))
        {
            UNITMODE_SetUnitMode(pUnit, nMoveMode);
            return 1;
        }
        PLAYER_SetModeAndSync(1, pUnit, nNeutralMode);
        return 0;
    case 23:
        if (sub_004804A0_SetPathTargetPos(pUnit, pTarget->nParam1, pTarget->nParam2))
        {
            UNITMODE_SetUnitMode(pUnit, 3);
            return 1;
        }
        PLAYER_SetModeAndSync(1, pUnit, nNeutralMode);
        return 0;
    case 24:
        if (UNITMODE_SetPathTargetUnit(pUnit, pTarget->nParam1, pTarget->nParam2))
        {
            UNITMODE_SetUnitMode(pUnit, 3);
            return 1;
        }
        PLAYER_SetModeAndSync(1, pUnit, nNeutralMode);
        return 0;
    case 6:
        pUnit->dwLastHitClass = pTarget->nParam3;
        UNITMODE_SetUnitMode(pUnit, 4);
        UNITMODE_SetPosition(pUnit, (unsigned short)pTarget->nParam1, (unsigned short)pTarget->nParam2, 1, 0, 0);
        return 1;
    case 19:
    {
        pUnit->dwLastHitClass = pTarget->nParam3;
        UNITMODE_SetModeOverlay(pUnit, 19);
        if (STATES_IsUnitShapeShifted(pUnit))
            UNITSND_UpdateUnitSound(pUnit, 3, 1);
        else
            UNITSND_UpdateUnitSound(pUnit, 19, 1);
        UNITMODE_SetPosition(pUnit, (unsigned short)pTarget->nParam1, (unsigned short)pTarget->nParam2, 1, 0, 0);
        return 1;
    }
    case 20:
        pUnit->dwLastHitClass = pTarget->nParam3;
        PATH_RecacheRoomIfNeeded(pPath);
        PATH_SetType(pPath, 11);
        PATH_SetDist(pPath, 5);
        D2COMMON_10170_PathSetTargetPos(pPath, pTarget->nParam1, pTarget->nParam2);
        D2Common_10142(pPath, pUnit, 0);
        UNITMODE_SetUnitMode(pUnit, 19);
        return 1;
    case 18:
    {
        pUnit->dwLastHitClass = pTarget->nParam3;
        if (INVENTORY_GetEquippedShield(pUnit->pInventory, 0))
            UNITMODE_SetUnitMode(pUnit, 9);
        else
        {
            int nWeaponClass;
            COMPOSIT_GetWeaponClassId(pUnit, pUnit->pInventory, &nWeaponClass, -1, 1);
            if (nWeaponClass == 13) UNITMODE_SetUnitMode(pUnit, 9);
        }
        UNITMODE_SetPosition(pUnit, (unsigned short)pTarget->nParam1, (unsigned short)pTarget->nParam2, 1, 0, 0);
        return 1;
    }
    case 8:
        if (sub_00463DD0_GetPlayerUnit() == pUnit) UI_CloseUIVars(1, 0);
        pUnit->dwLastHitClass = pTarget->nParam3;
        if (SELECT_GetSelectedUnit() == pUnit)
        {
            if (!(GAME_GetLeftClickState() & 8) && !(GAME_GetRightClickState() & 8)) SELECT_ClearSelection();
            else
            {
                GAME_ResetMouseState();
                SELECT_RefreshHoverUnit(0);
            }
        }
        UNITMODE_SetPosition(pUnit, (unsigned short)pTarget->nParam1, (unsigned short)pTarget->nParam2, 0, 0, 0);
        UNITMODE_SetUnitMode(pUnit, 0);
        PLAYER_ResetPlayerState(pUnit);
        GFX_ClearPendingAction(pUnit);
        return 1;
    case 9:
        UNITMODE_SetUnitMode(pUnit, 17);
        PLAYER_ResetPlayerState(pUnit);
        return 1;
    case 7:
    {
        int bDead = CUNIT_IsDeadOrDying(pUnit);
        CUNIT_UpdateAttackableFlag(pUnit);
        pUnit->dwFlags |= 2;
        UNITMODE_SetUnitMode(pUnit, nNeutralMode);
        if (pTarget) UNITMODE_MoveToPosition(pUnit, pTarget->nParam1, pTarget->nParam2, bDead);
        return 1;
    }
    case 2:
        UNITMODE_InteractWithUnit((unsigned short)pTarget->nParam1, pTarget->nParam2);
        return 1;
    case 25:
        UNITMODE_SetUnitMode(pUnit, 13);
        UNITMODE_SetPosition(pUnit, (unsigned short)pTarget->nParam1, (unsigned short)pTarget->nParam2, 0, 0, 0);
        return 1;
    default:
        D2_ASSERT(0, 0x432);
    }
}

// 0x00463390
void __fastcall sub_00463390_UpdatePlayerMode(D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    int bPathDone = 0;
    if (gaPlayerModeInfo[pUnit->dwAnimMode].nType == 1)
    {
        bPathDone = UNITMODE_UpdateUnitPath(pUnit);
        if (pUnit == sub_00463DD0_GetPlayerUnit())
            PLAYER_UpdateRoomPosition(pUnit);
        UNITSND_UpdateFootsteps(pUnit);
    }

    if (gaPlayerModeInfo[pUnit->dwAnimMode].nType == 2)
    {
        D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
        if (pSkill)
        {
            int nFlags = SKILLS_GetFlags(pSkill);
            int bRelease = 1;
            if (nFlags & 1)
            {
                if (UNITMODE_UpdateUnitPath(pUnit))
                {
                    SKILLS_SetFlags(pSkill, nFlags | 2);
                    SKILLS_DoUsedSkill(pUnit);
                    *(unsigned int*)&bRelease = 0;
                }
                if (pUnit == sub_00463DD0_GetPlayerUnit())
                    PLAYER_UpdateRoomPosition(pUnit);
            }

            const int nActionFrame = pUnit->nActionFrame;
            if (bRelease && !PLAYER_UnitHasFlag(pUnit, 0x40))
            {
                if (nActionFrame == 1 || nActionFrame == 2 || nActionFrame == 3)
                    SKILLS_DoUsedSkill(pUnit);
            }
        }
    }

    switch (gaPlayerModeInfo[pUnit->dwAnimMode].nSeqMode)
    {
    case 0:
        UNITS_StopSequence(pUnit);
        break;
    case 1:
        if (!UNITS_IsAtEndOfFrameCycle(pUnit))
            UNITS_StopSequence(pUnit);
        break;
    case 2:
        if (UNITS_IsAtEndOfFrameCycle(pUnit))
        {
            pUnit->nSeqCurrentFramePrecise = pUnit->dwFrameCountPrecise - 0x100;
            pUnit->wAnimSpeed = 0;
        }
        else
        {
            UNITS_StopSequence(pUnit);
        }
        break;
    case 3:
        pUnit->nSeqCurrentFramePrecise = 0x100;
        pUnit->wAnimSpeed = 0;
        break;
    }

    if (pUnit->dwAnimMode == 18 && PLAYER_UnitHasFlag(pUnit, 0x4000))
        GFX_RefreshUnitGfx(pUnit, 0);

    int bDone;
    switch (gaPlayerModeInfo[pUnit->dwAnimMode].nDoneMode)
    {
    case 1:
        bDone = bPathDone;
        break;
    case 2:
    case 3:
        bDone = UNITS_IsAtEndOfFrameCycle(pUnit);
        break;
    default:
        bDone = 0;
        break;
    }

    if (bDone)
    {
        if (pUnit->dwAnimMode == 19)
        {
            int aArgs[7] = {};
            aArgs[0] = PLAYER_GetUnitXInline(pUnit);
            aArgs[1] = PLAYER_GetUnitYInline(pUnit);
            PATH_RecacheRoomIfNeeded(pPath);
            PATH_ResetToPreviousType(pPath);
            PLAYER_QueueMoveInline(6, pUnit, (D2UnitTargetStrc*)aArgs, 1);
        }
        else if (!PLAYER_GetPlayerMode(pUnit))
        {
            PLAYER_QueueMoveInline(7, pUnit, 0, 1);
        }
        else
        {
            PLAYER_SetPlayerState(pUnit, 1);
        }
    }

    if (UNITS_IsCurrentRoomInvalid(pUnit))
    {
        UNITS_SetCurrentRoomInvalid(pUnit, 0);
        if (pUnit == sub_00463DD0_GetPlayerUnit())
            PLAYER_UpdateRoomState(pUnit);
    }

    D2COMMON_10193_PATH_AdjustDirection(pPath);
    if (pUnit->dwAnimMode == 3)
        sub_00463260_UpdateStoredUnit(pUnit);
    if (STATES_CheckStateMaskActiveOnUnit(pUnit))
        SKILLS_RunStateActiveFuncs(pUnit);
    PLAYER_PlaceOnFreeCoords(pUnit);
}

// 0x00463830
int __fastcall PLAYER_GetBaseIdFromMonsterId(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(nMonsterId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nBaseId;
    }
    return nMonsterId;
}

#include "gen/data/Source/D2Client/UNIT/Player.inc"
