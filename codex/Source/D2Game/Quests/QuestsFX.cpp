#include "D2ObjectIds.h"
#include "D2MissileIds.h"
#include "D2MonsterIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2ItemsWorld.h"
#include "D2GameRecords.h"
#include "D2ObjModes.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x00741CFC

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define MAX(a, b) ((a) < (b) ? (b) : (a))

union D2SeedStrc;
struct D2StaticPathStrc;
struct D2UnitFindArgStrc;
struct D2MissilesTxt;
struct D2GameStrc;
struct D2UnitStrc;
struct D2UnitFindDataStrc;
struct D2DataTablesStrc;
struct D2MissileStrc;
struct D2ObjectsTxt;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

enum D2C_M96QuestsFxConstants
{
    EVENTTYPE_MONUMOD = 7,
    MONUMOD_TEMPSUMMON = 21,
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, void* pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950
int __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData); // 0x0065AC70
void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData); // 0x0065AA00
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A4850
D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0
static void __stdcall QUESTSFX_MainHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSize, int nDelayMin, int nDelayMax, int bCheckIfUndead);


typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);

D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30

enum D2C_P11QuestsFxConstants
{
    OBJECT_COMPELLINGORB_STAIRS = 386,
    EVENTTYPE_ENDANIM = 1,
};

D2UnitStrc* __stdcall UNITFINDS_FindUnitInNeighboredRooms(D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId); // 0x0065A620
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

inline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
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

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMissilesTxt[nMissileId];
}

// 0x005DFBF0
static void __stdcall QUESTSFX_MainHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSize, int nDelayMin, int nDelayMax, int bCheckIfUndead)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);

    D2_ASSERT(nDelayMax, 32);
    D2_ASSERT(nDelayMax > nDelayMin, 33);

    D2UnitFindArgStrc unitFindArg;
    memset(&unitFindArg, 0, sizeof(unitFindArg));
    unitFindArg.nX = nX;
    unitFindArg.nSize = nSize;
    unitFindArg.nFlags = 0x583;
    unitFindArg.pUnit = pUnit;
    unitFindArg.nY = nY;

    D2UnitFindDataStrc unitFindData;
    UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, &unitFindData, pRoom, nX, nY, nSize, 0, &unitFindArg);
    UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&unitFindData);

    for (int i = 0; i < unitFindData.nIndex; ++i)
    {
        D2UnitStrc* pMonster = unitFindData.pUnitsArray[i];
        if (pMonster && pMonster->dwUnitType == UNIT_MONSTER)
        {
            int bAllied = 0;
            if (STATLIST_GetUnitAlignment(pMonster) == 0)
            {
                bAllied = 1;
            }

            if (bCheckIfUndead && !MONSTERS_IsUndead(pMonster))
            {
                bAllied = 0;
            }

            if (pMonster->dwClassId != MONSTER_DIABLOCLONE && bAllied)
            {
                const int nDelay = nDelayMin + ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nDelayMax - nDelayMin);
                EVENT_SetEvent(pGame, pMonster, EVENTTYPE_MONUMOD, pGame->dwGameFrame + nDelay, 0, 0);
                D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pMonster, MONUMOD_TEMPSUMMON, 0);
            }
        }
    }

    UNITFINDS_FreeUnitFindData(&unitFindData);
}

// 0x005DFD90
void __fastcall QUESTSFX_Bloodraven(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return QUESTSFX_MainHandler(pGame, pUnit, 35, 25, 125, 1);
}

// 0x005DFDB0
void __fastcall QUESTSFX_SpawnMephistoDeathControlMissile(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x8000;
    missileParams.nMissile = MISSILE_MEPHISTODEATHCONTROL;
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nSkillLevel = 1;
    missileParams.nRange = 100;
    MISSILES_CreateMissileFromParams(pGame, &missileParams);
}

// 0x005DFE00
void __fastcall QUESTSFX_Andariel(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return QUESTSFX_MainHandler(pGame, pUnit, 35, 1, 51, 0);
}

// 0x005DFE20
void __fastcall QUESTSFX_SpawnRadamentDeathMissile(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(MISSILE_RADAMENTDEATH);

    const int nDelayMax = MAX(pMissilesTxtRecord->wRange - 100, 100);

    QUESTSFX_MainHandler(pGame, pUnit, 35, 40, nDelayMax, 0);

    D2GAME_CreateMissile_6FD115E0(pGame, pUnit, 0, 1, MISSILE_RADAMENTDEATH, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
}

// 0x005DFEE0
void __fastcall QUESTSFX_SpawnCompellingOrbMissile(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc* hStairs = UNITFINDS_FindUnitInNeighboredRooms(UNITS_GetRoom(pUnit), UNIT_OBJECT, OBJECT_COMPELLINGORB_STAIRS);
    D2_ASSERT(hStairs, 143);

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x420;
    missileParams.nMissile = MISSILE_ORBMIST;
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nTargetX = CLIENTS_GetUnitX(hStairs);
    missileParams.nTargetY = CLIENTS_GetUnitY(hStairs);
    missileParams.nSkillLevel = 1;

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (pMissile)
    {
        MISSILE_SetTargetX(pMissile, hStairs->dwUnitId);
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(hStairs);
        DUNGEON_ToggleHasPortalFlag(pRoom, 0);
    }
    else if (hStairs->dwAnimMode == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(hStairs, OBJMODE_OPERATING);
        const unsigned int nFrame = pGame->dwGameFrame + (DATATBLS_GetObjectsTxtRecord(OBJECT_COMPELLINGORB_STAIRS)->dwFrameCnt[1] >> 8);
        EVENT_SetEvent(pGame, hStairs, EVENTTYPE_ENDANIM, nFrame, 0, 0);
    }
}

// 0x005E0020
void __fastcall QUESTSFX_Izual(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return QUESTSFX_MainHandler(pGame, pUnit, 105, 1, 2, 0);
}

// 0x005E0040
void __fastcall QUESTSFX_ShenkTheOverseer(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return QUESTSFX_MainHandler(pGame, pUnit, 35, 25, 125, 0);
}
// 0x005E0060
void __fastcall QUESTSFX_OnQuestCompleteModeChange(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
}

D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30

int __fastcall D2GAME_RechargeItem_6FC4BD50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055FE80

// 0x005E0070
void __fastcall QUESTSFX_UberPrimeEvil(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nMonsterId;

    if (!pUnit)
    {
        nMonsterId = -1;
    }
    else
    {
        nMonsterId = pUnit->dwClassId;
    }

    switch (nMonsterId)
    {
    case MONSTER_UBERMEPHISTO:
        pGame->bUberMephistoKilled = 1;
        break;
    case MONSTER_UBERDIABLO:
        pGame->bUberDiabloKilled = 1;
        break;
    case MONSTER_UBERBAAL:
        pGame->bUberBaalKilled = 1;
        break;
    default:
        D2_ASSERT(0, 230);
        return;
    }

    if (pGame->bUberMephistoKilled && pGame->bUberDiabloKilled && pGame->bUberBaalKilled)
    {
        int nItemLevel;
        pUnit->dwDropItemCode = ' 2mc';
        D2UnitStrc* pItem = D2GAME_DropItemAtUnit_6FC4FEC0(pGame, pUnit, ITEMQUAL_UNIQUE, &nItemLevel, 0, -1, 0);
        D2GAME_RechargeItem_6FC4BD50(pGame, 0, pItem);
        pUnit->dwDropItemCode = ' dts';
        const int nClients = pGame->nClients;
        for (int i = 0; i < nClients; i++)
        {
            D2GAME_DropItemAtUnit_6FC4FEC0(pGame, pUnit, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0);
        }
    }
}


