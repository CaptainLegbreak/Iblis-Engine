#include "D2Lang.h"
#include "D2LangTypes.h"

#pragma intrinsic(strcmp)

struct D2ArchiveHandleStrc;

struct D2StrCacheNodeStrc;

struct D2LanguageInfoStrc;

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2ArchiveHandleStrc* __fastcall sub_00517332_LoadMpqFile(const char* szFileName, void* hFile, void* pfShowMessage, int nPriority); // 0x00517332

void __fastcall ARCHIVE_UnloadMPQFile(D2ArchiveHandleStrc* pMPQHandle); // 0x005173AC

extern "C" const char gszExpansionMpq[]; // 0x006CD3A0

extern "C" const char gszPatchD2Mpq[]; // 0x006DC728

extern "C" const char gszD2DataMpq[]; // 0x006DC770

struct D2StrCacheNodeStrc
{
    wchar_t* pText;
    char* szKey;
    D2StrCacheNodeStrc* pNext;
};

extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(void* hKey, const char* szValueName, unsigned long* pReserved, unsigned long* pType, unsigned char* pData, unsigned long* pcbData); // 0x006CC00C

extern "C" __declspec(dllimport) long __stdcall RegOpenKeyExA(void* hKey, const char* szSubKey, unsigned long nOptions, unsigned long nSamDesired, void** phResult); // 0x006CC010

extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey); // 0x006CC030

extern "C" unsigned int __cdecl strlen(const char* szString);

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

extern "C" char* __cdecl strcat(char* szDst, const char* szSrc);

extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);

unsigned short __stdcall STRTABLE_FindString(const char* szKey, const wchar_t** ppText); // 0x00524D30

int __fastcall STRTABLE_GetLanguageIdFromName(const char* szLanguage); // 0x00525100

struct Unicode
{
    unsigned short wChar;

    Unicode toUpper() const
    {
        Unicode tResult;
// build: symbol ?gawToUpperTable@* 0x00730578
        tResult.wChar = wChar < 0x100 ? gawToUpperTable[wChar] : wChar;
        return tResult;
    }
    static int __fastcall compare(Unicode lhs, Unicode rhs);
    static Unicode* __fastcall strncat(Unicode* dest, const Unicode* src, int count);
};

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

int __fastcall sub_00527D50_GetCodePageCharCount(const char* szSource, int nLength); // 0x00527D50

extern const unsigned short gawCrc16Table[256]; // 0x007301D8

extern "C" const char gszNotTranslated[]; // 0x00730520

struct D2LanguageInfoStrc
{
    const char* szName;
    const char* szCode;
    const char* szAltCode;
    const char* szRegion;
    int nFourCC;
    int f_14;
};

extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2); // 0x006841E9

void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079

extern D2LanguageInfoStrc gaLanguageInfo[13]; // 0x007303D8

void* ghD2DataMpq; // 0x008829DC

unsigned int __stdcall STRTABLE_HashKey(const char* szKey, unsigned int nTableSize); // 0x005249E0

wchar_t* __fastcall STRTABLE_GetUntranslatedString(const char* szKey); // 0x00524AC0

void __cdecl UNISYS_FreeCodePageTables(); // 0x00527720

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

void __stdcall CRC16_CalculateChecksum(unsigned short* crc16_checksum_out, const unsigned char* data, unsigned int start_index, unsigned int end_index); // 0x00525020

extern D2TblHeaderStrc* gpM15EmitTbl;

extern "C" const char szM15EmitFormat[];

extern "C" char* __cdecl _i64toa(__int64 nValue, char* szOut, int nRadix); // 0x006876D7

extern Unicode gawszUnitSuffix[4][2]; // 0x00730510

Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource); // 0x005267E0

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70

static D2TblHeaderStrc* STRTABLE_LoadTblFile(const char* szPath); // 0x00525920

extern "C" char* __cdecl _ui64toa(unsigned __int64 nValue, char* szOut, int nRadix); // 0x00687708

static unsigned short __stdcall STRTABLE_FindKey(void** ppSlots, const char* szKey, void** ppOut, D2TblHeaderStrc* pTable); // 0x00524C60

void* ghPatchD2Mpq; // 0x008829E0

void* ghExpansionMpq; // 0x008829E4

extern unsigned short gwCrc16Table_007301D8[0x100];                                                         // 0x007301D8

extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330

void __stdcall STRTABLE_GetLanguageInfoField(void* pOut, int nField);                                                 // 0x00525260

void __cdecl STRTABLE_InitUnitSuffixes();                                                               // 0x00525770

int __fastcall UNISYS_LoadSysMap(void* hArchive, const char* szPath);                            // 0x00527790

static D2TblHeaderStrc* sghStringTable;                                                             // 0x008829B4

static Unicode** gppStringIndex;                                                                    // 0x008829B8

static Unicode** gppPatchStringIndex;                                                               // 0x008829BC

static Unicode** gppExpansionStringIndex;                                                           // 0x008829C0

static Unicode* gpStringData;                                                                      // 0x008829C4

static Unicode* gpPatchStringData;                                                                 // 0x008829C8

static Unicode* gpExpansionStringData;                                                             // 0x008829CC

static D2TblHeaderStrc* sghPatchStringTable;                                                        // 0x008829D0

static D2TblHeaderStrc* sghExpansionStringTable;                                                    // 0x008829D4

static int gnStringTableRefs;                                                                      // 0x008829D8

struct Unicode;

char gszLanguage[256]; // 0x008829F8

static D2StrCacheNodeStrc* gpStringCache; // 0x008829B0

int gnTableLanguage; // 0x008829EC

bool gbTableLanguageInitialized; // 0x008829F0

wchar_t gwszEmptyString[2]; // 0x008829E8

// 0x00524810
int __cdecl STRTABLE_OpenArchives()
{
    D2_ASSERT(!ghD2DataMpq, 0x8A);
    ghD2DataMpq = sub_00517332_LoadMpqFile(gszD2DataMpq, 0, 0, 1000);
    if (!ghD2DataMpq)
        return 0;
    ghPatchD2Mpq = sub_00517332_LoadMpqFile(gszPatchD2Mpq, 0, 0, 1000);
    if (!ghPatchD2Mpq)
    {
        ARCHIVE_UnloadMPQFile((D2ArchiveHandleStrc*)ghD2DataMpq);
        ghD2DataMpq = 0;
        return 0;
    }
    ghExpansionMpq = sub_00517332_LoadMpqFile(gszExpansionMpq, 0, 0, 1000);
    if (!ghExpansionMpq)
    {
        ARCHIVE_UnloadMPQFile((D2ArchiveHandleStrc*)ghD2DataMpq);
        ghD2DataMpq = 0;
        ARCHIVE_UnloadMPQFile((D2ArchiveHandleStrc*)ghPatchD2Mpq);
        ghPatchD2Mpq = 0;
        return 0;
    }
    return 1;
}

// 0x005248E0
void __cdecl STRTABLE_CloseArchives()
{
    if (ghD2DataMpq)
    {
        ARCHIVE_UnloadMPQFile((D2ArchiveHandleStrc*)ghD2DataMpq);
        ghD2DataMpq = 0;
    }
    if (ghPatchD2Mpq)
    {
        ARCHIVE_UnloadMPQFile((D2ArchiveHandleStrc*)ghPatchD2Mpq);
        ghPatchD2Mpq = 0;
    }
    if (ghExpansionMpq)
    {
        ARCHIVE_UnloadMPQFile((D2ArchiveHandleStrc*)ghExpansionMpq);
        ghExpansionMpq = 0;
    }
}

// 0x00524930
const Unicode* __fastcall sub_00524930(D2TblHeaderStrc* pTable, void* pIndex, unsigned short nIndex)
{
    unsigned short nCount = pTable->nNumElements;
    unsigned short* pIndices = (unsigned short*)(pTable + 1);
    D2TblNodeStrc* pNodes = (D2TblNodeStrc*)&pIndices[nCount];
    if (nIndex >= nCount) nIndex = 500;
    int nEntry = pIndices[nIndex];
    D2_ASSERT(nEntry < pTable->nHashTableSize, 0x102);
    D2_ASSERT((unsigned char*)&pNodes[nEntry] < (unsigned char*)pTable + pTable->dwFileSize, 0x106);
    D2_ASSERT(pNodes[nEntry].bUsed == 1, 0x107);
    const Unicode* const* pString = &((const Unicode**)pIndex)[nEntry];
    D2_ASSERT(*pString, 0x109);
    return ((const Unicode**)pIndex)[nEntry];
}

// 0x005249C0
static inline void STRTABLE_FreeTable(void* pTable)
{
    FOG_Free(pTable, ".\\StrTable\\strtable.cpp", 0x121, 0);
}

void __fastcall sub_M129_Emit_005249C0(void* pTable1, void* pTable2)
{
    STRTABLE_FreeTable(pTable1);
    STRTABLE_FreeTable(pTable2);
}

// 0x005249E0
unsigned int __stdcall STRTABLE_HashKey(const char* szKey, unsigned int nTableSize)
{
    unsigned int nHash = 0;
    while (*szKey)
    {
        nHash = (nHash << 4) + *szKey;
        unsigned int nHigh = nHash & 0xF0000000;
        if (nHigh)
            nHash = ((nHigh >> 0x18) ^ nHash) & 0x0FFFFFFF;
        ++szKey;
    }
    return nHash % nTableSize;
}

// 0x00524A30
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex)
{
    if (nIndex >= 0x4E20)
    {
        if (!sghExpansionStringTable)
        {
            nIndex = 0x2B46;
        }
        else
        {
            const Unicode* pText = sub_00524930(sghExpansionStringTable, gppExpansionStringIndex, nIndex - 0x4E20);
            if (pText)
                return pText;
        }
    }
    if (sghPatchStringTable && nIndex >= 0x2710)
    {
        const Unicode* pText = sub_00524930(sghPatchStringTable, gppPatchStringIndex, nIndex - 0x2710);
        if (pText)
            return pText;
    }
    D2_ASSERT(sghStringTable, 0x246);
    return sub_00524930(sghStringTable, gppStringIndex, nIndex);
}

// 0x00524AC0
wchar_t* __fastcall STRTABLE_GetUntranslatedString(const char* szKey)
{
    for (D2StrCacheNodeStrc* pNode = gpStringCache; pNode; pNode = pNode->pNext)
    {
        if (!strcmp(szKey, pNode->szKey))
            return pNode->pText;
    }
    D2StrCacheNodeStrc* pNode = (D2StrCacheNodeStrc*)FOG_Alloc(sizeof(D2StrCacheNodeStrc), ".\\StrTable\\strtable.cpp", 0x259, 0);
    pNode->pNext = gpStringCache;
    gpStringCache = pNode;
    pNode->szKey = (char*)FOG_Alloc(strlen(szKey) + 1, ".\\StrTable\\strtable.cpp", 0x264, 0);
    strcpy(pNode->szKey, szKey);
    const int nLength = strlen(szKey) + strlen(gszNotTranslated);
    char* szText = (char*)FOG_Alloc(nLength + 1, ".\\StrTable\\strtable.cpp", 0x26C, 0);
    strcpy(szText, szKey);
    strcat(szText, gszNotTranslated);
    const int nChars = sub_00527D50_GetCodePageCharCount(szText, nLength);
    pNode->pText = (wchar_t*)FOG_Alloc(nChars * 2 + 2, ".\\StrTable\\strtable.cpp", 0x271, 0);
    sub_00526320_ToUnicode((Unicode*)pNode->pText, szText, nChars);
    FOG_Free(szText, ".\\StrTable\\strtable.cpp", 0x277, 0);
    return pNode->pText;
}

// 0x00524C60
static unsigned short __stdcall STRTABLE_FindKey(void** ppSlots, const char* szKey, void** ppOut, D2TblHeaderStrc* pTable)
{
	D2TblNodeStrc* pHashTable = (D2TblNodeStrc*)((char*)pTable + sizeof(D2TblHeaderStrc) + pTable->nNumElements * sizeof(unsigned short));
	unsigned int nLoops = 0;
	int const tArg1 = pTable->nHashTableSize;
	int nHash = STRTABLE_HashKey(szKey, tArg1);
	while (nLoops < pTable->dwNumLoops)
	{
		++nLoops;
		if ((&pHashTable[nHash])->bUsed == 1 && !strcmp((const char*)pTable + (&pHashTable[nHash])->dwStringOffset, szKey))
		{
			D2_ASSERT(ppSlots[nHash], 662);
			*ppOut = ppSlots[nHash];
			return pHashTable[nHash].nIndexNo;
		}
		nHash = (nHash + 1) % pTable->nHashTableSize;
	}

	return 0xFFFF;
}

// 0x00524D30
unsigned short __stdcall STRTABLE_FindString(const char* szKey, const wchar_t** ppText)
{
    D2_ASSERT(sghStringTable, 0x2BA);
    D2_ASSERT(sghPatchStringTable, 0x2BB);
    D2_ASSERT(szKey, 0x2C0);
    if (!*szKey)
    {
        *ppText = gwszEmptyString;
        return 0;
    }
    unsigned short nIndex = STRTABLE_FindKey((void**)gppPatchStringIndex, szKey, (void**)ppText, sghPatchStringTable);
    if (nIndex != 0xFFFF)
        return nIndex + 10000;
    if (sghExpansionStringTable)
    {
        nIndex = STRTABLE_FindKey((void**)gppExpansionStringIndex, szKey, (void**)ppText, sghExpansionStringTable);
        if (nIndex != 0xFFFF)
            return nIndex + 20000;
    }
    nIndex = STRTABLE_FindKey((void**)gppStringIndex, szKey, (void**)ppText, sghStringTable);
    if (nIndex == 0xFFFF)
    {
        *ppText = STRTABLE_GetUntranslatedString(szKey);
        return 0;
    }
    return nIndex;
}

// 0x00524E20
const wchar_t* __fastcall D2LANG_GetStringByReferenceString(const char* szKey)
{
    const wchar_t* pText = 0;
    STRTABLE_FindString(szKey, &pText);
    return pText;
}

// 0x00524E40
void __cdecl STRTABLE_UnloadStringTables()
{
    if (sghStringTable && --gnStringTableRefs == 0)
    {
        if (gppStringIndex)
        {
            FOG_Free(gpStringData, ".\\StrTable\\strtable.cpp", 0x329, 0);
            gpStringData = 0;
            FOG_Free(gppStringIndex, ".\\StrTable\\strtable.cpp", 0x32E, 0);
            gppStringIndex = 0;
        }
        FOG_Free(sghStringTable, ".\\StrTable\\strtable.cpp", 0x121, 0);
        sghStringTable = 0;

        if (gppPatchStringIndex)
        {
            FOG_Free(gppPatchStringIndex, ".\\StrTable\\strtable.cpp", 0x33C, 0);
            gppPatchStringIndex = 0;
        }
        if (gpPatchStringData)
        {
            FOG_Free(gpPatchStringData, ".\\StrTable\\strtable.cpp", 0x341, 0);
            gpPatchStringData = 0;
        }
        FOG_Free(sghPatchStringTable, ".\\StrTable\\strtable.cpp", 0x121, 0);
        sghPatchStringTable = 0;

        if (gppExpansionStringIndex)
        {
            FOG_Free(gppExpansionStringIndex, ".\\StrTable\\strtable.cpp", 0x34A, 0);
            gppExpansionStringIndex = 0;
        }
        if (gpExpansionStringData)
        {
            FOG_Free(gpExpansionStringData, ".\\StrTable\\strtable.cpp", 0x34F, 0);
            gpExpansionStringData = 0;
        }
        if (sghExpansionStringTable)
        {
            FOG_Free(sghExpansionStringTable, ".\\StrTable\\strtable.cpp", 0x121, 0);
            sghExpansionStringTable = 0;
        }

        D2StrCacheNodeStrc* pNode = gpStringCache;
        while (pNode)
        {
            D2StrCacheNodeStrc* pNext = pNode->pNext;
            FOG_Free(pNode->pText, ".\\StrTable\\strtable.cpp", 0x377, 0);
            FOG_Free(pNode->szKey, ".\\StrTable\\strtable.cpp", 0x378, 0);
            FOG_Free(pNode, ".\\StrTable\\strtable.cpp", 0x379, 0);
            pNode = pNext;
        }
        gpStringCache = 0;
        UNISYS_FreeCodePageTables();
    }
}

// 0x00524FD0
void __cdecl CRC16_Initialize(unsigned short* pCrc)
{
    *pCrc = 0xFFFF;
}

// 0x00524FE0
void __cdecl CRC16_Update(unsigned short* pCrc, unsigned char nByte)
{
    *pCrc = (*pCrc << 8) ^ gwCrc16Table_007301D8[(*pCrc >> 8) ^ nByte];
}

// 0x00525010
// build: symbol ?MISSILES_ToWord@* 0x0059FFF0
unsigned short __fastcall MISSILES_ToWord(unsigned short nValue)
{
    return nValue;
}

// 0x00525020
void __stdcall CRC16_CalculateChecksum(unsigned short* crc16_checksum_out, const unsigned char* data, unsigned int start_index, unsigned int end_index)
{
    D2_ASSERT(start_index < end_index, 0x3EA);
    *crc16_checksum_out = 0xFFFF;
    for (unsigned int i = start_index; i < end_index; ++i)
        *crc16_checksum_out = (*crc16_checksum_out << 8) ^ gawCrc16Table[(*crc16_checksum_out >> 8) ^ data[i]];
}

// 0x00525090
void __fastcall STRTABLE_ConvertLanguageNameToCode(char* szLanguage)
{
    for (int i = 0; i < 13; ++i)
    {
        if (!_stricmp(szLanguage, gaLanguageInfo[i].szName))
        {
            strcpy(szLanguage, gaLanguageInfo[i].szCode);
            return;
        }
    }
    strcpy(szLanguage, gaLanguageInfo[0].szCode);
}

// 0x00525100
int __fastcall STRTABLE_GetLanguageIdFromName(const char* szLanguage)
{
    for (int i = 0; i < 13; ++i)
    {
        if (!_stricmp(szLanguage, gaLanguageInfo[i].szName))
            return gaLanguageInfo[i].f_14;
    }
    return 0;
}

// 0x00525150
int __cdecl STRTABLE_GetLanguage()
{
    if (!gbTableLanguageInitialized)
    {
        gbTableLanguageInitialized = true;
        unsigned char* pBuffer = (unsigned char*)ARCHIVE_AllocateBufferAndReadFile(ghD2DataMpq, "data\\local\\use", 0, ".\\StrTable\\strtable.cpp", 0x44B);
        if (pBuffer)
        {
            gnTableLanguage = *pBuffer;
            FOG_Free(pBuffer, ".\\StrTable\\strtable.cpp", 0x450, 0);
        }
        if (gnTableLanguage >= 14)
            gnTableLanguage = 0;
    }
    return gnTableLanguage;
}

// 0x005251C0
int __cdecl STRTABLE_GetSystemLanguage()
{
    void* hKey;
    if (!RegOpenKeyExA((void*)0x80000001, "Control Panel\\International", 0, 0x20019, &hKey))
    {
        unsigned long nType;
        unsigned long nLength;
        if (!RegQueryValueExA(hKey, "sLanguage", 0, &nType, (unsigned char*)gszLanguage, &nLength) && strlen(gszLanguage) && strlen(gszLanguage) < 4)
        {
            RegCloseKey(hKey);
            return STRTABLE_GetLanguageIdFromName(gszLanguage);
        }
    }
    return 0;
}

int sub_M15_Emit_00525920(const char* szDir, const char* szLang)
{
    char szPath[0x104];
    sprintf(szPath, szM15EmitFormat, szDir, szLang);
    gpM15EmitTbl = STRTABLE_LoadTblFile(szPath);
    return gpM15EmitTbl != 0;
}

static inline const Unicode* D2LANG_GetStringFromTblIndex_Inline(unsigned short nIndex)
{
    if (nIndex >= 0x4E20)
    {
        if (!sghExpansionStringTable)
        {
            nIndex = 0x2B46;
        }
        else
        {
            const Unicode* pText = sub_00524930(sghExpansionStringTable, gppExpansionStringIndex, nIndex - 0x4E20);
            if (pText)
            {
                return pText;
            }
        }
    }
    if (sghPatchStringTable && nIndex >= 0x2710)
    {
        const Unicode* pText = sub_00524930(sghPatchStringTable, gppPatchStringIndex, nIndex - 0x2710);
        if (pText)
        {
            return pText;
        }
    }
    D2_ASSERT(sghStringTable, 0x246);
    return sub_00524930(sghStringTable, gppStringIndex, nIndex);
}

// 0x005259C0
int __fastcall STRTABLE_LoadStringTables(void* pMemPool, const char* szLanguage, int bExpansion)
{
    char szLang[4];
    char szMapPath[0x104];
    char szPath[0x104];
    char szFormat[0x104];
    char szCodePage[0x20];
    D2TblNodeStrc* pNodes;
    Unicode* pText;
    Unicode** pIndex;
    int nTotal;
    int i;

    if (sghStringTable)
    {
        ++gnStringTableRefs;
        return 1;
    }

    if (szLanguage)
        strcpy(szLang, szLanguage);
    else
        STRTABLE_GetLanguageInfoField(szLang, 0);

    if (!_stricmp(szLang, "JPN"))
        strcpy(szCodePage, "JPN");
    else if (!_stricmp(szLang, "KOR"))
        strcpy(szCodePage, "KOR");
    else if (!_stricmp(szLang, "POL"))
        strcpy(szCodePage, "LATIN2");
    else if (!_stricmp(szLang, "RUS"))
        strcpy(szCodePage, "CYR");
    else
        strcpy(szCodePage, "LATIN");

    sprintf(szMapPath, "data\\local\\font\\%s\\default.map", szCodePage);
    UNISYS_LoadSysMap(ghD2DataMpq, szMapPath);

    strncpy(szFormat, "data\\local\\lng\\%s\\string.tbl", 0x103);
    sprintf(szPath, szFormat, szLang);
    sghStringTable = STRTABLE_LoadTblFile(szPath);
    if (!sghStringTable)
        return 0;

    D2TblHeaderStrc* pTbl = sghStringTable;
    D2TblHeaderStrc* pLoaded = sghStringTable;

    pIndex = (Unicode**)FOG_Alloc(pTbl->nHashTableSize * sizeof(Unicode*), ".\\StrTable\\strtable.cpp", 0x18F, 0);
    gppStringIndex = pIndex;
    memset(pIndex, 0, pTbl->nHashTableSize * sizeof(Unicode*));
    ++gnStringTableRefs;

    pNodes = (D2TblNodeStrc*)((char*)sghStringTable + sizeof(D2TblHeaderStrc) + pLoaded->nNumElements * sizeof(unsigned short));
    nTotal = 0;
    for (i = 0; i < pTbl->nHashTableSize; i++)
    {
        const char* szText = (char*)sghStringTable + pNodes[i].dwKeyOffset;
        nTotal += sub_00527D50_GetCodePageCharCount(szText, pNodes[i].nNameLen) + 1;
    }

    gpStringData = (Unicode*)FOG_Alloc(nTotal * sizeof(Unicode), ".\\StrTable\\strtable.cpp", 0x1A9, 0);
    pText = gpStringData;
    for (i = 0; i < pTbl->nHashTableSize; i++)
    {
        gppStringIndex[i] = pText;
        const char* szText = (char*)sghStringTable + pNodes[i].dwKeyOffset;
        const int nCount = sub_00527D50_GetCodePageCharCount(szText, pNodes[i].nNameLen) + 1;
        sub_00526320_ToUnicode(gppStringIndex[i], szText, nCount);
        pText += nCount;
    }

    strncpy(szFormat, "data\\local\\lng\\%s\\patchstring.tbl", 0x103);
    sprintf(szPath, szFormat, szLang);
    sghPatchStringTable = STRTABLE_LoadTblFile(szPath);
    D2_ASSERT(sghPatchStringTable, 0x1C3);

    pTbl = sghPatchStringTable;

    pIndex = (Unicode**)FOG_Alloc(pTbl->nHashTableSize * sizeof(Unicode*), ".\\StrTable\\strtable.cpp", 0x1C5, 0);
    gppPatchStringIndex = pIndex;
    memset(pIndex, 0, pTbl->nHashTableSize * sizeof(Unicode*));

    pTbl = sghPatchStringTable;
    pNodes = (D2TblNodeStrc*)((char*)pTbl + sizeof(D2TblHeaderStrc) + pTbl->nNumElements * sizeof(unsigned short));
    nTotal = 0;
    for (i = 0; i < pTbl->nHashTableSize; i++)
    {
        const char* szText = (char*)sghPatchStringTable + pNodes[i].dwKeyOffset;
        nTotal += sub_00527D50_GetCodePageCharCount(szText, pNodes[i].nNameLen) + 1;
    }

    gpPatchStringData = (Unicode*)FOG_Alloc(nTotal * sizeof(Unicode), ".\\StrTable\\strtable.cpp", 0x1DC, 0);
    pText = gpPatchStringData;
    for (i = 0; i < pTbl->nHashTableSize; i++)
    {
        gppPatchStringIndex[i] = pText;
        const char* szText = (char*)sghPatchStringTable + pNodes[i].dwKeyOffset;
        const int nCount = sub_00527D50_GetCodePageCharCount(szText, pNodes[i].nNameLen) + 1;
        sub_00526320_ToUnicode(gppPatchStringIndex[i], szText, nCount);
        pText += nCount;
    }

    if (bExpansion)
    {
        strncpy(szFormat, "data\\local\\lng\\%s\\expansionstring.tbl", 0x103);
        sprintf(szPath, szFormat, szLang);
        sghExpansionStringTable = STRTABLE_LoadTblFile(szPath);
        D2_ASSERT(sghExpansionStringTable, 0x1F6);

        pTbl = sghExpansionStringTable;

        pIndex = (Unicode**)FOG_Alloc(pTbl->nHashTableSize * sizeof(Unicode*), ".\\StrTable\\strtable.cpp", 0x1F8, 0);
        gppExpansionStringIndex = pIndex;
        memset(pIndex, 0, pTbl->nHashTableSize * sizeof(Unicode*));

        pTbl = sghExpansionStringTable;
        pNodes = (D2TblNodeStrc*)((char*)pTbl + sizeof(D2TblHeaderStrc) + pTbl->nNumElements * sizeof(unsigned short));
        nTotal = 0;
        for (i = 0; i < pTbl->nHashTableSize; i++)
        {
            const char* szText = (char*)sghExpansionStringTable + pNodes[i].dwKeyOffset;
            nTotal += sub_00527D50_GetCodePageCharCount(szText, pNodes[i].nNameLen) + 1;
        }

        gpExpansionStringData = (Unicode*)FOG_Alloc(nTotal * sizeof(Unicode), ".\\StrTable\\strtable.cpp", 0x20F, 0);
        pText = gpExpansionStringData;
        for (i = 0; i < pTbl->nHashTableSize; i++)
        {
            gppExpansionStringIndex[i] = pText;
            const char* szText = (char*)sghExpansionStringTable + pNodes[i].dwKeyOffset;
            const int nCount = sub_00527D50_GetCodePageCharCount(szText, pNodes[i].nNameLen) + 1;
            sub_00526320_ToUnicode(gppExpansionStringIndex[i], szText, nCount);
            pText += nCount;
        }
    }

    STRTABLE_InitUnitSuffixes();
    return 1;
}

// 0x00525260
void __stdcall STRTABLE_GetLanguageInfoField(void* pOut, int nField)
{
    const int nLanguageId = sub_00525150();
    D2_ASSERT(gaLanguageInfo[0].f_14 == 0, 0x490);

    int nIndex = 0;
    if (nLanguageId < 14)
    {
        for (nIndex = 0; nIndex < 13; ++nIndex)
        {
            if (gaLanguageInfo[nIndex].f_14 == nLanguageId)
            {
                break;
            }
        }
        if (nIndex >= 14)
        {
            nIndex = 0;
        }
    }

    switch (nField)
    {
    case 1:
        strcpy((char*)pOut, gaLanguageInfo[nIndex].szAltCode);
        break;
    case 2:
        strcpy((char*)pOut, gaLanguageInfo[nIndex].szRegion);
        break;
    case 3:
        *(int*)pOut = gaLanguageInfo[nIndex].nFourCC;
        break;
    default:
        strcpy((char*)pOut, gaLanguageInfo[nIndex].szCode);
        break;
    }
}

extern "C" char* __cdecl _itoa(int nValue, char* szOut, int nRadix); // 0x00687605

// 0x00525FB0
void __stdcall D2LANG_FormatInt(Unicode* pOut, int nValue, int nSize)
{
    char szBuffer[64];
    int nGroup = 0;
    D2_ASSERT(nSize > 2, 0x4B9);
    if (nValue < 0)
    {
        pOut->wChar = '-';
        ++pOut;
        --nSize;
        nValue = -nValue;
    }
    _itoa(nValue, szBuffer, 10);
    int nLength = strlen(szBuffer);
    if (nLength)
    {
        int nPos = nLength + (nLength - 1) / 3;
        if (nPos >= 1 && nPos < nSize - 1)
        {
            pOut[nPos].wChar = 0;
            while (nLength)
            {
                D2_ASSERT(nPos != 0, 0x4D3);
                --nLength;
                --nPos;
                pOut[nPos].wChar = szBuffer[nLength];
                ++nGroup;
                if (nGroup >= 3 && strlen(szBuffer) > 3)
                {
                    nGroup = 0;
                    if (nPos > 0)
                    {
                        --nPos;
                        pOut[nPos].wChar = ',';
                    }
                }
            }
            return;
        }
    }
    {
        Unicode wszStar[2];
        wszStar[0].wChar = 0;
        wszStar[1].wChar = 0;
        sub_00526320_ToUnicode(wszStar, gszStar, 2);
        sub_005267E0(pOut, wszStar);
    }
}

// 0x00525350
void __stdcall STR_GroupUintDigits(Unicode* pOut, unsigned int nValue, int nSize)
{
    char szBuffer[64];
    int nGroup = 0;
    D2_ASSERT(nSize > 2, 0x4ED);
    _ultoa(nValue, szBuffer, 10);
    int nLength = strlen(szBuffer);
    if (nLength)
    {
        int nPos = nLength + (nLength - 1) / 3;
        if (nPos >= 1 && nPos < nSize - 1)
        {
            pOut[nPos].wChar = 0;
            while (nLength)
            {
                D2_ASSERT(nPos != 0, 0x500);
                --nLength;
                --nPos;
                pOut[nPos].wChar = szBuffer[nLength];
                ++nGroup;
                if (nGroup >= 3 && strlen(szBuffer) > 3)
                {
                    nGroup = 0;
                    if (nPos > 0)
                    {
                        --nPos;
                        pOut[nPos].wChar = ',';
                    }
                }
            }
            return;
        }
    }
    Unicode wszStar[2];
    wszStar[0].wChar = 0;
    wszStar[1].wChar = 0;
// build: symbol ?gszStar@* 0x006D5830
    sub_00526320_ToUnicode(wszStar, gszStar, 2);
    sub_005267E0(pOut, wszStar);
}

// 0x00525490
void __stdcall STR_GroupInt64Digits(Unicode* pOut, __int64 nValue, int nSize)
{
    char szBuffer[64];
    int nGroup = 0;
    D2_ASSERT(nSize > 2, 0x519);
    if (nValue < 0)
    {
        pOut->wChar = '-';
        ++pOut;
        --nSize;
        nValue = -nValue;
    }
    _i64toa(nValue, szBuffer, 10);
    int nLength = strlen(szBuffer);
    if (nLength)
    {
        int nPos = nLength + (nLength - 1) / 3;
        if (nPos >= 1 && nPos < nSize - 1)
        {
            pOut[nPos].wChar = 0;
            while (nLength)
            {
                D2_ASSERT(nPos != 0, 0x533);
                --nLength;
                --nPos;
                pOut[nPos].wChar = szBuffer[nLength];
                ++nGroup;
                if (nGroup >= 3)
                {
                    nGroup = 0;
                    if (nPos > 0)
                    {
                        --nPos;
                        pOut[nPos].wChar = ',';
                    }
                }
            }
            return;
        }
    }
    Unicode wszStar[2];
    wszStar[0].wChar = 0;
    wszStar[1].wChar = 0;
    sub_00526320_ToUnicode(wszStar, gszStar, 2);
    sub_005267E0(pOut, wszStar);
}

// 0x005255C0
void __stdcall STR_GroupUint64DigitsWithSuffix(Unicode* pOut, unsigned __int64 nValue, int nSize)
{
    char szBuffer[64];
    int nGroup = 0;
    int nUnit;
    D2_ASSERT(nSize > 2, 0x54B);
    _ui64toa(nValue, szBuffer, 10);
    int nLength = strlen(szBuffer);
    if (nLength)
    {
        nUnit = (nLength - 1) / 3 - 1;
        if (nUnit >= 4)
        {
            nUnit = 4;
        }
        else if (nUnit < 0)
        {
            nUnit = 0;
        }
        nLength += nUnit * -3;
        int nPos = nLength + (nLength - 1) / 3;
        if (nPos >= 1 && nPos < nSize - 2)
        {
            pOut[nPos + 1].wChar = 0;
            switch (nUnit)
            {
            case 0:
                pOut[nPos].wChar = 0;
                break;
            case 1:
                pOut[nPos].wChar = gawszUnitSuffix[0][0].wChar;
                break;
            case 2:
                pOut[nPos].wChar = gawszUnitSuffix[1][0].wChar;
                break;
            case 3:
                pOut[nPos].wChar = gawszUnitSuffix[2][0].wChar;
                break;
            case 4:
                pOut[nPos].wChar = gawszUnitSuffix[3][0].wChar;
                break;
            }
            while (nLength)
            {
                D2_ASSERT(nPos != 0, 0x580);
                --nLength;
                --nPos;
                pOut[nPos].wChar = szBuffer[nLength];
                ++nGroup;
                if (nGroup >= 3)
                {
                    nGroup = 0;
                    if (nPos > 0)
                    {
                        --nPos;
                        pOut[nPos].wChar = ',';
                    }
                }
            }
            return;
        }
    }
    {
        Unicode wszStar[2];
        wszStar[0].wChar = 0;
        wszStar[1].wChar = 0;
        sub_00526320_ToUnicode(wszStar, gszStar, 2);
        sub_005267E0(pOut, wszStar);
    }
}

// 0x00525770
void __cdecl STRTABLE_InitUnitSuffixes()
{
    char szBuffer[8];

    sub_00526F70(szBuffer, D2LANG_GetStringFromTblIndex_Inline(0x14D0), 5);
    if (strlen(szBuffer) > 1)
    {
        gawszUnitSuffix[0][0].wChar = 'K';
    }
    else
    {
        gawszUnitSuffix[0][0].wChar = szBuffer[0];
    }

    sub_00526F70(szBuffer, D2LANG_GetStringFromTblIndex_Inline(0x14D1), 5);
    if (strlen(szBuffer) > 1)
    {
        gawszUnitSuffix[1][0].wChar = 'M';
    }
    else
    {
        gawszUnitSuffix[1][0].wChar = szBuffer[0];
    }

    sub_00526F70(szBuffer, D2LANG_GetStringFromTblIndex_Inline(0x14D2), 5);
    if (strlen(szBuffer) > 1)
    {
        gawszUnitSuffix[2][0].wChar = 'B';
    }
    else
    {
        gawszUnitSuffix[2][0].wChar = szBuffer[0];
    }

    sub_00526F70(szBuffer, D2LANG_GetStringFromTblIndex_Inline(0x14D3), 5);
    if (strlen(szBuffer) > 1)
    {
        gawszUnitSuffix[3][0].wChar = 'T';
    }
    else
    {
        gawszUnitSuffix[3][0].wChar = szBuffer[0];
    }
}

Unicode* __fastcall Unicode::strncat(Unicode* dest, const Unicode* src, int count)
{
    Unicode* pEnd = dest;
    while (pEnd->wChar)
    {
        ++pEnd;
    }

    while (count--)
    {
        if (!src->wChar)
        {
            break;
        }
        *pEnd++ = *src++;
    }

    pEnd->wChar = 0;
    return dest;
}

// 0x00525920
static D2TblHeaderStrc* STRTABLE_LoadTblFile(const char* szPath)
{
    D2TblHeaderStrc* pHeader = (D2TblHeaderStrc*)sub_00517079(ghD2DataMpq, szPath, 0, ".\\StrTable\\strtable.cpp", 0xC0);

    unsigned short nCRC;
    CRC16_CalculateChecksum(&nCRC, (const unsigned char*)pHeader, pHeader->dwIndexStart, pHeader->dwFileSize);
    D2_ASSERT(nCRC == pHeader->nCRC, 0xCE);

    D2TblNodeStrc* pNode = (D2TblNodeStrc*)((char*)pHeader + sizeof(D2TblHeaderStrc) + pHeader->nNumElements * sizeof(unsigned short));
    for (int i = 0; i < pHeader->nHashTableSize; ++i)
    {
        D2_ASSERT(pNode[i].dwStringOffset < pHeader->dwFileSize, 0xE0);
        D2_ASSERT(pNode[i].dwKeyOffset < pHeader->dwFileSize, 0xE1);
    }

    return pHeader;
}


#include "gen/data/Source/D2Lang/StrTable/strtable.inc"
