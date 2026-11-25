#include "D2SkillIds.h"
#include "D2GameTypes.h"

#include "D2GfxTypes.h"

#include "D2MultiTypes.h"

#include "D2Structs.h"

#include "D2Txt.h"

#include "D2StatIds.h"

#include "D2Win.h"

#include "D2StormTypes.h"

#include "D2Win32Types.h"

#include "D2CelContext.h"

#include "D2CmpTypes.h"

#include "D2WinTypes.h"

#include "D2WinControls.h"

#include "D2Unicode.h"

#include "D2ClientTypes.h"
#include "D2WinPopupLine.h"
#include "D2WinListData.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CelFileStrc;

struct D2WinControlStrc;

struct D2WinImageClickRectStrc;

struct D2UnitStrc;

struct D2CofDataStrc;

struct D2WinControl004FD110Strc;

struct Unicode;

struct tagRECT;

struct D2WinImage2Strc;

struct D2WinTimerStrc;

struct D2WinCommandRegisterStrc;

struct D2WinListDataStrc;

struct D2WinListStrc;

struct D2WinAccountListDataStrc;

struct D2WinAccountListStrc;

struct D2WinPopUpLineStrc;

struct D2CelContextStrc;

struct D2CofNodeStrc;

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

struct D2WinControl004FD110Strc
{
    int eType;
    D2CelFileStrc* pCellFile;
    unsigned char f_8[0x38];
    int nFrame;
};

int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pCellFile); // 0x006019F0

enum D2ControlTypes
{
    D2WIN_EDITBOX = 1,
    D2WIN_IMAGE = 2,
    D2WIN_ANIMIMAGE = 3,
    D2WIN_TEXTBOX = 4,
    D2WIN_SCROLLBAR = 5,
    D2WIN_BUTTON = 6,
    D2WIN_LIST = 7,
    D2WIN_TIMER = 8,
    D2WIN_SMACK = 9,
    D2WIN_PROGRESSBAR = 10,
    D2WIN_POPUP = 11,
    D2WIN_ACCOUNTLIST = 12,
    D2WIN_IMAGE2 = 13,
};

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

struct D2WinCommandRegisterStrc
{
    int nType;
    int nId;
    D2WinMsgHandler pCallback;
};



extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __stdcall D2GFX_UtilRect(tagRECT* pRect, unsigned char nPaletteIndex); // 0x004F62A0

void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, int eDrawMode); // 0x004F6300

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

void __fastcall WREGISTER_RegisterCommand(void* hWnd, int nType, int nId, D2WinMsgHandler pCallback); // 0x00506C40

void __fastcall WREGISTER_UnregisterCommand(void* hWnd, int nType, int nId, D2WinMsgHandler pCallback); // 0x00506CF0

extern void* sghPentagram; // 0x0087E96C

struct D2WinImageClickRectStrc
{
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    int (__stdcall* pCallback)(SMSGHANDLER_PARAMS* pMsg);
};

extern D2CofNodeStrc* gpCofNodeList; // 0x0087E83C

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

enum DrawMode
{
    DRAWMODE_NORMAL = 5,
};

void __stdcall TEXTURE_CelDrawClipped(D2CelContextStrc* pData, int nXPos, int nYPos, void* pCropRect, int eDrawMode); // 0x004F6510

int __fastcall D2Win_10058_0(D2WinControlStrc* pControl, const Unicode* pText, int nLineNum, int nColumn);         // 0x004FB790

int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl);                                             // 0x004F9210

int __stdcall IMAGE2_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg);                                             // 0x004FD5D0

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

void __stdcall CONTROL_RemoveFromList(void* pArg); // 0x004F9310

// 0x004FD0F0
void __fastcall IMAGE_Destroy(void* pArg)
{
    CONTROL_RemoveFromList(pArg);
}

// 0x004FD100
void __fastcall IMAGE2_Destroy(void* pArg)
{
    CONTROL_RemoveFromList(pArg);
}

// build: symbol ?IMAGE_Draw@@YIHPAUD2WinControlStrc@@@Z 0x004FD470

// 0x004FD110
int __stdcall IMAGE_SetFrame(D2WinControl004FD110Strc* pControl, int nFrame)
{
    D2_ASSERT(pControl->eType == 2, 0x8B);
    const int nFrames = CelFileGetCelsPerDirection(pControl->pCellFile);
    if (nFrame > nFrames - 1)
    {
        nFrame = nFrames - 1;
    }
    if (nFrame < 0)
    {
        nFrame = 0;
    }
    pControl->nFrame = nFrame;
    return 1;
}

unsigned int gdwTimeoutTickCount; // 0x00841B74

// 0x004FD1F0
int __fastcall IMAGE2_Draw(D2WinControlStrc* pControl)
{
    D2WinImage2Strc* pImage = (D2WinImage2Strc*)pControl;

    D2_ASSERT(pImage->controlHeader.eType == D2WIN_IMAGE, 0xB6);

    if (!(pImage->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pImage->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    if (pImage->controlHeader.pCellFile)
    {
        const int nX = pImage->controlHeader.nImageX;
        const int nBaseY = pImage->controlHeader.nImageY - pImage->controlHeader.nHeight + 1;
        const int nColumns = (pImage->controlHeader.nWidth + 255) >> 8;
        const int nRows = ((pImage->controlHeader.nHeight + 255) >> 8) - 1;

        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        tContext.pCellFile = pImage->controlHeader.pCellFile;
        tContext.nDirection = 0;
        tContext.nFrame = pImage->nFrame;

        for (int i = 0; i < nRows; ++i)
        {
            for (int j = 0; j < nColumns; ++j)
            {
                sub_004F6480(&tContext, nX + 256 * j, nBaseY + 256 * (i + 1), -1, pImage->eDrawMode, 0);
                ++tContext.nFrame;
            }
        }

        if (nRows >= 0)
        {
            for (int i = 0; i < nColumns; ++i)
            {
                sub_004F6480(&tContext, nX + 256 * i, pImage->controlHeader.nImageY, -1, pImage->eDrawMode, 0);
                ++tContext.nFrame;
            }
        }
    }

    return 1;
}

// build: symbol ?D2Win_10058@* 0x004FCD90
int __fastcall D2Win_10058(D2WinControlStrc* pControl, const Unicode* pText, int a3, int nColumn)
{
    return D2Win_10058_0(pControl, pText, a3, nColumn);
}

// 0x004FD340
static void __stdcall IMAGE_DrawTiled(const D2CropRectStrc* pDst, const D2CropRectStrc* pSrc, D2CelContextStrc* pGfxData)
{
    const int nSrcWidth = pSrc->nX1 - pSrc->nX0;
    const int nDstWidth = pDst->nX1 - pDst->nX0;
    const int nSrcHeight = pSrc->nY1 - pSrc->nY0;
    const int nDstHeight = pDst->nY1 - pDst->nY0;
    if (nSrcWidth == nDstWidth && nSrcHeight == nDstHeight)
    {
        TEXTURE_CelDrawClipped(pGfxData, pDst->nX0 - pSrc->nX0, pDst->nY1 - pSrc->nY1 + 256, (void*)pDst, DRAWMODE_NORMAL);
        return;
    }

    const int nColumns = (nDstWidth + nSrcWidth - 1) / nSrcWidth;
    const int nRows = (nDstHeight + nSrcHeight - 1) / nSrcHeight;
    int nY = pDst->nY0 - pSrc->nY0 + 256;
    D2CropRectStrc tRect;
    for (int j = 0; j < nRows; ++j)
    {
        int nX = pDst->nX0 - pSrc->nX0;
        for (int i = 0; i < nColumns; ++i)
        {
            tRect.nX0 = D2_MAX(pDst->nX0, pSrc->nX0 + nX);
            tRect.nX1 = D2_MIN(pDst->nX1, tRect.nX0 + nSrcWidth);
            tRect.nY0 = D2_MAX(pDst->nY0, pSrc->nY0 + nY - 256);
            tRect.nY1 = D2_MIN(pDst->nY1, tRect.nY0 + nSrcHeight);
            TEXTURE_CelDrawClipped(pGfxData, nX, nY, &tRect, DRAWMODE_NORMAL);
            nX += nSrcWidth;
        }
        nY += nSrcHeight;
    }
}

// build: symbol ?SKILLS_GetSkillValue@* 0x005C33D0
int __fastcall SKILLS_GetSkillValue(int nSkillId)
{
    switch (nSkillId)
    {
    case SKILL_PENETRATE:
        return 0xA;
    case SKILL_IMMOLATIONARROW:
        return 0xC;
    case SKILL_METEOR:
        return 0xB;
    }
    return 0;
}

// 0x004FD470
int __fastcall IMAGE_Draw(D2WinControlStrc* pControl)
{
    D2WinImageStrc* pImage = (D2WinImageStrc*)pControl;

    D2_ASSERT(pImage->controlHeader.eType == D2WIN_IMAGE, 0x10F);

    const int nBorderX = pImage->field_4C;
    const int nBorderY = pImage->field_50;
    D2CelContextStrc tGfxData;
    memset(&tGfxData, 0, sizeof(tGfxData));
    tGfxData.pCellFile = pImage->controlHeader.pCellFile;
    tGfxData.nDirection = 0;
    tGfxData.nFrame = 0;

    int nX[4];
    int nY[4];
    int nSrcY[4];
    int nSrcX[4];
    nSrcX[0] = 0;
    nSrcX[1] = nBorderX;
    nSrcX[2] = 256 - nBorderX;
    nSrcX[3] = 256;
    nSrcY[0] = 0;
    nSrcY[1] = nBorderY;
    nSrcY[2] = 256 - nBorderY;
    nSrcY[3] = 256;
    nX[0] = pImage->controlHeader.nImageX;
    nX[1] = pImage->controlHeader.nImageX + nBorderX;
    nX[2] = pImage->controlHeader.nImageX + pImage->controlHeader.nWidth - nBorderX;
    nX[3] = pImage->controlHeader.nImageX + pImage->controlHeader.nWidth;
    nY[0] = pImage->controlHeader.nImageY - pImage->controlHeader.nHeight;
    nY[1] = pImage->controlHeader.nImageY - pImage->controlHeader.nHeight + nBorderY;
    nY[2] = pImage->controlHeader.nImageY - nBorderY;
    nY[3] = pImage->controlHeader.nImageY;
    D2CropRectStrc tDst;
    D2CropRectStrc tSrc;
    for (int j = 0; j < 3; ++j)
    {
        tSrc.nY0 = nSrcY[j];
        tSrc.nY1 = nSrcY[j + 1];
        for (int i = 0; i < 3; ++i)
        {
            tDst.nX0 = nX[i];
            tDst.nX1 = nX[i + 1];
            tDst.nY0 = nY[j];
            tDst.nY1 = nY[j + 1];
            tSrc.nX0 = nSrcX[i];
            tSrc.nX1 = nSrcX[i + 1];
            IMAGE_DrawTiled(&tDst, &tSrc, &tGfxData);
        }
    }

    return 1;
}

// 0x004FD5A0
static inline int IMAGE_IsInClickRect(const D2WinImageClickRectStrc* pClickRect, int nX, int nY)
{
    const int nTop = pClickRect->nY;
    if (nX >= pClickRect->nX && nY >= nTop - pClickRect->nHeight && nX < pClickRect->nX + pClickRect->nWidth && nY < nTop)
    {
        return 1;
    }
    return 0;
}

static inline void SUNITDMG_ApplyDamageTargetAc(D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, STAT_ITEM_DAMAGETARGETAC, 0);
    if (nValue)
    {
        int nNew = STATLIST_UnitGetStatValue(pDefender, STAT_ARMORCLASS, 0) + nValue;
        if (nNew < 0)
        {
            nNew = 0;
        }
        STATLIST_SetUnitStat(pDefender, STAT_ARMORCLASS, nNew, 0);
    }
}

int __stdcall sub_M118_Emit_004FD5A0(const D2WinImageClickRectStrc* pClickRect, int nX, int nY)
{
    while (pClickRect && pClickRect->pCallback)
    {
        if (IMAGE_IsInClickRect(pClickRect, nX, nY))
        {
            return 1;
        }
        ++pClickRect;
    }
    return 0;
}

void __stdcall sub_M118_Emit_0057B7A0(D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    SUNITDMG_ApplyDamageTargetAc(pAttacker, pDefender);
}

tagPOINT gtMousePosition; // 0x007D55A4
struct Point { int x, y; };

// 0x004FD5D0
int __stdcall IMAGE2_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinImage2Strc* pImage = (D2WinImage2Strc*)pMsg->hWnd;

    D2_ASSERT(pImage->controlHeader.eType == D2WIN_IMAGE, 0x159);

    if (!(pImage->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pImage->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    const int nX = gtMousePosition.x - pImage->controlHeader.nImageX;
    const int nY = gtMousePosition.y + pImage->controlHeader.nHeight - pImage->controlHeader.nImageY;

    D2WinImageClickRectStrc* pClickRect = pImage->pClickRect;
    if (pClickRect)
    {
        for (int i = 0; pClickRect[i].pCallback; ++i)
        {
            const int nRectX = pClickRect[i].nX;
            const int nRectY = pClickRect[i].nY;
            if (nX >= nRectX && nY >= nRectY - pClickRect[i].nHeight && nX < nRectX + pClickRect[i].nWidth && nY < nRectY)
            {
                return pClickRect[i].pCallback(pMsg);
            }
        }
    }

    if (((D2WinImage2Strc*)pMsg->hWnd)->controlHeader.field_34)
    {
        return ((D2WinImage2Strc*)pMsg->hWnd)->controlHeader.field_34(pMsg);
    }

    return 0;
}

// 0x00506DA0
void __fastcall WREGISTER_RegisterCommands(void* hWnd, D2WinCommandRegisterStrc* pCommandRegister, unsigned int nCommands)
{
    D2_ASSERT(hWnd, 0x4D);

    for (unsigned int i = 0; i < nCommands; ++i)
    {
        WREGISTER_RegisterCommand(hWnd, pCommandRegister[i].nType, pCommandRegister[i].nId, pCommandRegister[i].pCallback);
    }
}

// 0x00506E00
void __fastcall WREGISTER_UnregisterCommands(void* hWnd, D2WinCommandRegisterStrc* pCommandRegister, unsigned int nCommands)
{
    D2_ASSERT(hWnd, 0x5A);

    for (unsigned int i = 0; i < nCommands; ++i)
    {
        WREGISTER_UnregisterCommand(hWnd, pCommandRegister[i].nType, pCommandRegister[i].nId, pCommandRegister[i].pCallback);
    }
}

// 0x004FD070
int __stdcall IMAGE_SetCellFile(D2WinImageStrc* pImage, D2CelFileStrc* pCellFile, D2WinImageClickRectStrc* pClickRect)
{
    D2_ASSERT(pImage->controlHeader.eType == 2, 0x5F);
    pImage->controlHeader.pCellFile = pCellFile;
    pImage->pClickRect = pClickRect;
    return 1;
}

// 0x004FD6C0
D2WinImage2Strc* __fastcall IMAGE2_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, D2WinMsgHandler a6, D2WinImageClickRectStrc* pClickRect, D2WinMsgHandler pfHandleVirtualKeyInput)
{
    D2WinImage2Strc* pImage = (D2WinImage2Strc*)FOG_Alloc(sizeof(D2WinImage2Strc), ".\\Src\\D2WinImage.cpp", 0x1D, 0);
    memset(pImage, 0, sizeof(D2WinImage2Strc));
    pImage->controlHeader.eType = 2;
    pImage->controlHeader.dwFlags |= gdwBitMasks[0];
    pImage->controlHeader.dwFlags |= gdwBitMasks[2];
    pImage->controlHeader.pCellFile = pCellFile;
    pImage->controlHeader.nImageX = nX;
    pImage->controlHeader.nImageY = nY;
    pImage->controlHeader.nWidth = nWidth;
    pImage->controlHeader.nHeight = nHeight;
    pImage->controlHeader.pfDraw = IMAGE2_Draw;
    pImage->controlHeader.pNext = 0;
    pImage->controlHeader.pfHandleMouseDown = IMAGE2_HandleMouseDown;
    pImage->controlHeader.pfHandleMouseUp = 0;
    pImage->controlHeader.pfHandleCharInput = 0;
    pImage->controlHeader.pfHandleVirtualKeyInput = pfHandleVirtualKeyInput;
    pImage->controlHeader.field_34 = a6;
    pImage->pClickRect = pClickRect;
    pImage->nFrame = 0;
    pImage->eDrawMode = 5;
    CONTROL_AppendToList(&pImage->controlHeader);
    return pImage;
}

// 0x004FD770
D2WinImageStrc* __fastcall IMAGE_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, int a6, int a7)
{
    D2WinImageStrc* pImage = (D2WinImageStrc*)FOG_Alloc(sizeof(D2WinImageStrc), ".\\Src\\D2WinImage.cpp", 0x3B, 0);
    memset(pImage, 0, sizeof(D2WinImageStrc));
    pImage->controlHeader.eType = 2;
    pImage->controlHeader.dwFlags |= gdwBitMasks[0];
    pImage->controlHeader.dwFlags |= gdwBitMasks[2];
    pImage->controlHeader.pCellFile = pCellFile;
    pImage->controlHeader.nImageX = nX;
    pImage->controlHeader.nImageY = nY;
    pImage->controlHeader.nWidth = nWidth;
    pImage->controlHeader.nHeight = nHeight;
    pImage->controlHeader.pfDraw = IMAGE_Draw;
    pImage->controlHeader.pNext = 0;
    pImage->controlHeader.pfHandleMouseDown = IMAGE2_HandleMouseDown;
    pImage->controlHeader.pfHandleMouseUp = 0;
    pImage->controlHeader.pfHandleCharInput = 0;
    pImage->controlHeader.pfHandleVirtualKeyInput = 0;
    pImage->controlHeader.field_34 = 0;
    pImage->pClickRect = 0;
    pImage->nFrame = 0;
    pImage->eDrawMode = 5;
    pImage->field_4C = a6;
    pImage->field_50 = a7;
    CONTROL_AppendToList(&pImage->controlHeader);
    return pImage;
}

// 0x004FD0B0
int __stdcall IMAGE_SetCoordinates(D2WinImageStrc* ptImageData, int nX, int nY)
{
    D2_ASSERT(ptImageData->controlHeader.eType == 2, 0x6C);
    ptImageData->controlHeader.nImageX = nX;
    ptImageData->controlHeader.nImageY = nY;
    return 1;
}

// 0x004FD170
int __stdcall IMAGE_ForceNormalDrawMode(D2WinImageStrc* ptImageData, int nUnused)
{
    D2_ASSERT(ptImageData->controlHeader.eType == 2, 0x9D);
    ptImageData->eDrawMode = 5;
    return 1;
}

// 0x004FD1B0
int __stdcall IMAGE_GetFrameCount(D2WinImageStrc* ptImageData)
{
    D2_ASSERT(ptImageData->controlHeader.eType == 2, 0xA9);
    return CelFileGetCelsPerDirection(ptImageData->controlHeader.pCellFile);
}

#include "gen/data/Source/D2Win/Src/D2WinImage.inc"
