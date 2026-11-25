#include "D2MonsterIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

struct D2MonStatsTxt;

struct D2MonStats2Txt;

struct D2DataTablesStrc;

struct D2ShiftRowsStrc;


struct D2PalShiftNodeStrc;

struct D2PalShiftEntryStrc;

struct D2ShiftRowsStrc
{
    unsigned char aRows[8][256];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned char* gpBloodRemap_007BB384; // 0x007BB384

void __fastcall PALSHIFT_BuildBloodShift(D2PalShiftNodeStrc* pShift); // 0x00477060

static void PALSHIFT_BuildBloodShift(int nMonsterId, D2PalShiftNodeStrc* pShift); // 0x00477060

struct D2PalShiftNodeStrc
{
    int nId;
    D2ShiftRowsStrc tBase;
    D2ShiftRowsStrc tBlood;
    D2PalShiftNodeStrc* pNext;
};

struct D2PalShiftEntryStrc
{
    int nId;
    D2PalShiftNodeStrc* pShift;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __fastcall PALSHIFT_LoadPalShift(int nMonsterId); // 0x00477170

extern D2PalShiftNodeStrc* gpPalShiftList; // 0x007B957C

unsigned char gabGlobalPalShifts[0x1E][0x100]; // 0x007B9580

extern int gnGlobal_007B957C; // 0x007B957C

int gbGlobalPalShifts; // 0x007BB380

void* gpBloodRemap; // 0x007BB384

D2PalShiftEntryStrc* gpPalShiftEntries; // 0x007B9578

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

extern "C" char* __cdecl strcat(char* szDst, const char* szSrc);


D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80

int __fastcall DATATBLS_GetMonStatsTxtRecordCount();                                                        // 0x0045C460

D2PalShiftNodeStrc* __fastcall PALSHIFT_FindPalShiftNode(int nId);                                          // 0x00477030

int __fastcall ARCHIVE_OpenFile(void* hArchive, const char* szFilePath, void** phFile, int bFileNotFoundLogSkipped); // 0x00516E46

void __fastcall ARCHIVE_CloseFile(void* hArchive, void* hFile);                                             // 0x00516E84

void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85




static inline D2MonStats2Txt* UNITS_GetMonStats2TxtRecordFromMonsterId_Inl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nId = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nId >= 0 && nId < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nId];
        }
    }
    return 0;
}

// 0x00476E30
void __cdecl PALSHIFT_LoadGreenBlood()
{
    void* hFile;
    if (ARCHIVE_OpenFile(0, "Data\\Global\\Monsters\\GreenBlood.dat", &hFile, 1))
    {
        void* pBuffer = FOG_Alloc(0x100, ".\\GAME\\PalShift.cpp", 0x52, 0);
        gpBloodRemap = pBuffer;
        memset(pBuffer, 0, 0x100);
        ARCHIVE_ReadFileToBuffer(0, hFile, pBuffer, 0x100);
        ARCHIVE_CloseFile(0, hFile);
    }
}

// 0x00476EA0
void __cdecl PALSHIFT_AllocPalShiftEntries()
{
    int nSize = sgptDataTables->nMonStatsTxtRecordCount * sizeof(D2PalShiftEntryStrc);
    D2PalShiftEntryStrc* pEntries = (D2PalShiftEntryStrc*)FOG_Alloc(nSize, ".\\GAME\\PalShift.cpp", 0x63, 0);
    gpPalShiftEntries = pEntries;
    memset(pEntries, 0, nSize);
    int nCount = sgptDataTables->nMonStatsTxtRecordCount;
    for (int i = 0; i < nCount; ++i)
    {
        pEntries[i].nId = i;
    }
    gnGlobal_007B957C = 0;
    void* hFile;
    if (ARCHIVE_OpenFile(0, "Data\\Global\\Monsters\\RandTransforms.dat", &hFile, 1))
    {
        ARCHIVE_ReadFileToBuffer(0, hFile, gabGlobalPalShifts, 0x1E00);
        ARCHIVE_CloseFile(0, hFile);
        gbGlobalPalShifts = 1;
    }
    void* hFile2;
    if (ARCHIVE_OpenFile(0, "Data\\Global\\Monsters\\GreenBlood.dat", &hFile2, 1))
    {
        void* pBuffer = FOG_Alloc(0x100, ".\\GAME\\PalShift.cpp", 0x52, 0);
        gpBloodRemap = pBuffer;
        memset(pBuffer, 0, 0x100);
        ARCHIVE_ReadFileToBuffer(0, hFile2, pBuffer, 0x100);
        ARCHIVE_CloseFile(0, hFile2);
    }
}

// 0x00476FB0
void __cdecl PALSHIFT_FreePalShifts()
{
    while (gpPalShiftList)
    {
        D2PalShiftNodeStrc* pNext = gpPalShiftList->pNext;
        FOG_Free(gpPalShiftList, ".\\GAME\\PalShift.cpp", 0x84, 0);
        gpPalShiftList = pNext;
    }
    if (gpPalShiftEntries)
    {
        FOG_Free(gpPalShiftEntries, ".\\GAME\\PalShift.cpp", 0x8A, 0);
        gpPalShiftEntries = 0;
    }
    if (gpBloodRemap)
    {
        FOG_Free(gpBloodRemap, ".\\GAME\\PalShift.cpp", 0x90, 0);
        gpBloodRemap = 0;
    }
}



// 0x00477030
D2PalShiftNodeStrc* __fastcall PALSHIFT_FindPalShiftNode(int nId)
{
    for (D2PalShiftNodeStrc* pNode = gpPalShiftList; pNode; pNode = pNode->pNext)
    {
        if (pNode->nId == nId)
            return pNode;
    }
    return 0;
}

// 0x00477060
static void PALSHIFT_BuildBloodShift(int nMonsterId, D2PalShiftNodeStrc* pShift)
{
    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId_Inl(nMonsterId);
    if (!pMonStats2TxtRecord || pMonStats2TxtRecord->nLocalBlood != 2)
    {
        return;
    }

    pShift->tBlood = pShift->tBase;

    const unsigned char* pRemap = gpBloodRemap_007BB384;
    for (int nRow = 0; nRow < 8; ++nRow)
    {
        const unsigned char* pSrc = pShift->tBase.aRows[nRow];
        unsigned char* pDst = pShift->tBlood.aRows[nRow];
        for (int i = 0; i < 256; ++i)
        {
            const unsigned char nIndex = pSrc[i];
            if (pRemap[nIndex])
            {
                pDst[i] = pRemap[nIndex];
            }
        }
    }
}

// The original builds this function without optimization (its code keeps every value on the stack).
#pragma optimize("", off)
// 0x00477170
void __fastcall PALSHIFT_LoadPalShift(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord;
    char szCode[4];
    char szFile[256];
    void* hFile;
    D2PalShiftNodeStrc* pShift;

    pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    if (PALSHIFT_FindPalShiftNode(nMonsterId))
    {
        return;
    }

    szCode[0] = pMonStatsTxtRecord->szCode[0] != ' ' ? pMonStatsTxtRecord->szCode[0] : 0;
    szCode[1] = pMonStatsTxtRecord->szCode[1] != ' ' ? pMonStatsTxtRecord->szCode[1] : 0;
    szCode[2] = pMonStatsTxtRecord->szCode[2] != ' ' ? pMonStatsTxtRecord->szCode[2] : 0;
    szCode[3] = 0;
    szCode[2] = 0;

    strcpy(szFile, "Data\\Global\\Monsters\\");
    strcat(szFile, szCode);
    strcat(szFile, "\\Cof\\palshift.dat");

    if (!ARCHIVE_OpenFile(0, szFile, &hFile, 1))
    {
        return;
    }

    pShift = (D2PalShiftNodeStrc*)FOG_Alloc(sizeof(D2PalShiftNodeStrc), ".\\GAME\\PalShift.cpp", 244, 0);
    memset(pShift, 0, sizeof(D2PalShiftNodeStrc));
    ARCHIVE_ReadFileToBuffer(0, hFile, &pShift->tBase, sizeof(pShift->tBase));
    ARCHIVE_CloseFile(0, hFile);
    PALSHIFT_BuildBloodShift(nMonsterId, pShift);
    pShift->nId = nMonsterId;
    pShift->pNext = gpPalShiftList;
    gpPalShiftList = pShift;

    for (int i = 0; i < DATATBLS_GetMonStatsTxtRecordCount(); ++i)
    {
        if (pShift->nId == i)
        {
            gpPalShiftEntries[i].pShift = pShift;
        }
    }
}
#pragma optimize("", on)


// 0x00477470
void __cdecl PALSHIFT_InitPalShifts()
{
    while (gpPalShiftList)
    {
        D2PalShiftNodeStrc* pNext = gpPalShiftList->pNext;
        FOG_Free(gpPalShiftList, ".\\GAME\\PalShift.cpp", 0x117, 0);
        gpPalShiftList = pNext;
    }

    const int nCount = sgptDataTables->nMonStatsTxtRecordCount;
    D2PalShiftEntryStrc* pEntries = gpPalShiftEntries;
    const int nSize = nCount * sizeof(D2PalShiftEntryStrc);
    if (!pEntries)
    {
        pEntries = (D2PalShiftEntryStrc*)FOG_Alloc(nSize, ".\\GAME\\PalShift.cpp", 0x11F, 0);
        gpPalShiftEntries = pEntries;
    }
    memset(pEntries, 0, nSize);
    for (int i = 0; i < nCount; ++i)
    {
        pEntries[i].nId = i;
    }

    PALSHIFT_LoadPalShift(MONSTER_NECROSKELETON);
    PALSHIFT_LoadPalShift(MONSTER_NECROMAGE);
    PALSHIFT_LoadPalShift(MONSTER_SPIRITWOLF);
    PALSHIFT_LoadPalShift(MONSTER_FENRIS);
}


extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall CUNIT_GetPalShiftIndex(D2UnitStrc* pUnit); // 0x00463EB0

int __cdecl GAME_GetColorFlag(); // 0x0044DC60

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0

// 0x00477530
unsigned char* __fastcall PALSHIFT_GetPalShift(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER)
    {
        D2PalShiftNodeStrc* pData = gpPalShiftEntries[pUnit->dwClassId].pShift;
        if (!pData)
            return 0;
        int nMode = CUNIT_GetPalShiftIndex(pUnit);
        switch (nMode)
        {
        case 0:
        case 1:
            switch (pUnit->dwClassId)
            {
            case 0x16B:
            case 0x16C:
                return pData->tBase.aRows[nMode];
            }
            return 0;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            break;
        default:
            if (gbGlobalPalShifts)
            {
                nMode -= 8;
                D2_ASSERT(nMode >= 0 && nMode < 0x1E, 0x160);
                return gabGlobalPalShifts[nMode];
            }
            break;
        }
        if (GAME_GetColorFlag())
        {
            D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
            if (pMonStats2TxtRecord && pMonStats2TxtRecord->nLocalBlood == 2)
                return pData->tBlood.aRows[nMode];
        }
        return pData->tBase.aRows[nMode];
    }
    return 0;
}

#include "gen/data/Source/D2Client/GAME/PalShift.inc"
