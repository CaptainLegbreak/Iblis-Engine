#pragma once

#include "D2LangTypes.h"

struct D2LangCharMapEntryStrc;
struct Unicode;

const Unicode* __fastcall STRTABLE_GetStringFromTable(D2TblHeaderStrc* pTable, void* pIndex, unsigned short nIndex); // 0x00524930
extern "C" char* __cdecl _ultoa(unsigned long nValue, char* szOut, int nRadix); // 0x00687652
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char gszStar[]; // 0x006D5830
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern D2LangCharMapEntryStrc* gpCharMap; // 0x00882B24
extern unsigned short gawToUpperTable[0x100]; // 0x00730578
int __cdecl sub_00525150(); // 0x00525150
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
void* __fastcall sub_00517079(void* hArchive, const char* szPath, int* pSize, const char* szFile, int nLine); // 0x00517079

// build: symbol ?FOG_DisplayHalt@* 0x00408A60
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2LangCharMapEntryStrc
{
    unsigned short wValue;
    unsigned short wChar;
};

typedef unsigned int size_t;

Unicode* __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
extern "C" void* __cdecl bsearch(const void* pKey, const void* pBase, unsigned int nCount, unsigned int nSize, int (__cdecl* pfCompare)(const void*, const void*)); // 0x006881B1
extern D2LangByteRangeStrc* gpLeadByteRanges; // 0x00882B28
extern unsigned short* gpCharMapIndex; // 0x00882B2C
int __cdecl sub_00527AE0_CompareKey(const void* pLeft, const void* pRight); // 0x00527AE0

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource); // 0x005267E0
int __fastcall UNICODE_StrLen(const Unicode* pString); // 0x00526800
char* __fastcall UNICODE_ToAscii(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70
