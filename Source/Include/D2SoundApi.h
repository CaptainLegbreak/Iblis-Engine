#pragma once
// D2Sound's exports that the other modules call.

struct D2EaxEnvironmentStrc;
struct D2SoundNodeStrc;
struct D2SoundObjStrc_00515A30;
struct D2SoundStrc;
struct D2WaveFormatStrc;
struct Node005169D0;

void __fastcall D2SOUND_SetEaxEnvironment(D2EaxEnvironmentStrc* pEnvironment); // 0x00513C50
void __cdecl D2SOUND_CloseSoundSystem(); // 0x00514060
void __fastcall sub_00514530_InitSound(int nArg1, int nArg2); // 0x00514530
int __cdecl D2SOUND_IsStreamChannelPlaying(); // 0x00514840
void __fastcall D2SOUND_10034(int nValue); // 0x005148F0
void __cdecl D2SOUND_StopChannel(); // 0x00514930
void __cdecl D2SOUND_FadeOutStreamChannel(); // 0x00514960
int __fastcall D2SOUND_SetSoundMixerOption(int nValue); // 0x00514CA0
int __cdecl D2SOUND_GetMasterVolumeOption(); // 0x00514CC0
int __fastcall D2SOUND_SetMasterVolumeOption(int nValue); // 0x00514CD0
int __cdecl D2SOUND_GetMusicVolumeOption(); // 0x00514CF0
int __fastcall D2SOUND_SetMusicVolumeOption(int nValue); // 0x00514D00
int __cdecl D2SOUND_GetPositionalBiasOption(); // 0x00514D20
int __fastcall D2SOUND_SetPositionalBiasOption(int nValue); // 0x00514D30
int __cdecl D2SOUND_GetNpcSpeechOption(); // 0x00514D50
int __fastcall sub_00514D60_SetNpcSpeech(int nValue); // 0x00514D60
int __cdecl D2SOUND_GetOptionsMusicOption(); // 0x00514D80
int __fastcall D2SOUND_SetOptionsMusicOption(int nValue); // 0x00514D90
void __cdecl D2SOUNDFAST_InitWaveSlots(); // 0x00514DB0
void __fastcall D2SOUNDFAST_PreloadWave(const char* szName); // 0x00514E10
void __fastcall D2SOUND_10039(const char* szName); // 0x00514EC0
int __cdecl D2SOUNDFAST_IsAnyWavePlaying(); // 0x00514FB0
int __cdecl D2SOUNDFAST_AreWaveSlotsInitialized(); // 0x00515060
void __cdecl D2SOUNDFAST_FreeWaveSlots(); // 0x00515070
void __cdecl sub_00515110_Nop(); // 0x00515110
D2SoundStrc* __fastcall D2SOUNDSMP_CreateSound(unsigned int nFlags, int nValue); // 0x00515530
int __fastcall D2SOUNDSMP_SetSoundData(D2SoundStrc* pSound, const void* pFile, unsigned int nSize); // 0x005155D0
int __fastcall D2SOUNDSMP_PlaySound(D2SoundStrc* pSound); // 0x005156A0
int __fastcall D2SOUNDSMP_GetSoundPlayingFlag(D2SoundStrc* pSound); // 0x00515710
int __fastcall D2SOUNDSMP_IsSoundBufferPlaying(D2SoundStrc* pSound); // 0x00515740
void __fastcall D2SOUNDSMP_SetSoundVolume(D2SoundStrc* pSound, int nVolume); // 0x005157B0
void __fastcall D2SOUNDSMP_SetSoundPan(D2SoundStrc* pSound, int nPan); // 0x00515890
void __fastcall D2SOUNDSMP_SetSoundPosition(D2SoundStrc* pSound, float x, float y, float z); // 0x00515950
extern "C" void __fastcall D2SOUND_SetSoundNoLoop(D2SoundObjStrc_00515A30* pSound, int nValue); // 0x00515A30
extern "C" void __fastcall D2SOUND_SetSoundLoopStart(D2SoundObjStrc_00515A30* pSound, int nValue); // 0x00515A60
void __fastcall D2SOUNDSMP_SetSoundAttenuation(D2SoundStrc* pSound, float fAttenuation); // 0x00515A90
void __fastcall D2SOUNDSMP_SetSoundReverbMix(D2SoundStrc* pSound, float fReverbMix); // 0x00515B40
int __fastcall D2SOUNDSMP_IsSoundStreaming(D2SoundStrc* pSound); // 0x00515C30
void __fastcall D2SOUNDSMP_SetMasterVolume(int nVolume); // 0x00515CE0
int __fastcall D2SOUNDSMP_StartSoundStream(D2SoundStrc* pSound, const char* szFileName, int nPosition, int bLoop); // 0x00515D70
void __cdecl sub_00515EC0_Nop(); // 0x00515EC0
void __cdecl sub_00515ED0_Nop(); // 0x00515ED0
void __fastcall D2SOUNDSMP_FadeOutMasterVolume(int nTime); // 0x00515F50
void __fastcall D2SOUNDSMP_DestroySound(D2SoundStrc* pSound); // 0x005160D0
void __fastcall D2SOUNDSMP_ResetSound(D2SoundStrc* pSound); // 0x00516140
const unsigned char* __fastcall D2SOUNDSMP_ReadWaveHeader(const unsigned int* pRiff, unsigned int* pnSize, D2WaveFormatStrc* pFormat); // 0x00516760
void __fastcall D2SOUNDSMP_GetPositionalVolumePan(int* pVolume, int* pPan, float fX, float fY, float fZ); // 0x00516830
extern "C" int __fastcall D2SOUNDUTIL_ListContains(Node005169D0* pNode, int nId); // 0x005169D0
void __fastcall D2SOUNDUTIL_ListFree(D2SoundNodeStrc** ppList); // 0x00516A10
void __fastcall D2SOUNDUTIL_ListAddTail(D2SoundNodeStrc** ppList, int nKey); // 0x00516A70
