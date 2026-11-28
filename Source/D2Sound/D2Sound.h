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
extern "C" double __cdecl log(double x); // 0x00687AC0
extern "C" double __cdecl pow(double x, double y); // 0x00687C10
extern int gnSoundMasterVolume; // 0x0072F9B0
extern int gbSoundReady; // 0x00881764
float __stdcall sub_005165F0_ToDecibels(float fMin, float fMax, float fValue); // 0x005165F0
int __cdecl D2SOUND_IsExpansion(); // 0x00513AE0
int __cdecl D2SOUND_IsPositionalSoundEnabled(); // 0x00513B60
int __cdecl D2SOUND_IsEaxEnabled(); // 0x00513B70
int __cdecl D2SOUND_GetEaxVersion(); // 0x00513B90
int __cdecl sub_00513BB0_GetValue(); // 0x00513BB0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
int __stdcall sub_00418140(void* hSample, unsigned int* pValueA, unsigned int* pValueB); // 0x00418140
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

struct D2SoundNodeStrc;
struct D2SoundStrc;
struct D2WaveFormatStrc;

void __cdecl D2SOUND_ReleaseSoundObjects(); // 0x00513AF0
void __cdecl D2SOUND_DestroyStreamChannel(); // 0x005147B0
int __cdecl D2SOUND_IsStreamChannelPlaying(); // 0x00514840
void __cdecl D2SOUND_ClearChannelTable(); // 0x00514860
int __cdecl D2SOUND_GetStreamChannelValue(); // 0x00514920
int __cdecl sub_00514990_PickRandomChannel(); // 0x00514990
void __cdecl D2SOUNDSMP_StopSoundThread(); // 0x00515120
int __fastcall D2SOUNDSMP_FillSoundBuffer(D2SoundStrc* sound,unsigned int sourcePosition,unsigned int destinationPosition,unsigned int size); // 0x00515180
D2SoundStrc* __fastcall D2SOUNDSMP_CreateSound(unsigned int nFlags, int nValue); // 0x00515530
void __fastcall D2SOUNDSMP_SetSoundVolume(D2SoundStrc* pSound, int nVolume); // 0x005157B0
void __fastcall D2SOUNDSMP_SetSoundPosition(D2SoundStrc* pSound, float x, float y, float z); // 0x00515950
void __fastcall D2SOUNDSMP_SetSoundAttenuation(D2SoundStrc* pSound, float fAttenuation); // 0x00515A90
int __fastcall D2SOUNDSMP_IsSoundStreaming(D2SoundStrc* pSound); // 0x00515C30
void __fastcall D2SOUNDSMP_StartSoundFade(D2SoundStrc* pFade, int nTarget, int nDuration); // 0x00515C60
void __fastcall D2SOUNDSMP_SetMasterVolume(int nVolume); // 0x00515CE0
int __cdecl D2SOUNDSMP_GetMasterVolume(); // 0x00515D60
int __fastcall D2SOUNDSMP_StartSoundStream(D2SoundStrc* pSound, const char* szFileName, int nPosition, int bLoop); // 0x00515D70
void __fastcall D2SOUNDSMP_CloseSoundStream(D2SoundStrc* pSound); // 0x00515E40
void __fastcall D2SOUNDSMP_StopSound(D2SoundStrc* pSound); // 0x00515EE0
int __fastcall D2SOUNDSMP_RestoreLostBuffer(D2SoundStrc* pSound); // 0x00515FD0
void __fastcall D2SOUNDSMP_DestroySound(D2SoundStrc* pSound); // 0x005160D0
void __fastcall D2SOUNDSMP_ResetSound(D2SoundStrc* pSound); // 0x00516140
unsigned long __stdcall D2SOUNDSMP_SoundThreadProc(void* pParameter); // 0x00516250
float __stdcall sub_00516670_RoomToVolume(float fRoom); // 0x00516670
void __fastcall D2SOUNDSMP_InitWaveFormat(D2WaveFormatStrc* pFormat, int nChannels); // 0x00516720
void __fastcall D2SOUNDUTIL_ListAddHead(D2SoundNodeStrc** ppList, void* pData); // 0x00516950
void __fastcall D2SOUNDUTIL_ListRemove(D2SoundNodeStrc** ppList, void* pData); // 0x00516980
