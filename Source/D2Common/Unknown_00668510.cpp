#include "D2Common.h"
#include "D2CommonInternal.h"
#include "D2TxtItems.h"
#include "D2LevelTxt.h"
#include "D2Records.h"
#include "D2DataTbls.h"

extern D2DataTablesStrc sgtDataTables; // 0x0096BC30

extern "C" const char gszEmptyAssertText;

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);

extern "C" char* __cdecl strchr(const char* szString, int nChar);


struct D2ItemsTxt;

struct D2UniqueItemsTxt;

struct D2SetItemsTxt;

extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);

extern "C" unsigned int __cdecl strlen(const char* szString);

int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, unsigned int dwCode, int bLogError); // 0x006BD130

extern "C" const char gszComma[]; // 0x006EE82C

extern "C" const char gszEqualComma[]; // 0x006EE824

extern "C" const char gszCowPortal[]; // 0x006EE88C

extern "C" const char gszPandemoniumPortal[]; // 0x006EE878

extern "C" const char gszPandemoniumFinalePortal[]; // 0x006EE85C


static int __stdcall sub_00668A90_ParseCubeInput(D2CubeOutputItem* pInput, char* szInput);

static void sub_00668510_MakeCode(const char* szText, char* szCode);

static char* sub_00668590_NextSetToken(char** ppString, const char* szSet);

int __stdcall FOG_GetRowFromTxt(void* pLinker, const char* szText, int nColumn);                            // 0x006BD3C0

static int __stdcall sub_00668600_CubeMainInputParser(D2CubeInputItem* pCubeInput, char* szInput);

// Kept noinline: a static whose callers here pass its arguments in registers (the #368 case).
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

static inline int DATATBLS_StringToCode(const char* szText)
{
    int nCode;
    sub_00668510_MakeCode(szText, (char*)&nCode);
    return nCode;
}

static __forceinline int sub_00668A90_LookupItem(D2CubeOutputItem* pInput, char* szText)
{
    int nLinkId;
    if (strlen(szText) <= 4 && (nLinkId = FOG_GetLinkIndex(sgtDataTables.pItemTypesLinker, DATATBLS_StringToCode(szText), 0)) >= 0)
    {
        pInput->nType = 0xFD;
        pInput->wBaseItemId = nLinkId;
    }
    else
    {
        nLinkId = -1;
        if (sgtDataTables.pUniqueItemsLinker)
        {
            nLinkId = FOG_GetRowFromTxt(sgtDataTables.pUniqueItemsLinker, szText, 0);
        }
        if (nLinkId >= 0)
        {
            int nItemId;
            DATATBLS_GetItemRecordFromItemCode(sgtDataTables.pUniqueItemsTxt[nLinkId].dwCode, &nItemId);
            pInput->wItemFlags |= 8;
            pInput->nType = 0xFC;
            pInput->nQuality = 7;
            pInput->wItemID = nLinkId + 1;
            pInput->wBaseItemId = nItemId;
            pInput->nILvl = sgtDataTables.pUniqueItemsTxt[nLinkId].nLevel;
        }
        else
        {
            nLinkId = -1;
            if (sgtDataTables.pSetItemsLinker)
            {
                nLinkId = FOG_GetRowFromTxt(sgtDataTables.pSetItemsLinker, szText, 0);
            }
            if (nLinkId >= 0)
            {
                int nItemId;
                DATATBLS_GetItemRecordFromItemCode(sgtDataTables.pSetItemsTxt[nLinkId].dwItemCode, &nItemId);
                pInput->wItemFlags |= 8;
                pInput->nType = 0xFC;
                pInput->nQuality = 5;
                pInput->wItemID = nLinkId + 1;
                pInput->wBaseItemId = nItemId;
                pInput->nILvl = (unsigned char)sgtDataTables.pSetItemsTxt[nLinkId].wLvl;
            }
            return 0;
        }
    }
    return 1;
}

static inline int sub_00668A90_TryItemCode(D2CubeOutputItem* pInput, char* szText)
{
    int nCode;
    if (strlen(szText) <= 4 && DATATBLS_GetItemRecordFromItemCode(DATATBLS_StringToCode(szText), &nCode))
    {
        pInput->nType = 0xFC;
        pInput->wBaseItemId = nCode;
        return 1;
    }
    return 0;
}

static __forceinline int sub_00668A90_ParseItemName(D2CubeOutputItem* pInput, char* szText)
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

    if (sgtDataTables.pUniqueItemsLinker)
    {
        nLinkId = FOG_GetRowFromTxt(sgtDataTables.pUniqueItemsLinker, szInput, 0);
    }

    if (nLinkId >= 0)
    {
        D2UniqueItemsTxt* pUniqueItemsTxtRecord = &sgtDataTables.pUniqueItemsTxt[nLinkId];
        DATATBLS_GetItemRecordFromItemCode(pUniqueItemsTxtRecord->dwCode, pBaseItemId);
        pCubeInput->wInputFlags |= 0x41;
        pCubeInput->nQuality = 7;
        pCubeInput->wItemID = nLinkId + 1;
        pCubeInput->wItem = *pBaseItemId;
        return 1;
    }

    int nSetId = -1;

    if (sgtDataTables.pSetItemsLinker)
    {
        nSetId = FOG_GetRowFromTxt(sgtDataTables.pSetItemsLinker, szInput, 0);
    }

    if (nSetId < 0)
    {
        return 0;
    }

    D2SetItemsTxt* pSetItemsTxtRecord = &sgtDataTables.pSetItemsTxt[nSetId];
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
                nLinkId = FOG_GetLinkIndex(sgtDataTables.pItemTypesLinker, DATATBLS_StringToCode(szInput), 0);
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
static int __stdcall sub_00668A90_ParseCubeInput(D2CubeOutputItem* pInput, char* szInput)
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

        unsigned short* pSuffix = pInput->wSuffixId;
        unsigned short* pPrefix = pInput->wPrefixId;
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
                pInput->wItemFlags |= 4;
            }
            else if (!strcmp(szToken, "sock"))
            {
                pInput->wItemFlags |= 2;
                pInput->nQuantity = sub_006685C0_NextSetTokenInt(&szNext, gszComma);
            }
            else if (!strcmp(szToken, "mod"))
            {
                pInput->wItemFlags |= 1;
            }
            else if (!strcmp(szToken, "uns"))
            {
                pInput->wItemFlags |= 0x10;
            }
            else if (!strcmp(szToken, "rem"))
            {
                pInput->wItemFlags |= 0x20;
            }
            else if (!strcmp(szToken, "reg"))
            {
                pInput->wItemFlags |= 0x40;
                pInput->nType = 0xFF;
            }
            else if (!strcmp(szToken, "exc"))
            {
                pInput->wItemFlags |= 0x80;
            }
            else if (!strcmp(szToken, "eli"))
            {
                pInput->wItemFlags |= 0x100;
            }
            else if (!strcmp(szToken, "rep"))
            {
                pInput->wItemFlags |= 0x200;
            }
            else if (!strcmp(szToken, "rch"))
            {
                pInput->wItemFlags |= 0x400;
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
        sub_00668600_CubeMainInputParser(&((D2CubeMainTxt*)pRecord)->pInputItem[nOffset], pSrc);
}

// 0x006690B0
void __fastcall DATATBLS_CubeMainOutputLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    if (pRecord && pSrc && *pSrc)
        sub_00668A90_ParseCubeInput(&((D2CubeMainTxt*)pRecord)->pOutputItem[nOffset], pSrc);
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
            if (sgtDataTables.pItemStatCostLinker)
            {
                nValue = FOG_GetRowFromTxt(sgtDataTables.pItemStatCostLinker, pSrc, 0);
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

#pragma pack(push, 1)
struct d2data_00749690_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

extern "C" struct d2data_00749690_t gData_00749690; // 0x00749690

extern "C" const char gszEqualComma[3] = "=,"; // 0x006EE824

extern "C" const char gszComma[2] = ","; // 0x006EE82C

extern "C" struct d2data_00749690_t gData_00749690 = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x00749690

extern "C" const char gszPandemoniumFinalePortal[28] = "Pandemonium Finale Portal"; // 0x006EE85C

extern "C" const char gszPandemoniumPortal[20] = "Pandemonium Portal"; // 0x006EE878

extern "C" const char gszCowPortal[12] = "Cow Portal"; // 0x006EE88C
