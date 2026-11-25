// Functional replacement for the function at 0x00677880, not the original code: only the ordinary build (tools/link.py) uses it.
// The other functions in this file are copies that give it its callees and their calling conventions; the build links their verified definitions instead.

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl ASSERT_GetSourceFile(); // 0x00408090
extern "C" void __cdecl ASSERT_Report(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
extern "C" void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { ASSERT_Report(&gszEmptyAssertText, ASSERT_GetSourceFile(), line); exit(-1); }

extern "C" const char gszOutPlaceFile[]; // 0x006F1500

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
extern "C" void* __cdecl sub_00681EF0_Memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2PosStrc
{
    int nX;
    int nY;
};

struct D2OffsetPosStrc
{
    int nX;
    int nY;
    int nA;
    int nB;
    int nDir;
};

struct D2JungleStrc
{
    D2OffsetPosStrc tCoord;
    int nBranch;
    D2JungleStrc* pBasedOn;
    D2JungleStrc* pBranches[3];
    int nPresetsBlocksX;
    int nPresetsBlocksY;
    int* pJungleDefs;
    int nJungleDefs;
};

struct D2DrlgStrc
{
    D2SeedStrc pSeed;
    char unk0x008[0x450 - 0x008];
    unsigned char nDifficulty;
    char unk0x451[0x478 - 0x451];
    void* pMempool;
    char unk0x47C[4];
    unsigned char nAct;
};

struct D2DrlgCoordStrc { int nPosX, nPosY, nWidth, nHeight; };
struct D2DrlgOrthStrc;
struct D2DrlgOutdoorInfoStrc
{
    unsigned int dwFlags;
    char unk0x004[0x260];
    D2DrlgOrthStrc* pRoomData;
};
struct D2DrlgPresetInfoStrc { int unk0x00; int nDirection; };

struct D2DrlgLevelStrc
{
    int nDrlgType;
    char unk0x004[0x10];
    union { D2DrlgOutdoorInfoStrc* pOutdoors; D2DrlgPresetInfoStrc* pPreset; };
    char unk0x018[4];
    union
    {
        struct
        {
            int nPosX;
            int nPosY;
            int nWidth;
            int nHeight;
        };
        D2DrlgCoordStrc pLevelCoords;
    };
    char unk0x02C[0x1B4 - 0x02C];
    D2DrlgStrc* pDrlg;
    int nJungleDefs;
    int* pnJungleDefs;
    char unk0x1C0[0x10];
    int eLevelId;
};

struct D2LevelDefBin
{
    char unk0x00[0x0C];
    int dwSizeX[3];
    int dwSizeY[3];
    int dwOffsetX;
    int dwOffsetY;
};

D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId); // 0x0061E470
D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId); // 0x00642BB0
int __fastcall DRLG_CheckNotOverlappingUsingManhattanDistance(D2OffsetPosStrc* pCoord1, D2OffsetPosStrc* pCoord2, int nDistance); // 0x0066B860

extern const int gnSpiderForestPresets[]; // 0x006F13BC
extern const int gnJunglePresets[][4]; // 0x006F13F0

static void __stdcall DRLGOUTPLACE_OffsetByDirection(const D2PosStrc* pBase, int nDir, int nA, int nB, D2OffsetPosStrc* pOut); // 0x006777D0

static __forceinline unsigned int SEED_RollRandomNumber_Jungle(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber_Jungle(pSeed) % (unsigned int)nMax;
    }

    return SEED_RollRandomNumber_Jungle(pSeed) & (nMax - 1);
}

#define SEED_ROLL_LIMITED(pSeed, nMax, nResult) \
    if ((nMax) <= 0) \
    { \
        nResult = 0; \
    } \
    else if (((nMax) - 1) & (nMax)) \
    { \
        nResult = SEED_RollRandomNumber_Jungle(pSeed) % (unsigned int)(nMax); \
    } \
    else \
    { \
        nResult = SEED_RollRandomNumber_Jungle(pSeed) & ((nMax) - 1); \
    }

static __forceinline int JUNGLE_ABS(int n)
{
    return n < 0 ? -n : n;
}

static __forceinline int JUNGLE_NormalizePresetId(int nId)
{
    int nPDef = nId % 16;
    if (nPDef != 0)
    {
        if (nId >= 16)
        {
            if (nId & 0x10)
            {
                nPDef = gnJunglePresets[nPDef][0];
            }
            if (nId & 0x20)
            {
                nPDef = gnJunglePresets[nPDef][1];
            }
            if (nId & 0x40)
            {
                nPDef = gnJunglePresets[nPDef][2];
            }
            if (nId & 0x80)
            {
                nPDef = gnJunglePresets[nPDef][3];
            }
            D2_ASSERT(nPDef != 0, 0x78C);
            return nPDef;
        }

        return nPDef + 0x211;
    }

    if (nId >= 16)
    {
        nPDef = gnSpiderForestPresets[nId >> 4];
        D2_ASSERT(nPDef != 0, 0x799);
    }

    return nPDef;
}

// 0x006777D0
static void __stdcall DRLGOUTPLACE_OffsetByDirection(const D2PosStrc* pBase, int nDir, int nA, int nB, D2OffsetPosStrc* pOut)
{
    int nDx = 0;
    int nDy = 0;
    switch (nDir)
    {
    case 0:
        nDx = 0;
        nDy = -nB;
        break;

    case 1:
        nDx = -nA;
        nDy = nB / -3;
        break;

    case 2:
        nDx = nA;
        nDy = nB / -3;
        break;

    case 3:
        nDx = -nA;
        nDy = -nB * 2 / 3;
        break;

    case 4:
        nDx = nA;
        nDy = -nB * 2 / 3;
        break;
    }

    pOut->nX = pBase->nX + nDx;
    pOut->nY = pBase->nY + nDy;
    pOut->nA = nA;
    pOut->nB = nB;
    pOut->nDir = nDir;
}

static __declspec(noinline) D2DrlgLevelStrc* DRLG_GenerateJungles(D2DrlgLevelStrc* pLevel);

// 0x00677880
static D2DrlgLevelStrc* DRLG_GenerateJungles(D2DrlgLevelStrc* pLevel)
{
    D2LevelDefBin* pLevelDef = DATATBLS_GetLevelDefRecord(76);
    int nIdx = 1;
    D2DrlgStrc* pDrlg = pLevel->pDrlg;
    void* pMemPool = pDrlg->pMempool;
    int nSizeX = pLevelDef->dwSizeX[pDrlg->nDifficulty];
    int nSizeY = pLevelDef->dwSizeY[pDrlg->nDifficulty];
    int nBlocksX = nSizeX / 32;
    int nBlocksY = nSizeY / 32;
    int nMinX = pLevel->nPosX;
    int nMaxY = pLevel->nPosY;
    int nMaxX = nMinX + nSizeX;
    int nMinY = nMaxY - nSizeY;

    D2JungleStrc tJungles[3];
    sub_00681EF0_Memset(tJungles, 0, sizeof(tJungles));

    const D2PosStrc* pLevelPos = (const D2PosStrc*)&pLevel->nPosX;
    DRLGOUTPLACE_OffsetByDirection(pLevelPos, 0, nSizeX, nSizeY, &tJungles[0].tCoord);

    int x;
    int y;
    int nJ;
    while (nIdx < 3)
    {
        unsigned int nBaseOn;
        SEED_ROLL_LIMITED(&pDrlg->pSeed, nIdx, nBaseOn);
        DRLGOUTPLACE_OffsetByDirection((const D2PosStrc*)&tJungles[nBaseOn].tCoord, SEED_RollLimitedRandomNumber(&pDrlg->pSeed, 5), nSizeX, nSizeY, &tJungles[nIdx].tCoord);

        for (y = 0; y < nIdx; y++)
        {
            if (!DRLG_CheckNotOverlappingUsingManhattanDistance(&tJungles[y].tCoord, &tJungles[nIdx].tCoord, 0))
            {
                break;
            }
        }

        if (y < nIdx)
        {
            continue;
        }

        tJungles[nBaseOn].pBranches[tJungles[nBaseOn].nBranch] = &tJungles[nIdx];
        tJungles[nIdx].pBasedOn = &tJungles[nBaseOn];
        ++tJungles[nBaseOn].nBranch;
        D2_ASSERT(tJungles[nBaseOn].nBranch <= 3, 0x63E);

        if (nMinX > tJungles[nIdx].tCoord.nX)
        {
            nMinX = tJungles[nIdx].tCoord.nX;
        }
        if (nMinY > tJungles[nIdx].tCoord.nY)
        {
            nMinY = tJungles[nIdx].tCoord.nY;
        }
        if (nMaxX < tJungles[nIdx].tCoord.nX + tJungles[nIdx].tCoord.nA)
        {
            nMaxX = tJungles[nIdx].tCoord.nX + tJungles[nIdx].tCoord.nA;
        }

        ++nIdx;
    }

    D2_ASSERT((nMaxX - nMinX) % 32 == 0, 0x64D);
    D2_ASSERT((nMaxY - nMinY) % 32 == 0, 0x64E);

    int nW = (nMaxX - nMinX) / 32 + 2;
    int nH = (nMaxY - nMinY) / 32 + 2;
    int nSize = nH * nW * sizeof(int);

    int* pPreset0 = (int*)FOG_AllocPool(pMemPool, nSize, gszOutPlaceFile, 0x658, 0);
    int* pPreset1 = (int*)FOG_AllocPool(pMemPool, nSize, gszOutPlaceFile, 0x659, 0);
    int* pPreset2 = (int*)FOG_AllocPool(pMemPool, nSize, gszOutPlaceFile, 0x65A, 0);
    int* pLevelPresetId = (int*)FOG_AllocPool(pMemPool, nSize, gszOutPlaceFile, 0x65B, 0);

RESTART:
    sub_00681EF0_Memset(pPreset0, 0, nSize);
    sub_00681EF0_Memset(pPreset1, 0, nSize);
    sub_00681EF0_Memset(pPreset2, 0, nSize);
    sub_00681EF0_Memset(pLevelPresetId, 0, nSize);

    for (nJ = 0; nJ < 3; nJ++)
    {
        int nBY;
        int nBX = (tJungles[nJ].tCoord.nX - nMinX) / 32 + 1;
        nBY = (tJungles[nJ].tCoord.nY - nMinY) / 32 + 1;
        tJungles[nJ].nPresetsBlocksX = nBX;
        tJungles[nJ].nPresetsBlocksY = nBY;
        tJungles[nJ].pJungleDefs = (int*)FOG_AllocPool(pMemPool, nBlocksY * nBlocksX * sizeof(int), gszOutPlaceFile, 0x66F, 0);

        int bOffset;
        if (nJ == 0)
        {
            bOffset = SEED_RollLimitedRandomNumber(&pDrlg->pSeed, 2);
        }
        else
        {
            bOffset = (tJungles[nJ].tCoord.nDir % 2) == 1;
        }

        int nAttach;
        do
        {
            for (int y = 0; y < nBlocksY; y++)
            {
                for (int x = 0; x < nBlocksX; x++)
                {
                    pPreset0[(nBY + y) * nW + nBX + x] = nJ + 1;
                    pPreset1[(nBY + y) * nW + nBX + x] = 0;
                    pPreset2[(nBY + y) * nW + nBX + x] = 0;
                    pLevelPresetId[(nBY + y) * nW + nBX + x] = 0;
                }
            }

            x = bOffset + nBX;
            y = nBY + nBlocksY - 1;
            if (nJ != 0)
            {
                pPreset2[nW * y + x] = 1;
                pPreset2[nW * y + x + (bOffset ? -1 : 1)] = 2;
            }

            for (int i = 0; i < tJungles[nJ].nBranch; i++)
            {
                switch (tJungles[nJ].pBranches[i]->tCoord.nDir)
                {
                case 0:
                    pPreset2[nBY * nW + nBX] = 1;
                    break;
                case 1:
                    pPreset2[(nBY + 3) * nW + nBX] = 1;
                    break;
                case 2:
                    pPreset2[(nBY + 3) * nW + nBX + 1] = 1;
                    break;
                case 3:
                    pPreset2[(nBY + 1) * nW + nBX] = 1;
                    break;
                case 4:
                    pPreset2[(nBY + 1) * nW + nBX + 1] = 1;
                    break;
                }
            }

            nAttach = nJ != 0;
            int nStep = 0;
            int nColumnSize = 0;
            while (y >= nBY)
            {
                pPreset1[x + nW * y] = (nJ + 1) * 100 + nStep;
                ++nStep;

                if (nColumnSize == 0 || y == nBY || SEED_RollLimitedRandomNumber(&pDrlg->pSeed, 3))
                {
                    ++nColumnSize;
                    if (nColumnSize >= 2 && y > 1)
                    {
                        if (pPreset2[nW * y + x + (bOffset ? -1 : 1)] == 0)
                        {
                            ++nAttach;
                            pPreset2[nW * y + x + (bOffset ? -1 : 1)] = 2;
                        }
                    }
                    --y;
                }
                else
                {
                    nColumnSize = 0;
                    if (bOffset)
                    {
                        --x;
                        bOffset = 0;
                    }
                    else
                    {
                        ++x;
                        bOffset = 1;
                    }
                }
            }
        }
        while (nAttach < 2);

        while (nAttach > 3)
        {
            unsigned int nRemove;
            SEED_ROLL_LIMITED(&pDrlg->pSeed, nAttach, nRemove);
            int bFinished = 0;
            int nRemoveIdx = 0;
            for (int y = 0; y < nBlocksY && !bFinished; y++)
            {
                for (int x = 0; x < nBlocksX && !bFinished; x++)
                {
                    if (pPreset2[(nBY + y) * nW + nBX + x] == 2)
                    {
                        if (nRemove == nRemoveIdx)
                        {
                            pPreset2[(nBY + y) * nW + nBX + x] = 0;
                            bFinished = 1;
                            --nAttach;
                        }
                        ++nRemoveIdx;
                    }
                }
            }
        }
    }

    for (int y = 0; y < nH; y++)
    {
        for (x = 0; x < nW; x++)
        {

            const int nP0 = pPreset0[y * nW + x];
            int nLast = 0x7FFFFFFF;
            int nFlags = 0;
            if (pPreset2[y * nW + x] == 1)
            {
                if (pPreset1[(y - 1) * nW + x] && pPreset1[(y - 1) * nW + x] < nLast && pPreset0[(y - 1) * nW + x] == nP0)
                {
                    nFlags = 8;
                    nLast = pPreset1[(y - 1) * nW + x];
                }
                if (pPreset1[(y + 1) * nW + x] && pPreset1[(y + 1) * nW + x] < nLast && pPreset0[(y + 1) * nW + x] == nP0)
                {
                    nFlags = 4;
                    nLast = pPreset1[(y + 1) * nW + x];
                }
                if (pPreset1[y * nW + x + 1] && pPreset1[y * nW + x + 1] < nLast && pPreset0[y * nW + x + 1] == nP0)
                {
                    nFlags = 2;
                    nLast = pPreset1[y * nW + x + 1];
                }
                if (pPreset1[y * nW + x - 1] && pPreset1[y * nW + x - 1] < nLast && pPreset0[y * nW + x - 1] == nP0)
                {
                    nFlags = 1;
                    nLast = pPreset1[y * nW + x - 1];
                }

                if (nFlags & 8)
                {
                    pLevelPresetId[(y - 1) * nW + x] |= 4;
                }
                if (nFlags & 4)
                {
                    pLevelPresetId[(y + 1) * nW + x] |= 8;
                }
                if (nFlags & 2)
                {
                    pLevelPresetId[y * nW + x + 1] |= 1;
                }
                if (nFlags & 1)
                {
                    pLevelPresetId[y * nW + x - 1] |= 2;
                }

                if (pPreset2[(y - 1) * nW + x] == 1 && pPreset0[(y - 1) * nW + x] != nP0)
                {
                    nFlags |= 8;
                }
                if (pPreset2[(y + 1) * nW + x] == 1 && pPreset0[(y + 1) * nW + x] != nP0)
                {
                    nFlags |= 4;
                }
                if (pPreset2[y * nW + x + 1] == 1 && pPreset0[y * nW + x + 1] != nP0)
                {
                    nFlags |= 2;
                }
                if (pPreset2[y * nW + x - 1] == 1 && pPreset0[y * nW + x - 1] != nP0)
                {
                    nFlags |= 1;
                }
            }

            const int nP1 = pPreset1[y * nW + x];
            if (nP1)
            {
                if (JUNGLE_ABS(nP1 - pPreset1[(y - 1) * nW + x]) == 1)
                {
                    nFlags |= 8;
                }
                if (JUNGLE_ABS(nP1 - pPreset1[(y + 1) * nW + x]) == 1)
                {
                    nFlags |= 4;
                }
                if (JUNGLE_ABS(nP1 - pPreset1[y * nW + x + 1]) == 1)
                {
                    nFlags |= 2;
                }
                if (JUNGLE_ABS(nP1 - pPreset1[y * nW + x - 1]) == 1)
                {
                    nFlags |= 1;
                }
            }

            pLevelPresetId[y * nW + x] |= nFlags;
        }
    }

    for (int y = 0; y < nH; y++)
    {
        for (x = 0; x < nW; x++)
        {

            const int nP0 = pPreset0[y * nW + x];
            int nLevelPreset = pLevelPresetId[y * nW + x];
            int nDirStart = SEED_RollLimitedRandomNumber(&pDrlg->pSeed, 4);
            const int bHadNoPreset = nLevelPreset == 0;
            if (pPreset2[y * nW + x] == 2)
            {
                nJ = 0;
                int bLook = 1;
                for (; nJ < 4 && bLook; nJ++)
                {
                    switch ((nDirStart + nJ) % 4)
                    {
                    case 0:
                        if (pPreset0[(y - 1) * nW + x] == nP0 && pLevelPresetId[(y - 1) * nW + x] && pLevelPresetId[(y - 1) * nW + x] < 15)
                        {
                            nLevelPreset |= 0x80;
                            bLook = 0;
                        }
                        break;
                    case 1:
                        if (pPreset0[(y + 1) * nW + x] == nP0 && pLevelPresetId[(y + 1) * nW + x] && pLevelPresetId[(y + 1) * nW + x] < 15)
                        {
                            nLevelPreset |= 0x40;
                            bLook = 0;
                        }
                        break;
                    case 2:
                        if (pPreset0[y * nW + x + 1] == nP0 && pLevelPresetId[y * nW + x + 1] && pLevelPresetId[y * nW + x + 1] < 15)
                        {
                            nLevelPreset |= 0x20;
                            bLook = 0;
                        }
                        break;
                    case 3:
                        if (pPreset0[y * nW + x - 1] == nP0 && pLevelPresetId[y * nW + x - 1] && pLevelPresetId[y * nW + x - 1] < 15)
                        {
                            nLevelPreset |= 0x10;
                            bLook = 0;
                        }
                        break;
                    }
                }

                if (!nLevelPreset)
                {
                    goto RESTART;
                }

                if (bHadNoPreset)
                {
                    nJ = 0;
                    bLook = 1;
                    for (; nJ < 4 && bLook; nJ++)
                    {
                        switch ((nDirStart + nJ) % 4)
                        {
                        case 0:
                            if (pPreset0[(y - 1) * nW + x] != nP0 && pPreset2[(y - 1) * nW + x] == 2)
                            {
                                nLevelPreset |= 0x80;
                                bLook = 0;
                            }
                            break;
                        case 1:
                            if (pPreset0[(y + 1) * nW + x] != nP0 && pPreset2[(y + 1) * nW + x] == 2)
                            {
                                nLevelPreset |= 0x40;
                                bLook = 0;
                            }
                            break;
                        case 2:
                            if (pPreset0[y * nW + x + 1] != nP0 && pPreset2[y * nW + x + 1] == 2)
                            {
                                nLevelPreset |= 0x20;
                                bLook = 0;
                            }
                            break;
                        case 3:
                            if (pPreset0[y * nW + x - 1] != nP0 && pPreset2[y * nW + x - 1] == 2)
                            {
                                nLevelPreset |= 0x10;
                                bLook = 0;
                            }
                            break;
                        }
                    }

                    bLook = SEED_RollLimitedRandomNumber(&pDrlg->pSeed, 2) != 0 && bLook;
                    D2SeedStrc* const pSeed = &pDrlg->pSeed;
                    nDirStart = SEED_RollLimitedRandomNumber(pSeed, 4);

                    for (nJ = 0; nJ < 4 && bLook; nJ++)
                    {
                        switch ((nDirStart + nJ) % 4)
                        {
                        case 0:
                            if (pLevelPresetId[(y - 1) * nW + x] && pLevelPresetId[(y - 1) * nW + x] < 15 && !(nLevelPreset & 0x80))
                            {
                                nLevelPreset |= 0x80;
                                bLook = 0;
                            }
                            break;
                        case 1:
                            if (pLevelPresetId[(y + 1) * nW + x] && pLevelPresetId[(y + 1) * nW + x] < 15 && !(nLevelPreset & 0x40))
                            {
                                nLevelPreset |= 0x40;
                                bLook = 0;
                            }
                            break;
                        case 2:
                            if (pLevelPresetId[y * nW + x + 1] && pLevelPresetId[y * nW + x + 1] < 15 && !(nLevelPreset & 0x20))
                            {
                                nLevelPreset |= 0x20;
                                bLook = 0;
                            }
                            break;
                        case 3:
                            if (pLevelPresetId[y * nW + x - 1] && pLevelPresetId[y * nW + x - 1] < 15 && !(nLevelPreset & 0x10))
                            {
                                nLevelPreset |= 0x10;
                                bLook = 0;
                            }
                            break;
                        }
                    }
                }

                if (nLevelPreset & 0x80)
                {
                    pLevelPresetId[(y - 1) * nW + x] |= 0x40;
                }
                if (nLevelPreset & 0x40)
                {
                    pLevelPresetId[(y + 1) * nW + x] |= 0x80;
                }
                if (nLevelPreset & 0x20)
                {
                    pLevelPresetId[y * nW + x + 1] |= 0x10;
                }
                if (nLevelPreset & 0x10)
                {
                    pLevelPresetId[y * nW + x - 1] |= 0x20;
                }

                pPreset2[y * nW + x] = 0;
            }

            pLevelPresetId[y * nW + x] |= nLevelPreset;
        }
    }

    for (y = 0; y < nH; y++)
    {
        for (x = 0; x < nW; x++)
        {
            pLevelPresetId[y * nW + x] = JUNGLE_NormalizePresetId(pLevelPresetId[y * nW + x]);
        }
    }

    for (nJ = 0; nJ < 3; nJ++)
    {
        int nDef = 0;
        for (int by = 0; by < nBlocksY; by++)
        {
            for (int bx = 0; bx < nBlocksX; bx++)
            {
                tJungles[nJ].pJungleDefs[nDef] = pLevelPresetId[(tJungles[nJ].nPresetsBlocksY + by) * nW + bx + tJungles[nJ].nPresetsBlocksX];
                if (tJungles[nJ].pJungleDefs[nDef] > 0x23E)
                {
                    ++tJungles[nJ].nJungleDefs;
                }
                ++nDef;
            }
        }
    }

    int bSwapped;
    do
    {
        bSwapped = 0;
        for (nJ = 0; nJ < 2; nJ++)
        {
            if (tJungles[nJ + 1].tCoord.nY > tJungles[nJ].tCoord.nY)
            {
                D2JungleStrc tTemp = tJungles[nJ + 1];
                tJungles[nJ + 1] = tJungles[nJ];
                bSwapped = 1;
                tJungles[nJ] = tTemp;
            }
        }
    }
    while (bSwapped);

    D2DrlgLevelStrc* pJungleLevel = 0;
    for (nJ = 0; nJ < 3; nJ++)
    {
        pJungleLevel = DRLG_GetLevel(pDrlg, nJ + 76);
        pJungleLevel->pnJungleDefs = tJungles[nJ].pJungleDefs;
        pJungleLevel->nJungleDefs = tJungles[nJ].nJungleDefs;
        pJungleLevel->nPosX = tJungles[nJ].tCoord.nX;
        pJungleLevel->nPosY = tJungles[nJ].tCoord.nY;
        pJungleLevel->nWidth = tJungles[nJ].tCoord.nA;
        pJungleLevel->nHeight = tJungles[nJ].tCoord.nB;
    }

    FOG_FreePool(pMemPool, pPreset0, gszOutPlaceFile, 0x7D2, 0);
    FOG_FreePool(pMemPool, pPreset1, gszOutPlaceFile, 0x7D3, 0);
    FOG_FreePool(pMemPool, pPreset2, gszOutPlaceFile, 0x7D4, 0);
    FOG_FreePool(pMemPool, pLevelPresetId, gszOutPlaceFile, 0x7D5, 0);

    return pJungleLevel;
}

struct D2DrlgLevelLinkDataStrc;

struct D2DrlgLinkStrc
{
    int (__fastcall* pfLinker)(D2DrlgLevelLinkDataStrc* pLevelLinkData);
    int nLevel;
    int nLevelLink;
    int nLevelLinkEx;
};

struct D2DrlgLevelLinkDataStrc
{
    D2SeedStrc pSeed;
    D2DrlgCoordStrc pLevelCoord[15];
    D2DrlgLinkStrc* pLink;
    int nRand[4][15];
    int nIteration;
    int nCurrentLevel;
};

struct D2DrlgWarpStrc;

typedef int (__fastcall* LINKFN)(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);
typedef void (__fastcall* FLAGFN)(D2DrlgLevelStrc* pLevel, int nIteration, int* pRand);

#define DRLGTYPE_PRESET 2
#define DRLGTYPE_OUTDOOR 3

D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId); // 0x00642BB0
D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId); // 0x0061E470
D2DrlgWarpStrc* __fastcall DRLG_GetDrlgWarpFromLevelId(D2DrlgStrc* pDrlg, int nLevelId); // 0x00642860
D2DrlgWarpStrc* __fastcall DRLG_SetWarpId(D2DrlgWarpStrc* pDrlgWarp, int nVis, int nWarp, int nShift); // 0x00642920
int __fastcall DRLG_CheckOverlappingWithOrthogonalMargin(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMargin); // 0x0066B880
int __fastcall DRLG_GetDirectionFromCoordinates(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2); // 0x00642240
int* __fastcall DRLGWARP_GetWarpIdArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId); // 0x0066AEC0
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId); // 0x0066C040
void __fastcall DRLGROOM_AddOrth(D2DrlgOrthStrc** ppDrlgOrth, D2DrlgLevelStrc* pLevel, int nDirection, int bIsPreset);

int __fastcall DRLGOUTPLACE_LinkAct1Wilderness(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration); // 0x00676DD0
int __fastcall DRLGOUTPLACE_LinkAct1Monastery(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration); // 0x00676EB0
int __fastcall DRLGOUTPLACE_LinkAct2Outdoors(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration); // 0x00676F50
int __fastcall DRLGOUTPLACE_LinkAct2Canyon(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration); // 0x00676FC0
int __fastcall DRLGOUTPLACE_LinkAct5Ubers(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration); // 0x00677030
int __fastcall DRLGOUTPLACE_LinkAct4Outdoors(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration); // 0x006770A0
int __fastcall DRLGOUTPLACE_LinkAct4ChaosSanctum(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration); // 0x00677110
void __fastcall DRLGOUTPLACE_SetAct1OutdoorFlags(D2DrlgLevelStrc* pLevel, int nIteration, int* pRand); // 0x00677180

extern D2DrlgLinkStrc gAct1WildernessDrlgLink[15]; // 0x006F0750
extern D2DrlgLinkStrc gAct1MonasteryDrlgLink[15]; // 0x006F0840
extern D2DrlgLinkStrc gAct2OutdoorDrlgLink[15]; // 0x006F0930
extern D2DrlgLinkStrc gAct2CanyonDrlgLink[15]; // 0x006F0A20
extern D2DrlgLinkStrc gAct5UbersDrlgLink[15]; // 0x006F0B10
extern D2DrlgLinkStrc gAct4OutdoorDrlgLink[15]; // 0x006F0C00
extern D2DrlgLinkStrc gAct4ChaosSanctumDrlgLink[15]; // 0x006F0CF0
extern D2DrlgLinkStrc gAct5OutdoorDrlgLink[15];
extern D2DrlgLinkStrc gAct5TundraDrlgLink[15];
// build: symbol ?gnDrlgLinkFlags@* 0x0096D66C
extern int gnDrlgLinkFlags;

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x006772C0
static void __stdcall DRLGOUTPLACE_InitLevelLinks(D2DrlgLinkStrc* pDrlgLink, LINKFN pfLink, FLAGFN pfFlag, D2DrlgStrc* pDrlg)
{
    D2DrlgLevelLinkDataStrc pLevelLinkData = {};
    D2LevelDefBin* pLevelDefBinRecord = 0;
    D2DrlgPresetInfoStrc* pPresetInfo = 0;
    D2DrlgLevelStrc* pLevel = 0;
    D2DrlgLinkStrc* pLink;
    int nLevelId = 0;
    int nCounter = 0;
    int nVisEx = 0;
    int nVis = 0;

    for (int i = 0; i < 15; ++i)
    {
        pLevelLinkData.nRand[2][i] = -1;
        pLevelLinkData.nRand[3][i] = -1;
        pLevelLinkData.nRand[0][i] = -1;
        pLevelLinkData.nRand[1][i] = -1;
    }

    pLevelLinkData.pLink = pDrlgLink;
    pLevelLinkData.pSeed = pDrlg->pSeed;

    for (int i = 0; pDrlgLink[i].nLevel; ++i)
    {
        pLevelDefBinRecord = DATATBLS_GetLevelDefRecord(pDrlgLink[i].nLevel);

        pLevelLinkData.pLevelCoord[i].nWidth = pLevelDefBinRecord->dwSizeX[pDrlg->nDifficulty];
        pLevelLinkData.pLevelCoord[i].nHeight = pLevelDefBinRecord->dwSizeY[pDrlg->nDifficulty];
    }

    nCounter = 0;
    pLink = pDrlgLink;
    while (pLink->nLevel)
    {
        pLevelLinkData.nIteration = nCounter;
        pLevelLinkData.nCurrentLevel = pLink->nLevel;

        if (!pLink->pfLinker(&pLevelLinkData))
        {
            pLevelLinkData.nRand[2][nCounter] = -1;
            pLevelLinkData.nRand[3][nCounter] = -1;
            pLevelLinkData.nRand[0][nCounter] = -1;
            pLevelLinkData.nRand[1][nCounter] = -1;

            --nCounter;
        }
        else if (!pfLink || pfLink(&pLevelLinkData, nCounter))
        {
            ++nCounter;
        }

        pLink = &pDrlgLink[nCounter];
    }

    nCounter = 0;
    pLink = pDrlgLink;
    while (pLink->nLevel)
    {
        nLevelId = pLink->nLevel;

        if (pLink->nLevelLink == -1)
        {
            nVis = 0;
        }
        else
        {
            nVis = pDrlgLink[pLink->nLevelLink].nLevel;
        }

        if (pLink->nLevelLinkEx == -1)
        {
            nVisEx = 0;
        }
        else
        {
            nVisEx = pDrlgLink[pLink->nLevelLinkEx].nLevel;
        }

        pLevel = DRLG_GetLevel(pDrlg, nLevelId);

        pLevel->pLevelCoords = pLevelLinkData.pLevelCoord[nCounter];

        if (pLevel->nDrlgType == DRLGTYPE_PRESET)
        {
            pPresetInfo = pLevel->pPreset;
            switch (pLevel->eLevelId)
            {
            case 1:
                pPresetInfo->nDirection = pLevelLinkData.nRand[0][nCounter];
                break;
            case 0x28:
                pPresetInfo->nDirection = pLevelLinkData.nRand[0][nCounter + 1];
                break;
            }
        }

        if (pLevel->eLevelId == 6)
        {
            D2DrlgLevelStrc* pOuterLevel = DRLG_GetLevel(pDrlg, 0x1B);
            pPresetInfo = pOuterLevel->pPreset;
            switch (pLevelLinkData.nRand[0][nCounter])
            {
            case 1:
                pPresetInfo->nDirection = ((unsigned char)SEED_RollRandomNumber(&pDrlg->pSeed) & 1) ? 1 : 2;
                break;
            case 3:
                pPresetInfo->nDirection = ~(unsigned char)SEED_RollRandomNumber(&pDrlg->pSeed) & 1;
                break;
            }
        }

        if (pfFlag)
        {
            pfFlag(pLevel, nCounter, pLevelLinkData.nRand[0]);
        }

        if (pDrlg->nAct != 4)
        {
            if (nVis)
            {
                D2DrlgWarpStrc* pDrlgWarp1 = DRLG_GetDrlgWarpFromLevelId(pDrlg, nLevelId);
                D2DrlgWarpStrc* pDrlgWarp2 = DRLG_GetDrlgWarpFromLevelId(pDrlg, nVis);
                DRLG_SetWarpId(pDrlgWarp1, nVis, -1, -1);
                DRLG_SetWarpId(pDrlgWarp2, nLevelId, -1, -1);
            }

            if (nVisEx)
            {
                D2DrlgWarpStrc* pDrlgWarp1 = DRLG_GetDrlgWarpFromLevelId(pDrlg, nLevelId);
                D2DrlgWarpStrc* pDrlgWarp2 = DRLG_GetDrlgWarpFromLevelId(pDrlg, nVisEx);
                DRLG_SetWarpId(pDrlgWarp1, nVisEx, -1, -1);
                DRLG_SetWarpId(pDrlgWarp2, nLevelId, -1, -1);
            }
        }

        ++nCounter;
        pLink = &pDrlgLink[nCounter];
    }
}

// 0x006775C0
static void __stdcall DRLGOUTPLACE_SetOverlapWarps(int nStartId, int nEndId, D2DrlgStrc* pDrlg)
{
    for (int i = nStartId; i <= nEndId; ++i)
    {
        D2DrlgLevelStrc* pLevel = DRLG_GetLevel(pDrlg, i);
        D2DrlgWarpStrc* pDrlgWarp = DRLG_GetDrlgWarpFromLevelId(pDrlg, i);

        for (int j = nStartId; j <= nEndId; ++j)
        {
            if (i != j)
            {
                D2DrlgLevelStrc* pOtherLevel = DRLG_GetLevel(pDrlg, j);
                if (DRLG_CheckOverlappingWithOrthogonalMargin((D2DrlgCoordStrc*)&pLevel->nPosX, (D2DrlgCoordStrc*)&pOtherLevel->nPosX, -1))
                {
                    DRLG_SetWarpId(pDrlgWarp, j, -1, -1);
                }
            }
        }
    }
}

// 0x00677640
static __forceinline void DRLGOUTPLACE_AddOrthToLevel(D2DrlgLevelStrc* pLevel, int nLevelId)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    D2DrlgLevelStrc* pWarpLevel = DRLG_GetLevel(pLevel->pDrlg, nLevelId);
    const int nDirection = DRLG_GetDirectionFromCoordinates((D2DrlgCoordStrc*)&pLevel->nPosX, (D2DrlgCoordStrc*)&pWarpLevel->nPosX);
    DRLGROOM_AddOrth(&pOutdoors->pRoomData, pWarpLevel, nDirection, pWarpLevel->nDrlgType == DRLGTYPE_PRESET);
}

// 0x00677680
static void __stdcall DRLGOUTPLACE_AddLevelOrths(D2DrlgStrc* pDrlg, int nEndId, int nStartId)
{
    for (int i = nStartId; i <= nEndId; ++i)
    {
        D2DrlgLevelStrc* pLevel = DRLG_GetLevel(pDrlg, i);

        if (pLevel->nDrlgType == DRLGTYPE_OUTDOOR)
        {
            int* pVisArray = DRLGROOM_GetVisArrayFromLevelId(pDrlg, i);
            int* pWarpIdArray = DRLGWARP_GetWarpIdArrayFromLevelId(pDrlg, i);

            for (int j = 0; j < 8; ++j)
            {
                if (pVisArray[j] && pWarpIdArray[j] == -1)
                {
                    DRLGOUTPLACE_AddOrthToLevel(pLevel, pVisArray[j]);
                }
            }
        }
    }
}

// 0x00677750
static __declspec(noinline) void DRLGOUTPLACE_CreateAct1LevelConnections(D2DrlgStrc* pDrlg)
{
    DRLGOUTPLACE_InitLevelLinks(gAct1WildernessDrlgLink, DRLGOUTPLACE_LinkAct1Wilderness, DRLGOUTPLACE_SetAct1OutdoorFlags, pDrlg);
    DRLGOUTPLACE_InitLevelLinks(gAct1MonasteryDrlgLink, DRLGOUTPLACE_LinkAct1Monastery, DRLGOUTPLACE_SetAct1OutdoorFlags, pDrlg);
    DRLGOUTPLACE_AddLevelOrths(pDrlg, 0x11, 1);
}

// 0x00677790
static __declspec(noinline) void DRLGOUTPLACE_CreateAct2LevelConnections(D2DrlgStrc* pDrlg)
{
    DRLGOUTPLACE_InitLevelLinks(gAct2OutdoorDrlgLink, DRLGOUTPLACE_LinkAct2Outdoors, 0, pDrlg);
    DRLGOUTPLACE_InitLevelLinks(gAct2CanyonDrlgLink, DRLGOUTPLACE_LinkAct2Canyon, 0, pDrlg);
    DRLGOUTPLACE_AddLevelOrths(pDrlg, 0x2E, 0x28);
}

// 0x00678A20
static __declspec(noinline) void DRLGOUTPLACE_CreateAct4LevelConnections(D2DrlgStrc* pDrlg)
{
    DRLGOUTPLACE_InitLevelLinks(gAct4OutdoorDrlgLink, DRLGOUTPLACE_LinkAct4Outdoors, 0, pDrlg);
    DRLGOUTPLACE_InitLevelLinks(gAct4ChaosSanctumDrlgLink, DRLGOUTPLACE_LinkAct4ChaosSanctum, 0, pDrlg);

    DRLG_GetLevel(pDrlg, 0x68)->pOutdoors->dwFlags |= gnDrlgLinkFlags;

    DRLGOUTPLACE_AddLevelOrths(pDrlg, 0x6A, 0x67);
}

// 0x00678A70
static __declspec(noinline) void DRLGOUTPLACE_CreateAct5LevelConnections(D2DrlgStrc* pDrlg)
{
    DRLGOUTPLACE_InitLevelLinks(gAct5OutdoorDrlgLink, 0, 0, pDrlg);
    DRLGOUTPLACE_InitLevelLinks(gAct5TundraDrlgLink, 0, 0, pDrlg);

    DRLGOUTPLACE_SetOverlapWarps(0x6F, 0x70, pDrlg);
    DRLGOUTPLACE_AddLevelOrths(pDrlg, 0x70, 0x6F);

    DRLGOUTPLACE_SetOverlapWarps(0x6E, 0x6F, pDrlg);
    DRLGOUTPLACE_SetOverlapWarps(0x6D, 0x6E, pDrlg);

    DRLGOUTPLACE_InitLevelLinks(gAct5UbersDrlgLink, DRLGOUTPLACE_LinkAct5Ubers, 0, pDrlg);
}

__declspec(noinline) D2DrlgLevelStrc* __stdcall DRLGOUTPLACE_PlaceKurastLevels(D2DrlgLevelStrc* pLevel); // 0x00678910
// 0x00678910
D2DrlgLevelStrc* __stdcall DRLGOUTPLACE_PlaceKurastLevels(D2DrlgLevelStrc* pLevel)
{
    D2LevelDefBin* pLevelDef;
    D2DrlgLevelStrc* pAdjacentLevel;
    int nSizeX;
    int nSizeY;
    D2DrlgStrc* pDrlg = pLevel->pDrlg;
    int nHalfWidth = pLevel->nWidth / 2;
    int nPosY = 0;

    for (int i = 0; i < 5; ++i)
    {
        pLevelDef = DATATBLS_GetLevelDefRecord(79 + i);
        nSizeX = pLevelDef->dwSizeX[pDrlg->nDifficulty];
        nSizeY = pLevelDef->dwSizeY[pDrlg->nDifficulty];
        nPosY -= nSizeY;
        pAdjacentLevel = DRLG_GetLevel(pDrlg, 79 + i);
        const int nOffsetX = nHalfWidth - nSizeX / 2;
        pAdjacentLevel->nPosX = nOffsetX + pLevel->nPosX;
        pAdjacentLevel->nPosY = pLevel->nPosY + nPosY;
        pAdjacentLevel->nWidth = nSizeX;
        pAdjacentLevel->nHeight = nSizeY;
    }

    return pAdjacentLevel;
}

static __declspec(noinline) void DRLGOUTPLACE_CreateAct3LevelConnections(D2DrlgStrc* pDrlg);
// 0x006789B0
static void DRLGOUTPLACE_CreateAct3LevelConnections(D2DrlgStrc* pDrlg)
{
    D2DrlgLevelStrc* pLevel = DRLG_GetLevel(pDrlg, 75);
    D2LevelDefBin* pDef = DATATBLS_GetLevelDefRecord(75);
    pLevel->nPosX = pDef->dwOffsetX;
    pLevel->nPosY = pDef->dwOffsetY;
    pLevel->nWidth = pDef->dwSizeX[pDrlg->nDifficulty];
    pLevel->nHeight = pDef->dwSizeY[pDrlg->nDifficulty];
    pLevel = DRLG_GenerateJungles(pLevel);
    DRLGOUTPLACE_PlaceKurastLevels(pLevel);
    DRLGOUTPLACE_SetOverlapWarps(75, 83, pDrlg);
    DRLGOUTPLACE_AddLevelOrths(pDrlg, 83, 75);
}

// 0x00678AD0
void __fastcall DRLGOUTPLACE_CreateLevelConnections(D2DrlgStrc* pDrlg, unsigned char nAct)
{
    switch (nAct)
    {
    case 0: DRLGOUTPLACE_CreateAct1LevelConnections(pDrlg); break; // 0x00677750
    case 1: DRLGOUTPLACE_CreateAct2LevelConnections(pDrlg); break; // 0x00677790
    case 2: DRLGOUTPLACE_CreateAct3LevelConnections(pDrlg); break; // 0x006789B0
    case 3: DRLGOUTPLACE_CreateAct4LevelConnections(pDrlg); break; // 0x00678A20
    case 4: DRLGOUTPLACE_CreateAct5LevelConnections(pDrlg); break; // 0x00678A70
    }
}
