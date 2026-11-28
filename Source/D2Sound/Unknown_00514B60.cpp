#include "D2Sound.h"
#include "D2SysTypes.h"
#include "D2GfxTypes.h"
#include "D2Win32Base.h"
#include "D2DDrawTypes.h"
#include "D2GlideTypes.h"
#include "D2GameTypes.h"

#include "D2SoundTypes.h"
#include "StormApi.h"

extern int gnNpcSpeech;                                                                              // 0x008817BC

extern int gnSoundMode; // 0x008817AC

extern int gnMasterVolume; // 0x008817B0

extern int gnMusicVolume; // 0x008817B4

extern int gnPositionalBias; // 0x008817B8

extern int gnOptionsMusic; // 0x008817C0

extern int gnSoundMode; // 0x008817AC

extern int gnMusicVolume; // 0x008817B4

extern int gnOptionsMusic; // 0x008817C0


extern int gnMasterVolume; // 0x008817B0

extern int gnPositionalBias; // 0x008817B8

extern int gnNpcSpeech; // 0x008817BC

// 0x00514B60
void __cdecl D2SOUND_LoadRegistrySettings()
{
    unsigned long nValue;
    gnSoundMode = 0;
    gnMasterVolume = 100;
    gnMusicVolume = 50;
    gnPositionalBias = 50;
    gnNpcSpeech = 2;
    gnOptionsMusic = 1;
    if (SRegLoadValue("Diablo II", "Sound Mixer", 0, &nValue) && nValue < 3)
        gnSoundMode = nValue;
    if (SRegLoadValue("Diablo II", "Master Volume", 0, &nValue) && nValue <= 100)
        gnMasterVolume = nValue;
    if (SRegLoadValue("Diablo II", "Music Volume", 0, &nValue) && nValue <= 100)
        gnMusicVolume = nValue;
    if (SRegLoadValue("Diablo II", "Positional Bias", 0, &nValue) && nValue <= 100)
        gnPositionalBias = nValue;
    if (SRegLoadValue("Diablo II", "NPC Speech", 0, &nValue) && nValue < 3)
        gnNpcSpeech = nValue;
    if (SRegLoadValue("Diablo II", "Options Music", 0, &nValue) && nValue <= 1)
        gnOptionsMusic = nValue;
}

// 0x00514C90
int __cdecl D2SOUND_GetSoundMixerOption()
{
    return gnSoundMode;
}

// 0x00514CA0
int __fastcall D2SOUND_SetSoundMixerOption(int nValue)
{
    SRegSaveValue("Diablo II", "Sound Mixer", 0, nValue);
    gnSoundMode = nValue;
    return nValue;
}

// 0x00514CC0
int __cdecl D2SOUND_GetMasterVolumeOption()
{
    return gnMasterVolume;
}

// 0x00514CD0
int __fastcall D2SOUND_SetMasterVolumeOption(int nValue)
{
    SRegSaveValue("Diablo II", "Master Volume", 0, nValue);
    gnMasterVolume = nValue;
    return nValue;
}

// 0x00514CF0
int __cdecl D2SOUND_GetMusicVolumeOption()
{
    return gnMusicVolume;
}

// 0x00514D00
int __fastcall D2SOUND_SetMusicVolumeOption(int nValue)
{
    SRegSaveValue("Diablo II", "Music Volume", 0, nValue);
    gnMusicVolume = nValue;
    return nValue;
}

// 0x00514D20
int __cdecl D2SOUND_GetPositionalBiasOption()
{
    return gnPositionalBias;
}

// 0x00514D30
int __fastcall D2SOUND_SetPositionalBiasOption(int nValue)
{
    SRegSaveValue("Diablo II", "Positional Bias", 0, nValue);
    gnPositionalBias = nValue;
    return nValue;
}

// 0x00514D50
int __cdecl D2SOUND_GetNpcSpeechOption()
{
    return gnNpcSpeech;
}

// 0x00514D60
int __fastcall D2SOUND_SetNpcSpeech(int nValue)
{
    SRegSaveValue("Diablo II", "NPC Speech", 0, nValue);
    gnNpcSpeech = nValue;
    return nValue;
}

// 0x00514D80
int __cdecl D2SOUND_GetOptionsMusicOption()
{
    return gnOptionsMusic;
}

// 0x00514D90
int __fastcall D2SOUND_SetOptionsMusicOption(int nValue)
{
    SRegSaveValue("Diablo II", "Options Music", 0, nValue);
    gnOptionsMusic = nValue;
    return nValue;
}

extern "C" const char* gData_0072F8FC[15] = { // 0x0072F8FC
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
