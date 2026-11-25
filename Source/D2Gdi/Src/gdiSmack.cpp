#include "D2Gdi.h"
#include "D2GfxTypes.h"
#include "D2Win32Types.h"


extern "C" __declspec(dllimport) void __stdcall SmackClose(D2SmackStrc* hSmack); // 0x006CC608
extern "C" __declspec(dllimport) int __stdcall SmackWait(D2SmackStrc* hSmack); // 0x006CC5F8
extern "C" __declspec(dllimport) void __stdcall SmackDoFrame(D2SmackStrc* hSmack); // 0x006CC5FC
extern "C" __declspec(dllimport) void __stdcall SmackNextFrame(D2SmackStrc* hSmack); // 0x006CC600
void __fastcall GDISMACK_GdiCloseSmacker(D2SmackRecordStrc* pRecord); // 0x006C9640
extern unsigned char* gpScreenBuffer_007C9154; // 0x007C9154
extern unsigned char gabGdiSmackPaletteMap[256]; // 0x0098A178
int gbRemapValid; // 0x0098A27C
extern unsigned char gabGamePalette_007C8CC8[]; // 0x007C8CC8
extern int gbSurfaceActive_007C9140; // 0x007C9140
extern int gbRenderPaused; // 0x007C9144
static void __stdcall GDISMACK_RemapRows(int nWidth, D2SmackRecordStrc* pRect, unsigned int nRows); // 0x006C9690

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" __declspec(dllimport) D2SmackStrc* __stdcall SmackOpen(const char* szName, unsigned int nFlags, unsigned int nExtraBuf); // 0x006CC604
extern "C" __declspec(dllimport) void __stdcall SmackToBuffer(D2SmackStrc* hSmack, unsigned int nLeft, unsigned int nTop, unsigned int nPitch, unsigned int nHeight, void* pBuffer, unsigned int nFlags); // 0x006CC60C
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
int __stdcall SFileLoadFileEx(void* hMpq, const char* szFileName, void** ppBuffer, int* pnSize, int nExtraBytes, int nFlags, void* pOverlapped); // 0x0041B680
int __stdcall SBmpDecodeImage(int nMode, void* pData, int nSize, tagPALETTEENTRY* pPalette, unsigned char* pDest, int nDestSize, int* pWidth, int* pHeight, int* pDepth); // 0x006C6A80

static unsigned char* gpGdiSmackBuffer; // 0x0098A278

// 0x006C9640
void __fastcall GDISMACK_GdiCloseSmacker(D2SmackRecordStrc* pRecord)
{
    if (gpGdiSmackBuffer)
    {
        FOG_Free(gpGdiSmackBuffer, ".\\Src\\gdiSmack.cpp", 0xF0, 0);
        gpGdiSmackBuffer = 0;
    }
    if (pRecord->nType == 's' && pRecord->pSmack)
    {
        SmackClose(pRecord->pSmack);
        pRecord->pSmack = 0;
    }
    pRecord->nType = 0;
}

static inline void sub_006C9690_RemapSpan(unsigned char* pDst, const unsigned char* pSrc, int nCount)
{
    while (nCount)
    {
        --nCount;
        *pDst++ = gabGdiSmackPaletteMap[*pSrc++];
    }
}

// 0x006C9690
static void __stdcall GDISMACK_RemapRows(int nWidth, D2SmackRecordStrc* pRect, unsigned int nRows)
{
    unsigned char* pSrc = gpGdiSmackBuffer;
// build: symbol ?gnRenderWidth@* 0x007C9138
    unsigned char* pDst = (pRect->nY - nRows) * gnRenderWidth + pRect->nX + gpScreenBuffer_007C9154;
    unsigned int nLeft = nRows;
    while (nLeft)
    {
        --nLeft;
        sub_006C9690_RemapSpan(pDst, pSrc, nWidth);
        pDst += gnRenderWidth;
        pSrc += nWidth;
    }
}

unsigned char gabGdiSmackPaletteMap[256]; // 0x0098A178

// 0x006C9710
void __fastcall GDISMACK_GdiDecodeSmacker(const char* szFile, D2SmackRecordStrc* pSmack, unsigned char nType)
{
    pSmack->nType = nType;
    switch (nType)
    {
    case 's':
    {
        if (pSmack->pSmack)
        {
            return;
        }
        D2SmackStrc* hSmack = SmackOpen(szFile, 0xFE000, -1);
        pSmack->pSmack = hSmack;
        if (!hSmack)
        {
            break;
        }
        gpGdiSmackBuffer = (unsigned char*)FOG_Alloc(hSmack->nWidth * hSmack->nHeight, ".\\Src\\gdiSmack.cpp", 67, 0);
        memset(gpGdiSmackBuffer, 0, hSmack->nWidth * hSmack->nHeight);
        SmackToBuffer(pSmack->pSmack, 0, 0, hSmack->nWidth, hSmack->nHeight, gpGdiSmackBuffer, 0);
        gbRemapValid = 0;
        return;
    }

    case 'p':
    {
        gpGdiSmackBuffer = (unsigned char*)FOG_Alloc(0x6DB0, ".\\Src\\gdiSmack.cpp", 81, 0);
        memset(gpGdiSmackBuffer, 0, 0x6DB0);

        void* pBuffer = 0;
        int nSize = 0;
        if (!SFileLoadFileEx(0, szFile, &pBuffer, &nSize, 0, 3, 0) || !pBuffer)
        {
            break;
        }

        tagPALETTEENTRY aPalette[256];
        int nWidth;
        int nHeight;
        int nDepth;
        const int bDecoded = SBmpDecodeImage(2, pBuffer, nSize, aPalette, gpGdiSmackBuffer, 0x6DB0, &nWidth, &nHeight, &nDepth);
        SMemFree(pBuffer, ".\\Src\\gdiSmack.cpp", 120, 0);
        if (!bDecoded || nWidth != 468 || nHeight != 60 || nDepth != 8)
        {
            break;
        }

        for (int i = 0; i < 256; ++i)
        {
            gabGdiSmackPaletteMap[i] = GetClosestColor(gabGamePalette_007C8CC8, 0x100, aPalette[i].peRed, aPalette[i].peGreen, aPalette[i].peBlue);
        }
        return;
    }

    default:
        return;
    }

    if (gpGdiSmackBuffer)
    {
        FOG_Free(gpGdiSmackBuffer, ".\\Src\\gdiSmack.cpp", 240, 0);
        gpGdiSmackBuffer = 0;
    }

    if (pSmack->nType == 's' && pSmack->pSmack)
    {
        SmackClose(pSmack->pSmack);
        pSmack->pSmack = 0;
    }
    pSmack->nType = 0;
}

// 0x006C9900
void __fastcall GDISMACK_PlaySmacker(D2SmackRecordStrc* pRecord)
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
                    gabGdiSmackPaletteMap[i] = GetClosestColor(gabGamePalette_007C8CC8, 256, hSmack->aPalette[i].nRed, hSmack->aPalette[i].nGreen, hSmack->aPalette[i].nBlue);
                }
                gbRemapValid = 1;
            }
            SmackDoFrame(hSmack);
            if (hSmack->nFrameNum == hSmack->nFrames)
                GDISMACK_GdiCloseSmacker(pRecord);
            else
                SmackNextFrame(hSmack);
        }
        if (gbRenderPaused)
            return;
        if (!gbRemapValid)
            return;
        GDISMACK_RemapRows(hSmack->nWidth, pRecord, hSmack->nHeight);
        return;
    }
    case 'p':
        if (!gbRenderPaused)
            GDISMACK_RemapRows(468, pRecord, 60);
        break;
    }
}
