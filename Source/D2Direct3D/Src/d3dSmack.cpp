#include "D2Direct3D.h"
#include "D2DDrawTypes.h"
#include "D2Win32Types.h"
#include "FogApi.h"
#include "StormApi.h"
#include "StormApi2.h"

#define gnHandle_00989760 (gatVideoVertices[0].dwColor)

#define gnHandle_00989780 (gatVideoVertices[1].dwColor)

#define gnHandle_009897A0 (gatVideoVertices[2].dwColor)

#define gnHandle_009897C0 (gatVideoVertices[3].dwColor)

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

D2TLVertexStrc gatVideoVertices[4]; // 0x00989750

extern void* gpBuffer_009897D0; // 0x009897D0



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

// The smacker frame goes through two halves (0x100 x 0x40 each): a system-memory surface and its texture, which
// the decoder writes, and a device surface and its texture, which are drawn.
extern unsigned int gdwBitMasks[]; // 0x006CE268

D2DDSurfaceStrc* gapSmackSurfaces[2]; // 0x009897D4

D2D3DTextureStrc* gapSmackSourceTextures[2]; // 0x009897DC

D2DDSurfaceStrc* gapSmackDeviceSurfaces[2]; // 0x009897E4

D2D3DTextureStrc* gapSmackTextures[2]; // 0x009897EC

int __fastcall D3DCORE_CreateMemoryTexture(D2DDSurfaceStrc** ppSurface, D2D3DTextureStrc** ppTexture, int nWidth, int nHeight); // 0x006B3730

int __fastcall D3DCORE_CreateDeviceTexture(D2DDSurfaceStrc** ppSurface, D2D3DTextureStrc** ppTexture, int nWidth, int nHeight); // 0x006B58A0

void __fastcall D3DCORE_CopySurface(D2DDSurfaceStrc* pDst, D2DDSurfaceStrc* pSrc, int nRows); // 0x006B38A0

void __fastcall D3DSMACK_CloseSmacker(D2SmackRecordStrc* video); // 0x006B9BB0

void __cdecl D3DSMACK_UploadSmackTextures(); // 0x006B9BD0

extern D2D3DDeviceStrc* gpDevice_00970E78; // 0x00970E78




static void __stdcall D3DSMACK_CopySmackBlock(unsigned short* pSource, unsigned short* pDest, int nDestPitch); // 0x006B9EB0

extern "C" const char gszFailedToUnlockMemorySurface[]; // 0x006FC284

extern "C" const char gszFailedToLockMemorySurface[]; // 0x006FC2A4

void __fastcall D3DCORE_LogDDrawError(const char* szWhere, int hResult); // 0x006B20E0

static void __stdcall sub_006B9EB0_CopyWithAlpha(const unsigned short* pSrc, unsigned char* pDst, int nPitch);

extern "C" __declspec(dllimport) void* __stdcall SmackOpen(const char* szName, unsigned int nFlags, unsigned int nExtraBuf); // 0x006CC604

extern "C" __declspec(dllimport) void __stdcall SmackClose(void* hSmack); // 0x006CC608

extern "C" __declspec(dllimport) void __stdcall SmackToBuffer(void* hSmack, unsigned int nLeft, unsigned int nTop, unsigned int nPitch, unsigned int nHeight, void* pBuffer, unsigned int nFlags); // 0x006CC60C

int __stdcall SBmpDecodeImage(int nMode, void* pData, int nSize, tagPALETTEENTRY* pPalette, unsigned char* pDest, int nDestSize, int* pWidth, int* pHeight, int* pDepth); // 0x006C6A80

void __cdecl D3DSMACK_UploadSmackFrameBuffer(); // 0x006B9F00

extern "C" const char gszD3DSmackFile[]; // 0x006FC358

extern unsigned short* gpD3DSmackBuffer_009897D0; // 0x009897D0

extern "C" void* gpSmackFrameBuffer; // 0x009897D0

// 0x006B9A10
void __cdecl D3DSMACK_SmackInit()
{
    gnHandle_00989760 = -1;
    gnHandle_00989780 = -1;
    gnHandle_009897A0 = -1;
    gnHandle_009897C0 = -1;
    gpBuffer_009897D0 = FOG_Alloc(0x10000, ".\\Src\\d3dSmack.cpp", 0x38, 0);
    memset(gpBuffer_009897D0, 0, 0x10000);
}

// 0x006B9A50
char* __fastcall D3DSMACK_CreateSmackSurfaces(char* pBuffer)
{
    for (int i = 0; i < 2; ++i)
    {
        D2DDSurfaceStrc** ppFirst = &gapSmackSurfaces[i];
        D2D3DTextureStrc** ppSecond = &gapSmackSourceTextures[i];
        D3DCORE_CreateMemoryTexture(ppFirst, ppSecond, 256, 64);
        D2_ASSERT(*ppFirst, 0x4A);
        D2_ASSERT(*ppSecond, 0x4B);
        ppFirst = &gapSmackDeviceSurfaces[i];
        ppSecond = &gapSmackTextures[i];
        int nResult = D3DCORE_CreateDeviceTexture(ppFirst, ppSecond, 256, 64);
        D2_ASSERT(*ppFirst, 0x4E);
        D2_ASSERT(*ppSecond, 0x4F);
        D2_ASSERT(nResult, 0x50);
    }
    return pBuffer + 0x10000;
}

// 0x006B9B30
void __cdecl D3DSMACK_ReleaseSmackSurfaces()
{
    for (int i = 0; i < 2; ++i)
    {
        RELEASE(gapSmackSourceTextures[i]);
        RELEASE(gapSmackSurfaces[i]);
        RELEASE(gapSmackTextures[i]);
        RELEASE(gapSmackDeviceSurfaces[i]);
    }
}

// 0x006B9BB0
void __fastcall D3DSMACK_CloseSmacker(D2SmackRecordStrc* pRecord)
{
    if (pRecord->nType == 's' && pRecord->hSmack)
    {
        SmackClose(pRecord->hSmack);
        pRecord->hSmack = 0;
    }
}

// 0x006B9BD0
void __cdecl D3DSMACK_UploadSmackTextures()
{
    if (gapSmackSurfaces[0])
    {
        if (gnRenderFlags_0096F3A8 & gdwBitMasks[10])
        {
            D3DCORE_CopySurface(gapSmackDeviceSurfaces[0], gapSmackSurfaces[0], 0x40);
            D3DCORE_CopySurface(gapSmackDeviceSurfaces[1], gapSmackSurfaces[1], 0x40);
        }
        else
        {
            gapSmackTextures[0]->lpVtbl->Load(gapSmackTextures[0], gapSmackSourceTextures[0]);
            gapSmackTextures[1]->lpVtbl->Load(gapSmackTextures[1], gapSmackSourceTextures[1]);
        }
    }
}

// 0x006B9C40
static void __stdcall D3DSMACK_DrawSmackFrame(D2SmackRecordStrc* video, int width, int height)
{
    const int top = video->nY - height;
    const int bottom = video->nY;
    D3DCORE_SetColorCombineMode(1);
    D3DCORE_SetAlphaBlendMode(1);
    D3DCORE_SetTextureFilterMode(1);

    int x = video->nX;
    int right = x + 256;
    gatVideoVertices[0].fX = (float)x;
    gatVideoVertices[0].fY = (float)top;
    gatVideoVertices[0].fZ = 0.5f;
    gatVideoVertices[0].fRhw = 1.0f;
    gatVideoVertices[0].fU = 0.0f;
    gatVideoVertices[0].fV = 0.0f;
    gatVideoVertices[1].fX = (float)x;
    gatVideoVertices[1].fY = (float)bottom;
    gatVideoVertices[1].fZ = 0.5f;
    gatVideoVertices[1].fRhw = 1.0f;
    gatVideoVertices[1].fU = 0.0f;
    gatVideoVertices[1].fV = 1.0f;
    gatVideoVertices[2].fX = (float)right;
    gatVideoVertices[2].fY = (float)bottom;
    gatVideoVertices[2].fZ = 0.5f;
    gatVideoVertices[2].fRhw = 1.0f;
    gatVideoVertices[2].fU = 1.0f;
    gatVideoVertices[2].fV = 1.0f;
    gatVideoVertices[3].fX = (float)right;
    gatVideoVertices[3].fY = (float)top;
    gatVideoVertices[3].fZ = 0.5f;
    gatVideoVertices[3].fRhw = 1.0f;
    gatVideoVertices[3].fU = 1.0f;
    gatVideoVertices[3].fV = 0.0f;
    gpDevice_00970E78->lpVtbl->SetTexture(gpDevice_00970E78, 0, gapSmackTextures[0]);
    gpDevice_00970E78->lpVtbl->DrawPrimitive(gpDevice_00970E78, 6, 0x1C4, gatVideoVertices, 4, 0x1C);

    x += 256;
    right = x + width - 256;
    const float u = (float)((width - 256) * (1.0 / 256.0));
    gatVideoVertices[0].fX = (float)x;
    gatVideoVertices[0].fY = (float)top;
    gatVideoVertices[0].fZ = 0.5f;
    gatVideoVertices[0].fRhw = 1.0f;
    gatVideoVertices[0].fU = 0.0f;
    gatVideoVertices[0].fV = 0.0f;
    gatVideoVertices[1].fX = (float)x;
    gatVideoVertices[1].fY = (float)bottom;
    gatVideoVertices[1].fZ = 0.5f;
    gatVideoVertices[1].fRhw = 1.0f;
    gatVideoVertices[1].fU = 0.0f;
    gatVideoVertices[1].fV = 1.0f;
    gatVideoVertices[2].fX = (float)right;
    gatVideoVertices[2].fY = (float)bottom;
    gatVideoVertices[2].fZ = 0.5f;
    gatVideoVertices[2].fRhw = 1.0f;
    gatVideoVertices[2].fU = u;
    gatVideoVertices[2].fV = 1.0f;
    gatVideoVertices[3].fX = (float)right;
    gatVideoVertices[3].fY = (float)top;
    gatVideoVertices[3].fZ = 0.5f;
    gatVideoVertices[3].fRhw = 1.0f;
    gatVideoVertices[3].fU = u;
    gatVideoVertices[3].fV = 0.0f;
    gpDevice_00970E78->lpVtbl->SetTexture(gpDevice_00970E78, 0, gapSmackTextures[1]);
    gpDevice_00970E78->lpVtbl->DrawPrimitive(gpDevice_00970E78, 6, 0x1C4, gatVideoVertices, 4, 0x1C);
}

// 0x006BA390
void __fastcall D3DSMACK_PlaySmacker(D2SmackRecordStrc* video)
{
    switch (video->nType)
    {
    case 's':
        {
            D2SmackStrc* smack = (D2SmackStrc*)video->hSmack;
            if (smack)
            {
                if (!SmackWait(smack))
                {
                    if (!ghDDrawWindow_007C9140)
                        return;
                    SmackDoFrame(smack);
                    sub_006B9F00_PresentFrame();
                    if (smack->nFrameNum == smack->nFrames)
                        D3DSMACK_CloseSmacker(video);
                    else
                        SmackNextFrame(smack);
                    if (gbRenderPaused)
                        return;
                    D3DSMACK_UploadSmackTextures();
                }
                if (!gbRenderPaused)
                    D3DSMACK_DrawSmackFrame(video, smack->nWidth, smack->nHeight);
            }
        }
        break;
    case 'p':
        if (!gbRenderPaused)
            D3DSMACK_DrawSmackFrame(video, 468, 60);
        break;
    }
}

// 0x006B9EB0
static void __stdcall D3DSMACK_CopySmackBlock(unsigned short* pSource, unsigned short* pDest, int nDestPitch)
{
    for (unsigned int nRow = 64; nRow; --nRow)
    {
        const unsigned short* pIn = pSource;
        const int nDelta = (char*)pDest - (char*)pSource;
        for (unsigned int i = 256; i; --i)
        {
            *(unsigned short*)((char*)pIn + nDelta) = *pIn | 0x8000;
            ++pIn;
        }
        pDest = (unsigned short*)((char*)pDest + nDestPitch);
        pSource += 512;
    }
}

// calling-convention shim (not game code)
void __fastcall sub_006B9EB0_Shim(unsigned short* pSource, unsigned short* pDest, int nDestPitch)
{
    D3DSMACK_CopySmackBlock(pSource, pDest, nDestPitch);
}

unsigned char* gpFrameBuffer_009897D0; // 0x009897D0

static void __stdcall sub_006B9EB0_CopyWithAlpha(const unsigned short* pSrc, unsigned char* pDst, int nPitch)
{
    for (int nRow = 64; nRow; --nRow)
    {
        unsigned short* pOut = (unsigned short*)pDst;
        for (int i = 0; i < 256; ++i)
        {
            pOut[i] = pSrc[i] | 0x8000;
        }
        pDst += nPitch;
        pSrc += 512;
    }
}

// 0x006B9F00
void __cdecl D3DSMACK_UploadSmackFrameBuffer()
{
    D2DDSurfaceDesc2Strc tDesc = { sizeof(D2DDSurfaceDesc2Strc) };
    if (!gapSmackSurfaces[0])
    {
        return;
    }

    long hResult = gapSmackSurfaces[0]->lpVtbl->Lock(gapSmackSurfaces[0], 0, &tDesc, 0x21, 0);
    if (hResult)
    {
        D3DCORE_LogDDrawError(gszFailedToLockMemorySurface, hResult);
    }
    sub_006B9EB0_CopyWithAlpha((const unsigned short*)gpFrameBuffer_009897D0, (unsigned char*)tDesc.lpSurface, tDesc.lPitch);
    hResult = gapSmackSurfaces[0]->lpVtbl->Unlock(gapSmackSurfaces[0], 0);
    if (hResult)
    {
        D3DCORE_LogDDrawError(gszFailedToUnlockMemorySurface, hResult);
    }

    if (!gapSmackSurfaces[1])
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x1DB);
        exit(-1);
    }

    hResult = gapSmackSurfaces[1]->lpVtbl->Lock(gapSmackSurfaces[1], 0, &tDesc, 0x21, 0);
    if (hResult)
    {
        D3DCORE_LogDDrawError(gszFailedToLockMemorySurface, hResult);
    }
    sub_006B9EB0_CopyWithAlpha((const unsigned short*)(gpFrameBuffer_009897D0 + 0x200), (unsigned char*)tDesc.lpSurface, tDesc.lPitch);
    hResult = gapSmackSurfaces[1]->lpVtbl->Unlock(gapSmackSurfaces[1], 0);
    if (hResult)
    {
        D3DCORE_LogDDrawError(gszFailedToUnlockMemorySurface, hResult);
    }
}

// 0x006BA010
void __fastcall D3DSMACK_DecodeSmacker(const char* szFile, D2SmackRecordStrc* pSmack, unsigned char nType)
{
    if (!gbRenderPaused)
    {
        D2_ASSERT(gpD3DSmackBuffer_009897D0, 0x94);
        memset(gpD3DSmackBuffer_009897D0, 0, 0x10000);
        D3DSMACK_UploadSmackFrameBuffer();
        D3DSMACK_UploadSmackTextures();
    }

    pSmack->nType = nType;
    switch (nType)
    {
    case 's':
        if (pSmack->hSmack)
        {
            return;
        }
        pSmack->hSmack = SmackOpen(szFile, 0xFE000, -1);
        if (!pSmack->hSmack)
        {
            break;
        }
        SmackToBuffer(pSmack->hSmack, 0, 0, 0x400, 0x80, gpD3DSmackBuffer_009897D0, 0x80000000);
        return;

    case 'p':
    {
        void* pBuffer = 0;
        int nSize = 0;
        if (!SFileLoadFileEx(0, szFile, &pBuffer, &nSize, 0, 3, 0) || !pBuffer)
        {
            break;
        }

        tagPALETTEENTRY aPalette[256];
        unsigned char aPixels[60][468];
        int nWidth;
        int nHeight;
        int nDepth;
        const int bDecoded = SBmpDecodeImage(2, pBuffer, nSize, aPalette, aPixels[0], 0x6DB0, &nWidth, &nHeight, &nDepth);
        SMemFree(pBuffer, gszD3DSmackFile, 0xDA, 0);
        if (!bDecoded || nWidth != 468 || nHeight != 60 || nDepth != 8)
        {
            break;
        }

        unsigned short (*pRows)[0x200] = (unsigned short (*)[0x200])gpD3DSmackBuffer_009897D0;
        for (int y = 0; y < 60; ++y)
        {
            for (int x = 0; x < 468; ++x)
            {
                const int nIndex = aPixels[y][x];
                pRows[y][x] = ((aPalette[nIndex].peGreen & 0xF8) << 2) | ((aPalette[nIndex].peRed & 0xF8) << 7) | (aPalette[nIndex].peBlue >> 3);
            }
        }

        if (!gbRenderPaused)
        {
            D3DSMACK_UploadSmackFrameBuffer();
            D3DSMACK_UploadSmackTextures();
        }
        return;
    }

    default:
        return;
    }

    if (pSmack->nType == 's' && pSmack->hSmack)
    {
        SmackClose(pSmack->hSmack);
        pSmack->hSmack = 0;
    }
}

// 0x006B9B00
extern "C" void __cdecl D3DSMACK_SmackFree()
{
    if (gpSmackFrameBuffer)
    {
        FOG_Free(gpSmackFrameBuffer, ".\\Src\\d3dSmack.cpp", 0x5E, 0);
        gpSmackFrameBuffer = 0;
    }
}
