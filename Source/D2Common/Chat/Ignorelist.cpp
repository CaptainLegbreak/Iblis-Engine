#include "D2Common.h"
#include "D2CmpTypes.h"
#include "D2CmpTiles.h"

#include "D2Drlg.h"

#include "D2DrlgRooms.h"

#include "D2Win32Base.h"

#include "D2StormLink.h"

#include "D2CmpCache.h"
#include "D2ProfileCounter.h"
#include "D2ExperienceTxt.h"

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags) throw(); // 0x00412650

__declspec(nothrow) char* __stdcall SStrDup(const char* szString);                                                             // 0x00414310

extern "C" int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0

struct D2StormHashKeyStrIAStrc
{
    char* m_str;

    D2StormHashKeyStrIAStrc(const char* szString);
    ~D2StormHashKeyStrIAStrc();
    D2StormHashKeyStrIAStrc& operator=(const D2StormHashKeyStrIAStrc& source);
    char* IGNORELIST_GetHashKeyString();
};

struct D2StormHashKeyStrIBStrc
{
    char* m_str;

    D2StormHashKeyStrIBStrc(const char* szString);
    D2StormHashKeyStrIBStrc& operator=(const D2StormHashKeyStrIBStrc& source);
};

struct D2CommonStormSlotListBStrc;

struct D2CommonStormSlotListAStrc;

struct D2DrlgActStrc;

struct D2ChatStormLinkAStrc;

struct D2ChatStormLinkBStrc;

struct D2ChatStormBaseArrayAStrc;

struct D2ChatStormBaseArrayBStrc;

struct D2ChatStormCtorLinkStrc;

struct D2ChatStormListCStrc;

struct D2ChatStormListDStrc;

struct D2ChatStormListEStrc;

struct D2CommonStormSlotLinkStrc;

struct D2CommonMappingEntryNodeBaseStrc;

struct D2CommonMappingEntryNodeStrc;

struct D2CommonStringEntryNodeStrc;

struct D2StormSlotList0060EDB0Strc;

struct D2CommonStormSlotArrayAStrc;

struct D2CommonStormSlotArrayAViewStrc;

struct D2Storm408ElemStrc;

struct D2StormArray408Strc;

struct D2CommonStormSlotArrayBStrc;

struct D2CommonStormSlotGrowArrayBStrc;

struct D2CommonStormZero6105F0Strc;

struct D2CommonRecord610610Strc;

struct D2ProfileCounterStrc;

struct D2CompCodeTxt;

struct D2ExperienceTxt;

struct D2ExperienceDataTbl;

struct Link;

struct Key;

struct Node;

struct List;

struct D2Object00610D30Strc;

struct D2CommonStormSlotLinkStrc
{
    D2CommonStormSlotLinkStrc* m_prevlink;
    char* m_next;

    D2CommonStormSlotLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
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
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
    inline char* NextChecked()
    {
        char* const pResult = (int)m_next <= 0 ? 0 : m_next;
        return pResult;
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

struct D2StormHashKeyStrIStrc
{
    char* m_str;

    D2StormHashKeyStrIStrc()
    {
        m_str = 0;
    }
    D2StormHashKeyStrIStrc(const char* szString)
    {
        m_str = SStrDup(szString);
    }
    // 0x0060DD90
    ~D2StormHashKeyStrIStrc()
    {
        if (m_str)
            SMemFree(m_str, "d:\\diablo2\\Diablo2\\3rdparty\\storm\\h\\stpl.h", 0x5E4, 0);
    }
    D2StormHashKeyStrIStrc& operator=(const D2StormHashKeyStrIStrc& source)
    {
        if (m_str)
            SMemFree(m_str, "d:\\diablo2\\Diablo2\\3rdparty\\storm\\h\\stpl.h", 0x5E9, 0);
        m_str = SStrDup(source.m_str);
        return *this;
    }
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

struct D2ChatStormListCStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListCStrc();
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

struct D2ChatStormListFStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListFStrc();
};

struct D2CommonStormSlotListAStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    D2CommonStormSlotListAStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        InitializeTerminator();
    }
    D2CommonStormSlotListAStrc(const D2CommonStormSlotListAStrc& source)
    {
        m_linkoffset = source.m_linkoffset;
        InitializeTerminator();
    }
    ~D2CommonStormSlotListAStrc();
    char* Head()
    {
        return m_terminator.Next();
    }
    char* MaskHead()
    {
        return m_terminator.MaskNext();
    }
    char* RawNext(char* pNode)
    {
        return Link(pNode)->m_next;
    }
    D2CommonStormSlotLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2CommonStormSlotLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Next(char* pNode)
    {
        return Link(pNode)->Next();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void ChangeLinkOffset(int nLinkOffset)
    {
        if (nLinkOffset != m_linkoffset)
        {
            UnlinkAll();
            m_linkoffset = nLinkOffset;
            InitializeTerminator();
        }
    }
void UnlinkAll();
    void IGNORELIST_InitStringListTerminator();
    char* IGNORELIST_GetStringListHead();
    void IGNORELIST_ResetStringList();
    D2CommonStormSlotLinkStrc* IGNORELIST_GetStringListLink(char* pNode);
    void IGNORELIST_InitStringListLinkOffset(int nLinkOffset);
    void IGNORELIST_LinkStringListNode(char* pNode, int nLinkType, char* pExistingNode);
    char* IGNORELIST_GetStringListRawNext(char* pNode);
    char* IGNORELIST_GetStringListNext(char* pNode);
    void IGNORELIST_ChangeStringListLinkOffset(int nLinkOffset);
    void IGNORELIST_UnlinkStringListNode(char* pNode);
    char* IGNORELIST_DeleteStringListNode(D2CommonStringEntryNodeStrc* pNode);
    D2CommonStringEntryNodeStrc* IGNORELIST_NewStringListNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
    void LinkNode(char* pNode, int nLinkType, char* pExistingNode)
    {
        D2CommonStormSlotLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2CommonStormSlotLinkStrc* pExistingLink = Link(pExistingNode);
        switch (nLinkType)
        {
        case 1:
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = pNode;
            break;
        default:
            D2CommonStormSlotLinkStrc* pPrevLink = pExistingLink->m_prevlink;
            pLink->m_prevlink = pPrevLink;
            pLink->m_next = pPrevLink->m_next;
            pPrevLink->m_next = pNode;
            pExistingLink->m_prevlink = pLink;
            break;
        }
    }
    void sub_006C4290(char* pNode)
    {
        Link(pNode)->Unlink();
    }
    static void operator delete(void* pMemory);
};

struct D2CommonStormSlotListBStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    D2CommonStormSlotListBStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        InitializeTerminator();
    }
    D2CommonStormSlotListBStrc(const D2CommonStormSlotListBStrc& source)
    {
        m_linkoffset = source.m_linkoffset;
        InitializeTerminator();
    }
    ~D2CommonStormSlotListBStrc();
    char* MaskHead()
    {
        return m_terminator.MaskNext();
    }
    char* RawNext(char* pNode)
    {
        return Link(pNode)->m_next;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
    D2CommonStormSlotLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2CommonStormSlotLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Next(char* pNode)
    {
        return Link(pNode)->Next();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void ChangeLinkOffset(int nLinkOffset)
    {
        if (nLinkOffset != m_linkoffset)
        {
            UnlinkAll();
            m_linkoffset = nLinkOffset;
            InitializeTerminator();
        }
    }
void UnlinkAll();
    void IGNORELIST_InitMappingListTerminator();
    char* IGNORELIST_GetMappingListHead();
    void IGNORELIST_ResetMappingList();
    void IGNORELIST_InitMappingListLinkOffset(int nLinkOffset);
    D2CommonStormSlotLinkStrc* IGNORELIST_GetMappingListLink(char* pNode);
    char* IGNORELIST_GetMappingListNext(char* pNode);
    void IGNORELIST_LinkMappingListNode(char* pNode, int nLinkType, char* pExistingNode);
    char* IGNORELIST_GetMappingListRawNext(char* pNode);
    void IGNORELIST_ChangeMappingListLinkOffset(int nLinkOffset);
    void IGNORELIST_UnlinkMappingListNode(char* pNode);
    char* IGNORELIST_DeleteMappingListNode(D2CommonMappingEntryNodeStrc* pNode);
    void LinkNode(char* pNode, int nLinkType, char* pExistingNode)
    {
        D2CommonStormSlotLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2CommonStormSlotLinkStrc* pExistingLink = Link(pExistingNode);
        switch (nLinkType)
        {
        case 1:
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = pNode;
            break;
        default:
            D2CommonStormSlotLinkStrc* pPrevLink = pExistingLink->m_prevlink;
            pLink->m_prevlink = pPrevLink;
            pLink->m_next = pPrevLink->m_next;
            pPrevLink->m_next = pNode;
            pExistingLink->m_prevlink = pLink;
            break;
        }
    }
    void sub_006C4290(char* pNode)
    {
        Link(pNode)->Unlink();
    }
    static void operator delete(void* pMemory);
};

struct D2CommonMappingEntryNodeBaseStrc
{
    unsigned int m_hashval;
    D2CommonStormSlotLinkStrc m_linktoslot;
    D2CommonStormSlotLinkStrc m_linktofull;
    D2StormHashKeyStrIStrc m_key;

    ~D2CommonMappingEntryNodeBaseStrc();                                                                    // 0x0060EA10
};

struct D2CommonMappingEntryNodeStrc : D2CommonMappingEntryNodeBaseStrc
{
    char* pMapped;

    D2CommonMappingEntryNodeStrc()
    {
        pMapped = 0;
    }
    ~D2CommonMappingEntryNodeStrc();
    static void operator delete(void* pMemory);
};

struct D2CommonStringEntryNodeStrc
{
    unsigned int m_hashval;
    D2CommonStormSlotLinkStrc m_linktoslot;
    D2CommonStormSlotLinkStrc m_linktofull;
    D2StormHashKeyStrIStrc m_key;

    ~D2CommonStringEntryNodeStrc();                                                                         // 0x0060EAE0
    void IGNORELIST_DestroyStringEntryNode();
    char* IGNORELIST_GetStringEntryKey();
    static void operator delete(void* pMemory);
};

struct D2StormSlotList0060EDB0Strc : D2CommonStormSlotListAStrc
{
    ~D2StormSlotList0060EDB0Strc();
};

struct Link { Link* previous; char* next; Link() { previous=0; next=0; } };

struct D2CommonStormSlotArrayAStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2CommonStormSlotListAStrc* m_data;
    unsigned int m_chunk;

    D2CommonStormSlotArrayAStrc()
    {
        m_alloc = 0;
        m_count = 0;
        m_data = 0;
        m_chunk = 0;
    }
    ~D2CommonStormSlotArrayAStrc();                                                                         // 0x0060F610
    void IGNORELIST_ClearStringSlotArray();
    D2CommonStormSlotListAStrc& operator[](unsigned int nIndex)
    {
        return m_data[nIndex];
    }
unsigned int sub_0060E2A0_CalcChunkSize(unsigned int nCount);
    void IGNORELIST_ReallocStringSlotArray(unsigned int nAlloc);                                                     // 0x0060F390
    void IGNORELIST_ReserveStringSlotArray(unsigned int nCount, int bRound);
    void IGNORELIST_SetStringSlotArrayCount(unsigned int nCount);
    void IGNORELIST_ForwardSetStringSlotArrayCount(unsigned int nCount);
    static void operator delete(void* pMemory);
};

struct D2CommonStormSlotArrayAViewStrc : D2CommonStormSlotArrayAStrc
{
    ~D2CommonStormSlotArrayAViewStrc();
};

extern "C" const char gszTypeNewsTableItem_0072FF8C[];

struct D2Storm408ElemStrc
{
    char unk0x00[0x408];
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
    D2StormArray408Strc* sub_006100A0_Init();
    void sub_0051D6A0_Clear();
    D2StormArray408Strc* sub_0051D720_Init();
    void sub_0051D730_FreeData();
    D2Storm408ElemStrc* sub_0051D7A0_New();
    void ReserveInline(unsigned int nCount, int bRound);
};

struct D2CommonStormSlotArrayBStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2CommonStormSlotListBStrc* m_data;
    unsigned int m_chunk;

    D2CommonStormSlotArrayBStrc()
    {
        m_alloc = 0;
        m_count = 0;
        m_data = 0;
        m_chunk = 0;
    }
    ~D2CommonStormSlotArrayBStrc();                                                                         // 0x0060F950
// build: symbol ??1D2CommonStormSlotArrayBStrc@@QAE@XZ 0x0060F950
// 0x006107B0
    void Clear()
    {
        this->~D2CommonStormSlotArrayBStrc();
        m_alloc = 0;
        m_count = 0;
        m_data = 0;
    }
    D2CommonStormSlotListBStrc& operator[](unsigned int nIndex)
    {
        return m_data[nIndex];
    }
unsigned int sub_0060E300_CalcChunkSize(unsigned int nCount);
    void IGNORELIST_ReallocMappingSlotArray(unsigned int nAlloc);                                                     // 0x0060F720
    void IGNORELIST_ReserveMappingSlotArray(unsigned int nCount, int bRound);
    void IGNORELIST_SetMappingSlotArrayCount(unsigned int nCount);
    void IGNORELIST_ForwardSetMappingSlotArrayCount(unsigned int nCount);
    static void operator delete(void* pMemory);
};

struct D2CommonStormSlotGrowArrayBStrc : D2CommonStormSlotArrayBStrc
{
    ~D2CommonStormSlotGrowArrayBStrc();
};

struct D2CommonStormZero6105F0Strc
{
    int unk0x00;
    int n0x04;
    int n0x08;
    int n0x0C;
    int n0x10;
    int n0x14;
    D2CommonStormZero6105F0Strc();
};

struct D2CommonStormZeroFE50Strc
{
    int unk0x00;
    int n0x04;
    int n0x08;
    int n0x0C;
    int n0x10;
    int n0x14;
    D2CommonStormZeroFE50Strc();
};

struct D2CommonStormZeroFE70Strc
{
    int unk0x00;
    int n0x04;
    int n0x08;
    int n0x0C;
    int n0x10;
    int n0x14;
    D2CommonStormZeroFE70Strc();
};

// build: symbol ?gnTileTypeTable@* 0x006EEF88
extern const int gnTileTypeTable[];

void __stdcall DUNGEON_GameTileToClientCoords(int* pX, int* pY);

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(__int64* pnFrequency); // 0x006CC254

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(__int64* pnCount); // 0x006CC25C

struct D2CommonRecord610610Strc
{
    int unk0x00;
    int f_4;
    int f_8;
    int nFieldC;
    int nField10;
    int nField14;
    int nField18;

    D2CommonRecord610610Strc(int nValue);
};


struct D2CompCodeTxt
{
    unsigned int dwCode;
};



typedef void(__stdcall* PROFHOOKFN)(int nA, char* pBuffer, int nC);

extern D2ProfileCounterStrc gaProfEntries[23]; // 0x00743800

extern D2CompCodeTxt* gpCompCodeTxt; // 0x0096BCAC

extern int gbCompileTxt; // 0x0096C8B4

void __cdecl LOG_11100(int nA, int nB, int nC, int nFlags, const char* szFile, int nLine, const char* szFormat, ...); // 0x006248E0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

int __fastcall DRLGROOM_GetWarpDestinationLevel(D2DrlgRoomStrc* pDrlgRoom, int nSourceLevel); // 0x0066BAC0

extern "C" void* __stdcall sub_00413020(unsigned,const char*,int,unsigned); // 0x00413020

extern "C" const char mappingName[]; // 0x0074362C

struct Key { char* text; Key() { text=0; } };

struct Node { unsigned hash; Link slot,full; Key key; void* mapped; Node() { mapped=0; } };

struct List {
    void IGNORELIST_LinkMappingListNode(char*,int,char*); // 0x0060E890
    Node* IGNORELIST_NewMappingListNode(int,unsigned,unsigned);
};

enum { ALLOC_FLAG = 8 };

struct D2Object00610D30Strc
{
    ~D2Object00610D30Strc(); // 0x00610AA0
    void* sub_00610D30(unsigned int nFlags);
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

struct D2CommonStormListCStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    D2CommonStormListCStrc(const D2CommonStormListCStrc& source);
};

struct D2CommonStormListDStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    D2CommonStormListDStrc(const D2CommonStormListDStrc& source);
};

struct D2CommonStormListEStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    D2CommonStormListEStrc(const D2CommonStormListEStrc& source);
};

struct D2CommonStormListFStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    D2CommonStormListFStrc(const D2CommonStormListFStrc& source);
};

struct StringEntryNode;

struct MappingEntryNode;

class HASHKEY_STRI;

template <class T, class KEY> class TSHashTable;

typedef TSHashTable<StringEntryNode, HASHKEY_STRI> D2CommonStormHashTableAStrc;

typedef TSHashTable<MappingEntryNode, HASHKEY_STRI> D2CommonStormHashTableBStrc;

// build: symbol ??0?$TSHashTable@UStringEntryNode@@VHASHKEY_STRI@@@@QAE@XZ 0x006104A0
// build: symbol ??0?$TSHashTable@UMappingEntryNode@@VHASHKEY_STRI@@@@QAE@XZ 0x00610B30
// build: symbol ??1?$TSHashTable@UStringEntryNode@@VHASHKEY_STRI@@@@UAE@XZ 0x0060FD90
// build: symbol ??1?$TSHashTable@UMappingEntryNode@@VHASHKEY_STRI@@@@UAE@XZ 0x00610550

struct D2CommonStormSlotListCStrc : D2CommonStormSlotListBStrc
{
    ~D2CommonStormSlotListCStrc();
};

template <> class TSHashTable<StringEntryNode, HASHKEY_STRI>
{
public:
    explicit TSHashTable(int nEmitTag)
    {
    }
    virtual void IGNORELIST_InternalDeleteStringTableNode(D2CommonStringEntryNodeStrc* pNode);                             // 0x0060FFA0
    virtual D2CommonStringEntryNodeStrc* IGNORELIST_AllocStringTableNodeInList(D2CommonStormSlotListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x0060FEF0
    virtual ~TSHashTable();                                                                                 // 0x0060FD90
    virtual void IGNORELIST_DestroyStringTable();                                                                  // 0x00610020
    static void operator delete(void* pMemory);

    D2StormSlotList0060EDB0Strc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayAViewStrc m_slotlistarray;
    unsigned int m_slotmask;

    TSHashTable();
    void IGNORELIST_UnlinkStringTableNode(D2CommonStringEntryNodeStrc* pNode);
    void IGNORELIST_DeleteStringTableNode(D2CommonStringEntryNodeStrc* pNode);
    char* IGNORELIST_GetStringTableNext(char* pNode);
    char* IGNORELIST_DeleteStringTableNodeAndGetNext(D2CommonStringEntryNodeStrc* pNode);
    void IGNORELIST_InternalClearStringTable(int bWarn);                                                             // 0x0060EB70
    D2CommonStringEntryNodeStrc* IGNORELIST_InternalFindStringTableNode(unsigned int nHashVal, const D2StormHashKeyStrIStrc& key);
    D2CommonStringEntryNodeStrc* IGNORELIST_FindStringTableNode(const char* szKey);                                       // 0x0060F8B0
    D2CommonStringEntryNodeStrc* IGNORELIST_NewStringTableNode(const char* szKey, unsigned int nExtraBytes, unsigned int nFlags); // 0x00610D60
    void IGNORELIST_ClearStringTable();
    char* IGNORELIST_GetStringTableHead();
    int IGNORELIST_MonitorStringTableFullness(unsigned int nSlot);                                                                   // 0x00610840
    void InternalLinkNode(D2CommonStringEntryNodeStrc* pNode, unsigned int nHashVal)
    {
        m_slotlistarray.m_data[nHashVal & m_slotmask].LinkNode((char*)pNode, 2, 0);
    }
    void IGNORELIST_GrowStringTableSlots();
    D2CommonStringEntryNodeStrc* IGNORELIST_InternalNewStringTableNode(unsigned int nHashVal, const D2StormHashKeyStrIStrc& key, unsigned int nExtraBytes, unsigned int nFlags);
};

template <> class TSHashTable<MappingEntryNode, HASHKEY_STRI>
{
public:
    explicit TSHashTable(int nEmitTag)
    {
    }
    virtual void IGNORELIST_InternalDeleteMappingTableNode(D2CommonMappingEntryNodeStrc* pNode);                             // 0x00610690
    virtual D2CommonMappingEntryNodeStrc* IGNORELIST_AllocMappingTableNodeInList(D2CommonStormSlotListBStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x006106D0
    virtual ~TSHashTable();                                                                                 // 0x00610550
    virtual void IGNORELIST_DestroyMappingTable();                                                                  // 0x006107D0
    static void operator delete(void* pMemory);

    D2CommonStormSlotListCStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotGrowArrayBStrc m_slotlistarray;
    unsigned int m_slotmask;

    TSHashTable();
    char* IGNORELIST_GetMappingTableNext(char* pNode);
    void IGNORELIST_InternalClearMappingTable(int bWarn);                                                             // 0x0060EE60
    void IGNORELIST_ClearMappingTable();
    D2CommonMappingEntryNodeStrc* IGNORELIST_InternalFindMappingTableNode(unsigned int nHashVal, const D2StormHashKeyStrIStrc& key); // 0x0060F1D0
    D2CommonMappingEntryNodeStrc* IGNORELIST_FindMappingTableNode(const char* szKey);                                      // 0x0060F510
    void InternalLinkNode(D2CommonMappingEntryNodeStrc* pNode, unsigned int nHashVal)
    {
        m_slotlistarray.m_data[nHashVal & m_slotmask].LinkNode((char*)pNode, 2, 0);
    }
    void IGNORELIST_GrowMappingTableSlots();
    D2CommonMappingEntryNodeStrc* IGNORELIST_NewMappingTableNode(const char* szKey, unsigned int nExtraBytes, unsigned int nFlags); // 0x00611170
    int IGNORELIST_MonitorMappingTableFullness(unsigned int nSlot);                                                                   // 0x00610CA0
    D2CommonMappingEntryNodeStrc* IGNORELIST_InternalNewMappingTableNode(unsigned int nHashVal, const D2StormHashKeyStrIStrc& key, unsigned int nExtraBytes, unsigned int nFlags);
};

class ChatIgnoreList;

typedef ChatIgnoreList D2CommonChatIgnoreListStrc;

class IgnoreList;

typedef IgnoreList D2CommonIgnoreListStrc;

struct _iobuf;

class ChatIgnoreList
{
public:
    ChatIgnoreList();
    virtual int IGNORELIST_AddName(const char* szName) = 0;
    virtual int IGNORELIST_RemoveName(const char* szName) = 0;
    virtual int IGNORELIST_IsListed(const char* szName) = 0;
    virtual int IGNORELIST_AddAlias(const char* szName) = 0;
    virtual int IGNORELIST_RemoveAlias(const char* szName) = 0;
    virtual int IGNORELIST_IsTextFiltered(const char* szName) = 0;
    virtual int IGNORELIST_StoreAccountAlias(char* szRaw, int nRawLen) = 0;
    virtual int IGNORELIST_TranslateAlias(const char* szName, char* szOut, int nSize) = 0;
    virtual int IGNORELIST_IsEnabled() = 0;
    virtual void IGNORELIST_SetEnabled(int bEnabled) = 0;
    virtual void IGNORELIST_ClearAccountAliases() = 0;
    virtual ~ChatIgnoreList();
    static void operator delete(void* pMemory);
};

class IgnoreList : public D2CommonChatIgnoreListStrc
{
public:
    D2CommonStormHashTableAStrc m_table;
    D2CommonStormHashTableAStrc m_table2;
    D2CommonStormHashTableBStrc m_table3;
    _iobuf* m_pFile;
    char szFileName[0x104];
    int m_bEnabled;

    IgnoreList();                                                                                           // 0x00611200
    virtual int IGNORELIST_AddName(const char* szName);                                                       // 0x00610EB0
    virtual int IGNORELIST_RemoveName(const char* szName);                                                    // 0x0060FB20
    virtual int IGNORELIST_IsListed(const char* szName);                                                  // 0x00610380
    virtual int IGNORELIST_AddAlias(const char* szName);                                                  // 0x00610F90
    virtual int IGNORELIST_RemoveAlias(const char* szName);                                               // 0x0060FBE0
    virtual int IGNORELIST_IsTextFiltered(const char* szName);                                                 // 0x0060FC40
    virtual int IGNORELIST_StoreAccountAlias(char* szRaw, int nRawLen);                                   // 0x00611320
    virtual int IGNORELIST_TranslateAlias(const char* szName, char* szOut, int nSize);                         // 0x0060F870
    virtual int IGNORELIST_IsEnabled();                                                                   // 0x0060DDF0
    virtual void IGNORELIST_SetEnabled(int bEnabled);                                                     // 0x0060DE00
    virtual void IGNORELIST_ClearAccountAliases();                                                                 // 0x0060F500
    virtual ~IgnoreList();                                                                                  // 0x00610AA0
    void IGNORELIST_CloseFile();
    void IGNORELIST_CopyNameBeforeStar(const char* szName, char* szOut, int nSize);                                // 0x0060DE30
    void IGNORELIST_CopyAccountFromStar(const char* szName, char* szOut, int nSize);                           // 0x0060DEA0
    int IGNORELIST_AppendLineToFile(const char* szLine);                                                           // 0x0060DF10
    int IGNORELIST_NormalizeKey(const char* szName, char* szOut, int nSize);                              // 0x0060DFF0
    int IGNORELIST_SaveToFile();                                                                                // 0x0060F0A0
    int IGNORELIST_ContainsName(const char* szKey);
    void IGNORELIST_LoadFromFile();                                                                               // 0x00611050
};

PROFHOOKFN gpfnProfHook; // 0x0096BC28

int gnCompCodeTxtRecordCount; // 0x0096BCB4

D2ExperienceDataTbl* gpExperienceTxt; // 0x0096C8A8

struct D2StormHashKeyStrIStrc;

extern "C" void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0

extern "C" const char gszTypeNameMappingEntryNode_0074362C[]; // 0x0074362C

extern "C" const char gszTypeNameStringEntryNode_0074364C[]; // 0x0074364C

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw();

D2CommonIgnoreListStrc* gpIgnoreList; // 0x0096BC20

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

char* __fastcall sub_0060E280_AddLinkOffset(char* pNode, int nLinkOffset);

char* __fastcall sub_0060E360_AddLinkOffset(char* pNode, int nLinkOffset);

struct D2CommonStormSlotListDStrc;

struct D2CommonStormSlotListEStrc;

struct D2CommonStormZeroAStrc;

struct D2CommonStormZeroBStrc;

struct D2CommonStormSlotListDStrc : D2CommonStormSlotListAStrc
{
    ~D2CommonStormSlotListDStrc();
};

struct D2CommonStormSlotListEStrc : D2CommonStormSlotListBStrc
{
    ~D2CommonStormSlotListEStrc();
};

struct D2CommonStormZeroAStrc
{
    int m_value;

    D2CommonStormZeroAStrc();
};

struct D2CommonStormZeroBStrc
{
    int m_value;

    D2CommonStormZeroBStrc();
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0

extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode);                              // 0x0068239A

extern "C" int __cdecl fclose(_iobuf* pFile);                                                               // 0x00681FDC

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                          // 0x004135D0

extern "C" char* __cdecl strstr(const char* szString, const char* szSubString);

extern "C" char* __stdcall SStrLower(char* szString); // 0x00414200

__declspec(nothrow) void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020

extern "C" int __cdecl fprintf(_iobuf*, const char*, ...); // 0x00684C94

extern const char gszFileModeW[]; // 0x006FF97C

extern const char gszFirstFormat_006CD90C[]; // 0x006CD90C

extern const char gszBangLineFormat[]; // 0x006E62A8

void __cdecl operator delete(void* pMemory, void* pWhere) throw();

extern "C" const char gszTypeNameStringEntryList_0074366C[];                                                          // 0x0074366C

extern "C" const char gszTypeNameMappingEntryList_007436AC[];                                                         // 0x007436AC

int __fastcall ERRORMANAGER_GetModuleDirectory(char* szPath, unsigned int nSize);                                    // 0x00406B60

void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                             // 0x0041D300

const char* __stdcall SStrChrR(const char* szString, char nChar);                                                     // 0x004134D0

unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize);                          // 0x00413800

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10

// build: symbol ??4D2StormHashKeyStrIAStrc@@QAEAAU0@ABU0@@Z 0x0060DCB0
// build: symbol ??4D2StormHashKeyStrIBStrc@@QAEAAU0@ABU0@@Z 0x0060E130
// build: symbol ??_7ChatIgnoreList@@6B@ 0x006E6248
// 0x0060DC70
D2StormHashKeyStrIAStrc::D2StormHashKeyStrIAStrc(const char* szString)
{
    m_str = SStrDup(szString);
}

// 0x0060DC90
D2StormHashKeyStrIAStrc::~D2StormHashKeyStrIAStrc()
{
    if (m_str)
        SMemFree(m_str, "d:\\diablo2\\Diablo2\\3rdparty\\storm\\h\\stpl.h", 0x5E4, 0);
}

// 0x0060DCB0
D2StormHashKeyStrIAStrc& D2StormHashKeyStrIAStrc::operator=(const D2StormHashKeyStrIAStrc& source)
{
    if (m_str)
        SMemFree(m_str, "d:\\diablo2\\Diablo2\\3rdparty\\storm\\h\\stpl.h", 0x5E9, 0);
    m_str = SStrDup(source.m_str);
    return *this;
}

// 0x0060DCF0
char* D2StormHashKeyStrIAStrc::IGNORELIST_GetHashKeyString()
{
    return m_str;
}

// 0x0060DD00
D2StormHashKeyStrIBStrc::D2StormHashKeyStrIBStrc(const char* szString)
{
    m_str = SStrDup(szString);
}

// build: symbol ??_GChatIgnoreList@@UAEPAXI@Z 0x0060DD60
inline void D2CommonChatIgnoreListStrc::operator delete(void* pMemory)
{
    SMemFree(pMemory, "delete", -1, 0);
}

int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590
struct D2CmpStringStrc
{
    const char* szText;

    int EqualsNoCase(const D2CmpStringStrc* pOther); // 0x0060DD20
};

// 0x0060DD20
int D2CmpStringStrc::EqualsNoCase(const D2CmpStringStrc* pOther)
{
    return !SStrCmpI(szText, pOther->szText, 0x7FFFFFFF);
}

// 0x0060DD50
D2CommonChatIgnoreListStrc::~ChatIgnoreList()
{
}

// 0x0060DDD0
D2CommonChatIgnoreListStrc::ChatIgnoreList()
{
}

// 0x0060DDE0
void D2CommonIgnoreListStrc::IGNORELIST_CloseFile()
{
    fclose(m_pFile);
}

// 0x0060DDF0
int D2CommonIgnoreListStrc::IGNORELIST_IsEnabled()
{
    return m_bEnabled;
}

// 0x0060DE00
void D2CommonIgnoreListStrc::IGNORELIST_SetEnabled(int bEnabled)
{
    m_bEnabled = bEnabled;
    SRegSaveValue("Diablo II", "Persistent Ignore", 0, bEnabled);
}

// 0x0060DE30
void D2CommonIgnoreListStrc::IGNORELIST_CopyNameBeforeStar(const char* szName, char* szOut, int nSize)
{
    unsigned int i = 0;
    while (szName[i] != '*' && szName[i] && i <= 16 && i < nSize - 1)
    {
        szOut[i] = szName[i];
        ++i;
    }
    szOut[i] = 0;
}

// 0x0060DEA0
void D2CommonIgnoreListStrc::IGNORELIST_CopyAccountFromStar(const char* szName, char* szOut, int nSize)
{
    for (unsigned int i = 0; szName[i]; ++i)
    {
        if (szName[i] == '*')
        {
            unsigned int n = i;
            for (; szName[n] && n - i <= 16 && n < nSize - 1; ++n)
            {
                szOut[n - i] = szName[n];
            }
            szOut[n] = 0;
            return;
        }
    }
}

// 0x0060E0B0
char* D2CommonStringEntryNodeStrc::IGNORELIST_GetStringEntryKey()
{
    return m_key.m_str;
}

// 0x0060E0C0
bool D2CommonStormSlotLinkStrc::IGNORELIST_IsLinkLinked()
{
    return m_next != 0;
}

// 0x0060E130
D2StormHashKeyStrIBStrc& D2StormHashKeyStrIBStrc::operator=(const D2StormHashKeyStrIBStrc& source)
{
    if (m_str)
        SMemFree(m_str, "d:\\diablo2\\Diablo2\\3rdparty\\storm\\h\\stpl.h", 0x5E9, 0);
    m_str = SStrDup(source.m_str);
    return *this;
}

// 0x0060E1A0
char* D2CommonStormSlotLinkStrc::sub_0060E1A0_Next()
{
    return MaskNext();
}

// 0x0060E200
D2ChatStormBaseArrayAStrc::D2ChatStormBaseArrayAStrc()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

// 0x0060E220
D2ChatStormBaseArrayBStrc::D2ChatStormBaseArrayBStrc()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

// 0x0060E230
unsigned int D2ChatStormBaseArrayAStrc::IGNORELIST_GetStringSlotArrayCount()
{
    return m_count;
}

// 0x0060E240
char* D2CommonStormSlotLinkStrc::sub_0060E240_Next()
{
    return MaskNext();
}

// 0x0060E250
unsigned int D2ChatStormBaseArrayBStrc::IGNORELIST_GetMappingSlotArrayCount()
{
    return m_count;
}

// 0x0060E260
void D2CommonStormSlotListAStrc::IGNORELIST_InitStringListTerminator()
{
    InitializeTerminator();
}

// 0x0060E270
void D2CommonStormSlotListBStrc::IGNORELIST_InitMappingListTerminator()
{
    InitializeTerminator();
}

// 0x0060E280
char* __fastcall sub_0060E280_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

inline unsigned int D2CommonStormSlotArrayAStrc::sub_0060E2A0_CalcChunkSize(unsigned int nCount)
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

inline unsigned int D2CommonStormSlotArrayBStrc::sub_0060E300_CalcChunkSize(unsigned int nCount)
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

// 0x0060E360
char* __fastcall sub_0060E360_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

// 0x0060E3B0
void D2CommonStormSlotLinkStrc::sub_0060E3B0_Unlink()
{
    Unlink();
}

// 0x0060E3F0
D2ChatStormLinkAStrc::D2ChatStormLinkAStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

// 0x0060E400
void D2CommonStormSlotLinkStrc::sub_0060E400_Unlink()
{
    Unlink();
}

// 0x0060E440
char* D2CommonStormSlotListAStrc::IGNORELIST_GetStringListHead()
{
    return m_terminator.MaskNext();
}

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

static unsigned int __stdcall STORM_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// build: symbol ??_7?$TSHashTable@UStringEntryNode@@VHASHKEY_STRI@@@@6B@ 0x006E62B4
// build: symbol ??_7?$TSHashTable@UMappingEntryNode@@VHASHKEY_STRI@@@@6B@ 0x006E62C8
// 0x0060E450
D2CommonStormSlotLinkStrc* D2CommonStormSlotListAStrc::IGNORELIST_GetStringListLink(char* pNode)
{
    return Link(pNode);
}

// 0x0060E470
void D2CommonStormSlotListAStrc::IGNORELIST_InitStringListLinkOffset(int nLinkOffset)
{
    m_linkoffset = nLinkOffset;
    InitializeTerminator();
}

// 0x0060E490
void D2CommonStormSlotListAStrc::IGNORELIST_LinkStringListNode(char* pNode, int nLinkType, char* pExistingNode)
{
    D2CommonStormSlotLinkStrc* pLink = Link(pNode);
    pLink->Unlink();
    D2CommonStormSlotLinkStrc* pExistingLink = Link(pExistingNode);
    switch (nLinkType)
    {
    case 1:
        pLink->m_prevlink = pExistingLink;
        pLink->m_next = pExistingLink->m_next;
        pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
        pExistingLink->m_next = pNode;
        break;
    default:
        D2CommonStormSlotLinkStrc* pPrevLink = pExistingLink->m_prevlink;
        pLink->m_prevlink = pPrevLink;
        pLink->m_next = pPrevLink->m_next;
        pPrevLink->m_next = pNode;
        pExistingLink->m_prevlink = pLink;
        break;
    }
}

// 0x0060E540
char* D2CommonStormSlotListAStrc::IGNORELIST_GetStringListRawNext(char* pNode)
{
    return Link(pNode)->m_next;
}

// build: symbol ??_GD2CommonMappingEntryNodeStrc@@QAEPAXI@Z 0x0060EDF0
// build: symbol ??_GD2CommonStormSlotListAStrc@@QAEPAXI@Z 0x0060EFC0
// build: symbol ??_GD2CommonStormSlotListBStrc@@QAEPAXI@Z 0x0060F300
// build: symbol ??_GD2CommonStringEntryNodeStrc@@QAEPAXI@Z 0x0060F160
// 0x0060E560
void D2CommonStormSlotListAStrc::IGNORELIST_UnlinkStringListNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x0060E5B0
void D2CommonStormSlotListBStrc::IGNORELIST_InitMappingListLinkOffset(int nLinkOffset)
{
    m_linkoffset = nLinkOffset;
    InitializeTerminator();
}

// 0x0060E5D0
char* D2CommonStormSlotListBStrc::IGNORELIST_GetMappingListHead()
{
    return m_terminator.MaskNext();
}

// 0x0060E5E0
D2ChatStormLinkBStrc::D2ChatStormLinkBStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

// 0x0060E5F0
void D2CommonStormSlotListAStrc::IGNORELIST_ResetStringList()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x0060E610
void D2CommonStormSlotListBStrc::IGNORELIST_ResetMappingList()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x0060E630
D2CommonStormSlotLinkStrc* D2CommonStormSlotListBStrc::IGNORELIST_GetMappingListLink(char* pNode)
{
    return Link(pNode);
}

// 0x0060E650
char* D2CommonStormSlotListAStrc::IGNORELIST_GetStringListNext(char* pNode)
{
    return Link(pNode)->Next();
}

// 0x0060E690
void D2CommonStormSlotLinkStrc::sub_0060E690_Unlink()
{
    Unlink();
}

// 0x0060E6D0
char* D2CommonStormHashTableAStrc::IGNORELIST_GetStringTableHead()
{
    return m_fulllist.m_terminator.MaskNext();
}

// 0x0060E6E0
void D2CommonStormHashTableAStrc::IGNORELIST_UnlinkStringTableNode(D2CommonStringEntryNodeStrc* pNode)
{
    if (pNode->m_linktoslot.m_next)
    {
        pNode->m_linktoslot.Unlink();
        pNode->m_linktofull.Unlink();
    }
}

// 0x0060E760
void D2CommonStormSlotLinkStrc::sub_0060E760_Unlink()
{
    Unlink();
}

// 0x0060E7A0
void D2CommonStormHashTableAStrc::IGNORELIST_DeleteStringTableNode(D2CommonStringEntryNodeStrc* pNode)
{
    IGNORELIST_UnlinkStringTableNode(pNode);
    IGNORELIST_InternalDeleteStringTableNode(pNode);
}

// 0x0060E7C0
char* D2CommonStormSlotListBStrc::IGNORELIST_GetMappingListNext(char* pNode)
{
    return Link(pNode)->Next();
}

// 0x0060E800
D2ChatStormListCStrc::D2ChatStormListCStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0060E870
D2ChatStormListDStrc::D2ChatStormListDStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// build: symbol ?UnlinkAll@D2CommonStormSlotListAStrc@@QAEXXZ 0x0060E820
inline void D2CommonStormSlotListAStrc::UnlinkAll()
{
    char* pNode;
    while ((pNode = Head()) != 0)
        Link(pNode)->Unlink();
}

// 0x0060E890
void D2CommonStormSlotListBStrc::IGNORELIST_LinkMappingListNode(char* pNode, int nLinkType, char* pExistingNode)
{
    D2CommonStormSlotLinkStrc* pLink = Link(pNode);
    pLink->Unlink();
    D2CommonStormSlotLinkStrc* pExistingLink = Link(pExistingNode);
    switch (nLinkType)
    {
    case 1:
        pLink->m_prevlink = pExistingLink;
        pLink->m_next = pExistingLink->m_next;
        pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
        pExistingLink->m_next = pNode;
        break;
    default:
        D2CommonStormSlotLinkStrc* pPrevLink = pExistingLink->m_prevlink;
        pLink->m_prevlink = pPrevLink;
        pLink->m_next = pPrevLink->m_next;
        pPrevLink->m_next = pNode;
        pExistingLink->m_prevlink = pLink;
        break;
    }
}

// 0x0060E940
char* D2CommonStormSlotListBStrc::IGNORELIST_GetMappingListRawNext(char* pNode)
{
    return Link(pNode)->m_next;
}

// 0x0060E960
void D2CommonStormSlotListBStrc::IGNORELIST_UnlinkMappingListNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x0060E9B0
D2CommonStormListCStrc::D2CommonStormListCStrc(const D2CommonStormListCStrc& source)
{
    m_linkoffset = source.m_linkoffset;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0060E9E0
D2CommonStormListDStrc::D2CommonStormListDStrc(const D2CommonStormListDStrc& source)
{
    m_linkoffset = source.m_linkoffset;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0060DDB0
void __cdecl IGNORELIST_FreeIgnoreList()
{
    delete gpIgnoreList;
    gpIgnoreList = 0;
}

// 0x0060EA10
D2CommonMappingEntryNodeBaseStrc::~D2CommonMappingEntryNodeBaseStrc()
{
}

// 0x0060EAA0
char* D2CommonStormHashTableAStrc::IGNORELIST_GetStringTableNext(char* pNode)
{
    return m_fulllist.Next(pNode);
}

// 0x0060EAE0
D2CommonStringEntryNodeStrc::~D2CommonStringEntryNodeStrc()
{
}

// 0x0060EB70
void D2CommonStormHashTableAStrc::IGNORELIST_InternalClearStringTable(int bWarn)
{
    m_fullnessIndicator = 0;
    m_fulllist.UnlinkAll();
    for (unsigned int i = 0; i < m_slotlistarray.m_count; i++)
    {
        while (char* pNode = m_slotlistarray[i].Head())
        {
            if (bWarn)
                m_slotlistarray[i].sub_006C4290(pNode);
            else
                IGNORELIST_InternalDeleteStringTableNode((D2CommonStringEntryNodeStrc*)pNode);
        }
    }
}

// 0x0060EC00
char* D2CommonStormHashTableBStrc::IGNORELIST_GetMappingTableNext(char* pNode)
{
    return m_fulllist.Next(pNode);
}

// 0x0060EC40
D2CommonStormSlotListAStrc::~D2CommonStormSlotListAStrc()
{
    UnlinkAll();
}

// 0x0060EC80
void D2CommonStormSlotListAStrc::IGNORELIST_ChangeStringListLinkOffset(int nLinkOffset)
{
    if (nLinkOffset != m_linkoffset)
    {
        UnlinkAll();
        m_linkoffset = nLinkOffset;
        InitializeTerminator();
    }
}

// build: symbol ?UnlinkAll@D2CommonStormSlotListBStrc@@QAEXXZ 0x0060ECB0
inline void D2CommonStormSlotListBStrc::UnlinkAll()
{
    char* pNode;
    while ((pNode = Head()) != 0)
        Link(pNode)->Unlink();
}

// 0x0060ED00
D2CommonStormListEStrc::D2CommonStormListEStrc(const D2CommonStormListEStrc& source)
{
    m_linkoffset = source.m_linkoffset;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0060ED30
D2CommonMappingEntryNodeStrc::~D2CommonMappingEntryNodeStrc()
{
    if (pMapped)
        SMemFree(pMapped, ".\\Chat\\Ignorelist.cpp", 0x11, 0);
}

// 0x0060ED60
void D2CommonStormHashTableAStrc::IGNORELIST_ClearStringTable()
{
    IGNORELIST_InternalClearStringTable(0);
}

// 0x0060ED70
char* D2CommonStormHashTableAStrc::IGNORELIST_DeleteStringTableNodeAndGetNext(D2CommonStringEntryNodeStrc* pNode)
{
    char* pNext = m_fulllist.Next((char*)pNode);
    IGNORELIST_UnlinkStringTableNode(pNode);
    IGNORELIST_InternalDeleteStringTableNode(pNode);
    return pNext;
}

// 0x0060EDB0
D2StormSlotList0060EDB0Strc::~D2StormSlotList0060EDB0Strc()
{
}

// 0x0060EDF0
inline void D2CommonMappingEntryNodeStrc::operator delete(void* pMemory)
{
    SMemFree(pMemory, "delete", -1, 0);
}

// 0x0060EE30
void D2CommonStringEntryNodeStrc::IGNORELIST_DestroyStringEntryNode()
{
    this->~D2CommonStringEntryNodeStrc();
}

// 0x0060EE40
D2ChatStormListEStrc::D2ChatStormListEStrc()
{
    m_linkoffset = 0xDDDDDDDD;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0060EE60
void D2CommonStormHashTableBStrc::IGNORELIST_InternalClearMappingTable(int bWarn)
{
    m_fullnessIndicator = 0;
    m_fulllist.UnlinkAll();
    for (unsigned int i = 0; i < m_slotlistarray.m_count; i++)
    {
        while (char* pNode = m_slotlistarray[i].Head())
        {
            if (bWarn)
                m_slotlistarray[i].sub_006C4290(pNode);
            else
                IGNORELIST_InternalDeleteMappingTableNode((D2CommonMappingEntryNodeStrc*)pNode);
        }
    }
}

// 0x0060EEF0
D2CommonStormSlotListBStrc::~D2CommonStormSlotListBStrc()
{
    UnlinkAll();
}

// 0x0060EF30
void D2CommonStormSlotListBStrc::IGNORELIST_ChangeMappingListLinkOffset(int nLinkOffset)
{
    if (nLinkOffset != m_linkoffset)
    {
        UnlinkAll();
        m_linkoffset = nLinkOffset;
        InitializeTerminator();
    }
}

// 0x0060EF60
char* D2CommonStormSlotListBStrc::IGNORELIST_DeleteMappingListNode(D2CommonMappingEntryNodeStrc* pNode)
{
    char* pNext = Link((char*)pNode)->Next();
    pNode->~D2CommonMappingEntryNodeStrc();
    SMemFree(pNode, gszTypeNameMappingEntryNode_0074362C, -2, 0);
    return pNext;
}

// 0x0060EFC0
inline void D2CommonStormSlotListAStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x0060F020
void __fastcall sub_0060F020_ConstructDeadList(D2StormDeadListStrc* pList) {
 new(pList) D2StormDeadListStrc;
}

// 0x0060F050
void __fastcall sub_0060F050_ConstructList(D2StormListEStrc* pList, const D2StormListEStrc* pSource)
{
    if (pList)
    {
        D2StormLinkStrc* pLink = &pList->m_terminator;
        pLink->m_prevlink = 0;
        pLink->m_next = 0;
        pList->m_linkoffset = pSource->m_linkoffset;
        pList->m_terminator.m_prevlink = &pList->m_terminator;
        pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
    }
}

// 0x0060F070
D2CommonStormListFStrc::D2CommonStormListFStrc(const D2CommonStormListFStrc& source)
{
    m_linkoffset = source.m_linkoffset;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0060F0A0
int D2CommonIgnoreListStrc::IGNORELIST_SaveToFile()
{
    _iobuf* pFile = fopen(szFileName, gszFileModeW);
    if (!pFile)
        return 0;
    for (char* pNode = m_table.m_fulllist.m_terminator.NextChecked(); (int)pNode > 0; pNode = ((D2CommonStormSlotLinkStrc*)(pNode + m_table.m_fulllist.m_linkoffset))->Next())
        fprintf(pFile, gszFirstFormat_006CD90C, ((D2CommonStringEntryNodeStrc*)pNode)->m_key.m_str);
    for (char* pNode = m_table2.m_fulllist.m_terminator.NextChecked(); (int)pNode > 0; pNode = ((D2CommonStormSlotLinkStrc*)(pNode + m_table2.m_fulllist.m_linkoffset))->Next())
        fprintf(pFile, gszBangLineFormat, ((D2CommonStringEntryNodeStrc*)pNode)->m_key.m_str);
    fclose(pFile);
    return 1;
}

// 0x0060F150
void D2CommonStormHashTableBStrc::IGNORELIST_ClearMappingTable()
{
    IGNORELIST_InternalClearMappingTable(0);
}

// 0x0060F160
inline void D2CommonStringEntryNodeStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x0060F190
D2CommonStormSlotListCStrc::~D2CommonStormSlotListCStrc()
{
}

// 0x0060F1D0
D2CommonMappingEntryNodeStrc* D2CommonStormHashTableBStrc::IGNORELIST_InternalFindMappingTableNode(unsigned int nHashVal, const D2StormHashKeyStrIStrc& key)
{
    for (char* pNode = m_slotlistarray[nHashVal & m_slotmask].MaskHead(); (int)pNode > 0; pNode = m_slotlistarray[nHashVal & m_slotmask].RawNext(pNode))
    {
        D2CommonMappingEntryNodeStrc* pEntry = (D2CommonMappingEntryNodeStrc*)pNode;
        if (pEntry->m_hashval == nHashVal && !SStrCmpI(pEntry->m_key.m_str, key.m_str, 0x7FFFFFFF))
            return pEntry;
    }
    return 0;
}

// 0x0060F250
D2ChatStormListFStrc::D2ChatStormListFStrc()
{
    m_linkoffset = 0xDDDDDDDD;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0060F270
char* D2CommonStormSlotListAStrc::IGNORELIST_DeleteStringListNode(D2CommonStringEntryNodeStrc* pNode)
{
    char* pNext = Link((char*)pNode)->Next();
    pNode->~D2CommonStringEntryNodeStrc();
    SMemFree(pNode, gszTypeNameStringEntryNode_0074364C, -2, 0);
    return pNext;
}

// 0x0060F2C0
D2CommonStormSlotListDStrc::~D2CommonStormSlotListDStrc()
{
}

// 0x0060F300
inline void D2CommonStormSlotListBStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x0060F360
void __fastcall sub_0060F360_ConstructDeadList(D2StormDeadListStrc* pList) {
 new(pList) D2StormDeadListStrc;
}

// 0x0060F390
void D2CommonStormSlotArrayAStrc::IGNORELIST_ReallocStringSlotArray(unsigned int nAlloc)
{
    D2CommonStormSlotListAStrc* pOldData = m_data;
    for (unsigned int i = nAlloc; i < m_count; i++)
        pOldData[i].~D2CommonStormSlotListAStrc();
    m_alloc = nAlloc;
    m_data = (D2CommonStormSlotListAStrc*)SMemReAlloc(pOldData, nAlloc * sizeof(D2CommonStormSlotListAStrc), gszTypeNameStringEntryList_0074366C, -2, 0x10);
    if (!m_data)
    {
        m_data = (D2CommonStormSlotListAStrc*)SMemAlloc(nAlloc * sizeof(D2CommonStormSlotListAStrc), gszTypeNameStringEntryList_0074366C, -2, 0);
        if (pOldData)
        {
            unsigned int nCount = nAlloc < m_count ? nAlloc : m_count;
            for (unsigned int i = 0; i < nCount; i++)
            {
                new (&m_data[i]) D2CommonStormSlotListAStrc(pOldData[i]);
                pOldData[i].~D2CommonStormSlotListAStrc();
            }
            SMemFree(pOldData, gszTypeNameStringEntryList_0074366C, -2, 0);
        }
    }
}

// 0x0060F4E0
void __fastcall sub_0060F4E0_ConstructList(D2StormListEStrc* pList, const D2StormListEStrc* pSource)
{
    if (pList)
    {
        D2StormLinkStrc* pLink = &pList->m_terminator;
        pLink->m_prevlink = 0;
        pLink->m_next = 0;
        pList->m_linkoffset = pSource->m_linkoffset;
        pList->m_terminator.m_prevlink = &pList->m_terminator;
        pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
    }
}

// 0x0060F500
void D2CommonIgnoreListStrc::IGNORELIST_ClearAccountAliases()
{
    m_table3.IGNORELIST_InternalClearMappingTable(0);
}

// 0x0060F510
D2CommonMappingEntryNodeStrc* D2CommonStormHashTableBStrc::IGNORELIST_FindMappingTableNode(const char* szKey)
{
    return IGNORELIST_InternalFindMappingTableNode(SStrHash(szKey, 0, 0), D2StormHashKeyStrIStrc(szKey));
}

// 0x0060F590
D2CommonStringEntryNodeStrc* D2CommonStormHashTableAStrc::IGNORELIST_InternalFindStringTableNode(unsigned int nHashVal, const D2StormHashKeyStrIStrc& key)
{
    for (char* pNode = m_slotlistarray[nHashVal & m_slotmask].MaskHead(); (int)pNode > 0; pNode = m_slotlistarray[nHashVal & m_slotmask].RawNext(pNode))
    {
        D2CommonStringEntryNodeStrc* pEntry = (D2CommonStringEntryNodeStrc*)pNode;
        if (pEntry->m_hashval == nHashVal && !SStrCmpI(pEntry->m_key.m_str, key.m_str, 0x7FFFFFFF))
            return pEntry;
    }
    return 0;
}

// 0x0060F610
D2CommonStormSlotArrayAStrc::~D2CommonStormSlotArrayAStrc()
{
    for (unsigned int i = 0; i < m_count; i++)
        m_data[i].~D2CommonStormSlotListAStrc();
    if (m_data)
        SMemFree(m_data, gszTypeNameStringEntryList_0074366C, -2, 0);
}

// 0x0060F690
D2CommonStormSlotListEStrc::~D2CommonStormSlotListEStrc()
{
}

// 0x0060F6D0
void D2CommonStormSlotArrayAStrc::IGNORELIST_ReserveStringSlotArray(unsigned int nCount, int bRound)
{
    nCount += m_count;
    if (nCount > m_alloc)
    {
        if (bRound)
        {
            unsigned int nChunk = m_chunk ? m_chunk : sub_0060E2A0_CalcChunkSize(nCount);
            nCount = STORM_RoundUp(nCount, nChunk);
        }
        IGNORELIST_ReallocStringSlotArray(nCount);
    }
}

// 0x0060F720
void D2CommonStormSlotArrayBStrc::IGNORELIST_ReallocMappingSlotArray(unsigned int nAlloc)
{
    D2CommonStormSlotListBStrc* pOldData = m_data;
    for (unsigned int i = nAlloc; i < m_count; i++)
        pOldData[i].~D2CommonStormSlotListBStrc();
    m_alloc = nAlloc;
    m_data = (D2CommonStormSlotListBStrc*)SMemReAlloc(pOldData, nAlloc * sizeof(D2CommonStormSlotListBStrc), gszTypeNameMappingEntryList_007436AC, -2, 0x10);
    if (!m_data)
    {
        m_data = (D2CommonStormSlotListBStrc*)SMemAlloc(nAlloc * sizeof(D2CommonStormSlotListBStrc), gszTypeNameMappingEntryList_007436AC, -2, 0);
        if (pOldData)
        {
            unsigned int nCount = nAlloc < m_count ? nAlloc : m_count;
            for (unsigned int i = 0; i < nCount; i++)
            {
                new (&m_data[i]) D2CommonStormSlotListBStrc(pOldData[i]);
                pOldData[i].~D2CommonStormSlotListBStrc();
            }
            SMemFree(pOldData, gszTypeNameMappingEntryList_007436AC, -2, 0);
        }
    }
}

// 0x00610EB0
int D2CommonIgnoreListStrc::IGNORELIST_AddName(const char* szName)
{
    if (!szName || !*szName || !IGNORELIST_IsEnabled())
        return 0;
    char szKey[0x100] = "";
    IGNORELIST_NormalizeKey(szName, szKey, 0x100);
    if (!szKey[0])
        return 0;
    if (!m_table.IGNORELIST_FindStringTableNode(szKey))
    {
        m_table.IGNORELIST_NewStringTableNode(szKey, 0, 0);
        IGNORELIST_AppendLineToFile(szKey);
    }
    return 1;
}

// 0x0060DF10
int D2CommonIgnoreListStrc::IGNORELIST_AppendLineToFile(const char* szLine)
{
    if (!szLine || !*szLine || !IGNORELIST_IsEnabled())
    {
        return 0;
    }

    int bResult = 0;
    char szBuffer[0x100];
    SStrCopy(szBuffer, szLine, sizeof(szBuffer));
// build: symbol ?gszNewline@* 0x006FFCB0
    SStrPack(szBuffer, gszNewline, sizeof(szBuffer));
    m_pFile = fopen(szFileName, "at+");
    if (m_pFile)
    {
        fwrite(szBuffer, SStrLen(szBuffer), 1, m_pFile);
        bResult = fclose(m_pFile) == 0;
    }
    return bResult;
}

// 0x0060DFF0
int D2CommonIgnoreListStrc::IGNORELIST_NormalizeKey(const char* szName, char* szOut, int nSize)
{
    D2_ASSERT(szOut, 416);

    *szOut = '\0';
    char szKey[0x100] = "";
    IGNORELIST_CopyAccountFromStar(szName, szKey, sizeof(szKey));
    if (!szKey[0])
    {
        IGNORELIST_CopyNameBeforeStar(szName, szKey, sizeof(szKey));
    }
    SStrCopy(szOut, szKey, nSize);
    return 0;
}

// 0x0060F870
int D2CommonIgnoreListStrc::IGNORELIST_TranslateAlias(const char* szName, char* szOut, int nSize)
{
    D2CommonMappingEntryNodeStrc* pNode = m_table3.IGNORELIST_FindMappingTableNode(szName);
    if (pNode)
    {
        SStrCopy(szOut, pNode->pMapped, nSize);
        return 1;
    }
    return 0;
}

// 0x0060F8B0
D2CommonStringEntryNodeStrc* D2CommonStormHashTableAStrc::IGNORELIST_FindStringTableNode(const char* szKey)
{
    return IGNORELIST_InternalFindStringTableNode(SStrHash(szKey, 0, 0), D2StormHashKeyStrIStrc(szKey));
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

// build: symbol ?BNNEWS_CopyNewsItem@* 0x0051D350
void __fastcall BNNEWS_CopyNewsItem(D2Storm408ElemStrc* pDst, const D2Storm408ElemStrc* pSrc)
{
    if (pDst)
        *pDst = *pSrc;
}

void D2StormArray408Strc::sub_0051D570_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

void D2StormArray408Strc::sub_0051D670_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

// 0x0060F930
D2CommonStormSlotArrayAViewStrc::~D2CommonStormSlotArrayAViewStrc()
{
}

// 0x0060F940
D2StormArray408Strc* D2StormArray408Strc::sub_0051D690_Init()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    m_chunk = 0;
    return this;
}

// 0x0060F950
D2CommonStormSlotArrayBStrc::~D2CommonStormSlotArrayBStrc()
{
    for (unsigned int i = 0; i < m_count; i++)
        m_data[i].~D2CommonStormSlotListBStrc();
    if (m_data)
        SMemFree(m_data, gszTypeNameMappingEntryList_007436AC, -2, 0);
}

// 0x0060F9D0
void D2CommonStormSlotArrayAStrc::IGNORELIST_SetStringSlotArrayCount(unsigned int nCount)
{
    if (nCount > m_count)
    {
        if (nCount > m_alloc)
        {
            unsigned int nChunk = m_chunk ? m_chunk : sub_0060E2A0_CalcChunkSize(nCount);
            IGNORELIST_ReallocStringSlotArray(STORM_RoundUp(nCount, nChunk));
        }
        for (unsigned int i = m_count; i < nCount; i++)
            new (&m_data[i]) D2CommonStormSlotListAStrc;
    }
    else if (nCount < m_count)
    {
        for (unsigned int i = nCount; i < m_count; i++)
            m_data[i].~D2CommonStormSlotListAStrc();
    }
    m_count = nCount;
}

// 0x0060FAD0
void D2CommonStormSlotArrayBStrc::IGNORELIST_ReserveMappingSlotArray(unsigned int nCount, int bRound)
{
    nCount += m_count;
    if (nCount > m_alloc)
    {
        if (bRound)
        {
            unsigned int nChunk = m_chunk ? m_chunk : sub_0060E300_CalcChunkSize(nCount);
            nCount = STORM_RoundUp(nCount, nChunk);
        }
        IGNORELIST_ReallocMappingSlotArray(nCount);
    }
}

// 0x0060FB20
int D2CommonIgnoreListStrc::IGNORELIST_RemoveName(const char* szName)
{
    if (!szName || !*szName)
        return 0;
    if (!IGNORELIST_IsEnabled())
        return 0;
    char szKey[0x100] = "";
    IGNORELIST_NormalizeKey(szName, szKey, sizeof(szKey));
    if (!szKey[0])
        return 0;
    D2CommonStringEntryNodeStrc* pNode = m_table.IGNORELIST_FindStringTableNode(szKey);
    if (!pNode)
        return 0;
    m_table.IGNORELIST_UnlinkStringTableNode(pNode);
    IGNORELIST_SaveToFile();
    return 1;
}

// 0x0060FBE0
int D2CommonIgnoreListStrc::IGNORELIST_RemoveAlias(const char* szName)
{
    if (szName && *szName && IGNORELIST_IsEnabled())
    {
        D2CommonStringEntryNodeStrc* pNode = m_table2.IGNORELIST_FindStringTableNode(szName);
        if (pNode)
        {
            m_table2.IGNORELIST_UnlinkStringTableNode(pNode);
            IGNORELIST_SaveToFile();
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

// 0x0060FC40
int D2CommonIgnoreListStrc::IGNORELIST_IsTextFiltered(const char* szName)
{
    if (szName && *szName && IGNORELIST_IsEnabled())
    {
        if (m_table2.IGNORELIST_FindStringTableNode(szName))
            return 1;
        char szLower[0x100];
        char szKey[0x100];
        SStrCopy(szLower, szName, 0x7FFFFFFF);
        SStrLower(szLower);
        for (char* pNode = (char*)((((int)m_table2.m_fulllist.m_terminator.m_next <= 0) - 1) & (int)m_table2.m_fulllist.m_terminator.m_next);
             (int)pNode > 0; pNode = m_table2.IGNORELIST_GetStringTableNext(pNode))
        {
            SStrCopy(szKey, ((D2CommonStringEntryNodeStrc*)pNode)->m_key.m_str, 0x7FFFFFFF);
            SStrLower(szKey);
            if (strstr(szLower, szKey))
                return 1;
        }
        return 0;
    }
    return 0;
}

// build: symbol ??_7?$TSHashTable@UStringEntryNode@@VHASHKEY_STRI@@@@6B@ 0x006E62B4
// 0x0060FD50
int D2CommonIgnoreListStrc::IGNORELIST_ContainsName(const char* szKey)
{
    if (!szKey || !*szKey)
        return 0;
    if (!IGNORELIST_IsEnabled())
        return 0;
    return m_table.IGNORELIST_FindStringTableNode(szKey) != 0;
}

// 0x0060FD90
D2CommonStormHashTableAStrc::~TSHashTable()
{
    IGNORELIST_InternalClearStringTable(1);
}

// 0x0060FE30
D2CommonStormZeroAStrc::D2CommonStormZeroAStrc()
{
    m_value = 0;
}

void D2StormArray408Strc::sub_0051D6A0_Clear()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
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
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

D2Storm408ElemStrc* D2StormArray408Strc::sub_0051D7A0_New()
{
    ReserveInline(1, 1);
    return &m_data[m_count++];
}

// 0x0060FE40
D2CommonStormZeroBStrc::D2CommonStormZeroBStrc()
{
    m_value = 0;
}

void sub_F44_EmitMappingEntryNode(D2CommonMappingEntryNodeStrc* p)
{
    delete p;
}

void sub_F44_EmitStringEntryNode(D2CommonStringEntryNodeStrc* p)
{
    delete p;
}



// 0x0060FE50
D2CommonStormZeroFE50Strc::D2CommonStormZeroFE50Strc() : n0x04(0), n0x08(0), n0x0C(0), n0x10(0), n0x14(0)
{
}

// 0x0060FE70
D2CommonStormZeroFE70Strc::D2CommonStormZeroFE70Strc() : n0x04(0), n0x08(0), n0x0C(0), n0x10(0), n0x14(0)
{
}

// build: symbol ??_G?$TSHashTable@UStringEntryNode@@VHASHKEY_STRI@@@@UAEPAXI@Z 0x00610050
// build: symbol ??_G?$TSHashTable@UMappingEntryNode@@VHASHKEY_STRI@@@@UAEPAXI@Z 0x00610800
// build: symbol ??_GD2CommonStormSlotArrayAStrc@@QAEPAXI@Z 0x0060FFD0
// build: symbol ??_GD2CommonStormSlotArrayBStrc@@QAEPAXI@Z 0x00610780
// 0x0060FE90
D2CommonStringEntryNodeStrc* D2CommonStormSlotListAStrc::IGNORELIST_NewStringListNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    D2CommonStringEntryNodeStrc* pNode = new (SMemAlloc(sizeof(D2CommonStringEntryNodeStrc) + nExtraBytes, gszTypeNameStringEntryNode_0074364C, -2, nFlags | 8)) D2CommonStringEntryNodeStrc;
    if (nLinkType)
        IGNORELIST_LinkStringListNode((char*)pNode, nLinkType, 0);
    return pNode;
}

// 0x0060FEF0
D2CommonStringEntryNodeStrc* D2CommonStormHashTableAStrc::IGNORELIST_AllocStringTableNodeInList(D2CommonStormSlotListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2CommonStringEntryNodeStrc) + nExtraBytes, gszTypeNameStringEntryNode_0074364C, -2, nFlags | 8);
    D2CommonStringEntryNodeStrc* pNode = new (pMemory) D2CommonStringEntryNodeStrc;
    pList->LinkNode((char*)pNode, 1, 0);
    return pNode;
}

// 0x0060FFA0
void D2CommonStormHashTableAStrc::IGNORELIST_InternalDeleteStringTableNode(D2CommonStringEntryNodeStrc* pNode)
{
    pNode->~D2CommonStringEntryNodeStrc();
    SMemFree(pNode, gszTypeNameStringEntryNode_0074364C, -2, 0);
}

// 0x0060FFD0
inline void D2CommonStormSlotArrayAStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x00610000
void D2CommonStormSlotArrayAStrc::IGNORELIST_ClearStringSlotArray()
{
    this->~D2CommonStormSlotArrayAStrc();
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

// 0x00610020
void D2CommonStormHashTableAStrc::IGNORELIST_DestroyStringTable()
{
    IGNORELIST_InternalClearStringTable(1);
    m_fullnessIndicator = 0;
    m_slotmask = 0;
    m_slotlistarray.IGNORELIST_ClearStringSlotArray();
}

// 0x00610050
inline void D2CommonStormHashTableAStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x00610080
D2CommonStormSlotGrowArrayBStrc::~D2CommonStormSlotGrowArrayBStrc()
{
}

// 0x00610090
void D2CommonStormSlotArrayAStrc::IGNORELIST_ForwardSetStringSlotArrayCount(unsigned int nCount)
{
    IGNORELIST_SetStringSlotArrayCount(nCount);
}

// 0x006100A0
D2StormArray408Strc* D2StormArray408Strc::sub_006100A0_Init()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    m_chunk = 0;
    return this;
}

// 0x006100B0
void D2CommonStormSlotArrayBStrc::IGNORELIST_SetMappingSlotArrayCount(unsigned int nCount)
{
    if (nCount > m_count)
    {
        if (nCount > m_alloc)
        {
            unsigned int nChunk = m_chunk ? m_chunk : sub_0060E300_CalcChunkSize(nCount);
            IGNORELIST_ReallocMappingSlotArray(STORM_RoundUp(nCount, nChunk));
        }
        for (unsigned int i = m_count; i < nCount; i++)
            new (&m_data[i]) D2CommonStormSlotListBStrc;
    }
    else if (nCount < m_count)
    {
        for (unsigned int i = nCount; i < m_count; i++)
            m_data[i].~D2CommonStormSlotListBStrc();
    }
    m_count = nCount;
}

// 0x006101B0
void D2CommonStormHashTableAStrc::IGNORELIST_GrowStringTableSlots()
{
    unsigned int nOldCount = m_slotmask + 1;
    unsigned int nNewCount = nOldCount * 2;
    D2CommonStormSlotListAStrc tTemp;
    tTemp.ChangeLinkOffset(4);
    for (unsigned int i = 0; i < nOldCount; i++)
    {
        char* pNode;
        while ((pNode = m_slotlistarray.m_data[i].Head()) != 0)
            tTemp.LinkNode(pNode, 2, 0);
    }
    m_slotlistarray.IGNORELIST_SetStringSlotArrayCount(nNewCount);
    for (unsigned int j = 0; j < nNewCount; j++)
        m_slotlistarray.m_data[j].ChangeLinkOffset(4);
    m_slotmask = nNewCount - 1;
    D2CommonStringEntryNodeStrc* pNode;
    while ((pNode = (D2CommonStringEntryNodeStrc*)tTemp.Head()) != 0)
        InternalLinkNode(pNode, pNode->m_hashval);
}

// 0x00610380
int D2CommonIgnoreListStrc::IGNORELIST_IsListed(const char* szName)
{
    if (!szName || !*szName || !IGNORELIST_IsEnabled())
        return 0;
    char szAlias[0x100] = "";
    char szNormalized[0x100] = "";
    IGNORELIST_CopyNameBeforeStar(szName, szNormalized, 0x100);
    IGNORELIST_TranslateAlias(szNormalized, szAlias, 0x100);
    if (!szAlias[0])
        IGNORELIST_CopyAccountFromStar(szName, szAlias, 0x100);
    if (szAlias[0] && IGNORELIST_ContainsName(szAlias))
        return 1;
    if (szNormalized[0] && IGNORELIST_ContainsName(szNormalized))
        return 1;
    return 0;
}

// build: symbol ??_7?$TSHashTable@UMappingEntryNode@@VHASHKEY_STRI@@@@6B@ 0x006E62C8
// 0x006104A0
D2CommonStormHashTableAStrc::TSHashTable()
{
    m_fullnessIndicator = 0;
    m_fulllist.ChangeLinkOffset(0xC);
    m_slotmask = 3;
    m_slotlistarray.IGNORELIST_SetStringSlotArrayCount(4);
    for (unsigned int i = 0; i <= m_slotmask; i++)
        m_slotlistarray.m_data[i].ChangeLinkOffset(4);
}

// 0x00610550
D2CommonStormHashTableBStrc::~TSHashTable()
{
    IGNORELIST_InternalClearMappingTable(1);
}

// build: symbol ?DRLGANIM_MapTileType@* 0x0066D7E0
int __fastcall DRLGANIM_MapTileType(int nId)
{
    return gnTileTypeTable[nId];
}

// build: symbol ?DRLGANIM_TileToClientCoords@* 0x0066D800
void __fastcall DRLGANIM_TileToClientCoords(int* pX, int* pY)
{
    *pY += 1;
    DUNGEON_GameTileToClientCoords(pX, pY);
    *pY += 0x28;
}

// 0x006105F0
D2CommonStormZero6105F0Strc::D2CommonStormZero6105F0Strc() : n0x04(0), n0x08(0), n0x0C(0), n0x10(0), n0x14(0)
{
}

// build: symbol ?IGNORELIST_LinkMappingListNode@List@@QAEXPADH0@Z 0x0060E890
// 0x00610610
D2CommonRecord610610Strc::D2CommonRecord610610Strc(int nValue)
    : f_4(0), f_8(0), nFieldC(0), nField10(0), nField14(0), nField18(nValue)
{
}

// 0x00610630
Node* List::IGNORELIST_NewMappingListNode(int linkType,unsigned extra,unsigned flags)
{
    void* memory=sub_00413020(sizeof(Node)+extra,mappingName,-2,flags|ALLOC_FLAG);
    Node* node=new(memory) Node;
    if(linkType) IGNORELIST_LinkMappingListNode((char*)node,linkType,0);
    return node;
}

// 0x00610690
void D2CommonStormHashTableBStrc::IGNORELIST_InternalDeleteMappingTableNode(D2CommonMappingEntryNodeStrc* pNode)
{
    pNode->~D2CommonMappingEntryNodeStrc();
    SMemFree(pNode, gszTypeNameMappingEntryNode_0074362C, -2, 0);
}

// 0x006106D0
D2CommonMappingEntryNodeStrc* D2CommonStormHashTableBStrc::IGNORELIST_AllocMappingTableNodeInList(D2CommonStormSlotListBStrc* pList, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2CommonMappingEntryNodeStrc) + nExtraBytes, gszTypeNameMappingEntryNode_0074362C, -2, nFlags | 8);
    D2CommonMappingEntryNodeStrc* pNode = new (pMemory) D2CommonMappingEntryNodeStrc;
    pList->LinkNode((char*)pNode, 1, 0);
    return pNode;
}

// 0x00610780
inline void D2CommonStormSlotArrayBStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x006107D0
void D2CommonStormHashTableBStrc::IGNORELIST_DestroyMappingTable()
{
    IGNORELIST_InternalClearMappingTable(1);
    m_fullnessIndicator = 0;
    m_slotmask = 0;
    m_slotlistarray.Clear();
}

// 0x00610800
inline void D2CommonStormHashTableBStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x00610830
void D2CommonStormSlotArrayBStrc::IGNORELIST_ForwardSetMappingSlotArrayCount(unsigned int nCount)
{
    IGNORELIST_SetMappingSlotArrayCount(nCount);
}

// 0x00610840
int D2CommonStormHashTableAStrc::IGNORELIST_MonitorStringTableFullness(unsigned int nSlot)
{
    D2CommonStormSlotListAStrc* const& pListArray = m_slotlistarray.m_data;
    if (m_slotmask >= 0x3FF)
        return 0;
    if (m_fullnessIndicator > 3)
        m_fullnessIndicator -= 3;
    else
        m_fullnessIndicator = 0;
    for (char* pNode = pListArray[nSlot].m_terminator.NextChecked(); (int)pNode > 0;)
    {
        ++m_fullnessIndicator;
        if (m_fullnessIndicator > 13)
        {
            m_fullnessIndicator = 0;
            IGNORELIST_GrowStringTableSlots();
            return 1;
        }
        D2CommonStormSlotListAStrc* pList = &pListArray[nSlot];
        D2CommonStormSlotLinkStrc* pLink = pNode ? (D2CommonStormSlotLinkStrc*)(pNode + pList->m_linkoffset) : &pList->m_terminator;
        pNode = pLink->m_next;
    }
    return 0;
}

// build: symbol ??_7ChatIgnoreList@@6B@ 0x006E6248
// build: symbol ??_7IgnoreList@@6B@ 0x006E62DC
// 0x006108D0
void D2CommonStormHashTableBStrc::IGNORELIST_GrowMappingTableSlots()
{
    unsigned int nOldCount = m_slotmask + 1;
    unsigned int nNewCount = nOldCount * 2;
    D2CommonStormSlotListBStrc tTemp;
    tTemp.ChangeLinkOffset(4);
    for (unsigned int i = 0; i < nOldCount; i++)
    {
        char* pNode;
        while ((pNode = m_slotlistarray.m_data[i].Head()) != 0)
            tTemp.LinkNode(pNode, 2, 0);
    }
    m_slotlistarray.IGNORELIST_SetMappingSlotArrayCount(nNewCount);
    for (unsigned int j = 0; j < nNewCount; j++)
        m_slotlistarray.m_data[j].ChangeLinkOffset(4);
    m_slotmask = nNewCount - 1;
    D2CommonMappingEntryNodeStrc* pNode;
    while ((pNode = (D2CommonMappingEntryNodeStrc*)tTemp.Head()) != 0)
        InternalLinkNode(pNode, pNode->m_hashval);
}

// 0x00610AA0
D2CommonIgnoreListStrc::~IgnoreList()
{
    m_table.IGNORELIST_InternalClearStringTable(0);
    m_table3.IGNORELIST_InternalClearMappingTable(0);
}

// 0x00610B30
D2CommonStormHashTableBStrc::TSHashTable()
{
    m_fullnessIndicator = 0;
    m_fulllist.ChangeLinkOffset(0xC);
    m_slotmask = 3;
    m_slotlistarray.IGNORELIST_SetMappingSlotArrayCount(4);
    for (unsigned int i = 0; i <= m_slotmask; i++)
        m_slotlistarray.m_data[i].ChangeLinkOffset(4);
}

// 0x00610BE0
D2CommonStringEntryNodeStrc* D2CommonStormHashTableAStrc::IGNORELIST_InternalNewStringTableNode(unsigned int nHashVal, const D2StormHashKeyStrIStrc& key, unsigned int nExtraBytes, unsigned int nFlags)
{
    unsigned int nSlot = nHashVal & m_slotmask;
    if (IGNORELIST_MonitorStringTableFullness(nSlot))
        nSlot = nHashVal & m_slotmask;
    D2CommonStringEntryNodeStrc* pNode = IGNORELIST_AllocStringTableNodeInList(&m_slotlistarray[nSlot], nExtraBytes, nFlags);
    m_fulllist.LinkNode((char*)pNode, 2, 0);
    pNode->m_hashval = nHashVal;
    pNode->m_key = key;
    return pNode;
}

// 0x00610CA0
int D2CommonStormHashTableBStrc::IGNORELIST_MonitorMappingTableFullness(unsigned int nSlot)
{
    D2CommonStormSlotListBStrc* const& pListArray = m_slotlistarray.m_data;
    if (m_slotmask >= 0x3FF)
        return 0;
    if (m_fullnessIndicator > 3)
        m_fullnessIndicator -= 3;
    else
        m_fullnessIndicator = 0;
    for (char* pNode = pListArray[nSlot].m_terminator.NextChecked(); (int)pNode > 0;)
    {
        ++m_fullnessIndicator;
        if (m_fullnessIndicator > 13)
        {
            m_fullnessIndicator = 0;
            IGNORELIST_GrowMappingTableSlots();
            return 1;
        }
        D2CommonStormSlotListBStrc* pList = &pListArray[nSlot];
        D2CommonStormSlotLinkStrc* pLink = pNode ? (D2CommonStormSlotLinkStrc*)(pNode + pList->m_linkoffset) : &pList->m_terminator;
        pNode = pLink->m_next;
    }
    return 0;
}

// 0x00610D30
void* D2Object00610D30Strc::sub_00610D30(unsigned int nFlags)
{
    this->~D2Object00610D30Strc();
    if (nFlags & 1)
        operator delete(this);
    return this;
}

// 0x00610D60
D2CommonStringEntryNodeStrc* D2CommonStormHashTableAStrc::IGNORELIST_NewStringTableNode(const char* szKey, unsigned int nExtraBytes, unsigned int nFlags)
{
    D2StormHashKeyStrIStrc key(szKey);
    return IGNORELIST_InternalNewStringTableNode(SStrHash(szKey, 0, 0), key, nExtraBytes, nFlags);
}

// 0x00610DF0
D2CommonMappingEntryNodeStrc* D2CommonStormHashTableBStrc::IGNORELIST_InternalNewMappingTableNode(unsigned int nHashVal, const D2StormHashKeyStrIStrc& key, unsigned int nExtraBytes, unsigned int nFlags)
{
    unsigned int nSlot = nHashVal & m_slotmask;
    if (IGNORELIST_MonitorMappingTableFullness(nSlot))
        nSlot = nHashVal & m_slotmask;
    D2CommonMappingEntryNodeStrc* pNode = IGNORELIST_AllocMappingTableNodeInList(&m_slotlistarray[nSlot], nExtraBytes, nFlags);
    m_fulllist.LinkNode((char*)pNode, 2, 0);
    pNode->m_hashval = nHashVal;
    pNode->m_key = key;
    return pNode;
}

// 0x006114E0
void IGNORELIST_CreateIgnoreList()
{
    gpIgnoreList = ::new (SMemAlloc(sizeof(D2CommonIgnoreListStrc), ".\\Chat\\Ignorelist.cpp", 0x41, 0))
        D2CommonIgnoreListStrc;
}

// 0x00611560
D2CommonIgnoreListStrc* IGNORELIST_GetOrCreateIgnoreList()
{
    if (!gpIgnoreList)
    {
        gpIgnoreList = ::new (SMemAlloc(sizeof(D2CommonIgnoreListStrc), ".\\Chat\\Ignorelist.cpp", 0x48, 0))
            D2CommonIgnoreListStrc;
    }
    return gpIgnoreList;
}

// build: symbol ??3@YAXPAX0@Z 0x0040EB30
// 0x00610F90
int D2CommonIgnoreListStrc::IGNORELIST_AddAlias(const char* szName)
{
    if (!szName || !*szName || !IGNORELIST_IsEnabled() || !*szName)
    {
        return 0;
    }

    if (!m_table2.IGNORELIST_FindStringTableNode(szName))
    {
        m_table2.IGNORELIST_NewStringTableNode(szName, 0, 0);
        char szLine[0x100] = "";
        szLine[0] = '!';
        SStrPack(szLine, szName, sizeof(szLine));
        IGNORELIST_AppendLineToFile(szLine);
    }

    return 1;
}

// 0x00611200
D2CommonIgnoreListStrc::IgnoreList()
{
    m_pFile = 0;
    m_bEnabled = 1;

    char szPath[0x104];
    ERRORMANAGER_GetModuleDirectory(szPath, 0x104);
    SMemZero(szFileName, 0x104);
    char* pSep = (char*)SStrChrR(szPath, 0x5C);
    if (pSep)
        pSep[1] = 0;
    SStrPack(szPath, "ignorelist", 0x104);
    SStrCopy(szFileName, szPath, 0x104);

    unsigned long dwEnabled = 1;
    SRegLoadValue("Diablo II", "Persistent Ignore", 0, &dwEnabled);
    m_bEnabled = dwEnabled;
    IGNORELIST_LoadFromFile();
}

// 0x00611050
void D2CommonIgnoreListStrc::IGNORELIST_LoadFromFile()
{
    _iobuf* pFile = fopen(szFileName, "rt");
    if (!pFile)
    {
        return;
    }

    char szLine[0x100] = "";
    while (fgets(szLine, sizeof(szLine), pFile))
    {
        for (unsigned int i = 0; i < SStrLen(szLine); ++i)
        {
            if (szLine[i] == '\r' || szLine[i] == '\n')
            {
                szLine[i] = '\0';
            }
        }

        if (szLine[0] == '!' && szLine[1])
        {
            m_table2.IGNORELIST_NewStringTableNode(&szLine[1], 0, 0);
        }
        else
        {
            m_table.IGNORELIST_NewStringTableNode(szLine, 0, 0);
        }
    }

    fclose(pFile);
}

// 0x00611170
D2CommonMappingEntryNodeStrc* D2CommonStormHashTableBStrc::IGNORELIST_NewMappingTableNode(const char* szKey, unsigned int nExtraBytes, unsigned int nFlags)
{
    D2StormHashKeyStrIStrc key(szKey);
    return IGNORELIST_InternalNewMappingTableNode(SStrHash(szKey, 0, 0), key, nExtraBytes, nFlags);
}

// 0x00611320
int D2CommonIgnoreListStrc::IGNORELIST_StoreAccountAlias(char* szRaw, int nRawLen)
{
    if (!szRaw || !*szRaw || !IGNORELIST_IsEnabled())
    {
        return 0;
    }

    char szAccount[0x100];
    char szName[0x100];
    SMemZero(szAccount, sizeof(szAccount));
    SMemZero(szName, sizeof(szName));

    unsigned int nStart = 0;
    for (unsigned int i = 0; szRaw[i] && i < nRawLen - 1; ++i)
    {
        if (szRaw[i + 1] == '(')
        {
            nStart = i + 1;
            SMemCopy(szName, szRaw, nStart);
        }

        if (szRaw[i + 1] == ')')
        {
            SMemCopy(szAccount, &szRaw[nStart + 1], i - nStart);
        }

        if (szName[0] && szAccount[0])
        {
            break;
        }
    }

    if (!szName[0] || !szAccount[0])
    {
        return 0;
    }

    D2CommonMappingEntryNodeStrc* pNode = m_table3.IGNORELIST_FindMappingTableNode(szName);
    if (!pNode)
    {
        pNode = m_table3.IGNORELIST_NewMappingTableNode(szName, 0, 0);
    }

    if (pNode->pMapped)
    {
        SMemFree(pNode->pMapped, ".\\Chat\\Ignorelist.cpp", 322, 0);
    }

    char szMapped[0x100] = "";
    szMapped[0] = '*';
    SStrPack(szMapped, szAccount, sizeof(szMapped));
    pNode->pMapped = SStrDup(szMapped);
    return 1;
}

void sub_F45_EmitHashTables(void* pTableA, void* pTableB)
{
    new (pTableA) D2CommonStormHashTableAStrc(0);
    new (pTableB) D2CommonStormHashTableBStrc(0);
}

void sub_F45_EmitSlotArrays(D2CommonStormSlotArrayAStrc* pArrayA, D2CommonStormSlotArrayBStrc* pArrayB)
{
    delete pArrayA;
    delete pArrayB;
}

#include "gen/data/Source/D2Common/Chat/Ignorelist.inc"
