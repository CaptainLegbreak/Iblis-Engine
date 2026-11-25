#pragma once


extern int gnRenderWidth; // 0x007C9138
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
unsigned char __stdcall GetClosestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090

struct D2BitmapInfoStrc;
struct D2CelContextStrc;
struct D2CmpCelContextStrc;
struct D2GfxBufferFuncsStrc;
struct D2TileDrawFunctionsStrc;
struct tagRECT;
extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498
extern "C" __declspec(dllimport) void* __stdcall CreateDIBSection(void* hDC, const D2BitmapInfoStrc* pbmi, unsigned int usage, void** ppvBits, void* hSection, unsigned int offset); // 0x006CC0CC
extern D2GfxBufferFuncsStrc* gpBufferFuncs_007C914C; // 0x007C914C
extern D2TileDrawFunctionsStrc* gpTileDrawFunctions_007C914C; // 0x007C914C
extern int gaSelectorValues[]; // 0x0074C5A0
extern int gbRenderPaused; // 0x007C9144
extern int gbSurfaceActive_007C9140; // 0x007C9140
extern int gnBufferHeight_007C913C; // 0x007C913C
extern int gnBufferWidth_007C9138; // 0x007C9138
extern int gnHeight_007C913C; // 0x007C913C
extern int gnModeWidth_0098A16C; // 0x0098A16C
extern int gnOriginX_0098A168; // 0x0098A168
extern int gnStride_007C9138; // 0x007C9138
extern int gnSurfaceHeight_007C913C; // 0x007C913C
extern int gnSurfaceWidth_007C9138; // 0x007C9138
extern int gnValue_007C9140; // 0x007C9140
extern int gnValue_007C9154; // 0x007C9154
extern unsigned char* gpBuffer_007C9154; // 0x007C9154
extern unsigned char* gpScreenBuffer_007C9154; // 0x007C9154
int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3); // 0x006001F0
void __cdecl sub_006C8930_Init(); // 0x006C8930
void __fastcall sub_006C82D0_Apply(int nArg); // 0x006C82D0
void __stdcall CelDraw(D2CmpCelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, int nArg9, int nArg10, int nArg11); // 0x006014C0
// build: symbol ?FOG_DisplayHalt@* 0x00408A60
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
struct D2BitmapInfoStrc
{
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
    unsigned int bmiColors[256];
};
struct D2GfxBufferFuncsStrc
{
    void (__fastcall* pfnSetBuffer)(void* pBits, int nWidth, int nHeight, int nReserved);
};
struct D2PaletteEntry006C7C10Strc
{
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};
struct D2LogPalette006C7C10Strc
{
    unsigned short palVersion;
    unsigned short palNumEntries;
    D2PaletteEntry006C7C10Strc palPalEntry[256];
};
