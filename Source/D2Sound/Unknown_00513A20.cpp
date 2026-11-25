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

extern int gdwGlobal_00881768; // 0x00881768

extern int gdwGlobal_0088176C; // 0x0088176C

extern int gdwGlobal_00881770; // 0x00881770

extern int gdwGlobal_00881774; // 0x00881774

extern int gdwGlobal_00881778; // 0x00881778

int gdwGlobal_00881790; // 0x00881790

// 0x00513AE0
int __cdecl D2SOUND_IsExpansion()
{
    return gdwGlobal_00881790;
}

extern D2ComObjectStrc* gpSoundObject_008816D8; // 0x008816D8
extern D2ComObjectStrc* gpSoundObject_00881740; // 0x00881740
extern D2ComObjectStrc* gpSoundObject_00881744; // 0x00881744

// 0x00513AF0
void __cdecl D2SOUND_ReleaseSoundObjects()
{
    if (gpSoundObject_008816D8)
    {
        gpSoundObject_008816D8->Release();
        gpSoundObject_008816D8 = 0;
    }
    if (gpSoundObject_00881740)
    {
        gpSoundObject_00881740->Release();
        gpSoundObject_00881740 = 0;
    }
    if (gpSoundObject_00881744)
    {
        gpSoundObject_00881744->Release();
        gpSoundObject_00881744 = 0;
    }
}

// 0x00513B50
int __cdecl D2SOUND_GetDirectSound()
{
    return gdwGlobal_00881768;
}

// 0x00513B60
int __cdecl D2SOUND_IsPositionalSoundEnabled()
{
    return gdwGlobal_0088176C;
}

// 0x00513B70
int __cdecl D2SOUND_IsEaxEnabled()
{
    return gdwGlobal_00881770;
}

// 0x00513B80
int __cdecl sub_00513B80()
{
    return 0;
}

// 0x00513B90
int __cdecl D2SOUND_GetEaxVersion()
{
    return gdwGlobal_00881774;
}

// 0x00513BA0
int __cdecl D2SOUND_IsEaxRoomOff()
{
    return gdwGlobal_00881778;
}

// 0x00513BB0
int __cdecl sub_00513BB0()
{
    return gdwGlobal_0072F830;
}

#include "gen/data/Source/D2Sound/Unknown_00513A20.inc"
