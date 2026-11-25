// Built /GS-: the buffer in 0x004680B0 has no security cookie.
#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientTypes.h"
#include "D2CelContext.h"
#include "D2Constants.h"
#include "D2StormTypes.h"
#include "D2Win32Types.h"
#include "D2WinSplitText.h"

struct D2MsgHandlerEntryStrc;

struct D2PanelAnimEntryStrc;

enum D2C_W04CursorConstants
{
    NUM_CURSOR_CELLS = 7,
};

struct D2PanelAnimEntryStrc
{
    void* pData;
    void (__cdecl* pfnDraw)();
    const char* f_8;
    char unk0x0C[0x10];
};

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...); // 0x006CC468

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

void __fastcall SCMD_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

extern D2MsgHandlerEntryStrc gaCursorMsgHandlers[]; // 0x00711FEC

extern D2PanelAnimEntryStrc gaPanelAnim[]; // 0x00712020

extern int gnScreenWidth; // 0x0071146C

int gbCursorVisible;                                                                                      // 0x007A6B08

static int gnCursorY;                                                                               // 0x007A6AAC

static int gnCursorX;                                                                               // 0x007A6AB0

static int gnCursorOffsetX;                                                                               // 0x007A6AB4

static int gnCursorAnim;                                                                               // 0x007A6ADC

static int gnCursorAnimFrame;                                                                               // 0x007A6AE0

static int gdwLastMouseMoveTick; // 0x007A6AE8

static int gnCursorState;                                                                               // 0x007A6AF0

static void* gapCursorCels[NUM_CURSOR_CELLS];                                                      // 0x007A6AC0

static unsigned short gwGlobal_007A6AE4; // 0x007A6AE4

#define NUM_CURSOR_MSG_HANDLERS 3

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

struct D2CelFileStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

D2CelFileStrc* gpCursorCel;        // 0x007A6AD8

struct D2UnitStrc;


extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __cdecl CURSOR_UpdateCursor();                                                                // 0x00468310

int __fastcall GFXUTIL_InitUnitCelContext(D2CelContextStrc* pToken, D2UnitStrc* pUnit, int nArg34, int nArg40, int nArg0, int* pItemId, unsigned char nComponent, int nMode); // 0x004DBB50

int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3);                // 0x006001F0

unsigned int __stdcall CelGetWidth(D2CelStrc* pCel);                                                        // 0x006018C0

unsigned int __stdcall CelGetHeight(D2CelStrc* pCel);                                                       // 0x006018F0

int __fastcall GFX_DrawItemCel(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80

static int gnCursorMaxY;                                                                               // 0x007A6AA8

static int gnCursorMaxX;                                                                               // 0x007A6AB8

static D2UnitStrc* gpCursorItem;                                                                   // 0x007A6ABC

struct D2CursorAnimStrc;

extern D2CursorAnimStrc gaCursorAnim[CURSOR_ANIM_COUNT]; // 0x00712010

void __cdecl CURSOR_AdvanceCursorAnim(); // 0x004681C0

void __cdecl CURSOR_StepCursorAnim(); // 0x004682C0

static unsigned int gdwCursorAnimTick; // 0x007A6AEC

// 0x00467DF0
static inline int CURSOR_GetCursorAnimField00(int nIndex)
{
// build: symbol ?gnCursorAnimCount@* 0x007120D4
    D2_ASSERT(gnCursorAnimCount == CURSOR_ANIM_COUNT, 0x84);
    D2_ASSERT(nIndex < CURSOR_ANIM_COUNT, 0x85);
    return gaCursorAnim[nIndex].bAnimated;
}

int __stdcall sub_M121_Emit_00467DF0(int nIndex) { return CURSOR_GetCursorAnimField00(nIndex); }

// 0x00467E40
static int CURSOR_IsCursorAnimated(int nIndex)
{
// build: symbol ?gnCursorAnimCount@* 0x007120D4
    D2_ASSERT(gnCursorAnimCount == CURSOR_ANIM_COUNT, 0x8F);
    D2_ASSERT(nIndex < CURSOR_ANIM_COUNT, 0x90);
    return gaCursorAnim[nIndex].f_4;
}

// 0x00467E90
static int CURSOR_GetCursorAnimLength(int nIndex)
{
    D2_ASSERT(gnCursorAnimCount == CURSOR_ANIM_COUNT, 0x9A);
    D2_ASSERT(nIndex < CURSOR_ANIM_COUNT, 0x9B);
    return gaCursorAnim[nIndex].nFrames << 8;
}

// 0x00467EE0
static inline void CURSOR_SetCursorAnim(int nIndex)
{
    gnCursorAnim = nIndex;
    gnCursorAnimFrame = 0;
}

void __stdcall sub_M121_Emit_00467EE0(int nIndex) { CURSOR_SetCursorAnim(nIndex); }

// 0x00467EF0
void __stdcall CURSOR_MsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->wParam == 2)
    {
        gbCursorVisible = 0;
        sub_004F59F0(0);
    }
    else
    {
        gbCursorVisible = 0;
    }
    pMsg->bReturn = 0;
    pMsg->lResult = 0;
}

// 0x00467F20
void __stdcall CURSOR_HandleButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    gnCursorX = pMsg->nXpos;
    gnCursorY = pMsg->nYpos;
    gdwLastMouseMoveTick = GetTickCount();
    if (gnCursorState != 5 && gaPanelAnim[gnCursorAnim].pData)
    {
        gnCursorState = 5;
        gnCursorAnim = 4;
        gnCursorAnimFrame = 0;
    }
    pMsg->bReturn = 0;
}

// 0x00467FA0
void __stdcall CURSOR_HandleButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    gnCursorX = pMsg->nXpos;
    gnCursorY = pMsg->nYpos;
    gdwLastMouseMoveTick = GetTickCount();
    if (gnCursorState == 5)
    {
        gnCursorAnim = 5;
        gnCursorState = 1;
        gnCursorAnimFrame = 0;
    }
    pMsg->bReturn = 0;
}

// 0x00468000
void __fastcall CURSOR_SetGlobal7A6B08(int nValue)
{
    gbCursorVisible = nValue;
}

// 0x00468010
void __fastcall CURSOR_SetState(int nValue, int nArg)
{
    gpCursorItem = (D2UnitStrc*)nValue;
    gnCursorAnim = 6;
    gdwGlobal_007A6AE0 = nArg;
    gnCursorState = 6;
}

struct Unicode;

void __fastcall CURSOR_SetCursorPosition(int nA, int nB);                                                               // 0x00468770

extern "C" void _ReadWriteBarrier(void);

extern "C" __declspec(dllimport) __declspec(noalias) int __stdcall GetWindowRect(void* hWindow, tagRECT* pRect);

extern "C" __declspec(dllimport) int __stdcall GetSystemMetrics(int nIndex);

int __stdcall WINDOW_IsFullScreen(); // 0x004F5A30

void* __cdecl sub_004F59A0_GetWindow(); // 0x004F59A0

extern int gnCursorX_007A6AB0; // 0x007A6AB0

// 0x00468030
int __cdecl CURSOR_GetCursorFrame()
{
    return gdwGlobal_007A6AE0;
}

// 0x00468040
void __fastcall sub_00468040(int nArg, int nArg2)
{
    gpCursorItem = 0;
    gnCursorAnim = 6;
    gdwGlobal_007A6AE0 = nArg;
    gnCursorState = nArg2 ? 8 : 7;
}

// 0x00468070
void __fastcall CURSOR_SetCursorItemState(D2UnitStrc* pItem)
{
    gpCursorItem = pItem;
    gnCursorAnim = 5;
    if (!pItem)
    {
        gdwGlobal_007A6AE0 = 0;
        gnCursorState = 1;
    }
    else
    {
        gdwGlobal_007A6AE0 = 0;
        gnCursorState = 1;
        gnCursorState = 4;
    }
}

// 0x004680B0
int __fastcall CURSOR_InitCursor(int nArg)
{
    char szPath[0x50];
    gnCursorOffsetX = nArg;
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaCursorMsgHandlers, 3);
    for (int i = 0; i < NUM_CURSOR_CELLS; ++i)
    {
// build: symbol ?gszDataGlobal@* 0x006D4118
        wsprintfA(szPath, "%s\\UI\\CURSOR\\%s", gszDataGlobal, gaPanelAnim[i].f_8);
        gapCursorCels[i] = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
    gbCursorVisible = 1;
    gnCursorState = 1;
    gnCursorAnim = 5;
    gnCursorAnimFrame = 0;
    gwGlobal_007A6AE4 = 0;
    gdwLastMouseMoveTick = GetTickCount();
    gnCursorX = gnScreenWidth / 2;
    gnCursorY = gnScreenHeight / 2;
    return 1;
}

// 0x00468170
void __cdecl CURSOR_ShutdownCursor()
{
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaCursorMsgHandlers, NUM_CURSOR_MSG_HANDLERS);
    gbCursorVisible = 0;
    for (int i = 0; i < NUM_CURSOR_CELLS; ++i)
    {
        if (gapCursorCels[i])
        {
            ARCHIVE_FreeClientCellFile(gapCursorCels[i]);
            gapCursorCels[i] = 0;
        }
    }
}

extern "C" __declspec(dllimport) int __stdcall SetCursorPos(int nX, int nY);                               // 0x006CC4B4

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0

#define SEED_ROLL(pSeed, lSeed) \
    unsigned __int64 lSeed = (unsigned __int64)(pSeed)->nHighSeed + (unsigned __int64)(pSeed)->nLowSeed * 0x6AC690C5; \
    (pSeed)->nLowSeed = (unsigned int)lSeed; \
    (pSeed)->nHighSeed = (unsigned int)(lSeed >> 32);

static void __fastcall sub_00468750_SetMousePos(int nX, int nY)
{
    SetCursorPos(nX, nY);
    gnCursorX = nX;
    gnCursorY = nY;
}

// 0x004681C0
void __cdecl CURSOR_AdvanceCursorAnim()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;
    const int nIndex = gnCursorAnim;
    if (gnCursorState == 1)
    {
        SEED_ROLL(&pPlayer->pSeed, lSeed);
        if (((char)lSeed & 0x3F) < 0x10)
            gnCursorAnimFrame += 0x20;
    }
    else
    {
        gnCursorAnimFrame += gaCursorAnim[nIndex].nStep;
    }
    if (gnCursorAnimFrame < CURSOR_GetCursorAnimLength(nIndex))
        return;
    if (CURSOR_IsCursorAnimated(gnCursorAnim))
    {
        gnCursorAnimFrame -= CURSOR_GetCursorAnimLength(gnCursorAnim);
        return;
    }
    if (gnCursorState == 2)
    {
        gnCursorState = 4;
        gnCursorAnim = 3;
        gnCursorAnimFrame = 0;
        return;
    }
    if (gnCursorState == 5)
    {
        gnCursorState = 1;
        gnCursorAnim = 5;
        gnCursorAnimFrame = 0;
        return;
    }
    D2_ASSERT(false, 0x1E9);
}

// 0x004682C0
void __cdecl CURSOR_StepCursorAnim()
{
    gnCursorAnimFrame -= 0x40;
    if (gnCursorAnimFrame < 0)
    {
        if (CURSOR_IsCursorAnimated(gnCursorAnim))
        {
            gnCursorAnimFrame -= CURSOR_GetCursorAnimLength(gnCursorAnim);
            return;
        }
        gnCursorState = 1;
        gnCursorAnim = 5;
        gnCursorAnimFrame = 0;
    }
}

// 0x00468310
void __cdecl CURSOR_UpdateCursor()
{
    const unsigned int dwTick = GetTickCount();
    D2_ASSERT(gnCursorAnimCount == CURSOR_ANIM_COUNT, 0x84);
    D2_ASSERT(gnCursorAnim < CURSOR_ANIM_COUNT, 0x85);
    if (gaCursorAnim[gnCursorAnim].bAnimated && dwTick > gdwCursorAnimTick + 0x10)
    {
        gdwCursorAnimTick = dwTick;
        if (gnCursorState != 3)
        {
            CURSOR_AdvanceCursorAnim();
        }
        else
        {
            CURSOR_StepCursorAnim();
        }
    }
    if (gnCursorState == 1 && gdwLastMouseMoveTick + 5000 < dwTick)
    {
        gnCursorState = 2;
        gnCursorAnim = 2;
        gnCursorAnimFrame = 0;
    }
}

// 0x004683C0
void __cdecl CURSOR_DrawDefaultCursor()
{
    int nX = gnCursorX + gnCursorOffsetX;
    int nY = gnCursorY;
    if (nY < 0)
    {
        nY = 0;
    }
    else if (nY > gnScreenHeight - 1)
    {
        nY = gnScreenHeight - 1;
    }
    if (nX < gnCursorOffsetX)
    {
        nX = gnCursorOffsetX;
    }
    else if (nX > gnScreenWidth - gnCursorOffsetX - 1)
    {
        nX = gnScreenWidth - gnCursorOffsetX - 1;
    }
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gapCursorCels[gnCursorAnim];
    tContext.nDirection = 0;
    tContext.nFrame = gnCursorAnimFrame >> 8;
    sub_004F6480(&tContext, nX, nY, -1, 5, 0);
    CURSOR_UpdateCursor();
}

// 0x00468460
void __cdecl CURSOR_DrawCursorCel()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCursorCel;
    tContext.nFrame = gnCursorAnimFrame;
    const int nX = gnCursorX + gnCursorOffsetX;
    const int nY = gnCursorY + 0x21;
    tContext.nDirection = 0;
    sub_004F6480(&tContext, nX, nY, -1, 5, 0);
}

// 0x004684C0
void __cdecl CURSOR_DrawCursor()
{
    if (!gbCursorVisible)
    {
        return;
    }
    D2UnitStrc* pItem = gpCursorItem;
    if (pItem && pItem->dwUnitType == UNIT_ITEM && gnCursorState < 6 && gnCursorState < 8)
    {
        D2CelContextStrc tContext;
        int nOut;
        memset(&tContext, 0, sizeof(tContext));
        if (GFXUTIL_InitUnitCelContext(&tContext, pItem, 0, 0, 0, &nOut, 1, -1) && sub_006001F0(&tContext, 0, 1))
        {
            D2_ASSERT(tContext.pCel, 0x27D);
            GFX_DrawItemCel(gpCursorItem, gnCursorX - CelGetWidth(tContext.pCel) / 2 + gnCursorOffsetX,
                gnCursorY - CelGetHeight(tContext.pCel) / 2);
        }
    }
    else
    {
        gaPanelAnim[gnCursorAnim].pfnDraw();
    }
}

// 0x004685C0
void __cdecl CURSOR_PaintCursorItem()
{
    if (!gbCursorVisible)
    {
        return;
    }
    D2UnitStrc* pItem = gpCursorItem;
    D2CelContextStrc tContext;
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        int nOut;
        memset(&tContext, 0, sizeof(tContext));
        if (GFXUTIL_InitUnitCelContext(&tContext, pItem, 0, 0, 0, &nOut, 1, -1) && sub_006001F0(&tContext, 0, 1))
        {
            D2_ASSERT(tContext.pCel, 0x2BB);
            GFX_DrawItemCel(gpCursorItem, gnCursorX - CelGetWidth(tContext.pCel) / 2 + gnCursorOffsetX,
                gnCursorY - CelGetHeight(tContext.pCel) / 2);
        }
    }
    else
    {
        int nType = gnCursorAnim;
        if (nType < NUM_CURSOR_CELLS)
        {
            int nX = gnCursorOffsetX + gnCursorX;
            int nY = gnCursorY;
            if (nY < 0)
            {
                nY = 0;
            }
            else if (nY > gnCursorMaxY - 1)
            {
                nY = gnCursorMaxY - 1;
            }
            if (nX < gnCursorOffsetX)
            {
                nX = gnCursorOffsetX;
            }
            else if (nX > gnCursorMaxX - gnCursorOffsetX - 1)
            {
                nX = gnCursorMaxX - gnCursorOffsetX - 1;
            }
            memset(&tContext, 0, sizeof(tContext));
            tContext.pCellFile = gapCursorCels[nType];
            tContext.nDirection = 0;
            tContext.nFrame = gnCursorAnimFrame >> 8;
            sub_004F6480(&tContext, nX, nY, -1, 5, 0);
            CURSOR_UpdateCursor();
        }
    }
}

// 0x004680A0
int __cdecl CURSOR_GetCursorItem()
{
    return (int)gpCursorItem;
}

extern int gdwGlobal_007A6AAC; // 0x007A6AAC

extern int gdwGlobal_007A6AB0; // 0x007A6AB0

// 0x00468730
int __cdecl sub_00468730()
{
    return gdwGlobal_007A6AB0;
}

// 0x00468740
int __cdecl sub_00468740()
{
    return gdwGlobal_007A6AAC;
}

extern int data_007A6AB0; // 0x007A6AB0

extern int data_007A6AAC; // 0x007A6AAC

// 0x00468750
void __fastcall CURSOR_SetCursorPos(int nX, int nY)
{
    SetCursorPos(nX, nY);
    data_007A6AB0 = nX;
    data_007A6AAC = nY;
}

// 0x00468770
void __fastcall CURSOR_SetCursorPosition(int nX, int nY)
{
    tagRECT rect;
    D2_ASSERT(nX >= 0, 0x30F);
    D2_ASSERT(nY >= 0, 0x310);
    if (!WINDOW_IsFullScreen())
    {
        _ReadWriteBarrier();
        tagRECT* pWindowRect = &rect;
        GetWindowRect(sub_004F59A0_GetWindow(), pWindowRect);
        int nScreenY = GetSystemMetrics(4);
        nScreenY += pWindowRect->top;
        nScreenY += nY;
        const int nScreenX = GetSystemMetrics(7) + rect.left + nX;
        SetCursorPos(nScreenX, nScreenY);
    }
    else
    {
        SetCursorPos(nX, nY);
    }
    gnCursorY = nY;
    gnCursorX_007A6AB0 = nX;
}

// 0x00468820
void __fastcall sub_00468820(int nArg1, int nArg2)
{
}

// 0x00468830
int __cdecl sub_00468830()
{
    return gnCursorState;
}

// 0x00468840
void __stdcall CURSOR_HandleMouseMotion(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gbCursorVisible = 1;
    gnCursorX = nX;
    gnCursorY = nY;
// build: symbol ?FOG_IsHandlingError@* 0x00407FF0
    if (D2GFX_HardwareAcceleratedRenderMode() && !FOG_IsHandlingError())
    {
        int bClip = 0;
        if (gnCursorX > gnScreenWidth - 1)
        {
            gnCursorX = gnScreenWidth - 1;
            bClip = 1;
        }
        if (gnCursorY > gnScreenHeight - 1)
        {
            gnCursorY = gnScreenHeight - 1;
            bClip = 1;
        }
        if (bClip)
        {
            sub_00468750_SetMousePos(gnCursorX, gnCursorY);
            return;
        }
    }
    sub_004F59F0(1);
    gdwLastMouseMoveTick = GetTickCount();
    if (gnCursorState == 4 || gnCursorState == 2)
    {
        gnCursorState = 3;
        gnCursorAnim = 2;
        gnCursorAnimFrame = 0;
        gnCursorAnimFrame = CURSOR_GetCursorAnimLength(gnCursorAnim) - 0x100;
    }
    pMsg->bReturn = 0;
    pMsg->lResult = 0;
}
#include "gen/data/Source/D2Client/ENGINE/Cursor.inc"

extern int gnQuotient_007A6B0C; // 0x007A6B0C
// build: symbol ??__EgnQuotient_007A6B0C@@YAXXZ 0x006CAAB0
int gnQuotient_007A6B0C = 1000 / gnDivisor_007121DC;
