#include "Storm.h"
#include "stpl.h"

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

// build: symbol ?ReallocData@?$TSFixedArray@IU?$TSCD@I@@@@QAEXI@Z 0x00421110
// build: symbol ?ReallocData@?$TSFixedArray@EU?$TSCD@E@@@@QAEXI@Z 0x00421680
// build: symbol ?ReallocData@?$TSFixedArray@DU?$TSCD@D@@@@QAEXI@Z 0x004216B0
// build: symbol ??4?$TSFixedArray@IU?$TSCD@I@@@@QAEAAU0@ABU0@@Z 0x00421870
// build: symbol ?SetCount@?$TSGrowableArray@EU?$TSCD@E@@@@QAEXI@Z 0x00421980
// build: symbol ??4?$TSGrowableArray@IU?$TSCD@I@@@@QAEAAU0@ABU0@@Z 0x00421BA0
// build: symbol ?Set@?$TSFixedArray@IU?$TSCD@I@@@@QAEXIPBI@Z 0x004215C0
// build: symbol ?CalcChunkSize@?$TSGrowableArray@EU?$TSCD@E@@@@QAEII@Z 0x00421160
// build: symbol ?ReallocData@?$TSGrowableArray@EU?$TSCD@E@@@@QAEXI@Z 0x004211C0
// build: symbol ??0?$TSBaseArray@I@@QAE@XZ 0x00421020
// build: symbol ??0?$TSBaseArray@E@@QAE@XZ 0x00421030
// build: symbol ??0?$TSGrowableArray@IU?$TSCD@I@@@@QAE@XZ 0x00421860
// build: symbol ??A?$TSBaseArray@I@@QAEAAII@Z 0x00420FD0
// build: symbol ??A?$TSBaseArray@D@@QAEAADI@Z 0x00421000
// build: symbol ?Ptr@?$TSBaseArray@D@@QAEPADXZ 0x00421010
// build: symbol ?Destruct@?$TSCD@E@@SIXPAE@Z 0x00421040
// build: symbol ?CopyConstruct@?$TSCD@E@@SIXPAEABE@Z 0x00421050
// build: symbol ?Construct@?$TSCD@E@@SIXPAE@Z 0x00421060
// build: symbol ?Destruct@?$TSCD@D@@SIXPAD@Z 0x00421070
// build: symbol ?Construct@?$TSCD@D@@SIXPAD@Z 0x00421080
// build: symbol ?CopyConstruct@?$TSCD@D@@SIXPADABD@Z 0x00421090
// build: symbol ?CalcChunkSize@?$TSGrowableArray@IU?$TSCD@I@@@@QAEII@Z 0x004210A0
// build: symbol ?RoundUp@?$TSGrowableArray@IU?$TSCD@I@@@@SGIII@Z 0x004210E0
// build: symbol ?Ptr@?$TSBaseArray@I@@QAEPAIXZ 0x00421150
// build: symbol ?RoundUp@?$TSGrowableArray@EU?$TSCD@E@@@@SGIII@Z 0x004211A0
// build: symbol ?CalcChunkSize@?$TSGrowableArray@DU?$TSCD@D@@@@QAEII@Z 0x00421240
// build: symbol ?RoundUp@?$TSGrowableArray@DU?$TSCD@D@@@@SGIII@Z 0x00421280
// build: symbol ?CopyConstruct@?$TSCD@I@@SIXPAIABI@Z 0x004212A0
// build: symbol ?Destruct@?$TSCD@I@@SIXPAI@Z 0x004212B0
// build: symbol ??1?$TSFixedArray@IU?$TSCD@I@@@@QAE@XZ 0x00421570
// build: symbol ??1?$TSFixedArray@EU?$TSCD@E@@@@QAE@XZ 0x00421590
// build: symbol ?Ptr@?$TSBaseArray@E@@QAEPAEXZ 0x004215B0
// build: symbol ?Reserve@?$TSGrowableArray@EU?$TSCD@E@@@@QAEXIH@Z 0x00421630
// build: symbol ?ReallocData@?$TSGrowableArray@IU?$TSCD@I@@@@QAEXI@Z 0x004216E0
// build: symbol ?ReallocData@?$TSGrowableArray@DU?$TSCD@D@@@@QAEXI@Z 0x00421770
// build: symbol ??1?$TSGrowableArray@IU?$TSCD@I@@@@QAE@XZ 0x004217F0
// build: symbol ??1?$TSGrowableArray@EU?$TSCD@E@@@@QAE@XZ 0x00421840
// build: symbol ??0?$TSGrowableArray@EU?$TSCD@E@@@@QAE@XZ 0x004218A0
// build: symbol ?Add@?$TSGrowableArray@EU?$TSCD@E@@@@QAEIIPBE@Z 0x004218B0
// build: symbol ?New@?$TSGrowableArray@EU?$TSCD@E@@@@QAEPAEXZ 0x00421930
// build: symbol ?Set@?$TSFixedArray@EU?$TSCD@E@@@@QAEXIPBE@Z 0x004219F0
// build: symbol ?Set@?$TSFixedArray@DU?$TSCD@D@@@@QAEXIPBD@Z 0x00421A50
// build: symbol ?Reserve@?$TSGrowableArray@IU?$TSCD@I@@@@QAEXIH@Z 0x00421AB0
// build: symbol ?Reserve@?$TSGrowableArray@DU?$TSCD@D@@@@QAEXIH@Z 0x00421B00
// build: symbol ?SetCount@?$TSGrowableArray@IU?$TSCD@I@@@@QAEXI@Z 0x00421F10
// build: symbol ?Add@?$TSGrowableArray@DU?$TSCD@D@@@@QAEIIPBD@Z 0x00421F60
// build: symbol _SMemAlloc@16 0x00413020
// build: symbol _SMemFree@16 0x00412650
// build: symbol _SMemReAlloc@20 0x004133D0
// build: symbol ??_R0I@8 0x0070886C
// build: symbol ??_R0E@8 0x00708878
// build: symbol ??_R0D@8 0x00708884
template TSBaseArray<unsigned int>::TSBaseArray();
template TSBaseArray<unsigned char>::TSBaseArray();
template TSGrowableArray<unsigned int>::TSGrowableArray();
template void TSFixedArray<unsigned int>::ReallocData(unsigned int);
template void TSFixedArray<unsigned char>::ReallocData(unsigned int);
template void TSFixedArray<char>::ReallocData(unsigned int);
template TSFixedArray<unsigned int>& TSFixedArray<unsigned int>::operator=(const TSFixedArray<unsigned int>&);
template void TSGrowableArray<unsigned char>::SetCount(unsigned int);
template TSGrowableArray<unsigned int>& TSGrowableArray<unsigned int>::operator=(const TSGrowableArray<unsigned int>&);
template unsigned int& TSBaseArray<unsigned int>::operator[](unsigned int);
template char& TSBaseArray<char>::operator[](unsigned int);
template char* TSBaseArray<char>::Ptr();
template unsigned int* TSBaseArray<unsigned int>::Ptr();
template unsigned char* TSBaseArray<unsigned char>::Ptr();
template void __fastcall TSCD<unsigned char>::Construct(unsigned char*);
template void __fastcall TSCD<unsigned char>::CopyConstruct(unsigned char*, const unsigned char&);
template void __fastcall TSCD<unsigned char>::Destruct(unsigned char*);
template void __fastcall TSCD<char>::Construct(char*);
template void __fastcall TSCD<char>::CopyConstruct(char*, const char&);
template void __fastcall TSCD<char>::Destruct(char*);
template void __fastcall TSCD<unsigned int>::CopyConstruct(unsigned int*, const unsigned int&);
template void __fastcall TSCD<unsigned int>::Destruct(unsigned int*);
template unsigned int TSGrowableArray<unsigned int>::CalcChunkSize(unsigned int);
template unsigned int __stdcall TSGrowableArray<unsigned int>::RoundUp(unsigned int, unsigned int);
template unsigned int TSGrowableArray<unsigned char>::CalcChunkSize(unsigned int);
template unsigned int __stdcall TSGrowableArray<unsigned char>::RoundUp(unsigned int, unsigned int);
template unsigned int TSGrowableArray<char>::CalcChunkSize(unsigned int);
template unsigned int __stdcall TSGrowableArray<char>::RoundUp(unsigned int, unsigned int);
template TSFixedArray<unsigned int>::~TSFixedArray();
template TSFixedArray<unsigned char>::~TSFixedArray();
template void TSFixedArray<unsigned int>::Set(unsigned int, const unsigned int*);
template void TSGrowableArray<unsigned char>::Reserve(unsigned int, int);
template void TSGrowableArray<unsigned char>::ReallocData(unsigned int);
template void TSGrowableArray<unsigned int>::ReallocData(unsigned int);
template void TSGrowableArray<char>::ReallocData(unsigned int);
template TSGrowableArray<unsigned int>::~TSGrowableArray();
template TSGrowableArray<unsigned char>::~TSGrowableArray();
template TSGrowableArray<unsigned char>::TSGrowableArray();
template unsigned int TSGrowableArray<unsigned char>::Add(unsigned int, const unsigned char*);
template unsigned char* TSGrowableArray<unsigned char>::New();
template void TSFixedArray<unsigned char>::Set(unsigned int, const unsigned char*);
template void TSFixedArray<char>::Set(unsigned int, const char*);
template void TSGrowableArray<unsigned int>::Reserve(unsigned int, int);
template void TSGrowableArray<char>::Reserve(unsigned int, int);
template void TSGrowableArray<unsigned int>::SetCount(unsigned int);
template unsigned int TSGrowableArray<char>::Add(unsigned int, const char*);

// The byte array's one-element Add keeps its own name: Storm's name for it isn't known.
struct D2StormArrayBStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned char* m_data;
    unsigned int m_chunk;

    unsigned int sub_004218B0_Add(unsigned int nCount, const unsigned char* pData);                         // 0x004218B0
    unsigned int sub_004219D0_AddOne(const unsigned char* pData);
};

// 0x004219D0
unsigned int D2StormArrayBStrc::sub_004219D0_AddOne(const unsigned char* pData)
{
    return sub_004218B0_Add(1, pData);
}

#include "gen/data/Source/Storm/Unknown_00421110.inc"
