#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2EventTimer.h"
#include "D2GameServer.h"
#include "D2GameClient.h"
#include "D2DataTbls.h"
#include "D2GameRecords.h"
#include "D2ItemsWorld.h"
#include "D2MonsterIds.h"
#include "D2LanguageNames.h"
#include "D2NpcEvent.h"
#include "D2ItemDataTbl.h"
#include "FogApi.h"
#include "D2CommonApi.h"
#include "D2CommonApi2.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2NpcRecordStrc;

struct D2ItemCacheStrc;

struct D2UnitProxyStrc;


struct D2NpcGambleStrc;

struct D2NpcVendorChainStrc;

struct D2NpcEventStrc;

struct D2NpcControlStrc;

struct D2NpcTradeStrc;

struct Pad40_00536B40;

struct Pad400_00536B40;

struct Obj00536B40;

struct D2ItemsTxt;

struct D2EventTimerSlabListStrc;

struct D2EventTimerQueueStrc;

struct D2QuestGUIDStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2UnitProxyStrc gaUnitProxyItemCache[17]; // 0x00883D78

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

struct D2NpcVendorChainStrc
{
    int dwGUID;
    int unk0x04;
    D2NpcVendorChainStrc* pNext;
};


struct D2NpcTradeStrc
{
    unsigned char bVendorInit;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned char bTrader;
    int unk0x04;
    unsigned int dwTick;
};

struct D2NpcControlStrc
{
    int nArraySize;
    D2NpcRecordStrc* pFirstRecord;
    D2SeedStrc pSeed;
    int nNpcCount;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260


#include "D2GameFuncs.h"
#include "D2CommonApi3.h"

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60


D2MonsterInteractStrc* __fastcall sub_00535E80_GetMonInteract(D2UnitStrc* pUnit); // 0x00535E80


unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc*); // 0x00628250

void __fastcall SUNITNPC_SetItemTradeFlags(D2UnitStrc*,D2UnitStrc*,D2GameStrc*,int,int); // 0x005762C0

int __fastcall SUNITNPC_RollTraderItems(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int); // 0x00579030

void __fastcall FOG_FreePool(void*,void*,const char*,int,int); // 0x0040B480

struct Pad40_00536B40 {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Pad400_00536B40 {
    Pad40_00536B40 t000;
    Pad40_00536B40 t040;
    Pad40_00536B40 t080;
    Pad40_00536B40 t0C0;
    Pad40_00536B40 t100;
    Pad40_00536B40 t140;
    Pad40_00536B40 t180;
    Pad40_00536B40 t1C0;
    Pad40_00536B40 t200;
    Pad40_00536B40 t240;
    Pad40_00536B40 t280;
    Pad40_00536B40 t2C0;
    Pad40_00536B40 t300;
    Pad40_00536B40 t340;
    Pad40_00536B40 t380;
    Pad40_00536B40 t3C0;
};

struct Obj00536B40 {
    Pad400_00536B40 tPad0000;
    Pad400_00536B40 tPad0400;
    Pad400_00536B40 tPad0800;
    Pad400_00536B40 tPad0C00;
    Pad400_00536B40 tPad1000;
    Pad400_00536B40 tPad1400;
    Pad400_00536B40 tPad1800;
    Pad40_00536B40 tPad1C00;
    Pad40_00536B40 tPad1C40;
    Pad40_00536B40 tPad1C80;
    Pad40_00536B40 tPad1CC0;
    unsigned int dwUnknown1D00;
    unsigned int dwUnknown1D04;
    unsigned int dwUnknown1D08;
    unsigned int dwUnknown1D0C;
    unsigned int dwUnknown1D10;
    unsigned int dwUnknown1D14;
    unsigned int dwUnknown1D18;
    unsigned int dwUnknown1D1C;
    unsigned int dwUnknown1D20;
    unsigned int dwValue1D24;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern unsigned char gbUnitProxyItemCacheInitialized[17]; // 0x00883E88

enum
{
    MAX_NPC_INVENTORY = 17,
    UNIT_ALIGNMENT_EVIL = 0,
    UNITFLAG_TARGETABLE = 0x00000002,
    UNITFLAG_ISMERC = 0x00000200,
    MONSTATS2FLAGINDEX_SOFT = 12,
};


#define MAX_NPC_INVENTORY 17

extern "C" const char szSUnitProxyCppFile[];                                                                // 0x006E0A30

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

static void SUNITPROXY_InitializeItemCache(D2GameStrc* pGame, D2UnitProxyStrc* pUnitProxy, int nNpcInventoryId);


extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern int gnNpcConfigCount; // 0x00731184
extern D2NpcConfigStrc gaNpcConfig[]; // 0x00731188

extern int gnCrossbowQuiverItemId; // 0x00883E9C

extern int gnArrowQuiverItemId; // 0x00883EA0

#define UNIT_MONSTER 1

#define NPCREC_FIELD(type, cursor, offset) (*(type*)((cursor) + (offset) - 0x2C))

extern "C" const char szSUnitProxyCppFile[]; // 0x006E0A30

static void __stdcall SUNITPROXY_RemoveInventoryItems(D2GameStrc* pGame, D2InventoryStrc* pInventory);

static void __stdcall SUNITPROXY_ClearNpcRecordData(D2NpcRecordStrc* pNpcRecord, D2GameStrc* pGame);

void __fastcall SUNITPROXY_AllocNpcInventory(D2GameStrc* pGame, D2NpcRecordStrc* pNpcRecord, D2UnitStrc* pNpc); // 0x00536D10

void __fastcall SUNITPROXY_FreeNpcGamble(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pPlayer);


// 0x00535F30
void __fastcall SUNITPROXY_AllocNpcEvent(D2UnitStrc* pNpc, D2GameStrc* pGame, D2UnitStrc* pPlayer, int bPending)
{
    int nUnused;
    D2NpcEventStrc* pNpcEvent = (D2NpcEventStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2NpcEventStrc), ".\\UNIT\\sunitproxy.cpp", 133, 0);
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromClassId(pGame, !pNpc ? -1 : pNpc->dwClassId, &nUnused);
    if (pNpcRecord)
    {
        pNpcEvent->pNext = pNpcRecord->pEvent;
        pNpcRecord->pEvent = pNpcEvent;
        pNpcEvent->field_C = 1;
        pNpcEvent->pUnit = pPlayer;
        pNpcEvent->nParam = bPending;
    }
    else
    {
        ITEMS_RemoveFromAllPlayers(pGame, pPlayer);
    }
}

// 0x00535FB0
static void SUNITPROXY_InitializeItemCache(D2GameStrc* pGame, D2UnitProxyStrc* pUnitProxy, int nNpcInventoryId)
{
    D2_ASSERT(nNpcInventoryId < MAX_NPC_INVENTORY, 164);
    pUnitProxy->nItems = gaUnitProxyItemCache[nNpcInventoryId].nItems;
    pUnitProxy->pItemCache = (D2ItemCacheStrc*)FOG_AllocPool(pGame->pMemoryPool, gaUnitProxyItemCache[nNpcInventoryId].nItems * sizeof(D2ItemCacheStrc), ".\\UNIT\\sunitproxy.cpp", 168, 0);
    memcpy(pUnitProxy->pItemCache, gaUnitProxyItemCache[nNpcInventoryId].pItemCache, gaUnitProxyItemCache[nNpcInventoryId].nItems * sizeof(D2ItemCacheStrc));
    pUnitProxy->nPerms = gaUnitProxyItemCache[nNpcInventoryId].nPerms;
    pUnitProxy->pPermCache = (unsigned int*)FOG_AllocPool(pGame->pMemoryPool, gaUnitProxyItemCache[nNpcInventoryId].nPerms * sizeof(unsigned int), ".\\UNIT\\sunitproxy.cpp", 171, 0);
    memcpy(pUnitProxy->pPermCache, gaUnitProxyItemCache[nNpcInventoryId].pPermCache, gaUnitProxyItemCache[nNpcInventoryId].nPerms * sizeof(unsigned int));
}

static D2MonStatsTxt* SUNITPROXY_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

static inline unsigned int RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 nSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return (unsigned int)nSeed;
}

// 0x00536070
void __fastcall SUNITPROXY_InitializeNpcControl(D2GameStrc* pGame)
{
    D2NpcRecordStrc* pRecords = (D2NpcRecordStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2NpcRecordStrc)*64, szSUnitProxyCppFile, 0xB7, 0);
    memset(pRecords, 0, sizeof(D2NpcRecordStrc)*64);
    D2NpcControlStrc* pControl = (D2NpcControlStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2NpcControlStrc), szSUnitProxyCppFile, 0xB9, 0);
    pControl->pFirstRecord = 0;
    pControl->nArraySize = 0;
    pControl->nNpcCount = 0;
    SEED_InitSeed(&pControl->pSeed);
    SEED_InitLowSeed(&pControl->pSeed, RollSeed(&pGame->pGameSeed));
    if (!gnCrossbowQuiverItemId) DATATBLS_GetItemRecordFromItemCode(0x20767163, &gnCrossbowQuiverItemId);
    if (!gnArrowQuiverItemId) DATATBLS_GetItemRecordFromItemCode(0x20767161, &gnArrowQuiverItemId);
    DATATBLS_GetItemDataTables();
    int nCount = 0;
    const int nTotal = sgptDataTables->nMonStatsTxtRecordCount;
    for (int nClass = 0; nClass < nTotal; ++nClass)
    {
        D2MonStatsTxt* pTxt = SUNITPROXY_GetMonStatsTxtRecordInline(nClass);
        int bInteract = 0;
        if (pTxt)
            bInteract = pTxt->nMonStatsFlags[1] & gdwBitMasks[1];
        if (!bInteract) continue;
        D2NpcRecordStrc* pNpc = &pRecords[nCount];
        pNpc->nNPC = nClass;
        pNpc->bTrading = 0;
        ++pControl->nNpcCount;
        pNpc->pEvent = 0;
        pNpc->bVendorInit = 0;
        pNpc->bInitialized = 0;
        pNpc->dwTicks = 0;
        pNpc->bTrader = 0;
        pNpc->pInventory = INVENTORY_AllocInventory(pGame->pMemoryPool, 0);
        pNpc->pVendorChain = 0;
        pNpc->pGamble = 0;
        pNpc->bGambleInit = 0;
        D2_ASSERT(nCount < 64, 0xE6);
        const int nConfigCount = gnNpcConfigCount;
        ++pControl->nArraySize;
        int nConfig = 0;
        int bFound = 0;
        while (nConfig < nConfigCount && !bFound)
        {
            if (gaNpcConfig[nConfig].nClassId == nClass) bFound = 1;
            else ++nConfig;
        }
        if (bFound == 1)
        {
            pNpc->nAct = gaNpcConfig[nConfig].nAct;
            pNpc->bTrader = gaNpcConfig[nConfig].bTrader;
            pNpc->bRepair = 0;
            pNpc->bVendor = 0;
            pNpc->unk0x26 = gaNpcConfig[nConfig].unknown06;
            pNpc->bRefreshInventory = 0;
            if (pNpc->bTrader == 1)
            {
                int nCacheIndex;
                switch (pNpc->nNPC)
                {
                case 257:
                    SUNITPROXY_InitializeItemCache(pGame, (D2UnitProxyStrc*)&pNpc->pItemCache, 12);
                    pNpc->bRepair = 1;
                    pNpc->bVendor = 1;
                    break;
                case 254:
                    SUNITPROXY_InitializeItemCache(pGame, (D2UnitProxyStrc*)&pNpc->pItemCache, 7);
                    pNpc->bGambleInit = 1;
                    break;
                case 154:
                    SUNITPROXY_InitializeItemCache(pGame, (D2UnitProxyStrc*)&pNpc->pItemCache, 2);
                    pNpc->bRepair = 1;
                    pNpc->bVendor = 1;
                    break;
                case 178:
                    SUNITPROXY_InitializeItemCache(pGame, (D2UnitProxyStrc*)&pNpc->pItemCache, 3);
                    pNpc->bRepair = 1;
                    pNpc->bVendor = 1;
                    break;
                case 252:
                    SUNITPROXY_InitializeItemCache(pGame, (D2UnitProxyStrc*)&pNpc->pItemCache, 10);
                    pNpc->bRepair = 1;
                    pNpc->bVendor = 1;
                    break;
                case 253:
                    SUNITPROXY_InitializeItemCache(pGame, (D2UnitProxyStrc*)&pNpc->pItemCache, 6);
                    pNpc->bRepair = 1;
                    pNpc->bVendor = 1;
                    break;
                case 148: SUNITPROXY_InitializeItemCache(pGame, (D2UnitProxyStrc*)&pNpc->pItemCache, 0); break;
                case 177: SUNITPROXY_InitializeItemCache(pGame, (D2UnitProxyStrc*)&pNpc->pItemCache, 5); break;
                case 202: SUNITPROXY_InitializeItemCache(pGame, (D2UnitProxyStrc*)&pNpc->pItemCache, 4); break;
                case 255: SUNITPROXY_InitializeItemCache(pGame, (D2UnitProxyStrc*)&pNpc->pItemCache, 8); break;
                case 147:
                    nCacheIndex = 1;
                    goto initialize_shared;
                case 199:
                    SUNITPROXY_InitializeItemCache(pGame, (D2UnitProxyStrc*)&pNpc->pItemCache, 9);
                    pNpc->bGambleInit = 1;
                    break;
                case 405:
                    nCacheIndex = 13;
initialize_shared:
                    SUNITPROXY_InitializeItemCache(pGame, (D2UnitProxyStrc*)&pNpc->pItemCache, nCacheIndex);
                    pNpc->bRepair = 1;
                    pNpc->bVendor = 1;
                    pNpc->bGambleInit = 1;
                    break;
                case 511:
                    SUNITPROXY_InitializeItemCache(pGame, (D2UnitProxyStrc*)&pNpc->pItemCache, 15);
                    pNpc->bRepair = 1;
                    pNpc->bVendor = 1;
                    break;
                case 514:
                    SUNITPROXY_InitializeItemCache(pGame, (D2UnitProxyStrc*)&pNpc->pItemCache, 15);
                    pNpc->bGambleInit = 1;
                    break;
                case 512:
                    SUNITPROXY_InitializeItemCache(pGame, (D2UnitProxyStrc*)&pNpc->pItemCache, 16);
                    pNpc->bRepair = 1;
                    pNpc->bVendor = 1;
                    pNpc->bGambleInit = 1;
                    break;
                case 513: SUNITPROXY_InitializeItemCache(pGame, (D2UnitProxyStrc*)&pNpc->pItemCache, 14); break;
                }
            }
            else
            {
                pNpc->pItemCache = 0;
                pNpc->pPermCache = 0;
            }
        }
        ++nCount;
    }
    pControl->pFirstRecord = pRecords;
    pGame->pNpcControl = pControl;
}

static D2NpcRecordStrc* D10_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc)
{
    int nIndex;
    return SUNITPROXY_GetNpcRecordFromClassId(pGame, !pNpc ? -1 : pNpc->dwClassId, &nIndex);
}

// 0x00536510
static void __stdcall SUNITPROXY_RemoveInventoryItems(D2GameStrc* pGame, D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
    while (pItem)
    {
        D2UnitStrc* pUnit = INVENTORY_UnitIsItem(pItem);
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pItem);
        D2_ASSERT(pUnit, 0x1C6);
        INVENTORY_GetItemNodePage(pItem);
        SUNIT_RemoveUnit(pGame, pUnit);
        pItem = pNext;
    }
}

// 0x00536580
static void __stdcall SUNITPROXY_ClearNpcRecordData(D2NpcRecordStrc* pNpcRecord, D2GameStrc* pGame)
{
    if (pNpcRecord->bGambleInit)
    {
        D2NpcGambleStrc* pGamble = pNpcRecord->pGamble;
        while (pGamble)
        {
            D2NpcGambleStrc* pNextGamble = pGamble->pNext;
            if (pGamble->pInventory)
            {
                SUNITPROXY_RemoveInventoryItems(pGame, pGamble->pInventory);
                INVENTORY_FreeInventory(pGamble->pInventory);
                pGamble->pInventory = 0;
            }
            sub_0040B480(pGame->pMemoryPool, pGamble, ".\\UNIT\\sunitproxy.cpp", 0x1E6, 0);
            pGamble = pNextGamble;
        }
        pNpcRecord->pGamble = 0;
    }

    SUNITPROXY_RemoveInventoryItems(pGame, pNpcRecord->pInventory);
    INVENTORY_FreeInventory(pNpcRecord->pInventory);
    pNpcRecord->pInventory = 0;

    D2NpcEventStrc* pNpcEvent = pNpcRecord->pEvent;
    while (pNpcEvent)
    {
        D2NpcEventStrc* pNextEvent = pNpcEvent->pNext;
        if (pNpcEvent->field_C == 1 && pNpcEvent->pUnit)
        {
            ITEMS_RemoveFromAllPlayers(pGame, pNpcEvent->pUnit);
        }
        sub_0040B480(pGame->pMemoryPool, pNpcEvent, ".\\UNIT\\sunitproxy.cpp", 0x204, 0);
        pNpcEvent = pNextEvent;
    }
    pNpcRecord->pEvent = 0;
}

// 0x00536640
void __fastcall SUNITPROXY_FreeNpcControl(D2GameStrc* pGame)
{
    D2NpcControlStrc* pNpcControl = pGame->pNpcControl;
    D2NpcRecordStrc* pFirst = pNpcControl->pFirstRecord;
    for (int i = 0; i < pNpcControl->nArraySize; ++i)
    {
        char* pCursor = (char*)&pFirst[i] + 0x2C;
        D2NpcVendorChainStrc* pVendorChain = NPCREC_FIELD(D2NpcVendorChainStrc*, pCursor, 0x18);
        if (pVendorChain)
        {
            do
            {
                D2NpcVendorChainStrc* pNext = pVendorChain->pNext;
                sub_0040B480(pGame->pMemoryPool, pVendorChain, ".\\UNIT\\sunitproxy.cpp", 0x21E, 0);
                pVendorChain = pNext;
            }
            while (pVendorChain);
            NPCREC_FIELD(D2NpcVendorChainStrc*, pCursor, 0x18) = 0;
        }

        SUNITPROXY_ClearNpcRecordData((D2NpcRecordStrc*)(pCursor - 0x2C), pGame);

        if (NPCREC_FIELD(void*, pCursor, 0x2C))
        {
            sub_0040B480(pGame->pMemoryPool, NPCREC_FIELD(void*, pCursor, 0x2C), ".\\UNIT\\sunitproxy.cpp", 0x227, 0);
            NPCREC_FIELD(void*, pCursor, 0x2C) = 0;
        }

        if (NPCREC_FIELD(void*, pCursor, 0x34))
        {
            sub_0040B480(pGame->pMemoryPool, NPCREC_FIELD(void*, pCursor, 0x34), ".\\UNIT\\sunitproxy.cpp", 0x22C, 0);
            NPCREC_FIELD(void*, pCursor, 0x34) = 0;
        }

        if (NPCREC_FIELD(void*, pCursor, 0x10))
        {
            sub_0040B480(pGame->pMemoryPool, NPCREC_FIELD(void*, pCursor, 0x10), ".\\UNIT\\sunitproxy.cpp", 0x237, 0);
            NPCREC_FIELD(void*, pCursor, 0x10) = 0;
        }

        NPCREC_FIELD(void*, pCursor, 0x14) = 0;
    }

    sub_0040B480(pGame->pMemoryPool, pNpcControl->pFirstRecord, ".\\UNIT\\sunitproxy.cpp", 0x242, 0);
    sub_0040B480(pGame->pMemoryPool, pNpcControl, ".\\UNIT\\sunitproxy.cpp", 0x243, 0);
    pGame->pNpcControl = 0;
}

void __stdcall SUNITPROXY_UpdateVendorInventory(D2GameStrc* pGame, unsigned char nAct, int bNoMorePlayersInLevel)
{
    D2NpcControlStrc* pNpcControl = pGame->pNpcControl;
    D2NpcRecordStrc* pRecords = pNpcControl->pFirstRecord;
    const unsigned int nTickCount = GetTickCount();
    for (int i = 0; i < pNpcControl->nArraySize; ++i)
    {
        D2NpcRecordStrc* pNpcRecord = &pRecords[i];
        if (&pNpcRecord->bVendorInit && pNpcRecord->nAct == nAct && pNpcRecord->bTrader == 1 && pNpcRecord->bTrading == 1 && pNpcRecord->bVendorInit == 1)
        {
            if (bNoMorePlayersInLevel)
            {
                D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pNpcRecord->dwNPCGUID);
                if (pNpc && pNpc->dwClassId == pNpcRecord->nNPC)
                {
                    if (!MONSTERAI_GetInteractUnitCount(sub_00535E80_GetMonInteract(pNpc)))
                    {
                        SUNITPROXY_AllocNpcInventory(pGame, pNpcRecord, pNpc);
                    }
                    else
                    {
                        pNpcRecord->bRefreshInventory = 1;
                    }
                }
                else
                {
                    SUNITPROXY_AllocNpcInventory(pGame, pNpcRecord, 0);
                }
            }
            else
            {
                if (nTickCount > pNpcRecord->dwTicks + 240000)
                {
                    pNpcRecord->bRefreshInventory = 1;
                    pNpcRecord->dwTicks = nTickCount;
                }
            }
        }
    }
}

// 0x00536760
static void __stdcall SUNITPROXY_AddNpcEvent(D2UnitStrc* pUnit, int nParam, int nAction, D2GameStrc* pGame, D2NpcRecordStrc* pNpcRecord)
{
    D2NpcEventStrc* pNpcEvent = (D2NpcEventStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2NpcEventStrc), ".\\UNIT\\sunitproxy.cpp", 0x263, 0);
    pNpcEvent->pNext = pNpcRecord->pEvent;
    pNpcEvent->pUnit = pUnit;
    pNpcEvent->field_C = 0;
    pNpcEvent->nParam = nParam;
    pNpcEvent->nAction = nAction;
    pNpcRecord->pEvent = pNpcEvent;
}

// 0x005367B0
void __fastcall SUNITPROXY_QueueTradeEvent(D2UnitStrc* pNpc, D2GameStrc* pGame, D2UnitStrc* pUnit, int nParam, int nAction)
{
    const unsigned long dwTick = GetTickCount();
    int nIndex;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromClassId(pGame, !pNpc ? -1 : pNpc->dwClassId, &nIndex);
    if (pNpcRecord)
    {
        D2NpcTradeStrc* pTrade = (D2NpcTradeStrc*)&pNpcRecord->bVendorInit;
        if (pTrade && pTrade->bTrader == 1 && pTrade->bVendorInit == 1 && pNpcRecord->bTrading == 1)
        {
            SUNITPROXY_AddNpcEvent(pUnit, nParam, nAction, pGame, pNpcRecord);
            pTrade->dwTick = dwTick;
        }
    }
}

struct D2ActiveRoomStrc;

struct D2UnitProxyArgStrc;


// 0x00536820
void __fastcall SUNITPROXY_CountPlayersInLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg)
{
    D2UnitProxyArgStrc* pUnitProxyArg = (D2UnitProxyArgStrc*)pArg;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom && pUnitProxyArg->nLevelId == DUNGEON_GetLevelIdFromRoom(pRoom))
    {
        ++pUnitProxyArg->nCounter;
    }
}

// 0x00535EA0
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromClassId(D2GameStrc* pGame, int nNpcClassId, int* pIndex)
{
    D2NpcRecordStrc* pRecords = pGame->pNpcControl->pFirstRecord;
    for (*pIndex = 0; *pIndex < MAX_NPC_RECORDS; ++*pIndex)
    {
        if (pRecords[*pIndex].nNPC == nNpcClassId)
        {
            return &pRecords[*pIndex];
        }
    }

    D2_ASSERT(nNpcClassId, 114);
    return 0;
}

// 0x00535F10
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc, int* pIndex)
{
    return SUNITPROXY_GetNpcRecordFromClassId(pGame, !pNpc ? -1 : pNpc->dwClassId, pIndex);
}

// 0x00536850
void __fastcall SUNITPROXY_InitializeNpcEventChain(D2GameStrc* pGame, int nUnused, D2UnitStrc* pUnit)
{
    int i = 0;
    D2NpcControlStrc* pNpcControl = pGame->pNpcControl;
    D2NpcRecordStrc* pRecord = pNpcControl->pFirstRecord;
    GetTickCount();
    for (; i < pNpcControl->nArraySize; ++i)
    {
        if (pRecord->bTrader == 1 && pRecord->bVendorInit == 1 && pRecord->bTrading == 1)
        {
            D2NpcEventStrc* pEvent = (D2NpcEventStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2NpcEventStrc), ".\\UNIT\\sunitproxy.cpp", 611, 0);
            pEvent->pNext = pRecord->pEvent;
            pEvent->field_C = 0;
            pEvent->pUnit = pUnit;
            pEvent->nParam = 1;
            pEvent->nAction = 4;
            pRecord->pEvent = pEvent;
        }
        ++pRecord;
    }
}

// 0x005368F0
void __fastcall SUNITPROXY_ProcessNpcEvents(D2GameStrc* game,D2UnitStrc* npc)
{
 int count=0;
 D2NpcRecordStrc* record;
 record=SUNITPROXY_GetNpcRecordFromClassId(game,!npc?-1:npc->dwClassId,(int*)&record);
 if(!record)return;
 D2NpcEventStrc* prev=0;
 for(D2NpcEventStrc* event=record->pEvent;event;event=event->pNext) {
  if(event->nParam) { event->nParam=0;if(!event->field_C && event->nAction==4)++count; }
 }
 if(count && npc->pInventory) {
  D2UnitStrc* iter=INVENTORY_GetFirstItem(npc->pInventory);
  while(iter && count) {
   D2UnitStrc* item=INVENTORY_UnitIsItem(iter);
   iter=INVENTORY_GetNextItem(iter);
   if(ITEMS_GetItemQuality(item)==ITEMQUAL_MAGIC){SUNITNPC_RemoveStoreItem(npc,item,game,0);--count;}
  }
 }
 D2NpcEventStrc* event=record->pEvent;
 while(event) {
  if(event->field_C==1) {
   int placed=D2GAME_PlaceItem(".\\UNIT\\sunitproxy.cpp",0x3cb,game,npc,!event->pUnit?-1:event->pUnit->dwUnitId,0,0,1,1,0);
   if(!placed) {
    if(ITEMS_GetInvPage(event->pUnit)==1){
     ITEMS_SetInvPage(event->pUnit,2);
     placed=D2GAME_PlaceItem(".\\UNIT\\sunitproxy.cpp",0x3d1,game,npc,!event->pUnit?-1:event->pUnit->dwUnitId,0,0,1,1,0);
    }else if(ITEMS_GetInvPage(event->pUnit)==2){
     ITEMS_SetInvPage(event->pUnit,1);
     placed=D2GAME_PlaceItem(".\\UNIT\\sunitproxy.cpp",0x3d9,game,npc,!event->pUnit?-1:event->pUnit->dwUnitId,0,0,1,1,0);
    }
   }
   if(!placed){prev=event;event=event->pNext;continue;}
   SUNITNPC_SetItemTradeFlags(npc,event->pUnit,game,0,0);
   if(event==record->pEvent){record->pEvent=event->pNext;FOG_FreePool(game->pMemoryPool,event,".\\UNIT\\sunitproxy.cpp",0x3ea,0);event=record->pEvent;prev=0;}
   else{prev->pNext=event->pNext;FOG_FreePool(game->pMemoryPool,event,".\\UNIT\\sunitproxy.cpp",0x3f1,0);event=prev->pNext;}
  }else {
   if(!SUNITNPC_RollTraderItems(game,npc,event->pUnit,event->nAction)){prev=event;event=event->pNext;continue;}
   if(event==record->pEvent){record->pEvent=event->pNext;FOG_FreePool(game->pMemoryPool,event,".\\UNIT\\sunitproxy.cpp",0x403,0);event=record->pEvent;prev=0;}
   else{prev->pNext=event->pNext;FOG_FreePool(game->pMemoryPool,event,".\\UNIT\\sunitproxy.cpp",0x40a,0);event=prev->pNext;}
  }
 }
}

// 0x00536B20
D2InventoryStrc* __fastcall SUNITPROXY_GetNpcInventory(D2GameStrc* pGame, int nNpc)
{
    int nUnused;
    return SUNITPROXY_GetNpcRecordFromClassId(pGame, nNpc, &nUnused)->pInventory;
}

// 0x00536B40
extern "C" __declspec(dllexport) unsigned int __fastcall SUNITPROXY_GetSeedFromNpcControl(Obj00536B40* pObj) {
    return pObj->dwValue1D24 + 8;
}

// 0x00536B50
void __fastcall SUNITPROXY_FreeVendorChain(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc)
{
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromClassId(pGame, !pNpc ? -1 : pNpc->dwClassId, (int*)&pNpc);
    if (!pNpcRecord)
    {
        return;
    }

    int& nPlayerGUID = *(int*)&pNpc;
    const int nGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    nPlayerGUID = nGUID;
    if (pNpcRecord->bGambleInit)
    {
        D2NpcGambleStrc* pPreviousGamble = 0;
        for (D2NpcGambleStrc* pGamble = pNpcRecord->pGamble; pGamble; pGamble = pGamble->pNext)
        {
            if (pGamble->dwGUID == nPlayerGUID)
            {
                if (pPreviousGamble)
                {
                    pPreviousGamble->pNext = pGamble->pNext;
                }
                else
                {
                    pNpcRecord->pGamble = pGamble->pNext;
                }

                if (pGamble->pInventory)
                {
                    SUNITPROXY_RemoveInventoryItems(pGame, pGamble->pInventory);
                    INVENTORY_FreeInventory(pGamble->pInventory);
                    pGamble->pInventory = 0;
                }

                sub_0040B480(pGame->pMemoryPool, pGamble, szSUnitProxyCppFile, 0x48F, 0);
                break;
            }

            pPreviousGamble = pGamble;
        }
    }

    D2NpcVendorChainStrc* pVendorChain = pNpcRecord->pVendorChain;
    if (!pVendorChain)
    {
        return;
    }

    D2NpcVendorChainStrc* pPreviousVendorChain = 0;
    for (; pVendorChain; pVendorChain = pVendorChain->pNext)
    {
        if (pVendorChain->dwGUID == nPlayerGUID)
        {
            if (pPreviousVendorChain)
            {
                pPreviousVendorChain->pNext = pVendorChain->pNext;
            }
            else
            {
                pNpcRecord->pVendorChain = pVendorChain->pNext;
            }

            sub_0040B480(pGame->pMemoryPool, pVendorChain, szSUnitProxyCppFile, 0x4A7, 0);
            return;
        }

        pPreviousVendorChain = pVendorChain;
    }
}

// 0x00536C50
D2InventoryStrc* __fastcall SUNITPROXY_GetGambleInventory(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc)
{
    int nUnused;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromClassId(pGame, !pNpc ? -1 : pNpc->dwClassId, &nUnused);
    if (!pNpcRecord || !pNpcRecord->bGambleInit)
    {
        return 0;
    }

    const int nPlayerGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    for (D2NpcGambleStrc* pGamble = pNpcRecord->pGamble; pGamble; pGamble = pGamble->pNext)
    {
        if (pGamble->dwGUID == nPlayerGUID)
        {
            return pGamble->pInventory;
        }
    }

    return 0;
}

// 0x00536CB0
D2NpcVendorChainStrc* __fastcall SUNITPROXY_GetVendorChain(D2GameStrc* pGame, D2NpcRecordStrc* pNpcRecord, D2UnitStrc* pPlayer)
{
    const int nNpcGUID = !pPlayer ? -1 : pPlayer->dwUnitId;

    for (D2NpcVendorChainStrc* pVendorChain = pNpcRecord->pVendorChain; pVendorChain; pVendorChain = pVendorChain->pNext)
    {
        if (pVendorChain->dwGUID == nNpcGUID)
        {
            return pVendorChain;
        }
    }

    D2NpcVendorChainStrc* pVendorChain = (D2NpcVendorChainStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2NpcVendorChainStrc), ".\\UNIT\\sunitproxy.cpp", 0x4ED, 0);
    pVendorChain->dwGUID = nNpcGUID;
    pVendorChain->pNext = pNpcRecord->pVendorChain;
    pNpcRecord->pVendorChain = pVendorChain;
    return pVendorChain;
}

// 0x00536D10
void __fastcall SUNITPROXY_AllocNpcInventory(D2GameStrc* pGame, D2NpcRecordStrc* pNpcRecord, D2UnitStrc* pNpc)
{
    SUNITPROXY_ClearNpcRecordData(pNpcRecord, pGame);

    pNpcRecord->bVendorInit = 0;
    pNpcRecord->dwTicks = 0;
    pNpcRecord->pInventory = INVENTORY_AllocInventory(pGame->pMemoryPool, 0);

    if (pNpc)
    {
        pNpc->pInventory = pNpcRecord->pInventory;
    }
}

// 0x00536D50
void __stdcall SUNITPROXY_FillIGlobaltemCacheRecordForNpc(int nNpcId)
{
    D2ItemDataTbl* pItemDataTbl = DATATBLS_GetItemDataTables();
    if (gbUnitProxyItemCacheInitialized[nNpcId])
    {
        return;
    }

    gbUnitProxyItemCacheInitialized[nNpcId] = 1;

    int nItemCount = 0;
    int nPermStoreItemCount = 0;
    for (int i = 0; i < pItemDataTbl->nItemsTxtRecordCount; ++i)
    {
        if (pItemDataTbl->pItemsTxt[i].nSpawnable && (pItemDataTbl->pItemsTxt[i].nVendorMax[nNpcId] || pItemDataTbl->pItemsTxt[i].nVendorMagicMax[nNpcId]))
        {
            if (!pItemDataTbl->pItemsTxt[i].nPermStoreItem)
            {
                ++nItemCount;
            }
            else
            {
                ++nPermStoreItemCount;
            }
        }
    }

    gaUnitProxyItemCache[nNpcId].pItemCache = (D2ItemCacheStrc*)FOG_AllocPool(0, sizeof(D2ItemCacheStrc) * nItemCount, ".\\UNIT\\sunitproxy.cpp", 0x523, 0);
    memset(gaUnitProxyItemCache[nNpcId].pItemCache, 0, sizeof(D2ItemCacheStrc) * nItemCount);
    gaUnitProxyItemCache[nNpcId].nItems = nItemCount;

    gaUnitProxyItemCache[nNpcId].pPermCache = (unsigned int*)FOG_AllocPool(0, sizeof(unsigned int) * nPermStoreItemCount, ".\\UNIT\\sunitproxy.cpp", 0x528, 0);
    memset(gaUnitProxyItemCache[nNpcId].pPermCache, 0, sizeof(unsigned int) * nPermStoreItemCount);
    gaUnitProxyItemCache[nNpcId].nPerms = nPermStoreItemCount;

    int nItemCacheIndex = 0;
    int nPermCacheIndex = 0;
    for (int i = 0; i < pItemDataTbl->nItemsTxtRecordCount; ++i)
    {
        if (pItemDataTbl->pItemsTxt[i].nSpawnable && (pItemDataTbl->pItemsTxt[i].nVendorMax[nNpcId] || pItemDataTbl->pItemsTxt[i].nVendorMagicMax[nNpcId]))
        {
            if (!pItemDataTbl->pItemsTxt[i].nPermStoreItem)
            {
                gaUnitProxyItemCache[nNpcId].pItemCache[nItemCacheIndex].nMin = pItemDataTbl->pItemsTxt[i].nVendorMin[nNpcId];
                gaUnitProxyItemCache[nNpcId].pItemCache[nItemCacheIndex].nMax = pItemDataTbl->pItemsTxt[i].nVendorMax[nNpcId];
                gaUnitProxyItemCache[nNpcId].pItemCache[nItemCacheIndex].nMagicMin = pItemDataTbl->pItemsTxt[i].nVendorMagicMin[nNpcId];
                gaUnitProxyItemCache[nNpcId].pItemCache[nItemCacheIndex].nMagicMax = pItemDataTbl->pItemsTxt[i].nVendorMagicMax[nNpcId];
                gaUnitProxyItemCache[nNpcId].pItemCache[nItemCacheIndex].nMagicLevel = pItemDataTbl->pItemsTxt[i].nVendorMagicLvl[nNpcId];
                gaUnitProxyItemCache[nNpcId].pItemCache[nItemCacheIndex].dwCode = pItemDataTbl->pItemsTxt[i].dwCode;
                ++nItemCacheIndex;
            }
            else
            {
                gaUnitProxyItemCache[nNpcId].pPermCache[nPermCacheIndex] = pItemDataTbl->pItemsTxt[i].dwCode;
                ++nPermCacheIndex;
            }
        }
    }
}


enum D2C_MonStatsTxtFlagIndices
{
    MONSTATSFLAGINDEX_INTERACT = 9,
};

// 0x00536F80
void __fastcall SUNITPROXY_FillGlobalItemCache()
{
    const int nRecordCount = sgptDataTables->nMonStatsTxtRecordCount;
    for (int i = 0; i < nRecordCount; ++i)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = SUNITPROXY_GetMonStatsTxtRecordInline(i);
        int bInteract = 0;
        if (pMonStatsTxtRecord)
            bInteract = pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_INTERACT >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_INTERACT & 7];
        if (bInteract)
        {
            switch (i)
            {
            case MONSTER_HALBU:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(12);
                break;
            case MONSTER_ALKOR:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(7);
                break;
            case MONSTER_CHARSI:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(2);
                break;
            case MONSTER_FARA:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(3);
                break;
            case MONSTER_ASHEARA:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(10);
                break;
            case MONSTER_HRATLI:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(6);
                break;
            case MONSTER_AKARA:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(0);
                break;
            case MONSTER_DROGNAN:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(5);
                break;
            case MONSTER_LYSANDER:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(4);
                break;
            case MONSTER_ORMUS:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(8);
                break;
            case MONSTER_GHEED:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(1);
                break;
            case MONSTER_ELZIX:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(9);
                break;
            case MONSTER_JAMELLA:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(13);
                break;
            case MONSTER_DREHYA:
            case MONSTER_NIHLATHAK:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(16);
                break;
            case MONSTER_MALAH:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(14);
                break;
            case MONSTER_LARZUK:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(15);
                break;
            default:
                break;
            }
        }
    }
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

// 0x00537120
void __fastcall SUNITPROXY_ClearGlobalItemCache()
{
    for (int i = 0; i < MAX_NPC_INVENTORY; ++i)
    {
        if (gbUnitProxyItemCacheInitialized[i] == 1)
        {
            gbUnitProxyItemCacheInitialized[i] = 0;

            if (gaUnitProxyItemCache[i].pItemCache)
            {
                FOG_FreePool(0, gaUnitProxyItemCache[i].pItemCache, ".\\UNIT\\sunitproxy.cpp", 0x59D, 0);
                gaUnitProxyItemCache[i].pItemCache = 0;
            }

            if (gaUnitProxyItemCache[i].pPermCache)
            {
                FOG_FreePool(0, gaUnitProxyItemCache[i].pPermCache, ".\\UNIT\\sunitproxy.cpp", 0x5A2, 0);
                gaUnitProxyItemCache[i].pPermCache = 0;
            }
        }
    }
}

// 0x00537190
void __fastcall SUNITPROXY_FreeNpcGamble(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pPlayer)
{
    int nIndex;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromClassId(pGame, !pNpc ? -1 : pNpc->dwClassId, &nIndex);
    const int nPlayerGUID = !pPlayer ? -1 : pPlayer->dwUnitId;

    if (pNpcRecord && pNpcRecord->bGambleInit)
    {
        D2NpcGambleStrc* pPreviousGamble = 0;
        for (D2NpcGambleStrc* pGamble = pNpcRecord->pGamble; pGamble; pGamble = pGamble->pNext)
        {
            if (pGamble->dwGUID == nPlayerGUID)
            {
                if (pPreviousGamble)
                {
                    pPreviousGamble->pNext = pGamble->pNext;
                }
                else
                {
                    pNpcRecord->pGamble = pGamble->pNext;
                }

                if (pGamble->pInventory)
                {
                    SUNITPROXY_RemoveInventoryItems(pGame, pGamble->pInventory);
                    INVENTORY_FreeInventory(pGamble->pInventory);
                    pGamble->pInventory = 0;
                }

                sub_0040B480(pGame->pMemoryPool, pGamble, ".\\UNIT\\sunitproxy.cpp", 0x5D0, 0);
                return;
            }

            pPreviousGamble = pGamble;
        }
    }
}

// 0x005A4F20
int __fastcall SUNITPROXY_GetDifficultyScaledBonus(D2GameStrc* pGame, int nCount)
{
    if (pGame->nDifficulty <= 0)
    {
        return 0;
    }

    if (nCount < 2)
    {
        return 0;
    }

    if (nCount < 9)
    {
        return gnDifficultyBonus[nCount];
    }

    return 8 * nCount - 16;
}

#pragma pack(push, 1)
struct d2data_00731184_t
{
    unsigned char b0[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00731188_t
{
    unsigned char b0[344];
};
#pragma pack(pop)

extern "C" struct d2data_00731184_t gData_00731184; // 0x00731184
extern "C" struct d2data_00731188_t gData_00731188; // 0x00731188

extern const int gnDifficultyBonus[9] = { 0, 0, 8, 16, 24, 32, 40, 48, 56 }; // 0x006E21F4

extern "C" struct d2data_00731184_t gData_00731184 = {
    { 0x2B }
}; // 0x00731184
#pragma comment(linker, "/alternatename:?gnNpcConfigCount@@3HA=_gData_00731184")

extern "C" struct d2data_00731188_t gData_00731188 = {
    {
        0x94, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x9A, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x96, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x93, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x9B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x0A, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAF, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
        0xB0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0xB1, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00,
        0xB2, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0xCA, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,
        0xC8, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0xD2, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
        0xC9, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0xC6, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
        0xC7, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x79, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
        0x7A, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x09, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xF4, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0xF5, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00,
        0xFB, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00,
        0xFD, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00,
        0xFF, 0x00, 0x00, 0x00, 0x01, 0x02, 0x01, 0x00, 0x08, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00,
        0xF6, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x96, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
        0x6F, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x98, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
        0x01, 0x01, 0x00, 0x00, 0x01, 0x03, 0x01, 0x00, 0x95, 0x01, 0x00, 0x00, 0x01, 0x03, 0x01, 0x00,
        0x29, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x4B, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
        0x01, 0x02, 0x00, 0x00, 0x01, 0x04, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x01, 0x04, 0x00, 0x00,
        0xFF, 0x01, 0x00, 0x00, 0x01, 0x04, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x01, 0x04, 0x00, 0x00,
        0x03, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x09, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
        0x08, 0x02, 0x00, 0x00, 0x00, 0x04
    }
}; // 0x00731188
#pragma comment(linker, "/alternatename:?gaNpcConfig@@3PAUD2NpcConfigStrc@@A=_gData_00731188")
