#include "D2Client.h"
#include "D2StormTypes.h"

struct D2SplittedTextStrc
{
    unsigned short* wszLine;
    D2SplittedTextStrc* pNextLine;
};

class EditBoxImplementation;
typedef int (__fastcall* EDITBOX_FILTER)(EditBoxImplementation* pEditBox, SMSGHANDLER_PARAMS* pMsg);
typedef void (*EDITBOX_CALLBACK)();

#pragma pack(push, 2)

class EditBoxImplementation
{
public:
    int OnKeyDown(SMSGHANDLER_PARAMS* pMsg);

    void* f_0;
    EDITBOX_FILTER pfFilter;
    int nX;
    int nY;
    int nTextX;
    int nTextY;
    int nTextWidth;
    int nHeight;
    int bNumeric;
    int bAllowRepeat;
    unsigned short* pText;
    unsigned short* pTextCopy;
    unsigned int nMaxValue;
    unsigned short nMaxLength;
    int nCaret;
    int nLength;
    int unk0x3E;
    EDITBOX_CALLBACK pfOnEnter;
    unsigned int unk0x46;
    int unk0x4A;
    int nFont;
};

#pragma pack(pop)

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
unsigned int __fastcall D2Win_10128(unsigned char nCharCode); // 0x00502550
D2SplittedTextStrc* __fastcall D2WINFONT_SplitText(const unsigned short* pText, int* pLineCount, int nWidth); // 0x00502970
int __fastcall D2Win_10127_SetFont(int nFontSize);                                                                 // 0x00502EF0
void __fastcall sub_005263E0(char* szDest, const unsigned short* pSource, int nMaxLength);         // 0x005263E0
extern "C" int __fastcall sub_00526800(const unsigned short* pText);                                      // 0x00526800
unsigned short* __fastcall sub_00526F20(unsigned short* pDst, const char* szSrc, int nMaxLength);    // 0x00526F20
extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" const char gszFmtDecimal_006D57BC[];                                                             // 0x006D57BC

// 0x004BB620
int EditBoxImplementation::OnKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (!bAllowRepeat && (pMsg->lParam & 0x40000000))
        return 1;

    if (pMsg->wParam > 0x7F)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return 1;
    }

    const char nChar = (char)pMsg->wParam;
    int bAccepted;
    if (pfFilter)
    {
        bAccepted = pfFilter(this, pMsg);
    }
    else if (bNumeric)
    {
        bAccepted = isdigit(nChar);
    }
    else
    {
        bAccepted = D2Win_10128(nChar);
        if (nChar == '\r' || nChar == 0x1B)
        {
            pfOnEnter();
            pMsg->lResult = 0;
            pMsg->bReturn = 1;
            sub_00420290_BreakHandlerChain(pMsg);
            return 1;
        }
    }

    if (nChar == 8)
    {
        if (nLength > 0)
        {
            if (nCaret != nLength && nCaret != 0)
            {
                for (int i = nCaret - 1; i < D2_MIN(nLength, nMaxLength) - 1; ++i)
                    pText[i] = pText[i + 1];
            }

            pText[nLength - 1] = 0;
            --nLength;
        }

        if (nCaret)
            --nCaret;

        pMsg->lResult = 0;
        pMsg->bReturn = 1;
        sub_00420290_BreakHandlerChain(pMsg);
        return 1;
    }

    if (nChar == 0x2E)
    {
        if (nLength > 0 && nCaret != nLength)
        {
            for (int i = nCaret; i < D2_MIN(nLength, nMaxLength); ++i)
                pText[i] = pText[i + 1];

            pText[nLength - 1] = 0;
            --nLength;
        }

        pMsg->lResult = 0;
        pMsg->bReturn = 1;
        sub_00420290_BreakHandlerChain(pMsg);
        return 1;
    }

    if (bAccepted)
    {
        if (nLength < nMaxLength - 1)
        {
            if (nCaret == nLength)
            {
                pText[nCaret] = nChar;
                ++nCaret;
                pText[nCaret] = 0;
                ++nLength;
            }
            else
            {
                for (int i = D2_MIN(nLength, nMaxLength); i >= nCaret; --i)
                    pText[i] = pText[i - 1];

                if (nLength < nMaxLength)
                    ++nLength;

                pText[nLength] = 0;
                pText[nCaret] = nChar;
            }
        }

        if (nLength)
        {
            D2Win_10127_SetFont(nFont);
            int nLines;
            D2SplittedTextStrc* pLine = D2WINFONT_SplitText(pText, &nLines, nTextWidth);
            while (pLine)
            {
                D2SplittedTextStrc* pNext = pLine->pNextLine;
                FOG_Free(pLine->wszLine, ".\\UI\\editbox.cpp", 0x203, 0);
                FOG_Free(pLine, ".\\UI\\editbox.cpp", 0x204, 0);
                pLine = pNext;
            }

            if (nLines > nHeight)
            {
                --nLength;
                --nCaret;
                pText[nLength] = 0;
            }
        }

        if (!pfFilter && sub_00526800(pText))
        {
            if (bNumeric)
            {
                char szValue[0x800];
                sub_005263E0(szValue, pText, nMaxLength);
                const unsigned int nMax = nMaxValue;
                if (atoi(szValue) > nMax)
                {
                    sprintf(szValue, gszFmtDecimal_006D57BC, nMax);
                    memset(pText, 0, nMaxLength * 2);
                    sub_00526F20(pText, szValue, nMaxLength);
                    const int nNewLength = sub_00526800(pText);
                    nCaret = nNewLength;
                    nLength = nNewLength;
                }
            }
            else
            {
                nLength = sub_00526800(pText);
            }
        }
    }
    else if (nChar == ' ' || nChar == 0x1B || nChar == '\r')
    {
        return 0;
    }

    pMsg->lResult = 0;
    pMsg->bReturn = 1;
    sub_00420290_BreakHandlerChain(pMsg);
    return 1;
}
