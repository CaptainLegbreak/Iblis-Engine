#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2ClientMenus.h"
#include "D2Win32Types.h"
#include "D2UnitData.h"
#include "D2Path.h"
#include "D2CelContext.h"
#include "D2Drlg.h"
#include "D2GameObjs.h"
#include "D2LevelTxt.h"
#include "D2ClientTypes.h"
#include "D2StateIds.h"
#include "D2ItemsWorld.h"
#include "D2Unicode.h"
#include "D2PlayerModes.h"
#include "D2MonModes.h"
#include "D2ObjModes.h"
#include "D2SetsTxt.h"
#include "D2MsgRecord.h"
#include "D2ClientKeyConfig.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

enum
{
    NUM_HOTKEYS = 114,
};



struct D2PalShiftDataStrc
{
    int unk0x00;
    unsigned char aShift[8][0x100];
    unsigned char aShiftBlood[8][0x100];
};

struct D2PalShiftEntryStrc
{
    int nId;
    D2PalShiftDataStrc* pData;
};

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C

int __cdecl GAME_GetColorFlag();                                                                                 // 0x0044DC60

int __cdecl sub_0044DA90();                                                                                 // 0x0044DA90

int __fastcall RECORD_DispatchRecordedMessage(D2MsgRecordStrc* pRecord);                                          // 0x00451880

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0

int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0

int __fastcall CUNIT_GetPalShiftIndex(D2UnitStrc* pUnit);                                               // 0x00463EB0

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304



extern int gnAutomapOriginY;                                                                              // 0x007A5208

extern int gnAutomapOriginX;                                                                              // 0x007A520C

extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS];                                                        // 0x007A6F90

D2WheelCallbackFn gpfnWheelUp; // 0x007A7404

D2WheelCallbackFn gpfnWheelDown; // 0x007A7408

extern D2PalShiftEntryStrc* gpPalShiftEntries;                                                     // 0x007B9578

extern unsigned char gaGlobalPalShifts_007B9580[0x1E][0x100];                                               // 0x007B9580

extern int gbGlobalPalShifts_007BB380;                                                                      // 0x007BB380

D2UnitStrc* gapClientUnitTable[6 * 0x80]; // 0x007A5E70

D2UnitStrc* gapServerUnitTable[6 * 0x80]; // 0x007A5270

D2UnitStrc* gpPlayerUnit; // 0x007A6A70

extern D2DrlgActStrc* gpGlobal_007A0634;                                                                             // 0x007A0634

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370

struct D2UnitStrc;

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY);                                                   // 0x00643260

#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

int __fastcall GFXUTIL_UnitSupportsMode(D2UnitStrc* pUnit, int nMode);                                 // 0x004DAE60

int __fastcall GFXUTIL_InitUnitCelContext(D2CelContextStrc* pToken, D2UnitStrc* pUnit, int nArg34, int nArg40, int nArg0, int* pItemId, unsigned char nComponent, int nMode); // 0x004DBB50

int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3);                // 0x006001F0

int __stdcall CelGetWidth(D2CelStrc* pCel);                                                                 // 0x006018C0

int __stdcall CelGetHeight(D2CelStrc* pCel);                                                                // 0x006018F0

int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650

int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0

int __stdcall PARTICLE_GetGfxClientY(D2UnitStrc* pUnit);                                          // 0x004DA0D0

int __stdcall PARTICLE_GetGfxClientZ(D2UnitStrc* pUnit);                                          // 0x004DA0F0

typedef int (__fastcall* SKILLSELECTPROC)(D2UnitStrc* pPlayer, D2UnitStrc* pTarget);

extern SKILLSELECTPROC gpfnSkillSelectProcs[];                                                      // 0x00711F34

int __stdcall sub_O05_EmitArg_SkillId(D2UnitStrc* pUnit);

struct D2GfxLightStrc;

struct D2UnitSpawnExtraStrc
{
    int nArg10;
    int nArg14;
};

struct D2UnitSpawnStrc
{
    unsigned int nUnitId;
    int nClassId;
    int nX;
    int nY;
    D2UnitSpawnExtraStrc tExtra;
    int nMode;
};

extern D2DrlgActStrc* gpAct;                                                                       // 0x007A0634

void __fastcall DLIGHTMAP_ReleaseLight(D2GfxLightStrc* pLight);                                   // 0x004743D0

D2GfxLightStrc* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* pValue);                                         // 0x00643A00

void __stdcall PARTICLE_FreeGfxMotion(D2UnitStrc* pUnit);                                               // 0x004DA080

void __fastcall UNITSND_ReleaseUnitHints(D2UnitStrc* pUnit, int bForce);                               // 0x004CA9C0

void __fastcall MONSTER_FreeClientUnit(D2UnitStrc* pUnit);                                             // 0x004AED30

void __fastcall ITEM_ReleaseItemUnit(D2UnitStrc* pUnit);                                            // 0x004C1A70

void __fastcall OBJECT_ReleaseObjectUnit(D2UnitStrc* pUnit);                                                // 0x004BCA50

void __fastcall MISSILE_FreeMissileUnit(D2UnitStrc* pMissile);                                         // 0x004CD170

void __fastcall CUNITEVENT_FreeCltUnitEvents(D2UnitStrc* pUnit);                                          // 0x004DC0C0

void __fastcall SCMD_FreePacketBuffer(void* pArg);                                                  // 0x0045F9F0

void __cdecl UI_FreePlayerUI();                                                                                // 0x00453DE0

void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection);                         // 0x006488A0

void __fastcall GAME_SetStandStillHeld(int nValue);                                                          // 0x0044BEA0

void __cdecl UI_LoadPlayerUI();                                                                   // 0x00453D90

void __fastcall VIEW_ResetSelectionForUnit(D2UnitStrc* pUnit);                                                            // 0x004879D0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0

void __fastcall ITEM_UpdateItemLink(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce, int bClamp);  // 0x004C0EC0

int __cdecl GAME_IsExpansion();                                                                                 // 0x0044DCC0

D2ActiveRoomStrc* __fastcall CUNIT_FindRoomBySubtile(int nX, int nY);                                // 0x00465420

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40

void __fastcall MISSILE_InitMissileUnit(D2UnitStrc* pMissile, D2ActiveRoomStrc* pRoom, int nTargetX, int nTargetY, int nUnused); // 0x004CD0A0

void __stdcall UNITS_InitializeStaticPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);      // 0x00620AE0

void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);        // 0x00620A70

int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);                           // 0x0064C350

void __fastcall PLAYERLIST_InitGfxData(D2UnitStrc* pUnit);                                                // 0x004DC510

void __fastcall OBJECT_UpdateObjectOverlay(D2UnitStrc* pUnit);                                        // 0x004BC8D0

D2UnitStrc* __fastcall CUNIT_AddClientMonster(D2UnitSpawnStrc* pSpawn, void* pArg2, unsigned char* pArg3, int nArg4, int nArg5, int nArg6); // 0x00466360

int CUNIT_AddUnitToTable(D2UnitStrc* pUnit); // 0x00463A50

struct D2InventoryStrc;

struct Unicode;

struct D2MonsterInfo16Strc
{
    unsigned int aValues[4];
};

struct D2MonsterDataLocalStrc
{
    char unk0x00[0x04];
    D2MonsterInfo16Strc tInfo;
};

struct D2HirelingInfoStrc
{
    unsigned short wValue;
    char unk0x02[2];
    unsigned int dwValue;
    int unk0x08;
    int unk0x0C;
};

unsigned char __cdecl GAME_GetDifficulty();                                                         // 0x0044DCD0

void __fastcall GFX_FreeGfxData(D2UnitStrc* pUnit);                                                // 0x0046EC10

int __fastcall sub_00477620_RollUnitValue(D2UnitStrc* pUnit, unsigned short nOffset); // 0x00477620

D2ClientEntryStrc* __fastcall ROSTERPETS_FindEntry(int nKey);                                             // 0x00478E40

int __fastcall ROSTERPETS_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny);                   // 0x00478F20

int __fastcall ROSTER_GetPetType(int nUnitId);                                                        // 0x00479180

int __fastcall ROSTERPETS_IsOwnedByPlayer(D2UnitStrc* pUnit);                                             // 0x004791B0

unsigned char* __fastcall MONUNIQUE_GetMonUmods(D2UnitStrc* pUnit);                                  // 0x004AC740

void __fastcall sub_004AC7A0(D2UnitStrc* pUnit, unsigned short wValue);                                     // 0x004AC7A0

short __fastcall sub_004AC7C0_GetSuperUniqueId(D2UnitStrc* pUnit);                                          // 0x004AC7C0

void __fastcall MONSTER_SetClientFlags(D2UnitStrc* pUnit, unsigned short wFlags);                      // 0x004AE0A0

void __fastcall MONSTER_SetOwnerGUID(D2UnitStrc* pUnit, unsigned int dwValue);                                      // 0x004AE150

int __fastcall MONSTER_IsUniqueMonster(D2UnitStrc* pUnit);                                              // 0x004AE360

void __fastcall MONSTER_InitMonster(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nClassId, int nMode); // 0x004AE8D0

void __fastcall MONSTER_InitHireling(D2UnitStrc* pUnit, D2HirelingInfoStrc* pInfo);                    // 0x004B1090

void __fastcall UNITSND_PlayInitSound(D2UnitStrc* pUnit);                                              // 0x004CC380

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0

void __fastcall MONSTERS_SetMonsterNameInMonsterData(D2UnitStrc* pMonster, const Unicode* wszName);         // 0x0063E810

int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit);                                                // 0x0063EE90

D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId);                         // 0x006556E0

static D2UnitStrc* __stdcall CUNIT_FindUnitInTable(D2UnitStrc** ppTable, unsigned int nUnitId, int nHash, int nUnitType); // 0x00463940

static void CUNIT_ApplyClassEffects(D2UnitStrc* pUnit, int nClassId); // 0x004656C0

void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

void __stdcall PARTICLE_ResetGfxMotion(D2UnitStrc* pUnit);                                              // 0x004DA000

void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0

void __stdcall GFXUTIL_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200

void __stdcall GFXUTIL_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA2A0

void __fastcall GFXUTIL_SetMotionFlagMask(D2UnitStrc* pUnit, int bSet);                                  // 0x004DA6E0

static D2UnitStrc* CUNIT_InsertUnit(D2UnitStrc* pUnit); // 0x00465F20

struct D2DynamicPathStrc;

struct D2UnitTargetStrc;

#define MONSTATS2FLAGINDEX_ISATT 9

#define UNITFLAG_CANBEATTACKED 0x00000004

#define UNITFLAG_ISDEAD 0x00010000

#define UNIT_HASH_BUCKETS 0x80

#define gpUnitTable_007A5670 (gapServerUnitTable + 2 * UNIT_HASH_BUCKETS)

#define gpUnitTable_007A6270 (gapClientUnitTable + 2 * UNIT_HASH_BUCKETS)

#define SKILLSFLAGINDEX_PERIODIC 38

struct D2PacketListStrc;

struct D2PlayerDataStrc;

struct D2MapAIStrc;

struct D2StaticPathStrc;

struct D2MonStatsTxt;

struct D2MonStats2Txt;

struct D2SkillsTxt;

struct D2SetsTxt;

struct D2SetItemsTxt;

struct D2UniqueItemsTxt;

struct D2HotkeyStrc;

struct D2ObjectDataStrc;

struct D2DrlgCoordsStrc;

struct D2DataTablesStrc;

struct D2ObjectsTxt;

struct D2LevelsTxt;

struct D2ActiveRoomStrc;

struct D2CoordStrc;

struct D2ItemsTxt;

struct D2PresetUnitStrc;

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern D2DrlgActStrc* gpDrlgAct_007A0634; // 0x007A0634

void __fastcall UNITMODE_UpdateUnit(D2UnitStrc* pUnit); // 0x00480810

void __fastcall sub_0046D780(D2UnitStrc* pUnit); // 0x0046D780

char __fastcall OBJECT_RunClientFunction(D2UnitStrc* pUnit); // 0x004BDEE0

int __fastcall GFX_GetGfxBasePalShift(D2GfxDataStrc* pGfxData); // 0x0046F1F0

int __fastcall GFX_GetGfxPalShift(D2GfxDataStrc* pGfxData); // 0x0046F250

D2UnitStrc* __cdecl SELECT_GetSelectedUnit(); // 0x00467A10

void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int bSetBothDirections); // 0x00649EF0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100

int __fastcall OBJECT_UpdateEnvObject(D2UnitStrc* pUnit, int nArg); // 0x004BC5E0

void __fastcall GFX_RefreshPathTarget(D2UnitStrc* pUnit); // 0x00480420

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

unsigned short __fastcall ROSTER_LookupPartyNumber(D2UnitStrc* pUnit); // 0x00479C00

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

int __fastcall PLAYER_ApplyUnitCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int bForce); // 0x00461250

void __cdecl SELECT_ClearSelection(); // 0x00466FE0

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140

void __cdecl GFXUTIL_StartFadeTimer(); // 0x004DBFE0

void __stdcall DUNGEON_UpdatePops(D2ActiveRoomStrc* pRoom, int nX, int nY, int bChanged); // 0x0061ACD0

unsigned char __stdcall DATATBLS_GetNoPerFromLevelsTxt(int nLevelId); // 0x0061DBE0

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

int __stdcall D2Common_10231(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit_unused, D2ActiveRoomStrc* pRooms, unsigned short nX, unsigned short nY); // 0x00650C20

void __cdecl AUTOMAP_SkipAutomapReveal(); // 0x00459140

void __fastcall sub_00472C20_PlayerMoved(int nArg); // 0x00472C20

int __stdcall D2Common_11020(D2UnitStrc* pUnit); // 0x00645630

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit); // 0x00463860

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

int __fastcall sub_M210_EmitTest(D2UnitStrc* pPlayer, D2UnitStrc* pUnit);

int __fastcall sub_M210_EmitUse(D2UnitStrc* pUnit);


typedef int (__stdcall* D2FarProcFn)();

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __cdecl TEXT_ResetTextBox(); // 0x0049F960

int __stdcall SFileUnloadFile(void* pBuffer); // 0x00416710

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

extern unsigned char gabColors_007BCAD8[5]; // 0x007BCAD8

extern int gnInvPanelMode; // 0x007BCBF0

extern int gnDialogState; // 0x00721E34

extern int gnHoverTopX; // 0x00721E3C

extern int gnHoverTopY; // 0x00721E40

extern int gnHoverBottomX; // 0x00721E44

extern int gnHoverBottomY; // 0x00721E48

extern int gnHoverCellX; // 0x00721E4C

extern int gnHoverCellY; // 0x00721E50

extern int gbHoverInGrid; // 0x007BCBE4

extern int gbHoverInBodyLoc; // 0x007BCBE8

extern int gpHoverItem; // 0x007BCBF4

extern int gpLastHoverItem; // 0x007BCBF8

extern D2TextHeaderStrc* gpTextHeader; // 0x007BF250

extern int gnTradeState; // 0x007C0E7C

extern unsigned char* gpDDrawDebugFontGlyphs; // 0x008815AC

extern void* gpReply_008818D0; // 0x008818D0

extern "C" void* gpGidFileData; // 0x00882744

extern "C" void* gpClhFileData; // 0x00882750

const Unicode* __fastcall sub_00463810_GetMonsterName(D2UnitStrc* pUnit); // 0x00463810

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

const Unicode* __fastcall sub_00464A30_GetWarpName(D2ActiveRoomStrc* pRoom, D2UnitStrc* pTile); // 0x00464A30

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

D2UnitStrc* __fastcall CUNIT_SpawnPresetUnit(int nClassId, int nX, int nY, int nUnitType, int nArg); // 0x00466730

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

static inline void CUNIT_PlayOverlaySound(D2UnitStrc* pUnit, int nOverlay); // 0x00464E20

static void CUNIT_SpawnPresetUnitInRoom(D2ActiveRoomStrc* pRoom, D2PresetUnitStrc* pPresetUnit); // 0x004667F0

int gnPeriodOfDay; // 0x007A6A74

struct D2RectStrc;

struct D2CoordPairStrc;

struct D2MonStats2SelectStrc;

static int __stdcall CUNIT_GetUnitSelectRect(D2UnitStrc* pUnit, int nMode, D2RectStrc* pRect, unsigned int nFrame); // 0x004640A0

extern "C" __declspec(dllimport) int __stdcall PtInRect(const D2RectStrc*, D2CoordPairStrc);

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_0045AE90(); // 0x0045AE90

int __fastcall sub_00451F30(D2UnitStrc*,unsigned int); // 0x00451F30

int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc*); // 0x00621190

void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc*,int*,int*,int*,const char*,int); // 0x00645270

int __fastcall GFX_HitTestUnitGfx(D2UnitStrc*,int,int,int,int); // 0x00470860

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

int __fastcall CUNIT_IsPointInTileRect(D2UnitStrc*,int,int); // 0x00463EE0

int __fastcall GFXUTIL_UpdateUnitGfx(D2UnitStrc*,int); // 0x004DB670

D2UnitStrc* gapAiTargets[1]; // 0x007A7470

int gbGoldButtonDisabled; // 0x007BCE2C

static int __stdcall CUNIT_CheckMonsterSkillSelect(D2UnitStrc* pUnit, D2UnitStrc* pPlayer); // 0x00464310

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

#define gpUnitTable_007A5470 (gapServerUnitTable + 1 * 0x80)

#define gpUnitTable_007A5870 (gapServerUnitTable + 3 * 0x80)

#define gpUnitTable_007A5E70 (gapClientUnitTable + 0 * 0x80)

#define gpUnitTable_007A6070 (gapClientUnitTable + 1 * 0x80)

#define gpUnitTable_007A6470 (gapClientUnitTable + 3 * 0x80)

#define gpUnitTable_007A6670 (gapClientUnitTable + 4 * 0x80)

union D2SeedStrc;

struct D2UnitSpawnExtraStrc;

struct D2UnitSpawnStrc;

typedef void (__fastcall* UNITFN)(D2UnitStrc* pUnit);

void __stdcall CUNIT_FreeUnitTable(D2UnitStrc** ppTable); // 0x00463CC0

void __fastcall CUNIT_FreeUnitModStats(D2UnitStrc* pUnit); // 0x00463D80

void __fastcall CUNIT_SyncFromServerUnit(D2UnitStrc* pUnit); // 0x00465070

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int id); // 0x0045C4B0

int __fastcall ROSTERPETS_FindRosterIndex(int unitId); // 0x00479150

extern const unsigned char gnSkillMask_006CE26C; // 0x006CE26C

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

D2UnitStrc* __fastcall CUNIT_FindServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x004639B0

D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

void __fastcall CUNIT_SetTargetByGUID(D2UnitStrc* pUnit, int nUnitType, unsigned int nUnitId); // 0x004643F0

static int __stdcall CUNIT_IsItemInInventory(D2UnitStrc* pOwner, D2UnitStrc* pItem, D2UnitStrc* pUnit); // 0x00464D20

static int __stdcall CUNIT_IsItemOwnedByOther(D2UnitStrc* pOwner, D2UnitStrc* pItem); // 0x00464D90

static void CUNIT_FreeUnit(D2UnitStrc* pUnit); // 0x00465870

void __cdecl CUNIT_FreeAllUnits(); // 0x004659C0

static void CUNIT_RemoveUnitFromTable(unsigned int nUnitId, int nUnitType, D2UnitStrc** ppTable, int nHash); // 0x00465E80

void __fastcall CUNIT_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465EE0

void __fastcall CUNIT_RemoveServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465F00

void __fastcall CUNIT_RemoveInventoryUnits(D2UnitStrc* pUnit, int bCheckOwner); // 0x00466CB0

static D2UnitStrc* __stdcall CUNIT_InitUnit(unsigned int nUnitId, int nClassId, int nY, int nUnitType, int nArg5, int nArg6, D2UnitStrc* pUnit, int nX); // 0x00465FD0

D2UnitStrc* __fastcall CUNIT_CreatePlayerUnit(unsigned int nUnitId, int nClassId, int nX, int nY, char* szName); // 0x00466200

D2UnitStrc* __fastcall CUNIT_AllocClientUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5); // 0x004661C0

D2UnitStrc* __fastcall CUNIT_CreateObjectUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5, int nArg6, unsigned char nInteractType); // 0x00466300

static inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag);

static inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag);

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

struct D2KeyConfigFileStrc;

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType);

D2UnitStrc* __fastcall CUNIT_FindServerSideUnit(unsigned int nUnitId, int nUnitType);

D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

static int __stdcall CUNIT_CheckSkillSelectProc(D2UnitStrc* pPlayer, D2UnitStrc* pTarget, int nSkillId); // 0x004642B0

struct D2TileRectStrc
{
    int unk0x00;
    int nX;
    int nY;
    int nWidth;
    int nHeight;
};

void __stdcall STATLIST_FreeModStats(void* pArg); // 0x00625960

// 0x004645B0
static int __stdcall CUNIT_CanInterruptSequence(int nUnused, D2UnitStrc* pUnit); // 0x004645B0

D2UnitStrc* __stdcall DEBUG_GetUnitFromTypeAndGUID(int nUnitType, int nUnitId); // 0x00534650

int __stdcall D2COMMON_10209_PathCheckPathingFlag(D2DynamicPathStrc* pPath); // 0x00648770

void __stdcall PATH_SetPathingFlag(D2DynamicPathStrc* pPath, int nArg); // 0x00648750

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize);

extern "C" char* __cdecl strcat(char* szDst, const char* szSrc);

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

D2ActiveRoomStrc* __stdcall DUNGEON_FindRoomBySubtileCoordinates(D2DrlgActStrc* pAct, int a2, int a3); // 0x00619DA0

void* __fastcall FOG_CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960

int __fastcall FOG_ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x004069B0

int __fastcall FOG_CloseFile(void* hFile); // 0x004069A0

void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

extern int gnTimerEnd; // 0x007A7464

extern int gnScreenWidth; // 0x0071146C

int __fastcall CUNIT_IsPetSkillTarget(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00464EC0

int __fastcall ROSTER_CanLoot(int nUnitId1, int nUnitId2); // 0x0047A4F0

unsigned int __fastcall GFXUTIL_TestRelationFlags(int nUnitId1, int nUnitId2, unsigned int nFlags); // 0x004DC440

extern "C" void* __cdecl memmove(void*, const void*, unsigned int); // 0x00683840

static int __stdcall CUNIT_IsInObjectSelectBox(int nY, D2ObjectsTxt* pObjectsTxtRecord, D2UnitStrc* pUnit, int nX);

static int CUNIT_AddUnitToTable(D2UnitStrc* pUnit);

void __fastcall CUNIT_SetPlayerUnit(D2UnitStrc* pUnit); // 0x00463D90

void __fastcall CUNIT_SetTargetByGUID(D2UnitStrc* pUnit, int nUnitType, unsigned int nUnitId);

static int __stdcall CUNIT_IsItemInInventory(D2UnitStrc* pOwner, D2UnitStrc* pItem, D2UnitStrc* pUnit);

static int __stdcall CUNIT_IsItemOwnedByOther(D2UnitStrc* pOwner, D2UnitStrc* pItem);

static void CUNIT_FreeUnit(D2UnitStrc* pUnit);

void __cdecl CUNIT_FreeAllUnits();

static void CUNIT_RemoveUnitFromTable(unsigned int nUnitId, int nUnitType, D2UnitStrc** ppTable, int nHash);

void __fastcall CUNIT_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType);

void __fastcall CUNIT_RemoveServerSideUnit(unsigned int nUnitId, int nUnitType);

void __fastcall CUNIT_RemoveInventoryUnits(D2UnitStrc* pUnit, int bCheckOwner);

static D2UnitStrc* __stdcall CUNIT_InitUnit(unsigned int nUnitId, int nClassId, int nY, int nUnitType, int nArg5, int nArg6, D2UnitStrc* pUnit, int nX);

D2UnitStrc* __fastcall CUNIT_CreatePlayerUnit(unsigned int nUnitId, int nClassId, int nX, int nY, char* szName);

D2UnitStrc* __fastcall CUNIT_AllocClientUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5);

D2UnitStrc* __fastcall CUNIT_CreateObjectUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5, int nArg6, unsigned char nInteractType);

D2UnitStrc* __fastcall CUNIT_SpawnPresetUnit(int nClassId, int nX, int nY, int nUnitType, int nArg);

int __stdcall CUNIT_CheckSkillSelectProc(D2UnitStrc* pPlayer, D2UnitStrc* pTarget, int nSkillId); // 0x004642B0


int __fastcall CUNIT_IsUnitSelectable(D2UnitStrc* pUnit, int nX, int nY, int bHitTest);



// 0x004637F0
unsigned char* __fastcall CUNIT_GetMonsterComponents(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent;
    }
    return 0;
}

static inline D2MonStatsTxt* MONSTATS_GetRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

static inline int MONSTATS_GetBaseIdInline(int nClassId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTATS_GetRecordInline(nClassId);
    if (!pMonStatsTxtRecord)
        return nClassId;
    return pMonStatsTxtRecord->nBaseId;
}

// 0x00463860
int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        return MONSTATS_GetBaseIdInline(pUnit->dwClassId);
    return -1;
}

inline D2MonStats2Txt* UNITS_GetMonStats2TxtRecordFromMonsterId_Inl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }
    return 0;
}

// 0x004638A0
int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag)
{
    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId_Inl(nMonsterId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }
    return pMonStats2TxtRecord->nFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

// 0x00463900
int __fastcall CUNIT_ValidateMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return nMonsterId;
    }
    return -1;
}

// 0x00463920
static inline D2UnitStrc** CUNIT_GetClientHashTable(int nUnitType)
{
    return &gapClientUnitTable[nUnitType * 0x80];
}

// 0x00463930
static inline D2UnitStrc** CUNIT_GetServerHashTable(int nUnitType)
{
    return &gapServerUnitTable[nUnitType * 0x80];
}

// 0x00463940
static D2UnitStrc* __stdcall CUNIT_FindUnitInTable(D2UnitStrc** ppTable, unsigned int nUnitId, int nHash, int nUnitType)
{
    for (D2UnitStrc* pUnit = ppTable[nHash]; pUnit; pUnit = pUnit->pListNext)
    {
        if (pUnit->dwUnitId == nUnitId)
        {
            D2_ASSERT(pUnit->dwUnitType == nUnitType, 0x5A);
            return pUnit;
        }
    }
    return 0;
}

// 0x00463990
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType)
{
    return CUNIT_FindUnitInTable(&gapClientUnitTable[nUnitType * 0x80], nUnitId, nUnitId & 0x7F, nUnitType);
}

// 0x004639B0
D2UnitStrc* __fastcall CUNIT_FindServerSideUnit(unsigned int nUnitId, int nUnitType)
{
    return CUNIT_FindUnitInTable(&gapServerUnitTable[nUnitType * 0x80], nUnitId, nUnitId & 0x7F, nUnitType);
}

// 0x004639D0
D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x83);
    if (UNIT_HasFlagEx(pUnit, 0x400))
    {
        const int nOwnerType = pUnit->dwOwnerType;
        const unsigned int nOwnerGUID = pUnit->dwOwnerGUID;
        const int nHash = nOwnerGUID & 0x7F;
        if (nOwnerType == 3)
        {
            return CUNIT_FindUnitInTable(&gapServerUnitTable[nOwnerType * 0x80], nOwnerGUID, nHash, nOwnerType);
        }
        return CUNIT_FindUnitInTable(&gapClientUnitTable[nOwnerType * 0x80], nOwnerGUID, nHash, nOwnerType);
    }
    return 0;
}

static inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (!pUnit)
        return 0;
    return (pUnit->dwFlags & nFlag) != 0;
}

inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

static inline int CUNIT_GetUnitClassId(D2UnitStrc* pUnit)
{
    int nClassId = -1;
    if (pUnit)
    {
        nClassId = pUnit->dwClassId;
    }
    return nClassId;
}

// 0x00463A50
static int CUNIT_AddUnitToTable(D2UnitStrc* pUnit)
{
    if (UNIT_HasFlag(pUnit, 0x200000))
    {
        if (CUNIT_FindServerSideUnit(pUnit->dwUnitId, pUnit->dwUnitType))
        {
            return 0;
        }
        D2_ASSERT(!CUNIT_FindServerSideUnit(pUnit->dwUnitId, pUnit->dwUnitType), 0x9C);
    }
    else
    {
        if (CUNIT_FindClientUnit(pUnit->dwUnitId, pUnit->dwUnitType))
        {
            return 0;
        }
        D2_ASSERT(!CUNIT_FindClientUnit(pUnit->dwUnitId, pUnit->dwUnitType), 0xA5);
    }

    sub_004CC160(pUnit, 1);

    const unsigned int nUnitId = pUnit->dwUnitId;
    const int nType = pUnit->dwUnitType;
    D2UnitStrc** ppTable;
    int nHash;
    if (UNIT_HasFlag(pUnit, 0x200000))
    {
        nHash = nUnitId & 0x7F;
        ppTable = &gapServerUnitTable[nType * 0x80];
    }
    else
    {
        nHash = nUnitId & 0x7F;
        ppTable = &gapClientUnitTable[nType * 0x80];
    }

    D2UnitStrc* pNext = ppTable[nHash];
    D2UnitStrc* pPrev = 0;
    for (;;)
    {
        if (!pNext)
        {
            pUnit->pListNext = pNext;
            break;
        }
        if (pNext->dwUnitId <= nUnitId)
        {
            pUnit->pListNext = pNext;
            break;
        }
        pPrev = pNext;
        pNext = pNext->pListNext;
    }
    if (pPrev)
    {
        pPrev->pListNext = pUnit;
    }
    else
    {
        ppTable[nHash] = pUnit;
    }

    return 1;
}

// 0x00463B80
static void CUNIT_QueueIdleMove(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        const int nMode = pUnit->dwAnimMode;
        if (UNITS_GetRoom(pUnit))
        {
            switch (nMode)
            {
            case PLRMODE_NEUTRAL:
            case PLRMODE_TOWNNEUTRAL:
                PLAYER_ApplyUnitCommand(7, pUnit, 0, 1);
                break;
            }
        }
    }
}

// 0x00463C60
static inline void CUNIT_RemoveUnitFromRoom(D2UnitStrc* pUnit)
{
    if (gpGlobal_007A0634)
    {
        UNITROOM_RemoveUnitFromRoom(pUnit);
    }
}

// 0x00463C70
void __cdecl CUNIT_ClearUnitTables()
{
    for (int i = 0; i < 6 * 0x80; ++i) gapClientUnitTable[i] = 0;
    for (int i = 0; i < 6 * 0x80; ++i) gapServerUnitTable[i] = 0;
}

// 0x00463C90
static void __stdcall CUNIT_ForEachUnitInTable(D2UnitStrc** ppTable, UNITFN pfnCallback)
{
    for (int i = 0; i < 0x80; ++i)
    {
        D2UnitStrc* pUnit = ppTable[i];
        while (pUnit)
        {
            D2UnitStrc* pNext = pUnit->pListNext;
            pfnCallback(pUnit);
            pUnit = pNext;
        }
    }
}

static inline D2UnitStrc* CLIENT_FindUnitInHashTable_Inl(int nUnitId, int nUnitType)
{
    D2UnitStrc* pUnit = gapServerUnitTable[(nUnitType << 7) + (nUnitId & 0x7F)];
    while (pUnit)
    {
        if (pUnit->dwUnitId == nUnitId)
        {
            D2_ASSERT(pUnit->dwUnitType == nUnitType, 0x5A);
            return pUnit;
        }
        pUnit = pUnit->pListNext;
    }
    return 0;
}

// 0x00463CC0
void __stdcall CUNIT_FreeUnitTable(D2UnitStrc** ppTable)
{
    for (int i = 0; i < UNIT_HASH_BUCKETS; ++i)
    {
        D2UnitStrc* pUnit = ppTable[i];
        while (pUnit)
        {
            D2UnitStrc* pNext = pUnit->pListNext;
            const int nUnitId = pUnit->dwUnitId;
            const int nUnitType = pUnit->dwUnitType;
            UNITMODE_UpdateUnit(pUnit);
            D2UnitStrc* pFound = CLIENT_FindUnitInHashTable_Inl(nUnitId, nUnitType);
            if (pFound)
            {
                if (pFound->dwUnitType == UNIT_MONSTER)
                {
                    sub_0046D780(pFound);
                }
                else if (pFound->dwUnitType == UNIT_OBJECT)
                {
                    OBJECT_RunClientFunction(pFound);
                }
            }
            pUnit = pNext;
        }
    }
}

// 0x00463D70
void __cdecl sub_00463D70_Empty()
{
}

// 0x00463D80
void __fastcall CUNIT_FreeUnitModStats(void* pArg)
{
    STATLIST_FreeModStats(pArg);
}


static inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
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

static inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
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

// 0x00463D90
void __fastcall CUNIT_SetPlayerUnit(D2UnitStrc* pUnit)
{
    if (gpPlayerUnit)
    {
        UI_FreePlayerUI();
    }

    if (pUnit)
    {
        sub_006488A0_SetDirection(pUnit->pDynamicPath, 0);
        gnCharClass_007A0522 = (unsigned char)CUNIT_GetUnitClassId(pUnit);
        GAME_SetStandStillHeld(0);
        UI_LoadPlayerUI();
    }

    gpPlayerUnit = pUnit;
}

// 0x00463DD0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit()
{
    return gpPlayerUnit;
}

// 0x00463DE0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit()
{
    return gpPlayerUnit;
}

void __fastcall sub_M109_Emit_00464E20(D2UnitStrc* pUnit, int nOverlay)
{
    if (pUnit)
        CUNIT_PlayOverlaySound(pUnit, nOverlay);
}

// 0x00463DF0
int __cdecl CUNIT_IsPlayerDeadOrMissing()
{
    D2UnitStrc* pPlayer = gpPlayerUnit;
    if (!pPlayer)
    {
        return 1;
    }
    return pPlayer->dwAnimMode == PLRMODE_DEAD;
}

// 0x00463E10
D2GfxDataStrc* __fastcall CUNIT_GetGfxData(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;
    return pUnit->pGfxData;
}


// 0x00463E20
void __fastcall CUNIT_SetBasePalShiftIndex(D2UnitStrc* pUnit, int nValue)
{
    D2_ASSERT(pUnit, 0x563);
    sub_0046F1C0(pUnit->pGfxData, nValue);
}

// 0x00463E50
int __fastcall CUNIT_GetBasePalShiftIndex(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x56C);
    return GFX_GetGfxBasePalShift(pUnit->pGfxData);
}

// 0x00463E80
void __fastcall CUNIT_SetPalShiftIndex(D2UnitStrc* pUnit, int nValue)
{
    D2_ASSERT(pUnit, 0x575);
    sub_0046F220(pUnit->pGfxData, nValue);
}

// 0x00463EB0
int __fastcall CUNIT_GetPalShiftIndex(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x57E);
    return GFX_GetGfxPalShift(pUnit->pGfxData);
}

// 0x00463EE0
int __fastcall CUNIT_IsPointInTileRect(D2UnitStrc* pUnit, int nX, int nY)
{
    D2_ASSERT(pUnit->dwUnitType == UNIT_TILE, 1419);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2TileRectStrc* pRect = sub_00619620(pRoom, pUnit);
    if (!pRect)
    {
        return 0;
    }

    int nUnitX = UNITS_GetXPositionInline(pUnit);
    int nUnitY = UNITS_GetYPositionInline(pUnit);
    DUNGEON_GameSubtileToClientCoords(&nUnitX, &nUnitY);

    const int nLeft = pRect->nX + nUnitX;
    const int nTop = pRect->nY + nUnitY;
    if (nX >= nLeft && nY >= nTop && nX <= nLeft + pRect->nWidth && nY <= nTop + pRect->nHeight)
    {
        return 1;
    }
    return 0;
}


inline int UNITS_InlineGetXPosition(D2UnitStrc* pUnit)
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

inline int UNITS_InlineGetYPosition(D2UnitStrc* pUnit)
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

// 0x00463FE0
static int __stdcall CUNIT_IsInObjectSelectBox(int nY, D2ObjectsTxt* pObjectsTxtRecord, D2UnitStrc* pUnit, int nX)
{
    int nUnitX = UNITS_InlineGetXPosition(pUnit);
    int nUnitY = UNITS_InlineGetYPosition(pUnit);
    DUNGEON_GameSubtileToClientCoords(&nUnitX, &nUnitY);

    const int nLeft = pObjectsTxtRecord->dwLeft + nUnitX;
    const int nTop = pObjectsTxtRecord->dwTop + nUnitY;
    if (nX >= nLeft && nY >= nTop && nX <= pObjectsTxtRecord->dwWidth + nLeft && nY <= pObjectsTxtRecord->dwHeight + nTop)
    {
        return 1;
    }

    return 0;
}

// 0x004640A0
static int __stdcall CUNIT_GetUnitSelectRect(D2UnitStrc* pUnit, int nMode, D2RectStrc* pRect, unsigned int nFrame)
{
    if (GFXUTIL_UnitSupportsMode(pUnit, nMode))
    {
        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));

        int nOut;
        if (GFXUTIL_InitUnitCelContext(&tContext, pUnit, 0, UNITS_GetDirection(pUnit), nFrame, &nOut, nMode, -1) && sub_006001F0(&tContext, 0, 1))
        {
            D2CelStrc* pCell = tContext.pCel;
            if (pCell)
            {
                D2_ASSERT(nFrame <= tContext.nFrames, 0x5DF);

                pRect->nLeft = (CelGetOffsetX(pCell) - 12) + UNITS_GetClientCoordX(pUnit);
                pRect->nRight = CelGetWidth(pCell) + pRect->nLeft + 24;
                pRect->nTop = CelGetOffsetY(pCell) + UNITS_GetClientCoordY(pUnit) + 12;
                pRect->nBottom = pRect->nTop - CelGetHeight(pCell) - 24;

                const int nTop = pRect->nTop;
                const int nWidth = pRect->nRight - pRect->nLeft;
                if (nWidth < 32)
                {
                    pRect->nLeft -= (32 - nWidth) >> 1;
                    pRect->nRight = ((32 - nWidth) >> 1) + pRect->nRight;
                }

                const int nHeight = nTop - pRect->nBottom;
                if (nHeight < 32)
                {
                    const int nPad = (32 - nHeight) >> 1;
                    pRect->nTop = nTop + nPad;
                    pRect->nBottom -= nPad;
                }

                const int nGfxOffsetX = sub_004DA0B0_GetUnitGfxOffsetX(pUnit);
                const int nGfxOffsetY = PARTICLE_GetGfxClientY(pUnit) + PARTICLE_GetGfxClientZ(pUnit);
                pRect->nLeft += nGfxOffsetX;
                pRect->nRight += nGfxOffsetX;
                pRect->nTop += nGfxOffsetY;
                pRect->nBottom += nGfxOffsetY;
                return 1;
            }
        }
    }

    return 0;
}

// 0x00464210
int __fastcall CUNIT_SelectProcCorpse(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    return D2COMMON_11021(pTarget);
}

// 0x00464220
int __fastcall CUNIT_SelectProcConsumable(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    return D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0);
}

// 0x00464230
int __fastcall CUNIT_SelectProcConvertTarget(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    if (!pTarget)
        return 0;
    if (!D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0))
        return 0;
    if (!sub_004B11F0(pTarget))
        return 0;
    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != 1)
        return 0;
    int nClass = CUNIT_GetMonsterBaseId(pTarget);
    if (nClass >= 0 && nClass < sgptDataTables->nMonStatsTxtRecordCount && nClass == 0x4E)
        return 0;
    return 1;
}

// 0x00464280
int __fastcall CUNIT_SkillSelectProc4(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    return D2COMMON_11018(pTarget);
}

// 0x00464290
int __fastcall CUNIT_SelectProcSoftCorpse(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    return D2Common_11020(pTarget);
}

int __fastcall sub_M210_Emit_00464310(D2UnitStrc* pPlayer, D2UnitStrc* pUnit)
{
    if (!sub_M210_EmitTest(pPlayer, pUnit))
        return 0;
    if (CUNIT_CheckMonsterSkillSelect(pUnit, pPlayer))
        return sub_M210_EmitUse(pUnit);
    return sub_M210_EmitUse(pPlayer);
}

// 0x004642A0
int __fastcall CUNIT_SkillSelectProc5(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    return D2COMMON_11019(pTarget);
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord_Inl(int nSkillId)
{
    return nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
}

// 0x004642B0
static int __stdcall CUNIT_CheckSkillSelectProc(D2UnitStrc* pPlayer, D2UnitStrc* pTarget, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord_Inl(nSkillId);
// build: symbol ?gnSkillSelectProcs@* 0x00711F50
    if (pSkillsTxtRecord && pSkillsTxtRecord->nSelectProc > 0 && pSkillsTxtRecord->nSelectProc < gnSkillSelectProcs)
    {
        if (gpfnSkillSelectProcs[pSkillsTxtRecord->nSelectProc](pPlayer, pTarget))
        {
            return 1;
        }
    }

    return 0;
}

// 0x00464310
static int __stdcall CUNIT_CheckMonsterSkillSelect(D2UnitStrc* pUnit, D2UnitStrc* pPlayer)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
        return 0;

    if (CUNIT_CheckSkillSelectProc(pPlayer, pUnit, SKILLS_GetSkillIdFromSkill(UNITS_GetLeftSkill(pPlayer), ".\\UNIT\\CUnit.cpp", 1674)))
        return 1;

    return CUNIT_CheckSkillSelectProc(pPlayer, pUnit, SKILLS_GetSkillIdFromSkill(UNITS_GetRightSkill(pPlayer), ".\\UNIT\\CUnit.cpp", 1678)) != 0;
}

// 0x00464370
int __fastcall CUNIT_IsSelectedUnit(D2UnitStrc* pUnit)
{
    D2UnitStrc* pSelected = SELECT_GetSelectedUnit();
    if (pSelected && pSelected->dwUnitType == UNIT_OBJECT && (DATATBLS_GetObjectsTxtRecord(pSelected->dwClassId)->nSubClass & 0x80))
    {
        return 0;
    }
    return SELECT_GetSelectedUnit() == pUnit;
}

// 0x004643B0
int __fastcall CUNIT_IsPlayerOrMonster(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x793);
    const int nType = pUnit->dwUnitType;
    return nType == 0 || nType == 1;
}

// 0x004643F0
void __fastcall CUNIT_SetTargetByGUID(D2UnitStrc* pUnit, int nUnitType, unsigned int nUnitId)
{
    UNITS_SetTargetUnitForDynamicUnit(pUnit, CUNIT_FindClientUnit(nUnitId, nUnitType));
}

// 0x00464420
void __fastcall CUNIT_TurnTowardPlayer(D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2UnitStrc* pPlayer = gpPlayerUnit;
    D2_ASSERT(pPath, 0x7F3);
    UNITS_ChangeAnimMode(pUnit, 1);
    D2Common_10216(pPath, UNITS_GetXPositionInline(pPlayer), UNITS_GetYPositionInline(pPlayer), 0);
}

// 0x004644E0
void __fastcall CUNIT_PlayerFaceUnit(D2UnitStrc* pUnit)
{
    D2UnitStrc* pPlayer = gpPlayerUnit;
    if (pPlayer && (pPlayer->dwAnimMode == PLRMODE_NEUTRAL || pPlayer->dwAnimMode == PLRMODE_TOWNNEUTRAL))
    {
        D2DynamicPathStrc* pPath = pPlayer->pDynamicPath;
        D2_ASSERT(pPath, 0x802);
        D2Common_10216(pPath, UNITS_GetXPositionInline(pUnit), UNITS_GetYPositionInline(pUnit), 0);
    }
}

// 0x00464600
int __fastcall CUNIT_CanUseSkill(D2UnitStrc* pUnit, int nArg)
{
    if (INVENTORY_GetCursorItem(pUnit->pInventory))
    {
        return 0;
    }

    if (pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    switch (pUnit->dwAnimMode)
    {
    case 0:
    case 4:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 17:
    case 19:
        return 0;

    case 18:
    {
        return CUNIT_CanInterruptSequence(nArg, pUnit);
    }

    case 13:
        if (pUnit->dwClassId == 3)
        {
            return 0;
        }
        break;

    case 14:
        if (pUnit->dwClassId == 6)
        {
            return 0;
        }
        break;

    case 15:
    case 16:
    {
        const int nClass = pUnit->dwClassId;
        if (nClass == 4 || nClass == 6 || nClass == 5)
        {
            return 0;
        }
        break;
    }

    default:
        break;
    }

    return 1;
}

// 0x004646A0
D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom()
{
    D2UnitStrc* pPlayer = gpPlayerUnit;
    if (pPlayer)
    {
        return UNITS_GetRoom(pPlayer);
    }
    return 0;
}

// 0x004646C0
void __cdecl CUNIT_UpdateObjectsForPeriod()
{
    const int nPeriod = ENVIRONMENT_GetPeriodOfDayFromAct(gpDrlgAct_007A0634, 0);
    if (nPeriod != gnPeriodOfDay)
    {
        gnPeriodOfDay = nPeriod;
        for (int i = 0; i < UNIT_HASH_BUCKETS; ++i)
        {
            D2UnitStrc* pUnit = gpUnitTable_007A6270[i];
            while (pUnit)
            {
                D2UnitStrc* pNext = pUnit->pListNext;
                D2_ASSERT(pUnit->dwUnitType == UNIT_OBJECT, 0x88C);
                OBJECT_UpdateEnvObject(pUnit, 0);
                pUnit = pNext;
            }
        }
        for (int i = 0; i < UNIT_HASH_BUCKETS; ++i)
        {
            D2UnitStrc* pUnit = gpUnitTable_007A5670[i];
            while (pUnit)
            {
                D2UnitStrc* pNext = pUnit->pListNext;
                D2_ASSERT(pUnit->dwUnitType == UNIT_OBJECT, 0x896);
                OBJECT_UpdateEnvObject(pUnit, 0);
                pUnit = pNext;
            }
        }
    }
}

// 0x00464770
D2PacketListStrc* __fastcall CUNIT_GetPacketList(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x8A5);
    return pUnit->pPacketList;
}

// 0x004647A0
void __fastcall CUNIT_SetPacketList(D2UnitStrc* pUnit, D2PacketListStrc* pPacketList)
{
    D2_ASSERT(pUnit, 0x8AF);
    pUnit->pPacketList = pPacketList;
}

// 0x004647D0
void __fastcall CUNIT_UpdateAttackableFlag(D2UnitStrc* pUnit)
{
    unsigned int dwFlags = pUnit->dwFlags & ~UNITFLAG_ISDEAD;
    pUnit->dwFlags = dwFlags;
    if (pUnit->dwUnitType != UNIT_MONSTER || MONSTERREGION_CheckMonStats2Flag(pUnit->dwClassId, MONSTATS2FLAGINDEX_ISATT))
    {
        dwFlags |= UNITFLAG_CANBEATTACKED;
        pUnit->dwFlags = dwFlags;
    }
}

// 0x00464810
void __fastcall CUNIT_MarkUnitDead(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x10000;
    }
}

// 0x00464820
int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit)
{
    if (pUnit->dwFlags & 0x10000)
    {
        return 1;
    }

    const int nMode = pUnit->dwAnimMode;
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        if (nMode == 0 || nMode == 0x11)
        {
            return 1;
        }
        break;

    case UNIT_MONSTER:
        if (nMode == 0 || nMode == 0x0C)
        {
            return 1;
        }
        break;
    }

    return 0;
}

static inline int OBJECTS_IsDeadInline(int nClassId, int nMode)
{
    const unsigned char nFlags = DATATBLS_GetObjectsTxtRecord(nClassId)->nFlags1B7;
    return (nFlags & 2) || (nMode == 2 && (nFlags & 1));
}

// 0x00464860
int __fastcall CUNIT_IsUnitDead(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nMode = pUnit->dwAnimMode;
        switch (pUnit->dwUnitType)
        {
        case UNIT_OBJECT:
            if (OBJECTS_IsDeadInline(pUnit->dwClassId, nMode))
            {
                return 1;
            }
            break;
        case UNIT_ITEM:
            return nMode == 3;
        case UNIT_MONSTER:
            if (!MONSTERREGION_CheckMonStats2Flag(pUnit->dwClassId, 0x14) && nMode == 12)
            {
                return 1;
            }
            break;
        case UNIT_PLAYER:
            if (nMode == 17)
            {
                return 1;
            }
            break;
        case UNIT_MISSILE:
            if (pUnit->dwFlags & 0x10000)
            {
                return 1;
            }
            break;
        }
    }
    return 0;
}

// 0x004648F0
D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit)
{
    GFX_RefreshPathTarget(pUnit);
    D2_ASSERT(pUnit->pDynamicPath, 0x946);
    return PATH_GetTargetUnit(pUnit->pDynamicPath);
}

// 0x00464930
void __fastcall CUNIT_FreeLight(D2UnitStrc* pUnit)
{
    if (pUnit->pLight)
    {
        DLIGHTMAP_ReleaseLight(pUnit->pLight);
        pUnit->pLight = 0;
    }
}

static inline int sub_00464EC0_GetUnitType(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

static inline int sub_00464EC0_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

// 0x00464950
void __fastcall CUNIT_ForEachPlayer(UNITFN pfnCallback)
{
    D2_ASSERT(pfnCallback, 0x961);
    CUNIT_ForEachUnitInTable(gpUnitTable_007A5E70, pfnCallback);
}

// 0x00464990
void __fastcall CUNIT_ForEachMonster(UNITFN pfnCallback)
{
    D2_ASSERT(pfnCallback, 0x96C);
    CUNIT_ForEachUnitInTable(gpUnitTable_007A6070, pfnCallback);
}

// 0x004649D0
void __fastcall CUNIT_ForEachObject(UNITFN pfnCallback)
{
    D2_ASSERT(pfnCallback, 0x977);
    CUNIT_ForEachUnitInTable(gpUnitTable_007A6270, pfnCallback);
}

// 0x00464A10
static D2UnitStrc* CUNIT_FindTileUnit(D2UnitStrc* pUnit)
{
    for (; pUnit; pUnit = pUnit->ptRoomNext)
    {
        if (pUnit->dwUnitType == UNIT_TILE)
        {
            return pUnit;
        }
    }
    return 0;
}

// 0x00464A30
const unsigned short* __fastcall CUNIT_GetTileLevelWarpName(D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit)
{
    const int nLevelId = sub_0061A1D0_GetTileLevelId(pRoom, !pUnit ? -1 : pUnit->dwClassId);
    if (nLevelId)
    {
        return DATATBLS_GetLevelsTxtRecord(nLevelId)->wszLevelWarp;
    }
    return 0;
}

// 0x00464A60
const Unicode* __fastcall CUNIT_GetUnitName(D2UnitStrc* pUnit)
{
    const Unicode* pName;
    D2ActiveRoomStrc* pRoom;
    D2UnitStrc* pTile;
    D2ActiveRoomStrc** ppRooms;
    unsigned int nRooms;
    int nValue;
    D2_ASSERT(pUnit, 0x99D);
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    {
        if (pUnit->pObjectData->pObjectTxt->nOpenWarp && pUnit->dwAnimMode == OBJMODE_OPENED)
        {
            pRoom = UNITS_GetRoom(pUnit);
            pTile = CUNIT_FindTileUnit(pRoom->pUnitFirst);
            if (pTile)
            {
                return sub_00464A30_GetWarpName(pRoom, pTile);
            }
            DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRooms, &nRooms);
            for (unsigned int i = 0; i < nRooms; ++i)
            {
                if (ppRooms[i] != pRoom)
                {
                    pTile = CUNIT_FindTileUnit(ppRooms[i]->pUnitFirst);
                    if (pTile)
                    {
                        return sub_00464A30_GetWarpName(ppRooms[i], pTile);
                    }
                }
            }
        }
        if (pUnit->pObjectData->pObjectTxt->nIsDoor)
        {
            nValue = pUnit->dwAnimMode;
            unsigned short nStringId = 0xC9B;
            if (nValue == 5 || nValue == 4)
            {
                nStringId = 0xC9C;
            }
            else if (nValue == 0)
            {
                nStringId = 0xC99;
            }
            else if (nValue == 6)
            {
                nStringId = 0xC9D;
            }
            return D2LANG_GetStringFromTblIndex(nStringId);
        }
        if (UNITS_IsShrine(pUnit))
        {
            return D2LANG_GetStringFromTblIndex(pUnit->pObjectData->InteractType + 0x2A39);
        }
        D2ObjectDataStrc* pObjectData = pUnit->pObjectData;
        if (pObjectData->pObjectTxt->nLockable && (pObjectData->InteractType & 0x80))
        {
            return D2LANG_GetStringFromTblIndex(0xCBE);
        }
        return (const Unicode*)pObjectData->pObjectTxt->wszName;
    }
    case UNIT_MONSTER:
    {
        pName = sub_00463810_GetMonsterName(pUnit);
        if (!sub_00526800(pName))
        {
            return D2LANG_GetStringFromTblIndex(DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId)->wNameStr);
        }
        return pName;
    }
    case UNIT_PLAYER:
    case UNIT_MISSILE:
    case UNIT_TILE:
        return 0;
    case UNIT_ITEM:
        nValue = pUnit->dwClassId;
        return D2LANG_GetStringFromTblIndex(DATATBLS_GetItemsTxtRecord(nValue)->wNameStr);
    }
    return 0;
}

// 0x00464C40
int __fastcall CUNIT_TickDrawDelay(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xA19);
    if (!*(int*)&pUnit->pGfxDataCopy)
    {
        return 0;
    }
    --*(int*)&pUnit->pGfxDataCopy;
    return !STATES_CheckState(pUnit, STATE_ATTACHED);
}

// 0x00464C90
void __fastcall CUNIT_SetDrawDelay(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xA34);
    *(int*)&pUnit->pGfxDataCopy = 3;
}

// 0x00464CC0
int __fastcall CUNIT_GetStartLight(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xA3F);
    return pUnit->dwStartLight;
}

// 0x00464CF0
void __fastcall CUNIT_SetStartLight(D2UnitStrc* pUnit, int nValue)
{
    D2_ASSERT(pUnit, 0xA4A);
    pUnit->dwStartLight = nValue;
}

// 0x00464D20
static int __stdcall CUNIT_IsItemInInventory(D2UnitStrc* pOwner, D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    if (pOwner == pUnit)
    {
        return 0;
    }

    if (pUnit->pInventory)
    {
        for (D2UnitStrc* pEntry = INVENTORY_GetFirstItem(pUnit->pInventory); pEntry; pEntry = INVENTORY_GetNextItem(pEntry))
        {
            D2UnitStrc* pInvItem = INVENTORY_UnitIsItem(pEntry);
            D2_ASSERT(pInvItem, 0xA5B);
            if (pInvItem == pItem)
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x00464D90
static int __stdcall CUNIT_IsItemOwnedByOther(D2UnitStrc* pOwner, D2UnitStrc* pItem)
{
    D2UnitStrc** ppTable = gapClientUnitTable;
    for (int nTable = 0; nTable < 2; ++nTable)
    {
        for (int i = 0; i < 0x80; ++i)
        {
            for (D2UnitStrc* pUnit = ppTable[i]; pUnit; pUnit = pUnit->pListNext)
            {
                if (CUNIT_IsItemInInventory(pOwner, pItem, pUnit))
                {
                    return 1;
                }
            }
        }
        ppTable = &gapClientUnitTable[0x80];
    }
    return 0;
}

// 0x00464E20
static inline void CUNIT_PlayOverlaySound(D2UnitStrc* pUnit, int nOverlay)
{
    switch (nOverlay)
    {
    case 0x97:
        sub_004B9A00(0x18C, pUnit, 0, 0, 0);
        break;
    case 0x98:
        sub_004B9A00(0x18D, pUnit, 0, 0, 0);
        break;
    }
}

// 0x00464E50
void __fastcall CUNIT_SetOverlayWithSound(D2UnitStrc* pUnit, int nOverlay, int nArg)
{
    if (!pUnit)
        return;

    if (nArg > 0)
        GFX_AddUnitOverlay(pUnit, nOverlay, 1, 0, nArg, 0, 0, 0);
    else
        GFX_AddUnitOverlay(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);

    switch (nOverlay)
    {
    case 0x97:
        sub_004B9A00(0x18C, pUnit, 0, 0, 0);
        break;
    case 0x98:
        sub_004B9A00(0x18D, pUnit, 0, 0, 0);
        break;
    }
}

// 0x00464EC0
int __fastcall CUNIT_IsPetSkillTarget(D2UnitStrc* unit, D2UnitStrc* target)
{
    int enabled = 0;
    if (unit && target && (sub_00464EC0_GetUnitType(unit) == 0 || target->dwUnitType == UNIT_MONSTER))
    {
        D2SkillStrc* skill = UNITS_GetLeftSkill(unit);
        if (skill)
        {
            D2SkillsTxt* record = sub_0045C4B0_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(skill, ".\\UNIT\\CUnit.cpp", 0xB4A));
            if (record && (record->nFlags[3] & gnSkillMask_006CE26C))
                enabled = 1;
        }
        skill = UNITS_GetRightSkill(unit);
        if (skill)
        {
            D2SkillsTxt* record = sub_0045C4B0_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(skill, ".\\UNIT\\CUnit.cpp", 0xB55));
            if (record && (record->nFlags[3] & gnSkillMask_006CE26C))
                enabled = 1;
        }
        if (enabled)
        {
            const int nRosterId = ROSTERPETS_FindRosterIndex(target->dwUnitId);
            return nRosterId == sub_00464EC0_GetUnitId(unit);
        }
    }
    return 0;
}


static int __stdcall CUNIT_CanInterruptSequence(int nUnused, D2UnitStrc* pUnit)
{
    int* pDead = &nUnused;
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 1;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAnim != 0x12)
    {
        return 1;
    }

    const unsigned char nFrame = pSkillsTxtRecord->nSeqInput;
    if (!nFrame)
    {
        return 0;
    }

    if (nFrame == 0xFF)
    {
        return 0;
    }

    return (pUnit->dwSeqFrame >> 8) >= nFrame;
}

int __fastcall sub_Emit_004645B0(D2UnitStrc* pUnit, int nArg)
{
    return CUNIT_CanInterruptSequence(nArg, pUnit);
}

static inline D2SkillsTxt* SKILLCLT_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static __forceinline int SKILLCLT_HasFlag26(D2SkillStrc* pSkill, int nLine)
{
    if (pSkill)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLCLT_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNIT\\CUnit.cpp", nLine));
        if (pSkillsTxtRecord && BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 26))
        {
            return 1;
        }
    }
    return 0;
}

// 0x00464F70
int __fastcall CUNIT_IsTargetBlocked(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    int bLeft = 0;
    if (pUnit && pTarget)
    {
        const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
        if (!nUnitType || !pTarget->dwUnitType || pTarget->dwUnitType == UNIT_MONSTER)
        {
            D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pUnit);
            if (pLeftSkill)
            {
                D2SkillsTxt* pSkillsTxtRecord = SKILLCLT_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pLeftSkill, ".\\UNIT\\CUnit.cpp", 2943));
                if (pSkillsTxtRecord && BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 26))
                {
                    bLeft = 1;
                }
            }
            if (SKILLCLT_HasFlag26(UNITS_GetRightSkill(pUnit), 2952) || bLeft)
            {
                int nTargetId = pTarget->dwUnitId;
                if (pTarget->dwUnitType != UNIT_MONSTER || (nTargetId = ROSTERPETS_FindRosterIndex(nTargetId)) != -1)
                {
                    return sub_0047A520(pUnit->dwUnitId, nTargetId) != 0;
                }
            }
        }
    }
    return 0;
}

// 0x00465070
void __fastcall CUNIT_SyncFromServerUnit(D2UnitStrc* pUnit)
{
    D2_ASSERT(!gdwGlobal_007A0610, 0xBAA);

    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
    D2UnitStrc* pServerUnit = DEBUG_GetUnitFromTypeAndGUID(nUnitType, nUnitId);
    if (!pServerUnit)
        return;

    D2DynamicPathStrc* pSrc = pServerUnit->pDynamicPath;
    D2DynamicPathStrc* pDst = pUnit->pDynamicPath;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return;

    const int nX = pSrc->wPosX;
    const int nY = pSrc->wPosY;
    if (nX != pDst->wPosX || nY != pDst->wPosY)
    {
        if (!COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY))
            return;

        D2Common_10231(pDst, pUnit, pRoom, nX, nY);
    }

    pDst->dwPrecisionX = pSrc->dwPrecisionX;
    pDst->dwPrecisionY = pSrc->dwPrecisionY;
    pDst->dwClientCoordX = pSrc->dwClientCoordX;
    pDst->dwClientCoordY = pSrc->dwClientCoordY;
    pDst->dwCurrentPointIdx = pSrc->dwCurrentPointIdx;
    pDst->dwPathPoints = pSrc->dwPathPoints;
    pDst->unk0x38 = pSrc->unk0x38;
    pDst->tTargetCoord = pSrc->tTargetCoord;
    pDst->tPrevTargetCoord = pSrc->tPrevTargetCoord;
    pDst->tFinalTargetCoord = pSrc->tFinalTargetCoord;
    pDst->dwTargetType = pSrc->dwTargetType;
    pDst->dwTargetId = pSrc->dwTargetId;
    pDst->unk0x67 = pSrc->unk0x67;
    pDst->dwSpeed = pSrc->dwSpeed;
    pDst->dwVelocity = pSrc->dwVelocity;
    pDst->nPreviousVelocity = pSrc->nPreviousVelocity;
    pDst->dwMaxVelocity = pSrc->dwMaxVelocity;
    pDst->dwAcceleration = pSrc->dwAcceleration;
    pDst->dwAccelerationsCounter = pSrc->dwAccelerationsCounter;
    pDst->bDistMax = pSrc->bDistMax;
    pDst->nIDAStarInitFScore = pSrc->nIDAStarInitFScore;
    pDst->nStepNum = pSrc->nStepNum;
    pDst->nDistance = pSrc->nDistance;
    pDst->nDirOffset = pSrc->nDirOffset;
    pDst->tDirectionVector = pSrc->tDirectionVector;

    if (pSrc->dwPathPoints)
        memcpy(pDst->PathPoints, pSrc->PathPoints, pSrc->dwPathPoints * sizeof(D2PathPointStrc));

    if (pSrc->nSavedStepsCount)
        memcpy(pDst->SavedSteps, pSrc->SavedSteps, pSrc->nSavedStepsCount * sizeof(D2PathPointStrc));

    pDst->nSavedStepsCount = pSrc->nSavedStepsCount;

    if (pSrc->eType != 8 && pSrc->eType != 11)
        pDst->eType = pSrc->eType;

    if (pSrc->ePrevType != 8 && pSrc->ePrevType != 11)
        pDst->ePrevType = pSrc->ePrevType;

    pDst->ePrevType = pSrc->ePrevType;
    pDst->dwUnitSize = pSrc->dwUnitSize;
    PATH_SetPathingFlag(pDst, D2COMMON_10209_PathCheckPathingFlag(pSrc));

    const unsigned int nMode = pUnit->dwAnimMode;
    const unsigned int nServerMode = pServerUnit->dwAnimMode;
    if (nMode != nServerMode)
    {
        switch (pUnit->dwUnitType)
        {
        case UNIT_PLAYER:
            switch (!pServerUnit ? 0u : pServerUnit->dwAnimMode)
            {
            case 2:
            case 6:
                switch (nMode)
                {
                case 1:
                case 5:
                    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
                        UNITS_ChangeAnimMode(pUnit, 6);
                    else
                        UNITS_ChangeAnimMode(pUnit, 2);
                    break;
                }
                break;

            case 3:
                switch (nMode)
                {
                case 1:
                case 3:
                case 5:
                    UNITS_ChangeAnimMode(pUnit, 3);
                    break;
                }
                break;

            case 1:
            case 5:
                switch (nMode)
                {
                case 2:
                case 3:
                case 6:
                    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
                        UNITS_ChangeAnimMode(pUnit, 5);
                    else
                        UNITS_ChangeAnimMode(pUnit, 1);
                    break;
                }
                break;

            case 18:
                break;

            default:
                if (nMode != 19)
                {
                    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
                    D2SkillStrc* pServerSkill = UNITS_GetUsedSkill(pServerUnit);
                    if (!pSkill)
                        break;

                    if (pServerSkill && (SKILLS_GetFlags(pServerSkill) & 1) && !(SKILLS_GetFlags(pServerSkill) & 2))
                        break;

                    const int nFlags = SKILLS_GetFlags(pSkill);
                    if (!(nFlags & 1))
                        break;

                    SKILLS_SetFlags(pSkill, nFlags | 2);
                    D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
                    return;
                }

                UNITS_ChangeAnimMode(pUnit, nServerMode);
                break;
            }
            break;

        case UNIT_MONSTER:
            switch (nServerMode)
            {
            case 1:
                switch (nMode)
                {
                case 2:
                case 15:
                    UNITS_ChangeAnimMode(pUnit, 1);
                    break;
                }
                break;

            case 2:
                switch (nMode)
                {
                case 1:
                    UNITS_ChangeAnimMode(pUnit, 2);
                    break;
                }
                break;

            case 15:
                switch (nMode)
                {
                case 1:
                    UNITS_ChangeAnimMode(pUnit, 15);
                    break;
                }
                break;
            }
            break;
        }
    }

    D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
}

// 0x00465400
short __fastcall CUNIT_GetPlayerPartyId(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        return ROSTER_LookupPartyNumber(pUnit);
    }
    return -1;
}

// 0x00465420
D2ActiveRoomStrc* __fastcall CUNIT_FindRoomBySubtile(int nX, int nY)
{
    char szMessage[0x200];
    D2UnitStrc* pPlayer = gpPlayerUnit;
    D2ActiveRoomStrc* pRoom = 0;
    if (!nX && !nY)
        return 0;
    if (pPlayer)
    {
        pRoom = UNITS_GetRoom(pPlayer);
        D2ActiveRoomStrc* pFound = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
        if (pFound)
            return pFound;
    }
    D2ActiveRoomStrc* pFound = DUNGEON_FindRoomBySubtileCoordinates(gpGlobal_007A0634, nX, nY);
    if (pFound)
        return pFound;
    SStrPrintf(szMessage, sizeof(szMessage), "Unable to find room for unit...  hControlUnit:%8x  hUnitRoom:%8x  ghAct:%8x  nX:%d  nY:%d", pPlayer, pRoom, gpGlobal_007A0634, nX, nY);
    D2_ASSERT(0, 0x13C);
}

// 0x004654C0
void __fastcall CUNIT_SetUnitPosition(D2UnitStrc* pUnit, int nX, int nY, int bFlag)
{
    D2UnitStrc* pPlayer = gpPlayerUnit;
    if (pUnit == pPlayer)
    {
        SELECT_ClearSelection();
    }
    D2ActiveRoomStrc* pRoom = sub_00465420_FindRoomAt(nX, nY);
    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    D2_ASSERT(pDynamicPath, 0x166);
    if (nX && nY)
    {
        D2_ASSERT(pRoom, 0x168);
    }
    if (pUnit->dwFlags & 0x10000)
    {
        return;
    }
    const int nMode = pUnit->dwAnimMode;
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        if (nMode == PLRMODE_DEATH || nMode == PLRMODE_DEAD)
        {
            return;
        }
        break;
    case UNIT_MONSTER:
        if (nMode == MONMODE_DEATH || nMode == MONMODE_DEAD)
        {
            return;
        }
        break;
    }
    if (pUnit == pPlayer)
    {
        D2ActiveRoomStrc* pOldRoom = UNITS_GetRoom(pUnit);
        if (pOldRoom)
        {
            D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
            D2SkillsTxt* pSkillsTxtRecord;
            if (pSkill && (pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordFromSkill(pSkill)) != 0 && (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_PERIODIC >> 3] & gdwBitMasks[SKILLSFLAGINDEX_PERIODIC & 7]))
            {
                bFlag = 0;
            }
            else if (bFlag)
            {
                D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 0x17D);
                GFXUTIL_StartFadeTimer();
            }
        }
        if (pRoom)
        {
            DUNGEON_UpdatePops(pRoom, nX, nY, pOldRoom != pRoom);
// build: symbol ?D2GFX_SetTownMode@* 0x004F5190
            D2GFX_SetTownMode(!DATATBLS_GetNoPerFromLevelsTxt(DUNGEON_GetLevelIdFromRoom(pRoom)));
            if (pOldRoom)
            {
                D2LevelsTxt* pOldLevel = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pOldRoom));
                D2LevelsTxt* pNewLevel = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
                if (pOldLevel->nPal != pNewLevel->nPal)
                {
                    sub_004FB480_SetActA(pNewLevel->nPal);
                    sub_00600C00_SetActB(pNewLevel->nPal);
                }
            }
        }
    }
    if (!sub_00650BE0_PlaceUnit(pDynamicPath, pUnit, pRoom, nX, nY))
    {
        D2CoordStrc tCoord;
        tCoord.nX = nX;
        tCoord.nY = nY;
        const int nUnitSize = UNITS_GetUnitSizeX(pUnit);
        COLLISION_GetFreeCoordinates(pRoom, &tCoord, nUnitSize, 0x1C09, 1);
        D2_ASSERT(D2Common_10231(pDynamicPath, pUnit, pRoom, tCoord.nX, tCoord.nY), 0x1A9);
    }
    AUTOMAP_SkipAutomapReveal();
    if (pUnit == pPlayer)
    {
        sub_00472C20_PlayerMoved(bFlag);
    }
    CUNIT_QueueIdleMove(pUnit);
}

// 0x004656C0
static void CUNIT_ApplyClassEffects(D2UnitStrc* pUnit, int nClassId)
{
    switch (nClassId)
    {
    case 0xF2:
    case 0x2C0:
        GFX_AddUnitOverlay(pUnit, 0x7A, 3, 0, 0, 0, 0, 0);
        break;
    case 0x14D:
        GFX_AddUnitOverlay(pUnit, 0xBA, 2, 0, 0, 0, 0, 0);
        break;
    case 0x154:
        PARTICLE_ResetGfxMotion(pUnit);
        GFXUTIL_SetMotionVectorA(pUnit, -0x20, -0x20, 0);
        break;
    case 0x155:
        PARTICLE_ResetGfxMotion(pUnit);
        GFXUTIL_SetMotionVectorA(pUnit, -0x20, 0x20, 0);
        break;
    case 0x156:
        PARTICLE_ResetGfxMotion(pUnit);
        GFXUTIL_SetMotionVectorA(pUnit, 0x20, 0x20, 0);
        break;
    case 0x157:
        PARTICLE_ResetGfxMotion(pUnit);
        GFXUTIL_SetMotionVectorA(pUnit, 0x20, -0x20, 0);
        break;
    case 0x15F:
    case 0x160:
    case 0x161:
    {
        const int nBase = (!pUnit ? -1 : pUnit->dwClassId) - 0xB3;
        GFX_AddUnitOverlay(pUnit, nBase, 4, 0, nBase + 3, 0, 0, 0);
        break;
    }
    case 0x196:
        PARTICLE_ResetGfxMotion(pUnit);
        GFXUTIL_SetMotionVectorA(pUnit, 0, 0, -0x37);
        GFXUTIL_SetMotionVectorB(pUnit, 0, 0, 1, 1);
        GFXUTIL_SetMotionVectorC(pUnit, 0, 0, 0x32, 0);
        GFXUTIL_SetMotionFlagMask(pUnit, 1);
        break;
    case 0x1A1:
    case 0x1A2:
        if (pUnit)
        {
            GFX_AddUnitOverlay(pUnit, 0x10E, 2, 0, 0, 0, 0, 0);
        }
        break;
    case 0x209:
        sub_0046BFF0(pUnit);
        break;
    case 0x21F:
        GFX_AddUnitOverlay(pUnit, 0x113, 3, 0, 0, 0, 0, 0);
        break;
    }
}

// 0x00465870
static void CUNIT_FreeUnit(D2UnitStrc* pUnit)
{
    if (pUnit->pLight)
    {
        DLIGHTMAP_ReleaseLight(pUnit->pLight);
        pUnit->pLight = 0;
    }

    D2GfxLightStrc* pRoomLight = D2Common_10958(pUnit, 0);
    if (pRoomLight)
    {
        DLIGHTMAP_ReleaseLight(pRoomLight);
    }

    PARTICLE_FreeGfxMotion(pUnit);
    UNITSND_ReleaseUnitHints(pUnit, 0);
    sub_004CC160(pUnit, -1);

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        if (pUnit->pHoverText)
        {
            sub_0049F3D0(pUnit->pHoverText);
            pUnit->pHoverText = 0;
        }
        sub_00460D50_FreePlayerUnit(pUnit);
        UNITSND_ReleaseUnitHints(pUnit, 1);
        break;

    case UNIT_MONSTER:
        if (pUnit->pHoverText)
        {
            sub_0049F3D0(pUnit->pHoverText);
            pUnit->pHoverText = 0;
        }
        MONSTER_FreeClientUnit(pUnit);
        UNITSND_ReleaseUnitHints(pUnit, 1);
        break;

    case UNIT_ITEM:
        ITEM_ReleaseItemUnit(pUnit);
        ITEMS_FreeItemData(0, pUnit);
        UNITS_FreeStaticPath(pUnit);
        break;

    case UNIT_OBJECT:
        if (pUnit->pHoverText)
        {
            sub_0049F3D0(pUnit->pHoverText);
            pUnit->pHoverText = 0;
        }
        OBJECT_ReleaseObjectUnit(pUnit);
        UNITS_FreeStaticPath(pUnit);
        UNITSND_ReleaseUnitHints(pUnit, 1);
        break;

    case UNIT_MISSILE:
        MISSILE_FreeMissileUnit(pUnit);
        break;

    case UNIT_TILE:
        if (gpAct)
        {
            UNITROOM_RemoveUnitFromRoom(pUnit);
        }
        UNITS_FreeStaticPath(pUnit);
        break;
    }

    CUNITEVENT_FreeCltUnitEvents(pUnit);
    SCMD_FreePacketBuffer(pUnit);

    if (pUnit == gpPlayerUnit)
    {
        CUNIT_SetPlayerUnit(0);
    }

    UNITS_FreeUnit(pUnit);
}

// 0x004659C0
void __cdecl CUNIT_FreeAllUnits()
{
    for (int nType = 0; nType < 6; ++nType)
    {
        for (int i = 0; i < 0x80; ++i)
        {
// build: symbol ?gaUnitTypes@* 0x006D6ABC
            D2UnitStrc* pUnit = gapClientUnitTable[gaUnitTypes[nType] * 0x80 + i];
            while (pUnit)
            {
                D2UnitStrc* pNext = pUnit->pListNext;
                CUNIT_FreeUnit(pUnit);
                pUnit = pNext;
                gapClientUnitTable[gaUnitTypes[nType] * 0x80 + i] = pUnit;
            }
        }
    }

    for (int nType = 0; nType < 6; ++nType)
    {
        for (int i = 0; i < 0x80; ++i)
        {
            D2UnitStrc* pUnit = gapServerUnitTable[gaUnitTypes[nType] * 0x80 + i];
            while (pUnit)
            {
                D2UnitStrc* pNext = pUnit->pListNext;
                CUNIT_FreeUnit(pUnit);
                pUnit = pNext;
                gapServerUnitTable[gaUnitTypes[nType] * 0x80 + i] = pUnit;
            }
        }
    }
}

static __forceinline void WalkUnitTable(D2UnitStrc** ppTable)
{
    for (int i = 0; i < 0x80; ++i)
    {
        for (D2UnitStrc* pUnit = ppTable[i]; pUnit; pUnit = pUnit->pListNext)
        {
        }
    }
}

// 0x00465AA0
void __cdecl CUNIT_ResetUnitTables()
{
    CUNIT_ForEachUnitInTable(gpUnitTable_007A6470, UNITMODE_UpdateUnit);
    CUNIT_FreeUnitTable(gpUnitTable_007A5870);
    CUNIT_FreeUnitTable(gpUnitTable_007A5670);
    CUNIT_ForEachUnitInTable(gpUnitTable_007A5E70, UNITMODE_UpdateUnit);
    CUNIT_ForEachUnitInTable(gpUnitTable_007A6070, UNITMODE_UpdateUnit);
    CUNIT_ForEachUnitInTable(gpUnitTable_007A6270, UNITMODE_UpdateUnit);
    CUNIT_ForEachUnitInTable(gpUnitTable_007A6670, UNITMODE_UpdateUnit);
    CUNIT_FreeUnitTable(gpUnitTable_007A5470);
    WalkUnitTable(gpUnitTable_007A5470);
    WalkUnitTable(gpUnitTable_007A6670);
    WalkUnitTable(gpUnitTable_007A5E70);
    WalkUnitTable(gpUnitTable_007A6070);
    CUNIT_ForEachUnitInTable(gpUnitTable_007A5470, CUNIT_FreeUnitModStats);
    CUNIT_ForEachUnitInTable(gpUnitTable_007A6670, CUNIT_FreeUnitModStats);
    CUNIT_ForEachUnitInTable(gpUnitTable_007A5E70, CUNIT_FreeUnitModStats);
    if (!gdwGlobal_007A0610)
    {
        CUNIT_ForEachUnitInTable(gpUnitTable_007A5E70, CUNIT_SyncFromServerUnit);
        CUNIT_ForEachUnitInTable(gpUnitTable_007A6070, CUNIT_SyncFromServerUnit);
    }
}

// 0x00465BF0
void __fastcall CUNIT_SetPathTargetToTargetUnit(D2UnitStrc* pUnit, int nArg)
{
    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (pTarget && pTarget != pUnit)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        D2_ASSERT(pPath, 0x7E2);
        D2Common_10216(pPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), nArg);
    }
}

static inline int UNITS_IsDeadOrDying(D2UnitStrc* pUnit)
{
    if (pUnit->dwFlags & 0x10000)
    {
        return 1;
    }

    const int nMode = pUnit->dwAnimMode;
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        if (nMode == 0 || nMode == 0x11)
        {
            return 1;
        }
        break;

    case UNIT_MONSTER:
        if (nMode == 0 || nMode == 0x0C)
        {
            return 1;
        }
        break;
    }

    return 0;
}

// 0x00465C60
int __fastcall CUNIT_IsHostileTo(D2UnitStrc* pUnit, D2UnitStrc* pOther)
{
    int nUnitType;
    int nUnitId;
    if (!pUnit)
    {
        nUnitType = 6;
        nUnitId = -1;
    }
    else
    {
        nUnitType = pUnit->dwUnitType;
        nUnitId = pUnit->dwUnitId;
    }

    int nOtherType = !pOther ? 6 : pOther->dwUnitType;
    int nOtherId = !pOther ? -1 : pOther->dwUnitId;

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if ((!pOther ? 6 : pOther->dwUnitType) == 0 && UNITS_IsDeadOrDying(pOther) && !ROSTER_CanLoot(nUnitId, pOther->dwUnitId))
        {
            return 0;
        }

        if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pOther && pOther->dwUnitType == UNIT_MONSTER
            && ROSTERPETS_FindRosterIndex(pOther->dwUnitId) != -1 && !CUNIT_IsPetSkillTarget(pUnit, pOther))
        {
            return 0;
        }

        return 1;
    }

    if (nUnitType == 1)
    {
        const int nOwnerId = ROSTERPETS_FindRosterIndex(nUnitId);
        if (nOwnerId != -1)
        {
            nUnitType = 0;
            nUnitId = nOwnerId;
        }

        int bUnitOwned = 0;
        if (pUnit)
        {
            bUnitOwned = (pUnit->dwFlagEx >> 10) & 1;
        }

        if (bUnitOwned && !pOther->dwOwnerType)
        {
            nUnitType = 0;
            nUnitId = pUnit->dwOwnerGUID;
        }
    }

    if (nOtherType == 1)
    {
        const int nOwnerId = ROSTERPETS_FindRosterIndex(nOtherId);
        if (nOwnerId != -1)
        {
            nOtherType = 0;
            nOtherId = nOwnerId;
        }

        int bOtherOwned = 0;
        if (pOther)
        {
            bOtherOwned = (pOther->dwFlagEx >> 10) & 1;
        }

        if (bOtherOwned && !pOther->dwOwnerType)
        {
            nOtherId = pOther->dwOwnerGUID;
            nOtherType = 0;
        }
    }

    if (nUnitType == nOtherType && nUnitId == nOtherId)
    {
        return 0;
    }

    if (nUnitType == 0 && nOtherType == 0)
    {
        if (pOther && pOther->dwUnitType == UNIT_PLAYER && CUNIT_IsDeadOrDying(pOther) && ROSTER_CanLoot(nUnitId, pOther->dwUnitId))
        {
            return 1;
        }

        return GFXUTIL_TestRelationFlags(nUnitId, nOtherId, 8);
    }

    if (nOtherType == 1)
    {
        if (MONSTERREGION_CheckMonStats2Flag(!pOther ? -1 : pOther->dwClassId, 4))
        {
            return 1;
        }

        if (MONSTERREGION_CheckMonStats2Flag(!pOther ? -1 : pOther->dwClassId, 5))
        {
            return 0;
        }
    }

    if (nUnitType == 0 && (nOtherType == 4 || nOtherType == 2))
    {
        return 1;
    }

    return !STATLIST_AreUnitsAligned(pUnit, pOther);
}

// 0x00465E80
static void CUNIT_RemoveUnitFromTable(unsigned int nUnitId, int nUnitType, D2UnitStrc** ppTable, int nHash)
{
    D2UnitStrc* pPrev = 0;
    for (D2UnitStrc* pUnit = ppTable[nHash]; pUnit; pUnit = pUnit->pListNext)
    {
        if (pUnit->dwUnitId == nUnitId && pUnit->dwUnitType == nUnitType)
        {
            if (!pPrev)
            {
                ppTable[nHash] = pUnit->pListNext;
            }
            else
            {
                pPrev->pListNext = pUnit->pListNext;
            }

            if (pUnit->dwUnitType == UNIT_ITEM)
            {
                VIEW_ResetSelectionForUnit(pUnit);
            }

            CUNIT_FreeUnit(pUnit);
            return;
        }
        pPrev = pUnit;
    }
}

// 0x00465EE0
void __fastcall CUNIT_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType)
{
    CUNIT_RemoveUnitFromTable(nUnitId, nUnitType, &gapClientUnitTable[nUnitType * 0x80], nUnitId & 0x7F);
}

// 0x00465F00
void __fastcall CUNIT_RemoveServerSideUnit(unsigned int nUnitId, int nUnitType)
{
    CUNIT_RemoveUnitFromTable(nUnitId, nUnitType, &gapServerUnitTable[nUnitType * 0x80], nUnitId & 0x7F);
}

// 0x00465F20
static D2UnitStrc* CUNIT_InsertUnit(D2UnitStrc* pUnit)
{
    if (!CUNIT_AddUnitToTable(pUnit))
    {
        D2UnitStrc* pOld = CUNIT_FindClientUnit(pUnit->dwUnitId, pUnit->dwUnitType);
        D2_ASSERT(pOld != pUnit, 0x1C6);
        if (pOld)
        {
            if (UNIT_HasFlag(pOld, 0x200000))
            {
                CUNIT_RemoveServerSideUnit(pOld->dwUnitId, pOld->dwUnitType);
            }
            else
            {
                CUNIT_RemoveClientSideUnit(pOld->dwUnitId, pOld->dwUnitType);
            }

            if (CUNIT_AddUnitToTable(pUnit))
            {
                return pUnit;
            }
        }

        CUNIT_FreeUnit(pUnit);
        pUnit = 0;
    }

    return pUnit;
}

// build: symbol ?VIEW_SpawnRoomPresets@* 0x00466820
void __fastcall VIEW_SpawnRoomPresets(D2ActiveRoomStrc* pRoom)
{
    for (D2PresetUnitStrc* pPresetUnit = DUNGEON_GetPresetUnitsFromRoom(pRoom); pPresetUnit; pPresetUnit = pPresetUnit->pNext)
    {
        if (pPresetUnit->bSpawned & 1)
        {
            CUNIT_SpawnPresetUnitInRoom(pRoom, pPresetUnit);
        }
    }
}

// 0x00465FD0
static D2UnitStrc* __stdcall CUNIT_InitUnit(unsigned int nUnitId, int nClassId, int nY, int nUnitType, int nArg5, int nArg6, D2UnitStrc* pUnit, int nX)
{
    const int bFlag = GAME_IsExpansion();
    if (pUnit)
    {
        if (bFlag)
        {
            pUnit->dwFlagEx |= 0x2000000;
        }
        else
        {
            pUnit->dwFlagEx &= ~0x2000000;
        }
    }

    pUnit->dwUnitType = nUnitType;
    pUnit->dwClassId = nClassId;
    pUnit->dwUnitId = nUnitId;
    pUnit->dwTickCount = 0;
    pUnit->pMemoryPool = 0;

    D2ActiveRoomStrc* pRoom = 0;
    if (nX || nY)
    {
        pRoom = CUNIT_FindRoomBySubtile(nX, nY);
        pUnit->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
        pUnit->pDrlgAct = gpAct;
    }

    SEED_InitSeed(&pUnit->pSeed);

    if (nUnitType == 4)
    {
        ITEMS_AllocItemData(0, pUnit);
        ITEMS_InitItemSeed(pUnit);
    }

    if (pRoom)
    {
        unsigned __int64 lSeed = pRoom->pSeed.nHighSeed + 0x6AC690C5i64 * pRoom->pSeed.nLowSeed;
        pRoom->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pRoom->pSeed.nLowSeed = (unsigned int)lSeed;
        pUnit->dwInitSeed = (unsigned int)lSeed;
        SEED_InitLowSeed(&pUnit->pSeed, (unsigned int)lSeed);
    }

    switch (nUnitType)
    {
    case 0:
        sub_00460BF0_InitPlayerUnit(pUnit, pRoom, nX, nY);
        break;

    case 1:
        D2_ASSERT(0, 0x202);
        break;

    case 2:
        UNITS_AllocStaticPath(pUnit);
        sub_004BC720_InitObjectUnit(pUnit, pRoom, nX, nY, nClassId, nArg6);
        break;

    case 4:
        UNITS_AllocStaticPath(pUnit);
        sub_004C1910_InitItemUnit(pUnit, pRoom, nX, nY, nArg5, 1);
        break;

    case 3:
        MISSILE_InitMissileUnit(pUnit, pRoom, nX, nY, nClassId);
        break;

    case 5:
        UNITS_AllocStaticPath(pUnit);
        pUnit->dwFlags |= 0x22;
        UNITS_InitializeStaticPath(pUnit, pRoom, nX, nY);
        UNITS_BlockCollisionPath(pUnit, pRoom, nX, nY);
        UNITROOM_AddUnitToRoom(pUnit, pRoom);
        break;
    }

    if (nUnitType != 5)
    {
        PLAYERLIST_InitGfxData(pUnit);
        if (nUnitType == 0 || nUnitType == 1)
        {
            UnitUpdateAnimRateAndVel(pUnit, ".\\UNIT\\CUnit.cpp", 0x21D);
        }
    }

    pUnit = CUNIT_InsertUnit(pUnit);
    if (pUnit && nUnitType == 2)
    {
        OBJECT_UpdateObjectOverlay(pUnit);
    }

    return pUnit;
}

// 0x004661C0
D2UnitStrc* __fastcall CUNIT_AllocClientUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5)
{
    D2UnitStrc* pUnit = UNITS_AllocUnit(0, nUnitType);
    if (!pUnit)
    {
        return 0;
    }

    return CUNIT_InitUnit(nUnitId, nClassId, nY, nUnitType, nArg5, 0, pUnit, nX);
}

// 0x00466200
D2UnitStrc* __fastcall CUNIT_CreatePlayerUnit(unsigned int nUnitId, int nClassId, int nX, int nY, char* szName)
{
    D2UnitStrc* pUnit = UNITS_AllocUnit(0, 0);
    if (!pUnit)
    {
        return 0;
    }

    const int bFlag = GAME_IsExpansion();
    if (pUnit)
    {
        if (bFlag)
        {
            pUnit->dwFlagEx |= 0x2000000;
        }
        else
        {
            pUnit->dwFlagEx &= ~0x2000000;
        }
    }

    pUnit->dwClassId = nClassId;
    pUnit->dwUnitType = 0;
    pUnit->dwUnitId = nUnitId;
    pUnit->dwTickCount = 0;
    pUnit->pMemoryPool = 0;

    D2ActiveRoomStrc* pRoom;
    if (nX || nY)
    {
        pRoom = CUNIT_FindRoomBySubtile(nX, nY);
        pUnit->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
        pUnit->pDrlgAct = gpAct;
    }
    else
    {
        pRoom = 0;
    }

    SEED_InitSeed(&pUnit->pSeed);

    if (pRoom)
    {
        unsigned __int64 lSeed = pRoom->pSeed.nHighSeed + 0x6AC690C5i64 * pRoom->pSeed.nLowSeed;
        pRoom->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pRoom->pSeed.nLowSeed = (unsigned int)lSeed;
        pUnit->dwInitSeed = (unsigned int)lSeed;
        SEED_InitLowSeed(&pUnit->pSeed, (unsigned int)lSeed);
    }

    sub_00460BF0_InitPlayerUnit(pUnit, pRoom, nX, nY);
    PLAYERLIST_InitGfxData(pUnit);
    UnitUpdateAnimRateAndVel(pUnit, ".\\UNIT\\CUnit.cpp", 0x21D);

    pUnit = CUNIT_InsertUnit(pUnit);
    if (pUnit)
    {
        UNITS_SetNameInPlayerData(pUnit, szName);
    }

    return pUnit;
}

// 0x00466300
D2UnitStrc* __fastcall CUNIT_CreateObjectUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5, int nArg6, unsigned char nInteractType)
{
    D2UnitStrc* pUnit = UNITS_AllocUnit(0, nUnitType);
    if (!pUnit)
    {
        return 0;
    }

    pUnit = CUNIT_InitUnit(nUnitId, nClassId, nY, nUnitType, nArg5, nArg6, pUnit, nX);
    if (pUnit)
    {
        pUnit->pObjectData->InteractType = nInteractType;
        if (UNITS_IsShrine(pUnit))
        {
            sub_004BD6B0_InitShrine(pUnit);
        }
    }

    return pUnit;
}

static inline D2MonStatsTxt* sub_F4B0_GetMonStatsTxt(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nId];
    }

    return 0;
}

static inline D2MonStats2Txt* sub_A3_GetMonStats2TxtRecord(int nMonStatsEx)
{
    if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
    {
        return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
    }

    return 0;
}

static inline D2MonStatsTxt* sub_A3_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static __forceinline D2MonStats2Txt* sub_F4B0_GetMonStats2TxtFromMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nId = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nId >= 0 && nId < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nId];
        }
    }

    return 0;
}

static inline D2MonsterInfo16Strc* sub_F4B0_GetMonsterInfo(D2UnitStrc* pUnit)
{
    D2MonsterDataLocalStrc* pMonsterData = pUnit->dwUnitType == UNIT_MONSTER ? (D2MonsterDataLocalStrc*)pUnit->pMonsterData : 0;
    return pMonsterData ? &pMonsterData->tInfo : 0;
}

static inline unsigned int sub_F4B0_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x00466360
D2UnitStrc* __fastcall CUNIT_AddClientMonster(D2UnitSpawnStrc* pSpawn, void* pArg2, unsigned char* pArg3, int nArg4, int nArg5, int nArg6)
{
    const unsigned int nUnitId = pSpawn->nUnitId;
    if (nUnitId == ROSTERPETS_FindPetIdByOwner(gpPlayerUnit, 7, 1))
    {
        D2UnitStrc* pPet = CUNIT_FindUnitInTable(&gapClientUnitTable[UNIT_MONSTER * 0x80], nUnitId, nUnitId & 0x7F, UNIT_MONSTER);
        if (pPet)
        {
            GFX_FreeGfxData(pPet);
            PLAYERLIST_InitGfxData(pPet);
            UNITS_ChangeAnimMode(pPet, pSpawn->nMode);
            return pPet;
        }
    }

    const int nClassId = pSpawn->nClassId;
    D2MonStatsTxt* pMonStatsTxtRecord = 0;
    D2MonStats2Txt* pMonStats2TxtRecord = 0;
    if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[nClassId];
        pMonStats2TxtRecord = sub_A3_GetMonStats2TxtRecord(sgptDataTables->pMonStatsTxt[nClassId].wMonStatsEx);
    }

    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pUnit = UNITS_AllocUnit(0, UNIT_MONSTER);
    D2UnitStrc* pMonster = pUnit;
    if (nArg6 && pUnit)
    {
        pUnit->dwFlags |= 0x600000;
    }

    const int nX = pSpawn->nX;
    const int nY = pSpawn->nY;
    pUnit->dwUnitType = UNIT_MONSTER;
    pUnit->dwClassId = pSpawn->nClassId;
    pUnit->dwUnitId = pSpawn->nUnitId;
    pUnit->pMemoryPool = 0;
    pUnit->dwTickCount = 0;
    D2ActiveRoomStrc* pRoom = CUNIT_FindRoomBySubtile(nX, nY);
    SEED_InitSeed(&pUnit->pSeed);
    if (pRoom)
    {
        pUnit->dwInitSeed = sub_F4B0_SeedStep(&pRoom->pSeed);
    }

    SEED_InitLowSeed(&pUnit->pSeed, pUnit->dwInitSeed);
    MONSTER_SetClientFlags(pUnit, 0);
    sub_004AC810_ToggleMonsterFlag(pUnit, (unsigned short)pSpawn->tExtra.nArg10, 1);
    if (sub_004AC7E0_CheckMonTypeFlag(pUnit, 2))
    {
        sub_004AC7A0(pUnit, nArg5);
    }

    MONSTER_SetOwnerGUID(pUnit, pSpawn->tExtra.nArg14);
    MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr));
    if (pArg3)
    {
        sub_004AC780_SetMonsterWord(pUnit, nArg4);
        unsigned char* pBytes = MONUNIQUE_GetMonUmods(pUnit);
        pBytes[0] = pArg3[0];
        pBytes[1] = pArg3[1];
        pBytes[2] = pArg3[2];
        pBytes[3] = pArg3[3];
        pBytes[4] = pArg3[4];
        pBytes[5] = pArg3[5];
        pBytes[6] = pArg3[6];
        pBytes[7] = pArg3[7];
        pBytes[8] = pArg3[8];
    }

    if (pArg2)
    {
        D2MonsterInfo16Strc* pInfo = sub_F4B0_GetMonsterInfo(pUnit);
        if (pInfo)
        {
            *pInfo = *(D2MonsterInfo16Strc*)pArg2;
        }
    }

    MONSTER_InitMonster(pUnit, pRoom, nX, nY, nClassId, pSpawn->nMode);
    PATH_SetStepNum(pUnit->pDynamicPath, pMonStats2TxtRecord->nSteps);
    PLAYERLIST_InitGfxData(pUnit);
    CUNIT_ApplyClassEffects(pUnit, nClassId);
    int nMode = 2;
    if (pMonStatsTxtRecord->nMode4D < 8)
    {
        nMode = pMonStatsTxtRecord->nMode4D + 2;
    }

    if (MONSTER_IsUniqueMonster(pUnit) && !MONSTERREGION_CheckMonStats2Flag(nClassId, 15))
    {
        nMode = sub_00477620_RollUnitValue(pUnit, nArg4);
    }

    D2MonStats2Txt* pModeTxtRecord = sub_F4B0_GetMonStats2TxtFromMonsterId(nClassId);
    if (pModeTxtRecord && pModeTxtRecord->nModes[GAME_GetDifficulty()])
    {
        nMode = pModeTxtRecord->nModes[GAME_GetDifficulty()];
        if (nMode == 0xFF)
        {
            nMode = !ROSTERPETS_IsOwnedByPlayer(pUnit);
        }
    }

    if (sub_004AC7E0_CheckMonTypeFlag(pUnit, 2))
    {
        D2SuperUniquesTxt* pSuperUniquesTxtRecord = DATATBLS_GetSuperUniquesTxtRecord(sub_004AC7C0_GetSuperUniqueId(pUnit));
        if (pSuperUniquesTxtRecord->nModes[GAME_GetDifficulty()])
        {
            nMode = pSuperUniquesTxtRecord->nModes[GAME_GetDifficulty()];
        }
    }

    if (nMode >= 30)
    {
        nMode = 2;
    }

    sub_0046F1C0(pUnit->pGfxData, nMode);
    sub_0046F220(pUnit->pGfxData, nMode);
    pUnit = CUNIT_InsertUnit(pUnit);
    if (ROSTER_GetPetType(pUnit->dwUnitId) == 7)
    {
        D2ClientEntryStrc* pEntry = ROSTERPETS_FindEntry(pUnit->dwUnitId);
        if (pEntry)
        {
            D2HirelingInfoStrc tInfo;
            tInfo.dwValue = pEntry->dwValue;
            tInfo.wValue = pEntry->wValue;
            MONSTER_InitHireling(pMonster, &tInfo);
        }
    }

    if (MONSTERS_GetHirelingTypeId(pMonster))
    {
        INVENTORY_AllocInventory(0, pMonster);
    }

    UNITSND_PlayInitSound(pMonster);
    return pMonster;
}

// 0x00466730
D2UnitStrc* __fastcall CUNIT_SpawnPresetUnit(int nClassId, int nX, int nY, int nUnitType, int nArg)
{
// build: symbol ?gnPresetUnitId@* 0x00711F30
    if (++gnPresetUnitId == -1)
    {
        gnPresetUnitId = 0;
    }

    if (nUnitType == 1)
    {
        D2UnitSpawnStrc tSpawn = {};
        tSpawn.nUnitId = gnPresetUnitId;
        tSpawn.nClassId = nClassId;
        tSpawn.nX = nX;
        tSpawn.nY = nY;
        tSpawn.nMode = nUnitType;
        return CUNIT_AddClientMonster(&tSpawn, 0, 0, 0, 0, nUnitType);
    }

    D2UnitStrc* pUnit = UNITS_AllocUnit(0, nUnitType);
    if (!pUnit)
    {
        return 0;
    }

    pUnit->dwFlags |= 0x600000;
    return CUNIT_InitUnit(gnPresetUnitId, nClassId, nY, nUnitType, nArg, 0, pUnit, nX);
}

void sub_I08_Emit_004656C0(D2UnitStrc* pUnit, int nClassId)
{
    CUNIT_ApplyClassEffects(pUnit, nClassId);
}

// 0x004667F0
static void CUNIT_SpawnPresetUnitInRoom(D2ActiveRoomStrc* pRoom, D2PresetUnitStrc* pPresetUnit)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    CUNIT_SpawnPresetUnit(pPresetUnit->nIndex, pPresetUnit->nXpos + tCoords.nSubtileX, pPresetUnit->nYpos + tCoords.nSubtileY, pPresetUnit->nUnitType, pPresetUnit->nMode);
}

// 0x00466870
int __fastcall CUNIT_IsUnitSelectable(D2UnitStrc* pUnit, int nX, int nY, int bHitTest)
{
    const int nMouseX=sub_00468730();
    switch(sub_0045AE90())
    {
    case 3: return 0;
    case 1: if(nMouseX>=gnScreenWidth_0071146C/2) return 0; break;
    case 2: if(nMouseX<gnScreenWidth_0071146C/2) return 0; break;
    }
    D2UnitStrc* pPlayer=gpPlayerUnit;
    if(UNIT_HasFlag(pUnit,0x200000)) return 0;
    if(!sub_00465C60(pPlayer,pUnit) && !sub_00464EC0(pPlayer,pUnit) && !sub_00464F70(pPlayer,pUnit)) return 0;
    int bSelectable=0;
    if(CUNIT_CheckMonsterSkillSelect(pUnit,pPlayer))
    {
        if(!pUnit) return 0;
        if(UNIT_HasFlag(pUnit,2) || (pUnit->dwUnitType==UNIT_MONSTER && CUNIT_IsDeadOrDying(pUnit) && sub_00451F30(pUnit,4))) bSelectable=1;
    }
    else
    {
        if(!pUnit) return 0;
        if(UNIT_HasFlag(pUnit,2)) bSelectable=1;
    }
    if(!UNIT_HasFlagEx(pUnit,0x80) || !bSelectable) return 0;
    if(!bHitTest) return 1;
    int nMode=UNITS_GetAnimOrSeqMode(pUnit);
    int nClassId=pUnit->dwClassId;
    int nType=pUnit->dwUnitType;
// build: symbol ?gszCUnitFile@* 0x006D6A48
    D2COMMON_11013_ConvertMode(pUnit,&nType,&nClassId,&nMode,gszCUnitFile,0x6ED);
    D2ObjectsTxt* ptObjectData=0;
    int nUnitX=UNITS_GetClientCoordX(pUnit);
    int nUnitY=UNITS_GetClientCoordY(pUnit);
    switch(nType)
    {
    case 1:
    {
        D2MonStats2SelectStrc* pStats=(D2MonStats2SelectStrc*)UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
        if(pStats->nFlags[0]&gdwBitMasks[0])
        {
            D2RectStrc tBox;
            const int nTop=nUnitY+pStats->nTop;
            const int nLeft=nUnitX+pStats->nLeft;
            tBox.nLeft=nLeft;
            tBox.nTop=nTop;
            tBox.nRight=nLeft+pStats->nWidth;
            tBox.nBottom=nTop+pStats->nHeight;
            D2CoordPairStrc tPoint={nX,nY};
            return PtInRect(&tBox,tPoint)!=0;
        }
        if(!GFX_HitTestUnitGfx(pUnit,nUnitX,nUnitY,nX,nY)) return 0;
        break;
    }
    case 0:
        if(!GFX_HitTestUnitGfx(pUnit,nUnitX,nUnitY,nX,nY)) return 0;
        break;
    case 2:
        ptObjectData=DATATBLS_GetObjectsTxtRecord(nClassId);
        if(!GFX_HitTestUnitGfx(pUnit,nUnitX,nUnitY,nX,nY) && !ptObjectData->nIsDoor && !ptObjectData->nSelectBox) return 0;
        break;
    case 4:
        if(pUnit->dwAnimMode!=3 || GAME_GetUIVarState(13)) return 0;
        break;
    case 5: return CUNIT_IsPointInTileRect(pUnit,nX,nY); // 0x00463EE0
    }
    int bAllComponents=0;
    switch(nType)
    {
    case 2:
        D2_ASSERT(ptObjectData,0x741);
        if(ptObjectData->nIsDoor)
        {
            if(pUnit->dwAnimMode==2 || pUnit->dwAnimMode==4 || pUnit->dwAnimMode==5)
                return CUNIT_IsInObjectSelectBox(nY,ptObjectData,pUnit,nX);
        }
        else if(ptObjectData->nSelectBox) return CUNIT_IsInObjectSelectBox(nY,ptObjectData,pUnit,nX);
        if(ptObjectData->nComponents>1) bAllComponents=1;
        break;
    case 1:
    {
        D2MonStats2SelectStrc* pStats=(D2MonStats2SelectStrc*)UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
        if(pStats && pStats->nComponents>1) bAllComponents=1;
        break;
    }
    case 0:bAllComponents=1;break;
    }
    int nFrame,nFrameCount;
    {
        D2RectStrc tRect;
        UNITS_GetShiftedFrameMetrics(pUnit,&nFrame,&nFrameCount);
        tRect.nBottom=tRect.nRight=tRect.nTop=tRect.nLeft=0;
        if(pUnit->dwUnitType==UNIT_PLAYER && pUnit->dwClassId==4 && pUnit->dwAnimMode==PLRMODE_SEQUENCE) return 1;
        if(bAllComponents)
        {
            for(unsigned int nComponent=0;nComponent<16;++nComponent)
                if(CUNIT_GetUnitSelectRect(pUnit,nComponent,&tRect,nFrame) && GFXUTIL_UpdateUnitGfx(pUnit,nComponent) && nX>=tRect.nLeft && nX<=tRect.nRight && nY>=tRect.nBottom && nY<=tRect.nTop) return 1;
            return 0;
        }
        if(CUNIT_GetUnitSelectRect(pUnit,1,&tRect,nFrame) && nX>=tRect.nLeft && nX<=tRect.nRight && nY>=tRect.nBottom && nY<=tRect.nTop) return 1;
        return 0;
    }
}

// 0x00466CB0
void __fastcall CUNIT_RemoveInventoryUnits(D2UnitStrc* pUnit, int bCheckOwner)
{
    D2_ASSERT(pUnit, 0xA80);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pEntry = INVENTORY_GetFirstItem(pInventory);
    while (pEntry)
    {
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pEntry);
        D2UnitStrc* pItem = CUNIT_FindClientUnit(INVENTORY_GetItemGUID(pEntry), 4);
        if (pItem)
        {
            int bRemove = 1;
            if (bCheckOwner)
            {
                bRemove = !CUNIT_IsItemOwnedByOther(pUnit, pItem);
            }

            if (bRemove)
            {
                ITEM_UpdateItemLink(pItem, pUnit, 0, 0);
                D2_ASSERT(INVENTORY_RemoveItemFromInventory(pInventory, pItem), 0xA92);
                CUNIT_RemoveClientSideUnit(pItem->dwUnitId, pItem->dwUnitType);
            }
            else
            {
                D2_ASSERT(INVENTORY_RemoveItemFromInventory(pInventory, pItem), 0xA96);
            }
        }
        pEntry = pNext;
    }
}


unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB); // 0x00469AA0



void __cdecl CUNIT_DrawCountdown(); // 0x0046C060

// 0x0046D750
void __cdecl CUNIT_ClearAiTargets()
{
    for (int i = 0; i < 8; ++i)
    {
        gapAiTargets[i] = 0;
    }
}

unsigned char* __fastcall PALSHIFT_GetPalShift(D2UnitStrc* pUnit); // 0x00477530

D2UnitStrc* __fastcall sub_M109_Emit_00463920(int nUnitType, int nHash)
{
    return CUNIT_GetClientHashTable(nUnitType)[nHash] ? CUNIT_GetServerHashTable(nUnitType)[nHash] : 0;
}

void __fastcall sub_M109_Emit_00463C60(D2UnitStrc* pUnit)
{
    CUNIT_RemoveUnitFromRoom(pUnit);
}

int __fastcall sub_Q03_Emit_ObjectSelectBox(D2UnitStrc* pUnit, int nX, int nY)
{
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pUnit->dwClassId);
    if (pObjectsTxtRecord->nIsDoor)
    {
        return CUNIT_IsInObjectSelectBox(nY, pObjectsTxtRecord, pUnit, nX);
    }

    return 0;
}

int __fastcall sub_Q03_Emit_UnitSelectRect(D2UnitStrc* pUnit, int nX)
{
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);

    D2RectStrc tRect;
    for (int nMode = 0; nMode < 16; ++nMode)
    {
        if (CUNIT_GetUnitSelectRect(pUnit, nMode, &tRect, nFrameNo) && nX >= tRect.nLeft && nX <= tRect.nRight)
        {
            return 1;
        }
    }

    return 0;
}

int __stdcall sub_O05_Emit_004642B0(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    if (CUNIT_CheckSkillSelectProc(pPlayer, pTarget, sub_O05_EmitArg_SkillId(pPlayer)))
    {
        return 1;
    }

    return CUNIT_CheckSkillSelectProc(pPlayer, pTarget, sub_O05_EmitArg_SkillId(pTarget)) != 0;
}

// 0x00483410
D2SetsTxt* __fastcall DATATBLS_GetSetsTxtRecord(int nSetId)
{
    if (nSetId >= 0 && nSetId < sgptDataTables->nSetsTxtRecordCount)
    {
        return &sgptDataTables->pSetsTxt[nSetId];
    }

    return 0;
}

// 0x00483440
D2SetItemsTxt* __fastcall DATATBLS_GetSetItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nSetItemsTxtRecordCount)
    {
        return &sgptDataTables->pSetItemsTxt[nIndex];
    }

    return 0;
}

// 0x00483470
D2UniqueItemsTxt* __fastcall DATATBLS_GetUniqueItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nUniqueItemsTxtRecordCount)
    {
        return &sgptDataTables->pUniqueItemsTxt[nIndex];
    }

    return 0;
}



// 0x004898A0
void __fastcall sub_004898A0(int nMode)
{
    gbGoldButtonDisabled = 1;
    if (gnInvPanelMode == 13)
    {
        gnInvPanelMode = 12;
    }

    UI_SetUIVar(5, 1, 0);
}

// 0x004898D0
void __fastcall CUNIT_SetDialogState(int nState)
{
    gnDialogState = nState;
    if (nState == 0)
    {
        gnHoverTopX = -1;
        gnHoverTopY = -1;
        gnHoverBottomX = -1;
        gnHoverBottomY = -1;
        gnHoverCellX = -1;
        gnHoverCellY = -1;
        gbHoverInGrid = 0;
        gbHoverInBodyLoc = 0;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
    }
}


// build: symbol ?DDDEBUGFONT_FreeDebugFont@* 0x005125B0
void __cdecl DDDEBUGFONT_FreeDebugFont()
{
    if (gpDDrawDebugFontGlyphs)
    {
        FOG_Free(gpDDrawDebugFontGlyphs, ".\\Src\\ddDebugFont.cpp", 0x5D, 0);
        gpDDrawDebugFontGlyphs = 0;
    }
}

// build: symbol ?BNSEND_FreeGamesList@* 0x0051B210
void __cdecl BNSEND_FreeGamesList()
{
    if (gpReply_008818D0)
    {
        FOG_Free(gpReply_008818D0, ".\\BnSend.cpp", 0x36A, 0);
    }

    gpReply_008818D0 = 0;
}

// build: symbol ?GRID_UnlockCDKeys@* 0x005239C0
void __cdecl GRID_UnlockCDKeys()
{
    if (gpGidFileData)
    {
        SFileUnloadFile(gpGidFileData);
        gpGidFileData = 0;
    }

    if (gpClhFileData)
    {
        SFileUnloadFile(gpClhFileData);
        gpClhFileData = 0;
    }
}

#include "gen/data/Source/D2Client/UNIT/CUnit.inc"
