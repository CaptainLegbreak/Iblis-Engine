#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2LevelTxt.h"
#include "D2ClientTypes.h"

struct D2UnitStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

#define UNIT_PLAYER 0

#define UNIT_MONSTER 1

#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

#define D2_ABS(n) ((n) < 0 ? -(n) : (n))

struct D2ClientSkillCmdStrc;

struct D2PlayerDataStrc;

struct D2SkillsTxt;

struct D2StaticPathStrc;

struct D2UnitTargetStrc;

void __stdcall PATH_RecacheRoomIfNeeded(D2DynamicPathStrc* pDynamicPath); // 0x00650590

void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

void __fastcall GFX_RefreshUnitGfx(D2UnitStrc* pUnit, int nArg); // 0x00470610

void __fastcall sub_004E4020(D2UnitStrc* pUnit); // 0x004E4020

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

void __cdecl sub_004DF800(); // 0x004DF800

struct D2ClientSkillCmdStrc
{
    int nSkillId;
    int nOwnerGUID;
    int nTargetType;
    int f_C;
    int unk0x10;
    int unk0x14;
    int unk0x18;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

void __fastcall MSG_SendDwords3(unsigned char nHeader, unsigned int d1, unsigned int d5, unsigned int d9); // 0x004786D0

int __fastcall SKILLS_StartSkillOnUnit(D2UnitStrc* pUnit, D2ClientSkillCmdStrc* pArgs); // 0x004C6EB0

void __fastcall UNITSND_PlayPlayerSpeech(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

unsigned short __cdecl GAME_GetClickFlags(); // 0x0044BEC0

int __cdecl GAME_GetCurrentTime(); // 0x0044DAA0

void __fastcall GAME_SetInteractDeadline(int nValue); // 0x0044DAD0

int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag); // 0x00451F30

void __fastcall GFX_ClearPendingAction(D2UnitStrc* pUnit); // 0x0045C470

int __fastcall PLAYER_IsInAuraRange(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pRange, int* pDistance); // 0x00461AC0

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

void __fastcall SELECT_RefreshHoverUnit(D2UnitStrc* pUnit); // 0x00467A70

int __fastcall ROSTER_CanLoot(int nUnitId1, int nUnitId2); // 0x0047A4F0

void __fastcall UNITMODE_SendUnitActionPacket(int nHeader, D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3); // 0x00480B40

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

int __stdcall UNITS_TestCollisionBetweenInteractingUnits(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, unsigned int nCollisionMask); // 0x00622B50

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40

int __stdcall UNITS_IsInMovingModeEx(D2UnitStrc* pUnit); // 0x00622DC0

int __stdcall UNITS_IsObjectInInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject); // 0x00623660

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260

int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill); // 0x00643AD0

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140

void __cdecl sub_K04_EmitUse(D2UnitStrc* pUnit);

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode); // 0x0046C140

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

void __fastcall UNITMODE_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nMode, int nTargetX, int nTargetY); // 0x004804E0

int __fastcall UNITMODE_DispatchUnitCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int nArg); // 0x00480C10

extern "C" void __stdcall PATH_SetPathingFlag(D2DynamicPathStrc* pDynamicPath, int bSet); // 0x00648750

struct D2SkillStrc;

extern "C" const char gszUnitModeFile[];                                                            // 0x006D8E84

int __fastcall sub_00480C10_UnitEvent(int nEvent, D2UnitStrc* pUnit, int* pArgs, int nFlag);                // 0x00480C10

static int UNITMODE_CanUseSkillNow(D2UnitStrc* pPlayer); // 0x00480BA0

static int UNITMODE_IsTargetInRange(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, int nAction); // 0x00480C80

#pragma intrinsic(memset)

void __fastcall UNITMODE_DoUnitAction(int nAction, D2UnitStrc* pPlayer, int nArg1, int nArg2, int nArg3); // 0x00481030

static void __stdcall UNITMODE_DoPlayerAction(D2UnitStrc* pPlayer, int nAction, int nArg1, int nArg2); // 0x004812E0

static int __stdcall UNITMODE_TryMonsterAction(int nAction, int nArg1, int nArg2, D2UnitStrc* pPlayer, D2UnitStrc* pUnit); // 0x004814A0


static int __stdcall UNITMODE_ActOnPlayer(int nAction, int nType, int nId, D2UnitStrc* pPlayer, D2UnitStrc* pUnit); // 0x00481400

extern "C" void __fastcall sub_00480420_ValidatePath(D2UnitStrc* unit);

extern "C" int __stdcall sub_00639DF0_CheckState(D2UnitStrc* unit, int state);

extern "C" void __fastcall SKILLDESC_CreateBlazeMissile(D2UnitStrc* unit); // 0x004E3AB0

extern "C" int __fastcall SKILLSMON_UpdateSpiderLay(D2UnitStrc* unit); // 0x004E2D40

extern "C" unsigned int __cdecl sub_0044DB10_GetFrame();

extern "C" int __stdcall sub_00650840_UpdatePath(D2UnitStrc* unit, unsigned int frame);


void __fastcall CUNIT_RemoveServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465F00

void __stdcall STATLIST_UpdateStatListsExpiration(D2UnitStrc* unit, int value); // 0x00627460

void __stdcall GFXUTIL_UpdateMotion(D2UnitStrc* unit); // 0x004DA350

void __fastcall GFX_UpdateStateOverlays(D2UnitStrc* unit); // 0x00470C30

void __fastcall sub_00463390_UpdatePlayerMode(D2UnitStrc* unit); // 0x00463390

void __fastcall MONSTER_UpdateMonsterClient(D2UnitStrc* unit); // 0x004B13A0

void __fastcall OBJECT_UpdateObject(D2UnitStrc* unit); // 0x004BDFF0

void __fastcall MISSILE_CltDoMissile(D2UnitStrc* unit); // 0x004D2C70

void __fastcall ITEM_UpdateItemAnim(D2UnitStrc* unit); // 0x004C1AD0

D2UnitStrc* __fastcall CUNIT_FindServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x004639B0

void __fastcall sub_0045FA40_FreeUnit(D2UnitStrc* unit); // 0x0045FA40

#define D2ABS(x) ((x) < 0 ? -(x) : (x))

int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650

int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0

void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY); // 0x00643260

int __fastcall GFXUTIL_HitTestUnitCel(D2UnitStrc* pUnit, int nX, int nY); // 0x004DBF20

D2ActiveRoomStrc* __stdcall DUNGEON_FindRoomBySubtileCoordinates(D2DrlgActStrc* pAct, int nX, int nY); // 0x00619DA0

extern D2DrlgActStrc* gpAct; // 0x007A0634

void __fastcall MSG_SendTwoWords(char nHeader, short nArg1, short nArg2); // 0x004785D0

void __fastcall AUTOMAP_UpdatePathAndMove(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463180

int __stdcall D2Common_10230(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650C60

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                // 0x00649970

int __fastcall PLAYER_ApplyUnitCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int nArg); // 0x00461250

void __fastcall MONSTER_HandleMonsterCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget); // 0x004AFF60

void __fastcall OBJECT_HandleObjectCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget); // 0x004BD6D0

void __fastcall ITEM_HandleItemCommand(int nCommand, D2UnitStrc* pUnit, int nParam1, int nParam2); // 0x004C1B80

// 0x00480490
void __fastcall UNITMODE_RecacheUnitPath(D2UnitStrc* pUnit)
{
    PATH_RecacheRoomIfNeeded(pUnit->pDynamicPath);
}

__forceinline int CLIENT_GetAnimModeInline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwAnimMode;
    }
    return 0;
}

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

inline int UNITS_GetFlag21Inl(D2UnitStrc* pUnit)
{
    return (pUnit->dwFlags >> 21) & 1;
}

// 0x004804A0
int __fastcall sub_004804A0_SetPathTargetPos(D2UnitStrc* pUnit, int nX, int nY)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
    return D2Common_10142(pPath, pUnit, UNITS_GetFlag21Inl(pUnit));
}

// 0x004804E0
void __fastcall UNITMODE_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nMode, int nTargetX, int nTargetY)
{
    if (!nX || !nY)
    {
        return;
    }
    if (CUNIT_IsDeadOrDying(pUnit))
    {
        return;
    }

    pUnit->nLastClickX = nX;
    pUnit->nLastClickY = nY;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    int bWarp = 0;
    const int nCurX = CLIENTS_GetUnitX(pUnit);
    const int nCurY = CLIENTS_GetUnitY(pUnit);
    int nTolerance;
    switch (nMode)
    {
    case 1:
        nTolerance = 10;
        break;
    case 2:
        nTolerance = 0;
        break;
    default:
        if (pUnit == sub_00463DD0_GetPlayerUnit())
        {
            switch (CLIENT_GetAnimModeInline(pUnit))
            {
            case 1:
                nTolerance = 3;
                break;
            case 3:
                nTolerance = 7;
                break;
            default:
                nTolerance = 5;
                break;
            }
            nTolerance += (sub_0044CE60_GetPing() + 50) >> 7;
        }
        else
        {
            nTolerance = 15;
            if (pUnit->dwUnitType == UNIT_MONSTER)
            {
                switch (CLIENT_GetAnimModeInline(pUnit))
                {
                case 3:
                case 4:
                case 5:
                    nTolerance = 5;
                    break;
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                    nTolerance = 7;
                    break;
                }
            }
        }
        break;
    }

    int nDiffX = nX - nCurX;
    if (D2ABS(nDiffX) > nTolerance)
    {
        bWarp = 1;
    }
    int nDiffY = nY - nCurY;
    if (D2ABS(nDiffY) > nTolerance)
    {
        bWarp = 1;
    }

    if (bWarp)
    {
        if (!nMode && nTargetX > 0)
        {
            const int nDistance = PATH_ComputeSquaredDistance(nCurX, nCurY, nX, nY);
            if (nDistance < 100 && PATH_ComputeSquaredDistance(nCurX, nCurY, nTargetX, nTargetY) < nDistance)
            {
                bWarp = 0;
            }
        }
    }

    if (!bWarp)
    {
        const int nPixelX = UNITS_GetClientCoordX(pUnit);
        const int nPixelY = UNITS_GetClientCoordY(pUnit);
        int nScreenX = nX;
        int nScreenY = nY;
        DUNGEON_GameSubtileToClientCoords(&nScreenX, &nScreenY);
        if (nX != nCurX && nY != nCurY && !GFXUTIL_HitTestUnitCel(pUnit, nPixelX, nPixelY) && !GFXUTIL_HitTestUnitCel(pUnit, nScreenX, nScreenY))
        {
            bWarp = 1;
        }
        if (!bWarp)
        {
            return;
        }
    }

    D2ActiveRoomStrc* pNewRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
    if (!pNewRoom)
    {
        pNewRoom = DUNGEON_FindRoomBySubtileCoordinates(gpAct, nX, nY);
        if (!pNewRoom)
        {
            return;
        }
    }

    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        MSG_SendTwoWords(0x5F, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
        return;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        AUTOMAP_UpdatePathAndMove(pUnit, pNewRoom, nX, nY);
    }
    else
    {
        D2Common_10230(pUnit->pDynamicPath, pUnit, pNewRoom, nX, nY);
    }
}

// 0x00480780
int __fastcall UNITMODE_SetPathTargetUnit(D2UnitStrc* pUnit, int nUnitType, int nUnitId)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2UnitStrc* pTarget = CUNIT_FindClientUnit(nUnitId, nUnitType);
    PATH_SetTargetUnit(pPath, pTarget);
    if (!pTarget)
    {
        return 0;
    }
    return D2Common_10142(pPath, pUnit, 0);
}


// 0x004807C0
extern "C" int __fastcall UNITMODE_UpdateUnitPath(D2UnitStrc* unit)
{
    sub_00480420_ValidatePath(unit);
    if (sub_00639DF0_CheckState(unit, 13))
        SKILLDESC_CreateBlazeMissile(unit);
    if (sub_00639DF0_CheckState(unit, 22))
        SKILLSMON_UpdateSpiderLay(unit);
    return sub_00650840_UpdatePath(unit, sub_0044DB10_GetFrame()) ? 0 : 1;
}

inline int GetUnitType(D2UnitStrc* unit)
{
    return unit ? unit->dwUnitType : UNIT_INVALID;
}

inline int GetUnitId(D2UnitStrc* unit)
{
    return unit ? unit->dwUnitId : -1;
}

inline int IsDeferredUnit(D2UnitStrc* unit)
{
    if (!unit) return 0;
    return (unit->dwFlags >> 23) & 1;
}

inline int HasQueuedUnitPacket(D2UnitStrc* unit)
{
    if (!unit) return 0;
    return (unit->dwFlagEx >> 5) & 1;
}

inline int IsServerUnit(D2UnitStrc* unit)
{
    if (!unit) return 0;
    return (unit->dwFlags >> 21) & 1;
}

// 0x00480810
void __fastcall UNITMODE_UpdateUnit(D2UnitStrc* unit)
{
    if (sub_00463DD0_GetPlayerUnit() != unit && IsDeferredUnit(unit))
    {
        if (HasQueuedUnitPacket(unit))
        {
            const int packetId = GetUnitId(unit);
            const int packetType = GetUnitType(unit);
            MSG_SendTwoDwords(0x4B, packetType, packetId);
            unit->dwFlags &= 0xFF7FFFFF;
            unit->dwFlagEx &= 0xFFFFFFDF;
        }
        if (IsServerUnit(unit))
            CUNIT_RemoveServerSideUnit(GetUnitId(unit), GetUnitType(unit));
        return;
    }
    STATLIST_UpdateStatListsExpiration(unit, 0);
    GFXUTIL_UpdateMotion(unit);
    int type, server;
    int id;
    if (!unit)
    {
        id = -1;
        type = 6;
        server = 0;
    }
    else
    {
        server = unit->dwFlags >> 21;
        type = unit->dwUnitType;
        id = unit->dwUnitId;
        server &= 1;
    }
    GFX_UpdateStateOverlays(unit);
    switch (unit->dwUnitType)
    {
    case UNIT_PLAYER: sub_00463390_UpdatePlayerMode(unit); break;
    case UNIT_MONSTER: MONSTER_UpdateMonsterClient(unit); break; // 0x004B13A0
    case UNIT_OBJECT: OBJECT_UpdateObject(unit); break; // 0x004BDFF0
    case UNIT_MISSILE: MISSILE_CltDoMissile(unit); break; // 0x004D2C70
    case UNIT_ITEM: ITEM_UpdateItemAnim(unit); break; // 0x004C1AD0
    }
    D2UnitStrc* found = server ? CUNIT_FindServerSideUnit(id, type) : CUNIT_FindClientUnit(id, type);
    if (found)
        sub_0045FA40_FreeUnit(found);
}

// 0x00480930
void __fastcall UNITMODE_InteractWithUnit(unsigned short nType, int nUnitId)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, nType);
    if (!pUnit)
    {
        return;
    }

    switch (nType)
    {
    case 2:
    {
        PATH_SetTargetUnit(pPlayer->pDynamicPath, 0);
        int bSelectable = 0;
        if (pUnit)
        {
            bSelectable = (pUnit->dwFlags >> 2) & 1;
        }

        if (bSelectable)
        {
            UNITS_UpdateDirectionAndSpeed(pPlayer, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));

            D2ClientSkillCmdStrc tCmd;
            memset(&tCmd, 0, sizeof(tCmd));
            tCmd.nSkillId = SKILLS_GetSkillIdFromSkill(SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, SKILL_KICK), ".\\UNIT\\UnitMode.cpp", 525);
            if (pUnit->dwClassId == 404)
            {
                if (pUnit->dwAnimMode == 0)
                {
                    D2UnitStrc* pItem = INVENTORY_GetLeftHandWeapon(pPlayer->pInventory);
                    if (!pItem || ITEMS_GetBaseCode(pItem) != 0x20326671)
                    {
                        UNITSND_PlayPlayerSpeech(pPlayer, 0x13);
                        return;
                    }

                    tCmd.nSkillId = SKILLS_GetSkillIdFromSkill(SKILLS_GetSkillById(pPlayer, SKILL_ATTACK, -1), ".\\UNIT\\UnitMode.cpp", 536);
                }
            }
            else if (pUnit->dwClassId == 376)
            {
                if (pUnit->dwAnimMode == 0)
                {
                    MSG_SendTwoDwords(0x13, nType, nUnitId);
                    return;
                }

                if (pUnit->dwAnimMode == 2)
                {
                    D2UnitStrc* pItem = INVENTORY_GetLeftHandWeapon(pPlayer->pInventory);
                    if (!pItem || ITEMS_GetBaseCode(pItem) != 0x20686668)
                    {
                        UNITSND_PlayPlayerSpeech(pPlayer, 0x13);
                        return;
                    }

                    tCmd.nSkillId = SKILLS_GetSkillIdFromSkill(SKILLS_GetSkillById(pPlayer, SKILL_ATTACK, -1), ".\\UNIT\\UnitMode.cpp", 558);
                }
            }

            tCmd.nOwnerGUID = -1;
            tCmd.nTargetType = 2;
            tCmd.f_C = nUnitId;
            SKILLS_StartSkillOnUnit(pPlayer, &tCmd);
        }
        break;
    }

    case 1:
    {
        const unsigned int nTick = GetTickCount();
        if (nTick - pUnit->dwTickCount < 200)
        {
            return;
        }

        pUnit->dwTickCount = nTick;
        break;
    }

    case 0:
        UNITS_UpdateDirectionAndSpeed(pPlayer, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
        break;

    case 4:
        MSG_SendDwords3(0x16, 4, nUnitId, (unsigned char)GAME_GetUIVarState(1));
        return;
    }

    MSG_SendTwoDwords(0x13, nType, nUnitId);
}

// 0x00480B40
void __fastcall UNITMODE_SendUnitActionPacket(int nHeader, int nUnused, int nArg1, int nArg2, int nUnused2)
{
    if (nHeader == 0x13)
    {
        return;
    }
    switch (nHeader)
    {
    case 1: case 3:
        MSG_SendTwoWords(nHeader, nArg1, nArg2);
        return;
    case 2: case 4: case 6: case 7: case 9: case 10: case 13: case 14: case 16: case 17:
        MSG_SendTwoDwords(nHeader, nArg1, nArg2);
        return;
    default:
        MSG_SendTwoWords(nHeader, nArg1, nArg2);
        return;
    }
}


static inline D2SkillsTxt* UMODE_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static inline int UMODE_GetPendingAction(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
    {
        return pUnit->pPlayerData->nMode;
    }
    return 0;
}

static inline void UMODE_SetPendingAction(D2UnitStrc* pUnit, int bFlag, int nAction, int nType, int nId)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
    {
        pUnit->pPlayerData->nState = bFlag;
        pUnit->pPlayerData->nMode = nAction;
        pUnit->pPlayerData->nArg1 = nType;
        pUnit->pPlayerData->nArg2 = nId;
    }
}

// 0x00480BA0
static int UNITMODE_CanUseSkillNow(D2UnitStrc* pPlayer)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pPlayer);
    if (!pSkill)
    {
        return 1;
    }

    D2SkillsTxt* pSkillsTxt = UMODE_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pSkill, gszUnitModeFile, 0x2CC));
    if (!pSkillsTxt || BITARRAY_CHECK((unsigned char*)pSkillsTxt, 63))
    {
        return 1;
    }

    if (pPlayer)
    {
        const int nMode = pPlayer->dwAnimMode;
        if (nMode == 1 || nMode == 5)
        {
            return 1;
        }
    }
    return 0;
}

// 0x00480C10
int __fastcall UNITMODE_DispatchUnitCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int nArg)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        return PLAYER_ApplyUnitCommand(nCommand, pUnit, pTarget, nArg);
    case UNIT_MONSTER:
        MONSTER_HandleMonsterCommand(nCommand, pUnit, pTarget);
        return 1;
    case UNIT_OBJECT:
        OBJECT_HandleObjectCommand(nCommand, pUnit, pTarget);
        return 1;
    case UNIT_ITEM:
        ITEM_HandleItemCommand(nCommand, pUnit, pTarget->nParam1, pTarget->nParam2);
        return 1;
    }
    return 1;
}


// 0x00480C80
static int UNITMODE_IsTargetInRange(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, int nAction)
{
    D2SkillStrc* pSkill;
    switch (nAction)
    {
    case 6:
        pSkill = UNITS_GetLeftSkill(pPlayer);
        break;

    case 13:
        pSkill = UNITS_GetRightSkill(pPlayer);
        break;

    default:
        pSkill = 0;
        break;
    }

    if (pSkill)
    {
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (pSkillsTxt && pSkillsTxt->wSrvDoFunc == 0x13)
        {
            int nRange;
            int nDistance;
            return PLAYER_IsInAuraRange(pSkill, pUnit, &nRange, &nDistance) != 0;
        }
    }

    if (pUnit && pUnit->dwUnitType == UNIT_OBJECT)
    {
        if (UNITS_IsObjectInInteractRange(pPlayer, pUnit) && !UNITS_TestCollisionBetweenInteractingUnits(pPlayer, pUnit, 0x804))
        {
            return 0;
        }
        return 1;
    }

    return UNITS_IsInMeleeRange(pPlayer, pUnit, UNITS_IsInMovingModeEx(pUnit)) == 0;
}

// 0x00480D20
void __fastcall UNITMODE_SetModeOverlay(D2UnitStrc* pUnit, int nMode)
{
    if (!pUnit)
        return;

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        if (nMode != 0 && nMode != 4 && nMode != 0x13)
            return;
    }
    else if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        if (nMode != 0 && nMode != 3 && nMode != 0xD)
            return;
    }
    else
    {
        return;
    }

    const unsigned int dwFlags = pUnit->dwLastHitClass;
    const unsigned int dwKind = dwFlags & 0xF0;
    if (!dwKind || !(dwFlags & 0xF))
        return;

    if (dwKind == 0x20)
        GFX_AddUnitOverlay(pUnit, 0x51, 2, 0, 0, 0, 0, 0);
    else if (dwKind == 0x30)
        GFX_AddUnitOverlay(pUnit, 0x24, 2, 0, 0, 0, 0, 0);
    else if (dwKind == 0x40)
        GFX_AddUnitOverlay(pUnit, 1, 2, 0, 0, 0, 0, 0);
    else if (dwKind == 0x10)
        GFX_AddUnitOverlay(pUnit, 0x36, 2, 0, 0, 0, 0, 0);
    else if (dwKind == 0x70)
        GFX_AddUnitOverlay(pUnit, 0x93, 2, 0, 0, 0, 0, 0);
    else if (dwKind == 0x80)
        GFX_AddUnitOverlay(pUnit, 0x15, 2, 0, 0, 0, 0, 0);
    else if (dwKind == 0x90)
        GFX_AddUnitOverlay(pUnit, 0x71, 2, 0, 0, 0, 0, 0);
}

// 0x00480E30
static int __stdcall UNITMODE_ChangeModeAndRefresh(D2UnitStrc* pUnit, int nMode)
{
    sub_004E4020(pUnit);
    if (pUnit)
        pUnit->dwFlags &= ~0x40u;
    if (UNITS_ChangeAnimMode(pUnit, nMode))
    {
        GFX_RefreshUnitGfx(pUnit, 0);
        return 1;
    }
    return 0;
}

// 0x00480E70
void __fastcall UNITMODE_SetUnitMode(D2UnitStrc* pUnit, int nMode)
{
    sub_004E4020(pUnit);
    if (pUnit)
        pUnit->dwFlags &= ~0x40;
    if (UNITS_ChangeAnimMode(pUnit, nMode))
    {
        GFX_RefreshUnitGfx(pUnit, 0);
        UNITMODE_SetModeOverlay(pUnit, nMode);
        sub_004CC5B0_RequestMode(pUnit, nMode, 0);
    }
}

// 0x00480EC0
void __fastcall UNITMODE_SetUnitModeNoOverlay(D2UnitStrc* pUnit, int nMode)
{
    sub_004E4020(pUnit);
    if (pUnit)
        pUnit->dwFlags &= ~0x40;
    if (UNITS_ChangeAnimMode(pUnit, nMode))
        GFX_RefreshUnitGfx(pUnit, 0);
}

int __cdecl sub_K04_EmitSetUnitMode(D2UnitStrc* pUnit, int nMode)
{
    const int bOk = UNITMODE_ChangeModeAndRefresh(pUnit, nMode);
    sub_K04_EmitUse(pUnit);
    return bOk;
}

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

// 0x00480EF0
void __fastcall UNITMODE_MoveToPosition(D2UnitStrc* pUnit, int nX, int nY, int bSetPosition)
{
    int bMove = 0;
    int nDiff = nX - UNITS_GetUnitXPosition(pUnit);
    if (D2_ABS(nDiff) > 1)
    {
        bMove = 1;
    }
    nDiff = nY - UNITS_GetUnitYPosition(pUnit);
    if (D2_ABS(nDiff) > 1)
    {
        bMove = 1;
    }

    const int nType = pUnit->dwUnitType;
    if ((nType != UNIT_MONSTER || sub_0046C140_TestMonModeFlag(pUnit->dwClassId, 2)) && bMove)
    {
        D2UnitTargetStrc tTarget;
        tTarget.nParam1 = nX;
        tTarget.nParam2 = nY;
        int nCommand = 1;
        switch (nType)
        {
        case UNIT_PLAYER:
            if (pUnit != sub_00463DE0_GetPlayerUnit())
            {
                if (bSetPosition)
                {
                    UNITMODE_SetPosition(pUnit, nX, nY, 2, 0, 0);
                    return;
                }
                nCommand = 0x17;
            }
            break;

        case UNIT_MONSTER:
            tTarget.unk0x0C[0] = 1;
            break;
        }
        tTarget.unk0x0C[1] = 100;
        tTarget.unk0x0C[2] = 15;
        UNITMODE_DispatchUnitCommand(nCommand, pUnit, &tTarget, 0);
    }
    else
    {
        PATH_SetPathingFlag(pUnit->pDynamicPath, 0);
    }
}

// 0x00481030
void __fastcall UNITMODE_DoUnitAction(int nAction, D2UnitStrc* pPlayer, int nArg1, int nArg2, int nArg3)
{
    if (!UNITMODE_CanUseSkillNow(pPlayer))
    {
        return;
    }

    int args[7] = {};
    args[0] = nArg1;
    args[1] = nArg2;

    int nEvent;
    switch (nAction)
    {
    case 1:
        nEvent = 1;
        break;

    case 2:
        nEvent = 0;
        break;

    case 3:
        nEvent = 0x17;
        break;

    case 4:
        nEvent = 0x18;
        break;

    case 19:
        if (nArg1 == 4)
        {
            D2UnitStrc* pItem = CUNIT_FindClientUnit(nArg2, nArg1);
            if (pItem && pItem->dwUnitType == UNIT_ITEM && !sub_00451F30_TestUnitFlag(pItem, 2))
            {
                return;
            }
        }
        nEvent = 2;
        break;

    case 5:
    case 8:
        args[0] = SKILLS_GetSkillIdFromSkill(UNITS_GetLeftSkill(pPlayer), gszUnitModeFile, 0x32C);
        args[1] = SKILLS_GetOwnerGUIDFromSkill(UNITS_GetLeftSkill(pPlayer));
        args[2] = nArg1;
        args[3] = nArg2;
        nEvent = 0x15;
        break;

    case 6:
    case 7:
    case 9:
    case 10:
        args[0] = SKILLS_GetSkillIdFromSkill(UNITS_GetLeftSkill(pPlayer), gszUnitModeFile, 0x336);
        args[1] = SKILLS_GetOwnerGUIDFromSkill(UNITS_GetLeftSkill(pPlayer));
        args[2] = nArg1;
        args[3] = nArg2;
        nEvent = 0x16;
        break;

    case 12:
    case 15:
        args[0] = SKILLS_GetSkillIdFromSkill(UNITS_GetRightSkill(pPlayer), gszUnitModeFile, 0x33E);
        args[1] = SKILLS_GetOwnerGUIDFromSkill(UNITS_GetRightSkill(pPlayer));
        args[2] = nArg1;
        args[3] = nArg2;
        nEvent = 0x15;
        break;

    case 13:
    case 14:
    case 16:
    case 17:
        args[0] = SKILLS_GetSkillIdFromSkill(UNITS_GetRightSkill(pPlayer), gszUnitModeFile, 0x348);
        args[1] = SKILLS_GetOwnerGUIDFromSkill(UNITS_GetRightSkill(pPlayer));
        args[2] = nArg1;
        args[3] = nArg2;
        nEvent = 0x16;
        break;

    default:
        D2_ASSERT(0, 0x352);
    }

    if (nEvent == 1 || nEvent == 0x17)
    {
        if (UMODE_GetPendingAction(pPlayer) == 19)
        {
            return;
        }
    }

    if (sub_00480C10_UnitEvent(nEvent, pPlayer, args, 0))
    {
        switch (nAction)
        {
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
            STATLIST_SetUnitStat(pPlayer, STAT_PIERCE_IDX, STATLIST_GetUnitBaseStat(pPlayer, STAT_PIERCE_IDX, 0) + 1, 0);
            break;
        }
        UNITMODE_SendUnitActionPacket(nAction, pPlayer, nArg1, nArg2, nArg3);
    }

    UMODE_SetPendingAction(pPlayer, 0, 0, 0, 0);
}

static inline D2PlayerDataStrc* sub_GetPlayerDataOrNull(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        return pUnit->pPlayerData;
    return 0;
}

static inline void sub_SetPlayerAction(D2UnitStrc* pPlayer, int nState, int nAction, int nArg1, int nArg2)
{
    if (sub_GetPlayerDataOrNull(pPlayer))
    {
        pPlayer->pPlayerData->nState = nState;
        pPlayer->pPlayerData->nMode = nAction;
        pPlayer->pPlayerData->nArg1 = nArg1;
        pPlayer->pPlayerData->nArg2 = nArg2;
    }
}

// 0x004812E0
static void __stdcall UNITMODE_DoPlayerAction(D2UnitStrc* pPlayer, int nAction, int nArg1, int nArg2)
{
    D2UnitTargetStrc tTarget;
    if (GAME_GetClickFlags() & 8)
    {
        if (UNITMODE_CanUseSkillNow(pPlayer))
        {
            memset(&tTarget, 0, sizeof(tTarget));
            tTarget.nParam1 = nArg1;
            tTarget.nParam2 = nArg2;
            if (UNITMODE_DispatchUnitCommand(0x18, pPlayer, &tTarget, 0))
                MSG_SendTwoDwords(4, nArg1, nArg2);
            sub_SetPlayerAction(pPlayer, 0, 0, 0, 0);
        }
    }
    else if (UNITMODE_CanUseSkillNow(pPlayer))
    {
        memset(&tTarget, 0, sizeof(tTarget));
        tTarget.nParam1 = nArg1;
        tTarget.nParam2 = nArg2;
        if (UNITMODE_DispatchUnitCommand(0, pPlayer, &tTarget, 0))
            MSG_SendTwoDwords(2, nArg1, nArg2);
        sub_SetPlayerAction(pPlayer, 0, 0, 0, 0);
    }
    sub_SetPlayerAction(pPlayer, 1, nAction, nArg1, nArg2);
}

// 0x00481400
static int __stdcall UNITMODE_ActOnPlayer(int nAction, int nType, int nId, D2UnitStrc* pPlayer, D2UnitStrc* pUnit)
{
    if (CUNIT_IsDeadOrDying(pUnit))
    {
        const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
        if (ROSTER_CanLoot(nPlayerId, nId))
        {
            UNITMODE_DoUnitAction(nAction, pPlayer, nType, nId, 0);
            return 0;
        }

        SELECT_RefreshHoverUnit(0);
        return 0;
    }

    {
        int bSelectable = 0;
        if (pUnit)
            bSelectable = (pUnit->dwFlags >> 1) & 1;
        if (!bSelectable)
        {
            SELECT_RefreshHoverUnit(0);
            return 0;
        }
    }

    if (UNITMODE_IsTargetInRange(pPlayer, pUnit, nAction))
    {
        UNITMODE_DoPlayerAction(pPlayer, nAction, nType, nId);
        return 0;
    }

    return 1;
}

static inline D2SkillsTxt* sub_004814A0_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004814A0
static int __stdcall UNITMODE_TryMonsterAction(int nAction, int nArg1, int nArg2, D2UnitStrc* pPlayer, D2UnitStrc* pUnit)
{
    if (CUNIT_IsDeadOrDying(pUnit))
    {
        D2SkillStrc* pSkill;
        switch (nAction)
        {
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
            pSkill = UNITS_GetLeftSkill(pPlayer);
            break;

        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
            pSkill = UNITS_GetRightSkill(pPlayer);
            break;

        default:
            pSkill = 0;
            break;
        }

        if (pSkill)
        {
            int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, gszUnitModeFile, 0x44F);
            D2SkillsTxt* pTxt = sub_004814A0_GetSkillsTxtRecord(nSkillId);
            if (pTxt && BITARRAY_CHECK((unsigned char*)pTxt, 56))
            {
                goto InRange;
            }
        }
        SELECT_RefreshHoverUnit(0);
        return 0;
    }

    {
        int bSelectable = 0;
        if (pUnit)
            bSelectable = (pUnit->dwFlags >> 1) & 1;
        if (!bSelectable)
        {
            SELECT_RefreshHoverUnit(0);
            return 0;
        }
    }

InRange:
    if (UNITMODE_IsTargetInRange(pPlayer, pUnit, nAction))
    {
        UNITMODE_DoPlayerAction(pPlayer, nAction, nArg1, nArg2);
        return 0;
    }
    return 1;
}

static inline int sub_IsUnitTargetable(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    return (pUnit->dwFlags >> 1) & 1;
}

// 0x004815A0
static int __stdcall sub_004815A0_TryUnitAction(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, int nAction, int nArg1, int nArg2)
{
    if (!sub_IsUnitTargetable(pUnit))
    {
        SELECT_RefreshHoverUnit(0);
        return 0;
    }

    if (UNITMODE_IsTargetInRange(pPlayer, pUnit, nAction))
    {
        UNITMODE_DoPlayerAction(pPlayer, nAction, nArg1, nArg2);
        return 0;
    }

    return 1;
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

// 0x00481600
void __fastcall sub_00481600_RunPendingAction(D2UnitStrc* pPlayer)
{
    if (sub_0044BE50(pPlayer) == 0 && pPlayer->pPlayerData && pPlayer->pPlayerData->nState)
    {
        const int nAction = sub_0044BE50(pPlayer) == 0 ? pPlayer->pPlayerData->nMode : 0;
        const int nArg1 = sub_0044BE50(pPlayer) == 0 ? pPlayer->pPlayerData->nArg1 : 0;
        const int nArg2 = sub_0044BE50(pPlayer) == 0 ? pPlayer->pPlayerData->nArg2 : 0;

        D2UnitStrc* pUnit = CUNIT_FindClientUnit(nArg2, nArg1);
        GFX_ClearPendingAction(pPlayer);

        if (nAction == 0x13 && nArg1 == 5)
        {
            GAME_SetInteractDeadline(GAME_GetCurrentTime() + 500);
        }

        if (pUnit && nAction)
        {
            switch (nArg1)
            {
            case 0:
                if (!UNITMODE_ActOnPlayer(nAction, 0, nArg2, pPlayer, pUnit))
                    return;
                break;
            case 1:
                if (!UNITMODE_TryMonsterAction(nAction, 1, nArg2, pPlayer, pUnit))
                    return;
                break;
            case 2:
                if (!sub_004815A0_TryUnitAction(pUnit, pPlayer, nAction, 2, nArg2))
                    return;
                break;
            default:
                if (!sub_00451F30_TestUnitFlag(pUnit, 2))
                {
                    SELECT_RefreshHoverUnit(0);
                    return;
                }
                break;
            }
            UNITMODE_DoUnitAction(nAction, pPlayer, nArg1, nArg2, 0);
        }
    }
}

// 0x00481780
int __cdecl UNITMODE_GetPlayerLevelId()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return 0;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return 0;
    return DUNGEON_GetLevelIdFromRoom(pRoom);
}

// 0x004817A0
int __cdecl UNITMODE_GetPlayerSoundEnviron()
{
    int nLevelId = 0;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
        if (pRoom)
            nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    }
    if (!nLevelId)
        return 0;
    return DATATBLS_GetLevelsTxtRecord(nLevelId)->nSoundEnv;
}

// 0x00481830
void __cdecl sub_00481830()
{
    sub_004DF800();
    sub_004BAAB0();
}


#include "gen/data/Source/D2Client/UNIT/UnitMode.inc"
