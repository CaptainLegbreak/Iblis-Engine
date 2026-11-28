#include "D2Client.h"

#include "D2Constants.h"

#include "D2Structs.h"

#include "D2Path.h"

#include "D2Structs.h"

#include "D2DataTbls.h"

#include "D2GameTypes.h"

#include "D2ClientUi.h"

#include "D2Txt.h"
#include "D2CommonApi.h"
#include "D2CommonApi2.h"
#include "D2CommonApi3.h"

struct D2GridCellStrc
{
    int unk0x00[4];
    D2CellNodeStrc* pNodes;
    int f_14;
    int unk0x18[3];
};

struct D2CellGridViewStrc
{
    int unk0x00;
    int nOffsetX;
    int nOffsetY;
    int unk0x0C[6];
    int nScrollX;
    int nScrollY;
    char unk0x2C[0xEA7C];
    D2GridCellStrc* pCells;
    char unk0xEAAC[0x04];
    int nSize;
    void __thiscall sub_004DF510_DrawCellNodes();
};

int __cdecl sub_0045AE90_GetPanelSlideMode(); // 0x0045AE90

void __fastcall SCMD_ReadGridCell(int nA, int nB, unsigned char* pByte0, unsigned char* pByte1, unsigned char* pByte2, unsigned char* pByte3); // 0x00475AA0

void __stdcall DWALL_DrawCellTiles(D2GridCellStrc* pCell, int nArg, D2CellGridViewStrc* pView); // 0x004DEF80

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern int gnEnvironLevelId; // 0x007C8C7C

extern int gnEnvironSoundHandle; // 0x007C8C80

extern int gnWeatherSoundHandle; // 0x007C8C84

extern int gnEnvironSoundId; // 0x007C8C88

extern int gnWeatherSoundId; // 0x007C8C8C

extern int gnEnvironAmbientId; // 0x007C8C90

extern int gnAmbientDelay; // 0x007C8C94

extern int gnAmbientTick; // 0x007C8C98

void __fastcall sub_004BA840_StopSound(int nHandle); // 0x004BA840

struct D2ClientModuleListStrc
{
    void* pBase;
    void* pUnknown04;
    int nModuleCount;
};

extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, unsigned int nSize, unsigned int nFreeType); // 0x006CC220




D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0




enum { SUCCESS_VALUE = 1 };

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0


D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540

int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0

void __fastcall sub_004E1970_SetInfernoFrames(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pUnit); // 0x004E1970

extern const int gaMissileVelocityPair[]; // 0x006DBAA0

extern const int gaMissileVelocityCharged[]; // 0x006DBB38

// 0x004DF4B0
static inline void sub_004DF4B0_DrawCellNode(D2CellGridViewStrc* pView, D2CellNodeStrc* pNode, int nArg)
{
    const int bMode = sub_004F51D0_IsPerspective();
    if (pNode->dwFlags & 1)
    {
        if (bMode)
        {
// build: symbol ?TILE_ShadowTileDraw@* 0x004F6980
            TILE_ShadowTileDraw(pNode->pPos->f_18, pNode->nA, pNode->nB, 4, nArg);
        }
        else
        {
            TILE_ShadowTileDraw(pNode->pPos->f_18, pView->nOffsetX - pView->nScrollX + pNode->pPos->nX, pNode->pPos->nY - pView->nScrollY + pView->nOffsetY, 4, nArg);
        }
    }
    else if (pNode->dwFlags & 2)
    {
// build: symbol ?GFX_DrawUnitShadow@* 0x00471620
        GFX_DrawUnitShadow(pNode->pPos);
    }
}

// 0x004DF510
void __thiscall D2CellGridViewStrc::sub_004DF510_DrawCellNodes()
{
    const int nCells = nSize;
    int nCount = nCells * nCells;
    D2GridCellStrc* pCell = pCells;
    const int nArg = sub_0045AE90_GetPanelSlideMode();
    while (nCount--)
    {
        for (D2CellNodeStrc* pNode = pCell->pNodes; pNode; pNode = pNode->pNext)
        {
            if (!(pNode->dwFlags & 3))
            {
                unsigned char nByte0;
                unsigned char nByte1;
                unsigned char nByte2;
                unsigned char nByte3;
                SCMD_ReadGridCell(pNode->nA, pNode->nB, &nByte0, &nByte1, &nByte2, &nByte3);
                sub_004DC7B0(pNode->pPos, (((nByte3 << 8 | nByte2) << 8 | nByte1) << 8) | nByte0, 0);
            }
            else
            {
                sub_004DF4B0_DrawCellNode(this, pNode, nArg);
            }
        }

        if (pCell->f_14)
        {
            DWALL_DrawCellTiles(pCell, 1, this);
        }
        ++pCell;
    }
}

// 0x00405A50
void __cdecl sub_00405A50_Nop()
{
}

// 0x00405A60
void __cdecl sub_00405A60_Nop()
{
}

// 0x0063A800
void __cdecl ITEMS_Nop()
{
}

// 0x00587830
void __cdecl OBJECTS_InitFunction70_Unused()
{
}

static inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord_Inline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004E3170
void __fastcall sub_004E3170_SetMissileFrames(D2UnitStrc* pMissile, int nDivisor)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && nDivisor)
    {
        D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord_Inline(pMissile->dwClassId);
        if (pMissilesTxtRecord)
        {
            UNITS_SetAnimationSpeed(pMissile, (pMissilesTxtRecord->nAnimLen << 8) / nDivisor);
        }
    }
}

// 0x004E4020
void __fastcall sub_004E4020_Nop(D2UnitStrc* pUnit)
{
}

// 0x004E4050
void __fastcall sub_004E4050_Nothing(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
}

extern const int gaMissileVelocityPair[6] = { -2, -1, 0, 1, 2 }; // 0x006DBAA0

extern const int gaMissileVelocityCharged[5] = { -1, -3, -2, -1 }; // 0x006DBB38

// 0x004E06A0
void __fastcall sub_004E06A0_FreeModules(D2ClientModuleListStrc* pList)
{
    if (!pList->pBase)
        return;
    unsigned char* pNames = (unsigned char*)pList->pBase + *(unsigned int*)((unsigned char*)pList->pBase + 0x1C);
    void* (__stdcall *pGetModuleHandleA)(const char*) = GetModuleHandleA;
    while (pList->nModuleCount > 0)
    {
        pList->nModuleCount--;
        const char* szName = (const char*)((unsigned char*)pList->pBase + *(unsigned int*)(pNames + pList->nModuleCount * 8));
        FreeLibrary(pGetModuleHandleA(szName));
    }
    VirtualFree(pList->pBase, 0, 0x8000);
    pList->pBase = 0;
    pList->pUnknown04 = 0;
}

// 0x004E0A30
int __fastcall sub_004E0A30_CltDoClearSeqSpeed(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    pUnit->dwSeqSpeed = 0;
    return 1;
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    return (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
}

static inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    return (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount) ? &sgptDataTables->pMissilesTxt[nMissileId] : 0;
}

static inline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static inline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static int __stdcall sub_004E1400_SetMissileFrames(D2UnitStrc* pUnit, int nSkillLevel, D2UnitStrc* pMissile, int nSkillId)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxt = pMissile ? DATATBLS_GetMissilesTxtRecord(pMissile->dwClassId) : 0;
    if (!pMissilesTxt)
    {
        return 0;
    }

    int nFrames = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[0], nSkillId, nSkillLevel);
    if (nFrames <= 0)
    {
        nFrames = pMissilesTxt->dwParam[1] + nSkillLevel - 1;
    }

    nFrames = nFrames > 1 ? (nFrames < 0xFF ? nFrames : 0xFF) : 1;

    PATH_SetNewDistance(pMissile->pDynamicPath, nFrames);
    UNITS_SetAnimationSpeed(pMissile, (pMissilesTxt->nAnimLen << 8) / nFrames);
    MISSILE_SetTotalFrames(pMissile, nFrames);
    MISSILE_SetCurrentFrame(pMissile, nFrames);
    return 1;
}

// 0x004E14D0
static D2UnitStrc* __stdcall sub_004E14D0_CreateSkillMissile(const int* pVelocityTable, int nTargetX, int nTargetY, int nSkillId, int nSkillLevel, D2UnitStrc* pUnit, int nMissileId)
{
    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x25;
    tMissile.pOwner = pUnit;
    if (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 4) > 0)
    {
        tMissile.dwFlags = 0x4025;
    }

    tMissile.nMissile = nMissileId;
    tMissile.nX = CLIENTS_GetUnitX(pUnit);
    tMissile.nY = CLIENTS_GetUnitY(pUnit);
    tMissile.nTargetX = nTargetX;
    tMissile.nTargetY = nTargetY;
    tMissile.nSkill = nSkillId;
    tMissile.nSkillLevel = nSkillLevel;

    D2MissilesTxt* pMissilesTxt = DATATBLS_GetMissilesTxtRecord(nMissileId);
    if (!pMissilesTxt)
    {
        return 0;
    }

    tMissile.nVelocity = pMissilesTxt->nVel + pVelocityTable[SEED_RollLimitedRandomNumber(&pUnit->pSeed, 5)];
    D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissile);
    if (!pMissile)
    {
        return 0;
    }

    sub_004E1400_SetMissileFrames(pUnit, nSkillLevel, pMissile, nSkillId);
    return pMissile;
}

// 0x004E1620
int __fastcall sub_004E1620_SkillCltDoMissilePair(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    const int nMissileA = pSkillsTxt->wCltMissileA;
    if (nMissileA < 0 || nMissileA >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    const int nMissileB = pSkillsTxt->wCltMissileB;
    int nX;
    int nY;
    if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    D2Common_10216(pUnit->pDynamicPath, nX, nY, 0);
    for (int nCount = 2; nCount; --nCount)
    {
        int nMissile = nMissileA;
        if (nMissileB > 0 && (SEED_RollRandomNumber(&pUnit->pSeed) & 1))
        {
            nMissile = nMissileB;
        }

        sub_004E14D0_CreateSkillMissile(gaMissileVelocityPair, nX, nY, nSkillId, nSkillLevel, pUnit, nMissile);
    }

    return 1;
}

// 0x004E1A20
int __fastcall sub_004E1A20_SkillCltDoChargedMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    const int nMissile = pSkillsTxt->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCltCalc[0], nSkillId, nSkillLevel);
    const int nParam = SKILLS_GetParam1(pSkill) + 1;
    if (nParam < nMax)
    {
        SKILLS_SetParam1(pSkill, nParam);
        return 0;
    }

    SKILLS_SetParam1(pSkill, 0);
    int nX;
    int nY;
    if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    D2Common_10216(pUnit->pDynamicPath, nX, nY, 0);
    sub_004E14D0_CreateSkillMissile(gaMissileVelocityCharged, nX, nY, nSkillId, nSkillLevel, pUnit, nMissile);
    sub_004E1970_SetInfernoFrames(pSkillsTxt, pUnit);
    return 1;
}

static D2MonStats2Txt* UNITS_GetMonStats2TxtRecordFromMonsterId_J03(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }

    return 0;
}

// 0x004E1970
void __fastcall sub_004E1970_SetInfernoFrames(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId_J03(pUnit->dwClassId);
        if (pMonStats2TxtRecord)
        {
            if (pSkillsTxtRecord->nMonAnim == 0xE)
            {
                UNITS_SetAnimationFrame(pUnit, pMonStats2TxtRecord->nInfernoAnim - 1);
                pUnit->dwFrameCountPrecise = (pMonStats2TxtRecord->nInfernoAnim + 1) << 8;
            }
            else
            {
                pUnit->nSeqCurrentFramePrecise = (pMonStats2TxtRecord->nInfernoAnim - 1) << 8;
            }
        }

        return;
    }

    UNITS_SetAnimationFrame(pUnit, 8);
    pUnit->dwFrameCountPrecise = 0x500;
}
