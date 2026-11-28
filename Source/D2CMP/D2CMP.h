#pragma once

struct D2CmpPoolStrc;
struct D2TileLibraryHashStrc;
struct AsyncData;
struct D2CriticalSectionStrc;

D2TileLibraryHashStrc* __cdecl sub_0060CDB0_AllocTileHash(); // 0x0060CDB0
AsyncData* __fastcall FOG_AsyncDataLoadFileEx(void* hArchive, const char* szFileName, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8, const char* szFile, int nLine); // 0x0040A620
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4
extern "C" __declspec(dllimport) unsigned int __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char gszNewline[]; // 0x006FFCB0
extern "C" const char gszSpriteCacheSourceFile[]; // 0x006E364C
extern "C" const char szFastCmpFile[]; // 0x006E5F08
extern "C" const char szSubTileFile[]; // 0x006E61F8
extern "C" const char szTileCodecFile[]; // 0x006E61F8
extern "C" double __cdecl sqrt(double x); // 0x006879C0
extern const char gszSubTileFile[]; // 0x006E61F8
extern int gaDirectionIndex64[][64]; // 0x006E45A0
extern int gbCmpCompressedDataMode; // 0x00741EFC
extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268
int __fastcall ARCHIVE_OpenFile(void* hArchive, const char* szFilePath, void** phFile, int bFileNotFoundLogSkipped); // 0x00516E46
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480
int __fastcall FOG_AsyncDataTestLoaded(AsyncData* ptAsyncData); // 0x0040A7F0
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed); // 0x00413CE0
void __fastcall ARCHIVE_CloseFile(void* hArchive, void* hFile); // 0x00516E84
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall LRUCacheInit(D2CmpPoolStrc* pPool, void* pMemPool, int nArg, void (__fastcall* pfnFree)(void*), int nBlocks); // 0x00609020
void __fastcall LRUCacheRelease(D2CmpPoolStrc* pPool, void* pMemory); // 0x006092D0
void __fastcall LRUCacheDestroy(D2CmpPoolStrc* pPool); // 0x006093E0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void* __fastcall SubTileCompress(const void* pSrc, int* pLength); // 0x0060D430

// build: symbol ?ganSquareTable@* 0x008E9034
#define gnSquareTableCenter_008E9430 (ganSquareTable + 255)

struct D2CelBlockStrc
{
    char unk0x00[0x28];
    unsigned char* pPixels;
};

struct D2GfxCellStrc
{
    unsigned int dwFlags;
    unsigned int dwWidth;
    unsigned int dwHeight;
    int nXOffset;
    int nYOffset;
    unsigned int unk0x14;
    unsigned int dwParent;
    unsigned int dwLength;
    unsigned char pPixels[1];
};

struct D2CellFileStrc
{
    unsigned int dwVersion;
    unsigned int dwFlags;
    unsigned int eFormat;
    unsigned int dwTermination;
    unsigned int nDirections;
    unsigned int nFrames;
    D2GfxCellStrc* pGfxCells[1];
};

struct D2ChatStormBaseArrayAStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    void* m_data;

    D2ChatStormBaseArrayAStrc();
    unsigned int IGNORELIST_GetStringSlotArrayCount();
};

struct D2ChatStormBaseArrayBStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    void* m_data;

    D2ChatStormBaseArrayBStrc();
    unsigned int IGNORELIST_GetMappingSlotArrayCount();
};

struct D2ChatStormCtorLinkStrc
{
    D2ChatStormCtorLinkStrc* m_prevlink;
    char* m_next;

    D2ChatStormCtorLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
};

struct D2ChatStormLinkStrc
{
    D2ChatStormLinkStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2ChatStormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2ChatStormLinkStrc*)(m_next + nLinkOffset);
    }
    char* MaskNext()
    {
        return (char*)((((int)m_next <= 0) - 1) & (int)m_next);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
    bool IGNORELIST_IsLinkLinked();
    char* sub_0060E1A0_Next();
    char* sub_0060E240_Next();
    void sub_0060E3B0_Unlink();
    void sub_0060E400_Unlink();
    void sub_0060E690_Unlink();
    void sub_0060E760_Unlink();
};

struct D2ChatStormListAStrc
{
    int m_linkoffset;
    D2ChatStormLinkStrc m_terminator;

    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void IGNORELIST_InitStringListTerminator();
    char* IGNORELIST_GetStringListHead();
    void IGNORELIST_ResetStringList();
    char* sub_006020C0_Head();
    void sub_00603510_Reset();
};

struct D2ChatStormHashTableStrc
{
    void* m_pVTable;
    D2ChatStormListAStrc m_fulllist;

    char* IGNORELIST_GetStringTableHead();
};

struct D2ChatStormLinkAStrc
{
    D2ChatStormLinkAStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkAStrc();
};

struct D2ChatStormLinkBStrc
{
    D2ChatStormLinkBStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkBStrc();
};

struct D2ChatStormListBStrc
{
    int m_linkoffset;
    D2ChatStormLinkStrc m_terminator;

    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void IGNORELIST_InitMappingListTerminator();
    char* IGNORELIST_GetMappingListHead();
    void IGNORELIST_ResetMappingList();
};

struct D2ChatStormListCStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListCStrc();
};

struct D2ChatStormListFStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListFStrc();
};

struct D2ChatStormListDStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListDStrc();
};

struct D2ChatStormListEStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListEStrc();
};

struct D2ChatStormNodeStrc
{
    unsigned int m_hashval;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc m_linktofull;
    char* m_key;

    char* IGNORELIST_GetStringEntryKey();
};

struct D2CmpByteMapStrc
{
    unsigned char ab[0x100];
    int nCount;
};

struct D2CmpCacheKeyStrc
{
    int nKeyA;
    int nKeyB;
    int nKeyC;
    char unk0x0C[0x14];
    unsigned char nFlags;
    char unk0x21[0x8F];
    AsyncData* pAsyncData;
};

struct D2CmpCacheListEntryStrc
{
    D2CmpCacheKeyStrc* pKey;
    char unk0x04[0x10];
    D2CmpCacheListEntryStrc* pNext;
};

typedef void (__stdcall* D2CmpColorCallback)(unsigned int nColor);

struct D2CmpPoolStrc
{
    union
    {
        unsigned char unk0x00[0x34];
        struct
        {
            void* pMemPool;                                         // 0x00
            unsigned int nTotal;                                    // 0x04
            unsigned int nHits;                                     // 0x08
        };
    };
};

struct D2CmpRGBStrc
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
};

struct D2CmpSubTilePosStrc
{
    int nX;
    int nY;
};

struct D2CommonMappingEntryNodeBaseStrc
{
    unsigned int m_hashval;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc m_linktofull;
    char* m_key;

    ~D2CommonMappingEntryNodeBaseStrc();
};

struct D2CommonMappingEntryNodeStrc : D2CommonMappingEntryNodeBaseStrc
{
    void* pMapped;

    ~D2CommonMappingEntryNodeStrc();
};

struct D2CommonStormHashTableAStrc
{
    void IGNORELIST_InternalClearStringTable(int bWarn);
    void IGNORELIST_ClearStringTable();
};

struct D2CommonStormSlotLinkStrc
{
    D2CommonStormSlotLinkStrc* m_prevlink;
    char* m_next;

    ~D2CommonStormSlotLinkStrc()
    {
        Unlink();
    }
    D2CommonStormSlotLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2CommonStormSlotLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2CommonStormSlotLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};

struct D2CommonStormSlotListAStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;
    ~D2CommonStormSlotListAStrc();
    void UnlinkAll();
};

struct D2CommonStormSlotListBStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    ~D2CommonStormSlotListBStrc();
    void UnlinkAll();
};

struct D2CommonStringEntryNodeStrc
{
    unsigned int m_hashval;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc m_linktofull;
    char* m_key;

    ~D2CommonStringEntryNodeStrc();
    void IGNORELIST_DestroyStringEntryNode();
};

struct D2HslStrc
{
    double dHue;
    double dSaturation;
    double dLightness;
};

struct D2PalRgbaStrc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nPad;
};

typedef void (__fastcall* D2SpriteCacheFreeFn)(unsigned int nKey);

struct D2SpriteCacheLockStrc
{
    char data[0x18];
};

struct D2Storm408ElemStrc
{
    char unk0x00[0x408];
};

struct D2Storm416A90Strc
{
    char pad00[0x14C];
    int n14C;
    int n150;
};

struct D2StormArray408Strc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2Storm408ElemStrc* m_data;
    unsigned int m_chunk;

    D2StormArray408Strc* sub_0051D2C0_InitBase();
    unsigned int sub_0051D2F0_CalcChunkSize(unsigned int nCount);
    void sub_0051D570_FreeData();
    void sub_0051D5D0_ReallocData(unsigned int nCount);
    void sub_0051D670_FreeData();
    D2StormArray408Strc* sub_0051D690_Init();
    void sub_0051D6A0_Clear();
    D2StormArray408Strc* sub_0051D720_Init();
    void sub_0051D730_FreeData();
    D2Storm408ElemStrc* sub_0051D7A0_New();
    void ReserveInline(unsigned int nCount, int bRound);
};

struct D2TileListHeaderStrc
{
    int nUnk0x00;
    int nUnk0x04;
    int nUnk0x08;
    int f_C;
    int f_10;
};

typedef unsigned int size_t;

struct D2CelStrc;
struct D2CmpTileBlockStrc;
struct D2CmpTileLibraryStrc;
struct D2TileLibraryHeaderStrc;

void __fastcall D2CMPTileCacheFreeProject(D2CmpTileLibraryStrc* pLibrary); // 0x005FE080
int __stdcall D2CMPGetFindTile(void* pData); // 0x00600760
void __stdcall D2CMPLoadProjectRecord(D2TileLibraryHeaderStrc** ppLibrary, const char* szFilePath); // 0x00600790
unsigned char __stdcall GetClosestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210
void* __stdcall CreateD2Palette(void* pSource); // 0x00606930
void __fastcall CelDrawRleShadow(D2CelStrc* pCel, unsigned char* pDst, int nX, int nClipLeft, int nClipRight, int nPitch, int nSkip, int nLines, int nTable, int nColor); // 0x00608D60
unsigned char __fastcall FindTileHash(int a, int b, int c); // 0x0060CD70
void __fastcall FindTileAddTile(D2TileLibraryHashStrc* pHash, D2CmpTileBlockStrc* pTile); // 0x0060CFA0
void __fastcall CelIterateRgbPixels(D2CelStrc* pCel, int nArg, int nTermination); // 0x0060D110
int __fastcall sub_0060D3A0_ScanOtherRun(const unsigned char* pData, const unsigned char* pEnd, unsigned char nValue, int nMax, int* pbRunReachedEnd, int* pbRestReachedEnd); // 0x0060D3A0
