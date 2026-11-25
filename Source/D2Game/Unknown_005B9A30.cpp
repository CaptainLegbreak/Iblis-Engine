#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2GameStrc.h"
struct D2RoomCoordListStrc;
struct D2UnitStrc;

struct D2QuestExStrc
{
    char unk0x00[0x02];
    unsigned char bMonsterSpawned;
    unsigned char f_3;
    unsigned char bSpawning;
    unsigned char unk0x05;
    char unk0x06[0x02];
    int nX;
    int nY;
    int unk0x10[2];
    unsigned char bInitDone;
    char unk0x19[0x0B];
    int nMonsterUnitId;
};
typedef int(__fastcall* QUESTCB)(D2QuestDataStrc*, void*);
struct D2QuestDataStrc
{
    char unk0x00[0x09];
    unsigned char bActive;
    char unk0x0A[0x0E];
    D2QuestExStrc* pQuestDataEx;
    char unk0x1C[0xA4];
    QUESTCB pCallback;
};
D2UnitStrc* __fastcall MONSTERUNIQUE_SpawnUniqueGroup(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int nClassId, int bAllowChampion, unsigned short nX, unsigned short nY, int bAvoidWarps); // 0x005A43E0
D2ActiveRoomStrc* __stdcall DUNGEON_FindRoomBySubtileCoordinates(void* pAct, int a2, int a3);                              // 0x00619DA0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                 // 0x00543640
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                            // 0x00624690

// Out of line as in the original: it takes an argument in esi, a convention the compiler gives only a static whose callers are all in this object.
static __declspec(noinline) void ACT3Q3_SpawnFetishBoss(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2QuestExStrc* pQuestDataEx) // 0x005B9930
{
    pQuestDataEx->bSpawning = 1;
    D2UnitStrc* pMonster = MONSTERUNIQUE_SpawnUniqueGroup(pGame, pRoom, 0, 0x197, 1, 0, 0, 1);
    if (pMonster)
    {
        pQuestDataEx->f_3 = 0;
        pQuestDataEx->bMonsterSpawned = 1;
        pQuestDataEx->nMonsterUnitId = pMonster->dwUnitId;
    }
    pQuestDataEx->bSpawning = 0;
}

static inline bool CanSpawnMonster(const D2QuestExStrc* pQuestDataEx)
{
    return pQuestDataEx->bInitDone == 1 && pQuestDataEx->f_3 && !pQuestDataEx->bMonsterSpawned;
}

// 0x005B9A30
bool __fastcall sub_005B9A30_QuestSeqCallback(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2QuestExStrc* pQuestDataEx = pQuestData->pQuestDataEx;
    pQuestDataEx->unk0x05 = 0;
    if (CanSpawnMonster(pQuestDataEx))
    {
        if (pGame->pAct[2])
        {
            D2ActiveRoomStrc* pRoom = DUNGEON_FindRoomBySubtileCoordinates(pGame->pAct[2], pQuestDataEx->nX, pQuestDataEx->nY);
            if (pRoom)
            {
                D2ActiveRoomStrc** ppRoomList;
                unsigned int nNumRooms;
                DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
                for (unsigned int i = 0; i < nNumRooms; ++i)
                {
                    for (D2UnitStrc* pUnit = ppRoomList[i]->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
                    {
                        if ((!pUnit ? 6 : pUnit->dwUnitType) == 0)
                        {
                            ACT3Q3_SpawnFetishBoss(pGame, pRoom, pQuestDataEx);
                            pQuestData->pCallback = sub_005B9980_QuestCallback;
                            return true;
                        }
                    }
                }
            }
        }
    }

    return true;
}

void __fastcall OBJECTS_InitFunction25_Gidbinn(D2ObjInitFnStrc* pOp) // 0x005B9AE0
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 17);
    if (pQuestData)
    {
        if (pQuestData->bActive)
        {
            D2QuestExStrc* pQuestDataEx = pQuestData->pQuestDataEx;
            pQuestDataEx->bInitDone = 1;
            pQuestDataEx->nX = pOp->nX;
            pQuestDataEx->nY = pOp->nY;
            if (pQuestDataEx->f_3 && !pQuestDataEx->bMonsterSpawned)
            {
                ACT3Q3_SpawnFetishBoss(pOp->pGame, pOp->pRoom, pQuestDataEx);
            }
        }
        else
        {
            UNITS_ChangeAnimMode(pOp->pObject, 2);
        }
    }
    else
    {
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
}
