#pragma once
// Storm's exports that the other modules call and StormApi.h doesn't declare; included only by the units that use it.

struct D2CmdArg006C4E50Strc;
struct D2SMemHeapStrc;
struct D2StormBigStrc;
struct D2StormOverlappedStrc;
struct D2StormSoundBufferStrc;
struct SMEMBLOCKDETAILS;
struct SMEMHEAPDETAILS;

void __fastcall UnlinkAndFreeHeap(D2SMemHeapStrc** ppLink); // 0x00411A80
int __stdcall SMemFindNextBlock(unsigned int hHeap, void* pMemory, void** ppBlock, SMEMBLOCKDETAILS* pInfo); // 0x004122F0
int __stdcall SMemFindNextHeap(unsigned int hPrev, unsigned int* phNext, SMEMHEAPDETAILS* pInfo); // 0x004124B0
unsigned int __stdcall SMemGetHeapByCaller(const char* szFile, int nLine); // 0x00412710
int __stdcall SStrCmp(const char* szString1, const char* szString2, int nMaxChars); // 0x00413550
char* __stdcall SStrUpper(char* szString); // 0x004141E0
char* __stdcall SStrLower(char* szString); // 0x00414200
void __cdecl InitPowTable(); // 0x004142A0
extern "C" void __cdecl SStrInitialize(); // 0x00414360
int __stdcall SRegDeleteValue(const char* szKeyName, const char* szValueName, unsigned int nFlags); // 0x00414D90
int __stdcall SFileEnableDirectAccess(int nFlags); // 0x00415F70
void __stdcall SFileEnableSeekOptimization(int nValue); // 0x00415F90
int __stdcall CopyFileRecName(void* hFile, char* szBuffer, unsigned int nSize); // 0x00416230
int __stdcall SFileGetFileSize(void* hFile, unsigned int* pdwFileSizeHigh); // 0x00416370
void __stdcall SFileSetAsyncBudget(int nValue); // 0x004164A0
void __stdcall SFileSetDataChunkSize(int nChunkSize); // 0x00416570
int __stdcall SFileSetIoErrorMode(int nValueA, int nValueB); // 0x004166B0
int __stdcall SFileCloseFile(void* hFile); // 0x004198D0
int __stdcall SFileOpenFile(const char* szFileName, void** phFile); // 0x00419980
void __stdcall SFileCancelRequest(void* pBuffer); // 0x0041A930
int __stdcall SFileDdaEnd(void* hFile); // 0x0041A990
void __stdcall SFilePrioritizeRequest(void* pBuffer, int nValue); // 0x0041AA80
int __stdcall SFileReadFileEx2(void* hFile, unsigned char* buffer, unsigned int size, unsigned int* read, D2StormOverlappedStrc* overlap, int nArg6, void* callback); // 0x0041AAD0
int __stdcall SFileReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped); // 0x0041B050
int __stdcall SFileDdaBeginEx(void* hFile, unsigned int nBufferSize, unsigned int nFlags, unsigned int nOffset, int nVolume, int nPan, D2StormSoundBufferStrc* pBuffer); // 0x0041B280
int __stdcall SFileOpenArchive(const char* szMpqName, int nPriority, unsigned int dwFlags, void** phMpq); // 0x0041BA60
int __stdcall StormGetOption(unsigned int nOption, const void* pInput, unsigned int nSize); // 0x0041BFC0
void __fastcall SetErrorReportCallback(void* pCallback); // 0x0041C0E0
void __cdecl LockErrorState(); // 0x0041C1A0
void __cdecl UnlockErrorState(); // 0x0041C1E0
int __stdcall SErrDisplayError(unsigned int nErrorCode,const char* szFile,int nLine,const char* szDescription,int bRecoverable,unsigned int nExitCode); // 0x0041CAF0
void __stdcall SMemZero(void* pLocation, unsigned int nLength); // 0x0041D300
int __stdcall SBigCompare(D2StormBigStrc* pA, D2StormBigStrc* pB); // 0x00421530
void __stdcall SBigAdd(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB); // 0x00423790
void __stdcall SBigFromUnsigned(D2StormBigStrc* pBig, unsigned int nValue); // 0x004238B0
void __stdcall SBigShl(D2StormBigStrc* pResult, D2StormBigStrc* pA, unsigned int nShift); // 0x00423A80
void __stdcall SBigSub(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB); // 0x00423AC0
void __stdcall SBigDiv(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB); // 0x00424E70
void __stdcall SBigMod(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB); // 0x00424ED0
int __stdcall SBigMul(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB); // 0x00424F10
int __stdcall SBigIsPrime(D2StormBigStrc* pBig); // 0x004255C0
int __stdcall SEvtPopState(unsigned int nType, unsigned int nSubType); // 0x004269C0
void __cdecl sub_0042B9D0_Nop(); // 0x0042B9D0
void __cdecl sub_00650EA0_Nop(); // 0x00650EA0
int __stdcall SCmdRegisterArgList(D2CmdArg006C4E50Strc* pArgs, unsigned int nCount); // 0x006C4E50
int __stdcall SUniConvertUTF16to8(char* pDest, unsigned int nDestSize, const unsigned short* pSrc, unsigned int nSrcLength, unsigned int* pDestWritten, unsigned int* pSrcRead); // 0x006C7130
int __stdcall SUniConvertUTF8to16(unsigned short* pDst, unsigned int nDstMax, const unsigned char* pSrc, unsigned int nSrcMax, unsigned int* pnDstWritten, unsigned int* pnSrcRead); // 0x006C7410
int __stdcall SUniConvertWinToUTF16(unsigned short* pDest, const unsigned char* pSource, unsigned int nCount); // 0x006C7960

extern "C" int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags); // 0x00412650
extern "C" void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int dwFlags); // 0x00413020
extern "C" void* __stdcall SMemReAlloc(void* pMemory, unsigned int nSize, const char* szFile, int nLine, unsigned int dwFlags); // 0x004133D0
char* __stdcall SStrDup(const char* szString); // 0x00414310
unsigned long __stdcall SFileSetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x004165A0
int __stdcall SFileAuthenticateArchive(void* hArchive, unsigned int* pnResult); // 0x004172F0
int __stdcall SFileOpenFileEx(void* hMpq, const char* szFileName, unsigned int dwFlags, void** phFile); // 0x004192F0
int __stdcall SFileLoadFile(const char* szFileName, void** ppBuffer, unsigned int* pSize, unsigned int nExtraSize, void* pOverlapped); // 0x0041B650
void __stdcall SErrSetLastError(unsigned int dwErrCode); // 0x0041C340
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith); // 0x0041D2C0
void __stdcall SLogClose(void* hLog); // 0x0041FD00
int __stdcall SLogCreate(const char* szFileName, unsigned long dwFlags, void** phLog); // 0x0041FD40
void __cdecl SLogWrite(void* hLog, const char* szFormat, ...); // 0x00420190
int __stdcall SMsgPopRegisterState(void* pContext); // 0x00420320
int __stdcall SMsgPushRegisterState(int nType); // 0x00420360
extern void* gpStormOwnerB_007790C4; // 0x007790C4
extern unsigned long gdwStormOwnerThread_007790C8; // 0x007790C8
