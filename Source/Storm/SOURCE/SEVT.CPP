#include "Storm.h"
#include "D2GameTypes.h"
#include "D2StormTypes.h"
#include "D2StormLink.h"
#include "stpl.h"

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC214

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC

// A critical section for the whole run: initialized before main, deleted at exit.
struct CCritSect : D2CriticalSectionStrc
{
    CCritSect() { InitializeCriticalSection(this); }
    ~CCritSect() { DeleteCriticalSection(this); }
};

// build: symbol ??__EgtSEvtLock@@YAXXZ 0x006CA920
// build: symbol ??__FgtSEvtLock@@YAXXZ 0x006CB370
CCritSect gtSEvtLock;                                                                           // 0x0077930C

static D2StormEventTypeStrc** gppSEvtTypes_00779300;                                                        // 0x00779300

static unsigned int gnSEvtTypeTableSize_00779304;                                                           // 0x00779304

static unsigned int gnSEvtTypeCount_00779308;                                                               // 0x00779308

static int gbSEvtModified_007792F8;                                                                         // 0x007792F8

void __cdecl operator delete(void* pMemory);                                                                // 0x004053F0

static inline D2StormEventTypeStrc* FindEventType(unsigned int nType, unsigned int nSubType); // 0x00426270

struct BREAKCMD : TSLinkedNode<BREAKCMD>
{
    void* pData;

    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

// build: symbol ??_GBREAKCMD@@QAEPAXI@Z 0x00426E20

struct SEvtBreakCmdStrc;
struct D2CriticalSectionStrc;
struct SEvtLinkStrc;

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);

struct SEvtLinkStrc
{
    SEvtLinkStrc* pPrevLink;
    SEvtBreakCmdStrc* pNext;

    SEvtLinkStrc() { pPrevLink = 0; pNext = 0; }
    SEvtLinkStrc* NextLink(int nLinkOffset = -1)
    {
        if ((int)pNext < 0)
            return (SEvtLinkStrc*)~(unsigned int)pNext;
        if (nLinkOffset < 0)
            nLinkOffset = (int)this - (int)pPrevLink->pNext;
        return (SEvtLinkStrc*)((int)pNext + nLinkOffset);
    }
    void Unlink()
    {
        if (pPrevLink)
        {
            NextLink()->pPrevLink = pPrevLink;
            pPrevLink->pNext = pNext;
            pPrevLink = 0;
            pNext = 0;
        }
    }
};

struct SEvtBreakCmdStrc
{
    SEvtLinkStrc f_0;
    void* pData;
};

void* __stdcall SMemAlloc(unsigned int nSize, const char* szLogName, int nLogLine, unsigned int nFlags); // 0x00413020

#include "gen/data/Source/Storm/SOURCE/SEVT.inc"
// 0x0042B9D0
void __cdecl sub_0042B9D0_Nop()
{
}

// 0x00515110
void __cdecl sub_00515110_Nop()
{
}

// 0x00515EC0
void __cdecl sub_00515EC0_Nop()
{
}

// 0x00515ED0
void __cdecl sub_00515ED0_Nop()
{
}

// 0x0043CBF0
void __cdecl sub_0043CBF0_Nop()
{
}

// 0x00650EA0
void __cdecl sub_00650EA0_Nop()
{
}

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

extern TSList<BREAKCMD> gtSEvtBreakCmdList_007088E8; // 0x007088E8

static long gnSEvtDispatchDepth_007792FC;                                                                   // 0x007792FC

void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0

void __stdcall CopyIdHashTable(_IDHASHTABLE* pDest, _IDHASHTABLE* pSource); // 0x00426180

void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340

int __stdcall SEvtDispatch(unsigned int nType, unsigned int nSubType, unsigned int nId, void* pData);

// 0x00426180
void __stdcall CopyIdHashTable(_IDHASHTABLE* pDest, _IDHASHTABLE* pSource)
{
    pDest->nSize = pSource->nSize;
    pDest->nUsed = pSource->nUsed;
    pDest->ppTable = (D2StormEventHandlerStrc**)SMemAlloc(pDest->nSize * sizeof(D2StormEventHandlerStrc*), gszSEvtCpp, 0x3E, 0);
    for (unsigned int i = 0; i < pSource->nSize; i++)
    {
        D2StormEventHandlerStrc** ppNext = &pDest->ppTable[i];
        for (D2StormEventHandlerStrc* pHandler = pSource->ppTable[i]; pHandler; pHandler = pHandler->pNext)
        {
            *ppNext = (D2StormEventHandlerStrc*)SMemAlloc(sizeof(D2StormEventHandlerStrc), gszSEvtCpp, 0x45, 0);
            SMemCopy(*ppNext, pHandler, sizeof(D2StormEventHandlerStrc));
            ppNext = &(*ppNext)->pNext;
        }
        *ppNext = 0;
    }
}

// 0x00426210
static void __cdecl DeleteHandlerTable(_IDHASHTABLE* pTable)
{
    for (unsigned int i = 0; i < pTable->nSize; i++)
    {
        D2StormEventHandlerStrc* pHandler;
        while ((pHandler = pTable->ppTable[i]) != 0)
        {
            pTable->ppTable[i] = pHandler->pNext;
            SMemFree(pHandler, "delete", -1, 0);
        }
    }
    SMemFree(pTable->ppTable, gszSEvtCpp, 88, 0);
    SMemFree(pTable, "delete", -1, 0);
}

// 0x00426270
static inline D2StormEventTypeStrc* FindEventType(unsigned int nType, unsigned int nSubType)
{
    if (!gppSEvtTypes_00779300 || !gnSEvtTypeTableSize_00779304)
        return 0;
    D2StormEventTypeStrc* pType;
    for (pType = gppSEvtTypes_00779300[(nType ^ nSubType) & (gnSEvtTypeTableSize_00779304 - 1)]; pType; pType = pType->pNext)
        if (pType->nType == nType && pType->nSubType == nSubType)
            break;
    return pType;
}

#define DELETE_TABLE DeleteHandlerTable

// 0x004262B0
int __stdcall SEvtDestroy()
{
    EnterCriticalSection(&gtSEvtLock);
    for (unsigned int i = 0; i < gnSEvtTypeTableSize_00779304; i++)
    {
        D2StormEventTypeStrc* pType;
        while ((pType = gppSEvtTypes_00779300[i]) != 0)
        {
            _IDHASHTABLE* pState;
            while ((pState = pType->pHandlers) != 0)
            {
                pType->pHandlers = pState->pPrevState;
                DELETE_TABLE(pState);
            }
            gppSEvtTypes_00779300[i] = pType->pNext;
            SMemFree(pType, "delete", -1, 0);
        }
    }
    if (gppSEvtTypes_00779300)
        SMemFree(gppSEvtTypes_00779300, "delete", -1, 0);
    gppSEvtTypes_00779300 = 0;
    gnSEvtTypeTableSize_00779304 = 0;
    gnSEvtTypeCount_00779308 = 0;
    gbSEvtModified_007792F8 = 1;
    LeaveCriticalSection(&gtSEvtLock);
    return 1;
}

// 0x00426370
int __stdcall SEvtPushState(unsigned int nType, unsigned int nSubType)
{
    int bResult = 0;
    EnterCriticalSection(&gtSEvtLock);
    D2StormEventTypeStrc* pType = FindEventType(nType, nSubType);
    if (pType)
    {
        _IDHASHTABLE* pState = (_IDHASHTABLE*)SMemAlloc(sizeof(_IDHASHTABLE), gszSEvtCpp, 284, 0);
        CopyIdHashTable(pState, pType->pHandlers);
        pState->pPrevState = pType->pHandlers;
        pType->pHandlers = pState;
        gbSEvtModified_007792F8 = 1;
        bResult = 1;
    }
    LeaveCriticalSection(&gtSEvtLock);
    return bResult;
}

static inline unsigned int CalcTableSize(unsigned int nCount)
{
    unsigned int nSize = 1;
    while (nSize <= nCount * 2 + 2)
        nSize <<= 1;
    return nSize;
}

// 0x00426420
int __stdcall SEvtRegisterHandler(unsigned int nType, unsigned int nSubType, unsigned int nId, unsigned int dwFlags, SEVTHANDLER pfnHandler)
{
    VALIDATEBEGIN;
    VALIDATE(pfnHandler);
    VALIDATE(!dwFlags);
    VALIDATEEND;

    EnterCriticalSection(&gtSEvtLock);
    D2StormEventTypeStrc* pType = FindEventType(nType, nSubType);
    if (!pType)
    {
        if (gnSEvtTypeCount_00779308 >= gnSEvtTypeTableSize_00779304 / 2)
        {
            unsigned int nNewSize = CalcTableSize(gnSEvtTypeCount_00779308);
            D2StormEventTypeStrc** ppNewTypes = (D2StormEventTypeStrc**)SMemAlloc(nNewSize * sizeof(D2StormEventTypeStrc*), gszSEvtCpp, 0x143, 8);
            if (gppSEvtTypes_00779300 && gnSEvtTypeTableSize_00779304)
            {
                for (unsigned int i = 0; i < gnSEvtTypeTableSize_00779304; ++i)
                {
                    D2StormEventTypeStrc* pNext;
                    for (D2StormEventTypeStrc* pCur = gppSEvtTypes_00779300[i]; pCur; pCur = pNext)
                    {
                        const unsigned int nBucket = (pCur->nSubType ^ pCur->nType) & (nNewSize - 1);
                        pNext = pCur->pNext;
                        pCur->pNext = ppNewTypes[nBucket];
                        ppNewTypes[nBucket] = pCur;
                    }
                }
            }
            if (gppSEvtTypes_00779300)
                SMemFree(gppSEvtTypes_00779300, gszSEvtCpp, 0x154, 0);
            gppSEvtTypes_00779300 = ppNewTypes;
            gnSEvtTypeTableSize_00779304 = nNewSize;
        }

        const unsigned int nBucket = (nType ^ nSubType) & (gnSEvtTypeTableSize_00779304 - 1);
        pType = (D2StormEventTypeStrc*)SMemAlloc(sizeof(D2StormEventTypeStrc), gszSEvtCpp, 0x15D, 8);
        pType->nType = nType;
        pType->nSubType = nSubType;
        pType->pHandlers = (_IDHASHTABLE*)SMemAlloc(sizeof(_IDHASHTABLE), gszSEvtCpp, 0x160, 8);
        ++gnSEvtTypeCount_00779308;
        pType->pNext = gppSEvtTypes_00779300[nBucket];
        gppSEvtTypes_00779300[nBucket] = pType;
    }

    if (pType->pHandlers->nUsed >= pType->pHandlers->nSize / 2)
    {
        unsigned int nNewSize;
        for (nNewSize = 1; nNewSize <= pType->pHandlers->nSize * 2 + 2; nNewSize *= 2)
            ;

        D2StormEventHandlerStrc** ppNewTable = (D2StormEventHandlerStrc**)SMemAlloc(nNewSize * sizeof(D2StormEventHandlerStrc*), gszSEvtCpp, 0x16E, 8);
        D2StormEventHandlerStrc*** pppTails = (D2StormEventHandlerStrc***)SMemAlloc(nNewSize * sizeof(D2StormEventHandlerStrc**), gszSEvtCpp, 0x16F, 8);
        for (unsigned int i = 0; i < nNewSize; ++i)
        {
            pppTails[i] = &ppNewTable[i];
        }

        if (pType->pHandlers->ppTable && pType->pHandlers->nSize)
        {
            for (unsigned int i = 0; i < pType->pHandlers->nSize; ++i)
            {
                D2StormEventHandlerStrc* pNext;
                for (D2StormEventHandlerStrc* pCur = pType->pHandlers->ppTable[i]; pCur; pCur = pNext)
                {
                    const unsigned int nBucket = pCur->nId & (nNewSize - 1);
                    pNext = pCur->pNext;
                    pCur->pNext = 0;
                    *pppTails[nBucket] = pCur;
                    pppTails[nBucket] = &pCur->pNext;
                }
            }
        }

        SMemFree(pppTails, gszSEvtCpp, 0x182, 0);
        if (pType->pHandlers->ppTable)
            SMemFree(pType->pHandlers->ppTable, gszSEvtCpp, 0x184, 0);

        pType->pHandlers->ppTable = ppNewTable;
        pType->pHandlers->nSize = nNewSize;
    }

    const unsigned int nBucket = (pType->pHandlers->nSize - 1) & nId;
    D2StormEventHandlerStrc* pHandler = (D2StormEventHandlerStrc*)SMemAlloc(sizeof(D2StormEventHandlerStrc), gszSEvtCpp, 0x18D, 8);
    pHandler->nId = nId;
    pHandler->nSequence = ++pType->nSequence;
    pHandler->pfnHandler = pfnHandler;
    pHandler->pNext = pType->pHandlers->ppTable[nBucket];
    pType->pHandlers->ppTable[nBucket] = pHandler;
    ++pType->pHandlers->nUsed;
    gbSEvtModified_007792F8 = 1;
    LeaveCriticalSection(&gtSEvtLock);
    return nValid ? 1 : 0;
}

// 0x00426720
int __stdcall SEvtUnregisterHandler(unsigned int nType, unsigned int nSubType, unsigned int nId, void* pfnHandler)
{
    int bResult = 0;
    EnterCriticalSection(&gtSEvtLock);
    D2StormEventTypeStrc* pType = FindEventType(nType, nSubType);
    if (pType && pType->pHandlers->ppTable && pType->pHandlers->nSize)
    {
        const unsigned int nKey = nId;
        D2StormEventHandlerStrc** ppNext = &pType->pHandlers->ppTable[nKey & (pType->pHandlers->nSize - 1)];
        while (*ppNext)
        {
            D2StormEventHandlerStrc* p = *ppNext;
            if (p->nId == nKey && (!pfnHandler || p->pfnHandler == pfnHandler))
            {
                *ppNext = p->pNext;
                delete p;
                gbSEvtModified_007792F8 = 1;
                bResult = 1;
                --pType->pHandlers->nUsed;
            }
            else
                ppNext = &p->pNext;
        }
    }
    LeaveCriticalSection(&gtSEvtLock);
    return bResult;
}

// 0x00426810
int __stdcall SEvtUnregisterType(unsigned int nType, unsigned int nSubType)
{
    int bResult = 0;
    EnterCriticalSection(&gtSEvtLock);
    D2StormEventTypeStrc* pType = FindEventType(nType, nSubType);
    if (pType)
    {
        _IDHASHTABLE* pState;
        while ((pState = pType->pHandlers) != 0)
        {
            pType->pHandlers = pState->pPrevState;
            DELETE_TABLE(pState);
        }
        D2StormEventTypeStrc** ppNext = &gppSEvtTypes_00779300[(nType ^ nSubType) & (gnSEvtTypeTableSize_00779304 - 1)];
        while (*ppNext)
        {
            D2StormEventTypeStrc* p = *ppNext;
            if (p == pType)
            {
                *ppNext = p->pNext;
                delete p;
                gnSEvtTypeCount_00779308 -= 1;
            }
            else
                ppNext = &p->pNext;
        }
        gbSEvtModified_007792F8 = 1;
        bResult = 1;
    }
    LeaveCriticalSection(&gtSEvtLock);
    return bResult;
}

#define UNREGISTER_TYPE SEvtUnregisterType

// 0x004269C0
int __stdcall SEvtPopState(unsigned int nType, unsigned int nSubType)
{
    int bResult = 0;
    EnterCriticalSection(&gtSEvtLock);
    D2StormEventTypeStrc* pType = FindEventType(nType, nSubType);
    if (pType)
    {
        _IDHASHTABLE* pState = pType->pHandlers;
        _IDHASHTABLE* pPrev = pState->pPrevState;
        if (!pPrev)
            bResult = UNREGISTER_TYPE(nType, nSubType);
        else
        {
            DELETE_TABLE(pState);
            pType->pHandlers = pPrev;
        }
    }
    gbSEvtModified_007792F8 = 1;
    LeaveCriticalSection(&gtSEvtLock);
    return bResult;
}

// The break-command list's other pieces. Their own types are not known yet, so they sit on placeholder
// list and link types.
struct D2SEvtPairStrc
{
    int nFirst;
    int nSecond;
};

struct D2SEvtListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(D2StormLinkStrc* pNode)
    {
        return pNode ? pNode : &m_terminator;
    }
    D2StormLinkStrc* sub_00426AE0_Link(D2StormLinkStrc* pNode);
    char* sub_00426BB0_Next(D2StormLinkStrc* pNode);
    void sub_00426C10_UnlinkNode(D2StormLinkStrc* pNode);
};

struct D2SEvtUnlinkStrc : D2StormLinkStrc
{
    void sub_00426BD0();
};

struct D2SEvtCtorLinkStrc
{
    D2SEvtCtorLinkStrc* m_prevlink;
    char* m_next;

    D2SEvtCtorLinkStrc();
};

struct D2SEvtAutoLinkStrc : D2StormLinkStrc
{
    ~D2SEvtAutoLinkStrc()
    {
        Unlink();
    }
};

// 0x00426900
char* __fastcall sub_00426900_Next(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x00426910
char* __fastcall sub_00426910_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

// 0x00426920
void __fastcall sub_00426920(D2SEvtPairStrc* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x00426930
D2StormLinkStrc* D2StormLinkStrc::sub_00426930_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x004269A0
void __fastcall sub_004269A0_InitTerminator(D2SEvtListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x004269B0
extern "C" void* __fastcall sub_004269B0(void* value)
{
    return value;
}

// 0x00426A60
char* D2ChatStormListAStrc::IGNORELIST_GetStringListHead()
{
    return m_terminator.MaskNext();
}

// 0x00426A70
D2SEvtCtorLinkStrc::D2SEvtCtorLinkStrc() : m_prevlink(0), m_next(0)
{
}

// 0x00426AC0
void D2ChatStormListAStrc::IGNORELIST_ResetStringList()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x00426AE0
D2StormLinkStrc* D2SEvtListStrc::sub_00426AE0_Link(D2StormLinkStrc* pNode)
{
    return Link(pNode);
}

// 0x00426BB0
char* D2SEvtListStrc::sub_00426BB0_Next(D2StormLinkStrc* pNode)
{
    return Link(pNode)->Next();
}

// 0x00426BD0
void D2SEvtUnlinkStrc::sub_00426BD0()
{
    Unlink();
}

// 0x00426C10
void D2SEvtListStrc::sub_00426C10_UnlinkNode(D2StormLinkStrc* pNode)
{
    Link(pNode)->Unlink();
}

// 0x00426C60
D2ChatStormListCStrc::D2ChatStormListCStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x00426E80
int __stdcall SEvtBreakHandlerChain(void* pData)
{
    EnterCriticalSection(&gtSEvtLock);
    BREAKCMD* pCmd = gtSEvtBreakCmdList_007088E8.NewNode(2, 0, 0);
    pCmd->pData = pData;
    LeaveCriticalSection(&gtSEvtLock);
    return 1;
}

// 0x00426F90
int __stdcall SEvtDispatch(unsigned int nType, unsigned int nSubType, unsigned int nId, void* pData)
{
    InterlockedIncrement(&gnSEvtDispatchDepth_007792FC);
    int bResult = 0;
    unsigned int nMinSequence = 0xFFFFFFFF;
    D2StormEventHandlerStrc* pHandler = 0;
    do
    {
        EnterCriticalSection(&gtSEvtLock);

        int bBreak = 0;
        {
            int nDelete = 0;
            BREAKCMD* pHead = gtSEvtBreakCmdList_007088E8.Head();
            BREAKCMD* pNode = pHead;
            while ((int)pNode > 0)
            {
                if (pNode->pData == pData)
                {
                    bBreak = 1;
                    nDelete = -12;
                }
                if (nDelete)
                {
                    BREAKCMD* pNext = gtSEvtBreakCmdList_007088E8.Next(pNode);
                    pNode->~BREAKCMD();
                    SMemFree(pNode, STORM_TYPENAME(BREAKCMD), -2, 0);
                    pNode = (nDelete > 0) ? pNext : 0;
                    nDelete = 0;
                }
                else
                    pNode = pNode->m_link.m_next;
            }
        }

        if (bBreak)
        {
            LeaveCriticalSection(&gtSEvtLock);
            break;
        }

        if (!pHandler || gbSEvtModified_007792F8)
        {
            pHandler = 0;
            D2StormEventTypeStrc* pType = FindEventType(nType, nSubType);
            if (pType && pType->pHandlers->ppTable && pType->pHandlers->nSize)
            {
                for (pHandler = pType->pHandlers->ppTable[(pType->pHandlers->nSize - 1) & nId]; pHandler; pHandler = pHandler->pNext)
                {
                    if (pHandler->nId == nId && pHandler->nSequence < nMinSequence)
                        break;
                }

                if (gnSEvtDispatchDepth_007792FC == 1)
                    gbSEvtModified_007792F8 = 0;
            }
        }

        SEVTHANDLER pfnHandler = 0;
        if (pHandler)
        {
            nMinSequence = pHandler->nSequence;
            pfnHandler = pHandler->pfnHandler;
            do
            {
                pHandler = pHandler->pNext;
            }
            while (pHandler && pHandler->nId != nId);
        }

        LeaveCriticalSection(&gtSEvtLock);

        if (pfnHandler)
        {
            bResult = 1;
            pfnHandler(pData);
        }
    }
    while (pHandler);

    InterlockedDecrement(&gnSEvtDispatchDepth_007792FC);

    if (gtSEvtBreakCmdList_007088E8.m_terminator.Next())
    {
        EnterCriticalSection(&gtSEvtLock);
        BREAKCMD* pHead = gtSEvtBreakCmdList_007088E8.Head();
        BREAKCMD* pNode = pHead;
        while ((int)pNode > 0)
        {
            if (pNode->pData == pData)
                pNode = gtSEvtBreakCmdList_007088E8.DeleteNode(pNode);
            else
                pNode = gtSEvtBreakCmdList_007088E8.RawNext(pNode);
        }
        LeaveCriticalSection(&gtSEvtLock);
    }

    return bResult;
}

// Link holders of the run whose types are not known yet: each constructor zeroes, each destructor unlinks.
struct sub_00426960
{
    D2StormLinkStrc tLink;
    ~sub_00426960();
};

struct sub_00426A80
{
    D2StormLinkStrc tLink;
    ~sub_00426A80();
};

struct sub_00426CA0
{
    D2StormLinkStrc tLink;
    sub_00426CA0();
};

struct sub_00426CB0
{
    D2StormLinkStrc tLink;
    ~sub_00426CB0();
};

struct sub_00426D70
{
    D2StormLinkStrc tLink;
    sub_00426D70();
};

struct sub_00426D80
{
    D2StormLinkStrc tLink;
    ~sub_00426D80();
};

// 0x00426960
sub_00426960::~sub_00426960()
{
    tLink.Unlink();
}

// 0x00426A80
sub_00426A80::~sub_00426A80()
{
    tLink.Unlink();
}

// 0x00426CA0
sub_00426CA0::sub_00426CA0()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
}

// 0x00426CB0
sub_00426CB0::~sub_00426CB0()
{
    tLink.Unlink();
}

// 0x00426D70
sub_00426D70::sub_00426D70()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
}

// 0x00426D80
sub_00426D80::~sub_00426D80()
{
    tLink.Unlink();
}

// build: symbol ??_R0?AUBREAKCMD@@@8 0x007088D0
// build: symbol _SMemAlloc@16 0x00413020
// build: symbol _SMemFree@16 0x00412650
// build: symbol ?LinkNode@?$TSList@UBREAKCMD@@U?$TSGetLink@UBREAKCMD@@@@@@QAEXPAUBREAKCMD@@I0@Z 0x00426B00
// build: symbol ?RawNext@?$TSList@UBREAKCMD@@U?$TSGetLink@UBREAKCMD@@@@@@QAEPAUBREAKCMD@@PBU2@@Z 0x00426C80
// build: symbol ?UnlinkAll@?$TSList@UBREAKCMD@@U?$TSGetLink@UBREAKCMD@@@@@@QAEXXZ 0x00426CF0
// build: symbol ??1?$TSList@UBREAKCMD@@U?$TSGetLink@UBREAKCMD@@@@@@QAE@XZ 0x00426D30
// build: symbol ?NewNode@?$TSList@UBREAKCMD@@U?$TSGetLink@UBREAKCMD@@@@@@QAEPAUBREAKCMD@@III@Z 0x00426DC0
// build: symbol ?DeleteNode@?$TSList@UBREAKCMD@@U?$TSGetLink@UBREAKCMD@@@@@@QAEPAUBREAKCMD@@PAU2@@Z 0x00426F20
template TSList<BREAKCMD>::~TSList();
template BREAKCMD* TSList<BREAKCMD>::DeleteNode(BREAKCMD*);
template BREAKCMD* TSList<BREAKCMD>::RawNext(const BREAKCMD*);

// build: symbol ??__EgtSEvtBreakCmdList_007088E8@@YAXXZ 0x006CA900
// build: symbol ??__FgtSEvtBreakCmdList_007088E8@@YAXXZ 0x006CB380
TSList<BREAKCMD> gtSEvtBreakCmdList_007088E8; // 0x007088E8
