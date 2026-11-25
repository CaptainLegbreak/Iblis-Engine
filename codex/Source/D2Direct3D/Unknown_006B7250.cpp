#include "D2Direct3D.h"
#include "D2DDrawTypes.h"
#include "D2D3DTypes.h"

#define ASSERT(expr,line) if (!(expr)) { FOG_DisplayHalt(gszEmptyString,sub_00408090(),line); exit(-1); }
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2Unknown006B7250Strc;
struct D2SurfaceStrc;
struct D2Device006B77B0Strc;
struct D2Direct3DDevice006B7F70Strc;
struct D2Unknown006B7250VtblStrc;
struct D2RectStrc;
struct D2SurfaceVtableStrc;
struct D2DeviceVtbl006B77B0Strc;
struct D2D3DRect006B7F70Strc;
struct D2Direct3DDeviceVtbl006B7F70Strc;
struct D2GridVertexStrc;
struct D2FixedPointStrc;
struct D2FixedShapeStrc;
struct D2ResourceInterface;
struct D2Object006B9730Strc;

struct D2Unknown006B7250VtblStrc
{
    long (__stdcall* pfnQueryInterface)(D2Unknown006B7250Strc* pThis, const void* riid, void** ppv);
    unsigned long (__stdcall* pfnAddRef)(D2Unknown006B7250Strc* pThis);
    unsigned long (__stdcall* pfnRelease)(D2Unknown006B7250Strc* pThis);
};

struct D2Unknown006B7250Strc
{
    D2Unknown006B7250VtblStrc* pVtbl;
};

extern D2Unknown006B7250Strc* gapGlyphSurfaces[0x60]; // 0x00971150

extern "C" __declspec(dllimport) void* __stdcall CreateCompatibleDC(void* hDC);
extern "C" __declspec(dllimport) void* __stdcall CreateFontA(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, unsigned long bItalic, unsigned long bUnderline, unsigned long bStrikeOut, unsigned long iCharSet, unsigned long iOutPrecision, unsigned long iClipPrecision, unsigned long iQuality, unsigned long iPitchAndFamily, const char* pszFaceName);
extern "C" __declspec(dllimport) void* __stdcall CreateCompatibleBitmap(void* hDC, int cx, int cy);
extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hDC, void* hObject);
extern "C" __declspec(dllimport) unsigned long __stdcall SetTextColor(void* hDC, unsigned long dwColor);
extern "C" __declspec(dllimport) unsigned long __stdcall SetBkColor(void* hDC, unsigned long dwColor);
extern "C" __declspec(dllimport) int __stdcall SetBkMode(void* hDC, int nMode);
extern "C" __declspec(dllimport) int __stdcall SetRect(D2RectStrc* pRect, int nLeft, int nTop, int nRight, int nBottom);
extern "C" __declspec(dllimport) int __stdcall DrawTextA(void* hDC, const char* szText, int nCount, D2RectStrc* pRect, unsigned int nFormat);
extern "C" __declspec(dllimport) unsigned long __stdcall GetPixel(void* hDC, int nX, int nY);
extern "C" __declspec(dllimport) int __stdcall GetCharWidthA(void* hDC, unsigned int nFirst, unsigned int nLast, int* pWidths);
extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* hObject);
extern "C" __declspec(dllimport) int __stdcall DeleteDC(void* hDC);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern unsigned long gdwFontTextColor; // 0x0074C0CC
extern unsigned int gdwRenderFlags_0096F3A8; // 0x0096F3A8
extern void* gapFontGlyphA_00971150[]; // 0x00971150
extern D2D3DTextureStrc* gapFontGlyphB_009712D0[]; // 0x009712D0
void __fastcall D3DCORE_LogDDrawError(const char* szWhere, int hResult); // 0x006B20E0
int __fastcall D3DCORE_CreateMemoryTexture(D2DDSurfaceStrc** ppSurface, D2D3DTextureStrc** ppTexture, int nWidth, int nHeight); // 0x006B3730
int __fastcall sub_006B58A0_CreateGlyphTexture(void** ppGlyphA, D2D3DTextureStrc** ppGlyphB, int nWidth, int nHeight); // 0x006B58A0
void __fastcall D3DCORE_CopySurface(void* pGlyphA, D2DDSurfaceStrc* pSurface, int nHeight); // 0x006B38A0

struct D2SurfaceVtableStrc { void* unk[31]; int (__stdcall *SetPalette)(D2SurfaceStrc*, void*); };

struct D2SurfaceStrc { D2SurfaceVtableStrc* vtable; };

void __fastcall D3DCORE_LogDDrawError(const char*, int); // 0x006B20E0

void __cdecl sub_006B72A0_CreateFontTextures(); // 0x006B72A0

extern D2GfxSettingsStrc* gpGfxSettings; // 0x007C9148

struct D2DeviceVtbl006B77B0Strc
{
    void* unk_00[28];
    long (__stdcall* DrawPrimitive)(D2Device006B77B0Strc* pDevice, int nPrimitiveType, unsigned long dwFVF, void* pVertices, unsigned long nVertices, unsigned long dwFlags);
};

struct D2Device006B77B0Strc
{
    D2DeviceVtbl006B77B0Strc* lpVtbl;
};
void __fastcall D3DCORE_SetColorCombineMode(int nState); // 0x006B1EA0
void __fastcall D3DCORE_SetAlphaBlendMode(int nBlend); // 0x006B1F40
void __fastcall D3DCORE_SetTextureFilterMode(int nMode); // 0x006B2030

void __fastcall sub_006B7B30_DrawLine(int x1,int y1,int x2,int y2,unsigned char index,unsigned char alpha); // 0x006B7B30
extern const char gszEmptyString[]; // 0x006CC837

struct D2D3DRect006B7F70Strc
{
    long x1;
    long y1;
    long x2;
    long y2;
};

struct D2Direct3DDeviceVtbl006B7F70Strc
{
    void* unk_00[20];
    long (__stdcall* Clear)(D2Direct3DDevice006B7F70Strc* pDevice, unsigned long nCount, const D2D3DRect006B7F70Strc* pRects, unsigned long nFlags, unsigned long nColor, float fZ, unsigned long nStencil);
};

struct D2Direct3DDevice006B7F70Strc
{
    D2Direct3DDeviceVtbl006B7F70Strc* lpVtbl;
};
extern D2Direct3DDevice006B7F70Strc* gpDevice_00970E7C; // 0x00970E7C

struct D2GridVertexStrc { float x,y,unknown08,unknown0C,s,t,unknown18,unknown1C; };

struct D2FixedPointStrc { int x,y,unknown08; };

struct D2FixedShapeStrc { D2FixedPointStrc points[6]; };

extern D2GridVertexStrc gaGridVertices[5][3]; // 0x00971458
extern int gaFixedShapes[10][6][3]; // 0x0074C100

struct D2ResourceInterface {
    virtual long __stdcall QueryInterface(const void* id, void** output) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct D2Object006B9730Strc
{
    unsigned char unk_00[0x10];
    unsigned int dwColor10;
};

extern unsigned char gbD3DColorRed; // 0x0097173A
extern unsigned char gbD3DColorGreen; // 0x00971738
extern unsigned char gbD3DColorBlue; // 0x00971739
extern unsigned char gabMultiplyTable[][256]; // 0x00971740
extern int gaScaleTable_00981748[0x2000]; // 0x00981748
extern int gnScaleTableReady_00989748; // 0x00989748
extern int gnD3DOriginX; // 0x00981740
extern int gnOriginY; // 0x00981744
extern int gnPerspective_00981748[]; // 0x00981748

D2Unknown006B7250Strc* gapGlyphTextures[0x60]; // 0x009712D0

// 0x006B7250
void __cdecl sub_006B7250_ReleaseAll()
{
    for (int i = 0; i < 0x60; ++i)
    {
        if (gapGlyphTextures[i])
        {
            gapGlyphTextures[i]->pVtbl->pfnRelease(gapGlyphTextures[i]);
            gapGlyphTextures[i] = 0;
        }
        if (gapGlyphSurfaces[i])
        {
            gapGlyphSurfaces[i]->pVtbl->pfnRelease(gapGlyphSurfaces[i]);
            gapGlyphSurfaces[i] = 0;
        }
    }
}

unsigned long gdwFontBkColor; // 0x00971148

int ganGlyphWidths[96]; // 0x00970FC8

// 0x006B72A0
void __cdecl sub_006B72A0_CreateFontTextures()
{
    void* hDC = CreateCompatibleDC(0);
    void* hFont = CreateFontA(10, 0, 0, 0, 400, 0, 0, 0, 0, 0, 0, 0, 1, "Courier");
    void* hBitmap = CreateCompatibleBitmap(hDC, 8, 16);
    SelectObject(hDC, hFont);
    SelectObject(hDC, hBitmap);
    SetTextColor(hDC, gdwFontTextColor);
    SetBkColor(hDC, gdwFontBkColor);
    SetBkMode(hDC, 2);

    D2RectStrc tRect;
    SetRect(&tRect, 0, 0, 8, 16);

    D2DDSurfaceStrc* pSurface = 0;
    D2D3DTextureStrc* pTexture = 0;
    D3DCORE_CreateMemoryTexture(&pSurface, &pTexture, 8, 16);

    for (int nChar = ' '; nChar <= 0x7F; ++nChar)
    {
        char szChar = (char)nChar;
        DrawTextA(hDC, &szChar, 1, &tRect, 0);

        D2DDSurfaceDesc2Strc tDesc = { sizeof(D2DDSurfaceDesc2Strc) };
        long hResult = pSurface->lpVtbl->Lock(pSurface, 0, &tDesc, 0x21, 0);
        if (hResult)
        {
            D3DCORE_LogDDrawError("Failed to lock memory surface", hResult);
        }

        unsigned short* pPixel = (unsigned short*)tDesc.lpSurface;
        for (int nY = 0; nY < 16; ++nY)
        {
            for (int nX = 0; nX < 8; ++nX)
            {
                if (GetPixel(hDC, nX, nY) == gdwFontTextColor)
                {
                    *pPixel++ = 0xFFFF;
                }
                else
                {
                    *pPixel++ = 0;
                }
            }
        }

        hResult = pSurface->lpVtbl->Unlock(pSurface, 0);
        if (hResult)
        {
            D3DCORE_LogDDrawError("Failed to unlock memory surface", hResult);
        }

        D2_ASSERT(sub_006B58A0_CreateGlyphTexture(&gapFontGlyphA_00971150[nChar - ' '], &gapFontGlyphB_009712D0[nChar - ' '], 8, 16), 0xBF);
        if (gdwRenderFlags_0096F3A8 & gdwBitMasks[10])
        {
            D3DCORE_CopySurface(gapFontGlyphA_00971150[nChar - ' '], pSurface, 16);
        }
        else
        {
            gapFontGlyphB_009712D0[nChar - ' ']->lpVtbl->Load(gapFontGlyphB_009712D0[nChar - ' '], pTexture);
        }
    }

    pTexture->lpVtbl->Release(pTexture);
    pSurface->lpVtbl->Release(pSurface);
    GetCharWidthA(hDC, 0x20, 0x7F, ganGlyphWidths);
    DeleteObject(hBitmap);
    DeleteObject(hFont);
    DeleteDC(hDC);
}

#include "gen/data/Source/D2Direct3D/Unknown_006B7250.inc"

D2SurfaceStrc* gaSurfaces_00971150[96]; // 0x00971150

// 0x006B74F0
void __fastcall sub_006B74F0_SetPalette(void* pPalette)
{
 if (!pPalette) return;
 D2SurfaceStrc** p = gaSurfaces_00971150;
 do {
  D2SurfaceStrc* s = *p;
  if (s) {
   int result = s->vtable->SetPalette(s, pPalette);
   if (result) { D3DCORE_LogDDrawError("SetPalette (debug font surface)", result); return; }
  }
  ++p;
 } while ((int)p < (int)(gaSurfaces_00971150 + 96));
}

D2TLVertexStrc gaVertices[4]; // 0x00970F48

// 0x006B76D0
char* __fastcall sub_006B76D0_InitVertices(char* pObject)
{
    sub_006B72A0_CreateFontTextures();
    gaVertices[0].fX = 0.0f;
    gaVertices[0].fY = 0.0f;
    gaVertices[0].fZ = 0.5f;
    gaVertices[0].fRhw = 1.0f;
    gaVertices[0].dwColor = 0xFFFFFFFF;
    gaVertices[1].dwColor = 0xFFFFFFFF;
    gaVertices[2].dwColor = 0xFFFFFFFF;
    gaVertices[3].dwColor = 0xFFFFFFFF;
    gaVertices[1].fRhw = 1.0f;
    gaVertices[1].fV = 1.0f;
    gaVertices[2].fRhw = 1.0f;
    gaVertices[2].fU = 1.0f;
    gaVertices[2].fV = 1.0f;
    gaVertices[3].fRhw = 1.0f;
    gaVertices[3].fU = 1.0f;
    gaVertices[0].fU = 0.0f;
    gaVertices[0].fV = 0.0f;
    gaVertices[1].fX = 0.0f;
    gaVertices[1].fY = 0.0f;
    gaVertices[1].fU = 0.0f;
    gaVertices[2].fX = 0.0f;
    gaVertices[2].fY = 0.0f;
    gaVertices[3].fX = 0.0f;
    gaVertices[3].fY = 0.0f;
    gaVertices[3].fV = 0.0f;
    gaVertices[1].fZ = 0.5f;
    gaVertices[2].fZ = 0.5f;
    gaVertices[3].fZ = 0.5f;
    return pObject + 0x6000;
}

// 0x006B77A0
int __cdecl sub_006B77A0_GetBlendedShadows()
{
    return gpGfxSettings->bBlendedShadows;
}

static inline int sub_006B77B0_Clip(int nValue, int nSize)
{
    int nClipped = nValue > 0 ? nValue : 0;
    return nClipped < nSize - 1 ? nClipped : nSize - 1;
}

// 0x006B77B0
void __fastcall sub_006B77B0_Call(int nX1, int nY1, int nX2, int nY2, unsigned char nColor, int nMode)
{
// build: symbol ?gnRenderWidth@* 0x007C9138
    nX1 = sub_006B77B0_Clip(nX1, gnRenderWidth);
    nX2 = sub_006B77B0_Clip(nX2, gnRenderWidth);
    if (nX1 == nX2)
        return;

// build: symbol ?gnRenderHeight@* 0x007C913C
    nY1 = sub_006B77B0_Clip(nY1, gnRenderHeight);
    nY2 = sub_006B77B0_Clip(nY2, gnRenderHeight);
    if (nY2 == nY1)
        return;

    D2_ASSERT(nY2 > nY1, 0x2B);

    D3DCORE_SetColorCombineMode(2);
    D3DCORE_SetAlphaBlendMode(4);
    D3DCORE_SetTextureFilterMode(1);

    D2TLVertexStrc tVertices[4];
    tVertices[0].fX = (float)nX1;
    tVertices[0].fY = (float)nY1;
    tVertices[0].fZ = 0.5f;
    tVertices[0].fRhw = 1.0f;
    tVertices[0].fU = 0.0f;
    tVertices[0].fV = 0.0f;
    tVertices[1].fX = (float)nX1;
    tVertices[1].fY = (float)nY2;
    tVertices[1].fZ = 0.5f;
    tVertices[1].fRhw = 1.0f;
    tVertices[1].fU = 0.0f;
    tVertices[1].fV = 0.0f;
    tVertices[2].fX = (float)nX2;
    tVertices[2].fY = (float)nY2;
    tVertices[2].fZ = 0.5f;
    tVertices[2].fRhw = 1.0f;
    tVertices[2].fU = 0.0f;
    tVertices[2].fV = 0.0f;
    tVertices[3].fX = (float)nX2;
    tVertices[3].fY = (float)nY1;
    tVertices[3].fZ = 0.5f;
    tVertices[3].fRhw = 1.0f;
    tVertices[3].fU = 0.0f;
    tVertices[3].fV = 0.0f;

// build: symbol ?D3DCORE_GetColor@* 0x006B1D50
    unsigned int dwColor = D3DCORE_GetColor(nColor) & 0xFFFFFF;
    switch (nMode)
    {
    case 0:
        dwColor |= 0x40000000;
        break;
    case 1:
        dwColor |= 0x80000000;
        break;
    case 2:
        dwColor |= 0xC0000000;
        break;
    default:
        dwColor |= 0xFF000000;
        break;
    }

    tVertices[0].dwColor = dwColor;
    tVertices[1].dwColor = dwColor;
    tVertices[2].dwColor = dwColor;
    tVertices[3].dwColor = dwColor;
    gpD3DDevice_00970E78->lpVtbl->DrawPrimitive(gpD3DDevice_00970E78, 6, 0x1C4, tVertices, 4, 0x1C);
}

// 0x006B7C90
void __fastcall sub_006B7C90_DrawDiamond(D2RectStrc* pRect, int nColor)
{
    D2_ASSERT(pRect->nLeft <= pRect->nRight, 0xC5);
    D2_ASSERT(pRect->nTop <= pRect->nBottom, 0xC6);

    int nLeft = pRect->nLeft;
    int nTop = pRect->nTop;
    unsigned int nWidth = pRect->nRight - nLeft;
    unsigned int nHeight = pRect->nBottom - nTop;
    if (!nWidth)
    {
        return;
    }
    if (!nHeight)
    {
        return;
    }

    int nMidX = nLeft + (nWidth >> 1);
    int nMidY = nTop + (nHeight >> 1);
    int nRight = nLeft + nWidth;
    int nBottom = nTop + nHeight;
    if (nRight < 0 || nLeft > gnRenderWidth || nBottom < 0 || nTop > gnRenderHeight)
    {
        return;
    }

    sub_006B7B30_DrawLine(nMidX, nTop, nRight, nMidY, nColor, 0xFF);
    sub_006B7B30_DrawLine(nRight, nMidY, nMidX, nBottom, nColor, 0xFF);
    sub_006B7B30_DrawLine(nMidX, nBottom, nLeft, nMidY, nColor, 0xFF);
    sub_006B7B30_DrawLine(nLeft, nMidY, nMidX, nTop, nColor, 0xFF);
}

// 0x006B7D80
void __fastcall sub_006B7D80_DrawRectangle(D2RectStrc* rect,int color) {
    ASSERT(rect->nLeft<=rect->nRight,235);
    ASSERT(rect->nTop<=rect->nBottom,236);
    int left=MIN(MAX(rect->nLeft,0),gnWidth_007C9138-1);
    int right=MIN(MAX(rect->nRight,0),gnWidth_007C9138-1);
    if (left==right) return;
    int top=MIN(MAX(rect->nTop,0),gnHeight_007C913C-1);
    int bottom=MIN(MAX(rect->nBottom,0),gnHeight_007C913C-1);
    if (top==bottom) return;
    ASSERT(bottom>top,252);
    sub_006B7B30_DrawLine(left,top,right,top,color,255);
    sub_006B7B30_DrawLine(right,top,right,bottom,color,255);
    sub_006B7B30_DrawLine(right,bottom,left,bottom,color,255);
    sub_006B7B30_DrawLine(left,bottom,left,top,color,255);
}

// 0x006B7F70
void __cdecl sub_006B7F70_ClearTarget()
{
// build: symbol ?gnRenderFlag@* 0x006CE290
    if (gnRenderFlags_0096F3A8 & gnRenderFlag)
    {
// build: symbol ?D3DCORE_Flush@* 0x006B3800
        D3DCORE_Flush();
        return;
    }
    D2D3DRect006B7F70Strc tRect;
    tRect.x1 = 0;
    tRect.y1 = 0;
    tRect.x2 = gnWidth_007C9138;
    tRect.y2 = gnHeight_007C913C;
    gpDevice_00970E7C->lpVtbl->Clear(gpDevice_00970E7C, 1, &tRect, 1, 0xFF000000, 0.0f, 0);
}

D2TLVertexStrc gaQuadVertices[4]; // 0x00971630

// 0x006B80A0
void __cdecl sub_006B80A0_InitializeDrawingGeometry()
{
 gaQuadVertices[0].fX=0.0f;gaQuadVertices[0].fY=0.0f;gaQuadVertices[0].fZ=0.5f;gaQuadVertices[0].fRhw=1.0f;
 gaQuadVertices[0].fU=0.0f;gaQuadVertices[0].fV=0.0f;
 gaQuadVertices[1].fX=0.0f;gaQuadVertices[1].fY=0.0f;gaQuadVertices[1].fZ=0.5f;gaQuadVertices[1].fRhw=1.0f;
 gaQuadVertices[1].fU=0.0f;gaQuadVertices[1].fV=1.0f;
 gaQuadVertices[2].fX=0.0f;gaQuadVertices[2].fY=0.0f;gaQuadVertices[2].fZ=0.5f;gaQuadVertices[2].fRhw=1.0f;
 gaQuadVertices[2].fU=1.0f;gaQuadVertices[2].fV=1.0f;
 gaQuadVertices[3].fX=0.0f;gaQuadVertices[3].fY=0.0f;gaQuadVertices[3].fZ=0.5f;gaQuadVertices[3].fRhw=1.0f;
 gaQuadVertices[3].fU=1.0f;gaQuadVertices[3].fV=0.0f;
 for(int row=0;row<5;++row) {
  float t=(float)(row*0.984375*0.25+0.015625);
  for(int column=0;column<3;++column) {
   gaGridVertices[row][column].x=0.5f;
   gaGridVertices[row][column].y=1.0f;
   gaGridVertices[row][column].s=(float)(column*0.984375*0.5+0.015625);
   gaGridVertices[row][column].t=t;
  }
 }
 for(int index=0;index<10;++index) {
  for(int point=0;point<6;++point) {
   int* pPoint=gaFixedShapes[index][point];
   pPoint[0]<<=16;
   pPoint[1]<<=16;
  }
 }
}

D2ResourceInterface* gpGridBuffer; // 0x00971734

// 0x006B9150
void __cdecl sub_006B9150_ReleaseResource()
{
    if (gpGridBuffer) {
        gpGridBuffer->Release();
        gpGridBuffer = 0;
    }
}

unsigned char gaScaleTable_00971740[256][256]; // 0x00971740

// 0x006B96C0
void __cdecl sub_006B96C0_BuildScaleTable()
{
    for (int i = 0; i < 256; ++i)
    {
        for (int j = 0; j < 256; ++j)
        {
            gaScaleTable_00971740[i][j] = (unsigned char)((i * j) / 255);
        }
    }
}

unsigned char gbD3DColorRed; // 0x0097173A

unsigned char gbD3DColorGreen; // 0x00971738

unsigned char gbD3DColorBlue; // 0x00971739

// 0x006B9710
void __fastcall sub_006B9710_SetColorComponents(unsigned char first, unsigned char second, unsigned char third)
{
    gbD3DColorRed = first;
    gbD3DColorGreen = second;
    gbD3DColorBlue = third;
}

// 0x006B9730
void __fastcall sub_006B9730_SetColor(D2Object006B9730Strc* pObject, unsigned char nIndex, unsigned char nAlpha)
{
    const unsigned char* pRow = gabMultiplyTable[nIndex];
    pObject->dwColor10 = ((((unsigned int)nAlpha << 8 | pRow[gbD3DColorRed]) << 8 | pRow[gbD3DColorGreen]) << 8) | pRow[gbD3DColorBlue];
}

// 0x006B9780
void __fastcall sub_006B9780_SetColor(D2Object006B9730Strc* pObject, unsigned int nPacked, unsigned char nAlpha)
{
    const unsigned char* pRow = gabMultiplyTable[(unsigned char)nPacked];
    pObject->dwColor10 = ((((unsigned int)nAlpha << 8 | pRow[(unsigned char)(nPacked >> 8)]) << 8 | pRow[(unsigned char)(nPacked >> 16)]) << 8) | pRow[nPacked >> 24];
}

// 0x006B97D0
void __cdecl sub_006B97D0_BuildScaleTable()
{
    for (int j = 0; j < 0x2000; ++j)
    {
        const int i = j - 0x1000;
        const int nValue = D2_MIN(D2_MAX(i, -2999), 2999);
        gaScaleTable_00981748[j] = 3072000 / (nValue - 3000);
    }
    gnScaleTableReady_00989748 = 256;
}

// 0x006B9830
int __cdecl sub_006B9830_GetPerspective()
{
    if (gpGfxSettings->bPerspectiveCapable)
        return gpGfxSettings->bPerspectiveEnabled;
    return 0;
}

// 0x006B9850
void __fastcall sub_006B9850_SetOrigin(int x, int y)
{
    gnD3DOriginX = x;
    gnOriginY = y;
}

int gnD3DOriginX; // 0x00981740

int gnOriginY; // 0x00981744

// 0x006B9860
void __fastcall sub_006B9860_Project(int x, int y, int z, int* outX, int* outY)
{
    int nA = ((x - gnD3DOriginX) * 24) >> 16;
    int nB = ((y - gnOriginY) * 24) >> 16;
    int nZ = z * 1228;
    int nSum = (nB + nA) * 724;
    int nScale = gnPerspective_00981748[(((nSum * 886 + nZ * 512) >> 20) - 4096) & 8191];
    *outX = (((nB - nA) * nScale * 724) >> 20) + gnRenderWidth / 2;
    *outY = ((((nZ * 886 - nSum * 512) >> 10) * nScale) >> 20) + gnRenderHeight / 2 - 32;
}

// 0x006B9A00
void __cdecl sub_006B9A00_ResetScale()
{
    gnScaleTableReady_00989748 = 256;
}

struct D2Point006B7F20Strc;
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
void __fastcall D3DCORE_SetColorCombineMode(int state); // 0x006B1EA0
void __fastcall D3DCORE_SetAlphaBlendMode(int mode); // 0x006B1F40
void __fastcall D3DCORE_SetTextureFilterMode(int mode); // 0x006B2030

int __fastcall sub_006B77B0_Call(int nLeft, int nTop, int nRight, int nBottom, int nValue, int nMode); // 0x006B77B0

struct D2Point006B7F20Strc
{
    int nX;
    int nY;
};

extern "C" __declspec(dllimport) int __stdcall SetRect(D2RectStrc* pRect, int nLeft, int nTop, int nRight, int nBottom);

static inline int ClampCoordinate(int value, int extent)
{
    value = value > 0 ? value : 0;
    return value < extent - 1 ? value : extent - 1;
}

// 0x006B7980
void __fastcall sub_006B7980_DrawRectangle(int left, int top, int right, int bottom, unsigned char color, unsigned char alpha)
{
    left = ClampCoordinate(left, gnWidth_007C9138);
    right = ClampCoordinate(right, gnWidth_007C9138);
    if (left == right)
        return;
    top = ClampCoordinate(top, gnHeight_007C913C);
    bottom = ClampCoordinate(bottom, gnHeight_007C913C);
    if (bottom == top)
        return;
    if (bottom <= top)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x68);
        exit(-1);
    }
    D3DCORE_SetColorCombineMode(2);
    D3DCORE_SetAlphaBlendMode(4);
    D3DCORE_SetTextureFilterMode(1);

    D2TLVertexStrc vertices[4];
    vertices[0].fX = (float)left;
    vertices[0].fY = (float)top;
    vertices[0].fZ = 0.5f;
    vertices[0].fRhw = 1.0f;
    vertices[0].fU = 0.0f;
    vertices[0].fV = 0.0f;
    vertices[1].fX = (float)left;
    vertices[1].fY = (float)bottom;
    vertices[1].fZ = 0.5f;
    vertices[1].fRhw = 1.0f;
    vertices[1].fU = 0.0f;
    vertices[1].fV = 0.0f;
    vertices[2].fX = (float)right;
    vertices[2].fY = (float)bottom;
    vertices[2].fZ = 0.5f;
    vertices[2].fRhw = 1.0f;
    vertices[2].fU = 0.0f;
    vertices[2].fV = 0.0f;
    vertices[3].fX = (float)right;
    vertices[3].fY = (float)top;
    vertices[3].fZ = 0.5f;
    vertices[3].fRhw = 1.0f;
    vertices[3].fU = 0.0f;
    vertices[3].fV = 0.0f;
// build: symbol ?D3DCORE_GetColor@* 0x006B1D50
    unsigned int diffuse = (D3DCORE_GetColor(color) & 0x00FFFFFF) | ((unsigned int)alpha << 24);
    vertices[0].dwColor = diffuse;
    vertices[1].dwColor = diffuse;
    vertices[2].dwColor = diffuse;
    vertices[3].dwColor = diffuse;
    gpD3DDevice_00970E78->lpVtbl->DrawPrimitive(gpD3DDevice_00970E78, 6, 0x1C4, vertices, 4, 0x1C);
}

// 0x006B7ED0
int __fastcall sub_006B7ED0_CallRect(D2RectStrc* pRect, int nValue)
{
    D2_ASSERT(pRect->nLeft <= pRect->nRight, 0x10C);
    D2_ASSERT(pRect->nTop <= pRect->nBottom, 0x10D);
    return sub_006B77B0_Call(pRect->nLeft, pRect->nTop, pRect->nRight, pRect->nBottom, nValue, 5);
}

// 0x006B7F20
void __fastcall sub_006B7F20_CallSquare(D2Point006B7F20Strc* pPoint, unsigned char nSize, int nValue)
{
    if (nSize)
    {
        --nSize;
        D2RectStrc tRect;
        SetRect(&tRect, pPoint->nX - nSize, pPoint->nY - nSize, pPoint->nX + nSize + 1, pPoint->nY + nSize + 1);
        sub_006B77B0_Call(tRect.nLeft, tRect.nTop, tRect.nRight, tRect.nBottom, nValue, 5);
    }
}

void __fastcall D3DCORE_SetColorCombineMode(int mode); // 0x006B1EA0
void __fastcall D3DCORE_SetAlphaBlendMode(int mode); // 0x006B1F40
void __fastcall D3DCORE_SetTextureFilterMode(int mode); // 0x006B2030
// 0x006B7B30
void __fastcall sub_006B7B30_DrawLine(int x1,int y1,int x2,int y2,unsigned char index,unsigned char alpha)
{
 if(x2<0 && x1<0) return;
// build: symbol ?gnRenderWidth@* 0x007C9138
 if(x2>=gnRenderWidth && x1>=gnRenderWidth) return;
 if(y2<0 && y1<0) return;
// build: symbol ?gnRenderHeight@* 0x007C913C
 if(y2>=gnRenderHeight && y1>=gnRenderHeight) return;
// build: symbol ?D3DCORE_GetColor@* 0x006B1D50
 unsigned int color=D3DCORE_GetColor(index);
 D3DCORE_SetColorCombineMode(2);
 if(alpha==255) D3DCORE_SetAlphaBlendMode(1);
 else {
  D3DCORE_SetAlphaBlendMode(4);
  color=(color&0xFFFFFF)|((unsigned int)alpha<<24);
 }
 D3DCORE_SetTextureFilterMode(1);
 if(x1==x2 && y1==y2) {
  D2TLVertexStrc point;
  point.fX=(float)x1;point.fY=(float)y1;point.fZ=0.5f;point.fRhw=1.0f;
  point.dwColor=color;point.fU=0.0f;point.fV=0.0f;
  gpD3DDevice_00970E78->lpVtbl->DrawPrimitive(gpD3DDevice_00970E78,1,0x1C4,&point,1,0x1C);
  return;
 } else {
 D2TLVertexStrc line[2];
 line[0].fX=(float)x1;line[0].fY=(float)y1;line[0].fZ=0.5f;line[0].fRhw=1.0f;
 line[0].dwColor=color;line[0].fU=0.0f;line[0].fV=0.0f;
 line[1].fX=(float)x2;line[1].fY=(float)y2;line[1].fZ=0.5f;line[1].fRhw=1.0f;
 line[1].dwColor=color;line[1].fU=0.0f;line[1].fV=0.0f;
 gpD3DDevice_00970E78->lpVtbl->DrawPrimitive(gpD3DDevice_00970E78,2,0x1C4,line,2,0x1C);
 }
}
