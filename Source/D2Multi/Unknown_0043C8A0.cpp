#include "D2Multi.h"
#include "D2MsgRecord.h"
#include "D2ClientTypes.h"
#include "D2FogTypes.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Drlg.h"
#include "D2LevelTxt.h"
#include "D2StormTypes.h"
#include "D2Unicode.h"
#include "D2MultiTypes.h"
#include "D2Win32Types.h"
#include "D2Win32System.h"
#include "D2MultiCharSave.h"
#include "FogApi.h"
#include "StormApi.h"
#include "FogApi.h"
struct _iobuf;

typedef struct _iobuf FILE;

extern "C" const char gszEmptyAssertText_006CC837; // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


extern "C" FILE* __cdecl fopen(const char* szFileName, const char* szMode); // 0x0068239A

extern "C" unsigned int __cdecl fread(void* pBuffer, unsigned int nSize, unsigned int nCount, FILE* pFile); // 0x00684782

extern "C" int __cdecl fclose(FILE* pFile); // 0x00681FDC

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

#pragma intrinsic(memcpy)


void __stdcall FOG_Encode14BitsToString(unsigned char* pStream, unsigned short nValue); // 0x006BBF40

extern const char gszDefaultSaveName_0070CCC8[]; // 0x0070CCC8

unsigned int __stdcall FOG_ComputeChecksum(const unsigned char* pData, unsigned int nSize); // 0x00411130
extern "C" const char gszSaveFormat_006D4230[]; // 0x006D4230
D2CharSaveHeaderStrc gtCharSaveHeader; // 0x0077AC10
// build: symbol ??__EgdwHeaderHash_0077AD64@@YAXXZ 0x006CA960
extern unsigned int gdwHeaderHash_0077AD64; // 0x0077AD64
unsigned int gdwHeaderHash_0077AD64 = SStrHash("Header", 0, 0);
// build: symbol ??__EgdwGameTimeHash_0077AD60@@YAXXZ 0x006CA980
extern unsigned int gdwGameTimeHash_0077AD60; // 0x0077AD60
unsigned int gdwGameTimeHash_0077AD60 = SStrHash("Game Time", 0, 0);

// 0x0043C8A0
int __fastcall sub_0043C8A0_ReadSaveSummary(const char* szName, unsigned char* pOut)
{
    int bResult = 0;
    if (!szName[0])
    {
        FOG_DisplayHalt(&gszEmptyAssertText_006CC837, sub_00408090(), 0xE9);
        exit(-1);
    }

    char szSaveDir[0x400];
    FOG_GetSavePath(szSaveDir, 0x400);

    char szPath[500];
    sprintf(szPath, "%s%s.d2s", szSaveDir, szName);
    FILE* pFile = fopen(szPath, "rb");
    if (!pFile)
        return 0;

    unsigned char aBuffer[0x2000];
    unsigned int nRead = fread(aBuffer, 1, 0x2000, pFile);
    if (nRead >= 8 && *(unsigned int*)aBuffer == 0xAA55AA55)
    {
        unsigned int nVersion = *(unsigned int*)(aBuffer + 4);
        const char* pCharName;
        unsigned char nLevel;
        unsigned short nFlags;
        unsigned char nClass;
        const char* pTitle;

        if (nVersion <= 0x5B)
        {
            if (nRead < 0x82 || nVersion < 0x47)
                goto close_dialog;
            pCharName = (const char*)aBuffer + 0x26;
            pTitle = (const char*)aBuffer + 0x36;
            nClass = aBuffer[0x22];
            nLevel = aBuffer[0x24];
            nFlags = *(unsigned short*)(aBuffer + 0x18);
        }
        else
        {
            if (nRead < 0x14F || nVersion > 0x60)
                goto close_dialog;
            pCharName = (const char*)aBuffer + 0x88;
            pTitle = (const char*)aBuffer + 0x98;
            nClass = aBuffer[0x28];
            nLevel = aBuffer[0x2B];
            nFlags = *(unsigned short*)(aBuffer + 0x24);
        }

        FOG_Encode14BitsToString(pOut, 0xE);
        pOut += 2;
        if (!pCharName[0])
        {
            for (int i = 0; i < 11; ++i)
                *pOut++ = gszDefaultSaveName_0070CCC8[i];
        }
        else
        {
            memcpy(pOut, pCharName, 11);
            pOut += 11;
        }
        *pOut++ = nClass + 1;
        memcpy(pOut, pTitle, 11);
        pOut += 11;
        *pOut++ = nLevel;
        FOG_Encode14BitsToString(pOut, nFlags);
        pOut += 2;
        FOG_Encode14BitsToString(pOut, 0);
        pOut += 2;
        *pOut++ = 0xFF;
        *pOut++ = 0xFF;
        *pOut = 0xFF;
        pOut[1] = 0;
        bResult = 1;
    }

close_dialog:
    fclose(pFile);
    return bResult;
}

// 0x0043CAA0
int __fastcall CHATDLG_UpdateSaveFlags(const char* szName)
{
    D2CharSaveFileStrc tSave;
    char szDir[0x400];
    char szPath[0x1F4];
    unsigned long dwFlags;
    unsigned long dwWritten;
    unsigned long dwRead;

    FOG_GetSavePath(szDir, 0x400);
    sprintf(szPath, gszSaveFormat_006D4230, szDir, szName);

    void* hFile = FOG_CreateFileA(szPath, 0xC0000000, 0, 0, 3, 0x8000000, 0);
    if (!hFile)
        return 0;

    FOG_ReadFile(hFile, &tSave, 0x2000, &dwRead, 0);
    if (dwRead < 8)
        return 0;
    if (tSave.dwMagic != 0xAA55AA55)
        return 0;

    int nResult;
    if (tSave.dwVersion <= 0x5B)
    {
        if (dwRead < 0x82)
            return 0;
        dwFlags = tSave.dwOldFlags | 0x20;
        FOG_SetFilePointer(hFile, 0x18, 0, 0);
        nResult = FOG_WriteFile(hFile, &dwFlags, 4, &dwWritten, 0);
    }
    else
    {
        if (dwRead < 0x14F)
            return 0;
        tSave.dwFlags |= 0x20;
        tSave.dwChecksum = 0;
        tSave.dwChecksum = FOG_ComputeChecksum((const unsigned char*)&tSave, dwRead);
        FOG_SetFilePointer(hFile, 0, 0, 0);
        nResult = FOG_WriteFile(hFile, &tSave, dwRead, &dwWritten, 0);
    }

    FOG_CloseFile(hFile);
    return nResult;
}
extern "C" const char* gData_0070CC8C[15] = { // 0x0070CC8C
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
