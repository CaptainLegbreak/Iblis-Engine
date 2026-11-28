#include "D2ObjectIds.h"
#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2UnitData.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2ClientTypes.h"
#include "D2ClientGame.h"
#include "D2PlayerModes.h"
#include "FogApi.h"
#include "D2CommonApi.h"
#include "D2CommonApi2.h"

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
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);



extern D2DataTablesStrc* sgptDataTables;
extern unsigned int gdwBitMasks[];
extern void* gpDrlgAct_007A0634;
unsigned int __cdecl sub_0044DA90_GetTickCounter();
unsigned int __cdecl GAME_GetInteractDeadline(); // 0x0044DAC0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);
int __stdcall PLAYER_IsPendingMode(int nArg1, int nArg2); // 0x00461D60
int __fastcall CUNIT_CanUseSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00464600
D2UnitStrc* __cdecl SELECT_GetSelectedUnit(); // 0x00467A10
D2UnitStrc* __fastcall SELECT_GetSkillTarget(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pX, int* pY, unsigned int dwFlags, int bForce); // 0x00467880
int __cdecl INV_GetScreenHeightMinusPanel(); // 0x00454970
void __fastcall PLAYER_SetPlayerMode(int nMode, D2UnitStrc* pUnit, int nArg1, int nArg2); // 0x00460780
int __fastcall PLAYER_FilterCommandMessage(D2PlayerCmdStrc* pCmd); // 0x00462930
void __fastcall CUNIT_SetPlayerUnit(int nArg);
D2UnitStrc* __cdecl sub_00463DD0();
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();
D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit);
void __fastcall VIEW_SetPetEntryValue(D2UnitStrc* pOwner, D2UnitStrc* pRecord, int nValue); // 0x00467410

struct D2ActiveRoomStrc { char unknown0[76]; int x, y, width, height; };

void __fastcall DLIGHTMAP_ReleaseLight(D2R01LightStrc* pLight); // 0x004743D0
void __fastcall UNITMODE_DoUnitAction(int nMode, D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3); // 0x00481030
void __fastcall SKILLS_DoUsedSkill(D2UnitStrc* pUnit); // 0x004C68F0
int __fastcall sub_004D9FC0_GetSkillUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill);
void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath);
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);
int __stdcall D2Common_10399(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);
D2SkillStrc* __fastcall SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);
void __stdcall PATH_SetUnitDeadCollision(D2UnitStrc* pUnit, int nArg); // 0x00649F70
void __cdecl PLAYER_RefreshAdjacentPlayers(); // 0x004608C0
extern D2UnitStrc* gapClientUnitTable[6 * 0x80]; // 0x007A5E70
extern D2UnitStrc* gapServerUnitTable[6 * 0x80]; // 0x007A5270

// 0x00463720
int __fastcall ITEMS_CheckUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwMask)
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
