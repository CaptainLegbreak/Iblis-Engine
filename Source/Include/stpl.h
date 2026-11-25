#pragma once
// Storm's list and array templates: an intrusive doubly linked list whose terminator link carries the complemented
// address of the list head, and the base/fixed/growable arrays.

extern "C" void* __stdcall SMemAlloc(unsigned int nBytes, const char* szFile, int nLine, unsigned int nFlags);
extern "C" void* __stdcall SMemReAlloc(void* pLocation, unsigned int nBytes, const char* szFile, int nLine, unsigned int nFlags);
extern "C" int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags);

// The compiler's type descriptor (typeid); only its address is used here.
class type_info
{
public:
    virtual ~type_info();
private:
    void* _m_data;
    char _m_d_name[1];
    type_info(const type_info&);
    type_info& operator=(const type_info&);
};

// The decorated name of T's type descriptor, which the array templates pass to the allocator as the file name.
#define STORM_TYPENAME(T) ((const char*)&typeid(T) + 8)

// The hash tables' key types: no key, and a string key (case-insensitive for HASHKEY_STRI).
class HASHKEY_NONE
{
};

class HASHKEY_STR
{
public:
    char* m_str;
};

class HASHKEY_STRI : public HASHKEY_STR
{
};

class HASHKEY_PTR
{
public:
    void* m_ptr;
};

template<class T> struct TSLink;
template<class T> struct TSLinkedNode;
template<class T> struct TSGetLink;
template<class T> struct TSGetExplicitLink;
template<class T, class TGetLink> struct TSList;
template<class T> struct TSCD;
template<class T> struct TSBaseArray;
template<class T, class TCD> struct TSFixedArray;
template<class T, class TCD> struct TSGrowableArray;

// The link a node embeds. m_next is the next node, or, on the last node, the complemented address of the
// terminator link; a list's terminator link points back at the first node the same way.
template<class T>
struct TSLink
{
    TSLink<T>* m_prevlink;                                  // 0x00
    T* m_next;                                              // 0x04

    TSLink()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    ~TSLink()
    {
        Unlink();
    }
    TSLink<T>* NextLink(int linkoffset)
    {
        if ((int)m_next < 0)
            return (TSLink<T>*)~(unsigned int)m_next;
        if (linkoffset < 0)
            linkoffset = (char*)this - (char*)m_prevlink->m_next;
        return (TSLink<T>*)((char*)m_next + linkoffset);
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
    T* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
    T* Prev()
    {
        return m_prevlink->m_prevlink->Next();
    }
    T* RawNext()
    {
        return m_next;
    }
};

// A node type that embeds its link as m_link (Storm's NODEDECL form).
template<class T>
struct TSLinkedNode
{
    TSLink<T> m_link;                                       // 0x00

    ~TSLinkedNode()
    {
        m_link.Unlink();
    }
    T* Next()
    {
        return m_link.Next();
    }
};

// The link policies: TSGetLink finds a node's link in its m_link member; TSGetExplicitLink uses the list's
// m_linkoffset. Both are __fastcall statics (D2CMP's object emits them out of line: 0x601CF0, 0x601DA0).
template<class T>
struct TSGetLink
{
    static TSLink<T>* __fastcall Link(const T* nodeptr, int linkoffset)
    {
        return &((T*)nodeptr)->m_link;
    }
};

template<class T>
struct TSGetExplicitLink
{
    static TSLink<T>* __fastcall Link(const T* nodeptr, int linkoffset)
    {
        return (TSLink<T>*)((char*)nodeptr + linkoffset);
    }
};

template<class T, class TGetLink = TSGetLink<T> >
struct TSList
{
    int m_linkoffset;                                       // 0x00
    TSLink<T> m_terminator;                                 // 0x04

    TSList()
    {
        m_linkoffset = 0;
        InitializeTerminator();
    }
    TSList(const TSList<T, TGetLink>& source)
    {
        m_linkoffset = source.m_linkoffset;
        InitializeTerminator();
    }
    ~TSList()
    {
        UnlinkAll();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (T*)~(unsigned int)&m_terminator;
    }
    T* Head()
    {
        return m_terminator.Next();
    }
    int IsEmpty()
    {
        return Head() == 0;
    }
    TSLink<T>* Link(const T* ptr)
    {
        return ptr ? TGetLink::Link(ptr, m_linkoffset) : &m_terminator;
    }
    void LinkNode(T* ptr, unsigned int linktype, T* existingptr)
    {
        TSLink<T>* link = Link(ptr);
        link->Unlink();
        TSLink<T>* existinglink = Link(existingptr);
        switch (linktype)
        {
        case 1:
            link->m_prevlink = existinglink;
            link->m_next = existinglink->m_next;
            existinglink->NextLink(m_linkoffset)->m_prevlink = link;
            existinglink->m_next = ptr;
            break;
        default:
            {
                TSLink<T>* prevlink = existinglink->m_prevlink;
                link->m_prevlink = prevlink;
                link->m_next = prevlink->m_next;
                prevlink->m_next = ptr;
                existinglink->m_prevlink = link;
            }
            break;
        }
    }
    T* Next(const T* ptr)
    {
        return Link(ptr)->Next();
    }
    T* RawNext(const T* ptr);
    void UnlinkNode(T* ptr)
    {
        Link(ptr)->Unlink();
    }
    T* NewNode(unsigned int linktype, unsigned int extrabytes, unsigned int flags)
    {
        T* ptr = new (SMemAlloc(sizeof(T) + extrabytes, STORM_TYPENAME(T), -2, flags | 8)) T;
        if (linktype)
            LinkNode(ptr, linktype, 0);
        return ptr;
    }
    void UnlinkAll();
    T* DeleteNode(T* ptr);
    void Clear();
    void SetLinkOffset(int linkoffset)
    {
        m_linkoffset = linkoffset;
        InitializeTerminator();
    }
    void ChangeLinkOffset(int linkoffset)
    {
        if (linkoffset != m_linkoffset)
        {
            UnlinkAll();
            m_linkoffset = linkoffset;
            InitializeTerminator();
        }
    }
};

// Construction/destruction policy of the arrays.
// The arrays' element policy: construct, copy-construct and destruct one element in place.
template<class T>
struct TSCD
{
    static void __fastcall Construct(T* ptr)
    {
        new (ptr) T;
    }
    static void __fastcall CopyConstruct(T* ptr, const T& source)
    {
        new (ptr) T(source);
    }
    static void __fastcall Destruct(T* ptr)
    {
        ptr->~T();
    }
};

template<class T>
struct TSBaseArray
{
    unsigned int m_alloc;                                   // 0x00
    unsigned int m_count;                                   // 0x04
    T* m_data;                                              // 0x08

    TSBaseArray()
    {
        m_alloc = 0;
        m_count = 0;
        m_data = 0;
    }
    unsigned int Count() const
    {
        return m_count;
    }
    T& operator[](unsigned int index)
    {
        return m_data[index];
    }
    T* Ptr()
    {
        return m_data;
    }
};

template<class T, class TCD = TSCD<T> >
struct TSFixedArray : TSBaseArray<T>
{
    ~TSFixedArray()
    {
        for (unsigned int i = 0; i < this->m_count; i++)
            TCD::Destruct(&this->m_data[i]);
        if (this->m_data)
            SMemFree(this->m_data, STORM_TYPENAME(T), -2, 0);
    }
    void ReallocData(unsigned int count)
    {
        this->m_alloc = count;
        if (this->m_data || count)
            this->m_data = (T*)SMemReAlloc(this->m_data, count * sizeof(T), STORM_TYPENAME(T), -2, 0);
    }
    void Set(unsigned int count, const T* data);
    void Clear()
    {
        this->~TSFixedArray();
        this->m_alloc = 0;
        this->m_count = 0;
        this->m_data = 0;
    }
    TSFixedArray<T, TCD>& operator=(const TSFixedArray<T, TCD>& source)
    {
        if (this != &source)
            Set(source.m_count, source.m_data);
        return *this;
    }
};

template<class T, class TCD = TSCD<T> >
struct TSGrowableArray : TSFixedArray<T, TCD>
{
    unsigned int m_chunk;                                   // 0x0C

    TSGrowableArray()
    {
        m_chunk = 0;
    }
    ~TSGrowableArray()
    {
    }
    static unsigned int __stdcall RoundUp(unsigned int value, unsigned int align)
    {
        unsigned int remainder = value % align;
        if (remainder)
            value += align - remainder;
        return value;
    }
    unsigned int CalcChunkSize(unsigned int count)
    {
        enum { MAXCHUNK = 256 / sizeof(T) > 8 ? 256 / sizeof(T) : 8 };
        if (count < MAXCHUNK)
        {
            unsigned int result = count;
            while (result & (result - 1))
                result &= result - 1;
            return result < 1 ? 1 : result;
        }
        m_chunk = MAXCHUNK;
        return MAXCHUNK;
    }
    void ReallocData(unsigned int count);
    void Reserve(unsigned int count, int round)
    {
        count += this->m_count;
        if (count > this->m_alloc)
        {
            if (round)
            {
                unsigned int chunk = m_chunk ? m_chunk : CalcChunkSize(count);
                count = RoundUp(count, chunk);
            }
            ReallocData(count);
        }
    }
    unsigned int Add(unsigned int count, const T* data)
    {
        Reserve(count, 1);
        for (unsigned int i = 0; i < count; i++, data++)
            TCD::CopyConstruct(&this->m_data[this->m_count + i], *data);
        this->m_count += count;
        return this->m_count - count;
    }
    T* New()
    {
        Reserve(1, 1);
        TCD::Construct(&this->m_data[this->m_count]);
        return &this->m_data[this->m_count++];
    }
    void SetCount(unsigned int count)
    {
        if (count > this->m_count)
        {
            if (count > this->m_alloc)
            {
                unsigned int chunk = m_chunk ? m_chunk : CalcChunkSize(count);
                ReallocData(RoundUp(count, chunk));
            }
            for (unsigned int i = this->m_count; i < count; i++)
                TCD::Construct(&this->m_data[i]);
        }
        else if (count < this->m_count)
        {
            for (unsigned int i = count; i < this->m_count; i++)
                TCD::Destruct(&this->m_data[i]);
        }
        this->m_count = count;
    }
    TSGrowableArray<T, TCD>& operator=(const TSGrowableArray<T, TCD>& source)
    {
        if (this != &source)
            this->Set(source.m_count, source.m_data);
        m_chunk = source.m_chunk;
        return *this;
    }
};

template<class T, class TGetLink>
T* TSList<T, TGetLink>::RawNext(const T* ptr)
{
    return Link(ptr)->m_next;
}

template<class T, class TGetLink>
void TSList<T, TGetLink>::UnlinkAll()
{
    while (T* ptr = Head())
        UnlinkNode(ptr);
}

template<class T, class TGetLink>
T* TSList<T, TGetLink>::DeleteNode(T* ptr)
{
    T* next = Next(ptr);
    ptr->~T();
    SMemFree(ptr, STORM_TYPENAME(T), -2, 0);
    return next;
}

template<class T, class TGetLink>
void TSList<T, TGetLink>::Clear()
{
    while (T* ptr = Head())
    {
        ptr->~T();
        SMemFree(ptr, STORM_TYPENAME(T), -2, 0);
    }
}

template<class T, class TCD>
void TSFixedArray<T, TCD>::Set(unsigned int count, const T* data)
{
    ReallocData(count);
    for (unsigned int i = 0; i < count; i++, data++)
        TCD::CopyConstruct(&this->m_data[i], *data);
    this->m_count = count;
}

template<class T, class TCD>
void TSGrowableArray<T, TCD>::ReallocData(unsigned int count)
{
    T* olddata = this->m_data;
    for (unsigned int i = count; i < this->m_count; i++)
        TCD::Destruct(&olddata[i]);
    this->m_alloc = count;
    this->m_data = (T*)SMemReAlloc(olddata, count * sizeof(T), STORM_TYPENAME(T), -2, 0x10);
    if (!this->m_data)
    {
        this->m_data = (T*)SMemAlloc(count * sizeof(T), STORM_TYPENAME(T), -2, 0);
        if (olddata)
        {
            unsigned int copycount = count < this->m_count ? count : this->m_count;
            for (unsigned int i = 0; i < copycount; i++)
            {
                TCD::CopyConstruct(&this->m_data[i], olddata[i]);
                TCD::Destruct(&olddata[i]);
            }
            SMemFree(olddata, STORM_TYPENAME(T), -2, 0);
        }
    }
}
