#include "D2Unicode.h"
#include "D2Client.h"
#include "D2WinSplitText.h"
struct D2SelectionRectStrc;
#pragma pack(push, 2)
struct D2TextScrollStrc
{
    D2SplittedTextStrc* pLines;
    int nLines;
    unsigned int nPos;
    int nSpeed;
    char unk0x10[6];
    int nState;
    unsigned int dwLastTime;
    unsigned int dwStartTime;
    unsigned int dwStep;
    unsigned int dwAccum;
    unsigned short wFrames;
};
#pragma pack(pop)

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime(void);                                // 0x006CC544

void __fastcall UI_DrawRectangleBorder(D2RectStrc* pRect);                                               // 0x00452E50
void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
int __stdcall D2Win_10125();                                                                                // 0x00501A40
void __fastcall D2WINFONT_DrawClippedFontText(const Unicode* pText, int nX, int nY, int nTextColor, int nSkipLines, int nDrawLines); // 0x00501DF0
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
int __fastcall D2Win_10127_SetFont(int nArg);                                                                      // 0x00502EF0

extern int gnTextTop;                                                                               // 0x007225FC
extern unsigned long gnTextDisplaySetting;                                                                     // 0x007BF1F6
extern int gbTextPanelOpen;                                                                               // 0x007BF1FA
extern int gbTextSide;                                                                             // 0x007BF236
extern int gnGlobal_007BF264;                                                                               // 0x007BF264
extern int gnTextLeft;                                                                               // 0x007BF278

// 0x0049D590
unsigned int __fastcall TEXT_CalcTextOffset(unsigned int nValue)
{
    return 0x70 - (nValue >> 10);
}

static __forceinline void sub_0049D5A0_DrawClippedLine(D2SplittedTextStrc* pLine, int nY, int nColor, int nSkipLines, int nDrawLines)
{
    if (gnTextDisplaySetting || gbTextPanelOpen)
    {
        D2WINFONT_DrawClippedFontText(pLine->wszLine, gnTextLeft + 0x10, gnTextTop + nY, nColor, nSkipLines, nDrawLines);
    }
}

static int TEXT_UpdateScrollText(D2TextScrollStrc* pRec); // 0x0049D5A0
static int TEXT_UpdateScrollText(D2TextScrollStrc* pRec); // 0x0049D5A0

// 0x0049D5A0
static int TEXT_UpdateScrollText(D2TextScrollStrc* pRec)
{
    D2_ASSERT(pRec, 1805);

    int nOldFont = D2Win_10127_SetFont(8);

    unsigned int dwNow = timeGetTime();
    if (!pRec->dwStartTime)
    {
        pRec->dwLastTime = dwNow;
        pRec->dwStartTime = dwNow;
    }
    else
    {
        unsigned int nElapsed = (dwNow - pRec->dwStartTime) >> 2;
        unsigned int nExtra = 0;
        if (pRec->dwLastTime == dwNow)
        {
            if (!pRec->dwStep)
            {
                ++pRec->wFrames;
            }
            else
            {
                pRec->dwAccum += pRec->dwStep;
                nExtra = pRec->dwAccum;
            }
        }
        else
        {
            pRec->dwAccum = 0;
            if (!pRec->dwStep && pRec->wFrames)
            {
                pRec->dwStep = (dwNow - pRec->dwLastTime) / pRec->wFrames;
            }
            pRec->dwLastTime = dwNow;
        }
        pRec->nPos = (nExtra + nElapsed) * pRec->nSpeed;
    }

    if (!gbTextSide && (gnTextDisplaySetting || gbTextPanelOpen))
    {
        AUTOMAP_DrawFramedBox(gnTextLeft, gnTextTop - 5, 0x145, 0x7A, 0, 1);
        D2RectStrc tRect;
        tRect.nLeft = gnTextLeft - 1;
        tRect.nTop = gnTextTop - 6;
        tRect.nRight = gnTextLeft + 0x146;
        tRect.nBottom = gnTextTop + 0x75;
        UI_DrawRectangleBorder(&tRect);
    }

    D2SplittedTextStrc* pLine = pRec->pLines;
    D2SplittedTextStrc* pLast = 0;
    unsigned int nFirstPos = 0;
    unsigned int nLastPos = 0;
    unsigned int nPos = pRec->nPos;
    D2SplittedTextStrc* pFirst = 0;
    if (nPos && pLine)
    {
        do
        {
            if (nPos < 0x17800)
            {
                int nY = TEXT_CalcTextOffset(nPos);
                if (gnTextDisplaySetting || gbTextPanelOpen)
                {
                    D2Win_10117_DrawText(pLine->wszLine, gnTextLeft + 0x10, gnTextTop + nY, 0, 0);
                }

                if (!pFirst)
                {
                    pFirst = pLine;
                    nFirstPos = nPos;
                }
                nLastPos = nPos;
                pLast = pLine;
            }

            if (nPos < 0x4800)
            {
                break;
            }

            pLine = pLine->pNextLine;
            nPos -= 0x4800;
        }
        while (pLine);

        if (pFirst)
        {
            D2SplittedTextStrc* pPrev = 0;
            D2SplittedTextStrc* pNode = pRec->pLines;
            while (pNode != pFirst)
            {
                pPrev = pNode;
                pNode = pNode->pNextLine;
            }

            if (pPrev)
            {
                int nY = TEXT_CalcTextOffset(nFirstPos) - 0x12;
                int nLines = nY < 0x12 ? nY : 0x12;

                sub_0049D5A0_DrawClippedLine(pPrev, nY, 3, 0, nLines);
            }
        }

        D2SplittedTextStrc* pNext;
        if (pLast && (pNext = pLast->pNextLine) != 0)
        {
            int nY = TEXT_CalcTextOffset(nLastPos + 0x400);
            int nSkip = nY - 0x5E;
            int nHeight = D2Win_10125();
            if (nSkip < nHeight)
            {

                const int nOldSkip = nSkip;
                nSkip = nHeight - nSkip;
                sub_0049D5A0_DrawClippedLine(pNext, nY + 0x13, 0, nOldSkip, nSkip);
            }
        }
    }

    if (!pFirst && !pLast)
    {
        D2SplittedTextStrc* pTail = pRec->pLines;
        unsigned int nTailPos = pRec->nPos;
        while (pTail->pNextLine)
        {
            pTail = pTail->pNextLine;
            nTailPos -= 0x4800;
        }

        if (nTailPos < 0x1C000)
        {
            int nY = TEXT_CalcTextOffset(nTailPos + 0x400);
            int nLines = nY < 0x12 ? nY : 0x12;
            if (nLines)
            {
                sub_0049D5A0_DrawClippedLine(pTail, nY, 3, 0, nLines);
            }
        }
    }

    D2Win_10127_SetFont(nOldFont);

    int nRows = pRec->nLines - 1;
    if (nRows <= 0)
    {
        nRows = 1;
    }

    if ((pRec->nPos >> 10) > (unsigned int)(nRows * 18 + 0x70))
    {
        if (gnGlobal_007BF264 == 1)
        {
            gnGlobal_007BF264 = 0;
        }
        return 1;
    }

    return 0;
}

#pragma pack(push, 1)
typedef int(__fastcall* PANELCLOSEFN)(void* pArg, int a2, int a3);
#pragma pack(pop)

extern D2TextScrollStrc* gpTextBox; // 0x007BF0A4
extern int gnPanelOpen_007BF1BC; // 0x007BF1BC
extern int gnPending_007BF1C4; // 0x007BF1C4
extern void* gpHint_007BF202; // 0x007BF202
extern int gbHintActive_007BF20A; // 0x007BF20A
extern void* gpHint_007BF24B; // 0x007BF24B
extern PANELCLOSEFN gpfnClose_007BF258; // 0x007BF258
extern void* gpCloseArg_007BF25C; // 0x007BF25C
extern int gbHandlers_007BF27C; // 0x007BF27C
extern char gHandlerTable_00722600[]; // 0x00722600

int __cdecl D2SOUND_GetMasterVolumeOption(); // 0x00514CC0
int __fastcall sub_004B95C0_IsHintPlaying(void* pHint); // 0x004B95C0
void __stdcall TEXT_FreeTextBox(D2TextScrollStrc* pTextBox); // 0x0049D410
void __fastcall SELECT_SetSelectionRect(const D2SelectionRectStrc* pRect); // 0x00467430
void __cdecl TEXT_ResetTextBox(); // 0x0049F960
void __fastcall NPCMENU_CancelNpcAndFlag(void* pHint); // 0x004B3D10
void __cdecl UI_StartUIVarDelay(); // 0x00453AE0
void* __stdcall WINDOW_GetWindow(); // 0x004F59A0
void __fastcall AUTOMAP_UnregisterHandlerTable(void* hWnd, void* pTable, int nCount); // 0x00451E10

// 0x004A0770
static int __stdcall TEXT_AdvanceTextBox(int bIgnore, D2TextScrollStrc* pTextBox)
{
    if (bIgnore)
    {
        pTextBox->nState = 2;
        return 0;
    }

    const int bBusy = D2SOUND_GetMasterVolumeOption();
    if (!gpHint_007BF24B || sub_004B95C0_IsHintPlaying(gpHint_007BF24B) || !bBusy)
    {
        gpHint_007BF24B = 0;
        if (TEXT_UpdateScrollText(pTextBox))
        {
            gnPanelOpen_007BF1BC = 1;
            if (!gbHintActive_007BF20A && gpTextBox)
            {
                TEXT_FreeTextBox(gpTextBox);
                gpTextBox = 0;
                SELECT_SetSelectionRect(0);
            }

            TEXT_ResetTextBox();
            if (gpfnClose_007BF258)
            {
                return gpfnClose_007BF258(gpCloseArg_007BF25C, 0, 0);
            }

            if (gnPending_007BF1C4 == 1)
            {
                gnPending_007BF1C4 = 0;
            }
            else if (gbHintActive_007BF20A)
            {
                NPCMENU_CancelNpcAndFlag(gpHint_007BF202);
            }

            UI_StartUIVarDelay();
            gbHintActive_007BF20A = 0;
            SELECT_SetSelectionRect(0);
            if (gbHandlers_007BF27C == 1)
            {
                gbHandlers_007BF27C = 0;
                AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(), gHandlerTable_00722600, 7);
            }

            return 0;
        }
    }

    return 1;
}

// calling-convention shim (not game code)
int __stdcall sub_004A0770_Shim()
{
    D2TextScrollStrc* pTextBox = gpTextBox;
    if (pTextBox && (pTextBox->nState == 1 || pTextBox->nState == 0))
    {
        return TEXT_AdvanceTextBox(gnPanelOpen_007BF1BC, pTextBox);
    }

    return 0;
}
