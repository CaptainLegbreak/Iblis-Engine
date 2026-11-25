#include "D2Common.h"
#include "D2TxtItems.h"
#include "D2LevelTxt.h"
#include "D2Records.h"

extern "C" const char gszEmptyAssertText;

extern "C" const char* __cdecl sub_00408090();

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);

extern "C" char* __cdecl strchr(const char* szString, int nChar);

void __fastcall DATATBLS_FreeTreasureClassEx();

struct D2ItemsTxt;

struct D2CubeInputItemStrc;

struct D2UniqueItemsTxt;

struct D2SetItemsTxt;

struct D2CubeInputItemStrc
{
    unsigned short wFlags;
    unsigned short wItem;
    unsigned short wItemId;
    unsigned char nQuality;
    unsigned char nQuantity;
    unsigned char nType;
    unsigned char unk0x09[2];
    unsigned char nLevel;
    unsigned short wPrefix[3];
    unsigned short wSuffix[3];
};

extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);

extern "C" unsigned int __cdecl strlen(const char* szString);

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, unsigned int dwCode, int bLogError); // 0x006BD130

extern "C" const char gszComma[]; // 0x006EE82C

extern "C" const char gszEqualComma[]; // 0x006EE824

extern "C" const char gszCowPortal[]; // 0x006EE88C

extern "C" const char gszPandemoniumPortal[]; // 0x006EE878

extern "C" const char gszPandemoniumFinalePortal[]; // 0x006EE85C

extern D2TxtLinkStrc* gpItemTypesLinker_0096C824; // 0x0096C824

extern D2TxtLinkStrc* gpSetItemsLinker; // 0x0096C844

extern D2SetItemsTxt* gpSetItemsTxt_0096C848; // 0x0096C848

extern D2TxtLinkStrc* gpUniqueItemsLinker; // 0x0096C850

extern D2UniqueItemsTxt* gpUniqueItemsTxt_0096C854; // 0x0096C854

static int __stdcall sub_00668A90_ParseCubeInput(D2CubeInputItemStrc* pInput, char* szInput);

static __declspec(noinline) void sub_00668510_MakeCode(const char* szText, char* szCode);

static char* sub_00668590_NextSetToken(char** ppString, const char* szSet);

extern "C" unsigned int __cdecl strcspn(const char* szString, const char* szSet);                          // 0x00688990

extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB

extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2);                              // 0x006841E9

int __stdcall FOG_GetRowFromTxt(void* pLinker, const char* szText, int nColumn);                            // 0x006BD3C0

static int __stdcall sub_00668600_CubeMainInputParser(D2CubeInputItem* pCubeInput, char* szInput);

// 0x00668510
static __declspec(noinline) void sub_00668510_MakeCode(const char* szText, char* szCode)
{
    if (!szText[0])
    {
        szCode[0] = ' ';
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[0] = szText[0];
    if (!szText[1])
    {
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[1] = szText[1];
    if (!szText[2])
    {
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[2] = szText[2];
    if (!szText[3])
    {
        szCode[3] = ' ';
        return;
    }
    szCode[3] = szText[3];
}

unsigned int __stdcall sub_M91_Emit_00668510(const char* szText)
{
    unsigned int dwCode;
    sub_00668510_MakeCode(szText, (char*)&dwCode);
    return dwCode;
}

// 0x00668560
static char* DATATBLS_StripQuotes(char* szText)
{
    if (*szText == '"')
        ++szText;
    for (char* p = szText; *p; ++p)
    {
        if (*p == '"')
            *p = 0;
    }
    return szText;
}

static char* DATATBLS_GetNextStringToken(char** ppString, char chSeparator)
{
    char* szToken = *ppString;
    *ppString = strchr(szToken, chSeparator);
    if (*ppString)
    {
        **ppString = 0;
        ++*ppString;
    }
    return szToken;
}

char* __stdcall sub_M116_Emit_006543C0(char* szText, char** ppOut)
{
    ppOut[0] = DATATBLS_StripQuotes(DATATBLS_GetNextStringToken(&szText, ','));
    ppOut[1] = DATATBLS_GetNextStringToken(&szText, ',');
    return szText;
}

void __fastcall DATATBLS_UnloadTreasureClassExTxt()
{
    DATATBLS_FreeTreasureClassEx();
}

void __cdecl DATATBLS_ShouldNeverCallInExpansion()
{
    D2_ASSERT(0, 0x6AE);
}

// 0x00668590
static char* sub_00668590_NextSetToken(char** ppString, const char* szSet)
{
    char* szToken = *ppString;
    *ppString += strcspn(szToken, szSet);
    if (**ppString)
    {
        **ppString = 0;
        ++*ppString;
    }
    else
    {
        *ppString = 0;
    }
    return szToken;
}

// 0x006685C0
static int sub_006685C0_NextSetTokenInt(char** ppString, const char* szSet)
{
    char* szToken = *ppString;
    *ppString += strcspn(szToken, szSet);
    if (**ppString)
    {
        **ppString = 0;
        ++*ppString;
    }
    else
    {
        *ppString = 0;
    }
    return atoi(szToken);
}

char* __stdcall sub_M133_Emit_006685C0(char* szText, const char* szSet, int* pOut)
{
    pOut[0] = sub_006685C0_NextSetTokenInt(&szText, szSet);
    pOut[1] = sub_006685C0_NextSetTokenInt(&szText, szSet);
    return szText;
}

static inline int DATATBLS_StringToCode(const char* szText)
{
    int nCode;
    sub_00668510_MakeCode(szText, (char*)&nCode);
    return nCode;
}

static __forceinline int sub_00668A90_LookupItem(D2CubeInputItemStrc* pInput, char* szText)
{
    int nLinkId;
    if (strlen(szText) <= 4 && (nLinkId = FOG_GetLinkIndex(gpItemTypesLinker_0096C824, DATATBLS_StringToCode(szText), 0)) >= 0)
    {
        pInput->nType = 0xFD;
        pInput->wItem = nLinkId;
    }
    else
    {
        nLinkId = -1;
        if (gpUniqueItemsLinker)
        {
            nLinkId = FOG_GetRowFromTxt(gpUniqueItemsLinker, szText, 0);
        }
        if (nLinkId >= 0)
        {
            int nItemId;
            DATATBLS_GetItemRecordFromItemCode(gpUniqueItemsTxt_0096C854[nLinkId].dwCode, &nItemId);
            pInput->wFlags |= 8;
            pInput->nType = 0xFC;
            pInput->nQuality = 7;
            pInput->wItemId = nLinkId + 1;
            pInput->wItem = nItemId;
            pInput->nLevel = gpUniqueItemsTxt_0096C854[nLinkId].nLevel;
        }
        else
        {
            nLinkId = -1;
            if (gpSetItemsLinker)
            {
                nLinkId = FOG_GetRowFromTxt(gpSetItemsLinker, szText, 0);
            }
            if (nLinkId >= 0)
            {
                int nItemId;
                DATATBLS_GetItemRecordFromItemCode(gpSetItemsTxt_0096C848[nLinkId].dwItemCode, &nItemId);
                pInput->wFlags |= 8;
                pInput->nType = 0xFC;
                pInput->nQuality = 5;
                pInput->wItemId = nLinkId + 1;
                pInput->wItem = nItemId;
                pInput->nLevel = (unsigned char)gpSetItemsTxt_0096C848[nLinkId].wLvl;
            }
            return 0;
        }
    }
    return 1;
}

static inline int sub_00668A90_TryItemCode(D2CubeInputItemStrc* pInput, char* szText)
{
    int nCode;
    if (strlen(szText) <= 4 && DATATBLS_GetItemRecordFromItemCode(DATATBLS_StringToCode(szText), &nCode))
    {
        pInput->nType = 0xFC;
        pInput->wItem = nCode;
        return 1;
    }
    return 0;
}

static __forceinline int sub_00668A90_ParseItemName(D2CubeInputItemStrc* pInput, char* szText)
{
    if (!_stricmp(szText, gszCowPortal))
    {
        pInput->nType = 1;
        return 1;
    }
    if (!_stricmp(szText, gszPandemoniumPortal))
    {
        pInput->nType = 2;
        return 1;
    }
    if (!_stricmp(szText, gszPandemoniumFinalePortal))
    {
        pInput->nType = 3;
        return 1;
    }
    if (!strcmp(szText, "usetype"))
    {
        pInput->nType = 0xFF;
        return 1;
    }

    if (!strcmp(szText, "useitem"))
    {
        pInput->nType = 0xFE;
        return 1;
    }

    return 0;
}

#pragma intrinsic(strlen, strcmp)

static __forceinline int DATATBLS_CubeInputFindUniqueOrSet(D2CubeInputItem* pCubeInput, char* szInput, int* pBaseItemId)
{
    int nLinkId = -1;

    if (gpUniqueItemsLinker)
    {
        nLinkId = FOG_GetRowFromTxt(gpUniqueItemsLinker, szInput, 0);
    }

    if (nLinkId >= 0)
    {
        D2UniqueItemsTxt* pUniqueItemsTxtRecord = &gpUniqueItemsTxt_0096C854[nLinkId];
        DATATBLS_GetItemRecordFromItemCode(pUniqueItemsTxtRecord->dwCode, pBaseItemId);
        pCubeInput->wInputFlags |= 0x41;
        pCubeInput->nQuality = 7;
        pCubeInput->wItemID = nLinkId + 1;
        pCubeInput->wItem = *pBaseItemId;
        return 1;
    }

    int nSetId = -1;

    if (gpSetItemsLinker)
    {
        nSetId = FOG_GetRowFromTxt(gpSetItemsLinker, szInput, 0);
    }

    if (nSetId < 0)
    {
        return 0;
    }

    D2SetItemsTxt* pSetItemsTxtRecord = &gpSetItemsTxt_0096C848[nSetId];
    DATATBLS_GetItemRecordFromItemCode(pSetItemsTxtRecord->dwItemCode, pBaseItemId);
    pCubeInput->wInputFlags |= 0x41;
    pCubeInput->nQuality = 5;
    pCubeInput->wItemID = nSetId + 1;
    pCubeInput->wItem = *pBaseItemId;
    return 1;
}

// 0x00668600
static int __stdcall sub_00668600_CubeMainInputParser(D2CubeInputItem* pCubeInput, char* szInput)
{
    char* szInputModifier;
    char* szNext;
    char* szTemp;
    int nBaseItemId;
    int nLinkId;

    if (*szInput == '"')
    {
        ++szInput;
    }

    szTemp = szInput;
    while (*szTemp)
    {
        if (*szTemp == '"')
        {
            *szTemp = 0;
        }
        ++szTemp;
    }

    if (!*szInput)
    {
        return 1;
    }

    {
        szNext = &szInput[strcspn(szInput, ",")];
        if (*szNext)
        {
            *szNext = 0;
            ++szNext;
        }
        else
        {
            szNext = 0;
        }

        if (strlen(szInput) <= 4 && !_stricmp(szInput, "any"))
        {
            pCubeInput->wInputFlags |= 1;
            pCubeInput->wItem = -1;
        }
        else
        {
            nLinkId = -1;

            if (strlen(szInput) <= 4)
            {
                nLinkId = FOG_GetLinkIndex(gpItemTypesLinker_0096C824, DATATBLS_StringToCode(szInput), 0);
            }

            if (nLinkId >= 0)
            {
                pCubeInput->wInputFlags |= 2;
                pCubeInput->wItem = nLinkId;
            }
            else if (strlen(szInput) <= 4 && DATATBLS_GetItemRecordFromItemCode(DATATBLS_StringToCode(szInput), &nBaseItemId))
            {
                pCubeInput->wInputFlags |= 1;
                pCubeInput->wItem = nBaseItemId;
            }
            else
            {
                if (!DATATBLS_CubeInputFindUniqueOrSet(pCubeInput, szInput, &nBaseItemId))
                {
                    return 0;
                }
            }
        }

        while (szNext)
        {
            szInputModifier = szNext;
            szNext = &szNext[strcspn(szNext, "=,")];
            if (*szNext)
            {
                *szNext = 0;
                ++szNext;
            }
            else
            {
                szNext = 0;
            }

            if (!szInputModifier)
            {
                return 1;
            }

            if (!strcmp(szInputModifier, "qty"))
            {
                szTemp = szNext;
                szNext = &szNext[strcspn(szNext, ",")];
                if (*szNext)
                {
                    *szNext = 0;
                    ++szNext;
                }
                else
                {
                    szNext = 0;
                }
                pCubeInput->nQuantity = atoi(szTemp);
            }
            else if (!strcmp(szInputModifier, "low"))
            {
                pCubeInput->nQuality = 1;
            }
            else if (!strcmp(szInputModifier, "nor"))
            {
                pCubeInput->nQuality = 2;
            }
            else if (!strcmp(szInputModifier, "hiq"))
            {
                pCubeInput->nQuality = 3;
            }
            else if (!strcmp(szInputModifier, "mag"))
            {
                pCubeInput->nQuality = 4;
            }
            else if (!strcmp(szInputModifier, "set"))
            {
                pCubeInput->nQuality = 5;
            }
            else if (!strcmp(szInputModifier, "rar"))
            {
                pCubeInput->nQuality = 6;
            }
            else if (!strcmp(szInputModifier, "uni"))
            {
                pCubeInput->nQuality = 7;
            }
            else if (!strcmp(szInputModifier, "crf"))
            {
                pCubeInput->nQuality = 8;
            }
            else if (!strcmp(szInputModifier, "tmp"))
            {
                pCubeInput->nQuality = 9;
            }
            else if (!strcmp(szInputModifier, "nos"))
            {
                pCubeInput->wInputFlags |= 4;
            }
            else if (!strcmp(szInputModifier, "sock"))
            {
                pCubeInput->wInputFlags |= 8;
            }
            else if (!strcmp(szInputModifier, "noe"))
            {
                pCubeInput->wInputFlags |= 0x20;
            }
            else if (!strcmp(szInputModifier, "eth"))
            {
                pCubeInput->wInputFlags |= 0x10;
            }
            else if (!strcmp(szInputModifier, "upg"))
            {
                pCubeInput->wInputFlags |= 0x80;
            }
            else if (!strcmp(szInputModifier, "bas"))
            {
                pCubeInput->wInputFlags |= 0x100;
            }
            else if (!strcmp(szInputModifier, "exc"))
            {
                pCubeInput->wInputFlags |= 0x200;
            }
            else if (!strcmp(szInputModifier, "eli"))
            {
                pCubeInput->wInputFlags |= 0x400;
            }
            else if (!strcmp(szInputModifier, "nru"))
            {
                pCubeInput->wInputFlags |= 0x800;
            }
            else
            {
                return 1;
            }
        }
    }

    return 1;
}

// 0x00668A90
static int __stdcall sub_00668A90_ParseCubeInput(D2CubeInputItemStrc* pInput, char* szInput)
{
    char* szText = szInput;
    if (*szText == '"')
    {
        ++szText;
    }

    for (char* pChar = szText; *pChar; ++pChar)
    {
        if (*pChar == '"')
        {
            *pChar = 0;
        }
    }

    char* szNext = szText + strcspn(szText, gszComma);
    if (*szNext)
    {
        *szNext = 0;
        ++szNext;
    }
    else
    {
        szNext = 0;
    }

    if (!sub_00668A90_ParseItemName(pInput, szText) && !sub_00668A90_TryItemCode(pInput, szText) && !sub_00668A90_LookupItem(pInput, szText))
    {
        return 0;
    }

    if (szNext)
    {

        unsigned short* pSuffix = pInput->wSuffix;
        unsigned short* pPrefix = pInput->wPrefix;
        do
        {
            char* szToken = sub_00668590_NextSetToken(&szNext, gszEqualComma);
            if (!szToken)
            {
                break;
            }

            if (!strcmp(szToken, "qty"))
            {
                pInput->nQuantity = sub_006685C0_NextSetTokenInt(&szNext, gszComma);
            }
            else if (!strcmp(szToken, "pre"))
            {
                *pPrefix = sub_006685C0_NextSetTokenInt(&szNext, gszComma);
                ++pPrefix;
            }
            else if (!strcmp(szToken, "suf"))
            {
                *pSuffix = sub_006685C0_NextSetTokenInt(&szNext, gszComma);
                ++pSuffix;
            }
            else if (!strcmp(szToken, "low"))
            {
                pInput->nQuality = 1;
            }
            else if (!strcmp(szToken, "nor"))
            {
                pInput->nQuality = 2;
            }
            else if (!strcmp(szToken, "hiq"))
            {
                pInput->nQuality = 3;
            }
            else if (!strcmp(szToken, "mag"))
            {
                pInput->nQuality = 4;
            }
            else if (!strcmp(szToken, "set"))
            {
                pInput->nQuality = 5;
            }
            else if (!strcmp(szToken, "rar"))
            {
                pInput->nQuality = 6;
            }
            else if (!strcmp(szToken, "uni"))
            {
                pInput->nQuality = 7;
            }
            else if (!strcmp(szToken, "crf"))
            {
                pInput->nQuality = 8;
            }
            else if (!strcmp(szToken, "tmp"))
            {
                pInput->nQuality = 9;
            }
            else if (!strcmp(szToken, "eth"))
            {
                pInput->wFlags |= 4;
            }
            else if (!strcmp(szToken, "sock"))
            {
                pInput->wFlags |= 2;
                pInput->nQuantity = sub_006685C0_NextSetTokenInt(&szNext, gszComma);
            }
            else if (!strcmp(szToken, "mod"))
            {
                pInput->wFlags |= 1;
            }
            else if (!strcmp(szToken, "uns"))
            {
                pInput->wFlags |= 0x10;
            }
            else if (!strcmp(szToken, "rem"))
            {
                pInput->wFlags |= 0x20;
            }
            else if (!strcmp(szToken, "reg"))
            {
                pInput->wFlags |= 0x40;
                pInput->nType = 0xFF;
            }
            else if (!strcmp(szToken, "exc"))
            {
                pInput->wFlags |= 0x80;
            }
            else if (!strcmp(szToken, "eli"))
            {
                pInput->wFlags |= 0x100;
            }
            else if (!strcmp(szToken, "rep"))
            {
                pInput->wFlags |= 0x200;
            }
            else if (!strcmp(szToken, "rch"))
            {
                pInput->wFlags |= 0x400;
            }
            else
            {
                break;
            }
        }
        while (szNext);
    }

    return 1;
}

// 0x00669080
void __fastcall sub_00669080_CubeInputLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    if (pRecord && pSrc && *pSrc)
        sub_00668600_CubeMainInputParser((D2CubeInputItem*)((char*)pRecord + 0x14 + 8 * nOffset), pSrc);
}

// 0x006690B0
void __fastcall DATATBLS_CubeMainOutputLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    if (pRecord && pSrc && *pSrc)
        sub_00668A90_ParseCubeInput((D2CubeInputItemStrc*)((char*)pRecord + 0x4C + nOffset * 0x54), pSrc);
}

char* __stdcall sub_M133_Emit_00668590(char* szText, const char* szSet, char** ppOut)
{
    ppOut[0] = sub_00668590_NextSetToken(&szText, szSet);
    ppOut[1] = sub_00668590_NextSetToken(&szText, szSet);
    return szText;
}

// 0x006690E0
void __fastcall DATATBLS_CubeMainParamLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    int nValue = 0;

    if (pRecord && pSrc && *pSrc)
    {
        if (*pSrc == '-' || *pSrc >= '0' && *pSrc <= '9')
        {
            *(int*)pRecord = atoi(pSrc);
        }
        else
        {
            if (gTxtLink_0096C800)
            {
                nValue = FOG_GetRowFromTxt(gTxtLink_0096C800, pSrc, 0);
                if (nValue >= 0)
                {
                    *(int*)pRecord = nValue;
                    return;
                }
            }

            *(int*)pRecord = 0;
        }
    }
}

#include "gen/data/Source/D2Common/Unknown_00668510.inc"
