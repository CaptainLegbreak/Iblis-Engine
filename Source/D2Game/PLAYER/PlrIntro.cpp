#include "D2Game.h"
#include "D2GameStrc.h"
#include "D2Primitives.h"
#include "D2GameAux.h"
#include "D2UnitData.h"
#include "D2LanguageNames.h"

#pragma intrinsic(memcpy)

struct D2BitBufferStrc;
struct D2NpcIndexMapStrc;
struct D2GameStrc;


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern D2NpcIndexMapStrc gaPlrIntroNpcIndexMap[]; // 0x00732738
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __stdcall sub_00410B10(unsigned char* pBitBuffer, int nBit); // 0x00410B10
int __stdcall sub_00410B30(unsigned char* pBitBuffer, int nBit); // 0x00410B30
void __stdcall sub_00410B50(unsigned char* pBitBuffer, int nBit); // 0x00410B50
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize); // 0x00410E40
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

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
    D2PlrIntroStrc* pPlayerIntro = (D2PlrIntroStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2PlrIntroStrc), ".\\PLAYER\\PlrIntro.cpp", 196, 0);
    D2BitBufferStrc* pBitBuffer1 = (D2BitBufferStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2BitBufferStrc), ".\\PLAYER\\PlrIntro.cpp", 197, 0);
    unsigned char* pBuffer1 = (unsigned char*)sub_0040B430(pGame->pMemoryPool, 8, ".\\PLAYER\\PlrIntro.cpp", 198, 0);
    memset(pBuffer1, 0, 8);

    BITMANIP_Initialize(pBitBuffer1, pBuffer1, 8);
    pPlayerIntro->pQuestIntroFlags = pBitBuffer1;

    D2BitBufferStrc* pBitBuffer2 = (D2BitBufferStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2BitBufferStrc), ".\\PLAYER\\PlrIntro.cpp", 203, 0);
    unsigned char* pBuffer2 = (unsigned char*)sub_0040B430(pGame->pMemoryPool, 8, ".\\PLAYER\\PlrIntro.cpp", 204, 0);
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

#include "gen/data/Source/D2Game/PLAYER/PlrIntro.inc"
