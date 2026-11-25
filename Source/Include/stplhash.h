#pragma once
// Storm's hash-table templates: the hash object a node derives from, the hash table, the reusing table that
// allocates nodes in chunks, and the export tables built on it. Kept apart from stpl.h's lists and arrays.

#include "stpl.h"

// A list whose nodes keep their link at an offset the list stores; STORM_EXPLICIT_LIST_UNSET marks a list whose
// offset is set at run time (ChangeLinkOffset).
#define STORM_EXPLICIT_LIST_UNSET ((int)0xDDDDDDDD)

template<class T, int linkoffset>
class TSExplicitList : public TSList<T, TSGetExplicitLink<T> >
{
public:
    TSExplicitList()
    {
        this->SetLinkOffset(linkoffset);
    }
    ~TSExplicitList()
    {
    }
};

// The hash tables' nodes: a node derives from TSHashObject and is linked into its slot's list and the table's
// full list.
template<class T, class KEY>
struct TSHashObject
{
    unsigned int m_hashval;                                 // 0x00
    TSLink<T> m_linktoslot;                                 // 0x04
    TSLink<T> m_linktofull;                                 // 0x0C
    KEY m_key;                                              // 0x14

    TSHashObject()
    {
    }
    TSHashObject(const TSHashObject<T, KEY>&)
    {
    }
};

// A block of nodes a reusing hash table allocates at once, linked into the table's chunk list.
template<class T, class KEY>
class TSHashObjectChunk
{
public:
    TSGrowableArray<T> m_array;                             // 0x00
    TSLink<TSHashObjectChunk<T, KEY> > m_link;              // 0x10

    ~TSHashObjectChunk()
    {
    }
};

// The hash table: every node is on the full list and on the list of its slot (hash value & m_slotmask).
template<class T, class KEY>
class TSHashTable
{
public:
    TSExplicitList<T, STORM_EXPLICIT_LIST_UNSET> m_fulllist;                         // 0x04
    unsigned int m_fullnessIndicator;                                                // 0x10
    TSGrowableArray<TSExplicitList<T, STORM_EXPLICIT_LIST_UNSET> > m_slotlistarray;  // 0x14
    unsigned int m_slotmask;                                                         // 0x24

    TSHashTable()
    {
        m_fullnessIndicator = 0;
        m_fulllist.ChangeLinkOffset((int)&((T*)0)->m_linktofull);
        m_slotmask = 3;
        m_slotlistarray.SetCount(4);
        for (unsigned int i = 0; i <= m_slotmask; i++)
            m_slotlistarray[i].ChangeLinkOffset((int)&((T*)0)->m_linktoslot);
    }
    virtual void InternalDelete(T* ptr)
    {
        ptr->~T();
        SMemFree(ptr, STORM_TYPENAME(T), -2, 0);
    }
    virtual T* InternalNew(TSExplicitList<T, STORM_EXPLICIT_LIST_UNSET>* listptr, unsigned int extrabytes, unsigned int flags)
    {
        T* ptr = new (SMemAlloc(sizeof(T) + extrabytes, STORM_TYPENAME(T), -2, flags | 8)) T;
        listptr->LinkNode(ptr, 1, 0);
        return ptr;
    }
    virtual ~TSHashTable()
    {
        InternalClear(1);
    }
    virtual void Destroy()
    {
        InternalClear(1);
        m_fullnessIndicator = 0;
        m_slotmask = 0;
        m_slotlistarray.Clear();
    }
    void Clear()
    {
        InternalClear(0);
    }
    void Initialize()
    {
        m_slotmask = 3;
        m_slotlistarray.SetCount(4);
        for (unsigned int i = 0; i <= m_slotmask; i++)
            m_slotlistarray[i].ChangeLinkOffset((int)&((T*)0)->m_linktoslot);
    }
    unsigned int ComputeSlot(unsigned int hashval)
    {
        return m_slotmask & hashval;
    }
    T* InternalFind(unsigned int hashval, const KEY& key);
    int MonitorFullness(unsigned int slot);
    void GrowListArray();
    T* New(unsigned int hashval, const KEY& key, unsigned int extrabytes, unsigned int flags);
    void Unlink(T* ptr)
    {
        if (ptr->m_linktoslot.m_next)
        {
            ptr->m_linktoslot.Unlink();
            ptr->m_linktofull.Unlink();
        }
    }
    void Delete(T* ptr)
    {
        Unlink(ptr);
        InternalDelete(ptr);
    }
    void InternalClear(int warn);
};

template<class T, class KEY>
void TSHashTable<T, KEY>::InternalClear(int warn)
{
    m_fullnessIndicator = 0;
    m_fulllist.UnlinkAll();
    for (unsigned int i = 0; i < m_slotlistarray.Count(); i++)
    {
        while (T* ptr = m_slotlistarray[i].Head())
        {
            if (warn)
                m_slotlistarray[i].UnlinkNode(ptr);
            else
                InternalDelete(ptr);
        }
    }
}

template<class T, class KEY>
T* TSHashTable<T, KEY>::InternalFind(unsigned int hashval, const KEY& key)
{
    T* head = m_slotlistarray[hashval & m_slotmask].Head();
    for (T* ptr = head; (int)ptr > 0; ptr = m_slotlistarray[hashval & m_slotmask].RawNext(ptr))
    {
        if (ptr->m_hashval == hashval)
            return ptr;
    }
    return 0;
}

template<class T, class KEY>
int TSHashTable<T, KEY>::MonitorFullness(unsigned int slot)
{
    if (m_slotmask >= 0x3FF)
        return 0;
    if (m_fullnessIndicator > 3)
        m_fullnessIndicator -= 3;
    else
        m_fullnessIndicator = 0;
    for (T* ptr = m_slotlistarray[slot].Head(); (int)ptr > 0; ptr = m_slotlistarray[slot].RawNext(ptr))
    {
        if (++m_fullnessIndicator > 13)
        {
            m_fullnessIndicator = 0;
            GrowListArray();
            return 1;
        }
    }
    return 0;
}

template<class T, class KEY>
void TSHashTable<T, KEY>::GrowListArray()
{
    unsigned int oldcount = m_slotmask + 1;
    unsigned int newcount = 2 * oldcount;
    TSExplicitList<T, STORM_EXPLICIT_LIST_UNSET> templist;
    templist.ChangeLinkOffset((int)&((T*)0)->m_linktoslot);
    for (unsigned int i = 0; i < oldcount; i++)
    {
        while (T* ptr = m_slotlistarray[i].Head())
            templist.LinkNode(ptr, 2, 0);
    }
    m_slotlistarray.SetCount(newcount);
    for (unsigned int i = 0; i < newcount; i++)
        m_slotlistarray[i].ChangeLinkOffset((int)&((T*)0)->m_linktoslot);
    m_slotmask = newcount - 1;
    while (T* ptr = templist.Head())
        m_slotlistarray[ptr->m_hashval & m_slotmask].LinkNode(ptr, 2, 0);
}

template<class T, class KEY>
T* TSHashTable<T, KEY>::New(unsigned int hashval, const KEY& key, unsigned int extrabytes, unsigned int flags)
{
    unsigned int slot = hashval & m_slotmask;
    if (MonitorFullness(slot))
        slot = hashval & m_slotmask;
    T* ptr = InternalNew(&m_slotlistarray[slot], extrabytes, flags);
    m_fulllist.LinkNode(ptr, 2, 0);
    ptr->m_hashval = hashval;
    return ptr;
}

// The hash table that keeps freed nodes for reuse and allocates nodes in chunks.
template<class T, class KEY, int REUSE>
class TSHashTableReuse : public TSHashTable<T, KEY>
{
public:
    TSExplicitList<T, STORM_EXPLICIT_LIST_UNSET> m_reuseList;                        // 0x28
    unsigned int m_chunkSize;                                                        // 0x34
    TSExplicitList<TSHashObjectChunk<T, KEY>, 0x10> m_chunkList;                     // 0x38

    TSHashTableReuse()
    {
        m_chunkSize = 0x10;
        m_reuseList.ChangeLinkOffset((int)&((T*)0)->m_linktoslot);
    }
    virtual void InternalDelete(T* ptr)
    {
        ptr->~T();
        SMemFree(ptr, STORM_TYPENAME(T), -2, 0);
    }
    virtual T* InternalNew(TSExplicitList<T, STORM_EXPLICIT_LIST_UNSET>* listptr, unsigned int extrabytes, unsigned int flags)
    {
        T* ptr = new (SMemAlloc(sizeof(T) + extrabytes, STORM_TYPENAME(T), -2, flags | 8)) T;
        listptr->LinkNode(ptr, 1, 0);
        return ptr;
    }
    virtual ~TSHashTableReuse()
    {
        DeleteChunksAndReuse();
    }
    virtual void Destroy()
    {
        this->InternalClear(0);
        DeleteChunksAndReuse();
    }
    void DeleteChunksAndReuse()
    {
        m_chunkList.Clear();
        m_reuseList.Clear();
    }
};

// The export tables: a reusing hash table of objects handed out by handle; the sync form guards the table with
// a lock of type TSYNC.
template<class T, class THANDLE, int CHUNKSIZE>
class TSExportTableSimple : public TSHashTableReuse<T, HASHKEY_NONE, CHUNKSIZE>
{
public:
    HASHKEY_NONE m_key;                                     // 0x44
    unsigned int m_sequence;                                // 0x48
    int m_wrapped;                                          // 0x4C

    TSExportTableSimple()
    {
        m_sequence = ~(unsigned int)this & 0x0FFFFFFF;
        m_wrapped = 0;
    }
    THANDLE GenerateHandle();
    T* Ptr(THANDLE handle)
    {
        return this->InternalFind((unsigned int)handle, m_key);
    }
    T* NewHandle(THANDLE* handleptr)
    {
        THANDLE handle = GenerateHandle();
        *handleptr = handle;
        return this->New((unsigned int)handle, m_key, 0, 0);
    }
    void Delete(T* ptr)
    {
        this->Unlink(ptr);
        this->InternalDelete(ptr);
    }
};

template<class T, class THANDLE, int CHUNKSIZE>
THANDLE TSExportTableSimple<T, THANDLE, CHUNKSIZE>::GenerateHandle()
{
    for (;;)
    {
        ++m_sequence;
        if (!m_sequence)
        {
            m_wrapped = 1;
            continue;
        }
        if (!m_wrapped || !this->InternalFind(m_sequence, m_key))
            break;
    }
    return (THANDLE)m_sequence;
}

template<class T, class THANDLE, class TLOCKEDHANDLE, class TSYNC, int CHUNKSIZE>
class TSExportTableSync : public TSExportTableSimple<T, THANDLE, CHUNKSIZE>
{
public:
    TSYNC m_sync;                                           // 0x50

    TSExportTableSync()
    {
    }
    void SyncEnterLock(TLOCKEDHANDLE* lockedhandle, int forwriting)
    {
        m_sync.Enter();
        *lockedhandle = forwriting ? (TLOCKEDHANDLE)1 : (TLOCKEDHANDLE)-1;
    }
    void SyncLeaveLock(TLOCKEDHANDLE lockedhandle)
    {
        if (lockedhandle)
            m_sync.Leave();
    }
    int IsWriteLock(TLOCKEDHANDLE lockedhandle)
    {
        return lockedhandle == (TLOCKEDHANDLE)1;
    }
    T* Lock(THANDLE handle, TLOCKEDHANDLE* lockedhandle, int forwriting)
    {
        SyncEnterLock(lockedhandle, forwriting);
        T* ptr = this->Ptr(handle);
        if (!ptr)
        {
            SyncLeaveLock(*lockedhandle);
            *lockedhandle = 0;
        }
        return ptr;
    }
    void Unlock(TLOCKEDHANDLE lockedhandle)
    {
        SyncLeaveLock(lockedhandle);
    }
    T* NewLock(THANDLE* handleptr, TLOCKEDHANDLE* lockedhandle)
    {
        SyncEnterLock(lockedhandle, 1);
        return this->NewHandle(handleptr);
    }
    void DeleteUnlock(T* ptr, TLOCKEDHANDLE lockedhandle)
    {
        this->Delete(ptr);
        SyncLeaveLock(lockedhandle);
    }
};
