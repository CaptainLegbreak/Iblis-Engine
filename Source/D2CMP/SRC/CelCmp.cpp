#include "D2CMP.h"

#include "D2CmpTileRecord.h"

#include "D2CmpCelFile.h"

#include "D2GameTypes.h"

#include "D2DrlgMaps.h"

#include "D2CmpTypes.h"

#include "D2CmpStormList.h"

#include "CELLIST.h"

#include "D2LRUNode.h"
#include "D2StormListArray.h"
#include "D2FindTileEntry.h"
#include "D2CmpDC6CacheEntry.h"
#include "FogApi.h"
#include "StormApi.h"
#include "FogApi.h"
#include "D2CommonApi2.h"
#include "D2HellApi.h"
#include "StormApi2.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CmpCellStrc;

struct D2DrlgLevelStrc;

struct D2CmpTileCacheStrc;

struct D2TileLibraryEntryStrc;

struct D2TSLinkStrc;


struct D2CmpCacheBlockOwnerStrc;

struct D2CmpCacheKeyStrc;

struct D2CmpCacheListEntryStrc;

struct D2CmpCacheNodeStrc;

struct D2CmpCacheStrc;

struct D2CelBlockStrc;

struct D2CmpCelContextStrc;

struct D2FindTileNodeStrc;

struct D2FindTileEntryStrc;

struct Cell;

struct CellTable;


struct D2StormListStrc;

struct D2Storm4167B0Strc;

struct D2Storm4168F0Strc;

struct D2Storm416A90Strc;




struct PairStrc_0060E1B0;

struct PairStrc_0060E290;

struct sub_0040F7D0;

struct sub_00417810;

struct sub_00417860;

struct sub_004178C0;

struct sub_00417900;

struct sub_00417950;

struct sub_004179B0;

struct sub_004183F0;

struct sub_00418430;

struct sub_00418780;

struct sub_004187C0;

struct sub_00418800;

struct sub_00418840;

struct sub_00418880;

struct sub_004188C0;

struct sub_00418BA0;

struct sub_00418BE0;

struct sub_00418C20;

struct sub_00418E10;

struct sub_0041C3D0;

struct sub_0041C500;

struct sub_0041C730;

struct sub_0041C800;

struct sub_00420430;

struct sub_004204B0;

struct sub_00420710;

struct sub_004207E0;

struct sub_00426960;

struct sub_00426A80;

struct sub_00426CB0;

struct sub_00426D80;

struct sub_0044DDD0;

struct sub_0044DE90;

struct sub_0044ECC0;

struct sub_0044ED50;










struct sub_00417780;

struct sub_00417850;

struct sub_004178B0;

struct sub_00417940;

struct sub_00417990;

struct sub_00418760;

struct sub_00418770;

struct sub_00418A40;

struct sub_00418DE0;

struct sub_00418DF0;

struct sub_00418E00;

struct sub_00418E50;

struct sub_00418FF0;

struct sub_00419060;

struct sub_0041C4F0;

struct sub_0041C720;

// build: symbol ?HANDLER@* 0x0041C7F0
struct HANDLER;

struct sub_004204A0;

struct sub_00420700;

struct sub_004207D0;

struct sub_00426CA0;

struct sub_00426D70;

struct sub_0044BDE0;

struct sub_0044ED40;

struct sub_0044ED90;






struct D2CommonStormSlotListAStrc;

struct D2CommonStormSlotArrayAStrc;

struct D2ChatStormLinkStrc;

struct D2ChatStormLinkAStrc;

struct D2ChatStormLinkBStrc;

struct D2ChatStormNodeStrc;

struct D2ChatStormBaseArrayAStrc;

struct D2ChatStormBaseArrayBStrc;

struct D2ChatStormListAStrc;

struct D2ChatStormListBStrc;

struct D2ChatStormHashTableStrc;

struct D2ChatStormCtorLinkStrc;

struct D2ChatStormListCStrc;

struct D2ChatStormListDStrc;

struct D2ChatStormListEStrc;

struct D2CommonStormSlotLinkStrc;

struct D2CommonStormSlotListBStrc;

struct D2CommonMappingEntryNodeBaseStrc;

struct D2CommonMappingEntryNodeStrc;

struct D2CommonStringEntryNodeStrc;

struct D2CommonStormHashTableAStrc;

struct R0052E0F0;


struct D2StormListEArrayStrc;

struct D2StormHashTableEStrc;

struct CriticalSection;

struct LockedObject;

struct D2StormChunkLinkStrc;

struct D2StormCtorLinkStrc;

struct D2SGameDataStrc;

struct D2StormGameArrayStrc;

struct D2StormChunkListStrc;

struct sub_0044F9F0;


struct D2StormDeadListStrc;

struct sub_0044FBE0;

struct sub_0044FC20;

struct sub_0044FDD0;

struct D2StormGameGrowArrayStrc;

struct D2StormGameHashChunkStrc;

struct D2Storm408ElemStrc;

struct D2StormArray408Strc;

struct D2CriticalSectionStrc;

struct D2CmpPoolStrc;

class WardenModule;


struct D2WardenModuleHolderAStrc;

struct D2WardenModuleHolderBStrc;

struct D2CmpTileCacheStrc
{
    unsigned char unk0x00[0x2C];
    int bActive;
    unsigned char unk0x30[0x20];
};

struct D2TSLinkStrc
{
    D2TSLinkStrc* pPrevLink;
    unsigned int nNext;
};

extern D2CmpPoolStrc gCmpPool; // 0x0088CAE0

extern D2CmpPoolStrc gCmpTilePool; // 0x0088DB20

extern D2CmpTileCacheStrc gCmpTileCache; // 0x0089DB60

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0
typedef void(__fastcall* CELFILECELLOPFN)(D2CelStrc* pCel, int nArg);
extern CELFILECELLOPFN gpfnCelFileCellOp[]; // 0x006E3698

void __fastcall D2CMPTileCacheReleaseTile(void* pEntry); // 0x005FDE50

void __cdecl D2CMPDestroyTileHeaders(); // 0x006006B0

void __fastcall D2CMPSpriteCacheFreeAll(D2CmpTileCacheStrc* pCache); // 0x005FFBE0

void __cdecl CodecReleaseLock(); // 0x0060CD50


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09



struct D2CmpCacheBlockOwnerStrc
{
    char unk0x00[0x54];
    int nBlockUsed;
    char unk0x58[4];
    void* pBlock;
};

extern const char* gszCmpCompressedExtension; // 0x00741F00

extern const char* gszCmpDefaultExtension; // 0x00741F04


struct D2CmpCacheNodeStrc
{
    char unk0x00[0x04];
    unsigned int nSize;
    char unk0x08[0x04];
    unsigned int dwFlags;
};

struct D2CmpCacheStrc
{
    char unk0x00[0x04];
    unsigned int nMaxSize;
    unsigned int nTotalSize;
    char unk0x0C[0x24];
    D2CriticalSectionStrc tLock;
};

D2CmpCacheNodeStrc* __fastcall D2CMPSpriteCacheEvict(D2CmpCacheStrc* pCache, D2CmpCacheNodeStrc* pNode, int nArg); // 0x005FF4A0

extern D2TileRecordStrc* gpTileRecords; // 0x008ADBB4

extern int gnCmpGfxMode; // 0x00741F08

extern unsigned char gaItemShiftMaps[][105][256]; // 0x008ADBB8

extern int gaDirectionIndex32[][32]; // 0x006E3A20

typedef void(__fastcall* CELFILECONVERTFN)(D2CelFileStrc* pSource, D2CelFileStrc* pTarget, int nArg1, int nArg2);

extern CELFILECONVERTFN gpfCelFileConvert[]; // 0x006E3690

typedef void(__fastcall* CELDRAWFN)(D2CelStrc* pCel, unsigned char* pDst, int nX, int nArg4, int nArg5, int nPitch, int nSkipRows, int nRows, int nArg9, int nArg10, int nArg13);

extern CELDRAWFN gpfnCelDraw[]; // 0x006E3688

struct D2FindTileNodeStrc
{
    void* pTile;
    D2FindTileNodeStrc* pNext;
};



extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

int __stdcall CelGameDirToFileDir(int nDirection, unsigned int nDirections); // 0x00600C90

struct Cell { int unk0; int width; int height; char pad[0x14]; unsigned char data[1]; };

struct CellTable { int type; unsigned char flags; char pad[0xB]; int nDirections; int stride; Cell* cells[1]; };


extern "C" const char emptyAssert; // 0x006CC837

enum { REQUIRED_TYPE = 6 };

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

extern unsigned short gwValue_0077905C;

struct D2Storm4167B0Strc
{
    D2StormLinkStrc m_link;

    ~D2Storm4167B0Strc();
};

struct D2Storm4168F0Strc
{
    D2StormLinkStrc m_link;

    ~D2Storm4168F0Strc();
};

struct PairStrc_0060E1B0
{
    int nFirst;
    int nSecond;
};

struct PairStrc_0060E290
{
    int nFirst;
    int nSecond;
};


struct sub_0040F7D0
{
    D2StormLinkStrc m_link;
    ~sub_0040F7D0();
};

struct sub_00417810
{
    D2StormLinkStrc m_link;
    ~sub_00417810();
};

struct sub_00417860
{
    D2StormLinkStrc m_link;
    ~sub_00417860();
};

struct sub_004178C0
{
    D2StormLinkStrc m_link;
    ~sub_004178C0();
};

struct sub_00417900
{
    D2StormLinkStrc m_link;
    ~sub_00417900();
};

struct sub_00417950
{
    D2StormLinkStrc m_link;
    ~sub_00417950();
};

struct sub_004179B0
{
    D2StormLinkStrc m_link;
    ~sub_004179B0();
};

struct sub_004183F0
{
    D2StormLinkStrc m_link;
    ~sub_004183F0();
};

struct sub_00418430
{
    D2StormLinkStrc m_link;
    ~sub_00418430();
};

struct sub_00418780
{
    D2StormLinkStrc m_link;
    ~sub_00418780();
};

struct sub_004187C0
{
    D2StormLinkStrc m_link;
    ~sub_004187C0();
};

struct sub_00418800
{
    D2StormLinkStrc m_link;
    ~sub_00418800();
};

struct sub_00418840
{
    D2StormLinkStrc m_link;
    ~sub_00418840();
};

struct sub_00418880
{
    D2StormLinkStrc m_link;
    ~sub_00418880();
};

struct sub_004188C0
{
    D2StormLinkStrc m_link;
    ~sub_004188C0();
};

struct sub_00418BA0
{
    D2StormLinkStrc m_link;
    ~sub_00418BA0();
};

struct sub_00418BE0
{
    D2StormLinkStrc m_link;
    ~sub_00418BE0();
};

struct sub_00418C20
{
    D2StormLinkStrc m_link;
    ~sub_00418C20();
};

struct sub_00418E10
{
    D2StormLinkStrc m_link;
    ~sub_00418E10();
};

struct sub_0041C3D0
{
    D2StormLinkStrc m_link;
    ~sub_0041C3D0();
};

struct sub_0041C500
{
    D2StormLinkStrc m_link;
    ~sub_0041C500();
};

struct sub_0041C730
{
    D2StormLinkStrc m_link;
    ~sub_0041C730();
};

struct sub_0041C800
{
    D2StormLinkStrc m_link;
    ~sub_0041C800();
};

struct sub_00420430
{
    D2StormLinkStrc m_link;
    ~sub_00420430();
};

struct sub_004204B0
{
    D2StormLinkStrc m_link;
    ~sub_004204B0();
};

struct sub_00420710
{
    D2StormLinkStrc m_link;
    ~sub_00420710();
};

struct sub_004207E0
{
    D2StormLinkStrc m_link;
    ~sub_004207E0();
};

struct sub_00426960
{
    D2StormLinkStrc m_link;
    ~sub_00426960();
};

struct sub_00426A80
{
    D2StormLinkStrc m_link;
    ~sub_00426A80();
};

struct sub_00426CB0
{
    D2StormLinkStrc m_link;
    ~sub_00426CB0();
};

struct sub_00426D80
{
    D2StormLinkStrc m_link;
    ~sub_00426D80();
};

struct sub_0044DDD0
{
    D2StormLinkStrc m_link;
    ~sub_0044DDD0();
};

struct sub_0044DE90
{
    D2StormLinkStrc m_link;
    ~sub_0044DE90();
};

struct sub_0044ECC0
{
    D2StormLinkStrc m_link;
    ~sub_0044ECC0();
};

struct sub_0044ED50
{
    D2StormLinkStrc m_link;
    ~sub_0044ED50();
};

struct sub_00417780
{
    D2StormLinkStrc m_link;
    sub_00417780();
};

struct sub_00417850
{
    D2StormLinkStrc m_link;
    sub_00417850();
};

struct sub_004178B0
{
    D2StormLinkStrc m_link;
    sub_004178B0();
};

struct sub_00417940
{
    D2StormLinkStrc m_link;
    sub_00417940();
};

struct sub_00417990
{
    D2StormLinkStrc m_link;
    sub_00417990();
};

struct sub_00418760
{
    D2StormLinkStrc m_link;
    sub_00418760();
};

struct sub_00418770
{
    D2StormLinkStrc m_link;
    sub_00418770();
};

struct sub_00418A40
{
    D2StormLinkStrc m_link;
    sub_00418A40();
};

struct sub_00418DE0
{
    D2StormLinkStrc m_link;
    sub_00418DE0();
};

struct sub_00418DF0
{
    D2StormLinkStrc m_link;
    sub_00418DF0();
};

struct sub_00418E00
{
    D2StormLinkStrc m_link;
    sub_00418E00();
};

struct sub_00418E50
{
    D2StormLinkStrc m_link;
    sub_00418E50();
};

struct sub_00418FF0
{
    D2StormLinkStrc m_link;
    sub_00418FF0();
};

struct sub_00419060
{
    D2StormLinkStrc m_link;
    sub_00419060();
};

struct sub_0041C4F0
{
    D2StormLinkStrc m_link;
    sub_0041C4F0();
};

struct sub_0041C720
{
    D2StormLinkStrc m_link;
    sub_0041C720();
};

struct HANDLER
{
    D2StormLinkStrc m_link;
    HANDLER();
};

struct sub_004204A0
{
    D2StormLinkStrc m_link;
    sub_004204A0();
};

struct sub_00420700
{
    D2StormLinkStrc m_link;
    sub_00420700();
};

struct sub_004207D0
{
    D2StormLinkStrc m_link;
    sub_004207D0();
};

struct sub_00426CA0
{
    D2StormLinkStrc m_link;
    sub_00426CA0();
};

struct sub_00426D70
{
    D2StormLinkStrc m_link;
    sub_00426D70();
};

struct sub_0044BDE0
{
    D2StormLinkStrc m_link;
    sub_0044BDE0();
};

struct sub_0044ED40
{
    D2StormLinkStrc m_link;
    sub_0044ED40();
};

struct sub_0044ED90
{
    D2StormLinkStrc m_link;
    sub_0044ED90();
};

struct D2CommonStormSlotArrayAStrc {
 unsigned int m_alloc,m_count;
 D2CommonStormSlotListAStrc* m_data;
 unsigned int m_chunk;
 D2CommonStormSlotListAStrc* sub_00601CC0_At(unsigned int index);
};

extern "C" const char gszIgnoreListSourceFile_006E6290[];

struct R0052E0F0
{
    void* pUnk0x00;
    void* m_pFile;
    bool sub_0052E0F0_IsOpen();
};

int __stdcall CelFileFreeHardware(D2CelFileStrc* pCelFile); // 0x00601A50

struct D2StormListEArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2StormListEStrc* m_data;
    unsigned int m_chunk;

    D2StormListEStrc* sub_0060E0E0_At(unsigned int nIndex);
    D2StormListEStrc* sub_0060E110_At(unsigned int nIndex);
    unsigned int sub_0060E2A0_CalcChunkSize(unsigned int nCount);
    unsigned int sub_0060E300_CalcChunkSize(unsigned int nCount);
};

struct D2StormHashTableEStrc
{
    char unk0x00[0x24];
    unsigned int m_slotmask;

    unsigned int sub_0060E1F0_SlotIndex(unsigned int nHashVal);
    unsigned int sub_0060E210_SlotIndex(unsigned int nHashVal);
};

struct CriticalSection { unsigned data[6]; };

struct LockedObject { char pad[0x50]; CriticalSection lock; void sub_00602090(int acquired); };

enum { NOT_ACQUIRED = 0 };

struct D2StormChunkLinkStrc
{
    D2StormChunkLinkStrc* m_prevlink;
    char* m_next;

    D2StormChunkLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormChunkLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormChunkLinkStrc*)(m_next + nLinkOffset);
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

struct D2StormCtorLinkStrc
{
    D2StormCtorLinkStrc* m_prevlink;
    char* m_next;

    D2StormCtorLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
};

struct D2SGameDataStrc
{
    char unk0x00[0x1DF4];

    ~D2SGameDataStrc();
};

struct D2StormGameArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2SGameDataStrc* m_data;
    unsigned int m_chunk;

    ~D2StormGameArrayStrc();
};

struct D2StormChunkListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormChunkListStrc();
    void UnlinkAll();
};

struct sub_0044F9F0
{
    D2SGameDataStrc tData;

    ~sub_0044F9F0();
};

struct D2StormDeadListStrc
{
    int m_linkoffset;
    D2StormCtorLinkStrc m_terminator;

    D2StormDeadListStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    D2StormDeadListStrc(const D2StormDeadListStrc& source)
    {
        m_linkoffset = source.m_linkoffset;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
};

struct sub_0044FBE0 : D2StormListAStrc
{
    ~sub_0044FBE0();
};

struct sub_0044FC20 : D2StormChunkListStrc
{
    ~sub_0044FC20();
};

struct sub_0044FDD0 : D2StormListAStrc
{
    ~sub_0044FDD0();
};

struct D2StormGameGrowArrayStrc
{
    D2StormGameArrayStrc tArray;

    ~D2StormGameGrowArrayStrc();
};

struct D2StormGameHashChunkStrc
{
    D2StormGameArrayStrc tArray;
    D2StormChunkLinkStrc m_link;

    ~D2StormGameHashChunkStrc();
};

extern "C" const char gszTypeNewsTableItem[];

typedef void (__fastcall* CelFileBuildFn)(CELLIST* pList, D2CelFileStrc* pCelFile);

extern CelFileBuildFn gapfnCelFileBuilders[]; // 0x006E3680

void __fastcall RawBuildCelFile(CELLIST* pList, D2CelFileStrc* pCelFile); // 0x0060D190

// build: symbol ??__EgCelListTable@@YAXXZ 0x006CAFC0
// build: symbol ??__FgCelListTable@@YAXXZ 0x006CB4C0
D2CelListSyncTable gCelListTable; // 0x008E8CC0

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw();

inline void __cdecl operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

extern "C" const char szWardenClientFile[];

class WardenModule
{
public:
    WardenModule();
    ~WardenModule();

    void* pImage;
    int unk0x04;
    int nImports;
    int unk0x0C;
    void* f_10;
};

struct D2WardenModuleHolderAStrc
{
    WardenModule tModule;

    ~D2WardenModuleHolderAStrc();
};

struct D2WardenModuleHolderBStrc
{
    WardenModule tModule;

    ~D2WardenModuleHolderBStrc();
};

int gbCmpPoolInitialized; // 0x0088CB14

int gnCmpPoolArg; // 0x0088CB18

extern const char gszCelCmp[]; // 0x006E5DD0

struct D2CelStrc;

extern "C" int __cdecl sub_00517ABB_BitScanForward1(unsigned int nValue);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837




int gpCharstatsTxt; // 0x0096C7F4

int gpAnimData; // 0x0096C8A4

int gnShrinesTxtRecordCount; // 0x0096D46C

char* __fastcall sub_0060E280_AddLinkOffset(char* pNode, int nLinkOffset);

int __cdecl sub_0068A420(); // 0x0068A420

int __cdecl sub_0069FA20(); // 0x0069FA20

sub_0040F7D0::~sub_0040F7D0()
{
    m_link.Unlink();
}

sub_00417780::sub_00417780()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_00417810::~sub_00417810()
{
    m_link.Unlink();
}

sub_00417850::sub_00417850()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_00417860::~sub_00417860()
{
    m_link.Unlink();
}

sub_004178B0::sub_004178B0()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_004178C0::~sub_004178C0()
{
    m_link.Unlink();
}

sub_00417900::~sub_00417900()
{
    m_link.Unlink();
}

sub_00417940::sub_00417940()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_00417950::~sub_00417950()
{
    m_link.Unlink();
}

sub_00417990::sub_00417990()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_004179B0::~sub_004179B0()
{
    m_link.Unlink();
}

sub_004183F0::~sub_004183F0()
{
    m_link.Unlink();
}

sub_00418430::~sub_00418430()
{
    m_link.Unlink();
}

sub_00418760::sub_00418760()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_00418770::sub_00418770()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_00418780::~sub_00418780()
{
    m_link.Unlink();
}

sub_004187C0::~sub_004187C0()
{
    m_link.Unlink();
}

sub_00418800::~sub_00418800()
{
    m_link.Unlink();
}

sub_00418840::~sub_00418840()
{
    m_link.Unlink();
}

sub_00418880::~sub_00418880()
{
    m_link.Unlink();
}

sub_004188C0::~sub_004188C0()
{
    m_link.Unlink();
}

sub_00418A40::sub_00418A40()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_00418BA0::~sub_00418BA0()
{
    m_link.Unlink();
}

sub_00418BE0::~sub_00418BE0()
{
    m_link.Unlink();
}

sub_00418C20::~sub_00418C20()
{
    m_link.Unlink();
}

sub_00418DE0::sub_00418DE0()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_00418DF0::sub_00418DF0()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_00418E00::sub_00418E00()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_00418E10::~sub_00418E10()
{
    m_link.Unlink();
}

sub_00418E50::sub_00418E50()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_00418FF0::sub_00418FF0()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_00419060::sub_00419060()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_0041C3D0::~sub_0041C3D0()
{
    m_link.Unlink();
}

sub_0041C4F0::sub_0041C4F0()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_0041C500::~sub_0041C500()
{
    m_link.Unlink();
}

sub_0041C720::sub_0041C720()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_0041C730::~sub_0041C730()
{
    m_link.Unlink();
}

HANDLER::HANDLER()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_0041C800::~sub_0041C800()
{
    m_link.Unlink();
}

sub_00420430::~sub_00420430()
{
    m_link.Unlink();
}

sub_004204A0::sub_004204A0()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_004204B0::~sub_004204B0()
{
    m_link.Unlink();
}

sub_00420700::sub_00420700()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_00420710::~sub_00420710()
{
    m_link.Unlink();
}

sub_004207D0::sub_004207D0()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_004207E0::~sub_004207E0()
{
    m_link.Unlink();
}

sub_00426960::~sub_00426960()
{
    m_link.Unlink();
}

sub_00426A80::~sub_00426A80()
{
    m_link.Unlink();
}

sub_00426CA0::sub_00426CA0()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_00426CB0::~sub_00426CB0()
{
    m_link.Unlink();
}

sub_00426D70::sub_00426D70()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_00426D80::~sub_00426D80()
{
    m_link.Unlink();
}

char* __fastcall sub_0060E360_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* D2ChatStormHashTableStrc::IGNORELIST_GetStringTableHead()
{
    return m_fulllist.m_terminator.MaskNext();
}

D2ChatStormListDStrc::D2ChatStormListDStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2CommonStormSlotListAStrc::~D2CommonStormSlotListAStrc()
{
    UnlinkAll();
}

D2CommonStormSlotListBStrc::~D2CommonStormSlotListBStrc()
{
    UnlinkAll();
}

D2CommonMappingEntryNodeStrc::~D2CommonMappingEntryNodeStrc()
{
    if (pMapped)
        SMemFree(pMapped, gszIgnoreListSourceFile_006E6290, 0x11, 0);
}

void D2CommonStringEntryNodeStrc::IGNORELIST_DestroyStringEntryNode()
{
    this->~D2CommonStringEntryNodeStrc();
}

void D2CommonStormHashTableAStrc::IGNORELIST_ClearStringTable()
{
    IGNORELIST_InternalClearStringTable(0);
}

int __stdcall sub_00436E90_AlwaysOne(int nArg)
{
    return 1;
}

sub_0044BDE0::sub_0044BDE0()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_0044DDD0::~sub_0044DDD0()
{
    m_link.Unlink();
}

sub_0044DE90::~sub_0044DE90()
{
    m_link.Unlink();
}

sub_0044ECC0::~sub_0044ECC0()
{
    m_link.Unlink();
}

sub_0044ED40::sub_0044ED40()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

sub_0044ED50::~sub_0044ED50()
{
    m_link.Unlink();
}

sub_0044ED90::sub_0044ED90()
{
    m_link.m_prevlink = 0;
    m_link.m_next = 0;
}

int __stdcall sub_004C6020_AlwaysOne(int nArg)
{
    return 1;
}

bool R0052E0F0::sub_0052E0F0_IsOpen()
{
    return m_pFile != 0;
}

int __stdcall OBJECTS_SpawnNothing(int nArg)
{
    return 1;
}

typedef void(__fastcall* PixelDataFreeCallback)(void* pData);

static PixelDataFreeCallback gpfnPixelDataFree; // 0x008E8CB8

typedef int (__stdcall* D2FarProcFn)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(D2FarProcFn lpfn); // 0x006CC34C

struct D2CmpPoolEntryStrc
{
    int unk0x00;
    int unk0x04;
    D2CmpTileStrc* pTile;
};

typedef void (__fastcall* D2TileFreeCallbackFn)(D2CmpTileStrc* pTile);

struct D2TileLibraryStrc
{
    char unk0x000[0x10C];
    int nTiles;
    D2TileLibraryEntryStrc* pTiles;
};


D2TileFreeCallbackFn gpfnTileFreeCallback; // 0x0088CB1C

void __fastcall LRUCacheTouch(D2CmpPoolStrc* pPool, D2LRUNodeStrc* pNode); // 0x00609380

D2LRUNodeStrc* __fastcall LRUCacheAlloc(D2CmpPoolStrc* pPool, unsigned int nSize, D2TileLibraryEntryStrc* pOwner); // 0x00609420

void __stdcall TileNormalizeSubTiles(D2TileLibraryEntryStrc* pEntry); // 0x0060A4C0

struct Config;

struct D2CmpSpriteContextStrc;

struct D2CmpDC6HeaderStrc;

struct D2CmpDC6CacheEntryStrc;

struct D2CmpDC6FrameStrc;

typedef char* va_list;

extern "C" int __cdecl vsprintf(char*,const char*,va_list);

extern "C" char* __cdecl strcat(char*,const char*);




static void* __stdcall SPRITECACHE_FindDC6Frame(void* pData, D2CmpSpriteContextStrc* pContext, D2CmpDC6HeaderStrc* pHeader); // 0x005FEB80

static void* SPRITECACHE_GetCachedDC6Frame(D2CmpSpriteContextStrc* pContext, D2CmpDC6CacheEntryStrc* pEntry); // 0x005FEC50

// 0x005FE210
void __stdcall D2CMPBuildFileName(char* output,int allowCompressed,const char* format,va_list args)
{
    vsprintf(output,format,args);
    const char* suffix = allowCompressed && gbCmpCompressedDataMode ? gszCmpCompressedExtension : gszCmpDefaultExtension;
    strcat(output,suffix);
}

// Kept noinline: CelGetRawData (0x6015D0) calls this out of line in the image; without it the compiler inlines it there.
// 0x00600C90
__declspec(noinline) int __stdcall CelGameDirToFileDir(int nDirection, unsigned int nDirections)
{
// build: symbol ?gaDirectionIndex64@* 0x006E45A0
    return gaDirectionIndex64[sub_00517ABB_FindLowestSetBit(nDirections)][nDirection];
}

// 0x00600D30
int __stdcall D2CMPSpriteCanConvertDirections(int nDirections, int nNewDirections)
{
    if (nDirections == 4)
    {
        return 0;
    }

    if (nDirections == 8 && nNewDirections == 16)
    {
        return 1;
    }

    return 0;
}

// 0x00601180
void __stdcall CelFileIteratePixels(D2CelFileStrc* pCelFile, int nArg)
{
    D2_ASSERT(pCelFile->dwFlags & 4, 0x322);
    for (unsigned int nDirection = 0; nDirection < pCelFile->nDirections; nDirection++)
    {
        for (unsigned int nFrame = 0; nFrame < pCelFile->nCelsPerDirection; nFrame++)
        {
            CelIterateRgbPixels(pCelFile->pCels[nDirection * pCelFile->nCelsPerDirection + nFrame], nArg, pCelFile->nTermination);
        }
    }
}

// 0x006011F0
int __stdcall CelFileSerialize(D2CelFileStrc* pCelFile, D2CelFileStrc** ppNewCelFile, unsigned int* pnSize)
{
    const unsigned int nCels = pCelFile->nCelsPerDirection * pCelFile->nDirections;
    unsigned int nSize = nCels * sizeof(D2CelStrc*) + 0x18;
    for (unsigned int i = 0; i < nCels; i++)
    {
        nSize += pCelFile->pCels[i]->nLength + pCelFile->pCels[i]->nDataSize + 0x23;
    }
    D2CelFileStrc* pNewCelFile = (D2CelFileStrc*)FOG_Alloc(nSize, ".\\SRC\\CelCmp.cpp", 0x345, 0);
    *pNewCelFile = *pCelFile;
    pNewCelFile->dwFlags = pNewCelFile->dwFlags & ~2 | 1;
    char* pData = (char*)&pNewCelFile->pCels[nCels];
    D2CelBlockStrc* pBlockToFree = 0;
    for (unsigned int i = 0; i < nCels; i++)
    {
        D2CelStrc* pNewCel = (D2CelStrc*)pData;
        const unsigned int nCelSize = pCelFile->pCels[i]->nLength + 0x23;
        pNewCelFile->pCels[i] = (D2CelStrc*)(pData - (char*)pNewCelFile);
        memcpy(pData, pCelFile->pCels[i], nCelSize);
        pData += nCelSize;
        if (pCelFile->pCels[i]->pBlockPixelData && pCelFile->pCels[i]->pBlockPixelData->pPixels)
        {
            memcpy(pData, pCelFile->pCels[i]->pBlockPixelData->pPixels, pCelFile->pCels[i]->nDataSize);
            if (!i)
            {
                pBlockToFree = pCelFile->pCels[0]->pBlockPixelData;
            }
        }
        pNewCel->pBlockPixelData = (D2CelBlockStrc*)(pData - (char*)pNewCelFile);
        pData += pCelFile->pCels[i]->nDataSize;
    }
    if (pBlockToFree)
    {
        FOG_Free(pBlockToFree, ".\\SRC\\CelCmp.cpp", 0x375, 0);
    }
    *ppNewCelFile = pNewCelFile;
    *pnSize = nSize;
    return 1;
}

// 0x00601340
void __stdcall CelFileNormalize(D2CelFileStrc* pFile, D2CelFileStrc** ppOutFile, const char* szFile, int nLine, int nSpecVersion, int nUnused)
{
    if (!pFile)
    {
        return;
    }

    const unsigned int dwFlags = pFile->dwFlags;
    D2_ASSERT(dwFlags & 1, 0x396);
    if (nSpecVersion == -1)
    {
        D2_ASSERT(pFile->dwVersion == 6, 0x399);
    }
    else
    {
        D2_ASSERT(pFile->dwVersion == nSpecVersion, 0x39B);
    }

    if (dwFlags & 2)
    {
        return;
    }

    const unsigned int nSize = pFile->nDirections * pFile->nCelsPerDirection * sizeof(D2CelBlockStrc);
    pFile->dwFlags = dwFlags | 2;
    D2CelBlockStrc* pBlocks = (D2CelBlockStrc*)FOG_Alloc(nSize, ".\\SRC\\CelCmp.cpp", 0x3A6, 0);
    memset(pBlocks, 0, nSize);
    unsigned int i = 0;
    if (i < (unsigned int)(pFile->nDirections * pFile->nCelsPerDirection))
    {
        D2CelBlockStrc* pBlock = pBlocks;
        D2CelStrc** ppCels = pFile->pCels;
        do
        {
            *ppCels = (D2CelStrc*)((char*)*ppCels + (unsigned int)pFile);
            (*ppCels)->pBlockPixelData = pBlock;
            ++i;
            ++pBlock;
            ++ppCels;
        }
        while (i < (unsigned int)(pFile->nDirections * pFile->nCelsPerDirection));
    }

    *ppOutFile = pFile;
}

// 0x00601410
void __stdcall CelFileFreeSerialized(D2CelFileStrc* pCelFile)
{
    D2_ASSERT(pCelFile, 0x40D);
    FOG_Free(pCelFile, ".\\SRC\\CelCmp.cpp", 0x40E, 0);
}

// 0x00601450
void __stdcall CelFileTransform(D2CelFileStrc* pCelFile, int nArg)
{
    D2_ASSERT(pCelFile, 0x431);
    for (unsigned int i = 0; i < pCelFile->nDirections * pCelFile->nCelsPerDirection; i++)
    {
        gpfnCelFileCellOp[pCelFile->nFormat](pCelFile->pCels[i], nArg);
    }
}

// 0x006014C0
void __stdcall CelDraw(D2CmpCelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, int nArg9, int nArg10, int nArg11)
{
    D2CelFileStrc* pCelFile = pContext->pCelFile;
    if (pCelFile)
    {
        D2_ASSERT(pCelFile->dwVersion == 6, 0x452);
        D2_ASSERT(!(pCelFile->dwFlags & 4), 0x453);
    }

    D2_ASSERT(pBuffer, 0x456);
    D2CelStrc* pCel = pContext->pCel;
    D2_ASSERT(pCel, 0x459);

    nY += pCel->nYOffset;
    nX += pCel->nXOffset;
    int nRows = pCel->nHeight;
    int nSkipRows = 0;
    if (nY - nRows < 0)
    {
        nRows = nY + 1;
    }

    if (nRows <= 0)
    {
        return;
    }

    if (nY >= nHeight)
    {
        nSkipRows = nY - nHeight + 1;
        nRows -= nSkipRows;
        if (nRows <= 0)
        {
            return;
        }
        nY = nHeight - 1;
    }

    if (!nArg4 && !nArg5)
    {
        if (nX < 0 || nY < 0)
        {
            return;
        }
    }

    unsigned char* pDst = pBuffer + nY * nPitch + nX;
    int nFormat = 0;
    if (pCelFile)
    {
        nFormat = pCelFile->nFormat;
    }

    CELDRAWFN pfnDraw = gpfnCelDraw[nFormat];
    D2_ASSERT(pfnDraw, 0x481);
    pfnDraw(pCel, pDst, nX, nArg4, nArg5, nPitch, nSkipRows, nRows, nArg9, nArg10, nArg11);
}

// 0x006015D0
int __stdcall CelGetRawData(CellTable* p, int nDirection, int nIndex, void* pDst)
{
    if (p->type != 6)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x4a0);
        exit(-1);
    }
    if ((p->flags & 4) == 0)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x4a1);
        exit(-1);
    }
    int idx = CelGameDirToFileDir(nDirection, p->nDirections) * p->stride + nIndex;
    Cell* cell = p->cells[idx];
    int size = cell->height * cell->width;
    memcpy(pDst, cell->data, (unsigned int)size * 3);
    return 1;
}

// 0x00600C60
int __fastcall DATATBLS_CallFree(void* pMemory)
{
    return sub_00517ABB_FindLowestSetBit((unsigned int)pMemory);
}



// 0x005FDE50
void __fastcall D2CMPTileCacheReleaseTile(void* pEntry)
{
    D2CmpTileStrc* pTile = ((D2CmpPoolEntryStrc*)pEntry)->pTile;
    if (gpfnTileFreeCallback)
    {
        D2_ASSERT(!IsBadCodePtr((D2FarProcFn)gpfnTileFreeCallback), 0xB4);
        gpfnTileFreeCallback(pTile);
    }

    pTile->nCount = 0;
    pTile->pNext = 0;
}

// 0x00601650
void __stdcall CelDrawEx(D2CmpCelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, int nArg9, int nArg10, int nClipTop, int nClipRows, int nArg13)
{
    D2CelFileStrc* pCelFile = pContext->pCelFile;
    if (pCelFile)
    {
        D2_ASSERT(pCelFile->dwVersion == 6, 0x4C6);
        D2_ASSERT(!(pCelFile->dwFlags & 4), 0x4C7);
    }
    D2_ASSERT(pBuffer, 0x4CA);
    D2CelStrc* pCel = pContext->pCel;
    D2_ASSERT(pCel, 0x4CD);
    nY += pCel->nYOffset;
    int nEnd = nY - nClipTop;
    nX += pCel->nXOffset;
    int nStart = nEnd - nClipRows;
    if (nEnd < 0 || nStart >= nHeight)
    {
        return;
    }
    if (nStart < 0)
    {
        nStart = 0;
    }
    if (nEnd >= nHeight)
    {
        nEnd = nHeight - 1;
    }
    const int nRows = nEnd - nStart;
    if (!nRows)
    {
        return;
    }
    CELDRAWFN pfnDraw = gpfnCelDraw[pCelFile->nFormat];
    D2_ASSERT(pfnDraw, 0x4E9);
    pfnDraw(pCel, &pBuffer[nEnd * nPitch + nX], nX, nArg4, nArg5, nPitch, nY - nEnd, nRows, nArg9, nArg10, nArg13);
}

// 0x00601730
void __stdcall CelDrawShadow(D2CmpCelContextStrc* pContext, int nX, int nY, int nClipLeft, int nClipRight, unsigned char* pBuffer, int nHeightLimit, int nPitch, int nTable, int nColor)
{
    D2CelFileStrc* pCelFile = pContext->pCelFile;
    if (pCelFile)
    {
        D2_ASSERT(pCelFile->dwVersion == 6, 0x50D);
        D2_ASSERT(!(pCelFile->dwFlags & 4), 0x50E);
    }

    D2_ASSERT(pBuffer, 0x511);
    D2CelStrc* pCel = pContext->pCel;
    D2_ASSERT(pCel, 0x514);

    nX += pCel->nXOffset + pCel->nYOffset / 2;
    nY += pCel->nYOffset / 2;
    int nLines = (unsigned int)pCel->nHeight / 2;
    int nSkip = 0;
    if (nY - pCel->nHeight / 2 < 0)
    {
        nLines = nY + 1;
    }

    if (nLines <= 0)
    {
        return;
    }

    if (nY >= nHeightLimit)
    {
        nSkip = nY - nHeightLimit + 1;
        nLines -= nSkip;
        if (nLines <= 0)
        {
            return;
        }
        nY = nHeightLimit - 1;
    }

    const int nStart = nX - nSkip;
    CelDrawRleShadow(pCel, pBuffer + nY * nPitch + nStart, nStart, nClipLeft, nClipRight, nPitch, nSkip, nLines, nTable, nColor);
}

// 0x00601810
int __stdcall CelValidateContext(D2CmpCelContextStrc* pContext)
{
    D2CelFileStrc* pCelFile = (D2CelFileStrc*)pContext->pCelFile;
    if (!pCelFile)
    {
        return 0;
    }

    if (pCelFile->dwVersion != 6)
    {
        return 0;
    }

    if (pContext->nDirection >= 0x40)
    {
        return 0;
    }

    if (pContext->nFrame > pCelFile->nFrames)
    {
        return 0;
    }

    return 1;
}

// 0x006018C0
int __stdcall CelGetWidth(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 1403);

    return pCel->nWidth;
}

// 0x006018F0
int __stdcall CelGetHeight(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 0x589);

    return pCel->nHeight;
}

// 0x00601920
int __stdcall CelGetOffsetX(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 0x597);

    return pCel->nXOffset;
}

// 0x00601950
int __stdcall CelGetOffsetY(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 0x5A5);

    return pCel->nYOffset;
}

// 0x00601980
char* __stdcall CelGetControlData(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 0x5B4);
    return pCel->data;
}

// 0x006019B0
int __stdcall CelFileGetNumDirections(D2UnitStrc* unit)
{
    if(unit->dwUnitType!=REQUIRED_TYPE) {
        FOG_DisplayHalt(&emptyAssert,sub_00408090(),0x5C2);
        exit(-1);
    }
    return unit->dwAnimMode;
}

// 0x006019F0
int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pFile)
{
    D2_ASSERT(pFile->dwVersion == 6, 1489);

    return pFile->nCelsPerDirection;
}

// 0x00601A30
void __stdcall CelSetHardwareFreeCallback(PixelDataFreeCallback pfnCallback)
{
    gpfnPixelDataFree = pfnCallback;
}

// 0x00601A40
PixelDataFreeCallback __stdcall CelGetHardwareFreeCallback()
{
    return gpfnPixelDataFree;
}

// 0x00601A50
int __stdcall CelFileFreeHardware(D2CelFileStrc* ptFile)
{
    if (!ptFile)
    {
        return 0;
    }
    D2_ASSERT(ptFile->dwVersion == 6, 0x5F1);
    D2CelBlockStrc* pBlocks = ptFile->pCels[0]->pBlockPixelData;
    D2_ASSERT(pBlocks, 0x5F5);
    for (unsigned int i = 0; i < ptFile->nCelsPerDirection * ptFile->nDirections; i++)
    {
        if (ptFile->pCels[i] && ptFile->pCels[i]->pBlockPixelData)
        {
            if (gpfnPixelDataFree)
            {
                gpfnPixelDataFree(ptFile->pCels[i]->pBlockPixelData);
            }
            ptFile->pCels[i]->pBlockPixelData = 0;
        }
    }
    FOG_Free(pBlocks, ".\\SRC\\CelCmp.cpp", 0x61D, 0);
    return 1;
}

// 0x00601840
D2CelStrc* __stdcall CelGetHandle(D2CmpCelContextStrc* pCelContext)
{
    D2_ASSERT(pCelContext, 0x566);
    D2_ASSERT(CelValidateContext(pCelContext), 0x567);

    D2CelFileStrc* pCelFile = (D2CelFileStrc*)pCelContext->pCelFile;
    const unsigned int nDirection = pCelContext->nDirection;
    const unsigned int nDirections = pCelFile->nDirectionCount;
// build: symbol ?gaDirectionIndex64@* 0x006E45A0
    const int nIndex = gaDirectionIndex64[sub_00517ABB_BitScanForward1(nDirections)][nDirection];
    return pCelFile->pCels[nIndex * pCelFile->nFrames + pCelContext->nFrame];
}

unsigned short __stdcall SFileGetLocale()
{
    return gwValue_0077905C;
}

void __stdcall sub_00416750_Nop()
{
}

void __stdcall sub_00416760_Nop()
{
}

char* __fastcall sub_004167A0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

D2Storm4167B0Strc::~D2Storm4167B0Strc()
{
    m_link.Unlink();
}

char* __fastcall sub_004167F0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}


static unsigned int __stdcall STORM_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

char* __fastcall sub_00416820_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416830_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416840_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416850_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416860_LinkPrev(D2StormLinkStrc* pLink)
{
    D2StormLinkStrc* pPrev = pLink->m_prevlink->m_prevlink;
    return (int)pPrev->m_next > 0 ? pPrev->m_next : 0;
}

char* __fastcall sub_00416880_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

D2Storm4168F0Strc::~D2Storm4168F0Strc()
{
    m_link.Unlink();
}

void __fastcall sub_004169F0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A00_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A10_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A20_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A30_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

int __fastcall sub_00416A90_TestField150(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n150)
        return 1;
    return 0;
}

int __fastcall sub_00416AB0_TestField14C(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n14C)
        return 1;
    return 0;
}



extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

// Three members of the cel list table keep the forms this file had before: the original reloads the slot list
// on every step of its loops, and no plain form of the templates' members has given that yet. InternalFind is
// defined at the end of the file; GenerateHandle is CelCmp_00603280.cpp's.
template<>
CELLIST* TSHashTable<CELLIST, HASHKEY_NONE>::InternalFind(unsigned int hashval, const HASHKEY_NONE& key);
template<>
int TSHashTable<CELLIST, HASHKEY_NONE>::MonitorFullness(unsigned int slot);
template<>
HCELLIST__* TSExportTableSimple<CELLIST, HCELLIST__*, 0>::GenerateHandle();


// 0x00601B10
void* __stdcall CelGetHardwareData(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 1578);

    return pCel->pBlockPixelData;
}

// 0x006045B0
template<>
int TSHashTable<CELLIST, HASHKEY_NONE>::MonitorFullness(unsigned int slot)
{
    D2CelListList* const& listarray = m_slotlistarray.m_data;
    if (m_slotmask >= 0x3FF)
        return 0;
    if (m_fullnessIndicator > 3)
        m_fullnessIndicator -= 3;
    else
        m_fullnessIndicator = 0;
    TSLink<CELLIST>* const terminator = &listarray[slot].m_terminator;
    CELLIST* const head = (int)terminator->m_next <= 0 ? 0 : terminator->m_next;
    for (CELLIST* ptr = head; (int)ptr > 0; )
    {
        ++m_fullnessIndicator;
        if (m_fullnessIndicator > 13)
        {
            m_fullnessIndicator = 0;
            GrowListArray();
            return 1;
        }
        ptr = listarray[slot].Link(ptr)->m_next;
    }
    return 0;
}

// Members of the cel list's templates whose template form isn't settled keep placeholder names: two empty
// functions, a link test, three link clears and three list resets (typed by their place in the run), a constant, two copies
// of a list's link offset, two member destructors, a list destructor, and the array wrappers the game list's
// object has too (SetCount, ReserveExact, New, a pair difference).
// 0x00601B40
void __cdecl sub_00601B40_Empty()
{
}

// 0x00601B50
void __cdecl sub_00601B50_Empty()
{
}

// 0x00601BB0
void __fastcall sub_00601BB0_ClearLink(TSLink<TCELENTRY>* pLink)
{
    pLink->m_prevlink = 0;
    pLink->m_next = 0;
}

// 0x00601D10
int __cdecl sub_00601D10()
{
    return 4;
}

// 0x00601D20
void __fastcall sub_00601D20_ClearLink(TSLink<CELLIST>* pLink)
{
    pLink->m_prevlink = 0;
    pLink->m_next = 0;
}

// 0x00601DB0
void __fastcall sub_00601DB0_ClearLink(TSLink<D2CelListChunk>* pLink)
{
    pLink->m_prevlink = 0;
    pLink->m_next = 0;
}

// 0x00602370
void __fastcall sub_00602370_ResetList(D2CelEntryList* pList)
{
    pList->SetLinkOffset(0);
}

// 0x00602390
void __fastcall sub_00602390_ResetList(D2CelListList* pList)
{
    pList->SetLinkOffset(0);
}

// 0x00603510
void __fastcall sub_00603510_ResetList(TSList<D2CelListChunk, TSGetExplicitLink<D2CelListChunk> >* pList)
{
    pList->SetLinkOffset(0);
}

struct D2CelEntryLinkHolderStrc
{
    TSLink<TCELENTRY> m_link;

    bool sub_00601DC0_IsLinked();
};

// 0x00601DC0
bool D2CelEntryLinkHolderStrc::sub_00601DC0_IsLinked()
{
    return m_link.m_next != 0;
}

struct D2CelEntryListHolderStrc
{
    D2CelEntryList m_list;

    void sub_00601E80_CopyLinkOffset(const D2CelEntryList& source);
};

struct D2CelChunkListHolderStrc
{
    TSExplicitList<D2CelListChunk, 0x10> m_list;

    void sub_00603F50_CopyLinkOffset(const TSExplicitList<D2CelListChunk, 0x10>& source);
};

// 0x00601E80
void D2CelEntryListHolderStrc::sub_00601E80_CopyLinkOffset(const D2CelEntryList& source)
{
    m_list.SetLinkOffset(source.m_linkoffset);
}

// 0x00603F50
void D2CelChunkListHolderStrc::sub_00603F50_CopyLinkOffset(const TSExplicitList<D2CelListChunk, 0x10>& source)
{
    m_list.SetLinkOffset(source.m_linkoffset);
}

struct D2CelListLinkHolderStrc
{
    TSLink<CELLIST> m_link;

    ~D2CelListLinkHolderStrc();
};

struct D2CelChunkLinkHolderStrc
{
    TSLink<D2CelListChunk> m_link;

    ~D2CelChunkLinkHolderStrc();
};

struct D2CelListListHolderStrc
{
    D2CelListList m_list;

    ~D2CelListListHolderStrc();
};

// 0x006024A0
D2CelListLinkHolderStrc::~D2CelListLinkHolderStrc()
{
}

// 0x00602760
D2CelChunkLinkHolderStrc::~D2CelChunkLinkHolderStrc()
{
}

// 0x00602DF0
D2CelListListHolderStrc::~D2CelListListHolderStrc()
{
}

struct D2CelListArrayHolderStrc
{
    TSGrowableArray<D2CelListList> m_array;

    void sub_00603850_SetCount(unsigned int nCount);
};

struct D2CelListRecordArrayHolderStrc
{
    TSGrowableArray<CELLIST> m_array;

    void CelListArrayGrow(unsigned int nCount);
    CELLIST* sub_00604460_New();
};

struct D2CelListPairStrc
{
    unsigned int nFirst;
    unsigned int nSecond;

    unsigned int sub_00603ED0_GetDifference();
};

// 0x00603850
void D2CelListArrayHolderStrc::sub_00603850_SetCount(unsigned int nCount)
{
    m_array.SetCount(nCount);
}

// 0x00603ED0
unsigned int D2CelListPairStrc::sub_00603ED0_GetDifference()
{
    return nFirst - nSecond;
}

// 0x00604440
void D2CelListRecordArrayHolderStrc::CelListArrayGrow(unsigned int nCount)
{
    unsigned int nTotal = m_array.m_count + nCount;
    if (nTotal > m_array.m_alloc)
        m_array.ReallocData(nTotal);
}

// 0x00604460
CELLIST* D2CelListRecordArrayHolderStrc::sub_00604460_New()
{
    return m_array.New();
}

// The cel list's Storm template members (D2CMP keeps its cel lists in a TSExportTableSync over
// TSHashTableReuse<CELLIST, HASHKEY_NONE, 0>), in the order the object has them.
// build: symbol ?Next@?$TSLink@UTCELENTRY@@@@QAEPAUTCELENTRY@@XZ 0x00601B60
// build: symbol ?RawNext@?$TSLink@UTCELENTRY@@@@QAEPAUTCELENTRY@@XZ 0x00601B70
// build: symbol ?SyncEnterLock@?$TSExportTableSync@UCELLIST@@PAUHCELLIST__@@PAUHLOCKEDCELLIST__@@VCCritSect@@$0A@@@QAEXPAPAUHLOCKEDCELLIST__@@H@Z 0x00601B80
// build: symbol ?NextLink@?$TSLink@UTCELENTRY@@@@QAEPAU1@H@Z 0x00601BC0
// build: symbol ??1?$TSLink@UTCELENTRY@@@@QAE@XZ 0x00601BF0
// build: symbol ?NextLink@?$TSLink@UCELLIST@@@@QAEPAU1@H@Z 0x00601C30
// build: symbol ?Next@?$TSLink@UCELLIST@@@@QAEPAUCELLIST@@XZ 0x00601C60
// build: symbol ??1?$TSLinkedNode@UTCELENTRY@@@@QAE@XZ 0x00601C70
// build: symbol ?IsWriteLock@?$TSExportTableSync@UCELLIST@@PAUHCELLIST__@@PAUHLOCKEDCELLIST__@@VCCritSect@@$0A@@@QAEHPAUHLOCKEDCELLIST__@@@Z 0x00601CB0
// build: symbol ??A?$TSBaseArray@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@@@QAEAAV?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@I@Z 0x00601CC0
// build: symbol ?Next@?$TSLink@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@@@QAEPAV?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@XZ 0x00601CE0
// build: symbol ?Link@?$TSGetLink@UTCELENTRY@@@@SIPAU?$TSLink@UTCELENTRY@@@@PBUTCELENTRY@@H@Z 0x00601CF0
// build: symbol ?ComputeSlot@?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@QAEII@Z 0x00601D00
// build: symbol ?NextLink@?$TSLink@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@@@QAEPAU1@H@Z 0x00601D30
// build: symbol ??1TCELENTRY@@QAE@XZ 0x00601D60
// build: symbol ?Link@?$TSGetExplicitLink@UCELLIST@@@@SIPAU?$TSLink@UCELLIST@@@@PBUCELLIST@@H@Z 0x00601DA0
// build: symbol ?Count@?$TSBaseArray@UCELLIST@@@@QBEIXZ 0x00601DD0
// build: symbol ?Link@?$TSGetExplicitLink@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@@@SIPAU?$TSLink@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@@@PBV?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@H@Z 0x00601DE0
// build: symbol ?InitializeTerminator@?$TSList@UTCELENTRY@@U?$TSGetLink@UTCELENTRY@@@@@@QAEXXZ 0x00601DF0
// build: symbol ??0?$TSBaseArray@UCELLIST@@@@QAE@XZ 0x00601E00
// build: symbol ?InitializeTerminator@?$TSList@UCELLIST@@U?$TSGetExplicitLink@UCELLIST@@@@@@QAEXXZ 0x00601E10
// build: symbol ?CalcChunkSize@?$TSGrowableArray@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@@@@@QAEII@Z 0x00601E20
// build: symbol ?RoundUp@?$TSGrowableArray@UCELLIST@@U?$TSCD@UCELLIST@@@@@@QAEIII@Z 0x00601E60
// build: symbol ?Head@?$TSList@UTCELENTRY@@U?$TSGetLink@UTCELENTRY@@@@@@QAEPAUTCELENTRY@@XZ 0x00601F00
// build: symbol ??0?$TSLink@UTCELENTRY@@@@QAE@XZ 0x00601F10
// build: symbol ?Unlink@?$TSLink@UTCELENTRY@@@@QAEXXZ 0x00601F20
// build: symbol ??1?$TSLink@UCELLIST@@@@QAE@XZ 0x00601F60
// build: symbol ?Link@?$TSList@UTCELENTRY@@U?$TSGetLink@UTCELENTRY@@@@@@QAEPAU?$TSLink@UTCELENTRY@@@@PBUTCELENTRY@@@Z 0x00601FA0
// build: symbol ?LinkNode@?$TSList@UTCELENTRY@@U?$TSGetLink@UTCELENTRY@@@@@@QAEXPAUTCELENTRY@@I0@Z 0x00601FC0
// build: symbol ?Next@?$TSList@UTCELENTRY@@U?$TSGetLink@UTCELENTRY@@@@@@QAEPAUTCELENTRY@@PBU2@@Z 0x00602070
// build: symbol ?SyncLeaveLock@?$TSExportTableSync@UCELLIST@@PAUHCELLIST__@@PAUHLOCKEDCELLIST__@@VCCritSect@@$0A@@@QAEXPAUHLOCKEDCELLIST__@@@Z 0x00602090
// build: symbol ?Head@?$TSList@UCELLIST@@U?$TSGetExplicitLink@UCELLIST@@@@@@QAEPAUCELLIST@@XZ 0x006020B0
// build: symbol ?Head@?$TSList@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@@@@@QAEPAV?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@XZ 0x006020C0
// build: symbol ?Unlink@?$TSLink@UCELLIST@@@@QAEXXZ 0x006020D0
// build: symbol ?Link@?$TSList@UCELLIST@@U?$TSGetExplicitLink@UCELLIST@@@@@@QAEPAU?$TSLink@UCELLIST@@@@PBUCELLIST@@@Z 0x00602110
// build: symbol ??0?$TSLinkedNode@UTCELENTRY@@@@QAE@XZ 0x00602130
// build: symbol ??1?$TSLink@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@@@QAE@XZ 0x00602140
// build: symbol ??0TCELENTRY@@QAE@XZ 0x00602180
// build: symbol ?UnlinkNode@?$TSList@UTCELENTRY@@U?$TSGetLink@UTCELENTRY@@@@@@QAEXPAUTCELENTRY@@@Z 0x00602190
// build: symbol ?Unlink@?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@QAEXPAUCELLIST@@@Z 0x006021E0
// build: symbol ?RawNext@?$TSList@UCELLIST@@U?$TSGetExplicitLink@UCELLIST@@@@@@QAEPAUCELLIST@@PBU2@@Z 0x00602260
// build: symbol ?Link@?$TSList@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@@@@@QAEPAU?$TSLink@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@@@PBV?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@@Z 0x00602280
// build: symbol ?UnlinkNode@?$TSList@UCELLIST@@U?$TSGetExplicitLink@UCELLIST@@@@@@QAEXPAUCELLIST@@@Z 0x006022A0
// build: symbol ?SetLinkOffset@?$TSList@UTCELENTRY@@U?$TSGetLink@UTCELENTRY@@@@@@QAEXH@Z 0x006022F0
// build: symbol ?Next@?$TSList@UCELLIST@@U?$TSGetExplicitLink@UCELLIST@@@@@@QAEPAUCELLIST@@PBU2@@Z 0x00602310
// build: symbol ?SetLinkOffset@?$TSList@UCELLIST@@U?$TSGetExplicitLink@UCELLIST@@@@@@QAEXH@Z 0x00602350
// build: symbol ??0?$TSList@UTCELENTRY@@U?$TSGetLink@UTCELENTRY@@@@@@QAE@ABU0@@Z 0x006023B0
// build: symbol ?RawNext@?$TSList@UTCELENTRY@@U?$TSGetLink@UTCELENTRY@@@@@@QAEPAUTCELENTRY@@PBU2@@Z 0x006023E0
// build: symbol ?Unlock@?$TSExportTableSync@UCELLIST@@PAUHCELLIST__@@PAUHLOCKEDCELLIST__@@VCCritSect@@$0A@@@QAEXPAUHLOCKEDCELLIST__@@@Z 0x00602400
// build: symbol ??0?$TSLink@UCELLIST@@@@QAE@XZ 0x00602420
// build: symbol ??1?$TSHashObject@UCELLIST@@VHASHKEY_NONE@@@@QAE@XZ 0x00602430
// build: symbol ?LinkNode@?$TSList@UCELLIST@@U?$TSGetExplicitLink@UCELLIST@@@@@@QAEXPAUCELLIST@@I0@Z 0x006024E0
// build: symbol ?UnlinkNode@?$TSList@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@@@@@QAEXPAV?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@@Z 0x00602590
// build: symbol ?UnlinkAll@?$TSList@UTCELENTRY@@U?$TSGetLink@UTCELENTRY@@@@@@QAEXXZ 0x006025E0
// build: symbol ?Delete@?$TSExportTableSimple@UCELLIST@@PAUHCELLIST__@@$0A@@@QAEXPAUCELLIST@@@Z 0x00602620
// build: symbol ?UnlinkAll@?$TSList@UCELLIST@@U?$TSGetExplicitLink@UCELLIST@@@@@@QAEXXZ 0x00602640
// build: symbol ?UnlinkAll@?$TSList@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@@@@@QAEXXZ 0x00602690
// build: symbol ?ChangeLinkOffset@?$TSList@UCELLIST@@U?$TSGetExplicitLink@UCELLIST@@@@@@QAEXH@Z 0x006026E0
// build: symbol ??0?$TSList@UTCELENTRY@@U?$TSGetLink@UTCELENTRY@@@@@@QAE@XZ 0x00602710
// build: symbol ??0?$TSList@UCELLIST@@U?$TSGetExplicitLink@UCELLIST@@@@@@QAE@XZ 0x00602730
// build: symbol ??0?$TSLink@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@@@QAE@XZ 0x00602750
// build: symbol ??1?$TSList@UTCELENTRY@@U?$TSGetLink@UTCELENTRY@@@@@@QAE@XZ 0x006027A0
// build: symbol ?Delete@?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@QAEXPAUCELLIST@@@Z 0x006027E0
// build: symbol ?InternalClear@?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@QAEXH@Z 0x00602800
// build: symbol ??1?$TSList@UCELLIST@@U?$TSGetExplicitLink@UCELLIST@@@@@@QAE@XZ 0x00602890
// build: symbol ??1?$TSExplicitList@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@$0BA@@@QAE@XZ 0x006028D0
// build: symbol ??0?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@QAE@XZ 0x00602910
// build: symbol ??0?$TSExplicitList@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@$0BA@@@QAE@XZ 0x00602930
// build: symbol ?Construct@?$TSCD@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@@@SIXPAV?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@@Z 0x00602950
// build: symbol ??0?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@QAE@ABV0@@Z 0x00602980
// build: symbol ?NewNode@?$TSList@UTCELENTRY@@U?$TSGetLink@UTCELENTRY@@@@@@QAEPAUTCELENTRY@@III@Z 0x006029B0
// build: symbol ?DeleteUnlock@?$TSExportTableSync@UCELLIST@@PAUHCELLIST__@@PAUHLOCKEDCELLIST__@@VCCritSect@@$0A@@@QAEXPAUCELLIST@@PAUHLOCKEDCELLIST__@@@Z 0x00602A10
// build: symbol ??_GTCELENTRY@@QAEPAXI@Z 0x00602A40
// build: symbol ??1?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@QAE@XZ 0x00602AA0
// build: symbol ??1?$TSList@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@@@@@QAE@XZ 0x00602AE0
// build: symbol ??1CELLIST@@QAE@XZ 0x00602B20
// build: symbol ??_G?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@QAEPAXI@Z 0x00602B70
// build: symbol ?CopyConstruct@?$TSCD@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@@@SIXPAV?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@ABV2@@Z 0x00602BD0
// build: symbol ?Clear@?$TSList@UTCELENTRY@@U?$TSGetLink@UTCELENTRY@@@@@@QAEXXZ 0x00602BF0
// build: symbol ?DeleteNode@?$TSList@UTCELENTRY@@U?$TSGetLink@UTCELENTRY@@@@@@QAEPAUTCELENTRY@@PAU2@@Z 0x00602C40
// build: symbol ??_GCELLIST@@QAEPAXI@Z 0x00602CB0
// build: symbol ?Clear@?$TSList@UCELLIST@@U?$TSGetExplicitLink@UCELLIST@@@@@@QAEXXZ 0x00602D20
// build: symbol ?DeleteNode@?$TSList@UCELLIST@@U?$TSGetExplicitLink@UCELLIST@@@@@@QAEPAUCELLIST@@PAU2@@Z 0x00602E30
// build: symbol ?Destruct@?$TSCD@UCELLIST@@@@SIXPAUCELLIST@@@Z 0x00602EC0
// build: symbol ?ReallocData@?$TSGrowableArray@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@@@@@QAEXI@Z 0x00602F10
// build: symbol ??1?$TSFixedArray@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@@@@@QAE@XZ 0x00603060
// build: symbol ?InternalFind@?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@QAEPAUCELLIST@@IABVHASHKEY_NONE@@@Z 0x006030E0
// build: symbol ??1?$TSFixedArray@UCELLIST@@U?$TSCD@UCELLIST@@@@@@QAE@XZ 0x00603140
// build: symbol ??0?$TSGrowableArray@UCELLIST@@U?$TSCD@UCELLIST@@@@@@QAE@XZ 0x006031E0
// build: symbol ?Reserve@?$TSGrowableArray@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@@@@@QAEXIH@Z 0x006031F0
// build: symbol ??1?$TSGrowableArray@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@@@@@QAE@XZ 0x00603240
// build: symbol ?Ptr@?$TSExportTableSimple@UCELLIST@@PAUHCELLIST__@@$0A@@@QAEPAUCELLIST@@PAUHCELLIST__@@@Z 0x00603250
// build: symbol ??1?$TSGrowableArray@UCELLIST@@U?$TSCD@UCELLIST@@@@@@QAE@XZ 0x00603270
// build: symbol ??1?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@QAE@XZ 0x006032C0
// build: symbol ?SetCount@?$TSGrowableArray@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@@@@@QAEXI@Z 0x00603300
// build: symbol ?Lock@?$TSExportTableSync@UCELLIST@@PAUHCELLIST__@@PAUHLOCKEDCELLIST__@@VCCritSect@@$0A@@@QAEPAUCELLIST@@PAUHCELLIST__@@PAPAUHLOCKEDCELLIST__@@H@Z 0x00603400
// build: symbol ??1?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@UAE@XZ 0x00603460
// build: symbol ?InitializeTerminator@?$TSList@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@@@@@QAEXXZ 0x00603500
// build: symbol ??0?$TSHashObject@UCELLIST@@VHASHKEY_NONE@@@@QAE@XZ 0x00603530
// build: symbol ??0?$TSList@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@@@@@QAE@XZ 0x00603550
// build: symbol ??0CELLIST@@QAE@XZ 0x00603570
// build: symbol ?NewNode@?$TSList@UCELLIST@@U?$TSGetExplicitLink@UCELLIST@@@@@@QAEPAUCELLIST@@III@Z 0x006035A0
// build: symbol ?InternalNew@?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@UAEPAUCELLIST@@PAV?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@II@Z 0x00603610
// build: symbol ?InternalDelete@?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@UAEXPAUCELLIST@@@Z 0x006036D0
// build: symbol ??_G?$TSFixedArray@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@@@@@QAEPAXI@Z 0x00603730
// build: symbol ?Clear@?$TSFixedArray@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@@@@@QAEXXZ 0x00603760
// build: symbol ?Destroy@?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@UAEXXZ 0x00603780
// build: symbol ??_G?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@UAEPAXI@Z 0x006037B0
// build: symbol ??_G?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@QAEPAXI@Z 0x006037E0
// build: symbol ?Clear@?$TSList@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@@@@@QAEXXZ 0x00603B60
// build: symbol ??0?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@QAE@XZ 0x00603BD0
// build: symbol ?GrowListArray@?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@QAEXXZ 0x00603C80
// build: symbol ?DeleteChunksAndReuse@?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@QAEXXZ 0x00603E50
// build: symbol ??0?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@QAE@XZ 0x00603E70
// build: symbol ?CalcChunkSize@?$TSGrowableArray@UCELLIST@@U?$TSCD@UCELLIST@@@@@@QAEII@Z 0x00603EE0
// build: symbol ?RoundUp@?$TSGrowableArray@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@@@@@QAEIII@Z 0x00603F20
// build: symbol ??0?$TSBaseArray@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@@@QAE@XZ 0x00603F40
// build: symbol ??0?$TSHashObject@UCELLIST@@VHASHKEY_NONE@@@@QAE@ABU0@@Z 0x00603F70
// build: symbol ??0?$TSList@UCELLIST@@U?$TSGetExplicitLink@UCELLIST@@@@@@QAE@ABU0@@Z 0x00603F90
// build: symbol ?LinkNode@?$TSList@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@@@@@QAEXPAV?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@I0@Z 0x00603FC0
// build: symbol ?Clear@?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@QAEXXZ 0x00604070
// build: symbol ?Construct@?$TSCD@UCELLIST@@@@SIXPAUCELLIST@@@Z 0x00604080
// build: symbol ??0CELLIST@@QAE@ABU0@@Z 0x006040B0
// build: symbol ?CopyConstruct@?$TSCD@UCELLIST@@@@SIXPAUCELLIST@@ABU2@@Z 0x00604100
// build: symbol ?InternalDelete@?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@UAEXPAUCELLIST@@@Z 0x00604150
// build: symbol ?ReallocData@?$TSGrowableArray@UCELLIST@@U?$TSCD@UCELLIST@@@@@@QAEXI@Z 0x006041B0
// build: symbol ?Reserve@?$TSGrowableArray@UCELLIST@@U?$TSCD@UCELLIST@@@@@@QAEXIH@Z 0x00604350
// build: symbol ??0?$TSGrowableArray@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@@@@@QAE@XZ 0x006043A0
// build: symbol ?New@?$TSGrowableArray@UCELLIST@@U?$TSCD@UCELLIST@@@@@@QAEPAUCELLIST@@XZ 0x006043B0
// build: symbol ??0?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@QAE@XZ 0x00604470
// build: symbol ?NewNode@?$TSList@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@@@@@QAEPAV?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@III@Z 0x00604490
// build: symbol ?InternalNew@?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@UAEPAUCELLIST@@PAV?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@II@Z 0x006044F0
// build: symbol ?MonitorFullness@?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@QAEHI@Z 0x006045B0
// build: symbol ??1?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@UAE@XZ 0x00604640
// build: symbol ?Destroy@?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@UAEXXZ 0x006046E0
// build: symbol ??_G?$TSExportTableSimple@UCELLIST@@PAUHCELLIST__@@$0A@@@UAEPAXI@Z 0x00604700
// build: symbol ??0?$TSExportTableSimple@UCELLIST@@PAUHCELLIST__@@$0A@@@QAE@XZ 0x00604730
// build: symbol ?New@?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@QAEPAUCELLIST@@IABVHASHKEY_NONE@@II@Z 0x00604760
// build: symbol ??1?$TSExportTableSimple@UCELLIST@@PAUHCELLIST__@@$0A@@@UAE@XZ 0x00604800
// build: symbol ??0?$TSExportTableSync@UCELLIST@@PAUHCELLIST__@@PAUHLOCKEDCELLIST__@@VCCritSect@@$0A@@@QAE@XZ 0x00604810
// build: symbol ?NewHandle@?$TSExportTableSimple@UCELLIST@@PAUHCELLIST__@@$0A@@@QAEPAUCELLIST@@PAPAUHCELLIST__@@@Z 0x00604840
// build: symbol ??_G?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@UAEPAXI@Z 0x00604870
// build: symbol ??1?$TSExportTableSync@UCELLIST@@PAUHCELLIST__@@PAUHLOCKEDCELLIST__@@VCCritSect@@$0A@@@UAE@XZ 0x006048A0
// build: symbol ?NewLock@?$TSExportTableSync@UCELLIST@@PAUHCELLIST__@@PAUHLOCKEDCELLIST__@@VCCritSect@@$0A@@@QAEPAUCELLIST@@PAPAUHCELLIST__@@PAPAUHLOCKEDCELLIST__@@@Z 0x006048C0
// build: symbol ??_G?$TSExportTableSync@UCELLIST@@PAUHCELLIST__@@PAUHLOCKEDCELLIST__@@VCCritSect@@$0A@@@UAEPAXI@Z 0x00604900
// build: symbol ??__EgCelListTable@@YAXXZ 0x006CAFC0
// build: symbol ??__FgCelListTable@@YAXXZ 0x006CB4C0
// build: symbol ?GenerateHandle@?$TSExportTableSimple@UCELLIST@@PAUHCELLIST__@@$0A@@@QAEPAUHCELLIST__@@XZ 0x00603280
// build: symbol ??_7?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@6B@ 0x006E5DE8
// build: symbol ??_7?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@6B@ 0x006E5DFC
// build: symbol ??_7?$TSExportTableSimple@UCELLIST@@PAUHCELLIST__@@$0A@@@6B@ 0x006E5E10
// build: symbol ??_7?$TSExportTableSync@UCELLIST@@PAUHCELLIST__@@PAUHLOCKEDCELLIST__@@VCCritSect@@$0A@@@6B@ 0x006E5E24
// build: symbol ??_R0?AUTCELENTRY@@@8 0x00741F0C
// build: symbol ??_R0?AUCELLIST@@@8 0x00741F24
// build: symbol ??_R0?AV?$TSExplicitList@UCELLIST@@$0?CCCCCCCD@@@@8 0x00741F3C
// build: symbol ??_R0?AV?$TSHashObjectChunk@UCELLIST@@VHASHKEY_NONE@@@@@8 0x00741FAC
template int D2CelListSyncTable::IsWriteLock(HLOCKEDCELLIST__*);
template unsigned int D2CelListTable::ComputeSlot(unsigned int);
template TSBaseArray<CELLIST>::TSBaseArray();
template unsigned int TSBaseArray<CELLIST>::Count() const;
template TCELENTRY* D2CelEntryList::Next(const TCELENTRY*);
template CELLIST* TSList<CELLIST, TSGetExplicitLink<CELLIST> >::Next(const CELLIST*);
template TCELENTRY* D2CelEntryList::RawNext(const TCELENTRY*);
template void D2CelListSyncTable::Unlock(HLOCKEDCELLIST__*);
template void D2CelListTable::Delete(CELLIST*);
template void D2CelListSyncTable::DeleteUnlock(CELLIST*, HLOCKEDCELLIST__*);
template TCELENTRY* D2CelEntryList::DeleteNode(TCELENTRY*);
template CELLIST* TSList<CELLIST, TSGetExplicitLink<CELLIST> >::DeleteNode(CELLIST*);
template TSGrowableArray<CELLIST>::TSGrowableArray();
template void TSGrowableArray<D2CelListList>::Reserve(unsigned int, int);
template CELLIST* TSList<CELLIST, TSGetExplicitLink<CELLIST> >::NewNode(unsigned int, unsigned int, unsigned int);
template void TSList<D2CelListChunk, TSGetExplicitLink<D2CelListChunk> >::LinkNode(D2CelListChunk*, unsigned int, D2CelListChunk*);
template void D2CelListTable::Clear();
template D2CelListChunk* TSList<D2CelListChunk, TSGetExplicitLink<D2CelListChunk> >::NewNode(unsigned int, unsigned int, unsigned int);

// 0x00601EA0
void __stdcall CelFileFree(D2CelFileStrc* pCelFile)
{
    D2_ASSERT(pCelFile, 0x41B);
    if (pCelFile->dwFlags & 3)
    {
        if (pCelFile->dwFlags & 2)
        {
            CelFileFreeHardware(pCelFile);
        }
        FOG_Free(pCelFile, ".\\SRC\\CelCmp.cpp", 0x422, 0);
    }
}

bool D2ChatStormLinkStrc::IGNORELIST_IsLinkLinked()
{
    return m_next != 0;
}

char* D2ChatStormLinkStrc::sub_0060E1A0_Next()
{
    return MaskNext();
}

char* D2ChatStormLinkStrc::sub_0060E240_Next()
{
    return MaskNext();
}

void D2ChatStormLinkStrc::sub_0060E3B0_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E400_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E690_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E760_Unlink()
{
    Unlink();
}

D2ChatStormLinkAStrc::D2ChatStormLinkAStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

D2ChatStormLinkBStrc::D2ChatStormLinkBStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

char* D2ChatStormNodeStrc::IGNORELIST_GetStringEntryKey()
{
    return m_key;
}

D2ChatStormBaseArrayAStrc::D2ChatStormBaseArrayAStrc()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

unsigned int D2ChatStormBaseArrayAStrc::IGNORELIST_GetStringSlotArrayCount()
{
    return m_count;
}

D2ChatStormBaseArrayBStrc::D2ChatStormBaseArrayBStrc()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

unsigned int D2ChatStormBaseArrayBStrc::IGNORELIST_GetMappingSlotArrayCount()
{
    return m_count;
}

void D2ChatStormListAStrc::IGNORELIST_InitStringListTerminator()
{
    InitializeTerminator();
}

void D2ChatStormListBStrc::IGNORELIST_InitMappingListTerminator()
{
    InitializeTerminator();
}

char* D2ChatStormListBStrc::IGNORELIST_GetMappingListHead()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::IGNORELIST_ResetMappingList()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

namespace NWardenClient
{
struct Library
{
    Library();
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
};
}

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

sub_0044F9F0::~sub_0044F9F0()
{
}

D2StormListAStrc::~D2StormListAStrc()
{
    UnlinkAll();
}

D2StormChunkListStrc::~D2StormChunkListStrc()
{
    UnlinkAll();
}

sub_0044FBE0::~sub_0044FBE0()
{
}

sub_0044FC20::~sub_0044FC20()
{
}

void __fastcall sub_0044FD60_CopyConstructDeadList(D2StormDeadListStrc* pList, const D2StormDeadListStrc* pSource)
{
    new (pList) D2StormDeadListStrc(*pSource);
}

sub_0044FDD0::~sub_0044FDD0()
{
}

D2StormGameGrowArrayStrc::~D2StormGameGrowArrayStrc()
{
}

D2StormGameHashChunkStrc::~D2StormGameHashChunkStrc()
{
    m_link.Unlink();
}

inline unsigned int RoundUpInline(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

inline void D2StormArray408Strc::ReserveInline(unsigned int nCount, int bRound)
{
    nCount += m_count;
    if (nCount > m_alloc)
    {
        if (bRound)
        {
            unsigned int nChunk = m_chunk ? m_chunk : sub_0051D2F0_CalcChunkSize(nCount);
            nCount = RoundUpInline(nCount, nChunk);
        }
        sub_0051D5D0_ReallocData(nCount);
    }
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D2C0_InitBase()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    return this;
}

void __cdecl sub_0051D2D0_Nop()
{
}

void __cdecl sub_0051D2E0_Nop()
{
}

void D2StormArray408Strc::sub_0051D570_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem, -2, 0);
}

void D2StormArray408Strc::sub_0051D670_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem, -2, 0);
}

void __fastcall sub_005179B3_ConvertCelPixels(void* pDst, void* pSrc, int nRows, unsigned int nSrcSize, unsigned int nWidth, int nRows2); // 0x005179B3


// 0x00603860
void __stdcall CelCompressAddImage(unsigned int hCelList, void* pSrc, unsigned int nSrcSize, unsigned int dwPixelWidth, unsigned int dwPixelHeight, int nArg6, int nArg7, int nArg8)
{
    D2_ASSERT(dwPixelWidth && dwPixelHeight, 0x229);
    D2_ASSERT(nSrcSize >= dwPixelHeight, 0x22A);
    HLOCKEDCELLIST__* hLock;
    CELLIST* pList = gCelListTable.Lock((HCELLIST__*)hCelList, &hLock, 0);
    TCELENTRY* pEntry = pList->tList.NewNode(2, 0, 0);
    ++pList->nCount;
    pEntry->nSize = dwPixelWidth * dwPixelHeight;
    pEntry->nArg6 = nArg6;
    pEntry->nWidth = dwPixelWidth;
    pEntry->nHeight = dwPixelHeight;
    pEntry->nArg7 = nArg7;
    pEntry->nArg8 = nArg8;
    const int nRows = pList->dwFlags & 4 ? 3 * dwPixelHeight : dwPixelHeight;
    pEntry->pData = FOG_Alloc(nRows * dwPixelWidth, ".\\SRC\\CelCmp.cpp", 0x239, 0);
    sub_005179B3_ConvertCelPixels(pEntry->pData, pSrc, nRows, nSrcSize, dwPixelWidth, nRows);
    gCelListTable.SyncLeaveLock(hLock);
}

// 0x006039C0
void __stdcall CelCompressDestroy(unsigned int hCelList)
{
    HLOCKEDCELLIST__* hLock;
    CELLIST* pList = gCelListTable.Lock((HCELLIST__*)hCelList, &hLock, 0);
    TCELENTRY* pHead = pList->tList.Head();
    for (TCELENTRY* pEntry = pHead; (int)pEntry > 0; pEntry = pEntry->m_link.RawNext())
    {
        FOG_Free(pEntry->pData, ".\\SRC\\CelCmp.cpp", 588, 0);
    }
    pList->tList.Clear();
    gCelListTable.Delete(pList);
    gCelListTable.SyncLeaveLock(hLock);
}

// 0x00603A70
unsigned int __stdcall CelCompressCreateCelFile(unsigned int hCelList, D2CelFileStrc** ppCelFile)
{
    HLOCKEDCELLIST__* hLock;
    CELLIST* pList = gCelListTable.Lock((HCELLIST__*)hCelList, &hLock, 0);
    *ppCelFile = 0;

    if (!pList->nCount)
    {
        return 0x85200001;
    }

    if (pList->nCount % pList->nDirections)
    {
        return 0x85200002;
    }

    D2CelFileStrc* pCelFile = (D2CelFileStrc*)FOG_Alloc(pList->nCount * sizeof(void*) + 0x18, ".\\SRC\\CelCmp.cpp", 615, 0);
    pCelFile->dwVersion = 6;
    pCelFile->dwFlags = pList->dwFlags;
    pCelFile->nFormat = pList->nType;
    pCelFile->nDirections = pList->nDirections;
    pCelFile->nCelsPerDirection = pList->nCount / pList->nDirections;
    if (pList->dwFlags & 4)
    {
        RawBuildCelFile(pList, pCelFile);
        pCelFile->nTermination = pList->nData;
    }
    else
    {
        gapfnCelFileBuilders[pList->nType](pList, pCelFile);
    }

    gCelListTable.SyncLeaveLock(hLock);
    *ppCelFile = pCelFile;
    return 0;
}

void D2StormArray408Strc::sub_0051D6A0_Clear()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem, -2, 0);
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D720_Init()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    m_chunk = 0;
    return this;
}

void D2StormArray408Strc::sub_0051D730_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem, -2, 0);
}

D2Storm408ElemStrc* D2StormArray408Strc::sub_0051D7A0_New()
{
    ReserveInline(1, 1);
    return &m_data[m_count++];
}

#define D2CMP_BITCOUNT_BX(x) ((x) - (((x) >> 1) & 0x77777777) - (((x) >> 2) & 0x33333333) - (((x) >> 3) & 0x11111111))

#define D2CMP_BITCOUNT(x) (((D2CMP_BITCOUNT_BX(x) + (D2CMP_BITCOUNT_BX(x) >> 4)) & 0x0F0F0F0F) % 255)

// 0x00604940
unsigned int __stdcall CelCompressCreate(int nType, unsigned int nDirections, int* pData, int bHasData)
{
    D2_ASSERT(D2CMP_BITCOUNT(nDirections) == 1, 0x1FF);
    D2_ASSERT(nDirections <= 32, 0x200);
    D2_ASSERT(nType < 2, 0x201);
    HCELLIST__* hHandle;
    HLOCKEDCELLIST__* hLock;
    CELLIST* pList = gCelListTable.NewLock(&hHandle, &hLock);
    pList->tList.Clear();
    pList->nType = nType;
    pList->nDirections = nDirections;
    pList->nCount = 0;
    pList->dwFlags = 0;
    if (bHasData)
    {
        pList->dwFlags = 4;
        if (pData)
        {
            pList->nData = *pData;
        }
    }
    gCelListTable.SyncLeaveLock(hLock);
    return (unsigned int)hHandle;
}


// 0x0060D040
int __fastcall FindTileGetTiles(D2FindTileEntryStrc** ppTable, void** ppResults, unsigned int nMax, int nKey1, int nKey2, int nKey3)
{
    int bFound = 0;
    int nCount = 0;
    D2_ASSERT(ppTable, 0xCF);
    D2_ASSERT(ppResults, 0xD0);
    if (!nMax)
    {
        return 0;
    }

    D2FindTileEntryStrc* pEntry = ppTable[FindTileHash(nKey3, nKey2, nKey1)];
    while (pEntry && !bFound)
    {
        if (pEntry->nKey3 == nKey3 && pEntry->nKey2 == nKey2 && pEntry->nKey1 == nKey1)
            bFound = 1;
        else
            pEntry = pEntry->pNext;
    }

    if (bFound)
    {
        unsigned int i = 0;
        for (D2FindTileNodeStrc* pNode = pEntry->pTileList; pNode && i < nMax; pNode = pNode->pNext)
        {
            ppResults[i] = pNode->pTile;
            nCount += 1;
            i += 1;
        }
    }

    return nCount;
}

// 0x0060E0D0
int __cdecl sub_0060E0D0()
{
    return 4;
}

// 0x0060E0E0
D2StormListEStrc* D2StormListEArrayStrc::sub_0060E0E0_At(unsigned int nIndex)
{
    return &m_data[nIndex];
}

// 0x0060E100
int __cdecl sub_0060E100()
{
    return 4;
}

// 0x0060E110
D2StormListEStrc* D2StormListEArrayStrc::sub_0060E110_At(unsigned int nIndex)
{
    return &m_data[nIndex];
}

// 0x0060E170
D2StormLinkStrc* D2StormLinkStrc::sub_0060E170_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x0060E1B0
void __fastcall sub_0060E1B0(PairStrc_0060E1B0* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x0060E1C0
D2StormLinkStrc* D2StormLinkStrc::sub_0060E1C0_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x0060E1F0
unsigned int D2StormHashTableEStrc::sub_0060E1F0_SlotIndex(unsigned int nHashVal)
{
    return m_slotmask & nHashVal;
}

// 0x0060E210
unsigned int D2StormHashTableEStrc::sub_0060E210_SlotIndex(unsigned int nHashVal)
{
    return m_slotmask & nHashVal;
}

// 0x0060E290
void __fastcall sub_0060E290(PairStrc_0060E290* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x0060E2A0
unsigned int D2StormListEArrayStrc::sub_0060E2A0_CalcChunkSize(unsigned int nCount)
{
    if (nCount < 0x15)
    {
        unsigned int nResult = nCount;
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    m_chunk = 0x15;
    return 0x15;
}

// 0x0060E2E0
unsigned int __stdcall sub_0060E2E0_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// 0x0060E300
unsigned int D2StormListEArrayStrc::sub_0060E300_CalcChunkSize(unsigned int nCount)
{
    if (nCount < 0x15)
    {
        unsigned int nResult = nCount;
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    m_chunk = 0x15;
    return 0x15;
}

// 0x0060E340
unsigned int __stdcall sub_0060E340_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// 0x0060E370
void D2StormListEStrc::sub_0060E370_CopyLinkOffset(const D2StormListEStrc* pSource)
{
    m_linkoffset = pSource->m_linkoffset;
    InitializeTerminator();
}

// 0x0060E390
void D2StormListEStrc::sub_0060E390_CopyLinkOffset(const D2StormListEStrc* pSource)
{
    m_linkoffset = pSource->m_linkoffset;
    InitializeTerminator();
}

// 0x00611610
void __stdcall sub_00611610(int nUnused1)
{
}

// 0x00611640
void __stdcall sub_00611640(int nUnused1)
{
}

// 0x00611D10
int __cdecl DATATBLS_GetCharstatsTxtTable()
{
    return gpCharstatsTxt;
}

// 0x00611D20
int __cdecl DATATBLS_GetAnimData()
{
    return gpAnimData;
}

// 0x00641500
int __cdecl DATATBLS_GetShrinesTxtRecordCount()
{
    return gnShrinesTxtRecordCount;
}

// 0x00600C00
void __stdcall D2CMPPalShiftSetAct(int nMode)
{
    if (nMode >= 1 && nMode <= 5)
    {
        gnCmpGfxMode = nMode;
    }
}

// 0x00600C20
unsigned char* __stdcall D2CMPPalShiftGetTransform(int nSet, int nIndex)
{
    if (nSet < 9 && nIndex < 21 && nSet != 0 && (nSet <= 2 || nSet > 4))
    {
        return gaItemShiftMaps[nSet][nIndex];
    }

    return 0;
}

// 0x00600C70
int __stdcall CelNormalDirToFileDir(int nDirection, unsigned int nDirections)
{
    return gaDirectionIndex32[sub_00517ABB_FindLowestSetBit(nDirections)][nDirection];
}

// 0x00600EE0
void __stdcall CelFileHalve(D2CelFileStrc* hFile, int nUnused)
{
    D2_ASSERT(hFile, 0x29C);
}

// 0x00600F10
int __stdcall CelFileConvert24To8(D2CelFileStrc* pFile, D2CelFileStrc** ppTarget, int nArg1, int nArg2)
{
    D2_ASSERT(pFile->dwFlags & 4, 0x2AD);
    const int nCells = pFile->nDirections * pFile->nCelsPerDirection;
    D2CelFileStrc* pTarget = (D2CelFileStrc*)FOG_Alloc(0x18 + nCells * sizeof(D2CmpCellStrc*), ".\\SRC\\CelCmp.cpp", 0x2B1, 0);
    pTarget->dwVersion = 6;
    pTarget->dwFlags = pFile->dwFlags & ~7;
    pTarget->nDirections = pFile->nDirections;
    pTarget->nCelsPerDirection = pFile->nCelsPerDirection;
    pTarget->nFormat = 0;
    gpfCelFileConvert[pFile->nFormat](pFile, pTarget, nArg1, nArg2);
    *ppTarget = pTarget;
    return 1;
}

// 0x00600FB0
void __stdcall CelFileConvertOldToNew(unsigned* cell,unsigned** output,unsigned* outputSize)
{
 unsigned* cellCopy = cell;
 D2_ASSERT(cellCopy[1]&1,0x2cb);
 D2_ASSERT(cellCopy[0]==5,0x2cc);
 cellCopy[1]|=2;
 for(unsigned i=0;i<cellCopy[4]*(cellCopy[5]);++i) {
  unsigned* frame=(unsigned*)(cellCopy[13+i]+(unsigned)cellCopy);
  cellCopy[13+i]=(unsigned)frame;
  if(frame[7])frame[8]+=(unsigned)cellCopy;else frame[8]=0;
 }
 unsigned count=cellCopy[4]*cellCopy[5];
 unsigned header=24+4*count;
 unsigned size=header;
 for(unsigned i=0;i<count;++i) {
  unsigned* frame=(unsigned*)cellCopy[13+i];
  size+=frame[9]+frame[7]+35;
 }
 unsigned* result=(unsigned*)FOG_Alloc(size,gszCelCmp,0x2e3,0);
 result[0]=6;
 result[1]=((unsigned char)cellCopy[1]&4)|1;
 result[2]=0;result[3]=0;
 result[4]=cellCopy[4];result[5]=cellCopy[5];
 unsigned char* cursor=(unsigned char*)result+header;
 for(unsigned i=0;i<count;++i) {
  result[6+i]=(unsigned)(cursor-(unsigned char*)result);
  unsigned* out=(unsigned*)cursor;
  out[0]=((unsigned*)cellCopy[13+i])[1];
  out[1]=((unsigned*)cellCopy[13+i])[3];
  out[2]=((unsigned*)cellCopy[13+i])[4];
  out[3]=((unsigned*)cellCopy[13+i])[5];
  out[4]=((unsigned*)cellCopy[13+i])[6];
  out[5]=((unsigned*)cellCopy[13+i])[7];
  out[7]=((unsigned*)cellCopy[13+i])[9];
  memcpy(out+8,(unsigned*)cellCopy[13+i]+10,out[7]);
  cursor+=out[7]+35;
  if(((unsigned*)cellCopy[13+i])[8]) {
   memcpy(cursor,(unsigned*)cellCopy[13+i]+8,((unsigned*)cellCopy[13+i])[7]);
   out[6]=(unsigned)(cursor-(unsigned char*)result);
   cursor+=((unsigned*)cellCopy[13+i])[7];
  }else out[6]=0;
 }
 *output=result;*outputSize=size;
}

// 0x005FE1F0
const char* __stdcall D2CMPGetGfxFileExtension(int bAllowCompressed)
{
    if (bAllowCompressed && gbCmpCompressedDataMode)
    {
        return gszCmpCompressedExtension;
    }

    return gszCmpDefaultExtension;
}

// 0x005FE280
void __stdcall D2CMPSetNoCompress(int bAllowCompressed)
{
    SRegLoadValue("Diablo II", "CompressedData", 1, (unsigned long*)&gbCmpCompressedDataMode);
    if (!bAllowCompressed)
    {
        gbCmpCompressedDataMode = 0;
    }
}

// 0x005FFE30
void __stdcall D2CMPSpriteCacheDestroy(int bFree)
{
    if (bFree && gCmpTileCache.bActive)
    {
        D2CMPSpriteCacheFreeAll(&gCmpTileCache);
    }

    memset(&gCmpTileCache, 0, sizeof(gCmpTileCache));

    if (bFree)
    {
// build: symbol ?LRUCacheDestroy@* 0x006093E0
        LRUCacheDestroy(&gCmpTilePool);
    }

    memset(&gCmpTilePool, 0, sizeof(gCmpTilePool));
    CodecReleaseLock();
}

// 0x00600960
D2TileLibraryHeaderStrc* __stdcall D2CMPFindTileProject(D2TileLibraryEntryStrc* pTile)
{
    for (D2TileRecordStrc* pRecord = gpTileRecords; pRecord; pRecord = pRecord->pPrev)
    {
        D2TileLibraryHeaderStrc* pLibrary = pRecord->pLibrary;
        for (int i = 0; i < pLibrary->nTiles; ++i)
        {
            if (pTile == &pLibrary->pFirst[i])
            {
                return pLibrary;
            }
        }
    }

    return 0;
}

int __fastcall SKILLS_GetMinimum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

int __fastcall SKILLS_GetMaximum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}

int __stdcall SKILLS_Return1(int nArg)
{
    return 1;
}

int __stdcall sub_00646260_AlwaysOne(int nArg)
{
    return 1;
}

int __stdcall sub_00646270_AlwaysOne(int nArg)
{
    return 1;
}

int __stdcall sub_00648390_AlwaysZero(int nUnused1, int nUnused2)
{
    return 0;
}

int __fastcall MISSILE_GetMinimum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

int __fastcall MISSILE_GetMaximum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}

int __cdecl sub_0065CCB0()
{
    return 0;
}

// 0x0066A210
void __stdcall sub_0066A210(int nUnused1, int nUnused2)
{
}

// 0x0066A220
void __stdcall sub_0066A220(int nUnused1, int nUnused2)
{
}

// 0x0066A230
int __stdcall sub_0066A230(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x0066A240
int __stdcall sub_0066A240(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x0066A250
void __stdcall sub_0066A250(int nUnused1)
{
}

int __fastcall sub_00675810(D2DrlgLevelStrc* pLevel)
{
    return DRLGOUTSIEGE_GetBorderLookupId(pLevel);
}

D2WardenModuleHolderAStrc::~D2WardenModuleHolderAStrc()
{
}

WardenModule::WardenModule()
{
    pImage = 0;
    unk0x04 = 0;
    nImports = 0;
    unk0x0C = 0;
    f_10 = 0;
}

D2WardenModuleHolderBStrc::~D2WardenModuleHolderBStrc()
{
}

NWardenClient::Library::Library()
{
}

// 0x005FF630
void __fastcall D2CMPSpriteCacheResize(D2CmpCacheStrc* pCache, D2CmpCacheNodeStrc* pNode, int nDelta, int nArg)
{
    EnterCriticalSection(&pCache->tLock);
    const unsigned int nNewSize = nDelta + pNode->nSize;
    pCache->nTotalSize -= pNode->nSize;
    pNode->dwFlags |= 2;
    pNode->nSize = nNewSize;
    pCache->nTotalSize += nNewSize;
    unsigned int nTotalSize = pCache->nTotalSize;
    LeaveCriticalSection(&pCache->tLock);

    while (nTotalSize > pCache->nMaxSize)
    {
        D2CmpCacheNodeStrc* pEvicted = D2CMPSpriteCacheEvict(pCache, 0, nArg);
        if (!pEvicted)
        {
            break;
        }

        D2_ASSERT(pEvicted != pNode, 0xA47);
        EnterCriticalSection(&pCache->tLock);
        nTotalSize = pCache->nTotalSize;
        LeaveCriticalSection(&pCache->tLock);
    }

    EnterCriticalSection(&pCache->tLock);
    pNode->dwFlags &= ~2;
    LeaveCriticalSection(&pCache->tLock);
}

// 0x005FE120
void __stdcall D2CMPTileCacheInit(void* pMemPool, int nArg)
{
    gnCmpPoolArg = nArg;
    memset(&gCmpPool, 0, sizeof(gCmpPool));
// build: symbol ?LRUCacheInit@* 0x00609020
    LRUCacheInit(&gCmpPool, pMemPool, nArg, D2CMPTileCacheReleaseTile, 0x1000);
    gbCmpPoolInitialized = 1;
}

// 0x005FDE10
void __stdcall D2CMPTileCacheDestroy(int bFree)
{
    if (gbCmpPoolInitialized)
    {
        if (bFree)
        {
            LRUCacheDestroy(&gCmpPool);
        }

        memset(&gCmpPool, 0, sizeof(gCmpPool));
        gnCmpPoolArg = 0;
    }

    D2CMPDestroyTileHeaders();
}

// 0x005FDF50
void __stdcall D2CMPTileCacheFreeTile(D2CmpCacheBlockOwnerStrc* pOwner)
{
// build: symbol ?LRUCacheRelease@* 0x006092D0
    LRUCacheRelease(&gCmpPool, pOwner->pBlock);
    pOwner->nBlockUsed = 0;
    pOwner->pBlock = 0;
}

// 0x005FDEA0
int __stdcall D2CMPTileValidate(D2TileLibraryEntryStrc* pEntry, int nUnused1, int nUnused2)
{
    if (pEntry->pNode)
    {
        LRUCacheTouch(&gCmpPool, pEntry->pNode);
        return 1;
    }

    if (!pEntry->nBlocks)
    {
        return 0;
    }

    pEntry->pNode = LRUCacheAlloc(&gCmpPool, pEntry->nSize, pEntry);
    pEntry->pBlocks = (D2GlideTileStrc*)pEntry->pNode->pData;
    memset(pEntry->pBlocks, 0, pEntry->nSize);

    void* hFile;
    if (!ARCHIVE_OpenFile(0, pEntry->szFilePath, &hFile, 0))
    {
        return 0;
    }

    ARCHIVE_SetFilePointer(0, hFile, pEntry->nFileOffset, 0, 0);
    ARCHIVE_ReadFileToBuffer(0, hFile, pEntry->pBlocks, pEntry->nSize);
    ARCHIVE_CloseFile(0, hFile);
    TileNormalizeSubTiles(pEntry);
    return 1;
}

// 0x005FDF80
int __fastcall D2CMPGetTileHeadersSize(const char* szFilePath)
{
    void* hFile;
    if (!ARCHIVE_OpenFile(0, szFilePath, &hFile, 0))
    {
        return 0;
    }

    D2TileLibraryHeaderStrc tHeader;
    ARCHIVE_ReadFileToBuffer(0, hFile, &tHeader, sizeof(tHeader));
    ARCHIVE_CloseFile(0, hFile);
    return tHeader.nTiles * sizeof(D2TileLibraryEntryStrc) + sizeof(tHeader);
}

// 0x005FE080
void __fastcall D2CMPTileCacheFreeProject(D2TileLibraryStrc* pLibrary)
{
    for (int i = 0; i < pLibrary->nTiles; ++i)
    {
        D2TileLibraryEntryStrc* pEntry = &pLibrary->pTiles[i];
        if (pEntry->pNode)
        {
            LRUCacheRelease(&gCmpPool, pEntry->pNode);
            pEntry->pBlocks = 0;
            pEntry->pNode = 0;
        }
    }
}

// 0x006030E0
// The cel list table's lookup. The original reloads the slot list on every step of the loop; no plain form of
// the template's InternalFind has given that yet, so this specialisation keeps the barrier the file had before.
template<>
CELLIST* TSHashTable<CELLIST, HASHKEY_NONE>::InternalFind(unsigned int hashval, const HASHKEY_NONE& key)
{
    for (CELLIST* ptr = m_slotlistarray[hashval & m_slotmask].Head(); _ReadWriteBarrier(), (int)ptr > 0; ptr = m_slotlistarray[hashval & m_slotmask].RawNext(ptr))
    {
        if (ptr->m_hashval == hashval)
            return ptr;
    }
    return 0;
}

extern "C" void __cdecl CelFileConvertRle24To8(); // 0x00606B50
extern "C" void __cdecl sub_00608540(); // 0x00608540
extern "C" void __cdecl CelCompressEncodeRleCels(); // 0x00608EE0

extern "C" const CelFileBuildFn gData_006E3680[2] = { (CelFileBuildFn)&CelCompressEncodeRleCels, 0 }; // 0x006E3680
#pragma comment(linker, "/alternatename:?gapfnCelFileBuilders@@3PAP6IXPAUCELLIST@@PAUD2CelFileStrc@@@ZA=_gData_006E3680")

extern "C" const CELDRAWFN gData_006E3688[2] = { (CELDRAWFN)&sub_00608540, 0 }; // 0x006E3688
#pragma comment(linker, "/alternatename:?gpfnCelDraw@@3PAP6IXPAUD2CelStrc@@PAEHHHHHHHHH@ZA=_gData_006E3688")

extern "C" const CELFILECONVERTFN gData_006E3690[2] = { (CELFILECONVERTFN)&CelFileConvertRle24To8, 0 }; // 0x006E3690
#pragma comment(linker, "/alternatename:?gpfCelFileConvert@@3PAP6IXPAUD2CmpCelFileStrc@@0HH@ZA=_gData_006E3690")

extern "C" const int gData_006E3A20[23][32] = { // 0x006E3A20
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 4, 5, 6, 7, 0, 2, 1, 3 },
    { 4, 5, 6, 7, 0, 2, 1, 3, 8, 9, 10, 11, 12, 13, 14, 15 },
    { 4, 5, 6, 7, 0, 2, 1, 3, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
    { 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 6, 6, 6, 6, 6, 6, 6, 6, 3, 3, 3, 3, 3, 3, 3, 3, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0 },
    { 0, 0, 8, 8, 8, 8, 4, 4, 4, 4, 9, 9, 9, 9, 2, 2, 2, 2, 10, 10, 10, 10, 5, 5, 5, 5, 11, 11, 11, 11, 1, 1 },
    { 1, 1, 12, 12, 12, 12, 6, 6, 6, 6, 13, 13, 13, 13, 3, 3, 3, 3, 14, 14, 14, 14, 7, 7, 7, 7, 15, 15, 15, 15, 0, 0 },
    { 0, 16, 16, 8, 8, 17, 17, 4, 4, 18, 18, 9, 9, 19, 19, 2, 2, 20, 20, 10, 10, 21, 21, 5, 5, 22, 22, 11, 11, 23, 23, 1 },
    { 1, 24, 24, 12, 12, 25, 25, 6, 6, 26, 26, 13, 13, 27, 27, 3, 3, 28, 28, 14, 14, 29, 29, 7, 7, 30, 30, 15, 15, 31, 31, 0 },
    { 0, 32, 16, 33, 8, 34, 17, 35, 4, 36, 18, 37, 9, 38, 19, 39, 2, 40, 20, 41, 10, 42, 21, 43, 5, 44, 22, 45, 11, 46, 23, 47 },
    { 1, 48, 24, 49, 12, 50, 25, 51, 6, 52, 26, 53, 13, 54, 27, 55, 3, 56, 28, 57, 14, 58, 29, 59, 7, 60, 30, 61, 15, 62, 31, 63 }
};
#pragma comment(linker, "/alternatename:?gaDirectionIndex32@@3PAY0CA@HA=_gData_006E3A20")

extern "C" const int gData_006E45A0[8][64] = { // 0x006E45A0
    { 0 },
    { 0 },
    { 0 },
    {
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3
    },
    {
        4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5,
        5, 5, 5, 5, 1, 1, 1, 1, 1, 1, 1, 1, 6, 6, 6, 6,
        6, 6, 6, 6, 2, 2, 2, 2, 2, 2, 2, 2, 7, 7, 7, 7,
        7, 7, 7, 7, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4
    },
    {
        4, 4, 8, 8, 8, 8, 0, 0, 0, 0, 9, 9, 9, 9, 5, 5,
        5, 5, 10, 10, 10, 10, 1, 1, 1, 1, 11, 11, 11, 11, 6, 6,
        6, 6, 12, 12, 12, 12, 2, 2, 2, 2, 13, 13, 13, 13, 7, 7,
        7, 7, 14, 14, 14, 14, 3, 3, 3, 3, 15, 15, 15, 15, 4, 4
    },
    {
        4, 16, 16, 8, 8, 17, 17, 0, 0, 18, 18, 9, 9, 19, 19, 5,
        5, 20, 20, 10, 10, 21, 21, 1, 1, 22, 22, 11, 11, 23, 23, 6,
        6, 24, 24, 12, 12, 25, 25, 2, 2, 26, 26, 13, 13, 27, 27, 7,
        7, 28, 28, 14, 14, 29, 29, 3, 3, 30, 30, 15, 15, 31, 31, 4
    },
    {
        4, 32, 16, 33, 8, 34, 17, 35, 0, 36, 18, 37, 9, 38, 19, 39,
        5, 40, 20, 41, 10, 42, 21, 43, 1, 44, 22, 45, 11, 46, 23, 47,
        6, 48, 24, 49, 12, 50, 25, 51, 2, 52, 26, 53, 13, 54, 27, 55,
        7, 56, 28, 57, 14, 58, 29, 59, 3, 60, 30, 61, 15, 62, 31, 63
    }
};
#pragma comment(linker, "/alternatename:?gaDirectionIndex64@@3PAY0EA@HA=_gData_006E45A0")

int gbCmpCompressedDataMode = 1; // 0x00741EFC

extern const char* gszCmpCompressedExtension = ".dcc"; // 0x00741F00

extern const char* gszCmpDefaultExtension = ".dc6"; // 0x00741F04

int gnCmpGfxMode = 1; // 0x00741F08
