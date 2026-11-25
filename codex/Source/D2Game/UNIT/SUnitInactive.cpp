#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2Drlg.h"
#include "D2InactiveUnits.h"
#include "D2ItemsWorld.h"
#include "D2GameRecords.h"
#include "D2GameObjs.h"
#include "D2GameTypes.h"
#include "D2UnitData.h"
#include "D2LanguageNames.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_MONSTER 1

struct D2MinionListStrc;

struct D2InactiveMonsterNodeStrc;

struct D2InactiveUnitNodeStrc;

struct D2InactiveItemNodeStrc;

struct D2ItemDataStrc;

struct D2InactiveUnitListStrc;

struct D2DrlgCoordsStrc;


union D2SeedStrc;

struct D2ObjectDataStrc;

struct D2StaticPathStrc;

struct D2MonsterDataStrc;

struct D2AiCmdStrc;

struct D2MonStatsTxt;

struct D2MonStats2Txt;

struct D2UnitStrc;

struct D2GameStrc;

struct D2ItemSaveStrc;

struct D2ActiveRoomStrc;

struct D2MapAIStrc;

struct D2DataTablesStrc;

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

void __fastcall AIGENERAL_FreeAllMinionLists(D2GameStrc* pGame, D2MinionListStrc* pMinionList); // 0x0058F350

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

int __stdcall ITEMS_GetCompactItemDataFromBitstreamDefault(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, void* pItemSave); // 0x0062E410

D2UnitStrc* __fastcall ITEMS_CreateItemFromBitstream(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char* pBitstream, unsigned int nBufferSize, int bCheckForHeader, D2ItemSaveStrc* pItemSave, unsigned int* pSize, unsigned int dwVersion); // 0x00558CB0

D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0

int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage); // 0x0063B210

void __fastcall D2GAME_ITEMS_UpdateStatList_6FC4BC00(D2GameStrc* pGame, D2UnitStrc* pSocketable, D2UnitStrc* pItem); // 0x0055FE60


int __stdcall ITEMS_SerializeItemToBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bServer, int bSaveItemInv, int bGamble); // 0x006313E0

int __fastcall ITEMS_GetGroundRemovalTime(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00558A10

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

static D2InactiveUnitListStrc* __stdcall SUNITINACTIVE_GetListNodeFromRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int bAllocNewNode);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

extern "C" const char gszSUnitInactiveSourceFile[]; // 0x006E0BC8

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0

void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __fastcall AITHINK_GetSpecialStateFromAiControl(D2AiControlStrc* pAiControl); // 0x005B0D60

unsigned short __fastcall MONSTERUNIQUE_GetNameSeed(D2UnitStrc* pUnit); // 0x005A0140

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit); // 0x005A01E0

void __fastcall QUESTS_SetGoldenBirdSpawn(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00544F20

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

unsigned char* __fastcall MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit); // 0x005A0120

void __fastcall AIGENERAL_GetAiControlInfo(D2UnitStrc* pUnit, int* pOwnerGUID, int* pOwnerType, int* pAiControlFlag1, int* pAiControlFlag2, D2MinionListStrc** ppMinionList); // 0x0058F440

D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0

D2MapAIStrc* __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc* pUnit); // 0x0058F000

D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc* pMapAI2); // 0x00666120

int __fastcall AIGENERAL_GetAiControlParam(D2UnitStrc* pUnit, int nIndex); // 0x0058EC50

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

int __fastcall EVENT_GetEventFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent); // 0x005415A0

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

unsigned char __fastcall D2GAME_CheckIfSparklyChest_6FCBD7F0(D2UnitStrc* pUnit); // 0x005540D0

void __fastcall SUNIT_SetAlignment(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

int __fastcall PLAYERPETS_HandlePetDeactivation(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit); // 0x005752B0

void __fastcall AIGENERAL_SetAiControlParam(D2UnitStrc* pMonster, int nIndex, int nParamValue); // 0x0058EC00

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer); // 0x00627260

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740

D2ActiveRoomStrc* __stdcall DUNGEON_FindRoomBySubtileCoordinates(D2DrlgActStrc* pAct, int nX, int nY); // 0x00619DA0

static int SUNITINACTIVE_IsItemNodeAlive(D2InactiveItemNodeStrc* pNode, D2GameStrc* pGame);

struct D2StatListStrc;

struct D2AiControlStrc;

struct D2DynamicPathStrc;

// build: symbol ?gnInactiveCmdParam1@* 0x007314C0
#include "gen/data/Source/D2Game/UNIT/SUnitInactive/gnInactiveCmdParam1.inc"

// build: symbol ?gnInactiveNoXpParam2@* 0x007314C4
#include "gen/data/Source/D2Game/UNIT/SUnitInactive/gnInactiveNoXpParam2.inc"

// build: symbol ?gnInactiveNoTcParam2@* 0x007314C8
#include "gen/data/Source/D2Game/UNIT/SUnitInactive/gnInactiveNoTcParam2.inc"

int __fastcall MONSTER_CheckSummonerFlag(D2UnitStrc* pUnit, int nFlag);                                      // 0x00573540

int __fastcall MONSTER_GetLevelId(D2UnitStrc* pUnit);                                                        // 0x00573520

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

static D2InactiveUnitListStrc* __stdcall SUNITINACTIVE_GetListNodeFromActAndCoordinates(D2GameStrc* pGame, int nAct, int nX, int nY, int bAllocNewNode);

struct D2InventoryStrc;

struct D2ObjectsTxt;

int __stdcall ITEMS_GetOwnerId(D2UnitStrc* pItem);                                                           // 0x00629F20

int __stdcall UNITS_IsShrine(D2UnitStrc* pUnit);                                                     // 0x00621B00

int __stdcall DRLG_GetSaveMonstersFromLevelId(int nLevelId);                                                // 0x00642820

int __stdcall STATES_CheckStateMaskUdeadOnUnit(D2UnitStrc* pUnit);                                          // 0x0063A770

void __fastcall TARGETS_RemoveUnitNode(D2GameStrc* pGame, D2UnitStrc* pUnit);                         // 0x005B1A90

void __stdcall UNITROOM_UpdatePath(D2UnitStrc* pUnit);                                                      // 0x0064C450

static void __stdcall SUNITINACTIVE_SaveSpecialMonsterParameters(D2GameStrc* pGame, D2InactiveMonsterNodeStrc* pNode, D2UnitStrc* pUnit); // 0x00541FE0

static void __stdcall SUNITINACTIVE_CompressInactiveMonster(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005421A0

static void __stdcall SUNITINACTIVE_CompressInactiveItem(D2InactiveUnitListStrc* pList, D2GameStrc* pGame, D2InactiveItemNodeStrc** ppItemNode, D2UnitStrc* pItem); // 0x00541B10

static void __stdcall SUNITINACTIVE_CompressInactiveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00542E10

static void __stdcall SUNITINACTIVE_CompressMonsterIfNeeded(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005431F0

struct D2ShrinesTxt;

struct D2SpawnAreaStrc;

int __fastcall ACT4Q2_IsChaosSanctumCleared(D2GameStrc*); // 0x005B5210

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*,int,int); // 0x00552F60

void __fastcall SUNIT_Restore(D2GameStrc*,D2UnitStrc*,D2ActiveRoomStrc*,int,int); // 0x00554A30

D2UnitStrc* __fastcall MONSTERSPAWN_SpawnWithUnitId(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nUnitGUID, int a8, short nFlags); // 0x005B30E0

D2UnitStrc* __fastcall MONSTERUNIQUE_RestoreUniqueMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nClassId, int nUnitGUID, unsigned short nNameSeed, int bChampion, int bSuperUnique, short nBossHcIdx, unsigned char* pUMods); // 0x005A4440

D2UnitStrc* __fastcall MONSTERUNIQUE_RestoreMinion(D2GameStrc*,D2ActiveRoomStrc*,int,int,int,int,unsigned char*); // 0x005A46E0

int __fastcall MONSTERREGION_FindSpawnLocation(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2SpawnAreaStrc* pArea, int nClassId, int* pX, int* pY, int bAvoidWarps); // 0x0054DC40

void __fastcall D2Common_10136(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, int nSize, unsigned short nMask, D2ActiveRoomStrc** ppRoom); // 0x0064E840

void __fastcall AIGENERAL_SetAiControlInfo(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nOwnerGUID, unsigned int nOwnerType, int bSetFlag1, int bSetFlag2, D2MinionListStrc* pMinionList); // 0x0058F4D0

void __fastcall AITHINK_ExecuteAiFn(D2GameStrc*,D2UnitStrc*,D2AiControlStrc*,int); // 0x005B0E00

void __fastcall TARGETS_InsertUnitNode(D2GameStrc*,D2UnitStrc*,int,int); // 0x005B1990

void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc*,D2UnitStrc*,int,int); // 0x005A4850

void __fastcall MONSTERREGION_AdjustCountsForInactiveMonster(D2MonsterRegionStrc**,int,int,int,int,int,D2UnitStrc*); // 0x00547ED0

void __fastcall DRLGPRESET_FreeMapAI(void*,D2MapAIStrc*); // 0x00666130

D2UnitStrc* __fastcall SUNIT_CreatePresetUnit(D2GameStrc*,D2ActiveRoomStrc*,int,int,int,int,int,int); // 0x005557D0

D2ShrinesTxt* __stdcall DATATBLS_GetShrinesTxtRecord(int nShrineId); // 0x006414B0

void __stdcall UNITS_SetShrineTxtRecordInObjectData(D2UnitStrc* pUnit, D2ShrinesTxt* pShrinesTxtRecord); // 0x00621BB0

void __stdcall UNITS_ChangeAnimMode(D2UnitStrc*,int); // 0x00624690

void __fastcall EVENT_SetEvent(D2GameStrc*,D2UnitStrc*,int,int,int,int); // 0x005417D0

unsigned char __fastcall OBJECTS_GetRegenerateMax(D2ObjectsTxt*); // 0x00552AA0

unsigned char __fastcall OBJECTS_GetRegenerateSteps(); // 0x00552AB0

static void __stdcall SUNITINACTIVE_RestoreInactiveMonsters(D2GameStrc*,D2ActiveRoomStrc*);

void __fastcall SUNITINACTIVE_RestoreInactiveUnits(D2GameStrc*,D2ActiveRoomStrc*); // 0x00542B40

static void __stdcall SUNITINACTIVE_RestoreSpecialMonsterParameters(D2GameStrc* pGame, D2InactiveMonsterNodeStrc* pNode, D2UnitStrc* pUnit);

static void __stdcall SUNITINACTIVE_TakeInactiveListNode(D2InactiveUnitNodeStrc** ppUnitNode, D2InactiveItemNodeStrc** ppItemNode, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);

static D2UnitStrc* __stdcall SUNITINACTIVE_RestoreInactiveItem(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2InactiveItemNodeStrc* pItemNode);

static void __stdcall SUNITINACTIVE_RestoreInactiveItems(D2ActiveRoomStrc* pRoom, D2GameStrc* pGame, D2InactiveItemNodeStrc* pItemNode);


static void __stdcall SUNITINACTIVE_CompressInactiveItem(D2InactiveUnitListStrc* pList, D2InactiveItemNodeStrc** ppItemNode, D2GameStrc* pGame, D2UnitStrc* pItem);

// 0x00541880
void __fastcall SUNITINACTIVE_SetItemActionStamp(D2UnitStrc* pItem, int nStamp)
{
    pItem->pItemData->dwActionStamp = nStamp;
}

// 0x00541890
static void SUNITINACTIVE_FreeInactiveMonsterNode(D2GameStrc* pGame, D2InactiveMonsterNodeStrc* pInactiveMonsterNode)
{
    if (pInactiveMonsterNode->pMapAI)
    {
        DRLGPRESET_FreeMapAI(pGame->pMemoryPool, pInactiveMonsterNode->pMapAI);
    }
    FOG_FreeServerMemory(pGame->pMemoryPool, pInactiveMonsterNode, ".\\UNIT\\SUnitInactive.cpp", 140, 0);
}

void __fastcall sub_M105_Emit_00541970(D2GameStrc* pGame, D2InactiveUnitListStrc* pList)
{
    D2InactiveItemNodeStrc* pPrevious = 0;
    D2InactiveItemNodeStrc* pCurrent = pList->pInactiveItems;
    while (pCurrent)
    {
        D2InactiveItemNodeStrc* pNext = pCurrent->pNext;
        if (!SUNITINACTIVE_IsItemNodeAlive(pCurrent, pGame))
        {
            if (pPrevious)
                pPrevious->pNext = pNext;
            else
                pList->pInactiveItems = pNext;
            FOG_FreeServerMemory(pGame->pMemoryPool, pCurrent, ".\\UNIT\\SUnitInactive.cpp", 0x723, 0);
        }
        else
        {
            pPrevious = pCurrent;
        }
        pCurrent = pNext;
    }
}

// 0x005418C0
static void __stdcall SUNITINACTIVE_TakeInactiveListNode(D2InactiveUnitNodeStrc** ppUnitNode, D2InactiveItemNodeStrc** ppItemNode, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    *ppUnitNode = 0;
    *ppItemNode = 0;
    const int nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);

    D2InactiveUnitListStrc* pPrevious = 0;
    for (D2InactiveUnitListStrc* pList = pGame->pInactiveUnitList[nAct]; pList; pList = pList->pNext)
    {
        if (tCoords.nSubtileX > pList->nX)
        {
            return;
        }

        if (tCoords.nSubtileX == pList->nX && tCoords.nSubtileY == pList->nY)
        {
            if (pPrevious)
            {
                pPrevious->pNext = pList->pNext;
            }
            else
            {
                pGame->pInactiveUnitList[nAct] = pList->pNext;
            }

            *ppUnitNode = pList->pInactiveUnits;
            *ppItemNode = pList->pInactiveItems;
            FOG_FreeServerMemory(pGame->pMemoryPool, pList, ".\\UNIT\\SUnitInactive.cpp", 0xB6, 0);
            return;
        }

        pPrevious = pList;
    }
}

// 0x00541970
static int SUNITINACTIVE_IsItemNodeAlive(D2InactiveItemNodeStrc* pNode, D2GameStrc* pGame)
{
    const int nFrame = pNode->nFrame;
    if (!nFrame)
        return 1;
    return pGame->dwGameFrame <= nFrame;
}

// 0x00541990
static D2UnitStrc* __stdcall SUNITINACTIVE_RestoreInactiveItem(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2InactiveItemNodeStrc* pItemNode)
{
    D2ItemSaveStrc tItemSave;
    unsigned int nSize;
    unsigned char* pBitstream = pItemNode->pBitstream;
    unsigned int nAvailableSize = pItemNode->nBitstreamSize;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pBitstream, nAvailableSize, 1, &tItemSave);
    D2UnitStrc* pItem = ITEMS_CreateItemFromBitstream(pGame, pRoom, pBitstream, nAvailableSize, 1, &tItemSave, &nSize, 0x60);
    if (!pItem)
    {
        return 0;
    }

    pBitstream += nSize;
    nAvailableSize -= nSize;

    const int nFrame = pItemNode->nFrame;
    if (nFrame && nFrame < pGame->dwGameFrame + 15000)
    {
        pItem->pItemData->dwActionStamp = pGame->dwGameFrame + 15000;
    }
    else
    {
        pItem->pItemData->dwActionStamp = nFrame;
    }

    if (tItemSave.nItemFileIndex)
    {
        D2InventoryStrc* pInventory = pItem->pInventory;
        if (!pInventory)
        {
            pInventory = INVENTORY_AllocInventory(0, pItem);
        }

        const int nSockets = tItemSave.nItemFileIndex;
        for (int i = 0; i < nSockets; ++i)
        {
            ITEMS_GetCompactItemDataFromBitstreamDefault(pBitstream, nAvailableSize, 1, &tItemSave);
            D2UnitStrc* pSocketable = ITEMS_CreateItemFromBitstream(pGame, 0, pBitstream, nAvailableSize, 1, &tItemSave, &nSize, 0x60);
            D2_ASSERT(pSocketable, 0x10C);
            pBitstream += nSize;
            nAvailableSize -= nSize;
            INVENTORY_PlaceItemInSocket(pInventory, pSocketable, 1);
            D2GAME_ITEMS_UpdateStatList_6FC4BC00(pGame, pSocketable, pItem);
        }
    }

    return pItem;
}

// 0x00541AC0
static void __stdcall SUNITINACTIVE_RestoreInactiveItems(D2ActiveRoomStrc* pRoom, D2GameStrc* pGame, D2InactiveItemNodeStrc* pItemNode)
{
    while (pItemNode)
    {
        D2InactiveItemNodeStrc* pNext = pItemNode->pNext;
        if (!pItemNode->nFrame || pGame->dwGameFrame <= pItemNode->nFrame)
        {
            SUNITINACTIVE_RestoreInactiveItem(pGame, pRoom, pItemNode);
        }

        FOG_FreeServerMemory(pGame->pMemoryPool, pItemNode, ".\\UNIT\\SUnitInactive.cpp", 0x126, 0);
        pItemNode = pNext;
    }
}

// 0x00541B10
static void __stdcall SUNITINACTIVE_CompressInactiveItem(D2InactiveUnitListStrc* pList, D2GameStrc* pGame, D2InactiveItemNodeStrc** ppItemNode, D2UnitStrc* pItem)
{
    D2InactiveItemBufferStrc tNode;
    tNode.nOwnerId = ITEMS_GetOwnerId(pItem);
    tNode.pNext = 0;
    tNode.nBitstreamSize = ITEMS_SerializeItemToBitstream(pItem, tNode.pBitstream, sizeof(tNode.pBitstream), 1, 1, 0);
    tNode.nFrame = ITEMS_GetGroundRemovalTime(pGame, pItem);

    const int nNodeSize = tNode.nBitstreamSize + 15;
    D2InactiveItemNodeStrc* pItemNode = (D2InactiveItemNodeStrc*)sub_0040B430(pGame->pMemoryPool, nNodeSize, ".\\UNIT\\SUnitInactive.cpp", 0x1E2, 0);
    memcpy(pItemNode, &tNode, nNodeSize);

    D2InventoryStrc* pInventory;
    if (ITEMS_CheckIfSocketable(pItem) && (pInventory = pItem->pInventory) != 0)
    {
        D2UnitStrc* pSocketable = INVENTORY_GetFirstItem(pInventory);
        while (pSocketable)
        {
            D2UnitStrc* pNext = INVENTORY_GetNextItem(pSocketable);
            D2UnitStrc* pSocketed = INVENTORY_UnitIsItem(pSocketable);
            INVENTORY_RemoveItemFromInventory(pInventory, pSocketed);
            SUNIT_RemoveUnit(pGame, pSocketed);
            pSocketable = pNext;
        }
    }

    SUNIT_RemoveUnit(pGame, pItem);

    if (ppItemNode)
    {
        *ppItemNode = pItemNode;
    }
    else
    {
        pItemNode->pNext = pList->pInactiveItems;
        pList->pInactiveItems = pItemNode;
    }
}

// 0x00541C50
static void SUNITINACTIVE_DeleteInactiveMonsterNode(D2GameStrc* pGame, unsigned short nClassId, unsigned char nAct)
{
    D2InactiveUnitListStrc* pInactiveUnitList = pGame->pInactiveUnitList[nAct];
    while (pInactiveUnitList)
    {
        D2InactiveMonsterNodeStrc* pInactiveMonsterNode = pInactiveUnitList->pInactiveMonsters;
        D2InactiveMonsterNodeStrc* pPreviousMonsterNode = 0;
        while (pInactiveMonsterNode)
        {
            if (pInactiveMonsterNode->nClassId == nClassId)
            {
                if (pInactiveMonsterNode == pInactiveUnitList->pInactiveMonsters)
                {
                    pInactiveUnitList->pInactiveMonsters = pInactiveMonsterNode->pNext;
                }
                else
                {
                    pPreviousMonsterNode->pNext = pInactiveMonsterNode->pNext;
                }
                AIGENERAL_FreeAllMinionLists(pGame, pInactiveMonsterNode->pMinionList);
                SUNITINACTIVE_FreeInactiveMonsterNode(pGame, pInactiveMonsterNode);
                return;
            }
            pPreviousMonsterNode = pInactiveMonsterNode;
            pInactiveMonsterNode = pInactiveMonsterNode->pNext;
        }
        pInactiveUnitList = pInactiveUnitList->pNext;
    }
}

// 0x00541CD0
static void SUNITINACTIVE_FreeInactiveMonsters(D2GameStrc* pGame, D2InactiveUnitListStrc* pList)
{
    D2InactiveMonsterNodeStrc* pCurrent = pList->pInactiveMonsters;
    while (pCurrent)
    {
        D2InactiveMonsterNodeStrc* pNode = pCurrent;
        pCurrent = pCurrent->pNext;
        AIGENERAL_FreeAllMinionLists(pGame, pNode->pMinionList);
        SUNITINACTIVE_FreeInactiveMonsterNode(pGame, pNode);
    }
}

D2InactiveMonsterNodeStrc* __stdcall sub_C899_Emit_00541DE0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int bAlloc)
{
    D2InactiveUnitListStrc* pList = SUNITINACTIVE_GetListNodeFromRoom(pGame, pRoom, bAlloc);
    return pList ? pList->pInactiveMonsters : 0;
}

// 0x00541D20
static D2InactiveUnitListStrc* __stdcall SUNITINACTIVE_GetListNodeFromActAndCoordinates(D2GameStrc* pGame, int nAct, int nX, int nY, int bAllocNewNode)
{
    int bFound = 0;
    D2InactiveUnitListStrc* pCurrent = pGame->pInactiveUnitList[nAct];
    D2InactiveUnitListStrc* pPrevious = 0;
    while (pCurrent)
    {
        if (nX == pCurrent->nX && nY == pCurrent->nY)
        {
            bFound = 1;
            break;
        }

        if (nX > pCurrent->nX)
        {
            break;
        }

        pPrevious = pCurrent;
        pCurrent = pCurrent->pNext;
    }

    if (!bAllocNewNode)
    {
        return bFound ? pCurrent : 0;
    }

    if (!bFound)
    {
        D2InactiveUnitListStrc* pNew = (D2InactiveUnitListStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2InactiveUnitListStrc), gszSUnitInactiveSourceFile, 0x424, 0);
        memset(&pNew->pInactiveItems, 0, 12);
        pNew->nX = nX;
        pNew->nY = nY;
        pNew->pNext = pCurrent;
        if (pPrevious)
        {
            pPrevious->pNext = pNew;
        }
        else
        {
            pGame->pInactiveUnitList[nAct] = pNew;
        }
        pCurrent = pNew;
    }

    return pCurrent;
}

// 0x00541DE0
static D2InactiveUnitListStrc* __stdcall SUNITINACTIVE_GetListNodeFromRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int bAllocNewNode)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    const int nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    return SUNITINACTIVE_GetListNodeFromActAndCoordinates(pGame, nAct, tCoords.nSubtileX, tCoords.nSubtileY, bAllocNewNode);
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

inline int MONSTERS_GetBaseIdInl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[nMonsterId];
        if (pMonStatsTxtRecord)
        {
            return pMonStatsTxtRecord->nBaseId;
        }
    }
    return nMonsterId;
}

inline unsigned char MONSTERS_GetComponent10Inl(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent[10];
    }
    return 0;
}

inline int CLIENTS_GetUnitXInl(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInl(D2UnitStrc* pUnit)
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

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnitInl(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }
    return 0;
}

#pragma intrinsic(memset)

inline D2MonsterDataStrc* MONSTERUNIQUE_GetMonsterDataInl(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}

inline void MONSTERS_SetComponentInl(D2UnitStrc* pUnit, int nComponent, unsigned char nValue)
{
    D2MonsterDataStrc* pMonsterData = MONSTERUNIQUE_GetMonsterDataInl(pUnit);
    if (pMonsterData)
    {
        pMonsterData->nComponent[nComponent] = nValue;
    }
}

// 0x00541E20
static void __stdcall SUNITINACTIVE_RestoreSpecialMonsterParameters(D2GameStrc* pGame, D2InactiveMonsterNodeStrc* pNode, D2UnitStrc* pUnit)
{
    const int nClassId = pUnit->dwClassId;
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInl(nClassId);

    if (BITARRAY_CHECK(pMonStatsTxtRecord->nMonStatsFlags, 9)
        || BITARRAY_CHECK(pMonStatsTxtRecord->nMonStatsFlags, 8)
        || BITARRAY_CHECK(pMonStatsTxtRecord->nMonStatsFlags, 10))
    {
        D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 10, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = pNode->nCmdParam1;
            pAiCmd->nCmdParam[2] = pNode->nCmdParam2;
            pAiCmd->nCmdParam[3] = 0;
        }

        D2MapAIStrc** ppMapAI = &pNode->pMapAI;
        D2MapAIStrc* pMapAI = AIGENERAL_GetMapAiFromUnit(pUnit);
        if (*ppMapAI)
        {
            DRLGPRESET_ChangeMapAI(ppMapAI, pMapAI);
        }
    }

    if (nClassId == 0x10B || nClassId == 0xF3 || (pNode->nTypeFlags & 0x800) && pNode->nBossHcIdx == 6)
    {
        if (pNode->nCmdParam1 || pNode->nCmdParam2)
        {
            D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 10, 0);
            if (pAiCmd)
            {
                pAiCmd->nCmdParam[1] = pNode->nCmdParam1;
                pAiCmd->nCmdParam[2] = pNode->nCmdParam2;
            }
        }
    }

    int nUnitType = 6;
    if (pUnit)
    {
        nUnitType = pUnit->dwUnitType;
    }
    if (nUnitType == 1)
    {
        const int nBaseId = MONSTERS_GetBaseIdInl(pUnit->dwClassId);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            if (nBaseId == MONSTER_SANDMAGGOT1)
            {
                AIGENERAL_SetAiControlParam(pUnit, 3, pNode->nCmdParam1);
            }
            else if (nBaseId == MONSTER_BAALTHRONE)
            {
                AIGENERAL_SetAiControlParam(pUnit, 1, pNode->nCmdParam1);
            }
        }
    }

    if (nClassId == 0x138)
    {
        const unsigned char nValue = (unsigned char)pNode->nCmdParam1;
        MONSTERS_SetComponentInl(pUnit, 10, nValue);
        MONSTERS_SetComponentInl(pUnit, 11, nValue);
    }
    else if (nClassId == 0x137)
    {
        const unsigned char nValue = (unsigned char)pNode->nCmdParam1;
        MONSTERS_SetComponentInl(pUnit, 10, nValue);
    }

    if (pNode->nCmdParam1 == gnInactiveCmdParam1)
    {
        if (pNode->nCmdParam2 & gnInactiveNoXpParam2)
        {
            pUnit->dwFlags |= 0x04000000;
        }

        if (pNode->nCmdParam2 & gnInactiveNoTcParam2)
        {
            pUnit->dwFlags |= 0x00020000;
        }
    }
}

// 0x00541FE0
static void __stdcall SUNITINACTIVE_SaveSpecialMonsterParameters(D2GameStrc* pGame, D2InactiveMonsterNodeStrc* pNode, D2UnitStrc* pUnit)
{
    const int nClassId = pUnit->dwClassId;
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInl(nClassId);

    if (UNIT_HasFlag(pUnit, 0x04000000))
    {
        pNode->nCmdParam1 = gnInactiveCmdParam1;
        pNode->nCmdParam2 |= gnInactiveNoXpParam2;
    }

    if (UNIT_HasFlag(pUnit, 0x00020000))
    {
        pNode->nCmdParam1 = gnInactiveCmdParam1;
        pNode->nCmdParam2 |= gnInactiveNoTcParam2;
    }

    if (BITARRAY_CHECK(pMonStatsTxtRecord->nMonStatsFlags, 9)
        || BITARRAY_CHECK(pMonStatsTxtRecord->nMonStatsFlags, 8)
        || BITARRAY_CHECK(pMonStatsTxtRecord->nMonStatsFlags, 10))
    {
        D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 10, 0);
        if (pAiCmd && pAiCmd->nCmdParam[1])
        {
            pNode->nCmdParam1 = pAiCmd->nCmdParam[1];
            pNode->nCmdParam2 = pAiCmd->nCmdParam[2];
        }

        D2MapAIStrc* pMapAI = AIGENERAL_GetMapAiFromUnit(pUnit);
        if (pMapAI->nPathNodes)
        {
            DRLGPRESET_ChangeMapAI((D2MapAIStrc**)pMapAI, (D2MapAIStrc*)&pNode->pMapAI);
        }
    }

    if (nClassId == 0x10B || nClassId == 0xF3 || (pNode->nTypeFlags & 0x800) && pNode->nBossHcIdx == 6)
    {
        D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 10, 0);
        if (pAiCmd)
        {
            pNode->nCmdParam1 = pAiCmd->nCmdParam[1];
            pNode->nCmdParam2 = pAiCmd->nCmdParam[2];
        }
    }

    if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        const int nBaseId = MONSTERS_GetBaseIdInl(pUnit->dwClassId);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            if (nBaseId == MONSTER_SANDMAGGOT1)
            {
                pNode->nCmdParam1 = AIGENERAL_GetAiControlParam(pUnit, 3);
            }
            else if (nBaseId == MONSTER_BAALTHRONE)
            {
                pNode->nCmdParam1 = AIGENERAL_GetAiControlParam(pUnit, 1);
            }
        }
    }

    if (nClassId == 0x138)
    {
        pNode->nCmdParam1 = MONSTERS_GetComponent10Inl(pUnit);
    }
    else if (nClassId == 0x137)
    {
        pNode->nCmdParam1 = MONSTERS_GetComponent10Inl(pUnit);
    }
}

#pragma function(memset)

// 0x005421A0
static void __stdcall SUNITINACTIVE_CompressInactiveMonster(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pUnit || !pRoom)
    {
        return;
    }

    for (int i = 0; i < sgptDataTables->nCurseStates; ++i)
    {
        const int nState = sgptDataTables->pCurseStates[i];
        if (STATES_CheckState(pUnit, nState))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
            if (pStatList)
            {
                D2Common_10474(pUnit, pStatList);
                STATLIST_FreeStatList(pStatList);
            }
        }
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);

    D2InactiveMonsterNodeStrc* pNode = (D2InactiveMonsterNodeStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2InactiveMonsterNodeStrc), ".\\UNIT\\SUnitInactive.cpp", 0x528, 0);
    memset(pNode, 0, sizeof(D2InactiveMonsterNodeStrc));

    pNode->nOwnerId = -1;
    pNode->nX = CLIENTS_GetUnitXInl(pUnit);
    pNode->nY = CLIENTS_GetUnitYInl(pUnit);
    pNode->nClassId = pUnit->dwClassId;
    pNode->nGameFrame = pGame->dwGameFrame;
    pNode->nAiSpecialState = AITHINK_GetSpecialStateFromAiControl(AIGENERAL_GetAiControlFromUnitInl(pUnit));
    pNode->nNameSeed = MONSTERUNIQUE_GetNameSeed(pUnit);
    SUNITINACTIVE_SaveSpecialMonsterParameters(pGame, pNode, pUnit);

    if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 4))
    {
        pNode->nTypeFlags |= 2;
    }

    if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 2))
    {
        pNode->nTypeFlags |= 0x800;
        pNode->nBossHcIdx = MONSTERUNIQUE_GetBossHcIdx(pUnit);
    }

    if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 1))
    {
        pNode->nTypeFlags |= 1;
        QUESTS_SetGoldenBirdSpawn(pGame, pUnit);
    }

    if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 0x10))
    {
        pNode->nTypeFlags |= 0x20;
    }

    if (MONSTER_CheckSummonerFlag(pUnit, 2))
    {
        pNode->nTypeFlags |= 0x40;
    }

    const int nAlignment = STATLIST_GetUnitAlignment(pUnit);
    if (nAlignment == 2)
    {
        pNode->nTypeFlags |= 0x100;
    }
    else if (nAlignment == 0)
    {
        pNode->nTypeFlags |= 0x200;
    }
    else if (nAlignment == 1)
    {
        pNode->nTypeFlags |= 0x80;
    }

    D2_ASSERT(pUnit->dwNodeIndex >= 8, 0x56A);

    if (pUnit->dwNodeIndex != 11)
    {
        pNode->nTypeFlags |= 0x400;
    }

    pNode->nExperience = STATLIST_UnitGetStatValue(pUnit, STAT_EXPERIENCE, 0);
    pNode->nMaxHitpoints = STATLIST_GetMaxLifeFromUnit(pUnit);
    pNode->nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    pNode->nLevelId = MONSTER_GetLevelId(pUnit);

    const unsigned char* pMonUMods = MONSTERUNIQUE_GetUMods(pUnit);
    if (pMonUMods)
    {
        for (int i = 0; i < 9; ++i)
        {
            pNode->nMonUMods[i] = pMonUMods[i];
        }
    }

    if (pUnit->dwAnimMode == 12 || pUnit->dwAnimMode == 0)
    {
        pNode->nTypeFlags |= 4;
    }

    D2MinionListStrc* pMinionList;
    int nOwnerGUID;
    int nOwnerType;
    int nFlag1;
    int nFlag2;
    AIGENERAL_GetAiControlInfo(pUnit, &nOwnerGUID, &nOwnerType, &nFlag1, &nFlag2, &pMinionList);

    if (nOwnerGUID != -1 && nOwnerType == 1)
    {
        pNode->nOwnerId = nOwnerGUID;
        pNode->pMinionList = pMinionList;

        if (nFlag1)
        {
            pNode->nTypeFlags |= 8;
        }

        if (nFlag2)
        {
            pNode->nTypeFlags |= 0x10;
        }
    }

    pNode->nUnitId = pUnit->dwUnitId;
    pNode->nUnitFlags = pUnit->dwFlags;
    pNode->nUnitFlagsEx = pUnit->dwFlagEx;

    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    const int nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2InactiveUnitListStrc* pList = SUNITINACTIVE_GetListNodeFromActAndCoordinates(pGame, nAct, tCoords.nSubtileX, tCoords.nSubtileY, 1);
    pNode->pNext = pList->pInactiveMonsters;
    pList->pInactiveMonsters = pNode;
}

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnitInline(D2UnitStrc* unit)
{
    if (unit && unit->dwUnitType == UNIT_MONSTER && unit->pMonsterData) return unit->pMonsterData->pAiControl;
    return 0;
}

// 0x005424F0
static void __stdcall SUNITINACTIVE_RestoreInactiveMonsters(D2GameStrc* pGame,D2ActiveRoomStrc* pRoom)
{
    D2DrlgCoordsStrc coords;
    DUNGEON_GetRoomCoordinates(pRoom,&coords);
    const int act = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2InactiveUnitListStrc* list = SUNITINACTIVE_GetListNodeFromActAndCoordinates(pGame,act,coords.nSubtileX,coords.nSubtileY,0);
    if (!list) return;
    D2InactiveMonsterNodeStrc* next = list->pInactiveMonsters;
    int chaos = 0;
    if (DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_CHAOSSANCTUM && ACT4Q2_IsChaosSanctumCleared(pGame)) chaos = 1;
    while (next)
    {
        D2InactiveMonsterNodeStrc* node = next;
        next = ((D2InactiveMonsterNodeStrc*)node)->pNext;
        const int id = node->nClassId;
        const int x = node->nX;
        const int y = ((D2InactiveMonsterNodeStrc*)node)->nY;
        int mode = 1;
        int typeFlags = node->nTypeFlags;
        if (typeFlags & 4) mode = 12;
        else if (chaos && id != 243) goto cleanup;
        {
            D2UnitStrc* unit = 0;
            if (node->nUnitFlagsEx & 0x100)
            {
                unit = SUNIT_GetServerUnit(pGame,1,node->nUnitId);
                if (unit) SUNIT_Restore(pGame,unit,pRoom,x,y);
                AIGENERAL_FreeAllMinionLists(pGame,node->pMinionList);
                goto cleanup;
            }
            int flags = 0x62;
            if (typeFlags & 0x40) flags = 0x6A;
            if ((typeFlags & 0x400) && ((typeFlags & 0x100) || (typeFlags & 0x80))) goto cleanup;
            if (BITARRAY_CHECK(DATATBLS_GetMonStatsTxtRecordInl(id)->nMonStatsFlags,14)) flags |= 0x80;
            int type = 0;
            if (typeFlags & 1) type = 1;
            if (typeFlags & 0x20) type = 2;
            switch (type)
            {
            case 2:
                unit = MONSTERUNIQUE_RestoreMinion(pGame,pRoom,x,y,id,node->nUnitId,node->nMonUMods);
                break;
            case 1:
                unit = MONSTERUNIQUE_RestoreUniqueMonster(pGame,pRoom,x,y,id,node->nUnitId,node->nNameSeed,node->nTypeFlags & 2,node->nTypeFlags & 0x800,node->nBossHcIdx,node->nMonUMods);
                break;
            case 0:
                unit = MONSTERSPAWN_SpawnWithUnitId(pGame,pRoom,x,y,id,mode,node->nUnitId,-1,flags);
                if (!unit)
                {
                    unit = MONSTERSPAWN_SpawnWithUnitId(pGame,pRoom,x,y,id,mode,node->nUnitId,5,flags);
                    if (!unit)
                    {
                        int sx,sy;
                        if (!MONSTERREGION_FindSpawnLocation(pGame,pRoom,0,id,&sx,&sy,0)) goto fallbackLocation;
                        unit = MONSTERSPAWN_SpawnWithUnitId(pGame,pRoom,sx,sy,id,mode,node->nUnitId,-1,flags);
                        if (!unit)
                        {
fallbackLocation:
                            D2CoordStrc alternate;
                            alternate.nX = x;
                            alternate.nY = y;
                            D2ActiveRoomStrc* otherRoom;
                            D2Common_10136(pRoom,&alternate,1,0x3C01,&otherRoom);
                            if (otherRoom) unit = MONSTERSPAWN_SpawnWithUnitId(pGame,otherRoom,alternate.nX,alternate.nY,id,mode,node->nUnitId,-1,flags);
                        }
                    }
                }
                break;
            }
            int alignment = 0;
            if (node->nTypeFlags & 0x100) alignment = 2;
            if (node->nTypeFlags & 0x80) alignment = 1;
            if (unit)
            {
                AIGENERAL_SetAiControlInfo(pGame,unit,node->nOwnerId,1,node->nTypeFlags & 8,node->nTypeFlags & 0x10,node->pMinionList);
                STATLIST_SetUnitStat(unit,STAT_EXPERIENCE,node->nExperience,0);
                if ((unsigned int)(pGame->dwGameFrame - node->nGameFrame) >= 7500)
                {
                    STATLIST_SetUnitStat(unit,STAT_MAXHP,node->nMaxHitpoints,0);
                    STATLIST_SetUnitStat(unit,STAT_HITPOINTS,node->nMaxHitpoints,0);
                }
                else
                {
                    STATLIST_SetUnitStat(unit,STAT_MAXHP,node->nMaxHitpoints,0);
                    STATLIST_SetUnitStat(unit,STAT_HITPOINTS,node->nHitpoints,0);
                }
                AITHINK_ExecuteAiFn(pGame,unit,AIGENERAL_GetAiControlFromUnitInline(unit),node->nAiSpecialState);
                SUNITINACTIVE_RestoreSpecialMonsterParameters(pGame,node,unit);
                if (node->nTypeFlags & 0x400)
                {
                    if (alignment == 2) TARGETS_InsertUnitNode(pGame,unit,0,8);
                    else { D2_ASSERT(alignment == 1,0x691); TARGETS_InsertUnitNode(pGame,unit,0,9); }
                }
                unsigned char* saved = node->nMonUMods;
                unsigned char* mods = MONSTERUNIQUE_GetUMods(unit);
                if (mods)
                {
                    int n = 9;
                    do
                    {
                        if (*mods != *saved) D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame,unit,*saved,0);
                        ++saved;
                        ++mods;
                        --n;
                    } while (n);
                }
                SUNIT_SetAlignment(unit,alignment,1);
                if (node->nUnitFlagsEx & 0x200) unit->dwFlagEx |= 0x200;
                unit->dwFlags |= (node->nUnitFlags & 0x20000) | 0x3000000;
            }
            else AIGENERAL_FreeAllMinionLists(pGame,node->pMinionList);
            const int levelId = node->nLevelId;
            const int currentLevel = DUNGEON_GetLevelIdFromRoom(pRoom);
            MONSTERREGION_AdjustCountsForInactiveMonster(pGame->pMonReg,levelId,currentLevel,alignment,mode == 12,node->nTypeFlags & 0x40,unit);
        }
cleanup:
        if (node->pMapAI) DRLGPRESET_FreeMapAI(pGame->pMemoryPool,node->pMapAI);
        FOG_FreeServerMemory(pGame->pMemoryPool,node,gszSUnitInactiveSourceFile,0x8C,0);
    }
}

// 0x005429B0
int __fastcall SUNITINACTIVE_IsDeadMonsterAt(D2GameStrc* ptGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nClassId)
{
    D2_ASSERT(ptGame, 0x6DA);
    D2_ASSERT(pRoom, 0x6DB);
    D2_ASSERT(nX && nY, 0x6DC);

    D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    const int nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    if (!pTargetRoom)
    {
        pTargetRoom = DUNGEON_FindRoomBySubtileCoordinates(ptGame->pAct[nAct], nX, nY);
    }

    if (pTargetRoom)
    {
        for (D2UnitStrc* pUnit = pTargetRoom->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
        {
            if ((!pUnit ? 6 : pUnit->dwUnitType) == 1 && pUnit->dwClassId == nClassId && SUNIT_IsDead(pUnit))
            {
                return 1;
            }
        }
    }

    D2InactiveUnitListStrc* pList = SUNITINACTIVE_GetListNodeFromActAndCoordinates(ptGame, nAct, nX, nY, 0);
    if (pList)
    {
        for (D2InactiveMonsterNodeStrc* pNode = pList->pInactiveMonsters; pNode; pNode = pNode->pNext)
        {
            if (pNode->nClassId == nClassId && (pNode->nTypeFlags & 4))
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x00542AC0
void __fastcall SUNITINACTIVE_DeleteExpiredItemNodes(D2GameStrc* pGame, int nAct)
{
    for (D2InactiveUnitListStrc* i = pGame->pInactiveUnitList[nAct]; i; i = i->pNext)
    {
        D2InactiveItemNodeStrc* pPrevious = 0;
        D2InactiveItemNodeStrc* pCurrent = i->pInactiveItems;
        while (pCurrent)
        {
            D2InactiveItemNodeStrc* pNext = pCurrent->pNext;
            if (pCurrent->nFrame && pGame->dwGameFrame > pCurrent->nFrame)
            {
                if (pPrevious)
                    pPrevious->pNext = pNext;
                else
                    i->pInactiveItems = pNext;
                FOG_FreeServerMemory(pGame->pMemoryPool, pCurrent, ".\\UNIT\\SUnitInactive.cpp", 0x723, 0);
            }
            else
            {
                pPrevious = pCurrent;
            }
            pCurrent = pNext;
        }
    }
}

void __fastcall sub_EMIT_00542871(D2GameStrc* pGame, D2UnitStrc* pUnit, D2InactiveMonsterNodeStrc* pNode)
{
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, pNode->nHitpoints, 0);
    SUNITINACTIVE_RestoreSpecialMonsterParameters(pGame, pNode, pUnit);
    if (pNode->nTypeFlags & 0x400)
    {
        STATLIST_SetUnitStat(pUnit, STAT_MANA, 0, 0);
    }
}

// 0x00542B40
void __fastcall SUNITINACTIVE_RestoreInactiveUnits(D2GameStrc* pGame,D2ActiveRoomStrc* pRoom)
{
    SUNITINACTIVE_RestoreInactiveMonsters(pGame,pRoom);
    D2InactiveUnitNodeStrc* next = 0;
    D2InactiveItemNodeStrc* items = 0;
    SUNITINACTIVE_TakeInactiveListNode(&next,&items,pGame,pRoom);
    SUNITINACTIVE_RestoreInactiveItems(pRoom,pGame,items);
    while (next)
    {
        D2InactiveUnitNodeStrc* node = next;
        next = node->pNext;
        const int mode = node->nMode;
        const int type = node->nUnitType;
        D2UnitStrc* unit = 0;
        if (node->nUnitFlagsEx & 0x100)
        {
            unit = SUNIT_GetServerUnit(pGame,type,node->nUnitId);
            if (unit)
            {
                SUNIT_Restore(pGame,unit,pRoom,node->nX,node->nY);
                unit->dwFlags |= 0x10;
                switch (type)
                {
                case 0:
                    D2_ASSERT(node->nMode == 17,0x156);
                    UNITS_ChangeAnimMode(unit,17);
                    break;
                case 2:
                    unit->pObjectData->InteractType = node->nInteractType;
                    break;
                }
            }
            FOG_FreeServerMemory(pGame->pMemoryPool,node,".\\UNIT\\SUnitInactive.cpp",0x15C,0);
        }
        else
        {
            if (type != 1) unit = SUNIT_CreatePresetUnit(pGame,pRoom,type,node->nClassId,node->nX,node->nY,mode,node->nUnitFlags);
            switch (type)
            {
            case 2:
            {
                D2_ASSERT(unit,0x170);
                D2ObjectsTxt* obj = DATATBLS_GetObjectsTxtRecord(unit->dwClassId);
                if (UNITS_IsShrine(unit) && node->nGameFrame)
                {
                    int frame = (unsigned short)node->nFrame | ((unsigned short)node->nUnitId << 16);
                    if (frame > 0)
                    {
                        if (frame <= pGame->dwGameFrame) frame = pGame->dwGameFrame + 1;
                        EVENT_SetEvent(pGame,unit,5,frame,0,0);
                    }
                    unit->pObjectData->InteractType = node->nInteractType;
                    UNITS_SetShrineTxtRecordInObjectData(unit,DATATBLS_GetShrinesTxtRecord(node->nInteractType));
                }
                else if (obj->nSubClass & 0x20)
                {
                    const unsigned char maximum = OBJECTS_GetRegenerateMax(obj);
                    unsigned char charges;
                    if (node->nInteractType < maximum)
                    {
                        const int period = obj->dwParm[0];
                        D2_ASSERT(period,0x18B);
                        if (node->nGameFrame < pGame->dwGameFrame + period)
                        {
                            int steps = (pGame->dwGameFrame - node->nGameFrame) / period;
                            if (steps >= 1) steps = 1;
                            charges = (unsigned char)(steps + node->nInteractType);
                            if (charges > maximum) charges = maximum;
                            unit->dwAnimMode = OBJECTS_GetRegenerateSteps() - charges / obj->dwParm[2];
                            if ((unsigned int)unit->dwAnimMode > 2)
                            {
                                unit->dwAnimMode = 0;
                                unit->pObjectData->InteractType = maximum;
                                goto objectDone;
                            }
                        }
                        else charges = node->nInteractType;
                        unit->pObjectData->InteractType = charges;
                        if (charges < maximum && maximum - charges > 0)
                        {
                            int offset = period;
                            int remaining = maximum - charges;
                            do
                            {
                                EVENT_SetEvent(pGame,unit,2,offset + pGame->dwGameFrame,0,0);
                                offset += period;
                                --remaining;
                            } while (remaining);
                        }
                    }
                }
                else
                {
                    unit->pObjectData->InteractType = node->nInteractType;
                    unit->bSparkChest = (unsigned char)node->nFrame;
                    if (node->nDropItemCode) unit->dwDropItemCode = node->nDropItemCode;
                }
                break;
            }
            }
objectDone:
            FOG_FreeServerMemory(pGame->pMemoryPool,node,".\\UNIT\\SUnitInactive.cpp",0x1C3,0);
        }
    }
}

// 0x00542E10
static void __stdcall SUNITINACTIVE_CompressInactiveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        SUNITINACTIVE_CompressInactiveMonster(pGame, pUnit);
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    int nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);

    D2GameStrc* pListGame = pGame;
    D2InactiveUnitListStrc* pList = pListGame->pInactiveUnitList[nAct];
    D2InactiveUnitListStrc* pPrevious = 0;
    while (pList)
    {
        if (tCoords.nSubtileX == pList->nX && tCoords.nSubtileY == pList->nY)
        {
            break;
        }

        if (tCoords.nSubtileX > pList->nX)
        {
            break;
        }

        pPrevious = pList;
        pList = pList->pNext;
    }

    if (!pList || tCoords.nSubtileX > pList->nX)
    {
        D2InactiveUnitListStrc* pNew = (D2InactiveUnitListStrc*)sub_0040B430(pListGame->pMemoryPool, sizeof(D2InactiveUnitListStrc), ".\\UNIT\\SUnitInactive.cpp", 0x22E, 0);
        *pNew = D2InactiveUnitListStrc();
        pNew->nX = tCoords.nSubtileX;
        pNew->nY = tCoords.nSubtileY;
        pNew->pNext = pList;
        if (pPrevious)
        {
            pPrevious->pNext = pNew;
        }
        else
        {
            pGame->pInactiveUnitList[nAct] = pNew;
        }
        pList = pNew;
        pListGame = pGame;
    }

    const int nUnitType = pUnit->dwUnitType;
    if (nUnitType == 4)
    {
        SUNITINACTIVE_CompressInactiveItem(pList, pListGame, 0, pUnit);
        return;
    }

    D2InactiveUnitNodeStrc* pNode = (D2InactiveUnitNodeStrc*)sub_0040B430(pListGame->pMemoryPool, sizeof(D2InactiveUnitNodeStrc), ".\\UNIT\\SUnitInactive.cpp", 0x244, 0);
    sub_00681EF0_memset(pNode, 0, sizeof(D2InactiveUnitNodeStrc));
    pNode->nX = CLIENTS_GetUnitXInl(pUnit);
    pNode->nY = CLIENTS_GetUnitYInl(pUnit);
    pNode->nUnitType = nUnitType;
    pNode->nClassId = pUnit->dwClassId;

    switch (nUnitType)
    {
    case 0:
        pNode->nUnitId = pUnit->dwUnitId;
        pNode->nMode = pUnit->dwAnimMode;
        break;

    case 2:
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pUnit->dwClassId);
        if (pUnit->dwAnimMode == 1 && !pObjectsTxtRecord->nCycleAnim[1] && pObjectsTxtRecord->nMode[2])
        {
            pUnit->dwAnimMode = 2;
        }

        pNode->nMode = pUnit->dwAnimMode;

        if (sub_00621B00_IsShrine(pUnit))
        {
            pNode->nUnitId = (unsigned int)EVENT_GetEventFrame(pGame, pUnit, 5) >> 16;
            pNode->nFrame = (unsigned short)EVENT_GetEventFrame(pGame, pUnit, 5);
        }
        else
        {
            const int nClassId = pUnit->dwClassId;
            if (nClassId == 0x3B || nClassId == 0x3C || nClassId == 0x64)
            {
                pNode->nUnitId = pUnit->dwUnitId;
            }
            else
            {
                pNode->nFrame = pUnit->bSparkChest;
            }
        }

        pNode->nDropItemCode = pUnit->dwDropItemCode;
        pNode->nInteractType = pUnit->pObjectData->InteractType;
        break;
    }

    default:
        pNode->nMode = pUnit->dwAnimMode;
        break;
    }

    pNode->nGameFrame = pGame->dwGameFrame;
    pNode->nUnitFlags = pUnit->dwFlags;
    pNode->nUnitFlagsEx = pUnit->dwFlagEx;
    pNode->pNext = pList->pInactiveUnits;
    pList->pInactiveUnits = pNode;
}

// 0x00543080
void __fastcall SUNITINACTIVE_FreeInactiveUnitLists(D2GameStrc* pGame)
{
    for (int i = 0; i < 5; ++i)
    {
        D2InactiveUnitListStrc* pNextList = pGame->pInactiveUnitList[i];
        while (pNextList)
        {
            D2InactiveUnitListStrc* pCurrentList = pNextList;
            pNextList = pCurrentList->pNext;
            D2InactiveUnitNodeStrc* pNextUnit = pCurrentList->pInactiveUnits;
            while (pNextUnit)
            {
                D2InactiveUnitNodeStrc* pUnit = pNextUnit;
                pNextUnit = pNextUnit->pNext;
                FOG_FreeServerMemory(pGame->pMemoryPool, pUnit, ".\\UNIT\\SUnitInactive.cpp", 666, 0);
            }
            D2InactiveItemNodeStrc* pItem = pCurrentList->pInactiveItems;
            while (pItem)
            {
                D2InactiveItemNodeStrc* pNextItem = pItem->pNext;
                FOG_FreeServerMemory(pGame->pMemoryPool, pItem, ".\\UNIT\\SUnitInactive.cpp", 676, 0);
                pItem = pNextItem;
            }
            SUNITINACTIVE_FreeInactiveMonsters(pGame, pCurrentList);
            FOG_FreeServerMemory(pGame->pMemoryPool, pCurrentList, ".\\UNIT\\SUnitInactive.cpp", 683, 0);
        }
    }
}

inline unsigned __int64 SEED_RollRandomNumberInl(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

inline D2MonStats2Txt* DATATBLS_GetMonStats2TxtRecordFromMonsterIdInl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nMonStats2Id = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStats2Id >= 0 && nMonStats2Id < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStats2Id];
        }
    }
    return 0;
}

// 0x00543140
void __fastcall SUNITINACTIVE_DeleteSingleListNode(D2GameStrc* pGame, unsigned short nUnitType, unsigned short nClassId, unsigned char nAct)
{
    if (nUnitType == UNIT_MONSTER)
    {
        SUNITINACTIVE_DeleteInactiveMonsterNode(pGame, nClassId, nAct);
        return;
    }
    D2InactiveUnitListStrc* pInactiveUnitList = pGame->pInactiveUnitList[nAct];
    while (pInactiveUnitList)
    {
        D2InactiveUnitNodeStrc* pInactiveUnitNode = pInactiveUnitList->pInactiveUnits;
        D2InactiveUnitNodeStrc* pPreviousUnitNode = 0;
        while (pInactiveUnitNode)
        {
            if (pInactiveUnitNode->nUnitType == nUnitType && pInactiveUnitNode->nClassId == nClassId)
            {
                if (pInactiveUnitNode == pInactiveUnitList->pInactiveUnits)
                {
                    pInactiveUnitList->pInactiveUnits = pInactiveUnitNode->pNext;
                }
                else
                {
                    pPreviousUnitNode->pNext = pInactiveUnitNode->pNext;
                }
                FOG_FreeServerMemory(pGame->pMemoryPool, pInactiveUnitNode, ".\\UNIT\\SUnitInactive.cpp", 804, 0);
                return;
            }
            pPreviousUnitNode = pInactiveUnitNode;
            pInactiveUnitNode = pInactiveUnitNode->pNext;
        }
        pInactiveUnitList = pInactiveUnitList->pNext;
    }
}

// 0x005431F0
static void __stdcall SUNITINACTIVE_CompressMonsterIfNeeded(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const int nAnimMode = pUnit->dwAnimMode;
    int bIsDead = 0;
    if (SUNIT_IsDead(pUnit))
    {
        bIsDead = 1;
    }

    int bCompress = 0;
    int bUnk = 0;
    if (DRLG_GetSaveMonstersFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)))
    {
        bCompress = 1;
    }

    if (pUnit->dwFlags & 0x02000000)
    {
        bCompress = 1;
    }

    if (nAnimMode == 0x0C)
    {
        D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
        if ((unsigned int)SEED_RollRandomNumberInl(pSeed) % 3)
        {
            bCompress = 0;
        }
    }

    if (bIsDead)
    {
        if (STATES_CheckStateMaskUdeadOnUnit(pUnit))
        {
            bCompress = 0;
        }

        if (STATLIST_GetUnitAlignment(pUnit) == 2)
        {
            bCompress = 0;
        }
    }

    if (pUnit->dwNodeIndex < 8)
    {
        if (!bIsDead)
        {
            bCompress = 1;
            SUNIT_SetAlignment(pUnit, 0, 1);
            TARGETS_RemoveUnitNode(pGame, pUnit);
        }
        else
        {
            bCompress = 0;
        }
    }

    if (bIsDead && (pUnit->dwClassId == 0x16B || pUnit->dwClassId == 0x16C))
    {
        bCompress = 0;
    }

    if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 0x18) && bIsDead)
    {
        bCompress = 0;
    }

    if (UNIT_HasFlag(pUnit, 0x80000000))
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
        {
            bUnk = PLAYERPETS_HandlePetDeactivation(pGame, pOwner, pUnit);
        }
        bCompress = 0;
    }

    if (UNIT_HasFlag(pUnit, 0x00000200))
    {
        bCompress = 0;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = DATATBLS_GetMonStats2TxtRecordFromMonsterIdInl(pUnit->dwClassId);
    if (pMonStats2TxtRecord && pMonStats2TxtRecord->nRestore)
    {
        if (pMonStats2TxtRecord->nRestore == 2)
        {
            bCompress = 1;
        }
    }
    else
    {
        bCompress = 0;
    }

    if (bUnk)
    {
        pUnit->dwFlagEx |= 0x100;
        if (bCompress)
        {
            SUNITINACTIVE_CompressInactiveUnit(pGame, pUnit);
        }
        UNITROOM_UpdatePath(pUnit);
    }
    else
    {
        if (bCompress)
        {
            SUNITINACTIVE_CompressInactiveUnit(pGame, pUnit);
        }
        SUNIT_RemoveUnit(pGame, pUnit);
    }
}

// 0x005433F0
void __fastcall SUNITINACTIVE_CompressUnitIfNeeded(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const int nUnitType = pUnit->dwUnitType;
    const int nClassId = pUnit->dwClassId;
    int bCompress = 0;

    if (nUnitType == 1)
    {
        SUNITINACTIVE_CompressMonsterIfNeeded(pGame, pUnit);
        return;
    }

    if (DRLG_GetSaveMonstersFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) || pUnit->dwFlags & 0x02000000)
    {
        bCompress = 1;
    }

    switch (nUnitType)
    {
    case 2:
    {
        if (nClassId == 0x3B || nClassId == 0x3C)
        {
            goto special;
        }

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
        if (!pObjectsTxtRecord->nRestore || D2GAME_CheckIfSparklyChest_6FCBD7F0(pUnit) & 2)
        {
            bCompress = 0;
        }

        if (pObjectsTxtRecord->nRestoreVirgins && pUnit->dwAnimMode)
        {
            bCompress = 0;
        }

        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 1, 0);
    }
    check:
        if (!bCompress)
        {
            break;
        }

    case 4:
    case 5:
        SUNITINACTIVE_CompressInactiveUnit(pGame, pUnit);
        break;

    case 0:
        if (STATES_CheckState(pUnit, STATE_PLAYERBODY))
        {
        special:
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 1, 0);
            pUnit->dwFlagEx |= 0x100;
            SUNITINACTIVE_CompressInactiveUnit(pGame, pUnit);
            UNITROOM_UpdatePath(pUnit);
            return;
        }
        goto check;
    }

    if (nUnitType != 4)
    {
        SUNIT_RemoveUnit(pGame, pUnit);
    }
}

#include "gen/data/Source/D2Game/UNIT/SUnitInactive.inc"
