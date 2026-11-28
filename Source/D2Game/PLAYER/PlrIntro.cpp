#include "D2Game.h"
#include "D2GameStrc.h"
#include "D2Primitives.h"
#include "D2GameAux.h"
#include "D2UnitData.h"
#include "D2LanguageNames.h"
#include "D2CommonApi.h"
#include "FogApi.h"

#pragma intrinsic(memcpy)

struct D2PoolSystemStrc;
struct D2BitBufferStrc;
struct D2NpcIndexMapStrc;
struct D2GameStrc;


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern D2NpcIndexMapStrc gaPlrIntroNpcIndexMap[]; // 0x00732738
void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
void __fastcall FOG_FreeServerMemory(D2PoolSystemStrc* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

// 0x00572330
int __fastcall PLRINTRO_GetNpcIndex(int nNpcId)
{
    for (int i = 0; i < gnPlrIntroNpcIndexMapCount; ++i)
    {
        if (gaPlrIntroNpcIndexMap[i].nNpcClassId == nNpcId)
        {
            return gaPlrIntroNpcIndexMap[i].nIndex;
        }
    }

    return 0;
}

// 0x00572360
void __fastcall PLRINTRO_SetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId)
{
    D2PlrIntroStrc* pPlayerIntro = UNITS_GetPlayerData(pUnit)->pPlayerIntro[pGame->nDifficulty];
    sub_00410B10(pPlayerIntro->pQuestIntroFlags->pBuffer, PLRINTRO_GetNpcIndex(nNpcId));
}

// 0x005723C0
int __fastcall PLRINTRO_GetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId)
{
    D2PlrIntroStrc* pPlayerIntro = UNITS_GetPlayerData(pUnit)->pPlayerIntro[pGame->nDifficulty];
    return sub_00410B30(pPlayerIntro->pQuestIntroFlags->pBuffer, PLRINTRO_GetNpcIndex(nNpcId));
}

// 0x00572420
void __fastcall PLRINTRO_SetNpcIntroFlag(D2PlrIntroStrc* pPlayerIntro, int nNpcId)
{
    sub_00410B10(pPlayerIntro->pNpcIntroFlags->pBuffer, PLRINTRO_GetNpcIndex(nNpcId));
}

// 0x00572470
int __fastcall PLRINTRO_GetNpcIntroFlag(D2PlrIntroStrc* pPlayerIntro, int nNpcId)
{
    return sub_00410B30(pPlayerIntro->pNpcIntroFlags->pBuffer, PLRINTRO_GetNpcIndex(nNpcId));
}

// 0x005724C0
void __fastcall PLRINTRO_MaskNpcIntroFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcId)
{
    D2PlrIntroStrc* pPlayerIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
    sub_00410B50(pPlayerIntro->pNpcIntroFlags->pBuffer, PLRINTRO_GetNpcIndex(nNpcId));
}

struct Pair00572520 { unsigned int dwFirst; unsigned int dwSecond; };

struct Mid00572520 { Pair00572520* pPair; };

struct Obj00572520 { Mid00572520* pMid; };

// 0x00572520
extern "C" __declspec(dllexport) void __fastcall PLRINTRO_CopyQuestIntroFlagsToBuffer(Obj00572520* pObj, Pair00572520* pOut) {
    *pOut = *pObj->pMid->pPair;
}

// 0x00572530
void __fastcall PLRINTRO_CopyNpcIntroFlagsToBuffer(D2PlrIntroStrc* pPlayerIntro, unsigned char* pBuffer)
{
    memcpy(pBuffer, pPlayerIntro->pNpcIntroFlags->pBuffer, 8);
}

// 0x00572540
void __fastcall PLRINTRO_CopyBufferToQuestIntroFlags(D2PlrIntroStrc* pPlayerIntro, unsigned char* pBuffer)
{
    memcpy(pPlayerIntro->pQuestIntroFlags->pBuffer, pBuffer, 8);
}

// 0x00572550
void __fastcall PLRINTRO_CopyBufferToNpcIntroFlags(D2PlrIntroStrc* pPlayerIntro, unsigned char* pBuffer)
{
    memcpy(pPlayerIntro->pNpcIntroFlags->pBuffer, pBuffer, 8);
}

// 0x00572560
D2PlrIntroStrc* __fastcall PLRINTRO_Create(D2GameStrc* pGame)
{
    D2PlrIntroStrc* pPlayerIntro = (D2PlrIntroStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2PlrIntroStrc), ".\\PLAYER\\PlrIntro.cpp", 196, 0);
    D2BitBufferStrc* pBitBuffer1 = (D2BitBufferStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2BitBufferStrc), ".\\PLAYER\\PlrIntro.cpp", 197, 0);
    unsigned char* pBuffer1 = (unsigned char*)FOG_AllocPool(pGame->pMemoryPool, 8, ".\\PLAYER\\PlrIntro.cpp", 198, 0);
    memset(pBuffer1, 0, 8);

    BITMANIP_Initialize(pBitBuffer1, pBuffer1, 8);
    pPlayerIntro->pQuestIntroFlags = pBitBuffer1;

    D2BitBufferStrc* pBitBuffer2 = (D2BitBufferStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2BitBufferStrc), ".\\PLAYER\\PlrIntro.cpp", 203, 0);
    unsigned char* pBuffer2 = (unsigned char*)FOG_AllocPool(pGame->pMemoryPool, 8, ".\\PLAYER\\PlrIntro.cpp", 204, 0);
    memset(pBuffer2, 0, 8);

    BITMANIP_Initialize(pBitBuffer2, pBuffer2, 8);
    pPlayerIntro->pNpcIntroFlags = pBitBuffer2;

    return pPlayerIntro;
}

// 0x00572620
void __fastcall PLRINTRO_Destroy(D2GameStrc* pGame, D2PlrIntroStrc* pPlayerIntro)
{
    if (pPlayerIntro->pQuestIntroFlags)
    {
        FOG_FreeServerMemory(pGame->pMemoryPool, pPlayerIntro->pQuestIntroFlags->pBuffer, ".\\PLAYER\\PlrIntro.cpp", 219, 0);
        FOG_FreeServerMemory(pGame->pMemoryPool, pPlayerIntro->pQuestIntroFlags, ".\\PLAYER\\PlrIntro.cpp", 220, 0);
        pPlayerIntro->pQuestIntroFlags = 0;
    }

    if (pPlayerIntro->pNpcIntroFlags)
    {
        FOG_FreeServerMemory(pGame->pMemoryPool, pPlayerIntro->pNpcIntroFlags->pBuffer, ".\\PLAYER\\PlrIntro.cpp", 225, 0);
        FOG_FreeServerMemory(pGame->pMemoryPool, pPlayerIntro->pNpcIntroFlags, ".\\PLAYER\\PlrIntro.cpp", 226, 0);
        pPlayerIntro->pNpcIntroFlags = 0;
    }

    FOG_FreeServerMemory(pGame->pMemoryPool, pPlayerIntro, ".\\PLAYER\\PlrIntro.cpp", 229, 0);
}

extern int gnPlrIntroNpcIndexMapCount = 35; // 0x00732734

extern D2NpcIndexMapStrc gaPlrIntroNpcIndexMap[35] = {
    { -1 },
    { 147, 1 },
    { 148, 2 },
    { 150, 3 },
    { 155, 4 },
    { 154, 5 },
    { 265, 6 },
    { 175, 7 },
    { 176, 8 },
    { 177, 9 },
    { 178, 10 },
    { 202, 11 },
    { 200, 12 },
    { 210, 13 },
    { 201, 14 },
    { 198, 15 },
    { 199, 16 },
    { 244, 17 },
    { 245, 18 },
    { 246, 19 },
    { 251, 20 },
    { 252, 21 },
    { 253, 22 },
    { 254, 23 },
    { 255, 24 },
    { 256, 25 },
    { 257, 26 },
    { 264, 27 },
    { 297, 28 },
    { 511, 29 },
    { 512, 30 },
    { 513, 31 },
    { 514, 32 },
    { 515, 33 },
    { 520, 34 }
}; // 0x00732738
