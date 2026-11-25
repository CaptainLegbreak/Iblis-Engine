#include "D2ObjectIds.h"
#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2UnitData.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2ClientTypes.h"
#include "D2ClientGame.h"
#include "D2PlayerModes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2GfxLightStrc;
struct Unicode;
struct D2StaticPathStrc;
struct D2PlayerDataStrc;
struct D2MonsterDataStrc;
struct D2PlayerCmdStrc;
struct D2SkillRefStrc;
struct D2SkillsTxt;
struct D2ClientEntryStrc;
struct D2MonStatsTxt;
struct D2StringRefStrc;

extern "C" const char gszEmptyAssertText;
extern "C" const char* __cdecl sub_00408090();
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);



extern D2DataTablesStrc* sgptDataTables;
extern unsigned int gdwBitMasks[];
extern void* gpDrlgAct_007A0634;
unsigned int __cdecl GAME_SetClickHandled(); // 0x0044BEF0
unsigned int __cdecl sub_0044DA90();
unsigned int __cdecl GAME_GetCurrentTime(); // 0x0044DAA0
unsigned int __cdecl GAME_GetInteractDeadline(); // 0x0044DAC0
void __fastcall GAME_SetInteractDeadline(unsigned int nValue); // 0x0044DAD0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);
void __cdecl UI_CancelCursorItemUse();
int __fastcall GAME_GetUIVarState(int nUIVar); // 0x004538D0
void __fastcall AUTOMAP_ScreenToMap(int* pX, int* pY); // 0x0045AFF0
void __fastcall GFX_ClearPendingAction(D2UnitStrc* pUnit); // 0x0045C470
int __stdcall PLAYER_IsPendingMode(int nArg1, int nArg2); // 0x00461D60
int __fastcall CUNIT_CanUseSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00464600
int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
int __fastcall CUNIT_IsHostileTo(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x00465C60
void __cdecl SELECT_ClearSelection(); // 0x00466FE0
D2UnitStrc* __cdecl SELECT_GetSelectedUnit(); // 0x00467A10
void __fastcall SELECT_RefreshHoverUnit(D2UnitStrc* pUnit); // 0x00467A70
D2UnitStrc* __fastcall SELECT_GetSkillTarget(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pX, int* pY, unsigned int dwFlags, int bForce); // 0x00467880
int __cdecl sub_00468830();
int __fastcall DLIGHTMAP_GetDistance(int nDX, int nDY); // 0x00474080
void __fastcall MSG_SendDword(char nHeader, int nArg); // 0x00478680
void __fastcall MSG_SendFourDwords(char nCommand, int nUnitType, int nUnitId, int nX, int nY); // 0x00478700
int __cdecl INV_GetScreenHeightMinusPanel(); // 0x00454970
int __fastcall MONSTERUNIQUE_CheckMonStatsFlag(int nMonsterId, int nFlag); // 0x00457490
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);
void __fastcall PLAYER_SetPlayerMode(int nMode, D2UnitStrc* pUnit, int nArg1, int nArg2); // 0x00460780
int __fastcall PLAYER_IsInAuraRange(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pRange, int* pDistance); // 0x00461AC0
int __fastcall PLAYER_FilterCommandMessage(D2PlayerCmdStrc* pCmd); // 0x00462930
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990
void __fastcall sub_00463D90(int nArg);
D2UnitStrc* __cdecl sub_00463DD0();
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();
void __fastcall CUNIT_MarkUnitDead(D2UnitStrc* pUnit); // 0x00464810
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);
void __fastcall CUNIT_FreeLight(D2UnitStrc* pUnit); // 0x00464930
void __fastcall CUNIT_SetUnitPosition(D2UnitStrc* pUnit, int nX, int nY, int nFlags); // 0x004654C0
void __fastcall CUNIT_RemoveInventoryUnits(D2UnitStrc* pUnit, int nArg); // 0x00466CB0
void __fastcall VIEW_SetPetEntryValue(D2UnitStrc* pOwner, D2UnitStrc* pRecord, int nValue); // 0x00467410
int __cdecl sub_00468740();

struct D2ActiveRoomStrc { char unknown0[76]; int x, y, width, height; };

void __fastcall sub_0046BF30_CheckThroneLevel(D2ActiveRoomStrc* pRoom);
void __fastcall GFX_RemoveAiTargetUnit(D2UnitStrc* pUnit); // 0x0046C700
void __fastcall GFX_FreeGfxData(D2UnitStrc* pUnit); // 0x0046EC10
void __fastcall GFX_PruneGfxNodes(D2UnitStrc* pUnit); // 0x0046ECE0
void __fastcall GFX_FillGfxEntries(D2UnitStrc* pUnit, char nValue); // 0x0046F020
void __fastcall sub_00473C90_SetGlobal(int nValue);
void __fastcall DLIGHTMAP_ReleaseLight(void* pResource); // 0x004743D0
D2ClientEntryStrc* __fastcall ROSTERPETS_FindEntry(int nKey); // 0x00478E40
int __fastcall ROSTERPETS_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny); // 0x00478F20
void __fastcall UNITMODE_SetUnitMode(D2UnitStrc* pUnit, int nArg); // 0x00480E70
void __fastcall UNITMODE_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nA, int nB, int nC); // 0x004804E0
void __fastcall UNITMODE_DoUnitAction(int nMode, D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3); // 0x00481030
void __fastcall NPCMENU_RefreshNpcEntries(D2UnitStrc* pUnit); // 0x004B3E10
void __cdecl ITEM_ResetWeaponClasses(); // 0x004C1E30
void __fastcall SKILLS_DoUsedSkill(D2UnitStrc* pUnit); // 0x004C68F0
void __fastcall UNITSND_PlayPlayerSpeech(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0
int __fastcall sub_004D9FC0_GetSkillUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill);
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);
int __stdcall DUNGEON_CheckLOSDraw(D2ActiveRoomStrc* pRoom); // 0x0061AA40
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);
void __stdcall DUNGEON_UpdatePops(D2ActiveRoomStrc* pRoom, int nX, int nY, int bChanged); // 0x0061ACD0
int __stdcall DUNGEON_GetPortalFlagFromLevelId(int nLevelId);
void __stdcall DUNGEON_InitRoomTileAnimation(void* pAct, D2ActiveRoomStrc* pNextRoom, D2ActiveRoomStrc* pRoom); // 0x0061AF10
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);
void __stdcall UNITS_GetRunAndWalkSpeedForPlayer(D2UnitStrc* pUnit, int nClassId, int* pSpeed, int* pBase); // 0x00620E40
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);
int __stdcall UNITS_IsCurrentRoomInvalid(D2UnitStrc* pUnit);
void __stdcall UNITS_FreePlayerData(void* pMemPool, D2UnitStrc* pPlayer);
void __stdcall UNITS_SetPlayerPortalFlags(D2UnitStrc* pUnit, int nPortalFlags);
int __stdcall UNITS_GetPlayerPortalFlags(D2UnitStrc* pUnit);
int __stdcall UNITS_TestCollisionBetweenInteractingUnits(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMask); // 0x00622B50
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);
int __stdcall UNITS_IsInMovingModeEx(D2UnitStrc* pUnit);
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer);
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);
int __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);
int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill);
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);
int __stdcall UNITS_IsObjectInInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject);
int __stdcall PATH_GetVelocity(D2DynamicPathStrc* pDynamicPath); // 0x006486C0
void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath);
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);
void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory);
int __stdcall D2Common_10399(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);
void* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* pValue);
D2SkillStrc* __fastcall SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);
D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill);
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);
int __stdcall D2Common_11016(D2UnitStrc* pUnit, D2SkillStrc* pSkill);
void __stdcall PATH_FreeDynamicPath(void* pMemPool, D2DynamicPathStrc* pDynamicPath);
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);
int __stdcall PATH_GetLastPointX(D2DynamicPathStrc* pPath); // 0x00648A40
int __stdcall PATH_GetLastPointY(D2DynamicPathStrc* pPath); // 0x00648A60
D2ActiveRoomStrc* __stdcall PATH_GetNextRoom(D2DynamicPathStrc* pDynamicPath);
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit);
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);
void __stdcall D2Common_10228(D2UnitStrc* pUnit);
void __stdcall PATH_SetUnitDeadCollision(D2UnitStrc* pUnit, int nArg); // 0x00649F70
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);
unsigned short __stdcall COLLISION_CheckMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask);
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms);
void __cdecl PLAYER_RefreshAdjacentPlayers(); // 0x004608C0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc*, D2ActiveRoomStrc***, int*); // 0x00619790
extern D2UnitStrc* gapClientUnitTable[6 * 0x80]; // 0x007A5E70
extern D2UnitStrc* gapServerUnitTable[6 * 0x80]; // 0x007A5270

// 0x00463720
int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwMask)
{
    if (!pUnit)
    {
        return 0;
    }
    return (pUnit->dwFlagEx & dwMask) != 0;
}

// 0x00463740
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* room, int x, int y)
{
    if (!room) return 0;
    if (x >= room->x && x < room->x + room->width && y >= room->y && y < room->y + room->height) return room;
    D2ActiveRoomStrc** adjacent = 0;
    int count = 0;
    DUNGEON_GetAdjacentRoomsListFromRoom(room, &adjacent, &count);
    for (unsigned int i = 0; i < (unsigned int)count; ++i) {
        if (adjacent[i] && x >= adjacent[i]->x && x < adjacent[i]->x + adjacent[i]->width
            && y >= adjacent[i]->y && y < adjacent[i]->y + adjacent[i]->height)
            return adjacent[i];
    }
    return 0;
}

// 0x00463810
const Unicode* __fastcall sub_00463810_GetMonsterName(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
        return pUnit->pMonsterData->wszMonName;
    return 0;
}
