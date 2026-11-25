#include "D2Glide.h"
#include "D2DrlgMaps.h"

struct D2TileLibraryEntryStrc;

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) void __stdcall SmackClose(void* hSmack); // 0x006CC608

D2GlideFloorCacheEntryStrc* __fastcall GLSMACK_FloorCacheUnlink(D2GlideFloorCacheStrc* pCache, int nIndex); // 0x0050F570

extern D2GrTexInfoStrc gtGlideTileTexInfo; // 0x0072F6A8

extern D2GrTexInfoStrc gtGlideFloorTexInfo; // 0x0072F6BC

extern unsigned char* gpGlideSmackBufferB; // 0x00880B70

extern unsigned char* gpGlideSmackBufferC; // 0x00880B74

D2GlideSpriteVertexStrc gaGlideSmackVertices[4];                                                         // 0x00880B78

unsigned char* sgbSmack8BitBuffer; // 0x00880BF0

extern unsigned char* gpGlideTileDecodeBuffer; // 0x00880BFC

extern unsigned char* gpGlideFloorDecodeBuffer; // 0x00880C00

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize); // 0x00683840

extern "C" __declspec(dllimport) void* __stdcall SmackOpen(const char* szName, unsigned int nFlags, unsigned int nExtraBuf); // 0x006CC604

extern "C" __declspec(dllimport) void __stdcall SmackToBuffer(void* hSmack, unsigned int nLeft, unsigned int nTop, unsigned int nPitch, unsigned int nHeight, void* pBuffer, unsigned int nFlags); // 0x006CC60C

int __stdcall SFileLoadFileEx(void* hMpq, const char* szFileName, void** ppBuffer, int* pnSize, int nExtraBytes, int nFlags, void* pOverlapped); // 0x0041B680

void __fastcall GLSMACK_SetSmackPalette(D2RgbColorStrc* pColors); // 0x0050E070

void __cdecl GLSPRITE_UploadSmackTextures(); // 0x0050E330

int __stdcall SBmpDecodeImage(int nMode, void* pData, int nSize, tagPALETTEENTRY* pPalette, unsigned char* pDest, int nDestSize, int* pWidth, int* pHeight, int* pDepth); // 0x006C6A80

extern int gbRenderPaused; // 0x007C9144

extern "C" __declspec(dllimport) int __stdcall SmackWait(D2SmackStrc* hSmack);                             // 0x006CC5F8

extern "C" __declspec(dllimport) void __stdcall SmackDoFrame(D2SmackStrc* hSmack);                         // 0x006CC5FC

extern "C" __declspec(dllimport) void __stdcall SmackNextFrame(D2SmackStrc* hSmack);                       // 0x006CC600

void __fastcall GLCORE_SetColorCombineMode(int nState);                                                     // 0x005094B0

void __fastcall GLCORE_SetAlphaBlendMode(int nMode);                                                    // 0x00509500

void __fastcall GLCORE_SetTextureFilterMode(int nMode);                                                      // 0x005095D0

void __fastcall GLCORE_SetTextureCombineMode(int nTmu);                                                 // 0x00509460

void __fastcall GLSMACK_CloseSmacker(D2SmackRecordStrc* pRecord);                                  // 0x0050E040

extern void (__stdcall* gpfnGrChromakeyMode)(int bEnable);                                                // 0x0087EB8C

void (__stdcall* gpfnGrTexSource)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo);        // 0x0087EB98

extern void (__stdcall* gpfnGrDrawVertexArrayContiguous)(int nMode, int nCount, void* pVertices, int nStride); // 0x0087EAC4

int gnGlideSmackTmu;                                                                               // 0x00880BF4

extern int gnGlideSmackTexAddrA;                                                                   // 0x00880BE8

extern int gnGlideSmackTexAddrB;                                                                   // 0x00880BEC

extern D2GrTexInfoStrc gtGlideSmackTexInfoA;                                                        // 0x0072F680

extern D2GrTexInfoStrc gtGlideSmackTexInfoB;                                                        // 0x0072F694

// 0x0050DF10
void __cdecl GLSMACK_SmackInit()
{
    gaGlideSmackVertices[0].dwColor = 0xFFFFFFFF;
    gaGlideSmackVertices[1].dwColor = 0xFFFFFFFF;
    gaGlideSmackVertices[2].dwColor = 0xFFFFFFFF;
    gaGlideSmackVertices[3].dwColor = 0xFFFFFFFF;
    gpGlideSmackBufferB = (unsigned char*)FOG_Alloc(0x8000, ".\\Src\\glSmack.cpp", 0x47, 0);
    gpGlideSmackBufferC = (unsigned char*)FOG_Alloc(0x8000, ".\\Src\\glSmack.cpp", 0x48, 0);
    sgbSmack8BitBuffer = (unsigned char*)FOG_Alloc(0x8000, ".\\Src\\glSmack.cpp", 0x49, 0);
}

static D2GlideTexCacheEntryStrc* sub_N19_TexPopHead(D2GlideTexCacheStrc* pCache)
{
    D2GlideTexCacheEntryStrc* pEntry = pCache->pHead;
    if (!pEntry)
        return 0;
    pCache->pHead = pEntry->pNext;
    if (pCache->pHead)
        pCache->pHead->pPrev = 0;
    else
        pCache->pTail = 0;
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

static D2GlideTileCacheEntryStrc* sub_N19_TilePopHead(D2GlideTileCacheStrc* pCache)
{
    D2GlideTileCacheEntryStrc* pEntry = pCache->pHead;
    if (!pEntry)
        return 0;
    pCache->pHead = pEntry->pNext;
    if (pCache->pHead)
        pCache->pHead->pPrev = 0;
    else
        pCache->pTail = 0;
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

static void sub_N19_TileEvict(D2GlideTileCacheStrc* pCache)
{
    if (!pCache->nUsed)
        return;
    D2GlideTileCacheEntryStrc* pEntry = sub_N19_TilePopHead(pCache);
    if (pEntry)
    {
        D2GlideTileStrc* pTile = pEntry->pTile;
        if (pTile)
        {
            pTile->nCacheIndex = 0;
            pEntry->pTile = 0;
        }
        if (!pCache->pFreeHead)
        {
            pCache->pFreeHead = pEntry;
            pCache->pFreeTail = pEntry;
        }
        else
        {
            pCache->pFreeTail->pNext = pEntry;
            pEntry->pPrev = pCache->pFreeTail;
            pCache->pFreeTail = pEntry;
        }
    }
    --pCache->nUsed;
}

static D2GlideFloorCacheEntryStrc* sub_N19_FloorPopHead(D2GlideFloorCacheStrc* pCache)
{
    D2GlideFloorCacheEntryStrc* pEntry = pCache->pHead;
    if (!pEntry)
        return 0;
    pCache->pHead = pEntry->pNext;
    if (pCache->pHead)
        pCache->pHead->pPrev = 0;
    else
        pCache->pTail = 0;
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

// 0x0050E030
void __cdecl GLSMACK_SmackFlush()
{
}

// 0x0050E040
void __fastcall GLSMACK_CloseSmacker(D2SmackRecordStrc* pRecord)
{
    if (pRecord->nType == 's' && pRecord->hSmack)
    {
        SmackClose(pRecord->hSmack);
        pRecord->hSmack = 0;
    }
    pRecord->nType = 0;
}

static unsigned short PackRgb565(int red, int green, int blue)
{
 unsigned short packed=red;
 packed &= ~7;
 packed=(unsigned short)((packed<<5)|(unsigned char)(green & 252));
 packed=(unsigned short)((packed<<3)|(unsigned char)(blue>>3));
 return packed;
}

// 0x0050E070
void __fastcall GLSMACK_SetSmackPalette(D2RgbColorStrc* colors)
{
 const unsigned char* source=sgbSmack8BitBuffer;
 unsigned short* left=(unsigned short*)gpGlideSmackBufferB;
 unsigned short* right=(unsigned short*)gpGlideSmackBufferC;
 for(int y=0;y<64;++y){
  for(int x=0;x<256;++x){
   const int nLeftIndex=source[x];
   left[x]=PackRgb565(colors[nLeftIndex].nRed,colors[nLeftIndex].nGreen,colors[nLeftIndex].nBlue);
   const int nRightIndex=source[x+256];
   right[x]=PackRgb565(colors[nRightIndex].nRed,colors[nRightIndex].nGreen,colors[nRightIndex].nBlue);
  }
  source+=512;left+=256;right+=256;
 }
}

// 0x0050E370
static void __stdcall GLSMACK_DrawSmackFrame(int nHeight, D2SmackRecordStrc* pRecord, int nWidth)
{
    GLCORE_SetColorCombineMode(1);
    GLCORE_SetAlphaBlendMode(1);
    GLCORE_SetTextureFilterMode(2);
    GLCORE_SetTextureCombineMode(gnGlideSmackTmu);
    gpfnGrChromakeyMode(0);
    int nTop = pRecord->nY - nHeight;
    int nY = pRecord->nY;
    gpfnGrTexSource(gnGlideSmackTmu, gnGlideSmackTexAddrA, 3, &gtGlideSmackTexInfoA);
    int nX = pRecord->nX;
    int nRight = nX + 0x100;
    int nTexWidth = 0x100;
    if (nWidth <= 0x100)
        nTexWidth = nWidth;
    gaGlideSmackVertices[0].x = (float)nX;
    gaGlideSmackVertices[0].y = (float)nTop;
    gaGlideSmackVertices[0].oow = 1.0f;
    gaGlideSmackVertices[0].sow = 0.0f;
    gaGlideSmackVertices[0].tow = 0.0f;
    gaGlideSmackVertices[1].x = (float)nX;
    gaGlideSmackVertices[1].y = (float)nY;
    gaGlideSmackVertices[1].oow = 1.0f;
    gaGlideSmackVertices[1].sow = 0.0f;
    gaGlideSmackVertices[1].tow = (float)nHeight;
    gaGlideSmackVertices[2].x = (float)nRight;
    gaGlideSmackVertices[2].y = (float)nY;
    gaGlideSmackVertices[2].oow = 1.0f;
    gaGlideSmackVertices[2].sow = (float)nTexWidth;
    gaGlideSmackVertices[2].tow = (float)nHeight;
    gaGlideSmackVertices[3].x = (float)nRight;
    gaGlideSmackVertices[3].y = (float)nTop;
    gaGlideSmackVertices[3].oow = 1.0f;
    gaGlideSmackVertices[3].sow = (float)nTexWidth;
    gaGlideSmackVertices[3].tow = 0.0f;
    gpfnGrDrawVertexArrayContiguous(5, 4, gaGlideSmackVertices, sizeof(D2GlideSpriteVertexStrc));

    gpfnGrTexSource(gnGlideSmackTmu, gnGlideSmackTexAddrB, 3, &gtGlideSmackTexInfoB);
    nX = nRight;
    nRight = nX + nWidth - 0x100;
    nTexWidth = nWidth - 0x100;
    gaGlideSmackVertices[0].x = (float)nX;
    gaGlideSmackVertices[0].y = (float)nTop;
    gaGlideSmackVertices[0].oow = 1.0f;
    gaGlideSmackVertices[0].sow = 0.0f;
    gaGlideSmackVertices[0].tow = 0.0f;
    gaGlideSmackVertices[1].x = (float)nX;
    gaGlideSmackVertices[1].y = (float)nY;
    gaGlideSmackVertices[1].oow = 1.0f;
    gaGlideSmackVertices[1].sow = 0.0f;
    gaGlideSmackVertices[1].tow = (float)nHeight;
    gaGlideSmackVertices[2].x = (float)nRight;
    gaGlideSmackVertices[2].y = (float)nY;
    gaGlideSmackVertices[2].oow = 1.0f;
    gaGlideSmackVertices[2].sow = (float)nTexWidth;
    gaGlideSmackVertices[2].tow = (float)nHeight;
    gaGlideSmackVertices[3].x = (float)nRight;
    gaGlideSmackVertices[3].y = (float)nTop;
    gaGlideSmackVertices[3].oow = 1.0f;
    gaGlideSmackVertices[3].sow = (float)nTexWidth;
    gaGlideSmackVertices[3].tow = 0.0f;
    gpfnGrDrawVertexArrayContiguous(5, 4, gaGlideSmackVertices, sizeof(D2GlideSpriteVertexStrc));
    gpfnGrChromakeyMode(1);
}

// 0x0050E5D0
void __fastcall GLSMACK_DecodeSmacker(const char* szFile, D2SmackRecordStrc* pSmack, unsigned char nType)
{
    D2_ASSERT(sgbSmack8BitBuffer, 142);
    memset(sgbSmack8BitBuffer, 0, 0x8000);
    memset(gpGlideSmackBufferB, 0, 0x8000);
    memset(gpGlideSmackBufferC, 0, 0x8000);
    if (!gbRenderPaused)
    {
        GLSPRITE_UploadSmackTextures();
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
        SmackToBuffer(pSmack->hSmack, 0, 0, 0x200, 0x40, sgbSmack8BitBuffer, 0);
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
        int nWidth;
        int nHeight;
        int nDepth;
        const int bDecoded = SBmpDecodeImage(2, pBuffer, nSize, aPalette, sgbSmack8BitBuffer, 0x6DB0, &nWidth, &nHeight, &nDepth);
        SMemFree(pBuffer, ".\\Src\\glSmack.cpp", 219, 0);
        if (!bDecoded || nWidth != 468 || nHeight != 60 || nDepth != 8)
        {
            break;
        }

        D2RgbColorStrc aColors[256];
        for (int i = 0; i < 256; ++i)
        {
            aColors[i].nRed = aPalette[i].peRed;
            aColors[i].nGreen = aPalette[i].peGreen;
            aColors[i].nBlue = aPalette[i].peBlue;
        }

        for (int y = 59; y > 0; --y)
        {
            memmove(&sgbSmack8BitBuffer[y * 0x200], &sgbSmack8BitBuffer[y * nWidth], nWidth);
        }

        GLSMACK_SetSmackPalette(aColors);
        GLSPRITE_UploadSmackTextures();
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
    pSmack->nType = 0;
}

// 0x0050E7F0
void __fastcall GLSMACK_PlaySmacker(D2SmackRecordStrc* pRecord)
{
    switch (pRecord->nType)
    {
    case 's':
    {
        D2SmackStrc* hSmack = (D2SmackStrc*)pRecord->hSmack;
        if (!hSmack)
            return;
        if (!SmackWait(hSmack))
        {
            if (!gbSurfaceActive_007C9140)
                return;
            SmackDoFrame(hSmack);
            if (hSmack->nFrameNum == hSmack->nFrames)
                GLSMACK_CloseSmacker(pRecord);
            else
                SmackNextFrame(hSmack);
            if (gbRenderPaused)
                return;
            GLSMACK_SetSmackPalette(hSmack->aPalette);
            GLSPRITE_UploadSmackTextures();
        }
        if (gbRenderPaused)
            return;
        GLSMACK_DrawSmackFrame(hSmack->nHeight, pRecord, hSmack->nWidth);
    }
    case 'p':
        if (!gbRenderPaused)
            GLSMACK_DrawSmackFrame(60, pRecord, 468);
        break;
    }
}

// 0x0050EAE0
D2GlideTexCacheEntryStrc* __fastcall GLSMACK_TexCacheUnlink(D2GlideTexCacheStrc* pCache, int nIndex)
{
    D2GlideTexCacheEntryStrc* pNode = pCache->pHead;
    if (!pNode)
        return 0;
    D2GlideTexCacheEntryStrc* pEntry = &pCache->pEntries[nIndex];
    if (pEntry == pNode)
    {
        pCache->pHead = pNode->pNext;
        if (pCache->pHead)
            pCache->pHead->pPrev = 0;
        else
            pCache->pTail = 0;
        pNode->pNext = 0;
        pNode->pPrev = 0;
        return pNode;
    }
    pNode = pCache->pTail;
    if (pEntry == pNode)
    {
        pNode = pNode->pPrev;
        pCache->pTail = pNode;
        pNode->pNext = 0;
    }
    else
    {
        pNode = pEntry->pPrev;
        pNode->pNext = pEntry->pNext;
        pNode = pEntry->pNext;
        pNode->pPrev = pEntry->pPrev;
    }
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

// 0x0050EC40
void __fastcall GLSMACK_TexCacheEvict(D2GlideTexCacheStrc* pCache)
{
    if (!pCache->nUsed)
        return;
    D2GlideTexCacheEntryStrc* pEntry = sub_N19_TexPopHead(pCache);
    if (pEntry)
    {
        if (pEntry->pOwner)
        {
            pEntry->pOwner[pEntry->nOwnerIndex].nCache = 0;
            pEntry->pOwner[pEntry->nOwnerIndex].nId = 0;
            pEntry->pOwner = 0;
        }
        if (!pCache->pFreeHead)
        {
            pCache->pFreeHead = pEntry;
            pCache->pFreeTail = pEntry;
        }
        else
        {
            pCache->pFreeTail->pNext = pEntry;
            pEntry->pPrev = pCache->pFreeTail;
            pCache->pFreeTail = pEntry;
        }
    }
    --pCache->nUsed;
}


// 0x0050F570
D2GlideFloorCacheEntryStrc* __fastcall GLSMACK_FloorCacheUnlink(D2GlideFloorCacheStrc* pCache, int nIndex)
{
    D2GlideFloorCacheEntryStrc* pNode = pCache->pHead;
    if (!pNode)
        return 0;
    D2GlideFloorCacheEntryStrc* pEntry = &pCache->pEntries[nIndex];
    if (pEntry == pNode)
    {
        pCache->pHead = pNode->pNext;
        if (pCache->pHead)
            pCache->pHead->pPrev = 0;
        else
            pCache->pTail = 0;
        pNode->pNext = 0;
        pNode->pPrev = 0;
        return pNode;
    }
    pNode = pCache->pTail;
    if (pEntry == pNode)
    {
        pNode = pNode->pPrev;
        pCache->pTail = pNode;
        pNode->pNext = 0;
    }
    else
    {
        pNode = pEntry->pPrev;
        pNode->pNext = pEntry->pNext;
        pNode = pEntry->pNext;
        pNode->pPrev = pEntry->pPrev;
    }
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

// 0x0050F6D0
void __fastcall GLSMACK_FloorCacheEvict(D2GlideFloorCacheStrc* pCache)
{
    if (!pCache->nUsed)
        return;
    D2GlideFloorCacheEntryStrc* pEntry = sub_N19_FloorPopHead(pCache);
    if (pEntry)
    {
        D2TileLibraryEntryStrc* pTile = pEntry->pTile;
        D2_ASSERT(pTile, 0xD3);
        pTile->nCacheIndex = 0;
        pEntry->pTile = 0;
        if (!pCache->pFreeHead)
        {
            pCache->pFreeHead = pEntry;
            pCache->pFreeTail = pEntry;
        }
        else
        {
            pCache->pFreeTail->pNext = pEntry;
            pEntry->pPrev = pCache->pFreeTail;
            pCache->pFreeTail = pEntry;
        }
    }
    --pCache->nUsed;
}

// 0x0050F750
void __fastcall GLSMACK_FloorCacheRemove(D2GlideFloorCacheStrc* pCache, int nIndex)
{
    if (!pCache->nUsed)
        return;
    D2GlideFloorCacheEntryStrc* pEntry = GLSMACK_FloorCacheUnlink(pCache, nIndex);
    if (pEntry)
    {
        D2TileLibraryEntryStrc* pTile = pEntry->pTile;
        D2_ASSERT(pTile, 0xF1);
        pTile->nCacheIndex = 0;
        pEntry->pTile = 0;
        if (!pCache->pFreeHead)
        {
            pCache->pFreeHead = pEntry;
            pCache->pFreeTail = pEntry;
        }
        else
        {
            pCache->pFreeTail->pNext = pEntry;
            pEntry->pPrev = pCache->pFreeTail;
            pCache->pFreeTail = pEntry;
        }
    }
    --pCache->nUsed;
}


// 0x0050DF70
void __cdecl GLSMACK_SmackFree()
{
    if (gpGlideSmackBufferB)
    {
        FOG_Free(gpGlideSmackBufferB, ".\\Src\\glSmack.cpp", 86, 0);
        gpGlideSmackBufferB = 0;
    }
    if (gpGlideSmackBufferC)
    {
        FOG_Free(gpGlideSmackBufferC, ".\\Src\\glSmack.cpp", 91, 0);
        gpGlideSmackBufferC = 0;
    }
    if (sgbSmack8BitBuffer)
    {
        FOG_Free(sgbSmack8BitBuffer, ".\\Src\\glSmack.cpp", 96, 0);
        sgbSmack8BitBuffer = 0;
    }
}
