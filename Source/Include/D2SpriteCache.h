#pragma once
struct D2PoolSystemStrc;
// D2CMP sprite cache: the cache record shared by SpriteCache and CelCmp.

#include "D2SysTypes.h"

struct D2SpriteCacheNodeStrc;

struct D2SpriteCacheStrc
{
    D2PoolSystemStrc* pMemPool; // 0x00
    unsigned int nMaxSize; // 0x04
    unsigned int nTotalSize; // 0x08
    unsigned int nCount; // 0x0C
    D2SpriteCacheNodeStrc* pNodes; // 0x10
    D2SpriteCacheNodeStrc* pHeadA; // 0x14
    D2SpriteCacheNodeStrc* pTailA; // 0x18
    D2SpriteCacheNodeStrc* pHeadB; // 0x1C
    D2SpriteCacheNodeStrc* pTailB; // 0x20
    D2SpriteCacheNodeStrc* pFreeHead; // 0x24
    D2SpriteCacheNodeStrc* pFreeTail; // 0x28
    int nArg; // 0x2C
    D2CriticalSectionStrc tLock; // 0x30
    unsigned int nHits; // 0x48
    unsigned int nRequests; // 0x4C
};
