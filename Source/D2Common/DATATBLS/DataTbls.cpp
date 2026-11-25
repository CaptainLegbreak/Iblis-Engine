#include "D2Common.h"

#include "D2Structs.h"

#include "D2Path.h"

#include "D2Txt.h"

#include "D2Records.h"

#include "D2TxtItems.h"

#include "D2Skills.h"

#include "D2TxtTables.h"

#include "D2Unicode.h"
#include "D2DataTbls.h"
#include "D2ExperienceTxt.h"

struct D2SkillListStrc;

struct D2InventoryStrc;

struct D2PropertyStrc;

struct D2BinFieldStrc;

struct D2BinFileStrc;

struct D2StatesTxt;

struct D2ExperienceTxt;

struct D2ExperienceDataTbl;

struct D2StaticPathStrc;

struct D2SkillsTxt;

struct D2DifficultyLevelsTxt;

struct D2ObjectsTxt;

struct D2RunesTxt;

struct D2RuneDataTbl;

struct PlayerRecord;

struct MonsterRecord;

struct ItemRecord;

struct ObjectRecord;

struct DataTables;

struct UnitHeader;

struct D2StatesTxt
{
    unsigned short wState;
    char unk0x02[0xE];
    unsigned char nStateFlags[8];
    char unk0x18[0x24];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode); // 0x0068239A

extern "C" int __cdecl fclose(_iobuf* pFile); // 0x00681FDC

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

unsigned short __stdcall STRTABLE_FindString(const char* szKey, const wchar_t** ppText); // 0x00524D30

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0

extern "C" const char gszFileModeWb_006D69E0[]; // 0x006D69E0

extern unsigned int gdwBitMasks[]; // 0x006CE268

D2StatesTxt* gpStatesTxt; // 0x0096BCEC



extern D2ExperienceDataTbl* gpExperienceTxt; // 0x0096C8A8
struct D2CompCodeTxt
{
    unsigned int dwCode;
};
extern D2CompCodeTxt* gpCompCodeTxt; // 0x0096BCAC
extern int gnCompCodeTxtRecordCount; // 0x0096BCB4

char* gpSkillsCode_0096BC70; // 0x0096BC70

int gnSkillsCodeSize_0096BC74; // 0x0096BC74

int gnSkillsCodeSizeEx_0096BC78; // 0x0096BC78

char* gpSkillDescCode_0096BC7C; // 0x0096BC7C

int gnSkillDescCodeSize_0096BC80; // 0x0096BC80

int gnSkillDescCodeSizeEx_0096BC84; // 0x0096BC84

int __fastcall DATATBLS_AppendMemoryBuffer(char** ppCodes, int* pSize, int* pSizeEx, void* pBuffer, int nBufferSize); // 0x006118B0

int __fastcall DATATBLS_MapSkillsTxtKeywordToNumber(char* szKey); // 0x00611930

int __fastcall DATATBLS_GetSkillsCalcParamCount(int nValue); // 0x006119E0

int __fastcall DATATBLS_SkillsCalcParamCallback(char* szText, int* pResult, int nType, int nKeywordNumber); // 0x006119F0

int __stdcall DATATBLS_CompileExpression(const char* szFormulaString, char* pOutBuffer, int nOutBufferSize, int (__fastcall* pfnKeywordToNumber)(char*), int (__fastcall* pfnGetParameterCount)(int), int (__fastcall* pfnLinkParse)(char*, int*, int, int)); // 0x006C1AE0

D2TxtLinkStrc* gpSkillsLinker_0096C7CC; // 0x0096C7CC

D2TxtLinkStrc* gpMissilesLinker_0096C798; // 0x0096C798

extern D2TxtLinkStrc* gpMissileCalcLinker_0096BC8C; // 0x0096BC8C

int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, unsigned int dwCode, int bLogError); // 0x006BD130

struct D2DifficultyLevelsTxt
{
    char unk0x00[0x58];
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int gnDifficultylevelsTxtRecordCount; // 0x0096C8B0

extern D2ObjectsTxt* gpObjectsTxt; // 0x0096D470

int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190

int __stdcall STATLIST_GetBaseStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625350

int __stdcall STATLIST_GetTotalStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625420

int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930

int __stdcall ITEMS_IsEthereal(D2UnitStrc* pItem); // 0x0062A8D0

D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList); // 0x00643910

void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270

D2ActiveRoomStrc* __stdcall PATH_GetRoom(D2DynamicPathStrc* pDynamicPath); // 0x00648A80

void __stdcall D2Common_10884_COMPOSIT_unk(D2UnitStrc* pUnit, int nClassId, int nMode, int nUnitType, D2InventoryStrc* pInventory, char* szPath, int* pWeaponClassCode, int a8, int a9); // 0x0064F5B0

void __stdcall ITEMMODS_ApplyEthereality(D2UnitStrc* pItem); // 0x0065E4D0

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480

void* __fastcall DATATBLS_ReadExcelFile(void* hArchive, const char* szName, const char* szExtension, int* pSize, const char* szFile, int nLine); // 0x00612280

extern "C" const char szBinExtension_006DCC68[]; // 0x006DCC68

int gbCompileTxt; // 0x0096C8B4

D2TxtLinkStrc* gpStatesLinker_0096BCF0; // 0x0096BCF0

int gnStatesTxtRecordCount; // 0x0096BCF4

void* gpSkillDescTxt_0096C7BC; // 0x0096C7BC

D2TxtLinkStrc* gpSkillDescLinker_0096C7C0; // 0x0096C7C0

int gnSkillDescTxtRecordCount_0096C7C4; // 0x0096C7C4

D2SkillsTxt* gpSkillsTxt_0096C7C8; // 0x0096C7C8

int gnSkillsTxtRecordCount_0096C7D0; // 0x0096C7D0

int* gpClassSkillCount_0096C7D4; // 0x0096C7D4

int gnHighestClassSkillCount_0096C7D8; // 0x0096C7D8

short* gpClassSkillList_0096C7DC; // 0x0096C7DC

int gnPassiveSkills_0096C7E0; // 0x0096C7E0

short* gpPassiveSkills_0096C7E4; // 0x0096C7E4

struct PlayerRecord
{
    char pad0[32];
    char name[164];
};

struct MonsterRecord
{
    char pad0[6];
    unsigned short nameIndex;
    char padTail[416];
};

struct ItemRecord
{
    char pad0[244];
    unsigned short nameIndex;
};

struct ObjectRecord
{
    char name[1];
};

struct DataTables
{
    char pad0[2680];
    MonsterRecord* monsters;
    char padMonsterCount[4];
    int monsterCount;
    char padPlayers[320];
    PlayerRecord* players;
    int playerCount;
};

struct UnitHeader
{
    unsigned int type;
    int classId;
};

extern DataTables* gVar_00744304; // 0x00744304

extern "C" char* __cdecl strncpy(char*, const char*, unsigned int); // 0x00687330

extern "C" int __cdecl _snprintf(char*, unsigned int, const char*, ...); // 0x006831DB

extern "C" char* __cdecl sub_006883F8_Copy(char*, const char*); // 0x006883F8

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70

ObjectRecord* __stdcall sub_00640E90_Object(int); // 0x00640E90

ItemRecord* __stdcall sub_006335F0_Item(int); // 0x006335F0

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

void __stdcall DATATBLS_WriteBinFile(char* szFileName, void* pWriteBuffer, unsigned int nBufferSize, int nRecordCount); // 0x006121F0

D2BinFileStrc* __stdcall FOG_CreateBinFile(void* pDataBuffer, int nBufferSize); // 0x006BD640

int __stdcall FOG_GetRecordCountFromBinFile(D2BinFileStrc* pBinFile); // 0x006BCDE0

void __stdcall FOG_10207(D2BinFileStrc* pBinFile, D2BinFieldStrc* pBinField, void* pTxt, int nRecordCount, int nRecordSize); // 0x006BD780

void __stdcall FOG_FreeBinFile(D2BinFileStrc* pBinFile); // 0x006BCDA0

extern "C" const char gszHitclassTxtName[]; // 0x006DCF50

extern D2DataTablesStrc gD2DataTables; // 0x0096BC30

void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0

void __fastcall DATATBLS_LoadItemTypesTxt(void* hArchive); // 0x00638D80

void __fastcall DATATBLS_LoadMonTypeTxt(void* hArchive); // 0x00658520

void __fastcall DATATBLS_LoadSoundsTxt(void* hArchive); // 0x00659BB0

void __fastcall DATATBLS_LoadPetTypeTxt(void* hArchive); // 0x00618D90

void __fastcall DATATBLS_LoadOverlayTxt(void* hArchive); // 0x00664150

void __fastcall DATATBLS_LoadItemStatCostTxt(void* hArchive); // 0x00637A00

void __fastcall DATATBLS_LoadPropertiesTxt(void* hArchive); // 0x00638630

void __fastcall DATATBLS_LoadMissilesTxt(void* hArchive); // 0x00661B20

void __fastcall DATATBLS_LoadStatesTxt(void* hArchive); // 0x00618100

void __stdcall DATATBLS_LoadSkills_SkillDescTxt(void* hArchive); // 0x00613F80

void __stdcall DATATBLS_LoadCharStatsTxt(void* hArchive); // 0x00613260

void __fastcall DATATBLS_LoadArenaTxt(void* hArchive); // 0x006649B0

void __fastcall DATATBLS_LoadCharTemplateTxt(void* hArchive); // 0x00664B80

void __fastcall DATATBLS_LoadItemsTxt(void* hArchive); // 0x006315D0

void __fastcall DATATBLS_LoadMagicSuffix_Prefix_AutomagicTxt(void* hArchive); // 0x00633730

void __fastcall DATATBLS_LoadRareSuffix_PrefixTxt(void* hArchive); // 0x00633F40

void __fastcall DATATBLS_LoadUniqueItemsTxt(void* hArchive); // 0x006342B0

void __fastcall DATATBLS_LoadSets_SetItemsTxt(void* hArchive); // 0x00634DC0

void __fastcall DATATBLS_LoadGemsTxt(void* hArchive); // 0x00636B70

void __fastcall DATATBLS_LoadBooksTxt(void* hArchive); // 0x00637320

void __fastcall DATATBLS_LoadQualityItemsTxt(void* hArchive); // 0x00636770

void __fastcall DATATBLS_LoadLowQualityItemsTxt(void* hArchive); // 0x00637500

void __fastcall DATATBLS_LoadRunesTxt(void* hArchive); // 0x006394A0

void __fastcall DATATBLS_LoadItemRatioTxt(void* hArchive); // 0x00637620

void __fastcall DATATBLS_LoadGambleTxt(void* hArchive); // 0x00638AE0

void __fastcall DATATBLS_LoadPlrType_ModeTxt(void* hArchive); // 0x0065ADC0

void __fastcall DATATBLS_LoadMonModeTxt(void* hArchive); // 0x0065AEF0

void __fastcall DATATBLS_LoadObjType_ModeTxt(void* hArchive); // 0x0065B1B0

void __fastcall DATATBLS_LoadCompositTxt(void* hArchive); // 0x0065B2E0

void __fastcall DATATBLS_LoadArmTypeTxt(void* hArchive); // 0x0065B350

void __stdcall DATATBLS_LoadExperienceTxt(void* hArchive); // 0x00613D30

void* __fastcall DATATBLS_LoadAnimDataD2(void* hArchive); // 0x0066A770

void __fastcall DATATBLS_LoadSomeMonsterTxts(void* hArchive); // 0x0065A400

void __fastcall DATATBLS_LoadLevelsTxt(void* hArchive); // 0x0061C540

void __fastcall DATATBLS_LoadLevelDefsBin(void* hArchive); // 0x0061DE00

void __fastcall DATATBLS_LoadLevelTypesTxt(void* hArchive); // 0x0061E520

void __fastcall DATATBLS_AllocGlobalTileLibraryHash(void* hArchive); // 0x0061FAE0

void __fastcall DATATBLS_LoadLvlWarpTxt(void* hArchive); // 0x0061F130

void __fastcall DATATBLS_LoadLvlMazeTxt(void* hArchive); // 0x0061F380

void __fastcall DATATBLS_LoadAutomapTxt(void* hArchive); // 0x0061FCF0

void __fastcall DATATBLS_LoadObjectsTxt(void* hArchive); // 0x0063F690

void __fastcall DATATBLS_LoadObjGroupTxt(void* hArchive); // 0x00640F20

void __fastcall DATATBLS_LoadShrinesTxt(void* hArchive); // 0x00641320

void __fastcall DATATBLS_LoadInventoryTxt(void* hArchive); // 0x0065B660

int __fastcall DATATBLS_LoadExpFieldD2(void* hArchive); // 0x0066A700

void __fastcall DATATBLS_LoadBeltsTxt(void* hArchive); // 0x00660290

void __fastcall DATATBLS_LoadMonItemPercentTxt(void* hArchive); // 0x00654F20

void __fastcall sub_0066A270(void* hArchive); // 0x0066A270

void __fastcall DATATBLS_LoadCubeMainTxt(void* hArchive); // 0x00669130

void __stdcall DATATBLS_LoadDifficultyLevelsTxt(void* hArchive); // 0x00617D90

void __fastcall DATATBLS_LoadLvlPrestTxt(void* hArchive, int bLoadFiles); // 0x0061EBB0

void __fastcall DATATBLS_LoadLvlSubTxt(void* hArchive, int a2, int a3); // 0x0061F500

void __fastcall DATATBLS_UnloadSoundsTxt(); // 0x00659C30

extern D2TxtLinkStrc* gpCompCodeLinker_0096BCB0; // 0x0096BCB0

D2TxtLinkStrc* gpPlayerClassLinker_0096BC34; // 0x0096BC34

D2TxtLinkStrc* gpElemTypesLinker_0096BC4C; // 0x0096BC4C

extern D2TxtLinkStrc* gpHitClassLinker_0096BC54; // 0x0096BC54

extern D2TxtLinkStrc* gpHireDescLinker_0096BCE8; // 0x0096BCE8

D2TxtLinkStrc* gpPlrModeLinker_0096BC64; // 0x0096BC64

D2TxtLinkStrc* gpSkillCalcLinker_0096BC6C; // 0x0096BC6C

D2TxtLinkStrc* gpEventsLinker_0096BCA8; // 0x0096BCA8

extern "C" const char gszTxtField_int[]; // 0x006E67EC

unsigned short __fastcall DATATBLS_GetStringIdFromReferenceString(char* szReference); // 0x006117B0

D2TxtLinkStrc* gpBodyLocsLinker_0096BC3C; // 0x0096BC3C

void __fastcall DATATBLS_InitUnicodeClassNamesInCharStatsTxt(void* pTable, int nRecordCount, int nRecordSize, int nNameOffset, int a5, int nNameLength); // 0x00612600

enum
{
    TXTFIELD_NONE = 0,
    TXTFIELD_WORD = 3,
    TXTFIELD_BYTE = 4,
    TXTFIELD_CODETOBYTE = 13,
    TXTFIELD_CODETOWORD = 15,
    TXTFIELD_NAMETOINDEX = 17,
    TXTFIELD_NAMETOWORD = 20,
    TXTFIELD_BIT = 26,
};

extern "C" const char gszTxtField_exp[]; // 0x006E7B3C

void __fastcall DATATBLS_BuildStateMask(unsigned int* pMask, int nFlag); // 0x00611D60

void __fastcall DATATBLS_BuildStateListByFlag(short** ppList, short* pnCount, int nFlag); // 0x00611DC0

void __fastcall DATATBLS_BuildStateListByField(short** ppList, short* pnCount, int nFieldOffset); // 0x00611E60

struct D2AnimDataTableStrc;

struct Unicode;

struct D2PetTypeTxt;

void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079

extern "C" const char gszOpenBracket_006E6438[]; // 0x006E6438

extern "C" const char gszCloseBracket_006E6434[]; // 0x006E6434

const Unicode* __fastcall D2LANG_GetStringByReferenceString(const char* szKey); // 0x00524E20

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790

extern "C" const char gszTxtField_Amazon[]; // 0x006E070C

extern "C" const char gszTxtField_Sorceress[]; // 0x006E0700

extern "C" const char gszTxtField_Necromancer[]; // 0x006E06F4

extern "C" const char gszTxtField_Paladin[]; // 0x006E06EC

extern "C" const char gszTxtField_Barbarian[]; // 0x006E06E0

extern "C" const char gszTxtField_Druid[]; // 0x006E06D8

extern "C" const char gszTxtField_Assassin[]; // 0x006E06CC

typedef unsigned int size_t;

struct D2PetTypeTxt
{
    char unk0x00[0xBC];
    int nSkillCount;
    short wSkillIds[15];
    short unk0xDE;
};

extern D2TxtLinkStrc* gpPettypeLinker_0096C81C; // 0x0096C81C

void __fastcall DATATBLS_SkillCalcLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn); // 0x00611BD0

void __fastcall DATATBLS_SkillDescCalcLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn); // 0x00611C70

extern int gnPettypeTxtRecordCount_0096C820; // 0x0096C820

void __stdcall DATATBLS_UnloadBin(void* pBinFile); // 0x006125C0

void __fastcall DATATBLS_GetBinFileHandle(void* hArchive, const char* szFile, void** ppFileHandle, int* pSize, int* pSizeEx); // 0x00613E90

void __stdcall sub_006BD230_AddRecordToLinker(D2TxtLinkStrc* pLinker, int nCode); // 0x006BD230

void __stdcall DATATBLS_UnloadCompCodeAndCompileBins(); // 0x00612EA0

void __fastcall DATATBLS_UnloadMissilesTxt(); // 0x00663210

void __fastcall DATATBLS_UnloadOverlayTxt(); // 0x00664530

void __fastcall DATATBLS_UnloadSkills_SkillDescTxt(); // 0x00617C30

void __fastcall DATATBLS_UnloadItemStatCostTxt(); // 0x006385D0

void __fastcall DATATBLS_UnloadStatesTxt(); // 0x00618C90

void __fastcall DATATBLS_UnloadItemsTxt(); // 0x00633540

void __fastcall DATATBLS_UnloadPropertiesTxt(); // 0x00638AA0

void __fastcall DATATBLS_UnloadMagicSuffix_Prefix_AutomagicTxt(); // 0x00633EA0

void __fastcall DATATBLS_UnloadRareSuffix_PrefixTxt(); // 0x00634220

void __fastcall DATATBLS_UnloadUniqueItemsTxt(); // 0x00634D90

void __fastcall DATATBLS_UnloadSets_SetItemsTxt(); // 0x00636730

void __fastcall DATATBLS_UnloadQualityItemsTxt(); // 0x00636B00

void __fastcall DATATBLS_UnloadLowQualityItemsTxt(); // 0x006375A0

void __fastcall DATATBLS_UnloadGemsTxt(); // 0x006372A0

void __fastcall DATATBLS_UnloadBooksTxt(); // 0x00637490

void __fastcall DATATBLS_UnloadItemRatioTxt(); // 0x006378F0

void __fastcall DATATBLS_UnloadGambleTxt(); // 0x00638C80

void __fastcall DATATBLS_UnloadItemTypesTxt(); // 0x006393E0

void __fastcall DATATBLS_FreeMonTypeTxt(); // 0x006586D0

void __fastcall DATATBLS_UnloadPlrMode_Type_MonMode_ObjMode_Type_Composit_ArmtypeTxt(); // 0x0065B3C0

void __fastcall DATATBLS_UnloadAnimDataD2(D2AnimDataTableStrc* pAnimData); // 0x0066A830

void __fastcall DATATBLS_UnloadSomeMonsterTxts(); // 0x0065A190

void __fastcall DATATBLS_UnloadLevelsTxt(); // 0x0061DC60

void __fastcall DATATBLS_UnloadLevelDefsBin(); // 0x0061E440

void __fastcall DATATBLS_UnloadLevelTypesTxt(); // 0x0061EA90

void __fastcall DATATBLS_UnloadLvlPrestTxt(); // 0x0061F030

void __fastcall DATATBLS_UnloadLvlWarpTxt(); // 0x0061F300

void __fastcall DATATBLS_UnloadLvlMazeTxt(); // 0x0061F480

void __fastcall DATATBLS_FreeGlobalTileLibraryHash(); // 0x0061FBF0

void __fastcall DATATBLS_UnloadLvlSubTxt(); // 0x0061F9C0

void __fastcall DATATBLS_FreeAutomap(); // 0x006200D0

void __fastcall DATATBLS_UnloadObjectsTxt(); // 0x00640EE0

void __fastcall DATATBLS_UnloadObjGroupTxt(); // 0x00640F00

void __fastcall DATATBLS_UnloadShrinesTxt(); // 0x00641510

void __fastcall sub_0065C130(); // 0x0065C130

void __fastcall DATATBLS_UnloadRunesTxt(); // 0x00639C90

int __stdcall DATATBLS_FreeCollisionFieldTable(); // 0x0066A420

void __fastcall DATATBLS_UnloadBeltsTxt(); // 0x00660C60

void __fastcall DATATBLS_UnloadMonItemPercentTxt(); // 0x00654FC0

void __fastcall DATATBLS_UnloadArenaTxt(); // 0x00664AF0

void __fastcall DATATBLS_UnloadCubeMainTxt(); // 0x0066A1A0

void __fastcall DATATBLS_UnloadCharTemplateTxt(); // 0x00665740

void __fastcall D2COMMON_10916_Return(); // 0x0066A280

extern D2AnimDataTableStrc* gpAnimData_0096C8A4; // 0x0096C8A4

D2ItemTypesTxt* gpItemTypesTxt_0096C828; // 0x0096C828

int gnItemTypesTxtRecordCount_0096C82C; // 0x0096C82C

D2DifficultyLevelsTxt* gpDifficultylevelsTxt; // 0x0096C8AC

D2RuneDataTbl sgtRuneWordsTblDesc; // 0x0096CA98

void* gpCompCodeTxt_0096BCAC; // 0x0096BCAC

void* gpPlayerClassTxt_0096BC30; // 0x0096BC30

void* gpBodyLocsTxt_0096BC38; // 0x0096BC38

void* gpStorePageTxt_0096BC40; // 0x0096BC40

D2TxtLinkStrc* gpStorePageLinker_0096BC44; // 0x0096BC44

void* gpElemTypesTxt_0096BC48; // 0x0096BC48

void* gpHitClassTxt_0096BC50; // 0x0096BC50

void* gpColorsTxt_0096C5E0; // 0x0096C5E0

D2TxtLinkStrc* gpColorsLinker_0096C5E4; // 0x0096C5E4

void* gpHireDescTxt_0096BCE4; // 0x0096BCE4

void* gpMonModeTxt_0096BC58; // 0x0096BC58

void* gpPlrModeTxt_0096BC60; // 0x0096BC60

void* gpMonAiTxt_0096BCB8; // 0x0096BCB8

D2TxtLinkStrc* gpMonAiLinker_0096BCBC; // 0x0096BCBC

void* gpMonPlaceTxt_0096C6CC; // 0x0096C6CC

D2TxtLinkStrc* gpMonPlaceLinker_0096C6D0; // 0x0096C6D0

void* gpSkillCalcTxt_0096BC68; // 0x0096BC68

void* gpMissileCalcTxt_0096BC88; // 0x0096BC88

void* gpSkillCodeTxt_0096BC9C; // 0x0096BC9C

D2TxtLinkStrc* gpSkillCodeLinker_0096BCA0; // 0x0096BCA0

void* gpEventsTxt_0096BCA4; // 0x0096BCA4

int gnCharstatsTxtRecordCount; // 0x0096C7F8

D2TxtLinkStrc* gpSoundsLinker_0096BDC8; // 0x0096BDC8

D2TxtLinkStrc* gpOverlayLinker_0096C7E8; // 0x0096C7E8

D2TxtLinkStrc* gpItemStatCostLinker_0096C800; // 0x0096C800

D2TxtLinkStrc* gpItemTypesLinker_0096C824; // 0x0096C824

D2PetTypeTxt* gpPettypeTxt_0096C818; // 0x0096C818

unsigned int* gpStateMasks_0096BCF8; // 0x0096BCF8

unsigned int* gfStateMasks_0096BCFC[40]; // 0x0096BCFC

short* gpProgressiveStates_0096BD9C; // 0x0096BD9C

short* gpCurseStates_0096BDA4; // 0x0096BDA4

short* gpTransformStates_0096BDAC; // 0x0096BDAC

short* gpActionStates_0096BDB4; // 0x0096BDB4

D2TxtLinkStrc* gTxtLink_0096C81C; // 0x0096C81C

int gnPettypeTxtRecordCount; // 0x0096C820

// 0x006117B0
unsigned short __fastcall DATATBLS_GetStringIdFromReferenceString(char* szReference)
{
    const wchar_t* pUnicode;
    unsigned short nIndex = STRTABLE_FindString(szReference, &pUnicode);
    if (!nIndex)
        nIndex = 5382;
    return nIndex;
}

static int DATATBLS_GetMaxLevelFromTable(D2ExperienceDataTbl* pExperienceTxt, int nClass)
{
    if (nClass < 0 || nClass >= 7)
    {
        nClass = 0;
    }

    return pExperienceTxt->tMax.dwClass[nClass];
}

// 0x006117D0
unsigned int __stdcall DATATBLS_GetCodeFromCompCodeTxt(int nCompCode)
{
    if (nCompCode >= gnCompCodeTxtRecordCount)
        return 0;
    return gpCompCodeTxt[nCompCode].dwCode;
}

// 0x00611800
unsigned int __stdcall DATATBLS_GetLevelThreshold(int nClass, unsigned int dwLevel)
{
    if (nClass < 0 || nClass >= 7)
        nClass = 0;
    return gpExperienceTxt->aLevels[dwLevel].dwClass[nClass];
}

// 0x00611830
int __stdcall DATATBLS_GetMaxLevel(int nClass)
{
    if (nClass < 0 || nClass >= 7)
        nClass = 0;
    return gpExperienceTxt->tMax.dwClass[nClass];
}

// 0x00611860
unsigned int __stdcall DATATBLS_GetCurrentLevelFromExp(int nClass, unsigned int dwExperience)
{
    if (nClass < 0 || nClass >= 7)
    {
        nClass = 0;
    }

    D2ExperienceDataTbl* pExperienceTxt = gpExperienceTxt;
    int nMaxLevel = DATATBLS_GetMaxLevelFromTable(pExperienceTxt, nClass);
    int nLevel = 0;
    while (dwExperience >= pExperienceTxt->aLevels[nLevel].dwClass[nClass] && nLevel < nMaxLevel)
    {
        ++nLevel;
    }

    return nLevel;
}

// 0x006118B0
int __fastcall DATATBLS_AppendMemoryBuffer(char** ppCodes, int* pSize, int* pSizeEx, void* pBuffer, int nBufferSize)
{
    while (*pSize + nBufferSize >= *pSizeEx)
    {
        *pSizeEx += 1024;
        if (*pSizeEx >= 0x7FFFFFFF)
            return 0;
        *ppCodes = (char*)FOG_ReallocPool(0, *ppCodes, *pSizeEx, ".\\DATATBLS\\DataTbls.cpp", 658, 0);
    }
    int nResult = *pSize;
    memcpy(*ppCodes + nResult, pBuffer, nBufferSize);
    *pSize += nBufferSize;
    return nResult;
}

// 0x00611930
int __fastcall DATATBLS_MapSkillsTxtKeywordToNumber(char* szKey)
{
    if (0 == SStrCmpI(szKey, "min", 32))
    {
        return 0;
    }
    else if (0 == SStrCmpI(szKey, "max", 32))
    {
        return 1;
    }
    else if (0 == SStrCmpI(szKey, "rand", 32))
    {
        return 2;
    }
    else if (0 == SStrCmpI(szKey, "skill", 32))
    {
        return 3;
    }
    else if (0 == SStrCmpI(szKey, "miss", 32))
    {
        return 4;
    }
    else if (0 == SStrCmpI(szKey, "stat", 32))
    {
        return 5;
    }
    else if (0 == SStrCmpI(szKey, "sklvl", 32))
    {
        return 6;
    }
    else
    {
        return -1;
    }
}

// 0x006119E0
int __fastcall DATATBLS_GetSkillsCalcParamCount(int nValue)
{
    return (nValue == 6) + 2;
}

// 0x00611760
static void DATATBLS_MakeCalcCode(const char* szText, char* szCode)
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

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x006119F0
int __fastcall DATATBLS_SkillsCalcParamCallback(char* szText, int* pResult, int nType, int nKeywordNumber)
{
    char szCode[4];
    if (nType == 1)
    {
        switch (nKeywordNumber)
        {
        case 3:
        {
            if (gpSkillsLinker_0096C7CC)
            {
                const int nRow = FOG_GetRowFromTxt(gpSkillsLinker_0096C7CC, szText, 0);
                if (nRow >= 0)
                {
                    *pResult = 1;
                    return nRow;
                }
            }
            DATATBLS_MakeCalcCode(szText, szCode);
            const int nIndex = FOG_GetLinkIndex(gpSkillCalcLinker_0096BC6C, *(unsigned int*)szCode, 1);
            *pResult = 0;
            return nIndex;
        }
        case 4:
        {
            if (gpMissilesLinker_0096C798)
            {
                const int nRow = FOG_GetRowFromTxt(gpMissilesLinker_0096C798, szText, 0);
                if (nRow >= 0)
                {
                    *pResult = 1;
                    return nRow;
                }
            }
            DATATBLS_MakeCalcCode(szText, szCode);
            const int nIndex = FOG_GetLinkIndex(gpMissileCalcLinker_0096BC8C, *(unsigned int*)szCode, 1);
            *pResult = 0;
            return nIndex;
        }
        case 5:
        {
            if (gpItemStatCostLinker)
            {
                const int nRow = FOG_GetRowFromTxt(gpItemStatCostLinker, szText, 0);
                if (nRow >= 0)
                {
                    *pResult = 1;
                    return nRow;
                }
            }
            if (!SStrCmpI(szText, "base", 32))
            {
                *pResult = 0;
                return 1;
            }
            if (!SStrCmpI(szText, "mod", 32))
            {
                *pResult = 0;
                return 2;
            }
            SStrCmpI(szText, "accr", 32);
            *pResult = 0;
            return 0;
        }
        case 6:
        {
            if (gpSkillsLinker_0096C7CC)
            {
                const int nRow = FOG_GetRowFromTxt(gpSkillsLinker_0096C7CC, szText, 0);
                if (nRow >= 0)
                {
                    *pResult = 1;
                    return nRow;
                }
            }
            DATATBLS_MakeCalcCode(szText, szCode);
            const int nIndex = FOG_GetLinkIndex(gpSkillCalcLinker_0096BC6C, *(unsigned int*)szCode, 1);
            *pResult = 0;
            return nIndex;
        }
        }
    }
    DATATBLS_MakeCalcCode(szText, szCode);
    const int nIndex = FOG_GetLinkIndex(gpSkillCalcLinker_0096BC6C, *(unsigned int*)szCode, 1);
    *pResult = 0;
    return nIndex;
}

// 0x00611BD0
void __fastcall DATATBLS_SkillCalcLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    char pBuffer[1024];

    if (!pRecord)
    {
        return;
    }

    if (!pSrc)
    {
        *(int*)((char*)pRecord + nOffset) = -1;
        return;
    }

    const int nBufferSize = DATATBLS_CompileExpression(pSrc, pBuffer, sizeof(pBuffer), DATATBLS_MapSkillsTxtKeywordToNumber, DATATBLS_GetSkillsCalcParamCount, DATATBLS_SkillsCalcParamCallback);
    if (nBufferSize <= 0)
    {
        *(int*)((char*)pRecord + nOffset) = -1;
        return;
    }

    *(int*)((char*)pRecord + nOffset) = DATATBLS_AppendMemoryBuffer(&gpSkillsCode_0096BC70, &gnSkillsCodeSize_0096BC74, &gnSkillsCodeSizeEx_0096BC78, pBuffer, nBufferSize);
}

// 0x00611C70
void __fastcall DATATBLS_SkillDescCalcLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    char pBuffer[1024];

    if (!pRecord)
    {
        return;
    }

    if (!pSrc)
    {
        *(int*)((char*)pRecord + nOffset) = -1;
        return;
    }

    const int nBufferSize = DATATBLS_CompileExpression(pSrc, pBuffer, sizeof(pBuffer), DATATBLS_MapSkillsTxtKeywordToNumber, DATATBLS_GetSkillsCalcParamCount, DATATBLS_SkillsCalcParamCallback);
    if (nBufferSize <= 0)
    {
        *(int*)((char*)pRecord + nOffset) = -1;
        return;
    }

    *(int*)((char*)pRecord + nOffset) = DATATBLS_AppendMemoryBuffer(&gpSkillDescCode_0096BC7C, &gnSkillDescCodeSize_0096BC80, &gnSkillDescCodeSizeEx_0096BC84, pBuffer, nBufferSize);
}

// 0x00611D30
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty)
{
    nDifficulty = nDifficulty > 0 ? nDifficulty : 0;
    if (nDifficulty >= gnDifficultylevelsTxtRecordCount - 1)
    {
        nDifficulty = gnDifficultylevelsTxtRecordCount - 1;
    }
    return &gpDifficultylevelsTxt[nDifficulty];
}

// 0x00611D60
void __fastcall DATATBLS_BuildStateMask(unsigned int* pMask, int nFlag)
{
    D2StatesTxt* pStatesTxt = gpStatesTxt;
    for (int i = 0; i < gnStatesTxtRecordCount; ++i)
    {
        if (pStatesTxt[i].nStateFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7])
            pMask[i >> 5] |= gdwBitMasks[i & 0x1F];
    }
}

// 0x00611DC0
void __fastcall DATATBLS_BuildStateListByFlag(short** ppList, short* pnCount, int nFlag)
{
    *ppList = (short*)FOG_AllocPool(0, sizeof(short) * gnStatesTxtRecordCount, ".\\DATATBLS\\DataTbls.cpp", 1611, 0);
    memset(*ppList, 0, sizeof(short) * gnStatesTxtRecordCount);
    D2StatesTxt* pStatesTxt = gpStatesTxt;
    *pnCount = 0;
    for (int i = 0; i < gnStatesTxtRecordCount; ++i)
    {
        if (pStatesTxt[i].nStateFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7])
        {
            (*ppList)[*pnCount] = i;
            ++*pnCount;
        }
    }
}

// 0x00611E60
void __fastcall DATATBLS_BuildStateListByField(short** ppList, short* pnCount, int nFieldOffset)
{
    *ppList = (short*)FOG_AllocPool(0, sizeof(short) * gnStatesTxtRecordCount, ".\\DATATBLS\\DataTbls.cpp", 1634, 0);
    memset(*ppList, 0, sizeof(short) * gnStatesTxtRecordCount);
    D2StatesTxt* pStatesTxt = gpStatesTxt;
    *pnCount = 0;
    for (int i = 0; i < gnStatesTxtRecordCount; ++i)
    {
        if (*(short*)((char*)&pStatesTxt[i] + nFieldOffset) > 0)
        {
            (*ppList)[*pnCount] = i;
            ++*pnCount;
        }
    }
}

// 0x00611EE0
static void DATATBLS_GetPlayerClassDebugName(char* buffer, int length, int id)
{
    if (length <= 0) return;
    if (id >= 0 && id < gVar_00744304->playerCount)
    {
        PlayerRecord* record = &gVar_00744304->players[id];
        if (record && record->name[0])
        {
            strncpy(buffer, record->name, length);
            buffer[length - 1] = 0;
            return;
        }
    }
    _snprintf(buffer, length, "player %d", id);
    buffer[length - 1] = 0;
}

// 0x00611F40
static void DATATBLS_GetMonsterDebugName(char* buffer, int length, int id)
{
    if (length <= 0) return;
    if (id >= 0 && id < gVar_00744304->monsterCount)
    {
        MonsterRecord* record = &gVar_00744304->monsters[id];
        if (record && record->nameIndex != 0x1506)
        {
            const Unicode* name = D2LANG_GetStringFromTblIndex(record->nameIndex);
            sub_00526F70(buffer, name, length);
            return;
        }
    }
    _snprintf(buffer, length, "monster %d", id);
    buffer[length - 1] = 0;
}

// 0x00611FA0
static void DATATBLS_GetObjectDebugName(char* buffer, int length, int id)
{
    if (length <= 0) return;
    ObjectRecord* record = sub_00640E90_Object(id);
    if (record && record->name[0])
    {
        strncpy(buffer, record->name, length);
        buffer[length - 1] = 0;
        return;
    }
    _snprintf(buffer, length, "object %d", id);
    buffer[length - 1] = 0;
}

// 0x00611FE0
static void DATATBLS_GetItemDebugName(char* buffer, int length, int id)
{
    ItemRecord* record = sub_006335F0_Item(id);
    if (record && record->nameIndex != 0x1506)
    {
        const Unicode* name = D2LANG_GetStringFromTblIndex(record->nameIndex);
            sub_00526F70(buffer, name, length);
        return;
    }
    if (length > 0)
    {
        _snprintf(buffer, length, "item %d", id);
        buffer[length - 1] = 0;
    }
}

// 0x00612030
static __declspec(noinline) void DATATBLS_GetMissileDebugName(char* buffer, int length, int id)
{
    if (length > 0)
    {
        _snprintf(buffer, length, "missile %d", id);
        buffer[length - 1] = 0;
    }
}

// 0x00612050
char* __stdcall DATATBLS_GetUnitDebugName(UnitHeader* unit, char* buffer, int length)
{
    buffer[0] = 0;
    if (!unit)
    {
        sub_006883F8_Copy(buffer, "NULL Unit");
        return buffer;
    }
    switch (unit->type)
    {
    case 0: DATATBLS_GetPlayerClassDebugName(buffer, length, unit->classId); break;
    case 1: DATATBLS_GetMonsterDebugName(buffer, length, unit->classId); break;
    case 2: DATATBLS_GetObjectDebugName(buffer, length, unit->classId); break;
    case 3: DATATBLS_GetMissileDebugName(buffer, length, unit->classId); break;
    case 4: DATATBLS_GetItemDebugName(buffer, length, unit->classId); break;
    default: sub_006883F8_Copy(buffer, "Invalid Unit"); break;
    }
    return buffer;
}

// 0x00612120
char* __stdcall DATATBLS_GetUnitTypeAndClassDebugName(unsigned int type, short id, char* buffer, int length)
{
    buffer[0] = 0;
    switch (type)
    {
    case 0: DATATBLS_GetPlayerClassDebugName(buffer, length, id); break;
    case 1: DATATBLS_GetMonsterDebugName(buffer, length, id); break;
    case 2: DATATBLS_GetObjectDebugName(buffer, length, id); break;
    case 3:
        if (length > 0)
        {
            _snprintf(buffer, length, "missile %d", id);
            buffer[length - 1] = 0;
        }
        break;
    case 4: DATATBLS_GetItemDebugName(buffer, length, id); break;
    default: sub_006883F8_Copy(buffer, "Invalid Unit Type"); break;
    }
    return buffer;
}

// 0x006121F0
void __stdcall DATATBLS_WriteBinFile(char* szFileName, void* pWriteBuffer, unsigned int nBufferSize, int nRecordCount)
{
    char szFilePath[260];
    wsprintfA(szFilePath, gszPathFormat_006D4124, gszExcelDirectory_006D8ED4, szFileName);
    _iobuf* pFile = fopen(szFilePath, gszFileModeWb_006D69E0);
    if (pFile)
    {
        fwrite(&nRecordCount, sizeof(nRecordCount), 1, pFile);
        fwrite(pWriteBuffer, nBufferSize, 1, pFile);
        fclose(pFile);
    }
}

// 0x00612280
void* __fastcall DATATBLS_ReadExcelFile(void* hArchive, const char* szName, const char* szExtension, unsigned int* pnSize, const char* szFile, int nLine)
{
    char szPath[0x104];
    wsprintfA(szPath, "%s\\%s%s", gszExcelDirectory_006D8ED4, szName, szExtension);
    return ARCHIVE_AllocateBufferAndReadFile(hArchive, szPath, pnSize, ".\\DATATBLS\\DataTbls.cpp", 0x82F);
}

// 0x006122F0
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize)
{
    int nDataSize = 0;
    void* pData;
    void* pTxt;
    int nRecordCount;
    char szPath[256];

    if (gbCompileTxt)
    {
        if (!_stricmp(szName, "leveldefs"))
        {
            pData = DATATBLS_ReadExcelFile(hArchive, "levels", ".txt", &nDataSize, ".\\DATATBLS\\DataTbls.cpp", 2233);
        }
        else
        {
            pData = DATATBLS_ReadExcelFile(hArchive, szName, ".txt", &nDataSize, ".\\DATATBLS\\DataTbls.cpp", 2240);
        }
        D2_ASSERT(pData, 2242);

        D2BinFileStrc* pBinFile = FOG_CreateBinFile(pData, nDataSize);
        nRecordCount = FOG_GetRecordCountFromBinFile(pBinFile);
        pTxt = FOG_AllocPool(0, nRecordSize * nRecordCount, ".\\DATATBLS\\DataTbls.cpp", 2249, 0);
        memset(pTxt, 0, nRecordSize * nRecordCount);
        FOG_10207(pBinFile, pTbl, pTxt, nRecordCount, nRecordSize);
        FOG_FreeBinFile(pBinFile);

        strcpy(szPath, szName);
        strcat(szPath, ".bin");
        DATATBLS_WriteBinFile(szPath, pTxt, nRecordSize * nRecordCount, nRecordCount);
        sub_0040B480(0, pTxt, ".\\DATATBLS\\DataTbls.cpp", 2262, 0);
    }

    if (DATATBLS_LoadFromBin)
    {
        pData = DATATBLS_ReadExcelFile(hArchive, szName, ".bin", &nDataSize, ".\\DATATBLS\\DataTbls.cpp", 2270);
    }
    else
    {
        if (!_stricmp(szName, "leveldefs"))
            pData = DATATBLS_ReadExcelFile(hArchive, "levels", ".txt", &nDataSize, ".\\DATATBLS\\DataTbls.cpp", 2274);
        else
            pData = DATATBLS_ReadExcelFile(hArchive, szName, ".txt", &nDataSize, ".\\DATATBLS\\DataTbls.cpp", 2276);
    }
    D2_ASSERT(pData, 2279);

    if (DATATBLS_LoadFromBin)
    {
        nRecordCount = *(int*)pData;
        pTxt = (char*)pData + 4;
    }
    else
    {
        D2BinFileStrc* pBinFile = FOG_CreateBinFile(pData, nDataSize);
        nRecordCount = FOG_GetRecordCountFromBinFile(pBinFile);
        pTxt = FOG_AllocPool(0, nRecordSize * nRecordCount, ".\\DATATBLS\\DataTbls.cpp", 2308, 0);
        memset(pTxt, 0, nRecordSize * nRecordCount);
        FOG_10207(pBinFile, pTbl, pTxt, nRecordCount, nRecordSize);
        FOG_FreeBinFile(pBinFile);
    }

    if (pRecordCount)
    {
        *pRecordCount = nRecordCount;
    }

    return pTxt;
}

// 0x006125A0
void __stdcall DATATBLS_ToggleCompileTxtFlag(int bSilent)
{
    gbCompileTxt = !bSilent;
}

// 0x006125C0
void __stdcall DATATBLS_UnloadBin(void* pBinFile)
{
    if (pBinFile)
    {
        if (DATATBLS_LoadFromBin)
            FOG_FreePool(0, (char*)pBinFile - 4, ".\\DATATBLS\\DataTbls.cpp", 0x924, 0);
        else
            FOG_FreePool(0, pBinFile, ".\\DATATBLS\\DataTbls.cpp", 0x926, 0);
    }
}

// 0x00612600
void __fastcall DATATBLS_InitUnicodeClassNamesInCharStatsTxt(void* pTable, int nRecordCount, int nRecordSize, int nNameOffset, int a5, int nNameLength)
{
    Unicode wszClass[512];
    Unicode wszName[512];
    for (int n = 0; n < 512; ++n)
    {
        wszClass[n].wChar = 0;
    }
    for (int n = 0; n < 512; ++n)
    {
        wszName[n].wChar = 0;
    }
    Unicode wszOpen[16] = {};
    Unicode wszClose[16] = {};

    sub_00526320_ToUnicode(wszOpen, gszOpenBracket_006E6438, 16);
    sub_00526320_ToUnicode(wszClose, gszCloseBracket_006E6434, 16);

    for (int i = 0; i < nRecordCount; ++i)
    {
        char* pRecord = (char*)pTable + i * nRecordSize;
        memset(pRecord + a5, 0, nNameLength);

        const Unicode* pString = D2LANG_GetStringByReferenceString(pRecord + nNameOffset);
        if (!pString)
        {
            sub_005267E0(wszClass, wszOpen);
            sub_00526320_ToUnicode(wszName, pRecord + nNameOffset, nNameLength - 1);
            sub_00526700(wszClass, wszName);
            sub_00526700(wszClass, wszClose);
            sub_00526790((Unicode*)(pRecord + a5), wszClass, nNameLength);
        }
        else
        {
            sub_00526790((Unicode*)(pRecord + a5), pString, nNameLength);
        }
    }
}

// 0x00612750
static void DATATBLS_LoadSomeTxts(void* hArchive)
{
    int nRecordCount;

    D2BinFieldStrc pCompCodeTbl[] =
    {
        { gszTxtField_code, 10, 0, 0, &gD2DataTables.pCompCodeLinker },
        { gszTxtField_end, 0, 0, 0, 0 },
    };
    gD2DataTables.pCompCodeLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 115);
    gD2DataTables.pCompCodeTxt = DATATBLS_CompileTxt(hArchive, "compcode", pCompCodeTbl, &gD2DataTables.nCompCodeTxtRecordCount, 4);

    if (gD2DataTables.bCompileTxt)
    {
        D2BinFieldStrc pPlayerClassTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pPlayerClassLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pPlayerClassLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 132);
        gD2DataTables.pPlayerClassTxt = DATATBLS_CompileTxt(hArchive, "playerclass", pPlayerClassTbl, &nRecordCount, 4);

        D2BinFieldStrc pBodyLocsTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pBodyLocsLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pBodyLocsLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 144);
        gD2DataTables.pBodyLocsTxt = DATATBLS_CompileTxt(hArchive, "bodylocs", pBodyLocsTbl, &nRecordCount, 4);

        D2BinFieldStrc pStorePageTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pStorePageLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pStorePageLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 156);
        gD2DataTables.pStorePageTxt = DATATBLS_CompileTxt(hArchive, "storepage", pStorePageTbl, &nRecordCount, 4);

        D2BinFieldStrc pElemTypesTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pElemTypesLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pElemTypesLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 168);
        gD2DataTables.pElemTypesTxt = DATATBLS_CompileTxt(hArchive, "elemtypes", pElemTypesTbl, &nRecordCount, 4);

        D2BinFieldStrc pHitClassTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pHitClassLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pHitClassLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 184);
        gD2DataTables.pHitClassTxt = DATATBLS_CompileTxt(hArchive, gszHitclassTxtName, pHitClassTbl, &nRecordCount, 4);

        D2BinFieldStrc pColorsTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pColorsLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pColorsLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 196);
        gD2DataTables.pColorsTxt = DATATBLS_CompileTxt(hArchive, "colors", pColorsTbl, &nRecordCount, 4);

        D2BinFieldStrc pHireDescTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pHireDescLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pHireDescLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 208);
        gD2DataTables.pHireDescTxt = DATATBLS_CompileTxt(hArchive, "hiredesc", pHireDescTbl, &nRecordCount, 4);

        D2BinFieldStrc pMonModeTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pMonModeLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pMonModeLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 220);
        gD2DataTables.pMonModeTxtStub = DATATBLS_CompileTxt(hArchive, "monmode", pMonModeTbl, &nRecordCount, 4);

        D2BinFieldStrc pPlrModeTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pPlrModeLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pPlrModeLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 232);
        gD2DataTables.pPlrModeTxtStub = DATATBLS_CompileTxt(hArchive, "plrmode", pPlrModeTbl, &nRecordCount, 4);

        D2BinFieldStrc pMonAiTbl[] =
        {
            { "AI", 17, 0, 0, &gD2DataTables.pMonAiLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pMonAiLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 244);
        gD2DataTables.pMonAiTxt = DATATBLS_CompileTxt(hArchive, "monai", pMonAiTbl, &gD2DataTables.nMonAiTxtRecordCount, 2);

        D2BinFieldStrc pMonPlaceTbl[] =
        {
            { gszTxtField_code, 17, 0, 0, &gD2DataTables.pMonPlaceLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pMonPlaceLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 256);
        gD2DataTables.pMonPlaceTxt = DATATBLS_CompileTxt(hArchive, "monplace", pMonPlaceTbl, &gD2DataTables.nMonPlaceTxtRecordCount, 2);

        D2BinFieldStrc pSkillCalcTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pSkillCalcLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pSkillCalcLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 268);
        gD2DataTables.pSkillCalcTxt = DATATBLS_CompileTxt(hArchive, "skillcalc", pSkillCalcTbl, &nRecordCount, 4);

        D2BinFieldStrc pMissileCalcTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pMissileCalcLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pMissileCalcLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 280);
        gD2DataTables.pMissileCalcTxt = DATATBLS_CompileTxt(hArchive, "misscalc", pMissileCalcTbl, &nRecordCount, 4);

        D2BinFieldStrc pSkillCodeTbl[] =
        {
            { "skill", 17, 0, 0, &gD2DataTables.unk0x70 },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.unk0x70 = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 291);
        gD2DataTables.pSkillCode = DATATBLS_CompileTxt(hArchive, "skills", pSkillCodeTbl, &nRecordCount, 2);

        D2BinFieldStrc pEventsTbl[] =
        {
            { "event", 17, 0, 0, &gD2DataTables.pEventsLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pEventsLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 303);
        gD2DataTables.pEventsTxt = DATATBLS_CompileTxt(hArchive, "events", pEventsTbl, &nRecordCount, 2);
    }
}

static void DATATBLS_UnloadBinInline(void* pBinFile)
{
    if (pBinFile)
    {
        if (DATATBLS_LoadFromBin)
            FOG_FreePool(0, (char*)pBinFile - 4, ".\\DATATBLS\\DataTbls.cpp", 0x924, 0);
        else
            FOG_FreePool(0, pBinFile, ".\\DATATBLS\\DataTbls.cpp", 0x926, 0);
    }
}

// 0x00612EA0
void __stdcall DATATBLS_UnloadCompCodeAndCompileBins()
{
    DATATBLS_UnloadBinInline(gpCompCodeTxt_0096BCAC);
    FOG_FreeLinker(gpCompCodeLinker_0096BCB0);

    if (gbCompileTxt)
    {
        DATATBLS_UnloadBinInline(gpPlayerClassTxt_0096BC30);
        FOG_FreeLinker(gpPlayerClassLinker_0096BC34);
        DATATBLS_UnloadBinInline(gpBodyLocsTxt_0096BC38);
        FOG_FreeLinker(gpBodyLocsLinker_0096BC3C);
        DATATBLS_UnloadBinInline(gpStorePageTxt_0096BC40);
        FOG_FreeLinker(gpStorePageLinker_0096BC44);
        DATATBLS_UnloadBinInline(gpElemTypesTxt_0096BC48);
        FOG_FreeLinker(gpElemTypesLinker_0096BC4C);
        DATATBLS_UnloadBinInline(gpHitClassTxt_0096BC50);
        FOG_FreeLinker(gpHitClassLinker_0096BC54);
        DATATBLS_UnloadBinInline(gpColorsTxt_0096C5E0);
        FOG_FreeLinker(gpColorsLinker_0096C5E4);
        DATATBLS_UnloadBinInline(gpHireDescTxt_0096BCE4);
        FOG_FreeLinker(gpHireDescLinker_0096BCE8);
        DATATBLS_UnloadBinInline(gpMonModeTxt_0096BC58);
        FOG_FreeLinker(gpMonModeLinker_0096BC5C);
        DATATBLS_UnloadBinInline(gpPlrModeTxt_0096BC60);
        FOG_FreeLinker(gpPlrModeLinker_0096BC64);
        DATATBLS_UnloadBinInline(gpMonAiTxt_0096BCB8);
        FOG_FreeLinker(gpMonAiLinker_0096BCBC);
        DATATBLS_UnloadBinInline(gpMonPlaceTxt_0096C6CC);
        FOG_FreeLinker(gpMonPlaceLinker_0096C6D0);
        DATATBLS_UnloadBinInline(gpSkillCalcTxt_0096BC68);
        FOG_FreeLinker(gpSkillCalcLinker_0096BC6C);
        DATATBLS_UnloadBinInline(gpMissileCalcTxt_0096BC88);
        FOG_FreeLinker(gpMissileCalcLinker_0096BC8C);
        DATATBLS_UnloadBinInline(gpSkillCodeTxt_0096BC9C);
        FOG_FreeLinker(gpSkillCodeLinker_0096BCA0);
        DATATBLS_UnloadBinInline(gpEventsTxt_0096BCA4);
        FOG_FreeLinker(gpEventsLinker_0096BCA8);
    }
}

struct D2UnitStrc;

// 0x00613260
void __stdcall DATATBLS_LoadCharStatsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "class", 1, 15, 32, 0 },
        { "str", 4, 0, 48, 0 },
        { "dex", 4, 0, 49, 0 },
        { "vit", 4, 0, 51, 0 },
        { gszTxtField_int, 4, 0, 50, 0 },
        { "stamina", 4, 0, 52, 0 },
        { "hpadd", 4, 0, 53, 0 },
        { "PercentStr", 4, 0, 54, 0 },
        { "PercentDex", 4, 0, 56, 0 },
        { "PercentVit", 4, 0, 57, 0 },
        { "PercentInt", 4, 0, 55, 0 },
        { "ManaRegen", 4, 0, 58, 0 },
        { "ToHitFactor", 2, 0, 60, 0 },
        { "WalkVelocity", 4, 0, 64, 0 },
        { "RunVelocity", 4, 0, 65, 0 },
        { "RunDrain", 4, 0, 66, 0 },
        { "LifePerLevel", 4, 0, 67, 0 },
        { "StaminaPerLevel", 4, 0, 68, 0 },
        { "ManaPerLevel", 4, 0, 69, 0 },
        { "LifePerVitality", 4, 0, 70, 0 },
        { "StaminaPerVitality", 4, 0, 71, 0 },
        { "ManaPerMagic", 4, 0, 72, 0 },
        { "BlockFactor", 4, 0, 73, 0 },
        { "basewclass", 9, 0, 76, 0 },
        { "StrAllSkills", 22, 0, 82, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "StrSkillTab1", 22, 0, 84, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "StrSkillTab2", 22, 0, 86, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "StrSkillTab3", 22, 0, 88, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "StrClassOnly", 22, 0, 90, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "StartSkill", 20, 0, 172, &gTxtLink_0096C7CC },
        { "Skill 1", 20, 0, 174, &gTxtLink_0096C7CC },
        { "Skill 2", 20, 0, 176, &gTxtLink_0096C7CC },
        { "Skill 3", 20, 0, 178, &gTxtLink_0096C7CC },
        { "Skill 4", 20, 0, 180, &gTxtLink_0096C7CC },
        { "Skill 5", 20, 0, 182, &gTxtLink_0096C7CC },
        { "Skill 6", 20, 0, 184, &gTxtLink_0096C7CC },
        { "Skill 7", 20, 0, 186, &gTxtLink_0096C7CC },
        { "Skill 8", 20, 0, 188, &gTxtLink_0096C7CC },
        { "Skill 9", 20, 0, 190, &gTxtLink_0096C7CC },
        { "Skill 10", 20, 0, 192, &gTxtLink_0096C7CC },
        { "StatPerLevel", 4, 0, 80, 0 },
        { "item1loc", 13, 0, 96, &gpBodyLocsLinker_0096BC3C },
        { "item2loc", 13, 0, 104, &gpBodyLocsLinker_0096BC3C },
        { "item3loc", 13, 0, 112, &gpBodyLocsLinker_0096BC3C },
        { "item4loc", 13, 0, 120, &gpBodyLocsLinker_0096BC3C },
        { "item5loc", 13, 0, 128, &gpBodyLocsLinker_0096BC3C },
        { "item6loc", 13, 0, 136, &gpBodyLocsLinker_0096BC3C },
        { "item7loc", 13, 0, 144, &gpBodyLocsLinker_0096BC3C },
        { "item8loc", 13, 0, 152, &gpBodyLocsLinker_0096BC3C },
        { "item9loc", 13, 0, 160, &gpBodyLocsLinker_0096BC3C },
        { "item10loc", 13, 0, 168, &gpBodyLocsLinker_0096BC3C },
        { "item1", 9, 0, 92, 0 },
        { "item1count", 4, 0, 97, 0 },
        { "item2", 9, 0, 100, 0 },
        { "item2count", 4, 0, 105, 0 },
        { "item3", 9, 0, 108, 0 },
        { "item3count", 4, 0, 113, 0 },
        { "item4", 9, 0, 116, 0 },
        { "item4count", 4, 0, 121, 0 },
        { "item5", 9, 0, 124, 0 },
        { "item5count", 4, 0, 129, 0 },
        { "item6", 9, 0, 132, 0 },
        { "item6count", 4, 0, 137, 0 },
        { "item7", 9, 0, 140, 0 },
        { "item7count", 4, 0, 145, 0 },
        { "item8", 9, 0, 148, 0 },
        { "item8count", 4, 0, 153, 0 },
        { "item9", 9, 0, 156, 0 },
        { "item9count", 4, 0, 161, 0 },
        { "item10", 9, 0, 164, 0 },
        { "item10count", 4, 0, 169, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpCharstatsTxt = DATATBLS_CompileTxt(hArchive, "charstats", pTbl, &gnCharstatsTxtRecordCount, 196);
    DATATBLS_InitUnicodeClassNamesInCharStatsTxt(gpCharstatsTxt, gnCharstatsTxtRecordCount, 196, 32, 0, 16);
}

// 0x00613D30
void __stdcall DATATBLS_LoadExperienceTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { gszTxtField_Amazon, 2, 0, 0, 0 },
        { gszTxtField_Sorceress, 2, 0, 4, 0 },
        { gszTxtField_Necromancer, 2, 0, 8, 0 },
        { gszTxtField_Paladin, 2, 0, 12, 0 },
        { gszTxtField_Barbarian, 2, 0, 16, 0 },
        { gszTxtField_Druid, 2, 0, 20, 0 },
        { gszTxtField_Assassin, 2, 0, 24, 0 },
        { "ExpRatio", 2, 0, 28, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpExperienceTxt = (D2ExperienceDataTbl*)DATATBLS_CompileTxt(hArchive, "experience", pTbl, 0, 32);
}

// 0x00613E60
unsigned int __stdcall DATATBLS_GetExpRatio(int nLevel)
{
    if (!gpExperienceTxt)
        return 0;
    if (nLevel <= 0)
        return gpExperienceTxt->tMax.dwExpRatio;
    if (nLevel > (int)gpExperienceTxt->tMax.dwClass[0])
        return 0;
    return gpExperienceTxt->aLevels[nLevel].dwExpRatio;
}

// 0x00613E90
void __fastcall DATATBLS_GetBinFileHandle(void* hArchive, const char* szFile, void** ppFileHandle, int* pSize, int* pSizeEx)
{
    int nSize;
    char szFilePath[0x104];
    if (gbCompileTxt && *ppFileHandle)
    {
        wsprintfA(szFilePath, "%s\\%s.bin", gszExcelDirectory_006D8ED4, szFile);
        _iobuf* pFile = fopen(szFilePath, gszFileModeWb_006D69E0);
        if (pFile)
        {
            fwrite(*ppFileHandle, *pSize, 1, pFile);
            fclose(pFile);
        }
        FOG_FreePool(0, *ppFileHandle, ".\\DATATBLS\\DataTbls.cpp", 0x275, 0);
    }
    *ppFileHandle = DATATBLS_ReadExcelFile(hArchive, szFile, szBinExtension_006DCC68, &nSize, ".\\DATATBLS\\DataTbls.cpp", 0x27A);
    *pSizeEx = nSize;
    *pSize = nSize;
}

// 0x00617C20
void __fastcall DATATBLS_LoadSkills(void* hArchive) {
 DATATBLS_LoadSkills_SkillDescTxt(hArchive);
}

// 0x00617C30
void __fastcall DATATBLS_UnloadSkills_SkillDescTxt()
{
    if (gpClassSkillCount_0096C7D4)
    {
        FOG_FreePool(0, gpClassSkillCount_0096C7D4, ".\\DATATBLS\\DataTbls.cpp", 0x5B8, 0);
        gpClassSkillCount_0096C7D4 = 0;
    }
    if (gpClassSkillList_0096C7DC)
    {
        FOG_FreePool(0, gpClassSkillList_0096C7DC, ".\\DATATBLS\\DataTbls.cpp", 0x5BE, 0);
        gpClassSkillList_0096C7DC = 0;
    }
    gnHighestClassSkillCount_0096C7D8 = 0;
    if (gpPassiveSkills_0096C7E4)
    {
        FOG_FreePool(0, gpPassiveSkills_0096C7E4, ".\\DATATBLS\\DataTbls.cpp", 0x5C5, 0);
        gpPassiveSkills_0096C7E4 = 0;
    }
    gnPassiveSkills_0096C7E0 = 0;
    if (gpSkillsCode_0096BC70)
    {
        FOG_FreePool(0, gpSkillsCode_0096BC70, ".\\DATATBLS\\DataTbls.cpp", 0x5CC, 0);
        gpSkillsCode_0096BC70 = 0;
    }
    gnSkillsCodeSize_0096BC74 = 0;
    gnSkillsCodeSizeEx_0096BC78 = 0;
    if (gpSkillDescCode_0096BC7C)
    {
        FOG_FreePool(0, gpSkillDescCode_0096BC7C, ".\\DATATBLS\\DataTbls.cpp", 0x5D4, 0);
        gpSkillDescCode_0096BC7C = 0;
    }
    gnSkillDescCodeSize_0096BC80 = 0;
    gnSkillDescCodeSizeEx_0096BC84 = 0;
    DATATBLS_UnloadBinInline(gpSkillsTxt_0096C7C8);
    FOG_FreeLinker(gpSkillsLinker_0096C7CC);
    gnSkillsTxtRecordCount_0096C7D0 = 0;
    DATATBLS_UnloadBinInline(gpSkillDescTxt_0096C7BC);
    FOG_FreeLinker(gpSkillDescLinker_0096C7C0);
    gnSkillDescTxtRecordCount_0096C7C4 = 0;
}

// 0x00617D90
void __stdcall DATATBLS_LoadDifficultyLevelsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "ResistPenalty", 2, 0, 0, 0 },
        { "DeathExpPenalty", 2, 0, 4, 0 },
        { "UberCodeOddsNormal", 2, 0, 8, 0 },
        { "UberCodeOddsGood", 2, 0, 12, 0 },
        { "UltraCodeOddsNormal", 2, 0, 32, 0 },
        { "UltraCodeOddsGood", 2, 0, 36, 0 },
        { "LifeStealDivisor", 2, 0, 40, 0 },
        { "ManaStealDivisor", 2, 0, 44, 0 },
        { "MonsterSkillBonus", 2, 0, 16, 0 },
        { "MonsterFreezeDivisor", 2, 0, 20, 0 },
        { "MonsterColdDivisor", 2, 0, 24, 0 },
        { "AiCurseDivisor", 2, 0, 28, 0 },
        { "UniqueDamageBonus", 2, 0, 48, 0 },
        { "ChampionDamageBonus", 2, 0, 52, 0 },
        { "HireableBossDamagePercent", 2, 0, 56, 0 },
        { "MonsterCEDamagePercent", 2, 0, 60, 0 },
        { "StaticFieldMin", 2, 0, 64, 0 },
        { "GambleRare", 2, 0, 68, 0 },
        { "GambleSet", 2, 0, 72, 0 },
        { "GambleUnique", 2, 0, 76, 0 },
        { "GambleUber", 2, 0, 80, 0 },
        { "GambleUltra", 2, 0, 84, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpDifficultylevelsTxt = (D2DifficultyLevelsTxt*)DATATBLS_CompileTxt(hArchive, "difficultylevels", pTbl, &gnDifficultylevelsTxtRecordCount, 88);
    TBL_ASSERT(gnDifficultylevelsTxtRecordCount == 3, 1567);
}

// 0x00618100
void __fastcall DATATBLS_LoadStatesTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "state", TXTFIELD_NAMETOINDEX, 0, 0, &gD2DataTables.pStatesLinker },
        { "group", TXTFIELD_WORD, 0, 30, 0 },
        { "nosend", TXTFIELD_BIT, 0, 16, 0 },
        { "hide", TXTFIELD_BIT, 2, 16, 0 },
        { "transform", TXTFIELD_BIT, 3, 16, 0 },
        { "aura", TXTFIELD_BIT, 1, 16, 0 },
        { "pgsv", TXTFIELD_BIT, 4, 16, 0 },
        { "active", TXTFIELD_BIT, 5, 16, 0 },
        { "remhit", TXTFIELD_BIT, 6, 16, 0 },
        { "damblue", TXTFIELD_BIT, 7, 16, 0 },
        { "damred", TXTFIELD_BIT, 8, 16, 0 },
        { "attblue", TXTFIELD_BIT, 9, 16, 0 },
        { "attred", TXTFIELD_BIT, 10, 16, 0 },
        { "curse", TXTFIELD_BIT, 11, 16, 0 },
        { "curable", TXTFIELD_BIT, 12, 16, 0 },
        { "plrstaydeath", TXTFIELD_BIT, 13, 16, 0 },
        { "monstaydeath", TXTFIELD_BIT, 14, 16, 0 },
        { "bossstaydeath", TXTFIELD_BIT, 15, 16, 0 },
        { "disguise", TXTFIELD_BIT, 16, 16, 0 },
        { "bossinv", TXTFIELD_BIT, 37, 16, 0 },
        { "meleeonly", TXTFIELD_BIT, 38, 16, 0 },
        { "restrict", TXTFIELD_BIT, 17, 16, 0 },
        { "blue", TXTFIELD_BIT, 18, 16, 0 },
        { "armblue", TXTFIELD_BIT, 19, 16, 0 },
        { "rfblue", TXTFIELD_BIT, 20, 16, 0 },
        { "rcblue", TXTFIELD_BIT, 21, 16, 0 },
        { "rlblue", TXTFIELD_BIT, 22, 16, 0 },
        { "rpblue", TXTFIELD_BIT, 23, 16, 0 },
        { "stambarblue", TXTFIELD_BIT, 24, 16, 0 },
        { "armred", TXTFIELD_BIT, 25, 16, 0 },
        { "rfred", TXTFIELD_BIT, 26, 16, 0 },
        { "rcred", TXTFIELD_BIT, 27, 16, 0 },
        { "rlred", TXTFIELD_BIT, 28, 16, 0 },
        { "rpred", TXTFIELD_BIT, 29, 16, 0 },
        { gszTxtField_exp, TXTFIELD_BIT, 30, 16, 0 },
        { "shatter", TXTFIELD_BIT, 31, 16, 0 },
        { "life", TXTFIELD_BIT, 32, 16, 0 },
        { "udead", TXTFIELD_BIT, 33, 16, 0 },
        { "green", TXTFIELD_BIT, 34, 16, 0 },
        { "nooverlays", TXTFIELD_BIT, 35, 16, 0 },
        { "notondead", TXTFIELD_BIT, 39, 16, 0 },
        { "noclear", TXTFIELD_BIT, 36, 16, 0 },
        { "overlay1", TXTFIELD_NAMETOWORD, 0, 2, &gD2DataTables.pOverlayLinker },
        { "overlay2", TXTFIELD_NAMETOWORD, 0, 4, &gD2DataTables.pOverlayLinker },
        { "overlay3", TXTFIELD_NAMETOWORD, 0, 6, &gD2DataTables.pOverlayLinker },
        { "overlay4", TXTFIELD_NAMETOWORD, 0, 8, &gD2DataTables.pOverlayLinker },
        { "pgsvoverlay", TXTFIELD_NAMETOWORD, 0, 14, &gD2DataTables.pOverlayLinker },
        { "castoverlay", TXTFIELD_NAMETOWORD, 0, 10, &gD2DataTables.pOverlayLinker },
        { "removerlay", TXTFIELD_NAMETOWORD, 0, 12, &gD2DataTables.pOverlayLinker },
        { "stat", TXTFIELD_NAMETOWORD, 0, 24, &gD2DataTables.pItemStatCostLinker },
        { "setfunc", TXTFIELD_WORD, 0, 26, 0 },
        { "remfunc", TXTFIELD_WORD, 0, 28, 0 },
        { "missile", TXTFIELD_NAMETOWORD, 0, 58, &gD2DataTables.pMissilesLinker },
        { "skill", TXTFIELD_NAMETOWORD, 0, 56, &gD2DataTables.unk0x70 },
        { "colorpri", TXTFIELD_BYTE, 0, 32, 0 },
        { "colorshift", TXTFIELD_BYTE, 0, 33, 0 },
        { "light-r", TXTFIELD_BYTE, 0, 34, 0 },
        { "light-g", TXTFIELD_BYTE, 0, 35, 0 },
        { "light-b", TXTFIELD_BYTE, 0, 36, 0 },
        { "onsound", TXTFIELD_NAMETOWORD, 0, 38, &gD2DataTables.pSoundsLinker },
        { "offsound", TXTFIELD_NAMETOWORD, 0, 40, &gD2DataTables.pSoundsLinker },
        { "itemtype", TXTFIELD_CODETOWORD, 0, 42, &gD2DataTables.pItemTypesLinker },
        { "itemtrans", TXTFIELD_CODETOBYTE, 0, 44, &gD2DataTables.pColorsLinker },
        { "gfxtype", TXTFIELD_BYTE, 0, 45, 0 },
        { "gfxclass", TXTFIELD_WORD, 0, 46, 0 },
        { "cltevent", TXTFIELD_NAMETOWORD, 0, 48, &gD2DataTables.pEventsLinker },
        { "clteventfunc", TXTFIELD_WORD, 0, 50, 0 },
        { "cltactivefunc", TXTFIELD_WORD, 0, 52, 0 },
        { "srvactivefunc", TXTFIELD_WORD, 0, 54, 0 },
        { gszTxtField_end, TXTFIELD_NONE, 0, 0, 0 },
    };

    gD2DataTables.pStatesLinker = sub_006BD040(".\\DATATBLS\\DataTbls.cpp", 1735);
    gD2DataTables.pStatesTxt = (D2StatesTxt*)DATATBLS_CompileTxt(hArchive, "states", pTbl, &gD2DataTables.nStatesTxtRecordCount, sizeof(D2StatesTxt));

    D2_ASSERT(gD2DataTables.nStatesTxtRecordCount < 256, 1737);

    unsigned int nMaskSize = sizeof(unsigned int) * ((gD2DataTables.nStatesTxtRecordCount + 32 - 1) / 32);
    unsigned int nSize = 40 * nMaskSize;
    gD2DataTables.pStateMasks = (unsigned int*)FOG_AllocPool(0, nSize, ".\\DATATBLS\\DataTbls.cpp", 1742, 0);
    memset(gD2DataTables.pStateMasks, 0, nSize);

    for (int i = 0; i < 40; ++i)
    {
        gD2DataTables.fStateMasks[i] = &gD2DataTables.pStateMasks[i * (nMaskSize / sizeof(unsigned int))];
        DATATBLS_BuildStateMask(gD2DataTables.fStateMasks[i], i);
    }

    DATATBLS_BuildStateListByFlag(&gD2DataTables.pProgressiveStates, &gD2DataTables.nProgressiveStates, 4);
    DATATBLS_BuildStateListByFlag(&gD2DataTables.pCurseStates, &gD2DataTables.nCurseStates, 11);
    DATATBLS_BuildStateListByFlag(&gD2DataTables.pTransformStates, &gD2DataTables.nTransformStates, 16);
    DATATBLS_BuildStateListByFlag(&gD2DataTables.pActionStates, &gD2DataTables.nActionStates, 5);
    DATATBLS_BuildStateListByField(&gD2DataTables.pColourStates, &gD2DataTables.nColourStates, 42);
}

// 0x00618C90
void __fastcall DATATBLS_UnloadStatesTxt()
{
    if (gpStateMasks_0096BCF8)
    {
        FOG_FreePool(0, gpStateMasks_0096BCF8, ".\\DATATBLS\\DataTbls.cpp", 0x6E8, 0);
        gpStateMasks_0096BCF8 = 0;
    }
    if (gpProgressiveStates_0096BD9C)
    {
        FOG_FreePool(0, gpProgressiveStates_0096BD9C, ".\\DATATBLS\\DataTbls.cpp", 0x6ED, 0);
        gpProgressiveStates_0096BD9C = 0;
    }
    if (gpCurseStates_0096BDA4)
    {
        FOG_FreePool(0, gpCurseStates_0096BDA4, ".\\DATATBLS\\DataTbls.cpp", 0x6F2, 0);
        gpCurseStates_0096BDA4 = 0;
    }
    if (gpTransformStates_0096BDAC)
    {
        FOG_FreePool(0, gpTransformStates_0096BDAC, ".\\DATATBLS\\DataTbls.cpp", 0x6F7, 0);
        gpTransformStates_0096BDAC = 0;
    }
    if (gpActionStates_0096BDB4)
    {
        FOG_FreePool(0, gpActionStates_0096BDB4, ".\\DATATBLS\\DataTbls.cpp", 0x6FC, 0);
        gpActionStates_0096BDB4 = 0;
    }
    memset(gfStateMasks_0096BCFC, 0, sizeof(gfStateMasks_0096BCFC));
    DATATBLS_UnloadBinInline(gpStatesTxt);
    FOG_FreeLinker(gpStatesLinker_0096BCF0);
}

// 0x00618D90
void __fastcall DATATBLS_LoadPetTypeTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "pet type", 18, 0, 0, &gTxtLink_0096C81C },
        { "group", 3, 0, 8, 0 },
        { "basemax", 3, 0, 10, 0 },
        { "warp", 26, 0, 4, 0 },
        { "range", 26, 1, 4, 0 },
        { "partysend", 26, 2, 4, 0 },
        { "unsummon", 26, 3, 4, 0 },
        { "automap", 26, 4, 4, 0 },
        { "drawhp", 26, 5, 4, 0 },
        { "icontype", 4, 0, 14, 0 },
        { "baseicon", 1, 32, 15, 0 },
        { "mclass1", 3, 0, 178, 0 },
        { "micon1", 1, 32, 47, 0 },
        { "mclass2", 3, 0, 180, 0 },
        { "micon2", 1, 32, 79, 0 },
        { "mclass3", 3, 0, 182, 0 },
        { "micon3", 1, 32, 111, 0 },
        { "mclass4", 3, 0, 184, 0 },
        { "micon4", 1, 32, 143, 0 },
        { "name", 22, 0, 12, (void*)DATATBLS_GetStringIdFromReferenceString },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gTxtLink_0096C81C = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 1833);
    gpPettypeTxt = DATATBLS_CompileTxt(hArchive, "pettype", pTbl, &gnPettypeTxtRecordCount, 224);
    TBL_ASSERT(gnPettypeTxtRecordCount < 256, 1835);
    gnPettypeTxtRecordCount = gnPettypeTxtRecordCount <= 0 ? 0 : gnPettypeTxtRecordCount;
    if (gnPettypeTxtRecordCount >= 256)
    {
        gnPettypeTxtRecordCount = 256;
    }
}

// 0x00619100
void __fastcall DATATBLS_UnloadPetTypeTxt()
{
    DATATBLS_UnloadBinInline(gpPettypeTxt);
    FOG_FreeLinker(gpPettypeLinker);
}

// 0x00619140
void __stdcall DATATBLS_UnloadAllBins()
{
    DATATBLS_UnloadCompCodeAndCompileBins();
    DATATBLS_UnloadBinInline(gpCharstatsTxt);
    DATATBLS_UnloadMissilesTxt();
    DATATBLS_UnloadOverlayTxt();
    DATATBLS_UnloadSkills_SkillDescTxt();
    DATATBLS_UnloadItemStatCostTxt();
    DATATBLS_UnloadStatesTxt();
    DATATBLS_UnloadBinInline(gpPettypeTxt);
    FOG_FreeLinker(gpPettypeLinker);
    DATATBLS_UnloadItemsTxt();
    DATATBLS_UnloadPropertiesTxt();
    DATATBLS_UnloadMagicSuffix_Prefix_AutomagicTxt();
    DATATBLS_UnloadRareSuffix_PrefixTxt();
    DATATBLS_UnloadUniqueItemsTxt();
    DATATBLS_UnloadSets_SetItemsTxt();
    DATATBLS_UnloadQualityItemsTxt();
    DATATBLS_UnloadLowQualityItemsTxt();
    DATATBLS_UnloadGemsTxt();
    DATATBLS_UnloadBooksTxt();
    DATATBLS_UnloadItemRatioTxt();
    DATATBLS_UnloadGambleTxt();
    DATATBLS_UnloadItemTypesTxt();
    DATATBLS_FreeMonTypeTxt();
    DATATBLS_UnloadPlrMode_Type_MonMode_ObjMode_Type_Composit_ArmtypeTxt();
    DATATBLS_UnloadBinInline(gpExperienceTxt);
    DATATBLS_UnloadAnimDataD2(gpAnimData_0096C8A4);
    DATATBLS_UnloadSomeMonsterTxts();
    DATATBLS_UnloadLevelsTxt();
    DATATBLS_UnloadLevelDefsBin();
    DATATBLS_UnloadLevelTypesTxt();
    DATATBLS_UnloadLvlPrestTxt();
    DATATBLS_UnloadLvlWarpTxt();
    DATATBLS_UnloadLvlMazeTxt();
    DATATBLS_FreeGlobalTileLibraryHash();
    DATATBLS_UnloadLvlSubTxt();
    DATATBLS_FreeAutomap();
    DATATBLS_UnloadObjectsTxt();
    DATATBLS_UnloadObjGroupTxt();
    DATATBLS_UnloadShrinesTxt();
    sub_0065C130();
    DATATBLS_UnloadRunesTxt();
    DATATBLS_FreeCollisionFieldTable();
    DATATBLS_UnloadBeltsTxt();
    DATATBLS_UnloadMonItemPercentTxt();
    DATATBLS_UnloadArenaTxt();
    DATATBLS_UnloadCubeMainTxt();
    DATATBLS_UnloadCharTemplateTxt();
    D2COMMON_10916_Return();
    DATATBLS_UnloadBinInline(gpDifficultylevelsTxt);
}

// 0x00619300
void __stdcall DATATBLS_LoadAllTxts(void* hArchive, int a2, int a3)
{
    DATATBLS_LoadSomeTxts(hArchive);
    DATATBLS_LoadItemTypesTxt(hArchive);
    DATATBLS_LoadMonTypeTxt(hArchive);
    DATATBLS_LoadSoundsTxt(hArchive);
    DATATBLS_LoadPetTypeTxt(hArchive);
    DATATBLS_LoadOverlayTxt(hArchive);
    DATATBLS_LoadItemStatCostTxt(hArchive);
    DATATBLS_LoadPropertiesTxt(hArchive);
    DATATBLS_LoadMissilesTxt(hArchive);
    DATATBLS_LoadStatesTxt(hArchive);
    DATATBLS_LoadSkills_SkillDescTxt(hArchive);
    DATATBLS_LoadCharStatsTxt(hArchive);
    DATATBLS_LoadArenaTxt(hArchive);
    DATATBLS_LoadCharTemplateTxt(hArchive);
    DATATBLS_LoadItemsTxt(hArchive);
    DATATBLS_LoadMagicSuffix_Prefix_AutomagicTxt(hArchive);
    DATATBLS_LoadRareSuffix_PrefixTxt(hArchive);
    DATATBLS_LoadUniqueItemsTxt(hArchive);
    DATATBLS_LoadSets_SetItemsTxt(hArchive);
    DATATBLS_LoadGemsTxt(hArchive);
    DATATBLS_LoadBooksTxt(hArchive);
    DATATBLS_LoadQualityItemsTxt(hArchive);
    DATATBLS_LoadLowQualityItemsTxt(hArchive);
    DATATBLS_LoadRunesTxt(hArchive);
    DATATBLS_LoadItemRatioTxt(hArchive);
    DATATBLS_LoadGambleTxt(hArchive);
    DATATBLS_LoadPlrType_ModeTxt(hArchive);
    DATATBLS_LoadMonModeTxt(hArchive);
    DATATBLS_LoadObjType_ModeTxt(hArchive);
    DATATBLS_LoadCompositTxt(hArchive);
    DATATBLS_LoadArmTypeTxt(hArchive);
    DATATBLS_LoadExperienceTxt(hArchive);
    gD2DataTables.pAnimData = DATATBLS_LoadAnimDataD2(hArchive);
    DATATBLS_LoadSomeMonsterTxts(hArchive);
    DATATBLS_LoadLevelsTxt(hArchive);
    DATATBLS_LoadLevelDefsBin(hArchive);
    DATATBLS_LoadLevelTypesTxt(hArchive);
    if (a2)
    {
        DATATBLS_AllocGlobalTileLibraryHash(hArchive);
    }
    DATATBLS_LoadLvlPrestTxt(hArchive, a2);
    DATATBLS_LoadLvlWarpTxt(hArchive);
    DATATBLS_LoadLvlMazeTxt(hArchive);
    DATATBLS_LoadLvlSubTxt(hArchive, a2, a3);
    DATATBLS_LoadAutomapTxt(hArchive);
    DATATBLS_LoadObjectsTxt(hArchive);
    DATATBLS_LoadObjGroupTxt(hArchive);
    DATATBLS_LoadShrinesTxt(hArchive);
    DATATBLS_LoadInventoryTxt(hArchive);
    DATATBLS_LoadExpFieldD2(hArchive);
    DATATBLS_LoadBeltsTxt(hArchive);
    DATATBLS_LoadMonItemPercentTxt(hArchive);
    sub_0066A270(hArchive);
    DATATBLS_LoadCubeMainTxt(hArchive);
    DATATBLS_LoadDifficultyLevelsTxt(hArchive);
    DATATBLS_UnloadSoundsTxt();
}

// 0x00625560
int __stdcall STATLIST_GetUnitStatBonus(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer)
{
    if (!pUnit->pStatListEx)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    int nValue = STATLIST_GetTotalStatValue(pStatList, nStatId, nLayer);
    return nValue - STATLIST_GetBaseStatValue(pStatList, nStatId, nLayer);
}

#include "gen/data/Source/D2Common/DATATBLS/DataTbls.inc"
