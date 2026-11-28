#include "D2Sound.h"
#include "D2SoundTypes.h"

struct D2SoundListNodeStrc;
struct D2SoundNode00516980Strc;
struct Node005169D0;
struct D2SoundNodeStrc;
struct D2FixedFileInfoStrc;
struct D2VxdResourceStrc;
struct D2VxdHeaderStrc;
struct D2DosHeaderStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" const char gszD2SoundUtilFile[]; // 0x006DEB68

struct D2SoundListNodeStrc
{
    void* pData;
    D2SoundListNodeStrc* pNext;
};

struct D2SoundNode00516980Strc
{
    int nId;
    D2SoundNode00516980Strc* pNext;
};

struct Node005169D0 { int nId; Node005169D0* pNext; };

struct D2FixedFileInfoStrc
{
    unsigned int dwSignature;
    unsigned int dwStrucVersion;
    unsigned short wFileVersionMSLow;
    unsigned short wFileVersionMSHigh;
    unsigned short wFileVersionLSLow;
};

int __fastcall D2SOUNDUTIL_ReadVxdVersionResource(const char* szFileName, unsigned long* pSize, void* pBuffer); // 0x00516AC0
extern "C" int __stdcall VerQueryValueA(const void* pBlock, const char* szSubBlock, void** ppBuffer, unsigned int* puLen); // 0x006B01A4
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* lpFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* lpSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C
extern "C" __declspec(dllimport) void* __stdcall CreateFileMappingA(void* hFile, void* lpAttributes, unsigned long flProtect, unsigned long dwMaximumSizeHigh, unsigned long dwMaximumSizeLow, const char* lpName); // 0x006CC314
extern "C" __declspec(dllimport) void* __stdcall MapViewOfFile(void* hFileMappingObject, unsigned long dwDesiredAccess, unsigned long dwFileOffsetHigh, unsigned long dwFileOffsetLow, unsigned long dwNumberOfBytesToMap); // 0x006CC310
extern "C" __declspec(dllimport) int __stdcall UnmapViewOfFile(const void* lpBaseAddress); // 0x006CC2F8
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

struct D2VxdResourceStrc
{
    int unk0x00[2];
    unsigned long nSize;
    unsigned char pData[4];
};

struct D2VxdHeaderStrc
{
    unsigned long dwSignature;
    unsigned char unk0x04[0xB4];
    unsigned long dwResourceOffset;
    unsigned long dwResourceLength;
};

struct D2DosHeaderStrc
{
    unsigned short e_magic;
    unsigned short unk0x02[29];
    long nHeaderOffset;
};

// 0x00516950
void __fastcall D2SOUNDUTIL_ListAddHead(D2SoundListNodeStrc** ppList, void* pData)
{
    D2SoundListNodeStrc* pNode = (D2SoundListNodeStrc*)FOG_Alloc(sizeof(D2SoundListNodeStrc), gszD2SoundUtilFile, 0xD5, 0);
    memset(pNode, 0, sizeof(D2SoundListNodeStrc));
    D2SoundListNodeStrc* pHead = *ppList;
    pNode->pData = pData;
    pNode->pNext = pHead;
    *ppList = pNode;
}

// 0x00516980
void __fastcall D2SOUNDUTIL_ListRemove(D2SoundNode00516980Strc** ppList, int nId)
{
    D2SoundNode00516980Strc* pPrev = 0;
    for (D2SoundNode00516980Strc* pNode = *ppList; pNode; pNode = pNode->pNext)
    {
        if (pNode && pNode->nId == nId)
        {
            if (*ppList == pNode)
            {
                *ppList = pNode->pNext;
            }
            if (pPrev)
            {
                pPrev->pNext = pNode->pNext;
            }
            FOG_Free(pNode, ".\\Src\\D2SoundUtil.cpp", 0xF1, 0);
            return;
        }
        pPrev = pNode;
    }
}

// 0x005169D0
extern "C" __declspec(dllexport) int __fastcall D2SOUNDUTIL_ListContains(Node005169D0* pNode, int nId) {
    for (; pNode; pNode = pNode->pNext) {
        if (pNode->nId == nId) {
            return 1;
        }
    }
    return 0;
}

// 0x005169F0
int __fastcall D2SOUNDUTIL_ListCount(D2SoundListNodeStrc* pNode)
{
    int nCount = 0;
    while (pNode)
    {
        pNode = pNode->pNext;
        ++nCount;
    }

    return nCount;
}

static inline void RemoveNode(D2SoundNodeStrc** ppList, int nKey)
{
    D2SoundNodeStrc* pPrev = 0;
    for (D2SoundNodeStrc* pNode = *ppList; pNode; pNode = pNode->pNext)
    {
        if (pNode && pNode->nKey == nKey)
        {
            if (*ppList == pNode)
            {
                *ppList = pNode->pNext;
            }
            if (pPrev)
            {
                pPrev->pNext = pNode->pNext;
            }
            FOG_Free(pNode, ".\\Src\\D2SoundUtil.cpp", 0xF1, 0);
            return;
        }
        pPrev = pNode;
    }
}

// 0x00516A10
void __fastcall D2SOUNDUTIL_ListFree(D2SoundNodeStrc** ppList)
{
    while (*ppList)
    {
        RemoveNode(ppList, (*ppList)->nKey);
    }
}

// 0x00516A70
void __fastcall D2SOUNDUTIL_ListAddTail(D2SoundNodeStrc** ppList, int nKey)
{
    D2SoundNodeStrc* pNew = (D2SoundNodeStrc*)FOG_Alloc(sizeof(D2SoundNodeStrc), ".\\Src\\D2SoundUtil.cpp", 0x120, 0);
    memset(pNew, 0, sizeof(D2SoundNodeStrc));
    pNew->nKey = nKey;

    for (D2SoundNodeStrc* pNode = *ppList; pNode; pNode = pNode->pNext)
    {
        if (!pNode->pNext)
        {
            pNode->pNext = pNew;
            return;
        }
    }

    *ppList = pNew;
}

// 0x00516AC0
int __fastcall D2SOUNDUTIL_ReadVxdVersionResource(const char* szFileName, unsigned long* pSize, void* pBuffer)
{
    void* hFile = 0;
    void* hMapping = 0;
    void* pView = 0;
    int bResult = 0;
    __try
    {
        hFile = CreateFileA(szFileName, 0x80000000, 1, 0, 3, 0, 0);
        if (hFile == (void*)-1)
            __leave;

        hMapping = CreateFileMappingA(hFile, 0, 2, 0, 0, 0);
        if (!hMapping)
            __leave;

        pView = MapViewOfFile(hMapping, 4, 0, 0, 0);
        if (!pView)
            __leave;

        const D2DosHeaderStrc* pDos = (const D2DosHeaderStrc*)pView;
        if (pDos->e_magic != 0x5A4D)
        {
            SetLastError(0x0B);
            __leave;
        }

        const D2VxdHeaderStrc* pHeader = (const D2VxdHeaderStrc*)((const char*)pDos + pDos->nHeaderOffset);
        if (pHeader->dwSignature != 0x454C)
        {
            SetLastError(0x0B);
            __leave;
        }

        if (!pHeader->dwResourceLength)
        {
            *pSize = 0;
            SetLastError(0x714);
            __leave;
        }

        const D2VxdResourceStrc* pResource = (const D2VxdResourceStrc*)((const char*)pDos + pHeader->dwResourceOffset);
        const unsigned long nSize = pResource->nSize;
        const unsigned char* pData = pResource->pData;
        if (pBuffer && *pSize >= nSize)
        {
            memset(pBuffer, 0, *pSize);
            memcpy(pBuffer, pData, nSize);
            *pSize = nSize;
            SetLastError(0);
            bResult = 1;
        }
        else
        {
            *pSize = nSize;
            SetLastError(0x7A);
        }
    }
    __finally
    {
        const unsigned long dwError = GetLastError();
        if (pView)
            UnmapViewOfFile(pView);
        if (hMapping)
            CloseHandle(hMapping);
        if (hFile != (void*)-1)
            CloseHandle(hFile);
        SetLastError(dwError);
    }

    return bResult;
}

// 0x00516C40
unsigned long __fastcall D2SOUNDUTIL_GetVxdVersionInfoSize(const char* szPath)
{
    unsigned long nSize = 0;
    if (!D2SOUNDUTIL_ReadVxdVersionResource(szPath, &nSize, 0) && GetLastError() == 0x7A)
    {
        SetLastError(0);
        return nSize;
    }
    return 0;
}

// 0x00516C80
int __fastcall D2SOUNDUTIL_GetVxdVersionInfo(const char* szPath, unsigned long nSize, void* pBuffer)
{
    return D2SOUNDUTIL_ReadVxdVersionResource(szPath, &nSize, pBuffer);
}

// 0x00516CA0
int __fastcall D2SOUNDUTIL_GetVxdFileVersion(const char* szPath, unsigned int* pMajor, unsigned int* pMinor, unsigned int* pBuild)
{
    unsigned long nSize = D2SOUNDUTIL_GetVxdVersionInfoSize(szPath);
    if (!nSize)
        return 0;

    void* pBuffer = FOG_Alloc(nSize, gszD2SoundUtilFile, 0x21C, 0);
    if (!D2SOUNDUTIL_GetVxdVersionInfo(szPath, nSize, pBuffer))
    {
        FOG_Free(pBuffer, gszD2SoundUtilFile, 0x221, 0);
        return 0;
    }

    D2FixedFileInfoStrc* pInfo;
    unsigned int nInfoLen;
    if (!VerQueryValueA(pBuffer, "\\", (void**)&pInfo, &nInfoLen))
    {
        FOG_Free(pBuffer, gszD2SoundUtilFile, 0x229, 0);
        return 0;
    }

    *pMajor = pInfo->wFileVersionMSHigh;
    *pMinor = pInfo->wFileVersionMSLow;
    *pBuild = pInfo->wFileVersionLSLow;
    return 1;
}

extern "C" const char* gData_0072F9B4[15] = { // 0x0072F9B4
    "English",
    "Spanish",
    "German",
    "French",
    "Portuguese",
    "Italian",
    "Japanese",
    "Korean",
    "Simplified Chinese",
    "Traditional Chinese",
    "Polish",
    "Russian",
    "English with Korean Chat",
    "Unknown",
    "14"
};
