#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2GameAux.h"

struct D2TargetNodeStrc;
struct D2UnitStrc;
struct D2GameStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0


void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

// 0x005B1880
void __fastcall TARGETS_AllocPlayerNode(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3)
{
    if (!pGame || !pUnit || pUnit->dwUnitType != UNIT_PLAYER || pUnit->dwNodeIndex != 11)
        return;
    D2TargetNodeStrc** ppNode = pGame->pTargetNodes;
    int i = 0;
    for (; i < 8; ++i, ++ppNode)
    {
        if (!*ppNode)
            break;
    }
    if (pGame->nClients > 8 || i >= 8)
        return;
    D2TargetNodeStrc* p = (D2TargetNodeStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2TargetNodeStrc), gszTargetsSourceFile, 57, 0);
    if (!p)
        return;
    memset(p, 0, sizeof(D2TargetNodeStrc));
    p->hUnit = pUnit;
    p->nNodeData = a3;
    *ppNode = p;
    pUnit->dwNodeIndex = i;
}

// 0x005B1900
void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex)
{
    if (!pGame || !pUnit || pUnit->dwNodeIndex != 11 || nNodeIndex >= 8 || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
        return;
    D2TargetNodeStrc* pNode = pGame->pTargetNodes[nNodeIndex];
    if (!pNode || !pNode->hUnit)
        return;
    D2TargetNodeStrc* p = (D2TargetNodeStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2TargetNodeStrc), gszTargetsSourceFile, 108, 0);
    if (!p)
        return;
    memset(p, 0, sizeof(D2TargetNodeStrc));
    p->hUnit = pUnit;
    p->nNodeData = a3;
    p->pNext = pNode->pNext;
    p->pPrevious = pNode;
    if (pNode->pNext)
        pNode->pNext->pPrevious = p;
    pNode->pNext = p;
    pUnit->dwNodeIndex = nNodeIndex;
}

extern "C" const char gData_006E2C78[120]; // 0x006E2C78

extern "C" const char gData_006E2C78[120] = {
    46, 92, 71, 65, 77, 69, 92, 84, 97, 114, 103, 101, 116, 115, 46, 99,
    112, 112, 0, 0, 0, 0, 0, 0, 98, 115, 100, 32, 4, 1, 0, 0,
    116, 97, 120, 32, 4, 1, 0, 0, 118, 111, 117, 32, 4, 1, 0, 0,
    116, 111, 119, 32, 5, 1, 0, 0, 116, 97, 120, 32, 5, 1, 0, 0,
    114, 105, 110, 32, 6, 1, 0, 0, 102, 108, 100, 32, 3, 1, 0, 0,
    104, 103, 108, 32, 10, 1, 0, 0, 102, 108, 100, 32, 3, 1, 0, 0,
    104, 98, 116, 32, 9, 1, 0, 0, 104, 98, 116, 32, 9, 1, 0, 0,
    99, 114, 110, 32, 1, 1
}; // 0x006E2C78
#pragma comment(linker, "/alternatename:_gszTargetsSourceFile=_gData_006E2C78")

// 0x005B1990
void __fastcall TARGETS_InsertUnitNode(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex)
{
    if (!pGame || !pUnit || pUnit->dwNodeIndex != 11 || nNodeIndex < 8 || nNodeIndex > 9 || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
        return;
    D2TargetNodeStrc* pNode = pGame->pTargetNodes[nNodeIndex];
    D2TargetNodeStrc* p = (D2TargetNodeStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2TargetNodeStrc), gszTargetsSourceFile, 161, 0);
    if (!p)
        return;
    memset(p, 0, sizeof(D2TargetNodeStrc));
    p->hUnit = pUnit;
    p->nNodeData = a3;
    pGame->pTargetNodes[nNodeIndex] = p;
    if (pNode)
    {
        p->pNext = pNode;
        pNode->pPrevious = p;
    }
    pUnit->dwNodeIndex = nNodeIndex;
}

// 0x005B1A20
void __fastcall D2GAME_FreeUnitNode_6FC40310(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pGame || !pUnit || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
    {
        return;
    }

    const int nNodeIndex = pUnit->dwNodeIndex;
    if (nNodeIndex == 11)
    {
        return;
    }

    D2TargetNodeStrc* pTargetNode = pGame->pTargetNodes[nNodeIndex];
    while (pTargetNode)
    {
        D2TargetNodeStrc* pNext = pTargetNode->pNext;
        if (pTargetNode->hUnit)
        {
            pTargetNode->hUnit->dwNodeIndex = 11;
        }

        FOG_FreePool(pGame->pMemoryPool, pTargetNode, gszTargetsSourceFile, 232, 0);
        pTargetNode = pNext;
    }
    pGame->pTargetNodes[nNodeIndex] = 0;
}

// 0x005B1A90
void __fastcall TARGETS_RemoveUnitNode(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pGame || !pUnit || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
        return;
    const int nNodeIndex = pUnit->dwNodeIndex;
    if (nNodeIndex == 11)
        return;
    D2TargetNodeStrc* pTargetNode = pGame->pTargetNodes[nNodeIndex];
    if (!pTargetNode)
        return;
    if (nNodeIndex < 8)
    {
        for (pTargetNode = pTargetNode->pNext; pTargetNode; pTargetNode = pTargetNode->pNext)
        {
            if (pTargetNode->hUnit == pUnit)
            {
                pTargetNode->pPrevious->pNext = pTargetNode->pNext;
                if (pTargetNode->pNext) pTargetNode->pNext->pPrevious = pTargetNode->pPrevious;
                FOG_FreePool(pGame->pMemoryPool, pTargetNode, gszTargetsSourceFile, 322, 0);
                pUnit->dwNodeIndex = 11;
                return;
            }
        }
    }
    else
    {
        D2TargetNodeStrc* const pHead = pTargetNode;
        for (; pTargetNode; pTargetNode = pTargetNode->pNext)
        {
            if (pTargetNode->hUnit == pUnit)
            {
                if (pTargetNode == pHead)
                {
                    pGame->pTargetNodes[nNodeIndex] = pTargetNode->pNext;
                    if (pTargetNode->pNext) pTargetNode->pNext->pPrevious = 0;
                }
                else
                {
                    pTargetNode->pPrevious->pNext = pTargetNode->pNext;
                    if (pTargetNode->pNext) pTargetNode->pNext->pPrevious = pTargetNode->pPrevious;
                }
                FOG_FreePool(pGame->pMemoryPool, pTargetNode, gszTargetsSourceFile, 322, 0);
                break;
            }
        }
    }
    pUnit->dwNodeIndex = 11;
}

// 0x005B1B70
void __fastcall TARGETS_FreeAllTargetNodes(D2GameStrc* pGame)
{
    if (!pGame)
    {
        return;
    }

    D2TargetNodeStrc** ppTargetNode = pGame->pTargetNodes;
    D2TargetNodeStrc* pTargetNode = *ppTargetNode;
    for (int nCount = 10; nCount; --nCount)
    {
        if (pTargetNode && pTargetNode->hUnit)
        {
            D2GAME_FreeUnitNode_6FC40310(pGame, pTargetNode->hUnit);
        }
        pTargetNode = *++ppTargetNode;
    }
}

// 0x005B1BC0
D2TargetNodeStrc* __fastcall TARGETS_FindTargetNode(D2UnitStrc* pUnit, D2GameStrc* pGame)
{
    if (!pGame || !pUnit || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
    {
        return 0;
    }

    const int nNodeIndex = pUnit->dwNodeIndex;
    if (nNodeIndex == 11)
    {
        return 0;
    }

    for (D2TargetNodeStrc* pNode = pGame->pTargetNodes[nNodeIndex]; pNode; pNode = pNode->pNext)
    {
        if (pNode->hUnit == pUnit)
        {
            return pNode;
        }
    }

    return 0;
}

// 0x005B1C00
void __fastcall TARGETS_ToggleTargetFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFlags, int bSet)
{
    if (!pGame || !pUnit)
    {
        return;
    }

    D2TargetNodeStrc* pTargetNode;
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        pTargetNode = TARGETS_FindTargetNode(pUnit, pGame);
    }
    else if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        pTargetNode = TARGETS_FindTargetNode(pUnit, pGame);
    }
    else
    {
        return;
    }

    if (!pTargetNode)
    {
        return;
    }

    if (bSet)
    {
        pTargetNode->nNodeData |= nFlags;
    }
    else
    {
        pTargetNode->nNodeData &= ~nFlags;
    }
}
