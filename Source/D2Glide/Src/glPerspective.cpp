#include "D2Glide.h"

#include "D2DrlgMaps.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MIN(a, b) ((a) < (b) ? (a) : (b))

extern int* gpnPerspectiveTable; // 0x00880B6C

extern int gnProjectOriginX; // 0x00880B60

extern int gnGlideSpriteScale; // 0x00880B64

extern int gnProjectOriginY; // 0x00880B68

// 0x0050DC80
void __cdecl GLPERSPECTIVE_AllocPerspectiveTable()
{
    gpnPerspectiveTable = (int*)FOG_Alloc(0x8000, ".\\Src\\glPerspective.cpp", 0x38, 0);
}

// 0x0050DCA0
void __cdecl GLPERSPECTIVE_FreePerspectiveTable()
{
    if (gpnPerspectiveTable)
    {
        FOG_Free(gpnPerspectiveTable, ".\\Src\\glPerspective.cpp", 63, 0);
        gpnPerspectiveTable = 0;
    }
}

// 0x0050DCD0
void __cdecl GLPERSPECTIVE_FillPerspectiveTable()
{
    int* pTable = gpnPerspectiveTable;
    for (int i = 0; i < 0x2000; ++i)
    {
        const int nX = i - 0x1000;
        pTable[i] = 0x2EE000 / (MIN(MAX(nX, -0xBB7), 0xBB7) - 0xBB8);
    }
    gnGlideSpriteScale = 0x100;
}

int gnProjectOriginX; // 0x00880B60

int gnProjectOriginY; // 0x00880B68

// 0x0050DD50
void __fastcall GLPERSPECTIVE_SetProjectOrigin(int nX, int nY)
{
    gnProjectOriginX = nX;
    gnProjectOriginY = nY;
}

// 0x0050DD60
void __fastcall GLPERSPECTIVE_PerspectiveTransform(int nX, int nY, int nZ, int* pScreenX, int* pScreenY)
{
    const int nA = ((nX - gnProjectOriginX) * 24) >> 16;
    const int nB = ((nY - gnProjectOriginY) * 24) >> 16;
    const int nZScaled = nZ * 0x4CC;
    const int nSum = (nB + nA) * 0x2D4;
    const int nPerspective = gpnPerspectiveTable[(((nSum * 0x376 + (nZScaled << 9)) >> 20) - 0x1000) & 0x1FFF];
    *pScreenX = (((nB - nA) * nPerspective * 0x2D4) >> 20) + gnRenderWidth_007C9138 / 2;
    *pScreenY = ((((nZScaled * 0x376 - (nSum << 9)) >> 10) * nPerspective) >> 20) + gnRenderHeight_007C913C / 2 - 0x20;
}

static int* gpnPerspectiveTable;                                                                   // 0x00880B6C

// 0x0050DE10
void __fastcall GLPERSPECTIVE_ProjectToScreenScaled(int nX, int nY, int nZ, int* pScreenX, int* pScreenY, int bLarge)
{
    const int* pTable = gpnPerspectiveTable;
    const int nA = ((nX - gnProjectOriginX) * 24) >> 16;
    const int nB = ((nY - gnProjectOriginY) * 24) >> 16;
    const int nSum = (nB + nA) * 0x2D4;
    const int nHeight = (nSum * -512) >> 10;
    const int nAngle = (nSum * 0x376) >> 20;
    const int nPerspective = pTable[(nAngle - 0x1000) & 0x1FFF];
    const int nTop = (nHeight * nPerspective) >> 20;
    *pScreenX = (((nB - nA) * nPerspective * 0x2D4) >> 20) + gnRenderWidth_007C9138 / 2;
    *pScreenY = nTop + gnRenderHeight_007C913C / 2 - 0x10;
    const int nScale = nTop - (((nHeight + 0x37400) * gpnPerspectiveTable[(nAngle - 0xF80) & 0x1FFF]) >> 20);
    if (bLarge)
    {
        gnGlideSpriteScale = (nScale * 0x4CC) >> 10;
    }
    else
    {
        gnGlideSpriteScale = (nScale * 0x466) >> 10;
    }
}
