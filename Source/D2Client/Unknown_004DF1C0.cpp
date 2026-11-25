#include "D2Client.h"

#include "D2Structs.h"

#include "D2DataTbls.h"

#include "D2Txt.h"

#include "D2GameTypes.h"

#include "D2DrlgMaps.h"

#include "D2ClientUi.h"

#include "D2ClientSound.h"
#include "D2ClientTileLight.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define SKILLS_GetSkillsTxtRecord_E1120(nSkillId) \
    ((nSkillId) >= 0 && (nSkillId) < sgptDataTables->nSkillsTxtRecordCount ? &sgptDataTables->pSkillsTxt[nSkillId] : 0)

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


struct D2UnitLightNodeStrc
{
    int unk0x00;
    int nX;
    int nY;
    D2CellPosStrc* pPos;
    D2UnitLightNodeStrc* pNext;
};

struct D2TileLightEntryStrc
{
    int unk0x00[5];
    D2TileLightNodeStrc* pFadeList;
    D2UnitLightNodeStrc* pUnitList;
    int unk0x1C;
    D2TileLightNodeStrc* pList;
};

struct D2TileLightCtxStrc
{
    int unk0x00;
    int nX;
    int nY;
    int unk0x0C[6];
    int f_24;
    int f_28;
    char unk0x2C[0xEAA8 - 0x2C];
    D2TileLightEntryStrc* pEntries;
    int unk0xEAAC;
    unsigned int nSize;
};

extern D2LightOffsetsStrc gaLightOffsetsA[]; // 0x0072ABC8

extern D2LightOffsetsStrc gaLightOffsetsB[]; // 0x0072A9E8

int __cdecl sub_0045AE90(); // 0x0045AE90

int __cdecl DLIGHTMAP_GetRenderMode(); // 0x00477730

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

void __fastcall SCMD_ReadGridCell(int nX, int nY, unsigned char* pValue0, unsigned char* pValue1, unsigned char* pValue2, unsigned char* pValue3); // 0x00475AA0

int __stdcall TILE_TileDrawTrans(D2TileLibraryEntryStrc* pTile, int nXPos, int nYPos, D2GfxLightStrc* pLight, int nScreenPanels, unsigned char nAlpha); // 0x004F6950

int __stdcall TILE_TileDrawLit(D2TileLibraryEntryStrc* pTile, int nXPos, int nYPos, D2GfxLightStrc* pLight, int nScreenPanels); // 0x004F6920


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* pAddress, unsigned long nSize, unsigned long nType, unsigned long nProtect); // 0x006CC21C

extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, unsigned long nSize, unsigned long nFreeType); // 0x006CC220

extern "C" __declspec(dllimport) int __stdcall VirtualProtect(void* pAddress, unsigned long nSize, unsigned long nNewProtect, unsigned long* pOldProtect); // 0x006CC360

extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName); // 0x006CC144

extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName); // 0x006CC148

extern "C" __declspec(dllimport) int __stdcall FlushInstructionCache(void* hProcess, const void* pBaseAddress, unsigned long nSize); // 0x006CC35C

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize); // 0x006829C0

struct WardenSectionStrc
{
    unsigned int dwRva;
    unsigned int dwSize;
    unsigned int dwProtect;
};

struct WardenHeaderStrc
{
    unsigned int dwImageSize;
    unsigned int unk0x04;
    unsigned int dwRelocOffset;
    unsigned int nRelocCount;
    unsigned int unk0x10[3];
    unsigned int dwImportOffset;
    unsigned int nImportCount;
    unsigned int nSections;
};

struct WardenRawModuleStrc
{
    WardenHeaderStrc tHeader;
    WardenSectionStrc aSections[1];
};

struct WardenImportStrc
{
    unsigned int dwNameOffset;
    unsigned int dwThunkOffset;
};

class WardenModule
{
public:
    ~WardenModule();                                                                // 0x004E06A0
    bool sub_004E0730_Load(void* pData, int nSize);

    void* pImage;
    int unk0x04;
    int nImports;
    int unk0x0C;
    void* pEntry;
};

struct D2RC4Strc
{
    unsigned char S[0x100];
    unsigned char i;
    unsigned char j;

    void sub_004E09B0_Init(const unsigned char* pKey, unsigned int nKeySize);
    void ApplyKeystream(unsigned char* pData, unsigned int nSize);       // 0x0047F8C0
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern const unsigned char gaDirection64To4[64]; // 0x006DBA60

extern const unsigned char gaDirection4[4]; // 0x006DBA58

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540

void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection); // 0x006488A0

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330

static D2LightOffsetsStrc* __stdcall sub_004DEDB0_GetLightOffsets(D2TileLibraryEntryStrc* pTile, unsigned int* pCount, int bAlternate)
{
// build: symbol ?gaLightSampleCounts@* 0x006DB9D8
    *pCount = gaLightSampleCounts[pTile->nLightDirection];
    if (bAlternate)
        return &gaLightOffsetsA[pTile->nLightDirection];
    return &gaLightOffsetsB[pTile->nLightDirection];
}

// 0x004DF1C0
void __fastcall sub_004DF1C0_UpdateFadingTileLights(D2TileLightCtxStrc* pCtx)
{
    int nCount = pCtx->nSize * pCtx->nSize;
    D2TileLightEntryStrc* pEntry = pCtx->pEntries;
    while (nCount--)
    {
        if (pEntry->pFadeList)
        {
            const int nScreenPanels = sub_0045AE90();
            const int bPerspective = sub_004F51D0_IsPerspective();
            const int nLightDetail = DLIGHTMAP_GetRenderMode();
            const unsigned int nTick = GetTickCount();
            const int bFade = nLightDetail >= 4;
            for (D2TileLightNodeStrc* pNode = pEntry->pFadeList; pNode; pNode = pNode->pNext)
            {
                D2DrlgTileDataStrc* pTileData = pNode->pTileData;
                D2_ASSERT(pTileData->nTileType != 15, 0xF9);

                const unsigned int dwLightFlags = pTileData->dwPopFlags;
                if (dwLightFlags & 2)
                {
                    if (bFade)
                    {
                        if (nTick < pTileData->nPopTick)
                        {
                            pTileData->nRed = pTileData->nGreen + (pTileData->nBlue - pTileData->nGreen) * (int)(nTick - pTileData->nPopTick + 500) / 500;
                        }
                        else
                        {
                            unsigned char* pAlpha = &pTileData->nRed;
                            *pAlpha = pTileData->nBlue;
                            pTileData->dwPopFlags = dwLightFlags & ~2;
                        }
                    }
                    else
                    {
                        unsigned char* pAlpha = &pTileData->nRed;
                        *pAlpha = pTileData->nBlue;
                        pTileData->dwPopFlags = dwLightFlags & ~2;
                    }

                    if (!pTileData->nRed)
                        pTileData->dwFlags |= 0x400;
                    else
                        pTileData->dwFlags &= ~0x400;
                }

                if ((pTileData->dwPopFlags & 4) && nTick >= pTileData->nPopTick)
                {
                    pTileData->dwPopFlags &= ~4;
                    pTileData->dwFlags |= 8;
                }

                if (pTileData->dwFlags & 0x408)
                    continue;

                if (!(pTileData->dwFlags & 0x1C000))
                    continue;

                unsigned int nLights;
                D2LightOffsetsStrc* pOffsets = sub_004DEDB0_GetLightOffsets(pTileData->pTile, &nLights, pTileData->dwPopFlags & 1);
                D2GfxLightStrc tLight;
                for (unsigned int i = 0; i < nLights; ++i)
                {
                    unsigned char nValue0;
                    unsigned char nValue1;
                    unsigned char nValue2;
                    unsigned char nValue3;
                    SCMD_ReadGridCell(pNode->nX + 8 * pOffsets->aOffset[i].nX, pNode->nY + 8 * pOffsets->aOffset[i].nY, &nValue0, &nValue1, &nValue2, &nValue3);
                    nValue0 = nValue0 > 0 ? nValue0 : 0;
                    tLight.aColor[i] = (nValue3 << 24) | (nValue2 << 16) | (nValue1 << 8) | nValue0;
                }

                const unsigned char nAlpha = pTileData->nRed;
                int nX;
                int nY;
                if (bPerspective)
                {
                    nX = pNode->nX;
                    nY = pNode->nY;
                }
                else
                {
                    nX = pCtx->nX - pCtx->f_24 + pTileData->nWidth;
                    nY = pTileData->nHeight - pCtx->f_28 + pCtx->nY;
                }

                int bDrawn;
                if (nAlpha != 0xFF)
                    bDrawn = TILE_TileDrawTrans(pTileData->pTile, nX, nY, &tLight, nScreenPanels, nAlpha);
                else
                    bDrawn = TILE_TileDrawLit(pTileData->pTile, nX, nY, &tLight, nScreenPanels);

                if (bDrawn)
                    pTileData->dwFlags |= 0x20000;
            }
        }

        for (D2UnitLightNodeStrc* pUnitNode = pEntry->pUnitList; pUnitNode; pUnitNode = pUnitNode->pNext)
        {
            unsigned char nValue0;
            unsigned char nValue1;
            unsigned char nValue2;
            unsigned char nValue3;
            SCMD_ReadGridCell(pUnitNode->nX, pUnitNode->nY, &nValue0, &nValue1, &nValue2, &nValue3);
            sub_004DC7B0(pUnitNode->pPos, (nValue3 << 24) | (nValue2 << 16) | (nValue1 << 8) | nValue0, 0);
        }

        ++pEntry;
    }
}

// 0x004E0730
bool WardenModule::sub_004E0730_Load(void* pData, int nSize)
{
    int bFailed = 1;
    __try
    {
        WardenRawModuleStrc* pRaw = (WardenRawModuleStrc*)pData;
        unk0x04 = pRaw->tHeader.dwImageSize;
        pImage = VirtualAlloc(0, unk0x04, 0x1000, 4);
        if (!pImage)
        {
            __leave;
        }

        *(WardenHeaderStrc*)pImage = pRaw->tHeader;

        unsigned char* pChunk = (unsigned char*)&pRaw->aSections[((WardenHeaderStrc*)pImage)->nSections];
        unsigned char* pDest = (unsigned char*)pImage + pRaw->aSections[0].dwRva;
        unsigned char* pEnd = (unsigned char*)pImage + ((WardenHeaderStrc*)pImage)->dwImageSize;
        bool bCopy = true;
        while (pDest < pEnd)
        {
            unsigned short nLength = *(unsigned short*)pChunk;
            pChunk += 2;
            if (bCopy)
            {
                memcpy(pDest, pChunk, nLength);
                pChunk += nLength;
            }
            pDest += nLength;
            if (pDest >= pEnd)
            {
                break;
            }
            bCopy = !bCopy;
        }

        unsigned char* pReloc = (unsigned char*)pImage + ((WardenHeaderStrc*)pImage)->dwRelocOffset;
        unsigned int nOffset = 0;
        for (unsigned int i = 0; i < ((WardenHeaderStrc*)pImage)->nRelocCount; ++i)
        {
            if (pReloc[0] & 0x80)
            {
                nOffset = (((((pReloc[0] & 0x7F) << 8) + pReloc[1]) << 8) + pReloc[2] << 8) + pReloc[3];
                pReloc += 4;
            }
            else
            {
                nOffset += (pReloc[0] << 8) + pReloc[1];
                pReloc += 2;
            }
            *(unsigned int*)((unsigned char*)pImage + nOffset) += (unsigned int)pImage;
        }

        WardenImportStrc* pImports = (WardenImportStrc*)((unsigned char*)pImage + ((WardenHeaderStrc*)pImage)->dwImportOffset);
        for (unsigned int j = 0; j < ((WardenHeaderStrc*)pImage)->nImportCount; ++j)
        {
            const char* const szLibrary = (const char*)pImage + pImports[j].dwNameOffset;
            void* hLibrary = LoadLibraryA(szLibrary);
            if (!hLibrary)
            {
                __leave;
            }
            for (unsigned int* pThunk = (unsigned int*)((unsigned char*)pImage + pImports[j].dwThunkOffset); *pThunk; ++pThunk)
            {
                if (*pThunk & 0x80000000)
                {
                    *pThunk = (unsigned int)GetProcAddress(hLibrary, (const char*)(*pThunk & 0x7FFFFFFF));
                }
                else
                {
                    *pThunk = (unsigned int)GetProcAddress(hLibrary, (const char*)pImage + *pThunk);
                }
            }
            ++nImports;
        }

        for (unsigned int k = 0; k < ((WardenHeaderStrc*)pImage)->nSections; ++k)
        {
            WardenSectionStrc* pSection = &pRaw->aSections[k];
            void* pAddress = (unsigned char*)pImage + pSection->dwRva;
            unsigned long nLength = pSection->dwSize;
            unsigned long dwOldProtect;
            VirtualProtect(pAddress, nLength, pSection->dwProtect, &dwOldProtect);
            if (pSection->dwProtect & 0xF0)
            {
                FlushInstructionCache(GetCurrentProcess(), pAddress, nLength);
            }
        }

        if (((WardenHeaderStrc*)pImage)->dwRelocOffset < ((WardenHeaderStrc*)pImage)->dwImageSize)
        {
            const unsigned int nRelocStart = ((WardenHeaderStrc*)pImage)->dwRelocOffset;
            const unsigned int nPage = (nRelocStart + 0xFFF) & 0xFFFFF000;
            if (nPage >= nRelocStart && nPage < ((WardenHeaderStrc*)pImage)->dwImageSize)
            {
                VirtualFree((unsigned char*)pImage + nPage, ((WardenHeaderStrc*)pImage)->dwImageSize - nPage, 0x4000);
            }
        }
        bFailed = 0;
    }
    __except (1)
    {
    }

    if (bFailed)
    {
        this->~WardenModule();
    }
    return !bFailed;
}

// 0x004E09B0
void D2RC4Strc::sub_004E09B0_Init(const unsigned char* pKey, unsigned int nKeySize)
{
    for (unsigned int n = 0; n < 0x100; ++n)
    {
        S[n] = (unsigned char)n;
    }
    i = 0;
    j = 0;
    unsigned char k = 0;
    unsigned char b = 0;
    unsigned int n = 0;
    do
    {
        b += pKey[k] + S[n];
        unsigned char* pA = &S[n];
        unsigned char* pB = &S[b];
        unsigned char t = *pA;
        *pA = *pB;
        *pB = t;
        k = (unsigned char)((k + 1) % nKeySize);
        ++n;
    } while (n < 0x100);
}

static int CLT_Abs(int nValue)
{
    return nValue < 0 ? -nValue : nValue;
}

// 0x004E1120
int __fastcall sub_004E1120_SkillCreateTargetMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord_E1120(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    const int nMissile = pSkillsTxt->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    const int nTargetX = CLIENTS_GetUnitX(pTarget);
    const int nTargetY = CLIENTS_GetUnitY(pTarget);
    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    int nEndX = nTargetX;
    int nEndY = nTargetY;
    int nSteps = 4;
    if (CLT_Abs(nTargetX - nX) < CLT_Abs(nTargetY - nY))
    {
        nEndX = nX;
        do
        {
            if (nEndX > nTargetX)
            {
                --nEndX;
            }
            else if (nEndX < nTargetX)
            {
                ++nEndX;
            }
        }
        while (--nSteps > 0);
    }
    else
    {
        nEndY = nY;
        do
        {
            if (nEndY > nTargetY)
            {
                --nEndY;
            }
            else if (nEndY < nTargetY)
            {
                ++nEndY;
            }
        }
        while (--nSteps > 0);
    }

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 3;
    tMissile.pOwner = pUnit;
    tMissile.nTargetX = nEndX - nX;
    tMissile.nTargetY = nEndY - nY;
    tMissile.nX = nX + tMissile.nTargetX / 6 - 1;
    tMissile.nY = nY + tMissile.nTargetY / 6 - 1;
    tMissile.nSkill = nSkillId;
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nMissile = nMissile;
    sub_006488A0_SetDirection(pUnit->pDynamicPath, gaDirection4[gaDirection64To4[UNITS_GetDirectionToCoords(pUnit, nEndX, nEndY) & 0x3F] & 3]);
    MISSILE_CreateClientMissile(&tMissile);
    return 1;
}

#include "gen/data/Source/D2Client/Unknown_004DF1C0.inc"

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static inline D2MissilesTxt* sub_004E1400_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile)
    {
        const int nMissileId = pMissile->dwClassId;
        if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        {
            return &sgptDataTables->pMissilesTxt[nMissileId];
        }
    }

    return 0;
}

// 0x004E1400
static int __stdcall sub_004E1400_UpdateInfernoAnimation(D2UnitStrc* pUnit, D2UnitStrc* pMissile, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = sub_004E1400_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    int nFrame = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nFrame <= 0)
    {
        nFrame = pMissilesTxtRecord->dwParam[1] + nSkillLevel - 1;
    }

    nFrame = D2_MIN(D2_MAX(nFrame, 1), 255);

    PATH_SetNewDistance(pMissile->pDynamicPath, nFrame);
    UNITS_SetAnimationSpeed(pMissile, (pMissilesTxtRecord->nAnimLen << 8) / nFrame);
    MISSILE_SetTotalFrames(pMissile, nFrame);
    MISSILE_SetCurrentFrame(pMissile, nFrame);
    return 1;
}

int __fastcall sub_004E1400_EmitCaller(D2UnitStrc* pUnit, D2UnitStrc* pMissile, int nSkillId, int nSkillLevel)
{
    return sub_004E1400_UpdateInfernoAnimation(pUnit, pMissile, nSkillId, nSkillLevel);
}
