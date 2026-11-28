#include "D2Win.h"
#include "D2GameTypes.h"

#include "D2WinTypes.h"

#include "D2CelContext.h"

#include "D2WinControls.h"

#include "D2StormTypes.h"
#include "FogApi.h"
#include "D2CMPApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

struct D2WinControlStrc;

struct Unicode;

typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

enum D2ControlTypes
{
    D2WIN_IMAGE = 2,
    D2WIN_TYPE_5 = 5,
    D2WIN_TYPE_6 = 6,
};


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

struct D2AnimatedImageDescriptor
{
    D2CelFileStrc** ppCellFile1;
    D2CelFileStrc** ppCellFile2;
    int eDrawMode;
    int nAnimSpeed;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

int __fastcall ANIMIMAGE_ShouldMouseInputBeHandled(D2WinControlStrc* pControl);                             // 0x005003A0

D2CelStrc* __stdcall CelGetHandle(D2GfxDataStrc* pContext);                                        // 0x00601840

int __stdcall sub_004F6480(D2GfxDataStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

static int ANIMIMAGE_UpdateState(D2WinAnimImageStrc* pAnimImage); // 0x00500480

extern tagPOINT gtMousePosition;                                                                    // 0x007D55A4

int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl); // 0x004F9210

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

void __stdcall CONTROL_RemoveFromList(void* pArg); // 0x004F9310

// 0x00500300
void __fastcall ANIMIMAGE_Destroy(void* pArg)
{
    CONTROL_RemoveFromList(pArg);
}

// 0x00500310
extern "C" int __fastcall D2Win_10106(D2WinAnimImageStrc* ptAnim)
{
    D2_ASSERT(ptAnim->controlHeader.eType == D2WIN_IMAGE, 0x50);
    return ptAnim->nAnimType;
}

// 0x00500340
int __fastcall D2Win_10104(D2WinAnimImageStrc* ptAnim)
{
    D2_ASSERT(ptAnim->controlHeader.eType == 2, 92);

    if (ptAnim->nAnimType == 3)
    {
        ptAnim->nAnimType = 4;
        ptAnim->nFrame = 0;
        ptAnim->dwStartTickCount = GetTickCount();
    }
    else if (ptAnim->nAnimType == 2 || ptAnim->nAnimType == 4)
    {
        return 0;
    }

    return 1;
}

// 0x00500480
static int ANIMIMAGE_UpdateState(D2WinAnimImageStrc* pAnimImage)
{
    D2_ASSERT(pAnimImage->controlHeader.eType == 2, 0x9A);

    if (!pAnimImage->pAnimatedImageDescriptor)
        return 0;

    int nAnimType = pAnimImage->nAnimType;
    const int nOldAnimType = nAnimType;
    if (nAnimType == 0 || nAnimType == 1)
    {
        nAnimType = ANIMIMAGE_ShouldMouseInputBeHandled(&pAnimImage->controlHeader) != 0;
        pAnimImage->nAnimType = nAnimType;
        if (nOldAnimType != nAnimType)
        {
            SMSGHANDLER_PARAMS msg;
            msg.hWnd = pAnimImage;
            msg.lParam = nAnimType == 1;
            if (pAnimImage->field_58)
                pAnimImage->field_58(&msg);
        }
    }

    int nMaxFrames = 1;
    D2CelFileStrc** ppCellFile = pAnimImage->pAnimatedImageDescriptor[pAnimImage->nAnimType].ppCellFile1;
    if (ppCellFile && *ppCellFile)
        nMaxFrames = CelFileGetCelsPerDirection(*ppCellFile);

    nAnimType = pAnimImage->nAnimType;
    switch (pAnimImage->nAnimType)
    {
    case 4:
        if (pAnimImage->nFrame >= nMaxFrames - 2)
        {
            pAnimImage->nAnimType = 1;
            pAnimImage->nFrame = 0;
            pAnimImage->dwStartTickCount = GetTickCount();
        }
        break;
    case 2:
        if (pAnimImage->nFrame >= nMaxFrames - 2)
        {
            pAnimImage->nAnimType = 3;
            pAnimImage->nFrame = 0;
            pAnimImage->dwStartTickCount = GetTickCount();
        }
        break;
    }

    if (nAnimType != pAnimImage->nAnimType)
    {
        D2CelFileStrc** ppNewCellFile = pAnimImage->pAnimatedImageDescriptor[pAnimImage->nAnimType].ppCellFile1;
        if (ppNewCellFile && *ppNewCellFile)
            CelFileGetCelsPerDirection(*ppNewCellFile);
    }

    if (pAnimImage->nFrame > nMaxFrames)
    {
        pAnimImage->nFrame = 0;
        pAnimImage->dwStartTickCount = GetTickCount();
    }

    return 1;
}

int __fastcall ANIMIMAGE_Draw(D2WinControlStrc* pControl);

// 0x00500790
int __stdcall ANIMIMAGE_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinAnimImageStrc* pAnimImage = (D2WinAnimImageStrc*)pMsg->hWnd;
    D2_ASSERT(pAnimImage->controlHeader.eType == 2, 0x15A);
    int nResult;
    if (pAnimImage->controlHeader.field_34)
        nResult = pAnimImage->controlHeader.field_34(pMsg);
    else
        nResult = 0;
    if (nResult)
    {
        if (pAnimImage->nAnimType == 3)
        {
            pAnimImage->nAnimType = 4;
            pAnimImage->nFrame = 0;
            pAnimImage->dwStartTickCount = GetTickCount();
        }
        else if (pAnimImage->nAnimType == 1)
        {
            pAnimImage->nAnimType = 2;
            pAnimImage->nFrame = 0;
            pAnimImage->dwStartTickCount = GetTickCount();
        }
    }
    return nResult;
}

// 0x00500850
D2WinAnimImageStrc* __fastcall ANIMIMAGE_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, unsigned int nAnimSpeed, D2WinMsgHandler pfnOnClick, D2AnimatedImageDescriptor* pDescriptor, int eDrawMode, D2WinMsgHandler pfnField58)
{
    D2WinAnimImageStrc* pAnimImage = (D2WinAnimImageStrc*)FOG_Alloc(sizeof(D2WinAnimImageStrc), ".\\D2WinAnimImage.cpp", 0x1C, 0);
    memset(pAnimImage, 0, sizeof(D2WinAnimImageStrc));
    pAnimImage->controlHeader.eType = 2;
    pAnimImage->controlHeader.dwFlags |= gdwBitMasks[0];
    pAnimImage->controlHeader.dwFlags |= gdwBitMasks[2];
    pAnimImage->controlHeader.pCellFile = pCellFile;
    pAnimImage->controlHeader.nImageX = nX;
    pAnimImage->controlHeader.nImageY = nY;
    pAnimImage->controlHeader.nWidth = nWidth;
    pAnimImage->controlHeader.nHeight = nHeight;
    pAnimImage->controlHeader.pfDraw = ANIMIMAGE_Draw;
    pAnimImage->controlHeader.pNext = 0;
    pAnimImage->controlHeader.pfHandleMouseDown = ANIMIMAGE_HandleMouseDown;
    pAnimImage->controlHeader.pfHandleMouseUp = 0;
    pAnimImage->controlHeader.pfHandleCharInput = 0;
    pAnimImage->controlHeader.pfHandleVirtualKeyInput = 0;
    pAnimImage->controlHeader.field_34 = pfnOnClick;
    pAnimImage->pAnimatedImageDescriptor = pDescriptor;
    pAnimImage->nAnimSpeed = nAnimSpeed;
    pAnimImage->nFrame = 0;
    pAnimImage->dwStartTickCount = GetTickCount();
    pAnimImage->nAnimType = 0;
    if (pDescriptor)
        pAnimImage->controlHeader.pfShouldMouseInputBeHandled = ANIMIMAGE_ShouldMouseInputBeHandled;
    if (!eDrawMode)
        pAnimImage->eDrawMode = 5;
    else
        pAnimImage->eDrawMode = eDrawMode;
    pAnimImage->field_58 = pfnField58;
    pAnimImage->bIsRunning = 1;
    CONTROL_AppendToList(&pAnimImage->controlHeader);
    return pAnimImage;
}

// 0x005005B0
int __fastcall ANIMIMAGE_Draw(D2WinControlStrc* pControl)
{
    D2WinAnimImageStrc* pAnimImage = (D2WinAnimImageStrc*)pControl;
    D2_ASSERT(pAnimImage->controlHeader.eType == 2, 0xF9);

    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.nDirection = 0;

    if (!pAnimImage->controlHeader.pCellFile && !pAnimImage->pAnimatedImageDescriptor)
        return 1;

    int nX = pAnimImage->controlHeader.nImageX;
    int nY = pAnimImage->controlHeader.nImageY;
    ANIMIMAGE_UpdateState(pAnimImage);

    D2CelFileStrc* pCellFile1 = 0;
    D2CelFileStrc* pCellFile2 = 0;
    int nAnimDrawMode;
    int nDrawMode;
    int nFrameCount;
    int nAnimSpeed;
    if (pAnimImage->pAnimatedImageDescriptor)
    {
        D2CelFileStrc** ppCellFile1 = pAnimImage->pAnimatedImageDescriptor[pAnimImage->nAnimType].ppCellFile1;
        D2CelFileStrc** ppCellFile2 = pAnimImage->pAnimatedImageDescriptor[pAnimImage->nAnimType].ppCellFile2;
        if (ppCellFile1)
            pCellFile1 = *ppCellFile1;
        if (ppCellFile2)
            pCellFile2 = *ppCellFile2;
        nDrawMode = pAnimImage->pAnimatedImageDescriptor[pAnimImage->nAnimType].eDrawMode;
        nAnimDrawMode = pAnimImage->eDrawMode;
        nFrameCount = CelFileGetCelsPerDirection(pCellFile1);
        nAnimSpeed = pAnimImage->pAnimatedImageDescriptor[pAnimImage->nAnimType].nAnimSpeed;
    }
    else
    {
        pCellFile1 = pAnimImage->controlHeader.pCellFile;
        pCellFile2 = 0;
        nAnimDrawMode = pAnimImage->eDrawMode;
        nDrawMode = nAnimDrawMode;
        nFrameCount = CelFileGetCelsPerDirection(pCellFile1);
        nAnimSpeed = pAnimImage->nAnimSpeed;
        tContext.pCelFile = pCellFile1;
        tContext.nDirection = 0;
        tContext.nFrame = 0;
        D2CelStrc* pCel = CelGetHandle(&tContext);
        nY -= CelGetOffsetY(pCel);
        nX -= CelGetOffsetX(pCel);
    }

    if (pCellFile1)
    {
        tContext.pCelFile = pCellFile1;
        tContext.nFrame = pAnimImage->nFrame;
        sub_004F6480(&tContext, nX, nY, -1, nAnimDrawMode, 0);
    }

    if (pCellFile2)
    {
        tContext.pCelFile = pCellFile2;
        tContext.nFrame = pAnimImage->nFrame;
        sub_004F6480(&tContext, nX, nY, -1, nDrawMode, 0);
    }

    if (nAnimSpeed && nFrameCount > 1 && pAnimImage->bIsRunning)
    {
        const int nFrameDivisor = 1000 * nAnimSpeed / 25;
        switch (pAnimImage->nAnimType)
        {
        case 2:
        case 4:
            pAnimImage->nFrame = (GetTickCount() - pAnimImage->dwStartTickCount) / nFrameDivisor;
            pAnimImage->nFrame = pAnimImage->nFrame < nFrameCount - 1 ? pAnimImage->nFrame : nFrameCount - 1;
            break;
        default:
            pAnimImage->nFrame = (GetTickCount() - pAnimImage->dwStartTickCount) / nFrameDivisor % (nFrameCount - 1);
            break;
        }
    }

    return 1;
}

// 0x005003A0
int __fastcall ANIMIMAGE_ShouldMouseInputBeHandled(D2WinControlStrc* pControl)
{
    D2WinAnimImageStrc* pAnimImage = (D2WinAnimImageStrc*)pControl;
    D2_ASSERT(pAnimImage->controlHeader.eType == 2, 0x73);

    int nY = gtMousePosition.y;
    int nX = gtMousePosition.x;

    D2CelFileStrc* pCellFile = 0;
    D2CelFileStrc** ppCellFile = pAnimImage->pAnimatedImageDescriptor[pAnimImage->nAnimType].ppCellFile1;
    if (ppCellFile)
    {
        pCellFile = *ppCellFile;
    }

    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCelFile = pCellFile;
    tContext.nDirection = 0;
    tContext.nFrame = 0;

    D2CelStrc* pCel = CelGetHandle(&tContext);
    const int nImageX = pAnimImage->controlHeader.nImageX;
    const int nImageY = pAnimImage->controlHeader.nImageY;
    const int nWidth = CelGetWidth(pCel);
    const int nHeight = CelGetHeight(pCel);
    nX -= CelGetOffsetX(pCel);
    nY -= CelGetOffsetY(pCel);
    return nX >= nImageX && nY >= nImageY - nHeight && nX < nImageX + nWidth && nY < nImageY;
}

// 0x00500810
int __stdcall ANIMIMAGE_SetIsRunning(D2WinAnimImageStrc* ptAnim, int bIsRunning)
{
    D2_ASSERT(ptAnim->controlHeader.eType == 2, 0x183);
    ptAnim->bIsRunning = bIsRunning;
    return 1;
}

extern "C" const char* gData_0072DF84[15] = { // 0x0072DF84
    "English",
    "Spanish",
    "German",
    "French",
    "Portuguese",
    "Italian",
    "Japanese",
    "Korean",
    "Simplified Chinese",
    "Traditional Chinese",
    "Polish",
    "Russian",
    "English with Korean Chat",
    "Unknown",
    "14"
};
