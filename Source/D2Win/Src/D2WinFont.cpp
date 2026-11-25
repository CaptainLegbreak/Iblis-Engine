#include "D2WinTypes.h"
#include "D2GfxTypes.h"
#include "D2MultiTypes.h"
#include "D2Win32Types.h"
#include "D2StormTypes.h"
#include "D2WinControls.h"
#include "D2Structs.h"
#include "D2Txt.h"

#include "D2Unicode.h"

#include "D2Win.h"

#include "D2ClientTypes.h"

#include "D2CelContext.h"
#include "D2WinSplitText.h"

struct D2CelFileStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);           // 0x006CC468

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern "C" unsigned int __cdecl strlen(const char* szString);

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

D2CelFileStrc* __fastcall ARCHIVE_LoadCellFile(const char* szFile, int nType);                              // 0x004FA9B0

void __fastcall ARCHIVE_FreeCellFile(D2CelFileStrc* pCellFile);                                        // 0x004FAAE0

void* __stdcall D2Win_GetArchive(); // 0x004FAC80

D2CharStrc* __fastcall FONT_GetCharInfoByIndex(unsigned short wChar);                                                  // 0x00501650

D2CharStrc* __fastcall FONT_FindCharInfo(unsigned short wChar);                                                  // 0x00501690

void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFilePath, unsigned int* pdwBytesWritten, const char* szSrcPath, int nLine); // 0x00517079

int __cdecl STRTABLE_GetLanguage();                                                                         // 0x00525150

void __fastcall sub_00526320_ToUnicode(wchar_t* pDest, const char* szSource, int nLength);                  // 0x00526320

extern "C" const char gszDataGlobal_006D4118[];                                                             // 0x006D4118

extern "C" const char gszDataLocal[];                                                              // 0x006D41A8

extern const char* gaFontNames[14];                                                                // 0x006DC980

extern int gnCurrentFont;                                                                          // 0x0072DFFC

extern int gnFontMetric1;                                                                          // 0x0072E000

extern int gnFontMetric2;                                                                          // 0x0072E004

extern int gnFontMetric3;                                                                          // 0x0072E008

D2FontCacheStrc* gpFontCache;                                                                      // 0x00841D88

char gszFontLanguage[4];                                                                           // 0x00841D8C

D2CharStrc* (__fastcall* gpfnGetCharInfo)(int nChar);                                             // 0x00841DA0

D2CelFileStrc* ghMonsterIndicators;                                                                // 0x00841DA4

extern D2FontCacheStrc gatFontCache[14];                                                             // 0x00841DA8

unsigned int gdwLastShiftedTickCount;                                                              // 0x00841EC0

bool gbKoreanFonts;                                                                                // 0x00841EC6

// build: symbol ??__EgwszFramedText@@YAXXZ 0x006CAE20
Unicode gwszFramedText[1024];                                                                      // 0x00841EC8

// build: symbol ??__EgwszMonsterCode_008426DC@@YAXXZ 0x006CAE50
Unicode gwszMonsterCode_008426DC[2]; // 0x008426DC

// build: symbol ??__EgwszColorCode_008426E0@@YAXXZ 0x006CAE40
Unicode gwszColorCode_008426E0[2]; // 0x008426E0

struct D2FontStrc;

struct D2CmpCelContextStrc;

struct D2CharStrc;

struct D2FontCacheStrc;

struct D2SplittedTextStrc;

struct D2CelContextStrc;

struct Unicode;

void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300

int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pCelFile); // 0x006019F0

D2CelStrc* __stdcall CelGetHandle(D2CmpCelContextStrc* pContext); // 0x00601840

void __stdcall TEXTURE_CelDraw(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480

void __stdcall TEXTURE_CelDrawColor(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, int nGlobalPaletteShift); // 0x004F64B0

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

int gnFramedTextAlign;                                                                             // 0x008426D4

int gnFramedTextColor;                                                                             // 0x008426D0

int gnFramedTextRectColor;                                                                         // 0x008426D8

int gnFramedTextX;                                                                                 // 0x008426C8

int gnFramedTextY;                                                                                 // 0x008426CC

int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength);                                        // 0x005017D0

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0

typedef unsigned int size_t;

static int FONT_GetMaxLineWidth(const Unicode* pText); // 0x00501840

static int FONT_GetFirstLineWidth(const Unicode* pText); // 0x00501910

static void __stdcall FONT_DrawString(const Unicode* wszText, int nX, int nY, int nWidth, int nGlobalPaletteShift, int bCentered);

static void __stdcall FONT_DrawTextLineWithDrawMode(const Unicode* wszText, int nX, int nY, int nWidth, int nColor, int bCentered, int eDrawMode); // 0x00501C30

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

extern "C" int __fastcall sub_00526800_2(const unsigned short* pText);

static int FONT_GetTextHeight(const Unicode* pText); // 0x005019C0

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

int __stdcall WINDOW_GetDimensions(int* pWidth, int* pHeight);                                              // 0x004F59B0

static int shim_2;

void __stdcall shim_1(int nLength, int nY, int nWidth, int nPalette, int bCentered);

__declspec(noinline) static void __stdcall sub_00501A80_DrawString(const Unicode* wszText, int nX, int nY, int nWidth, int nPalette, int bCentered);

extern unsigned int gaFontCharValidBits[8]; // 0x006DC9B8

unsigned char __stdcall PALETTE_FindPaletteIndex(unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x004FB180

extern unsigned char gnTooltipColor; // 0x00841EC4

static void __stdcall sub_00501A80_DrawTextLine(int nY, int nWidth, int nShift, int bCentre, const Unicode* pText, int nX);

extern "C" const char gszFormatMonsterIndicators[];                                                // 0x006DCA10

static void __stdcall FONT_BuildFontPath(int nFont, char* pBuffer, int nLength); // 0x005013A0

static void __stdcall FONT_BuildFontTablePath(int nFont, char* pBuffer, int nLength); // 0x00501490

static void FONT_LoadFontTable(int nFont); // 0x00501580

int __fastcall D2Win_10127_SetFont(int nFontSize); // 0x00502EF0

void* __fastcall FOG_AllocPool(void* pPool, int nSize, const char* szFile, int nLine, int n0);              // 0x0040B430

void __fastcall D2Win_10118_DrawBlendedText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered, int eDrawMode);

// 0x005013A0
static void __stdcall FONT_BuildFontPath(int nFont, char* pBuffer, int nLength)
{
    char szPath[0x104];
    wsprintfA(szPath, "%s\\%s\\", gszDataLocal, "Font");
    D2_ASSERT(nLength > (int)strlen(szPath) + 20, 0x7B);

    if (!gbKoreanFonts)
        wsprintfA(pBuffer, "%s%s%s", szPath, gszFontLanguage, gaFontNames[nFont]);
    else if (nFont == 13)
        wsprintfA(pBuffer, "%s%s%s", szPath, "KOR\\", gaFontNames[13]);
    else
        wsprintfA(pBuffer, "%s%s%s", szPath, gszFontLanguage, gaFontNames[nFont]);
}

// 0x00501490
static void __stdcall FONT_BuildFontTablePath(int nFont, char* pBuffer, int nLength)
{
    char szPath[0x104];
    wsprintfA(szPath, "%s\\%s\\", gszDataLocal, "Font");
    D2_ASSERT(nLength > (int)strlen(szPath) + 20, 0x95);

    if (!gbKoreanFonts)
        wsprintfA(pBuffer, "%s%s%s.tbl", szPath, gszFontLanguage, gaFontNames[nFont]);
    else if (nFont == 13)
        wsprintfA(pBuffer, "%s%s%s.tbl", szPath, "KOR\\", gaFontNames[13]);
    else
        wsprintfA(pBuffer, "%s%s%s.tbl", szPath, gszFontLanguage, gaFontNames[nFont]);
}

// 0x00501580
static void FONT_LoadFontTable(int nFont)
{
    char szFile[0x50];
    FONT_BuildFontTablePath(nFont, szFile, 0x4F);

    if (gatFontCache[nFont].pFontInfo[0])
        FOG_Free(gatFontCache[nFont].pFontInfo[0], ".\\Src\\D2WinFont.cpp", 0xB3, 0);

    D2FontStrc* pFont = (D2FontStrc*)ARCHIVE_AllocateBufferAndReadFile(D2Win_GetArchive(), szFile, 0, ".\\Src\\D2WinFont.cpp", 0xB5);
    gatFontCache[nFont].pFontInfo[0] = pFont;
    gatFontCache[nFont].pFontInfo[1] = pFont;
    gatFontCache[nFont].pCharInfo = pFont->aChars;
}

// 0x005015F0
void __stdcall D2Win_10116()
{
    for (int i = 0; i < 14; ++i)
    {
        if (gatFontCache[i].pCellFile)
        {
            sub_004FAAE0_FreeCellFile(gatFontCache[i].pCellFile);
            gatFontCache[i].pCellFile = 0;
        }
        if (gatFontCache[i].pFontInfo[0])
        {
            FOG_Free(gatFontCache[i].pFontInfo[0], ".\\Src\\D2WinFont.cpp", 0x135, 0);
            gatFontCache[i].pFontInfo[0] = 0;
        }
    }
    sub_004FAAE0_FreeCellFile(ghMonsterIndicators);
    ghMonsterIndicators = 0;
}

// 0x00501650
D2CharStrc* __fastcall FONT_GetCharInfoByIndex(unsigned short wChar)
{
    if (wChar > 0xFF)
    {
        return gatFontCache[gnCurrentFont].pCharInfo;
    }

    return &gatFontCache[gnCurrentFont].pCharInfo[wChar];
}

inline int D2Win_IsColorCodePrefix(unsigned short wChar)
{
    if (wChar >= 0x100)
    {
        return 0;
    }

    return wChar == 0xFF;
}

// 0x00501690
D2CharStrc* __fastcall FONT_FindCharInfo(unsigned short wChar)
{
    int nIterations = 0;
    int nMin = 0;
// build: symbol ?gnCurrentFont@* 0x0072DFFC
    D2FontCacheStrc* pFontCache = &gatFontCache[gnCurrentFont];
    int nMax = pFontCache->pFontInfo[1]->nCharCount - 1;
    if (nMax >= 0)
    {
        D2CharStrc* pCharInfo = pFontCache->pCharInfo;
        do
        {
            const int nMid = (nMin + nMax) / 2;
            ++nIterations;
            if (wChar == pCharInfo[nMid].wChar)
            {
                return &pCharInfo[nMid];
            }

            if (wChar < pCharInfo[nMid].wChar)
            {
                nMax = nMid - 1;
            }
            else
            {
                nMin = nMid + 1;
            }

            if (nIterations > 1000)
            {
                break;
            }
        }
        while (nMax >= nMin);
    }

    return pFontCache->pCharInfo + 31;
}

// 0x00501730
int __fastcall D2Win_10123(const Unicode* wszText, int nTextLength)
{
    int nWidth = 0;
    int nCount = 0;
    const Unicode* pChar = wszText;
    while (pChar->wChar)
    {
        if (nCount >= nTextLength)
        {
            break;
        }

        const unsigned short wChar = pChar->wChar;
        if (wChar != '\n')
        {
            if (nCount + 3 < nTextLength && D2Win_IsColorCodePrefix(wChar) && pChar[1].wChar == 'c' && pChar[2].wChar >= '0' && pChar[2].wChar < '7')
            {
                pChar += 3;
                nCount += 3;
                continue;
            }

            nWidth += gpfnGetCharInfo(wChar)->nWidth;
        }

        ++pChar;
        ++nCount;
    }

    return nWidth;
}

// 0x005017D0
int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength)
{
    int nCount = 0;
    int nWidth = 0;
    for (const Unicode* i = wszText; i->wChar; ++i)
    {
        if (nCount >= nTextLength)
            break;
        const unsigned short wChar = i->wChar;
        if (wChar != '\n')
            nWidth += gpfnGetCharInfo(wChar)->nWidth;
        ++nCount;
    }
    return nWidth;
}

// 0x00501820
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText)
{
    return D2Win_10122(wszText, sub_00526800(wszText));
}

// 0x00501840
static int FONT_GetMaxLineWidth(const Unicode* pText)
{
    D2_ASSERT(pText, 525);
    int nWidth = 0;
    int nMax = 0;
    const int nLength = sub_00526800((const Unicode*)pText);
    for (int nCount = 0; nCount < nLength; ++nCount)
    {
        const unsigned short wChar = pText->wChar;
        if (!wChar)
            break;
        if (wChar == '\n')
        {
            if (nWidth > nMax)
                nMax = nWidth;
            nWidth = 0;
            ++pText;
            continue;
        }
        const int bColor = (wChar < 0x100) ? (wChar == 0xFF) : 0;
        if (bColor)
        {
            ++pText;
            if (!Unicode::strnicmp(pText, (const Unicode*)gwszMonsterCode_008426DC, 1))
                nWidth += gpfnGetCharInfo(*(const int*)gwszMonsterCode_008426DC)->nWidth;
            pText += 2;
            nCount += 2;
            continue;
        }
        nWidth += gpfnGetCharInfo(wChar)->nWidth;
        ++pText;
    }
    if (nMax > nWidth)
        nWidth = nMax;
    return nWidth;
}

void __fastcall sub_Emit_00501840(const Unicode* pText, int* pWidth, int nExtra)
{
    *pWidth = FONT_GetMaxLineWidth(pText) + nExtra;
}

// 0x00501910
static int FONT_GetFirstLineWidth(const Unicode* pText)
{
    D2_ASSERT(pText, 572);
    int nWidth = 0;
    const int nLength = sub_00526800((const Unicode*)pText);
    for (int nCount = 0; nCount < nLength; ++nCount)
    {
        const unsigned short wChar = pText->wChar;
        if (wChar == '\n')
            break;
        const int bColor = (wChar < 0x100) ? (wChar == 0xFF) : 0;
        if (bColor)
        {
            ++pText;
            if (!Unicode::strnicmp(pText, (const Unicode*)gwszMonsterCode_008426DC, 1))
                nWidth += gpfnGetCharInfo(*(const int*)gwszMonsterCode_008426DC)->nWidth;
            nCount += 2;
            pText += 2;
            continue;
        }
        nWidth += gpfnGetCharInfo(wChar)->nWidth;
        ++pText;
    }
    return nWidth;
}

void __fastcall sub_M388_Emit_00501910(const Unicode* pText, int* pWidth, int nExtra)
{
    *pWidth = FONT_GetFirstLineWidth(pText) + nExtra;
}

// 0x005019C0
static int FONT_GetTextHeight(const Unicode* pText)
{
    D2_ASSERT(pText, 606);

    int nLines = 1;
    int nLength = sub_00526800(pText);
    const Unicode* pChar = pText;
    if (nLength > 0)
    {
        do
        {
            if (pChar->wChar == '\n')
                ++nLines;
            ++pChar;
        }
        while (--nLength);
    }

    return gatFontCache[gnCurrentFont].pFontInfo[1]->nHeight * gnFontMetric2 * nLines / 10;
}

// 0x00501A40
int __stdcall D2Win_10125()
{
    return gatFontCache[gnCurrentFont].pFontInfo[1]->nHeight;
}

// 0x00501A60
static void __stdcall FONT_DrawBox(int nX, int nY, int nWidth, int nHeight, unsigned int dwColor, int nDrawMode)
{
    D2GFX_DrawBox(nX, nY - nHeight, nWidth + nX, nY, dwColor, nDrawMode);
}

// 0x00501A80
static void __stdcall FONT_DrawString(const Unicode* wszText, int nX, int nY, int nWidth, int nGlobalPaletteShift, int bCentered)
{
    const int nLength = sub_00526800(wszText);
    int nCount = 0;
    const int nStartX = nX;
    if (bCentered)
    {
        nX += (nWidth - FONT_GetFirstLineWidth(wszText)) >> 1;
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpFontCache->pCellFile;
    tContext.nDirection = 0;

    const Unicode* wszTextCur = wszText;
    while (nCount < nLength)
    {
        const Unicode tChar = *wszTextCur;
        ++wszTextCur;
        ++nCount;
        const unsigned short wChar = wszTextCur[-1].wChar;

        const int bColor = (wChar < 0x100) ? (wChar == 0xFF) : 0;
        if (bColor)
        {
            const Unicode tNext = *wszTextCur;
            ++nCount;
            ++wszTextCur;

            if (!Unicode::strncmp(&tNext, (const Unicode*)gwszColorCode_008426E0, 1))
            {
                if (nCount >= nLength)
                {
                    nGlobalPaletteShift = 0;
                }
                else
                {
                    const Unicode* pDigit = wszTextCur;
                    ++nCount;
                    ++wszTextCur;
                    nGlobalPaletteShift = pDigit->wChar - '0';
                    if (nGlobalPaletteShift >= '\r')
                    {
                        nGlobalPaletteShift = 0;
                    }
                }
            }
            else
            {
                --nCount;
                --wszTextCur;

                D2CharStrc* pCharInfo = gpfnGetCharInfo(*(const int*)&tChar);
                tContext.nFrame = pCharInfo->nImageIndex;
                TEXTURE_CelDrawColor(&tContext, nX, nY, (unsigned int)-1, 5, nGlobalPaletteShift);

                nX += pCharInfo->nWidth;
            }
        }
        else if (tChar.wChar != '\n')
        {
            D2CharStrc* pCharInfo = gpfnGetCharInfo(*(const int*)&tChar);
            tContext.nFrame = pCharInfo->nImageIndex;
            TEXTURE_CelDrawColor(&tContext, nX, nY, (unsigned int)-1, 5, nGlobalPaletteShift);

            nX += pCharInfo->nWidth;
        }
        else
        {
            if (bCentered)
            {
                nX = ((nWidth - FONT_GetFirstLineWidth(wszTextCur)) >> 1) + nStartX;
            }
            else
            {
                nX = nStartX;
            }

            nY += gnFontMetric1 * gatFontCache[gnCurrentFont].pFontInfo[1]->nHeight / -10;
        }
    }
}


// 0x00501C30
static void __stdcall FONT_DrawTextLineWithDrawMode(const Unicode* wszText, int nX, int nY, int nWidth, int nColor, int bCentered, int eDrawMode)
{
    const int nLength = sub_00526800(wszText);
    int nCount = 0;
    const int nStartX = nX;
    if (bCentered)
    {
        nX += (nWidth - FONT_GetFirstLineWidth(wszText)) >> 1;
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpFontCache->pCellFile;
    tContext.nDirection = 0;

    if (nLength <= 0)
    {
        return;
    }

    const Unicode* wszTextCur = wszText;
    do
    {
        const Unicode tChar = *wszTextCur;
        ++wszTextCur;
        ++nCount;
        const unsigned short wChar = wszTextCur[-1].wChar;

        const int bColor = (wChar < 0x100) ? (wChar == 0xFF) : 0;
        if (bColor)
        {
            const Unicode tNext = *wszTextCur;
            ++nCount;
            ++wszTextCur;

            if (!Unicode::strncmp(&tNext, (const Unicode*)gwszColorCode_008426E0, 1))
            {
                if (nCount >= nLength)
                {
                    nColor = 0;
                }
                else
                {
                    const Unicode* pDigit = wszTextCur;
                    ++nCount;
                    ++wszTextCur;
                    nColor = pDigit->wChar - '0';
                    if (nColor >= '\r')
                    {
                        nColor = 0;
                    }
                }
            }
            else
            {
                --nCount;
                --wszTextCur;

                D2CharStrc* pCharInfo = gpfnGetCharInfo(*(const int*)&tChar);
                tContext.nFrame = pCharInfo->nImageIndex;
                TEXTURE_CelDrawColor(&tContext, nX, nY, (unsigned int)-1, eDrawMode, nColor);

                nX += pCharInfo->nWidth;
            }
        }
        else if (tChar.wChar != '\n')
        {
            D2CharStrc* pCharInfo = gpfnGetCharInfo(*(const int*)&tChar);
            tContext.nFrame = pCharInfo->nImageIndex;
            TEXTURE_CelDrawColor(&tContext, nX, nY, (unsigned int)-1, eDrawMode, nColor);

            nX += pCharInfo->nWidth;
        }
        else
        {
            if (bCentered)
            {
                nX = ((nWidth - FONT_GetFirstLineWidth(wszTextCur)) >> 1) + nStartX;
            }
            else
            {
                nX = nStartX;
            }

            nY += -16 * gatFontCache[gnCurrentFont].pFontInfo[1]->nHeight / 10;
        }
    }
    while (nCount < nLength);
}

inline int sub_K08_IsColorCodePrefix(unsigned short wChar)
{
    if (wChar >= 0x100)
        return 0;

    return wChar == 0xFF;
}

// 0x00502190
static void D2Win_10126_DrawTextFromCache(const Unicode* pText, int nX, int nY)
{
    const Unicode* wszText = pText;
    const int nStartX = nX;
    const int nLength = sub_00526800(pText);

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpFontCache->pCellFile;
    tContext.nDirection = 0;

    if (nLength <= 0)
        return;

    while (1)
    {
        const Unicode wc = *wszText;
        ++wszText;
        if (sub_K08_IsColorCodePrefix(wc.wChar))
        {
            wszText += 2;
            continue;
        }

        if (wc.wChar != 0x0A)
        {
            D2CharStrc* pChar = ((D2CharStrc* (__fastcall*)(unsigned short))gpfnGetCharInfo)(wc.wChar);
            tContext.nFrame = pChar->nImageIndex;
            sub_004F6480(&tContext, nX, nY, -1, 5, 0);
            nX += pChar->nWidth;
        }
        else
        {
            nX = nStartX;
            nY += -15 * gatFontCache[gnCurrentFont].pFontInfo[1]->nHeight / 10;
        }
    }
}

// 0x00502280
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nTextColor, int nAlign)
{
    if (wszText && sub_00526800(wszText) < 1024)
        sub_005267E0(gwszFramedText, wszText);
    else
        memset(gwszFramedText, 0, sizeof(gwszFramedText));
    gnFramedTextX = nX;
    gnFramedTextY = nY;
    gnFramedTextColor = nTextColor;
    gnFramedTextAlign = nAlign;
    gnFramedTextRectColor = 0;
}

// 0x005022F0
void __fastcall D2Win_10130_DrawFramedTextEx(const Unicode* wszText, int nX, int nY, int nTextColor, int nAlign, int nRectangleColor)
{
    D2Win_10129_DrawFramedText(wszText, nX, nY, nTextColor, nAlign);
    gnFramedTextRectColor = nRectangleColor;
}

// 0x00502320
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered)
{
    int nWidth = 0;
    if (bCentered)
        nWidth = FONT_GetMaxLineWidth(wszText) + 8;
    sub_00501A80_DrawTextLine(nY, nWidth, nColor, bCentered, wszText, nX);
}

// 0x00502360
void __fastcall D2Win_10118_DrawBlendedText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered, int eDrawMode)
{
    int nWidth = 0;
    if (bCentered)
        nWidth = FONT_GetMaxLineWidth(wszText) + 8;
    FONT_DrawTextLineWithDrawMode(wszText, nX, nY, nWidth, nColor, bCentered, eDrawMode);
}

// 0x005023A0
void __fastcall FONT_DrawTextFromCache(const Unicode* pText, int nX, int nY)
{
    D2Win_10126_DrawTextFromCache(pText, nX, nY);
}

// calling-convention shim (not game code)
static void __stdcall sub_00501A80_DrawString(const Unicode* wszText, int nX, int nY, int nWidth, int nPalette, int bCentered)
{
    shim_2 = nX;
    const int nLength = sub_00526800((const Unicode*)wszText);
    shim_1(nLength, nY, nWidth, nPalette, bCentered);
}

static inline void sub_005023B0_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight)
{
    *pWidth = FONT_GetMaxLineWidth(pText) + 8;
    *pHeight = FONT_GetTextHeight(pText);
}

// 0x005023B0
void __fastcall D2Win_10132(const Unicode* wszText, int nX, int nY, unsigned int dwColor, int eDrawMode, int nColor)
{
    int nTextWidth = 0;
    int nTextHeight = 0;
    sub_005023B0_GetTextDimensions(wszText, &nTextWidth, &nTextHeight);

    nY += 2;

    int nScreenWidth;
    int nScreenHeight;
    WINDOW_GetDimensions(&nScreenWidth, &nScreenHeight);

    int nLeft = D2_MAX(nX, 0);
    if (nLeft >= nScreenWidth - nTextWidth)
    {
        nLeft = nScreenWidth - nTextWidth;
    }
    nY = D2_MIN(D2_MAX(nY, nTextHeight), nScreenHeight - 31);

    D2GFX_DrawBox(nLeft, nY - nTextHeight, nTextWidth + nLeft, nY, dwColor, eDrawMode);
    sub_00501A80_DrawString(wszText, nLeft, nY - 3 * gatFontCache[gnCurrentFont].pFontInfo[1]->nHeight / 10, nTextWidth, nColor, 1);
}

// 0x00502480
void __fastcall D2Win_10133(const Unicode* wszText, int nX, int nY, int nColor, int nDrawMode, int nTextColor)
{
    int nScreenWidth;
    int nLeft;
    int nTop;
    int nScreenHeight;
    const int nRectWidth = FONT_GetMaxLineWidth(wszText);
    const int nRectHeight = gatFontCache[gnCurrentFont].pFontInfo[1]->nHeight;
    nLeft = nX;
    nY += 2;
    nTop = nY;
    WINDOW_GetDimensions(&nScreenWidth, &nScreenHeight);
    if (nX + nRectWidth > nScreenWidth)
        nLeft = nScreenWidth - nRectWidth;
    if (nY > nScreenHeight - 31)
        nTop = nScreenHeight - 31;
    if (nTop - nRectHeight < 0)
        nTop *= 2;
    D2GFX_DrawBox(nLeft, nTop - nRectHeight, nLeft + nRectWidth, nTop, nColor, nDrawMode);
    sub_00501A80_DrawTextLine(nTop - 2, nRectWidth, nTextColor, 1, wszText, nLeft);
}

static int FONT_GetMaxLineWidth(unsigned short wChar)
{
    return wChar == 0xFF;
}

static void __stdcall sub_00501A80_DrawTextLine(int nY, int nWidth, int nShift, int bCentre, const Unicode* pText, int nX)
{
    const int nLength = sub_00526800(pText);
    int nCount = 0;
    const int nStartX = nX;
    if (bCentre)
        nX += (nWidth - FONT_GetFirstLineWidth(pText)) >> 1;
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpFontCache->pCellFile;
    tContext.nDirection = 0;
    while (nCount < nLength)
    {
        const Unicode c = *pText;
        const int bColor = sub_K08_IsColorCodePrefix(pText->wChar);
        ++pText;
        ++nCount;
        if (bColor)
        {
            const Unicode c2 = *pText;
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
                    nShift = (pText++)->wChar - '0';
                    if (nShift >= 13)
                        nShift = 0;
                }
            }
            else
            {
                --nCount;
                --pText;
                D2CharStrc* pChar = gpfnGetCharInfo(c.wChar);
                tContext.nFrame = pChar->nImageIndex;
                TEXTURE_CelDrawColor(&tContext, nX, nY, -1, 5, nShift);
                nX += pChar->nWidth;
            }
        }
        else if (c.wChar != '\n')
        {
            D2CharStrc* pChar = gpfnGetCharInfo(c.wChar);
            tContext.nFrame = pChar->nImageIndex;
            TEXTURE_CelDrawColor(&tContext, nX, nY, -1, 5, nShift);
            nX += pChar->nWidth;
        }
        else
        {
            if (bCentre)
                nX = ((nWidth - FONT_GetFirstLineWidth(pText)) >> 1) + nStartX;
            else
                nX = nStartX;
            nY += gatFontCache[gnCurrentFont].pFontInfo[1]->nHeight * gnFontMetric1 / -10;
        }
    }
}

// 0x00502520
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight)
{
    *pWidth = FONT_GetMaxLineWidth(pText);
    *pHeight = FONT_GetTextHeight(pText);
}

// Returns whether the font can draw a character: 0 for the colour-code prefix 0xFF, else the character's bit in its
// row of gaFontCharValidBits.
// 0x00502550
unsigned int __fastcall D2Win_10128(unsigned char nCharCode)
{
    if (Unicode(nCharCode).isPipe())
    {
        return 0;
    }

    // stands for the original not knowing the character's range: it masks the row with 7 and checks it against 8 (the identical arms, the identical-arm if and the __assume keep that shape)
    const unsigned int nRowChar = nCharCode ? nCharCode : nCharCode;
    const unsigned int dwOffset = (nRowChar >> 5) & 7;
    D2_ASSERT(dwOffset < 8, 0x4D8);
    const int nShift = nCharCode % 32;
    unsigned int dwWord = gaFontCharValidBits[dwOffset];
    if (dwOffset)
    {
        dwWord >>= nShift;
    }
    else
    {
        dwWord >>= nShift;
    }
    const int nBits = (unsigned char)dwWord;
    __assume(nBits != 0x80000000);
    return nBits & 1;
}

// 0x005025C0
void __fastcall FONT_DrawTextWithBackground(const Unicode* wszText, int nX, int nY, int nWidth, int nColor, int eDrawMode, int nTextColor)
{
    int nScreenWidth;
    int nLeft;
    int nScreenHeight;
    const int nTextHeight = FONT_GetTextHeight(wszText);
    const int nPad = 4 * gatFontCache[gnCurrentFont].pFontInfo[1]->nHeight / 10;
    nLeft = nX;
    nY += 2;
    WINDOW_GetDimensions(&nScreenWidth, &nScreenHeight);
    if (nX + nWidth > nScreenWidth)
        nLeft = nScreenWidth - nWidth;
    if (nY > nScreenHeight - 31)
        nY = nScreenHeight - 31;
    if (nY - nTextHeight < 0)
        nY *= 2;
    const int nInset = nLeft - 4;
    D2GFX_DrawBox(nInset, nY + nPad - nTextHeight, nInset + nWidth, nY, nColor, eDrawMode);
    sub_00501A80_DrawTextLine(nY - 2, 0, nTextColor, 0, wszText, nLeft);
}

void __fastcall sub_M98_Emit_005019C0(const Unicode* pText, int* pHeight, int nExtra)
{
    *pHeight = FONT_GetTextHeight(pText) + nExtra;
}

// 0x00502680
void __fastcall D2Win_10134_DrawCellFile(D2CelFileStrc* pCell, int nX, int nY, int nAlign, int eDrawMode, int nShift)
{
    const unsigned int nFrames = CelFileGetCelsPerDirection((D2CelFileStrc*)pCell);
    unsigned int nWidth;
    D2CelContextStrc tGfxData;
    memset(&tGfxData, 0, sizeof(tGfxData));
    tGfxData.pCellFile = (D2CelFileStrc*)pCell;
    tGfxData.nDirection = 0;
    nWidth = 0;

    if (nAlign == 1 || nAlign == 2)
    {
        for (unsigned int i = 0; i < nFrames; ++i)
        {
            tGfxData.nFrame = i;
            D2CelStrc* pCel = CelGetHandle((D2CmpCelContextStrc*)&tGfxData);
            nWidth += CelGetWidth(pCel);
        }

        if (nAlign == 1)
        {
            nX -= (nWidth >> 1) + 1;
        }
        else
        {
            nX -= nWidth;
        }
    }

    unsigned int j = 0;
    if (j < nFrames)
    {
        int nPosX = nX;
        do
        {
            tGfxData.nFrame = j;
            if (nShift == -1)
            {
                TEXTURE_CelDraw(&tGfxData, nPosX, nY, (unsigned int)-1, eDrawMode, 0);
            }
            else
            {
                TEXTURE_CelDrawColor(&tGfxData, nPosX, nY, (unsigned int)-1, eDrawMode, nShift);
            }
            nPosX += 0x100;
        } while (++j < nFrames);
    }
}

// 0x00502750
void __fastcall D2Win_10120(const Unicode* text,int x,int y,int color,int centered,int fill)
{
 if(!sub_00526800(text)) return;
 const int width=FONT_GetMaxLineWidth(text)+8;
 int screenWidth,screenHeight;
 int rest;
 int height=FONT_GetTextHeight(text);
 if(centered==1) { rest=width>>1; x-=rest; }
 y+=2;
 WINDOW_GetDimensions(&screenWidth,&screenHeight);
 const int left=((0<x?x:0)<screenWidth-width?(0<x?x:0):screenWidth-width);
 y=((y>height?y:height)<screenHeight-31?(y>height?y:height):screenHeight-31);
 if(fill) {
  if(!gnTooltipColor) gnTooltipColor=PALETTE_FindPaletteIndex(80,0,0);
  const int filled=(width*fill)>>7;
  const int right=filled+left;
  ((void (__stdcall*)(int,int,int,int,unsigned char,int))D2GFX_DrawBox)(left,y-height,right,y,gnTooltipColor,1);
  rest=width-filled;
  if(rest) D2GFX_DrawBox(right,y-height,right+rest,y,0,2);
 } else D2GFX_DrawBox(left,y-height,left+width,y,0,2);
 const int inset=3*gatFontCache[gnCurrentFont].pFontInfo[1]->nHeight/10;
 FONT_DrawString(text,left,y-inset,width,color,1);
}

// 0x005028A0
void __fastcall D2Win_10200(D2SplittedTextStrc* pLines)
{
    while (pLines)
    {
        D2SplittedTextStrc* pNext = pLines->pNextLine;
        FOG_Free(pLines->wszLine, ".\\Src\\D2WinFont.cpp", 0x579, 0);
        FOG_Free(pLines, ".\\Src\\D2WinFont.cpp", 0x57A, 0);
        pLines = pNext;
    }
}

// 0x005028E0
D2SplittedTextStrc* __stdcall D2Win_AllocateSplitText(const Unicode* wszText, int nLength, int bSkipSpace)
{
    const Unicode* pText = wszText;
    D2SplittedTextStrc* pSplitText = (D2SplittedTextStrc*)FOG_Alloc(sizeof(D2SplittedTextStrc), ".\\Src\\D2WinFont.cpp", 0x588, 0);
    int nCount = nLength;
    if (bSkipSpace && pText->wChar < 0x100 && isspace(pText->wChar))
    {
        nCount = nCount - 1;
        pText = pText + 1;
    }
    pSplitText->wszLine = (Unicode*)FOG_Alloc(sizeof(Unicode) * (nCount + 1), ".\\Src\\D2WinFont.cpp", 0x591, 0);
    pSplitText->pNextLine = 0;
    Unicode::strncpy(pSplitText->wszLine, pText, nCount);
    pSplitText->wszLine[nCount].wChar = 0;
    return pSplitText;
}

// 0x00502C40
int* __fastcall D2WINFONT_ClearTable(int* pTable)
{
    for (int i = 0; i < 0x200; ++i)
    {
        pTable[i] = 0;
    }
    return pTable;
}

extern "C" void __stdcall sub_K08_EmitDrawRect(int nX, int nY, int nWidth, int nHeight, unsigned int dwColor, int nDrawMode)
{
    FONT_DrawBox(nX, nY, nWidth, nHeight, dwColor, nDrawMode);
}

// 0x00502C60
void __fastcall D2Win_10115_FONT()
{
    char szFile[0x50];
    const int nLanguage = STRTABLE_GetLanguage();
    gbKoreanFonts = false;
    gnFontMetric1 = 16;
    gnFontMetric2 = 17;
    gnFontMetric3 = 3;

    if (nLanguage < 6)
    {
        strcpy(gszFontLanguage, "Latin\\");
        gpfnGetCharInfo = (D2CharStrc* (__fastcall*)(int))FONT_GetCharInfoByIndex;
        gnFontMetric2 = 16;
    }
    else switch (nLanguage)
    {
    case 12:
        gbKoreanFonts = true;
        strcpy(gszFontLanguage, "LATIN\\");
        gpfnGetCharInfo = (D2CharStrc* (__fastcall*)(int))FONT_GetCharInfoByIndex;
        break;

    case 6:
        gnFontMetric1 = 14;
        gnFontMetric2 = 15;
        gnFontMetric3 = 5;
        strcpy(gszFontLanguage, "JPN\\");
        gpfnGetCharInfo = (D2CharStrc* (__fastcall*)(int))FONT_FindCharInfo;
        break;

    case 7:
        gnFontMetric3 = 5;
        strcpy(gszFontLanguage, "KOR\\");
        gpfnGetCharInfo = (D2CharStrc* (__fastcall*)(int))FONT_FindCharInfo;
        break;

    case 8:
    case 9:
        gnFontMetric3 = 2;
        gnFontMetric1 = 14;
        gnFontMetric2 = 14;
        strcpy(gszFontLanguage, "CHI\\");
        gpfnGetCharInfo = (D2CharStrc* (__fastcall*)(int))FONT_FindCharInfo;
        break;

    case 10:
        gnFontMetric1 = 13;
        gnFontMetric2 = 13;
        strcpy(gszFontLanguage, "LATIN2\\");
        gpfnGetCharInfo = (D2CharStrc* (__fastcall*)(int))FONT_FindCharInfo;
        break;

    case 11:
        strcpy(gszFontLanguage, "CYR\\");
        gpfnGetCharInfo = (D2CharStrc* (__fastcall*)(int))FONT_FindCharInfo;
        break;

    default:
        strcpy(gszFontLanguage, "Latin\\");
        gpfnGetCharInfo = (D2CharStrc* (__fastcall*)(int))FONT_FindCharInfo;
        break;
    }

    if (!gatFontCache[1].pCellFile)
    {
        FONT_BuildFontPath(1, szFile, 0x4F);
        gatFontCache[1].pCellFile = ARCHIVE_LoadCellFile(szFile, 0);
        FONT_LoadFontTable(1);
    }

    if (!ghMonsterIndicators)
    {
        char szPath[0x104];
        wsprintfA(szPath, "%s\\UI\\Font\\MonsterIndicators", gszDataGlobal_006D4118);
        ghMonsterIndicators = ARCHIVE_LoadCellFile(szPath, 0);
    }

    gpFontCache = &gatFontCache[1];
    memset(gwszFramedText, 0, 0x800);
    *(unsigned short*)szFile = 'c';
    sub_00526320_ToUnicode((wchar_t*)gwszColorCode_008426E0, szFile, 2);
    *(unsigned short*)szFile = 'm';
    sub_00526320_ToUnicode((wchar_t*)gwszMonsterCode_008426DC, szFile, 2);
}

// 0x00502EF0
int __fastcall D2Win_10127_SetFont(int nFontSize)
{
    const int nOldFont = gnCurrentFont;
    const unsigned int dwShiftedTickCount = GetTickCount() >> 10;

    if (nOldFont == nFontSize)
    {
        gatFontCache[nFontSize].dwShiftedTickCount = dwShiftedTickCount;
        return nOldFont;
    }

    gnCurrentFont = nFontSize;

    if (!gatFontCache[nFontSize].pCellFile)
    {
        char szFile[0x50];
        FONT_BuildFontPath(nFontSize, szFile, 0x4F);
        gatFontCache[nFontSize].pCellFile = ARCHIVE_LoadCellFile(szFile, 0);
        FONT_LoadFontTable(nFontSize);
        gatFontCache[nFontSize].dwShiftedTickCount = dwShiftedTickCount;
    }

    if (dwShiftedTickCount - gdwLastShiftedTickCount > 600)
    {
        gdwLastShiftedTickCount = dwShiftedTickCount;

        for (int i = 0; i < 14; ++i)
        {
            D2FontCacheStrc* pFont = &gatFontCache[i];
            if (i != nFontSize && dwShiftedTickCount - pFont->dwShiftedTickCount > 240 && pFont->pCellFile)
            {
                ARCHIVE_FreeCellFile(pFont->pCellFile);
                pFont->pCellFile = 0;
            }
        }
    }

    gpFontCache = &gatFontCache[nFontSize];

    if (gbKoreanFonts)
    {
        gpfnGetCharInfo = (D2CharStrc* (__fastcall*)(int))FONT_FindCharInfo;
        if (nFontSize == 13)
            return nOldFont;
        gpfnGetCharInfo = (D2CharStrc* (__fastcall*)(int))FONT_GetCharInfoByIndex;
    }

    return nOldFont;
}

// 0x00503000
void __stdcall D2Win_10124()
{
    const int nSavedFont = gnCurrentFont;
    int nFont = gnCurrentFont;

    if (!sub_00526800(gwszFramedText))
    {
        return;
    }

    int nWidth;
    int nHeight;
    int nX;
    int nY;
    int nScreenWidth;
    int nScreenHeight;
    int nRest = 0;
    for (;;)
    {
        nWidth = FONT_GetMaxLineWidth(gwszFramedText) + 8;
        nHeight = FONT_GetTextHeight(gwszFramedText);

        nX = gnFramedTextX;
        if (gnFramedTextAlign == 1)
        {
            nX = gnFramedTextX - (nWidth >> 1);
        }

        nY = gnFramedTextY + 2;
        WINDOW_GetDimensions(&nScreenWidth, &nScreenHeight);

        if (nHeight <= nScreenHeight - 10)
        {
            break;
        }

        if (nFont == 1)
        {
            D2Win_10127_SetFont(0);
            nFont = 0;
        }
        else
        {
            if (gnCurrentFont)
            {
                break;
            }

            D2Win_10127_SetFont(6);
            nFont = 6;
        }
    }

    nX = D2_MIN(D2_MAX(nX, 0), nScreenWidth - nWidth);
    nY = D2_MIN(D2_MAX(nY, nHeight - 5), nScreenHeight - 5);

    if (gnFramedTextRectColor)
    {
        if (!gnTooltipColor)
        {
            gnTooltipColor = PALETTE_FindPaletteIndex(0x50, 0, 0);
        }

        const int nFill = nWidth * gnFramedTextRectColor >> 7;
        const int nRight = nFill + nX;
        ((void (__stdcall*)(int, int, int, int, unsigned char, int))D2GFX_DrawBox)(nX, nY - nHeight, nRight, nY, gnTooltipColor, 1);

        nRest = nWidth - nFill;
        if (nRest)
        {
            D2GFX_DrawBox(nRight, nY - nHeight, nRight + nRest, nY, 0, 2);
        }
    }
    else
    {
        D2GFX_DrawBox(nX, nY - nHeight, nX + nWidth, nY, 0, 2);
    }

    FONT_DrawString(gwszFramedText, nX, nY - gnFontMetric3 * gatFontCache[gnCurrentFont].pFontInfo[1]->nHeight / 10, nWidth,
                            gnFramedTextColor, 1);

    if (nFont != nSavedFont)
    {
        D2Win_10127_SetFont(nSavedFont);
    }
}

#include "gen/data/Source/D2Win/Src/D2WinFont.inc"
