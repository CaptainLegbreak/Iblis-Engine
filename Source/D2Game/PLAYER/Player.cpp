#include "D2ItemTypes.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2LevelTxt.h"
#include "D2UnitData.h"
#include "D2PlayerModes.h"
#include "D2StateIds.h"
#include "D2GameCallbackArgs.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x0073110C

#define UNIT_PLAYER 0

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

#define ITEMQUAL_NORMAL 2

#define UNIT_MONSTER 1

#define UNIT_INVALID 6

struct D2CorpseStrc;

struct D2ItemsTxt;

struct D2PlayerDataStrc;

struct D2StaticPathStrc;

struct D2CharStatsTxt;

struct D2CharItemStrc;

struct D2GameStrc;

struct D2UnitStrc;

struct D2CoordStrc;

struct D2DataTablesStrc;



void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

void __fastcall PLRINTRO_Destroy(D2GameStrc* pGame, D2PlrIntroStrc* pPlayerIntro); // 0x00572620

D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc* pInventory); // 0x0063D570

int __stdcall INVENTORY_GetUnitGUIDFromCorpse(D2CorpseStrc* pCorpse); // 0x0063D630

D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc* pCorpse); // 0x0063D610

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

void __fastcall PLAYERPETS_FreePetsFromPlayerData(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005746D0

void __fastcall PARTY_LeaveParty(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005407A0

void __fastcall PLAYERLIST_FreePlayerLists(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x0055B790

void __fastcall SUNITDMG_FreeAttackerCombatList(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0057C980

void __fastcall SUNIT_RemoveAllItemsFromInventory(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555AE0

void __fastcall ARENA_FreeArenaUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x0053F580

void __fastcall PLAYER_FreePlayerDataExtras(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00534880

void __fastcall EVENT_FreeUnitTimers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540EE0

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int a8, int a9, D2InventoryStrc* pInventory); // 0x00560200

int __fastcall ITEMMODE_EquipCursorItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int a5, int* pUnused); // 0x005606B0

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40

int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int a2); // 0x00558200

D2UnitStrc* __fastcall D2GAME_CreateItemUnit_6FC501A0(D2UnitStrc* pPlayer, int nItemId, D2GameStrc* pGame, int nSpawnTarget, int nQuality, int bNoSockets, int bNoEthereal, int nItemLevel, int bUseSeed, int dwSeed, int dwItemSeed); // 0x00559CE0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x006257D0

void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0

void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150

unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0

int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc); // 0x00627D70

int __fastcall ITEMMODE_PlaceCursorItemInBelt(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nBeltSlot, int bFindFreeSlot, int* a6); // 0x0055E9B0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID); // 0x00554100

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

void __fastcall SCMD_SendInteractionTarget(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitId, int a5); // 0x0053D6D0

void __fastcall D2GAME_NPC_ResetInteract_6FCCB4D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc); // 0x00579130

void __fastcall OBJMODE_CloseObjectInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pObject); // 0x005854D0

void __fastcall PLRTRADE_CloseCubeInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00567330

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50

void __fastcall D2GAME_SetStatOrResetGold_6FC7CA70(D2UnitStrc* pUnit, int nStat, int nValue); // 0x00530EA0

void __fastcall ITEMS_DropGoldPiles(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nAmount, D2UnitStrc** ppGold, int* pCount, int nMaxCount); // 0x0055A090

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870

void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x00621CE0

D2UnitStrc* __fastcall SUNIT_GetPortalOwner(D2GameStrc* pGame, D2UnitStrc* pPortal); // 0x00553720

void __fastcall ACT5Q5_OnPortalClosed(D2GameStrc* pGame, D2UnitStrc* pPortal); // 0x0058CF50

void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bReset); // 0x0061AED0

#define STAT_LEVEL 12

#define STAT_GOLD 14

#define STAT_GOLDLOST 175

struct D2DifficultyLevelsTxt;

unsigned int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70

int __fastcall PLAYER_DropGold(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, int nValue); // 0x00535510

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30

unsigned int __stdcall DATATBLS_GetLevelThreshold(int nClass, unsigned int dwLevel); // 0x00611800

void __fastcall CLIENTS_SetExperienceLoss(D2ClientStrc* pClient, int nExpLoss); // 0x005391E0

static int __stdcall PLAYER_PlaceItemInInventory(D2GameStrc* pGame, int a8, D2UnitStrc* pItem, D2UnitStrc* pPlayer);

static int __stdcall PLAYER_EquipStartItem(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer);

static D2UnitStrc* __stdcall PLAYER_CreateStartItemStack(D2GameStrc* pGame, int nCount, int nItemId, D2UnitStrc* pPlayer, D2CharStatsTxt* pCharStatsTxt);

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer);     // 0x00627260

static void __stdcall PLAYER_ApplyDeathGoldLoss(D2GameStrc* pGame, D2UnitStrc* pKiller, D2UnitStrc* pPlayer);

void __fastcall PLAYER_Destroy(D2GameStrc* pGame, D2UnitStrc* pPlayer);

void __fastcall PLAYER_CreateStartItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2CharStatsTxt* pCharStatsTxt, int nCount, D2CharItemStrc* pCharItem);

int gnVirtualPlayerCount; // 0x00883D70

static void __stdcall PLAYER_ApplyDeathExperienceLoss(D2GameStrc* pGame, D2UnitStrc* pDefender);

void __fastcall PLAYER_ApplyDeathPenalty(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker);

extern "C" const char gszEmptyAssertText; // 0x006CC837

void __fastcall CLIENTS_SetSkillHotKey(D2ClientStrc* pClient, int nHotkeyId, short nSkillId, unsigned char nHand, int nItemGUID); // 0x005390A0

D2PlrIntroStrc* __fastcall PLRINTRO_Create(D2GameStrc* pGame); // 0x00572560

// 0x00534800
void __fastcall PLAYER_CreatePlayerIntros(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData)
    {
        for (int i = 0; i < 3; ++i)
        {
            pPlayerData->pPlayerIntro[i] = PLRINTRO_Create(pGame);
        }
        pPlayerData->dwBoughtItemId = 0;
    }
}

// 0x00534840
static void PLAYER_FreePartyLifeList(D2GameStrc* pGame, D2PlayerDataStrc* pPlayerData)
{
    D2LifeSyncStrc* pNode = pPlayerData->pPartyLifeList;
    while (pNode)
    {
        D2LifeSyncStrc* pNext = pNode->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, pNode, ".\\PLAYER\\Player.cpp", 43, 0);
        pNode = pNext;
    }
    pPlayerData->pPartyLifeList = 0;
}

// 0x00534880
void __fastcall PLAYER_FreePlayerDataExtras(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData)
    {
        PLAYER_FreePartyLifeList(pGame, pPlayerData);
        for (int i = 0; i < 3; ++i)
        {
            PLRINTRO_Destroy(pGame, pPlayerData->pPlayerIntro[i]);
            pPlayerData->pPlayerIntro[i] = 0;
        }
    }
}

void __fastcall SUNIT_InitClientInPlayerData(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00553180

#define UNITFLAG_TARGETABLE 0x02

#define UNITFLAG_CANBEATTACKED 0x04

#define UNITFLAG_ISVALIDTARGET 0x08

struct D2SkillListStrc;

typedef void (__fastcall* STATLIST_CallbackFn)(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOther, int nLayer_StatId, int nPreviousValue, int nNewValue);

void __fastcall PLAYER_CreatePlayerIntros(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00534800

void __fastcall ARENA_AllocArenaUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0053F530

void __fastcall D2GAME_DeleteTimersOnUnit_6FC34A30(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540F30

void __fastcall SUNIT_SetAlignment(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0

void __fastcall D2GAME_ITEMMODE_ServerStatlistCallback_6FC41910(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOther, int nLayer_StatId, int nPreviousValue, int nNewValue); // 0x0055B800

void __fastcall PLAYERPETS_AllocPetList(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00575AF0

void __stdcall UNITS_AllocPlayerData(D2UnitStrc* pUnit); // 0x00621F90

void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, STATLIST_CallbackFn pfCallback, D2GameStrc* pGame); // 0x00626D40

D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0

D2SkillListStrc* __stdcall SKILLS_AllocSkillList(void* pMemPool); // 0x006438B0

void __stdcall SKILLS_InitSkillList(D2UnitStrc* pUnit); // 0x00647EE0

// 0x005348C0
void __fastcall PLAYER_Create(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPlayerGUID)
{
    D2_ASSERT(pPlayer, 71);

    pPlayer->dwFlags |= UNITFLAG_ISVALIDTARGET | UNITFLAG_CANBEATTACKED | UNITFLAG_TARGETABLE;
    pPlayer->dwUnitId = nPlayerGUID;

    INVENTORY_AllocInventory(0, pPlayer);

    pPlayer->pSkills = SKILLS_AllocSkillList(pGame->pMemoryPool);
    SKILLS_InitSkillList(pPlayer);

    STATLIST_AllocStatListEx(pPlayer, 0, D2GAME_ITEMMODE_ServerStatlistCallback_6FC41910, pGame);
    UNITS_AllocPlayerData(pPlayer);
    PLAYER_CreatePlayerIntros(pGame, pPlayer);

    SUNIT_InitClientInPlayerData(pPlayer, 0);
    D2GAME_DeleteTimersOnUnit_6FC34A30(pGame, pPlayer);
    ARENA_AllocArenaUnit(pGame, pPlayer);
    PLAYERPETS_AllocPetList(pGame, pPlayer);
    SUNIT_SetAlignment(pPlayer, 2, 1);
}

// 0x00534970
static void PLAYER_RemoveCorpseUnits(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    for (D2CorpseStrc* pCorpse = INVENTORY_GetFirstCorpse(pPlayer->pInventory); pCorpse; pCorpse = INVENTORY_GetNextCorpse(pCorpse))
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, INVENTORY_GetUnitGUIDFromCorpse(pCorpse));
        if (pUnit)
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
            if (pRoom)
            {
                const int guid=(pUnit ? pUnit->dwUnitId : -1);
                DUNGEON_AllocDrlgDelete(pRoom, pUnit->dwUnitType, guid);
            }
            SUNIT_RemoveUnit(pGame, pUnit);
        }
    }
}

// 0x005349D0
void __fastcall PLAYER_Destroy(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    PLAYERPETS_FreePetsFromPlayerData(pGame, pPlayer);
    PARTY_LeaveParty(pGame, pPlayer);
    PLAYERLIST_FreePlayerLists(pGame, pPlayer);
    SUNITDMG_FreeAttackerCombatList(pGame, pPlayer);
    PLAYER_RemoveCorpseUnits(pGame, pPlayer);
    SUNIT_RemoveAllItemsFromInventory(pGame, pPlayer);
    INVENTORY_FreeInventory(pPlayer->pInventory);
    ARENA_FreeArenaUnit(pGame, pPlayer);
    PLAYER_FreePlayerDataExtras(pGame, pPlayer);
    UNITS_FreePlayerData(pGame->pMemoryPool, pPlayer);
    if (pPlayer->pHoverText)
    {
        CHAT_FreeHoverMsg(pGame->pMemoryPool, pPlayer->pHoverText);
    }
    EVENT_FreeUnitTimers(pGame, pPlayer);
}

D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit); // 0x00552DB0

// 0x00534A50
void __fastcall PLAYER_RemoveAllPlayers(D2GameStrc* pGame)
{
    for (int i = 0; i < 128; ++i)
    {
        D2UnitStrc* pPlayer = pGame->pUnitList[UNIT_PLAYER][i];
        while (pPlayer)
        {
            D2UnitStrc* pCurrent = pPlayer;
            pPlayer = SUNIT_GetNextUnitFromList(pPlayer);
            SUNIT_RemoveUnit(pGame, pCurrent);
        }
    }
}

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10

// 0x00534AB0
void __fastcall PLAYER_ClearTargetIfMatch(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (pTarget == SUNIT_GetTargetUnit(pGame, pUnit))
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
    }
}

#define EVENTTYPE_DELAYEDPORTAL 11

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

void __fastcall PLRMODE_ChangeModeToCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0

#define EVENTTYPE_STATREGEN 3

// 0x00534AD0
void __fastcall PLAYER_InitializePosition(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY)
{
    PLRMODE_ChangeModeToCoords(pGame, pUnit, 0, PLRMODE_NEUTRAL, nX, nY, 1);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_STATREGEN, pGame->dwGameFrame + 1, 0, 0);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_DELAYEDPORTAL, pGame->dwGameFrame + 250, 0, 0);
}

inline int M08_UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

// 0x00534B30
static int __stdcall PLAYER_PlaceItemInInventory(D2GameStrc* pGame, int a8, D2UnitStrc* hItem, D2UnitStrc* hPlayer)
{
    D2_ASSERT(hItem, 180);
    D2_ASSERT(hPlayer, 181);
    ITEMS_SetInvPage(hItem, INVPAGE_INVENTORY);
    const int nItemGUID = hItem->dwUnitId;
    return D2GAME_PlaceItem_6FC44410(".\\PLAYER\\Player.cpp", 186, pGame, hPlayer, nItemGUID, CLIENTS_GetUnitX(hItem), CLIENTS_GetUnitY(hItem), a8, 1, 0) != 0;
}

// 0x00534BB0
static int __stdcall PLAYER_EquipStartItem(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    D2_ASSERT(pItem, 198);
    D2_ASSERT(pPlayer, 199);
    const int nItemGUID = pItem->dwUnitId;
    int nUnused;
    return ITEMMODE_EquipCursorItem(pGame, pPlayer, nItemGUID, ITEMS_GetBodyLocation(pItem), 1, &nUnused) != 0;
}

static __forceinline int __stdcall sub_M08_PlaceStartItemInBelt(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, int bFindFreeSlot)
{
    D2_ASSERT(pItem, 216);
    D2_ASSERT(pPlayer, 217);
    int nUnused;
    const int nX = M08_UNITS_GetXPositionInline(pItem);
    const int nItemGUID = pItem->dwUnitId;
    return ITEMMODE_PlaceCursorItemInBelt(pGame, pPlayer, nItemGUID, nX, bFindFreeSlot, &nUnused) != 0;
}

// 0x00534C10
static int __stdcall PLAYER_PlaceStartItemInBelt(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, int bFindFreeSlot)
{
    D2_ASSERT(pItem, 216);
    D2_ASSERT(pPlayer, 217);
    const int nItemGUID = pItem->dwUnitId;
    int nUnused;
    return ITEMMODE_PlaceCursorItemInBelt(pGame, pPlayer, nItemGUID, CLIENTS_GetUnitX(pItem), bFindFreeSlot, &nUnused) != 0;
}

// 0x00534C70
static D2UnitStrc* __stdcall PLAYER_CreateStartItemStack(D2GameStrc* pGame, int nCount, int nItemId, D2UnitStrc* pPlayer, D2CharStatsTxt* pCharStatsTxt)
{
    if (!pPlayer)
    {
        return 0;
    }
    const int nItemLevel = ITEMS_GetItemLevelForNewItem(pPlayer, 0);
    D2UnitStrc* pItem = D2GAME_CreateItemUnit_6FC501A0(pPlayer, nItemId, pGame, 4, ITEMQUAL_NORMAL, 1, 1, nItemLevel, 0, 0, 0);
    if (pItem)
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pItem, 0, 0x40);
        if (pStatList)
        {
            D2Common_10474(pItem, pStatList);
            STATLIST_FreeStatList(pStatList);
        }
        if (!nCount && pCharStatsTxt->wStartSkill >= 0 && pCharStatsTxt->wStartSkill < sgptDataTables->nSkillsTxtRecordCount)
        {
            D2StatListStrc* pStartItemStatList = STATLIST_GetStatListFromUnitStateAndFlag(pItem, 0, 0x40);
            if (!pStartItemStatList)
            {
                pStartItemStatList = STATLIST_AllocStatList(!pItem ? 0 : pItem->pMemoryPool, 0x40, 0, UNIT_ITEM, !pItem ? -1 : pItem->dwUnitId);
                D2COMMON_10475_PostStatToStatList(pItem, pStartItemStatList, 1);
            }
            const int nLayer = (unsigned short)pCharStatsTxt->wStartSkill;
            STATLIST_SetStatIfListIsValid(pStartItemStatList, STAT_ITEM_SINGLESKILL, 1, nLayer);
        }
        if (ITEMS_CheckIfStackable(pItem))
        {
            const int nMaxStack = ITEMS_GetTotalMaxStack(pItem);
            STATLIST_SetUnitStat(pItem, STAT_QUANTITY, nMaxStack, 0);
        }
    }
    return pItem;
}

// 0x00534D60
void __fastcall PLAYER_CreateStartItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2CharStatsTxt* pCharStatsTxt, int nCount, D2CharItemStrc* pCharItem)
{
    int nItemId;
    if (!DATATBLS_GetItemRecordFromItemCode(pCharItem->dwItemCode, &nItemId))
    {
        return;
    }
    for (int i = 0; i < pCharItem->nItemCount; ++i)
    {
        D2UnitStrc* pItem = PLAYER_CreateStartItemStack(pGame, nCount, nItemId, pPlayer, pCharStatsTxt);
        ITEMS_SetItemFlag(pItem, IFLAG_STARTITEM, 1);
        ITEMS_SetBodyLocation(pItem, pCharItem->nBodyLoc);
        if (ITEMS_CheckIfBeltable(pItem))
        {
            if (!sub_M08_PlaceStartItemInBelt(pGame, pPlayer, pItem, 1))
            {
                PLAYER_PlaceItemInInventory(pGame, 1, pItem, pPlayer);
            }
        }
        else if (pCharItem->nBodyLoc)
        {
            if (!PLAYER_EquipStartItem(pGame, pItem, pPlayer))
            {
                PLAYER_PlaceItemInInventory(pGame, 1, pItem, pPlayer);
            }
            if (ITEMSIsA(pItem, ITEMTYPE_BOW_QUIVER))
            {
                STATLIST_SetUnitStat(pItem, STAT_QUANTITY, 250, 0);
            }
            else
            {
                STATLIST_SetUnitStat(pItem, STAT_DURABILITY, STATLIST_GetMaxDurabilityFromUnit(pItem), 0);
            }
        }
        else
        {
            PLAYER_PlaceItemInInventory(pGame, 1, pItem, pPlayer);
            if (ITEMSIsA(pItem, ITEMTYPE_BOW_QUIVER))
            {
                STATLIST_SetUnitStat(pItem, STAT_QUANTITY, 250, 0);
            }
            else
            {
                STATLIST_SetUnitStat(pItem, STAT_DURABILITY, STATLIST_GetMaxDurabilityFromUnit(pItem), 0);
            }
            if (ITEMSIsA(pItem, ITEMTYPE_BOW_QUIVER))
            {
                STATLIST_SetUnitStat(pItem, STAT_QUANTITY, 100, 0);
            }
        }
    }
}

void __fastcall PLAYER_CreateStartItemsFromCharStatsTxt(D2UnitStrc* pPlayer, D2GameStrc* pGame, unsigned char nAct); // 0x00534F10

static inline D2CharStatsTxt* PLRSAVE2_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x00534F10
void __fastcall PLAYER_CreateStartItemsFromCharStatsTxt(D2UnitStrc* pPlayer, D2GameStrc* pGame, void* pUnused)
{
    if (!pPlayer)
    {
        return;
    }

    D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pPlayer->dwClassId);
    if (!pCharStatsTxtRecord)
    {
        return;
    }

    for (int i = 0; i < 10; ++i)
    {
        PLAYER_CreateStartItem(pGame, pPlayer, pCharStatsTxtRecord, i, &pCharStatsTxtRecord->pItems[i]);
    }
}

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

void __fastcall D2GAME_SendP0x9D_ItemAction_Equip_6FC3EA50(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D090

void __fastcall D2GAME_SendP0x9C_ItemAction_PutInContainer_6FC3E980(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053ED50

void __fastcall D2GAME_SendP0x9C_ItemAction_PutInBelt_6FC3EB90(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053EE70

// 0x00534F80
void __fastcall PLAYER_SynchronizeItemsToClient(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2_ASSERT(pUnit->pInventory, 391);

    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        if (INVENTORY_GetItemNodePage(pItem) == 3)
        {
            D2GAME_SendP0x9D_ItemAction_Equip_6FC3EA50(pClient, pUnit, pCheckedItem, 0);
        }
        else if (pUnit == CLIENTS_GetPlayerFromClient(pClient, 0) && INVENTORY_GetItemNodePage(pItem) == 1)
        {
            D2GAME_SendP0x9C_ItemAction_PutInContainer_6FC3E980(pClient, pUnit, pCheckedItem, 0);
        }
        else if (pUnit == CLIENTS_GetPlayerFromClient(pClient, 0) && INVENTORY_GetItemNodePage(pItem) == 2)
        {
            D2GAME_SendP0x9C_ItemAction_PutInBelt_6FC3EB90(pClient, pUnit, pCheckedItem, 0);
        }
    }
}

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

// 0x00535060
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pUnit, &nUnitType, &nUnitGUID))
    {
        return 1;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (INVENTORY_GetCursorItem(pInventory))
    {
        return 1;
    }

    return UNITS_GetPlayerData(pUnit)->bBusy;
}

// 0x005350B0
void __fastcall PLAYER_ResetBusyState(D2UnitStrc* pUnit)
{
    D2PlayerDataStrc* ptPlayerInfo = UNITS_GetPlayerData(pUnit);
    D2_ASSERT(ptPlayerInfo->bBusy != 0, 0x1C7);

    ptPlayerInfo->bBusy = 0;
}

int __fastcall sub_K10_EmitPlaceStartItemInBelt(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    return PLAYER_PlaceStartItemInBelt(pGame, pPlayer, pItem, 1);
}

// 0x005351C0
void __fastcall PLAYER_CloseInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nUnitType;
    int nUnitGUID;
    D2UnitStrc* pInteractUnit;
    int nInteractUnitId;
    if (SUNIT_GetInteractInfo(pUnit, &nUnitType, &nUnitGUID) && (pInteractUnit = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID)) != 0)
    {
        {
            switch (nUnitType)
            {
            case UNIT_MONSTER:
                D2GAME_NPC_ResetInteract_6FCCB4D0(pGame, pUnit, pInteractUnit);
                nInteractUnitId = pInteractUnit->dwUnitId;
                SCMD_SendInteractionTarget(UnitGetClient(pUnit, ".\\PLAYER\\Player.cpp", 0x202), 0x62, UNIT_MONSTER, nInteractUnitId, 0);
                return;

            case UNIT_OBJECT:
                OBJMODE_CloseObjectInteraction(pGame, pUnit, pInteractUnit);
                nInteractUnitId = pInteractUnit->dwUnitId;
                SCMD_SendInteractionTarget(UnitGetClient(pUnit, ".\\PLAYER\\Player.cpp", 0x206), 0x62, UNIT_OBJECT, nInteractUnitId, 0);
                return;

            case UNIT_PLAYER:
                sub_6FC91250(pGame, pUnit, 6, 0);
                return;

            case UNIT_ITEM:
                if (DATATBLS_GetItemsTxtRecord(pInteractUnit->dwClassId)->dwCode == ' xob')
                {
                    PLRTRADE_CloseCubeInteraction(pGame, pUnit);
                    nInteractUnitId = pInteractUnit->dwUnitId;
                    SCMD_SendInteractionTarget(UnitGetClient(pUnit, ".\\PLAYER\\Player.cpp", 0x211), 0x62, UNIT_ITEM, nInteractUnitId, 0);
                }
                return;
            }
        }
    }

    SCMD_SendInteractionTarget(UnitGetClient(pUnit, ".\\PLAYER\\Player.cpp", 0x217), 0x62, UNIT_INVALID, 0, 0);
}

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc*,int); // 0x00624690

void __fastcall D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(D2GameStrc* pGame, int nUnitId, int nCorpseId, unsigned char bAssign); // 0x0053DF80

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

#define UNITFLAG_INITSEEDSET 0x10

#define EVENTTYPE_FREEHOVER 3

#define EVENTTYPE_STATREGEN 4

#define EVENTTYPE_TRAP 6

#define COLLIDE_MASK_CORPSE 0x9C19

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

int __stdcall INVENTORY_GetOwnerId(D2InventoryStrc* pInventory); // 0x0063D450

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesEx(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int nPosIncrementValue); // 0x0064E7E0

void __stdcall D2Common_10231(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650C20

// 0x005352C0
void __fastcall PLAYER_PlaceCorpse(D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, int nPlayerGUID, D2CoordStrc* pCoord)
{
    D2_ASSERT(hRoom, 543);

    COLLISION_GetFreeCoordinatesEx(hRoom, pCoord, 2, COLLIDE_MASK_CORPSE, 4);

    D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nPlayerGUID);
    if (!pPlayer)
    {
        return;
    }

    D2Common_10231(pPlayer->pDynamicPath, pPlayer, hRoom, pCoord->nX, pCoord->nY);
    pPlayer->dwFlags |= UNITFLAG_TARGETABLE;

    UNITS_ChangeAnimMode(pPlayer, PLRMODE_DEAD);
    pPlayer->dwFlags &= ~UNITFLAG_ISVALIDTARGET;

    STATES_ToggleState(pPlayer, STATE_PLAYERBODY, 1);
    pPlayer->dwFlags |= UNITFLAG_INITSEEDSET;

    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer, EVENTTYPE_FREEHOVER, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer, EVENTTYPE_STATREGEN, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer, EVENTTYPE_TRAP, 0);

    const int nOwnerGUID = INVENTORY_GetOwnerId(pPlayer->pInventory);
    if (nOwnerGUID != -1)
    {
        D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(pGame, nOwnerGUID, nPlayerGUID, 1);
    }
}

// 0x005353B0
void __fastcall PLAYER_SetUniqueIdInPlayerData(D2UnitStrc* pPlayer, int nUnitGUID)
{
    D2_ASSERT(pPlayer, 0x240);

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 0x243);

    pPlayerData->dwUniqueId = nUnitGUID;
}

// 0x005353F0
int __fastcall PLAYER_GetUniqueIdFromPlayerData(D2UnitStrc* pPlayer)
{
    D2_ASSERT(pPlayer, 0x24D);

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 0x250);

    return pPlayerData->dwUniqueId;
}

// 0x00535430
void __fastcall PLAYER_RemoveTownPortal(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
	D2_ASSERT(pPlayer, 602);

	D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
	D2_ASSERT(pPlayerData, 605);

	D2UnitStrc* pPortal = SUNIT_GetServerUnit(pGame, 2, pPlayerData->dwUniqueId);
	if (!pPortal || pPortal->dwClassId != 59)
	{
		return;
	}

	ACT5Q5_OnPortalClosed(pGame, pPortal);

	D2UnitStrc* pOwner = SUNIT_GetPortalOwner(pGame, pPortal);
	D2ActiveRoomStrc* pPortalRoom = UNITS_GetRoom(pPortal);
	if (pPortalRoom)
	{
		DUNGEON_AllocDrlgDelete(pPortalRoom, 2, !pPortal ? -1 : pPortal->dwUnitId);
	}

	SUNIT_RemoveUnit(pGame, pPortal);
	DUNGEON_ToggleHasPortalFlag(pPortalRoom, 1);

	if (!pOwner)
	{
		return;
	}

	ACT5Q5_OnPortalClosed(pGame, pOwner);

	D2ActiveRoomStrc* pOwnerRoom = UNITS_GetRoom(pOwner);
	if (pOwnerRoom)
	{
		DUNGEON_AllocDrlgDelete(pOwnerRoom, 2, !pOwner ? -1 : pOwner->dwUnitId);
	}

	SUNIT_RemoveUnit(pGame, pOwner);
	DUNGEON_ToggleHasPortalFlag(pOwnerRoom, 1);
}

// 0x00535510
int __fastcall PLAYER_DropGold(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, int nValue)
{
    if (SUNIT_GetServerUnit(pGame, 0, nUnitGUID) != pUnit)
    {
        return 0;
    }

    if (nValue > STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0))
    {
        return 0;
    }

    if (nValue < 0)
    {
        return 0;
    }

    if (nValue > (int)UNITS_GetInventoryGoldLimit(pUnit))
    {
        return 0;
    }

    const unsigned int nAmount = nValue;
    if (nAmount > 0)
    {
        D2CoordStrc tCoord;
        UNITS_GetCoords(pUnit, &tCoord);

        unsigned int nGoldValue = nAmount;
        if (nAmount > 2000000000)
        {
            nGoldValue = 2000000000;
        }

        D2UnitStrc* pGoldPiles[0x20];
        int nCount = 0;
        ITEMS_DropGoldPiles(pGame, pUnit, nGoldValue, pGoldPiles, &nCount, 0x20);
        if (nCount)
        {
            for (int i = 0; i < nCount; ++i)
            {
                D2UnitStrc* pItem = pGoldPiles[i];
                if (pUnit && GAME_GetUnitTypeOrInvalid(pUnit) == 0)
                {
                    UNITS_StoreOwner(pItem, pUnit);
                }

                const int nPileGold = STATLIST_UnitGetStatValue(pItem, STAT_GOLD, 0);
                D2GAME_SetStatOrResetGold_6FC7CA70(pUnit, 0xE, STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0) - nPileGold);
            }
        }
    }

    return 1;
}

void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190

int __fastcall PLRTRADE_PrepareItemChange(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* a3); // 0x00567620

int __fastcall MONSTERAI_IsInteractionReady(D2UnitStrc* pNpc, D2UnitStrc* pPlayer); // 0x00573140

// 0x00535610
int __fastcall PLAYER_CanModifyInventory(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* a3)
{
    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID))
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
        if (!pInteractUnit)
        {
            SUNIT_ResetInteractInfo(pPlayer);
            return 0;
        }

        switch (nUnitType)
        {
        case UNIT_PLAYER:
            return PLRTRADE_PrepareItemChange(pGame, pPlayer, a3);

        case UNIT_MONSTER:
            return MONSTERAI_IsInteractionReady(pInteractUnit, pPlayer);
        }
    }
    else
    {
        if (UNITS_GetPlayerData(pPlayer)->bBusy)
        {
            return 0;
        }
    }

    return PLRTRADE_PrepareItemChange(pGame, pPlayer, a3);
}

// 0x005356B0
int __fastcall PLAYER_SetSkillHotKey(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nHotkeyId, short nSkillId, unsigned char nHand, int nFlags)
{
    D2ClientStrc* pClient = UnitGetClient(pPlayer, ".\\PLAYER\\Player.cpp", 755);
    if (!pClient)
    {
        return 0;
    }

    CLIENTS_SetSkillHotKey(pClient, nHotkeyId, nSkillId, nHand, nFlags);
    return 1;
}

struct D2UnitProxyArgStrc;

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0

// 0x005356F0
void __fastcall PLAYER_CountPlayersInLevelCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg)
{
    D2UnitProxyArgStrc* pCount = (D2UnitProxyArgStrc*)pArg;
    if (DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)) == pCount->nLevelId && pUnit && pUnit->dwAnimMode != PLRMODE_DEATH && pUnit->dwAnimMode != PLRMODE_DEAD)
    {
        ++pCount->nCounter;
    }
}

// 0x00535730
int __fastcall PLAYER_CountPlayersInLevel(D2GameStrc* pGame, int nLevelId)
{
    D2UnitProxyArgStrc arg = {};
    arg.nLevelId = nLevelId;
    SUNIT_IterateLivingPlayers(pGame, PLAYER_CountPlayersInLevelCallback, &arg);
    return arg.nCounter;
}

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

// 0x00535760
void __fastcall PLAYER_CountLivingPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pLivingPlayers)
{
    if (!SUNIT_IsDead(pUnit))
    {
        ++*((int*)pLivingPlayers);
    }
}

// 0x00535780
void __fastcall PLAYER_SetVirtualPlayerCount(int nPlayers)
{
    if (nPlayers >= 0 && nPlayers <= 8)
    {
        gnVirtualPlayerCount = nPlayers;
    }
}

// 0x00535790
int __fastcall PLAYER_GetPlayerCount(D2GameStrc* pGame)
{
    int nLivingPlayers = 0;
    SUNIT_IterateLivingPlayers(pGame, PLAYER_CountLivingPlayers, &nLivingPlayers);

    switch (pGame->nGameType)
    {
    case 1:
    case 2:
    case 3:
        if (gnVirtualPlayerCount > nLivingPlayers)
        {
            return gnVirtualPlayerCount;
        }
        break;
    }

    return nLivingPlayers;
}

static inline void PLAYER_SetStatOrResetGold(D2UnitStrc* pUnit, int nStat, int nValue)
{
    if (!pUnit)
    {
        return;
    }

    if (nValue < 0)
    {
        STATLIST_SetUnitStat(pUnit, nStat, 0, 0);
        return;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        if (nStat == 14)
        {
            if (nValue > (int)UNITS_GetInventoryGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
                return;
            }
        }
        else if (nStat == 15)
        {
            if (nValue > UNITS_GetStashGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLDBANK, 0, 0);
                return;
            }
        }
    }

    STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
}

// 0x005357D0
static void __stdcall PLAYER_ApplyDeathGoldLoss(D2GameStrc* pGame, D2UnitStrc* pKiller, D2UnitStrc* pPlayer)
{
    const int nLevel = STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0);
    const int nGold = STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0);
    const int nStash = STATLIST_UnitGetStatValue(pPlayer, STAT_GOLDBANK, 0);
    const int nTotal = nStash + nGold;
    const int nPercent = nLevel < 20 ? nLevel : 20;
    const int nMinimum = nLevel * 500;
    int nLoss = nPercent * nTotal / 100;
    const int nKeep = nTotal - nLoss;

    int bPlayerKill = 0;
    if (pKiller && pKiller != pPlayer)
    {
        if (pKiller->dwUnitType == UNIT_PLAYER)
        {
            bPlayerKill = 1;
        }
        else if (pKiller->dwUnitType == UNIT_MONSTER)
        {
            D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pKiller);
            if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
            {
                bPlayerKill = 1;
            }
        }
    }

    if (pGame->nGameType == 3)
    {
        if (nKeep < nMinimum)
        {
            nLoss = nTotal - nMinimum;
            if (nLoss < 0)
            {
                nLoss = 0;
            }
        }

        if (nLoss > nGold)
        {
            nLoss = nGold;
        }
    }

    if (bPlayerKill)
    {
        if (nLoss > nGold)
        {
            PLAYER_SetStatOrResetGold(pPlayer, 15, nStash - nLoss + nGold);
            PLAYER_SetStatOrResetGold(pPlayer, 14, nLoss);
        }

        PLAYER_DropGold(pGame, pPlayer, !pPlayer ? -1 : pPlayer->dwUnitId, nLoss);
    }
    else
    {
        if (!(nLoss > nGold))
        {
            const int nDrop = nGold - nLoss;
            PLAYER_DropGold(pGame, pPlayer, !pPlayer ? -1 : pPlayer->dwUnitId, nDrop);
        }
        else
        {
            if (pGame->nGameType != 3)
            {
                PLAYER_SetStatOrResetGold(pPlayer, 15, nStash - nLoss + nGold);
            }
        }

        PLAYER_SetStatOrResetGold(pPlayer, 14, 0);
    }

    PLAYER_SetStatOrResetGold(pPlayer, 0xAF, nLoss);
}


// 0x005359F0
static void __stdcall PLAYER_ApplyDeathExperienceLoss(D2GameStrc* pGame, D2UnitStrc* pDefender)
{
    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    const int nClassId = !pDefender ? -1 : pDefender->dwClassId;
    const int nDefenderLevel = STATLIST_UnitGetStatValue(pDefender, STAT_LEVEL, 0);
    if (nDefenderLevel > 1)
    {
        const unsigned int nPreviousExpThreshold = DATATBLS_GetLevelThreshold(nClassId, nDefenderLevel - 1);
        const unsigned int nCurrentExpThreshold = DATATBLS_GetLevelThreshold(nClassId, nDefenderLevel);
        const unsigned int nExpRange = nCurrentExpThreshold - nPreviousExpThreshold;
        int nNewExperienceValue = STATLIST_UnitGetStatValue(pDefender, STAT_EXPERIENCE, 0);
        int nExperiencePenalty = pDifficultyLevelsTxtRecord->dwDeathExpPenalty * nExpRange / 100;
        if (nExperiencePenalty)
        {
            nNewExperienceValue -= nExperiencePenalty;
            if (nNewExperienceValue <= nPreviousExpThreshold)
            {
                nExperiencePenalty += nNewExperienceValue - nPreviousExpThreshold;
                if (nExperiencePenalty < 0)
                {
                    nExperiencePenalty = 0;
                }
                nNewExperienceValue = nPreviousExpThreshold + 1;
            }
            CLIENTS_SetExperienceLoss(UnitGetClient(pDefender, ".\\PLAYER\\Player.cpp", 0x3C4), nExperiencePenalty);
            STATLIST_SetUnitStat(pDefender, STAT_EXPERIENCE, nNewExperienceValue, 0);
        }
    }
}

// 0x00535AB0
void __fastcall PLAYER_ApplyDeathPenalty(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker)
{
    PLAYER_ApplyDeathGoldLoss(pGame, pAttacker, pDefender);
    if (pAttacker)
    {
        if (pAttacker->dwUnitType == UNIT_PLAYER)
        {
            return;
        }
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pAttacker);
        if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
        {
            return;
        }
    }
    PLAYER_ApplyDeathExperienceLoss(pGame, pDefender);
}

struct D2RosterIterateStrc;


int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags); // 0x0055B300

// 0x00535AF0
void __fastcall PLAYER_CheckHostilityCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs)
{
    D2RosterIterateStrc* pRosterIterate = (D2RosterIterateStrc*)pArgs;
    if (PLAYERLIST_CheckFlag(pRosterIterate->pUnit, pUnit, 8))
    {
        pRosterIterate->bFlag = 1;
    }
}

// 0x00535B10
int __fastcall PLAYER_HasHostilePlayer(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pGame || !pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    D2RosterIterateStrc rosterIterate = {};

    rosterIterate.bFlag = 0;
    rosterIterate.pUnit = pUnit;

    SUNIT_IterateLivingPlayers(pGame, PLAYER_CheckHostilityCallback, &rosterIterate);
    return rosterIterate.bFlag;
}

// 0x00535B50
void __fastcall PLAYER_CheckHostileToUnitCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs)
{
    D2RosterIterateStrc* pRosterIterate = (D2RosterIterateStrc*)pArgs;
    if (PLAYERLIST_CheckFlag(pUnit, pRosterIterate->pUnit, 8))
    {
        pRosterIterate->bFlag = 1;
    }
}

// 0x00535B80
int __fastcall PLAYER_IsAnyPlayerHostileTo(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pGame || !pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    D2RosterIterateStrc rosterIterate = {};
    rosterIterate.bFlag = 0;
    rosterIterate.pUnit = pUnit;
    SUNIT_IterateLivingPlayers(pGame, PLAYER_CheckHostileToUnitCallback, &rosterIterate);
    return rosterIterate.bFlag;
}

struct D2SkillsTxt;

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0

D2UnitStrc* __fastcall PLAYER_GetWeaponForSkill(D2UnitStrc* pUnit); // 0x00535BC0

struct D2SkillStrc;

// 0x00535BC0
D2UnitStrc* __fastcall PLAYER_GetWeaponForSkill(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2UnitStrc* pEquippedWeapon;
    int nBodyLoc;
    int bIsLeftHandItem;
    INVENTORY_GetEquippedWeapon(pInventory, &pEquippedWeapon, &nBodyLoc, &bIsLeftHandItem);

    if (UNITS_CanDualWield(pUnit))
    {
        D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
        if (pSkill)
        {
            D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
            if (pSkillsTxtRecord)
            {
                D2UnitStrc* pWeapon = 0;
                switch (pSkillsTxtRecord->nWeapSel)
                {
                case 2:
                {
                    const int nFlag = SKILLS_GetFlags(pSkill) & 0x2000;
// build: symbol ?INVENTORY_GetCompositItem@* 0x0063C050
                    pWeapon = INVENTORY_GetCompositItem(pInventory, 5);
                    D2UnitStrc* pTemp = INVENTORY_GetCompositItem(pInventory, 6);
                    if (!pWeapon || !ITEMSIsA(pWeapon, ITEMTYPE_WEAPON) || pTemp && ITEMSIsA(pTemp, ITEMTYPE_WEAPON) && nFlag)
                    {
                        pWeapon = pTemp;
                    }
                    break;
                }
                case 3:
                {
                    if (((pUnit->dwSeqFrame >> 8) % 2) != 0)
                    {
                        pWeapon = INVENTORY_GetCompositItem(pInventory, 6);
                    }
                    else
                    {
                        pWeapon = INVENTORY_GetCompositItem(pInventory, 5);
                    }
                    break;
                }
                case 4:
                {
                    pEquippedWeapon = 0;
                    break;
                }
                case 1:
                {
                    pWeapon = INVENTORY_GetCompositItem(pInventory, 6);
                    break;
                }
                default:
                    pWeapon = INVENTORY_GetCompositItem(pInventory, 5);
                    if (!pWeapon || !ITEMSIsA(pWeapon, ITEMTYPE_WEAPON))
                    {
                        pWeapon = INVENTORY_GetCompositItem(pInventory, 6);
                    }
                    break;
                }

                if (ITEMSIsA(pWeapon, ITEMTYPE_WEAPON) && ITEMS_CanBeEquipped(pWeapon))
                {
                    return pWeapon;
                }
            }
        }
        return pEquippedWeapon;
    }
    return pEquippedWeapon;
}

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0

D2UnitStrc* __stdcall INVENTORY_GetSecondaryWeapon(D2InventoryStrc* pInventory); // 0x0063BF90

// 0x00535D10
void __fastcall PLAYER_ApplyWeaponStatsForSkill(D2UnitStrc* pAttacker, int bTemporaryWeaponStats)
{
    if (bTemporaryWeaponStats)
    {
        D2UnitStrc* pLeftHandWeapon = INVENTORY_GetLeftHandWeapon(pAttacker->pInventory);
        if (pLeftHandWeapon && STATLIST_GetOwner(pLeftHandWeapon, 0))
        {
            STATLIST_MergeStatLists(pAttacker, pLeftHandWeapon, 0);
        }

        D2UnitStrc* pSecondaryWeapon = INVENTORY_GetSecondaryWeapon(pAttacker->pInventory);
        if (pSecondaryWeapon && pSecondaryWeapon != pLeftHandWeapon && STATLIST_GetOwner(pSecondaryWeapon, 0))
        {
            STATLIST_MergeStatLists(pAttacker, pSecondaryWeapon, 0);
        }
    }

    if (UNITS_CanDualWield(pAttacker))
    {
        D2UnitStrc* pWeapon = PLAYER_GetWeaponForSkill(pAttacker);
        D2UnitStrc* pLeftHandWeapon = INVENTORY_GetLeftHandWeapon(pAttacker->pInventory);
        if (!pWeapon)
        {
            if (pLeftHandWeapon)
            {
                if (STATLIST_GetOwner(pLeftHandWeapon, 0))
                {
                    STATLIST_MergeStatLists(pAttacker, pLeftHandWeapon, 1);
                }
            }
        }
        else if (pWeapon == pLeftHandWeapon)
        {
            D2UnitStrc* pSecondaryWeapon = INVENTORY_GetSecondaryWeapon(pAttacker->pInventory);
            if (STATLIST_GetOwner(pLeftHandWeapon, 0))
            {
                STATLIST_MergeStatLists(pAttacker, pLeftHandWeapon, 1);
            }

            if (pSecondaryWeapon && STATLIST_GetOwner(pSecondaryWeapon, 0))
            {
                STATLIST_MergeStatLists(pAttacker, pSecondaryWeapon, 0);
            }
        }
        else
        {
            if (STATLIST_GetOwner(pWeapon, 0))
            {
                STATLIST_MergeStatLists(pAttacker, pWeapon, 1);
            }

            if (pLeftHandWeapon && STATLIST_GetOwner(pLeftHandWeapon, 0))
            {
                STATLIST_MergeStatLists(pAttacker, pLeftHandWeapon, 0);
            }
        }
    }
}

// 0x00535E20
void __fastcall PLAYER_RestoreWeaponStats(D2UnitStrc* pTarget, int bTemporaryWeaponStats)
{
    if (!bTemporaryWeaponStats)
    {
        return;
    }

    D2UnitStrc* pLeftHandWeapon = INVENTORY_GetLeftHandWeapon(pTarget->pInventory);
    if (pLeftHandWeapon && STATLIST_GetOwner(pLeftHandWeapon, 0))
    {
        STATLIST_MergeStatLists(pTarget, pLeftHandWeapon, 1);
    }

    D2UnitStrc* pSecondaryWeapon = INVENTORY_GetSecondaryWeapon(pTarget->pInventory);
    if (pSecondaryWeapon && pSecondaryWeapon != pLeftHandWeapon)
    {
        if (STATLIST_GetOwner(pSecondaryWeapon, 0))
        {
            STATLIST_MergeStatLists(pTarget, pSecondaryWeapon, 0);
        }
    }
}


