#pragma once
// D2Sound DirectSound interfaces, buffers, wave formats and sound channel records

#include "D2Check.h"
#include "D2Structs.h"

struct D2WaveFormatStrc;
struct D2GuidStrc;
struct D2SoundStrc;
struct D2SoundNodeStrc;
struct D2SoundChannelEntryStrc;
struct D2KsPropertySetStrc;
struct D2DSoundBufferStrc;
struct D2WaveStrc;
struct D2DirectSoundStrc;
struct D2DSound3DBufferStrc;
struct D2DSBufferDescStrc;

#pragma pack(push, 1)
struct D2WaveFormatStrc
{
    unsigned short wFormatTag; // 0x00
    unsigned short nChannels; // 0x02
    unsigned int nSamplesPerSec; // 0x04
    unsigned int nAvgBytesPerSec; // 0x08
    unsigned short nBlockAlign; // 0x0C
    unsigned short wBitsPerSample; // 0x0E
    unsigned short cbSize; // 0x10
};
#pragma pack(pop)

struct D2SoundStrc
{
    D2DSoundBufferStrc* pBuffer; // 0x00
    unsigned int nBufferSize; // 0x04
    unsigned int nHalfBufferBytes; // 0x08
    D2DSound3DBufferStrc* p3DBuffer; // 0x0C
    D2KsPropertySetStrc* pPropertySet; // 0x10
    void* pData; // 0x14
    unsigned int nDataSize; // 0x18
    int bStreaming; // 0x1C
    unsigned long nPosition; // 0x20
    unsigned long nFillPosition; // 0x24
    int bSecondHalf; // 0x28
    int bStreamed; // 0x2C
    int nLoopStart; // 0x30
    unsigned int dwFlags; // 0x34
    int nVolume; // 0x38
    union
    {
        int nAttenuationBits; // 0x3C
        float fAttenuation; // 0x3C
    };
    int bNoLoop; // 0x40
    unsigned int nMinDataSize; // 0x44
    void* hStream; // 0x48
    int bFading; // 0x4C
    int nFadeFrom; // 0x50
    int nFadeTo; // 0x54
    int nFadeStart; // 0x58
    int nFadeEnd; // 0x5C
};

struct D2SoundNodeStrc
{
    union
    {
        int nKey; // 0x00
        D2SoundStrc* pSound; // 0x00
    };
    D2SoundNodeStrc* pNext; // 0x04
};

struct D2SoundChannelEntryStrc
{
    const char* szFile; // 0x00
    int bBusy; // 0x04
};

struct D2KsPropertySetStrc
{
    virtual long __stdcall QueryInterface(const D2GuidStrc& riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall Get(const D2GuidStrc& rguidPropSet, unsigned long dwPropID, void* pInstanceData, unsigned long cbInstanceData, void* pPropData, unsigned long cbPropData, unsigned long* pcbReturned) = 0;
    virtual long __stdcall Set(const D2GuidStrc& rguidPropSet, unsigned long dwPropID, void* pInstanceData, unsigned long cbInstanceData, void* pPropData, unsigned long cbPropData) = 0;
    virtual long __stdcall QuerySupport(const D2GuidStrc& rguidPropSet, unsigned long dwPropID, unsigned long* pTypeSupport) = 0;
};

struct D2DSoundBufferStrc
{
    virtual long __stdcall QueryInterface(const D2GuidStrc& riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetCaps(void* pCaps) = 0;
    virtual long __stdcall GetCurrentPosition(unsigned long* pdwPlay, unsigned long* pdwWrite) = 0;
    virtual long __stdcall GetFormat(void* pFormat, unsigned long dwSize, unsigned long* pdwWritten) = 0;
    virtual long __stdcall GetVolume(long* plVolume) = 0;
    virtual long __stdcall GetPan(long* plPan) = 0;
    virtual long __stdcall GetFrequency(unsigned long* pdwFrequency) = 0;
    virtual long __stdcall GetStatus(unsigned long* pdwStatus) = 0;
    virtual long __stdcall Initialize(void* pDirectSound, const void* pDesc) = 0;
    virtual long __stdcall Lock(unsigned long dwOffset, unsigned long dwBytes, void** ppv1, unsigned long* pdw1, void** ppv2, unsigned long* pdw2, unsigned long dwFlags) = 0;
    virtual long __stdcall Play(unsigned long dwReserved, unsigned long dwPriority, unsigned long dwFlags) = 0;
    virtual long __stdcall SetCurrentPosition(unsigned long dwPosition) = 0;
    virtual long __stdcall SetFormat(const void* pFormat) = 0;
    virtual long __stdcall SetVolume(long lVolume) = 0;
    virtual long __stdcall SetPan(long lPan) = 0;
    virtual long __stdcall SetFrequency(unsigned long dwFrequency) = 0;
    virtual long __stdcall Stop() = 0;
    virtual long __stdcall Unlock(void* pv1, unsigned long dw1, void* pv2, unsigned long dw2) = 0;
    virtual long __stdcall Restore() = 0;
};

struct D2WaveStrc
{
    char szName[80]; // 0x00
    void* pData; // 0x50
    unsigned int nSize; // 0x54
    unsigned int nType; // 0x58
    D2WaveStrc* pNext; // 0x5C
};

struct D2DirectSoundStrc
{
    virtual long __stdcall QueryInterface(const D2GuidStrc& riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall CreateSoundBuffer(D2DSBufferDescStrc* pDesc, D2DSoundBufferStrc** ppBuffer, void* pUnkOuter) = 0;
    virtual long __stdcall GetCaps(void* pCaps) = 0;
    virtual long __stdcall DuplicateSoundBuffer(D2DSoundBufferStrc* pOriginal, D2DSoundBufferStrc** ppDuplicate) = 0;
    virtual long __stdcall SetCooperativeLevel(void* hWnd, unsigned long dwLevel) = 0;
    virtual long __stdcall Compact() = 0;
    virtual long __stdcall GetSpeakerConfig(unsigned long* pdwSpeakerConfig) = 0;
    virtual long __stdcall SetSpeakerConfig(unsigned long dwSpeakerConfig) = 0;
    virtual long __stdcall Initialize(const D2GuidStrc* pcGuidDevice) = 0;
};

struct D2DSound3DBufferStrc
{
    virtual long __stdcall QueryInterface(const D2GuidStrc& riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetAllParameters(void* pParams) = 0;
    virtual long __stdcall GetConeAngles(unsigned long* pdwInside, unsigned long* pdwOutside) = 0;
    virtual long __stdcall GetConeOrientation(void* pvOrientation) = 0;
    virtual long __stdcall GetConeOutsideVolume(long* plVolume) = 0;
    virtual long __stdcall GetMaxDistance(float* pflMaxDistance) = 0;
    virtual long __stdcall GetMinDistance(float* pflMinDistance) = 0;
    virtual long __stdcall GetMode(unsigned long* pdwMode) = 0;
    virtual long __stdcall GetPosition(void* pvPosition) = 0;
    virtual long __stdcall GetVelocity(void* pvVelocity) = 0;
    virtual long __stdcall SetAllParameters(const void* pParams, unsigned long dwApply) = 0;
    virtual long __stdcall SetConeAngles(unsigned long dwInside, unsigned long dwOutside, unsigned long dwApply) = 0;
    virtual long __stdcall SetConeOrientation(float x, float y, float z, unsigned long dwApply) = 0;
    virtual long __stdcall SetConeOutsideVolume(long lVolume, unsigned long dwApply) = 0;
    virtual long __stdcall SetMaxDistance(float flMaxDistance, unsigned long dwApply) = 0;
    virtual long __stdcall SetMinDistance(float flMinDistance, unsigned long dwApply) = 0;
    virtual long __stdcall SetMode(unsigned long dwMode, unsigned long dwApply) = 0;
    virtual long __stdcall SetPosition(float x, float y, float z, unsigned long dwApply) = 0;
    virtual long __stdcall SetVelocity(float x, float y, float z, unsigned long dwApply) = 0;
};

struct D2DSBufferDescStrc
{
    unsigned long dwSize; // 0x00
    unsigned long dwFlags; // 0x04
    unsigned long dwBufferBytes; // 0x08
    unsigned long dwReserved; // 0x0C
    D2WaveFormatStrc* lpwfxFormat; // 0x10
};

D2_CHECK_SIZE(D2WaveFormatStrc, 0x12);
D2_CHECK_SIZE(D2SoundStrc, 0x60);
D2_CHECK_SIZE(D2SoundNodeStrc, 0x8);
D2_CHECK_SIZE(D2SoundChannelEntryStrc, 0x8);
D2_CHECK_SIZE(D2WaveStrc, 0x60);
D2_CHECK_SIZE(D2DSBufferDescStrc, 0x14);
