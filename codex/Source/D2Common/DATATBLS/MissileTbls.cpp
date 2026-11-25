extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

struct D2TxtLinkStrc;

struct D2UnusedPadStrc
{
    int nPad000;
    int nPad001;
    int nPad002;
    int nPad003;
    int nPad004;
    int nPad005;
    int nPad006;
    int nPad007;
    int nPad008;
    int nPad009;
    int nPad010;
    int nPad011;
    int nPad012;
    int nPad013;
    int nPad014;
    int nPad015;
};

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

struct D2MissilesTxt
{
    char unk0x000[0x183];
    unsigned char nCollideType;
    char unk0x184[0x20];
};

struct D2DataTablesStrc
{
    char unk0x000[0x1C];
    D2TxtLinkStrc* pElemTypesLinker;
    char unk0x020[0x40];
    void* pMissCode;
    int nMissCodeSize;
    int nMissCodeSizeEx;
    char unk0x06C[0x04];
    D2TxtLinkStrc* pSkillsLinker;
    char unk0x074[0x124];
    D2TxtLinkStrc* pSoundsLinker;
    char unk0x19C[0x9C8];
    D2MissilesTxt* pMissilesTxt;
    D2TxtLinkStrc* pMissilesLinker;
    int nMissilesTxtRecordCount;
    char unk0xB70[0x48];
    D2TxtLinkStrc* pOverlayLinker;
};

extern "C" const char gszTxtField_Missile[];                                                                // 0x006EE408
extern "C" const char gszTxtField_LastCollide[];                                                            // 0x006EE3FC
extern "C" const char gszTxtField_Explosion[];                                                              // 0x006EE3F0
extern "C" const char gszTxtField_Pierce[];                                                                 // 0x006EE3E8
extern "C" const char gszTxtField_CanSlow[];                                                                // 0x006EE3E0
extern "C" const char gszTxtField_CanDestroy[];                                                             // 0x006EE3D4
extern "C" const char gszTxtField_NoMultiShot[];                                                            // 0x006EE3C8
extern "C" const char gszTxtField_NoUniqueMod[];                                                            // 0x006EE3BC
extern "C" const char gszTxtField_ClientSend[];                                                             // 0x006EE3B0
extern "C" const char gszTxtField_GetHit[];                                                                 // 0x006EE3A8
extern "C" const char gszTxtField_SoftHit[];                                                                // 0x006EE3A0
extern "C" const char gszTxtField_ApplyMastery[];                                                           // 0x006EE390
extern "C" const char gszTxtField_ReturnFire[];                                                             // 0x006EE384
extern "C" const char gszTxtField_Town[];                                                                   // 0x006EE37C
extern "C" const char gszTxtField_SrcTown[];                                                                // 0x006EE374
extern "C" const char gszTxtField_pCltDoFunc[];                                                             // 0x006EE368
extern "C" const char gszTxtField_pCltHitFunc[];                                                            // 0x006EE35C
extern "C" const char gszTxtField_pSrvDoFunc[];                                                             // 0x006EE350
extern "C" const char gszTxtField_pSrvHitFunc[];                                                            // 0x006EE344
extern "C" const char gszTxtField_pSrvDmgFunc[];                                                            // 0x006EE338
extern "C" const char gszTxtField_Param1[];                                                                 // 0x006E6AA0
extern "C" const char gszTxtField_Param2[];                                                                 // 0x006E6A98
extern "C" const char gszTxtField_Param3[];                                                                 // 0x006E6A90
extern "C" const char gszTxtField_Param4[];                                                                 // 0x006E6A88
extern "C" const char gszTxtField_Param5[];                                                                 // 0x006E6A80
extern "C" const char gszTxtField_SrvCalc1[];                                                               // 0x006EE32C
extern "C" const char gszTxtField_CltParam1[];                                                              // 0x006EE320
extern "C" const char gszTxtField_CltParam2[];                                                              // 0x006EE314
extern "C" const char gszTxtField_CltParam3[];                                                              // 0x006EE308
extern "C" const char gszTxtField_CltParam4[];                                                              // 0x006EE2FC
extern "C" const char gszTxtField_CltParam5[];                                                              // 0x006EE2F0
extern "C" const char gszTxtField_CltCalc1[];                                                               // 0x006EE2E4
extern "C" const char gszTxtField_sHitPar1[];                                                               // 0x006EE2D8
extern "C" const char gszTxtField_sHitPar2[];                                                               // 0x006EE2CC
extern "C" const char gszTxtField_sHitPar3[];                                                               // 0x006EE2C0
extern "C" const char gszTxtField_SHitCalc1[];                                                              // 0x006EE2B4
extern "C" const char gszTxtField_cHitPar1[];                                                               // 0x006EE2A8
extern "C" const char gszTxtField_cHitPar2[];                                                               // 0x006EE29C
extern "C" const char gszTxtField_cHitPar3[];                                                               // 0x006EE290
extern "C" const char gszTxtField_CHitCalc1[];                                                              // 0x006EE284
extern "C" const char gszTxtField_dParam1[];                                                                // 0x006EE27C
extern "C" const char gszTxtField_dParam2[];                                                                // 0x006EE274
extern "C" const char gszTxtField_DmgCalc1[];                                                               // 0x006EE268
extern "C" const char gszTxtField_TravelSound[];                                                            // 0x006EE25C
extern "C" const char gszTxtField_HitSound[];                                                               // 0x006ECE08
extern "C" const char gszTxtField_ProgSound[];                                                              // 0x006EE250
extern "C" const char gszTxtField_ProgOverlay[];                                                            // 0x006EE244
extern "C" const char gszTxtField_ExplosionMissile[];                                                       // 0x006EE230
extern "C" const char gszTxtField_SubMissile1[];                                                            // 0x006EE224
extern "C" const char gszTxtField_SubMissile2[];                                                            // 0x006EE218
extern "C" const char gszTxtField_SubMissile3[];                                                            // 0x006EE20C
extern "C" const char gszTxtField_HitSubMissile1[];                                                         // 0x006EE1FC
extern "C" const char gszTxtField_HitSubMissile2[];                                                         // 0x006EE1EC
extern "C" const char gszTxtField_HitSubMissile3[];                                                         // 0x006EE1DC
extern "C" const char gszTxtField_HitSubMissile4[];                                                         // 0x006EE1CC
extern "C" const char gszTxtField_CltSubMissile1[];                                                         // 0x006EE1BC
extern "C" const char gszTxtField_CltSubMissile2[];                                                         // 0x006EE1AC
extern "C" const char gszTxtField_CltSubMissile3[];                                                         // 0x006EE19C
extern "C" const char gszTxtField_CltHitSubMissile1[];                                                      // 0x006EE188
extern "C" const char gszTxtField_CltHitSubMissile2[];                                                      // 0x006EE174
extern "C" const char gszTxtField_CltHitSubMissile3[];                                                      // 0x006EE160
extern "C" const char gszTxtField_CltHitSubMissile4[];                                                      // 0x006EE14C
extern "C" const char gszTxtField_ResultFlags[];                                                            // 0x006E6D28
extern "C" const char gszTxtField_HitFlags[];                                                               // 0x006E6D1C
extern "C" const char gszTxtField_HitClass[];                                                               // 0x006E6D10
extern "C" const char gszTxtField_Range[];                                                                  // 0x006EE144
extern "C" const char gszTxtField_LevRange[];                                                               // 0x006EE138
extern "C" const char gszTxtField_KnockBack[];                                                              // 0x006EE12C
extern "C" const char gszTxtField_animrate[];                                                               // 0x006EE120
extern "C" const char gszTxtField_xoffset[];                                                                // 0x006EE118
extern "C" const char gszTxtField_yoffset[];                                                                // 0x006EE110
extern "C" const char gszTxtField_zoffset[];                                                                // 0x006EE108
extern "C" const char gszTxtField_MissileSkill[];                                                           // 0x006EE0F8
extern "C" const char gszTxtField_Skill[];                                                                  // 0x006EE0F0
extern "C" const char gszTxtField_MinDamage[];                                                              // 0x006EE0E4
extern "C" const char gszTxtField_MinLevDam1[];                                                             // 0x006E6A00
extern "C" const char gszTxtField_MinLevDam2[];                                                             // 0x006E69F4
extern "C" const char gszTxtField_MinLevDam3[];                                                             // 0x006E69E8
extern "C" const char gszTxtField_MinLevDam4[];                                                             // 0x006E69DC
extern "C" const char gszTxtField_MinLevDam5[];                                                             // 0x006E69D0
extern "C" const char gszTxtField_MaxDamage[];                                                              // 0x006EE0D8
extern "C" const char gszTxtField_MaxLevDam1[];                                                             // 0x006E69BC
extern "C" const char gszTxtField_MaxLevDam2[];                                                             // 0x006E69B0
extern "C" const char gszTxtField_MaxLevDam3[];                                                             // 0x006E69A4
extern "C" const char gszTxtField_MaxLevDam4[];                                                             // 0x006E6998
extern "C" const char gszTxtField_MaxLevDam5[];                                                             // 0x006E698C
extern "C" const char gszTxtField_DmgSymPerCalc[];                                                          // 0x006E697C
extern "C" const char gszTxtField_EType[];                                                                  // 0x006E6974
extern "C" const char gszTxtField_EMin[];                                                                   // 0x006E696C
extern "C" const char gszTxtField_MinELev1[];                                                               // 0x006EE0CC
extern "C" const char gszTxtField_MinELev2[];                                                               // 0x006EE0C0
extern "C" const char gszTxtField_MinELev3[];                                                               // 0x006EE0B4
extern "C" const char gszTxtField_MinELev4[];                                                               // 0x006EE0A8
extern "C" const char gszTxtField_MinELev5[];                                                               // 0x006EE09C
extern "C" const char gszTxtField_EMax[];                                                                   // 0x006E6928
extern "C" const char gszTxtField_MaxELev1[];                                                               // 0x006EE090
extern "C" const char gszTxtField_MaxELev2[];                                                               // 0x006EE084
extern "C" const char gszTxtField_MaxELev3[];                                                               // 0x006EE078
extern "C" const char gszTxtField_MaxELev4[];                                                               // 0x006EE06C
extern "C" const char gszTxtField_MaxELev5[];                                                               // 0x006EE060
extern "C" const char gszTxtField_EDmgSymPerCalc[];                                                         // 0x006E68DC
extern "C" const char gszTxtField_ELen[];                                                                   // 0x006E68D4
extern "C" const char gszTxtField_ELevLen1[];                                                               // 0x006E68C8
extern "C" const char gszTxtField_ELevLen2[];                                                               // 0x006E68BC
extern "C" const char gszTxtField_ELevLen3[];                                                               // 0x006E68B0
extern "C" const char gszTxtField_CltSrcTown[];                                                             // 0x006EE054
extern "C" const char gszTxtField_SrcDamage[];                                                              // 0x006EE048
extern "C" const char gszTxtField_SrcMissDmg[];                                                             // 0x006EE03C
extern "C" const char gszTxtField_Half2HSrc[];                                                              // 0x006EE030
extern "C" const char gszTxtField_Vel[];                                                                    // 0x006EE02C
extern "C" const char gszTxtField_VelLev[];                                                                 // 0x006EE024
extern "C" const char gszTxtField_MaxVel[];                                                                 // 0x006EE01C
extern "C" const char gszTxtField_Accel[];                                                                  // 0x006EE014
extern "C" const char gszTxtField_Holy[];                                                                   // 0x006EE00C
extern "C" const char gszTxtField_Light[];                                                                  // 0x006EE004
extern "C" const char gszTxtField_Flicker[];                                                                // 0x006EDFFC
extern "C" const char gszTxtField_Red[];                                                                    // 0x006E8530
extern "C" const char gszTxtField_Green[];                                                                  // 0x006E8528
extern "C" const char gszTxtField_Blue[];                                                                   // 0x006E8520
extern "C" const char gszTxtField_InitSteps[];                                                              // 0x006EDFF0
extern "C" const char gszTxtField_Activate[];                                                               // 0x006EDFE4
extern "C" const char gszTxtField_LoopAnim[];                                                               // 0x006EDFD8
extern "C" const char gszTxtField_CelFile[];                                                                // 0x006EDFD0
extern "C" const char gszTxtField_AnimLen[];                                                                // 0x006EDFC8
extern "C" const char gszTxtField_RandStart[];                                                              // 0x006EDFBC
extern "C" const char gszTxtField_SubLoop[];                                                                // 0x006EDFB4
extern "C" const char gszTxtField_SubStart[];                                                               // 0x006EDFA8
extern "C" const char gszTxtField_SubStop[];                                                                // 0x006EDFA0
extern "C" const char gszTxtField_CollideType[];                                                            // 0x006EDF94
extern "C" const char gszTxtField_CollideKill[];                                                            // 0x006EDF88
extern "C" const char gszTxtField_CollideFriend[];                                                          // 0x006EDF78
extern "C" const char gszTxtField_Collision[];                                                              // 0x006EDF6C
extern "C" const char gszTxtField_ClientCol[];                                                              // 0x006EDF60
extern "C" const char gszTxtField_NextHit[];                                                                // 0x006EDF58
extern "C" const char gszTxtField_NextDelay[];                                                              // 0x006EDF4C
extern "C" const char gszTxtField_Size[];                                                                   // 0x006EDF44
extern "C" const char gszTxtField_ToHit[];                                                                  // 0x006E6A40
extern "C" const char gszTxtField_AlwaysExplode[];                                                          // 0x006EDF34
extern "C" const char gszTxtField_Trans[];                                                                  // 0x006EAC64
extern "C" const char gszTxtField_Qty[];                                                                    // 0x006EDF30
extern "C" const char gszTxtField_SpecialSetup[];                                                           // 0x006EDF20
extern "C" const char gszTxtField_HitShift[];                                                               // 0x006E6A1C
extern "C" const char gszTxtField_NumDirections[];                                                          // 0x006EDF10
extern "C" const char gszTxtField_AnimSpeed[];                                                              // 0x006EDEE8
extern "C" const char gszTxtField_LocalBlood[];                                                             // 0x006EDEDC
extern "C" const char gszTxtField_DamageRate[];                                                             // 0x006EDED0
extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
void __fastcall DATATBLS_MissileCalcLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn);// 0x006619A0
extern "C" const char gszMissilesTxtName[];                                                                 // 0x006EDEC4
extern "C" const char gszMissCodeName[];                                                                    // 0x006EDEB8
extern "C" const char gszMissileTblsSourceFile[];                                                           // 0x006EDEF4
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
D2TxtLinkStrc* __stdcall FOG_AllocLinker(const char* szFile, int nLine);                                    // 0x006BD040
void __fastcall DATATBLS_GetBinFileHandle(void* hArchive, const char* szFile, void** ppFileHandle, int* pSize, int* pSizeEx);// 0x00613E90
extern D2DataTablesStrc sgtDataTables;                                                                        // 0x0096BC30
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

static D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, unsigned int dwCode, int bLogError); // 0x006BD130

extern D2TxtLinkStrc* gpSkillCalcLinker_0096BC6C; // 0x0096BC6C

extern D2TxtLinkStrc* gpSkillCodeLinker_0096BCA0; // 0x0096BCA0

extern D2TxtLinkStrc* gpMissilesLinker_0096C798; // 0x0096C798

extern char* gpMissCode; // 0x0096BC90

int __fastcall DATATBLS_AppendMemoryBuffer(char** ppCodes, int* pSize, int* pSizeEx, void* pBuffer, int nBufferSize); // 0x006118B0

int __fastcall DATATBLS_MapMissilesTxtKeywordToNumber(char* szKey); // 0x00661800

int __fastcall DATATBLS_MissileLinkerResolveKeyword(char* szText, int* a2, int a3, int nKeywordNumber); // 0x00661880

int __stdcall DATATBLS_CompileExpression(const char* szFormulaString, char* pOutBuffer, int nOutBufferSize, int (__fastcall* pfnKeywordToNumber)(char*), int (__cdecl* pfnGetParameterCount)(), int (__fastcall* pfnLinkParse)(char*, int*, int, int)); // 0x006C1AE0

static int __stdcall DATATBLS_ClampMissileField(D2BinFieldStrc* pFields, int nMissileId, int nOffset, int nType, int nMin, int nMax); // 0x00661A30

D2TxtLinkStrc* gpMissileCalcLinker_0096BC8C; // 0x0096BC8C

int gnMissCodeSize; // 0x0096BC94

int gnMissCodeSizeEx; // 0x0096BC98

int __stdcall FOG_GetRowFromTxt(D2TxtLinkStrc* pLinker, const char* szText, int nColumn); // 0x006BD3C0

int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars); // 0x00413590

// 0x006617B0
static void DATATBLS_TextToLinkCode(const char* szText, char* szCode)
{
    if (!szText[0])
    {
        szCode[0] = ' ';
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
    }
    else
    {
        szCode[0] = szText[0];
        if (!szText[1])
        {
            szCode[1] = ' ';
            szCode[2] = ' ';
            szCode[3] = ' ';
        }
        else
        {
            szCode[1] = szText[1];
            if (!szText[2])
            {
                szCode[2] = ' ';
                szCode[3] = ' ';
            }
            else
            {
                szCode[2] = szText[2];
                if (!szText[3])
                {
                    szCode[3] = ' ';
                }
                else
                {
                    szCode[3] = szText[3];
                }
            }
        }
    }
}

// 0x00661800
int __fastcall DATATBLS_MapMissilesTxtKeywordToNumber(char* szKey)
{
    if (!SStrCmpI(szKey, "min", 32))
    {
        return 0;
    }
    else if (!SStrCmpI(szKey, "max", 32))
    {
        return 1;
    }
    else if (!SStrCmpI(szKey, "rand", 32))
    {
        return 2;
    }
    else if (!SStrCmpI(szKey, "skill", 32))
    {
        return 3;
    }
    else if (!SStrCmpI(szKey, "miss", 32))
    {
        return 4;
    }
    else
    {
        return -1;
    }
}

// 0x00661880
int __fastcall DATATBLS_MissileLinkerResolveKeyword(char* szText, int* a2, int a3, int nKeywordNumber)
{
    char szCode[4];

    if (a3 == 1)
    {
        if (nKeywordNumber == 3)
        {
            if (gpSkillCodeLinker_0096BCA0)
            {
                const int nRow = FOG_GetRowFromTxt(gpSkillCodeLinker_0096BCA0, szText, 0);
                if (nRow >= 0)
                {
                    *a2 = 1;
                    return nRow;
                }

                DATATBLS_TextToLinkCode(szText, szCode);
                const int nIndex = FOG_GetLinkIndex(gpSkillCalcLinker_0096BC6C, *(unsigned int*)szCode, 1);
                *a2 = 0;
                return nIndex;
            }
        }
        else if (nKeywordNumber == 4)
        {
            if (gpMissilesLinker_0096C798)
            {
                const int nRow = FOG_GetRowFromTxt(gpMissilesLinker_0096C798, szText, 0);
                if (nRow >= 0)
                {
                    *a2 = 1;
                    return nRow;
                }
            }

            DATATBLS_TextToLinkCode(szText, szCode);
            const int nIndex = FOG_GetLinkIndex(gpMissileCalcLinker_0096BC8C, *(unsigned int*)szCode, 1);
            *a2 = 0;
            return nIndex;
        }
    }

    DATATBLS_TextToLinkCode(szText, szCode);
    const int nIndex = FOG_GetLinkIndex(gpMissileCalcLinker_0096BC8C, *(unsigned int*)szCode, 1);
    *a2 = 0;
    return nIndex;
}

// 0x006619A0
void __fastcall DATATBLS_MissileCalcLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
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

    const int nBufferSize = DATATBLS_CompileExpression(pSrc, pBuffer, sizeof(pBuffer), DATATBLS_MapMissilesTxtKeywordToNumber, 0, DATATBLS_MissileLinkerResolveKeyword);
    if (nBufferSize <= 0)
    {
        *(int*)((char*)pRecord + nOffset) = -1;
        return;
    }

    *(int*)((char*)pRecord + nOffset) = DATATBLS_AppendMemoryBuffer(&gpMissCode, &gnMissCodeSize, &gnMissCodeSizeEx, pBuffer, nBufferSize);
}

// 0x00661A30
static int __stdcall DATATBLS_ClampMissileField(D2BinFieldStrc* pFields, int nMissileId, int nOffset, int nType, int nMin, int nMax)
{
    char* pRecord = (char*)DATATBLS_GetMissilesTxtRecord(nMissileId);
    int nValue = 0;
    switch (nType)
    {
    case 0:
        nValue = *(signed char*)(pRecord + nOffset);
        break;
    case 1:
        nValue = *(unsigned char*)(pRecord + nOffset);
        break;
    case 2:
        nValue = *(short*)(pRecord + nOffset);
        break;
    case 3:
        nValue = *(unsigned short*)(pRecord + nOffset);
        break;
    case 4:
        nValue = *(int*)(pRecord + nOffset);
        break;
    }

    if (nValue < nMin || nValue > nMax)
    {
        for (int nField = 0; pFields[nField].nFieldType; ++nField)
        {
            if (pFields[nField].nFieldOffset == nOffset)
            {
                break;
            }
        }

        nValue = D2_MIN(D2_MAX(nValue, nMin), nMax);

        switch (nType)
        {
        case 0:
        case 1:
            *(char*)(pRecord + nOffset) = (char)nValue;
            break;
        case 2:
        case 3:
            *(short*)(pRecord + nOffset) = (short)nValue;
            break;
        case 4:
            *(int*)(pRecord + nOffset) = nValue;
            break;
        }
    }
    return nValue;
}

// Nothing in the game calls 0x661A30; this caller keeps its register-argument copy.
void __fastcall sub_00661A30_Shim(D2BinFieldStrc* pFields)
{
    for (int i = 0; i < sgptDataTables->nMissilesTxtRecordCount; ++i)
    {
        DATATBLS_ClampMissileField(pFields, i, 0x183, 1, 0, 8);
        DATATBLS_ClampMissileField(pFields, i, 0x190, 2, -1, 100);
    }
}

// 0x00661B20
void __fastcall DATATBLS_LoadMissilesTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { gszTxtField_Missile, 17, 0, 0, &sgtDataTables.pMissilesLinker },
        { gszTxtField_LastCollide, 26, 0, 4, 0 },
        { gszTxtField_Explosion, 26, 1, 4, 0 },
        { gszTxtField_Pierce, 26, 2, 4, 0 },
        { gszTxtField_CanSlow, 26, 3, 4, 0 },
        { gszTxtField_CanDestroy, 26, 4, 4, 0 },
        { gszTxtField_NoMultiShot, 26, 12, 4, 0 },
        { gszTxtField_NoUniqueMod, 26, 13, 4, 0 },
        { gszTxtField_ClientSend, 26, 5, 4, 0 },
        { gszTxtField_GetHit, 26, 6, 4, 0 },
        { gszTxtField_SoftHit, 26, 7, 4, 0 },
        { gszTxtField_ApplyMastery, 26, 8, 4, 0 },
        { gszTxtField_ReturnFire, 26, 9, 4, 0 },
        { gszTxtField_Town, 26, 10, 4, 0 },
        { gszTxtField_SrcTown, 26, 11, 4, 0 },
        { gszTxtField_pCltDoFunc, 3, 0, 8, 0 },
        { gszTxtField_pCltHitFunc, 3, 0, 10, 0 },
        { gszTxtField_pSrvDoFunc, 3, 0, 12, 0 },
        { gszTxtField_pSrvHitFunc, 3, 0, 14, 0 },
        { gszTxtField_pSrvDmgFunc, 3, 0, 16, 0 },
        { gszTxtField_Param1, 2, 0, 56, 0 },
        { gszTxtField_Param2, 2, 0, 60, 0 },
        { gszTxtField_Param3, 2, 0, 64, 0 },
        { gszTxtField_Param4, 2, 0, 68, 0 },
        { gszTxtField_Param5, 2, 0, 72, 0 },
        { gszTxtField_SrvCalc1, 25, 0, 128, (void*)DATATBLS_MissileCalcLinker },
        { gszTxtField_CltParam1, 2, 0, 88, 0 },
        { gszTxtField_CltParam2, 2, 0, 92, 0 },
        { gszTxtField_CltParam3, 2, 0, 96, 0 },
        { gszTxtField_CltParam4, 2, 0, 100, 0 },
        { gszTxtField_CltParam5, 2, 0, 104, 0 },
        { gszTxtField_CltCalc1, 25, 0, 132, (void*)DATATBLS_MissileCalcLinker },
        { gszTxtField_sHitPar1, 2, 0, 76, 0 },
        { gszTxtField_sHitPar2, 2, 0, 80, 0 },
        { gszTxtField_sHitPar3, 2, 0, 84, 0 },
        { gszTxtField_SHitCalc1, 25, 0, 136, (void*)DATATBLS_MissileCalcLinker },
        { gszTxtField_cHitPar1, 2, 0, 108, 0 },
        { gszTxtField_cHitPar2, 2, 0, 112, 0 },
        { gszTxtField_cHitPar3, 2, 0, 116, 0 },
        { gszTxtField_CHitCalc1, 25, 0, 140, (void*)DATATBLS_MissileCalcLinker },
        { gszTxtField_dParam1, 2, 0, 120, 0 },
        { gszTxtField_dParam2, 2, 0, 124, 0 },
        { gszTxtField_DmgCalc1, 25, 0, 144, (void*)DATATBLS_MissileCalcLinker },
        { gszTxtField_TravelSound, 20, 0, 18, &sgtDataTables.pSoundsLinker },
        { gszTxtField_HitSound, 20, 0, 20, &sgtDataTables.pSoundsLinker },
        { gszTxtField_ProgSound, 20, 0, 52, &sgtDataTables.pSoundsLinker },
        { gszTxtField_ProgOverlay, 20, 0, 54, &sgtDataTables.pOverlayLinker },
        { gszTxtField_ExplosionMissile, 20, 0, 22, &sgtDataTables.pMissilesLinker },
        { gszTxtField_SubMissile1, 20, 0, 24, &sgtDataTables.pMissilesLinker },
        { gszTxtField_SubMissile2, 20, 0, 26, &sgtDataTables.pMissilesLinker },
        { gszTxtField_SubMissile3, 20, 0, 28, &sgtDataTables.pMissilesLinker },
        { gszTxtField_HitSubMissile1, 20, 0, 36, &sgtDataTables.pMissilesLinker },
        { gszTxtField_HitSubMissile2, 20, 0, 38, &sgtDataTables.pMissilesLinker },
        { gszTxtField_HitSubMissile3, 20, 0, 40, &sgtDataTables.pMissilesLinker },
        { gszTxtField_HitSubMissile4, 20, 0, 42, &sgtDataTables.pMissilesLinker },
        { gszTxtField_CltSubMissile1, 20, 0, 30, &sgtDataTables.pMissilesLinker },
        { gszTxtField_CltSubMissile2, 20, 0, 32, &sgtDataTables.pMissilesLinker },
        { gszTxtField_CltSubMissile3, 20, 0, 34, &sgtDataTables.pMissilesLinker },
        { gszTxtField_CltHitSubMissile1, 20, 0, 44, &sgtDataTables.pMissilesLinker },
        { gszTxtField_CltHitSubMissile2, 20, 0, 46, &sgtDataTables.pMissilesLinker },
        { gszTxtField_CltHitSubMissile3, 20, 0, 48, &sgtDataTables.pMissilesLinker },
        { gszTxtField_CltHitSubMissile4, 20, 0, 50, &sgtDataTables.pMissilesLinker },
        { gszTxtField_ResultFlags, 3, 0, 172, 0 },
        { gszTxtField_HitFlags, 8, 0, 168, 0 },
        { gszTxtField_HitClass, 4, 0, 148, 0 },
        { gszTxtField_Range, 3, 0, 150, 0 },
        { gszTxtField_LevRange, 3, 0, 152, 0 },
        { gszTxtField_KnockBack, 4, 0, 174, 0 },
        { gszTxtField_animrate, 3, 0, 160, 0 },
        { gszTxtField_xoffset, 3, 0, 162, 0 },
        { gszTxtField_yoffset, 3, 0, 164, 0 },
        { gszTxtField_zoffset, 3, 0, 166, 0 },
        { gszTxtField_MissileSkill, 26, 15, 4, 0 },
        { gszTxtField_Skill, 20, 0, 404, &sgtDataTables.pSkillsLinker },
        { gszTxtField_MinDamage, 2, 0, 176, 0 },
        { gszTxtField_MinLevDam1, 2, 0, 184, 0 },
        { gszTxtField_MinLevDam2, 2, 0, 188, 0 },
        { gszTxtField_MinLevDam3, 2, 0, 192, 0 },
        { gszTxtField_MinLevDam4, 2, 0, 196, 0 },
        { gszTxtField_MinLevDam5, 2, 0, 200, 0 },
        { gszTxtField_MaxDamage, 2, 0, 180, 0 },
        { gszTxtField_MaxLevDam1, 2, 0, 204, 0 },
        { gszTxtField_MaxLevDam2, 2, 0, 208, 0 },
        { gszTxtField_MaxLevDam3, 2, 0, 212, 0 },
        { gszTxtField_MaxLevDam4, 2, 0, 216, 0 },
        { gszTxtField_MaxLevDam5, 2, 0, 220, 0 },
        { gszTxtField_DmgSymPerCalc, 25, 0, 224, (void*)DATATBLS_MissileCalcLinker },
        { gszTxtField_EType, 13, 0, 228, &sgtDataTables.pElemTypesLinker },
        { gszTxtField_EMin, 2, 0, 232, 0 },
        { gszTxtField_MinELev1, 2, 0, 240, 0 },
        { gszTxtField_MinELev2, 2, 0, 244, 0 },
        { gszTxtField_MinELev3, 2, 0, 248, 0 },
        { gszTxtField_MinELev4, 2, 0, 252, 0 },
        { gszTxtField_MinELev5, 2, 0, 256, 0 },
        { gszTxtField_EMax, 2, 0, 236, 0 },
        { gszTxtField_MaxELev1, 2, 0, 260, 0 },
        { gszTxtField_MaxELev2, 2, 0, 264, 0 },
        { gszTxtField_MaxELev3, 2, 0, 268, 0 },
        { gszTxtField_MaxELev4, 2, 0, 272, 0 },
        { gszTxtField_MaxELev5, 2, 0, 276, 0 },
        { gszTxtField_EDmgSymPerCalc, 25, 0, 280, (void*)DATATBLS_MissileCalcLinker },
        { gszTxtField_ELen, 2, 0, 284, 0 },
        { gszTxtField_ELevLen1, 2, 0, 288, 0 },
        { gszTxtField_ELevLen2, 2, 0, 292, 0 },
        { gszTxtField_ELevLen3, 2, 0, 296, 0 },
        { gszTxtField_CltSrcTown, 4, 0, 300, 0 },
        { gszTxtField_SrcDamage, 4, 0, 301, 0 },
        { gszTxtField_SrcMissDmg, 4, 0, 302, 0 },
        { gszTxtField_Half2HSrc, 26, 14, 4, 0 },
        { gszTxtField_Vel, 4, 0, 154, 0 },
        { gszTxtField_VelLev, 4, 0, 155, 0 },
        { gszTxtField_MaxVel, 4, 0, 156, 0 },
        { gszTxtField_Accel, 3, 0, 158, 0 },
        { gszTxtField_Holy, 4, 0, 303, 0 },
        { gszTxtField_Light, 4, 0, 304, 0 },
        { gszTxtField_Flicker, 4, 0, 305, 0 },
        { gszTxtField_Red, 4, 0, 306, 0 },
        { gszTxtField_Green, 4, 0, 307, 0 },
        { gszTxtField_Blue, 4, 0, 308, 0 },
        { gszTxtField_InitSteps, 4, 0, 309, 0 },
        { gszTxtField_Activate, 4, 0, 310, 0 },
        { gszTxtField_LoopAnim, 4, 0, 311, 0 },
        { gszTxtField_CelFile, 1, 64, 312, 0 },
        { gszTxtField_AnimLen, 4, 0, 376, 0 },
        { gszTxtField_RandStart, 2, 0, 380, 0 },
        { gszTxtField_SubLoop, 4, 0, 384, 0 },
        { gszTxtField_SubStart, 4, 0, 385, 0 },
        { gszTxtField_SubStop, 4, 0, 386, 0 },
        { gszTxtField_CollideType, 4, 0, 387, 0 },
        { gszTxtField_CollideKill, 4, 0, 390, 0 },
        { gszTxtField_CollideFriend, 4, 0, 391, 0 },
        { gszTxtField_Collision, 4, 0, 388, 0 },
        { gszTxtField_ClientCol, 4, 0, 389, 0 },
        { gszTxtField_NextHit, 4, 0, 392, 0 },
        { gszTxtField_NextDelay, 4, 0, 393, 0 },
        { gszTxtField_Size, 4, 0, 394, 0 },
        { gszTxtField_ToHit, 4, 0, 395, 0 },
        { gszTxtField_AlwaysExplode, 4, 0, 396, 0 },
        { gszTxtField_Trans, 4, 0, 397, 0 },
        { gszTxtField_Qty, 4, 0, 398, 0 },
        { gszTxtField_SpecialSetup, 2, 0, 400, 0 },
        { gszTxtField_HitShift, 4, 0, 406, 0 },
        { gszTxtField_NumDirections, 4, 0, 416, 0 },
        { gszTxtField_AnimSpeed, 4, 0, 417, 0 },
        { gszTxtField_LocalBlood, 4, 0, 418, 0 },
        { gszTxtField_DamageRate, 2, 0, 412, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    sgtDataTables.pMissilesLinker = FOG_AllocLinker(gszMissileTblsSourceFile, 393);
    sgtDataTables.pMissilesTxt = (D2MissilesTxt*)DATATBLS_CompileTxt(hArchive, gszMissilesTxtName, pTbl, &sgtDataTables.nMissilesTxtRecordCount, sizeof(D2MissilesTxt));

    for (int i = 0; i < sgtDataTables.nMissilesTxtRecordCount; ++i)
    {
        D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(i);
        int nValue = pMissilesTxtRecord->nCollideType;
        if (nValue < 0 || nValue > 8)
        {
            D2BinFieldStrc* pFields = pTbl;
            for (int nField = 0; pFields[nField].nFieldType; ++nField)
            {
                if (pFields[nField].nFieldOffset == 0x183)
                {
                    break;
                }
            }

            if (nValue > 0)
            {
                _ReadWriteBarrier();
            }
            else
            {
                nValue = 0;
            }
            if (nValue >= 8)
            {
                nValue = 8;
            }
            pMissilesTxtRecord->nCollideType = nValue;
        }
    }

    DATATBLS_GetBinFileHandle(hArchive, gszMissCodeName, &sgtDataTables.pMissCode, &sgtDataTables.nMissCodeSize, &sgtDataTables.nMissCodeSizeEx);
}

void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);             // 0x0040B480
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                               // 0x006125C0
void __stdcall FOG_FreeLinker(D2TxtLinkStrc* pLinker);                                                      // 0x006BD0B0

// 0x00663210
void __fastcall DATATBLS_UnloadMissilesTxt()
{
    if (sgtDataTables.pMissCode)
    {
        sub_0040B480(0, sgtDataTables.pMissCode, ".\\DATATBLS\\MissileTbls.cpp", 414, 0);
        sgtDataTables.pMissCode = 0;
    }
    sgtDataTables.nMissCodeSize = 0;
    sgtDataTables.nMissCodeSizeEx = 0;

    if (sgtDataTables.pMissilesTxt)
    {
        DATATBLS_UnloadBin(sgtDataTables.pMissilesTxt);
    }

    if (sgtDataTables.pMissilesLinker)
    {
        FOG_FreeLinker(sgtDataTables.pMissilesLinker);
    }
    sgtDataTables.nMissilesTxtRecordCount = 0;
}

#include "gen/data/Source/D2Common/DATATBLS/MissileTbls.inc"
