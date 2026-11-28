// A piece of ItemTbls.cpp (0x00631430-0x00639CC0), kept as its own file because the join doesn't build equal. Moved into
// ItemTbls.cpp, this loader and DATATBLS_LoadRareSuffix_PrefixTxt (0x00633F40) swap the loads of their summed
// record-count locals (and 0x00633F40 its commutative lea), and adding only the two field types this function needs
// (TXTFIELD_WORD, TXTFIELD_CODETOBYTE) to ItemTbls.cpp's D2C_TxtFieldTypes, with no function moved, already flips
// 0x00633F40. Placing those members in the existing later enum, in a new enum before the function or at the end of
// D2C_TxtFieldTypes gives the same result, so the piece stays until the unit's declaration sensitivity is understood.
struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

struct D2MagicAffixTxt
{
    char szName[0x20];
    unsigned short wTblIndex;
    char unk0x22[0x6E];
};

struct D2MagicAffixDataTbl
{
    int nMagicAffixTxtRecordCount;
    D2MagicAffixTxt* pMagicAffixTxt;
    D2MagicAffixTxt* pMagicSuffix;
    D2MagicAffixTxt* pMagicPrefix;
    D2MagicAffixTxt* pAutoMagic;
};

struct D2DataTablesStrc
{
    char unk0x000[0x004];
    D2TxtLinkStrc* pPlayerClassLinker;
    char unk0x008[0x0A0];
    D2TxtLinkStrc* pPropertiesLinker;
    char unk0x0AC[0x908];
    D2TxtLinkStrc* pColorsLinker;
    char unk0x9B8[0x23C];
    D2TxtLinkStrc* pItemTypesLinker;
    char unk0xBF8[0x254];
    D2MagicAffixDataTbl pMagicAffixDataTables;
};

enum
{
    TXTFIELD_NONE = 0,
    TXTFIELD_ASCII = 1,
    TXTFIELD_DWORD = 2,
    TXTFIELD_WORD = 3,
    TXTFIELD_BYTE = 4,
    TXTFIELD_CODETOBYTE = 13,
    TXTFIELD_CODETOWORD = 15,
    TXTFIELD_NAMETODWORD = 19,
    TXTFIELD_CALCTODWORD = 25,
};

extern "C" const char gszTxtField_version[];                                                                // 0x006DCCF0
extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
extern D2DataTablesStrc sgtDataTables;                                                                      // 0x0096BC30

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                          // 0x006125C0
unsigned short __stdcall STRTABLE_FindString(const char* szKey, const wchar_t** ppText);                // 0x00524D30
void __fastcall DATATBLS_ItemParamLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn);// 0x006336A0

// 0x00633730
void __fastcall DATATBLS_LoadMagicSuffix_Prefix_AutomagicTxt(void* hArchive)
{
    D2MagicAffixTxt* pMagicSuffix;
    D2MagicAffixTxt* pMagicPrefix;
    D2MagicAffixTxt* pAutoMagic;

    int nSuffixRecords;
    int nPrefixRecords;
    int nAutoMagicRecords;

    D2BinFieldStrc pTbl[] =
    {
        { "name", TXTFIELD_ASCII, 31, 0, 0 },
        { "spawnable", TXTFIELD_BYTE, 0, 84, 0 },
        { "level", TXTFIELD_DWORD, 0, 88, 0 },
        { "group", TXTFIELD_DWORD, 0, 92, 0 },
        { gszTxtField_version, TXTFIELD_WORD, 0, 34, 0 },
        { "divide", TXTFIELD_DWORD, 0, 132, 0 },
        { "multiply", TXTFIELD_DWORD, 0, 136, 0 },
        { "add", TXTFIELD_DWORD, 0, 140, 0 },
        { "rare", TXTFIELD_BYTE, 0, 100, 0 },
        { "maxlevel", TXTFIELD_DWORD, 0, 96, 0 },
        { "levelreq", TXTFIELD_BYTE, 0, 101, 0 },
        { "classspecific", TXTFIELD_CODETOBYTE, 0, 102, &sgtDataTables.pPlayerClassLinker },
        { "class", TXTFIELD_CODETOBYTE, 0, 103, &sgtDataTables.pPlayerClassLinker },
        { "classlevelreq", TXTFIELD_BYTE, 0, 104, 0 },
        { "itype1", TXTFIELD_CODETOWORD, 0, 106, &sgtDataTables.pItemTypesLinker },
        { "itype2", TXTFIELD_CODETOWORD, 0, 108, &sgtDataTables.pItemTypesLinker },
        { "itype3", TXTFIELD_CODETOWORD, 0, 110, &sgtDataTables.pItemTypesLinker },
        { "itype4", TXTFIELD_CODETOWORD, 0, 112, &sgtDataTables.pItemTypesLinker },
        { "itype5", TXTFIELD_CODETOWORD, 0, 114, &sgtDataTables.pItemTypesLinker },
        { "itype6", TXTFIELD_CODETOWORD, 0, 116, &sgtDataTables.pItemTypesLinker },
        { "itype7", TXTFIELD_CODETOWORD, 0, 118, &sgtDataTables.pItemTypesLinker },
        { "etype1", TXTFIELD_CODETOWORD, 0, 120, &sgtDataTables.pItemTypesLinker },
        { "etype2", TXTFIELD_CODETOWORD, 0, 122, &sgtDataTables.pItemTypesLinker },
        { "etype3", TXTFIELD_CODETOWORD, 0, 124, &sgtDataTables.pItemTypesLinker },
        { "etype4", TXTFIELD_CODETOWORD, 0, 126, &sgtDataTables.pItemTypesLinker },
        { "etype5", TXTFIELD_CODETOWORD, 0, 128, &sgtDataTables.pItemTypesLinker },
        { "transformcolor", TXTFIELD_CODETOBYTE, 0, 86, &sgtDataTables.pColorsLinker },
        { "frequency", TXTFIELD_BYTE, 0, 130, 0 },
        { "mod1code", TXTFIELD_NAMETODWORD, 0, 36, &sgtDataTables.pPropertiesLinker },
        { "mod1param", TXTFIELD_CALCTODWORD, 0, 40, (void*)DATATBLS_ItemParamLinker },
        { "mod1min", TXTFIELD_DWORD, 0, 44, 0 },
        { "mod1max", TXTFIELD_DWORD, 0, 48, 0 },
        { "mod2code", TXTFIELD_NAMETODWORD, 0, 52, &sgtDataTables.pPropertiesLinker },
        { "mod2param", TXTFIELD_CALCTODWORD, 0, 56, (void*)DATATBLS_ItemParamLinker },
        { "mod2min", TXTFIELD_DWORD, 0, 60, 0 },
        { "mod2max", TXTFIELD_DWORD, 0, 64, 0 },
        { "mod3code", TXTFIELD_NAMETODWORD, 0, 68, &sgtDataTables.pPropertiesLinker },
        { "mod3param", TXTFIELD_CALCTODWORD, 0, 72, (void*)DATATBLS_ItemParamLinker },
        { "mod3min", TXTFIELD_DWORD, 0, 76, 0 },
        { "mod3max", TXTFIELD_DWORD, 0, 80, 0 },
        { gszTxtField_end, TXTFIELD_NONE, 0, 0, 0 },
    };

    pMagicSuffix = (D2MagicAffixTxt*)DATATBLS_CompileTxt(hArchive, "magicsuffix", pTbl, &nSuffixRecords, sizeof(D2MagicAffixTxt));
    pMagicPrefix = (D2MagicAffixTxt*)DATATBLS_CompileTxt(hArchive, "magicprefix", pTbl, &nPrefixRecords, sizeof(D2MagicAffixTxt));
    pAutoMagic = (D2MagicAffixTxt*)DATATBLS_CompileTxt(hArchive, "automagic", pTbl, &nAutoMagicRecords, sizeof(D2MagicAffixTxt));

    sgtDataTables.pMagicAffixDataTables.nMagicAffixTxtRecordCount = nSuffixRecords + nPrefixRecords + nAutoMagicRecords;
    sgtDataTables.pMagicAffixDataTables.pMagicAffixTxt = (D2MagicAffixTxt*)FOG_AllocPool(0, sizeof(D2MagicAffixTxt) * sgtDataTables.pMagicAffixDataTables.nMagicAffixTxtRecordCount, ".\\DATATBLS\\ItemTbls.cpp", 663, 0);

    sgtDataTables.pMagicAffixDataTables.pMagicSuffix = sgtDataTables.pMagicAffixDataTables.pMagicAffixTxt;
    memcpy(sgtDataTables.pMagicAffixDataTables.pMagicAffixTxt, pMagicSuffix, sizeof(D2MagicAffixTxt) * nSuffixRecords);
    memcpy(sgtDataTables.pMagicAffixDataTables.pMagicPrefix = &sgtDataTables.pMagicAffixDataTables.pMagicSuffix[nSuffixRecords], pMagicPrefix, sizeof(D2MagicAffixTxt) * nPrefixRecords);
    memcpy(sgtDataTables.pMagicAffixDataTables.pAutoMagic = &sgtDataTables.pMagicAffixDataTables.pMagicPrefix[nPrefixRecords], pAutoMagic, sizeof(D2MagicAffixTxt) * nAutoMagicRecords);

    DATATBLS_UnloadBin(pMagicSuffix);
    DATATBLS_UnloadBin(pMagicPrefix);
    DATATBLS_UnloadBin(pAutoMagic);

    const wchar_t* pUnicode = 0;
    for (int i = 0; i < sgtDataTables.pMagicAffixDataTables.nMagicAffixTxtRecordCount; ++i)
    {
        sgtDataTables.pMagicAffixDataTables.pMagicAffixTxt[i].wTblIndex = STRTABLE_FindString(sgtDataTables.pMagicAffixDataTables.pMagicAffixTxt[i].szName, &pUnicode);
    }
}
