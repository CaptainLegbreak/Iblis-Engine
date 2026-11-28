#include "D2Sound.h"

extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);

extern int gdwGlobal_0072F830;                                                                              // 0x0072F830

int gbSoundEnumDone;                                                                               // 0x00881780

extern int gbCheckEmu10k1;                                                                         // 0x00881788

int gbCheckCrlds3d;                                                                                // 0x0088178C

// 0x00513A20
int __stdcall sub_00513A20_EnumCallback(void* pGuid, const char* szDescription, const char* szModule, void* pContext)
{
    if (pGuid && !gbSoundEnumDone)
    {
        if (!strcmp(szModule, "EMU10K1.VXD"))
            gbCheckEmu10k1 = 1;
        if (!strcmp(szModule, "es197x.vxd"))
            gbCheckCrlds3d = 1;
        if (!strcmp(szDescription, "Crystal SoundFusion(tm)"))
            gbCheckCrlds3d = 1;
        if (!strcmp(szModule, "YDSXG.VXD"))
            gdwGlobal_0072F830 = 0;
        if (!strcmp(szModule, "RIPTIDE.VXD"))
            gdwGlobal_0072F830 = 0;
        gbSoundEnumDone = 1;
    }
    return 1;
}

extern int gpDirectSound; // 0x00881768

extern int gfPositionalSound; // 0x0088176C

extern int gbEaxEnabled; // 0x00881770

extern int gnEaxVersion; // 0x00881774

extern int gbEaxRoomOff; // 0x00881778

extern int gfSoundExpansion; // 0x00881790

// 0x00513AE0
int __cdecl D2SOUND_IsExpansion()
{
    return gfSoundExpansion;
}

extern D2ComObjectStrc* gpSoundObject_008816D8; // 0x008816D8
extern D2ComObjectStrc* gpSoundObject; // 0x00881740
extern D2ComObjectStrc* gpEaxBuffer; // 0x00881744

// 0x00513AF0
void __cdecl D2SOUND_ReleaseSoundObjects()
{
    if (gpSoundObject_008816D8)
    {
        gpSoundObject_008816D8->Release();
        gpSoundObject_008816D8 = 0;
    }
    if (gpSoundObject)
    {
        gpSoundObject->Release();
        gpSoundObject = 0;
    }
    if (gpEaxBuffer)
    {
        gpEaxBuffer->Release();
        gpEaxBuffer = 0;
    }
}

// 0x00513B50
int __cdecl D2SOUND_GetDirectSound()
{
    return gpDirectSound;
}

// 0x00513B60
int __cdecl D2SOUND_IsPositionalSoundEnabled()
{
    return gfPositionalSound;
}

// 0x00513B70
int __cdecl D2SOUND_IsEaxEnabled()
{
    return gbEaxEnabled;
}

// 0x00513B80
int __cdecl sub_00513B80_AlwaysZero()
{
    return 0;
}

// 0x00513B90
int __cdecl D2SOUND_GetEaxVersion()
{
    return gnEaxVersion;
}

// 0x00513BA0
int __cdecl D2SOUND_IsEaxRoomOff()
{
    return gbEaxRoomOff;
}

// 0x00513BB0
int __cdecl sub_00513BB0_GetValue()
{
    return gdwGlobal_0072F830;
}

extern "C" const char* gData_0072F7F4[15] = { // 0x0072F7F4
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

int gdwGlobal_0072F830 = 1; // 0x0072F830

extern "C" unsigned char gData_0072F834[4] = { 0 }; // 0x0072F834
