#include "D2Glide.h"
#include "D2DrlgMaps.h"
#include "FogApi.h"

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) void* __stdcall CreateCompatibleDC(void* hdc); // 0x006CC0A0

extern "C" __declspec(dllimport) void* __stdcall CreateCompatibleBitmap(void* hdc, int cx, int cy); // 0x006CC0E4

extern int ganSubtileRowXOffset[]; // 0x0072DB48

extern int ganSubtileRowWidth[]; // 0x0072DB84

extern int ganSubtileRowSrcOffset[]; // 0x0072DBC0

extern unsigned long gdwGlideDebugFontTextColor; // 0x0072F2B0

extern int gnScreenPitch; // 0x007D544C

extern int gaGlideDebugFontCharWidths[96]; // 0x008802C8

extern unsigned char* gpGlideDebugFontGlyphs; // 0x0088044C

unsigned long gdwGlideDebugFontBkColor; // 0x00880448

unsigned char* gpGlideDebugFontGlyphs; // 0x0088044C

// 0x0050B9E0
void __cdecl GLDEBUGFONT_CreateDebugFont()
{
    void* hDC = CreateCompatibleDC(0);
// build: symbol ?gszCourier@* 0x006DD52C
    void* hFont = CreateFontA(10, 0, 0, 0, 400, 0, 0, 0, 0, 0, 0, 0, 1, gszCourier);
    void* hBitmap = CreateCompatibleBitmap(hDC, 8, 16);
    SelectObject(hDC, hFont);
    SelectObject(hDC, hBitmap);
    SetTextColor(hDC, gdwGlideDebugFontTextColor);
    SetBkColor(hDC, gdwGlideDebugFontBkColor);
    SetBkMode(hDC, 2);
    tagRECT rect;
    SetRect(&rect, 0, 0, 8, 16);
    D2_ASSERT(!gpGlideDebugFontGlyphs, 0x98);
    gpGlideDebugFontGlyphs = (unsigned char*)FOG_Alloc(0x3000, ".\\Src\\glDebugFont.cpp", 0x99, 0);
    for (int nGlyph = 0; nGlyph < 96; ++nGlyph)
    {
        unsigned char* pMask = &gpGlideDebugFontGlyphs[nGlyph * 0x80];
        char cChar = nGlyph + 0x20;
        DrawTextA(hDC, &cChar, 1, &rect, 0);
        for (int y = 0; y < 16; ++y)
        {
            for (int x = 0; x < 8; ++x)
            {
                if (GetPixel(hDC, x, y) == gdwGlideDebugFontTextColor)
                    *pMask++ = 0xFF;
                else
                    *pMask++ = 0;
            }
        }
    }
    GetCharWidthA(hDC, 0x20, 0x7F, gaGlideDebugFontCharWidths);
    DeleteObject(hBitmap);
    DeleteObject(hFont);
    DeleteDC(hDC);
}

// 0x0050BB70
void __cdecl GLDEBUGFONT_FreeDebugFont()
{
    if (gpGlideDebugFontGlyphs)
    {
        FOG_Free(gpGlideDebugFontGlyphs, ".\\Src\\glDebugFont.cpp", 0xFB, 0);
        gpGlideDebugFontGlyphs = 0;
    }
}

struct D2GlideFontVertexStrc
{
    float x;
    float y;
    int nColor;
    float oow;
    float sow;
    float tow;
    float unk0x18;
};

typedef void (__stdcall* GlideTexDownloadMipMapFn)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo);

extern GlideTexDownloadMipMapFn gpfnGrTexDownloadMipMap;                 // 0x0087EAB8

extern D2GrTexInfoStrc gtGlideDebugFontTexInfo;                             // 0x0072F2B4

int gaGlideDebugFontTexAddr[96];                                           // 0x008800D8

D2GlideFontVertexStrc gaGlideDebugFontVertices[4];                         // 0x00880258

static int gnGlideDebugFontTmu;                                            // 0x00880450




#pragma intrinsic(memcpy)

static int __fastcall GlideAlignAddress(int nAddress, int nAlignment)
{
    if (nAddress & (nAlignment - 1))
        nAddress = (nAddress | (nAlignment - 1)) + 1;
    return nAddress;
}

// 0x0050B860
int __fastcall GLDEBUGFONT_DownloadDebugFont(int nStartAddress, int nAlignment)
{
    int nStride = GlideAlignAddress(0x80, nAlignment);
    int nTotal = nStride * 96;
    nStartAddress = GlideAlignAddress(nStartAddress, nAlignment);

    unsigned char* pBuffer = (unsigned char*)FOG_Alloc(0x80, ".\\Src\\glDebugFont.cpp", 0x62, 0);
    gtGlideDebugFontTexInfo.pData = pBuffer;

    for (int nGlyph = 0; nGlyph < 96; ++nGlyph)
    {
        gaGlideDebugFontTexAddr[nGlyph] = nStartAddress;
        memcpy(pBuffer, &gpGlideDebugFontGlyphs[nGlyph * 0x80], 0x80);
        gpfnGrTexDownloadMipMap(gnGlideDebugFontTmu, gaGlideDebugFontTexAddr[nGlyph], 3, &gtGlideDebugFontTexInfo);
        nStartAddress += nStride;
    }

    FOG_Free(pBuffer, ".\\Src\\glDebugFont.cpp", 0x70, 0);

    gaGlideDebugFontVertices[0].x = 0.0f;
    gaGlideDebugFontVertices[0].y = 0.0f;
    gaGlideDebugFontVertices[0].nColor = -1;
    gaGlideDebugFontVertices[0].oow = 1.0f;
    gaGlideDebugFontVertices[1].oow = 1.0f;
    gaGlideDebugFontVertices[1].nColor = -1;
    gaGlideDebugFontVertices[0].sow = 0.0f;
    gaGlideDebugFontVertices[0].tow = 0.0f;
    gaGlideDebugFontVertices[1].x = 0.0f;
    gaGlideDebugFontVertices[1].y = 0.0f;
    gaGlideDebugFontVertices[1].sow = 0.0f;
    gaGlideDebugFontVertices[1].tow = 256.0f;
    gaGlideDebugFontVertices[2].x = 0.0f;
    gaGlideDebugFontVertices[2].y = 0.0f;
    gaGlideDebugFontVertices[2].nColor = -1;
    gaGlideDebugFontVertices[2].oow = 1.0f;
    gaGlideDebugFontVertices[2].sow = 128.0f;
    gaGlideDebugFontVertices[3].sow = 128.0f;
    gaGlideDebugFontVertices[2].tow = 256.0f;
    gaGlideDebugFontVertices[3].x = 0.0f;
    gaGlideDebugFontVertices[3].y = 0.0f;
    gaGlideDebugFontVertices[3].nColor = -1;
    gaGlideDebugFontVertices[3].tow = 0.0f;
    gaGlideDebugFontVertices[3].oow = 1.0f;

    return nTotal;
}

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szDest, const char* szFormat, char* args); // 0x006CC4AC
extern void (__stdcall* gpfnGrTexSource)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo); // 0x0087EB98
extern void (__stdcall* gpfnGrDrawVertexArrayContiguous)(int nMode, int nCount, void* pVertices, int nStride); // 0x0087EAC4
struct D2GlideVtxStrc { float x; float y; float z; float oow; float sow; float tow; unsigned int color; };
int gaGlideDebugFontCharWidths[96]; // 0x008802C8

// 0x0050BBA0
static int __stdcall GLDEBUGFONT_DebugDrawChar(char ch, int nX, int nY)
{
    if (nX > 640)
        return 0;

    if (nX < 0)
        return gaGlideDebugFontCharWidths[ch];

    if ((unsigned char)(ch - 0x20) <= 0x5F)
    {
        const int nRight = nX + 8;
        const int nBottom = nY + 16;
        gaGlideDebugFontVertices[0].x = (float)nX;
        gaGlideDebugFontVertices[0].y = (float)nY;
        gaGlideDebugFontVertices[1].x = (float)nX;
        gaGlideDebugFontVertices[1].y = (float)nBottom;
        gaGlideDebugFontVertices[2].x = (float)nRight;
        gaGlideDebugFontVertices[2].y = (float)nBottom;
        gaGlideDebugFontVertices[3].x = (float)nRight;
        gaGlideDebugFontVertices[3].y = (float)nY;

        ch -= 0x20;
        gpfnGrTexSource(gnGlideDebugFontTmu, gaGlideDebugFontTexAddr[ch], 3, &gtGlideDebugFontTexInfo);
        gpfnGrDrawVertexArrayContiguous(5, 4, gaGlideDebugFontVertices, sizeof(D2GlideSpriteVertexStrc));
        return gaGlideDebugFontCharWidths[ch];
    }

    return gaGlideDebugFontCharWidths[0];
}

// 0x0050BC90
void __fastcall GLDEBUGFONT_DebugPrintf(int nX, int nY, const char* szFormat, char* args)
{
    char szText[0x200];
    const int nLength = wvsprintfA(szText, szFormat, args);
    const int nStartX = nX;

    GLCORE_SetColorCombineMode(1);
    GLCORE_SetAlphaBlendMode(1);
    GLCORE_SetTextureFilterMode(1);
    GLCORE_SetTextureCombineMode(gnGlideDebugFontTmu);

    for (int i = 0; i < nLength; ++i)
    {
        nX += GLDEBUGFONT_DebugDrawChar(szText[i], nX, nY);
        if (szText[i] == '\n')
        {
            nX = nStartX;
            nY += 12;
        }
    }
}

unsigned long gdwGlideDebugFontTextColor = 0xFFFFFF; // 0x0072F2B0

D2GrTexInfoStrc gtGlideDebugFontTexInfo = { 4, 4, -1, 5, 0 }; // 0x0072F2B4
