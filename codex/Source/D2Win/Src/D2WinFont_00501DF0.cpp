#include "D2Win.h"
#include "D2CelContext.h"
#include "D2WinTypes.h"
#include "D2WinSplitText.h"

struct Unicode;
struct D2CharStrc;
struct D2FontStrc;
struct D2FontCacheStrc;
struct D2CelContextStrc;
struct D2SplittedTextStrc;
struct D2CelFileStrc;
struct D2CelStrc;

struct Unicode
{
    unsigned short wChar;
    int IsColorCodePrefix() const
    {
        if (wChar >= 0x100)
            return 0;

        return wChar == 0xFF;
    }
    int ToDigit() const
    {
        return wChar - '0';
    }
    static int __fastcall strncmp(const Unicode* str1, const Unicode* str2, unsigned int count);            // 0x00526540
// build: symbol ?strncpy@Unicode@@SIPAU1@PAU1@PBU1@H@Z 0x00526790
    static Unicode* __fastcall strncpy(Unicode* dest, const Unicode* src, int count);                       // 0x00526790
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __stdcall TEXTURE_CelDrawColor(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, int nGlobalPaletteShift); // 0x004F64B0
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
int __cdecl D2GFX_GetDisplayType(); // 0x004F5140
void __stdcall TEXTURE_CelDraw(D2CelContextStrc* pContext, int nX, int nY, unsigned int nGamma, int nDrawMode, unsigned char* pPalette); // 0x004F6480
void __stdcall TEXTURE_CelDrawEx(D2CelContextStrc* pContext, int nX, int nY, int nSkipLines, int nDrawLines, int nDrawMode); // 0x004F64E0
D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext); // 0x00601840
int __stdcall CelGetHeight(D2CelStrc* pCel); // 0x006018F0
extern int gnCurrentFont; // 0x0072DFFC
extern D2FontCacheStrc* gpFontCache; // 0x00841D88
extern D2CelFileStrc* ghMonsterIndicators; // 0x00841DA4
extern wchar_t gwszMonsterCode_008426DC[2]; // 0x008426DC

typedef D2CharStrc* (__fastcall* D2GetCharInfoFn)(unsigned short wChar);

extern D2GetCharInfoFn gpfnGetCharInfo; // 0x00841DA0
extern D2FontCacheStrc gatFontCache[]; // 0x00841DA8
extern wchar_t gwszColorCode_008426E0[2]; // 0x008426E0

extern "C" const char gszD2WinFontSourceFile[]; // 0x006DC9FC
int __fastcall D2Win_10123(const Unicode* wszText, int nLength); // 0x00501730
int __fastcall sub_00526D30_IsLineBreak(const Unicode* pText, unsigned int nIndex); // 0x00526D30
D2SplittedTextStrc* __stdcall D2Win_AllocateSplitText(const Unicode* wszText, int nLength, int bSkipSpace); // 0x005028E0

inline int sub_00501DF0_IsColorCodePrefix(unsigned short wChar)
{
    if (wChar >= 0x100)
        return 0;
    return wChar == 0xFF;
}

// 0x00501DF0
void __fastcall D2WINFONT_DrawClippedFontText(const Unicode* pText, int nX, int nY, int nTextColor, int nSkipLines, int nDrawLines)
{
    if (nSkipLines < 0)
        return;

    const int nDisplayType = D2GFX_GetDisplayType();
    const int nLength = sub_00526800(pText);
    int nCount = 0;
    const int nStartX = nX;
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.nDirection = 0;

    if (nLength > 0)
    {
        const Unicode* pScan = pText - 1;
        do
        {
            const Unicode c = pText[nCount++];
            Unicode c2;
            const unsigned short wScan = (++pScan)->wChar;
            if (sub_00501DF0_IsColorCodePrefix(wScan))
            {
                c2 = pText[nCount];
                ++nCount;
                ++pScan;
                if (!Unicode::strncmp(&c2, (const Unicode*)gwszColorCode_008426E0, 1))
                {
                    ++nCount;
                    ++pScan;
                    continue;
                }
                if (!Unicode::strncmp(&c2, (const Unicode*)gwszMonsterCode_008426DC, 1))
                {
                    const Unicode* pMarker = pScan;
                    ++nCount;
                    ++pScan;
                    const unsigned short wMarker = pMarker->wChar;
                    D2CharStrc* pChar = gpfnGetCharInfo(wMarker);
                    tContext.pCellFile = ghMonsterIndicators;
                    tContext.nFrame = pChar->nImageIndex;
                    TEXTURE_CelDraw(&tContext, nX, nY, -1, 5, 0);
                    nY += 16 * gatFontCache[gnCurrentFont].pFontInfo[1]->nHeight / 10;
                }
            }
            else if (c.wChar != '\n')
            {
                D2CharStrc* pChar = gpfnGetCharInfo(c.wChar);
                if (nDisplayType != 6)
                {
                    tContext.pCellFile = gpFontCache->pCellFile;
                    tContext.nFrame = pChar->nImageIndex;
                    const int nHeight = CelGetHeight(CelGetHandle(&tContext));
                    if (nSkipLines + nDrawLines <= nHeight)
                        TEXTURE_CelDrawEx(&tContext, nX, nY, nSkipLines, nDrawLines, 5);
                    else
                        TEXTURE_CelDrawEx(&tContext, nX, nY, 0, nHeight, 5);
                }
                nX += pChar->nWidth;
            }
            else
            {
                nX = nStartX;
                nY += -16 * gatFontCache[gnCurrentFont].pFontInfo[1]->nHeight / 10;
            }
        }
        while (nCount < nLength);
    }
}

// 0x00501FE0
void __fastcall D2WINFONT_DrawTickerText(const Unicode* wszText, int nX, int nY, int nColor, int nScroll, int nWidth)
{
    const int nLength = sub_00526800(wszText);
    int nCount = 0;
    const int nStartX = nX;
    nX += nScroll;

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpFontCache->pCellFile;
    tContext.nDirection = 0;

    if (nLength <= 0)
    {
        return;
    }

    const int nRight = nStartX + nWidth;
    int nShift = nColor;
    const Unicode* pText = wszText;
    do
    {
        if (nX > nRight)
        {
            break;
        }

        Unicode c2;
        const Unicode c = *pText;
        ++nCount;
        ++pText;
        const int bColorPrefix = pText[-1].IsColorCodePrefix();
        if (bColorPrefix)
        {
            c2 = *pText;
            ++nCount;
            ++pText;
            if (!Unicode::strncmp(&c2, (const Unicode*)gwszColorCode_008426E0, 1))
            {
                if (nCount >= nLength)
                {
                    nShift = 0;
                }
                else
                {
                    ++nCount;
                    nShift = (pText++)->ToDigit();
                    if (nShift >= 13)
                    {
                        nShift = 0;
                    }
                }
            }
            else
            {
                --nCount;
                --pText;
                D2CharStrc* pChar = gpfnGetCharInfo(c.wChar);
                tContext.nFrame = pChar->nImageIndex;
                if (nX > nStartX)
                {
                    TEXTURE_CelDrawColor(&tContext, nX, nY, -1, 5, nShift);
                }
                nX += pChar->nWidth;
            }
        }
        else if (c.wChar != '\n')
        {
            D2CharStrc* pChar = gpfnGetCharInfo(c.wChar);
            tContext.nFrame = pChar->nImageIndex;
            if (nX > nStartX)
            {
                TEXTURE_CelDrawColor(&tContext, nX, nY, -1, 5, nShift);
            }
            nX += pChar->nWidth;
        }
        else
        {
            nX = nStartX;
            nY += -16 * gatFontCache[gnCurrentFont].pFontInfo[1]->nHeight / 10;
        }
    }
    while (nCount < nLength);
}

static inline D2SplittedTextStrc* AllocSplitTextLine_Inline(const Unicode* wszText, int nLength, int bSkipSpace)
{
    D2SplittedTextStrc* pSplitText = (D2SplittedTextStrc*)FOG_Alloc(sizeof(D2SplittedTextStrc), gszD2WinFontSourceFile, 0x588, 0);
    int nCount = nLength;
    const Unicode* pText = wszText;
    if (bSkipSpace && pText->wChar < 0x100 && isspace(pText->wChar))
    {
        nCount = nCount - 1;
        pText = pText + 1;
    }
    pSplitText->wszLine = (Unicode*)FOG_Alloc(sizeof(Unicode) * (nCount + 1), gszD2WinFontSourceFile, 0x591, 0);
    pSplitText->pNextLine = 0;
    Unicode::strncpy(pSplitText->wszLine, pText, nCount);
    pSplitText->wszLine[nCount].wChar = 0;
    return pSplitText;
}

// 0x00502970
D2SplittedTextStrc* __fastcall D2WINFONT_SplitText(const Unicode* wszText, int* pLineCount, int nWidth)
{
    const int nLength = sub_00526800(wszText);
    D2SplittedTextStrc* pLast = 0;
    D2SplittedTextStrc* pFirst = 0;
    *pLineCount = 0;
    if (D2Win_10123(wszText, nLength) <= nWidth)
    {
        *pLineCount = 1;
        return AllocSplitTextLine_Inline(wszText, nLength + 1, 0);
    }

    int nStart = 0;
    int nEnd = nLength;
    for (;;)
    {
        int nTextWidth = 0;
        for (; nEnd > nStart; --nEnd)
        {
            nTextWidth = D2Win_10123(&wszText[nStart], nEnd - nStart + 1);
            if (nTextWidth <= nWidth)
            {
                break;
            }
        }
        for (; nEnd > nStart; --nEnd)
        {
            if (nEnd == nLength || sub_00526D30_IsLineBreak(&wszText[nStart], nEnd - nStart + 1))
            {
                break;
            }
        }

        if (nEnd == nStart)
        {
            for (nEnd = nLength; nEnd > nStart; --nEnd)
            {
                if (D2Win_10123(&wszText[nStart], nEnd - nStart + 1) <= nWidth)
                {
                    break;
                }
            }

            D2SplittedTextStrc* pLine = AllocSplitTextLine_Inline(&wszText[nStart], nEnd - nStart + 1, 1);
            ++*pLineCount;
            if (pLast)
            {
                pLast->pNextLine = pLine;
            }
            pLast = pLine;
            if (!pFirst)
            {
                pFirst = pLine;
            }
            nStart = nEnd + 1;
            nEnd = nLength;
            if (nStart > nLength)
            {
                break;
            }
        }
        else
        {
            if (nTextWidth > nWidth)
            {
                for (nEnd = nLength; nEnd > nStart; --nEnd)
                {
                    if (D2Win_10123(&wszText[nStart], nEnd - nStart + 1) <= nWidth)
                    {
                        break;
                    }
                }
                for (; nEnd > nStart; --nEnd)
                {
                    if (nEnd == nLength || sub_00526D30_IsLineBreak(&wszText[nStart], nEnd - nStart + 1))
                    {
                        break;
                    }
                }
                D2SplittedTextStrc* pLine;
                if (nEnd == nStart)
                {
                    for (nEnd = nLength; nEnd > nStart; --nEnd)
                    {
                        if (D2Win_10123(&wszText[nStart], nEnd - nStart + 1) <= nWidth)
                        {
                            break;
                        }
                    }
                    pLine = D2Win_AllocateSplitText(&wszText[nStart], nEnd - nStart + 1, 1);
                }
                else
                {
                    pLine = D2Win_AllocateSplitText(&wszText[nStart], nEnd - nStart + 1, 1);
                }
                ++*pLineCount;
                if (pLast)
                {
                    pLast->pNextLine = pLine;
                }
                pLast = pLine;
                if (!pFirst)
                {
                    pFirst = pLine;
                }
                nStart = nEnd + 1;
                nEnd = nLength;
                if (nStart > nLength)
                {
                    break;
                }
            }
            else
            {
                D2SplittedTextStrc* pLine = D2Win_AllocateSplitText(&wszText[nStart], nEnd - nStart + 1, 1);
                ++*pLineCount;
                if (pLast)
                {
                    pLast->pNextLine = pLine;
                }
                pLast = pLine;
                if (!pFirst)
                {
                    pFirst = pLine;
                }
                nStart = nEnd + 1;
                nEnd = nLength;
                if (nStart > nLength)
                {
                    break;
                }
            }
        }
    }

    return pFirst;
}
