#include "D2CMP.h"
#include "FogApi.h"
#include "StormApi.h"

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileSize(void* hFile, unsigned long* pFileSizeHigh);

int __fastcall FASTCMP_LoadPcxPalette(const char* szFileName);                                         // 0x00605340
extern unsigned int gnPaletteEnd;                                                                  // 0x008E902C
extern unsigned int gnPaletteStart;                                                                // 0x008E9930
extern int ganSquareTable[511];                                                                     // 0x008E9034
extern unsigned int gdwSwappedColor;                                                               // 0x008E9D38
int gbPaletteLoaded;                                                                               // 0x008E9934
unsigned char gaPaletteRaw[0x300];                                                                 // 0x008E8D28
unsigned char gaPcxPalette[256 * 4];                                                               // 0x008E9938

// 0x006054F0
int __stdcall PaletteInit(const char* szFile, int nStart, int nEnd)
{
    D2_ASSERT(szFile, 0x3B6);
    D2_ASSERT(nStart <= nEnd, 0x3B7);
    D2_ASSERT(nStart >= 0, 0x3B8);
    D2_ASSERT(nEnd < 0x100, 0x3B9);

    gnPaletteEnd = nEnd;
    gnPaletteStart = 1;
    for (int i = -0x100; i < 0x100; i++)
    {
        gnSquareTableCenter_008E9430[i] = i * i;
    }

    gdwSwappedColor = 0;
    if (SStrLen(szFile))
    {
        void* hFile = CreateFileA(szFile, 0x80000000, 1, 0, 3, 0, 0);
        if (hFile == (void*)-1)
        {
            OutputDebugStringA("Unable to open ");
            OutputDebugStringA(szFile);
// build: symbol ?gszNewline@* 0x006FFCB0
            OutputDebugStringA(gszNewline);
            return 0;
        }

        if (GetFileSize(hFile, (unsigned long*)&nStart) == 0x300)
        {
            unsigned long nRead = 0;
            ReadFile(hFile, gaPaletteRaw, 0x300, &nRead, 0);
            if (nRead == 0x300)
            {
                for (unsigned int i = 0; i < 0x100; ++i)
                {
                    gaPcxPalette[i * 4 + 2] = gaPaletteRaw[i * 3 + 0];
                    gaPcxPalette[i * 4 + 1] = gaPaletteRaw[i * 3 + 1];
                    gaPcxPalette[i * 4 + 0] = gaPaletteRaw[i * 3 + 2];
                }

                gbPaletteLoaded = 1;
                CloseHandle(hFile);
                return gbPaletteLoaded;
            }

            gbPaletteLoaded = 0;
            CloseHandle(hFile);
            return gbPaletteLoaded;
        }

        CloseHandle(hFile);
        gbPaletteLoaded = FASTCMP_LoadPcxPalette(szFile);
        return gbPaletteLoaded;
    }

    for (unsigned int i = 0; i < 0x100; ++i)
    {
        gaPcxPalette[i * 4 + 0] = (unsigned char)i;
        gaPcxPalette[i * 4 + 1] = (unsigned char)i;
        gaPcxPalette[i * 4 + 2] = (unsigned char)i;
    }

    gbPaletteLoaded = 1;
    return 1;
}
