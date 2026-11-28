#pragma once
// Storm: memory manager heaps and blocks, error reports, archive headers and event dispatch records.

#include "D2Check.h"
#include "D2Structs.h"

struct D2SMemBlockSigStrc;
struct D2SMemBlockStrc;
struct D2SMemLargeHeaderStrc;
struct D2SMemHeapStrc;
struct D2ErrorReportStrc;
struct D2StormMpqHeaderStrc;
struct D2StormHashEntryStrc;
struct D2StormArrayViewStrc;
struct D2StormEventHandlerStrc;
struct _IDHASHTABLE;
struct D2StormEventTypeStrc;

typedef void (__stdcall* D2ErrorCallback)(D2ErrorReportStrc*);
typedef void (__stdcall* SEVTHANDLER)(void* pData);

struct D2SMemBlockSigStrc
{
    unsigned short wHeapHigh; // 0x00
    unsigned short wMagic; // 0x02
};

struct D2SMemBlockStrc
{
    unsigned short bytes; // 0x00
    unsigned char nPadding; // 0x02
    unsigned char flags; // 0x03
    union
    {
        D2SMemBlockSigStrc tSig; // 0x04
        D2SMemBlockStrc* pNextFree; // 0x04
    };
};

struct D2SMemLargeHeaderStrc
{
    unsigned int nSize; // 0x00
    D2SMemBlockStrc* pBlock; // 0x04
    D2SMemBlockStrc tBlock; // 0x08
};

struct D2SMemHeapStrc
{
    D2SMemHeapStrc* pNext; // 0x00
    unsigned int dwId; // 0x04
    int nLockIndex; // 0x08
    D2SMemBlockSigStrc tSig; // 0x0C
    int bReportLeak; // 0x10
    int nBlocks; // 0x14
    unsigned int nUsedBytes; // 0x18
    D2SMemBlockStrc* pFirst; // 0x1C
    D2SMemBlockStrc* pEnd; // 0x20
    unsigned int nFragments; // 0x24
    unsigned int nPageSize; // 0x28
    unsigned int nCommitted; // 0x2C
    unsigned int nReserved; // 0x30
    unsigned int nLargeBytes; // 0x34
    D2SMemBlockStrc* apFree[9]; // 0x38
    int nLine; // 0x5C
    char szFile[4]; // 0x60
};

struct D2ErrorReportStrc
{
    unsigned int error; // 0x00
    const char* context; // 0x04
    const char* message; // 0x08
    D2ErrorCallback callback; // 0x0C
};

struct D2StormMpqHeaderStrc
{
    unsigned int dwSignature; // 0x00
    unsigned int nHeaderSize; // 0x04
    unsigned int nArchiveSize; // 0x08
    unsigned short wVersion; // 0x0C
    unsigned char nSectorShift; // 0x0E
    unsigned char unused0x0F; // 0x0F
    unsigned int nHashOffset; // 0x10
    unsigned int nBlockOffset; // 0x14
    unsigned int nHashEntries; // 0x18
    unsigned int nBlockEntries; // 0x1C
};

struct D2StormHashEntryStrc
{
    unsigned int nName1; // 0x00
    unsigned int nName2; // 0x04
    unsigned short wLocale; // 0x08
    unsigned char nPlatform; // 0x0A
    unsigned char nReserved; // 0x0B
    int nBlockIndex; // 0x0C
};

struct D2StormArrayViewStrc
{
    const unsigned int* pData; // 0x00
    unsigned int nCount; // 0x04
};

struct D2StormEventHandlerStrc
{
    unsigned int nId; // 0x00
    unsigned int nSequence; // 0x04
    SEVTHANDLER pfnHandler; // 0x08
    D2StormEventHandlerStrc* pNext; // 0x0C
};

struct _IDHASHTABLE
{
    D2StormEventHandlerStrc** ppTable; // 0x00
    unsigned int nSize; // 0x04
    int nUsed; // 0x08
    _IDHASHTABLE* pPrevState; // 0x0C
};

struct D2StormEventTypeStrc
{
    unsigned int nType; // 0x00
    unsigned int nSubType; // 0x04
    unsigned int nSequence; // 0x08
    _IDHASHTABLE* pHandlers; // 0x0C
    D2StormEventTypeStrc* pNext; // 0x10
};

struct SMSGHANDLER_PARAMS
{
    void* hWnd; // 0x00
    unsigned int uMessage; // 0x04
    union
    {
        unsigned int wParam; // 0x08
        struct
        {
            unsigned short wParamLow; // 0x08
            unsigned short wParamHigh; // 0x0A
        };
    };
    union
    {
        unsigned int lParam; // 0x0C
        struct
        {
            unsigned short nXpos; // 0x0C
            unsigned short nYpos; // 0x0E
        };
    };
    unsigned int dwCommandSource; // 0x10
    unsigned int dwArg; // 0x14
    int bReturn; // 0x18
    int lResult; // 0x1C
};

D2_CHECK_SIZE(SMSGHANDLER_PARAMS, 0x20);
D2_CHECK_SIZE(D2SMemBlockSigStrc, 0x4);
D2_CHECK_SIZE(D2SMemBlockStrc, 0x8);
D2_CHECK_SIZE(D2SMemLargeHeaderStrc, 0x10);
D2_CHECK_SIZE(D2SMemHeapStrc, 0x64);
D2_CHECK_SIZE(D2ErrorReportStrc, 0x10);
D2_CHECK_SIZE(D2StormMpqHeaderStrc, 0x20);
D2_CHECK_SIZE(D2StormHashEntryStrc, 0x10);
D2_CHECK_SIZE(D2StormArrayViewStrc, 0x8);
D2_CHECK_SIZE(D2StormEventHandlerStrc, 0x10);
D2_CHECK_SIZE(_IDHASHTABLE, 0x10);
D2_CHECK_SIZE(D2StormEventTypeStrc, 0x14);
