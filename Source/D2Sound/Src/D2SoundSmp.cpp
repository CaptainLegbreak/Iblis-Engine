#include "D2Sound.h"

#include "D2SoundTypes.h"


#define DSBSTATUS_BUFFERLOST 0x00000002

#define DSERR_BUFFERLOST ((long)0x88780096)

struct D2DirectSoundStrc;

struct D2ComObjectStrc;

struct D2DSoundBufferStrc;

struct D2SoundStrc;

struct D2SoundNodeStrc;

struct D2WaveStrc;

struct D2SoundChannelEntryStrc;

struct D2WaveFormatStrc;

struct D2SoundSampleStrc;

struct D2SoundViewStrc;

struct D2StoredUnitRecordStrc;

struct D2PanelCtrlStrc_004B8370;

struct D2SoundObjStrc_00515A30;

struct D2ClientStrc;

struct D2LinkStrc_004CA990;

struct D2OwnerStrc_004CA990;

struct D2SoundFadeStrc;

struct D2CriticalSectionStrc;

struct D2KsPropertySetStrc;

struct D2DSound3DBufferStrc;

struct D2GuidStrc;

struct D2DSBufferDescStrc;

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void __cdecl sub_00419F30(); // 0x00419F30

int __stdcall SFileDdaEnd(void* hStream); // 0x0041A990

D2DirectSoundStrc* __cdecl D2SOUND_GetDirectSound(); // 0x00513B50

void __fastcall D2SOUNDSMP_SetSoundVolume(D2SoundStrc* pSound, int nVolume); // 0x005157B0

void __fastcall D2SOUNDSMP_StopSound(D2SoundStrc* pSound); // 0x00515EE0

int __fastcall FOG_FOpenFile(const char* szFileName, void** phFile); // 0x004068E0

int __stdcall SFileDdaBeginEx(void* hFile, int nBufferSize, unsigned int nFlags, unsigned int nOffset, int nVolume, int nPan, D2DSoundBufferStrc* pBuffer); // 0x0041B280

int __fastcall D2SOUNDSMP_FillSoundBuffer(D2SoundStrc* sound,unsigned int sourcePosition,unsigned int destinationPosition,unsigned int size); // 0x00515180

void* __fastcall D2SOUNDSMP_ReadWaveHeader(const void* pFile, unsigned int* pnSize, D2WaveFormatStrc* pFormat); // 0x00516760

void __fastcall D2SOUNDSMP_DestroySound(D2SoundStrc* pSound); // 0x005160D0

extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent); // 0x006CC130

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218



extern D2ComObjectStrc* gpSoundObject_008816D8; // 0x008816D8

extern D2ComObjectStrc* gpSoundObject_00881740; // 0x00881740

extern D2ComObjectStrc* gpSoundObject_00881744; // 0x00881744

extern D2SoundStrc* gpSoundChannel; // 0x00881794

int gnSoundMode; // 0x008817AC

int gnMusicVolume; // 0x008817B4

int gnOptionsMusic; // 0x008817C0

extern D2CriticalSectionStrc gtWaveLock; // 0x008817C4

extern D2SoundStrc* gapWaveSlots[8]; // 0x008817DC

extern int gbWaveSlotsInit; // 0x008817FC

D2SoundNodeStrc* gpSoundList; // 0x00881808

struct D2SoundSampleStrc
{
    char unk0x00[0x48];
    void* hSample;
};

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10

D2CriticalSectionStrc gtSoundLock; // 0x0088174C

struct D2SoundViewStrc
{
    char unk0x00[0x38];
    int nField38;
};

struct D2StoredUnitRecordStrc
{
    char unk0x00[0x66];
    char szName[1];
};

struct D2PanelCtrlStrc_004B8370
{
    char unk0x00[0x5C];
    int nState;
};

struct D2SoundObjStrc_00515A30
{
    char unk0x00[0x40];
    int nValue40;
    int nValue44;
};

struct D2ClientStrc
{
    char unk0x00[0x3D4];
    unsigned int dwFlags;
};

struct D2LinkStrc_004CA990
{
    void* pFirst;
};

struct D2OwnerStrc_004CA990
{
    char unk0x00[0x78];
    D2LinkStrc_004CA990* pLink;
};

typedef char check_ptr_width[(sizeof(void*) == 4) ? 1 : -1];

typedef char check_size_entry[(sizeof(D2StoredUnitRecordStrc) == 0x67) ? 1 : -1];

typedef char check_size_ctrl[(sizeof(D2PanelCtrlStrc_004B8370) == 0x60) ? 1 : -1];

typedef char check_size_sound[(sizeof(D2SoundObjStrc_00515A30) == 0x48) ? 1 : -1];

typedef char check_size_client[(sizeof(D2ClientStrc) == 0x3D8) ? 1 : -1];

typedef char check_size_owner[(sizeof(D2OwnerStrc_004CA990) == 0x7C) ? 1 : -1];

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void* pAttributes, int bManualReset, int bInitialState, const char* szName); // 0x006CC228

extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId); // 0x006CC250

extern "C" double __cdecl log10(double x); // 0x00687EA0

struct D2SoundFadeStrc
{
    char unk0x00[0x38];
    int nCurrent;
    char unk0x3C[0x10];
    int f_4C;
    int nFadeStart;
    int f_54;
    unsigned int dwFadeStartTick;
    unsigned int dwFadeEndTick;
};

unsigned long __stdcall D2SOUNDSMP_SoundThreadProc(void* pParameter); // 0x00516250

void* ghSoundEvent; // 0x0088180C

void* ghSoundThread; // 0x00881810

void __fastcall D2SOUNDSMP_CloseSoundStream(D2SoundStrc* pSound); // 0x00515E40

int __cdecl D2SOUND_IsEaxRoomOff(); // 0x00513BA0

float __stdcall sub_00516670_RoomToVolume(float fRoom); // 0x00516670

extern const D2GuidStrc gtEaxListener20PropertySet; // 0x006DE460

extern const D2GuidStrc gtEaxBuffer20PropertySet; // 0x006DE470

extern const D2GuidStrc gtEaxListener10PropertySet; // 0x006DE480

extern const D2GuidStrc gtEaxBuffer10PropertySet; // 0x006DE490

extern int gbEaxEnabled; // 0x00881770

extern int gnEaxVersion; // 0x00881774

extern int gbEaxRoomOff; // 0x00881778

void __fastcall D2SOUNDSMP_SetSoundPosition(D2SoundStrc* pSound, float x, float y, float z); // 0x00515950

void __fastcall D2SOUNDSMP_SetSoundAttenuation(D2SoundStrc* pSound, float fAttenuation); // 0x00515A90

void __fastcall D2SOUNDSMP_InitWaveFormat(D2WaveFormatStrc* pFormat, int nChannels); // 0x00516720

void __fastcall D2SOUNDUTIL_ListAddHead(D2SoundNodeStrc** ppList, void* pData); // 0x00516950

void __fastcall D2SOUNDUTIL_ListRemove(D2SoundNodeStrc** ppList, void* pData); // 0x00516980

extern const D2GuidStrc gIidDirectSound3DBuffer_006DE3D0; // 0x006DE3D0

extern const D2GuidStrc gIidKsPropertySet_006DE410; // 0x006DE410

D2KsPropertySetStrc* gpEaxListenerPropertySet; // 0x008816D8

int gnChannelTableSel; // 0x008817A4

int gbChannelTableInit; // 0x008817A8

D2WaveStrc* gpWaveList; // 0x00881800

int gnMasterVolume; // 0x008817B0

int gnPositionalBias; // 0x008817B8

int gnNpcSpeech; // 0x008817BC

int gbSoundGlobalFocus; // 0x00881804

extern "C" { int gnStreamChannelArg; } // 0x008817A0

extern "C" int __stdcall SFileDdaInitialize(int nValue); // 0x00415EE0

D2SoundStrc* __fastcall D2SOUNDSMP_CreateSound(unsigned int nFlags, int nValue); // 0x00515530

extern const char gszEmptyAssert[]; // 0x006CC837

extern "C" void* __cdecl memcpy(void*,const void*,unsigned int); // 0x006829C0

extern "C" const char gszD2SoundSmpFile[];                                                          // 0x006DEAEC

extern "C" __declspec(dllimport) int __stdcall IsIconic(void* hWnd); // 0x006CC50C

extern int gbIconic; // 0x00881814

extern "C" void* __cdecl sub_004F59A0_GetHwnd(); // 0x004F59A0

int __cdecl D2SOUND_GetStreamChannelValue(); // 0x00514920

int __cdecl D2SOUND_IsStreamChannelPlaying(); // 0x00514840

int __cdecl sub_00514990_PickRandomChannel(); // 0x00514990

int __fastcall D2SOUNDSMP_ClearSoundBuffer(D2DSoundBufferStrc* pBuffer, unsigned long nOffset, unsigned long nBytes); // 0x00515300

int __fastcall D2SOUNDSMP_RestoreLostBuffer(D2SoundStrc* pSound); // 0x00515FD0

extern "C" double __cdecl sqrt(double x); // 0x006879C0

extern const float gfMaxSoundDistance; // 0x006DEB10

const unsigned char* __fastcall D2SOUNDSMP_ReadWaveHeader(const unsigned int* pRiff, unsigned int* pnSize, D2WaveFormatStrc* pFormat); // 0x00516760

static void D2SOUNDSMP_ReleaseSoundBuffers(D2SoundStrc* pSound); // 0x00516070

void __fastcall D2SOUNDSMP_ResetSound(D2SoundStrc* pSound); // 0x00516140

// build: symbol ?D2SOUNDSMP_CreateSoundBuffer@* 0x005153C0
static int __stdcall D2SOUNDSMP_CreateSoundBuffer(unsigned int nFlags, D2SoundStrc* pSound)
{
    D2WaveFormatStrc tFormat;
    D2SOUNDSMP_InitWaveFormat(&tFormat, (nFlags & 1) ? 2 : 1);

    D2DSBufferDescStrc tDesc;
    memset(&tDesc, 0, sizeof(tDesc));
    const unsigned int nBytes = (nFlags & 1) ? 0x40000 : 0x20000;
    tDesc.dwSize = 0x14;
    tDesc.dwFlags = gbSoundGlobalFocus ? 0x80A0 : 0xA0;
    if (nFlags & 2)
        tDesc.dwFlags |= 0x14;
    else
        tDesc.dwFlags |= 0x40;
    tDesc.dwBufferBytes = nBytes;
    tDesc.lpwfxFormat = &tFormat;

    D2DirectSoundStrc* pDirectSound = D2SOUND_GetDirectSound();
    if (pDirectSound->CreateSoundBuffer(&tDesc, &pSound->pBuffer, 0) < 0)
        return 0;

    if (nFlags & 2)
    {
        if (pSound->pBuffer->QueryInterface(gIidDirectSound3DBuffer_006DE3D0, (void**)&pSound->p3DBuffer) < 0)
        {
            pSound->pBuffer->Release();
            return 0;
        }
    }

// build: symbol ?D2SOUND_IsEaxEnabled@* 0x00513B70
    if ((nFlags & 2) && D2SOUND_IsEaxEnabled())
    {
        if (pSound->p3DBuffer->QueryInterface(gIidKsPropertySet_006DE410, (void**)&pSound->pPropertySet) < 0)
        {
            pSound->pBuffer->Release();
            return 0;
        }

        unsigned long dwSupport = 0;
        long hr;
// build: symbol ?D2SOUND_GetEaxVersion@* 0x00513B90
        if (D2SOUND_GetEaxVersion() == 1)
            hr = pSound->pPropertySet->QuerySupport(gtEaxBuffer10PropertySet, 1, &dwSupport);
        else
            hr = pSound->pPropertySet->QuerySupport(gtEaxBuffer20PropertySet, 1, &dwSupport);
        if (hr < 0 || (dwSupport & 3) != 3)
        {
            pSound->pPropertySet->Release();
            pSound->pBuffer->Release();
            return 0;
        }
    }

    pSound->nBufferSize = nBytes;
    pSound->nHalfBufferBytes = nBytes >> 1;
    pSound->dwFlags = nFlags;
    pSound->nLoopStart = -1;
    return 1;
}

static const unsigned char* __stdcall D2SOUNDSMP_FindRiffChunk(const unsigned char* pData, unsigned int* pnSize, unsigned int nChunkId, unsigned int* pnChunkSize); // 0x005166D0

void __cdecl sub_0042B9D0_Nop()
{
}

void __cdecl sub_0043CBF0_Nop()
{
}

// build: symbol @ROSTER_GetEntryName@* 0x004795C0
extern "C" const char* __fastcall ROSTER_GetEntryName(D2StoredUnitRecordStrc* pEntry)
{
    D2_ASSERT(pEntry, 372);
    return pEntry->szName;
}

// build: symbol @ROSTER_SetCtrlState@* 0x004B8370
extern "C" void __fastcall ROSTER_SetCtrlState(D2PanelCtrlStrc_004B8370* pCtrl, int nState)
{
    D2_ASSERT(pCtrl, 1310);
    pCtrl->nState = nState;
}

// build: symbol @UNITSND_GetLinkFirst@* 0x004CA990
extern "C" void* __fastcall UNITSND_GetLinkFirst(D2OwnerStrc_004CA990* pOwner)
{
    D2_ASSERT(pOwner, 3171);
    D2LinkStrc_004CA990* pLink = pOwner->pLink;
    if (pLink)
    {
        return pLink->pFirst;
    }

    return 0;
}

extern "C" void __fastcall CLIENTS_SetPlayerUnitAlive(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 518);
    pClient->dwFlags |= 1;
}

void __cdecl sub_00650EA0_Nop()
{
}


// 0x00515110
void __cdecl sub_00515110_Nop()
{
}

// 0x00515120
void __cdecl D2SOUNDSMP_StopSoundThread()
{
    if (ghSoundThread && ghSoundEvent)
    {
        SetEvent(ghSoundEvent);
        WaitForSingleObject(ghSoundThread, -1);
        CloseHandle(ghSoundEvent);
        CloseHandle(ghSoundThread);
        ghSoundEvent = 0;
        ghSoundThread = 0;
    }
}

// 0x00515180
int __fastcall D2SOUNDSMP_FillSoundBuffer(D2SoundStrc* sound,unsigned int sourcePosition,unsigned int destinationPosition,unsigned int size)
{
 void* locked=0;
 if(sound && sound->pBuffer && sound->pData && size) {
  EnterCriticalSection(&gtSoundLock);
  unsigned long lockedSize=size;
  if(sound->pBuffer->Lock(destinationPosition,size,&locked,&lockedSize,0,0,0)<0) {
   LeaveCriticalSection(&gtSoundLock);
   return 0;
  }
  unsigned char* destination=(unsigned char*)locked;
  do {
   unsigned int end=sound->nDataSize;
   if(sourcePosition>=end)
    sourcePosition=sound->nMinDataSize+(sourcePosition-sound->nMinDataSize)%(end-sound->nMinDataSize);
   unsigned int count=size<end-sourcePosition?size:end-sourcePosition;
   memcpy(destination,(unsigned char*)sound->pData+sourcePosition,count);
   sound->nFillPosition+=count;
   destination+=count;
   destinationPosition+=count;
   size-=count;
   sourcePosition+=count;
  } while(sound->bNoLoop && size);
  if(size) {
   if(sound->nLoopStart!=(unsigned int)-1) {
    if(destinationPosition>=sound->nLoopStart) goto unlock;
    size=sound->nLoopStart-destinationPosition;
   }
   if(size) memset(destination,0,size);
  }
 unlock:
  sound->pBuffer->Unlock(locked,lockedSize,0,0);
  if(!sound->bNoLoop && sound->nFillPosition>=sound->nDataSize) sound->bStreamed=1;
  LeaveCriticalSection(&gtSoundLock);
  return 1;
 }
 FOG_DisplayHalt(gszEmptyAssert,sub_00408090(),221);
 exit(-1);
}

// 0x00515300
int __fastcall D2SOUNDSMP_ClearSoundBuffer(D2DSoundBufferStrc* pBuffer, unsigned long nOffset, unsigned long nBytes)
{
    void* pAudio = 0;
    D2_ASSERT(pBuffer, 0x14B);
    EnterCriticalSection(&gtSoundLock);
    if (pBuffer->Lock(nOffset, nBytes, &pAudio, &nBytes, 0, 0, 0) < 0)
    {
        LeaveCriticalSection(&gtSoundLock);
        return 0;
    }
    memset(pAudio, 0, nBytes);
    pBuffer->Unlock(pAudio, nBytes, 0, 0);
    LeaveCriticalSection(&gtSoundLock);
    return 1;
}

// 0x00515530
D2SoundStrc* __fastcall D2SOUNDSMP_CreateSound(unsigned int nFlags, int nValue)
{
    gbSoundGlobalFocus = nValue;
// build: symbol ?D2SOUND_IsPositionalSoundEnabled@* 0x00513B60
    if ((nFlags & 2) && !D2SOUND_IsPositionalSoundEnabled())
        return 0;
    if ((nFlags & 2) && (nFlags & 1))
        return 0;

    D2SoundStrc* pSound = (D2SoundStrc*)FOG_Alloc(0x60, ".\\Src\\D2SoundSmp.cpp", 0x1D9, 0);
    memset(pSound, 0, 0x60);
    if (!D2SOUNDSMP_CreateSoundBuffer(nFlags, pSound))
    {
        FOG_Free(pSound, ".\\Src\\D2SoundSmp.cpp", 0x1E0, 0);
        return 0;
    }

    EnterCriticalSection(&gtSoundLock);
    D2SOUNDUTIL_ListAddHead(&gpSoundList, pSound);
    LeaveCriticalSection(&gtSoundLock);
    return pSound;
}

// 0x005155D0
int __fastcall D2SOUNDSMP_SetSoundData(D2SoundStrc* pSound, const void* pFile, unsigned int nSize)
{
    D2_ASSERT(pSound && pSound->pBuffer && pFile && nSize, 0x257);
    EnterCriticalSection(&gtSoundLock);
    unsigned int nDataSize = nSize;
    D2WaveFormatStrc tFormat;
    void* pData = D2SOUNDSMP_ReadWaveHeader(pFile, &nDataSize, &tFormat);
    D2_ASSERT(pSound->nMinDataSize < nDataSize, 0x25F);
    pSound->nDataSize = nDataSize;
    pSound->pData = pData;
    D2SOUNDSMP_FillSoundBuffer(pSound, 0, 0, pSound->nBufferSize);
    pSound->bSecondHalf = 1;
    if (!pSound->bNoLoop && pSound->nDataSize < pSound->nBufferSize)
        pSound->nLoopStart = pSound->nDataSize;
    else
        pSound->nLoopStart = -1;
    LeaveCriticalSection(&gtSoundLock);
    return 1;
}

// 0x005156A0
int __fastcall D2SOUNDSMP_PlaySound(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound, 0x279);
    EnterCriticalSection(&gtSoundLock);
    if (pSound->pBuffer->Play(0, 0, 1) < 0)
    {
        LeaveCriticalSection(&gtSoundLock);
        return 0;
    }
    pSound->bStreaming = 1;
    LeaveCriticalSection(&gtSoundLock);
    return 1;
}

// 0x00515710
int __fastcall D2SOUNDSMP_GetSoundPlayingFlag(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound && pSound->pBuffer, 0x2A5);
    return pSound->bStreaming;
}

// 0x00515740
int __fastcall D2SOUNDSMP_IsSoundBufferPlaying(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound && pSound->pBuffer, 0x2B0);
    EnterCriticalSection(&gtSoundLock);
    unsigned long dwStatus;
    if (pSound->pBuffer->GetStatus(&dwStatus) < 0)
    {
        LeaveCriticalSection(&gtSoundLock);
        return 0;
    }
    LeaveCriticalSection(&gtSoundLock);
    const unsigned char bPlaying = dwStatus & 1;
    return bPlaying;
}

// 0x005157B0
void __fastcall D2SOUNDSMP_SetSoundVolume(D2SoundStrc* pSound, int nVolume)
{
    D2_ASSERT(pSound && pSound->pBuffer, 0x2CB);
// build: symbol ?gnSoundMasterVolume@* 0x0072F9B0
    int nScaled = nVolume * gnSoundMasterVolume;
    pSound->nVolume = nVolume;
    nScaled /= 255;
    if (!(pSound->dwFlags & 4) || D2SOUND_GetEaxVersion() != 2)
        nScaled = (int)((1.0f - pSound->fAttenuation) * nScaled);
    const int nDecibels = (int)sub_005165F0_ToDecibels(0.0f, 255.0f, (float)nScaled);
    pSound->pBuffer->SetVolume(nDecibels);
}

// 0x00515860
int __fastcall D2SOUNDSMP_GetSoundVolume(D2SoundViewStrc* pSound)
{
    D2_ASSERT(pSound, 0x2E4);
    return pSound->nField38;
}

// 0x00515890
void __fastcall D2SOUNDSMP_SetSoundPan(D2SoundStrc* pSound, int nPan)
{
    long lPan;

    D2_ASSERT(pSound, 0x2EF);
    if (nPan > 0x80)
        lPan = (long)-sub_005165F0_ToDecibels(0.0f, 127.0f, (float)(0xFF - nPan));
    else if (nPan < 0x80)
        lPan = (long)sub_005165F0_ToDecibels(0.0f, 127.0f, (float)nPan);
    else
        lPan = 0;
    pSound->pBuffer->SetPan(lPan);
}

// 0x00515950
void __fastcall D2SOUNDSMP_SetSoundPosition(D2SoundStrc* pSound, float x, float y, float z)
{
    D2_ASSERT(pSound && pSound->pBuffer, 0x302);
    if (pSound->dwFlags & 2)
        pSound->p3DBuffer->SetPosition(x, y, z, 0);
}

// 0x005159B0
unsigned int __fastcall D2SOUNDSMP_GetStreamPosition(D2SoundSampleStrc* pSound)
{
    D2_ASSERT(pSound, 784);
    EnterCriticalSection(&gtSoundLock);
    if (pSound->hSample)
    {
        unsigned int nValueA;
        unsigned int nValueB;
        if (sub_00418140(pSound->hSample, &nValueA, &nValueB))
        {
            LeaveCriticalSection(&gtSoundLock);
            return nValueA >> 2;
        }
        LeaveCriticalSection(&gtSoundLock);
        return 0;
    }
    LeaveCriticalSection(&gtSoundLock);
    return 0;
}

// 0x00515A30
extern "C" void __fastcall D2SOUND_SetSoundNoLoop(D2SoundObjStrc_00515A30* pSound, int nValue)
{
    D2_ASSERT(pSound, 815);
    pSound->nValue40 = nValue;
}

// 0x00515A60
extern "C" void __fastcall D2SOUND_SetSoundLoopStart(D2SoundObjStrc_00515A30* pSound, int nValue)
{
    D2_ASSERT(pSound, 826);
    pSound->nValue44 = nValue;
}

// 0x00515A90
void __fastcall D2SOUNDSMP_SetSoundAttenuation(D2SoundStrc* pSound, float fAttenuation)
{
    D2_ASSERT(pSound, 0x345);
    pSound->fAttenuation = fAttenuation;
    if (pSound->pPropertySet && D2SOUND_GetEaxVersion() == 2)
    {
        if ((pSound->dwFlags & 4) || fAttenuation == 0.0f)
        {
            fAttenuation = 1.0f - fAttenuation;
            int nValue = (int)sub_005165F0_ToDecibels(0.0f, 1.0f, fAttenuation);
            pSound->pPropertySet->Set(gtEaxBuffer20PropertySet, 7, 0, 0, &nValue, 4);
        }
    }
}

// 0x00515B40
void __fastcall D2SOUNDSMP_SetSoundReverbMix(D2SoundStrc* pSound, float fReverbMix)
{
    D2_ASSERT(pSound, 0x359);
    if (D2SOUND_IsEaxRoomOff())
        fReverbMix = 0.0f;
    if (pSound->pPropertySet)
    {
        if (D2SOUND_GetEaxVersion() == 1)
        {
            if (fReverbMix != 0.0f)
                fReverbMix = -1.0f;
            pSound->pPropertySet->Set(gtEaxBuffer10PropertySet, 1, 0, 0, &fReverbMix, 4);
        }
        else
        {
            int nValue = (int)sub_005165F0_ToDecibels(0.0f, 1.0f, fReverbMix);
            pSound->pPropertySet->Set(gtEaxBuffer20PropertySet, 5, 0, 0, &nValue, 4);
            pSound->pPropertySet->Set(gtEaxBuffer20PropertySet, 4, 0, 0, &nValue, 4);
        }
    }
}

// 0x00515C30
int __fastcall D2SOUNDSMP_IsSoundStreaming(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound, 0x37A);
    return pSound->hStream != 0;
}

// 0x00515C60
void __fastcall D2SOUNDSMP_StartSoundFade(D2SoundFadeStrc* pFade, int nTarget, int nDuration)
{
    D2_ASSERT(pFade, 0x39E);
    if (D2SOUND_GetDirectSound())
    {
        EnterCriticalSection(&gtSoundLock);
        pFade->f_4C = 1;
        pFade->nFadeStart = pFade->nCurrent;
        pFade->f_54 = nTarget;
        const unsigned int dwTick = GetTickCount();
        pFade->dwFadeStartTick = dwTick;
        pFade->dwFadeEndTick = dwTick + nDuration;
        LeaveCriticalSection(&gtSoundLock);
    }
}

// 0x00515CE0
void __fastcall D2SOUNDSMP_SetMasterVolume(int nVolume)
{
    if (!D2SOUND_GetDirectSound())
        return;
    if (nVolume == gnSoundMasterVolume)
        return;
    D2_ASSERT(nVolume >= 0 && nVolume <= 0xFF, 0x3B9);
    EnterCriticalSection(&gtSoundLock);
    gnSoundMasterVolume = nVolume;
    for (D2SoundNodeStrc* pNode = gpSoundList; pNode; pNode = pNode->pNext)
    {
        D2_ASSERT(pNode->pSound, 0x2E4);
        D2SOUNDSMP_SetSoundVolume(pNode->pSound, pNode->pSound->nVolume);
    }
    LeaveCriticalSection(&gtSoundLock);
}

// 0x00515D60
int __cdecl D2SOUNDSMP_GetMasterVolume()
{
    return D2SOUND_GetDirectSound() ? gnSoundMasterVolume : 0;
}

// 0x00515D70
int __fastcall D2SOUNDSMP_StartSoundStream(D2SoundStrc* pSound, const char* szFileName, int nPosition, int bLoop)
{
    D2_ASSERT(pSound, 0x3DB);
    void* hFile;
    if (!FOG_FOpenFile(szFileName, &hFile))
        return 0;
    EnterCriticalSection(&gtSoundLock);
    if (!SFileDdaBeginEx(hFile, pSound->nBufferSize, bLoop ? 0x40000 : 0, nPosition * 4, 0x7FFFFFFF, 0x7FFFFFFF, pSound->pBuffer))
    {
// build: symbol ?FOG_FCloseFile@* 0x004068F0
        FOG_FCloseFile(hFile);
        LeaveCriticalSection(&gtSoundLock);
        return 0;
    }
    pSound->hStream = hFile;
    pSound->bStreaming = 1;
    pSound->nLoopStart = -1;
    LeaveCriticalSection(&gtSoundLock);
    return 1;
}

// 0x00515E40
void __fastcall D2SOUNDSMP_CloseSoundStream(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound && pSound->pBuffer, 0x400);
    EnterCriticalSection(&gtSoundLock);
    if (pSound->hStream)
    {
        SFileDdaEnd(pSound->hStream);
        pSound->pBuffer->Stop();
        FOG_FCloseFile(pSound->hStream);
        pSound->hStream = 0;
        pSound->bStreaming = 0;
    }
    LeaveCriticalSection(&gtSoundLock);
}

// 0x00515EC0
void __cdecl sub_00515EC0_Nop()
{
}

// 0x00515ED0
void __cdecl sub_00515ED0_Nop()
{
}

// 0x00515EE0
void __fastcall D2SOUNDSMP_StopSound(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound && pSound->pBuffer, 658);
    EnterCriticalSection(&gtSoundLock);
    if (pSound->hStream)
    {
        D2SOUNDSMP_CloseSoundStream(pSound);
    }
    pSound->pBuffer->Stop();
    pSound->bStreaming = 0;
    LeaveCriticalSection(&gtSoundLock);
}

// 0x00515F50
void __fastcall D2SOUNDSMP_FadeOutMasterVolume(int nTime)
{
    if (!D2SOUND_GetDirectSound())
        return;
    D2_ASSERT(nTime > 0, 0x387);
    unsigned int nVolume = D2SOUNDSMP_GetMasterVolume();
    const unsigned int nStep = nVolume / (nTime / 20u);
    while (nVolume)
    {
        Sleep(20);
        if (nVolume > nStep)
            nVolume -= nStep;
        else
            nVolume = 0;
        D2SOUNDSMP_SetMasterVolume(nVolume);
    }
}

// 0x00515FD0
int __fastcall D2SOUNDSMP_RestoreLostBuffer(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound->pBuffer, 290);
    EnterCriticalSection(&gtSoundLock);
    unsigned long dwStatus;
    if (pSound->pBuffer->GetStatus(&dwStatus) < 0)
    {
        LeaveCriticalSection(&gtSoundLock);
        return 0;
    }

    if (dwStatus & DSBSTATUS_BUFFERLOST)
    {
        for (;;)
        {
            const long hResult = pSound->pBuffer->Restore();
            if (hResult == DSERR_BUFFERLOST)
            {
                Sleep(10);
                continue;
            }
            if (hResult >= 0)
            {
                break;
            }
        }
        D2SOUNDSMP_StopSound(pSound);
    }

    LeaveCriticalSection(&gtSoundLock);
    return 1;
}

// 0x00516070
static void D2SOUNDSMP_ReleaseSoundBuffers(D2SoundStrc* pSound)
{
    D2SOUNDSMP_StopSound(pSound);
    if (pSound->pPropertySet)
    {
        pSound->pPropertySet->Release();
        pSound->pPropertySet = 0;
    }
    if (pSound->p3DBuffer)
    {
        pSound->p3DBuffer->Release();
        pSound->p3DBuffer = 0;
    }
    if (pSound->pBuffer)
    {
        pSound->pBuffer->Release();
        pSound->pBuffer = 0;
    }
    memset(pSound, 0, 0x60);
}

// 0x005160D0
void __fastcall D2SOUNDSMP_DestroySound(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound, 0x211);
    EnterCriticalSection(&gtSoundLock);
    D2SOUNDSMP_ReleaseSoundBuffers(pSound);
    D2SOUNDUTIL_ListRemove(&gpSoundList, pSound);
    LeaveCriticalSection(&gtSoundLock);
    FOG_Free(pSound, ".\\Src\\D2SoundSmp.cpp", 0x21D, 0);
}

// 0x00516140
void __fastcall D2SOUNDSMP_ResetSound(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound && pSound->pBuffer, 0x226);
    D2_ASSERT(!pSound->hStream, 0x227);

    EnterCriticalSection(&gtSoundLock);
    if (sub_00513BB0())
    {
        pSound->pData = 0;
        pSound->nDataSize = 0;
        pSound->nPosition = 0;
        pSound->nFillPosition = 0;
        pSound->bStreamed = 0;
        pSound->bNoLoop = 0;
        pSound->nMinDataSize = 0;
    }
    else
    {
        const unsigned int nFlags = pSound->dwFlags;
        D2SOUNDSMP_ReleaseSoundBuffers(pSound);
        D2SOUNDSMP_CreateSoundBuffer(nFlags, pSound);
    }

    pSound->pBuffer->SetCurrentPosition(0);
    if (pSound->p3DBuffer)
    {
        pSound->p3DBuffer->SetMaxDistance(100.0f, 0);
        pSound->p3DBuffer->SetMinDistance(2.0f, 0);
    }
    if (pSound->dwFlags & 2)
        D2SOUNDSMP_SetSoundPosition(pSound, 0.0f, 0.0f, 0.0f);
    else
        pSound->pBuffer->SetPan(0);
    D2SOUNDSMP_SetSoundAttenuation(pSound, 0.0f);
    D2SOUNDSMP_SetSoundVolume(pSound, 0xFF);
    LeaveCriticalSection(&gtSoundLock);
}

static inline void sub_00515EE0_StopSoundInline(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound->pBuffer, 658);
    EnterCriticalSection(&gtSoundLock);
    if (pSound->hStream)
    {
        D2SOUNDSMP_CloseSoundStream(pSound);
    }
    pSound->pBuffer->Stop();
    pSound->bStreaming = 0;
    LeaveCriticalSection(&gtSoundLock);
}

static inline void sub_AdvancePlayPositionInline(D2SoundStrc* pSound, unsigned long dwPlay, unsigned long nMask)
{
    const unsigned long nOffset = pSound->nPosition & nMask;
    unsigned long nPosition = pSound->nPosition - nOffset;
    if (dwPlay < nOffset)
    {
        nPosition += pSound->nBufferSize;
    }
    pSound->nPosition = nPosition + dwPlay;
}

// 0x00516250
unsigned long __stdcall D2SOUNDSMP_SoundThreadProc(void* pParameter)
{
    unsigned long dwPlay;
    while (WaitForSingleObject(ghSoundEvent, 50) == 0x102)
    {
        EnterCriticalSection(&gtSoundLock);

        const int bWasIconic = gbIconic;
        gbIconic = IsIconic(sub_004F59A0_GetHwnd());

        if (D2SOUND_GetStreamChannelValue() && !D2SOUND_IsStreamChannelPlaying())
        {
            sub_00514990_PickRandomChannel();
        }

        for (D2SoundNodeStrc* pNode = gpSoundList; pNode; pNode = pNode->pNext)
        {
            D2SoundStrc* pSound = pNode->pSound;
            D2SOUNDSMP_RestoreLostBuffer(pSound);

            if (gbIconic != bWasIconic)
            {
                D2SOUNDSMP_SetSoundVolume(pSound, pSound->nVolume);
            }

            if (pSound->bFading)
            {
                const int nTick = GetTickCount();
                if (nTick >= pSound->nFadeStart && nTick <= pSound->nFadeEnd)
                {
                    D2SOUNDSMP_SetSoundVolume(pSound, (pSound->nFadeTo - pSound->nFadeFrom) * (nTick - pSound->nFadeStart) / (pSound->nFadeEnd - pSound->nFadeStart) + pSound->nFadeFrom);
                }
                else
                {
                    D2SOUNDSMP_SetSoundVolume(pSound, pSound->nFadeTo);
                    if (!pSound->nFadeTo)
                    {
                        sub_00515EE0_StopSoundInline(pSound);
                    }
                    pSound->bFading = 0;
                }
            }

            if (pSound->hStream)
            {
                unsigned int nValueA;
                unsigned int nValueB;
                if (!sub_00418140(pSound->hStream, &nValueA, &nValueB))
                {
                    sub_00515EE0_StopSoundInline(pSound);
                }
            }
            else if (pSound->bStreaming)
            {
                unsigned long dwWrite;
                if (pSound->pBuffer->GetCurrentPosition(&dwPlay, &dwWrite) >= 0)
                {
                    const unsigned long nMask = pSound->nBufferSize - 1;
                    sub_AdvancePlayPositionInline(pSound, dwPlay, nMask);

                    if (!pSound->bStreamed)
                    {
                        const unsigned long* const pnPos = &pSound->nPosition;
                        if (pSound->nFillPosition - *pnPos < pSound->nHalfBufferBytes || *pnPos > pSound->nFillPosition)
                        {
                            const unsigned long nFillOffset = pSound->nFillPosition & nMask;
                            D2SOUNDSMP_FillSoundBuffer(pSound, pSound->nFillPosition, nFillOffset, pSound->nHalfBufferBytes);
                            pSound->nLoopStart = -1;
                            pSound->bSecondHalf = nFillOffset != 0;
                        }
                    }
                    else if (!pSound->bNoLoop)
                    {
                        if (dwPlay < pSound->nHalfBufferBytes && !pSound->bSecondHalf)
                        {
                            D2SOUNDSMP_ClearSoundBuffer(pSound->pBuffer, pSound->nHalfBufferBytes, pSound->nHalfBufferBytes);
                            pSound->bSecondHalf = 1;
                        }

                        if (dwPlay >= pSound->nHalfBufferBytes && pSound->bSecondHalf == 1)
                        {
                            D2SOUNDSMP_ClearSoundBuffer(pSound->pBuffer, 0, pSound->nHalfBufferBytes);
                            pSound->bSecondHalf = 0;
                        }

                        if (pSound->nPosition > pSound->nDataSize)
                        {
                            pSound->pBuffer->Stop();
                            pSound->bStreaming = 0;
                        }
                    }
                }
            }
        }

        LeaveCriticalSection(&gtSoundLock);
    }

    return 0;
}

// 0x00516510
void __cdecl D2SOUNDSMP_StartSoundThread()
{
    unsigned long dwThreadId;
    D2_ASSERT(!ghSoundThread, 0xBC);
    ghSoundEvent = CreateEventA(0, 1, 0, 0);
    ghSoundThread = CreateThread(0, 0, D2SOUNDSMP_SoundThreadProc, 0, 0, &dwThreadId);
}

// 0x00516570
float __stdcall sub_00516570_Log(float fValue)
{
    return (float)log(fValue);
}

// 0x00516590
float __stdcall sub_00516590_Pow(float fBase, float fExponent)
{
    return (float)pow(fBase, fExponent);
}

// 0x005165B0
float __cdecl sub_005165B0_Log(float fValue)
{
    return (float)log(fValue);
}

// 0x005165D0
float __cdecl sub_005165D0_Pow(float fBase, float fExponent)
{
    return (float)pow(fBase, fExponent);
}

// 0x005165F0
float __stdcall D2SOUNDSMP_ScaleToDecibels(float fMin, float fMax, float fValue)
{
    if (fValue <= fMin + 0.0001f)
        return -10000.0f;
    if (fValue >= fMax - 0.0001f)
        return 0.0f;
    return (float)(log10(fValue != 0.0f ? (fMin + fMax) / fValue : (fMin + fMax) / fMax) * -2000.0f);
}

// 0x00516670
float __stdcall D2SOUNDSMP_DecibelsToScale(float fVolume)
{
    if (fVolume + 0.0001f > 0.0)
        return 1.0f;
    if (fVolume - 0.0001f < -10000.0)
        return 0.0f;
    return (float)pow(10.0, fVolume / 2000.0);
}

// 0x005166D0
static const unsigned char* __stdcall D2SOUNDSMP_FindRiffChunk(const unsigned char* pData, unsigned int* pnSize, unsigned int nChunkId, unsigned int* pnChunkSize)
{
    while (*pnSize >= 8)
    {
        *pnSize -= 8;
        const unsigned int nRemaining = *pnSize;
        const unsigned int* pHeader = (const unsigned int*)pData;
        pData += 8;
        const unsigned int nLength = pHeader[1];
        if (pHeader[0] == nChunkId)
        {
            *pnChunkSize = nLength;
            return pData;
        }

        if (nRemaining < nLength)
            return 0;

        *pnSize = nRemaining - nLength;
        pData += nLength;
    }

    return 0;
}

// 0x00516720
void __fastcall D2SOUNDSMP_InitWaveFormat(D2WaveFormatStrc* pFormat, int nChannels)
{
    memset(pFormat, 0, sizeof(D2WaveFormatStrc));
    pFormat->wFormatTag = 1;
    pFormat->nChannels = nChannels;
    pFormat->nSamplesPerSec = 22050;
    pFormat->wBitsPerSample = 16;
    pFormat->nBlockAlign = nChannels * 2;
    pFormat->nAvgBytesPerSec = pFormat->nSamplesPerSec * pFormat->nBlockAlign;
}

// 0x00516760
const unsigned char* __fastcall D2SOUNDSMP_ReadWaveHeader(const unsigned int* pRiff, unsigned int* pnSize, D2WaveFormatStrc* pFormat)
{
    D2WaveFormatStrc* const pOut = pFormat;
    if (*pnSize < 0x20)
        return 0;

    *pnSize -= 12;
    if (pRiff[0] != 0x46464952 || pRiff[2] != 0x45564157)
        return 0;

    unsigned int nChunkSize = 0;
    const unsigned char* pChunk = D2SOUNDSMP_FindRiffChunk((const unsigned char*)pRiff + 12, pnSize, 0x20746D66, &nChunkSize);
    if (!pChunk)
        return 0;

    if (nChunkSize < 0x10)
        return 0;

    if (*pnSize < nChunkSize)
        return 0;

    const D2WaveFormatStrc* pChunkFormat = (const D2WaveFormatStrc*)pChunk;
    *pnSize -= nChunkSize;
    pChunk += nChunkSize;
    pOut->wFormatTag = pChunkFormat->wFormatTag;
    pOut->nChannels = pChunkFormat->nChannels;
    pOut->nSamplesPerSec = pChunkFormat->nSamplesPerSec;
    pOut->nAvgBytesPerSec = pChunkFormat->nAvgBytesPerSec;
    pOut->nBlockAlign = pChunkFormat->nBlockAlign;
    pOut->wBitsPerSample = pChunkFormat->wBitsPerSample;
    pOut->cbSize = 0;

    pChunk = D2SOUNDSMP_FindRiffChunk(pChunk, pnSize, 0x61746164, &nChunkSize);
    if (pChunk && *pnSize >= nChunkSize)
    {
        *pnSize = nChunkSize;
        return pChunk;
    }

    return 0;
}

static float SOUND_SqrtF(float fValue)
{
    return (float)sqrt(fValue);
}

static float SOUND_LogF(float fValue)
{
    return (float)log(fValue);
}

static float SOUND_Log2F(float fValue)
{
    return SOUND_LogF(fValue) / 0.6931472f;
}

static float SOUND_PowF(float fBase, float fExponent)
{
    return (float)pow(fBase, fExponent);
}

static double SOUND_GetDistance(float fX, float fY, float fZ)
{
    return SOUND_SqrtF(fX * fX + fY * fY + fZ * fZ);
}

static __forceinline float SOUND_GetAttenuation(float fDistance)
{
    if (fDistance > 100.0)
        fDistance = gfMaxSoundDistance;

    if (fDistance < 2.0f)
        return 0.0f;

    return SOUND_Log2F(fDistance * 0.5f) * 6.0f;
}

// 0x00516830
void __fastcall D2SOUNDSMP_GetPositionalVolumePan(int* pVolume, int* pPan, float fX, float fY, float fZ)
{
    const float fAttenuation = SOUND_GetAttenuation(SOUND_GetDistance(fX, fY, fZ));

    int nVolume = (int)(255.0f / SOUND_PowF(10.0f, fAttenuation / 20.0f));
    nVolume = nVolume > 0 ? nVolume : 0;
    if (nVolume >= 255)
        nVolume = 255;

    const float fPan = fX * 127.0f / 1.25f + 128.0f;
    int nPan = (int)fPan;
    nPan = nPan > 0 ? nPan : 0;
    if (nPan >= 255)
        nPan = 255;

    *pVolume = nVolume;
    *pPan = nPan;
}

#include "gen/data/Source/D2Sound/Src/D2SoundSmp.inc"
