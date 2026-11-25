#include "D2Hell.h"

struct D2ArchiveHandleStrc;

int __fastcall ARCHIVE_OpenFile(void* pUnused, const char* szFileName, void** phFile, int bAllowMissing); // 0x00516E46

void __fastcall ARCHIVE_CloseFile(void* pUnused, void* pFile); // 0x00516E84

unsigned int __fastcall ARCHIVE_GetFileSize(void* unused, void* file, unsigned int* high); // 0x00516EAB

void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

extern "C" __declspec(dllimport) char* __stdcall lstrcpyA(char* szDst, const char* szSrc);

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);

static void* __stdcall ARCHIVE_FindAndOpenArchive(char* szOutPath, const char* szFileName, int nPriority, int bSomething); // 0x00517299

int __stdcall SFileCloseArchive(void* hArchive); // 0x00419A80

int __fastcall FOG_FCloseFile(void* pArg); // 0x004068F0

// build: symbol ?FOG_DisplayHalt@* 0x00408A60
#define D2_ASSERT(expr,line) if(!(expr)) {FOG_DisplayHalt(&gszEmptyAssertText,sub_00408090(),line);exit(-1);}

int __fastcall FOG_FGetFileSize(void*,unsigned int*);  // 0x00406930

int __stdcall CopyFileRecName(void*,char*,unsigned int); // 0x00416230

#define FAIL_LINE 0x5F

#define NAME_SIZE 0x104

#define NULL_LINE 0x59

int __fastcall FOG_FReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6); // 0x00406900

int __fastcall FOG_FSetFilePointer(void* hFile, long nOffset, long* pnOffsetHigh, int nMethod); // 0x00406940

typedef unsigned long DWORD;

extern "C" __declspec(dllimport) DWORD __stdcall GetLastError(void);

static int __stdcall ARCHIVE_FindArchive(const char* filename,int priority,void** outHandle,char* path); // 0x00517128

D2ArchiveHandleStrc* __fastcall ARCHIVE_LoadMPQFile(const char* szName, const char* szModule, ARCHIVE_ShowMessageFunctionPtr pfShowMessage, int nPriority);

extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void* hModule, char* szFileName, unsigned long nSize); // 0x006CC1BC


static void ARCHIVE_GetModuleDirectory(char* szPath); // 0x005170E7

// 0x00516E46
int __fastcall ARCHIVE_OpenFile(void* pUnused, const char* szFileName, void** phFile, int bAllowMissing)
{
// build: symbol ?FOG_FOpenFile@* 0x004068E0
    if (FOG_FOpenFile(szFileName, phFile))
        return 1;

    DWORD dwError = GetLastError();
    if (!bAllowMissing || dwError != 2)
        LOGMANAGER_WriteLogLine("Error opening file: %s", szFileName);
    return 0;
}

// 0x00516E84
void __fastcall ARCHIVE_CloseFile(void* pUnused, void* hFile)
{
    if (!hFile)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 73);
        exit(-1);
    }

    FOG_FCloseFile(hFile);
}

// 0x00516EAB
unsigned int __fastcall ARCHIVE_GetFileSize(void* unused,void* file,unsigned int* high) {
 char name[NAME_SIZE];
 D2_ASSERT(file,NULL_LINE);
 unsigned int size=FOG_FGetFileSize(file,high);
 if(!size) {
  CopyFileRecName(file,name,NAME_SIZE);
  D2_ASSERT(0,FAIL_LINE);
 }
 return size;
}

// 0x00516F14
int __fastcall ARCHIVE_SetFilePointer(void* unused, void* file, long nOffset, long* pnOffsetHigh, int nMethod)
{
    char name[0x104];
    D2_ASSERT(file, 0x70);
    int nResult = FOG_FSetFilePointer(file, nOffset, pnOffsetHigh, nMethod);
    if (nResult != -1)
    {
        return nResult;
    }

    CopyFileRecName(file, name, 0x104);
    D2_ASSERT(0, 0x79);
}

// 0x00516F85
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead)
{
    D2_ASSERT(hFile, 0x87);

    int dwBytes;
    if (!FOG_FReadFile(hFile, pBuffer, dwBytesToRead, &dwBytes, 0, 0, 0))
    {
        char szArchivePath[0x104];
        CopyFileRecName(hFile, szArchivePath, sizeof(szArchivePath));
        D2_ASSERT(0, 0x8F);
    }

    D2_ASSERT(dwBytesToRead == dwBytes, 0x92);
}

// 0x00517015
unsigned int __fastcall ARCHIVE_ReadFileToSizedBuffer(void* hArchive, const char* szFilePath, void* pBuffer, unsigned int dwBufferSize)
{
    void* hFile;
    ARCHIVE_OpenFile(hArchive, szFilePath, &hFile, 0);
    D2_ASSERT(dwBufferSize >= ARCHIVE_GetFileSize(hArchive, hFile, 0), 0xA5);
    ARCHIVE_ReadFileToBuffer(hArchive, hFile, pBuffer, dwBufferSize);
    ARCHIVE_CloseFile(hArchive, hFile);
    return dwBufferSize;
}

// 0x00517079
void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFilePath, unsigned int* pdwBytesWritten, const char* szSrcPath, int nLine)
{
    void* hFile;
    if (!ARCHIVE_OpenFile(hArchive, szFilePath, &hFile, 0))
    {
        return 0;
    }

    unsigned int dwFileSizeHigh;
    unsigned int dwFileSize = ARCHIVE_GetFileSize(hArchive, hFile, &dwFileSizeHigh);
    void* pBuffer = FOG_Alloc(dwFileSize + 800, ".\\SRC\\Archive.cpp", 207, 0);
    if (!pBuffer)
    {
        return 0;
    }

    ARCHIVE_ReadFileToBuffer(hArchive, hFile, pBuffer, dwFileSize);
    ARCHIVE_CloseFile(hArchive, hFile);

    if (pdwBytesWritten)
    {
        *pdwBytesWritten = dwFileSize;
    }

    return pBuffer;
}

// 0x005170E7
static void ARCHIVE_GetModuleDirectory(char* szPath)
{
    GetModuleFileNameA(0, szPath, 260);
    szPath[259] = 0;
    char* pEnd = szPath;
    while (*pEnd && SStrChr(pEnd + 1, '\\'))
    {
        pEnd = (char*)SStrChr(pEnd + 1, '\\');
    }
    *pEnd = 0;
}

// 0x00517128
static int __stdcall ARCHIVE_FindArchive(const char* filename,int priority,void** outHandle,char* path)
{
 char drives[260];
 GetModuleFileNameA(0,path,260);
 path[259]=0;
 char* end=path;
 while(*end && SStrChr(end+1,'\\')) end=SStrChr(end+1,'\\');
 *end=0;
 SStrPack(path,"\\",0x7FFFFFFF);
 SStrPack(path,filename,0x7FFFFFFF);
 if(SFileOpenArchive(path,priority,2,outHandle)) return 1;
 unsigned long length=GetLogicalDriveStringsA(260,drives);
 if(!length || length>260) return 0;
 while(*filename=='\\') ++filename;
 char* current=drives;
 while(*current) {
  char* root=current;
  while(*current++) {}
  if(GetDriveTypeA(root)==5 && GetVolumeInformationA(root,0,0,0,0,0,0,0)) {
   SStrCopy(path,root,0x7FFFFFFF);
   SStrPack(path,filename,0x7FFFFFFF);
   if(SFileOpenArchive(path,priority,2,outHandle)) return 1;
  }
 }
 return 0;
}

// 0x00517299
static void* __stdcall ARCHIVE_FindAndOpenArchive(char* szOutPath, const char* szFileName, int nPriority, int bSomething)
{
    unsigned int nFlags = 2;
    if (bSomething)
    {
        nFlags = 3;
    }
    void* hArchive;
    SStrCopy(szOutPath, szFileName, 0x7FFFFFFF);
    if (SFileOpenArchive(szOutPath, nPriority, nFlags, &hArchive))
    {
        return hArchive;
    }
    if (!GetModuleFileNameA(0, szOutPath, 260))
    {
        *szOutPath = 0;
    }
    char* pLastBackslash = strrchr(szOutPath, '\\');
    if (pLastBackslash)
    {
        pLastBackslash[1] = 0;
    }
    SStrPack(szOutPath, szFileName, 0x7FFFFFFF);
    if (SFileOpenArchive(szOutPath, nPriority, nFlags, &hArchive))
    {
        return hArchive;
    }
    if (ARCHIVE_FindArchive(szFileName, nPriority, &hArchive, szOutPath))
    {
        return hArchive;
    }
    return 0;
}

// 0x00517332
D2ArchiveHandleStrc* __fastcall ARCHIVE_LoadMPQFile(const char* szName, const char* szModule, ARCHIVE_ShowMessageFunctionPtr pfShowMessage, int nPriority)
{
    D2ArchiveHandleStrc* pMpqHandle = (D2ArchiveHandleStrc*)FOG_Alloc(sizeof(D2ArchiveHandleStrc), ".\\SRC\\Archive.cpp", 0x20A, 0);
    pMpqHandle->hArchive = 0;
    do
    {
        pMpqHandle->hArchive = ARCHIVE_FindAndOpenArchive(pMpqHandle->szPath, szName, nPriority, (int)szModule);
        if (!pMpqHandle->hArchive)
        {
            if (!pfShowMessage || !pfShowMessage())
            {
                FOG_Free(pMpqHandle, ".\\SRC\\Archive.cpp", 0x21A, 0);
                return 0;
            }
            Sleep(100);
        }
    }
    while (!pMpqHandle->hArchive);
    return pMpqHandle;
}

// 0x005173AC
void __fastcall ARCHIVE_UnloadMPQFile(D2ArchiveHandleStrc* pArchive)
{
    if (pArchive->hArchive)
    {
        SFileCloseArchive(pArchive->hArchive);
    }
    pArchive->hArchive = 0;
    FOG_Free(pArchive, ".\\SRC\\Archive.cpp", 0x25C, 0);
}

int __cdecl EmitFindArchive(const char* filename,int priority,void** outHandle,char* path)
{
 return ARCHIVE_FindArchive(filename,priority,outHandle,path);
}


// calling-convention shim (not game code)
void __fastcall sub_005170E7_Shim(char* szPath)
{
    ARCHIVE_GetModuleDirectory(szPath);
}
