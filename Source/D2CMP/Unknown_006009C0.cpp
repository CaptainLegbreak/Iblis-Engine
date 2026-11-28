extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
#pragma intrinsic(strcpy, strcat)
int __fastcall ARCHIVE_OpenFile(void* hArchive, const char* szFilePath, void** phFile, int bFileNotFoundLogSkipped); // 0x00516E46
void __fastcall ARCHIVE_CloseFile(void* hArchive, void* hFile);                                             // 0x00516E84
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85

unsigned char gaItemShiftMaps[9][105][256];                                                                 // 0x008ADBB8

// build: symbol $SG2565 0x006DCD3C
// build: symbol $SG2566 0x006DCD34
// 0x006009C0
void __fastcall D2CMP_LoadItemPalShift(const char* szName, int nIndex)
{
    void* hFile;
    unsigned int nSize;

    {
        char szPath[0x100];

        strcpy(szPath, "Data\\Global\\Items\\Palette\\");
        strcat(szPath, szName);
        strcat(szPath, ".dat");
        nSize = 0x1500;
        if (!ARCHIVE_OpenFile(0, szPath, &hFile, 1))
        {
            D2_ASSERT(0, 0x39);
            memset(gaItemShiftMaps[nIndex], 0, nSize);
        }
        else
        {
            ARCHIVE_ReadFileToBuffer(0, hFile, gaItemShiftMaps[nIndex], nSize);
            ARCHIVE_CloseFile(0, hFile);
        }
    }
}
