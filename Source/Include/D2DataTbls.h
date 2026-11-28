// The game's data tables: every .txt table loaded at start-up, with its record count and lookups (sgptDataTables).
// D2DataTablesStrc is 0xC84 bytes in 1.14d: nothing reaches past offset 0xC70 through sgptDataTables, and the loaders
// only compile the way the game's do when gbCompileTxt, the next four bytes, is a global of its own. The item, level
// and cube tables that D2MOO's 1.10 struct holds after it are their own files' globals here.
#pragma once

#include "D2Check.h"

struct D2AnimDataTableStrc;
struct D2AnimSeqRecordStrc;
struct D2AnimSeqTxt;
struct D2CharStatsTxt;
struct D2CompCodeTxt;
struct D2CubeMainTxt;
struct D2DifficultyLevelsTxt;
struct D2DrlgFileStrc;
struct D2ExperienceDataTbl;
struct D2HirelingTxt;
struct D2ItemStatCostTxt;
struct D2ItemTypesTxt;
struct D2ItemsTxt;
struct D2LevelDefBin;
struct D2LevelsTxt;
struct D2LvlPrestTxt;
struct D2LvlSubTxt;
struct D2LvlTypesTxt;
struct D2MagicAffixTxt;
struct D2MissilesTxt;
struct D2MonEquipTxt;
struct D2MonLvlTxt;
struct D2MonPresetTxt;
struct D2MonSoundsTxt;
struct D2MonStats2Txt;
struct D2MonStatsTxt;
struct D2MonTypeTxt;
struct D2MonUModTxt;
struct D2NpcTxt;
struct D2OverlayTxt;
struct D2PetTypeTxt;
struct D2PropertiesTxt;
struct D2RareAffixTxt;
struct D2RunesTxt;
struct D2SetItemsTxt;
struct D2SetsTxt;
struct D2SkillDescTxt;
struct D2SkillsTxt;
struct D2StatesTxt;
struct D2SuperUniquesTxt;
struct D2TCExShortStrc;
struct D2TxtLinkStrc;
struct D2UniqueItemsTxt;

struct D2MagicAffixDataTbl
{
    int nMagicAffixTxtRecordCount; // 0x00
    D2MagicAffixTxt* pMagicAffixTxt; // 0x04
    D2MagicAffixTxt* pMagicSuffix; // 0x08
    D2MagicAffixTxt* pMagicPrefix; // 0x0C
    D2MagicAffixTxt* pAutoMagic; // 0x10
};

struct D2RuneDataTbl
{
    int nRunesTxtRecordCount; // 0x00
    D2RunesTxt* pRunesTxt; // 0x04
};

struct D2GambleDataTbl
{
    int nGambleTxtRecordCount; // 0x00
    int* pGambleSelection; // 0x04
    int pGambleChooseLimit[100]; // 0x08
};

struct D2CollisionFieldStrc
{
    int nWidth; // 0x00
    int nHeight; // 0x04
    int nArea; // 0x08
    int nCenterX; // 0x0C
    int nCenterY; // 0x10
};

struct D2DataTablesStrc
{
    void* pPlayerClassTxt; // 0x00
    D2TxtLinkStrc* pPlayerClassLinker; // 0x04
    void* pBodyLocsTxt; // 0x08
    D2TxtLinkStrc* pBodyLocsLinker; // 0x0C
    void* pStorePageTxt; // 0x10
    D2TxtLinkStrc* pStorePageLinker; // 0x14
    void* pElemTypesTxt; // 0x18
    D2TxtLinkStrc* pElemTypesLinker; // 0x1C
    void* pHitClassTxt; // 0x20
    D2TxtLinkStrc* pHitClassLinker; // 0x24
    void* pMonModeTxtStub; // 0x28
    D2TxtLinkStrc* pMonModeLinker; // 0x2C
    void* pPlrModeTxtStub; // 0x30
    D2TxtLinkStrc* pPlrModeLinker; // 0x34
    void* pSkillCalcTxt; // 0x38
    D2TxtLinkStrc* pSkillCalcLinker; // 0x3C
    char* pSkillsCode; // 0x40
    int nSkillsCodeSize; // 0x44
    int nSkillsCodeSizeEx; // 0x48
    char* pSkillDescCode; // 0x4C
    int nSkillDescCodeSize; // 0x50
    int nSkillDescCodeSizeEx; // 0x54
    void* pMissileCalcTxt; // 0x58
    D2TxtLinkStrc* pMissileCalcLinker; // 0x5C
    char* pMissCode; // 0x60
    int nMissCodeSize; // 0x64
    int nMissCodeSizeEx; // 0x68
    void* pSkillCode; // 0x6C
    D2TxtLinkStrc* pSkillCodeLinker; // 0x70
    void* pEventsTxt; // 0x74
    D2TxtLinkStrc* pEventsLinker; // 0x78
    D2CompCodeTxt* pCompCodeTxt; // 0x7C
    D2TxtLinkStrc* pCompCodeLinker; // 0x80
    int nCompCodeTxtRecordCount; // 0x84
    void* pMonAiTxt; // 0x88
    D2TxtLinkStrc* pMonAiLinker; // 0x8C
    int nMonAiTxtRecordCount; // 0x90
    D2TxtLinkStrc* pItemsLinker; // 0x94
    char* pItemsCode; // 0x98
    int nItemsCodeSize; // 0x9C
    int nItemsCodeSizeEx; // 0xA0
    D2PropertiesTxt* pPropertiesTxt; // 0xA4
    D2TxtLinkStrc* pPropertiesLinker; // 0xA8
    int nPropertiesTxtRecordCount; // 0xAC
    D2TxtLinkStrc* pRunesLinker; // 0xB0
    void* pHireDescTxt; // 0xB4
    D2TxtLinkStrc* pHireDescLinker; // 0xB8
    D2StatesTxt* pStatesTxt; // 0xBC
    D2TxtLinkStrc* pStatesLinker; // 0xC0
    int nStatesTxtRecordCount; // 0xC4
    unsigned int* pStateMasks; // 0xC8
    unsigned int* fStateMasks[40]; // 0xCC
    short* pProgressiveStates; // 0x16C
    short nProgressiveStates; // 0x170
    unsigned char unk0x172[0x2]; // 0x172
    short* pCurseStates; // 0x174
    short nCurseStates; // 0x178
    unsigned char unk0x17A[0x2]; // 0x17A
    short* pTransformStates; // 0x17C
    short nTransformStates; // 0x180
    unsigned char unk0x182[0x2]; // 0x182
    short* pActionStates; // 0x184
    short nActionStates; // 0x188
    unsigned char unk0x18A[0x2]; // 0x18A
    short* pColourStates; // 0x18C
    short nColourStates; // 0x190
    unsigned char unk0x192[0x2]; // 0x192
    void* pSoundsTxtCodes; // 0x194
    D2TxtLinkStrc* pSoundsLinker; // 0x198
    int nSoundsTxtCodes; // 0x19C
    D2HirelingTxt* pHirelingTxt; // 0x1A0
    int nHirelingTxtRecordCount; // 0x1A4
    int nHirelingIds[2][256]; // 0x1A8 the first record of each hireling id, classic and expansion
    D2NpcTxt* pNpcTxt; // 0x9A8
    int nNpcTxtRecordCount; // 0x9AC
    void* pColorsTxt; // 0x9B0
    D2TxtLinkStrc* pColorsLinker; // 0x9B4
    D2TxtLinkStrc* pTreasureClassExLinker; // 0x9B8
    D2TCExShortStrc* pTreasureClassEx; // 0x9BC
    int nTreasureClassEx; // 0x9C0
    D2TCExShortStrc* pChestTreasureClasses[3][5][3]; // 0x9C4
    D2MonStatsTxt* pMonStatsTxt; // 0xA78
    D2TxtLinkStrc* pMonStatsLinker; // 0xA7C
    int nMonStatsTxtRecordCount; // 0xA80
    D2MonSoundsTxt* pMonSoundsTxt; // 0xA84
    D2TxtLinkStrc* pMonSoundsLinker; // 0xA88
    int nMonSoundsTxtRecordCount; // 0xA8C
    D2MonStats2Txt* pMonStats2Txt; // 0xA90
    D2TxtLinkStrc* pMonStats2Linker; // 0xA94
    int nMonStats2TxtRecordCount; // 0xA98
    void* pMonPlaceTxt; // 0xA9C
    D2TxtLinkStrc* pMonPlaceLinker; // 0xAA0
    int nMonPlaceTxtRecordCount; // 0xAA4
    D2MonPresetTxt* pMonPresetTxt; // 0xAA8
    D2MonPresetTxt* pMonPresetTxtActSections[5]; // 0xAAC
    int nMonPresetTxtActRecordCounts[5]; // 0xAC0
    D2SuperUniquesTxt* pSuperUniquesTxt; // 0xAD4
    D2TxtLinkStrc* pSuperUniquesLinker; // 0xAD8
    int nSuperUniquesTxtRecordCount; // 0xADC
    unsigned short nSuperUniqueIds[66]; // 0xAE0
    D2MissilesTxt* pMissilesTxt; // 0xB64
    D2TxtLinkStrc* pMissilesLinker; // 0xB68
    int nMissilesTxtRecordCount; // 0xB6C
    D2MonLvlTxt* pMonLvlTxt; // 0xB70
    int nMonLvlTxtRecordCount; // 0xB74
    D2AnimSeqTxt* pMonSeqTxt; // 0xB78
    D2TxtLinkStrc* pMonSeqLinker; // 0xB7C
    int nMonSeqTxtRecordCount; // 0xB80
    D2AnimSeqRecordStrc* pMonSeqTable; // 0xB84
    int nMonSeqTableRecordCount; // 0xB88
    D2SkillDescTxt* pSkillDescTxt; // 0xB8C
    D2TxtLinkStrc* pSkillDescLinker; // 0xB90
    int nSkillDescTxtRecordCount; // 0xB94
    D2SkillsTxt* pSkillsTxt; // 0xB98
    D2TxtLinkStrc* pSkillsLinker; // 0xB9C
    int nSkillsTxtRecordCount; // 0xBA0
    int* nClassSkillCount; // 0xBA4
    int nHighestClassSkillCount; // 0xBA8
    short* nClassSkillList; // 0xBAC
    int nPassiveSkills; // 0xBB0
    unsigned short* pPassiveSkills; // 0xBB4
    D2TxtLinkStrc* pOverlayLinker; // 0xBB8
    D2OverlayTxt* pOverlayTxt; // 0xBBC
    int nOverlayTxtRecordCount; // 0xBC0
    D2CharStatsTxt* pCharStatsTxt; // 0xBC4
    int nCharStatsTxtRecordCount; // 0xBC8
    D2ItemStatCostTxt* pItemStatCostTxt; // 0xBCC
    D2TxtLinkStrc* pItemStatCostLinker; // 0xBD0
    int nItemStatCostTxtRecordCount; // 0xBD4
    short* pStatsWithDescFunc; // 0xBD8
    int nStatsWithDescFunc; // 0xBDC
    D2MonEquipTxt* pMonEquipTxt; // 0xBE0
    int nMonEquipTxtRecordCount; // 0xBE4
    D2PetTypeTxt* pPetTypeTxt; // 0xBE8
    D2TxtLinkStrc* pPetTypeLinker; // 0xBEC
    int nPetTypeTxtRecordCount; // 0xBF0
    D2TxtLinkStrc* pItemTypesLinker; // 0xBF4
    D2ItemTypesTxt* pItemTypesTxt; // 0xBF8
    int nItemTypesTxtRecordCount; // 0xBFC
    int nItemTypesIndex; // 0xC00
    unsigned int* pItemTypesEquivalenceLUTs; // 0xC04
    D2TxtLinkStrc* pSetsLinker; // 0xC08
    D2SetsTxt* pSetsTxt; // 0xC0C
    int nSetsTxtRecordCount; // 0xC10
    D2TxtLinkStrc* pSetItemsLinker; // 0xC14
    D2SetItemsTxt* pSetItemsTxt; // 0xC18
    int nSetItemsTxtRecordCount; // 0xC1C
    D2TxtLinkStrc* pUniqueItemsLinker; // 0xC20
    D2UniqueItemsTxt* pUniqueItemsTxt; // 0xC24
    int nUniqueItemsTxtRecordCount; // 0xC28
    D2TxtLinkStrc* pMonPropLinker; // 0xC2C
    void* pMonPropTxt; // 0xC30
    int nMonPropTxtRecordCount; // 0xC34
    D2TxtLinkStrc* pMonTypeLinker; // 0xC38
    D2MonTypeTxt* pMonTypeTxt; // 0xC3C
    int nMonTypeTxtRecordCount; // 0xC40
    unsigned int* pMonTypeNest; // 0xC44
    int nMonTypeIndex; // 0xC48
    D2TxtLinkStrc* pMonUModLinker; // 0xC4C
    D2MonUModTxt* pMonUModTxt; // 0xC50
    int nMonUModTxtRecordCount; // 0xC54
    D2LevelsTxt* pLevelsTxt; // 0xC58
    int nLevelsTxtRecordCount; // 0xC5C
    D2LevelDefBin* pLevelDefBin; // 0xC60
    D2LvlPrestTxt* pLvlPrestTxt; // 0xC64
    int nLvlPrestTxtRecordCount; // 0xC68
    int nStuff; // 0xC6C
    int nShiftedStuff; // 0xC70
    D2AnimDataTableStrc* pAnimData; // 0xC74
    D2ExperienceDataTbl* pExperienceTxt; // 0xC78
    D2DifficultyLevelsTxt* pDifficultyLevelsTxt; // 0xC7C
    int nDifficultyLevelsTxtRecordCount; // 0xC80
};

D2_CHECK_SIZE(D2MagicAffixDataTbl, 0x14);
D2_CHECK_SIZE(D2RuneDataTbl, 0x8);
D2_CHECK_SIZE(D2GambleDataTbl, 0x198);
D2_CHECK_SIZE(D2CollisionFieldStrc, 0x14);
D2_CHECK_SIZE(D2DataTablesStrc, 0xC84);
D2_CHECK_OFFSET(D2DataTablesStrc, pPlayerClassTxt, 0x0);
D2_CHECK_OFFSET(D2DataTablesStrc, pMissileCalcTxt, 0x58);
D2_CHECK_OFFSET(D2DataTablesStrc, pCompCodeTxt, 0x7C);
D2_CHECK_OFFSET(D2DataTablesStrc, pPropertiesTxt, 0xA4);
D2_CHECK_OFFSET(D2DataTablesStrc, nStatesTxtRecordCount, 0xC4);
D2_CHECK_OFFSET(D2DataTablesStrc, pHirelingTxt, 0x1A0);
D2_CHECK_OFFSET(D2DataTablesStrc, pNpcTxt, 0x9A8);
D2_CHECK_OFFSET(D2DataTablesStrc, pColorsTxt, 0x9B0);
D2_CHECK_OFFSET(D2DataTablesStrc, pTreasureClassEx, 0x9BC);
D2_CHECK_OFFSET(D2DataTablesStrc, pChestTreasureClasses, 0x9C4);
D2_CHECK_OFFSET(D2DataTablesStrc, pMonStatsTxt, 0xA78);
D2_CHECK_OFFSET(D2DataTablesStrc, pMonSoundsTxt, 0xA84);
D2_CHECK_OFFSET(D2DataTablesStrc, pMonStats2Txt, 0xA90);
D2_CHECK_OFFSET(D2DataTablesStrc, pMonPresetTxt, 0xAA8);
D2_CHECK_OFFSET(D2DataTablesStrc, pSuperUniquesTxt, 0xAD4);
D2_CHECK_OFFSET(D2DataTablesStrc, pMissilesTxt, 0xB64);
D2_CHECK_OFFSET(D2DataTablesStrc, pMonLvlTxt, 0xB70);
D2_CHECK_OFFSET(D2DataTablesStrc, pMonSeqTxt, 0xB78);
D2_CHECK_OFFSET(D2DataTablesStrc, pMonSeqTable, 0xB84);
D2_CHECK_OFFSET(D2DataTablesStrc, pSkillDescTxt, 0xB8C);
D2_CHECK_OFFSET(D2DataTablesStrc, pSkillsTxt, 0xB98);
D2_CHECK_OFFSET(D2DataTablesStrc, pOverlayTxt, 0xBBC);
D2_CHECK_OFFSET(D2DataTablesStrc, pCharStatsTxt, 0xBC4);
D2_CHECK_OFFSET(D2DataTablesStrc, pItemStatCostTxt, 0xBCC);
D2_CHECK_OFFSET(D2DataTablesStrc, pMonEquipTxt, 0xBE0);
D2_CHECK_OFFSET(D2DataTablesStrc, pPetTypeTxt, 0xBE8);
D2_CHECK_OFFSET(D2DataTablesStrc, pItemTypesTxt, 0xBF8);
D2_CHECK_OFFSET(D2DataTablesStrc, pSetsTxt, 0xC0C);
D2_CHECK_OFFSET(D2DataTablesStrc, pSetItemsTxt, 0xC18);
D2_CHECK_OFFSET(D2DataTablesStrc, pUniqueItemsTxt, 0xC24);
D2_CHECK_OFFSET(D2DataTablesStrc, pMonTypeTxt, 0xC3C);
D2_CHECK_OFFSET(D2DataTablesStrc, pMonUModTxt, 0xC50);
D2_CHECK_OFFSET(D2DataTablesStrc, pLevelsTxt, 0xC58);
D2_CHECK_OFFSET(D2DataTablesStrc, pExperienceTxt, 0xC78);
D2_CHECK_OFFSET(D2DataTablesStrc, nDifficultyLevelsTxtRecordCount, 0xC80);
