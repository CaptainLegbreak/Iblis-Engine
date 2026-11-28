#include "D2CmpTypes.h"
#include "FogApi.h"
struct D2CmpRawFrameStrc
{
    int unk0x00;
    D2CmpRawFrameStrc* pNext;
    int nFlip;
    int nWidth;
    int nHeight;
    int unk0x14;
    int nOffsetX;
    int nOffsetY;
    void* pData;
};

struct D2CmpRawStrc
{
    char unk0x00[0x24];
    unsigned int nFrames;
    unsigned int nDirections;
    char unk0x2C[0x08];
    D2CmpRawFrameStrc* pFirst;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
int __stdcall CelGameDirToFileDir(int nDirection, unsigned int nDirections);                   // 0x00600C90

// 0x0060D190
void __fastcall RawBuildCelFile(D2CmpRawStrc* pRaw, D2CmpDC6HeaderStrc* pDC6)
{
    unsigned int nPerDir = pRaw->nFrames / pRaw->nDirections;
    unsigned int nFrame = 0;

    for (D2CmpRawFrameStrc* pRawFrame = (D2CmpRawFrameStrc*)((((int)pRaw->pFirst <= 0) - 1) & (int)pRaw->pFirst);
         (int)pRawFrame > 0; pRawFrame = pRawFrame->pNext)
    {
        unsigned int nLength = pRawFrame->nWidth * pRawFrame->nHeight * 3;
        D2CmpDC6FrameStrc* pFrame = (D2CmpDC6FrameStrc*)FOG_Alloc(nLength + 0x23, ".\\SRC\\Raw.cpp", 0x22, 0);
        pFrame->nFlip = pRawFrame->nFlip;
        pFrame->nWidth = pRawFrame->nWidth;
        pFrame->nHeight = pRawFrame->nHeight;
        pFrame->nOffsetX = pRawFrame->nOffsetX;
        pFrame->nOffsetY_10 = pRawFrame->nOffsetY;
        pFrame->nOffsetY_14 = 0;
        pFrame->pCel = 0;
        pFrame->nLength = nLength;
        memcpy(pFrame->pPixels, pRawFrame->pData, nLength);

        unsigned int nDirections = pRaw->nDirections;
        int nDirection;
        if (nDirections > 1)
        {
            nDirection = ((nFrame / nPerDir) << 6) / nDirections;
        }
        else
        {
            nDirection = 1;
        }

        int nIndex = CelGameDirToFileDir(nDirection, nDirections);
        pDC6->pFrames[nIndex * nPerDir + nFrame % nPerDir] = pFrame;
        ++nFrame;
    }
}
