#pragma once
// D2CMP's cel lists (CELLIST, 0x38 B, named by its type descriptor at 0x741F24) and their cel entries (TCELENTRY,
// 0x741F0C), with the Storm hash-table types the cel compressor keeps its lists in (descriptors 0x741F3C-0x742070).

#include "stplhash.h"
#include "CCritSect.h"

struct HCELLIST__;
struct HLOCKEDCELLIST__;

// One image added to a cel list (CelCompressAddImage).
struct TCELENTRY : TSLinkedNode<TCELENTRY>
{
    int nArg8;                                              // 0x08
    unsigned int nHeight;                                   // 0x0C
    unsigned int nWidth;                                    // 0x10
    unsigned int nSize;                                     // 0x14
    int nArg6;                                              // 0x18
    int nArg7;                                              // 0x1C
    void* pData;                                            // 0x20
};

// A cel list under construction: its format, its directions and the images added so far.
struct CELLIST : TSHashObject<CELLIST, HASHKEY_NONE>
{
    unsigned int dwFlags;                                   // 0x18
    int nType;                                              // 0x1C
    int nData;                                              // 0x20
    unsigned int nCount;                                    // 0x24
    unsigned int nDirections;                               // 0x28
    TSList<TCELENTRY, TSGetLink<TCELENTRY> > tList;         // 0x2C
};

typedef TSList<TCELENTRY, TSGetLink<TCELENTRY> > D2CelEntryList;
typedef TSExplicitList<CELLIST, STORM_EXPLICIT_LIST_UNSET> D2CelListList;
typedef TSHashObjectChunk<CELLIST, HASHKEY_NONE> D2CelListChunk;
typedef TSHashTable<CELLIST, HASHKEY_NONE> D2CelListTable;
typedef TSHashTableReuse<CELLIST, HASHKEY_NONE, 0> D2CelListReuseTable;
typedef TSExportTableSimple<CELLIST, HCELLIST__*, 0> D2CelListExportTable;
typedef TSExportTableSync<CELLIST, HCELLIST__*, HLOCKEDCELLIST__*, CCritSect, 0> D2CelListSyncTable;
