#include "D2GameTypes.h"

#include "D2GfxTypes.h"

#include "D2Win32Base.h"

#include "D2DDrawTypes.h"

#include "D2GlideTypes.h"

#include "D2SysTypes.h"

#include "D2Sound.h"

#include "D2SoundTypes.h"
#include "FogApi.h"
#include "StormApi.h"




extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2SoundStrc;

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218

extern "C" int __cdecl rand();                                                                              // 0x00687461








extern D2CriticalSectionStrc gtSoundLock;                                                           // 0x0088174C

static D2SoundStrc* gpSoundChannel;                                                                // 0x00881794

extern int gnChannelValue;                                                                         // 0x00881798

extern int gbChannelFlag;                                                                          // 0x0088179C

extern int gnChannelTableSel;                                                                      // 0x008817A4

extern int gbChannelTableInit;                                                                     // 0x008817A8

void __cdecl sub_00419F30(); // 0x00419F30

D2DirectSoundStrc* __cdecl D2SOUND_GetDirectSound(); // 0x00513B50


extern int gnChannelTableSel; // 0x008817A4

extern int gbChannelTableInit; // 0x008817A8

extern "C" { int gnStreamChannelArg; } // 0x008817A0





extern "C" __declspec(dllimport) unsigned int __stdcall GetWindowsDirectoryA(char* lpBuffer, unsigned int uSize); // 0x006CC374

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

extern "C" int __stdcall DirectSoundEnumerateA(void* pfCallback, void* pContext);                           // 0x006B134A

int __stdcall sub_00513A20_EnumCallback(void* pGuid, const char* szDescription, const char* szModule, void* pContext); // 0x00513A20

void __cdecl sub_005140D0_InitDirectSound(); // 0x005140D0

int __fastcall D2SOUNDUTIL_GetVxdFileVersion(const char* szPath, unsigned int* pMajor, unsigned int* pMinor, unsigned int* pBuild); // 0x00516CA0

extern int gnChannelArg;                                                                             // 0x008816DC

int gbSoundReady;                                                                                  // 0x00881764

extern int gfPositionalSound;                                                                              // 0x0088176C

int gbEaxEnabled;                                                                                  // 0x00881770

extern int gbSoundEnumDone;                                                                        // 0x00881780

int gbOldSoundDriver;                                                                              // 0x00881784

int gbCheckEmu10k1;                                                                                // 0x00881788

extern int gbCheckCrlds3d;                                                                         // 0x0088178C

extern int gfSoundExpansion;                                                                              // 0x00881790

extern D2KsPropertySetStrc* gpEaxListenerPropertySet;                                              // 0x008816D8

extern const D2GuidStrc gtEaxListener10PropertySet;                                                         // 0x006DE480

extern const D2GuidStrc gtEaxListener20PropertySet;                                                 // 0x006DE460

int gbEaxRoomOff;                                                                                  // 0x00881778

// 0x00513BC0
int __fastcall sub_00513BC0_SetEaxRoomOff(int nEaxVersion)
{
    if (!gpEaxListenerPropertySet)
    {
        return 0;
    }

    if (nEaxVersion == 1)
    {
        float fVolume = 0.0f;
        if (gpEaxListenerPropertySet->Set(gtEaxListener10PropertySet, 2, 0, 0, &fVolume, 4) < 0)
        {
            return 0;
        }
    }
    else
    {
        int nRoom = -10000;
        if (gpEaxListenerPropertySet->Set(gtEaxListener20PropertySet, 2, 0, 0, &nRoom, 4) < 0)
        {
            return 0;
        }
        if (gpEaxListenerPropertySet->Set(gtEaxListener20PropertySet, 3, 0, 0, &nRoom, 4) < 0)
        {
            return 0;
        }
    }

    gbEaxRoomOff = 1;
    return 1;
}

struct D2DSGuid { unsigned long a; unsigned short b; unsigned short c; unsigned char d[8]; };

struct D2DSBufferCaps { unsigned long dwSize; unsigned long dwFlags; unsigned long dwBufferBytes; unsigned long dwUnlockTransferRate; unsigned long dwPlayCpuOverhead; };

struct D2DSCaps { unsigned long dwSize; unsigned long a[10]; unsigned long dwMaxHw3DAllBuffers; unsigned long b[13]; };

struct D2DSUnknown
{
    virtual long __stdcall QueryInterface(const D2DSGuid& riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct D2DSBuffer : D2DSUnknown
{
    virtual long __stdcall GetCaps(D2DSBufferCaps* pCaps) = 0;
    virtual long __stdcall GetCurrentPosition(unsigned long* a, unsigned long* b) = 0;
    virtual long __stdcall GetFormat(D2WaveFormatStrc* a, unsigned long b, unsigned long* c) = 0;
    virtual long __stdcall GetVolume(long* a) = 0;
    virtual long __stdcall GetPan(long* a) = 0;
    virtual long __stdcall GetFrequency(unsigned long* a) = 0;
    virtual long __stdcall GetStatus(unsigned long* a) = 0;
    virtual long __stdcall Initialize(void* a, const D2DSBufferDescStrc* b) = 0;
    virtual long __stdcall Lock(unsigned long a, unsigned long b, void** c, unsigned long* d, void** e, unsigned long* f, unsigned long g) = 0;
    virtual long __stdcall Play(unsigned long dwReserved1, unsigned long dwPriority, unsigned long dwFlags) = 0;
    virtual long __stdcall SetCurrentPosition(unsigned long a) = 0;
    virtual long __stdcall SetFormat(const D2WaveFormatStrc* pFormat) = 0;
};

struct D2DSDirectSound : D2DSUnknown
{
    virtual long __stdcall CreateSoundBuffer(const D2DSBufferDescStrc* pDesc, D2DSBuffer** ppBuffer, D2DSUnknown* pOuter) = 0;
    virtual long __stdcall GetCaps(D2DSCaps* pCaps) = 0;
    virtual long __stdcall DuplicateSoundBuffer(D2DSBuffer* a, D2DSBuffer** b) = 0;
    virtual long __stdcall SetCooperativeLevel(void* hWnd, unsigned long dwLevel) = 0;
};

struct D2DSPropertySet : D2DSUnknown
{
    virtual long __stdcall Get(const D2DSGuid& a, unsigned long b, void* c, unsigned long d, void* e, unsigned long f, unsigned long* g) = 0;
    virtual long __stdcall Set(const D2DSGuid& a, unsigned long b, void* c, unsigned long d, void* e, unsigned long f) = 0;
    virtual long __stdcall QuerySupport(const D2DSGuid& rguid, unsigned long nId, unsigned long* pSupport) = 0;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210

extern "C" long __stdcall DirectSoundCreate(const D2DSGuid* pGuid, D2DSDirectSound** ppDS, D2DSUnknown* pOuter); // 0x006B1344

void* __cdecl WINDOW_GetWindow(); // 0x004F59A0


const char* __fastcall D2SOUND_GetDirectSoundErrorString(long hResult); // 0x00513ED0

void __cdecl D2SOUND_CloseSoundSystem(); // 0x00514060

void __cdecl D2SOUND_LoadRegistrySettings(); // 0x00514B60

int __fastcall D2SOUNDSMP_ClearSoundBuffer(D2DSBuffer* pBuffer, unsigned long nOffset, unsigned long nBytes); // 0x00515300


void __cdecl D2SOUNDSMP_StartSoundThread(); // 0x00516510


extern D2DSPropertySet* gpPropertySet_008816D8; // 0x008816D8

extern D2DSCaps gtDSCaps; // 0x008816E0

extern int gbUseEax_00881770; // 0x00881770

extern int gbOldSoundDriver; // 0x00881784

extern const D2DSGuid gtIidDirectSound3DBuffer; // 0x006DE3D0

extern const D2DSGuid gtIidKsPropertySet; // 0x006DE410

extern const D2DSGuid gDSPROPSETID_EAX20_ListenerProperties_006DE460; // 0x006DE460

extern const D2DSGuid gDSPROPSETID_EAX_ReverbProperties_006DE480; // 0x006DE480

int gnChannelArg; // 0x008816DC

D2DSUnknown* gp3DBuffer; // 0x00881740

D2DSBuffer* gpEaxBuffer; // 0x00881744

D2DSBuffer* gpSoundObject; // 0x00881748

D2DSDirectSound* gpDirectSound; // 0x00881768

int gb3DSound; // 0x0088176C

int gnEaxVersion; // 0x00881774

int gbSoundLockInit; // 0x0088177C

extern "C" const D2DSGuid gData_006DE3D0 = { // 0x006DE3D0
    0x279AFA86,
    0x4981,
    0x11CE,
    { 0xA5, 0x21, 0x00, 0x20, 0xAF, 0x0B, 0xE5, 0x60 }
};
#pragma comment(linker, "/alternatename:?gtIidDirectSound3DBuffer@@3UD2DSGuid@@B=_gData_006DE3D0")

extern "C" const unsigned char gData_006DE3E0[48] = { // 0x006DE3E0
    0x81, 0x07, 0x21, 0xB0, 0xCD, 0x89, 0xD0, 0x11, 0xAF, 0x08, 0x00, 0xA0, 0xC9, 0x25, 0xCD, 0x16,
    0x82, 0x07, 0x21, 0xB0, 0xCD, 0x89, 0xD0, 0x11, 0xAF, 0x08, 0x00, 0xA0, 0xC9, 0x25, 0xCD, 0x16,
    0x83, 0x07, 0x21, 0xB0, 0xCD, 0x89, 0xD0, 0x11, 0xAF, 0x08, 0x00, 0xA0, 0xC9, 0x25, 0xCD, 0x16
};

extern "C" const D2DSGuid gData_006DE410 = { // 0x006DE410
    0x31EFAC30,
    0x515C,
    0x11D0,
    { 0xA9, 0xAA, 0x00, 0xAA, 0x00, 0x61, 0xBE, 0x93 }
};
#pragma comment(linker, "/alternatename:?gtIidKsPropertySet@@3UD2DSGuid@@B=_gData_006DE410")

extern "C" const unsigned char gData_006DE420[64] = { // 0x006DE420
    0x3F, 0x33, 0x41, 0xC2, 0x1B, 0x1C, 0xD2, 0x11, 0x94, 0xF5, 0x00, 0xC0, 0x4F, 0xC2, 0x8A, 0xCA,
    0x40, 0x33, 0x41, 0xC2, 0x1B, 0x1C, 0xD2, 0x11, 0x94, 0xF5, 0x00, 0xC0, 0x4F, 0xC2, 0x8A, 0xCA,
    0x42, 0x33, 0x41, 0xC2, 0x1B, 0x1C, 0xD2, 0x11, 0x94, 0xF5, 0x00, 0xC0, 0x4F, 0xC2, 0x8A, 0xCA,
    0x81, 0x3B, 0xF5, 0x4F, 0xE0, 0x1C, 0xD3, 0x11, 0xAA, 0xB8, 0x00, 0xA0, 0xC9, 0x59, 0x49, 0xD5
};

extern "C" const char* gData_0072F838[15] = { // 0x0072F838
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

static int gnChannelCountA = 8; // 0x0072F874

static D2SoundChannelEntryStrc gaChannelTableA[8] = { // 0x0072F878
    { "data\\global\\music\\common\\options.wav", 0 },
    { "data\\global\\music\\act1\\caves.wav", 0 },
    { "data\\global\\music\\act1\\monastery.wav", 0 },
    { "data\\global\\music\\act1\\crypt.wav", 0 },
    { "data\\global\\music\\act2\\harem.wav", 0 },
    { "data\\global\\music\\act2\\tombs.wav", 0 },
    { "data\\global\\music\\act3\\spider.wav", 0 },
    { "data\\global\\music\\act3\\kurastsewer.wav", 0 }
};

static D2SoundChannelEntryStrc gaChannelTableB[8] = { // 0x0072F8B8
    { "data\\global\\music\\introedit.wav", 0 },
    { "data\\global\\music\\act5\\icecaves.wav", 0 },
    { "data\\global\\music\\act5\\xtemple.wav", 0 },
    { "data\\global\\music\\act2\\desert.wav", 0 },
    { "data\\global\\music\\act2\\sewer.wav", 0 },
    { "data\\global\\music\\act3\\kurast.wav", 0 },
    { "data\\global\\music\\act3\\kurastsewer.wav", 0 },
    { "data\\global\\music\\act4\\diablo.wav", 0 }
};

static int gnChannelCountB = 8; // 0x0072F8F8

extern "C" void __fastcall D2SOUND_CreateStreamChannel(int nArg); // 0x00514780

#define DSERR_BUFFERLOST ((long)0x88780096)

struct D2EaxEnvironmentStrc
{
    unsigned int dwEnvironment;
    float fEnvironmentSize;
    float fEnvironmentDiffusion;
    int nRoom;
    int nRoomHF;
    float fDecayTime;
    float fDecayHFRatio;
    int nReflections;
    float fReflectionsDelay;
    int nReverb;
    float fReverbDelay;
    float fRoomRolloffFactor;
    float fAirAbsorptionHF;
};


extern D2KsPropertySetStrc* gpEaxListenerPropertySet; // 0x008816D8

// 0x00513C50
void __fastcall D2SOUND_SetEaxEnvironment(D2EaxEnvironmentStrc* pEnvironment)
{
    if (!gbEaxEnabled || !gpEaxListenerPropertySet)
        return;
    if (gnEaxVersion == 1)
    {
        float fVolume = sub_00516670_RoomToVolume((float)pEnvironment->nRoom);
        gpEaxListenerPropertySet->Set(gtEaxListener10PropertySet, 1, 0, 0, pEnvironment, 4);
        gpEaxListenerPropertySet->Set(gtEaxListener10PropertySet, 2, 0, 0, &fVolume, 4);
        gpEaxListenerPropertySet->Set(gtEaxListener10PropertySet, 3, 0, 0, &pEnvironment->fDecayTime, 4);
    }
    if (gnEaxVersion == 2)
    {
        int nFlags = 0x20;
        gpEaxListenerPropertySet->Set(gtEaxListener20PropertySet, 0xB, 0, 0, pEnvironment, 4);
        gpEaxListenerPropertySet->Set(gtEaxListener20PropertySet, 0xF, 0, 0, &nFlags, 4);
        gpEaxListenerPropertySet->Set(gtEaxListener20PropertySet, 0xB, 0, 0, pEnvironment, 4);
        gpEaxListenerPropertySet->Set(gtEaxListener20PropertySet, 0xC, 0, 0, &pEnvironment->fEnvironmentSize, 4);
        gpEaxListenerPropertySet->Set(gtEaxListener20PropertySet, 0xD, 0, 0, &pEnvironment->fEnvironmentDiffusion, 4);
        gpEaxListenerPropertySet->Set(gtEaxListener20PropertySet, 2, 0, 0, &pEnvironment->nRoom, 4);
        gpEaxListenerPropertySet->Set(gtEaxListener20PropertySet, 3, 0, 0, &pEnvironment->nRoomHF, 4);
        gpEaxListenerPropertySet->Set(gtEaxListener20PropertySet, 5, 0, 0, &pEnvironment->fDecayTime, 4);
        gpEaxListenerPropertySet->Set(gtEaxListener20PropertySet, 6, 0, 0, &pEnvironment->fDecayHFRatio, 4);
        gpEaxListenerPropertySet->Set(gtEaxListener20PropertySet, 7, 0, 0, &pEnvironment->nReflections, 4);
        gpEaxListenerPropertySet->Set(gtEaxListener20PropertySet, 8, 0, 0, &pEnvironment->fReflectionsDelay, 4);
        gpEaxListenerPropertySet->Set(gtEaxListener20PropertySet, 9, 0, 0, &pEnvironment->nReverb, 4);
        gpEaxListenerPropertySet->Set(gtEaxListener20PropertySet, 0xA, 0, 0, &pEnvironment->fReverbDelay, 4);
        gpEaxListenerPropertySet->Set(gtEaxListener20PropertySet, 4, 0, 0, &pEnvironment->fRoomRolloffFactor, 4);
        gpEaxListenerPropertySet->Set(gtEaxListener20PropertySet, 0xE, 0, 0, &pEnvironment->fAirAbsorptionHF, 4);
    }
    gbEaxRoomOff = pEnvironment->nRoom == -10000;
}

// 0x00513ED0
const char* __fastcall D2SOUND_GetDirectSoundErrorString(long hResult)
{
    switch (hResult)
    {
    case 0x80004005:
        return "DSERR_GENERIC";
    case 0x80004002:
        return "DSERR_NOINTERFACE";
    case 0x80004001:
        return "DSERR_UNSUPPORTED";
    case 0x80040110:
        return "DSERR_NOAGGREGATION";
    case 0x80070057:
        return "DSERR_INVALIDPARAM";
    case 0x8007000E:
        return "DSERR_OUTOFMEMORY";
    case 0x8878000A:
        return "DSERR_ALLOCATED";
    case 0x88780064:
        return "DSERR_BADFORMAT";
    case 0x8878001E:
        return "DSERR_CONTROLUNAVAIL";
    case 0x88780032:
        return "DSERR_INVALIDCALL";
    case 0x88780078:
        return "DSERR_NODRIVER";
    case 0x88780046:
        return "DSERR_PRIOLEVELNEEDED";
    case 0x88780082:
        return "DSERR_ALREADYINITIALIZED";
    case 0x887800A0:
        return "DSERR_OTHERAPPHASPRIO";
    case 0x88780096:
        return "DSERR_BUFFERLOST";
    case 0x887800AA:
        return "DSERR_UNINITIALIZED";
    case 0:
        return "DS_OK";
    }
    return 0;
}



// 0x00514040
void __cdecl sub_00514040_Nothing()
{
}

// 0x00514050
void __cdecl sub_00514050_Nothing()
{
}

// 0x00514060
void __cdecl D2SOUND_CloseSoundSystem()
{
    gbSoundReady = 0;
    D2SOUNDSMP_SetMasterVolume(0);
    D2SOUND_DestroyStreamChannel();
    D2SOUNDSMP_StopSoundThread();
    D2SOUND_ReleaseSoundObjects();
    if (gpSoundObject)
    {
        gpSoundObject->Release();
        gpSoundObject = 0;
    }
    if (gpDirectSound)
    {
        gpDirectSound->Release();
        gpDirectSound = 0;
    }
    if (gbSoundLockInit)
    {
        DeleteCriticalSection(&gtSoundLock);
        gbSoundLockInit = 0;
    }
}

// 0x005140D0
void __cdecl sub_005140D0_InitDirectSound()
{
    if (gb3DSound && gbOldSoundDriver)
    {
        return;
    }

    D2_ASSERT(!gbSoundLockInit, 0x53);
    InitializeCriticalSection(&gtSoundLock);
    gbSoundLockInit = 1;

    long hResult = DirectSoundCreate(0, &gpDirectSound, 0);
    if (hResult < 0)
    {
        LOGMANAGER_WriteLogLine("DirectSound error: %s returned on DirectSoundCreate", D2SOUND_GetDirectSoundErrorString(hResult));
        D2SOUND_CloseSoundSystem();
        return;
    }

    hResult = gpDirectSound->SetCooperativeLevel(WINDOW_GetWindow(), 2);
    if (hResult < 0)
    {
        LOGMANAGER_WriteLogLine("DirectSound error: %s returned on SetCooperativeLevel", D2SOUND_GetDirectSoundErrorString(hResult));
        D2SOUND_CloseSoundSystem();
        return;
    }

    D2DSBufferDescStrc tDesc;
    memset(&tDesc, 0, sizeof(tDesc));
    tDesc.dwSize = 0x14;
    tDesc.dwFlags = 1;
    if (gb3DSound)
    {
        tDesc.dwFlags = 0x11;
    }
    tDesc.dwBufferBytes = 0;
    tDesc.lpwfxFormat = 0;
    hResult = gpDirectSound->CreateSoundBuffer(&tDesc, &gpSoundObject, 0);
    if (hResult < 0)
    {
        LOGMANAGER_WriteLogLine("........DirectSound progress: %s returned on failed CreateSoundBuffer", D2SOUND_GetDirectSoundErrorString(hResult));
        D2SOUND_CloseSoundSystem();
        return;
    }

    gtDSCaps.dwSize = 0x60;
    hResult = gpDirectSound->GetCaps(&gtDSCaps);
    if (hResult < 0)
    {
        LOGMANAGER_WriteLogLine("........DirectSound progress: %s returned on failed GetCaps", D2SOUND_GetDirectSoundErrorString(hResult));
        D2SOUND_CloseSoundSystem();
        return;
    }

    if (gb3DSound && gtDSCaps.dwMaxHw3DAllBuffers < 0x10)
    {
        LOGMANAGER_WriteLogLine("........DirectSound progress: %d buffers available is less than min needed %d buffers for 3d sound", gtDSCaps.dwMaxHw3DAllBuffers, 0x10);
        D2SOUND_CloseSoundSystem();
        return;
    }

    D2WaveFormatStrc tFormat;
    memset(&tFormat, 0, sizeof(tFormat));
    tFormat.wFormatTag = 1;
    tFormat.nChannels = 2;
    tFormat.nSamplesPerSec = 0x5622;
    tFormat.wBitsPerSample = 0x10;
    tFormat.nBlockAlign = 4;
    tFormat.nAvgBytesPerSec = 0x15888;
    hResult = gpSoundObject->SetFormat(&tFormat);
    if (hResult < 0)
    {
        LOGMANAGER_WriteLogLine("........DirectSound progress: %s returned on failed SetFormat", D2SOUND_GetDirectSoundErrorString(hResult));
        gpSoundObject->Release();
        D2SOUND_CloseSoundSystem();
        return;
    }

    gnEaxVersion = 0;
    if (gbUseEax_00881770)
    {
        D2WaveFormatStrc tEaxFormat;
        D2SOUNDSMP_InitWaveFormat(&tEaxFormat, 1);
        D2DSBufferDescStrc tEaxDesc;
    memset(&tEaxDesc, 0, sizeof(tEaxDesc));
        tEaxDesc.dwSize = 0x14;
        tEaxDesc.dwBufferBytes = 0x400;
        tEaxDesc.dwFlags = 0x12;
        tEaxDesc.lpwfxFormat = &tEaxFormat;
        unsigned long nSupport;
        if (!gnEaxVersion)
        {
            if (gpDirectSound->CreateSoundBuffer(&tEaxDesc, &gpEaxBuffer, 0) >= 0
                && gpEaxBuffer->QueryInterface(gtIidDirectSound3DBuffer, (void**)&gp3DBuffer) >= 0
                && gp3DBuffer->QueryInterface(gtIidKsPropertySet, (void**)&gpPropertySet_008816D8) >= 0
                && gpPropertySet_008816D8->QuerySupport(gDSPROPSETID_EAX20_ListenerProperties_006DE460, 1, &nSupport) >= 0
                && (nSupport & 3) == 3
                && sub_00513BC0_SetEaxRoomOff(2))
            {
                gnEaxVersion = 2;
            }
            else
            {
                D2SOUND_ReleaseSoundObjects();
            }
        }
        if (!gnEaxVersion)
        {
            if (gpDirectSound->CreateSoundBuffer(&tEaxDesc, &gpEaxBuffer, 0) >= 0
                && gpEaxBuffer->QueryInterface(gtIidDirectSound3DBuffer, (void**)&gp3DBuffer) >= 0
                && gp3DBuffer->QueryInterface(gtIidKsPropertySet, (void**)&gpPropertySet_008816D8) >= 0
                && gpPropertySet_008816D8->QuerySupport(gDSPROPSETID_EAX_ReverbProperties_006DE480, 0, &nSupport) >= 0
                && (nSupport & 3) == 3
                && sub_00513BC0_SetEaxRoomOff(1))
            {
                gnEaxVersion = 1;
            }
            else
            {
                D2SOUND_ReleaseSoundObjects();
            }
        }
        if (!gnEaxVersion)
        {
            LOGMANAGER_WriteLogLine("........DirectSound progress: Unsupported EAX or EAX emulation");
            D2SOUND_CloseSoundSystem();
            return;
        }
    }

    D2DSBufferCaps tCaps;
    memset(&tCaps, 0, sizeof(tCaps));
    tCaps.dwSize = 0x14;
    gpSoundObject->GetCaps(&tCaps);
    D2SOUNDSMP_ClearSoundBuffer(gpSoundObject, 0, tCaps.dwBufferBytes);
    gpSoundObject->Play(0, 0, 1);
    D2SOUNDSMP_StartSoundThread();
    D2SOUND_CreateStreamChannel(gnChannelArg);
    D2SOUND_LoadRegistrySettings();
    D2SOUNDSMP_SetMasterVolume(0xFF);
    gbSoundReady = 1;
}

// 0x00514530
void __fastcall sub_00514530_InitSound(int nArg1, int nArg2)
{
    gfSoundExpansion = nArg1;
    gnChannelArg = nArg2;
    gbSoundEnumDone = 0;
    DirectSoundEnumerateA(sub_00513A20_EnumCallback, 0);

    char szPath[260];
    unsigned int nMajor;
    unsigned int nMinor;
    unsigned int nBuild;
    if (gbCheckEmu10k1)
    {
        GetWindowsDirectoryA(szPath, sizeof(szPath));
        strcat(szPath, "\\SYSTEM\\EMU10K1.VXD");
        if (D2SOUNDUTIL_GetVxdFileVersion(szPath, &nMajor, &nMinor, &nBuild) && nMajor == 4)
        {
            if (nMinor == 6)
            {
                if (nBuild - 622 <= 88)
                {
                    gbOldSoundDriver = 1;
                }
            }
            else if (nMinor == 11)
            {
                if (nBuild - 628 <= 1)
                {
                    gbOldSoundDriver = 1;
                }
            }
        }
    }

    if (gbCheckCrlds3d)
    {
        GetWindowsDirectoryA(szPath, sizeof(szPath));
        strcat(szPath, "\\SYSTEM\\CRLDS3D.VXD");
        if (D2SOUNDUTIL_GetVxdFileVersion(szPath, &nMajor, &nMinor, &nBuild)
            && (nMajor < 4 || nMajor == 4 && (nMinor < 12 || nMinor == 12 && nBuild < 0x40B)))
        {
            gbOldSoundDriver = 1;
        }
    }

    if (!gbSoundReady)
    {
        gfPositionalSound = 1;
        gbEaxEnabled = 1;
        sub_005140D0_InitDirectSound();
        if (!gbSoundReady)
        {
            gfPositionalSound = 1;
            gbEaxEnabled = 0;
            sub_005140D0_InitDirectSound();
            if (!gbSoundReady)
            {
                gfPositionalSound = 0;
                gbEaxEnabled = 0;
                sub_005140D0_InitDirectSound();
                if (!gbSoundReady)
                {
                    LOGMANAGER_WriteLogLine("\tCouldn't initialize DirectSound");
                }
            }
        }
    }
}

// Kept noinline: a static that takes its arguments in registers; sub_00514990_PickRandomChannel (0x514990) calls it out of line in the image (the #368 case).
// 0x00514710
__declspec(noinline) static D2SoundChannelEntryStrc* D2SOUND_GetChannelEntry(int nIndex)
{
    if (!gbChannelTableInit)
    {
        gbChannelTableInit = 1;
// build: symbol ?D2SOUND_IsExpansion@* 0x00513AE0
        gnChannelTableSel = D2SOUND_IsExpansion();
    }
    D2_ASSERT(gnChannelCountA == gnChannelCountB, 0x52);
    D2_ASSERT(nIndex < gnChannelCountA, 0x53);
    if (gnChannelTableSel)
        return &gaChannelTableB[nIndex];
    return &gaChannelTableA[nIndex];
}

// 0x00514860 inlines 0x00514710 and the other callers call it, so the body is here twice: this copy for the inlined use.
static D2SoundChannelEntryStrc* sub_N19_GetChannelEntry(int nIndex)
{
    if (!gbChannelTableInit)
    {
        gbChannelTableInit = 1;
// build: symbol ?D2SOUND_IsExpansion@* 0x00513AE0
        gnChannelTableSel = D2SOUND_IsExpansion();
    }
    D2_ASSERT(gnChannelCountA == gnChannelCountB, 0x52);
    D2_ASSERT(nIndex < gnChannelCountA, 0x53);
    if (gnChannelTableSel)
        return &gaChannelTableB[nIndex];
    return &gaChannelTableA[nIndex];
}

// 0x00514780
extern "C" void __fastcall D2SOUND_CreateStreamChannel(int nArg)
{
    gnStreamChannelArg = nArg;
    SFileDdaInitialize((int)D2SOUND_GetDirectSound());
    gpSoundChannel = D2SOUNDSMP_CreateSound(1, gnStreamChannelArg);
}

// Kept noinline: D2SOUND_CloseSoundSystem (0x514060) calls this out of line in the image; without it the compiler inlines it there.
// 0x005147B0
__declspec(noinline) void __cdecl D2SOUND_DestroyStreamChannel()
{
    if (gpSoundChannel)
    {
        D2SOUNDSMP_DestroySound(gpSoundChannel);
        gpSoundChannel = 0;
    }
    sub_00419F30();
}



extern int gnChannelValue; // 0x00881798

extern int gbChannelFlag; // 0x0088179C

extern int gnChannelValue; // 0x00881798

// 0x005147D0
int __fastcall D2SOUND_PlayStreamChannel(const char* szFile, int bLoop)
{
    if (gpSoundChannel && D2SOUNDSMP_GetMasterVolume() && !D2SOUNDSMP_IsSoundStreaming(gpSoundChannel) && szFile)
    {
        D2SOUNDSMP_ResetSound(gpSoundChannel);
        D2SOUNDSMP_SetSoundVolume(gpSoundChannel, 0x6E);
        if (D2SOUNDSMP_StartSoundStream(gpSoundChannel, szFile, 0, bLoop))
        {
            return 1;
        }
    }
    return 0;
}

// 0x00514840
int __cdecl D2SOUND_IsStreamChannelPlaying()
{
    if (gpSoundChannel && D2SOUNDSMP_IsSoundStreaming(gpSoundChannel))
        return 1;
    return 0;
}

// 0x00514860
void __cdecl D2SOUND_ClearChannelTable()
{
    for (int i = 0; i < gnChannelCountA; ++i)
        sub_N19_GetChannelEntry(i)->bBusy = 0;
}

// 0x005148F0
void __fastcall D2SOUND_10034(int nValue)
{
    if (nValue && !gnChannelValue)
    {
        D2SOUND_ClearChannelTable();
        gbChannelFlag = 1;
    }
    gnChannelValue = nValue;
}

// 0x00514920
int __cdecl D2SOUND_GetStreamChannelValue()
{
    return gnChannelValue;
}

// 0x00514930
void __cdecl D2SOUND_StopChannel()
{
    if (gpSoundChannel)
    {
        gnChannelValue = 0;
        if (D2SOUNDSMP_IsSoundStreaming(gpSoundChannel))
            D2SOUNDSMP_StopSound(gpSoundChannel);
    }
}

// 0x00514960
void __cdecl D2SOUND_FadeOutStreamChannel()
{
    if (gpSoundChannel)
    {
        gnChannelValue = 0;
        if (D2SOUNDSMP_IsSoundStreaming(gpSoundChannel))
            D2SOUNDSMP_StartSoundFade(gpSoundChannel, 0, 200);
    }
}

// 0x00514990
int __cdecl sub_00514990_PickRandomChannel()
{
    D2SoundChannelEntryStrc* pEntry;
    const char* szFile;
    int nIndex;
    int bCleared;

    EnterCriticalSection(&gtSoundLock);
    if (!gpSoundChannel || !D2SOUNDSMP_GetMasterVolume() || D2SOUND_IsStreamChannelPlaying())
    {
        LeaveCriticalSection(&gtSoundLock);
        return 0;
    }

    bCleared = 0;
    for (;;)
    {
        for (nIndex = 0; nIndex < gnChannelCountA; ++nIndex)
        {
            pEntry = D2SOUND_GetChannelEntry(nIndex);
            if (!pEntry->bBusy)
                goto found;
        }
        if (bCleared)
        {
            gnChannelValue = 0;
            LeaveCriticalSection(&gtSoundLock);
            return 0;
        }
        D2SOUND_ClearChannelTable();
        ++bCleared;

    found:
        if (gbChannelFlag)
        {
            pEntry = D2SOUND_GetChannelEntry(0);
            gbChannelFlag = 0;
        }
        else
        {
            nIndex = rand() % gnChannelCountA;
            for (;;)
            {
                if (!gbChannelTableInit)
                {
                    gbChannelTableInit = 1;
                    gnChannelTableSel = D2SOUND_IsExpansion();
                }
                D2_ASSERT(gnChannelCountA == gnChannelCountB, 0x52);
                D2_ASSERT(nIndex < gnChannelCountA, 0x53);
                if (gnChannelTableSel)
                    pEntry = &gaChannelTableB[nIndex];
                else
                    pEntry = &gaChannelTableA[nIndex];
                if (!pEntry->bBusy)
                    break;
                if (++nIndex >= gnChannelCountA)
                    nIndex = 0;
            }
        }

        szFile = pEntry->szFile;
        pEntry->bBusy = 1;
        if (D2SOUND_PlayStreamChannel(szFile, 0))
        {
            LeaveCriticalSection(&gtSoundLock);
            return 1;
        }
    }
}
