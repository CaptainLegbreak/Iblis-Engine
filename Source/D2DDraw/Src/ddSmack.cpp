#include "D2DDraw.h"

#include "D2GfxTypes.h"
#include "StormApi.h"
#include "StormApi2.h"

extern "C" __declspec(dllimport) int __stdcall SmackWait(D2SmackStrc* hSmack);                             // 0x006CC5F8

extern "C" __declspec(dllimport) void __stdcall SmackDoFrame(D2SmackStrc* hSmack);                         // 0x006CC5FC

extern "C" __declspec(dllimport) void __stdcall SmackNextFrame(D2SmackStrc* hSmack);                       // 0x006CC600


unsigned char gabDDrawSmackRemap[256];                                                                  // 0x008815B0

extern unsigned char* gpRemapSource_008816B0;                                                               // 0x008816B0

int gbDDrawSmackRemapReady;                                                                                  // 0x008816B4

extern unsigned char gabGamePalette_007C8CC8[];                                                             // 0x007C8CC8

static void __stdcall DDSMACK_RemapRows(int nWidth, D2SmackRecordStrc* pRect, unsigned int nRows); // 0x00513380

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern "C" __declspec(dllimport) D2SmackStrc* __stdcall SmackOpen(const char* szName, unsigned int nFlags, unsigned int nExtraBuf); // 0x006CC604

extern "C" __declspec(dllimport) void __stdcall SmackToBuffer(void* hSmack, unsigned int nLeft, unsigned int nTop, unsigned int nPitch, unsigned int nHeight, void* pBuffer, unsigned int nFlags); // 0x006CC60C

int __stdcall SBmpDecodeImage(int nMode, void* pData, int nSize, tagPALETTEENTRY* pPalette, unsigned char* pDest, int nDestSize, int* pWidth, int* pHeight, int* pDepth); // 0x006C6A80

extern tagPALETTEENTRY gatGamePalette[256];                                                     // 0x007C8CC8

extern unsigned char gabDDrawSmackRemap[256];                                                       // 0x008815B0

extern int gbDDrawSmackRemapReady;                                                                 // 0x008816B4

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
        gbDDrawSmackRemapReady = 0;
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
            gabDDrawSmackRemap[i] = GetClosestColor((const unsigned char*)gatGamePalette, 256, aPalette[i].peRed, aPalette[i].peGreen, aPalette[i].peBlue);
        }
        return;
    }

    default:
        return;
    }

    DDSMACK_CloseSmacker(pRecord);
}

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

extern "C" const char gData_006DE20C[452] = { // 0x006DE20C
    '.', '\\', 'S', 'r', 'c', '\\', 'd', 'd', 'S', 'm', 'a', 'c', 'k', '.', 'c', 'p',
    'p', 0, 0, 0, 7, 'c', -11, 'S', -65, -74, -48, 17, -108, -14, 0, -96,
    -55, 30, -5, -117, 8, 'c', -11, 'S', -65, -74, -48, 17, -108, -14, 0, -96,
    -55, 30, -5, -117, 10, 'c', -11, 'S', -65, -74, -48, 17, -108, -14, 0, -96,
    -55, 30, -5, -117, 11, 'c', -11, 'S', -65, -74, -48, 17, -108, -14, 0, -96,
    -55, 30, -5, -117, 12, 'c', -11, 'S', -65, -74, -48, 17, -108, -14, 0, -96,
    -55, 30, -5, -117, 13, 'c', -11, 'S', -65, -74, -48, 17, -108, -14, 0, -96,
    -55, 30, -5, -117, 16, 'c', -11, 'S', -65, -74, -48, 17, -108, -14, 0, -96,
    -55, 30, -5, -117, 17, 'c', -11, 'S', -65, -74, -48, 17, -108, -14, 0, -96,
    -55, 30, -5, -117, 18, 'c', -11, 'S', -65, -74, -48, 17, -108, -14, 0, -96,
    -55, 30, -5, -117, '`', -2, -52, '*', '0', -63, -46, 17, -80, -126, 0, -96,
    -55, 30, -5, -117, -32, -47, -32, -122, -119, -128, -48, 17, -100, -28, 8, 0,
    '>', '0', 31, 's', 'x', -23, '6', 'M', '%', -29, -50, 17, -65, -63, 8, 0,
    '+', -31, 3, 24, -61, -94, 'R', 'X', '0', 'e', -47, 17, -74, -93, 0, 0,
    -8, 'u', '{', -7, -38, -82, -102, 'P', '9', 'V', -47, 17, -74, -95, 0, 0,
    -8, 'u', '{', -7, 'F', -39, -44, 'G', -24, 'b', -49, 17, -109, -68, 'D', 'E',
    'S', 'T', 0, 0, '?', -52, 1, '9', -75, -124, -92, 'O', -70, '5', -86, -127,
    'r', -72, -96, -101, -128, 7, '!', -80, -51, -119, -48, 17, -81, 8, 0, -96,
    -55, '%', -51, 22, 19, -84, -68, -28, -103, 127, 8, 'I', -102, -114, 't', -29,
    -65, '$', -74, -31, 12, '0', -92, -2, 'Y', 'y', 'G', 'A', -78, 'j', '#', 'w',
    -71, -25, -87, 29, 0, 0, -16, -34, 'm', -100, -19, 'G', -86, -15, 'M', -38,
    -113, '+', '\\', 3, 1, 0, -16, -34, 'm', -100, -19, 'G', -86, -15, 'M', -38,
    -113, '+', '\\', 3, 2, 0, -16, -34, 'm', -100, -19, 'G', -86, -15, 'M', -38,
    -113, '+', '\\', 3, 3, 0, -16, -34, 'm', -100, -19, 'G', -86, -15, 'M', -38,
    -113, '+', '\\', 3, -105, 'h', -88, 'V', -44, 10, -50, 17, -80, ':', 0, ' ',
    -81, 11, -89, 'p', -125, -6, -102, '\'', -127, 'I', -50, 17, -91, '!', 0, ' ',
    -81, 11, -27, '`', -123, -6, -102, '\'', -127, 'I', -50, 17, -91, '!', 0, ' ',
    -81, 11, -27, '`', -124, -6, -102, '\'', -127, 'I', -50, 17, -91, '!', 0, ' ',
    -81, 11, -27, '`'
};
#pragma comment(linker, "/alternatename:_gszDDSmackFile=_gData_006DE20C")
