#include "D2Direct3D.h"
#include "D2Win32Base.h"
#include "FogApi.h"

#define WRITE_CORNER(i) pVertices[i].dwColor=PackGridColor(pPoints[i],nAlpha); pVertices[i].fX=(float)pPoints[i].nX; pVertices[i].fY=(float)pPoints[i].nY;
struct D2DrawDeviceStrc;
struct D2TileLibraryEntryStrc;
struct D2TileStrc;
struct D2RectStrc;
struct D2TilePartStrc;
struct D2TileContextStrc;
struct D2DrawVtableStrc;
struct D2PerspectiveTileStrc;
struct D2PerspectiveSpriteStrc;
struct BufferDescription;
struct VertexBuffer;
struct GraphicsInterface;
struct IndexStrip;
struct D2GridPointStrc;
struct D2RendererSettingsStrc;

extern D2TLVertexStrc gaVertices[4]; // 0x00970F48
static int __stdcall sub_006B7530_DrawGlyph(int nX, int nY, char nChar);
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
static void __stdcall sub_006B7FD0_GetPanelRect(int nSide, D2RectStrc* pRect, int* pOffset, int bFlag);

struct D2TilePartStrc { short x,y; char unknown004[16]; };

struct D2TileContextStrc { char unknown000[0x50]; int count; D2TilePartStrc* parts; };

struct D2DrawVtableStrc { void* unknown000[28]; int (__stdcall* DrawPrimitive)(D2DrawDeviceStrc*,int,unsigned int,void*,unsigned int,unsigned int); long (__stdcall* DrawIndexedPrimitive)(D2DrawDeviceStrc*,int,unsigned int,void*,unsigned int,unsigned short*,unsigned int,unsigned int); };

struct D2DrawDeviceStrc { D2DrawVtableStrc* vtable; };

extern D2TLVertexStrc gaQuadVertices[4]; // 0x00971630
extern D2DrawDeviceStrc* gpDrawDevice; // 0x00970E78
void __fastcall D3DFLOORCACHE_BindTileTexture(D2TilePartStrc*); // 0x006BBA00

struct D2PerspectiveTileStrc { short nX,nY; char unknown04[0x10]; };

struct D2PerspectiveSpriteStrc { char unknown00[0x50]; int nTiles; D2PerspectiveTileStrc* pTiles; };

extern D2TLVertexStrc gaPerspectiveVertices[15]; // 0x00971450
extern unsigned short gaPerspectiveIndices[22]; // 0x0074C0D0
void __fastcall sub_006B9860_Project(int nX,int nY,int nZ,int* pOutX,int* pOutY); // 0x006B9860
void __fastcall D3DFLOORCACHE_BindTileTexture(D2PerspectiveTileStrc* pTile); // 0x006BBA00
int __stdcall D2CMPTileValidate(void*, int, int); // 0x005FDEA0
static int __stdcall sub_006B8950_Lit(int, D2TileStrc*, int, int, unsigned int*, unsigned char); // 0x006B8950
static int __stdcall sub_006B87A0_DrawNoPerspective(D2TileStrc*, int, int, const unsigned int*, int, unsigned char); // 0x006B87A0

struct BufferDescription { unsigned int size,caps,format,count; };

struct VertexBuffer {
 virtual long __stdcall QueryInterface(const void*,void**) = 0;
 virtual unsigned long __stdcall AddRef() = 0;
 virtual unsigned long __stdcall Release() = 0;
 virtual long __stdcall Lock(unsigned int,D2TLVertexStrc**,unsigned int*) = 0;
 virtual long __stdcall Unlock() = 0;
};

struct GraphicsInterface {
 virtual long __stdcall QueryInterface(const void*,void**) = 0;
 virtual unsigned long __stdcall AddRef() = 0;
 virtual unsigned long __stdcall Release() = 0;
 virtual void __stdcall Unused0C() = 0;
 virtual void __stdcall Unused10() = 0;
 virtual void __stdcall Unused14() = 0;
 virtual void __stdcall Unused18() = 0;
 virtual void __stdcall Unused1C() = 0;
 virtual void __stdcall Unused20() = 0;
 virtual long __stdcall CreateVertexBuffer(BufferDescription*,VertexBuffer**,unsigned int,void*) = 0;
};

struct IndexStrip { unsigned short indices[12];unsigned short last; };

extern int gTileWidth; // 0x0096F4DC
extern int gTileHeight; // 0x009702B8
extern GraphicsInterface* gGraphics; // 0x00970E64
extern VertexBuffer* gGridBuffer; // 0x00971734
extern IndexStrip gIndexStrips[5]; // 0x009716B0
extern const char gCreateFailure[]; // 0x006FC2C4
extern const char gLockFailure[]; // 0x006FC330
extern const char gUnlockFailure[]; // 0x006FC310
void __fastcall D3DCORE_LogDDrawError(const char* szWhere, int hResult); // 0x006B20E0

struct D2GridPointStrc { unsigned char nScale,nRed,nGreen,nBlue; int nX,nY; };

struct D2RendererSettingsStrc { int unknown00,unknown04; int bFlat; };

extern D2RendererSettingsStrc* gpRendererSettings_007C9148; // 0x007C9148
extern D2VertexBufferStrc* gpGridBuffer_00971734; // 0x00971734
extern unsigned short gaFlatIndices[4]; // 0x0074C3D0
extern unsigned short gaGridIndices[65]; // 0x009716B0
extern unsigned char gabMultiplyTable[256][256]; // 0x00971740
void __fastcall D3DCORE_LogDDrawError(const char* szWhere,int hResult); // 0x006B20E0
extern int gnD3DOriginX; // 0x00981740
extern int gnOriginY; // 0x00981744
extern int gnPerspectiveScale; // 0x00989748

struct D2TileBlockStrc { short x,y; unsigned char unk_04[16]; };
struct D2TileStrc { unsigned int type; unsigned char unk_04[0x4c]; int count; D2TileBlockStrc* blocks; };
extern int gaGeometry[10][6][3]; // 0x0074C100
extern unsigned short gaIndices[22]; // 0x0074C0D0
extern const char gszAssert_006CC837[]; // 0x006CC837
__declspec(noreturn) void __cdecl sub_00681E09_Exit(int);
void __cdecl sub_00681E09_Exit(int); // 0x00681E09
void __fastcall sub_006B9780_SetColor(D2TLVertexStrc*,unsigned int,unsigned char); // 0x006B9780
void __fastcall D3DFLOORCACHE_BindTileTexture(D2TileBlockStrc*); // 0x006BBA00
#define D3D_VERTEX_IN_RECT(v, r) ((v).fX >= (r).nLeft && (v).fX < (r).nRight && (v).fY >= (r).nTop && (v).fY < (r).nBottom)
#define D2ASSERT(c,l) if(!(c)) { FOG_DisplayHalt(gszAssert_006CC837,sub_00408090(),l); sub_00681E09_Exit(-1); }
static int __stdcall sub_006B8DF0_DrawTransparentWallTile(D2TileStrc* pTile, unsigned char nAlpha, int nPosX, int nPosY, unsigned int* pLight, int nScreenPanels);
int __stdcall D2CMPTileValidate(D2TileStrc*,int,int); // 0x005FDEA0

static inline unsigned int PackGridColor(const D2GridPointStrc& point,unsigned char nAlpha);

// 0x006B7530
static int __stdcall sub_006B7530_DrawGlyph(int nX, int nY, char nChar)
{
    if (nX > 640)
    {
        return 0;
    }

    if (nX < 0)
    {
        return ganGlyphWidths[nChar];
    }

    if ((unsigned char)(nChar - 0x20) <= 0x5F)
    {
        const int nRight = nX + 8;
        const int nBottom = nY + 16;
        gaVertices[0].fX = (float)nX;
        gaVertices[0].fY = (float)nY;
        gaVertices[1].fX = (float)nX;
        gaVertices[1].fY = (float)nBottom;
        gaVertices[2].fX = (float)nRight;
        gaVertices[2].fY = (float)nBottom;
        gaVertices[3].fX = (float)nRight;
        gaVertices[3].fY = (float)nY;

        nChar -= 0x20;
        gpD3DDevice_00970E78->lpVtbl->SetTexture(gpD3DDevice_00970E78, 0, gapGlyphTextures_009712D0[nChar]);
        gpD3DDevice_00970E78->lpVtbl->DrawPrimitive(gpD3DDevice_00970E78, 6, 0x1C4, gaVertices, 4, 0x1C);
        return ganGlyphWidths[nChar];
    }

    return ganGlyphWidths[0];
}


typedef char* va_list;
extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szOut, const char* szFormat, va_list args);


// 0x006B7630
void __fastcall sub_006B7630_DrawTextV(int nX, int nY, const char* szFormat, va_list args)
{
    char szBuffer[0x200];
    const int nLength = wvsprintfA(szBuffer, szFormat, args);
    const int nStartX = nX;
// build: symbol ?D3DCORE_SetColorCombineMode@* 0x006B1EA0
    D3DCORE_SetColorCombineMode(1);
    D3DCORE_SetAlphaBlendMode(1);
    D3DCORE_SetTextureFilterMode(1);
    for (int i = 0; i < nLength; ++i)
    {
        nX += sub_006B7530_DrawGlyph(nX, nY, szBuffer[i]);
        if (szBuffer[i] == '\n')
        {
            nX = nStartX;
            nY += 12;
        }
    }
}

// 0x006B7FD0
static void __stdcall sub_006B7FD0_GetPanelRect(int nSide, D2RectStrc* pRect, int* pOffset, int bFlag)
{
    D2_ASSERT(pRect, 0x53);

    pRect->nLeft = 0;
// build: symbol ?gnRenderWidth@* 0x007C9138
    pRect->nRight = gnRenderWidth;
    pRect->nTop = 0;
// build: symbol ?gnRenderHeight@* 0x007C913C
    pRect->nBottom = gnRenderHeight - 47;

    if (!bFlag)
    {
        pRect->nLeft = -32;
        pRect->nBottom += 32;
        switch (nSide)
        {
        case 1:
            pRect->nRight += -(gnRenderWidth / 2);
            break;
        case 2:
            pRect->nLeft = gnRenderWidth / 2 - 32;
            break;
        }
        return;
    }

    D2_ASSERT(pOffset, 0x69);

    const int nShift = gnRenderWidth / 4;
    switch (nSide)
    {
    case 1:
        *pOffset = -nShift;
        pRect->nRight -= nShift;
        pRect->nLeft += nShift;
        break;
    case 2:
        *pOffset = nShift;
        pRect->nRight -= nShift;
        pRect->nLeft += nShift;
        break;
    }
}

// 0x006B8220
int __fastcall sub_006B8220_DrawTileParts(D2TileContextStrc* pTile, int nX, int nY, int nLight, int nColorMode, int nViewMode)
{
    tagRECT tRect;
    tRect.left = 0;
    tRect.top = 0;
    tRect.right = gnRenderWidth;
    tRect.bottom = gnRenderHeight - 47;
    tRect.left -= 32;
    tRect.bottom += 32;

    int bDrawn = 0;
    switch (nViewMode)
    {
    case 1:
        tRect.right -= gnRenderWidth / 2;
        break;
    case 2:
        tRect.left += gnRenderWidth / 2;
        break;
    }

    nY += 32;
    for (int i = 0; i < pTile->count; ++i)
    {
        int nLeft = pTile->parts[i].x + nX;
        int nBottom = pTile->parts[i].y + nY;
        if (nLeft >= tRect.left && nLeft < tRect.right && nBottom >= tRect.top && nBottom < tRect.bottom)
        {
            int nTop = nBottom - 32;
            bDrawn = 1;
            int nRight = nLeft + 32;
            D3DFLOORCACHE_BindTileTexture(&pTile->parts[i]);
            gaQuadVertices[0].fX = (float)nLeft;
            gaQuadVertices[0].fY = (float)nTop;
            gaQuadVertices[1].fX = (float)nLeft;
            gaQuadVertices[1].fY = (float)nBottom;
            gaQuadVertices[2].fX = (float)nRight;
            gaQuadVertices[2].fY = (float)nBottom;
            gaQuadVertices[3].fX = (float)nRight;
            gaQuadVertices[3].fY = (float)nTop;
            sub_006B9730_SetQuadColor(gaQuadVertices, (unsigned char)nLight, nColorMode);
            gaQuadVertices[1].dwColor = gaQuadVertices[0].dwColor;
            gaQuadVertices[2].dwColor = gaQuadVertices[0].dwColor;
            gaQuadVertices[3].dwColor = gaQuadVertices[0].dwColor;
            gpDrawDevice->vtable->DrawPrimitive(gpDrawDevice, 6, 0x1C4, gaQuadVertices, 4, 0x1C);
        }
    }

    return bDrawn;
}

static inline int IsVisible(const D2RectStrc& rect, const D2TLVertexStrc& v)
{
    return v.fX >= rect.nLeft && v.fX < rect.nRight && v.fY >= rect.nTop && v.fY < rect.nBottom;
}

// 0x006B83A0
int __fastcall sub_006B83A0_DrawPerspective(D2PerspectiveSpriteStrc* pSprite,int nX,int nY,int nColor,unsigned char nAlpha,int nSide)
{
    int nResult=0;
    int nOffset=0;

    int nOne=1;
    D2RectStrc rect;
    sub_006B7FD0_GetPanelRect(nSide,&rect,&nOffset,1);
    nX <<= 13;
    nY <<= 13;
    for(int i=0;i<pSprite->nTiles;++i)
    {
        const int nTileX=pSprite->pTiles[i].nX >> 5;
        const int nTileY=(pSprite->pTiles[i].nY+96) >> 5;
        const int nOffsetX=((nTileX+2*nTileY)<<16)-0x38000;
        const int nOffsetY=(((nTileY<<nOne)-nTileX)<<16)+0x18000;
        int nDrawY=nOffsetY+nY;
        int nDrawX=nOffsetX+nX;
        int nOutX;
        sub_006B9860_Project(nDrawX,nDrawY,0,&nOutX,&nSide);
        gaPerspectiveVertices[0].fX=(float)nOutX;
        gaPerspectiveVertices[0].fY=(float)nSide;
        sub_006B9860_Project(nX+nOffsetX+0x20000,nY+nOffsetY+0x20000,0,&nOutX,&nSide);
        gaPerspectiveVertices[12].fX=(float)nOutX;
        gaPerspectiveVertices[12].fY=(float)nSide;
        sub_006B9860_Project(nX+nOffsetX+0x30000,nY+nOffsetY+0x10000,0,&nOutX,&nSide);
        gaPerspectiveVertices[14].fX=(float)nOutX;
        gaPerspectiveVertices[14].fY=(float)nSide;
        sub_006B9860_Project(nX+nOffsetX+0x10000,nY+nOffsetY-0x10000,0,&nOutX,&nSide);
        gaPerspectiveVertices[2].fX=(float)nOutX;
        gaPerspectiveVertices[2].fY=(float)nSide;
        if(IsVisible(rect,gaPerspectiveVertices[0]))
        {
Draw:
            D3DFLOORCACHE_BindTileTexture(&pSprite->pTiles[i]);
            const float fOffset=(float)nOffset;
            D2TLVertexStrc* pVertex=gaPerspectiveVertices;
            int nStartY=nDrawY;
            int nStartX=nDrawX;
            do
            {
                // The tile's origin variables walk each row of three vertices; the row starts keep the next row's origin.
                nDrawX=nStartX;
                nDrawY=nStartY;
                for(int j=0;j<3;++j)
                {
                    sub_006B9860_Project(nDrawX,nDrawY,0,&nOutX,&nSide);
                    pVertex->fY=(float)nSide;
                    pVertex->fX=(float)nOutX+fOffset;
                    sub_006B9730_SetColor(pVertex,nColor,nAlpha);
                    ++pVertex;
                    nDrawX+=0x8000;
                    nDrawY-=0x8000;
                }
                nStartX+=0x8000;
                nStartY+=0x8000;
            } while ((int)pVertex < (int)(gaPerspectiveVertices + 15));
            gpD3DDevice_00970E78->lpVtbl->DrawIndexedPrimitive(gpD3DDevice_00970E78,5,0x1c4,gaPerspectiveVertices,15,gaPerspectiveIndices,22,0x1c);
            nResult=1;
        }
        else if(IsVisible(rect,gaPerspectiveVertices[12])) goto Draw;
        else if(IsVisible(rect,gaPerspectiveVertices[14])) goto Draw;
        else if(IsVisible(rect,gaPerspectiveVertices[2])) goto Draw;
    }
    return nResult;
}

extern "C" const char gData_006FC310[32] = "Vertex buffer unlock failed!"; // 0x006FC310
#pragma comment(linker, "/alternatename:?gUnlockFailure@@3QBDB=_gData_006FC310")

extern "C" const char gData_006FC330[28] = "Vertex buffer lock failed!"; // 0x006FC330
#pragma comment(linker, "/alternatename:?gLockFailure@@3QBDB=_gData_006FC330")

unsigned short gaPerspectiveIndices[22] = { 0, 1, 3, 4, 6, 7, 9, 10, 12, 13, 13, 1, 1, 2, 4, 5, 7, 8, 10, 11, 13, 14 }; // 0x0074C0D0

int gaGeometry[10][6][3] = { // 0x0074C100
    { { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 } },
    { { 0, 5, -40 }, { 0, 3, -56 }, { 0, 1, -72 }, { 0, -1, -88 }, { 0, -3, -104 }, { 0, -5, -120 } },
    { { -5, 0, -120 }, { -3, 0, -104 }, { -1, 0, -88 }, { 1, 0, -72 }, { 3, 0, -56 }, { 5, 0, -40 } },
    { { 0, 5, -40 }, { 0, 3, -56 }, { 0, 1, -72 }, { 1, 0, -72 }, { 3, 0, -56 }, { 5, 0, -40 } },
    { { -5, 0, -120 }, { -3, 0, -104 }, { -1, 0, -88 }, { 0, -1, -88 }, { 0, -3, -104 }, { 0, -5, -120 } },
    { { 0, 5, -40 }, { 0, 3, -56 }, { 0, 1, -72 }, { 1, 0, -72 }, { 3, 0, -56 }, { 5, 0, -40 } },
    { { 5, 10, 40 }, { 5, 8, 24 }, { 5, 6, 8 }, { 5, 4, -8 }, { 5, 2, -24 }, { 5, 0, -40 } },
    { { 0, 5, -40 }, { 2, 5, -24 }, { 4, 5, -8 }, { 6, 5, 8 }, { 8, 5, 24 }, { 10, 5, 40 } },
    { { 0, 5, -40 }, { 2, 5, -24 }, { 4, 5, -8 }, { 5, 4, -8 }, { 5, 2, -24 }, { 5, 0, -40 } },
    { { 0, 5, -40 }, { 2, 5, -24 }, { 4, 5, -8 }, { 5, 4, -8 }, { 5, 2, -24 }, { 5, 0, -40 } }
};

unsigned short gaFlatIndices[4] = { 0, 5, 35, 30 }; // 0x0074C3D0

// 0x006B87A0
static int __stdcall sub_006B87A0_DrawNoPerspective(D2TileStrc* pTile, int nX, int nY, const unsigned int* pLight, int nPanels, unsigned char nAlpha)
{
    int nDrawn = 0;
    int n = gnRenderWidth;
    D2RectStrc tRect;
    tRect.nLeft = 0;
    tRect.nTop = 0;
    tRect.nRight = n;
    tRect.nBottom = gnRenderHeight - 47;
    tRect.nLeft -= 32;
    tRect.nBottom += 32;

    switch (nPanels)
    {
    case 1:
        tRect.nRight -= gnRenderWidth / 2;
        break;
    case 2:
        tRect.nLeft += gnRenderWidth / 2;
        break;
    }

    nY += 32;
    for (n = 0; n < pTile->count; ++n)
    {
        int nBlockX = pTile->blocks[n].x;
        int x = nX + nBlockX;
        int y = nY + pTile->blocks[n].y;
        if (x >= tRect.nLeft && x < tRect.nRight && y >= tRect.nTop && y < tRect.nBottom)
        {
            const int nCol = nBlockX >> 5;
            unsigned int nLeftLight = pLight[nCol];
            unsigned int nRightLight = pLight[nCol + 1];
            int nTop = y - 32;
            int nRight = x + 32;
            nDrawn = 1;
            D3DFLOORCACHE_BindTileTexture(&pTile->blocks[n]);
            gaQuadVertices[0].fX = (float)x;
            gaQuadVertices[0].fY = (float)nTop;
            gaQuadVertices[1].fX = (float)x;
            gaQuadVertices[1].fY = (float)y;
            gaQuadVertices[2].fX = (float)nRight;
            gaQuadVertices[2].fY = (float)y;
            gaQuadVertices[3].fX = (float)nRight;
            gaQuadVertices[3].fY = (float)nTop;
            sub_006B9780_SetColor(&gaQuadVertices[0], nLeftLight, nAlpha);
            sub_006B9780_SetColor(&gaQuadVertices[1], nLeftLight, nAlpha);
            sub_006B9780_SetColor(&gaQuadVertices[2], nRightLight, nAlpha);
            sub_006B9780_SetColor(&gaQuadVertices[3], nRightLight, nAlpha);
            gpDrawDevice->vtable->DrawPrimitive(gpDrawDevice, 6, 0x1C4, &gaQuadVertices[0], 4, 28);
        }
    }
    return nDrawn;
}

// 0x006B8950
static int __stdcall sub_006B8950_Lit(int nScreenPanels, D2TileStrc* pTile, int nPosX, int nPosY, unsigned int* pLight, unsigned char nAlpha)
{
    int nResult = 0;
    int nOffset = 0;
    D2RectStrc tRect;
    sub_006B7FD0_GetPanelRect(nScreenPanels, &tRect, &nOffset, 1);

    nPosY <<= 13;
    nPosX <<= 13;
    const int nType = pTile->type;
    D2ASSERT(nType >= 0 && nType <= 9, 0x213);

    for (int i = 0; i < pTile->count; ++i)
    {
        const int nCol = pTile->blocks[i].x >> 5;
        const int nHeight = pTile->blocks[i].y;
        D2ASSERT(nCol >= 0 && nCol <= 4, 0x21B);

        const int nX0 = gaGeometry[nType][nCol][0] + nPosX;
        const int nY0 = gaGeometry[nType][nCol][1] + nPosY;
        const int nZ0 = gaGeometry[nType][nCol][2] - nHeight;
        const int nX1 = gaGeometry[nType][nCol + 1][0] + nPosX;
        const int nY1 = gaGeometry[nType][nCol + 1][1] + nPosY;
        const int nZ1 = gaGeometry[nType][nCol + 1][2] - nHeight;
        int nScreenX;
        int nScreenY;

        sub_006B9860_Project(nX0, nY0, nZ0, &nScreenX, &nScreenY);
        gaPerspectiveVertices[0].fX = (float)nScreenX;
        gaPerspectiveVertices[0].fY = (float)nScreenY;
        sub_006B9860_Project(nX0, nY0, nZ0 - 0x20, &nScreenX, &nScreenY);
        gaPerspectiveVertices[12].fX = (float)nScreenX;
        gaPerspectiveVertices[12].fY = (float)nScreenY;
        sub_006B9860_Project(nX1, nY1, nZ1 - 0x20, &nScreenX, &nScreenY);
        gaPerspectiveVertices[14].fX = (float)nScreenX;
        gaPerspectiveVertices[14].fY = (float)nScreenY;
        sub_006B9860_Project(nX1, nY1, nZ1, &nScreenX, &nScreenY);
        gaPerspectiveVertices[2].fX = (float)nScreenX;
        gaPerspectiveVertices[2].fY = (float)nScreenY;

        if (D3D_VERTEX_IN_RECT(gaPerspectiveVertices[0], tRect)
            || D3D_VERTEX_IN_RECT(gaPerspectiveVertices[12], tRect)
            || D3D_VERTEX_IN_RECT(gaPerspectiveVertices[14], tRect)
            || D3D_VERTEX_IN_RECT(gaPerspectiveVertices[2], tRect))
        {
            const int nMidX = (nX0 + nX1) >> 1;
            const int nMidY = (nY0 + nY1) >> 1;
            const int nMidZ = (nZ0 + nZ1) >> 1;
            unsigned int aColors[3];
            aColors[0] = pLight[nCol];
            aColors[2] = pLight[nCol + 1];
            const int nMixA = (unsigned char)(((unsigned char)(aColors[2] >> 24) + (unsigned char)(aColors[0] >> 24)) >> 1);
            const int nMixR = (unsigned char)(((unsigned char)(aColors[2] >> 16) + (unsigned char)(aColors[0] >> 16)) >> 1);
            const int nMixG = (unsigned char)(((unsigned char)(aColors[2] >> 8) + (unsigned char)(aColors[0] >> 8)) >> 1);
            const int nMixB = (unsigned char)(((unsigned char)aColors[2] + (unsigned char)aColors[0]) >> 1);
            aColors[1] = (((((nMixA << 8) + nMixR) << 8) + nMixG) << 8) + nMixB;
            D3DFLOORCACHE_BindTileTexture(&pTile->blocks[i]);

            for (int nGridRow = 0; nGridRow < 5; ++nGridRow)
            {
                const int nDepth = nGridRow << 3;
                if (nGridRow != 0 && nGridRow != 4)
                {
                    sub_006B9860_Project(nX0, nY0, nZ0 - nDepth, &nScreenX, &nScreenY);
                    gaPerspectiveVertices[nGridRow * 3].fX = (float)nScreenX;
                    gaPerspectiveVertices[nGridRow * 3].fY = (float)nScreenY;
                    sub_006B9860_Project(nX1, nY1, nZ1 - nDepth, &nScreenX, &nScreenY);
                    gaPerspectiveVertices[nGridRow * 3 + 2].fX = (float)nScreenX;
                    gaPerspectiveVertices[nGridRow * 3 + 2].fY = (float)nScreenY;
                }

                sub_006B9860_Project(nMidX, nMidY, nMidZ - nDepth, &nScreenX, &nScreenY);
                gaPerspectiveVertices[nGridRow * 3 + 1].fX = (float)nScreenX;
                gaPerspectiveVertices[nGridRow * 3 + 1].fY = (float)nScreenY;
                for (int nGridCol = 0; nGridCol < 3; ++nGridCol)
                {
                    D2TLVertexStrc* pVertex = &gaPerspectiveVertices[nGridRow * 3 + nGridCol];
                    pVertex->fX = pVertex->fX + (float)nOffset;
                    sub_006B9780_SetColor(pVertex, aColors[nGridCol], nAlpha);
                }
            }

            gpDrawDevice->vtable->DrawIndexedPrimitive(gpDrawDevice, 5, 0x1c4, gaPerspectiveVertices, 15, gaIndices, 22, 0x1c);
            nResult = 1;
        }
    }

    return nResult;
}


// 0x006B8DF0
static int __stdcall sub_006B8DF0_DrawTransparentWallTile(D2TileStrc* pTile, unsigned char nAlpha, int nPosX, int nPosY, unsigned int* pLight, int nScreenPanels)
{
    if (D2CMPTileValidate(pTile, 1, 0))
    {
        D3DCORE_SetColorCombineMode(1);
        int nBlendMode = 1;
        if (nAlpha != 0xFF)
        {
            nBlendMode = 4;
        }
        D3DCORE_SetAlphaBlendMode(nBlendMode);
        D3DCORE_SetTextureFilterMode(1);
        if (sub_006B9830_GetPerspective())
        {
            return sub_006B8950_Lit(nScreenPanels, pTile, nPosX, nPosY, pLight, nAlpha);
        }
        return sub_006B87A0_DrawNoPerspective(pTile, nPosX, nPosY, pLight, nScreenPanels, nAlpha);
    }
    return 0;
}

// 0x006B8E60
int __fastcall sub_006B8E60_DrawRelay(D2TileStrc* pTile, int nPosX, int nPosY, unsigned int* pLight, int nScreenPanels, unsigned char nAlpha)
{
    return sub_006B8DF0_DrawTransparentWallTile(pTile, nAlpha, nPosX, nPosY, pLight, nScreenPanels);
}


// 0x006B8E90
int __fastcall sub_006B8E90_DrawWallTile(D2TileStrc* pTile, int nPosX, int nPosY, unsigned int* pLight, int nScreenPanels)
{
    int nResult = 0;
    if (D2CMPTileValidate(pTile, 1, 0))
    {
        D3DCORE_SetColorCombineMode(1);
        D3DCORE_SetAlphaBlendMode(1);
        D3DCORE_SetTextureFilterMode(1);
        if (sub_006B9830_GetPerspective())
            nResult = sub_006B8950_Lit(nScreenPanels, pTile, nPosX, nPosY, pLight, 0xFF);
        else
            nResult = sub_006B87A0_DrawNoPerspective(pTile, nPosX, nPosY, pLight, nScreenPanels, 0xFF);
    }
    return nResult;
}

// 0x006B8F10
void __cdecl sub_006B8F10_CreateGridVertexBuffer()
{
    float xStep = (float)(160.0 / gTileWidth);
    xStep = (float)(xStep / 10.0);
    float yStep = (float)(80.0 / gTileHeight);
    yStep = (float)(yStep / 10.0);

    BufferDescription description = { sizeof(BufferDescription) };
    description.caps = 0x10800;
    description.format = 0x1C4;
    description.count = 36;
    long result = gGraphics->CreateVertexBuffer(&description, &gGridBuffer, 4, 0);
    if (result)
    {
        D3DCORE_ShowD3DError(gCreateFailure, result);
        return;
    }

    D2TLVertexStrc* data;
    result = gGridBuffer->Lock(0x21, &data, 0);
    if (result)
    {
        D3DCORE_LogDDrawError(gLockFailure, result);
        return;
    }

    for (int row = 0; row < 6; ++row)
    {
        for (int column = 0; column < 6; ++column)
        {
            int xBorder = 0;
            int yBorder = 0;
            if (column == 0)
            {
                xBorder = 1;
                yBorder = 1;
            }
            else if (column == 5)
            {
                xBorder = -1;
                yBorder = -1;
            }

            if (row == 0)
            {
                --xBorder;
                ++yBorder;
            }
            else if (row == 5)
            {
                ++xBorder;
                --yBorder;
            }

            float u = (float)(xBorder + 80) / gTileWidth;
            u += (column - row) * xStep;
            float v = (float)yBorder / gTileHeight;
            v += (column + row) * yStep;
            data->fZ = 0.5f;
            data->fRhw = 1.0f;
            data->fU = u;
            data->fV = v;
            ++data;
        }
    }

    result = gGridBuffer->Unlock();
    if (result)
    {
        D3DCORE_LogDDrawError(gUnlockFailure, result);
        return;
    }

    unsigned short indices[5][12];
    for (int row = 0; row < 5; ++row)
    {
        for (int column = 0; column < 6; ++column)
        {
            unsigned short* pTop = &indices[row][column * 2];
            unsigned short* pBottom = &indices[row][column * 2 + 1];
            *pTop = row * 6 + (unsigned short)column;
            *pBottom = row * 6 + (unsigned short)column + 6;
        }
    }

    IndexStrip* pStrip = gIndexStrips;
    for (int row = 0; row < 5; ++row)
    {
        const unsigned short* pSource = indices[row];
        for (int i = 0; i < 6; ++i)
        {
            ((int*)pStrip->indices)[i] = ((int*)pSource)[i];
        }
        pStrip->last = pStrip->indices[11];
        ++pStrip;
    }
}

static __forceinline unsigned int PackGridColor(const D2GridPointStrc& point,unsigned char nAlpha)
{
    const unsigned char* pRow=gabMultiplyTable[point.nScale];
    return (((((unsigned int)nAlpha<<8)|pRow[point.nRed])<<8)|pRow[point.nGreen])<<8|pRow[point.nBlue];
}

// 0x006B9170
void __fastcall sub_006B9170_DrawGrid(D2TileLibraryEntryStrc* pTexture,D2GridPointStrc* pPoints,int nArg1,int nArg2,int nArg3,int nArg4,unsigned char nAlphaInput,int nArg6,int nFilter)
{
    if(!sub_006BB870_BindTileTexture(pTexture)) return;
    {
    D3DCORE_SetColorCombineMode(1);
    int nBlend=1;
    const unsigned char nAlpha = nAlphaInput;
    if(nAlpha!=255) nBlend=4;
    D3DCORE_SetAlphaBlendMode(nBlend);
    if(nFilter) D3DCORE_SetTextureFilterMode(2);
    else D3DCORE_SetTextureFilterMode(1); // 0x006B2030
    {
    D2TLVertexStrc* pVertices;
    if(gpRendererSettings_007C9148->bFlat)
    {
        long nResult=gpGridBuffer_00971734->lpVtbl->Lock(gpGridBuffer_00971734,0x21,(void**)&pVertices,0);
        if(nResult) { D3DCORE_LogDDrawError(gLockFailure,nResult);return; }
        WRITE_CORNER(0)
        WRITE_CORNER(5)
        WRITE_CORNER(35)
        WRITE_CORNER(30)
        nResult=gpGridBuffer_00971734->lpVtbl->Unlock(gpGridBuffer_00971734);
        if(nResult) { D3DCORE_LogDDrawError(gUnlockFailure,nResult);return; }
        gpD3DDevice_00970E78->lpVtbl->DrawIndexedPrimitiveVB(gpD3DDevice_00970E78,6,gpGridBuffer_00971734,gaFlatIndices,4,0x1c);
    }
    else
    {
        long nResult=gpGridBuffer_00971734->lpVtbl->Lock(gpGridBuffer_00971734,0x21,(void**)&pVertices,0);
        if(nResult) { D3DCORE_LogDDrawError(gLockFailure,nResult);return; }
        const D2GridPointStrc* pPoint=pPoints;
        for(int nPoint=0;nPoint<36;++nPoint)
        {
            pVertices->dwColor=PackGridColor(*pPoint,nAlpha);
            pVertices->fX=(float)pPoint->nX;
            pVertices->fY=(float)pPoint->nY;
            ++pVertices;
            ++pPoint;
        }
        nResult=gpGridBuffer_00971734->lpVtbl->Unlock(gpGridBuffer_00971734);
        if(nResult) { D3DCORE_LogDDrawError(gUnlockFailure,nResult);return; }
        gpD3DDevice_00970E78->lpVtbl->DrawIndexedPrimitiveVB(gpD3DDevice_00970E78,5,gpGridBuffer_00971734,gaGridIndices,65,0x1c);
    }
    }
    }
}

int ganPerspectiveTable[0x2000]; // 0x00981748

// 0x006B9910
void __fastcall sub_006B9910_ProjectPoint(int nX, int nY, int nUnused, int* pScreenX, int* pScreenY, int bAlternate)
{
    int nA = ((nX - gnD3DOriginX) * 24) >> 16;
    int nB = ((nY - gnOriginY) * 24) >> 16;
    int nSum = (nB + nA) * 724;
    int nDepth = (nSum * -512) >> 10;
    int nAngle = (nSum * 886) >> 20;
    int nCos = ganPerspectiveTable[(nAngle - 0x1000) & 0x1FFF];

    int nHeight = (nDepth * nCos) >> 20;
    *pScreenX = (((nB - nA) * nCos * 724) >> 20) + gnRenderWidth / 2;

    *pScreenY = gnRenderHeight / 2 + nHeight - 16;

    int nValue = nHeight - (((nDepth + 0x37400) * ganPerspectiveTable[(nAngle - 0xF80) & 0x1FFF]) >> 20);

    if (bAlternate)
    {
        gnPerspectiveScale = (nValue * 0x4CC) >> 10;
    }
    else
    {
        gnPerspectiveScale = (nValue * 0x466) >> 10;
    }
}

int __stdcall D2CMPTileValidate(void*, int, int); // 0x005FDEA0
int __fastcall sub_006B83A0_DrawPerspective(void*, int, int, int, unsigned char, int); // 0x006B83A0
int __fastcall sub_006B8220_DrawFlat(void*, int, int, int, unsigned char, int); // 0x006B8220

// 0x006B86F0
int __fastcall sub_006B86F0_DrawShadow(void* sprite, int x, int y, int mode, int extra)
{
    int nResult = 0;
    if (D2CMPTileValidate(sprite, 1, 0))
    {
        unsigned char alpha = 255;
        D3DCORE_SetColorCombineMode(1);
        if (sub_006B77A0_GetBlendedShadows())
        {
            D3DCORE_SetAlphaBlendMode(4);
            alpha = 192;
        }
        else
        {
            D3DCORE_SetAlphaBlendMode(1);
        }
        D3DCORE_SetTextureFilterMode(1);
        if (sub_006B9830_GetPerspective())
        {
            nResult = sub_006B83A0_DrawPerspective(sprite, x, y, mode, alpha, extra);
        }
        else
        {
            nResult = sub_006B8220_DrawFlat(sprite, x, y, mode, alpha, extra);
        }
    }
    return nResult;
}
