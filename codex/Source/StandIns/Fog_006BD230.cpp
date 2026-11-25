// Functional replacement for the function at 0x006BD230, not the original code: only the ordinary build (tools/link.py) uses it.

struct D2TxtLinkEntry006BD230Strc { unsigned int nKey; int nIndex; };
struct D2TxtLink006BD230Strc
{
    int nCount;
    int nCapacity;
    D2TxtLinkEntry006BD230Strc* pEntries;
    void* pFirstNode;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl ASSERT_Report(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl ASSERT_GetSourceFile(); // 0x00408090
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize); // 0x00683840
void* __fastcall FOG_ReallocServerMemory(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
extern const char gszExcelSourceFile_006FC448[]; // 0x006FC448

#define D2_ASSERT(expr, line) if (!(expr)) { ASSERT_Report(&gszEmptyAssertText, ASSERT_GetSourceFile(), line); exit(-1); }

// 0x006BD230
int __stdcall sub_006BD230_InsertLinkKey(D2TxtLink006BD230Strc* pLink, unsigned int nKey)
{
    D2_ASSERT(pLink, 0x3D1);
    D2_ASSERT(!pLink->pFirstNode, 0x3D8);

    if (pLink->nCapacity <= pLink->nCount)
    {
        int nNewCapacity = pLink->nCapacity + 0x40;
        pLink->pEntries = (D2TxtLinkEntry006BD230Strc*)FOG_ReallocServerMemory(0, pLink->pEntries,
            nNewCapacity * sizeof(D2TxtLinkEntry006BD230Strc), gszExcelSourceFile_006FC448, 0x3DF, 0);
        memset(&pLink->pEntries[pLink->nCapacity], 0, 0x40 * sizeof(D2TxtLinkEntry006BD230Strc));
        pLink->nCapacity = nNewCapacity;
    }

    int nLow;
    for (;;)
    {
        D2TxtLinkEntry006BD230Strc* pEntries = pLink->pEntries;
        nLow = 0;
        int nHigh = pLink->nCount;
        while (nLow < nHigh)
        {
            int nMid = nLow + (nHigh - nLow) / 2;
            unsigned int nMidKey = pEntries[nMid].nKey;
            if (nKey > nMidKey)
                nLow = nMid + 1;
            else if (nKey < nMidKey)
                nHigh = nMid;
            else
                goto found;
        }
        break;
    found:
        ++nKey;
    }

    if (nLow < pLink->nCount)
    {
        memmove(&pLink->pEntries[nLow + 1], &pLink->pEntries[nLow],
            (pLink->nCount - nLow) * sizeof(D2TxtLinkEntry006BD230Strc));
    }

    pLink->pEntries[nLow].nKey = nKey;
    pLink->pEntries[nLow].nIndex = pLink->nCount;
    int nResult = pLink->pEntries[nLow].nIndex;
    ++pLink->nCount;
    return nResult;
}
