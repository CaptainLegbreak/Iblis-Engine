#include "D2Direct3D.h"
#include "D2Win32Types.h"
#include "D2DDrawTypes.h"
#include "D2GfxTypes.h"

struct D2CriticalSectionStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0


extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall BinkNextFrame(D2BinkStrc* pBink); // 0x006CC5BC
extern "C" __declspec(dllimport) int __stdcall BinkCopyToBuffer(D2BinkStrc* pBink, void* pDest, int nDestPitch, unsigned int nDestHeight, unsigned int nDestX, unsigned int nDestY, unsigned int nFlags); // 0x006CC5C0
extern "C" __declspec(dllimport) int __stdcall BinkDoFrame(D2BinkStrc* pBink); // 0x006CC5C4
extern D2CriticalSectionStrc* gpRenderCriticalSection; // 0x007C9134
extern D2DDSurfaceStrc* gpSurface_00970E68; // 0x00970E68
extern unsigned int gnBinkX_00989C0C; // 0x00989C0C
extern D2BinkStrc* gpBink_00989C10; // 0x00989C10
extern int gbBinkDone_00989C1C; // 0x00989C1C
extern int gbSurfaceActive_007C9140; // 0x007C9140

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) long __stdcall DispatchMessageA(const tagMSG* pMsg); // 0x006CC478
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const tagMSG* pMsg); // 0x006CC47C
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(tagMSG* pMsg, void* hWnd, unsigned int uMsgFilterMin, unsigned int uMsgFilterMax, unsigned int wRemoveMsg); // 0x006CC480
extern "C" __declspec(dllimport) D2BinkStrc* __stdcall BinkOpen(void* hFile, unsigned int nFlags); // 0x006CC5B8
extern "C" __declspec(dllimport) int __stdcall BinkWait(D2BinkStrc* pBink); // 0x006CC5C8
extern "C" __declspec(dllimport) void __stdcall BinkClose(D2BinkStrc* pBink); // 0x006CC5CC
extern "C" __declspec(dllimport) unsigned int __stdcall BinkDDSurfaceType(D2DDSurfaceStrc* pSurface); // 0x006CC5D0
extern "C" __declspec(dllimport) int __stdcall BinkSetSoundSystem(void* pfOpen, unsigned long nParam); // 0x006CC5D4
extern "C" __declspec(dllimport) void* __stdcall BinkOpenDirectSound(unsigned long nParam); // 0x006CC5D8
int __cdecl FOG_UseDirect(); // 0x00406D20
int __stdcall SFileOpenFileEx(unsigned int hMpq, const char* szFileName, unsigned int dwFlags, void** phFile); // 0x004192F0
void __cdecl sub_006BBBF0_RenderVideoFrame(); // 0x006BBBF0
void __fastcall D2SOUNDSMP_SetMasterVolume(int nVolume); // 0x00515CE0
extern int gnRenderHeight; // 0x007C913C
extern unsigned int gnBinkY_00989C08; // 0x00989C08
extern unsigned int gnBinkFlags_00989C18; // 0x00989C18

unsigned int gnBinkY_00989C08; // 0x00989C08

unsigned int gnBinkFlags_00989C18; // 0x00989C18

// 0x006BBBF0
void __cdecl sub_006BBBF0_RenderVideoFrame()
{
    if (!gbSurfaceActive_007C9140)
        return;
    D2DDSurfaceDesc2Strc ddsd = { sizeof(D2DDSurfaceDesc2Strc) };
    BinkDoFrame(gpBink_00989C10);
    D2_ASSERT(gpRenderCriticalSection, 0x3D);
    EnterCriticalSection(gpRenderCriticalSection);
    if (gpSurface_00970E68->lpVtbl->Lock(gpSurface_00970E68, 0, &ddsd, 0x21, 0) == 0)
    {
        BinkCopyToBuffer(gpBink_00989C10, ddsd.lpSurface, ddsd.lPitch, gpBink_00989C10->nHeight, gnBinkX_00989C0C, gnBinkY_00989C08, gnBinkFlags_00989C18);
        gpSurface_00970E68->lpVtbl->Unlock(gpSurface_00970E68, 0);
    }
    LeaveCriticalSection(gpRenderCriticalSection);
    if (gpBink_00989C10->nFrameNum == gpBink_00989C10->nFrames)
    {
        gbBinkDone_00989C1C = 1;
        return;
    }
    BinkNextFrame(gpBink_00989C10);
}

unsigned int gnBinkX_00989C0C; // 0x00989C0C

D2BinkStrc* gpBink_00989C10; // 0x00989C10

int gbBinkDone_00989C1C; // 0x00989C1C

int gbBinkQuit_00989C20; // 0x00989C20

unsigned long gdwBinkAbortTick_00989C24; // 0x00989C24

// 0x006BBCE0
void __fastcall sub_006BBCE0_Run(const char* szFile, int nMode, void (__cdecl* pfCallback)())
{
    int bAbort = 0;
    gbBinkDone_00989C1C = 0;
    if (gpBink_00989C10)
    {
        return;
    }
// build: symbol ?gbRenderPaused@* 0x007C9144
    if (gbRenderPaused)
    {
        return;
    }

    gnBinkFlags_00989C18 = BinkDDSurfaceType(gpSurface_00970E68);
    BinkSetSoundSystem(BinkOpenDirectSound, 0);
    int nScope = 4;
    if (FOG_UseDirect())
    {
        nScope = 5;
    }

    void* hFile;
    SFileOpenFileEx(0, szFile, nScope, &hFile);
    if (!hFile)
    {
        goto FAIL;
    }

    unsigned int nFlags;
    nFlags = 0x800000;
    switch (nMode)
    {
    case 1:
        nFlags = 0x30800000;
        break;
    case 2:
        nFlags = 0x10800000;
        break;
    case 3:
        nFlags = 0x40800000;
        break;
    }
    gpBink_00989C10 = BinkOpen(hFile, nFlags);
    if (!gpBink_00989C10)
    {
        CloseHandle(hFile);
FAIL:
        if (gpBink_00989C10)
        {
            BinkClose(gpBink_00989C10);
            gpBink_00989C10 = 0;
        }
        return;
    }

// build: symbol ?gnRenderWidth@* 0x007C9138
    gnBinkX_00989C0C = (gnRenderWidth - gpBink_00989C10->nWidth) >> 1;
    if (gnBinkX_00989C0C & 3)
    {
        gnBinkX_00989C0C = (gnBinkX_00989C0C | 3) + 1;
    }
    gnBinkY_00989C08 = (gnRenderHeight - gpBink_00989C10->nHeight) >> 1;
    {
        const unsigned long dwEnd = GetTickCount() + 500;
        for (;;)
        {
            if (gbBinkDone_00989C1C && GetTickCount() >= dwEnd)
            {
                break;
            }
            if (gbRenderPaused)
            {
                break;
            }
            if (bAbort)
            {
                break;
            }
            if (pfCallback)
            {
                pfCallback();
            }

            tagMSG tMsg;
            if (PeekMessageA(&tMsg, 0, 0, 0, 1))
            {
                switch (tMsg.message)
                {
                case 0x12:
                    gbBinkDone_00989C1C = 1;
                    gbBinkQuit_00989C20 = 1;
                    break;
                case 0x102:
                case 0x201:
                case 0x204:
                case 0x207:
                    bAbort = 1;
                    gdwBinkAbortTick_00989C24 = GetTickCount();
                    break;
                }
                TranslateMessage(&tMsg);
                DispatchMessageA(&tMsg);
            }
            else if (!BinkWait(gpBink_00989C10))
            {
                sub_006BBBF0_RenderVideoFrame();
            }
            else
            {
                Sleep(1);
            }
        }
    }

    if (gpBink_00989C10)
    {
        D2SOUNDSMP_SetMasterVolume(0);
        BinkClose(gpBink_00989C10);
        CloseHandle(hFile);
        D2SOUNDSMP_SetMasterVolume(0xFF);
        gpBink_00989C10 = 0;
    }
    if (gbBinkQuit_00989C20)
    {
        exit(-1);
    }
}
