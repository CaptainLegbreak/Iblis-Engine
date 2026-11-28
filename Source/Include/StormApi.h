#pragma once
// Storm's exports that the other modules call: strings, the registry and the message dispatcher.

struct SMSGHANDLER_PARAMS;

unsigned int __stdcall SStrCopy(char* dest,const char* source,unsigned int limit); // 0x004135D0
unsigned int __stdcall SStrPack(char* dest, const char* source, unsigned int limit); // 0x00413800
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590
const char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed); // 0x00413CE0
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned long nBufferSize); // 0x00414E50
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070
int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam, int* pbUseResult, int* plResult); // 0x00420B00
int __stdcall SMsgBreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __stdcall SFileUnloadFile(void* pBuffer); // 0x00416710
int __stdcall SFileLoadFileEx(void* hMpq, const char* szFileName, void** ppBuffer, int* pnSize, int nExtraBytes, int nFlags, void* pOverlapped); // 0x0041B680
int __stdcall SBmpDecodeImage(int nType, const unsigned char* pData, unsigned int nDataSize, unsigned char* pPalette, unsigned char* pPixels, unsigned int nPixelsSize, int* pWidth, int* pHeight, int* pBitDepth); // 0x006C6A80
int __stdcall SRegSaveData(const char* szKeyName, const char* szValueName, unsigned int nFlags, const void* pData, unsigned long nSize); // 0x00415000
int __stdcall SFileSetBasePath(const char* szPath); // 0x004164B0
int __stdcall SErrRegisterMessageSource(unsigned short wFacility, void* hModule, void* pReserved); // 0x0041C2F0
int __stdcall SErrGetErrorStr(unsigned long error, char* buffer, unsigned long size); // 0x0041C430
void __stdcall SStrTokenize(const char** pszString, char* szBuffer, unsigned int nBufferChars, const char* szWhitespace, int* pQuoted); // 0x00413B80
const char* __stdcall SStrChrR(const char* szString, char nChar); // 0x004134D0
int __stdcall SRegLoadData(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned char* pData, unsigned long nSize, unsigned long* pcbData); // 0x00414DE0
int __stdcall SFileCloseArchive(void* hArchive); // 0x00419A80
unsigned int __stdcall SStrHashHT(const char* szPath); // 0x00414150
int __cdecl SFileDdaDestroy(); // 0x00419F30
extern "C" int __stdcall SFileDdaInitialize(int nValue); // 0x00415EE0
