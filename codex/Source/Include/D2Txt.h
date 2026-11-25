// Records of the game's .txt data tables (skills, monsters, items, missiles, objects, stats, classes).
#pragma once

#include "D2Check.h"


struct D2CharItemStrc
{
    unsigned int dwItemCode; // 0x00
    unsigned char nBodyLoc; // 0x04
    unsigned char nItemCount; // 0x05
    unsigned char unk0x06[0x2]; // 0x06
};

struct D2OpStatDataStrc
{
    unsigned short nOpBase; // 0x00
    unsigned short nStat; // 0x02
    unsigned char nOp; // 0x04
    unsigned char nOpParam; // 0x05
};

struct D2MonStats2CompStrc
{
    unsigned char nComposit[12]; // 0x00
};

struct D2CharStatsTxt
{
    unsigned short wszClassName[16]; // 0x00
    char szClassName[16]; // 0x20
    unsigned char nStr; // 0x30
    unsigned char nDex; // 0x31
    unsigned char nInt; // 0x32
    unsigned char nVit; // 0x33
    unsigned char nStamina; // 0x34
    unsigned char nLifeAdd; // 0x35
    unsigned char nPercentStr; // 0x36
    unsigned char nPercentInt; // 0x37
    unsigned char nPercentDex; // 0x38
    unsigned char nPercentVit; // 0x39
    unsigned char nManaRegen; // 0x3A
    unsigned char unk0x3B[0x1]; // 0x3B
    int dwToHitFactor; // 0x3C
    unsigned char nWalkSpeed; // 0x40
    unsigned char nRunSpeed; // 0x41
    unsigned char nRunDrain; // 0x42
    unsigned char lifePerLevel; // 0x43
    unsigned char staminaPerLevel; // 0x44
    unsigned char manaPerLevel; // 0x45
    unsigned char nLifePerVitality; // 0x46
    unsigned char nStaminaPerVitality; // 0x47
    unsigned char nManaPerMagic; // 0x48
    unsigned char nBlockFactor; // 0x49
    unsigned char unk0x4A[0x2]; // 0x4A
    int dwBaseWClass; // 0x4C
    signed char statPerLevel; // 0x50
    unsigned char unk0x51[0x1]; // 0x51
    unsigned short wStrAllSkills; // 0x52
    unsigned short wStrSkillTab[3]; // 0x54
    unsigned short wStrClassOnly; // 0x5A
    D2CharItemStrc pItems[10]; // 0x5C
    short wStartSkill; // 0xAC
    short nBaseSkill[10]; // 0xAE
    unsigned char unk0xC2[0x2]; // 0xC2
};

struct D2ItemStatCostTxt
{
    unsigned short wStatId; // 0x00
    unsigned char unk0x02[0x2]; // 0x02
    unsigned char nItemStatFlags[4]; // 0x04
    unsigned char nSendBits; // 0x08
    unsigned char nSendParamBits; // 0x09
    unsigned char nCsvBits; // 0x0A
    unsigned char nCsvParam; // 0x0B
    int nDivide; // 0x0C
    int dwMultiply; // 0x10
    int dwAdd; // 0x14
    unsigned char nValShift; // 0x18
    unsigned char nSaveBits; // 0x19
    unsigned char n109SaveBits; // 0x1A
    unsigned char unk0x1B[0x1]; // 0x1B
    int dwSaveAdd; // 0x1C
    int n109SaveAdd; // 0x20
    int nSaveParamBits; // 0x24
    int dw09SaveParamBits; // 0x28
    int dwMinAccr; // 0x2C
    unsigned char nEncode; // 0x30
    unsigned char unk0x31[0x1]; // 0x31
    unsigned short wMaxStat; // 0x32
    short nDescPriority; // 0x34
    unsigned char nDescFunc; // 0x36
    unsigned char nDescVal; // 0x37
    unsigned short wDescStrPos; // 0x38
    unsigned short wDescStrNeg; // 0x3A
    unsigned short wDescStr2; // 0x3C
    unsigned short wDescGrp; // 0x3E
    unsigned char nDescGrpFunc; // 0x40
    unsigned char nDescGrpVal; // 0x41
    unsigned short wDescGrpStrPos; // 0x42
    unsigned short wDescGrpStrNeg; // 0x44
    unsigned short wDescGrpStr2; // 0x46
    short wItemEvent[2]; // 0x48
    short wItemEventFunc[2]; // 0x4C
    unsigned char nKeepZero; // 0x50
    unsigned char bIsBaseOfOtherStatOp; // 0x51
    unsigned char bHasOpStatData; // 0x52
    unsigned char bHasOpApplyingToItem; // 0x53
    unsigned char nOp; // 0x54
    unsigned char nOpParam; // 0x55
    unsigned short wOpBase; // 0x56
    unsigned short wOpStat[3]; // 0x58
    unsigned short wStatsAffected[64]; // 0x5E
    D2OpStatDataStrc pOpStatData[16]; // 0xDE
    unsigned char unk0x13E[0x2]; // 0x13E
    int nStuff; // 0x140
};

struct D2ItemsTxt
{
    char szFlippyFile[32]; // 0x00
    char szInvFile[32]; // 0x20
    char szUniqueInvFile[32]; // 0x40
    char szSetInvFile[32]; // 0x60
    unsigned int dwCode; // 0x80
    unsigned int dwNormCode; // 0x84
    unsigned int dwUberCode; // 0x88
    unsigned int dwUltraCode; // 0x8C
    unsigned int dwAltCode2; // 0x90
    int dwPspell; // 0x94
    short wState; // 0x98
    short wCurseState[2]; // 0x9A
    short wStat[3]; // 0x9E
    unsigned int dwCalc[3]; // 0xA4
    unsigned int dwLen; // 0xB0
    unsigned char nDescType; // 0xB4
    unsigned char unk0xB5[0x1]; // 0xB5
    unsigned short wStringId; // 0xB6
    int dwSpellDescCalc; // 0xB8
    unsigned int dwUpgradeCode; // 0xBC
    unsigned int dwWeapClass; // 0xC0
    unsigned int dwWeapClass2Hand; // 0xC4
    unsigned int dwTransmogrifyType; // 0xC8
    int dwMinAc; // 0xCC
    int dwMaxAc; // 0xD0
    unsigned int dwGambleCost; // 0xD4
    int dwSpeed; // 0xD8
    unsigned int dwBitField1; // 0xDC
    int dwCost; // 0xE0
    unsigned int dwMinStack; // 0xE4
    unsigned int dwMaxStack; // 0xE8
    unsigned int dwSpawnStack; // 0xEC
    int dwGemOffset; // 0xF0
    unsigned short wNameStr; // 0xF4
    unsigned short wVersion; // 0xF6
    unsigned short wAutoPrefix; // 0xF8
    unsigned short wMissileType; // 0xFA
    unsigned char nRarity; // 0xFC
    unsigned char nLevel; // 0xFD
    unsigned char nMinDam; // 0xFE
    unsigned char nMaxDam; // 0xFF
    unsigned char nMinMisDam; // 0x100
    unsigned char nMaxMisDam; // 0x101
    unsigned char n2HandMinDam; // 0x102
    unsigned char n2HandMaxDam; // 0x103
    unsigned char nRangeAdder; // 0x104
    unsigned char unk0x105[0x1]; // 0x105
    short nStrBonus; // 0x106
    short nDexBonus; // 0x108
    unsigned short wReqStr; // 0x10A
    unsigned short wReqDex; // 0x10C
    unsigned char nAbsorb; // 0x10E
    unsigned char nInvWidth; // 0x10F
    unsigned char nInvHeight; // 0x110
    unsigned char nBlock; // 0x111
    unsigned char nDurability; // 0x112
    unsigned char nNoDurability; // 0x113
    unsigned char nMissile; // 0x114
    unsigned char nComponent; // 0x115
    unsigned char nArmorComp[6]; // 0x116
    unsigned char n2Handed; // 0x11C
    unsigned char bFlag0x11D; // 0x11D
    short wType[2]; // 0x11E
    unsigned char nSubType; // 0x122
    unsigned char unk0x123[0x1]; // 0x123
    short wDropSound; // 0x124
    short wUseSound; // 0x126
    unsigned char nDropSfxFrame; // 0x128
    unsigned char nUnique; // 0x129
    unsigned char nQuest; // 0x12A
    unsigned char nQuestDiffCheck; // 0x12B
    unsigned char nTransparent; // 0x12C
    unsigned char nTransTbl; // 0x12D
    unsigned char unk0x12E[0x1]; // 0x12E
    unsigned char nLightRadius; // 0x12F
    unsigned char nBelt; // 0x130
    unsigned char nAutoBelt; // 0x131
    unsigned char nStackable; // 0x132
    unsigned char nSpawnable; // 0x133
    unsigned char nSpellIcon; // 0x134
    unsigned char nDurWarning; // 0x135
    unsigned char nQuantityWarning; // 0x136
    unsigned char nHasInv; // 0x137
    unsigned char nGemSockets; // 0x138
    unsigned char nTransmogrify; // 0x139
    unsigned char nTmogMin; // 0x13A
    unsigned char nTmogMax; // 0x13B
    unsigned char nHitClass; // 0x13C
    unsigned char n1or2Handed; // 0x13D
    unsigned char nGemApplyType; // 0x13E
    unsigned char levelReq; // 0x13F
    unsigned char nMagicLevel; // 0x140
    unsigned char nTransform; // 0x141
    unsigned char nInvTrans; // 0x142
    unsigned char nCompactSave; // 0x143
    unsigned char nSkipName; // 0x144
    unsigned char nNameable; // 0x145
    unsigned char nVendorMin[17]; // 0x146
    unsigned char nVendorMax[17]; // 0x157
    unsigned char nVendorMagicMin[17]; // 0x168
    unsigned char nVendorMagicMax[17]; // 0x179
    unsigned char nVendorMagicLvl[17]; // 0x18A
    unsigned char unk0x19B[0x1]; // 0x19B
    unsigned int dwNightmareUpgrade; // 0x19C
    unsigned int dwHellUpgrade; // 0x1A0
    unsigned char nPermStoreItem; // 0x1A4
    unsigned char nField1A5; // 0x1A5
    unsigned char unk0x1A6[0x2]; // 0x1A6
};

struct D2MissilesTxt
{
    unsigned short wId; // 0x00
    unsigned char unk0x02[0x2]; // 0x02
    unsigned char nMissileFlags[4]; // 0x04
    unsigned short wCltDoFunc; // 0x08
    unsigned short wCltHitFunc; // 0x0A
    unsigned short wSrvDoFunc; // 0x0C
    unsigned short wSrvHitFunc; // 0x0E
    unsigned short wSrvDmgFunc; // 0x10
    unsigned short wTravelSound; // 0x12
    unsigned short wHitSound; // 0x14
    unsigned short wExplosionMissile; // 0x16
    short wSubMissile[3]; // 0x18
    short wCltSubMissile[3]; // 0x1E
    short wHitSubMissile[4]; // 0x24
    short wCltHitSubMissile[4]; // 0x2C
    short wProgSound; // 0x34
    short wProgOverlay; // 0x36
    int dwParam[5]; // 0x38
    int dwHitPar[3]; // 0x4C
    int dwCltParam[5]; // 0x58
    int dwCltHitPar[3]; // 0x6C
    int dwDmgParam[2]; // 0x78
    unsigned int dwSrvCalc; // 0x80
    unsigned int dwCltCalc; // 0x84
    unsigned int dwHitCalc; // 0x88
    unsigned int dwCltHitCalc; // 0x8C
    unsigned int dwDmgCalc; // 0x90
    unsigned char nHitClass; // 0x94
    unsigned char unk0x95[0x1]; // 0x95
    short wRange; // 0x96
    short wLevRange; // 0x98
    unsigned char nVel; // 0x9A
    unsigned char nVelLev; // 0x9B
    unsigned char nMaxVel; // 0x9C
    unsigned char unk0x9D[0x1]; // 0x9D
    short wAccel; // 0x9E
    short nAnimLen_2; // 0xA0
    short nOffsetX; // 0xA2
    short wYoffset; // 0xA4
    short nOffsetY; // 0xA6
    unsigned int dwHitFlags; // 0xA8
    unsigned short wResultFlags; // 0xAC
    unsigned char nKnockBack; // 0xAE
    unsigned char unk0xAF[0x1]; // 0xAF
    int dwMinDamage; // 0xB0
    int dwMaxDamage; // 0xB4
    int dwMinLevDam[5]; // 0xB8
    int dwMaxLevDam[5]; // 0xCC
    int dwDmgSymPerCalc; // 0xE0
    unsigned char nElemType; // 0xE4
    unsigned char unk0xE5[0x3]; // 0xE5
    int dwElemMin; // 0xE8
    int dwElemMax; // 0xEC
    int dwMinElemLev[5]; // 0xF0
    int dwMaxElemLev[5]; // 0x104
    int dwElemDmgSymPerCalc; // 0x118
    int nElementLength; // 0x11C
    int nElementLengthPerLevel[3]; // 0x120
    unsigned char nCltSrcTown; // 0x12C
    unsigned char nSrcDamage; // 0x12D
    unsigned char nSrcMissDmg; // 0x12E
    unsigned char nHoly; // 0x12F
    unsigned char nLight; // 0x130
    unsigned char nFlicker; // 0x131
    union
    {
        struct
        {
            unsigned char nRed; // 0x132
            unsigned char nGreen; // 0x133
            unsigned char nBlue; // 0x134
        };
        unsigned char nRGB[3]; // 0x132
    };
    unsigned char nCanDestroy; // 0x135
    unsigned char nActivate; // 0x136
    unsigned char nLoopAnim; // 0x137
    char szCelFile[64]; // 0x138
    unsigned char nAnimLen; // 0x178
    unsigned char unk0x179[0x3]; // 0x179
    int nRandFrames; // 0x17C
    unsigned char nSubLoop; // 0x180
    unsigned char nSubStart; // 0x181
    unsigned char nSubStop; // 0x182
    unsigned char nCollideType; // 0x183
    unsigned char nCollision; // 0x184
    unsigned char nClientCol; // 0x185
    unsigned char nCollideKill; // 0x186
    unsigned char nCollideFriend; // 0x187
    unsigned char nNextHit; // 0x188
    unsigned char nNextDelay; // 0x189
    unsigned char nSize; // 0x18A
    unsigned char nToHit; // 0x18B
    unsigned char nAlwaysExplode; // 0x18C
    unsigned char nTrans; // 0x18D
    unsigned char nQty[0x8]; // 0x18E
    unsigned char nHitShift; // 0x196
    unsigned char unk0x197[0x5]; // 0x197
    int nMissileStatValue; // 0x19C
    unsigned char nNumDirections; // 0x1A0
    unsigned char nAnimSpeed; // 0x1A1
    unsigned char bAltPalette; // 0x1A2
    unsigned char unk0x1A3[0x1]; // 0x1A3
};

struct D2MonStatsTxt
{
    short nId; // 0x00
    short nBaseId; // 0x02
    short nNextInClass; // 0x04
    unsigned short wNameStr; // 0x06
    unsigned short wDescStr; // 0x08
    unsigned char unk0x0A[0x2]; // 0x0A
    unsigned char nMonStatsFlags[4]; // 0x0C
    union
    {
        unsigned int dwCode; // 0x10
        char szCode[4]; // 0x10
    };
    short wMonSound; // 0x14
    short wUMonSound; // 0x16
    short wMonStatsEx; // 0x18
    short wMonProp; // 0x1A
    short wMonType; // 0x1C
    short wAI; // 0x1E
    short wSpawn; // 0x20
    signed char nSpawnX; // 0x22
    signed char nSpawnY; // 0x23
    signed char nSpawnMode; // 0x24
    unsigned char unk0x25[0x1]; // 0x25
    short wMinion[2]; // 0x26
    short nMonEquipTxtRecordId; // 0x2A
    unsigned char nPartyMin; // 0x2C
    unsigned char nPartyMax; // 0x2D
    unsigned char rarity; // 0x2E
    unsigned char nMinGrp; // 0x2F
    unsigned char nMaxGrp; // 0x30
    unsigned char nSparsePopulate; // 0x31
    short nVelocity; // 0x32
    short nRun; // 0x34
    short nWalkAnimSpeed; // 0x36
    short nRunAnimSpeed; // 0x38
    short wMissiles[8]; // 0x3A, by mode: A1, A2, S1, S2, S3, S4, C, SQ
    unsigned char nMaxChainId; // 0x4A
    unsigned char nChainId; // 0x4B
    unsigned char nAlign; // 0x4C
    unsigned char nMode4D; // 0x4D
    unsigned char nThreat; // 0x4E
    unsigned char nAIdel[3]; // 0x4F
    unsigned char nAiDist[3]; // 0x52
    unsigned char unk0x55; // 0x55
    short wAiParam[8][3]; // 0x56
    unsigned short wTreasureClass[3][4]; // 0x86
    unsigned char nTCQuestId; // 0x9E
    unsigned char nTCQuestCP; // 0x9F
    unsigned char nDrain[3]; // 0xA0
    unsigned char nBlock[3]; // 0xA3
    unsigned char nCrit; // 0xA6
    unsigned char unk0xA7[0x1]; // 0xA7
    short wSkillDamage; // 0xA8
    short nLevel[3]; // 0xAA
    short nMinHP[3]; // 0xB0
    short nMaxHP[3]; // 0xB6
    short nAC[3]; // 0xBC
    short nA1TH[3]; // 0xC2
    short nA2TH[3]; // 0xC8
    short nS1TH[3]; // 0xCE
    short nExp[3]; // 0xD4
    short nA1MinD[3]; // 0xDA
    short nA1MaxD[3]; // 0xE0
    short nA2MinD[3]; // 0xE6
    short nA2MaxD[3]; // 0xEC
    short nS1MinD[3]; // 0xF2
    short nS1MaxD[3]; // 0xF8
    unsigned char nElMode[3]; // 0xFE
    unsigned char nElType[3]; // 0x101
    unsigned char nElPct[3][3]; // 0x104
    short nElMinD[3][3]; // 0x10E
    short nElMaxD[3][3]; // 0x120
    short nElDur[3][3]; // 0x132
    short wResDm[3]; // 0x144
    short wResMa[3]; // 0x14A
    short wResFi[3]; // 0x150
    short wResLi[3]; // 0x156
    short wResCo[3]; // 0x15C
    short wResPo[3]; // 0x162
    signed char nColdEffect[3]; // 0x168
    unsigned char unk0x16B[0x1]; // 0x16B
    unsigned char nSendSkill[4]; // 0x16C
    short nSkill[8]; // 0x170
    unsigned char nSkillMode[8]; // 0x180
    short nSkillLevel[8]; // 0x188
    char nSkLvl[8]; // 0x198
    int nDamageRegen; // 0x1A0
    unsigned char nSplEndDeath; // 0x1A4
    unsigned char nSplGetModeChart; // 0x1A5
    unsigned char nSpecialEnd; // 0x1A6
    unsigned char nSplClientEnd; // 0x1A7
};

struct D2MonStats2Txt
{
    int dwId; // 0x00
    unsigned char nFlags[4]; // 0x04
    signed char nSizeX; // 0x08
    signed char nSizeY; // 0x09
    unsigned char nSpawnCol; // 0x0A
    char nType; // 0x0B
    unsigned char nOverlayHeight; // 0x0C
    unsigned char nPixHeight; // 0x0D
    unsigned char nSteps; // 0x0E
    unsigned char unk0x0F[0x1]; // 0x0F
    unsigned int dwBaseW; // 0x10
    unsigned char nHitClass; // 0x14
    unsigned char nComponentChoiceCounts[16]; // 0x15
    unsigned char nExtraComponentChoices; // 0x25
    D2MonStats2CompStrc pComponents[16]; // 0x26
    unsigned char unk0xE6[0x2]; // 0xE6
    unsigned char nComponentFlags[4]; // 0xE8
    unsigned char nTotalPieces; // 0xEC
    unsigned char unk0xED[0x3]; // 0xED
    unsigned char nModeFlags[4]; // 0xF0
    unsigned char nModeDirections[16]; // 0xF4
    unsigned char nModeEnabledWhenMovingFlags[4]; // 0x104
    unsigned char nInfernoLen; // 0x108
    unsigned char nInfernoAnim; // 0x109
    unsigned char nInfernoRollback; // 0x10A
    unsigned char nResurrectMode; // 0x10B
    unsigned short nResurrectSkill; // 0x10C
    unsigned char whtTop[0xA]; // 0x10E
    int dwAutomapCel; // 0x118
    unsigned char nLocalBlood; // 0x11C
    unsigned char nBleed; // 0x11D
    unsigned char nLightRadius; // 0x11E
    unsigned char nLight_R; // 0x11F
    unsigned char nLight_G; // 0x120
    unsigned char nLight_B; // 0x121
    unsigned char nModes[3]; // 0x122
    unsigned char unk0x125[0xB]; // 0x125
    unsigned char nRestore; // 0x130
    unsigned char unk0x131[0x3]; // 0x131
};

struct D2ObjectsTxt
{
    char szName[64]; // 0x00
    unsigned short wszName[64]; // 0x40
    unsigned char szToken[0x4]; // 0xC0
    unsigned char nSelectable[8]; // 0xC4
    unsigned char nTrapProb[0x4]; // 0xCC
    unsigned int dwSizeX; // 0xD0
    unsigned int dwSizeY; // 0xD4
    unsigned int dwFrameCnt[8]; // 0xD8
    short nFrameDelta[8]; // 0xF8
    unsigned char nCycleAnim[8]; // 0x108
    unsigned char nLit[8]; // 0x110
    unsigned char nBlocksLight[8]; // 0x118
    unsigned char nHasCollision[8]; // 0x120
    unsigned char nIsAttackable0; // 0x128
    unsigned char nStart[8]; // 0x129
    unsigned char nOrderFlag[8]; // 0x131
    unsigned char nEnvEffect; // 0x139
    unsigned char nIsDoor; // 0x13A
    unsigned char nBlocksVis; // 0x13B
    unsigned char nSide; // 0x13C
    unsigned char nAutomap13D; // 0x13D
    unsigned char nTrans; // 0x13E
    unsigned char nMode[8]; // 0x13F
    unsigned char unk0x147[0x1]; // 0x147
    int nXOffset; // 0x148
    int nYOffset; // 0x14C
    unsigned char bDraw; // 0x150
    unsigned char nModeEnabled[16]; // 0x151
    unsigned char nComponents; // 0x161
    unsigned char nXSpacing; // 0x162
    unsigned char nYSpacing; // 0x163
    unsigned char nRed; // 0x164
    unsigned char nGreen; // 0x165
    unsigned char nBlue; // 0x166
    unsigned char nSubClass; // 0x167
    unsigned int dwNameOffset; // 0x168
    unsigned char unk0x16C[0x1]; // 0x16C
    unsigned char nMonsterOK; // 0x16D
    unsigned char nOperateRange; // 0x16E
    unsigned char nShrineFunction; // 0x16F
    unsigned char nAct; // 0x170
    unsigned char nLockable; // 0x171
    unsigned char nGore; // 0x172
    unsigned char nRestore; // 0x173
    unsigned char nRestoreVirgins; // 0x174
    unsigned char nSync; // 0x175
    unsigned char unk0x176[0x2]; // 0x176
    int dwParm[8]; // 0x178
    unsigned char nTgtFX[0x4]; // 0x198
    unsigned char nDamage; // 0x19C
    unsigned char nSelectBox; // 0x19D
    unsigned char unk0x19E[0x2]; // 0x19E
    int dwLeft; // 0x1A0
    int dwTop; // 0x1A4
    int dwWidth; // 0x1A8
    int dwHeight; // 0x1AC
    unsigned char nBeta; // 0x1B0
    unsigned char nInitFn; // 0x1B1
    unsigned char nPopulateFn; // 0x1B2
    unsigned char nOperateFn; // 0x1B3
    unsigned char nClientFn; // 0x1B4
    unsigned char nOverlay; // 0x1B5
    unsigned char nBlockMissile; // 0x1B6
    unsigned char nFlags1B7; // 0x1B7
    unsigned char nOpenWarp; // 0x1B8
    unsigned char unk0x1B9[0x3]; // 0x1B9
    int dwAutomap; // 0x1BC
};

struct D2SkillsTxt
{
    short nSkillId; // 0x00
    unsigned char unk0x02[0x2]; // 0x02
    unsigned char nFlags[8]; // 0x04
    char nCharClass; // 0x0C
    unsigned char unk0x0D[0x3]; // 0x0D
    unsigned char nAnim; // 0x10
    unsigned char nMonAnim; // 0x11
    char nSeqTrans; // 0x12
    unsigned char nSeqNum; // 0x13
    char nAuraTargetState; // 0x14
    unsigned char nSelectProc; // 0x15
    unsigned char nSeqInput; // 0x16
    unsigned char unk0x17[0x1]; // 0x17
    short nITypeA[3]; // 0x18
    short nITypeB[3]; // 0x1E
    short nETypeA[2]; // 0x24
    short nETypeB[2]; // 0x28
    short wSrvStartFunc; // 0x2C
    short wSrvDoFunc; // 0x2E
    short wProgFunc[3]; // 0x30
    unsigned char unk0x36[0x2]; // 0x36
    unsigned int dwPrgCalc[3]; // 0x38
    unsigned char nPrgDamage; // 0x44
    unsigned char unk0x45[0x1]; // 0x45
    short wSrvMissile; // 0x46
    short wSrvMissileA; // 0x48
    short wSrvMissileB; // 0x4A
    short wSrvMissileC; // 0x4C
    short wSrvOverlay; // 0x4E
    unsigned int dwAuraFilter; // 0x50
    short wAuraStat[6]; // 0x54
    unsigned int dwAuraLenCalc; // 0x60
    unsigned int dwAuraRangeCalc; // 0x64
    unsigned int dwAuraStatCalc[6]; // 0x68
    short nAuraState; // 0x80
    short wAuraTargetState; // 0x82
    short wAuraEvent[3]; // 0x84
    short wAuraEventFunc[3]; // 0x8A
    unsigned char wAuraTgtEvent[0x4]; // 0x90
    short nPassiveState; // 0x94
    short nPassiveIType; // 0x96
    short nPassiveStat[5]; // 0x98
    unsigned char unk0xA2[0x2]; // 0xA2
    unsigned int dwPassiveCalc[5]; // 0xA4
    unsigned char wPassiveEvent[0x4]; // 0xB8
    short wSummon; // 0xBC
    char nPetType; // 0xBE
    unsigned char nSumMode; // 0xBF
    unsigned int dwPetMax; // 0xC0
    short wSumSkill[5]; // 0xC4
    unsigned char unk0xCE[0x2]; // 0xCE
    unsigned int dwSumSkCalc[5]; // 0xD0
    short wSumUMod; // 0xE4
    short wSumOverlay; // 0xE6
    union
    {
        struct
        {
            short wAuraFunc; // 0xE8
            short wCltMissileA; // 0xEA
            short wCltMissileB; // 0xEC
            short wCltMissileC; // 0xEE
        };
        short wCltMissile[4]; // 0xE8
    };
    short wCltMissileD; // 0xF0
    short wStartFunc; // 0xF2
    short clientDo; // 0xF4
    short wCltPrgFunc[3]; // 0xF6
    short wStSound; // 0xFC
    short wStartSoundClass; // 0xFE
    short wDoSound; // 0x100
    short wDoSoundA; // 0x102
    short wDoSoundB; // 0x104
    short wCastOverlay; // 0x106
    short wTgtOverlay; // 0x108
    short wTgtSound; // 0x10A
    short wPrgOverlay; // 0x10C
    short wPrgSound; // 0x10E
    short wCltOverlayA; // 0x110
    short wCltOverlayB; // 0x112
    int dwCltCalc[3]; // 0x114
    unsigned char nItemTarget; // 0x120
    unsigned char unk0x121[0x1]; // 0x121
    short wItemStartSound; // 0x122
    short wItemCastOverlay; // 0x124
    unsigned char unk0x126[0x2]; // 0x126
    unsigned int dwPerDelay; // 0x128
    short nMaxLevel; // 0x12C
    unsigned short wResultFlags; // 0x12E
    unsigned int dwHitFlags; // 0x130
    unsigned int dwHitClass; // 0x134
    unsigned int dwCalc[4]; // 0x138
    int dwParam[8]; // 0x148
    unsigned char nWeapSel; // 0x168
    unsigned char unk0x169[0x1]; // 0x169
    short wItemEffect; // 0x16A
    short clientDoSecondary; // 0x16C
    unsigned char unk0x16E[0x2]; // 0x16E
    unsigned int dwSkPoints; // 0x170
    short wReqLevel; // 0x174
    short wReqStr; // 0x176
    short wReqDex; // 0x178
    short wReqInt; // 0x17A
    short wReqVit; // 0x17C
    short nReqSkill[3]; // 0x17E
    short wStartMana; // 0x184
    short wMinMana; // 0x186
    short nManaShift; // 0x188
    short wMana; // 0x18A
    short wLevelMana; // 0x18C
    unsigned char nAttackRank; // 0x18E
    unsigned char nLineOfSight; // 0x18F
    unsigned int dwDelay; // 0x190
    short wSkillDesc; // 0x194
    unsigned char unk0x196[0x2]; // 0x196
    int dwToHit; // 0x198
    int dwLevToHit; // 0x19C
    unsigned int dwToHitCalc; // 0x1A0
    unsigned char nToHitShift; // 0x1A4
    unsigned char nSrcDam; // 0x1A5
    unsigned char unk0x1A6[0x2]; // 0x1A6
    int dwMinDam; // 0x1A8
    int dwMaxDam; // 0x1AC
    int dwMinLvlDam[5]; // 0x1B0
    int dwMaxLvlDam[5]; // 0x1C4
    unsigned int dwDmgSymPerCalc; // 0x1D8
    unsigned char nEType; // 0x1DC
    unsigned char unk0x1DD[0x3]; // 0x1DD
    int dwEMin; // 0x1E0
    int dwEMax; // 0x1E4
    int dwEMinLev[5]; // 0x1E8
    int dwEMaxLev[5]; // 0x1FC
    unsigned int dwEDmgSymPerCalc; // 0x210
    int dwELen; // 0x214
    int dwELevLen[3]; // 0x218
    unsigned int dwELenSymPerCalc; // 0x224
    unsigned char nRestrict; // 0x228
    unsigned char unk0x229[0x1]; // 0x229
    short nState[3]; // 0x22A
    unsigned char nAiType; // 0x230
    unsigned char unk0x231[0x1]; // 0x231
    short wAiBonus; // 0x232
    int nCostMult; // 0x234
    int nCostAdd; // 0x238
};

D2_CHECK_SIZE(D2CharItemStrc, 0x08);
D2_CHECK_SIZE(D2OpStatDataStrc, 0x06);
D2_CHECK_SIZE(D2MonStats2CompStrc, 0x0C);
D2_CHECK_SIZE(D2CharStatsTxt, 0xC4);
D2_CHECK_OFFSET(D2CharStatsTxt, nBaseSkill, 0xAE);
D2_CHECK_SIZE(D2ItemStatCostTxt, 0x144);
D2_CHECK_OFFSET(D2ItemStatCostTxt, nStuff, 0x140);
D2_CHECK_SIZE(D2ItemsTxt, 0x1A8);
D2_CHECK_OFFSET(D2ItemsTxt, nField1A5, 0x1A5);
D2_CHECK_SIZE(D2MissilesTxt, 0x1A4);
D2_CHECK_OFFSET(D2MissilesTxt, bAltPalette, 0x1A2);
D2_CHECK_SIZE(D2MonStatsTxt, 0x1A8);
D2_CHECK_OFFSET(D2MonStatsTxt, nSplClientEnd, 0x1A7);
D2_CHECK_SIZE(D2MonStats2Txt, 0x134);
D2_CHECK_OFFSET(D2MonStats2Txt, nRestore, 0x130);
D2_CHECK_SIZE(D2ObjectsTxt, 0x1C0);
D2_CHECK_OFFSET(D2ObjectsTxt, dwAutomap, 0x1BC);
D2_CHECK_SIZE(D2SkillsTxt, 0x23C);
D2_CHECK_OFFSET(D2SkillsTxt, nCostAdd, 0x238);
