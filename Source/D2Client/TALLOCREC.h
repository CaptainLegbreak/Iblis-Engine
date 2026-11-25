#pragma once
// The memory report's record: one heap's SMemFindNextHeap result, kept on a Storm list (TSList<TALLOCREC>).

#include "stpl.h"

struct D2SMemHeapInfoStrc
{
    unsigned int dwSize;
    unsigned int hHeap;
    unsigned int adwName[0x41];
    int nLine;
    unsigned int dw110;
    unsigned int dw114;
    unsigned int dw118;
    unsigned int dw11C;
    unsigned int dw120;
    unsigned int dw124;
};

struct TALLOCREC : TSLinkedNode<TALLOCREC>
{
    D2SMemHeapInfoStrc tInfo;                               // 0x08

    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};
