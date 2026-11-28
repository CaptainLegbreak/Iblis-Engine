#pragma once
// D2Hell's exports that the other modules call.

struct D2ArchiveHandleStrc;

bool __fastcall sub_00516D8B_RunSurvey(const char* szExePath); // 0x00516D8B
bool __fastcall sub_00516DE1_Verify(void* pContext); // 0x00516DE1
int __fastcall ARCHIVE_OpenFile(void* pUnused, const char* szFileName, void** phFile, int bAllowMissing); // 0x00516E46
void __fastcall ARCHIVE_CloseFile(void* pUnused, void* hFile); // 0x00516E84
int __fastcall ARCHIVE_SetFilePointer(void* unused, void* file, long nOffset, long* pnOffsetHigh, int nMethod); // 0x00516F14
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85
void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFilePath, unsigned int* pdwBytesWritten, const char* szSrcPath, int nLine); // 0x00517079
void __fastcall ARCHIVE_UnloadMPQFile(D2ArchiveHandleStrc* pArchive); // 0x005173AC
int __fastcall sub_0051740B_ErrorBox(const char* text); // 0x0051740B
void __fastcall sub_005177B2_SetLoadStringFn(void* pfnLoadString); // 0x005177B2
void __cdecl sub_0051793E_FormatAndRaise(unsigned long dwError, ...); // 0x0051793E
void __fastcall sub_005179A4_FreeVirtualMemory(void* address); // 0x005179A4
void __fastcall sub_005179B3_CopyRect(unsigned char* pDest, const unsigned char* pSource, int nDestPitch, int nSourcePitch, int nRows, int nWidth); // 0x005179B3
int __cdecl sub_00517ABB_FindLowestSetBit(unsigned int dwMask); // 0x00517ABB
unsigned int __fastcall CRC32_Compute(void* pData, unsigned int dwSize); // 0x006C99F6
int __fastcall sub_006C9A38_StringLength(char* pString); // 0x006C9A38
