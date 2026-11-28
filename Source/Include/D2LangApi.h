#pragma once
// D2Lang's exports that the other modules call: the string table and the Unicode helpers.

struct Unicode;

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __cdecl sub_005269D0_FormatText(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
char* __fastcall UNICODE_ToAscii(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70
char* __fastcall UNICODE_ToUtf8(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0
int __cdecl STRTABLE_GetLanguage(); // 0x00525150
Unicode* __fastcall sub_00526940_FindSubstring(const Unicode* str, const Unicode* substr); // 0x00526940
Unicode* __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526E40
unsigned short __stdcall STRTABLE_FindString(const char* szKey, const wchar_t** ppText); // 0x00524D30
int __fastcall sub_00526D30_IsLineBreak(const Unicode* pText, unsigned int nIndex); // 0x00526D30
void __stdcall STRTABLE_GetLanguageInfoField(void* pOut, int nField); // 0x00525260
const wchar_t* __fastcall D2LANG_GetStringByReferenceString(const char* szKey); // 0x00524E20
int __fastcall sub_005262A0_Utf8CountChars(const char* pSrc, int nCount); // 0x005262A0
void __fastcall sub_005272B0_FormatText(Unicode* pDst, const Unicode* pOwner, const Unicode* pItem, int nMaxLength, int nLanguage); // 0x005272B0
void __stdcall D2LANG_FormatInt(Unicode* pOut, int nValue, int nSize); // 0x00525FB0
