#include "D2CMP.h"
#include "D2CmpTypes.h"
#include "D2FindTileEntry.h"
#include "FogApi.h"

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0


struct D2FindTileNodeStrc
{
    D2CmpTileBlockStrc* pTile;
    D2FindTileNodeStrc* pNext;
};





// 0x0060CEA0
static void FindTileAddToEntry(D2FindTileEntryStrc* pEntry, D2CmpTileBlockStrc* pTile)
{
    for (D2FindTileNodeStrc* pNode = pEntry->pTileList; pNode; pNode = pNode->pNext)
    {
        if (pNode->pTile == pTile)
        {
            return;
        }
    }
    D2FindTileNodeStrc* pNode = (D2FindTileNodeStrc*)FOG_Alloc(sizeof(D2FindTileNodeStrc), ".\\SRC\\FindTiles.cpp", 0x6E, 0);
    D2_ASSERT(pNode, 0x6F);
    memset(pNode, 0, sizeof(D2FindTileNodeStrc));
    pNode->pTile = pTile;
    pNode->pNext = pEntry->pTileList;
    pEntry->pTileList = pNode;
}

// 0x0060CF00
static void FindTileAddEntry(D2FindTileEntryStrc** ppBucket, D2CmpTileBlockStrc* pTile)
{
    D2FindTileEntryStrc* pEntry = (D2FindTileEntryStrc*)FOG_Alloc(sizeof(D2FindTileEntryStrc), ".\\SRC\\FindTiles.cpp", 0x82, 0);
    D2_ASSERT(pEntry, 0x83);
    memset(pEntry, 0, sizeof(D2FindTileEntryStrc));
    pEntry->nKey3 = pTile->nSubIndex;
    pEntry->nKey2 = pTile->nIndex;
    pEntry->nKey1 = pTile->nOrientation;
    pEntry->pNext = *ppBucket;
    *ppBucket = pEntry;
    D2FindTileNodeStrc* pNode = (D2FindTileNodeStrc*)FOG_Alloc(sizeof(D2FindTileNodeStrc), ".\\SRC\\FindTiles.cpp", 0x8E, 0);
    D2_ASSERT(pNode, 0x8F);
    memset(pNode, 0, sizeof(D2FindTileNodeStrc));
    pNode->pTile = pTile;
    pEntry->pTileList = pNode;
}

// 0x0060CDB0
D2FindTileEntryStrc** __cdecl FindTileCreateTable()
{
    D2FindTileEntryStrc** ppBuckets = (D2FindTileEntryStrc**)FOG_Alloc(0x200, ".\\SRC\\FindTiles.cpp", 0x2A, 0);
    D2_ASSERT(ppBuckets, 0x2B);
    memset(ppBuckets, 0, 0x200);
    return ppBuckets;
}

// 0x0060CE00
void __fastcall FindTileDestroyTable(D2CmpFindTilesNodeStrc** ppBuckets)
{
    if (!ppBuckets)
        return;
    for (int i = 0; i < 0x80; i++)
    {
        D2CmpFindTilesNodeStrc* pNode = ppBuckets[i];
        while (pNode)
        {
            D2CmpFindTilesSubStrc* pSub = pNode->pSubs;
            D2CmpFindTilesNodeStrc* pNext = pNode->pNext;
            while (pSub)
            {
                D2CmpFindTilesSubStrc* pSubNext = pSub->pNext;
                FOG_Free(pSub, ".\\SRC\\FindTiles.cpp", 0x4C, 0);
                pSub = pSubNext;
            }
            pNode->pSubs = 0;
            FOG_Free(pNode, ".\\SRC\\FindTiles.cpp", 0x50, 0);
            pNode = pNext;
        }
        ppBuckets[i] = 0;
    }
    FOG_Free(ppBuckets, ".\\SRC\\FindTiles.cpp", 0x57, 0);
}

// 0x0060CFA0
void __fastcall FindTileAddTile(D2FindTileEntryStrc** ppTable, D2CmpTileBlockStrc* pTile)
{
    int bNew = 1;
    D2_ASSERT(ppTable, 0xA5);
    D2_ASSERT(pTile, 0xA6);
    D2FindTileEntryStrc** ppBucket = &ppTable[FindTileHash(pTile->nSubIndex, pTile->nIndex, pTile->nOrientation)];
    D2FindTileEntryStrc* pEntry = *ppBucket;
    while (pEntry && bNew)
    {
        if (pEntry->nKey3 == pTile->nSubIndex && pEntry->nKey2 == pTile->nIndex && pEntry->nKey1 == pTile->nOrientation)
        {
            bNew = 0;
        }
        else
        {
            pEntry = pEntry->pNext;
        }
    }
    if (bNew)
    {
        FindTileAddEntry(ppBucket, pTile);
    }
    else
    {
        FindTileAddToEntry(pEntry, pTile);
    }
}
