#include "D2BNClient.h"
#include "D2Primitives.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2Storm408ElemStrc;

struct D2StormArray408Strc;

struct D2SystemTimeStrc;

struct D2FileTimeStrc;

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2Storm408ElemStrc
{
    unsigned int nFlags;
    unsigned int nStamp;
    char szText[0x400];
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

extern "C" const char gszNewsItemTypeName_0072FF8C[]; // 0x0072FF8C

struct D2StormArray408Strc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2Storm408ElemStrc* m_data;
    unsigned int m_chunk;
    D2Storm408ElemStrc* sub_0051D2A0_At(unsigned int nIndex);
    unsigned int sub_0051D2F0_CalcChunkSize(unsigned int nCount);                                           // 0x0051D2F0
    void sub_0051D5D0_ReallocData(unsigned int nCount);                                                     // 0x0051D5D0
    void sub_0051D6D0_Reserve(unsigned int nCount, int bRound);
    void sub_0051D7F0_Grow(unsigned int nCount);
    D2StormArray408Strc* sub_0051D2C0_InitBase();
    void sub_0051D570_FreeData();
    void sub_0051D670_FreeData();
    D2StormArray408Strc* sub_0051D690_Init();
    void sub_0051D6A0_Clear();
    D2StormArray408Strc* sub_0051D720_Init();
    void sub_0051D730_FreeData();
    D2Storm408ElemStrc* sub_0051D7A0_New();
    void ReserveInline(unsigned int nCount, int bRound);
    ~D2StormArray408Strc()
    {
        if (m_data)
            SMemFree(m_data, gszNewsItemTypeName_0072FF8C, -2, 0);
    }
    static void operator delete(void* pMemory);
    void sub_0051D810_SetCount(unsigned int nCount);
};

int gbNewsActive; // 0x00881C24

int (__cdecl* gpfnNewsRefresh)(); // 0x00881C2C

// build: symbol ??__EgtNewsItems@@YAXXZ 0x006CAEC0
// build: symbol ??__FgtNewsItems@@YAXXZ 0x006CB450
D2StormArray408Strc gtNewsItems;        // 0x00881C30

unsigned int gnNewsFirstIndex;        // 0x00881C40

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020

void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0

int (__fastcall* gpfnNewsMessage)(unsigned int nStamp, const char* szText); // 0x00881C28

inline void* operator new(unsigned int, void* pPlace) throw();

extern "C" size_t __cdecl strlen(const char* szString);

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" __declspec(dllimport) int __stdcall SystemTimeToFileTime(const D2SystemTimeStrc* pSystemTime, D2FileTimeStrc* pFileTime); // 0x006CC26C

int __fastcall CACHE_WriteCachedFile(const char* szName, const void* pData, unsigned int nSize, const D2FileTimeStrc* pFileTime, unsigned int nSeconds1, unsigned int nSeconds2); // 0x00519DB0

extern "C" const char gszBNNewsFile[]; // 0x006DF228

int __cdecl BNNEWS_SaveNews(); // 0x0051D370

void __cdecl BNNEWS_ReportNews(); // 0x0051D510

int __fastcall CACHE_LoadCachedFile(const char*, D2FileTimeStrc*, void**, unsigned int*); // 0x00519920

extern const char* gpszNewsName; // 0x0072FF80

unsigned int gnNewsNewest;        // 0x00881C44

extern "C" char* __cdecl strncpy(char*,const char*,unsigned);




extern unsigned gnNewsLastStamp_00881C44; // 0x00881C44

// 0x0051D260
void __fastcall BNNEWS_SelectNewsFile(int bAlternate)
{
    D2_ASSERT(!gbNewsActive, 0x2F);
    gpszNewsName_0072FF80 = "BNNews-D2DV";
    if (!bAlternate)
        gpszNewsName_0072FF80 = "BNNews-D2XP";
}

inline unsigned int RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// 0x0051D2A0
D2Storm408ElemStrc* D2StormArray408Strc::sub_0051D2A0_At(unsigned int nIndex)
{
    return &m_data[nIndex];
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

// 0x0051D2C0
D2StormArray408Strc* D2StormArray408Strc::sub_0051D2C0_InitBase()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    return this;
}

// 0x0051D2D0
void __cdecl sub_0051D2D0_Nop()
{
}

// 0x0051D2E0
void __cdecl sub_0051D2E0_Nop()
{
}

// 0x0051D2F0
unsigned int D2StormArray408Strc::sub_0051D2F0_CalcChunkSize(unsigned int nCount)
{
    if (nCount < 8)
    {
        unsigned int nResult = nCount;
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    m_chunk = 8;
    return 8;
}

// 0x0051D330
unsigned int __stdcall BNNEWS_RoundUpToMultiple(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// 0x0051D350
void __fastcall BNNEWS_CopyNewsItem(D2Storm408ElemStrc* pDst, const D2Storm408ElemStrc* pSrc)
{
    if (pDst)
        *pDst = *pSrc;
}

static inline bool AddItemSize(const D2Storm408ElemStrc* pItem, int* pnSize)
{
    *pnSize += sizeof(unsigned int);
    int nLen = strlen(pItem->szText);
    if (nLen >= 0x400)
        return false;
    *pnSize += nLen + 1;
    return true;
}

// 0x0051D370
int __cdecl BNNEWS_SaveNews()
{
    unsigned int nEnd = gtNewsItems.m_count;
    unsigned int nFirst = gnNewsFirstIndex;
    unsigned int nCount = gtNewsItems.m_count;
    unsigned int nNew = nCount - nFirst;
    D2_ASSERT(nNew < 0x100, 0x13B);

    int nSize = 8;
    int nLen;
    for (unsigned int i = nFirst; i < nCount; ++i)
    {
        if (!AddItemSize(&gtNewsItems.m_data[i], &nSize))
            return 0;
    }

    char* pBuffer = (char*)FOG_Alloc(nSize, gszBNNewsFile, 0x154, 0);
    if (pBuffer)
    {
        *(unsigned int*)pBuffer = gnNewsNewest;
        char* pOut = pBuffer + 4;
        *(unsigned int*)pOut = nNew;
        pOut += 4;
        for (unsigned int i = gnNewsFirstIndex; i < nEnd; ++i)
        {
            D2Storm408ElemStrc* pItem = &gtNewsItems.m_data[i];
            *(unsigned int*)pOut = pItem->nStamp;
            pOut += 4;
            nLen = strlen(pItem->szText);
            strcpy(pOut, pItem->szText);
            pOut += nLen + 1;
        }

        D2SystemTimeStrc tSystemTime;
        D2FileTimeStrc tFileTime;
        GetSystemTime(&tSystemTime);
        SystemTimeToFileTime(&tSystemTime, &tFileTime);
        int nResult = CACHE_WriteCachedFile(gpszNewsName_0072FF80, pBuffer, nSize, &tFileTime, -1, -1);
        FOG_Free(pBuffer, gszBNNewsFile, 0x17B, 0);
        return nResult;
    }
    return 0;
}

// 0x0051D510
void __cdecl BNNEWS_ReportNews()
{
    if (gpfnNewsRefresh)
        gpfnNewsRefresh();
    if (!gpfnNewsMessage)
        return;
    unsigned int nIndex = gtNewsItems.m_count;
    const int nCount = nIndex - gnNewsFirstIndex;
    for (int i = 0; i < nCount; ++i)
    {
        gpfnNewsMessage(gtNewsItems.m_data[nIndex - 1].nStamp, gtNewsItems.m_data[nIndex - 1].szText);
        --nIndex;
    }
}

// build: symbol ??_GD2StormArray408Strc@@QAEPAXI@Z 0x0051D590
inline void D2StormArray408Strc::operator delete(void* pMemory)
{
    SMemFree(pMemory, "delete", -1, 0);
}

inline void* operator new(unsigned int, void* pPlace) throw()
{
    return pPlace;
}

// 0x0051D570
void D2StormArray408Strc::sub_0051D570_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszNewsItemTypeName_0072FF8C, -2, 0);
}

// 0x0051D5D0
void D2StormArray408Strc::sub_0051D5D0_ReallocData(unsigned int nAlloc)
{
    D2Storm408ElemStrc* pOld = m_data;
    m_alloc = nAlloc;
    m_data = (D2Storm408ElemStrc*)SMemReAlloc(pOld, nAlloc * sizeof(D2Storm408ElemStrc), gszNewsItemTypeName_0072FF8C, -2, 0x10);
    if (!m_data)
    {
        m_data = (D2Storm408ElemStrc*)SMemAlloc(nAlloc * sizeof(D2Storm408ElemStrc), gszNewsItemTypeName_0072FF8C, -2, 0);
        if (pOld)
        {
            unsigned int nCount = nAlloc < m_count ? nAlloc : m_count;
            for (unsigned int i = 0; i < nCount; i++)
                new (&m_data[i]) D2Storm408ElemStrc(pOld[i]);
            SMemFree(pOld, gszNewsItemTypeName_0072FF8C, -2, 0);
        }
    }
}

// 0x0051D670
void D2StormArray408Strc::sub_0051D670_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszNewsItemTypeName_0072FF8C, -2, 0);
}

// 0x0051D690
D2StormArray408Strc* D2StormArray408Strc::sub_0051D690_Init()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    m_chunk = 0;
    return this;
}

// 0x0051D6A0
void D2StormArray408Strc::sub_0051D6A0_Clear()
{
    if (m_data)
        SMemFree(m_data, gszNewsItemTypeName_0072FF8C, -2, 0);
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

// 0x0051D6D0
void D2StormArray408Strc::sub_0051D6D0_Reserve(unsigned int nCount, int bRound)
{
    nCount += m_count;
    if (nCount > m_alloc)
    {
        if (bRound)
        {
            unsigned int nChunk = m_chunk ? m_chunk : sub_0051D2F0_CalcChunkSize(nCount);
            nCount = RoundUp(nCount, nChunk);
        }
        sub_0051D5D0_ReallocData(nCount);
    }
}

// 0x0051D720
D2StormArray408Strc* D2StormArray408Strc::sub_0051D720_Init()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    m_chunk = 0;
    return this;
}

// 0x0051D730
void D2StormArray408Strc::sub_0051D730_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszNewsItemTypeName_0072FF8C, -2, 0);
}

// 0x0051D750
int __cdecl BNNEWS_UnloadBNetNews()
{
    gpfnNewsMessage = 0;
    gpfnNewsRefresh = 0;
    if (gtNewsItems.m_data)
        SMemFree(gtNewsItems.m_data, gszNewsItemTypeName_0072FF8C, -2, 0);
    gtNewsItems.m_alloc = 0;
    gtNewsItems.m_count = 0;
    gtNewsItems.m_data = 0;
    gbNewsActive = 0;
    return 1;
}

// 0x0051D7A0
D2Storm408ElemStrc* D2StormArray408Strc::sub_0051D7A0_New()
{
    ReserveInline(1, 1);
    return &m_data[m_count++];
}

// 0x0051D7F0
void D2StormArray408Strc::sub_0051D7F0_Grow(unsigned int nCount)
{
    const unsigned int nNewCount = m_count + nCount;
    if (nNewCount > m_alloc)
        sub_0051D5D0_ReallocData(nNewCount);
}

// 0x0051D810
void D2StormArray408Strc::sub_0051D810_SetCount(unsigned int nCount)
{
    if (nCount > m_count && nCount > m_alloc)
    {
        unsigned int nChunk = m_chunk;
        if (!nChunk)
            nChunk = sub_0051D2F0_CalcChunkSize(nCount);
        unsigned int nAlloc = nCount;
        const unsigned int nRemainder = nCount % nChunk;
        if (nRemainder)
            nAlloc = nCount + nChunk - nRemainder;
        sub_0051D5D0_ReallocData(nAlloc);
    }
    m_count = nCount;
}

// 0x0051D860
int __fastcall BNNEWS_ParseNewsInfo(const char* data)
{
 unsigned count=*data;
 const char* cursor=data+5;
 unsigned first=*(unsigned*)cursor;cursor+=4;
 unsigned last=*(unsigned*)cursor;cursor+=4;
 D2_ASSERT(count<=256,0x77);
 for(unsigned i=0;i<count;++i) {
  unsigned stamp=*(unsigned*)cursor;cursor+=4;
  const char* text=cursor;
  while(*cursor++);
  if(stamp) {
   unsigned index=gtNewsItems.m_count;
   unsigned* entry=0;
   if(gtNewsItems.m_count) {
    entry=&gtNewsItems.m_data[gtNewsItems.m_count].nStamp;
    do {
     entry=(unsigned*)((char*)entry-0x408);
     --index;
     if(stamp>*entry)goto insert;
     if(stamp==*entry)goto update;
    }while(index);
   }
   --index;
   goto insert;
update:
   entry[-1]=0;
   strncpy((char*)(entry+1),text,1024);
   goto next;
insert:
   ++index;
   gtNewsItems.sub_0051D810_SetCount(gtNewsItems.m_count+1);
   for(unsigned j=gtNewsItems.m_count-1;j>index;--j)gtNewsItems.m_data[j]=gtNewsItems.m_data[j-1];
   gtNewsItems.m_data[index].nFlags=0;
   gtNewsItems.m_data[index].nStamp=stamp;
   strncpy(gtNewsItems.m_data[index].szText,text,1024);
  } else if(gpfnNewsMessage)gpfnNewsMessage(0,text);
next:;
 }
 gnNewsLastStamp_00881C44=last;
 unsigned index=0;
 while(index<gtNewsItems.m_count && gtNewsItems.m_data[index].nStamp<first)++index;
 gnNewsFirstIndex=index;
 BNNEWS_SaveNews();BNNEWS_ReportNews();return 1;
}


// 0x0051DA30
int __cdecl BNNEWS_LoadNews()
{
    D2FileTimeStrc fileTime;
    unsigned int nSize;
    int bResult = 0;
    void* pData = 0;
    if (CACHE_LoadCachedFile(gpszNewsName, &fileTime, &pData, &nSize))
    {
        const char* p = (const char*)pData;
        gnNewsNewest = *(const unsigned int*)p;
        p += sizeof(unsigned int);
        unsigned int nCount = *(const unsigned int*)p;
        p += sizeof(unsigned int);
        if (nCount <= 256)
        {
            gtNewsItems.sub_0051D810_SetCount(0);
            if (gtNewsItems.m_count + nCount > gtNewsItems.m_alloc)
                gtNewsItems.sub_0051D5D0_ReallocData(gtNewsItems.m_count + nCount);
            gnNewsFirstIndex = 0;
            unsigned int nLastStamp = 0;
            unsigned int i;
            for (i = 0; i < nCount; ++i)
            {
                unsigned int nNewCount = gtNewsItems.m_count + 1;
                if (nNewCount > gtNewsItems.m_alloc)
                {
                    unsigned int nChunk = gtNewsItems.m_chunk;
                    if (!nChunk) nChunk = gtNewsItems.sub_0051D2F0_CalcChunkSize(nNewCount);
                    unsigned int nAlloc = nNewCount;
                    const unsigned int nRemainder = nNewCount % nChunk;
                    if (nRemainder) nAlloc = nNewCount + nChunk - nRemainder;
                    gtNewsItems.sub_0051D5D0_ReallocData(nAlloc);
                }
                D2Storm408ElemStrc* pItem = &gtNewsItems.m_data[gtNewsItems.m_count++];
                pItem->nFlags = 0;
                pItem->nStamp = *(const unsigned int*)p;
                p += sizeof(unsigned int);
                int nLength = strlen(p);
                if (nLength >= 1024) goto Cleanup;
                strcpy(pItem->szText, p);
                p += nLength + 1;
                if (nLastStamp > pItem->nStamp) break;
                nLastStamp = pItem->nStamp;
            }
            bResult = i == nCount;
        }
    }
Cleanup:
    if (!bResult)
    {
        if (gtNewsItems.m_data)
            SMemFree(gtNewsItems.m_data, gszNewsItemTypeName_0072FF8C, -2, 0);
        gtNewsItems.m_alloc = 0;
        gtNewsItems.m_count = 0;
        gtNewsItems.m_data = 0;
        gnNewsFirstIndex = 0;
        gnNewsNewest = 0;
    }
    if (pData) SMemFree(pData, ".\\BNNews.cpp", 299, 0);
    return bResult;
}

void sub_W11_EmitDeleteStormArray408(D2StormArray408Strc* pArray)
{
    delete pArray;
}

// 0x0051DF90
int __fastcall BNNEWS_TryDecodeCDKey(const char* szKey, void* pArg2, void* pArg3, void* pArg4)
{
    if (!szKey)
        return 0;
    sub_00522AE0_DecodeCDKey(szKey, pArg3, pArg2, pArg4);
    return 1;
}

#include "gen/data/Source/D2BNClient/BNNews.inc"
