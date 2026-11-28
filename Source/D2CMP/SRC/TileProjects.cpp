#include "D2CMP.h"
#include "D2CmpCache.h"
#include "FogApi.h"
struct D2CmpFindTilesNodeStrc;


void __stdcall TileProjectDestroy(D2TileLibraryHeaderStrc* pLibrary, int bKeep);                    // 0x00609E90
void __fastcall FindTileDestroyTable(D2CmpFindTilesNodeStrc** ppBuckets);                        // 0x0060CE00
static D2TileRecordStrc* gpTileRecords;                                                                   // 0x008ADBB4

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
int __fastcall D2CMPGetTileHeadersSize(const char* szFilePath);                                     // 0x005FDF80

void __stdcall TileProjectNormalizeHeaders(D2TileLibraryHeaderStrc* pLibrary, D2TileLibraryHeaderStrc** ppLibrary, const char* szName); // 0x0060A390
D2TileLibraryHashStrc* __fastcall TileProjectBuildFindTable(D2TileLibraryHeaderStrc* pLibrary);        // 0x0060A440

// 0x006006B0
void __cdecl D2CMPDestroyTileHeaders()
{
    D2TileRecordStrc* pRecord = gpTileRecords;
    while (pRecord)
    {
        D2TileRecordStrc* pNext = pRecord->pPrev;
        TileProjectDestroy(pRecord->pLibrary, 0);
        pRecord->pLibrary = 0;
        FindTileDestroyTable((D2CmpFindTilesNodeStrc**)pRecord->pHashBlock);
        pRecord->pHashBlock = 0;
        FOG_Free(pRecord, ".\\SRC\\TileProjects.cpp", 0x2A, 0);
        pRecord = pNext;
    }
    gpTileRecords = 0;
}

// 0x00600710
static D2TileRecordStrc* D2CMPFindTileRecord(const char* szName)
{
    for (D2TileRecordStrc* pRecord = gpTileRecords; pRecord; pRecord = pRecord->pPrev)
    {
        if (!strcmp(pRecord->szLibraryName, szName))
        {
            return pRecord;
        }
    }
    return 0;
}

// 0x00600760
D2TileLibraryHashStrc* __stdcall D2CMPGetFindTile(const char* szName)
{
    D2TileRecordStrc* pRecord = D2CMPFindTileRecord(szName);
    if (pRecord)
    {
        return pRecord->pHashBlock;
    }
    return 0;
}

// 0x00600790
D2TileLibraryHeaderStrc* __stdcall D2CMPLoadProjectRecord(D2TileLibraryHashStrc** ppHashBlock, const char* szName)
{
    D2TileLibraryHeaderStrc* pLibrary = 0;
    void* hFile = 0;
    D2TileRecordStrc* pRecord = D2CMPFindTileRecord(szName);
    if (pRecord)
    {
        *ppHashBlock = pRecord->pHashBlock;
        return pRecord->pLibrary;
    }
    const int nSize = D2CMPGetTileHeadersSize(szName);
    void* ptData = FOG_Alloc(nSize, ".\\SRC\\TileProjects.cpp", 0x6B, 0);
    D2_ASSERT(ptData, 0x6C);
    memset(ptData, 0, nSize);
    ARCHIVE_OpenFile(0, szName, &hFile, 0);
    ARCHIVE_ReadFileToBuffer(0, hFile, ptData, nSize);
    ARCHIVE_CloseFile(0, hFile);
    TileProjectNormalizeHeaders((D2TileLibraryHeaderStrc*)ptData, &pLibrary, szName);
    D2TileLibraryHashStrc* pHashBlock = TileProjectBuildFindTable(pLibrary);
    D2TileRecordStrc* pNew = (D2TileRecordStrc*)FOG_Alloc(sizeof(D2TileRecordStrc), ".\\SRC\\TileProjects.cpp", 0x7B, 0);
    D2_ASSERT(pNew, 0x7C);
    memset(pNew, 0, sizeof(D2TileRecordStrc));
    pNew->pPrev = gpTileRecords;
    pNew->pLibrary = pLibrary;
    pNew->pHashBlock = pHashBlock;
    gpTileRecords = pNew;
    strcpy(pNew->szLibraryName, szName);
    *ppHashBlock = pNew->pHashBlock;
    return pLibrary;
}
