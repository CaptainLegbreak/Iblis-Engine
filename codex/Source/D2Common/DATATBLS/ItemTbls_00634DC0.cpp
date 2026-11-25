struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

struct D2PropertyStrc
{
    int nProperty;
    int nLayer;
    int nMin;
    int nMax;
};

struct D2SetItemsTxt;

struct D2SetsTxt
{
    unsigned short wSetId;
    unsigned short wStringId;
    unsigned short wVersion;
    unsigned short unk0x06;
    int unk0x08;
    int nSetItems;
    char unk0x10[0x110 - 0x10];
    D2SetItemsTxt* pSetItem[6];
};

struct D2SetItemsTxt
{
    unsigned short wSetItemId;
    char szName[32];
    unsigned short wVersion;
    unsigned short wStringId;
    unsigned short pad0x26;
    unsigned int dwItemCode;
    short nSetId;
    short nSetItems;
    unsigned short wLvl;
    unsigned short wLvlReq;
    unsigned int dwRarity;
    unsigned int dwCostMult;
    unsigned int dwCostAdd;
    unsigned char nChrTransform;
    unsigned char nInvTransform;
    char szFlippyFile[32];
    char szInvFile[32];
    unsigned short wDropSound;
    unsigned short wUseSound;
    unsigned char nDropSfxFrame;
    unsigned char nAddFunc;
    D2PropertyStrc pProperties[9];
    D2PropertyStrc pBoniPartial[10];
};

extern "C" const char gszTxtField_name[];                                                           // 0x006E7C68
extern "C" const char gszTxtField_index[];                                                          // 0x006E9CCC
extern "C" const char gszTxtField_end[];                                                            // 0x006D9060
extern "C" const char gszTxtField_item[];                                                           // 0x006E9E2C
extern "C" const char gszTxtField_set[];                                                            // 0x006D5BCC
extern "C" const char gszTxtField_lvl[];                                                            // 0x006E9CB8
extern "C" const char gszTxtField_lvl_req[];                                                        // 0x006E9CB0
extern "C" const char gszTxtField_rarity[];                                                         // 0x006E9908
extern "C" const char gszTxtField_cost_mult[];                                                      // 0x006E6860
extern "C" const char gszTxtField_cost_add[];                                                       // 0x006E6854
extern "C" const char gszTxtField_chrtransform[];                                                   // 0x006E9C90
extern "C" const char gszTxtField_invtransform[];                                                   // 0x006E9C80
extern "C" const char gszTxtField_flippyfile[];                                                     // 0x006E9830
extern "C" const char gszTxtField_invfile[];                                                        // 0x006E9828
extern "C" const char gszTxtField_dropsound[];                                                      // 0x006E9770
extern "C" const char gszTxtField_dropsfxframe[];                                                   // 0x006E9760
extern "C" const char gszTxtField_usesound[];                                                       // 0x006E9754
extern "C" const char gszTxtField_add_func[];                                                       // 0x006E9E20
extern "C" const char gszTxtField_prop1[];                                                          // 0x006E9C78
extern "C" const char gszTxtField_par1[];                                                           // 0x006E9C70
extern "C" const char gszTxtField_min1[];                                                           // 0x006E9C68
extern "C" const char gszTxtField_max1[];                                                           // 0x006E9C60
extern "C" const char gszTxtField_prop2[];                                                          // 0x006E9C58
extern "C" const char gszTxtField_par2[];                                                           // 0x006E9C50
extern "C" const char gszTxtField_min2[];                                                           // 0x006E9C48
extern "C" const char gszTxtField_max2[];                                                           // 0x006E9C40
extern "C" const char gszTxtField_prop3[];                                                          // 0x006E9C38
extern "C" const char gszTxtField_par3[];                                                           // 0x006E9C30
extern "C" const char gszTxtField_min3[];                                                           // 0x006E9C28
extern "C" const char gszTxtField_max3[];                                                           // 0x006E9C20
extern "C" const char gszTxtField_prop4[];                                                          // 0x006E9C18
extern "C" const char gszTxtField_par4[];                                                           // 0x006E9C10
extern "C" const char gszTxtField_min4[];                                                           // 0x006E9C08
extern "C" const char gszTxtField_max4[];                                                           // 0x006E9C00
extern "C" const char gszTxtField_prop5[];                                                          // 0x006E9BF8
extern "C" const char gszTxtField_par5[];                                                           // 0x006E9BF0
extern "C" const char gszTxtField_min5[];                                                           // 0x006E9BE8
extern "C" const char gszTxtField_max5[];                                                           // 0x006E9BE0
extern "C" const char gszTxtField_prop6[];                                                          // 0x006E9BD8
extern "C" const char gszTxtField_par6[];                                                           // 0x006E9BD0
extern "C" const char gszTxtField_min6[];                                                           // 0x006E9BC8
extern "C" const char gszTxtField_max6[];                                                           // 0x006E9BC0
extern "C" const char gszTxtField_prop7[];                                                          // 0x006E9BB8
extern "C" const char gszTxtField_par7[];                                                           // 0x006E9BB0
extern "C" const char gszTxtField_min7[];                                                           // 0x006E9BA8
extern "C" const char gszTxtField_max7[];                                                           // 0x006E9BA0
extern "C" const char gszTxtField_prop8[];                                                          // 0x006E9B98
extern "C" const char gszTxtField_par8[];                                                           // 0x006E9B90
extern "C" const char gszTxtField_min8[];                                                           // 0x006E9B88
extern "C" const char gszTxtField_max8[];                                                           // 0x006E9B80
extern "C" const char gszTxtField_prop9[];                                                          // 0x006E9B78
extern "C" const char gszTxtField_par9[];                                                           // 0x006E9B70
extern "C" const char gszTxtField_min9[];                                                           // 0x006E9B68
extern "C" const char gszTxtField_max9[];                                                           // 0x006E9B60
extern "C" const char gszTxtField_aprop1a[];                                                        // 0x006E9E18
extern "C" const char gszTxtField_apar1a[];                                                         // 0x006E9E10
extern "C" const char gszTxtField_amin1a[];                                                         // 0x006E9E08
extern "C" const char gszTxtField_amax1a[];                                                         // 0x006E9E00
extern "C" const char gszTxtField_aprop1b[];                                                        // 0x006E9DF8
extern "C" const char gszTxtField_apar1b[];                                                         // 0x006E9DF0
extern "C" const char gszTxtField_amin1b[];                                                         // 0x006E9DE8
extern "C" const char gszTxtField_amax1b[];                                                         // 0x006E9DE0
extern "C" const char gszTxtField_aprop2a[];                                                        // 0x006E9DD8
extern "C" const char gszTxtField_apar2a[];                                                         // 0x006E9DD0
extern "C" const char gszTxtField_amin2a[];                                                         // 0x006E9DC8
extern "C" const char gszTxtField_amax2a[];                                                         // 0x006E9DC0
extern "C" const char gszTxtField_aprop2b[];                                                        // 0x006E9DB8
extern "C" const char gszTxtField_apar2b[];                                                         // 0x006E9DB0
extern "C" const char gszTxtField_amin2b[];                                                         // 0x006E9DA8
extern "C" const char gszTxtField_amax2b[];                                                         // 0x006E9DA0
extern "C" const char gszTxtField_aprop3a[];                                                        // 0x006E9D98
extern "C" const char gszTxtField_apar3a[];                                                         // 0x006E9D90
extern "C" const char gszTxtField_amin3a[];                                                         // 0x006E9D88
extern "C" const char gszTxtField_amax3a[];                                                         // 0x006E9D80
extern "C" const char gszTxtField_aprop3b[];                                                        // 0x006E9D78
extern "C" const char gszTxtField_apar3b[];                                                         // 0x006E9D70
extern "C" const char gszTxtField_amin3b[];                                                         // 0x006E9D68
extern "C" const char gszTxtField_amax3b[];                                                         // 0x006E9D60
extern "C" const char gszTxtField_aprop4a[];                                                        // 0x006E9D58
extern "C" const char gszTxtField_apar4a[];                                                         // 0x006E9D50
extern "C" const char gszTxtField_amin4a[];                                                         // 0x006E9D48
extern "C" const char gszTxtField_amax4a[];                                                         // 0x006E9D40
extern "C" const char gszTxtField_aprop4b[];                                                        // 0x006E9D38
extern "C" const char gszTxtField_apar4b[];                                                         // 0x006E9D30
extern "C" const char gszTxtField_amin4b[];                                                         // 0x006E9D28
extern "C" const char gszTxtField_amax4b[];                                                         // 0x006E9D20
extern "C" const char gszTxtField_aprop5a[];                                                        // 0x006E9D18
extern "C" const char gszTxtField_apar5a[];                                                         // 0x006E9D10
extern "C" const char gszTxtField_amin5a[];                                                         // 0x006E9D08
extern "C" const char gszTxtField_amax5a[];                                                         // 0x006E9D00
extern "C" const char gszTxtField_aprop5b[];                                                        // 0x006E9CF8
extern "C" const char gszTxtField_apar5b[];                                                         // 0x006E9CF0
extern "C" const char gszTxtField_amin5b[];                                                         // 0x006E9CE8
extern "C" const char gszTxtField_amax5b[];                                                         // 0x006E9CE0
extern "C" const char gszTxtName_setitems[];                                                        // 0x006E9CD4
extern "C" const char gszItemTblsSourceFile[];                                                      // 0x006E90E4
extern "C" const char gszEmptyAssertText;                                                           // 0x006CC837

struct D2DataTablesStrc
{
    char unk0x000[0xA8];
    D2TxtLinkStrc* pPropertiesLinker;
    char unk0x0AC[0x198 - 0xAC];
    D2TxtLinkStrc* pSoundsLinker;
    char unk0x19C[0x9B4 - 0x19C];
    D2TxtLinkStrc* pColorsLinker;
    char unk0x9B8[0xC08 - 0x9B8];
    D2TxtLinkStrc* pSetsLinker;
    D2SetsTxt* pSetsTxt;
    int nSetsTxtRecordCount;
    D2TxtLinkStrc* pSetItemsLinker;
    D2SetItemsTxt* pSetItemsTxt;
    int nSetItemsTxtRecordCount;
};

extern D2DataTablesStrc sgtDataTables;                                                              // 0x0096BC30

unsigned short __fastcall DATATBLS_GetStringIdFromReferenceString(char* szReference);               // 0x006117B0
void __fastcall DATATBLS_ItemParamLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn);// 0x006336A0
D2TxtLinkStrc* __stdcall FOG_AllocLinker(const char* szFile, int nLine);                    // 0x006BD040
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
void __stdcall FOG_10216_AddRecordToLinkingTable(D2TxtLinkStrc* pLinker, const char* szName);       // 0x006BD500
unsigned short __stdcall STRTABLE_FindString(const char* szKey, void** ppText);                 // 0x00524D30
extern "C" const char* __cdecl sub_00408090();                                              // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);           // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                       // 0x00681E09

#define ITEM_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00634DC0
void __fastcall DATATBLS_LoadSets_SetItemsTxt(void* hArchive)
{
    D2BinFieldStrc pSetsTbl[] =
    {
        { "index", 17, 0, 0, &sgtDataTables.pSetsLinker },
        { gszTxtField_name, 22, 0, 2, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "version", 3, 0, 4, 0 },
        { "pcode2a", 19, 0, 16, &sgtDataTables.pPropertiesLinker },
        { "pparam2a", 25, 0, 20, (void*)DATATBLS_ItemParamLinker },
        { "pmin2a", 2, 0, 24, 0 },
        { "pmax2a", 2, 0, 28, 0 },
        { "pcode2b", 19, 0, 32, &sgtDataTables.pPropertiesLinker },
        { "pparam2b", 25, 0, 36, (void*)DATATBLS_ItemParamLinker },
        { "pmin2b", 2, 0, 40, 0 },
        { "pmax2b", 2, 0, 44, 0 },
        { "pcode3a", 19, 0, 48, &sgtDataTables.pPropertiesLinker },
        { "pparam3a", 25, 0, 52, (void*)DATATBLS_ItemParamLinker },
        { "pmin3a", 2, 0, 56, 0 },
        { "pmax3a", 2, 0, 60, 0 },
        { "pcode3b", 19, 0, 64, &sgtDataTables.pPropertiesLinker },
        { "pparam3b", 25, 0, 68, (void*)DATATBLS_ItemParamLinker },
        { "pmin3b", 2, 0, 72, 0 },
        { "pmax3b", 2, 0, 76, 0 },
        { "pcode4a", 19, 0, 80, &sgtDataTables.pPropertiesLinker },
        { "pparam4a", 25, 0, 84, (void*)DATATBLS_ItemParamLinker },
        { "pmin4a", 2, 0, 88, 0 },
        { "pmax4a", 2, 0, 92, 0 },
        { "pcode4b", 19, 0, 96, &sgtDataTables.pPropertiesLinker },
        { "pparam4b", 25, 0, 100, (void*)DATATBLS_ItemParamLinker },
        { "pmin4b", 2, 0, 104, 0 },
        { "pmax4b", 2, 0, 108, 0 },
        { "pcode5a", 19, 0, 112, &sgtDataTables.pPropertiesLinker },
        { "pparam5a", 25, 0, 116, (void*)DATATBLS_ItemParamLinker },
        { "pmin5a", 2, 0, 120, 0 },
        { "pmax5a", 2, 0, 124, 0 },
        { "pcode5b", 19, 0, 128, &sgtDataTables.pPropertiesLinker },
        { "pparam5b", 25, 0, 132, (void*)DATATBLS_ItemParamLinker },
        { "pmin5b", 2, 0, 136, 0 },
        { "pmax5b", 2, 0, 140, 0 },
        { "fcode1", 19, 0, 144, &sgtDataTables.pPropertiesLinker },
        { "fparam1", 25, 0, 148, (void*)DATATBLS_ItemParamLinker },
        { "fmin1", 2, 0, 152, 0 },
        { "fmax1", 2, 0, 156, 0 },
        { "fcode2", 19, 0, 160, &sgtDataTables.pPropertiesLinker },
        { "fparam2", 25, 0, 164, (void*)DATATBLS_ItemParamLinker },
        { "fmin2", 2, 0, 168, 0 },
        { "fmax2", 2, 0, 172, 0 },
        { "fcode3", 19, 0, 176, &sgtDataTables.pPropertiesLinker },
        { "fparam3", 25, 0, 180, (void*)DATATBLS_ItemParamLinker },
        { "fmin3", 2, 0, 184, 0 },
        { "fmax3", 2, 0, 188, 0 },
        { "fcode4", 19, 0, 192, &sgtDataTables.pPropertiesLinker },
        { "fparam4", 25, 0, 196, (void*)DATATBLS_ItemParamLinker },
        { "fmin4", 2, 0, 200, 0 },
        { "fmax4", 2, 0, 204, 0 },
        { "fcode5", 19, 0, 208, &sgtDataTables.pPropertiesLinker },
        { "fparam5", 25, 0, 212, (void*)DATATBLS_ItemParamLinker },
        { "fmin5", 2, 0, 216, 0 },
        { "fmax5", 2, 0, 220, 0 },
        { "fcode6", 19, 0, 224, &sgtDataTables.pPropertiesLinker },
        { "fparam6", 25, 0, 228, (void*)DATATBLS_ItemParamLinker },
        { "fmin6", 2, 0, 232, 0 },
        { "fmax6", 2, 0, 236, 0 },
        { "fcode7", 19, 0, 240, &sgtDataTables.pPropertiesLinker },
        { "fparam7", 25, 0, 244, (void*)DATATBLS_ItemParamLinker },
        { "fmin7", 2, 0, 248, 0 },
        { "fmax7", 2, 0, 252, 0 },
        { "fcode8", 19, 0, 256, &sgtDataTables.pPropertiesLinker },
        { "fparam8", 25, 0, 260, (void*)DATATBLS_ItemParamLinker },
        { "fmin8", 2, 0, 264, 0 },
        { "fmax8", 2, 0, 268, 0 },
        { "end", 0, 0, 0, 0 },
    };

    sgtDataTables.pSetsLinker = FOG_AllocLinker(gszItemTblsSourceFile, 1010);
    sgtDataTables.pSetsTxt = (D2SetsTxt*)DATATBLS_CompileTxt(hArchive, "sets", pSetsTbl, &sgtDataTables.nSetsTxtRecordCount, sizeof(D2SetsTxt));
    ITEM_ASSERT(sgtDataTables.nSetsTxtRecordCount < 32767, 1012);

    D2BinFieldStrc pSetItemsTbl[] =
    {
        { "index", 1, 31, 2, 0 },
        { gszTxtField_item, 9, 0, 40, 0 },
        { gszTxtField_set, 20, 0, 44, &sgtDataTables.pSetsLinker },
        { gszTxtField_lvl, 3, 0, 48, 0 },
        { gszTxtField_lvl_req, 3, 0, 50, 0 },
        { gszTxtField_rarity, 2, 0, 52, 0 },
        { gszTxtField_cost_mult, 2, 0, 56, 0 },
        { gszTxtField_cost_add, 2, 0, 60, 0 },
        { gszTxtField_chrtransform, 13, 0, 64, &sgtDataTables.pColorsLinker },
        { gszTxtField_invtransform, 13, 0, 65, &sgtDataTables.pColorsLinker },
        { gszTxtField_flippyfile, 1, 31, 66, 0 },
        { gszTxtField_invfile, 1, 31, 98, 0 },
        { gszTxtField_dropsound, 20, 0, 130, &sgtDataTables.pSoundsLinker },
        { gszTxtField_dropsfxframe, 4, 0, 134, 0 },
        { gszTxtField_usesound, 20, 0, 132, &sgtDataTables.pSoundsLinker },
        { gszTxtField_add_func, 4, 0, 135, 0 },
        { gszTxtField_prop1, 19, 0, 136, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_par1, 25, 0, 140, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_min1, 2, 0, 144, 0 },
        { gszTxtField_max1, 2, 0, 148, 0 },
        { gszTxtField_prop2, 19, 0, 152, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_par2, 25, 0, 156, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_min2, 2, 0, 160, 0 },
        { gszTxtField_max2, 2, 0, 164, 0 },
        { gszTxtField_prop3, 19, 0, 168, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_par3, 25, 0, 172, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_min3, 2, 0, 176, 0 },
        { gszTxtField_max3, 2, 0, 180, 0 },
        { gszTxtField_prop4, 19, 0, 184, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_par4, 25, 0, 188, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_min4, 2, 0, 192, 0 },
        { gszTxtField_max4, 2, 0, 196, 0 },
        { gszTxtField_prop5, 19, 0, 200, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_par5, 25, 0, 204, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_min5, 2, 0, 208, 0 },
        { gszTxtField_max5, 2, 0, 212, 0 },
        { gszTxtField_prop6, 19, 0, 216, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_par6, 25, 0, 220, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_min6, 2, 0, 224, 0 },
        { gszTxtField_max6, 2, 0, 228, 0 },
        { gszTxtField_prop7, 19, 0, 232, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_par7, 25, 0, 236, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_min7, 2, 0, 240, 0 },
        { gszTxtField_max7, 2, 0, 244, 0 },
        { gszTxtField_prop8, 19, 0, 248, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_par8, 25, 0, 252, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_min8, 2, 0, 256, 0 },
        { gszTxtField_max8, 2, 0, 260, 0 },
        { gszTxtField_prop9, 19, 0, 264, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_par9, 25, 0, 268, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_min9, 2, 0, 272, 0 },
        { gszTxtField_max9, 2, 0, 276, 0 },
        { gszTxtField_aprop1a, 19, 0, 280, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_apar1a, 25, 0, 284, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_amin1a, 2, 0, 288, 0 },
        { gszTxtField_amax1a, 2, 0, 292, 0 },
        { gszTxtField_aprop1b, 19, 0, 296, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_apar1b, 25, 0, 300, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_amin1b, 2, 0, 304, 0 },
        { gszTxtField_amax1b, 2, 0, 308, 0 },
        { gszTxtField_aprop2a, 19, 0, 312, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_apar2a, 25, 0, 316, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_amin2a, 2, 0, 320, 0 },
        { gszTxtField_amax2a, 2, 0, 324, 0 },
        { gszTxtField_aprop2b, 19, 0, 328, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_apar2b, 25, 0, 332, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_amin2b, 2, 0, 336, 0 },
        { gszTxtField_amax2b, 2, 0, 340, 0 },
        { gszTxtField_aprop3a, 19, 0, 344, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_apar3a, 25, 0, 348, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_amin3a, 2, 0, 352, 0 },
        { gszTxtField_amax3a, 2, 0, 356, 0 },
        { gszTxtField_aprop3b, 19, 0, 360, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_apar3b, 25, 0, 364, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_amin3b, 2, 0, 368, 0 },
        { gszTxtField_amax3b, 2, 0, 372, 0 },
        { gszTxtField_aprop4a, 19, 0, 376, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_apar4a, 25, 0, 380, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_amin4a, 2, 0, 384, 0 },
        { gszTxtField_amax4a, 2, 0, 388, 0 },
        { gszTxtField_aprop4b, 19, 0, 392, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_apar4b, 25, 0, 396, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_amin4b, 2, 0, 400, 0 },
        { gszTxtField_amax4b, 2, 0, 404, 0 },
        { gszTxtField_aprop5a, 19, 0, 408, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_apar5a, 25, 0, 412, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_amin5a, 2, 0, 416, 0 },
        { gszTxtField_amax5a, 2, 0, 420, 0 },
        { gszTxtField_aprop5b, 19, 0, 424, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_apar5b, 25, 0, 428, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_amin5b, 2, 0, 432, 0 },
        { gszTxtField_amax5b, 2, 0, 436, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    sgtDataTables.pSetItemsLinker = FOG_AllocLinker(gszItemTblsSourceFile, 1117);
    sgtDataTables.pSetItemsTxt = (D2SetItemsTxt*)DATATBLS_CompileTxt(hArchive, gszTxtName_setitems, pSetItemsTbl, &sgtDataTables.nSetItemsTxtRecordCount, sizeof(D2SetItemsTxt));
    ITEM_ASSERT(sgtDataTables.nSetItemsTxtRecordCount < 32767, 1119);

    for (int i = 0; i < sgtDataTables.nSetItemsTxtRecordCount; ++i)
    {
        D2SetItemsTxt* pSetItemsTxtRecord = &sgtDataTables.pSetItemsTxt[i];
        pSetItemsTxtRecord->wSetItemId = i;
        FOG_10216_AddRecordToLinkingTable(sgtDataTables.pSetItemsLinker, pSetItemsTxtRecord->szName);
        void* pUnicode = 0;
        pSetItemsTxtRecord->wStringId = STRTABLE_FindString(pSetItemsTxtRecord->szName, &pUnicode);
        if (!pSetItemsTxtRecord->wStringId)
        {
            pSetItemsTxtRecord->wStringId = 5383;
        }

        if (pSetItemsTxtRecord->nSetId >= 0 && pSetItemsTxtRecord->nSetId < sgtDataTables.nSetsTxtRecordCount)
        {
            D2SetsTxt* pSetsTxtRecord = &sgtDataTables.pSetsTxt[pSetItemsTxtRecord->nSetId];
            if (pSetsTxtRecord->nSetItems < 6)
            {
                pSetItemsTxtRecord->wVersion = pSetsTxtRecord->wVersion;
                pSetItemsTxtRecord->nSetItems = pSetsTxtRecord->nSetItems;
                pSetsTxtRecord->pSetItem[pSetItemsTxtRecord->nSetItems] = pSetItemsTxtRecord;
                ++pSetsTxtRecord->nSetItems;
            }
        }
    }
}

#include "gen/data/Source/D2Common/DATATBLS/ItemTbls_00634DC0.inc"
