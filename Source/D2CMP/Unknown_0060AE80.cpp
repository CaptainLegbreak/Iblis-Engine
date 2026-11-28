#include "D2CMP.h"

#include "D2CmpTypes.h"

#include "D2CmpCache.h"
#include "FogApi.h"
#include "FogApi2.h"

struct D2CmpBitCursorStrc;

struct D2CmpByteMapStrc;

struct D2CmpByteRunStrc;

struct D2DccFrameStrc;

struct D2DccDirStrc;

struct D2DccIterStrc;

struct D2BitBufferInitStrc;

struct D2SpritePixelsStrc;

struct D2SpriteCelStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2BitBufferInitStrc
{
    unsigned char* pBuffer;
    unsigned char* pCurrent;
    int nBits;
    int nPos;
};

struct D2SpritePixelsStrc { int unknown00,width,height; char unknown0C[0x14]; unsigned char* pixels; int pitch; int topDown; };

struct D2SpriteCelStrc { int unknown00[7]; unsigned int dataSize; };


void* __cdecl sub_006829C0_Copy(void* dest,const void* source,unsigned int size); // 0x006829C0


// 0x0060AE80
static unsigned int sub_0060AE80_GetCelDataHashKey(const char* szName)
{
    unsigned int nHash = SStrHash(szName, 1, 0);
    return ((nHash ^ (nHash >> 8)) ^ ((nHash ^ (nHash >> 8)) >> 16)) & 0x1FF;
}

unsigned int __fastcall sub_M383_Emit_0060AE80(int nAdd, const char* szName)
{
    return sub_0060AE80_GetCelDataHashKey(szName) + nAdd * 3;
}

// 0x0060B130
void __cdecl sub_0060B130_Nothing()
{
}

// 0x0060B160
static void __stdcall sub_0060B160_Copy(D2BitBufferInitStrc* dst,const D2BitBufferInitStrc* src) {
 dst->pBuffer=src->pBuffer;
 dst->pCurrent=src->pCurrent;
 dst->nBits=src->nBits;
 dst->nPos=src->nPos;
}

void __stdcall EmitCopy(D2BitBufferInitStrc* dst,const D2BitBufferInitStrc* src) {sub_0060B160_Copy(dst,src);}

// 0x0060B180
unsigned char* D2CmpBitCursorStrc::sub_0060B180_GetBytePtr()
{
    return (unsigned char*)pData + (nBitPos + 7) / 8;
}

// 0x0060B1D0
void D2CmpBitCursorStrc::sub_0060B1D0_AlignToByte()
{
    const unsigned int nPos = (nBitPos + 7) & ~7u;
    nBitPos = nPos & 0x1F;
    pData += nPos / 32;
}

// 0x0060B1F0
int D2CmpBitCursorStrc::sub_0060B1F0_GetBitPos()
{
    return (pData - pStart) * 32 + nBitPos;
}

// 0x0060B140
static void __stdcall sub_0060B140_BitBufferInit(int nSize, unsigned char* pBuffer, D2BitBufferInitStrc* pBitBuf)
{
    pBitBuf->pBuffer = pBuffer;
    pBitBuf->pCurrent = pBuffer;
    pBitBuf->nBits = nSize * 8;
    pBitBuf->nPos = 0;
}

void __stdcall sub_K13_Emit_0060B140(D2BitBufferInitStrc* pBitBuf, unsigned char* pBuffer, int nSize)
{
    sub_0060B140_BitBufferInit(nSize, pBuffer, pBitBuf);
}
