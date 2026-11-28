#include "D2MonsterIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameTypes.h"
#include "D2CommonApi.h"
struct D2ActiveRoomStrc;
struct D2CoordStrc;
struct D2UnitStrc;

struct D2MonsterDataStrc;
struct D2QuestExStrc;
struct D2ObjInitFnStrc;
struct D2Act2Quest4Strc;

struct D2GameStrc
{
    char unk00[0xA8];
    int dwGameFrame;
    unsigned char unk_AC[0x1874];
    char unk0x1920[0x7A00];
};


struct D2MonsterDataStrc { int unk00[12]; void* interact; };


struct D2QuestExStrc {
    char unk00[12]; unsigned char oldSpawned; unsigned char spawned;
    char unk0E[7]; unsigned char coordinatesSet; char unk16[18];
    int x; int y; int guardX; int guardY; int blockerId; int unitId;
};

struct D2QuestDataStrc
{
    int id;
    union
    {
        D2GameStrc* game;
        D2GameStrc* pGame;
    };
    unsigned char act;
    union
    {
        unsigned char notIntro;
        bool bNotIntro;
    };
    unsigned char active;
    unsigned char lastState;
    union
    {
        unsigned char state;
        unsigned char fState;
    };
    char unk0D[11];
    union
    {
        D2QuestExStrc* ex;
        void* pQuestDataEx;
    };
};

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*,int,int); // 0x00552F60
int __fastcall MONSTERAI_HasInteractUnit(void*); // 0x00572DC0
void __fastcall MONSTERAI_CloseNpcInteractions(D2GameStrc* pGame, D2UnitStrc* pMonster, void(__fastcall* pCallback)(D2UnitStrc*), char bClientSide); // 0x00573180
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc*,int); // 0x00543640
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc*,int,int); // 0x00463740
#include "D2GameFuncs.h"
#include "D2CommonApi2.h"
D2UnitStrc* __fastcall D2GAME_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20


struct D2Act2Quest4Strc
{
    unsigned char unused0x00[4];
    unsigned char bDrognanActivated;
    unsigned char pad0x05[3];
    D2ActiveRoomStrc* pRoom;
    unsigned char bJerhynStartInitialized;
    unsigned char bJerhynPalaceInitialized;
    unsigned char bPalaceOpen;
    unsigned char bJerhynTeleportedToPalace;
    unsigned char bGuardMoveStarted;
    unsigned char bHaremBlockerInitialized;
    unsigned char unk0x12;
    unsigned char unk0x13;
    unsigned char bJerhynInPalace;
    unsigned char bJerhynCoordinatesStored;
    unsigned char bPortalToCanyonOpen;
    unsigned char unused0x17;
    unsigned char bGuardAtPost;
    unsigned char bGuardSteppedAside;
    unsigned char bPlayerCloseToHaremBlocker;
    unsigned char pad0x1B;
    int nPlayerCloseToHaremBlockerGUID;
    D2CoordStrc pHaremBlockerCoords;
    D2CoordStrc pJerhynCoords;
    D2CoordStrc pGuardCoords;
    int nHaremBlockerGUID;
};

typedef int (__fastcall* SUNIT_ITERATEFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, SUNIT_ITERATEFN pfIterate); // 0x005537D0
int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pInputRoom, int nX, int nY, int bSkipCollisionSearch, int bSyncOtherPlayersOnly); // 0x00554EA0
bool __fastcall ACT2Q6_IsJerhynTalkDone(D2GameStrc* pGame); // 0x0059D7C0
unsigned char __fastcall ACT2Q6_IsAwaitingJerhynTalk(D2GameStrc* pGame); // 0x0059D7E0
int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC5C0
int __fastcall ACT2Q4_UnitIterate_CheckDistanceToHaremBlocker(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059B820
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

static inline void* GetMonsterInteract(D2UnitStrc* unit) {
    if (unit && unit->dwUnitType==UNIT_MONSTER && unit->pMonsterData) return unit->pMonsterData->interact;
    return 0;
}

static
// 0x0059EF70
void __stdcall ACT2Q4_InitializeJerhynMonster(D2QuestDataStrc* quest,D2ActiveRoomStrc* room,D2CoordStrc* coords) {
    D2QuestExStrc* ex=quest->ex;
    if (ex->oldSpawned==1) {
        D2UnitStrc* unit=SUNIT_GetServerUnit(quest->game,1,ex->unitId);
        if (unit) {
            void* interact=GetMonsterInteract(unit);
            if (MONSTERAI_HasInteractUnit(interact)) {
                MONSTERAI_CloseNpcInteractions(quest->game,unit,0,1);
                return;
            }
// build: symbol ?GAME_RemoveUnit@* 0x0052E050
            GAME_RemoveUnit(unit,quest->game);
            ex->oldSpawned=0;
        }
    }
    if (ex->spawned==1) return;
    D2QuestDataStrc* other=QUESTS_GetQuestData(quest->game,13);
    int bDone=1;
    if (other && other->notIntro && other->state < 2) bDone=0;
    if (bDone) coords->nX+=15;
    else coords->nX-=10;
    coords->nY-=3;
    D2ActiveRoomStrc* found=sub_00463740_FindRoomAtPoint(room,coords->nX,coords->nY);
    QUESTS_GetFreePosition(room,coords,3,0x100,&found,9,100);
    D2UnitStrc* npc=D2GAME_SpawnMonster(quest->game,found,coords->nX,coords->nY,MONSTER_JERHYN,1,-1,0);
    if (!npc) npc=D2GAME_SpawnMonster(quest->game,found,coords->nX,coords->nY,MONSTER_JERHYN,1,2,0);
    if (npc) {
        npc->dwFlags|=0x03000000;
        ex=quest->ex;
        ex->spawned=1;
        if (!ex->coordinatesSet) {
            ex->coordinatesSet=1;
            ex->x=coords->nX;
            ex->y=coords->nY;
        }
    }
}


// 0x0059F580
void __fastcall ACT2Q4_GetAndUpdatePalaceNpcState(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pContinueAi, int* pIdle)
{
    D2QuestDataStrc* pQuestData11 = QUESTS_GetQuestData(pGame, 11);
    if (!pQuestData11 || !pQuestData11->bNotIntro)
    {
        *pContinueAi = 1;
        *pIdle = 0;
        return;
    }

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData11->pQuestDataEx;
    if (!pQuestDataEx->bJerhynPalaceInitialized)
    {
        *pContinueAi = 1;
        *pIdle = 0;
        return;
    }

    if (QUESTS_GetGlobalState(pGame, 12, 13) || QUESTS_GetGlobalState(pGame, 14, 13) || ACT2Q6_IsJerhynTalkDone(pGame))
    {
        *pContinueAi = 1;
        *pIdle = 0;
        return;
    }

    if (pQuestDataEx->bJerhynInPalace)
    {
        *pContinueAi = 1;
        *pIdle = 0;
        return;
    }

    {
        if (ACT2Q6_IsAwaitingJerhynTalk(pGame))
        {
            pQuestDataEx->unk0x12 = 1;
        }

        if (pQuestDataEx->unk0x12 == 1)
        {
            if (!pQuestDataEx->unk0x13 || pQuestDataEx->bJerhynTeleportedToPalace)
            {
                pQuestDataEx->bPlayerCloseToHaremBlocker = 0;
                pQuestDataEx->nPlayerCloseToHaremBlockerGUID = 0;
                SUNIT_IterateUnitsOfType(pQuestData11->pGame, 0, 0, ACT2Q4_UnitIterate_CheckDistanceToHaremBlocker);

                if (pQuestDataEx->bPlayerCloseToHaremBlocker)
                {
                    AITACTICS_WalkToTargetCoordinates(pGame, pUnit, pQuestDataEx->pHaremBlockerCoords.nX, pQuestDataEx->pHaremBlockerCoords.nY);
                    pQuestDataEx->unk0x13 = 1;
                    pQuestDataEx->unk0x12 = 0;
                    *pContinueAi = 0;
                    *pIdle = 0;
                    return;
                }

                *pContinueAi = 0;
                *pIdle = 1;
                return;
            }

            *pContinueAi = 0;
            *pIdle = 1;

            if (pQuestDataEx->bHaremBlockerInitialized != 1)
            {
                return;
            }

            if ((unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, pQuestDataEx->pHaremBlockerCoords.nX, pQuestDataEx->pHaremBlockerCoords.nY) <= 2)
            {
                D2UnitStrc* pHaremBlocker = SUNIT_GetServerUnit(pGame, 2, pQuestDataEx->nHaremBlockerGUID);
                if (!pHaremBlocker)
                {
                    *pContinueAi = 0;
                    *pIdle = 1;
                    return;
                }

                D2CoordStrc pCoord;
                UNITS_GetCoords(pHaremBlocker, &pCoord);
                pCoord.nX += 4;
                D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pHaremBlocker);
                if (!COLLISION_GetFreeCoordinates(pRoom, &pCoord, 1, 0x3C01, 0) && !COLLISION_GetFreeCoordinates(pRoom, &pCoord, 2, 0x3C01, 0) && !COLLISION_GetFreeCoordinates(pRoom, &pCoord, 3, 0x3C01, 0))
                {
                    *pContinueAi = 0;
                    *pIdle = 1;
                    return;
                }

                if (!SUNIT_TeleportUnit(pGame, pUnit, pRoom, pCoord.nX, pCoord.nY, 0, 0))
                {
                    *pContinueAi = 0;
                    *pIdle = 1;
                    return;
                }

                pQuestDataEx->bJerhynTeleportedToPalace = 1;
                pQuestDataEx->bJerhynInPalace = 1;
                return;
            }

            pQuestDataEx->bGuardSteppedAside = 1;
            pQuestDataEx->bGuardAtPost = 0;
            AITACTICS_WalkToTargetCoordinates(pGame, pUnit, pQuestDataEx->pHaremBlockerCoords.nX, pQuestDataEx->pHaremBlockerCoords.nY);
            *pIdle = 0;
            return;
        }
    }

    *pContinueAi = 1;
    *pIdle = 0;
}

// 0x0059F820
void __fastcall sub_0059F820_ClearGameBlock(D2GameStrc* pGame)
{
    memset(pGame->unk0x1920, 0, sizeof(pGame->unk0x1920));
}
