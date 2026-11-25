#pragma once


extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, unsigned int nSize); // 0x006829C0
int __fastcall sub_0052A2E0_BigCompare(void* hLeft, void* hRight); // 0x0052A2E0
int __fastcall sub_0052A2F0_BigCompareUnsigned(void* hBig, unsigned int nValue); // 0x0052A2F0
int __fastcall GAME_DeleteBigNum(void* pArg); // 0x0052A600
unsigned int __fastcall sub_0052A2A0_BigToBinary(void* hBig, void* pBuffer, unsigned int nSize); // 0x0052A2A0
void __fastcall sub_0052A370_BigOpUnsigned_423790(void* hResult, void* hLeft, unsigned int nValue); // 0x0052A370
void __fastcall sub_0052A560_BigOpPair_424F10_424ED0(void* hResult, void* hLeft, void* hRight, void* hSecond); // 0x0052A560
void __fastcall sub_0052A590_BigOp_425330(void* hResult, void* hArg1, void* hArg2, void* hArg3); // 0x0052A590
void __fastcall sub_0052A5B0_BigOpUnsigned_425330(void* hResult, void* hArg1, unsigned int nValue, void* hArg3); // 0x0052A5B0
void* __fastcall sub_0052A240_BigFromUnsigned(unsigned int nValue); // 0x0052A240
void* __fastcall sub_0052A270_BigFromBinary(const void* pData, unsigned int nSize); // 0x0052A270
