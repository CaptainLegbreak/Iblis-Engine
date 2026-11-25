#include "D2DDraw.h"

#include "D2GfxTypes.h"

extern "C" __declspec(dllimport) int __stdcall SmackWait(D2SmackStrc* hSmack);                             // 0x006CC5F8

extern "C" __declspec(dllimport) void __stdcall SmackDoFrame(D2SmackStrc* hSmack);                         // 0x006CC5FC

extern "C" __declspec(dllimport) void __stdcall SmackNextFrame(D2SmackStrc* hSmack);                       // 0x006CC600

void __fastcall DDSMACK_CloseSmacker(D2SmackRecordStrc* pRecord);                                      // 0x00513330

unsigned char gabDDrawSmackRemap[256];                                                                  // 0x008815B0

extern unsigned char* gpRemapSource_008816B0;                                                               // 0x008816B0

int gbDDrawSmackRemapReady;                                                                                  // 0x008816B4

extern unsigned char gabGamePalette_007C8CC8[];                                                             // 0x007C8CC8

static void __stdcall DDSMACK_RemapRows(int nWidth, D2SmackRecordStrc* pRect, unsigned int nRows); // 0x00513380

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern "C" __declspec(dllimport) D2SmackStrc* __stdcall SmackOpen(const char* szName, unsigned int nFlags, unsigned int nExtraBuf); // 0x006CC604

extern "C" __declspec(dllimport) void __stdcall SmackToBuffer(void* hSmack, unsigned int nLeft, unsigned int nTop, unsigned int nPitch, unsigned int nHeight, void* pBuffer, unsigned int nFlags); // 0x006CC60C

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

int __stdcall SFileLoadFileEx(void* hMpq, const char* szFileName, void** ppBuffer, int* pnSize, int nExtraBytes, int nFlags, void* pOverlapped); // 0x0041B680

int __stdcall SBmpDecodeImage(int nMode, void* pData, int nSize, tagPALETTEENTRY* pPalette, unsigned char* pDest, int nDestSize, int* pWidth, int* pHeight, int* pDepth); // 0x006C6A80

extern tagPALETTEENTRY gatGamePalette[256];                                                     // 0x007C8CC8

extern unsigned char gaDDrawSmackRemap_008815B0[256];                                                       // 0x008815B0

extern int gbDDrawSmackRemapReady_008816B4;                                                                 // 0x008816B4

static void* gpDDrawSmackBuffer; // 0x008816B0

static inline void sub_00513380_RemapSpan(unsigned char* pDst, const unsigned char* pSrc, int nCount)
{
    while (nCount)
    {
        --nCount;
        *pDst++ = gabDDrawSmackRemap[*pSrc++];
    }
}

// 0x00513380
static void __stdcall DDSMACK_RemapRows(int nWidth, D2SmackRecordStrc* pRect, unsigned int nRows)
{
    if (!gpRemapSource_008816B0)
        return;
    unsigned char* pSrc = gpRemapSource_008816B0;
// build: symbol ?gnRenderWidth@* 0x007C9138
    unsigned char* pDst = (pRect->nY - nRows) * gnRenderWidth + pRect->nX + gpScreenBuffer_007C9154;
    unsigned int nLeft = nRows;
    while (nLeft)
    {
        --nLeft;
        sub_00513380_RemapSpan(pDst, pSrc, nWidth);
        pDst += gnRenderWidth;
        pSrc += nWidth;
    }
}

// 0x00513330
void __fastcall DDSMACK_CloseSmacker(D2SmackRecordStrc* pRecord)
{
    if (gpDDrawSmackBuffer)
    {
// build: symbol ?gszDDSmackFile@* 0x006DE20C
        FOG_Free(gpDDrawSmackBuffer, gszDDSmackFile, 0xF0, 0);
        gpDDrawSmackBuffer = 0;
    }
    if (pRecord->nType == 's' && pRecord->hSmack)
    {
        SmackClose(pRecord->hSmack);
        pRecord->hSmack = 0;
    }
}

// 0x00513400
void __fastcall DDSMACK_DecodeSmacker(const char* szFile, D2SmackRecordStrc* pRecord, unsigned char nType)
{
    pRecord->nType = nType;
    switch (nType)
    {
    case 's':
    {
        if (pRecord->hSmack)
        {
            return;
        }
        D2SmackStrc* pSmack = SmackOpen(szFile, 0xFE000, -1);
        pRecord->hSmack = pSmack;
        if (!pSmack)
        {
            break;
        }
        unsigned char* pBuffer = (unsigned char*)FOG_Alloc(pSmack->nWidth * pSmack->nHeight, gszDDSmackFile, 0x42, 0);
        gpDDrawSmackBuffer = pBuffer;
        memset(pBuffer, 0, pSmack->nWidth * pSmack->nHeight);
        SmackToBuffer(pRecord->hSmack, 0, 0, pSmack->nWidth, pSmack->nHeight, pBuffer, 0);
        gbDDrawSmackRemapReady_008816B4 = 0;
        return;
    }

    case 'p':
    {
        gpDDrawSmackBuffer = (unsigned char*)FOG_Alloc(0x6DB0, gszDDSmackFile, 0x53, 0);
        memset(gpDDrawSmackBuffer, 0, 0x6DB0);
        void* pData = 0;
        int nSize = 0;
        if (!SFileLoadFileEx(0, szFile, &pData, &nSize, 0, 3, 0) || !pData)
        {
            break;
        }

        tagPALETTEENTRY aPalette[256];
        int nHeight;
        int nDepth;
        int nWidth;
        const int bDecoded = SBmpDecodeImage(2, pData, nSize, aPalette, (unsigned char*)gpDDrawSmackBuffer, 0x6DB0, &nWidth, &nHeight, &nDepth);
        SMemFree(pData, gszDDSmackFile, 0x78, 0);
        if (!bDecoded || nWidth != 0x1D4 || nHeight != 0x3C || nDepth != 8)
        {
            break;
        }

        for (int i = 0; i < 256; ++i)
        {
            gaDDrawSmackRemap_008815B0[i] = GetClosestColor((const unsigned char*)gatGamePalette, 256, aPalette[i].peRed, aPalette[i].peGreen, aPalette[i].peBlue);
        }
        return;
    }

    default:
        return;
    }

    DDSMACK_CloseSmacker(pRecord);
}

unsigned char __stdcall GetClosestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210
extern int gbSurfaceActive_007C9140;                                                                        // 0x007C9140

// 0x005135F0
void __fastcall DDSMACK_PlaySmacker(D2SmackRecordStrc* pRecord)
{
    switch (pRecord->nType)
    {
    case 's':
    {
        D2SmackStrc* hSmack = pRecord->pSmack;
        if (!hSmack)
            return;
        if (!SmackWait(hSmack))
        {
            if (!gbSurfaceActive_007C9140)
                return;
            if (hSmack->bNewPalette)
            {
                for (int i = 0; i < 256; ++i)
                {
                    gabDDrawSmackRemap[i] = GetClosestColor(gabGamePalette_007C8CC8, 256, hSmack->aPalette[i].nRed, hSmack->aPalette[i].nGreen, hSmack->aPalette[i].nBlue);
                }
                gbDDrawSmackRemapReady = 1;
            }
            SmackDoFrame(hSmack);
            if (hSmack->nFrameNum == hSmack->nFrames)
                DDSMACK_CloseSmacker(pRecord);
            else
                SmackNextFrame(hSmack);
        }
// build: symbol ?gbRenderPaused@* 0x007C9144
        if (gbRenderPaused)
            return;
        if (!gbDDrawSmackRemapReady)
            return;
        DDSMACK_RemapRows(hSmack->nWidth, pRecord, hSmack->nHeight);
        return;
    }
    case 'p':
        if (!gbRenderPaused)
            DDSMACK_RemapRows(468, pRecord, 60);
        break;
    }
}

#include "gen/data/Source/D2DDraw/Src/ddSmack.inc"
