#pragma once

#include "D2SysTypes.h"

struct D2CriticalSectionStrc;

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(); // 0x006CC1B4
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC
extern "C" __declspec(dllimport) void __stdcall SetLastError(unsigned long dwErrCode); // 0x006CC2E4
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" double __cdecl log(double x); // 0x00687AC0
extern "C" double __cdecl pow(double x, double y); // 0x00687C10
extern int gnSoundMasterVolume; // 0x0072F9B0
extern int gnSoundState_00881764; // 0x00881764
float __stdcall sub_005165F0_ToDecibels(float fMin, float fMax, float fValue); // 0x005165F0
int __cdecl D2SOUND_IsExpansion(); // 0x00513AE0
int __cdecl D2SOUND_IsPositionalSoundEnabled(); // 0x00513B60
int __cdecl D2SOUND_IsEaxEnabled(); // 0x00513B70
int __cdecl D2SOUND_GetEaxVersion(); // 0x00513B90
int __cdecl sub_00513BB0(); // 0x00513BB0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
int __stdcall sub_00418140(void* hSample, unsigned int* pValueA, unsigned int* pValueB); // 0x00418140
void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...); // 0x00410610
int __fastcall FOG_FCloseFile(void* pArg); // 0x004068F0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

struct D2ComObjectStrc
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct D2GuidStrc
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

// build: symbol ?FOG_DisplayHalt@* 0x00408A60
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
