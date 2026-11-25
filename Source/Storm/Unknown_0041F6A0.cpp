#include "Storm.h"
#include "D2GameTypes.h"
#include "D2StormLink.h"

struct HWND__;
struct D2StormLinkStrc;
struct D2StormNodeListStrc;
struct HUFFNODE;
struct CHuffman;
class TOutputStream;
class THuffmannTree;
struct D2CriticalSectionStrc;
struct D2SLogStrc;
struct D2Field14Strc;
struct D2UnitStrc;
struct D2StormByteArrayStrc;
struct D2StormFixedArrayAStrc;
struct D2StormFixedArrayBStrc;
struct D2StormFixedUIntArrayStrc;
struct D2StormFixedUCharArrayStrc;
struct D2StormGrowUIntArrayStrc;
struct D2StormGrowUCharArrayStrc;
struct D2StormArrayBStrc;
struct D2StormNodeListStrc
{
    int nLinkOffset;
    D2StormLinkStrc terminator;
    void __thiscall sub_0041EE40_UnlinkAll(); // 0x0041EE40
    inline void Clear()
    {
        sub_0041EE40_UnlinkAll();
        terminator.Unlink();
    }
};

struct HUFFNODE
{
    D2StormLinkStrc link;
    unsigned int nValue, nWeight;
    HUFFNODE* pParent;
    HUFFNODE* pChild;
};

struct CHuffman
{
    int unk_00[2];
    HUFFNODE items[515];
    D2StormNodeListStrc listA;
    D2StormNodeListStrc listB;
};

void __fastcall sub_0041EE90_DestroyItem(void* pItem); // 0x0041EE90
void __stdcall sub_00686AD1_DestroyArray(void* pArray, unsigned int nSize, int nCount, void (__fastcall* pDestroy)(void*)); // 0x00686AD1

class TOutputStream
{
public:
    TOutputStream(void* pvOutBuffer, unsigned int cbOutLength);                                             // 0x0041D920

    unsigned char* pbOutBuffer;
    unsigned int cbOutSize;
    unsigned char* pbOutPos;
    unsigned int BitBuffer;
    unsigned int BitCount;
};

class THuffmannTree
{
public:
    THuffmannTree();                                                                                        // 0x0041F4A0
    ~THuffmannTree();                                                                                       // 0x0041F6A0
    unsigned int Compress(TOutputStream* os, void* pvInBuffer, int cbInBuffer, unsigned char nCmpType);    // 0x0041F850

    unsigned int adwData[0x3474 / 4];
};

typedef int (__stdcall* SMSGHANDLER)(void* pParams);

struct D2StormByteArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    char* m_data;
    unsigned int m_chunk;

    char* sub_00421010_Ptr();
};

struct D2StormFixedArrayAStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned int* m_data;

    unsigned int* sub_00421150_Ptr();
};

struct D2StormFixedArrayBStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned char* m_data;

    unsigned char* sub_004215B0_Ptr();
};

struct D2StormFixedUIntArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned int* m_data;

    ~D2StormFixedUIntArrayStrc();
};

struct D2StormFixedUCharArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned char* m_data;

    ~D2StormFixedUCharArrayStrc();
};

struct D2StormGrowUIntArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned int* m_data;
    unsigned int m_chunk;

    ~D2StormGrowUIntArrayStrc();
};

struct D2StormGrowUCharArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned char* m_data;
    unsigned int m_chunk;

    ~D2StormGrowUCharArrayStrc();
};

struct D2StormArrayBStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned char* m_data;
    unsigned int m_chunk;

    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    unsigned int sub_00421160_CalcChunkSize(unsigned int nCount);                                           // 0x00421160
    void sub_004211C0_ReallocData(unsigned int nAlloc);                                                     // 0x004211C0
    unsigned char* sub_00421930_New();
};

#include "D2StormBigBuffer.h"

// 0x0041F6A0
void __fastcall sub_0041F6A0_DestroyTree(CHuffman* pTree)
{
    pTree->listB.Clear();
    pTree->listA.Clear();
    sub_00686AD1_DestroyArray(pTree->items, sizeof(HUFFNODE), 515, sub_0041EE90_DestroyItem);
}

// 0x0041F980
void __fastcall HuffmanCompress(void* pvOutBuffer, int* pcbOutBuffer, void* pvInBuffer, int cbInBuffer, int* pCmpType, int nCmpLevel)
{
    TOutputStream os(pvOutBuffer, *pcbOutBuffer);
    THuffmannTree ht;
    *pcbOutBuffer = ht.Compress(&os, pvInBuffer, cbInBuffer, *pCmpType);
}

// 0x00420E70
int* __fastcall MONSTERMODE_GetTargetTimerPtr(D2Field14Strc* pRecord)
{
    return &pRecord->nField14;
}

static inline int MONSTERMODE_IsActionFrame(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwAnimMode == 14)
        return (pUnit->dwFlags >> 6) & 1;
    return pUnit->nActionFrame == 1;
}

void __fastcall sub_M111_Emit_005A64F0(D2UnitStrc* pUnit, int* pResult)
{
    *pResult = MONSTERMODE_IsActionFrame(pUnit) + 1;
}

// build: symbol ?BigIsEven@* 0x00421440
static int BigIsEven(const BigBuffer& a)
{
    return !a.Count() || !(a[0] & 1);
}

