#pragma once
// D2Sound's exports that the other modules call; included only by the units that use it.

struct D2DSDirectSound;
struct D2SoundStrc;

int __cdecl D2SOUND_GetDirectSound(); // 0x00513B50
int __cdecl D2SOUND_IsPositionalSoundEnabled(); // 0x00513B60
int __cdecl D2SOUND_GetSoundMixerOption(); // 0x00514C90
void __cdecl D2SOUNDFAST_FadeOutWaves(); // 0x00515020
void __fastcall D2SOUNDSMP_StopSound(D2SoundStrc* pSound); // 0x00515EE0
extern D2DSDirectSound* gpDirectSound; // 0x00881768
extern int gbEaxEnabled; // 0x00881770
extern int gnEaxVersion; // 0x00881774
extern int gbEaxRoomOff; // 0x00881778
extern int gnChannelValue; // 0x00881798
extern int gnSoundMode; // 0x008817AC
extern int gnMasterVolume; // 0x008817B0
extern int gnMusicVolume; // 0x008817B4
extern int gnPositionalBias; // 0x008817B8
extern int gnNpcSpeech; // 0x008817BC
extern int gnOptionsMusic; // 0x008817C0
extern int gbWaveSlotsInit; // 0x008817FC
