#pragma once
// D2Lang's exports that the other modules call; included only by the units that use it.

struct D2LangByteRangeStrc;
struct Unicode;

void __cdecl STRTABLE_UnloadStringTables(); // 0x00524E40
void __stdcall STR_GroupUintDigits(Unicode* pOut, unsigned int nValue, int nSize); // 0x00525350
int __cdecl sub_00527AE0_CompareKey(const void* pLeft, const void* pRight); // 0x00527AE0
extern unsigned short gaCaseTable[0x100]; // 0x00730778
extern D2LangByteRangeStrc* gpLeadByteRanges; // 0x00882B28
