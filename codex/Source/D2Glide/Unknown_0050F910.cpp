#include "D2Glide.h"

#include "D2GfxTypes.h"

#include "D2GlideTypes.h"

#include "D2Win32Types.h"

extern int gbRenderPaused; // 0x007C9144
extern int gnRenderWidth; // 0x007C9138

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern "C" __declspec(dllimport) long __stdcall DispatchMessageA(const tagMSG* pMsg); // 0x006CC478
int __cdecl FOG_UseDirect(); // 0x00406D20
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(tagMSG* pMsg, void* hWnd, unsigned int uMsgFilterMin, unsigned int uMsgFilterMax, unsigned int wRemoveMsg); // 0x006CC480
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const tagMSG* pMsg); // 0x006CC47C
extern void (__stdcall* gpfnGrTexDownloadMipMap)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo); // 0x0087EAB8
extern void (__stdcall* gpfnGrTexSource)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo); // 0x0087EB98

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2DDrawSurfaceStrc;

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void __fastcall GLCORE_SetTextureCombineMode(int nTmu); // 0x00509460

void __fastcall GLSUBTILECACHE_TileCacheTouch(D2GlideTileCacheStrc* pCache, int nIndex); // 0x0050F0F0

short __fastcall GLSUBTILECACHE_TileCacheAdd(D2GlideTileCacheStrc* pCache); // 0x0050F2B0

extern D2GrTexInfoStrc gtGlideTileTexInfo; // 0x0072F6A8

extern D2GlideTileCacheStrc gtGlideTileCache; // 0x0087EB48

extern int gnGlideTileTmu; // 0x00880BF8

extern unsigned char* gpGlideTileDecodeBuffer; // 0x00880BFC

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) D2BinkStrc* __stdcall BinkOpen(void* hFile, unsigned int nFlags); // 0x006CC5B8

extern "C" __declspec(dllimport) int __stdcall BinkWait(D2BinkStrc* pBink); // 0x006CC5C8

extern "C" __declspec(dllimport) void __stdcall BinkClose(D2BinkStrc* pBink); // 0x006CC5CC

extern "C" __declspec(dllimport) unsigned int __stdcall BinkDDSurfaceType(D2DDrawSurfaceStrc* pSurface); // 0x006CC5D0

extern "C" __declspec(dllimport) int __stdcall BinkSetSoundSystem(void* pfOpen, unsigned long nParam); // 0x006CC5D4

extern "C" __declspec(dllimport) void* __stdcall BinkOpenDirectSound(unsigned long nParam); // 0x006CC5D8

int __stdcall SFileOpenFileEx(unsigned int hMpq, const char* szFileName, unsigned int dwFlags, void** phFile); // 0x004192F0

void __cdecl GLIDE_DrawVideoFrame(); struct D2CriticalSectionStrc;
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall BinkNextFrame(D2BinkStrc* pBink); // 0x006CC5BC
extern "C" __declspec(dllimport) int __stdcall BinkCopyToBuffer(D2BinkStrc* pBink, void* pDest, int nDestPitch, unsigned int nDestHeight, unsigned int nDestX, unsigned int nDestY, unsigned int nFlags); // 0x006CC5C0
extern "C" __declspec(dllimport) int __stdcall BinkDoFrame(D2BinkStrc* pBink); // 0x006CC5C4
extern int (__stdcall* gpfnGrLfbLock)(int nType, int nBuffer, int nWriteMode, int nOrigin, int bPixelPipeline, D2GrLfbInfoStrc* pInfo); // 0x0087EADC
extern int (__stdcall* gpfnGrLfbUnlock)(int nType, int nBuffer); // 0x0087EAD8
extern D2CriticalSectionStrc* gpRenderCriticalSection; // 0x007C9134
extern int gbSurfaceActive_007C9140; // 0x007C9140

// 0x0050FD10

void __cdecl DDRAW_DrawVideoFrame(); // 0x005136F0

void __fastcall D2SOUNDSMP_SetMasterVolume(int nVolume); // 0x00515CE0

extern int gnRenderHeight; // 0x007C913C

extern unsigned int gnGlideBinkY; // 0x00880C04

extern unsigned int gnGlideBinkFlags; // 0x00880C14

extern D2DDrawSurfaceStrc* gpDDrawPrimarySurface; // 0x00881278

extern unsigned int gnDDrawBinkY; // 0x008816B8

extern unsigned int gnDDrawBinkFlags; // 0x008816C8

void __fastcall DDCORE_SetPalette(tagPALETTEENTRY* pPalette); // 0x00510160

extern D2PaletteTableStrc* gpGfxPaletteView_007C9150; // 0x007C9150

extern tagPALETTEENTRY gaDDrawSavedPalette[256]; // 0x00880D40

// 0x0050F910
static void sub_0050F910_DecodeTileRuns(const unsigned char* pData, unsigned char* pDst)
{
    int nRows = 0x20;
    unsigned char* pRow = pDst;
    unsigned char* p = pDst;
    const unsigned char* pSrc = pData;
    memset(pDst, 0, 0x400);

    do
    {
        const unsigned char nGap = *pSrc++;
        unsigned char nCount = *pSrc++;
        if (!nGap && !nCount)
        {
            --nRows;
            pRow += 0x20;
            p = pRow;
        }
        else
        {
            p += nGap;
            while (nCount--)
            {
                *p++ = *pSrc++;
            }
        }
    }
    while (nRows);
}

D2GlideTileCacheStrc gtGlideTileCache; // 0x0087EB48

int gnGlideTileTmu; // 0x00880BF8

// 0x0050FBD0
void __fastcall sub_0050FBD0_GlideBindTileTexture(D2GlideTileStrc* pTile)
{
    D2_ASSERT(pTile->nCacheIndex >= 0, 0x105);

    int nTexAddress;
    if (pTile->nCacheIndex == 0)
    {
        sub_0050F910_DecodeTileRuns(pTile->pData, gpGlideTileDecodeBuffer);
        pTile->nCacheIndex = GLSUBTILECACHE_TileCacheAdd(&gtGlideTileCache);
        const int nEntry = pTile->nCacheIndex - 1;
        D2_ASSERT(nEntry >= 0, 0x112);
        D2_ASSERT(nEntry < gtGlideTileCache.nCount, 0x113);
        gtGlideTileCache.pEntries[pTile->nCacheIndex - 1].pTile = pTile;
        nTexAddress = gtGlideTileCache.pEntries[pTile->nCacheIndex - 1].nAddress;
// build: symbol ?gpfnGrTexDownloadMipMap@* 0x0087EAB8
        gpfnGrTexDownloadMipMap(gnGlideTileTmu, nTexAddress, 3, &gtGlideTileTexInfo);
    }
    else
    {
        GLSUBTILECACHE_TileCacheTouch(&gtGlideTileCache, pTile->nCacheIndex);
        nTexAddress = gtGlideTileCache.pEntries[pTile->nCacheIndex - 1].nAddress;
    }

// build: symbol ?gpfnGrTexSource@* 0x0087EB98
    gpfnGrTexSource(gnGlideTileTmu, nTexAddress, 3, &gtGlideTileTexInfo);
    GLCORE_SetTextureCombineMode(gnGlideTileTmu);
}

#include "gen/data/Source/D2Glide/Unknown_0050F910.inc"

unsigned int gnGlideBinkX; // 0x00880C08

D2BinkStrc* gpGlideBink; // 0x00880C0C

int gbGlideBinkDone; // 0x00880C18

unsigned long gdwGlideBinkAbortTick; // 0x00880C1C

// 0x0050FD10
void __cdecl GLIDE_DrawVideoFrame()
{
    if (!gbSurfaceActive_007C9140)
        return;
    BinkDoFrame(gpGlideBink);
    D2_ASSERT(gpRenderCriticalSection, 0x39);
    EnterCriticalSection(gpRenderCriticalSection);
    D2GrLfbInfoStrc info = { sizeof(D2GrLfbInfoStrc) };
    if (gpfnGrLfbLock(1, 0, 5, 0, 0, &info))
    {
        BinkCopyToBuffer(gpGlideBink, info.lfbPtr, info.strideInBytes, gpGlideBink->nHeight, gnGlideBinkX, gnGlideBinkY, gnGlideBinkFlags);
        gpfnGrLfbUnlock(1, 0);
    }
    LeaveCriticalSection(gpRenderCriticalSection);
    if (gpGlideBink->nFrameNum == gpGlideBink->nFrames)
    {
        gbGlideBinkDone = 1;
        return;
    }
    BinkNextFrame(gpGlideBink);
}

// 0x0050FDF0
void __fastcall sub_0050FDF0_GlidePlayVideoFile(const char* szFile, int nMode, void (__cdecl* pfCallback)())
{
    int bAbort = 0;
    gbGlideBinkDone = 0;
    if (gpGlideBink)
    {
        return;
    }
// build: symbol ?gbRenderPaused@* 0x007C9144
    if (gbRenderPaused)
    {
        return;
    }

    gnGlideBinkFlags = 2;
    BinkSetSoundSystem(BinkOpenDirectSound, 0);
    int nScope = 4;
// build: symbol ?FOG_UseDirect@* 0x00406D20
    if (FOG_UseDirect())
    {
        nScope = 5;
    }

    void* hFile;
    SFileOpenFileEx(0, szFile, nScope, &hFile);
    if (!hFile)
    {
        goto OpenFailed;
    }

    unsigned int nFlags;
    nFlags = 0x800000;
    switch (nMode)
    {
    case 1:
        nFlags = 0x30800000;
        break;
    case 2:
        nFlags = 0x10800000;
        break;
    case 3:
        nFlags = 0x40800000;
        break;
    }
    gpGlideBink = BinkOpen(hFile, nFlags);
    if (!gpGlideBink)
    {
        CloseHandle(hFile);
OpenFailed:
        if (gpGlideBink)
        {
            BinkClose(gpGlideBink);
            gpGlideBink = 0;
        }
        return;
    }

// build: symbol ?gnRenderWidth@* 0x007C9138
    gnGlideBinkX = (gnRenderWidth - gpGlideBink->nWidth) >> 1;
    if (gnGlideBinkX & 3)
    {
        gnGlideBinkX = (gnGlideBinkX | 3) + 1;
    }
    gnGlideBinkY = (gnRenderHeight - gpGlideBink->nHeight) >> 1;
    {
        const unsigned long dwEnd = GetTickCount() + 500;
        for (;;)
        {
            if (gbGlideBinkDone && GetTickCount() >= dwEnd)
            {
                break;
            }
            if (gbRenderPaused)
            {
                break;
            }
            if (pfCallback)
            {
                pfCallback();
            }
            if (bAbort)
            {
                break;
            }

            tagMSG tMsg;
            if (PeekMessageA(&tMsg, 0, 0, 0, 1))
            {
                switch (tMsg.message)
                {
                case 0x12:
                    gbGlideBinkDone = 1;
                    break;
                case 0x102:
                case 0x201:
                case 0x204:
                case 0x207:
                    bAbort = 1;
                    gdwGlideBinkAbortTick = GetTickCount();
                    break;
                }
                TranslateMessage(&tMsg);
                DispatchMessageA(&tMsg);
            }
            else if (!BinkWait(gpGlideBink))
            {
                GLIDE_DrawVideoFrame();
            }
            else
            {
                Sleep(1);
            }
        }
    }

    if (gpGlideBink)
    {
        D2SOUNDSMP_SetMasterVolume(0);
        BinkClose(gpGlideBink);
        CloseHandle(hFile);
        D2SOUNDSMP_SetMasterVolume(0xFF);
        gpGlideBink = 0;
    }
}

