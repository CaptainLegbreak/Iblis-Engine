#pragma once
// Bnclient's exports that the other modules call; included only by the units that use it.

struct D2IdeaUserKeyStrc;

void __cdecl sub_00521B50_ReseedLogin(); // 0x00521B50
void __cdecl sub_00521B90_ClearSrpState(); // 0x00521B90
void __cdecl sub_005241A0_ClearHashContexts(); // 0x005241A0
void __fastcall sub_005241C0_GetDigest(int nIndex, unsigned int* pDigest); // 0x005241C0
void __fastcall sub_00524200_HashBlock(int nIndex, const void* pBlock, unsigned int* pDigest); // 0x00524200
void __fastcall sub_00524280_InitHashContext(int nIndex); // 0x00524280
void __cdecl sub_00524740_ClearKeySchedules(); // 0x00524740
void __fastcall sub_00524760_CipherBlock(int nIndex, const unsigned short* pIn, unsigned short* pOut); // 0x00524760
void __fastcall sub_00524780_SetKey(int nIndex, int bEncrypt, const D2IdeaUserKeyStrc* pUserKey); // 0x00524780
void* __fastcall sub_0052A240_BigFromUnsigned(unsigned int nValue); // 0x0052A240
void* __fastcall sub_0052A270_BigFromBinary(const void* pData, unsigned int nSize); // 0x0052A270
unsigned int __fastcall sub_0052A2A0_BigToBinary(void* hBig, void* pBuffer, unsigned int nSize); // 0x0052A2A0
int __fastcall sub_0052A2E0_BigCompare(void* hLeft, void* hRight); // 0x0052A2E0
int __fastcall sub_0052A2F0_BigCompareUnsigned(void* hBig, unsigned int nValue); // 0x0052A2F0
int __fastcall sub_0052A350_BigOp_423790(void* hResult, void* hLeft, void* hRight); // 0x0052A350
void __fastcall sub_0052A370_BigOpUnsigned_423790(void* hResult, void* hLeft, unsigned int nValue); // 0x0052A370
int __fastcall sub_0052A3B0_BigOp_423AC0(void* hResult, void* hLeft, void* hRight); // 0x0052A3B0
void __fastcall sub_0052A560_BigOpPair_424F10_424ED0(void* hResult, void* hLeft, void* hRight, void* hSecond); // 0x0052A560
void __fastcall sub_0052A590_BigOp_425330(void* hResult, void* hArg1, void* hArg2, void* hArg3); // 0x0052A590
void __fastcall sub_0052A5B0_BigOpUnsigned_425330(void* hResult, void* hArg1, unsigned int nValue, void* hArg3); // 0x0052A5B0
