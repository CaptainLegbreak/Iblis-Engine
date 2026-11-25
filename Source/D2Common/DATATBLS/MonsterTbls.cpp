#include "D2ItemTypes.h"

#include "D2Common.h"

#include "D2Structs.h"

#include "D2Txt.h"

#include "D2Records.h"

#include "D2Unicode.h"

#include "D2LevelTxt.h"

#include "D2DataTbls.h"

#include "D2TxtItems.h"

#include "D2TxtTables.h"

#include "D2AnimData.h"

static void __declspec(noinline) DATATBLS_MakeCode(const char* szText, char* szCode);

#pragma function(memset)

#define MONSTATSFLAGINDEX_NORATIO 2

#define ITEMTYPES_RECORD(i) (((i) >= 0 && (i) < sgptDataTables->nItemTypesTxtRecordCount) ? &((D2ItemTypesTxt*)sgptDataTables->pItemTypesTxt)[(i)] : 0)

struct D2ObjectsTxt;

struct D2ShrinesTxt;

struct D2SuperUniquesTxt;

struct D2MonStats2Txt;

struct D2BinFieldStrc;

struct D2MonStatsTxt;

struct D2MonLvlTxt;

struct D2MonStatsInitStrc;

union D2SeedStrc;

struct Unicode;

struct D2TCExInfoStrc;

struct D2TCExShortStrc;

struct D2ItemsTxt;

struct D2ItemDataTbl;

struct D2TreasureClassExTxt;

struct D2UniqueItemsTxt;

struct D2SetItemsTxt;

struct D2HirelingTxt;

struct D2MonPresetTxt;

struct D2TxtLinkStrc;

struct D2DataTablesStrc;

struct D2UnitStrc;

struct D2AnimSeqTxt;

struct D2NpcTxt;

struct D2MonSoundsTxt;

struct D2MonItemPercentTxt;

void __stdcall DATATBLS_UnloadBin(void* pBinFile); // 0x006125C0

void __fastcall DATATBLS_UnloadHirelingTxt(); // 0x006562B0

void __fastcall DATATBLS_UnloadMonPresetTxt(); // 0x00659AF0

void __fastcall DATATBLS_UnloadMonSeqTxt(); // 0x00659DE0

void __fastcall DATATBLS_FreeTreasureClassEx(); // 0x00654D50

void __cdecl DATATBLS_UnloadUniqueNameTxts(); // 0x00653E20

extern int gnObjgroupTxtRecordCount; // 0x0096D47C

D2NpcTxt* gpNpcTxt; // 0x0096C5D8

D2SuperUniquesTxt* gpSuperUniquesTxt; // 0x0096C704

int gnSuperUniquesTxtRecordCount; // 0x0096C70C

int gnMonumodTxtRecordCount; // 0x0096C884

D2MonStatsTxt* gpMonstatsTxt; // 0x0096C6A8

D2TxtLinkStrc* gpMonStatsLinker; // 0x0096C6AC

D2TxtLinkStrc* gpMonPropLinker; // 0x0096C85C

D2MonSoundsTxt* gpMonsoundsTxt; // 0x0096C6B4

D2TxtLinkStrc* gpMonSoundsLinker; // 0x0096C6B8

int gnMonsoundsTxtRecordCount; // 0x0096C6BC

unsigned short __fastcall DATATBLS_GetStringIdFromReferenceString(char* szReference); // 0x006117B0

D2TxtLinkStrc* gpMonStats2Linker; // 0x0096C6C4

D2TxtLinkStrc* gpMonTypeLinker;                                                                           // 0x0096C868

extern D2TxtLinkStrc* gpMonAiLinker; // 0x0096BCBC

extern D2TxtLinkStrc* gTxtLink_0096C798; // 0x0096C798

extern D2TxtLinkStrc* gTxtLink_0096BC4C; // 0x0096BC4C

void __fastcall DATATBLS_MonStatsSkillModeLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn); // 0x00651150

void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __cdecl DATATBLS_ComputeMonStatsDepths(); // 0x00651040

void __stdcall DATATBLS_InitMonStatsAnimSpeeds(int nRecordCount); // 0x00650F00

struct D2MonLvlTxt
{
    unsigned int dwAC[2][3];
    unsigned int dwTH[2][3];
    unsigned int dwHP[2][3];
    unsigned int dwDM[2][3];
    unsigned int dwXP[2][3];
};

struct D2MonStatsInitStrc
{
    int nMinHP;
    int nMaxHP;
    int nAC;
    int nTH;
    int nExp;
    int nA1MinD;
    int nA1MaxD;
    int nA2MinD;
    int nA2MaxD;
    int nS1MinD;
    int nS1MaxD;
    int nElMinD;
    int nElMaxD;
    int nElDur;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

extern D2UniqueNameTxt* gpUniqueNameTxtTables[4]; // 0x0096D488

extern int gnUniqueNameTxtRecordCounts[4]; // 0x0096D498

extern Unicode gwszDataTablesDefault; // 0x0096D4B4

struct D2TCExInfoStrc
{
    int nClassic;
    int nProb;
    short nItemId;
    short nTxtRow;
    unsigned char nFlags;
    char unk0x0D;
    short nMagic;
    short nRare;
    short nSet;
    short nUnique;
    short nSuperior;
    short nNormal;
    char unk0x1A[2];
};

struct D2TCExShortStrc
{
    short nGroup;
    short nLevel;
    int nTypes;
    int nClassic;
    int nProb;
    int nPicks;
    int nNoDrop;
    char unk0x18[2];
    short nQuality[6];
    char unk0x26[2];
    D2TCExInfoStrc* pInfo;
};

struct D2ItemDataTbl
{
    int nItemsTxtRecordCount;
    D2ItemsTxt* pItemsTxt;
};

typedef char check_D2ItemTypesTxt_size[sizeof(D2ItemTypesTxt) == 0xE4 ? 1 : -1];

typedef char check_D2ItemsTxt_size[sizeof(D2ItemsTxt) == 0x1A8 ? 1 : -1];

typedef char check_D2TCExInfoStrc_size[sizeof(D2TCExInfoStrc) == 0x1C ? 1 : -1];

typedef char check_D2TCExShortStrc_size[sizeof(D2TCExShortStrc) == 0x2C ? 1 : -1];

extern unsigned short gwTreasureClassItemTypes; // 0x0096D4B0

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40

int __stdcall FOG_GetStringFromLinkIndex(D2TxtLinkStrc* pLinker, int nIndex, char* szString); // 0x006BD180

extern "C" D2ItemTypesTxt* __fastcall SUNIT_GetTableRow(int index); // 0x00555C90

int __stdcall ITEMS_CheckItemTypeIdByItemId(int nItemId, int nItemType); // 0x00629A90

D2ItemDataTbl* __stdcall DATATBLS_GetItemDataTables(); // 0x00633590

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

D2TCExShortStrc* __fastcall DATATBLS_NewTreasureClassEx(const char* szTreasureClass); // 0x00653F90

__declspec(noinline) D2TCExInfoStrc* __fastcall DATATBLS_AddTreasureClassInfo(D2TCExShortStrc* pTCExShort); // 0x00654080

void __fastcall DATATBLS_UpdateTreasureClassProbabilities(D2TCExShortStrc* pTCExShort, D2TCExInfoStrc* pTCExInfo, int nProbability, int bExpansion); // 0x006540C0

extern "C" char* __cdecl strchr(const char* szString, int nChar); // 0x00687740

struct D2TreasureClassExTxt
{
    char szTreasureClass[32];
    int nPicks;
    unsigned short nGroup;
    short nLevel;
    unsigned short nQuality[6];
    int nNoDrop;
    char szItem[10][64];
    int nProb[10];
};

typedef char check_D2TreasureClassExTxt_size[sizeof(D2TreasureClassExTxt) == 0x2E0 ? 1 : -1];

typedef char check_D2SetItemsTxt_size[sizeof(D2SetItemsTxt) == 0x1B8 ? 1 : -1];

extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);

extern "C" unsigned int __cdecl strlen(const char* sz);

D2TCExShortStrc* gpTreasureClassEx; // 0x0096C5EC

extern "C" const char gszTxtField_magic[]; // 0x006DCFBC

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

D2TxtLinkStrc* gpMonUModLinker; // 0x0096C87C

void* gpMonumodTxt; // 0x0096C880

extern D2DataTablesStrc sgtDataTables; // 0x0096BC30

D2HirelingTxt* gpHirelingTxt; // 0x0096BDD0

D2TxtLinkStrc* gpMonModeLinker; // 0x0096BC5C

enum
{
    TXTFIELD_NONE = 0,
    TXTFIELD_DWORD = 2,
    TXTFIELD_WORD = 3,
    TXTFIELD_BYTE = 4,
    TXTFIELD_ASCIITOCODE = 9,
    TXTFIELD_CODETOBYTE = 13,
    TXTFIELD_NAMETOINDEX = 17,
    TXTFIELD_NAMETOWORD = 20,
    TXTFIELD_CUSTOMLINK = 23,
    TXTFIELD_BIT = 26,
};

extern "C" const char gszTxtField_Id[]; // 0x006E6850

extern "C" const char gszTxtField_Height[]; // 0x006EAA88

extern "C" const char gszTxtField_overlayHeight[]; // 0x006ED120

extern "C" const char gszTxtField_pixHeight[]; // 0x006ED114

extern "C" const char gszTxtField_SizeX[]; // 0x006E8654

extern "C" const char gszTxtField_SizeY[]; // 0x006E864C

extern "C" const char gszTxtField_spawnCol[]; // 0x006ED108

extern "C" const char gszTxtField_MeleeRng[]; // 0x006ED0FC

extern "C" const char gszTxtField_BaseW[]; // 0x006ED0F4

extern "C" const char gszTxtField_HitClass[]; // 0x006E6D10

extern "C" const char gszTxtField_HDv[]; // 0x006ED0F0

extern "C" const char gszTxtField_TRv[]; // 0x006ED0EC

extern "C" const char gszTxtField_LGv[]; // 0x006ED0E8

extern "C" const char gszTxtField_Rav[]; // 0x006ED0E4

extern "C" const char gszTxtField_Lav[]; // 0x006ED0E0

extern "C" const char gszTxtField_RHv[]; // 0x006ED0DC

extern "C" const char gszTxtField_LHv[]; // 0x006ED0D8

extern "C" const char gszTxtField_SHv[]; // 0x006ED0D4

extern "C" const char gszTxtField_S1v[]; // 0x006ED0D0

extern "C" const char gszTxtField_S2v[]; // 0x006ED0CC

extern "C" const char gszTxtField_S3v[]; // 0x006ED0C8

extern "C" const char gszTxtField_S4v[]; // 0x006ED0C4

extern "C" const char gszTxtField_S5v[]; // 0x006ED0C0

extern "C" const char gszTxtField_S6v[]; // 0x006ED0BC

extern "C" const char gszTxtField_S7v[]; // 0x006ED0B8

extern "C" const char gszTxtField_S8v[]; // 0x006ED0B4

extern "C" const char gszTxtField_HD[]; // 0x006EABFC

extern "C" const char gszTxtField_TR[]; // 0x006EABF8

extern "C" const char gszTxtField_LG[]; // 0x006EABF4

extern "C" const char gszTxtField_RA[]; // 0x006EABF0

extern "C" const char gszTxtField_LA[]; // 0x006EABEC

extern "C" const char gszTxtField_RH[]; // 0x006EABE8

extern "C" const char gszTxtField_LH[]; // 0x006EABE4

extern "C" const char gszTxtField_SH[]; // 0x006EABE0

extern "C" const char gszTxtField_S1[]; // 0x006EABDC

extern "C" const char gszTxtField_S2[]; // 0x006EABD8

extern "C" const char gszTxtField_S3[]; // 0x006EABD4

extern "C" const char gszTxtField_S4[]; // 0x006EABD0

extern "C" const char gszTxtField_S5[]; // 0x006EABCC

extern "C" const char gszTxtField_S6[]; // 0x006EABC8

extern "C" const char gszTxtField_S7[]; // 0x006EABC4

extern "C" const char gszTxtField_S8[]; // 0x006EABC0

extern "C" const char gszTxtField_TotalPieces[]; // 0x006EABB4

extern "C" const char gszTxtField_mDT[]; // 0x006ED0B0

extern "C" const char gszTxtField_mNU[]; // 0x006ED0AC

extern "C" const char gszTxtField_mWL[]; // 0x006ED0A8

extern "C" const char gszTxtField_mGH[]; // 0x006ED0A4

extern "C" const char gszTxtField_mA1[]; // 0x006ED0A0

extern "C" const char gszTxtField_mA2[]; // 0x006ED09C

extern "C" const char gszTxtField_mBL[]; // 0x006ED098

extern "C" const char gszTxtField_mSC[]; // 0x006ED094

extern "C" const char gszTxtField_mS1[]; // 0x006ED090

extern "C" const char gszTxtField_mS2[]; // 0x006ED08C

extern "C" const char gszTxtField_mS3[]; // 0x006ED088

extern "C" const char gszTxtField_mS4[]; // 0x006ED084

extern "C" const char gszTxtField_mDD[]; // 0x006ED080

extern "C" const char gszTxtField_mKB[]; // 0x006ED07C

extern "C" const char gszTxtField_mSQ[]; // 0x006ED078

extern "C" const char gszTxtField_mRN[]; // 0x006ED074

extern "C" const char gszTxtField_dDT[]; // 0x006ED070

extern "C" const char gszTxtField_dNU[]; // 0x006ED06C

extern "C" const char gszTxtField_dWL[]; // 0x006ED068

extern "C" const char gszTxtField_dGH[]; // 0x006ED064

extern "C" const char gszTxtField_dA1[]; // 0x006ED060

extern "C" const char gszTxtField_dA2[]; // 0x006ED05C

extern "C" const char gszTxtField_dBL[]; // 0x006ED058

extern "C" const char gszTxtField_dSC[]; // 0x006ED054

extern "C" const char gszTxtField_dS1[]; // 0x006ED050

extern "C" const char gszTxtField_dS2[]; // 0x006ED04C

extern "C" const char gszTxtField_dS3[]; // 0x006ED048

extern "C" const char gszTxtField_dS4[]; // 0x006ED044

extern "C" const char gszTxtField_dDD[]; // 0x006ED040

extern "C" const char gszTxtField_dKB[]; // 0x006ED03C

extern "C" const char gszTxtField_dSQ[]; // 0x006ED038

extern "C" const char gszTxtField_dRN[]; // 0x006ED034

extern "C" const char gszTxtField_A1mv[]; // 0x006ED02C

extern "C" const char gszTxtField_A2mv[]; // 0x006ED024

extern "C" const char gszTxtField_SCmv[]; // 0x006ED01C

extern "C" const char gszTxtField_S1mv[]; // 0x006ED014

extern "C" const char gszTxtField_S2mv[]; // 0x006ED00C

extern "C" const char gszTxtField_S3mv[]; // 0x006ED004

extern "C" const char gszTxtField_S4mv[]; // 0x006ECFFC

extern "C" const char gszTxtField_noGfxHitTest[]; // 0x006ECFEC

extern "C" const char gszTxtField_htTop[]; // 0x006ECFE4

extern "C" const char gszTxtField_htLeft[]; // 0x006ECFDC

extern "C" const char gszTxtField_htWidth[]; // 0x006ECFD4

extern "C" const char gszTxtField_htHeight[]; // 0x006ECFC8

extern "C" const char gszTxtField_restore[]; // 0x006ECFC0

extern "C" const char gszTxtField_automapCel[]; // 0x006ECFB4

extern "C" const char gszTxtField_noMap[]; // 0x006ECFAC

extern "C" const char gszTxtField_noOvly[]; // 0x006ECFA4

extern "C" const char gszTxtField_isSel[]; // 0x006ECF9C

extern "C" const char gszTxtField_alSel[]; // 0x006ECF94

extern "C" const char gszTxtField_noSel[]; // 0x006ECF8C

extern "C" const char gszTxtField_shiftSel[]; // 0x006ECF80

extern "C" const char gszTxtField_corpseSel[]; // 0x006ECF74

extern "C" const char gszTxtField_revive[]; // 0x006ECF6C

extern "C" const char gszTxtField_isAtt[]; // 0x006ECF64

extern "C" const char gszTxtField_large[]; // 0x006ECF5C

extern "C" const char gszTxtField_small[]; // 0x006ECF54

extern "C" const char gszTxtField_soft[]; // 0x006ECF4C

extern "C" const char gszTxtField_critter[]; // 0x006ECF44

extern "C" const char gszTxtField_inert[]; // 0x006ECF3C

extern "C" const char gszTxtField_objCol[]; // 0x006ECF34

extern "C" const char gszTxtField_deadCol[]; // 0x006ECF2C

extern "C" const char gszTxtField_unflatDead[]; // 0x006ECF20

extern "C" const char gszTxtField_shadow[]; // 0x006ECF18

extern "C" const char gszTxtField_noUniqueShift[]; // 0x006ECF08

extern "C" const char gszTxtField_compositeDeath[]; // 0x006ECEF8

extern "C" const char gszTxtField_localBlood[]; // 0x006ECEEC

extern "C" const char gszTxtField_bleed[]; // 0x006ECEE4

extern "C" const char gszTxtField_light[]; // 0x006ECEDC

extern "C" const char gszTxtField_light_r[]; // 0x006E7A7C

extern "C" const char gszTxtField_light_g[]; // 0x006E7A74

extern "C" const char gszTxtField_light_b[]; // 0x006E7A6C

extern "C" const char gszTxtField_Utrans[]; // 0x006EC9A8

extern "C" const char gszTxtField_Utrans_N_[]; // 0x006EC99C

extern "C" const char gszTxtField_Utrans_H_[]; // 0x006EC990

extern "C" const char gszTxtField_Heart[]; // 0x006ECED4

extern "C" const char gszTxtField_BodyPart[]; // 0x006ECEC8

extern "C" const char gszTxtField_InfernoLen[]; // 0x006ECEBC

extern "C" const char gszTxtField_InfernoAnim[]; // 0x006ECEB0

extern "C" const char gszTxtField_InfernoRollback[]; // 0x006ECEA0

extern "C" const char gszTxtField_ResurrectMode[]; // 0x006ECE90

extern "C" const char gszTxtField_ResurrectSkill[]; // 0x006ECE80

extern "C" const char gszMonStats2TxtName[]; // 0x006ECE74

void __fastcall DATATBLS_MonStats2CompositLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn); // 0x00657010

extern D2TxtLinkStrc* gpPropertiesLinker; // 0x0096BCD8

void* gpMonpropTxt; // 0x0096C860

int gnMonpropTxtRecordCount; // 0x0096C864

void* gpMonlvlTxt; // 0x0096C7A0

int gnMonlvlTxtRecordCount; // 0x0096C7A4

struct D2MonPresetTxt
{
    unsigned char nAct;
    unsigned char nType;
    unsigned short nPlace;
};

D2MonPresetTxt* gpMonPresetTxtActSections[5]; // 0x0096C6DC

int gnMonPresetTxtActRecordCounts[5]; // 0x0096C6F0

void __fastcall DATATBLS_MonPresetPlaceLinker(char* pSrc, D2MonPresetTxt* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn); // 0x00659990

extern D2TxtLinkStrc* gpSoundsLinker; // 0x0096BDC8

extern int gnSoundsGuard; // 0x0096C8B4

D2TxtLinkStrc* gpMonSeqLinker; // 0x0096C7AC

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

D2ObjectsTxt* gpObjectsTxt; // 0x0096D470

void* gpObjgroupTxt; // 0x0096D478

D2ShrinesTxt* gpShrinesTxt; // 0x0096D468

D2MonEquipTxt* gpMonEquipTxt; // 0x0096C810

int gnMonEquipTxtRecordCount; // 0x0096C814

D2TxtLinkStrc* gpSuperUniquesLinker; // 0x0096C708

void* gpMonTable_96C6C0; // 0x0096C6C0

#define TC_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UniqueNameTablesStrc;

typedef unsigned int size_t;

struct D2UniqueNameTablesStrc
{
    void* pTables[4];
    int nCounts[4];
};

extern D2UniqueNameTablesStrc gUniqueNameTables; // 0x0096D488

void __fastcall DATATBLS_LoadMonLvlTxt(void* hArchive); // 0x00659500

void __stdcall DATATBLS_InitTreasureClassEx(void* hArchive); // 0x0065A390

D2MonStats2Txt* __fastcall DATATBLS_LoadMonStats2Txt(void* hArchive); // 0x006571A0

void __fastcall DATATBLS_LoadMonPropTxt(void* hArchive); // 0x00658720

void __fastcall DATATBLS_LoadMonSoundsTxt(void* hArchive); // 0x00656930

void __fastcall DATATBLS_LoadMonSeqTxt(void* hArchive); // 0x00659C60

void __fastcall DATATBLS_LoadMonStatsTxt(void* hArchive); // 0x00651210

void __fastcall DATATBLS_LoadMonUModTxt(void* hArchive); // 0x00655030

void __fastcall DATATBLS_LoadSuperUniquesTxt(void* hArchive); // 0x006552E0

void __fastcall DATATBLS_LoadMonPresetTxt(void* hArchive); // 0x00659A10

void __fastcall DATATBLS_LoadHirelingTxt(void* hArchive); // 0x00655720

void __fastcall DATATBLS_LoadNpcTxt(void* hArchive); // 0x00656620

void __fastcall DATATBLS_LoadMonEquipTxt(void* hArchive); // 0x00659E60

extern D2TCExShortStrc* gpChestTreasureClasses[3][5][3]; // 0x0096C5F4

extern "C" const char* const gaszChestNames[3]; // 0x00745A10

extern "C" const char* const gaszDifficultySuffixes[3]; // 0x00745A1C

void __stdcall FOG_10216_AddRecordToLinkingTable(D2TxtLinkStrc* pLinker, const char* szKey); // 0x006BD500

void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0

void __cdecl DATATBLS_CreateItemTypeTreasureClasses(); // 0x006541C0

void __stdcall DATATBLS_CompileTreasureClassExTxt(void* hArchive); // 0x006547D0

int gnTreasureClassEx; // 0x0096C5F0

extern "C" const char gszChestTreasureClassFormat[]; // 0x006ED588

extern "C" const char gszTxtField_Name[]; // 0x006EA354

extern D2TxtLinkStrc* gpMonPlaceLinker; // 0x0096C6D0

extern "C" const char gszTxtField_Act[]; // 0x006E84D4

extern "C" const char gszTxtField_Place[]; // 0x006ED4F8

extern "C" const char gszMonPresetTxtName[]; // 0x006ED500

struct D2MonTypeTxt
{
    short nType;
    short nEquiv[3];
    char unk0x08[4];
};

D2MonTypeTxt* gpMonTypeTxt; // 0x0096C86C

extern "C" const char gszTxtField_equiv1[];                                                                 // 0x006DCD14

extern "C" const char gszTxtField_equiv2[];                                                                 // 0x006DCD0C

extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060

int gnMonTypeTxtRecordCount;                                                                                // 0x0096C870

unsigned int* gpMonTypeNest;                                                                                // 0x0096C874

int gnMonTypeIndex;                                                                                         // 0x0096C878

D2TxtLinkStrc* __stdcall FOG_AllocLinker(const char* szFile, int nLine);                                    // 0x006BD040

int __fastcall DATATBLS_CheckNestedMonsterTypes(int nMonType1, int nMonType2);

void __fastcall DATATBLS_LoadMonTypeTxt(void* hArchive);

#define FIELD_TEXT(x) (x)

#define FIXTURE_LINE(x) (x)

unsigned short __stdcall STRTABLE_FindString(const char* szKey, const wchar_t** ppText);               // 0x00524D30

D2TxtLinkStrc* gpHireDescLinker_0096BCE8;                                                                   // 0x0096BCE8

extern D2TxtLinkStrc* gpSkillsLinker_0096C7CC;                                                              // 0x0096C7CC

int __cdecl FOG_IsExpansion(); // 0x00408F20

extern "C" const char gszTxtField_version[]; // 0x006DCCF0

extern "C" const char gszTxtField_gold[]; // 0x006DCD90

extern "C" const char gszField_006D9060[]; // 0x006D9060

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), FIXTURE_LINE(line)); exit(-1); }

struct D2HirelingTableGlobals
{
    D2HirelingTxt* f_0;
    int nCount;
    int indices[2][256];
};

extern D2HirelingTableGlobals gHirelingTables;  // 0x0096BDD0

#define gpHirelingTxt (gHirelingTables.f_0)

#define gnHirelingTxtRecordCount (gHirelingTables.nCount)

#define gaHirelingIds (gHirelingTables.indices)

D2TxtLinkStrc* gpTreasureClassExLinker; // 0x0096C5E8

int gnMonstatsTxtRecordCount; // 0x0096C6B0

int gnTreasureClassItemTypes; // 0x0096D4B0

int gnNpcTxtRecordCount; // 0x0096C5DC

D2MonPresetTxt* gpMonPresetTxt; // 0x0096C6D8

void* gpSoundsTxt; // 0x0096BDC4

int gnSoundsTxtRecordCount; // 0x0096BDCC

D2AnimSeqTxt* gpMonseqTxt; // 0x0096C7A8

int gnMonseqTxtRecordCount; // 0x0096C7B0

D2AnimSeqRecordStrc* gpMonSeqTable; // 0x0096C7B4

int gnMonSeqTableRecordCount; // 0x0096C7B8

#define MON_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2MonItemPercentDataTbl;

struct D2NpcTxt
{
    unsigned int dwNpc;
    char unk[0x4C - 4];
};

struct D2MonItemPercentTxt
{
    int nValue;
};

struct D2MonItemPercentDataTbl
{
    int nMonItemPercentTxtRecordCount;
    D2MonItemPercentTxt* pMonItemPercentTxt;
};

D2MonItemPercentDataTbl gMonItemPercentDataTables; // 0x0096D480

void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, unsigned int dwCode, int bLogError);                 // 0x006BD130

D2TxtLinkStrc* gpCompCodeLinker_0096BCB0;                                                                   // 0x0096BCB0

struct D2MonEquipTxt;

struct D2MonEquipTxt
{
    short monster,level;
    char onInit;
    char unk05[3];
    unsigned int item[3];
    char location[3];
    char modifier[3];
    char unk1A[2];
};

extern void* gpItemsLinker; // 0x0096BCC4

extern void* gpBodyLocsLinker_0096BC3C; // 0x0096BC3C

extern const char gszField_level[]; // 0x006DCCBC

extern const char gszField_item3[]; // 0x006E6588

extern const char gszField_item2[]; // 0x006E659C

extern const char gszField_item1[]; // 0x006E65B0

extern const char gszField_mod3[]; // 0x006ED53C

extern const char gszField_loc3[]; // 0x006ED544

extern const char gszField_mod2[]; // 0x006ED54C

extern const char gszField_loc2[]; // 0x006ED554

extern const char gszField_mod1[]; // 0x006ED55C

extern const char gszField_loc1[]; // 0x006ED564

extern const char gszField_oninit[]; // 0x006ED56C

extern const char gszField_monster[]; // 0x006ED574

extern const char gszField_monequip[]; // 0x006ED57C

extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB

extern D2TxtLinkStrc* gpTreasureClassExLinker;                                                              // 0x0096C5E8

D2TxtLinkStrc* gpSetItemsLinker;                                                                            // 0x0096C844

void* gpSetItemsTxt;                                                                                        // 0x0096C848

extern D2TxtLinkStrc* gpUniqueItemsLinker;                                                                  // 0x0096C850

extern void* gpUniqueItemsTxt;                                                                              // 0x0096C854

static int __declspec(noinline) DATATBLS_GetNextIntToken(char** ppString, char chSeparator);

struct D2TCExRecordArgStrc
{
    D2TCExShortStrc* pRecord;
};

static int __stdcall DATATBLS_ParseTreasureClassItem(D2TCExRecordArgStrc tRecord, int nProb, char* szText); // 0x00654440

const D2AnimDataRecordStrc* __fastcall DATATBLS_GetAnimDataRecord(D2UnitStrc* pUnit, int nClassId, int nMode, int nUnitType, void* pInventory); // 0x0066A9B0
struct D2ChainRecordStrc
{
    unsigned short wId;
    unsigned short wParent;
    unsigned short wNext;
    char unk0x06[0x4A - 0x06];
    unsigned char nDepth;
    unsigned char nRoot;
    char unk0x4C[0x1A8 - 0x4C];
};

// 0x00650EB0
static void DATATBLS_MakeCode(const char* szText, char* szCode)
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

// 0x00650F00
void __stdcall DATATBLS_InitMonStatsAnimSpeeds(int nRecordCount)
{
    int i = 0;
    if (nRecordCount <= 0) return;
    do
    {
        int base = gpMonstatsTxt[i].nBaseId;
        if (base < 0 || base >= nRecordCount)
        {
            gpMonstatsTxt[i].nBaseId = i;
            base = i;
        }

        const D2AnimDataRecordStrc* pAnimDataRecord = DATATBLS_GetAnimDataRecord(0, base, 2, 1, 0);
        unsigned int speed = pAnimDataRecord->dwAnimSpeed;
        if (base != i && gpMonstatsTxt[base].nVelocity > 0)
            speed = gpMonstatsTxt[i].nVelocity * speed / gpMonstatsTxt[base].nVelocity;
        speed = speed > 0 ? speed : 0;
        gpMonstatsTxt[i].nWalkAnimSpeed = speed < 0x7FFF ? speed : 0x7FFF;

        if (i >= 410)
            speed = DATATBLS_GetAnimDataRecord(0, base, 15, 1, 0)->dwAnimSpeed;
        else
            speed = gpMonstatsTxt[base].nWalkAnimSpeed / 2;
        if (base != i && gpMonstatsTxt[base].nRun > 0)
            speed = gpMonstatsTxt[i].nRun * speed / gpMonstatsTxt[base].nRun;
        speed = speed > 0 ? speed : 0;
        gpMonstatsTxt[i].nRunAnimSpeed = speed < 0x7FFF ? speed : 0x7FFF;
        ++i;
    } while (i < nRecordCount);
}

// 0x00651040
void __cdecl DATATBLS_ComputeMonStatsDepths()
{
    for (short i = 0; i < gnMonstatsTxtRecordCount; ++i)
    {
        unsigned short nNext = ((D2ChainRecordStrc*)gpMonstatsTxt)[i].wParent;
        int nDepth = 0;
        unsigned int nId = nNext;
        // __assume: stands in for the original zero-extending the parent id twice (movzx then movzx ax)
        __assume(nId != 0x10000);
        do
        {
            if ((short)nId == i)
            {
                ((D2ChainRecordStrc*)gpMonstatsTxt)[i].nRoot = nDepth;
            }
            nNext = ((D2ChainRecordStrc*)gpMonstatsTxt)[(short)nId].wNext;
            ++nDepth;
            if ((short)nId == (short)nNext)
            {
                break;
            }
            nId = nNext;
            if (nDepth > 255)
            {
                break;
            }
        }
        while ((short)nId >= 0);
        ((D2ChainRecordStrc*)gpMonstatsTxt)[i].nDepth = nDepth;
    }
}

// 0x006510C0
int __stdcall DATATBLS_GetMonsterChainInfo(int nMonsterId, int* pMaxChainId, int* pChainId)
{
    if (nMonsterId >= 0 && nMonsterId < gnMonstatsTxtRecordCount)
    {
        if (pMaxChainId)
        {
            *pMaxChainId = gpMonstatsTxt[nMonsterId].nMaxChainId;
        }

        if (pChainId)
        {
            *pChainId = gpMonstatsTxt[nMonsterId].nChainId;
        }

        return gpMonstatsTxt[nMonsterId].nChainId;
    }

    if (pMaxChainId)
    {
        *pMaxChainId = 0;
    }

    if (pChainId)
    {
        *pChainId = 0;
    }

    return 0;
}

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

// 0x00651150
void __fastcall DATATBLS_MonStatsSkillModeLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    D2MonStatsTxt* pMonStatsTxtRecord = (D2MonStatsTxt*)pRecord;
    if (!pMonStatsTxtRecord || (unsigned int)nOffset > 7)
    {
        return;
    }

    pMonStatsTxtRecord->nSkillMode[nOffset] = 0;
    pMonStatsTxtRecord->nSkillLevel[nOffset] = -1;
    if (pMonStatsTxtRecord->nSkill[nOffset] < 0 || !pSrc)
    {
        return;
    }

    if (strlen(pSrc) <= 3)
    {
        int nText;
        unsigned int dwCode;
        strcpy((char*)&nText, pSrc);
        DATATBLS_MakeCode((const char*)&nText, (char*)&dwCode);
        const char nMode = (char)FOG_GetLinkIndex(gpMonModeLinker, dwCode, 1);
        pMonStatsTxtRecord->nSkillMode[nOffset] = nMode;
        if (nMode >= 0 && nMode != 14)
        {
            return;
        }
    }

    pMonStatsTxtRecord->nSkillMode[nOffset] = 14;
    pMonStatsTxtRecord->nSkillLevel[nOffset] = FOG_GetRowFromTxt(gpMonTableLinker_96C7AC, pSrc, 1);
}

// 0x00651210
void __fastcall DATATBLS_LoadMonStatsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Id", 17, 0, 0, &gpMonStatsLinker },
        { "BaseId", 20, 0, 2, &gpMonStatsLinker },
        { "NextInClass", 20, 0, 4, &gpMonStatsLinker },
        { "NameStr", 22, 0, 6, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "DescStr", 22, 0, 8, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "Code", 9, 0, 16, 0 },
        { "TransLvl", 4, 0, 77, 0 },
        { "MonSound", 20, 0, 20, &gpMonSoundsLinker },
        { "UMonSound", 20, 0, 22, &gpMonSoundsLinker },
        { "MonStatsEx", 20, 0, 24, &gpMonStats2Linker },
        { "MonType", 20, 0, 28, &gpMonTypeLinker },
        { "MonProp", 20, 0, 26, &gpMonPropLinker },
        { "AI", 20, 0, 30, &gpMonAiLinker },
        { "spawn", 20, 0, 32, &gpMonStatsLinker },
        { "spawnx", 4, 0, 34, 0 },
        { "spawny", 4, 0, 35, 0 },
        { "spawnmode", 13, 0, 36, &gpMonModeLinker },
        { "minion1", 20, 0, 38, &gpMonStatsLinker },
        { "minion2", 20, 0, 40, &gpMonStatsLinker },
        { "PartyMin", 4, 0, 44, 0 },
        { "PartyMax", 4, 0, 45, 0 },
        { "Rarity", 4, 0, 46, 0 },
        { "MinGrp", 4, 0, 47, 0 },
        { "MaxGrp", 4, 0, 48, 0 },
        { "sparsePopulate", 4, 0, 49, 0 },
        { "Velocity", 3, 0, 50, 0 },
        { "Run", 3, 0, 52, 0 },
        { "Align", 4, 0, 76, 0 },
        { "enabled", 26, 25, 12, 0 },
        { "rangedtype", 26, 28, 12, 0 },
        { "placespawn", 26, 23, 12, 0 },
        { "isSpawn", 26, 0, 12, 0 },
        { "isMelee", 26, 1, 12, 0 },
        { "noRatio", 26, 2, 12, 0 },
        { "SetBoss", 26, 4, 12, 0 },
        { "BossXfer", 26, 5, 12, 0 },
        { "boss", 26, 6, 12, 0 },
        { "primeevil", 26, 7, 12, 0 },
        { "opendoors", 26, 3, 12, 0 },
        { "npc", 26, 8, 12, 0 },
        { "interact", 26, 9, 12, 0 },
        { "inventory", 26, 24, 12, 0 },
        { "inTown", 26, 10, 12, 0 },
        { "lUndead", 26, 11, 12, 0 },
        { "hUndead", 26, 12, 12, 0 },
        { "demon", 26, 13, 12, 0 },
        { "flying", 26, 14, 12, 0 },
        { "killable", 26, 15, 12, 0 },
        { "switchai", 26, 16, 12, 0 },
        { "noaura", 26, 27, 12, 0 },
        { "nomultishot", 26, 17, 12, 0 },
        { "neverCount", 26, 18, 12, 0 },
        { "petIgnore", 26, 19, 12, 0 },
        { "deathDmg", 26, 20, 12, 0 },
        { "genericSpawn", 26, 21, 12, 0 },
        { "zoo", 26, 22, 12, 0 },
        { "MissA1", 20, 0, 58, &gTxtLink_0096C798 },
        { "MissA2", 20, 0, 60, &gTxtLink_0096C798 },
        { "MissS1", 20, 0, 62, &gTxtLink_0096C798 },
        { "MissS2", 20, 0, 64, &gTxtLink_0096C798 },
        { "MissS3", 20, 0, 66, &gTxtLink_0096C798 },
        { "MissS4", 20, 0, 68, &gTxtLink_0096C798 },
        { "MissC", 20, 0, 70, &gTxtLink_0096C798 },
        { "MissSQ", 20, 0, 72, &gTxtLink_0096C798 },
        { "TreasureClass1", 20, 0, 134, &gpTreasureClassExLinker },
        { "TreasureClass2", 20, 0, 136, &gpTreasureClassExLinker },
        { "TreasureClass3", 20, 0, 138, &gpTreasureClassExLinker },
        { "TreasureClass4", 20, 0, 140, &gpTreasureClassExLinker },
        { "TreasureClass1(N)", 20, 0, 142, &gpTreasureClassExLinker },
        { "TreasureClass2(N)", 20, 0, 144, &gpTreasureClassExLinker },
        { "TreasureClass3(N)", 20, 0, 146, &gpTreasureClassExLinker },
        { "TreasureClass4(N)", 20, 0, 148, &gpTreasureClassExLinker },
        { "TreasureClass1(H)", 20, 0, 150, &gpTreasureClassExLinker },
        { "TreasureClass2(H)", 20, 0, 152, &gpTreasureClassExLinker },
        { "TreasureClass3(H)", 20, 0, 154, &gpTreasureClassExLinker },
        { "TreasureClass4(H)", 20, 0, 156, &gpTreasureClassExLinker },
        { "TCQuestId", 4, 0, 158, 0 },
        { "TCQuestCP", 4, 0, 159, 0 },
        { "threat", 4, 0, 78, 0 },
        { "aidel", 4, 0, 79, 0 },
        { "aidel(N)", 4, 0, 80, 0 },
        { "aidel(H)", 4, 0, 81, 0 },
        { "aidist", 4, 0, 82, 0 },
        { "aidist(N)", 4, 0, 83, 0 },
        { "aidist(H)", 4, 0, 84, 0 },
        { "aip1", 3, 0, 86, 0 },
        { "aip1(N)", 3, 0, 88, 0 },
        { "aip1(H)", 3, 0, 90, 0 },
        { "aip2", 3, 0, 92, 0 },
        { "aip2(N)", 3, 0, 94, 0 },
        { "aip2(H)", 3, 0, 96, 0 },
        { "aip3", 3, 0, 98, 0 },
        { "aip3(N)", 3, 0, 100, 0 },
        { "aip3(H)", 3, 0, 102, 0 },
        { "aip4", 3, 0, 104, 0 },
        { "aip4(N)", 3, 0, 106, 0 },
        { "aip4(H)", 3, 0, 108, 0 },
        { "aip5", 3, 0, 110, 0 },
        { "aip5(N)", 3, 0, 112, 0 },
        { "aip5(H)", 3, 0, 114, 0 },
        { "aip6", 3, 0, 116, 0 },
        { "aip6(N)", 3, 0, 118, 0 },
        { "aip6(H)", 3, 0, 120, 0 },
        { "aip7", 3, 0, 122, 0 },
        { "aip7(N)", 3, 0, 124, 0 },
        { "aip7(H)", 3, 0, 126, 0 },
        { "aip8", 3, 0, 128, 0 },
        { "aip8(N)", 3, 0, 130, 0 },
        { "aip8(H)", 3, 0, 132, 0 },
        { "Level", 3, 0, 170, 0 },
        { "Level(N)", 3, 0, 172, 0 },
        { "Level(H)", 3, 0, 174, 0 },
        { "SkillDamage", 20, 0, 168, &gTxtLink_0096C7CC },
        { "NoShldBlock", 26, 26, 12, 0 },
        { "Drain", 4, 0, 160, 0 },
        { "Drain(N)", 4, 0, 161, 0 },
        { "Drain(H)", 4, 0, 162, 0 },
        { "ToBlock", 4, 0, 163, 0 },
        { "ToBlock(N)", 4, 0, 164, 0 },
        { "ToBlock(H)", 4, 0, 165, 0 },
        { "Crit", 4, 0, 166, 0 },
        { "MinHP", 3, 0, 176, 0 },
        { "MinHP(N)", 3, 0, 178, 0 },
        { "MinHP(H)", 3, 0, 180, 0 },
        { "MaxHP", 3, 0, 182, 0 },
        { "MaxHP(N)", 3, 0, 184, 0 },
        { "MaxHP(H)", 3, 0, 186, 0 },
        { "AC", 3, 0, 188, 0 },
        { "AC(N)", 3, 0, 190, 0 },
        { "AC(H)", 3, 0, 192, 0 },
        { "Exp", 3, 0, 212, 0 },
        { "Exp(N)", 3, 0, 214, 0 },
        { "Exp(H)", 3, 0, 216, 0 },
        { "A1TH", 3, 0, 194, 0 },
        { "A1TH(N)", 3, 0, 196, 0 },
        { "A1TH(H)", 3, 0, 198, 0 },
        { "A1MinD", 3, 0, 218, 0 },
        { "A1MinD(N)", 3, 0, 220, 0 },
        { "A1MinD(H)", 3, 0, 222, 0 },
        { "A1MaxD", 3, 0, 224, 0 },
        { "A1MaxD(N)", 3, 0, 226, 0 },
        { "A1MaxD(H)", 3, 0, 228, 0 },
        { "A2TH", 3, 0, 200, 0 },
        { "A2TH(N)", 3, 0, 202, 0 },
        { "A2TH(H)", 3, 0, 204, 0 },
        { "A2MinD", 3, 0, 230, 0 },
        { "A2MinD(N)", 3, 0, 232, 0 },
        { "A2MinD(H)", 3, 0, 234, 0 },
        { "A2MaxD", 3, 0, 236, 0 },
        { "A2MaxD(N)", 3, 0, 238, 0 },
        { "A2MaxD(H)", 3, 0, 240, 0 },
        { "S1TH", 3, 0, 206, 0 },
        { "S1TH(N)", 3, 0, 208, 0 },
        { "S1TH(H)", 3, 0, 210, 0 },
        { "S1MinD", 3, 0, 242, 0 },
        { "S1MinD(N)", 3, 0, 244, 0 },
        { "S1MinD(H)", 3, 0, 246, 0 },
        { "S1MaxD", 3, 0, 248, 0 },
        { "S1MaxD(N)", 3, 0, 250, 0 },
        { "S1MaxD(H)", 3, 0, 252, 0 },
        { "El1Mode", 13, 0, 254, &gpMonModeLinker },
        { "El1Type", 13, 0, 257, &gTxtLink_0096BC4C },
        { "El1Pct", 4, 0, 260, 0 },
        { "El1Pct(N)", 4, 0, 261, 0 },
        { "El1Pct(H)", 4, 0, 262, 0 },
        { "El1MinD", 3, 0, 270, 0 },
        { "El1MinD(N)", 3, 0, 272, 0 },
        { "El1MinD(H)", 3, 0, 274, 0 },
        { "El1MaxD", 3, 0, 288, 0 },
        { "El1MaxD(N)", 3, 0, 290, 0 },
        { "El1MaxD(H)", 3, 0, 292, 0 },
        { "El1Dur", 3, 0, 306, 0 },
        { "El1Dur(N)", 3, 0, 308, 0 },
        { "El1Dur(H)", 3, 0, 310, 0 },
        { "El2Mode", 13, 0, 255, &gpMonModeLinker },
        { "El2Type", 13, 0, 258, &gTxtLink_0096BC4C },
        { "El2Pct", 4, 0, 263, 0 },
        { "El2Pct(N)", 4, 0, 264, 0 },
        { "El2Pct(H)", 4, 0, 265, 0 },
        { "El2MinD", 3, 0, 276, 0 },
        { "El2MinD(N)", 3, 0, 278, 0 },
        { "El2MinD(H)", 3, 0, 280, 0 },
        { "El2MaxD", 3, 0, 294, 0 },
        { "El2MaxD(N)", 3, 0, 296, 0 },
        { "El2MaxD(H)", 3, 0, 298, 0 },
        { "El2Dur", 3, 0, 312, 0 },
        { "El2Dur(N)", 3, 0, 314, 0 },
        { "El2Dur(H)", 3, 0, 316, 0 },
        { "El3Mode", 13, 0, 256, &gpMonModeLinker },
        { "El3Type", 13, 0, 259, &gTxtLink_0096BC4C },
        { "El3Pct", 4, 0, 266, 0 },
        { "El3Pct(N)", 4, 0, 267, 0 },
        { "El3Pct(H)", 4, 0, 268, 0 },
        { "El3MinD", 3, 0, 282, 0 },
        { "El3MinD(N)", 3, 0, 284, 0 },
        { "El3MinD(H)", 3, 0, 286, 0 },
        { "El3MaxD", 3, 0, 300, 0 },
        { "El3MaxD(N)", 3, 0, 302, 0 },
        { "El3MaxD(H)", 3, 0, 304, 0 },
        { "El3Dur", 3, 0, 318, 0 },
        { "El3Dur(N)", 3, 0, 320, 0 },
        { "El3Dur(H)", 3, 0, 322, 0 },
        { "ColdEffect", 4, 0, 360, 0 },
        { "ColdEffect(N)", 4, 0, 361, 0 },
        { "ColdEffect(H)", 4, 0, 362, 0 },
        { "ResDm", 3, 0, 324, 0 },
        { "ResDm(N)", 3, 0, 326, 0 },
        { "ResDm(H)", 3, 0, 328, 0 },
        { "ResMa", 3, 0, 330, 0 },
        { "ResMa(N)", 3, 0, 332, 0 },
        { "ResMa(H)", 3, 0, 334, 0 },
        { "ResFi", 3, 0, 336, 0 },
        { "ResFi(N)", 3, 0, 338, 0 },
        { "ResFi(H)", 3, 0, 340, 0 },
        { "ResLi", 3, 0, 342, 0 },
        { "ResLi(N)", 3, 0, 344, 0 },
        { "ResLi(H)", 3, 0, 346, 0 },
        { "ResCo", 3, 0, 348, 0 },
        { "ResCo(N)", 3, 0, 350, 0 },
        { "ResCo(H)", 3, 0, 352, 0 },
        { "ResPo", 3, 0, 354, 0 },
        { "ResPo(N)", 3, 0, 356, 0 },
        { "ResPo(H)", 3, 0, 358, 0 },
        { "SendSkills", 8, 0, 364, 0 },
        { "Skill1", 20, 0, 368, &gTxtLink_0096C7CC },
        { "Sk1mode", 23, 0, 0, (void*)DATATBLS_MonStatsSkillModeLinker },
        { "Sk1lvl", 4, 0, 408, 0 },
        { "Skill2", 20, 0, 370, &gTxtLink_0096C7CC },
        { "Sk2mode", 23, 0, 1, (void*)DATATBLS_MonStatsSkillModeLinker },
        { "Sk2lvl", 4, 0, 409, 0 },
        { "Skill3", 20, 0, 372, &gTxtLink_0096C7CC },
        { "Sk3mode", 23, 0, 2, (void*)DATATBLS_MonStatsSkillModeLinker },
        { "Sk3lvl", 4, 0, 410, 0 },
        { "Skill4", 20, 0, 374, &gTxtLink_0096C7CC },
        { "Sk4mode", 23, 0, 3, (void*)DATATBLS_MonStatsSkillModeLinker },
        { "Sk4lvl", 4, 0, 411, 0 },
        { "Skill5", 20, 0, 376, &gTxtLink_0096C7CC },
        { "Sk5mode", 23, 0, 4, (void*)DATATBLS_MonStatsSkillModeLinker },
        { "Sk5lvl", 4, 0, 412, 0 },
        { "Skill6", 20, 0, 378, &gTxtLink_0096C7CC },
        { "Sk6mode", 23, 0, 5, (void*)DATATBLS_MonStatsSkillModeLinker },
        { "Sk6lvl", 4, 0, 413, 0 },
        { "Skill7", 20, 0, 380, &gTxtLink_0096C7CC },
        { "Sk7mode", 23, 0, 6, (void*)DATATBLS_MonStatsSkillModeLinker },
        { "Sk7lvl", 4, 0, 414, 0 },
        { "Skill8", 20, 0, 382, &gTxtLink_0096C7CC },
        { "Sk8mode", 23, 0, 7, (void*)DATATBLS_MonStatsSkillModeLinker },
        { "Sk8lvl", 4, 0, 415, 0 },
        { "DamageRegen", 2, 0, 416, 0 },
        { "SplEndDeath", 4, 0, 420, 0 },
        { "SplGetModeChart", 4, 0, 421, 0 },
        { "SplEndGeneric", 4, 0, 422, 0 },
        { "SplClientEnd", 4, 0, 423, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpMonStatsLinker = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 521);
    gpMonstatsTxt = (D2MonStatsTxt*)DATATBLS_CompileTxt(hArchive, "monstats", pTbl, &gnMonstatsTxtRecordCount, 424);
    TBL_ASSERT(gnMonstatsTxtRecordCount < 32767, 540);
    DATATBLS_ComputeMonStatsDepths();
    DATATBLS_InitMonStatsAnimSpeeds(gnMonstatsTxtRecordCount);
}

inline D2MonLvlTxt* DATATBLS_GetMonLvlTxtRecord(int nLevel)
{
    if (nLevel >= 0 && nLevel < sgptDataTables->nMonLvlTxtRecordCount)
    {
        return &sgptDataTables->pMonLvlTxt[nLevel];
    }

    return 0;
}

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x006538A0
int __stdcall DATATBLS_CalculateMonsterStatsByLevel(int nMonsterId, int nGameType, int nDifficulty, int nLevel, short nFlags, D2MonStatsInitStrc* pMonStatsInit)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    D2MonLvlTxt* pMonLvlTxtRecord = DATATBLS_GetMonLvlTxtRecord(nLevel < sgptDataTables->nMonLvlTxtRecordCount - 1 ? nLevel : sgptDataTables->nMonLvlTxtRecordCount - 1);
    if (!pMonLvlTxtRecord)
    {
        return 0;
    }

    nDifficulty = nDifficulty > 0 ? nDifficulty : 0;
    if (nDifficulty >= 2)
    {
        nDifficulty = 2;
    }

    const int bExpansion = nGameType != 0;

    if (nFlags & 1)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nMinHP = pMonStatsTxtRecord->nMinHP[nDifficulty];
            pMonStatsInit->nMaxHP = pMonStatsTxtRecord->nMaxHP[nDifficulty];
        }
        else
        {
            pMonStatsInit->nMinHP = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwHP[bExpansion][nDifficulty], pMonStatsTxtRecord->nMinHP[nDifficulty], 0x64);
            pMonStatsInit->nMaxHP = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwHP[bExpansion][nDifficulty], pMonStatsTxtRecord->nMaxHP[nDifficulty], 0x64);
        }
    }

    if (nFlags & 2)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nAC = pMonStatsTxtRecord->nAC[nDifficulty];
        }
        else
        {
            pMonStatsInit->nAC = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwAC[bExpansion][nDifficulty], pMonStatsTxtRecord->nAC[nDifficulty], 0x64);
        }
    }

    if (nFlags & 4)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nExp = pMonStatsTxtRecord->nExp[nDifficulty];
        }
        else
        {
            pMonStatsInit->nExp = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwXP[bExpansion][nDifficulty], pMonStatsTxtRecord->nExp[nDifficulty], 0x64);
        }
    }

    if (nFlags & 8)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nTH = pMonStatsTxtRecord->nA1TH[nDifficulty];
            pMonStatsInit->nA1MinD = pMonStatsTxtRecord->nA1MinD[nDifficulty];
            pMonStatsInit->nA1MaxD = pMonStatsTxtRecord->nA1MaxD[nDifficulty];
        }
        else
        {
            pMonStatsInit->nTH = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwTH[bExpansion][nDifficulty], pMonStatsTxtRecord->nA1TH[nDifficulty], 0x64);
            pMonStatsInit->nA1MinD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nA1MinD[nDifficulty], 0x64);
            pMonStatsInit->nA1MaxD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nA1MaxD[nDifficulty], 0x64);
        }
    }

    if (nFlags & 0x10)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nTH = pMonStatsTxtRecord->nA2TH[nDifficulty];
            pMonStatsInit->nA2MinD = pMonStatsTxtRecord->nA2MinD[nDifficulty];
            pMonStatsInit->nA2MaxD = pMonStatsTxtRecord->nA2MaxD[nDifficulty];
        }
        else
        {
            pMonStatsInit->nTH = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwTH[bExpansion][nDifficulty], pMonStatsTxtRecord->nA2TH[nDifficulty], 0x64);
            pMonStatsInit->nA2MinD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nA2MinD[nDifficulty], 0x64);
            pMonStatsInit->nA2MaxD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nA2MaxD[nDifficulty], 0x64);
        }
    }

    if (nFlags & 0x20)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nTH = pMonStatsTxtRecord->nS1TH[nDifficulty];
            pMonStatsInit->nS1MinD = pMonStatsTxtRecord->nS1MinD[nDifficulty];
            pMonStatsInit->nS1MaxD = pMonStatsTxtRecord->nS1MaxD[nDifficulty];
        }
        else
        {
            pMonStatsInit->nTH = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwTH[bExpansion][nDifficulty], pMonStatsTxtRecord->nS1TH[nDifficulty], 0x64);
            pMonStatsInit->nS1MinD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nS1MinD[nDifficulty], 0x64);
            pMonStatsInit->nS1MaxD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nS1MaxD[nDifficulty], 0x64);
        }
    }

    if (nFlags & 0x40)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nS1MinD = pMonStatsTxtRecord->nElMinD[0][nDifficulty];
            pMonStatsInit->nS1MaxD = pMonStatsTxtRecord->nElMaxD[0][nDifficulty];
        }
        else
        {
            pMonStatsInit->nElMinD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nElMinD[0][nDifficulty], 0x64);
            pMonStatsInit->nElMaxD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nElMaxD[0][nDifficulty], 0x64);
        }

        pMonStatsInit->nElDur = pMonStatsTxtRecord->nElDur[0][nDifficulty];
    }

    if (nFlags & 0x80)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nS1MinD = pMonStatsTxtRecord->nElMinD[1][nDifficulty];
            pMonStatsInit->nS1MaxD = pMonStatsTxtRecord->nElMaxD[1][nDifficulty];
        }
        else
        {
            pMonStatsInit->nElMinD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nElMinD[1][nDifficulty], 0x64);
            pMonStatsInit->nElMaxD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nElMaxD[1][nDifficulty], 0x64);
        }

        pMonStatsInit->nElDur = pMonStatsTxtRecord->nElDur[1][nDifficulty];
    }

    if (nFlags & 0x100)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nS1MinD = pMonStatsTxtRecord->nElMinD[2][nDifficulty];
            pMonStatsInit->nS1MaxD = pMonStatsTxtRecord->nElMaxD[2][nDifficulty];
        }
        else
        {
            pMonStatsInit->nElMinD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nElMinD[2][nDifficulty], 0x64);
            pMonStatsInit->nElMaxD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nElMaxD[2][nDifficulty], 0x64);
        }

        pMonStatsInit->nElDur = pMonStatsTxtRecord->nElDur[2][nDifficulty];
    }

    return 1;
}

// 0x00653D30
void __fastcall DATATBLS_UnloadMonStatsTxt()
{
    if (gpMonstatsTxt)
    {
        DATATBLS_UnloadBin(gpMonstatsTxt);
        FOG_FreeLinker(gpMonStatsLinker);
    }
    gpMonstatsTxt = 0;
}

// 0x00653D60
void __stdcall DATATBLS_SetVelocityInMonStatsTxtRecord(int nMonsterId, short nVelocity)
{
    MON_ASSERT(gpMonstatsTxt, 751);

    if (nMonsterId >= 0 && nMonsterId < gnMonstatsTxtRecordCount)
    {
        gpMonstatsTxt[nMonsterId].nVelocity = nVelocity;
    }
}

// 0x00653DB0
void __fastcall DATATBLS_LoadUniqueNameTxt(void* hArchive, const char* szName, unsigned int nIndex)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Name", 22, 0, 0, DATATBLS_GetStringIdFromReferenceString },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    if (nIndex <= 3)
    {
        gUniqueNameTables.pTables[nIndex] = DATATBLS_CompileTxt(hArchive, szName, pTbl, &gUniqueNameTables.nCounts[nIndex], 2);
    }
}

// 0x00653E20
void __cdecl DATATBLS_UnloadUniqueNameTxts()
{
    for (int i = 0; i < 4; ++i)
    {
        if (gUniqueNameTables.pTables[i])
        {
            DATATBLS_UnloadBin(gUniqueNameTables.pTables[i]);
            gUniqueNameTables.pTables[i] = 0;
            gUniqueNameTables.nCounts[i] = 0;
        }
    }
}

// 0x00653E50
const Unicode* __fastcall DATATBLS_RollRandomUniqueNameString(D2UnitStrc* pUnit, int nTable)
{
    if (pUnit && gnUniqueNameTxtRecordCounts[nTable] > 0)
    {
        const int nRand = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, gnUniqueNameTxtRecordCounts[nTable]);
        if (gpUniqueNameTxtTables[nTable][nRand].wStringId)
        {
            const Unicode* pString = D2LANG_GetStringFromTblIndex(gpUniqueNameTxtTables[nTable][nRand].wStringId);
            if (pString)
            {
                return pString;
            }
        }
    }
    return &gwszDataTablesDefault;
}

// 0x00653E90
const Unicode* __fastcall DATATBLS_RollRandomUniqueTitleString(D2UnitStrc* pUnit)
{
    if (pUnit && gnUniqueNameTxtRecordCounts[0] > 0)
    {
        const int nRand = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, gnUniqueNameTxtRecordCounts[0]);
        if (gpUniqueNameTxtTables[0][nRand].wStringId)
        {
            const Unicode* pString = D2LANG_GetStringFromTblIndex(gpUniqueNameTxtTables[0][nRand].wStringId);
            if (pString)
            {
                return pString;
            }
        }
    }
    return &gwszDataTablesDefault;
}

// 0x00653F90
D2TCExShortStrc* __fastcall DATATBLS_NewTreasureClassEx(const char* szTreasureClass)
{
    FOG_10216_AddRecordToLinkingTable(gpTreasureClassExLinker, szTreasureClass);

    if (!(gnTreasureClassEx % 16))
    {
        gpTreasureClassEx = (D2TCExShortStrc*)FOG_ReallocPool(0, gpTreasureClassEx, sizeof(D2TCExShortStrc) * (gnTreasureClassEx + 16), ".\\DATATBLS\\MonsterTbls.cpp", 930, 0);
    }

    memset(&gpTreasureClassEx[gnTreasureClassEx], 0, sizeof(D2TCExShortStrc));
    return &gpTreasureClassEx[gnTreasureClassEx++];
}

// 0x00654010
void __fastcall DATATBLS_ReallocTCExInfo(D2TCExShortStrc* pTCExShort, int nNewRecordCount)
{
    pTCExShort->pInfo = (D2TCExInfoStrc*)FOG_ReallocPool(0, pTCExShort->pInfo, sizeof(D2TCExInfoStrc) * nNewRecordCount, ".\\DATATBLS\\MonsterTbls.cpp", 954, 0);
    memset(&pTCExShort->pInfo[pTCExShort->nTypes], 0, sizeof(D2TCExInfoStrc) * (nNewRecordCount - pTCExShort->nTypes));
    pTCExShort->nTypes = nNewRecordCount;
}

// 0x00654080
D2TCExInfoStrc* __fastcall DATATBLS_AddTreasureClassInfo(D2TCExShortStrc* pTCExShort)
{
    const int nRecordId = pTCExShort->nTypes;

    DATATBLS_ReallocTCExInfo(pTCExShort, nRecordId + 1);
    pTCExShort->pInfo[nRecordId].nClassic = pTCExShort->nClassic;
    pTCExShort->pInfo[nRecordId].nProb = pTCExShort->nProb;
    return &pTCExShort->pInfo[nRecordId];
}

// 0x006540C0
void __fastcall DATATBLS_UpdateTreasureClassProbabilities(D2TCExShortStrc* pTCExShort, D2TCExInfoStrc* pTCExInfo, int nProbability, int bExpansion)
{
    int nIndex = pTCExInfo - pTCExShort->pInfo;
    int nCurrent;

    if (nIndex == pTCExShort->nTypes - 1)
    {
        nCurrent = pTCExShort->nProb - pTCExInfo->nProb;
    }
    else
    {
        nCurrent = pTCExShort->pInfo[nIndex + 1].nProb - pTCExInfo->nProb;
    }

    if (nCurrent != nProbability)
    {
        int nDiff = nProbability - nCurrent;
        pTCExShort->nProb += nDiff;
        for (int i = nIndex + 1; i < pTCExShort->nTypes; ++i)
        {
            pTCExShort->pInfo[i].nProb += nDiff;
        }
    }

    if (!bExpansion)
    {
        if (nIndex == pTCExShort->nTypes - 1)
        {
            nCurrent = pTCExShort->nClassic - pTCExInfo->nClassic;
        }
        else
        {
            nCurrent = pTCExShort->pInfo[nIndex + 1].nClassic - pTCExInfo->nClassic;
        }

        if (nCurrent != nProbability)
        {
            int nDiff = nProbability - nCurrent;
            pTCExShort->nClassic += nDiff;
            for (int i = nIndex + 1; i < pTCExShort->nTypes; ++i)
            {
                pTCExShort->pInfo[i].nClassic += nDiff;
            }
        }
    }
}

// 0x006541C0
void __cdecl DATATBLS_CreateItemTypeTreasureClasses()
{
    char szName[32];
    char szCode[8];

    DATATBLS_NewTreasureClassEx(&gszEmptyAssertText);
    D2ItemDataTbl* pItemDataTables = DATATBLS_GetItemDataTables();

    for (int i = 0; i < sgptDataTables->nItemTypesTxtRecordCount; ++i)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = ITEMTYPES_RECORD(i);
        if (!pItemTypesTxtRecord)
        {
            break;
        }

        if (pItemTypesTxtRecord->nTreasureClass)
        {
            ++gwTreasureClassItemTypes;

            int nLevel = 3;
            do
            {
                if (FOG_GetStringFromLinkIndex(gpItemTypesLinker, i, szCode))
                {
                    SStrPrintf(szName, sizeof(szName), "%s%d", szCode, nLevel);
                    D2TCExShortStrc* pTCExTxtRecord = DATATBLS_NewTreasureClassEx(szName);
                    if (pTCExTxtRecord)
                    {
                        pTCExTxtRecord->nPicks = 1;
                        pTCExTxtRecord->nGroup = 0;
                        pTCExTxtRecord->nLevel = nLevel - 3;

                        for (int j = 0; j < pItemDataTables->nItemsTxtRecordCount; ++j)
                        {
                            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(j);
                            if (pItemsTxtRecord && !pItemsTxtRecord->nQuest && pItemsTxtRecord->nSpawnable && ITEMS_CheckItemTypeIdByItemId(j, i)
                                && (i == 38 || !ITEMS_CheckItemTypeIdByItemId(j, ITEMTYPE_MISSILE_POTION))
                                && pItemsTxtRecord->nLevel > nLevel - 3 && pItemsTxtRecord->nLevel <= nLevel)
                            {
                                D2ItemTypesTxt* pTypeRecord = SUNIT_GetTableRow(pItemsTxtRecord->wType[0]);
                                if (pTypeRecord)
                                {
                                    const int nProbability = pTypeRecord->nRarity > 1 ? pTypeRecord->nRarity : 1;
                                    D2TCExInfoStrc* pTCExInfo = DATATBLS_AddTreasureClassInfo(pTCExTxtRecord);
                                    pTCExInfo->nItemId = j;
                                    if (pItemsTxtRecord->wVersion >= 100)
                                    {
                                        pTCExInfo->nFlags |= 0x10;
                                    }
                                    DATATBLS_UpdateTreasureClassProbabilities(pTCExTxtRecord, pTCExInfo, nProbability, pItemsTxtRecord->wVersion >= 100);
                                }
                            }
                        }
                    }
                }
                nLevel += 3;
            }
            while (nLevel <= 96);
        }
    }
}

// 0x006543C0
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

// 0x006543F0
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

// 0x00654410
static int DATATBLS_GetNextIntToken(char** ppString, char chSeparator)
{
    char* szToken = *ppString;
    *ppString = strchr(szToken, chSeparator);
    if (*ppString)
    {
        **ppString = 0;
        ++*ppString;
    }
    return atoi(szToken);
}

// 0x00654440
static int __stdcall DATATBLS_ParseTreasureClassItem(D2TCExRecordArgStrc tRecord, int nProb, char* szText)
{
    D2TCExInfoStrc* pTCExInfo;
    if (nProb <= 0)
    {
        return 0;
    }

    char* szItem = szText;
    if (*szItem == '"')
    {
        ++szItem;
    }

    for (char* szTmp = szItem; *szTmp; ++szTmp)
    {
        if (*szTmp == '"')
        {
            *szTmp = 0;
        }
    }

    char* szNext = strchr(szItem, ',');
    if (szNext)
    {
        *szNext = 0;
        ++szNext;
    }

    if (strlen(szItem) <= 4)
    {
        unsigned int dwCode;
        DATATBLS_MakeCode(szItem, (char*)&dwCode);
        int nItemId;
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(dwCode, &nItemId);
        if (pItemsTxtRecord)
        {
            pTCExInfo = DATATBLS_AddTreasureClassInfo(tRecord.pRecord);
            pTCExInfo->nItemId = nItemId;
            if (pItemsTxtRecord->wVersion >= 100)
            {
                pTCExInfo->nFlags |= 0x10;
            }
            DATATBLS_UpdateTreasureClassProbabilities(tRecord.pRecord, pTCExInfo, nProb, pItemsTxtRecord->wVersion >= 100);
            goto MODIFIERS;
        }
    }

    {
        int nIndex = FOG_GetRowFromTxt(gpTreasureClassExLinker, szItem, 0);
        if (nIndex > 0)
        {
            pTCExInfo = DATATBLS_AddTreasureClassInfo(tRecord.pRecord);
            pTCExInfo->nFlags |= 4;
            pTCExInfo->nItemId = nIndex;
            if (!gpTreasureClassEx[nIndex].nClassic)
            {
                pTCExInfo->nFlags |= 0x10;
            }
            DATATBLS_UpdateTreasureClassProbabilities(tRecord.pRecord, pTCExInfo, nProb, gpTreasureClassEx[nIndex].nClassic == 0);
        }
        else if (gpUniqueItemsLinker && (nIndex = FOG_GetRowFromTxt(gpUniqueItemsLinker, szItem, 0)) > 0)
        {
            pTCExInfo = DATATBLS_AddTreasureClassInfo(tRecord.pRecord);
            int nUniqueItemId;
            DATATBLS_GetItemRecordFromItemCode(((D2UniqueItemsTxt*)gpUniqueItemsTxt)[nIndex].dwCode, &nUniqueItemId);
            pTCExInfo->nItemId = nUniqueItemId;
            pTCExInfo->nFlags |= 0x11;
            pTCExInfo->nTxtRow = nIndex;
            DATATBLS_UpdateTreasureClassProbabilities(tRecord.pRecord, pTCExInfo, nProb, 1);
        }
        else if (gpSetItemsLinker && (nIndex = FOG_GetRowFromTxt(gpSetItemsLinker, szItem, 0)) >= 0)
        {
            pTCExInfo = DATATBLS_AddTreasureClassInfo(tRecord.pRecord);
            int nSetItemId;
            DATATBLS_GetItemRecordFromItemCode(((D2SetItemsTxt*)gpSetItemsTxt)[nIndex].dwItemCode, &nSetItemId);
            pTCExInfo->nItemId = nSetItemId;
            pTCExInfo->nFlags |= 0x12;
            pTCExInfo->nTxtRow = nIndex;
            DATATBLS_UpdateTreasureClassProbabilities(tRecord.pRecord, pTCExInfo, nProb, 1);
        }
        else
        {
            return 0;
        }
    }

MODIFIERS:
    while (szNext)
    {
        char* szKey = szNext;
        szNext = strchr(szNext, '=');
        if (!szNext)
        {
            break;
        }
        *szNext = 0;
        ++szNext;
        if (!szNext)
        {
            break;
        }

        if (!strcmp(szKey, "mul"))
        {
            char* szValue = szNext;
            szNext = strchr(szValue, ',');
            if (szNext)
            {
                *szNext = 0;
                ++szNext;
            }
            pTCExInfo->nTxtRow = atoi(szValue);
        }
        else if (!strcmp(szKey, "cu"))
        {
            char* szValue = szNext;
            szNext = strchr(szValue, ',');
            if (szNext)
            {
                *szNext = 0;
                ++szNext;
            }
            pTCExInfo->nUnique = atoi(szValue);
        }
        else if (!strcmp(szKey, "cs"))
        {
            char* szValue = szNext;
            szNext = strchr(szValue, ',');
            if (szNext)
            {
                *szNext = 0;
                ++szNext;
            }
            pTCExInfo->nSet = atoi(szValue);
        }
        else if (!strcmp(szKey, "cr"))
        {
            pTCExInfo->nRare = DATATBLS_GetNextIntToken(&szNext, ',');
        }
        else if (!strcmp(szKey, "cm"))
        {
            pTCExInfo->nMagic = DATATBLS_GetNextIntToken(&szNext, ',');
        }
        else if (!strcmp(szKey, "ce"))
        {
            pTCExInfo->nSuperior = DATATBLS_GetNextIntToken(&szNext, ',');
        }
        else if (!strcmp(szKey, "cg"))
        {
            pTCExInfo->nNormal = DATATBLS_GetNextIntToken(&szNext, ',');
        }
        else if (!strcmp(szKey, "ma") || !strcmp(szKey, "mg"))
        {
            pTCExInfo->nTxtRow = DATATBLS_GetNextIntToken(&szNext, ',');
        }
        else
        {
            break;
        }
    }

    return 1;
}

// 0x006547D0
void __stdcall DATATBLS_CompileTreasureClassExTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "treasure class", 1, 32, 0, 0 },
        { "group", 3, 0, 36, 0 },
        { "level", 3, 0, 38, 0 },
        { "picks", 2, 0, 32, 0 },
        { "unique", 3, 0, 46, 0 },
        { "set", 3, 0, 44, 0 },
        { "rare", 3, 0, 42, 0 },
        { gszTxtField_magic, 3, 0, 40, 0 },
        { "nodrop", 2, 0, 52, 0 },
        { "item1", 1, 64, 56, 0 },
        { "prob1", 2, 0, 696, 0 },
        { "item2", 1, 64, 120, 0 },
        { "prob2", 2, 0, 700, 0 },
        { "item3", 1, 64, 184, 0 },
        { "prob3", 2, 0, 704, 0 },
        { "item4", 1, 64, 248, 0 },
        { "prob4", 2, 0, 708, 0 },
        { "item5", 1, 64, 312, 0 },
        { "prob5", 2, 0, 712, 0 },
        { "item6", 1, 64, 376, 0 },
        { "prob6", 2, 0, 716, 0 },
        { "item7", 1, 64, 440, 0 },
        { "prob7", 2, 0, 720, 0 },
        { "item8", 1, 64, 504, 0 },
        { "prob8", 2, 0, 724, 0 },
        { "item9", 1, 64, 568, 0 },
        { "prob9", 2, 0, 728, 0 },
        { "item10", 1, 64, 632, 0 },
        { "prob10", 2, 0, 732, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    int nRecordCount;
    D2TreasureClassExTxt* pTreasureClassExTxt = (D2TreasureClassExTxt*)DATATBLS_CompileTxt(hArchive, "treasureclassex", pTbl, &nRecordCount, sizeof(D2TreasureClassExTxt));

    for (int i = 0; i < nRecordCount; ++i)
    {
        if (!pTreasureClassExTxt[i].szTreasureClass[0])
        {
            break;
        }

        D2TCExShortStrc* pTCExTxtRecord = DATATBLS_NewTreasureClassEx(pTreasureClassExTxt[i].szTreasureClass);
        if (pTCExTxtRecord)
        {
            if (pTreasureClassExTxt[i].nGroup)
            {
                pTCExTxtRecord->nGroup = pTreasureClassExTxt[i].nGroup + gnTreasureClassItemTypes;
            }
            pTCExTxtRecord->nLevel = pTreasureClassExTxt[i].nLevel;
            pTCExTxtRecord->nPicks = pTreasureClassExTxt[i].nPicks;
            if (!pTCExTxtRecord->nPicks)
            {
                pTCExTxtRecord->nPicks = 1;
            }
            pTCExTxtRecord->nNoDrop = pTreasureClassExTxt[i].nNoDrop;
            for (int nQuality = 0; nQuality < 6; ++nQuality)
            {
                pTCExTxtRecord->nQuality[nQuality] = pTreasureClassExTxt[i].nQuality[nQuality];
            }

            for (int nItem = 0; nItem < 10; ++nItem)
            {
                if (!pTreasureClassExTxt[i].szItem[nItem][0])
                {
                    break;
                }
                D2TCExRecordArgStrc tRecord = { pTCExTxtRecord };
                DATATBLS_ParseTreasureClassItem(tRecord, pTreasureClassExTxt[i].nProb[nItem], pTreasureClassExTxt[i].szItem[nItem]);
            }
        }
    }

    DATATBLS_UnloadBin(pTreasureClassExTxt);
}

// 0x00654D50
void __fastcall DATATBLS_FreeTreasureClassEx()
{
    FOG_FreeLinker(gpTreasureClassExLinker);

    for (int i = 0; i < gnTreasureClassEx; ++i)
    {
        if (gpTreasureClassEx[i].pInfo)
        {
            sub_0040B480(0, gpTreasureClassEx[i].pInfo, ".\\DATATBLS\\MonsterTbls.cpp", 1603, 0);
        }
    }

    sub_0040B480(0, gpTreasureClassEx, ".\\DATATBLS\\MonsterTbls.cpp", 1607, 0);
    gpTreasureClassEx = 0;
    gnTreasureClassEx = 0;
}

// 0x00654DD0
D2TCExShortStrc* __stdcall DATATBLS_GetTreasureClassExRecordFromName(char* szText)
{
    int nId = FOG_GetRowFromTxt(gpTreasureClassExLinker, szText, 0);
    if (nId >= 0)
    {
        return &gpTreasureClassEx[nId];
    }

    return 0;
}

// 0x00654E00
D2TCExShortStrc* __stdcall DATATBLS_GetTreasureClassExRecordFromIdAndLevel(unsigned short wTCId, int nLvl)
{
    D2TCExShortStrc* pTCExRecord = 0;
    D2TCExShortStrc* pNext = 0;

    if (wTCId > 0 && wTCId < gnTreasureClassEx)
    {
        pTCExRecord = &gpTreasureClassEx[wTCId];
        if (nLvl > 0 && pTCExRecord->nGroup)
        {
            pNext = pTCExRecord + 1;

            while (pNext->nGroup == pTCExRecord->nGroup)
            {
                if (pNext->nLevel > nLvl)
                {
                    break;
                }

                pTCExRecord = pNext;
                ++pNext;
            }
        }

        return pTCExRecord;
    }

    return 0;
}

// 0x00654E70
int __stdcall sub_00654E70(int a1, int a2)
{
    return 0;
}

char* __stdcall sub_M116_Emit_006543C0(char* szText, char** ppOut)
{
    ppOut[0] = DATATBLS_StripQuotes(DATATBLS_GetNextStringToken(&szText, ','));
    ppOut[1] = DATATBLS_GetNextStringToken(&szText, ',');
    return szText;
}

// 0x00654E80
D2TCExShortStrc* __stdcall DATATBLS_GetTreasureClassExRecordFromActAndDifficulty(int nDifficulty, int nAct, int nIndex)
{
    const int nDifficultyFloor = nDifficulty > 0 ? nDifficulty : 0;
    const int nDifficultyIndex = nDifficultyFloor < 2 ? nDifficultyFloor : 2;
    const int nActFloor = nAct > 0 ? nAct : 0;
    const int nActIndex = nActFloor < 4 ? nActFloor : 4;
    const int nIndexFloor = nIndex > 0 ? nIndex : 0;
    const int nChestIndex = nIndexFloor < 2 ? nIndexFloor : 2;

    return gpChestTreasureClasses[nDifficultyIndex][nActIndex][nChestIndex];
}

// 0x00654EF0
void __fastcall DATATBLS_UnloadTreasureClassExTxt()
{
    DATATBLS_FreeTreasureClassEx();
}

// 0x00654F00
void __cdecl DATATBLS_ShouldNeverCallInExpansion()
{
    D2_ASSERT(0, 0x6AE);
}

// 0x00654F20
void __fastcall DATATBLS_LoadMonItemPercentTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "HeartPercent", 4, 0, 0, 0 },
        { "BodyPartPercent", 4, 0, 1, 0 },
        { "TreasureClassPercent", 4, 0, 2, 0 },
        { "ComponentPercent", 4, 0, 3, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gMonItemPercentDataTables.pMonItemPercentTxt = (D2MonItemPercentTxt*)DATATBLS_CompileTxt(hArchive, "monitempercent", pTbl, &gMonItemPercentDataTables.nMonItemPercentTxtRecordCount, 4);
}

// 0x00654FC0
void __fastcall DATATBLS_UnloadMonItemPercentTxt()
{
    DATATBLS_UnloadBin(gMonItemPercentDataTables.pMonItemPercentTxt);
}

// 0x00654FD0
D2MonItemPercentDataTbl* __fastcall DATATBLS_GetMonItemPercentDataTables()
{
    return &gMonItemPercentDataTables;
}

// 0x00654FE0
D2MonItemPercentTxt* __stdcall DATATBLS_GetMonItemPercentTxtRecord(int nId)
{
    if (nId >= gMonItemPercentDataTables.nMonItemPercentTxtRecordCount || nId == -1)
    {
        return 0;
    }
    else
    {
        MON_ASSERT(gMonItemPercentDataTables.pMonItemPercentTxt, 1756);
        MON_ASSERT(&gMonItemPercentDataTables.pMonItemPercentTxt[nId], 1756 + 1);
        return &gMonItemPercentDataTables.pMonItemPercentTxt[nId];
    }
}

// 0x00655030
void __fastcall DATATBLS_LoadMonUModTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "uniquemod", 17, 0, 0, &gpMonUModLinker },
        { gszTxtField_version, 3, 0, 4, 0 },
        { "enabled", 4, 0, 6, 0 },
        { "xfer", 4, 0, 7, 0 },
        { "champion", 4, 0, 8, 0 },
        { "fpick", 4, 0, 9, 0 },
        { "exclude1", 20, 0, 10, &gpMonTypeLinker },
        { "exclude2", 20, 0, 12, &gpMonTypeLinker },
        { "cpick", 3, 0, 14, 0 },
        { "cpick (N)", 3, 0, 16, 0 },
        { "cpick (H)", 3, 0, 18, 0 },
        { "upick", 3, 0, 20, 0 },
        { "upick (N)", 3, 0, 22, 0 },
        { "upick (H)", 3, 0, 24, 0 },
        { "constants", 2, 0, 28, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpMonUModLinker = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 1791);
    gpMonumodTxt = DATATBLS_CompileTxt(hArchive, "monumod", pTbl, &gnMonumodTxtRecordCount, 32);
    if (gnMonumodTxtRecordCount > 256)
    {
        gnMonumodTxtRecordCount = 256;
    }
}

// 0x006552A0
void __fastcall DATATBLS_UnloadMonUModTxt()
{
    if (gpMonUModLinker)
    {
        FOG_FreeLinker(gpMonUModLinker);
        gpMonUModLinker = 0;
    }

    if (gpMonumodTxt)
    {
        DATATBLS_UnloadBin(gpMonumodTxt);
        gpMonumodTxt = 0;
    }

    gnMonumodTxtRecordCount = 0;
}

// 0x006552E0
void __fastcall DATATBLS_LoadSuperUniquesTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Superunique", 17, 0, 0, &sgtDataTables.pSuperUniquesLinker },
        { "Name", 22, 0, 2, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "Class", 19, 0, 4, &sgtDataTables.pMonStatsLinker },
        { "hcIdx", 2, 0, 8, 0 },
        { "MonSound", 19, 0, 24, &sgtDataTables.pMonSoundsLinker },
        { "Mod1", 2, 0, 12, 0 },
        { "Mod2", 2, 0, 16, 0 },
        { "Mod3", 2, 0, 20, 0 },
        { "MinGrp", 2, 0, 28, 0 },
        { "MaxGrp", 2, 0, 32, 0 },
        { "AutoPos", 4, 0, 36, 0 },
        { "EClass", 4, 0, 37, 0 },
        { "Stacks", 4, 0, 38, 0 },
        { "Replaceable", 4, 0, 39, 0 },
        { "Utrans", 4, 0, 40, 0 },
        { "Utrans(N)", 4, 0, 41, 0 },
        { "Utrans(H)", 4, 0, 42, 0 },
        { "TC", 20, 0, 44, &sgtDataTables.pTreasureClassExLinker },
        { "TC(N)", 20, 0, 46, &sgtDataTables.pTreasureClassExLinker },
        { "TC(H)", 20, 0, 48, &sgtDataTables.pTreasureClassExLinker },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    sgtDataTables.pSuperUniquesLinker = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 0x744);
    sgtDataTables.pSuperUniquesTxt = (D2SuperUniquesTxt*)DATATBLS_CompileTxt(hArchive, "superuniques", pTbl, &sgtDataTables.nSuperUniquesTxtRecordCount, sizeof(D2SuperUniquesTxt));
    if (sgtDataTables.nSuperUniquesTxtRecordCount >= 512)
    {
        sgtDataTables.nSuperUniquesTxtRecordCount = 512;
    }

    for (int i = 0; i < 66; ++i)
    {
        sgtDataTables.nSuperUniqueIds[i] = 0xFFFF;
    }

    for (int i = 0; i < sgtDataTables.nSuperUniquesTxtRecordCount; ++i)
    {
        const int nId = sgtDataTables.pSuperUniquesTxt[i].dwHcIdx;
        if (nId >= 0 && nId < 66 && sgtDataTables.nSuperUniqueIds[nId] == 0xFFFF)
        {
            sgtDataTables.nSuperUniqueIds[nId] = (unsigned short)i;
        }
    }

    for (int i = 0; i < 66; ++i)
    {
        D2_ASSERT(sgtDataTables.nSuperUniqueIds[i] != 0xFFFF, 0x782);
    }
}

// 0x006556A0
void __fastcall DATATBLS_UnloadSuperUniquesTxt()
{
    if (gpSuperUniquesLinker)
    {
        FOG_FreeLinker(gpSuperUniquesLinker);
    }

    if (gpSuperUniquesTxt)
    {
        DATATBLS_UnloadBin(gpSuperUniquesTxt);
        gpSuperUniquesTxt = 0;
    }

    gnSuperUniquesTxtRecordCount = 0;
}

// 0x006556E0
D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId)
{
    if (nSuperUniqueId >= gnSuperUniquesTxtRecordCount)
    {
        return 0;
    }

    return &gpSuperUniquesTxt[nSuperUniqueId];
}

// 0x00655710
int __fastcall DATATBLS_GetSuperUniquesTxtRecordCount()
{
    return gnSuperUniquesTxtRecordCount;
}

// 0x00655720
void __fastcall DATATBLS_LoadHirelingTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { FIELD_TEXT(gszTxtField_version), 3, 0, 0x0, 0 },
        { FIELD_TEXT("id"), 2, 0, 0x4, 0 },
        { FIELD_TEXT("class"), 2, 0, 0x8, 0 },
        { FIELD_TEXT("act"), 2, 0, 0xC, 0 },
        { FIELD_TEXT("difficulty"), 2, 0, 0x10, 0 },
        { FIELD_TEXT("seller"), 2, 0, 0x14, 0 },
        { FIELD_TEXT(gszTxtField_gold), 2, 0, 0x18, 0 },
        { FIELD_TEXT("level"), 2, 0, 0x1C, 0 },
        { FIELD_TEXT("namefirst"), 1, 32, 0xD3, 0 },
        { FIELD_TEXT("namelast"), 1, 32, 0xF3, 0 },
        { FIELD_TEXT("exp/lvl"), 2, 0, 0x20, 0 },
        { FIELD_TEXT("hp"), 2, 0, 0x24, 0 },
        { FIELD_TEXT("hp/lvl"), 2, 0, 0x28, 0 },
        { FIELD_TEXT("defense"), 2, 0, 0x2C, 0 },
        { FIELD_TEXT("def/lvl"), 2, 0, 0x30, 0 },
        { FIELD_TEXT("str"), 2, 0, 0x34, 0 },
        { FIELD_TEXT("str/lvl"), 2, 0, 0x38, 0 },
        { FIELD_TEXT("dex"), 2, 0, 0x3C, 0 },
        { FIELD_TEXT("dex/lvl"), 2, 0, 0x40, 0 },
        { FIELD_TEXT("ar"), 2, 0, 0x44, 0 },
        { FIELD_TEXT("ar/lvl"), 2, 0, 0x48, 0 },
        { FIELD_TEXT("share"), 2, 0, 0x4C, 0 },
        { FIELD_TEXT("dmg-min"), 2, 0, 0x50, 0 },
        { FIELD_TEXT("dmg-max"), 2, 0, 0x54, 0 },
        { FIELD_TEXT("dmg/lvl"), 2, 0, 0x58, 0 },
        { FIELD_TEXT("resist"), 2, 0, 0x5C, 0 },
        { FIELD_TEXT("resist/lvl"), 2, 0, 0x60, 0 },
        { FIELD_TEXT("hiredesc"), 13, 0, 0xD2, &gpHireDescLinker_0096BCE8 },
        { FIELD_TEXT("defaultchance"), 2, 0, 0x64, 0 },
        { FIELD_TEXT("skill1"), 19, 0, 0x78, &gpSkillsLinker_0096C7CC },
        { FIELD_TEXT("mode1"), 4, 0, 0xC0, 0 },
        { FIELD_TEXT("chance1"), 2, 0, 0x90, 0 },
        { FIELD_TEXT("chanceperlvl1"), 2, 0, 0xA8, 0 },
        { FIELD_TEXT("level1"), 4, 0, 0xC6, 0 },
        { FIELD_TEXT("lvlperlvl1"), 4, 0, 0xCC, 0 },
        { FIELD_TEXT("skill2"), 19, 0, 0x7C, &gpSkillsLinker_0096C7CC },
        { FIELD_TEXT("mode2"), 4, 0, 0xC1, 0 },
        { FIELD_TEXT("chance2"), 2, 0, 0x94, 0 },
        { FIELD_TEXT("chanceperlvl2"), 2, 0, 0xAC, 0 },
        { FIELD_TEXT("level2"), 4, 0, 0xC7, 0 },
        { FIELD_TEXT("lvlperlvl2"), 4, 0, 0xCD, 0 },
        { FIELD_TEXT("skill3"), 19, 0, 0x80, &gpSkillsLinker_0096C7CC },
        { FIELD_TEXT("mode3"), 4, 0, 0xC2, 0 },
        { FIELD_TEXT("chance3"), 2, 0, 0x98, 0 },
        { FIELD_TEXT("chanceperlvl3"), 2, 0, 0xB0, 0 },
        { FIELD_TEXT("level3"), 4, 0, 0xC8, 0 },
        { FIELD_TEXT("lvlperlvl3"), 4, 0, 0xCE, 0 },
        { FIELD_TEXT("skill4"), 19, 0, 0x84, &gpSkillsLinker_0096C7CC },
        { FIELD_TEXT("mode4"), 4, 0, 0xC3, 0 },
        { FIELD_TEXT("chance4"), 2, 0, 0x9C, 0 },
        { FIELD_TEXT("chanceperlvl4"), 2, 0, 0xB4, 0 },
        { FIELD_TEXT("level4"), 4, 0, 0xC9, 0 },
        { FIELD_TEXT("lvlperlvl4"), 4, 0, 0xCF, 0 },
        { FIELD_TEXT("skill5"), 19, 0, 0x88, &gpSkillsLinker_0096C7CC },
        { FIELD_TEXT("mode5"), 4, 0, 0xC4, 0 },
        { FIELD_TEXT("chance5"), 2, 0, 0xA0, 0 },
        { FIELD_TEXT("chanceperlvl5"), 2, 0, 0xB8, 0 },
        { FIELD_TEXT("level5"), 4, 0, 0xCA, 0 },
        { FIELD_TEXT("lvlperlvl5"), 4, 0, 0xD0, 0 },
        { FIELD_TEXT("skill6"), 19, 0, 0x8C, &gpSkillsLinker_0096C7CC },
        { FIELD_TEXT("mode6"), 4, 0, 0xC5, 0 },
        { FIELD_TEXT("chance6"), 2, 0, 0xA4, 0 },
        { FIELD_TEXT("chanceperlvl6"), 2, 0, 0xBC, 0 },
        { FIELD_TEXT("level6"), 4, 0, 0xCB, 0 },
        { FIELD_TEXT("lvlperlvl6"), 4, 0, 0xD1, 0 },
        { FIELD_TEXT("head"), 2, 0, 0x68, 0 },
        { FIELD_TEXT("torso"), 2, 0, 0x6C, 0 },
        { FIELD_TEXT("weapon"), 2, 0, 0x70, 0 },
        { FIELD_TEXT("shield"), 2, 0, 0x74, 0 },
        { FIELD_TEXT(gszField_006D9060), 0, 0, 0x0, 0 },
    };
    gpHirelingTxt = (D2HirelingTxt*)DATATBLS_CompileTxt(hArchive, FIELD_TEXT("hireling"), pTbl, &gnHirelingTxtRecordCount, sizeof(D2HirelingTxt));
    for (int i = 0; i < 256; ++i)
    {
        gaHirelingIds[0][i] = -1;
        gaHirelingIds[1][i] = -1;
    }
    const int bExpansion = FOG_IsExpansion();
    for (int i = 0; i < gnHirelingTxtRecordCount; ++i)
    {
        const wchar_t* pUnicode = 0;
        gpHirelingTxt[i].wNameFirst = STRTABLE_FindString(gpHirelingTxt[i].szNameFirst, &pUnicode);
        gpHirelingTxt[i].wNameLast = STRTABLE_FindString(gpHirelingTxt[i].szNameLast, &pUnicode);
        if (bExpansion)
        {
            D2_ASSERT(gpHirelingTxt[i].wNameFirst > 0, 0x816);
            D2_ASSERT(gpHirelingTxt[i].wNameLast > gpHirelingTxt[i].wNameFirst, 0x817);
            D2_ASSERT(gpHirelingTxt[i].nId < 256, 0x818);
        }
        if (gpHirelingTxt[i].nId < 256)
        {
            const int nVersion = gpHirelingTxt[i].wVersion >= 100;
            if (gaHirelingIds[nVersion][gpHirelingTxt[i].nId] < 0)
                gaHirelingIds[nVersion][gpHirelingTxt[i].nId] = i;
        }
    }
}

// 0x006562B0
void __fastcall DATATBLS_UnloadHirelingTxt()
{
    DATATBLS_UnloadBin(gpHirelingTxt);
    gnHirelingTxtRecordCount = 0;

    for (int i = 0; i < 256; ++i)
    {
        gaHirelingIds[0][i] = -1;
        gaHirelingIds[1][i] = -1;
    }
}

// 0x006562F0
D2HirelingTxt* __stdcall DATATBLS_GetHirelingTxtRecordFromIdAndLevel(int bExpansion, int nId, int nLevel)
{
    D2HirelingTxt* pResult = 0;
    if (nId >= 256)
    {
        return 0;
    }

    const unsigned short nVersion = bExpansion ? 100 : 0;
    const int nIndex = gaHirelingIds[bExpansion != 0][nId];
    if (nIndex < 0)
    {
        return 0;
    }

    for (int i = nIndex; i < gnHirelingTxtRecordCount; ++i)
    {
        D2HirelingTxt* pRecord = &gpHirelingTxt[i];
        if (pRecord->nId == nId && pRecord->wVersion == nVersion)
        {
            if (!pResult)
            {
                pResult = pRecord;
            }
            else if (pRecord->nHirelingLevel <= nLevel)
            {
                pResult = pRecord;
            }
            else
            {
                return pResult;
            }
        }
        else if (pRecord->nId > nId)
        {
            return pResult;
        }
    }

    return pResult;
}

// 0x00656390
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromNameId(int bExpansion, unsigned short nNameId, D2HirelingTxt* pOldRecord)
{
    D2HirelingTxt* pHirelingTxtRecord = 0;
    const unsigned short nVersion = bExpansion != 0 ? 100 : 0;
    int nRecordId = 0;

    if (pOldRecord)
    {
        nRecordId = pOldRecord - gpHirelingTxt + 1;
    }

    for (int i = nRecordId; i < gnHirelingTxtRecordCount; ++i)
    {
        if (gpHirelingTxt[i].wNameFirst <= nNameId && gpHirelingTxt[i].wNameLast >= nNameId && gpHirelingTxt[i].wVersion == nVersion)
        {
            pHirelingTxtRecord = &gpHirelingTxt[i];
            break;
        }
    }

    return pHirelingTxtRecord;
}

// 0x00656440
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromClassId(int bExpansion, int nClass, D2HirelingTxt* pOldRecord)
{
    D2HirelingTxt* pHirelingTxtRecord = 0;
    const unsigned short nVersion = bExpansion != 0 ? 100 : 0;
    int nRecordId = 0;

    if (pOldRecord)
    {
        nRecordId = pOldRecord - gpHirelingTxt + 1;
    }

    for (int i = nRecordId; i < gnHirelingTxtRecordCount; ++i)
    {
        if (gpHirelingTxt[i].dwClass == nClass && gpHirelingTxt[i].wVersion == nVersion)
        {
            pHirelingTxtRecord = &gpHirelingTxt[i];
            break;
        }
    }

    return pHirelingTxtRecord;
}

// 0x006564D0
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromVendorIdAndDifficulty(int bExpansion, int nVendorId, int nDifficulty, D2HirelingTxt* pOldRecord)
{
    D2HirelingTxt* pHirelingTxtRecord = 0;
    const unsigned short nVersion = bExpansion != 0 ? 100 : 0;
    int nRecordId = 0;

    if (pOldRecord)
    {
        nRecordId = pOldRecord - gpHirelingTxt + 1;
    }

    const int nDifficultyId = nDifficulty + 1;
    for (int i = nRecordId; i < gnHirelingTxtRecordCount; ++i)
    {
        if (gpHirelingTxt[i].dwSeller == nVendorId && gpHirelingTxt[i].dwDifficulty == nDifficultyId && gpHirelingTxt[i].wVersion == nVersion)
        {
            pHirelingTxtRecord = &gpHirelingTxt[i];
            break;
        }
    }

    return pHirelingTxtRecord;
}

// 0x00656580
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromActAndDifficulty(int bExpansion, int nAct, int nDifficulty, D2HirelingTxt* pOldRecord)
{
    ++nAct;
    ++nDifficulty;

    D2HirelingTxt* pHirelingTxtRecord = 0;
    const unsigned short nVersion = bExpansion != 0 ? 100 : 0;
    int nRecordId = 0;
    int nLevel = 0;

    if (pOldRecord)
    {
        nRecordId = pOldRecord - gpHirelingTxt + 1;
        nLevel = pOldRecord->nHirelingLevel;
    }

    for (int i = nRecordId; i < gnHirelingTxtRecordCount; ++i)
    {
        pHirelingTxtRecord = &gpHirelingTxt[i];
        if (pHirelingTxtRecord->dwAct == nAct && pHirelingTxtRecord->dwDifficulty == nDifficulty && pHirelingTxtRecord->wVersion == nVersion && (!nLevel || pHirelingTxtRecord->nHirelingLevel == nLevel))
        {
            return pHirelingTxtRecord;
        }
    }

    return 0;
}

// 0x00656620
void __fastcall DATATBLS_LoadNpcTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "npc", 19, 0, 0, &gpMonStatsLinker },
        { "sell mult", 2, 0, 4, 0 },
        { "buy mult", 2, 0, 8, 0 },
        { "rep mult", 2, 0, 12, 0 },
        { "questflag A", 2, 0, 16, 0 },
        { "questflag B", 2, 0, 20, 0 },
        { "questflag C", 2, 0, 24, 0 },
        { "questsellmult A", 2, 0, 28, 0 },
        { "questsellmult B", 2, 0, 32, 0 },
        { "questsellmult C", 2, 0, 36, 0 },
        { "questbuymult A", 2, 0, 40, 0 },
        { "questbuymult B", 2, 0, 44, 0 },
        { "questbuymult C", 2, 0, 48, 0 },
        { "questrepmult A", 2, 0, 52, 0 },
        { "questrepmult B", 2, 0, 56, 0 },
        { "questrepmult C", 2, 0, 60, 0 },
        { "max buy", 2, 0, 64, 0 },
        { "max buy (N)", 2, 0, 68, 0 },
        { "max buy (H)", 2, 0, 72, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpNpcTxt = (D2NpcTxt*)DATATBLS_CompileTxt(hArchive, "npc", pTbl, &gnNpcTxtRecordCount, 76);
}

// 0x006568F0
void __fastcall DATATBLS_UnloadNpcTxt()
{
    DATATBLS_UnloadBin(gpNpcTxt);
}

// 0x00656900
D2NpcTxt* __stdcall DATATBLS_GetNpcTxtRecord(unsigned int dwNpcId)
{
    for (int i = 0; i < gnNpcTxtRecordCount; ++i)
    {
        D2NpcTxt* pNpcTxtRecord = &gpNpcTxt[i];
        if (pNpcTxtRecord->dwNpc == dwNpcId)
        {
            return pNpcTxtRecord;
        }
    }

    return 0;
}

// 0x00656930
void __fastcall DATATBLS_LoadMonSoundsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Id", 17, 0, 0, &gpMonSoundsLinker },
        { "Attack1", 19, 0, 4, &gpSoundsLinker },
        { "Att1Del", 2, 0, 8, 0 },
        { "Att1Prb", 2, 0, 12, 0 },
        { "Attack2", 19, 0, 28, &gpSoundsLinker },
        { "Att2Del", 2, 0, 32, 0 },
        { "Att2Prb", 2, 0, 36, 0 },
        { "Weapon1", 19, 0, 16, &gpSoundsLinker },
        { "Wea1Del", 2, 0, 20, 0 },
        { "Wea1Vol", 2, 0, 24, 0 },
        { "Weapon2", 19, 0, 40, &gpSoundsLinker },
        { "Wea2Del", 2, 0, 44, 0 },
        { "Wea2Vol", 2, 0, 48, 0 },
        { "HitSound", 19, 0, 52, &gpSoundsLinker },
        { "HitDelay", 2, 0, 56, 0 },
        { "DeathSound", 19, 0, 60, &gpSoundsLinker },
        { "DeaDelay", 2, 0, 64, 0 },
        { "Skill1", 19, 0, 68, &gpSoundsLinker },
        { "Skill2", 19, 0, 72, &gpSoundsLinker },
        { "Skill3", 19, 0, 76, &gpSoundsLinker },
        { "Skill4", 19, 0, 80, &gpSoundsLinker },
        { "Footstep", 19, 0, 84, &gpSoundsLinker },
        { "FootstepLayer", 19, 0, 88, &gpSoundsLinker },
        { "FsCnt", 2, 0, 92, 0 },
        { "FsOff", 2, 0, 96, 0 },
        { "FsPrb", 2, 0, 100, 0 },
        { "Neutral", 19, 0, 104, &gpSoundsLinker },
        { "NeuTime", 2, 0, 108, 0 },
        { "Init", 19, 0, 112, &gpSoundsLinker },
        { "Taunt", 19, 0, 116, &gpSoundsLinker },
        { "Flee", 19, 0, 120, &gpSoundsLinker },
        { "CvtMo1", 13, 0, 124, &gpMonModeLinker },
        { "CvtMo2", 13, 0, 132, &gpMonModeLinker },
        { "CvtMo3", 13, 0, 140, &gpMonModeLinker },
        { "CvtSk1", 19, 0, 128, &gTxtLink_0096C7CC },
        { "CvtSk2", 19, 0, 136, &gTxtLink_0096C7CC },
        { "CvtSk3", 19, 0, 144, &gTxtLink_0096C7CC },
        { "CvtTgt1", 13, 0, 125, &gpMonModeLinker },
        { "CvtTgt2", 13, 0, 133, &gpMonModeLinker },
        { "CvtTgt3", 13, 0, 141, &gpMonModeLinker },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpMonSoundsLinker = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 2415);
    gpMonsoundsTxt = (D2MonSoundsTxt*)DATATBLS_CompileTxt(hArchive, "monsounds", pTbl, &gnMonsoundsTxtRecordCount, 148);
}

// 0x00656F60
void __fastcall DATATBLS_UnloadMonSoundsTxt()
{
    if (gpMonsoundsTxt)
    {
        DATATBLS_UnloadBin(gpMonsoundsTxt);
        FOG_FreeLinker(gpMonSoundsLinker);
        gnMonsoundsTxtRecordCount = 0;
    }
}

// 0x00656F90
D2MonSoundsTxt* __stdcall DATATBLS_GetMonSoundsTxtRecordFromSoundId(int nSoundId)
{
    if (gpMonsoundsTxt && nSoundId >= 0 && nSoundId < gnMonsoundsTxtRecordCount)
    {
        return &gpMonsoundsTxt[nSoundId];
    }

    return 0;
}

// 0x00656FC0
D2MonSoundsTxt* __stdcall DATATBLS_GetMonSoundsTxtRecordFromMonsterId(int nMonsterId)
{
    if (gpMonsoundsTxt && gpMonstatsTxt && nMonsterId < gnMonstatsTxtRecordCount)
    {
        int nSoundId = gpMonstatsTxt[nMonsterId].wMonSound;
        if (nSoundId >= 0 && nSoundId < gnMonsoundsTxtRecordCount)
        {
            return &gpMonsoundsTxt[nSoundId];
        }
    }

    return 0;
}

static void DATATBLS_MakeCompCode(const char* szText, char* szCode)
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

#pragma intrinsic(memset)

// 0x00657010
void __fastcall DATATBLS_MonStats2CompositLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    D2MonStats2Txt* pMonStats2TxtRecord = (D2MonStats2Txt*)pRecord;
    char szCode[4];

    if (!pMonStats2TxtRecord || (unsigned int)nOffset > 15)
    {
        return;
    }

    pMonStats2TxtRecord->nComponentChoiceCounts[nOffset] = 0;
    memset(pMonStats2TxtRecord->pComponents[nOffset].nComposit, -1, sizeof(pMonStats2TxtRecord->pComponents[nOffset].nComposit));

    if (!pSrc)
    {
        return;
    }

    char* pNext = pSrc;
    if (*pSrc == '"')
    {
        pNext = pSrc + 1;
    }

    for (char* pTmp = pNext; *pTmp; ++pTmp)
    {
        if (*pTmp == '"')
        {
            *pTmp = 0;
        }
    }

    int nCounter = 0;
    do
    {
        char* szToken = pNext;
        pNext = strchr(pNext, ',');
        if (pNext)
        {
            *pNext = 0;
            ++pNext;
        }

        if (!szToken || !*szToken || strlen(szToken) > 4)
        {
            break;
        }

        DATATBLS_MakeCompCode(szToken, szCode);
        pMonStats2TxtRecord->pComponents[nOffset].nComposit[nCounter] = (unsigned char)FOG_GetLinkIndex(gpCompCodeLinker_0096BCB0, *(unsigned int*)szCode, 1);
        ++nCounter;
    }
    while (pNext && nCounter < 12);

    pMonStats2TxtRecord->nComponentChoiceCounts[nOffset] = (unsigned char)nCounter;

    if (nOffset == 15)
    {
        int nTotal = 0;
        for (int i = 0; i < 16; ++i)
        {
            if (pMonStats2TxtRecord->nComponentChoiceCounts[i] > 1)
            {
                nTotal += pMonStats2TxtRecord->nComponentChoiceCounts[i] - 1;
            }
        }

        if (nTotal > 254)
        {
            nTotal = 254;
        }

        pMonStats2TxtRecord->nExtraComponentChoices = (unsigned char)nTotal;
    }
}

// 0x006571A0
D2MonStats2Txt* __fastcall DATATBLS_LoadMonStats2Txt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { gszTxtField_Id, TXTFIELD_NAMETOINDEX, 0, 0, &sgtDataTables.pMonStats2Linker },
        { gszTxtField_Height, TXTFIELD_BYTE, 0, 11, 0 },
        { gszTxtField_overlayHeight, TXTFIELD_BYTE, 0, 12, 0 },
        { gszTxtField_pixHeight, TXTFIELD_BYTE, 0, 13, 0 },
        { gszTxtField_SizeX, TXTFIELD_BYTE, 0, 8, 0 },
        { gszTxtField_SizeY, TXTFIELD_BYTE, 0, 9, 0 },
        { gszTxtField_spawnCol, TXTFIELD_BYTE, 0, 10, 0 },
        { gszTxtField_MeleeRng, TXTFIELD_BYTE, 0, 14, 0 },
        { gszTxtField_BaseW, TXTFIELD_ASCIITOCODE, 0, 16, 0 },
        { gszTxtField_HitClass, TXTFIELD_BYTE, 0, 20, 0 },
        { gszTxtField_HDv, TXTFIELD_CUSTOMLINK, 0, 0, (void*)DATATBLS_MonStats2CompositLinker },
        { gszTxtField_TRv, TXTFIELD_CUSTOMLINK, 0, 1, (void*)DATATBLS_MonStats2CompositLinker },
        { gszTxtField_LGv, TXTFIELD_CUSTOMLINK, 0, 2, (void*)DATATBLS_MonStats2CompositLinker },
        { gszTxtField_Rav, TXTFIELD_CUSTOMLINK, 0, 3, (void*)DATATBLS_MonStats2CompositLinker },
        { gszTxtField_Lav, TXTFIELD_CUSTOMLINK, 0, 4, (void*)DATATBLS_MonStats2CompositLinker },
        { gszTxtField_RHv, TXTFIELD_CUSTOMLINK, 0, 5, (void*)DATATBLS_MonStats2CompositLinker },
        { gszTxtField_LHv, TXTFIELD_CUSTOMLINK, 0, 6, (void*)DATATBLS_MonStats2CompositLinker },
        { gszTxtField_SHv, TXTFIELD_CUSTOMLINK, 0, 7, (void*)DATATBLS_MonStats2CompositLinker },
        { gszTxtField_S1v, TXTFIELD_CUSTOMLINK, 0, 8, (void*)DATATBLS_MonStats2CompositLinker },
        { gszTxtField_S2v, TXTFIELD_CUSTOMLINK, 0, 9, (void*)DATATBLS_MonStats2CompositLinker },
        { gszTxtField_S3v, TXTFIELD_CUSTOMLINK, 0, 10, (void*)DATATBLS_MonStats2CompositLinker },
        { gszTxtField_S4v, TXTFIELD_CUSTOMLINK, 0, 11, (void*)DATATBLS_MonStats2CompositLinker },
        { gszTxtField_S5v, TXTFIELD_CUSTOMLINK, 0, 12, (void*)DATATBLS_MonStats2CompositLinker },
        { gszTxtField_S6v, TXTFIELD_CUSTOMLINK, 0, 13, (void*)DATATBLS_MonStats2CompositLinker },
        { gszTxtField_S7v, TXTFIELD_CUSTOMLINK, 0, 14, (void*)DATATBLS_MonStats2CompositLinker },
        { gszTxtField_S8v, TXTFIELD_CUSTOMLINK, 0, 15, (void*)DATATBLS_MonStats2CompositLinker },
        { gszTxtField_HD, TXTFIELD_BIT, 0, 232, 0 },
        { gszTxtField_TR, TXTFIELD_BIT, 1, 232, 0 },
        { gszTxtField_LG, TXTFIELD_BIT, 2, 232, 0 },
        { gszTxtField_RA, TXTFIELD_BIT, 3, 232, 0 },
        { gszTxtField_LA, TXTFIELD_BIT, 4, 232, 0 },
        { gszTxtField_RH, TXTFIELD_BIT, 5, 232, 0 },
        { gszTxtField_LH, TXTFIELD_BIT, 6, 232, 0 },
        { gszTxtField_SH, TXTFIELD_BIT, 7, 232, 0 },
        { gszTxtField_S1, TXTFIELD_BIT, 8, 232, 0 },
        { gszTxtField_S2, TXTFIELD_BIT, 9, 232, 0 },
        { gszTxtField_S3, TXTFIELD_BIT, 10, 232, 0 },
        { gszTxtField_S4, TXTFIELD_BIT, 11, 232, 0 },
        { gszTxtField_S5, TXTFIELD_BIT, 12, 232, 0 },
        { gszTxtField_S6, TXTFIELD_BIT, 13, 232, 0 },
        { gszTxtField_S7, TXTFIELD_BIT, 14, 232, 0 },
        { gszTxtField_S8, TXTFIELD_BIT, 15, 232, 0 },
        { gszTxtField_TotalPieces, TXTFIELD_BYTE, 0, 236, 0 },
        { gszTxtField_mDT, TXTFIELD_BIT, 0, 240, 0 },
        { gszTxtField_mNU, TXTFIELD_BIT, 1, 240, 0 },
        { gszTxtField_mWL, TXTFIELD_BIT, 2, 240, 0 },
        { gszTxtField_mGH, TXTFIELD_BIT, 3, 240, 0 },
        { gszTxtField_mA1, TXTFIELD_BIT, 4, 240, 0 },
        { gszTxtField_mA2, TXTFIELD_BIT, 5, 240, 0 },
        { gszTxtField_mBL, TXTFIELD_BIT, 6, 240, 0 },
        { gszTxtField_mSC, TXTFIELD_BIT, 7, 240, 0 },
        { gszTxtField_mS1, TXTFIELD_BIT, 8, 240, 0 },
        { gszTxtField_mS2, TXTFIELD_BIT, 9, 240, 0 },
        { gszTxtField_mS3, TXTFIELD_BIT, 10, 240, 0 },
        { gszTxtField_mS4, TXTFIELD_BIT, 11, 240, 0 },
        { gszTxtField_mDD, TXTFIELD_BIT, 12, 240, 0 },
        { gszTxtField_mKB, TXTFIELD_BIT, 13, 240, 0 },
        { gszTxtField_mSQ, TXTFIELD_BIT, 14, 240, 0 },
        { gszTxtField_mRN, TXTFIELD_BIT, 15, 240, 0 },
        { gszTxtField_dDT, TXTFIELD_BYTE, 0, 244, 0 },
        { gszTxtField_dNU, TXTFIELD_BYTE, 0, 245, 0 },
        { gszTxtField_dWL, TXTFIELD_BYTE, 0, 246, 0 },
        { gszTxtField_dGH, TXTFIELD_BYTE, 0, 247, 0 },
        { gszTxtField_dA1, TXTFIELD_BYTE, 0, 248, 0 },
        { gszTxtField_dA2, TXTFIELD_BYTE, 0, 249, 0 },
        { gszTxtField_dBL, TXTFIELD_BYTE, 0, 250, 0 },
        { gszTxtField_dSC, TXTFIELD_BYTE, 0, 251, 0 },
        { gszTxtField_dS1, TXTFIELD_BYTE, 0, 252, 0 },
        { gszTxtField_dS2, TXTFIELD_BYTE, 0, 253, 0 },
        { gszTxtField_dS3, TXTFIELD_BYTE, 0, 254, 0 },
        { gszTxtField_dS4, TXTFIELD_BYTE, 0, 255, 0 },
        { gszTxtField_dDD, TXTFIELD_BYTE, 0, 256, 0 },
        { gszTxtField_dKB, TXTFIELD_BYTE, 0, 257, 0 },
        { gszTxtField_dSQ, TXTFIELD_BYTE, 0, 258, 0 },
        { gszTxtField_dRN, TXTFIELD_BYTE, 0, 259, 0 },
        { gszTxtField_A1mv, TXTFIELD_BIT, 4, 260, 0 },
        { gszTxtField_A2mv, TXTFIELD_BIT, 5, 260, 0 },
        { gszTxtField_SCmv, TXTFIELD_BIT, 7, 260, 0 },
        { gszTxtField_S1mv, TXTFIELD_BIT, 8, 260, 0 },
        { gszTxtField_S2mv, TXTFIELD_BIT, 9, 260, 0 },
        { gszTxtField_S3mv, TXTFIELD_BIT, 10, 260, 0 },
        { gszTxtField_S4mv, TXTFIELD_BIT, 11, 260, 0 },
        { gszTxtField_noGfxHitTest, TXTFIELD_BIT, 0, 4, 0 },
        { gszTxtField_htTop, TXTFIELD_WORD, 0, 270, 0 },
        { gszTxtField_htLeft, TXTFIELD_WORD, 0, 272, 0 },
        { gszTxtField_htWidth, TXTFIELD_WORD, 0, 274, 0 },
        { gszTxtField_htHeight, TXTFIELD_WORD, 0, 276, 0 },
        { gszTxtField_restore, TXTFIELD_BYTE, 0, 304, 0 },
        { gszTxtField_automapCel, TXTFIELD_DWORD, 0, 280, 0 },
        { gszTxtField_noMap, TXTFIELD_BIT, 1, 4, 0 },
        { gszTxtField_noOvly, TXTFIELD_BIT, 2, 4, 0 },
        { gszTxtField_isSel, TXTFIELD_BIT, 3, 4, 0 },
        { gszTxtField_alSel, TXTFIELD_BIT, 4, 4, 0 },
        { gszTxtField_noSel, TXTFIELD_BIT, 5, 4, 0 },
        { gszTxtField_shiftSel, TXTFIELD_BIT, 6, 4, 0 },
        { gszTxtField_corpseSel, TXTFIELD_BIT, 7, 4, 0 },
        { gszTxtField_revive, TXTFIELD_BIT, 8, 4, 0 },
        { gszTxtField_isAtt, TXTFIELD_BIT, 9, 4, 0 },
        { gszTxtField_large, TXTFIELD_BIT, 11, 4, 0 },
        { gszTxtField_small, TXTFIELD_BIT, 10, 4, 0 },
        { gszTxtField_soft, TXTFIELD_BIT, 12, 4, 0 },
        { gszTxtField_critter, TXTFIELD_BIT, 13, 4, 0 },
        { gszTxtField_inert, TXTFIELD_BIT, 17, 4, 0 },
        { gszTxtField_objCol, TXTFIELD_BIT, 18, 4, 0 },
        { gszTxtField_deadCol, TXTFIELD_BIT, 19, 4, 0 },
        { gszTxtField_unflatDead, TXTFIELD_BIT, 20, 4, 0 },
        { gszTxtField_shadow, TXTFIELD_BIT, 14, 4, 0 },
        { gszTxtField_noUniqueShift, TXTFIELD_BIT, 15, 4, 0 },
        { gszTxtField_compositeDeath, TXTFIELD_BIT, 16, 4, 0 },
        { gszTxtField_localBlood, TXTFIELD_BYTE, 0, 284, 0 },
        { gszTxtField_bleed, TXTFIELD_BYTE, 0, 285, 0 },
        { gszTxtField_light, TXTFIELD_BYTE, 0, 286, 0 },
        { gszTxtField_light_r, TXTFIELD_BYTE, 0, 287, 0 },
        { gszTxtField_light_g, TXTFIELD_BYTE, 0, 288, 0 },
        { gszTxtField_light_b, TXTFIELD_BYTE, 0, 289, 0 },
        { gszTxtField_Utrans, TXTFIELD_BYTE, 0, 290, 0 },
        { gszTxtField_Utrans_N_, TXTFIELD_BYTE, 0, 291, 0 },
        { gszTxtField_Utrans_H_, TXTFIELD_BYTE, 0, 292, 0 },
        { gszTxtField_Heart, TXTFIELD_ASCIITOCODE, 0, 296, 0 },
        { gszTxtField_BodyPart, TXTFIELD_ASCIITOCODE, 0, 300, 0 },
        { gszTxtField_InfernoLen, TXTFIELD_BYTE, 0, 264, 0 },
        { gszTxtField_InfernoAnim, TXTFIELD_BYTE, 0, 265, 0 },
        { gszTxtField_InfernoRollback, TXTFIELD_BYTE, 0, 266, 0 },
        { gszTxtField_ResurrectMode, TXTFIELD_CODETOBYTE, 0, 267, &sgtDataTables.pMonModeLinker },
        { gszTxtField_ResurrectSkill, TXTFIELD_NAMETOWORD, 0, 268, &sgtDataTables.pSkillsLinker },
        { gszTxtField_end, TXTFIELD_NONE, 0, 0, 0 },
    };

    sgtDataTables.pMonStats2Linker = FOG_AllocLinker(gszMonsterTblsSourceFile, 2705);
    return sgtDataTables.pMonStats2Txt = (D2MonStats2Txt*)DATATBLS_CompileTxt(hArchive, gszMonStats2TxtName, pTbl, &sgtDataTables.nMonStats2TxtRecordCount, 308);
}

// 0x00658440
void __fastcall DATATBLS_UnloadMonTypeTxt()
{
    if (gpMonTable_96C6C0)
    {
        DATATBLS_UnloadBin(gpMonTable_96C6C0);
        FOG_FreeLinker(gpMonStats2Linker);
    }
}

// 0x0065A2C0
void __cdecl DATATBLS_InitChestTreasureClasses()
{
    char szName[0x100];

    for (int nDifficulty = 0; nDifficulty < 3; ++nDifficulty)
    {
        for (int nAct = 0; nAct < 5; ++nAct)
        {
            for (int i = 0; i < 3; ++i)
            {
                SStrPrintf(szName, sizeof(szName), "Act %d%s Chest %s", nAct + 1, gaszDifficultySuffixes[nDifficulty], gaszChestNames[i]);

                const int nId = FOG_GetRowFromTxt(gpTreasureClassExLinker, szName, 0);
                gpChestTreasureClasses[nDifficulty][nAct][i] = nId >= 0 ? &gpTreasureClassEx[nId] : 0;
            }
        }
    }
}

// 0x0065A390
void __stdcall DATATBLS_InitTreasureClassEx(void* hArchive)
{
    gpTreasureClassExLinker = sub_006BD040(".\\DATATBLS\\MonsterTbls.cpp", 1550);
    DATATBLS_CreateItemTypeTreasureClasses();
    DATATBLS_CompileTreasureClassExTxt(hArchive);
    DATATBLS_InitChestTreasureClasses();
    TC_ASSERT(gnTreasureClassEx < 0xFFFF, 1558);
}

// 0x0065A3F0
void __fastcall DATATBLS_LoadTreasureClassExTxt(void* hArchive)
{
    DATATBLS_InitTreasureClassEx(hArchive);
}

// 0x00658460
int __fastcall DATATBLS_CheckNestedMonsterTypes(int nMonType1, int nMonType2)
{
    int nParentMonsterTypes[128];

    if (nMonType2 <= 0)
    {
        return 0;
    }

    if (nMonType1 <= 0 || nMonType1 >= gnMonTypeTxtRecordCount)
    {
        return 0;
    }

    nParentMonsterTypes[0] = nMonType1;
    int nIndex = 1;
    do
    {
        int nMonsterType = nParentMonsterTypes[--nIndex];
        if (nMonType2 == nMonsterType)
        {
            return 1;
        }

        if (nMonsterType >= gnMonTypeTxtRecordCount || nIndex > 124)
        {
            break;
        }

        D2MonTypeTxt* pMonTypeTxtRecord = &gpMonTypeTxt[nMonsterType];
        if (pMonTypeTxtRecord->nEquiv[0] > 0)
        {
            nParentMonsterTypes[nIndex++] = pMonTypeTxtRecord->nEquiv[0];
            if (pMonTypeTxtRecord->nEquiv[1])
            {
                nParentMonsterTypes[nIndex++] = pMonTypeTxtRecord->nEquiv[1];
                if (pMonTypeTxtRecord->nEquiv[2])
                {
                    nParentMonsterTypes[nIndex++] = pMonTypeTxtRecord->nEquiv[2];
                }
            }
        }
    }
    while (nIndex);

    return 0;
}

// 0x00658520
void __fastcall DATATBLS_LoadMonTypeTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "type", 17, 0, 0, &gpMonTypeLinker },
        { gszTxtField_equiv1, 20, 0, 2, &gpMonTypeLinker },
        { gszTxtField_equiv2, 20, 0, 4, &gpMonTypeLinker },
        { "equiv3", 20, 0, 6, &gpMonTypeLinker },
        { "strsing", 22, 0, 8, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "strplur", 22, 0, 10, (void*)DATATBLS_GetStringIdFromReferenceString },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpMonTypeLinker = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 2806);
    gpMonTypeTxt = (D2MonTypeTxt*)DATATBLS_CompileTxt(hArchive, "montype", pTbl, &gnMonTypeTxtRecordCount, 12);

    gnMonTypeIndex = (gnMonTypeTxtRecordCount + 31) / 32;
    const int nCount = gnMonTypeIndex * gnMonTypeTxtRecordCount;
    gpMonTypeNest = (unsigned int*)FOG_AllocPool(0, nCount * sizeof(unsigned int), ".\\DATATBLS\\MonsterTbls.cpp", 2812, 0);
    memset(gpMonTypeNest, 0, nCount * sizeof(unsigned int));

    for (int i = 0; i < gnMonTypeTxtRecordCount; ++i)
    {
        unsigned int* pMonTypeNest = &gpMonTypeNest[gnMonTypeIndex * i];
        for (int j = 0; j < gnMonTypeTxtRecordCount; ++j)
        {
            if (DATATBLS_CheckNestedMonsterTypes(i, j))
            {
                pMonTypeNest[j >> 5] |= gdwBitMasks[j & 31];
            }
        }
    }
}

// 0x006586D0
void __fastcall DATATBLS_FreeMonTypeTxt()
{
    if (gpMonTypeTxt)
    {
        DATATBLS_UnloadBin(gpMonTypeTxt);
        FOG_FreeLinker(gpMonTypeLinker);
        sub_0040B480(0, gpMonTypeNest, ".\\DATATBLS\\MonsterTbls.cpp", 2838, 0);
        gpMonTypeTxt = 0;
        gpMonTypeLinker = 0;
    }
}

// 0x00658720
void __fastcall DATATBLS_LoadMonPropTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Id", 18, 0, 0, &gpMonPropLinker },
        { "prop1", 19, 0, 4, &gpPropertiesLinker },
        { "par1", 2, 0, 8, 0 },
        { "chance1", 4, 0, 292, 0 },
        { "min1", 2, 0, 12, 0 },
        { "max1", 2, 0, 16, 0 },
        { "prop2", 19, 0, 20, &gpPropertiesLinker },
        { "chance2", 4, 0, 293, 0 },
        { "par2", 2, 0, 24, 0 },
        { "min2", 2, 0, 28, 0 },
        { "max2", 2, 0, 32, 0 },
        { "prop3", 19, 0, 36, &gpPropertiesLinker },
        { "chance3", 4, 0, 294, 0 },
        { "par3", 2, 0, 40, 0 },
        { "min3", 2, 0, 44, 0 },
        { "max3", 2, 0, 48, 0 },
        { "prop4", 19, 0, 52, &gpPropertiesLinker },
        { "chance4", 4, 0, 295, 0 },
        { "par4", 2, 0, 56, 0 },
        { "min4", 2, 0, 60, 0 },
        { "max4", 2, 0, 64, 0 },
        { "prop5", 19, 0, 68, &gpPropertiesLinker },
        { "chance5", 4, 0, 296, 0 },
        { "par5", 2, 0, 72, 0 },
        { "min5", 2, 0, 76, 0 },
        { "max5", 2, 0, 80, 0 },
        { "prop6", 19, 0, 84, &gpPropertiesLinker },
        { "chance6", 4, 0, 297, 0 },
        { "par6", 2, 0, 88, 0 },
        { "min6", 2, 0, 92, 0 },
        { "max6", 2, 0, 96, 0 },
        { "prop1 (N)", 19, 0, 100, &gpPropertiesLinker },
        { "chance1 (N)", 4, 0, 298, 0 },
        { "par1 (N)", 2, 0, 104, 0 },
        { "min1 (N)", 2, 0, 108, 0 },
        { "max1 (N)", 2, 0, 112, 0 },
        { "prop2 (N)", 19, 0, 116, &gpPropertiesLinker },
        { "chance2 (N)", 4, 0, 299, 0 },
        { "par2 (N)", 2, 0, 120, 0 },
        { "min2 (N)", 2, 0, 124, 0 },
        { "max2 (N)", 2, 0, 128, 0 },
        { "prop3 (N)", 19, 0, 132, &gpPropertiesLinker },
        { "chance3 (N)", 4, 0, 300, 0 },
        { "par3 (N)", 2, 0, 136, 0 },
        { "min3 (N)", 2, 0, 140, 0 },
        { "max3 (N)", 2, 0, 144, 0 },
        { "prop4 (N)", 19, 0, 148, &gpPropertiesLinker },
        { "chance4 (N)", 4, 0, 301, 0 },
        { "par4 (N)", 2, 0, 152, 0 },
        { "min4 (N)", 2, 0, 156, 0 },
        { "max4 (N)", 2, 0, 160, 0 },
        { "prop5 (N)", 19, 0, 164, &gpPropertiesLinker },
        { "chance5 (N)", 4, 0, 302, 0 },
        { "par5 (N)", 2, 0, 168, 0 },
        { "min5 (N)", 2, 0, 172, 0 },
        { "max5 (N)", 2, 0, 176, 0 },
        { "prop6 (N)", 19, 0, 180, &gpPropertiesLinker },
        { "chance6 (N)", 4, 0, 303, 0 },
        { "par6 (N)", 2, 0, 184, 0 },
        { "min6 (N)", 2, 0, 188, 0 },
        { "max6 (N)", 2, 0, 192, 0 },
        { "prop1 (H)", 19, 0, 196, &gpPropertiesLinker },
        { "chance1 (H)", 4, 0, 304, 0 },
        { "par1 (H)", 2, 0, 200, 0 },
        { "min1 (H)", 2, 0, 204, 0 },
        { "max1 (H)", 2, 0, 208, 0 },
        { "prop2 (H)", 19, 0, 212, &gpPropertiesLinker },
        { "chance2 (H)", 4, 0, 305, 0 },
        { "par2 (H)", 2, 0, 216, 0 },
        { "min2 (H)", 2, 0, 220, 0 },
        { "max2 (H)", 2, 0, 224, 0 },
        { "prop3 (H)", 19, 0, 228, &gpPropertiesLinker },
        { "chance3 (H)", 4, 0, 306, 0 },
        { "par3 (H)", 2, 0, 232, 0 },
        { "min3 (H)", 2, 0, 236, 0 },
        { "max3 (H)", 2, 0, 240, 0 },
        { "prop4 (H)", 19, 0, 244, &gpPropertiesLinker },
        { "chance4 (H)", 4, 0, 307, 0 },
        { "par4 (H)", 2, 0, 248, 0 },
        { "min4 (H)", 2, 0, 252, 0 },
        { "max4 (H)", 2, 0, 256, 0 },
        { "prop5 (H)", 19, 0, 260, &gpPropertiesLinker },
        { "chance5 (H)", 4, 0, 308, 0 },
        { "par5 (H)", 2, 0, 264, 0 },
        { "min5 (H)", 2, 0, 268, 0 },
        { "max5 (H)", 2, 0, 272, 0 },
        { "prop6 (H)", 19, 0, 276, &gpPropertiesLinker },
        { "chance6 (H)", 4, 0, 309, 0 },
        { "par6 (H)", 2, 0, 280, 0 },
        { "min6 (H)", 2, 0, 284, 0 },
        { "max6 (H)", 2, 0, 288, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpMonPropLinker = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 2953);
    gpMonpropTxt = DATATBLS_CompileTxt(hArchive, "monprop", pTbl, &gnMonpropTxtRecordCount, 312);
}

// 0x006594D0
void __fastcall DATATBLS_UnloadMonPropTxt()
{
    if (gpMonpropTxt)
    {
        DATATBLS_UnloadBin(gpMonpropTxt);
        FOG_FreeLinker(gpMonPropLinker);
    }
    gnMonpropTxtRecordCount = 0;
}

// 0x00659500
void __fastcall DATATBLS_LoadMonLvlTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "AC", 2, 0, 0, 0 },
        { "AC(N)", 2, 0, 4, 0 },
        { "AC(H)", 2, 0, 8, 0 },
        { "TH", 2, 0, 24, 0 },
        { "TH(N)", 2, 0, 28, 0 },
        { "TH(H)", 2, 0, 32, 0 },
        { "HP", 2, 0, 48, 0 },
        { "HP(N)", 2, 0, 52, 0 },
        { "HP(H)", 2, 0, 56, 0 },
        { "DM", 2, 0, 72, 0 },
        { "DM(N)", 2, 0, 76, 0 },
        { "DM(H)", 2, 0, 80, 0 },
        { "XP", 2, 0, 96, 0 },
        { "XP(N)", 2, 0, 100, 0 },
        { "XP(H)", 2, 0, 104, 0 },
        { "L-AC", 2, 0, 12, 0 },
        { "L-AC(N)", 2, 0, 16, 0 },
        { "L-AC(H)", 2, 0, 20, 0 },
        { "L-TH", 2, 0, 36, 0 },
        { "L-TH(N)", 2, 0, 40, 0 },
        { "L-TH(H)", 2, 0, 44, 0 },
        { "L-HP", 2, 0, 60, 0 },
        { "L-HP(N)", 2, 0, 64, 0 },
        { "L-HP(H)", 2, 0, 68, 0 },
        { "L-DM", 2, 0, 84, 0 },
        { "L-DM(N)", 2, 0, 88, 0 },
        { "L-DM(H)", 2, 0, 92, 0 },
        { "L-XP", 2, 0, 108, 0 },
        { "L-XP(N)", 2, 0, 112, 0 },
        { "L-XP(H)", 2, 0, 116, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpMonlvlTxt = DATATBLS_CompileTxt(hArchive, "monlvl", pTbl, &gnMonlvlTxtRecordCount, 120);
}

// 0x00659970
void __fastcall DATATBLS_UnloadMonLvlTxt()
{
    if (gpMonlvlTxt)
    {
        DATATBLS_UnloadBin(gpMonlvlTxt);
        gnMonlvlTxtRecordCount = 0;
    }
}

// 0x00659990
void __fastcall DATATBLS_MonPresetPlaceLinker(char* pSrc, D2MonPresetTxt* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    int nRow = 0;

    if (pRecord)
    {
        pRecord->nType = 0;
        pRecord->nPlace = 0;

        if (pSrc && *pSrc)
        {
            nRow = FOG_GetRowFromTxt(gpSuperUniquesLinker, pSrc, 0);
            if (nRow >= 0)
            {
                pRecord->nType = 2;
                pRecord->nPlace = nRow;
                return;
            }

            nRow = FOG_GetRowFromTxt(gpMonStatsLinker, pSrc, 0);
            if (nRow >= 0)
            {
                pRecord->nType = 1;
                pRecord->nPlace = nRow;
                return;
            }

            nRow = FOG_GetRowFromTxt(gpMonPlaceLinker, pSrc, 1);
            if (nRow >= 0)
            {
                pRecord->nType = 0;
                pRecord->nPlace = nRow;
            }
        }
    }
}

// 0x00659A10
void __fastcall DATATBLS_LoadMonPresetTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Act", 4, 0, 0, 0 },
        { "Place", 0x17, 0, 0, (void*)DATATBLS_MonPresetPlaceLinker },
        { gszTxtField_end, 0, 0, 0, 0 },
    };
    int nRecordCount = 0;

    D2MonPresetTxt* pMonPresetTxt = (D2MonPresetTxt*)DATATBLS_CompileTxt(hArchive, "monpreset", pTbl, &nRecordCount, sizeof(D2MonPresetTxt));

    gpMonPresetTxt = pMonPresetTxt;
    D2MonPresetTxt* pRecord = pMonPresetTxt;
    gpMonPresetTxtActSections[0] = pMonPresetTxt;

    int nAct = 0;
    int nActRecords = 0;
    for (int i = 0; i < nRecordCount; ++i, ++pRecord)
    {
        while (pRecord->nAct > nAct + 1)
        {
            gnMonPresetTxtActRecordCounts[nAct] = nActRecords;
            ++nAct;
            nActRecords = 0;
            gpMonPresetTxtActSections[nAct] = pRecord;
        }

        ++nActRecords;
    }

    gnMonPresetTxtActRecordCounts[nAct] = nActRecords;
}

// 0x00659AF0
void __fastcall DATATBLS_UnloadMonPresetTxt()
{
    if (gpMonPresetTxt)
    {
        DATATBLS_UnloadBin(gpMonPresetTxt);
    }

    for (int i = 0; i < 5; ++i)
    {
        gpMonPresetTxtActSections[i] = 0;
        gnMonPresetTxtActRecordCounts[i] = 0;
    }
}

// 0x00659B40
void* __stdcall DATATBLS_GetMonPresetTxtActSection(int nAct, int* pRecordCount)
{
    if (pRecordCount)
    {
        if (nAct >= 0 && nAct < 5 && gpMonPresetTxt)
        {
            *pRecordCount = gnMonPresetTxtActRecordCounts[nAct];
            return gpMonPresetTxtActSections[nAct];
        }

        *pRecordCount = 0;
    }

    return 0;
}

// 0x00659B80
int __stdcall DATATBLS_MapSuperUniqueId(int nType, int nSuperUnique)
{
    switch (nType)
    {
    case 0:
        nSuperUnique += gnSuperUniquesTxtRecordCount;
    case 2:
        nSuperUnique += sgptDataTables->nMonStatsTxtRecordCount;
        break;
    }

    return nSuperUnique;
}

// 0x00659BB0
void __fastcall DATATBLS_LoadSoundsTxt(void* hArchive)
{
    if (gnSoundsGuard)
    {
        D2BinFieldStrc pTbl[] =
        {
            { "Sound", 17, 0, 0, &gpSoundsLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };

        gpSoundsLinker = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 3225);
        gpSoundsTxt = DATATBLS_CompileTxt(hArchive, "sounds", pTbl, &gnSoundsTxtRecordCount, 2);
    }
}

// 0x00659C30
void __fastcall DATATBLS_UnloadSoundsTxt()
{
    if (gpSoundsTxt)
    {
        DATATBLS_UnloadBin(gpSoundsTxt);
        FOG_FreeLinker(gpSoundsLinker);
        gnSoundsTxtRecordCount = 0;
    }
}

static inline D2MonStatsTxt* GetMonStatsRecord(int monster)
{
 if(monster>=0 && monster<sgptDataTables->nMonStatsTxtRecordCount)return &gpMonstatsTxt[monster];
 return 0;
}

// 0x00659C60
void __fastcall DATATBLS_LoadMonSeqTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "sequence", 17, 0, 0, &gpMonSeqLinker },
        { "mode", 13, 0, 2, &gpMonModeLinker },
        { "frame", 4, 0, 3, 0 },
        { "dir", 4, 0, 4, 0 },
        { "event", 4, 0, 5, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpMonSeqLinker = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 3267);
    gpMonseqTxt = (D2AnimSeqTxt*)DATATBLS_CompileTxt(hArchive, "monseq", pTbl, &gnMonseqTxtRecordCount, 6);

    if (gnMonseqTxtRecordCount > 0)
    {
        gnMonSeqTableRecordCount = gpMonseqTxt[gnMonseqTxtRecordCount - 1].wSequence + 1;
        gpMonSeqTable = (D2AnimSeqRecordStrc*)FOG_AllocPool(0, sizeof(D2AnimSeqRecordStrc) * gnMonSeqTableRecordCount, ".\\DATATBLS\\MonsterTbls.cpp", 3276, 0);
        memset(gpMonSeqTable, 0, sizeof(D2AnimSeqRecordStrc) * gnMonSeqTableRecordCount);

        for (int i = 0; i < gnMonseqTxtRecordCount; ++i)
        {
            int nSequence = gpMonseqTxt[i].wSequence;
            if (!gpMonSeqTable[nSequence].pAnimSeqTxtRecord)
            {
                gpMonSeqTable[nSequence].pAnimSeqTxtRecord = &gpMonseqTxt[i];
            }

            ++gpMonSeqTable[nSequence].nSeqFramesCount;
            ++gpMonSeqTable[nSequence].nFramesCount;
        }
    }
}

// 0x00659DE0
void __fastcall DATATBLS_UnloadMonSeqTxt()
{
    if (gpMonseqTxt)
    {
        DATATBLS_UnloadBin(gpMonseqTxt);
        FOG_FreeLinker(gpMonSeqLinker);
        gnMonseqTxtRecordCount = 0;
    }

    if (gpMonSeqTable)
    {
        sub_0040B480(0, gpMonSeqTable, ".\\DATATBLS\\MonsterTbls.cpp", 3306, 0);
        gnMonSeqTableRecordCount = 0;
    }
}

// 0x00659E30
D2AnimSeqRecordStrc* __stdcall DATATBLS_GetMonSeqTableRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < gnMonSeqTableRecordCount)
    {
        return &gpMonSeqTable[nIndex];
    }

    return 0;
}

// 0x00659E60
void __fastcall DATATBLS_LoadMonEquipTxt(void* archive)
{
 D2BinFieldStrc fields[]={
 {gszField_monster,20,0,0,&gpMonStatsLinker},
 {gszField_level,3,0,2,0},
 {gszField_oninit,4,0,4,0},
 {gszField_item1,9,0,8,&gpItemsLinker},
 {gszField_loc1,13,0,20,&gpBodyLocsLinker_0096BC3C},
 {gszField_mod1,4,0,23,0},
 {gszField_item2,9,0,12,&gpItemsLinker},
 {gszField_loc2,13,0,21,&gpBodyLocsLinker_0096BC3C},
 {gszField_mod2,4,0,24,0},
 {gszField_item3,9,0,16,&gpItemsLinker},
 {gszField_loc3,13,0,22,&gpBodyLocsLinker_0096BC3C},
 {gszField_mod3,4,0,25,0},
 {gszTxtField_end,0,0,0,0}};
 gpMonEquipTxt=(D2MonEquipTxt*)DATATBLS_CompileTxt(archive,gszField_monequip,fields,&gnMonEquipTxtRecordCount,sizeof(D2MonEquipTxt));
 if(gnMonEquipTxtRecordCount>=32767){
  FOG_DisplayHalt(&gszEmptyAssertText,sub_00408090(),3356);exit(-1);
 }
 for(int i=0;i<sgptDataTables->nMonStatsTxtRecordCount;++i)gpMonstatsTxt[i].nMonEquipTxtRecordId=-1;
 for(int i=0;i<gnMonEquipTxtRecordCount;++i){
  D2MonEquipTxt* equip=&gpMonEquipTxt[i];
  if(equip->monster>=0 && equip->monster<sgptDataTables->nMonStatsTxtRecordCount){
   if(gpMonstatsTxt[equip->monster].nMonEquipTxtRecordId<0)gpMonstatsTxt[equip->monster].nMonEquipTxtRecordId=(short)i;
   char* location=equip->location;
   unsigned int* item=equip->item;
   int remaining=3;
   do {
    if (*location<=0 || *location>=11)
    {
        *location=0;
    }
    else if (*item!=0x20202020 && FOG_GetLinkIndex(sgptDataTables->pItemsLinker,*item,1)<0)
    {
        *location=0;
    }
    ++item;
    ++location;
   } while(--remaining);
  }
 }
}

// 0x0065A170
void __fastcall DATATBLS_UnloadMonEquipTxt()
{
    if (gpMonEquipTxt)
    {
        DATATBLS_UnloadBin(gpMonEquipTxt);
        gnMonEquipTxtRecordCount = 0;
    }
}

// 0x0065A400
void __fastcall DATATBLS_LoadSomeMonsterTxts(void* hArchive)
{
    {
        D2BinFieldStrc pTbl[] =
        {
            { "Name", 22, 0, 0, (void*)DATATBLS_GetStringIdFromReferenceString },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gUniqueNameTables.pTables[0] = DATATBLS_CompileTxt(hArchive, "uniquetitle", pTbl, &gUniqueNameTables.nCounts[0], 2);
    }

    {
        D2BinFieldStrc pTbl[] =
        {
            { "Name", 22, 0, 0, (void*)DATATBLS_GetStringIdFromReferenceString },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gUniqueNameTables.pTables[1] = DATATBLS_CompileTxt(hArchive, "uniqueprefix", pTbl, &gUniqueNameTables.nCounts[1], 2);
    }

    {
        D2BinFieldStrc pTbl[] =
        {
            { "Name", 22, 0, 0, (void*)DATATBLS_GetStringIdFromReferenceString },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gUniqueNameTables.pTables[2] = DATATBLS_CompileTxt(hArchive, "uniquesuffix", pTbl, &gUniqueNameTables.nCounts[2], 2);
    }

    {
        D2BinFieldStrc pTbl[] =
        {
            { "Name", 22, 0, 0, (void*)DATATBLS_GetStringIdFromReferenceString },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gUniqueNameTables.pTables[3] = DATATBLS_CompileTxt(hArchive, "uniqueappellation", pTbl, &gUniqueNameTables.nCounts[3], 2);
    }

    DATATBLS_LoadMonLvlTxt(hArchive);
    DATATBLS_InitTreasureClassEx(hArchive);
    DATATBLS_LoadMonStats2Txt(hArchive);
    DATATBLS_LoadMonPropTxt(hArchive);
    DATATBLS_LoadMonSoundsTxt(hArchive);
    DATATBLS_LoadMonSeqTxt(hArchive);
    DATATBLS_LoadMonStatsTxt(hArchive);
    DATATBLS_LoadMonUModTxt(hArchive);
    DATATBLS_LoadSuperUniquesTxt(hArchive);
    DATATBLS_LoadMonPresetTxt(hArchive);
    DATATBLS_LoadHirelingTxt(hArchive);
    DATATBLS_LoadNpcTxt(hArchive);
    DATATBLS_LoadMonEquipTxt(hArchive);
}

// 0x0065A190
void __fastcall DATATBLS_UnloadSomeMonsterTxts()
{
    if (gpMonEquipTxt)
    {
        DATATBLS_UnloadBin(gpMonEquipTxt);
        gnMonEquipTxtRecordCount = 0;
    }

    DATATBLS_UnloadBin(gpNpcTxt);

    DATATBLS_UnloadHirelingTxt();
    DATATBLS_UnloadMonPresetTxt();

    if (gpSuperUniquesLinker)
    {
        FOG_FreeLinker(gpSuperUniquesLinker);
    }
    if (gpSuperUniquesTxt)
    {
        DATATBLS_UnloadBin(gpSuperUniquesTxt);
        gpSuperUniquesTxt = 0;
    }
    gnSuperUniquesTxtRecordCount = 0;

    if (gpMonUModLinker)
    {
        FOG_FreeLinker(gpMonUModLinker);
        gpMonUModLinker = 0;
    }
    if (gpMonumodTxt)
    {
        DATATBLS_UnloadBin(gpMonumodTxt);
        gpMonumodTxt = 0;
    }
    gnMonumodTxtRecordCount = 0;

    if (gpMonstatsTxt)
    {
        DATATBLS_UnloadBin(gpMonstatsTxt);
        FOG_FreeLinker(gpMonStatsLinker);
    }
    gpMonstatsTxt = 0;

    if (gpMonTable_96C6C0)
    {
        DATATBLS_UnloadBin(gpMonTable_96C6C0);
        FOG_FreeLinker(gpMonStats2Linker);
    }

    if (gpMonpropTxt)
    {
        DATATBLS_UnloadBin(gpMonpropTxt);
        FOG_FreeLinker(gpMonPropLinker);
    }
    gnMonpropTxtRecordCount = 0;

    if (gpMonsoundsTxt)
    {
        DATATBLS_UnloadBin(gpMonsoundsTxt);
        FOG_FreeLinker(gpMonSoundsLinker);
        gnMonsoundsTxtRecordCount = 0;
    }

    DATATBLS_UnloadMonSeqTxt();
    DATATBLS_FreeTreasureClassEx();

    if (gpMonlvlTxt)
    {
        DATATBLS_UnloadBin(gpMonlvlTxt);
        gnMonlvlTxtRecordCount = 0;
    }

    DATATBLS_UnloadUniqueNameTxts();
}

#include "gen/data/Source/D2Common/DATATBLS/MonsterTbls.inc"
