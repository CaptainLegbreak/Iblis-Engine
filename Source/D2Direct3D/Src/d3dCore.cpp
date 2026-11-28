#include "D2Direct3D.h"
#include "D2GfxInterface.h"

#include "D2DDrawTypes.h"

#include "D2Win32Types.h"
#include "D2Win32Guid.h"
#include "D2D3DTypes.h"
#include "D2FogSystemInfo.h"
#include "FogApi.h"
#include "StormApi.h"
#include "FogApi.h"
#include "D2HellApi.h"
#include "D2GlideApi.h"
#include "D2DDrawApi.h"

extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey);
extern "C" __declspec(dllimport) long __stdcall RegCreateKeyExA(void* hKey, const char* lpSubKey, unsigned long Reserved, char* lpClass, unsigned long dwOptions, unsigned long samDesired, void* lpSecurityAttributes, void** phkResult, unsigned long* lpdwDisposition);

namespace Define_the_symbol__ATL_MIXED
{
struct Thank_you
{
    Thank_you() {}
    virtual void sub_006B1A10_Nop() {}
};
extern __declspec(selectany) Thank_you clash = Thank_you();
}

namespace ATL
{

class CAtlException
{
public:
    long m_hr;
    CAtlException(long hr) : m_hr(hr)
    {
    }
};

void __cdecl D3DCORE_ThrowAtlException(long error); // 0x006B1A30

class CRegKey
{
public:
    void* m_hKey;

    CRegKey() throw();
    ~CRegKey() throw();
    long Close() throw();
    long Create(void* hKeyParent, const char* lpszKeyName, char* lpszClass = 0, unsigned long dwOptions = 0, unsigned long samDesired = 0x20006, void* lpSecAttr = 0, unsigned long* lpdwDisposition = 0) throw();
    long SetDWORDValue(const char* pszValueName, unsigned long dwValue) throw();
    long SetStringValue(const char* pszValueName, const char* pszValue, unsigned long dwType = 1) throw();
    long SetBinaryValue(const char* pszValueName, const void* pValue, unsigned long nBytes) throw()
    {
        return RegSetValueExA(m_hKey, pszValueName, 0, 3, (const unsigned char*)pValue, nBytes);
    }
    void* GetHKEY() const throw();
};

}

struct GUID
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

// atliface.h
extern "C" const GUID LIBID_ATLLib;
extern "C" const GUID CLSID_Registrar;
extern "C" const GUID IID_IRegistrar;
extern "C" const GUID IID_IAxWinHostWindow;
extern "C" const GUID IID_IAxWinAmbientDispatch;
extern "C" const GUID IID_IInternalConnection;
extern "C" const GUID IID_IDocHostUIHandlerDispatch;
extern "C" const GUID IID_IAxWinHostWindowLic;
extern "C" const GUID IID_IAxWinAmbientDispatchEx;

namespace ATL
{

// statreg.h
class CRegParser
{
public:
    static const char* const szStringVal;
    static const char* const multiszStringVal;
    static const char* const szDwordVal;
    static const char* const szBinaryVal;
    static const char* const szValToken;
    static const char* const szForceRemove;
    static const char* const szNoRemove;
    static const char* const szDelete;
    static const int MAX_VALUE;
    static const int MAX_TYPE;
    static const char* const rgszNeverDelete[12];
    static const int cbNeverDelete;
};

}

// The .rdata in front of these, 0x6FADC4-0x6FAF0B, is atlbase.h's AtlLimits<T>::_Min/_Max for int, unsigned int,
// long, unsigned long, __int64 and unsigned __int64, then atlcomcli.h's CVarTypeInfo<T>::VT and ::pmField for each
// variant type ATL maps (each VARTYPE is stored in a 4-byte slot). They are template statics, so they are defined in the
// data include under their addresses.

struct D2PixelFormat006B1B60Strc
{
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwFourCC;
    unsigned long dwRGBBitCount;
    unsigned long dwRBitMask;
    unsigned long dwGBitMask;
    unsigned long dwBBitMask;
    unsigned long dwRGBAlphaBitMask;
};

extern D2PixelFormat006B1B60Strc gtWantedFormat; // 0x0074C024
extern unsigned int gdwBitMasks[]; // 0x006CE268

#define DD_CHECK(expr,message) { error=(expr); if(error) { D3DCORE_LogDDrawError(message,error); goto Fail; } }

#define D3D_CHECK(expr,message) { error=(expr); if(error) { msg=message; goto D3DFail; } }

struct Draw;

struct Surface;

struct Device;

struct D3D;

struct Gamma;

struct View;

struct D2ComObject006B58A0Strc;

struct SurfaceDesc;

struct Caps;

struct Viewport;

struct Guid;

struct WindowOptions;

struct D2DDSurfaceDesc006B58A0Strc;

struct D2ComObjectVtbl006B58A0Strc;

struct D2ComObjectStrc;

struct D2GuidStrc;

struct D2CriticalSectionStrc;

struct SurfaceDesc { unsigned long size, flags, height, width; long pitch; unsigned long backBuffers; char unk18[80]; unsigned long caps; char unk6C[16]; };

struct Caps { unsigned long flags, flags2, flags3, flags4; };

struct Viewport { unsigned long size, x, y, width, height; float clipX, clipY, clipWidth, clipHeight, minZ, maxZ; };

struct Guid { unsigned long a; unsigned short b,c; unsigned char d[8]; };

struct Gamma
{
    virtual void __stdcall Unused00() = 0;
    virtual void __stdcall Unused04() = 0;
    virtual void __stdcall Unused08() = 0;
    virtual long __stdcall GetGammaRamp(unsigned long nFlags, void* pRamp) = 0;
};

struct Surface
{
    virtual long __stdcall QueryInterface(const Guid* riid, Gamma** ppGamma) = 0;
    virtual void __stdcall Unused04() = 0;
    virtual void __stdcall Unused08() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual void __stdcall Unused18() = 0;
    virtual void __stdcall Unused1C() = 0;
    virtual void __stdcall Unused20() = 0;
    virtual void __stdcall Unused24() = 0;
    virtual void __stdcall Unused28() = 0;
    virtual long __stdcall Flip(Surface* pOverride, unsigned long dwFlags) = 0;
    virtual long __stdcall GetAttachedSurface(Caps* pCaps, Surface** ppSurface) = 0;
};

struct Draw
{
    virtual void __stdcall Unused00() = 0;
    virtual void __stdcall Unused04() = 0;
    virtual void __stdcall Unused08() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual long __stdcall CreateSurface(SurfaceDesc* pDesc, Surface** ppSurface, void* pOuter) = 0;
    virtual void __stdcall Unused1C() = 0;
    virtual void __stdcall Unused20() = 0;
    virtual void __stdcall Unused24() = 0;
    virtual void __stdcall Unused28() = 0;
    virtual void __stdcall Unused2C() = 0;
    virtual void __stdcall Unused30() = 0;
    virtual void __stdcall Unused34() = 0;
    virtual void __stdcall Unused38() = 0;
    virtual void __stdcall Unused3C() = 0;
    virtual void __stdcall Unused40() = 0;
    virtual void __stdcall Unused44() = 0;
    virtual void __stdcall Unused48() = 0;
    virtual void __stdcall Unused4C() = 0;
    virtual long __stdcall SetCooperativeLevel(void* hWnd, unsigned long dwFlags) = 0;
    virtual long __stdcall SetDisplayMode(unsigned long nWidth, unsigned long nHeight, unsigned long nBpp, unsigned long nRefresh, unsigned long dwFlags) = 0;
    virtual void __stdcall Unused58() = 0;
    virtual long __stdcall GetAvailableMemory(Caps* pCaps, unsigned long* pTotal, unsigned long* pFree) = 0;
};

struct View
{
    virtual void __stdcall Unused00() = 0;
    virtual void __stdcall Unused04() = 0;
    virtual void __stdcall Unused08() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual void __stdcall Unused18() = 0;
    virtual void __stdcall Unused1C() = 0;
    virtual void __stdcall Unused20() = 0;
    virtual void __stdcall Unused24() = 0;
    virtual void __stdcall Unused28() = 0;
    virtual void __stdcall Unused2C() = 0;
    virtual void __stdcall Unused30() = 0;
    virtual void __stdcall Unused34() = 0;
    virtual void __stdcall Unused38() = 0;
    virtual void __stdcall Unused3C() = 0;
    virtual void __stdcall Unused40() = 0;
    virtual long __stdcall SetViewport(Viewport* pViewport) = 0;
};

struct D3D
{
    virtual void __stdcall Unused00() = 0;
    virtual void __stdcall Unused04() = 0;
    virtual void __stdcall Unused08() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual long __stdcall CreateViewport(View** ppView, void* pOuter) = 0;
    virtual void __stdcall Unused1C() = 0;
    virtual long __stdcall CreateDevice(const Guid* rclsid, Surface* pSurface, Device** ppDevice, void* pOuter) = 0;
};

struct Device
{
    virtual void __stdcall Unused00() = 0;
    virtual void __stdcall Unused04() = 0;
    virtual void __stdcall Unused08() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual long __stdcall AddViewport(View* pView) = 0;
    virtual void __stdcall Unused18() = 0;
    virtual void __stdcall Unused1C() = 0;
    virtual void __stdcall Unused20() = 0;
    virtual void __stdcall Unused24() = 0;
    virtual void __stdcall Unused28() = 0;
    virtual void __stdcall Unused2C() = 0;
    virtual long __stdcall SetCurrentViewport(View* pView) = 0;
    virtual void __stdcall Unused34() = 0;
    virtual void __stdcall Unused38() = 0;
    virtual void __stdcall Unused3C() = 0;
    virtual void __stdcall Unused40() = 0;
    virtual void __stdcall Unused44() = 0;
    virtual void __stdcall Unused48() = 0;
    virtual void __stdcall Unused4C() = 0;
    virtual void __stdcall Unused50() = 0;
    virtual void __stdcall Unused54() = 0;
    virtual long __stdcall SetRenderState(unsigned long nState, unsigned long nValue) = 0;
    virtual void __stdcall Unused5C() = 0;
    virtual void __stdcall Unused60() = 0;
    virtual void __stdcall Unused64() = 0;
    virtual void __stdcall Unused68() = 0;
    virtual void __stdcall Unused6C() = 0;
    virtual void __stdcall Unused70() = 0;
    virtual void __stdcall Unused74() = 0;
    virtual void __stdcall Unused78() = 0;
    virtual void __stdcall Unused7C() = 0;
    virtual void __stdcall Unused80() = 0;
    virtual void __stdcall Unused84() = 0;
    virtual void __stdcall Unused88() = 0;
    virtual void __stdcall Unused8C() = 0;
    virtual void __stdcall Unused90() = 0;
    virtual void __stdcall Unused94() = 0;
    virtual void __stdcall Unused98() = 0;
    virtual void __stdcall Unused9C() = 0;
    virtual long __stdcall SetTextureStageState(unsigned long nStage, unsigned long nState, unsigned long nValue) = 0;
};

struct WindowOptions { char unk00[16]; int flag; };

extern int gnInitialized; // 0x00970E40

extern int gnState; // 0x00970E44

extern int gnModeFlag; // 0x00970E8C

extern int gnFlags; // 0x0096F3A8



extern unsigned long gnWidth; // 0x007C9138

extern unsigned long gnHeight; // 0x007C913C

extern void* ghWindow; // 0x007C9140

extern int gnWindowed; // 0x007C9144

extern WindowOptions* gpOptions; // 0x007C9148

extern Draw* gpDraw; // 0x00970E60

extern D3D* gpD3D; // 0x00970E64

extern Surface* gpPrimary; // 0x00970E68

extern Surface* gpBack; // 0x00970E6C

extern Gamma* gpGamma; // 0x00970E74

extern Device* gpDevice; // 0x00970E78

extern View* gpView; // 0x00970E7C

extern unsigned char gGammaRamp[]; // 0x0096FCB8

extern const Guid gGammaGuid; // 0x006FF7C8

extern const Guid gDeviceGuid; // 0x006FF518

extern unsigned long gnTextureTotal; // 0x0096F4C4

extern unsigned long gnTextureFree; // 0x0096F4C8

extern unsigned long gnLocalTotal; // 0x0096F4CC

extern unsigned long gnLocalFree; // 0x0096F4D0

extern unsigned long gnAgpTotal; // 0x0096F4D4

extern unsigned long gnAgpFree; // 0x0096F4D8

extern const char gCoopError[]; // 0x006DE0A8

extern const char gDisplayError[]; // 0x006DE090

extern const char gSurfaceError[]; // 0x006FC108

extern const char gAttachedError[]; // 0x006FC0EC

extern const char gGammaInterfaceError[]; // 0x006FC0C4

extern const char gGammaError[]; // 0x006FC0A0

extern const char gDeviceError[]; // 0x006FC080

extern const char gCreateViewError[]; // 0x006FC064

extern const char gAddViewError[]; // 0x006FC040

extern const char gSetViewError[]; // 0x006FC02C

extern const char gCurrentViewError[]; // 0x006FC010

extern const char gTextureError[]; // 0x006FBAD8

extern const char gLocalError[]; // 0x006FBA74

extern const char gAgpError[]; // 0x006FBA1C



extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09

extern "C" void* __cdecl memset(void*,int,unsigned int); // 0x00681EF0

extern "C" __declspec(dllimport) int __stdcall MoveWindow(void*,int,int,int,int,int); // 0x006CC444

void __fastcall D3DCORE_LogDDrawError(const char* szWhere, int hResult); // 0x006B20E0


void __cdecl D3DCORE_ReleaseResources(); // 0x006B3320

void __cdecl D3DCORE_InitBufferPools(); // 0x006B3080


void __cdecl sub_006B8F10_CreateGridVertexBuffer(); // 0x006B8F10


static int D3DCORE_InitFullscreen(void*,int); // 0x006B4FD0

struct D2DDSurfaceDesc006B58A0Strc
{
    unsigned int dwSize;
    unsigned int dwFlags;
    unsigned int dwHeight;
    unsigned int dwWidth;
    unsigned int aUnk0x10[14];
    D2PixelFormat006B1B60Strc tPixelFormat;
    unsigned int dwCaps;
    unsigned int aCaps2[3];
    unsigned int dwTextureStage;
};

struct D2ComObjectVtbl006B58A0Strc
{
    long (__stdcall* QueryInterface)(D2ComObject006B58A0Strc* pThis, const void* pIid, void** ppOut);
    unsigned long (__stdcall* AddRef)(D2ComObject006B58A0Strc* pThis);
    unsigned long (__stdcall* Release)(D2ComObject006B58A0Strc* pThis);
    void* pfn0C;
    void* pfn10;
    void* pfn14;
    long (__stdcall* CreateSurface)(D2ComObject006B58A0Strc* pThis, D2DDSurfaceDesc006B58A0Strc* pDesc, D2ComObject006B58A0Strc** ppSurface, void* pOuter);
};

struct D2ComObject006B58A0Strc
{
    D2ComObjectVtbl006B58A0Strc* lpVtbl;
};

extern D2ComObject006B58A0Strc* gpDirectDraw4; // 0x00970E60

extern const unsigned char gabIidTexture[16]; // 0x006FF478

struct D2ComObjectStrc
{
    void** lpVtbl;
};

typedef int (__stdcall* D2ComQueryInterfaceFn)(D2ComObjectStrc* pThis, const void* pIid, D2ComObjectStrc** ppOut);

typedef unsigned int (__stdcall* D2ComReleaseFn)(D2ComObjectStrc* pThis);

typedef int (__stdcall* D2DDGetDeviceIdentifierFn)(D2ComObjectStrc* pThis, void* pIdentifier, unsigned int dwFlags);

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* pCriticalSection);

extern "C" int __cdecl atexit(void (__cdecl* pfnExit)()); // 0x00683824

int __stdcall sub_006B1350_DirectDrawCreate(D2GuidStrc* pGuid, D2ComObjectStrc** ppDD, void* pUnkOuter); // 0x006B1350

void __cdecl D3DCORE_CloseAtExit(); // 0x006B5990

void __cdecl sub_006B80A0_InitializeDrawingGeometry(); // 0x006B80A0

void __cdecl sub_006B96C0_BuildScaleTable(); // 0x006B96C0

void __cdecl sub_006B97D0_BuildScaleTable(); // 0x006B97D0



extern const D2GuidStrc gtIidDirectDraw4; // 0x006FF8D8

extern const D2GuidStrc gtIidDirect3D3; // 0x006FF558

extern "C" const char gszD3DCoreFile[]; // 0x006FC120

extern int gnD3DArg1_007C9148; // 0x007C9148

extern unsigned int gnDeviceFlags_0096F3A8; // 0x0096F3A8

extern D2GuidStrc gDeviceGuid_0096F3AC; // 0x0096F3AC

extern D2ComObjectStrc* gpDirect3D3; // 0x00970E64

extern D2DDrawSurfaceStrc* gpDevice_00970E68; // 0x00970E68

void __fastcall sub_006BBCE0_Run(int a, int b, int c); // 0x006BBCE0

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);

D2D3DDeviceStrc* gpDevice_00970E78; // 0x00970E78

int __cdecl D3DCORE_Close(); // 0x006B5550

struct D2ComObject006B5550Strc;

struct D2ComObjectVtbl006B5550Strc;

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pCriticalSection);


struct D2ComObjectVtbl006B5550Strc
{
    long (__stdcall* QueryInterface)(D2ComObject006B5550Strc* pThis, const void* riid, void** ppv);
    unsigned long (__stdcall* AddRef)(D2ComObject006B5550Strc* pThis);
    unsigned long (__stdcall* Release)(D2ComObject006B5550Strc* pThis);
};

struct D2ComObject006B5550Strc
{
    D2ComObjectVtbl006B5550Strc* lpVtbl;
};

extern int gbD3DInitialized; // 0x00970E48

extern int gn_007C9140; // 0x007C9140

extern D2ComObject006B5550Strc* gpObject_00970E60; // 0x00970E60



extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);

int __fastcall D3DCORE_CreateSurface(void* window,int mode); // 0x006B55E0

int gnColorCombineMode; // 0x00970E54

int gnFilterMode; // 0x00970E5C

int gnAlphaBlendMode; // 0x00970E58

void __fastcall sub_006B7F70_ClearTarget(int); // 0x006B7F70

void __fastcall sub_006B9710_SetColorComponents(int, int, int); // 0x006B9710

extern D2ComObjectStrc* gpInterface_00970E78; // 0x00970E78

void __cdecl D3DCORE_ReleaseRenderer(); // 0x006B32B0

void __cdecl sub_006B9150_ReleaseResource(); // 0x006B9150


unsigned int gadwColors[256]; // 0x009702C0

unsigned short gawColors16[256]; // 0x0096FA80

extern D2DDSurfaceStrc* gpSurface_00970E6C; // 0x00970E6C

struct D2Device006B2030Strc;

struct D2DeviceVtbl006B2030Strc;

struct D2DeviceVtbl006B2030Strc
{
    void* unk_00[40];
    long (__stdcall* SetTextureStageState)(D2Device006B2030Strc* pDevice, unsigned long nStage, unsigned long nType, unsigned long nValue);
};

struct D2Device006B2030Strc
{
    D2DeviceVtbl006B2030Strc* lpVtbl;
};

extern int gbVideoUp; // 0x00970E40

extern int gnVideoState; // 0x00970E44

extern D2ComObjectStrc* gpPrimarySurface; // 0x00970E68

typedef long (__stdcall* D2DDFlipFn)(D2ComObjectStrc* pThis, D2ComObjectStrc* pTarget, unsigned long dwFlags);

D2PaletteTableStrc gPaletteView; // 0x0096F280

extern D2ComObjectStrc* gpRenderSurface; // 0x00970E6C

extern D2ComObjectStrc* gpInterface; // 0x00970E70

extern D2ComObjectStrc* gpGammaControl; // 0x00970E74

extern D2ComObjectStrc* gpViewport; // 0x00970E7C

extern char gabGammaRamp[1536]; // 0x0096FCB8

typedef long (__stdcall* D2DDSetGammaRampFn)(D2ComObjectStrc* pThis, unsigned long dwFlags, void* pRamp);

extern unsigned int gnCapabilities_0096F3A8;                                                                // 0x0096F3A8





extern int gnGammaScale;                                                                           // 0x0074C020


extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, unsigned int nBytes);

D2ComObject006B5550Strc* gpObject_00970E64; // 0x00970E64

int gbD3DBusy; // 0x00970E50

int gnDeviceTextureFlag; // 0x00970E4C

int gpTileDrawFunctions; // 0x007C914C

int gbD3DInitialized; // 0x00970E48

D2ComObjectStrc* gpDirectDraw4_00970E60; // 0x00970E60

int __cdecl D3DCORE_InitCutsceneMode(); // 0x006B3420

extern unsigned int gnRenderFlags_0096F3A8; // 0x0096F3A8



extern "C" const char gszFailedToLockDest[];                                                       // 0x006FB130

extern "C" const char gszFailedToLockSource[];                                                     // 0x006FB14C

struct D2Object006BB3E0Strc;

struct D2Object006BADC0Strc;

struct D2DDrawDeviceStrc;


struct D2Cache006BA830Strc;

struct D2DDCaps006B3420Strc;

struct D2DDSurfaceDesc006B3420Strc;

struct D2ComObject006B3420Strc;

extern "C" __declspec(dllimport) long __stdcall RegCreateKeyExA(void* hKey, const char* szSubKey, unsigned long nReserved, char* szClass, unsigned long nOptions, unsigned long samDesired, void* pSecurity, void** phkResult, unsigned long* pDisposition); // 0x006CC004

extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey); // 0x006CC030

extern D2DDrawDeviceStrc gaDDrawDevices[]; // 0x0096F4E0


struct D2Cache006BA830Strc
{
    int unk0x00[7];
};




void __fastcall sub_006BA830_FreeCache(D2Cache006BA830Strc* pCache, int bFree); // 0x006BA830

void __fastcall D3DSUBTILECACHE_SubtileCacheDestroy(D2Object006BADC0Strc* pObject, int bFree); // 0x006BADC0

void __fastcall D3DFLOORCACHE_FloorCacheDestroy(D2Object006BB3E0Strc* pObject, int bFree); // 0x006BB3E0


extern D2Object006BADC0Strc gtSubtileCache; // 0x0096FC80

extern D2Object006BB3E0Strc gTextureCache; // 0x0096FC9C

extern D2Cache006BA830Strc gtTextureCache1; // 0x00970EC8

extern D2Cache006BA830Strc gtTextureCache2; // 0x00970EE4

extern D2Cache006BA830Strc gtTextureCache3; // 0x00970F00

extern void* ghDDrawWindow_007C9140; // 0x007C9140

struct D2DDCaps006B3420Strc
{
    unsigned int dwCaps;
    unsigned int dwCaps2;
    unsigned int dwCaps3;
    unsigned int dwCaps4;
};

struct D2DDSurfaceDesc006B3420Strc
{
    unsigned int dwSize;
    unsigned int dwFlags;
    unsigned int aUnk0x08[24];
    D2DDCaps006B3420Strc tCaps;
    unsigned int dwTextureStage;
};

struct D2ComObject006B3420Strc
{
    virtual void __stdcall Unused00() = 0;
    virtual void __stdcall Unused04() = 0;
    virtual void __stdcall Unused08() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual long __stdcall CreateSurface(D2DDSurfaceDesc006B3420Strc* pDesc, D2ComObject006B3420Strc** ppSurface, void* pOuter) = 0;
    virtual void __stdcall Unused1C() = 0;
    virtual void __stdcall Unused20() = 0;
    virtual void __stdcall Unused24() = 0;
    virtual void __stdcall Unused28() = 0;
    virtual void __stdcall Unused2C() = 0;
    virtual void __stdcall Unused30() = 0;
    virtual void __stdcall Unused34() = 0;
    virtual void __stdcall Unused38() = 0;
    virtual void __stdcall Unused3C() = 0;
    virtual void __stdcall Unused40() = 0;
    virtual void __stdcall Unused44() = 0;
    virtual void __stdcall Unused48() = 0;
    virtual void __stdcall Unused4C() = 0;
    virtual void __stdcall Unused50() = 0;
    virtual long __stdcall SetDisplayMode(unsigned int nWidth, unsigned int nHeight, unsigned int nBpp, unsigned int nRefresh, unsigned int dwFlags) = 0;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern D2ComObject006B3420Strc* gpPrimary_00970E68; // 0x00970E68

extern int gnRenderHeight; // 0x007C913C

void __fastcall D3DCORE_SaveVideoConfig(int nRender, int nDevice); // 0x006B2F60

struct D2GammaControlStrc;

struct D2ComObject006B3730Strc;

struct D2Surface006B3570Strc;

struct D2GammaRampStrc;

struct D2GammaControlVTableStrc;

struct D2DDPixelFormat006B3730Strc;

struct D2DDSurfaceDesc006B3730Strc;

struct D2ComObjectVtbl006B3730Strc;

struct D2Surface006B3570VtableStrc;

struct D2VideoKeyStrc;

struct D2GammaControlVTableStrc
{
    void* unk_00[4];
    int (__stdcall *SetGammaRamp)(D2GammaControlStrc*, int, D2GammaRampStrc*);
};

struct D2GammaControlStrc { D2GammaControlVTableStrc* pVTable; };


extern unsigned int gnCapabilities_0096F3A8; // 0x0096F3A8

extern int gnGammaScale; // 0x0074C020

extern D2GammaControlStrc* gpGammaControl_00970E74; // 0x00970E74


void __fastcall D3DCORE_LogDDrawError(const char* szMessage, int nResult); // 0x006B20E0

extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, unsigned int nBytes);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern int gnRenderHeight; // 0x007C913C

extern D2DDSurfaceStrc* gpSurface_00970E6C; // 0x00970E6C

struct D2DDPixelFormat006B3730Strc
{
    unsigned int aData[8];
};

struct D2DDSurfaceDesc006B3730Strc
{
    unsigned int dwSize;
    unsigned int dwFlags;
    unsigned int dwHeight;
    unsigned int dwWidth;
    unsigned int aUnk0x10[14];
    D2DDPixelFormat006B3730Strc tPixelFormat;
    unsigned int dwCaps;
    unsigned int aCaps2[3];
    unsigned int dwTextureStage;
};

struct D2ComObjectVtbl006B3730Strc
{
    long (__stdcall* QueryInterface)(D2ComObject006B3730Strc* pThis, const void* pIid, void** ppOut);
    unsigned long (__stdcall* AddRef)(D2ComObject006B3730Strc* pThis);
    unsigned long (__stdcall* Release)(D2ComObject006B3730Strc* pThis);
    void* pfn0C;
    void* pfn10;
    void* pfn14;
    long (__stdcall* CreateSurface)(D2ComObject006B3730Strc* pThis, D2DDSurfaceDesc006B3730Strc* pDesc, D2ComObject006B3730Strc** ppSurface, void* pOuter);
};

struct D2ComObject006B3730Strc
{
    D2ComObjectVtbl006B3730Strc* lpVtbl;
};

extern D2ComObject006B3730Strc* gpDDraw4_00970E60; // 0x00970E60

extern D2DDPixelFormat006B3730Strc gtWantedDDFormat_0074C024; // 0x0074C024

extern const unsigned char gabIidTexture[16]; // 0x006FF478

struct D2Surface006B3570VtableStrc
{
    void* unk_00[25];
    int (__stdcall* Lock)(D2Surface006B3570Strc*, void*, D2DDSurfaceDesc2Strc*, unsigned int, void*);
    void* unk_68[6];
    int (__stdcall* Unlock)(D2Surface006B3570Strc*, void*);
};

struct D2Surface006B3570Strc
{
    D2Surface006B3570VtableStrc* lpVtbl;
};

extern D2Surface006B3570Strc* gpPrimarySurface_00970E68; // 0x00970E68

extern D2Surface006B3570Strc* gpRenderSurface_00970E6C; // 0x00970E6C



__declspec(noreturn) void __cdecl exit(int); // 0x00681E09



int __stdcall SRegLoadData(const char*,const char*,unsigned int,void*,unsigned int,unsigned int*); // 0x00414DE0

#pragma pack(push, 1)

struct D2VideoKeyStrc { unsigned int words[5]; unsigned short tail; };

#pragma pack(pop)

extern const D2VideoKeyStrc gtVideoKey; // 0x006DD634

typedef void* HINSTANCE;

typedef void* HWND;

typedef void* HMENU;

typedef void* HICON;

typedef void* HCURSOR;

typedef void* HBRUSH;

typedef void* HGDIOBJ;

typedef long LRESULT;

typedef long HRESULT;

typedef unsigned int WPARAM;

typedef long LPARAM;

typedef unsigned short ATOM;

typedef LRESULT (__stdcall* WNDPROC)(HWND, unsigned int, WPARAM, LPARAM);

typedef int (__stdcall* LPDDENUMCALLBACKA)(void* pGuid, char* szDescription, char* szName, void* pContext);

extern "C" __declspec(dllimport) HGDIOBJ __stdcall GetStockObject(int nObject);                             // 0x006CC0E8

extern "C" __declspec(dllimport) void __stdcall SetLastError(unsigned long dwError);                        // 0x006CC2E4

extern "C" __declspec(dllimport) LRESULT __stdcall DefWindowProcA(HWND hWnd, unsigned int nMsg, WPARAM wParam, LPARAM lParam); // 0x006CC488

extern "C" __declspec(dllimport) int __stdcall UnregisterClassA(const char* szClassName, HINSTANCE hInstance); // 0x006CC4C8

extern "C" __declspec(dllimport) ATOM __stdcall RegisterClassA(const WNDCLASSA* pWndClass);                 // 0x006CC4CC

extern "C" __declspec(dllimport) int __stdcall DestroyWindow(HWND hWnd);                                    // 0x006CC4E0

extern "C" __declspec(dllimport) HWND __stdcall CreateWindowExA(unsigned long dwExStyle, const char* szClassName, const char* szWindowName, unsigned long dwStyle, int nX, int nY, int nWidth, int nHeight, HWND hParent, HMENU hMenu, HINSTANCE hInstance, void* pParam); // 0x006CC4F0

extern "C" HRESULT __stdcall DirectDrawEnumerateA(LPDDENUMCALLBACKA pCallback, void* pContext);             // 0x006C9B82

void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...) throw();                                                  // 0x00410610

void __fastcall D3DCORE_LogDDrawError(const char* szMessage, long hResult) throw();                      // 0x006B20E0

void __fastcall D3DCORE_SaveVideoConfig(int nRender, int nDevice);                                     // 0x006B2F60

int __stdcall D3DCORE_EnumerateD3DDevices(void* pGuid, char* szDescription, char* szName, void* pContext); // 0x006B42F0

extern char gszEnumerationClass[];                                                                 // 0x0074C044

extern char gszEnumerationWindow[];                                                                // 0x0074C058

extern HWND ghEnumWindow;                                                                          // 0x00970E84

extern int gnD3DDeviceCount;                                                                       // 0x00970E88

extern int gnDeviceStatus2;                                                                        // 0x0096F83C

extern int gnDeviceStatus3;                                                                        // 0x0096F95C

#pragma pack(push,1)

#pragma pack(pop)

static int __stdcall D3DCORE_DetectDirect3D(HINSTANCE hInstance); // 0x006B4C90

int gbConfigured; // 0x00970EB8

int gbSeen; // 0x00970EBC

char gszDeviceName[264]; // 0x0096F3BC

unsigned long gdwRenderFlags; // 0x0096F3A8

unsigned int gtDeviceGuid[4]; // 0x0096F3AC

int __fastcall D3DCORE_LoadVideoConfiguration(void* window); // 0x006B4E80

typedef unsigned int DWORD;
struct D2DDGuidStrc { DWORD a,b,c,d; };
struct DDCAPS { DWORD size,caps,caps2; DWORD rest0C[12]; DWORD videoTotal,videoFree; DWORD rest44[78]; };
struct DDSCAPS2 { DWORD caps,caps2,caps3,caps4; };
struct DDSURFACEDESC2 { DWORD size,flags,height,width,pitch,backCount,mipCount,alphaDepth,reserved; void* surface; DWORD colorKeys[8]; DWORD pixelFormat[8]; DDSCAPS2 caps; DWORD textureStage; };
struct D3DDEVICEDESC { DWORD size,flags,colorModel,devCaps; DWORD rest10[29]; DWORD textureCaps,textureFilterCaps; DWORD rest8C[28]; };
struct DDDEVICEIDENTIFIER { char driver[512]; char description[512]; unsigned __int64 driverVersion; DWORD vendor,device,subsys,revision; D2DDGuidStrc identifier; };
struct D2DisplayMode006B42F0Strc { int flags,bpp,width,height,refresh; };
struct D2RendererInfoStrc { DWORD flags; D2DDGuidStrc guid; DWORD vendor,device; char description[256]; DWORD videoTotal,videoFree,textureTotal,textureFree,localTotal,localFree,agpTotal,agpFree; D2DisplayMode006B42F0Strc modes[32]; int modeCount; };
struct D2RendererSelectionStrc { DWORD flags; D2DDGuidStrc guid; DWORD vendor,device; char description[256]; int renderer; };
struct IDirectDraw; struct IDirectDraw4; struct IDirectDrawSurface4; struct IDirect3D3; struct IDirect3DDevice3;
struct IUnknownVtbl {
 HRESULT (__stdcall* QueryInterface)(IDirectDraw*,const D2DDGuidStrc*,void**);
 DWORD (__stdcall* AddRef)(IDirectDraw*);
 DWORD (__stdcall* Release)(IDirectDraw*);
};
struct IDirectDraw { IUnknownVtbl* vtbl; };
struct IDirectDraw4Vtbl {
 HRESULT (__stdcall* QueryInterface)(IDirectDraw4*,const D2DDGuidStrc*,void**);
 DWORD (__stdcall* AddRef)(IDirectDraw4*);
 DWORD (__stdcall* Release)(IDirectDraw4*);
 void* methods03[3];
 HRESULT (__stdcall* CreateSurface)(IDirectDraw4*,DDSURFACEDESC2*,IDirectDrawSurface4**,void*);
 void* method07;
 HRESULT (__stdcall* EnumDisplayModes)(IDirectDraw4*,DWORD,DDSURFACEDESC2*,void*,int(__stdcall*)(DDSURFACEDESC2*,void*));
 void* methods09[2];
 HRESULT (__stdcall* GetCaps)(IDirectDraw4*,DDCAPS*,DDCAPS*);
 void* methods12[8];
 HRESULT (__stdcall* SetCooperativeLevel)(IDirectDraw4*,void*,DWORD);
 HRESULT (__stdcall* SetDisplayMode)(IDirectDraw4*,DWORD,DWORD,DWORD,DWORD,DWORD);
 void* method22;
 HRESULT (__stdcall* GetAvailableVidMem)(IDirectDraw4*,DDSCAPS2*,DWORD*,DWORD*);
 void* methods24[3];
 HRESULT (__stdcall* GetDeviceIdentifier)(IDirectDraw4*,DDDEVICEIDENTIFIER*,DWORD);
};
struct IDirectDraw4 { IDirectDraw4Vtbl* vtbl; };
struct IDirectDrawSurface4Vtbl {
 void* methods00[2];
 DWORD (__stdcall* Release)(IDirectDrawSurface4*);
 void* methods03[9];
 HRESULT (__stdcall* GetAttachedSurface)(IDirectDrawSurface4*,DDSCAPS2*,IDirectDrawSurface4**);
};
struct IDirectDrawSurface4 { IDirectDrawSurface4Vtbl* vtbl; };
struct IDirect3D3Vtbl {
 void* methods00[2];
 DWORD (__stdcall* Release)(IDirect3D3*);
 void* methods03[5];
 HRESULT (__stdcall* CreateDevice)(IDirect3D3*,const D2DDGuidStrc*,IDirectDrawSurface4*,IDirect3DDevice3**,void*);
};
struct IDirect3D3 { IDirect3D3Vtbl* vtbl; };
struct IDirect3DDevice3Vtbl {
 void* methods00[2];
 DWORD (__stdcall* Release)(IDirect3DDevice3*);
 HRESULT (__stdcall* GetCaps)(IDirect3DDevice3*,D3DDEVICEDESC*,D3DDEVICEDESC*);
 void* methods04[4];
 HRESULT (__stdcall* EnumTextureFormats)(IDirect3DDevice3*,int(__stdcall*)(void*,void*),void*);
};
struct IDirect3DDevice3 { IDirect3DDevice3Vtbl* vtbl; };
typedef char CheckCapsSize[sizeof(DDCAPS)==0x17c?1:-1];
typedef char CheckDescSize[sizeof(DDSURFACEDESC2)==0x7c?1:-1];
typedef char CheckD3DCapsSize[sizeof(D3DDEVICEDESC)==0xfc?1:-1];
typedef char CheckIdentifierSize[sizeof(DDDEVICEIDENTIFIER)==0x428?1:-1];
typedef char CheckRendererSize[sizeof(D2RendererInfoStrc)==0x3c0?1:-1];
extern "C" char* __cdecl sub_00687330_Strncpy(char*,const char*,unsigned int); // 0x00687330
void __fastcall D3DCORE_LogDDrawError(const char*,HRESULT) throw(); // 0x006B20E0
int __stdcall D3DCORE_EnumerateDisplayMode(DDSURFACEDESC2*,void*); // 0x006B3FD0
int __stdcall D3D_EnumTextureFormatCallback(void*,void*); // 0x006B1B60
extern IDirectDraw4* gpIDirectDraw4_00970E60; // 0x00970E60
extern IDirect3D3* gpIDirect3D3_00970E64; // 0x00970E64
extern void* ghEnumerationWindow; // 0x00970E84
extern int gnDisplayCount; // 0x00970E88
extern D2RendererInfoStrc gaDisplays[2]; // 0x009706C0
extern D2RendererSelectionStrc gPrimarySelection; // 0x0096F720
extern D2RendererSelectionStrc gSecondarySelection; // 0x0096F840
extern int gnPrimaryRenderer; // 0x0096F3A4
extern int gnSecondaryRenderer; // 0x0096F3A0
extern const D2DDGuidStrc gIIDDirectDraw4; // 0x006FF8D8
extern const D2DDGuidStrc gIIDDirect3D3; // 0x006FF558
extern const D2DDGuidStrc gIIDHardwareDevice; // 0x006FF518
extern const DWORD gdwInvBitMasks; // 0x006CE2E8
extern const char gszEnumD3DCleanupFailed[]; // 0x006FB8A4
extern const char gszEnumD3DCaughtFailure[]; // 0x006FB8D4
extern const char gszNoTriangleSupport[]; // 0x006FB908
extern const char gszPassedRequirements[]; // 0x006FB928
extern const char gszNoTextureFormats[]; // 0x006FB950
extern const char gszSupports1555Textures[]; // 0x006FB98C
extern const char gszEnumTextureFormatsFailed[]; // 0x006FB9A8
extern const char gszNoAgpTexturing[]; // 0x006FB9C4
extern const char gszAgpMemoryFormat[]; // 0x006FB9F4
extern const char gszAgpMemoryFailed[]; // 0x006FBA1C
extern const char gszLocalMemoryFormat[]; // 0x006FBA48
extern const char gszLocalMemoryFailed[]; // 0x006FBA74
extern const char gszTextureMemoryFormat[]; // 0x006FBAA4
extern const char gszTextureMemoryFailed[]; // 0x006FBAD8
extern const char gszVideoMemoryFormat[]; // 0x006FBB00
extern const char gszNoMipmapping[]; // 0x006FBB30
extern const char gszRequiresSquareTextures[]; // 0x006FBB50
extern const char gszNoPerspectiveTextures[]; // 0x006FBB6C
extern const char gszSupportsNonPow2Textures[]; // 0x006FBBA0
extern const char gszNoVideoMemoryTextures[]; // 0x006FBBC8
extern const char gszGetD3DDeviceCapsFailed[]; // 0x006FBBF4
extern const char gszNoHardware3D[]; // 0x006FBC14
extern const char gszSupportsGammaCalibration[]; // 0x006FBC44
extern const char gszNoGammaControl[]; // 0x006FBC64
extern const char gszNo3DSupport[]; // 0x006FBC88
extern const char gszGetDD4CapsFailed[]; // 0x006FBCA8
extern const char gszGetBackbufferFailed[]; // 0x006FBCC0
extern const char gszCreatePrimarySurfaceFailed[]; // 0x006FBCE4
extern const char gszSetDisplayModeCall[]; // 0x006FBD08
extern const char gszNoGameDisplayMode[]; // 0x006FBD24
extern const char gszNoUIDisplayMode[]; // 0x006FBD5C
extern const char gszSupports24BitCutscenes[]; // 0x006FBD9C
extern const char gszSupports32BitCutscenes[]; // 0x006FBDBC
extern const char gszNoValidDisplayModes[]; // 0x006FBDDC
extern const char gszEnumDisplayModesCall[]; // 0x006FBE08
extern const char gszSetCooperativeLevelFailed[]; // 0x006FBE28
extern const char gszGetD3DInterfaceFailed[]; // 0x006FBE44
extern const char gszVendorDeviceIdFormat[]; // 0x006FBE60
extern const char gszCheckingCapabilitiesFormat[]; // 0x006FBE88
extern const char gszEnumGetDirectDraw4Failed[]; // 0x006FBEA8
extern const char gszEnumDirectDrawCreateFailed[]; // 0x006FBED8
extern const char gszMaxDisplayCountFormat[]; // 0x006FBEFC

extern "C" char* __cdecl strcpy(char*, const char*);
#pragma intrinsic(strcpy)
extern "C" void* __cdecl memset(void*, int, unsigned int);
#pragma intrinsic(memset)

struct D2FloorCacheStrc;
struct D2SubtileCacheStrc;
struct D2TextureCacheStrc;

void __fastcall D3DFLOORCACHE_FloorCacheDestroy(D2FloorCacheStrc* pCache, int bFree); // 0x006BB3E0
void __fastcall D3DSUBTILECACHE_SubtileCacheDestroy(D2SubtileCacheStrc* pCache, int bFree); // 0x006BADC0
void __fastcall sub_006BA830_FreeTextureCache(D2TextureCacheStrc* pCache, int bFree); // 0x006BA830

extern D2FloorCacheStrc gtFloorCache; // 0x0096FC9C
extern D2SubtileCacheStrc gSubtileCache_0096FC80; // 0x0096FC80
extern D2TextureCacheStrc gTextureCache_00970EC8; // 0x00970EC8
extern D2TextureCacheStrc gTextureCache_00970EE4; // 0x00970EE4
extern D2TextureCacheStrc gTextureCache_00970F00; // 0x00970F00

extern int gbD3DBusy; // 0x00970E50
// 0x006B1A30
void __cdecl ATL::D3DCORE_ThrowAtlException(long error)
{
    throw CAtlException(error);
}

// 0x006B1A50
ATL::CRegKey::CRegKey() throw() : m_hKey(0)
{
}

// 0x006B1A60
void* ATL::CRegKey::GetHKEY() const throw()
{
    return m_hKey;
}

// 0x006B1A70
inline long ATL::CRegKey::Close() throw()
{
    long lRes = 0;
    if (m_hKey != 0)
    {
        lRes = RegCloseKey(m_hKey);
        m_hKey = 0;
    }
    return lRes;
}

// 0x006B2F40
ATL::CRegKey::~CRegKey() throw()
{
    Close();
}

// 0x006B1A90
long ATL::CRegKey::Create(void* hKeyParent, const char* lpszKeyName, char* lpszClass, unsigned long dwOptions, unsigned long samDesired, void* lpSecAttr, unsigned long* lpdwDisposition) throw()
{
    unsigned long dw;
    void* hKey = 0;
    long lRes = RegCreateKeyExA(hKeyParent, lpszKeyName, 0, lpszClass, dwOptions, samDesired, lpSecAttr, &hKey, &dw);
    if (lpdwDisposition != 0)
        *lpdwDisposition = dw;
    if (lRes == 0)
    {
        lRes = Close();
        m_hKey = hKey;
    }
    return lRes;
}

// 0x006B1B00
long ATL::CRegKey::SetDWORDValue(const char* pszValueName, unsigned long dwValue) throw()
{
    return RegSetValueExA(m_hKey, pszValueName, 0, 4, (const unsigned char*)&dwValue, sizeof(unsigned long));
}

// 0x006B1B20
long ATL::CRegKey::SetStringValue(const char* pszValueName, const char* pszValue, unsigned long dwType) throw()
{
    if (!pszValue)
        D3DCORE_ThrowAtlException(0x80004005);
    return RegSetValueExA(m_hKey, pszValueName, 0, dwType, (const unsigned char*)pszValue, (lstrlenA(pszValue) + 1) * sizeof(char));
}

// 0x006B1B60
int __stdcall D3D_EnumTextureFormatCallback(D2PixelFormat006B1B60Strc* pFormat, unsigned long* pFlags)
{
    if (!pFlags)
    {
        return 1;
    }
    if (pFormat->dwFlags != gtWantedFormat.dwFlags)
    {
        return 1;
    }
    if (pFormat->dwRGBBitCount != gtWantedFormat.dwRGBBitCount)
    {
        return 1;
    }
    if (pFormat->dwRBitMask != gtWantedFormat.dwRBitMask)
    {
        return 1;
    }
    if (pFormat->dwGBitMask != gtWantedFormat.dwGBitMask)
    {
        return 1;
    }
    if (pFormat->dwBBitMask != gtWantedFormat.dwBBitMask)
    {
        return 1;
    }
    if (pFormat->dwRGBAlphaBitMask != gtWantedFormat.dwRGBAlphaBitMask)
    {
        return 1;
    }
    *pFlags |= gdwBitMasks[9];
    return 1;
}

// 0x006B1BC0
void __fastcall D3DCORE_ClearCaches()
{
    D3DFLOORCACHE_FloorCacheDestroy(&gtFloorCache, 0);
    D3DSUBTILECACHE_SubtileCacheDestroy(&gSubtileCache_0096FC80, 0);
    sub_006BA830_FreeTextureCache(&gTextureCache_00970EC8, 0);
    sub_006BA830_FreeTextureCache(&gTextureCache_00970EE4, 0);
    sub_006BA830_FreeTextureCache(&gTextureCache_00970F00, 0);
}

// 0x006B1C00
int __cdecl D3DCORE_CheckCutScene()
{
    return gbD3DBusy;
}

// 0x006B1C10
void __fastcall D3DCORE_SetGlobalScale(int nValue)
{
    gnSceneScaleFactor = nValue;
}

// 0x006B1C20
unsigned int __cdecl D3DCORE_GetMaskedFlags()
{
    return gnDeviceFlags_0096F3A8 & gdwBitMasks[4];
}

// 0x006B1C30
int __cdecl D3DCORE_FlipPrimary()
{
    if (gpGfxSettings->bVSync)
        ((D2DDFlipFn)gpPrimarySurface->lpVtbl[11])(gpPrimarySurface, 0, 1);
    else
        ((D2DDFlipFn)gpPrimarySurface->lpVtbl[11])(gpPrimarySurface, 0, 9);
    return 1;
}

// 0x006B1C60
void __fastcall D3DCORE_GetScreenSize(int* pWidth, int* pHeight)
{
    *pWidth = gnRenderWidth;
    *pHeight = gnRenderHeight;
}

// 0x006B1C70
void __fastcall D3DCORE_SetPalette(tagPALETTEENTRY* pPalette)
{
    for (int i = 0; i < 256; ++i)
    {
        gadwColors[i] = 0xFF000000 | (pPalette[i].peRed << 16) | (pPalette[i].peGreen << 8) | pPalette[i].peBlue;

        int nRed = pPalette[i].peRed >> 3;
        int nBlue = pPalette[i].peBlue >> 3;
        int nGreen = pPalette[i].peGreen >> 3;
        if (nRed < 31 && (pPalette[i].peRed & 7) >= 4)
            ++nRed;
        if (nBlue < 31 && (pPalette[i].peBlue & 7) >= 4)
            ++nBlue;
        if (nGreen < 31 && (pPalette[i].peGreen & 7) >= 4)
            ++nGreen;
        gawColors16[i] = (unsigned short)(0x8000 | (nRed << 10) | (nGreen << 5) | nBlue);

        if (!pPalette[i].peRed && !pPalette[i].peGreen && !pPalette[i].peBlue)
        {
            gadwColors[i] = 0;
            gawColors16[i] = 0;
        }
    }
}

// 0x006B1D50
unsigned int __fastcall D3DCORE_GetColor(unsigned int nIndex)
{
    return gadwColors[nIndex];
}

// 0x006B1D60
void __fastcall D3DCORE_SetPaletteView(const D2PaletteTableStrc* pSource)
{
    gPaletteView = *pSource;
    gpGfxPaletteView = &gPaletteView;
}

// 0x006B1D80
void __fastcall D3DCORE_CopyRows(char* pSrc, char* pDst, int nBytes, int nRows, int nDstPitch, int nUnused)
{
    for (int i = 0; i < nRows; ++i)
    {
        memcpy(pDst, pSrc, nBytes);
        pSrc += nBytes;
        pDst += nDstPitch;
    }
}

// 0x006B1DC0
void __fastcall D3DCORE_BlitIndexedToHighColor(const unsigned char* pSrc, unsigned short* pDst, int nWidth, int nHeight, int nDstPitch, int nUnused)
{
    unsigned short* pRowDst = pDst;
    const unsigned char* pRowSrc = pSrc;
    for (int y = 0; y < nHeight; ++y)
    {
        unsigned short* d = pRowDst;
        const unsigned char* s = pRowSrc;
        for (int x = 0; x < nWidth; ++x)
        {
            *d++ = gawColors16[*s++];
        }
        pRowSrc += nWidth;
        pRowDst += nDstPitch;
    }
}

// 0x006B1E30
void __fastcall D3DCORE_Blit8To32(const unsigned char* pSource, unsigned int* pDest, int nWidth, int nHeight, int nPitch, int nUnused)
{
    unsigned int* pDRow = pDest;
    const unsigned char* pRow = pSource;
    if (nHeight > 0)
    {
        nPitch *= 4;
        int y = nHeight;
        do
        {
            unsigned int* pDst = (unsigned int*)pDRow;
            const unsigned char* pSrc = pRow;
            if (nWidth > 0)
            {
                int x = nWidth;
                do
                {
                    *pDst++ = gadwColors[*pSrc++];
                    --x;
                } while (x);
            }
            pRow += nWidth;
            pDRow = (unsigned int*)((char*)pDRow + nPitch);
            --y;
        } while (y);
    }
}

// 0x006B1EA0
void __fastcall D3DCORE_SetColorCombineMode(int nState)
{
    if (gnColorCombineMode && nState == gnColorCombineMode)
        return;
    switch (nState)
    {
    case 1:
        gpDevice->SetTextureStageState(0, 1, 4);
        gpDevice->SetTextureStageState(0, 4, 4);
        gpDevice->SetRenderState(15, 1);
        break;
    case 2:
        gpDevice->SetTextureStageState(0, 1, 3);
        gpDevice->SetTextureStageState(0, 4, 3);
        gpDevice->SetRenderState(15, 0);
        break;
    }
    gnColorCombineMode = nState;
}

// 0x006B1F40
void __fastcall D3DCORE_SetAlphaBlendMode(int nState)
{
    if (gnAlphaBlendMode && nState == gnAlphaBlendMode)
        return;
    switch (nState)
    {
    case 1:
        gpDevice->SetRenderState(27, 0);
        gpDevice->SetRenderState(19, 2);
        gpDevice->SetRenderState(20, 1);
        break;
    case 2:
        gpDevice->SetRenderState(27, 1);
        gpDevice->SetRenderState(19, 2);
        gpDevice->SetRenderState(20, 2);
        break;
    case 3:
        gpDevice->SetRenderState(27, 1);
        gpDevice->SetRenderState(19, 1);
        gpDevice->SetRenderState(20, 3);
        break;
    case 4:
        gpDevice->SetRenderState(27, 1);
        gpDevice->SetRenderState(19, 5);
        gpDevice->SetRenderState(20, 6);
        break;
    }
    gnAlphaBlendMode = nState;
}

// 0x006B2030
void __fastcall D3DCORE_SetTextureFilterMode(int nMode)
{
    if (gnFilterMode && nMode == gnFilterMode)
    {
        return;
    }
    switch (nMode)
    {
    case 1:
        gpDevice->SetTextureStageState(0, 16, 1);
        gpDevice->SetTextureStageState(0, 17, 1);
        break;
    case 2:
        gpDevice->SetTextureStageState(0, 16, 2);
        gpDevice->SetTextureStageState(0, 17, 2);
        break;
    }
    gnFilterMode = nMode;
}

// 0x006B20A0
void* __cdecl QSERVER_GetFloorCacheSize()
{
    return gnFloorCacheSize;
}

// 0x006B20B0
int __cdecl D3DCORE_ActivateWindow()
{
    return 0;
}

// 0x006B3320
void __cdecl D3DCORE_ReleaseResources()
{
    if (!gbVideoUp)
    {
        return;
    }

    sub_006B9150_ReleaseResource();
    D3DFLOORCACHE_ReleaseTileSurfaces();
    D3DCORE_ReleaseRenderer();

    if (gpViewport)
    {
        ((D2ComReleaseFn)gpViewport->lpVtbl[2])(gpViewport);
        gpViewport = 0;
    }

    if (gpInterface_00970E78)
    {
        ((D2ComReleaseFn)gpInterface_00970E78->lpVtbl[2])(gpInterface_00970E78);
        gpInterface_00970E78 = 0;
    }

    if (gpGammaControl)
    {
        const long hResult = ((D2DDSetGammaRampFn)gpGammaControl->lpVtbl[4])(gpGammaControl, 0, gabGammaRamp);
        if (hResult && hResult != (long)0x887601C2)
        {
            D3DCORE_LogDDrawError("Failed to restore original gamma ramp", hResult);
        }
        ((D2ComReleaseFn)gpGammaControl->lpVtbl[2])(gpGammaControl);
        gpGammaControl = 0;
    }

    if (gpInterface)
    {
        ((D2ComReleaseFn)gpInterface->lpVtbl[2])(gpInterface);
        gpInterface = 0;
    }

    if (gpRenderSurface)
    {
        ((D2ComReleaseFn)gpRenderSurface->lpVtbl[2])(gpRenderSurface);
        gpRenderSurface = 0;
    }

    if (gpPrimarySurface)
    {
        ((D2ComReleaseFn)gpPrimarySurface->lpVtbl[2])(gpPrimarySurface);
        gpPrimarySurface = 0;
    }

    gbVideoUp = 0;
    gnVideoState = 0;
}

// 0x006B3400
int __cdecl D3DCORE_ReleaseWindow()
{
    D3DCORE_ReleaseResources();
    ghDDrawWindow_007C9140 = 0;
    return 1;
}

// 0x006B3420
int __cdecl D3DCORE_InitCutsceneMode()
{
    D2_ASSERT(!gbVideoUp, 0x7CB);

    gnRenderWidth = 640;
    gnRenderHeight = 480;

    unsigned int nBpp = 16;
    if (gdwBitMasks[7] & gnCapabilities_0096F3A8)
    {
        nBpp = 32;
    }
    else if (gdwBitMasks[8] & gnCapabilities_0096F3A8)
    {
        nBpp = 24;
    }

    const char* szError;
    long hResult = gpDraw->SetDisplayMode(640, 480, nBpp, 0, 0);
    if (hResult)
    {
        szError = "SetDisplayMode failed!";
        goto fail;
    }

    {
        SurfaceDesc tDesc = { sizeof(tDesc) };
        tDesc.flags = 1;
        tDesc.caps = 0x4200;
        hResult = gpDraw->CreateSurface(&tDesc, &gpPrimary, 0);
    }
    if (hResult)
    {
        szError = "Failed to create primary surface for cutscenes";
fail:
        D3DCORE_LogDDrawError(szError, hResult);
        LOGMANAGER_WriteLogLine("Opening Direct3D window for cutscenes failed!");
        return 0;
    }

    gbVideoUp = 1;
    gnVideoState = 1;
    return 1;
}

// 0x006B3530
int __cdecl D3DCORE_BeginCutScene()
{
    if (gbRenderPaused)
    {
        return 0;
    }

    if (!(gnRenderFlags_0096F3A8 & gdwBitMasks[7]) && !(gnRenderFlags_0096F3A8 & gdwBitMasks[8]))
    {
        return 1;
    }

    D3DCORE_ReleaseResources();
    return D3DCORE_InitCutsceneMode();
}

struct D2GammaRampStrc
{
    int red[128];
    int green[128];
    int blue[128];
};

// 0x006B3570
void __fastcall D3DCORE_SetGamma(int nGamma)
{
    D2GammaRampStrc ramp;
    if (gnCapabilities_0096F3A8 & gdwBitMasks[4])
    {
        EXCEL_BuildGammaTable(nGamma, (unsigned short*)ramp.red, gnGammaScale, 2, 256, 65535);
        memcpy(ramp.green, ramp.red, sizeof(ramp.red));
        memcpy(ramp.blue, ramp.red, sizeof(ramp.red));
        if (gpGammaControl)
        {
            int nResult = ((D2DDSetGammaRampFn)gpGammaControl->lpVtbl[4])(gpGammaControl, 0, &ramp);
            if (nResult)
                D3DCORE_LogDDrawError("Failed to set gamma ramp", nResult);
        }
    }
}

// 0x006B3610
int __fastcall D3DCORE_GetBackBuffer(unsigned char* pDst)
{
    D2DDSurfaceDesc2Strc tDesc = { sizeof(D2DDSurfaceDesc2Strc) };
    if (!gpSurface_00970E6C)
    {
        return 0;
    }

    long hResult = gpSurface_00970E6C->lpVtbl->Lock(gpSurface_00970E6C, 0, &tDesc, 0x11, 0);
    if (hResult)
    {
        D3DCORE_LogDDrawError("Lock failed!", hResult);
        return 0;
    }

    int nPitch = tDesc.lPitch / 4;
    unsigned char* pOutRow = pDst;
    unsigned int* pSrcRow = (unsigned int*)tDesc.lpSurface;
    for (int y = 0; y < gnRenderHeight; ++y)
    {
        unsigned char* pOut = pOutRow;
        unsigned int* pSrc = pSrcRow;
        for (int x = 0; x < gnRenderWidth; ++x)
        {
            unsigned int dwPixel = *pSrc++;
            *pOut++ = (unsigned char)(dwPixel >> 16);
            *pOut++ = (unsigned char)(dwPixel >> 8);
            *pOut++ = (unsigned char)dwPixel;
        }
        pOutRow += gnRenderWidth * 3;
        pSrcRow += nPitch;
    }

    hResult = gpSurface_00970E6C->lpVtbl->Unlock(gpSurface_00970E6C, 0);
    if (hResult)
    {
        D3DCORE_LogDDrawError("Unlock failed!", hResult);
        return 0;
    }
    return 1;
}

// 0x006B3730
int __fastcall D3DCORE_CreateMemoryTexture(D2ComObject006B58A0Strc** ppSurface, D2ComObject006B58A0Strc** ppTexture, unsigned int nWidth, unsigned int nHeight)
{
    D2DDSurfaceDesc006B58A0Strc tDesc = { sizeof(tDesc) };
    tDesc.dwFlags = 0x1007;
    tDesc.dwCaps = 0x840;
    tDesc.tPixelFormat = gtWantedFormat;
    tDesc.dwWidth = nWidth;
    tDesc.dwHeight = nHeight;
    long hResult = gpDirectDraw4->lpVtbl->CreateSurface(gpDirectDraw4, &tDesc, ppSurface, 0);
    if (hResult)
    {
        D3DCORE_LogDDrawError("CreateSurface (memory surface)", hResult);
        return 0;
    }
    hResult = (*ppSurface)->lpVtbl->QueryInterface(*ppSurface, gabIidTexture, (void**)ppTexture);
    if (hResult)
    {
        D3DCORE_LogDDrawError("Failed to get texture interface for memory surface", hResult);
        (*ppSurface)->lpVtbl->Release(*ppSurface);
        return 0;
    }
    return 1;
}

// 0x006B3800
void __cdecl D3DCORE_Flush()
{
    D2Surface006B3570Strc* pSurface = gpRenderSurface_00970E6C ? gpRenderSurface_00970E6C : gpPrimarySurface_00970E68;
    D2DDSurfaceDesc2Strc desc;
    desc.dwSize = sizeof(desc);
    memset((char*)&desc + sizeof(desc.dwSize), 0, sizeof(desc) - sizeof(desc.dwSize));
    int nResult = pSurface->lpVtbl->Lock(pSurface, 0, &desc, 0x21, 0);
    if (nResult)
    {
        D3DCORE_LogDDrawError("Failed to lock render surface for clear", nResult);
        return;
    }
    int nHeight = gnRenderHeight;
    int nPitch = desc.lPitch;
    char* pPixels = (char*)desc.lpSurface;
    while (nHeight)
    {
        --nHeight;
        memset(pPixels, 0, nPitch);
        pPixels += nPitch;
    }
    pSurface->lpVtbl->Unlock(pSurface, 0);
}

// 0x006B38A0
void __fastcall D3DCORE_CopySurface(D2DDSurfaceStrc* pDst, D2DDSurfaceStrc* pSrc, unsigned int nRows)
{
    unsigned char* pSrcBits;
    unsigned char* pDstBits;
    unsigned int nDstPitch;
    unsigned int nWidth;
    D2DDSurfaceDesc2Strc tSrcDesc = { sizeof(D2DDSurfaceDesc2Strc) };
    long hResult = pSrc->lpVtbl->Lock(pSrc, 0, &tSrcDesc, 0x21, 0);
    if (hResult)
    {
        D3DCORE_LogDDrawError(gszFailedToLockSource, hResult);
    }
    else
    {
        pSrcBits = (unsigned char*)tSrcDesc.lpSurface;
        D2DDSurfaceDesc2Strc tDstDesc = { sizeof(D2DDSurfaceDesc2Strc) };
        hResult = pDst->lpVtbl->Lock(pDst, 0, &tDstDesc, 0x21, 0);
        if (hResult)
        {
            D3DCORE_LogDDrawError(gszFailedToLockDest, hResult);
        }
        else
        {
            nDstPitch = tDstDesc.lPitch;
            nWidth = tSrcDesc.lPitch;
            pDstBits = (unsigned char*)tDstDesc.lpSurface;
            nWidth = nWidth < nDstPitch ? nWidth : nDstPitch;
            unsigned int nLeft = nRows;
            while (nLeft--)
            {
                memcpy(pDstBits, pSrcBits, nWidth);

                if (nLeft && (int)pDst < 0 && (int)pSrc < 0 && nWidth) pDstBits += nDstPitch; else pDstBits += nDstPitch;
                pSrcBits += tSrcDesc.lPitch;
            }
        }
    }
    pSrc->lpVtbl->Unlock(pSrc, 0);
    pDst->lpVtbl->Unlock(pDst, 0);
}

struct D2SurfaceDescStrc { unsigned int size, flags, height, width, pitch, backBuffers, refresh; unsigned int reserved1[14]; unsigned int bits; unsigned int reserved2[4]; unsigned int caps; unsigned int reserved3[4]; };
struct D2CapsStrc { unsigned int caps, caps2, caps3, caps4; };
struct D2DeviceStrc;
struct D2SurfaceStrc;
struct D2DeviceStrc
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
struct D2SurfaceStrc
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual void __stdcall Unused18() = 0;
    virtual void __stdcall Unused1C() = 0;
    virtual void __stdcall Unused20() = 0;
    virtual void __stdcall Unused24() = 0;
    virtual void __stdcall Unused28() = 0;
    virtual void __stdcall Unused2C() = 0;
    virtual long __stdcall GetAttachedSurface(D2CapsStrc* pCaps, D2SurfaceStrc** ppSurface) = 0;
};
struct D2DrawStrc
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual long __stdcall CreateSurface(D2SurfaceDescStrc* pDesc, D2SurfaceStrc** ppSurface, void* pOuter) = 0;
    virtual void __stdcall Unused1C() = 0;
    virtual void __stdcall Unused20() = 0;
    virtual void __stdcall Unused24() = 0;
    virtual void __stdcall Unused28() = 0;
    virtual void __stdcall Unused2C() = 0;
    virtual void __stdcall Unused30() = 0;
    virtual void __stdcall Unused34() = 0;
    virtual void __stdcall Unused38() = 0;
    virtual void __stdcall Unused3C() = 0;
    virtual void __stdcall Unused40() = 0;
    virtual void __stdcall Unused44() = 0;
    virtual void __stdcall Unused48() = 0;
    virtual void __stdcall Unused4C() = 0;
    virtual long __stdcall SetCooperativeLevel(void* hWnd, unsigned int dwFlags) = 0;
    virtual long __stdcall SetDisplayMode(unsigned int nWidth, unsigned int nHeight, unsigned int nBpp, unsigned int nRefresh, unsigned int dwFlags) = 0;
};
struct D2D3DStrc
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual void __stdcall Unused18() = 0;
    virtual void __stdcall Unused1C() = 0;
    virtual long __stdcall CreateDevice(const void* rclsid, D2SurfaceStrc* pSurface, D2DeviceStrc** ppDevice, void* pOuter) = 0;
};
struct D2DisplayModeStrc { unsigned int flags,bits,width,height,refresh; };
struct D2DisplayContextStrc { unsigned int reserved[0x13c/4]; D2DisplayModeStrc modes[32]; int count; };
extern D2DrawStrc* gpDraw_00970E60; // 0x00970E60
extern D2D3DStrc* gpD3D_00970E64; // 0x00970E64
extern void* ghEnumWindow; // 0x00970E84
extern unsigned int ganWidths[2]; // 0x0074C000
extern unsigned int ganHeights[2]; // 0x0074C010
extern const unsigned int gadwHalGuid[4]; // 0x006FF518
extern const char gszTooMany[]; // 0x006FB86C
extern const char gszCoop[]; // 0x006FB83C
extern const char gszSetDisplayModeFailed[]; // 0x006FB810
extern const char gszPrimary[]; // 0x006FB7DC
extern const char gszAttached[]; // 0x006FB7AC
extern const char gszCreateHalDeviceFailed[]; // 0x006FB77C
extern const char gszCutscene[]; // 0x006DE0F4

// 0x006B39B0
void __fastcall D3DCORE_ShowD3DError(const char* text,long result)
{
    const char* name;
    switch(result) {
    case (long)0x887602BC: name="D3DERR_BADMAJORVERSION"; break;
    case (long)0x887602BD: name="D3DERR_BADMINORVERSION"; break;
    case (long)0x887602C1: name="D3DERR_INVALID_DEVICE"; break;
    case (long)0x887602C2: name="D3DERR_INITFAILED"; break;
    case (long)0x887602C3: name="D3DERR_DEVICEAGGREGATED"; break;
    case (long)0x887602C6: name="D3DERR_EXECUTE_CREATE_FAILED"; break;
    case (long)0x887602C7: name="D3DERR_EXECUTE_DESTROY_FAILED"; break;
    case (long)0x887602C8: name="D3DERR_EXECUTE_LOCK_FAILED"; break;
    case (long)0x887602C9: name="D3DERR_EXECUTE_UNLOCK_FAILED"; break;
    case (long)0x887602CA: name="D3DERR_EXECUTE_LOCKED"; break;
    case (long)0x887602CB: name="D3DERR_EXECUTE_NOT_LOCKED"; break;
    case (long)0x887602CC: name="D3DERR_EXECUTE_FAILED"; break;
    case (long)0x887602CD: name="D3DERR_EXECUTE_CLIPPED_FAILED"; break;
    case (long)0x887602D0: name="D3DERR_TEXTURE_NO_SUPPORT"; break;
    case (long)0x887602D1: name="D3DERR_TEXTURE_CREATE_FAILED"; break;
    case (long)0x887602D2: name="D3DERR_TEXTURE_DESTROY_FAILED"; break;
    case (long)0x887602D3: name="D3DERR_TEXTURE_LOCK_FAILED"; break;
    case (long)0x887602D4: name="D3DERR_TEXTURE_UNLOCK_FAILED"; break;
    case (long)0x887602D5: name="D3DERR_TEXTURE_LOAD_FAILED"; break;
    case (long)0x887602D6: name="D3DERR_TEXTURE_SWAP_FAILED"; break;
    case (long)0x887602D7: name="D3DERR_TEXTURE_LOCKED"; break;
    case (long)0x887602D8: name="D3DERR_TEXTURE_NOT_LOCKED"; break;
    case (long)0x887602D9: name="D3DERR_TEXTURE_GETSURF_FAILED"; break;
    case (long)0x887602DA: name="D3DERR_MATRIX_CREATE_FAILED"; break;
    case (long)0x887602DB: name="D3DERR_MATRIX_DESTROY_FAILED"; break;
    case (long)0x887602DC: name="D3DERR_MATRIX_SETDATA_FAILED"; break;
    case (long)0x887602DD: name="D3DERR_MATRIX_GETDATA_FAILED"; break;
    case (long)0x887602DE: name="D3DERR_SETVIEWPORTDATA_FAILED"; break;
    case (long)0x887602DF: name="D3DERR_INVALIDCURRENTVIEWPORT"; break;
    case (long)0x887602E0: name="D3DERR_INVALIDPRIMITIVETYPE"; break;
    case (long)0x887602E1: name="D3DERR_INVALIDVERTEXTYPE"; break;
    case (long)0x887602E2: name="D3DERR_TEXTURE_BADSIZE"; break;
    case (long)0x887602E3: name="D3DERR_INVALIDRAMPTEXTURE"; break;
    case (long)0x887602E4: name="D3DERR_MATERIAL_CREATE_FAILED"; break;
    case (long)0x887602E5: name="D3DERR_MATERIAL_DESTROY_FAILED"; break;
    case (long)0x887602E6: name="D3DERR_MATERIAL_SETDATA_FAILED"; break;
    case (long)0x887602E7: name="D3DERR_MATERIAL_GETDATA_FAILED"; break;
    case (long)0x887602E8: name="D3DERR_INVALIDPALETTE"; break;
    case (long)0x887602E9: name="D3DERR_ZBUFF_NEEDS_SYSTEMMEMORY"; break;
    case (long)0x887602EA: name="D3DERR_ZBUFF_NEEDS_VIDEOMEMORY"; break;
    case (long)0x887602EB: name="D3DERR_SURFACENOTINVIDMEM"; break;
    case (long)0x887602EE: name="D3DERR_LIGHT_SET_FAILED"; break;
    case (long)0x887602EF: name="D3DERR_LIGHTHASVIEWPORT"; break;
    case (long)0x887602F0: name="D3DERR_LIGHTNOTINTHISVIEWPORT"; break;
    case (long)0x887602F8: name="D3DERR_SCENE_IN_SCENE"; break;
    case (long)0x887602F9: name="D3DERR_SCENE_NOT_IN_SCENE"; break;
    case (long)0x887602FA: name="D3DERR_SCENE_BEGIN_FAILED"; break;
    case (long)0x887602FB: name="D3DERR_SCENE_END_FAILED"; break;
    case (long)0x88760302: name="D3DERR_INBEGIN"; break;
    case (long)0x88760303: name="D3DERR_NOTINBEGIN"; break;
    case (long)0x88760304: name="D3DERR_NOVIEWPORTS"; break;
    case (long)0x88760305: name="D3DERR_VIEWPORTDATANOTSET"; break;
    case (long)0x88760306: name="D3DERR_VIEWPORTHASNODEVICE"; break;
    case (long)0x88760307: name="D3DERR_NOCURRENTVIEWPORT"; break;
    case 0: name="D3D_OK"; break;
    default: D3DCORE_LogDDrawError(text,result); return; // 0x006B20E0
    }
    LOGMANAGER_WriteLogLine("***** Direct3D error: %s - %s (0x%x)",text,name,result);
}

// 0x006B3FD0
int __stdcall D3DCORE_EnumerateDisplayMode(D2SurfaceDescStrc* mode,D2DisplayContextStrc* context)
{
    D2SurfaceStrc* primary=0;
    D2SurfaceStrc* attached=0;
    D2DeviceStrc* device=0;
    D2CapsStrc caps;
    D2SurfaceDescStrc desc;
    unsigned int flags=0;
    long result;
    if(!context) goto done;
    if(!mode || mode->size!=0x7c) return 0;
    if(context->count>=32) {
        LOGMANAGER_WriteLogLine(gszTooMany,context->count,32);
        if(device) { device->Release(); device=0; }
        if(attached) attached=0;
        if(primary) primary->Release();
        return 0;
    }
    if(mode->bits==32 && mode->width==640 && mode->height==480) flags=gdwBitMasks_006CE268[2];
    else if(mode->bits==24 && mode->width==640 && mode->height==480) flags=gdwBitMasks_006CE268[3];
    if(mode->bits==32 && mode->width==ganWidths[0] && mode->height==ganHeights[0]) flags|=gdwBitMasks_006CE268[1];
    if(mode->bits==32 && mode->width==ganWidths[1] && mode->height==ganHeights[1]) flags|=gdwBitMasks_006CE268[0];
    if(!flags) goto done;
    result=gpDraw_00970E60->SetCooperativeLevel(ghEnumWindow,0x11);
    if(result && result!=(long)0x88760245) { D3DCORE_LogDDrawError(gszCoop,result); goto cleanup; }
    result=gpDraw_00970E60->SetDisplayMode(mode->width,mode->height,mode->bits,mode->refresh,0);
    if(result) { D3DCORE_LogDDrawError(gszSetDisplayModeFailed,result); goto cleanup; }
    if(!(flags&gdwBitMasks_006CE268[0]) && !(flags&gdwBitMasks_006CE268[1])) {
        desc.size=sizeof(desc); memset(&desc.flags,0,sizeof(desc)-4); desc.flags=1; desc.caps=0x4200;
        result=gpDraw_00970E60->CreateSurface(&desc,&primary,0);
        if(result) { D3DCORE_LogDDrawError(gszCutscene,result); goto cleanup; }
    }
    else {
        desc.size=sizeof(desc); memset(&desc.flags,0,sizeof(desc)-4); desc.flags=0x21; desc.caps=0x6218; desc.backBuffers=1;
        result=gpDraw_00970E60->CreateSurface(&desc,&primary,0);
        if(result) { D3DCORE_LogDDrawError(gszPrimary,result); goto cleanup; }
        memset(&caps,0,sizeof(caps)); caps.caps=4;
        result=primary->GetAttachedSurface(&caps,&attached);
        if(result) { D3DCORE_LogDDrawError(gszAttached,result); goto cleanup; }
        gpD3D_00970E64->CreateDevice(gadwHalGuid,attached,&device,0);
        if(!device) { D3DCORE_ShowD3DError(gszCreateHalDeviceFailed,0); goto cleanup; }
    }
    {
        D2DisplayModeStrc* out=&context->modes[context->count];
        out->flags=flags; out->width=mode->width; out->height=mode->height; out->bits=mode->bits; out->refresh=mode->refresh;
        ++context->count;
    }
cleanup:
    if(device) { device->Release(); device=0; }
    if(attached) attached=0;
    if(primary) primary->Release();
done:

    return 1;
}

// 0x006B42F0
int __stdcall D3DCORE_EnumerateD3DDevices(D2DDGuidStrc* guid,char* description,char* name,void* context)
{
 IDirectDraw* dd=0;
 DDCAPS caps={sizeof(caps)};
 IDirectDrawSurface4* primary=0;
 IDirectDrawSurface4* back=0;
 IDirect3DDevice3* device=0;
 gpIDirectDraw4_00970E60=0;
 gpIDirect3D3_00970E64=0;
 try {
  FOG_GetSystemInfo();
  int index=gnDisplayCount;
  if(index>=2) { LOGMANAGER_WriteLogLine(gszMaxDisplayCountFormat,index,2); return 0; }
  D2RendererInfoStrc* display=&gaDisplays[index];
  memset(display,0,0x134);
  if(!guid) display->flags|=gdwBitMasks[0];
  else { display->flags&=gdwInvBitMasks; display->guid=*guid; }
  HRESULT hr=sub_006B1350_DirectDrawCreate((D2GuidStrc*)guid,(D2ComObjectStrc**)&dd,0);
  if(hr) { D3DCORE_LogDDrawError(gszEnumDirectDrawCreateFailed,hr); goto Cleanup; }
  hr=dd->vtbl->QueryInterface(dd,&gIIDDirectDraw4,(void**)&gpIDirectDraw4_00970E60);
  if(hr) { D3DCORE_LogDDrawError(gszEnumGetDirectDraw4Failed,hr); goto Cleanup; }
  dd->vtbl->Release(dd); dd=0;

  DDDEVICEIDENTIFIER aIdentifier[2];
  DDDEVICEIDENTIFIER& identifier=aIdentifier[0];
  hr=gpIDirectDraw4_00970E60->vtbl->GetDeviceIdentifier(gpIDirectDraw4_00970E60,&identifier,0);
  if(!hr) sub_00687330_Strncpy(display->description,identifier.description,256); else sub_00687330_Strncpy(display->description,name,256);
  LOGMANAGER_WriteLogLine(gszCheckingCapabilitiesFormat,display->description);
  if(!hr) {
   display->vendor=identifier.vendor; display->device=identifier.device;
   LOGMANAGER_WriteLogLine(gszVendorDeviceIdFormat,display->vendor,display->device);
  }
  hr=gpIDirectDraw4_00970E60->vtbl->QueryInterface(gpIDirectDraw4_00970E60,&gIIDDirect3D3,(void**)&gpIDirect3D3_00970E64);
  if(hr) { D3DCORE_LogDDrawError(gszGetD3DInterfaceFailed,hr); goto Cleanup; }
  hr=gpIDirectDraw4_00970E60->vtbl->SetCooperativeLevel(gpIDirectDraw4_00970E60,ghEnumerationWindow,0x11);
  if(hr) { D3DCORE_LogDDrawError(gszSetCooperativeLevelFailed,hr); goto Cleanup; }
  hr=gpIDirectDraw4_00970E60->vtbl->EnumDisplayModes(gpIDirectDraw4_00970E60,0,0,display,D3DCORE_EnumerateDisplayMode);
  if(hr) { D3DCORE_LogDDrawError(gszEnumDisplayModesCall,hr); goto Cleanup; }
  if(!display->modeCount) { LOGMANAGER_WriteLogLine(gszNoValidDisplayModes); goto Cleanup; }
  int hasUI=0,hasGame=0,has32=0,has24=0;
  int invalid=0;
  for(int i=0;i<display->modeCount;++i) {
   if(display->modes[i].flags&gdwBitMasks[2]) has32=1;
   if(display->modes[i].flags&gdwBitMasks[3]) has24=1;
   if(display->modes[i].flags&gdwBitMasks[0]) hasUI=1;
   if(display->modes[i].flags&gdwBitMasks[1]) hasGame=1;
  }
  if(has32) { LOGMANAGER_WriteLogLine(gszSupports32BitCutscenes); display->flags|=gdwBitMasks[7]; }
  if(has24) { LOGMANAGER_WriteLogLine(gszSupports24BitCutscenes); display->flags|=gdwBitMasks[8]; }
  if(!hasUI) { LOGMANAGER_WriteLogLine(gszNoUIDisplayMode); invalid=1; }
  if(!hasGame) { LOGMANAGER_WriteLogLine(gszNoGameDisplayMode); goto Cleanup; }
  if(invalid) goto Cleanup;
  D2DisplayMode006B42F0Strc* mode=&display->modes[display->modeCount-1];
  hr=gpIDirectDraw4_00970E60->vtbl->SetDisplayMode(gpIDirectDraw4_00970E60,mode->width,mode->height,mode->bpp,mode->refresh,0);
  if(hr) { D3DCORE_LogDDrawError(gszSetDisplayModeCall,hr); goto Cleanup; }
  DDSURFACEDESC2 surface={sizeof(surface)};
  surface.flags=0x21;surface.caps.caps=0x6218;surface.backCount=1;
  hr=gpIDirectDraw4_00970E60->vtbl->CreateSurface(gpIDirectDraw4_00970E60,&surface,&primary,0);
  if(hr) { D3DCORE_LogDDrawError(gszCreatePrimarySurfaceFailed,hr); goto Cleanup; }
  DDSCAPS2 attachCaps;memset(&attachCaps,0,sizeof(attachCaps));attachCaps.caps=4;
  hr=primary->vtbl->GetAttachedSurface(primary,&attachCaps,&back);
  if(hr) { D3DCORE_LogDDrawError(gszGetBackbufferFailed,hr); goto Cleanup; }
  hr=gpIDirectDraw4_00970E60->vtbl->GetCaps(gpIDirectDraw4_00970E60,&caps,0);
  if(hr) { D3DCORE_LogDDrawError(gszGetDD4CapsFailed,hr); goto Cleanup; }
  if(!(caps.caps&1)) { LOGMANAGER_WriteLogLine(gszNo3DSupport); goto Cleanup; }
  if(caps.caps2&0x20000) display->flags|=gdwBitMasks[4];
  else LOGMANAGER_WriteLogLine(gszNoGammaControl);
  if(caps.caps2&0x100000) { display->flags|=gdwBitMasks[5]; LOGMANAGER_WriteLogLine(gszSupportsGammaCalibration); }
  gpIDirect3D3_00970E64->vtbl->CreateDevice(gpIDirect3D3_00970E64,&gIIDHardwareDevice,back,&device,0);
  if(!device) { LOGMANAGER_WriteLogLine(gszNoHardware3D); goto Cleanup; }
  D3DDEVICEDESC hardware,software;
  hardware.size=sizeof(hardware);software.size=sizeof(software);
  hr=device->vtbl->GetCaps(device,&hardware,&software);
  if(hr) { D3DCORE_ShowD3DError(gszGetD3DDeviceCapsFailed,hr); goto Cleanup; }
  if(!(hardware.devCaps&0x200)) { LOGMANAGER_WriteLogLine(gszNoVideoMemoryTextures); goto Cleanup; }
  if(hardware.textureCaps&0x100) LOGMANAGER_WriteLogLine(gszSupportsNonPow2Textures);
  if(hardware.flags&0x40) {
  if(!(hardware.textureCaps&1)) LOGMANAGER_WriteLogLine(gszNoPerspectiveTextures);
  if(hardware.textureCaps&0x20) { LOGMANAGER_WriteLogLine(gszRequiresSquareTextures); display->flags|=gdwBitMasks[2]; goto Cleanup; }
  if(hardware.textureFilterCaps&0x20) display->flags|=gdwBitMasks[3];
  else LOGMANAGER_WriteLogLine(gszNoMipmapping);
  display->videoTotal=caps.videoTotal;display->videoFree=caps.videoFree;
  LOGMANAGER_WriteLogLine(gszVideoMemoryFormat,display->videoTotal/1048576.0f,display->videoFree/1048576.0f);
  DDSCAPS2 memoryCaps;memset(&memoryCaps,0,sizeof(memoryCaps));memoryCaps.caps=0x5000;
  hr=gpIDirectDraw4_00970E60->vtbl->GetAvailableVidMem(gpIDirectDraw4_00970E60,&memoryCaps,&display->textureTotal,&display->textureFree);
  if(hr) { D3DCORE_LogDDrawError(gszTextureMemoryFailed,hr); goto Cleanup; }
  LOGMANAGER_WriteLogLine(gszTextureMemoryFormat,display->textureTotal/1048576.0f,display->textureFree/1048576.0f);
  memset(&memoryCaps,0,sizeof(memoryCaps));memoryCaps.caps=0x10005000;
  hr=gpIDirectDraw4_00970E60->vtbl->GetAvailableVidMem(gpIDirectDraw4_00970E60,&memoryCaps,&display->localTotal,&display->localFree);
  if(hr) { D3DCORE_LogDDrawError(gszLocalMemoryFailed,hr); goto Cleanup; }
  LOGMANAGER_WriteLogLine(gszLocalMemoryFormat,display->localTotal/1048576.0f,display->localFree/1048576.0f);
  if((caps.caps2&0x200)&&(hardware.devCaps&0x1000)) {
   display->flags|=gdwBitMasks[1];
   memset(&memoryCaps,0,sizeof(memoryCaps));memoryCaps.caps=0x20005000;
   hr=gpIDirectDraw4_00970E60->vtbl->GetAvailableVidMem(gpIDirectDraw4_00970E60,&memoryCaps,&display->agpTotal,&display->agpFree);
   if(hr) D3DCORE_LogDDrawError(gszAgpMemoryFailed,hr);
   else LOGMANAGER_WriteLogLine(gszAgpMemoryFormat,display->agpTotal/1048576.0f,display->agpFree/1048576.0f);
  } else LOGMANAGER_WriteLogLine(gszNoAgpTexturing);
  hr=device->vtbl->EnumTextureFormats(device,D3D_EnumTextureFormatCallback,display);
  if(hr) { D3DCORE_ShowD3DError(gszEnumTextureFormatsFailed,hr); goto Cleanup; }

  int textures=0;
  if(display->flags&gdwBitMasks[9]) { LOGMANAGER_WriteLogLine(gszSupports1555Textures); textures=1; }
  if(!textures) { LOGMANAGER_WriteLogLine(gszNoTextureFormats); goto Cleanup; }
  if(gnDisplayCount==0) {
   gPrimarySelection.flags=display->flags;gPrimarySelection.guid=display->guid;
   gPrimarySelection.vendor=display->vendor;gPrimarySelection.device=display->device;
   strcpy(gPrimarySelection.description,display->description);
   gPrimarySelection.renderer=2;gnPrimaryRenderer=2;
  } else if(gnDisplayCount==1) {
   gSecondarySelection.flags=display->flags;gSecondarySelection.guid=display->guid;
   gSecondarySelection.vendor=display->vendor;gSecondarySelection.device=display->device;
   strcpy(gSecondarySelection.description,display->description);
   gSecondarySelection.renderer=2;gnSecondaryRenderer=2;
  }
  ++gnDisplayCount;LOGMANAGER_WriteLogLine(gszPassedRequirements);

  } else LOGMANAGER_WriteLogLine(gszNoTriangleSupport);
 } catch(...) {
  LOGMANAGER_WriteLogLine(gszEnumD3DCaughtFailure);
  if(!gnDisplayCount) gPrimarySelection.renderer=0;
  else if(gnDisplayCount==1) gSecondarySelection.renderer=0;
 }
Cleanup:
 try {
  if(device) { device->vtbl->Release(device);device=0; }
  if(back) back=0;
  if(primary) { primary->vtbl->Release(primary);primary=0; }
  if(gpIDirect3D3_00970E64) { gpIDirect3D3_00970E64->vtbl->Release(gpIDirect3D3_00970E64);gpIDirect3D3_00970E64=0; }
  if(gpIDirectDraw4_00970E60) { gpIDirectDraw4_00970E60->vtbl->Release(gpIDirectDraw4_00970E60);gpIDirectDraw4_00970E60=0; }
 } catch(...) { LOGMANAGER_WriteLogLine(gszEnumD3DCleanupFailed); }
 return 1;
}

// 0x006B4C90
static int __stdcall D3DCORE_DetectDirect3D(HINSTANCE hInstance)
{
    WNDCLASSA wc;

    try
    {
        LOGMANAGER_WriteLogLine("Detecting boards which support Direct3D...");

        memset(&wc, 0, sizeof(wc));
        gnD3DDeviceCount = 0;
        wc.style = 0;
        wc.lpfnWndProc = DefWindowProcA;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = hInstance;
        wc.hIcon = 0;
        wc.hbrBackground = (HBRUSH)GetStockObject(5);
        wc.lpszMenuName = 0;
        wc.lpszClassName = gszEnumerationClass;
        if (!RegisterClassA(&wc))
        {
            sub_0051793E_FormatAndRaise(GetLastError());
            return 0;
        }

        SetLastError(0);
        ghEnumWindow = CreateWindowExA(0x40000, gszEnumerationClass, gszEnumerationWindow, 0xA0000000, 0, 0, 640, 480, 0, 0, hInstance, 0);
        if (!ghEnumWindow)
        {
            LOGMANAGER_WriteLogLine("***** Failed to create window for D3D enumeration= %d", GetLastError());
            return 0;
        }

        const HRESULT hResult = DirectDrawEnumerateA(D3DCORE_EnumerateD3DDevices, 0);
        if (hResult)
        {
            D3DCORE_LogDDrawError("DirectDrawEnumerate", hResult);
        }
    }
    catch (...)
    {
        LOGMANAGER_WriteLogLine(" ** Caught a failure in Direct3DDetect ** ");
    }

    try
    {
        if (ghEnumWindow)
        {
            DestroyWindow(ghEnumWindow);
            LOGMANAGER_WriteLogLine("Destroyed D3D window.");
        }

        if (!gnD3DDeviceCount)
        {
            LOGMANAGER_WriteLogLine("Found no valid Direct3D devices to use!");
            return 0;
        }
    }
    catch (...)
    {
    }

    UnregisterClassA(gszEnumerationClass, hInstance);

    if (gnDeviceStatus2 == 2)
    {
        D3DCORE_SaveVideoConfig(1, 2);
        return 2;
    }

    if (gnDeviceStatus3 == 2)
    {
        D3DCORE_SaveVideoConfig(1, 3);
        return 2;
    }

    return 0;
}

// 0x006B4E80
int __fastcall D3DCORE_LoadVideoConfiguration(void* window) {
    D2FogSystemInfoStrc* info=FOG_GetSystemInfo();
    if (!info) { FOG_DisplayHalt("",sub_00408090(),1032); exit(-1); }
    if (info->nOsKind==1) return 0;
    D2VideoKeyStrc key=gtVideoKey;
    if (gbSeen && !gbConfigured) {
        D3DCORE_DetectDirect3D(window);
        gbConfigured=1;
    }
    gbSeen=1;
    for (;;) {
        if (!SRegLoadString((const char*)&key,"DeviceName",0,gszDeviceName,256)) {
            if (gbConfigured) return 0;
            int result=D3DCORE_DetectDirect3D(window);
            gbConfigured=1;
            if (result!=2) return 0;
        } else if (!SRegLoadValue((const char*)&key,"dwFlags",0,&gdwRenderFlags)) {
            if (gbConfigured) return 0;
            int result=D3DCORE_DetectDirect3D(window);
            gbConfigured=1;
            if (result!=2) return 0;
        } else break;
    }
    if (!(gdwRenderFlags & gdwBitMasks_006CE268[0])) {
        unsigned int length=16;
        if (!SRegLoadData((const char*)&key,"GUID",0,gtDeviceGuid,16,&length) || length!=16) return 0;
    }
    return 1;
}

// 0x006B4FD0
static int D3DCORE_InitFullscreen(void* window,int mode)
{
    if(gnInitialized) { FOG_DisplayHalt("",sub_00408090(),0x50F); exit(-1); }
    long error;
    const char* msg;
    ghWindow=window;
    if(mode==0) { gnWidth=640; gnHeight=480; } else { gnWidth=800; gnHeight=600; }
    switch(mode) { case 0: case 2: gnModeFlag=1; break; default: gnModeFlag=0; break; }
    DD_CHECK(gpDraw->SetCooperativeLevel(window,0x411),"SetCooperativeLevel failed!");
    error=gpDraw->SetDisplayMode(gnWidth,gnHeight,32,0,0);
    if(error) { D3DCORE_LogDDrawError("SetDisplayMode failed!",error); return 0; }
    MoveWindow(window,0,0,gnWidth,gnHeight,1);
    gnInitialized=1; gnState=0;
    SurfaceDesc desc;
    desc.size=sizeof(desc);
    memset((char*)&desc+4,0,sizeof(desc)-4);
    desc.flags=0x21; desc.caps=0x6218; desc.backBuffers=1;
    DD_CHECK(gpDraw->CreateSurface(&desc,&gpPrimary,0),gSurfaceError);
    Caps caps;
    memset(&caps,0,sizeof(caps)); caps.flags=4;
    DD_CHECK(gpPrimary->GetAttachedSurface(&caps,&gpBack),gAttachedError);
    if(gnFlags & gdwBitMasks[4])
    {
        DD_CHECK(gpPrimary->QueryInterface(&gGammaGuid,&gpGamma),gGammaInterfaceError);
        DD_CHECK(gpGamma->GetGammaRamp(0,gGammaRamp),gGammaError);
    }
    D3D_CHECK(gpD3D->CreateDevice(&gDeviceGuid,gpBack,&gpDevice,0),gDeviceError);
    D3D_CHECK(gpD3D->CreateViewport(&gpView,0),gCreateViewError);
    D3D_CHECK(gpDevice->AddViewport(gpView),gAddViewError);
    Viewport viewport;
    memset(&viewport,0,sizeof(viewport));
    viewport.size=sizeof(viewport); viewport.x=0; viewport.y=0;
    viewport.width=gnWidth; viewport.height=gnHeight;
    viewport.clipX=0.0f; viewport.clipY=0.0f;
    viewport.clipWidth=(float)gnWidth; viewport.clipHeight=(float)gnHeight;
    viewport.minZ=0.0f; viewport.maxZ=1.0f;
    D3D_CHECK(gpView->SetViewport(&viewport),gSetViewError);
    D3D_CHECK(gpDevice->SetCurrentViewport(gpView),gCurrentViewError);
    memset(&caps,0,sizeof(caps)); caps.flags=0x5000;
    error=gpDraw->GetAvailableMemory(&caps,&gnTextureTotal,&gnTextureFree);
    if(error) D3DCORE_LogDDrawError(gTextureError,error);
    memset(&caps,0,sizeof(caps)); caps.flags=0x10005000;
    error=gpDraw->GetAvailableMemory(&caps,&gnLocalTotal,&gnLocalFree);
    if(error) D3DCORE_LogDDrawError(gLocalError,error);
    if(gnFlags & gdwBitMasks[1])
    {
        memset(&caps,0,sizeof(caps)); caps.flags=0x20005000;
        error=gpDraw->GetAvailableMemory(&caps,&gnAgpTotal,&gnAgpFree);
        if(error) D3DCORE_LogDDrawError(gAgpError,error);
    }
    gpDevice->SetRenderState(29,0);
    gpDevice->SetRenderState(22,1);
    gpDevice->SetRenderState(4,0);
    gpDevice->SetRenderState(7,0);
    gpDevice->SetRenderState(14,0);
    gpDevice->SetRenderState(26,1);
    gpDevice->SetRenderState(25,6);
    gpDevice->SetRenderState(24,0);
    gpDevice->SetTextureStageState(0,12,3);
    D3DCORE_SetTextureFilterMode(1);
    gpDevice->SetTextureStageState(0,2,2);
    gpDevice->SetTextureStageState(0,3,0);
    gpDevice->SetTextureStageState(0,5,2);
    gpDevice->SetTextureStageState(0,6,0);
    D3DCORE_InitBufferPools(); D3DFLOORCACHE_CreateTileSurfaces(); sub_006B8F10_CreateGridVertexBuffer();
    return 1;
D3DFail:
    D3DCORE_ShowD3DError(msg,error);
Fail:
    D3DCORE_ReleaseResources(); ghWindow=0; return 0;
}

// 0x006B5520
void __cdecl D3DCORE_FlushAndFlip()
{
    D3DCORE_Flush();
    if (gpGfxSettings->bVSync)
    {
        gpDevice_00970E68->lpVtbl->Flip(gpDevice_00970E68, 0, 1);
    }
    else
    {
        gpDevice_00970E68->lpVtbl->Flip(gpDevice_00970E68, 0, 9);
    }
}

// 0x006B5550
int __cdecl D3DCORE_Close()
{
    if (gbD3DInitialized)
    {
        D3DSMACK_SmackFree();
        D3DCORE_ReleaseResources();
        gn_007C9140 = 0;
        RELEASE(gpObject_00970E64);
        RELEASE(gpObject_00970E60);
        if (gpRenderCriticalSection)
        {
            DeleteCriticalSection(gpRenderCriticalSection);
            FOG_Free(gpRenderCriticalSection, ".\\Src\\d3dCore.cpp", 0x71D, 0);
            gpRenderCriticalSection = 0;
        }
        gbD3DInitialized = 0;
    }
    return 1;
}

// 0x006B55E0
int __fastcall D3DCORE_CreateSurface(void* window,int mode)
{
    if (gnInitialized)
        return 1;

    if (!D3DCORE_InitFullscreen(window, mode))
        return 0;

    D3DCORE_Flush();
    if (gpOptions->flag)
        gpPrimary->Flip(0, 1);
    else
        gpPrimary->Flip(0, 9);
    return 1;
}

// 0x006B5630
void __fastcall D3DCORE_PauseSurface(void* window, int mode, int paused)
{
    if (!gpRenderCriticalSection) { FOG_DisplayHalt("", sub_00408090(), 0x7b0); exit(-1); }
    EnterCriticalSection(gpRenderCriticalSection);
    if (paused) {
        gbRenderPaused = 1;
        D3DCORE_ReleaseResources();
        gn_007C9140 = 0;
    }
    else {
        gbRenderPaused = 0;
        D3DCORE_CreateSurface(window, mode);
    }
    LeaveCriticalSection(gpRenderCriticalSection);
}

// 0x006B56C0
void __fastcall D3DCORE_OpenSmackCutscene(int a, int b, int c)
{
    if (!gnWindowed)
    {
        gbD3DBusy = 1;
        D3DCORE_Flush();
        if (gpGfxSettings->bVSync)
        {
            gpDevice_00970E68->lpVtbl->Flip(gpDevice_00970E68, 0, 1);
        }
        else
        {
            gpDevice_00970E68->lpVtbl->Flip(gpDevice_00970E68, 0, 9);
        }
        sub_006BBCE0_Run(a, b, c);
        gbD3DBusy = 0;
    }
}

// 0x006B5720
int __fastcall D3DCORE_StartDraw(int clear, int unused, int unusedA, int unusedB)
{
    if (gbRenderPaused) return 0;
    if (!gpRenderCriticalSection) { FOG_DisplayHalt("", sub_00408090(), 0x842); exit(-1); }
    EnterCriticalSection(gpRenderCriticalSection);
    if (clear) sub_006B7F70_ClearTarget(0);
    gnColorCombineMode = 0;
    gnAlphaBlendMode = 0;
    gnFilterMode = 0;
    sub_006B9710_SetColorComponents(255, 255, 255);
    long result = gpDevice_00970E78->lpVtbl->BeginScene(gpDevice_00970E78);
    if (result) D3DCORE_ShowD3DError("BeginScene failed!", result);
    return 1;
}

// 0x006B57D0
int __cdecl D3DCORE_EndDraw()
{
    const long nResult = gpDevice_00970E78->lpVtbl->EndScene(gpDevice_00970E78);
    if (nResult)
    {
        D3DCORE_ShowD3DError("EndScene failed!", nResult);
    }
    D2_ASSERT(gpRenderCriticalSection, 0x8B3);
    LeaveCriticalSection(gpRenderCriticalSection);
    return 1;
}

// 0x006B5830
int __fastcall D3DCORE_ChangeRes(void* window,int mode)
{
    if (gnWindowed)
        return 1;

    D3DCORE_ReleaseResources();
    ghWindow = 0;
    if (!D3DCORE_InitFullscreen(window, mode))
        return 0;

    D3DCORE_Flush();
    if (gpOptions->flag)
        gpPrimary->Flip(0, 1);
    else
        gpPrimary->Flip(0, 9);
    return 1;
}

// 0x006B58A0
int __fastcall D3DCORE_CreateDeviceTexture(D2ComObject006B58A0Strc** ppSurface, D2ComObject006B58A0Strc** ppTexture, unsigned int nWidth, unsigned int nHeight)
{
    D2DDSurfaceDesc006B58A0Strc tDesc = { sizeof(tDesc) };
    tDesc.dwFlags = 0x1007;
    tDesc.aCaps2[0] = 0x80;
    tDesc.tPixelFormat = gtWantedFormat;
    tDesc.dwWidth = nWidth;
    tDesc.dwHeight = nHeight;
    tDesc.dwCaps = gnDeviceTextureFlag ? 0x5000 : 0x10005000;
    long hResult = gpDirectDraw4->lpVtbl->CreateSurface(gpDirectDraw4, &tDesc, ppSurface, 0);
    if (hResult)
    {
        if (hResult != (long)0x8876017C)
        {
            D3DCORE_LogDDrawError("CreateSurface (device surface)", hResult);
        }
        return 0;
    }
    hResult = (*ppSurface)->lpVtbl->QueryInterface(*ppSurface, gabIidTexture, (void**)ppTexture);
    if (hResult)
    {
        D3DCORE_ShowD3DError("Failed to get texture interface for device surface", hResult);
        (*ppSurface)->lpVtbl->Release(*ppSurface);
        return 0;
    }
    return 1;
}

// 0x006B5990
void __cdecl D3DCORE_CloseAtExit()
{
    D3DCORE_Close();
}

// 0x006B59A0
int __fastcall D3DCORE_Init(int nArg1, int nArg2)
{
    D2ComObjectStrc* pDirectDraw = 0;
    char tIdentifier[0x850];

    D2_ASSERT(!gbD3DInitialized, 0x687);

    gnD3DArg1_007C9148 = nArg1;
    gpTileDrawFunctions = nArg2;

    int hResult;
    if (gnDeviceFlags_0096F3A8 & gdwBitMasks[0])
    {
        hResult = sub_006B1350_DirectDrawCreate(0, &pDirectDraw, 0);
    }
    else
    {
        hResult = sub_006B1350_DirectDrawCreate(&gDeviceGuid_0096F3AC, &pDirectDraw, 0);
    }

    if (hResult)
    {
        D3DCORE_LogDDrawError("DirectDrawCreate failed!", hResult);
        return 0;
    }

    hResult = ((D2ComQueryInterfaceFn)pDirectDraw->lpVtbl[0])(pDirectDraw, &gtIidDirectDraw4, &gpDirectDraw4_00970E60);
    if (hResult)
    {
        D3DCORE_LogDDrawError("Failed to get DirectDraw4 interface!", hResult);
        return 0;
    }

    ((D2ComReleaseFn)pDirectDraw->lpVtbl[2])(pDirectDraw);
    pDirectDraw = 0;

    hResult = ((D2ComQueryInterfaceFn)gpDirectDraw4_00970E60->lpVtbl[0])(gpDirectDraw4_00970E60, &gtIidDirect3D3, &gpDirect3D3);
    if (hResult)
    {
        D3DCORE_LogDDrawError("Failed to get D3D interface!", hResult);
        return 0;
    }

    hResult = ((D2DDGetDeviceIdentifierFn)gpDirectDraw4_00970E60->lpVtbl[0x1B])(gpDirectDraw4_00970E60, tIdentifier, 0);
    if (hResult)
    {
        D3DCORE_LogDDrawError("Failed to get device identifier interface!", hResult);
    }

    atexit(D3DCORE_CloseAtExit);
    gbD3DInitialized = 1;
    sub_006B96C0_BuildScaleTable();
    sub_006B97D0_BuildScaleTable();
    sub_006B80A0_InitializeDrawingGeometry();
    D3DSMACK_SmackInit();
    gpRenderCriticalSection = (D2CriticalSectionStrc*)FOG_Alloc(0x18, gszD3DCoreFile, 0x6EA, 0);
    InitializeCriticalSection(gpRenderCriticalSection);
    return 1;
}

// 0x006B20C0
int __fastcall D3DCORE_SetOption(int nId, int nValue)
{
    if (nId != 11)
        return 0;
    gnGammaScale = nValue;
    return 1;
}

// 0x006B20E0
void __fastcall D3DCORE_LogDDrawError(const char* szWhere, int hResult)
{
    const char* szError;
    switch (hResult)
    {
    case (int)0x80004005: szError = "DDERR_GENERIC"; break;
    case (int)0x80004001: szError = "DDERR_UNSUPPORTED"; break;
    case (int)0x800401F0: szError = "DDERR_NOTINITIALIZED"; break;
    case (int)0x80070057: szError = "DDERR_INVALIDPARAMS"; break;
    case (int)0x8007000E: szError = "DDERR_OUTOFMEMORY"; break;
    case (int)0x88760005: szError = "DDERR_ALREADYINITIALIZED"; break;
    case (int)0x8876000A: szError = "DDERR_CANNOTATTACHSURFACE"; break;
    case (int)0x88760014: szError = "DDERR_CANNOTDETACHSURFACE"; break;
    case (int)0x88760028: szError = "DDERR_CURRENTLYNOTAVAIL"; break;
    case (int)0x88760037: szError = "DDERR_EXCEPTION"; break;
    case (int)0x8876005A: szError = "DDERR_HEIGHTALIGN"; break;
    case (int)0x8876005F: szError = "DDERR_INCOMPATIBLEPRIMARY"; break;
    case (int)0x88760064: szError = "DDERR_INVALIDCAPS"; break;
    case (int)0x8876006E: szError = "DDERR_INVALIDCLIPLIST"; break;
    case (int)0x88760078: szError = "DDERR_INVALIDMODE"; break;
    case (int)0x88760082: szError = "DDERR_INVALIDOBJECT"; break;
    case (int)0x88760091: szError = "DDERR_INVALIDPIXELFORMAT"; break;
    case (int)0x88760096: szError = "DDERR_INVALIDRECT"; break;
    case (int)0x887600A0: szError = "DDERR_LOCKEDSURFACES"; break;
    case (int)0x887600AA: szError = "DDERR_NO3D"; break;
    case (int)0x887600B4: szError = "DDERR_NOALPHAHW"; break;
    case (int)0x887600CD: szError = "DDERR_NOCLIPLIST"; break;
    case (int)0x887600D2: szError = "DDERR_NOCOLORCONVHW"; break;
    case (int)0x887600D4: szError = "DDERR_NOCOOPERATIVELEVELSET"; break;
    case (int)0x887600D7: szError = "DDERR_NOCOLORKEY"; break;
    case (int)0x887600DC: szError = "DDERR_NOCOLORKEYHW"; break;
    case (int)0x887600DE: szError = "DDERR_NODIRECTDRAWSUPPORT"; break;
    case (int)0x887600E1: szError = "DDERR_NOEXCLUSIVEMODE"; break;
    case (int)0x887600E6: szError = "DDERR_NOFLIPHW"; break;
    case (int)0x887600F0: szError = "DDERR_NOGDI"; break;
    case (int)0x887600FA: szError = "DDERR_NOMIRRORHW"; break;
    case (int)0x887600FF: szError = "DDERR_NOTFOUND"; break;
    case (int)0x88760104: szError = "DDERR_NOOVERLAYHW"; break;
    case (int)0x88760118: szError = "DDERR_NORASTEROPHW"; break;
    case (int)0x88760122: szError = "DDERR_NOROTATIONHW"; break;
    case (int)0x88760136: szError = "DDERR_NOSTRETCHHW"; break;
    case (int)0x8876013C: szError = "DDERR_NOT4BITCOLOR"; break;
    case (int)0x8876013D: szError = "DDERR_NOT4BITCOLORINDEX"; break;
    case (int)0x88760140: szError = "DDERR_NOT8BITCOLOR"; break;
    case (int)0x8876014A: szError = "DDERR_NOTEXTUREHW"; break;
    case (int)0x8876014F: szError = "DDERR_NOVSYNCHW"; break;
    case (int)0x88760154: szError = "DDERR_NOZBUFFERHW"; break;
    case (int)0x8876015E: szError = "DDERR_NOZOVERLAYHW"; break;
    case (int)0x88760168: szError = "DDERR_OUTOFCAPS"; break;
    case (int)0x8876017C: szError = "DDERR_OUTOFVIDEOMEMORY"; break;
    case (int)0x8876017E: szError = "DDERR_OVERLAYCANTCLIP"; break;
    case (int)0x88760180: szError = "DDERR_OVERLAYCOLORKEYONLYONEACTIVE"; break;
    case (int)0x88760183: szError = "DDERR_PALETTEBUSY"; break;
    case (int)0x88760190: szError = "DDERR_COLORKEYNOTSET"; break;
    case (int)0x8876019A: szError = "DDERR_SURFACEALREADYATTACHED"; break;
    case (int)0x887601A4: szError = "DDERR_SURFACEALREADYDEPENDENT"; break;
    case (int)0x887601AE: szError = "DDERR_SURFACEBUSY"; break;
    case (int)0x887601B3: szError = "DDERR_CANTLOCKSURFACE"; break;
    case (int)0x887601B8: szError = "DDERR_SURFACEISOBSCURED"; break;
    case (int)0x887601C2: szError = "DDERR_SURFACELOST"; break;
    case (int)0x887601CC: szError = "DDERR_SURFACENOTATTACHED"; break;
    case (int)0x887601D6: szError = "DDERR_TOOBIGHEIGHT"; break;
    case (int)0x887601E0: szError = "DDERR_TOOBIGSIZE"; break;
    case (int)0x887601EA: szError = "DDERR_TOOBIGWIDTH"; break;
    case (int)0x887601FE: szError = "DDERR_UNSUPPORTEDFORMAT"; break;
    case (int)0x88760208: szError = "DDERR_UNSUPPORTEDMASK"; break;
    case (int)0x88760219: szError = "DDERR_VERTICALBLANKINPROGRESS"; break;
    case (int)0x8876021C: szError = "DDERR_WASSTILLDRAWING"; break;
    case (int)0x88760230: szError = "DDERR_XALIGN"; break;
    case (int)0x88760231: szError = "DDERR_INVALIDDIRECTDRAWGUID"; break;
    case (int)0x88760232: szError = "DDERR_DIRECTDRAWALREADYCREATED"; break;
    case (int)0x88760233: szError = "DDERR_NODIRECTDRAWHW"; break;
    case (int)0x88760234: szError = "DDERR_PRIMARYSURFACEALREADYEXISTS"; break;
    case (int)0x88760235: szError = "DDERR_NOEMULATION"; break;
    case (int)0x88760236: szError = "DDERR_REGIONTOOSMALL"; break;
    case (int)0x88760237: szError = "DDERR_CLIPPERISUSINGHWND"; break;
    case (int)0x88760238: szError = "DDERR_NOCLIPPERATTACHED"; break;
    case (int)0x88760239: szError = "DDERR_NOHWND"; break;
    case (int)0x8876023A: szError = "DDERR_HWNDSUBCLASSED"; break;
    case (int)0x8876023B: szError = "DDERR_HWNDALREADYSET"; break;
    case (int)0x8876023C: szError = "DDERR_NOPALETTEATTACHED"; break;
    case (int)0x8876023D: szError = "DDERR_NOPALETTEHW"; break;
    case (int)0x8876023E: szError = "DDERR_BLTFASTCANTCLIP"; break;
    case (int)0x8876023F: szError = "DDERR_NOBLTHW"; break;
    case (int)0x88760240: szError = "DDERR_NODDROPSHW"; break;
    case (int)0x88760241: szError = "DDERR_OVERLAYNOTVISIBLE"; break;
    case (int)0x88760242: szError = "DDERR_NOOVERLAYDEST"; break;
    case (int)0x88760243: szError = "DDERR_INVALIDPOSITION"; break;
    case (int)0x88760244: szError = "DDERR_NOTAOVERLAYSURFACE"; break;
    case (int)0x88760245: szError = "DDERR_EXCLUSIVEMODEALREADYSET"; break;
    case (int)0x88760246: szError = "DDERR_NOTFLIPPABLE"; break;
    case (int)0x88760247: szError = "DDERR_CANTDUPLICATE"; break;
    case (int)0x88760248: szError = "DDERR_NOTLOCKED"; break;
    case (int)0x88760249: szError = "DDERR_CANTCREATEDC"; break;
    case (int)0x8876024A: szError = "DDERR_NODC"; break;
    case (int)0x8876024B: szError = "DDERR_WRONGMODE"; break;
    case (int)0x8876024C: szError = "DDERR_IMPLICITLYCREATED"; break;
    case (int)0x8876024D: szError = "DDERR_NOTPALETTIZED"; break;
    case (int)0x8876024E: szError = "DDERR_UNSUPPORTEDMODE"; break;
    case (int)0x8876024F: szError = "DDERR_NOMIPMAPHW"; break;
    case (int)0x88760250: szError = "DDERR_INVALIDSURFACETYPE"; break;
    case (int)0x88760258: szError = "DDERR_NOOPTIMIZEHW"; break;
    case (int)0x88760259: szError = "DDERR_NOTLOADED"; break;
    case (int)0x8876026C: szError = "DDERR_DCALREADYCREATED"; break;
    case (int)0x88760276: szError = "DDERR_NONONLOCALVIDMEM"; break;
    case (int)0x88760280: szError = "DDERR_CANTPAGELOCK"; break;
    case (int)0x88760294: szError = "DDERR_CANTPAGEUNLOCK"; break;
    case (int)0x887602A8: szError = "DDERR_NOTPAGELOCKED"; break;
    case (int)0x887602B2: szError = "DDERR_MOREDATA"; break;
    case (int)0x887602B7: szError = "DDERR_VIDEONOTACTIVE"; break;
    case (int)0x887602BB: szError = "DDERR_DEVICEDOESNTOWNSURFACE"; break;
    case (int)0x00000000: szError = "DD_OK"; break;
    default: szError = "< unknown >"; break;
    }

    LOGMANAGER_WriteLogLine("***** DirectDraw error: %s - %s (0x%x)", szWhere, szError, hResult);
}

void __fastcall D3DCORE_ClearCaches(); // 0x006B1BC0

int gnModeFlag;        // 0x00970E8C

// 0x006B2F20
int __cdecl D3DCORE_GetModeFlag()
{
    return gnModeFlag;
}

// 0x006B2F30
void __fastcall sub_006B2F30_SetGlobal(int nValue)
{
    gnModeFlag = nValue;
}

struct D2Object006BB3E0Strc;

struct D2Object006BADC0Strc;

struct D2DDrawDeviceStrc;


struct D2Cache006BA830Strc;

struct D2DDCaps006B3420Strc;

struct D2DDSurfaceDesc006B3420Strc;

struct D2ComObject006B3420Strc;


extern "C" __declspec(dllimport) long __stdcall RegCreateKeyExA(void* hKey, const char* szSubKey, unsigned long nReserved, char* szClass, unsigned long nOptions, unsigned long samDesired, void* pSecurity, void** phkResult, unsigned long* pDisposition); // 0x006CC004

extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey); // 0x006CC030

extern D2DDrawDeviceStrc gaDDrawDevices[]; // 0x0096F4E0






void __fastcall sub_006BA830_FreeCache(D2Cache006BA830Strc* pCache, int bFree); // 0x006BA830

void __fastcall D3DSUBTILECACHE_SubtileCacheDestroy(D2Object006BADC0Strc* pObject, int bFree); // 0x006BADC0

void __fastcall D3DFLOORCACHE_FloorCacheDestroy(D2Object006BB3E0Strc* pObject, int bFree); // 0x006BB3E0


extern D2Object006BADC0Strc gtSubtileCache; // 0x0096FC80

extern D2Object006BB3E0Strc gTextureCache; // 0x0096FC9C

extern D2Cache006BA830Strc gtTextureCache1; // 0x00970EC8

extern D2Cache006BA830Strc gtTextureCache2; // 0x00970EE4

extern D2Cache006BA830Strc gtTextureCache3; // 0x00970F00

void __cdecl D3DCORE_ReleaseResources(); // 0x006B3320

extern void* ghDDrawWindow_007C9140; // 0x007C9140




extern "C" const char gszEmptyAssertText; // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0


void __fastcall D3DCORE_LogDDrawError(const char* szWhere, int hResult); // 0x006B20E0

extern int gbVideoUp; // 0x00970E40

extern int gnVideoState; // 0x00970E44


extern D2ComObject006B3420Strc* gpPrimary_00970E68; // 0x00970E68



extern int gnRenderHeight; // 0x007C913C

// 0x006B2F60
void __fastcall D3DCORE_SaveVideoConfig(int nRender, int nDevice)
{
    int aDeviceName[0x104 / 4];
    int aFlags[0x104 / 4];
    int aGuid[0x104 / 4];
    sprintf((char*)aDeviceName, "DeviceName");
    sprintf((char*)aFlags, "dwFlags");
    sprintf((char*)aGuid, "GUID");

    ATL::CRegKey tKey;
    if (tKey.Create((void*)0x80000001, "SOFTWARE\\Blizzard Entertainment\\Diablo II\\VideoConfig") == 0)
    {
        tKey.SetDWORDValue("Render", nRender);
        tKey.SetStringValue((const char*)aDeviceName, gaDDrawDevices[nDevice].szName);
        tKey.SetDWORDValue((const char*)aFlags, gaDDrawDevices[nDevice].dwFlags);
        tKey.SetBinaryValue((const char*)aGuid, gaDDrawDevices[nDevice].guid, 0x10);
    }
}

struct D2TileLibraryEntryStrc;
struct D2ComObjectStrc;
struct BufferPool;
struct BufferPool { unsigned int count; char unknown[24]; };
extern unsigned int gRenderFlags; // 0x0096F3A8
extern unsigned int gAvailableMemory; // 0x0096F4D0
extern unsigned int gPreferredMemory; // 0x0096F4D8
extern unsigned int gTileWidth; // 0x0096F4DC
extern unsigned int gTileHeight; // 0x009702B8
extern int gUsePreferredMemory; // 0x00970E4C
extern unsigned int gBufferCopies; // 0x00970E80
extern unsigned int gPrimaryBudget; // 0x007C90C8
extern unsigned int gSecondaryBudget; // 0x007C90D4
extern unsigned int gLargeBudget; // 0x007C90E0
extern unsigned int gMediumBudget; // 0x007C90E4
extern unsigned int gSmallBudget; // 0x007C90E8
extern BufferPool gTilePool; // 0x0096FC9C
extern BufferPool gAuxiliaryPool; // 0x0096FC80
extern BufferPool gLargePool; // 0x00970EC8
extern BufferPool gMediumPool; // 0x00970EE4
extern BufferPool gSmallPool; // 0x00970F00
char* __fastcall sub_006B76D0_InitVertices(char*); // 0x006B76D0
char* __fastcall D3DFLOORCACHE_FloorCacheInit(BufferPool*,char*,char*,unsigned int); // 0x006BAFC0
char* __fastcall D3DSUBTILECACHE_SubtileCacheInit(BufferPool*,char*,char*,unsigned int); // 0x006BA9A0
char* __fastcall sub_006BA420_Init(BufferPool*,char*,char*,unsigned int,unsigned int); // 0x006BA420
void __stdcall TileSetHardwareFreeCallback(void*); // 0x00604A30
extern D2ComObjectStrc* gpInterface_00970E78; // 0x00970E78
void __cdecl sub_006B9150_ReleaseResource(); // 0x006B9150
int gbVideoUp; // 0x00970E40
int gnVideoState; // 0x00970E44
D2ComObjectStrc* gpPrimarySurface; // 0x00970E68
D2ComObjectStrc* gpRenderSurface; // 0x00970E6C
D2ComObjectStrc* gpInterface; // 0x00970E70
D2ComObjectStrc* gpGammaControl; // 0x00970E74
D2ComObjectStrc* gpViewport; // 0x00970E7C
char gabGammaRamp[1536]; // 0x0096FCB8

// 0x006B3080
void __cdecl D3DCORE_InitBufferPools()
{
 unsigned int memory;
 gBufferCopies=2;
 gUsePreferredMemory=0;
 if((gRenderFlags&gdwBitMasks[1]) && gAvailableMemory<0xD00000) {
  gUsePreferredMemory=1;
  if(gPreferredMemory>=0x2000000)gPreferredMemory=0x2000000;
  memory=gAvailableMemory;
  if(memory<=gPreferredMemory)memory=gPreferredMemory;
 } else {
  memory=gAvailableMemory;
  if(memory>=0x2000000)memory=0x2000000;
 }
 char* current = 0;char* start;unsigned int remaining;
 if(gnModeFlag) {
  unsigned int width,height;
  if(gRenderFlags&gdwBitMasks[6]){width=160;height=80;}else{width=256;height=128;}
  gTileHeight=height;gTileWidth=width;
  unsigned int tileSize=2*width*height;
  unsigned int primary=memory/2<0x600000?memory/2:0x600000;
  unsigned int secondary=memory/8<0x300000?memory/8:0x300000;
  current=sub_006B76D0_InitVertices(current);
  gPrimaryBudget=primary;
  primary+=(unsigned int)current;
  current=D3DFLOORCACHE_FloorCacheInit(&gTilePool,current,(char*)primary,tileSize);
  gSecondaryBudget=secondary;
  secondary+=(unsigned int)current;
  current=D3DSUBTILECACHE_SubtileCacheInit(&gAuxiliaryPool,current,(char*)secondary,2048);
  start=current;remaining=memory-(unsigned int)current;
  current=sub_006BA420_Init(&gLargePool,current,current+remaining*20/100,256,256);
  gLargeBudget=gLargePool.count*gBufferCopies*65536;
  current=sub_006BA420_Init(&gMediumPool,current,start+remaining*75/100,128,128);
 } else {
  gPrimaryBudget=0;gSecondaryBudget=0;
  current=D3DSMACK_CreateSmackSurfaces(current);
  start=current;remaining=memory-(unsigned int)current;
  current=sub_006BA420_Init(&gLargePool,current,current+remaining*70/100,256,256);
  gLargeBudget=gLargePool.count*gBufferCopies*65536;
  current=sub_006BA420_Init(&gMediumPool,current,start+remaining*80/100,128,128);
 }
 gMediumBudget=gMediumPool.count*gBufferCopies*16384;
 sub_006BA420_Init(&gSmallPool,current,(char*)memory,32,32);
 gSmallBudget=gSmallPool.count*gBufferCopies*1024;
 D3DSPRITE_InitSprites();
 TileSetHardwareFreeCallback((void*)D3DFLOORCACHE_InvalidateTileCaches);
}

// 0x006B32B0
void __cdecl D3DCORE_ReleaseRenderer()
{
    if (gnModeFlag)
    {
        sub_006B7250_ReleaseAll();
        D3DFLOORCACHE_FloorCacheDestroy(&gTextureCache, 1);
        D3DSUBTILECACHE_SubtileCacheDestroy(&gtSubtileCache, 1);
    }
    else
    {
        D3DSMACK_ReleaseSmackSurfaces();
    }

    sub_006BA830_FreeCache(&gtTextureCache1, 1);
    sub_006BA830_FreeCache(&gtTextureCache2, 1);
    sub_006BA830_FreeCache(&gtTextureCache3, 1);
    D3DSPRITE_ReleaseSprites();
}

// The entry points of the Direct3D renderer, which D2Gfx selects by video mode (gapGraphicsInterfaces).
extern D2GraphicsInterfaceStrc gtD3DGraphicsInterface; // 0x0074BF28

extern "C" void __cdecl D3DSMACK_CloseSmacker(); // 0x006B9BB0
extern "C" void __cdecl D3DSMACK_DecodeSmacker(); // 0x006BA010
extern "C" void __cdecl D3DSMACK_PlaySmacker(); // 0x006BA390
extern "C" void __cdecl D3DSPRITE_CelDrawHilight(); // 0x006B7090
extern "C" void __cdecl D3DSPRITE_DebugFillBackBuffer(); // 0x006B7100
extern "C" void __cdecl D3DSPRITE_DrawFlatSprite(); // 0x006B6730
extern "C" void __cdecl D3DSPRITE_DrawSpriteClipped(); // 0x006B6EE0
extern "C" void __cdecl D3DSPRITE_DrawSpriteRows(); // 0x006B6C90
extern "C" void __cdecl D3DSPRITE_DrawSpriteShadow(); // 0x006B7000
extern "C" void __cdecl sub_006B7630_DrawTextV(); // 0x006B7630
extern "C" void __cdecl sub_006B76C0_Nop(); // 0x006B76C0
extern "C" void __cdecl sub_006B77B0_Call(); // 0x006B77B0
extern "C" void __cdecl sub_006B7980_DrawRectangle(); // 0x006B7980
extern "C" void __cdecl sub_006B7B30_DrawLine(); // 0x006B7B30
extern "C" void __cdecl sub_006B7C90_DrawDiamond(); // 0x006B7C90
extern "C" void __cdecl sub_006B7D80_DrawRectangle(); // 0x006B7D80
extern "C" void __cdecl sub_006B7ED0_CallRect(); // 0x006B7ED0
extern "C" void __cdecl sub_006B7F20_CallSquare(); // 0x006B7F20
extern "C" void __cdecl sub_006B86F0_DrawShadow(); // 0x006B86F0
extern "C" void __cdecl sub_006B8E60_DrawRelay(); // 0x006B8E60
extern "C" void __cdecl sub_006B8E90_DrawWallTile(); // 0x006B8E90
extern "C" void __cdecl sub_006B9170_DrawGrid(); // 0x006B9170
extern "C" void __cdecl sub_006B9850_SetOrigin(); // 0x006B9850
extern "C" void __cdecl sub_006B9860_Project(); // 0x006B9860
extern "C" void __cdecl sub_006B9910_ProjectPoint(); // 0x006B9910
extern "C" void __cdecl sub_006B9A00_ResetScale(); // 0x006B9A00
extern "C" void __cdecl D3DSPRITE_CelDraw(); // 0x006B6B40
extern "C" void __cdecl D3DSPRITE_CelDrawColor(); // 0x006B6BF0

extern "C" const unsigned char gData_006FADC2[2] = { 0 }; // 0x006FADC2

extern "C" const int gData_006FADC4 = (-2147483647 - 1); // 0x006FADC4

extern "C" const int gData_006FADC8 = 0x7FFFFFFF; // 0x006FADC8

extern "C" const unsigned int gData_006FADCC = 0; // 0x006FADCC

extern "C" const unsigned int gData_006FADD0 = 0xFFFFFFFF; // 0x006FADD0

extern "C" const long gData_006FADD4 = (-2147483647 - 1); // 0x006FADD4

extern "C" const long gData_006FADD8 = 0x7FFFFFFF; // 0x006FADD8

extern "C" const unsigned long gData_006FADDC = 0; // 0x006FADDC

extern "C" const unsigned long gData_006FADE0 = 0xFFFFFFFF; // 0x006FADE0

extern "C" const __int64 gData_006FADE8 = (-9223372036854775807i64 - 1); // 0x006FADE8

extern "C" const __int64 gData_006FADF0 = 0x7FFFFFFFFFFFFFFFi64; // 0x006FADF0

extern "C" const unsigned __int64 gData_006FADF8 = 0; // 0x006FADF8

extern "C" const unsigned __int64 gData_006FAE00 = 0xFFFFFFFFFFFFFFFFui64; // 0x006FAE00

extern "C" const unsigned int gData_006FAE08 = 16; // 0x006FAE08

extern "C" const int gData_006FAE0C = 8; // 0x006FAE0C

extern "C" const unsigned int gData_006FAE10 = 17; // 0x006FAE10

extern "C" const int gData_006FAE14 = 8; // 0x006FAE14

extern "C" const unsigned int gData_006FAE18 = 16400; // 0x006FAE18

extern "C" const int gData_006FAE1C = 8; // 0x006FAE1C

extern "C" const unsigned int gData_006FAE20 = 16401; // 0x006FAE20

extern "C" const int gData_006FAE24 = 8; // 0x006FAE24

extern "C" const unsigned int gData_006FAE28 = 2; // 0x006FAE28

extern "C" const int gData_006FAE2C = 8; // 0x006FAE2C

extern "C" const unsigned int gData_006FAE30 = 16386; // 0x006FAE30

extern "C" const int gData_006FAE34 = 8; // 0x006FAE34

extern "C" const unsigned int gData_006FAE38 = 18; // 0x006FAE38

extern "C" const int gData_006FAE3C = 8; // 0x006FAE3C

extern "C" const unsigned int gData_006FAE40 = 16402; // 0x006FAE40

extern "C" const int gData_006FAE44 = 8; // 0x006FAE44

extern "C" const unsigned int gData_006FAE48 = 3; // 0x006FAE48

extern "C" const int gData_006FAE4C = 8; // 0x006FAE4C

extern "C" const unsigned int gData_006FAE50 = 16387; // 0x006FAE50

extern "C" const int gData_006FAE54 = 8; // 0x006FAE54

extern "C" const unsigned int gData_006FAE58 = 19; // 0x006FAE58

extern "C" const int gData_006FAE5C = 8; // 0x006FAE5C

extern "C" const unsigned int gData_006FAE60 = 16403; // 0x006FAE60

extern "C" const int gData_006FAE64 = 8; // 0x006FAE64

extern "C" const unsigned int gData_006FAE68 = 3; // 0x006FAE68

extern "C" const int gData_006FAE6C = 8; // 0x006FAE6C

extern "C" const unsigned int gData_006FAE70 = 16387; // 0x006FAE70

extern "C" const int gData_006FAE74 = 8; // 0x006FAE74

extern "C" const unsigned int gData_006FAE78 = 19; // 0x006FAE78

extern "C" const int gData_006FAE7C = 8; // 0x006FAE7C

extern "C" const unsigned int gData_006FAE80 = 16403; // 0x006FAE80

extern "C" const int gData_006FAE84 = 8; // 0x006FAE84

extern "C" const unsigned int gData_006FAE88 = 20; // 0x006FAE88

extern "C" const int gData_006FAE8C = 8; // 0x006FAE8C

extern "C" const unsigned int gData_006FAE90 = 16404; // 0x006FAE90

extern "C" const int gData_006FAE94 = 8; // 0x006FAE94

extern "C" const unsigned int gData_006FAE98 = 21; // 0x006FAE98

extern "C" const int gData_006FAE9C = 8; // 0x006FAE9C

extern "C" const unsigned int gData_006FAEA0 = 16405; // 0x006FAEA0

extern "C" const int gData_006FAEA4 = 8; // 0x006FAEA4

extern "C" const unsigned int gData_006FAEA8 = 4; // 0x006FAEA8

extern "C" const int gData_006FAEAC = 8; // 0x006FAEAC

extern "C" const unsigned int gData_006FAEB0 = 16388; // 0x006FAEB0

extern "C" const int gData_006FAEB4 = 8; // 0x006FAEB4

extern "C" const unsigned int gData_006FAEB8 = 5; // 0x006FAEB8

extern "C" const int gData_006FAEBC = 8; // 0x006FAEBC

extern "C" const unsigned int gData_006FAEC0 = 16389; // 0x006FAEC0

extern "C" const int gData_006FAEC4 = 8; // 0x006FAEC4

extern "C" const unsigned int gData_006FAEC8 = 12; // 0x006FAEC8

extern "C" const unsigned int gData_006FAECC = 8; // 0x006FAECC

extern "C" const int gData_006FAED0 = 8; // 0x006FAED0

extern "C" const unsigned int gData_006FAED4 = 16392; // 0x006FAED4

extern "C" const int gData_006FAED8 = 8; // 0x006FAED8

extern "C" const unsigned int gData_006FAEDC = 13; // 0x006FAEDC

extern "C" const int gData_006FAEE0 = 8; // 0x006FAEE0

extern "C" const unsigned int gData_006FAEE4 = 16397; // 0x006FAEE4

extern "C" const int gData_006FAEE8 = 8; // 0x006FAEE8

extern "C" const unsigned int gData_006FAEEC = 9; // 0x006FAEEC

extern "C" const int gData_006FAEF0 = 8; // 0x006FAEF0

extern "C" const unsigned int gData_006FAEF4 = 16393; // 0x006FAEF4

extern "C" const int gData_006FAEF8 = 8; // 0x006FAEF8

extern "C" const unsigned int gData_006FAEFC = 6; // 0x006FAEFC

extern "C" const int gData_006FAF00 = 8; // 0x006FAF00

extern "C" const unsigned int gData_006FAF04 = 16390; // 0x006FAF04

extern "C" const int gData_006FAF08 = 8; // 0x006FAF08

extern "C" const __declspec(selectany) GUID LIBID_ATLLib = { // 0x006FAF0C
    0x44EC0535,
    0x400F,
    0x11D0,
    { 0x9D, 0xCD, 0x00, 0xA0, 0xC9, 0x03, 0x91, 0xD3 }
};

extern "C" const __declspec(selectany) GUID CLSID_Registrar = { // 0x006FAF1C
    0x44EC053A,
    0x400F,
    0x11D0,
    { 0x9D, 0xCD, 0x00, 0xA0, 0xC9, 0x03, 0x91, 0xD3 }
};

extern "C" const __declspec(selectany) GUID IID_IRegistrar = { // 0x006FAF2C
    0x44EC053B,
    0x400F,
    0x11D0,
    { 0x9D, 0xCD, 0x00, 0xA0, 0xC9, 0x03, 0x91, 0xD3 }
};

extern "C" const __declspec(selectany) GUID IID_IAxWinHostWindow = { // 0x006FAF3C
    0xB6EA2050,
    0x48A,
    0x11D1,
    { 0x82, 0xB9, 0x00, 0xC0, 0x4F, 0xB9, 0x94, 0x2E }
};

extern "C" const __declspec(selectany) GUID IID_IAxWinAmbientDispatch = { // 0x006FAF4C
    0xB6EA2051,
    0x48A,
    0x11D1,
    { 0x82, 0xB9, 0x00, 0xC0, 0x4F, 0xB9, 0x94, 0x2E }
};

extern "C" const __declspec(selectany) GUID IID_IInternalConnection = { // 0x006FAF5C
    0x72AD0770,
    0x6A9F,
    0x11D1,
    { 0xBC, 0xEC, 0x00, 0x60, 0x08, 0x8F, 0x44, 0x4E }
};

extern "C" const __declspec(selectany) GUID IID_IDocHostUIHandlerDispatch = { // 0x006FAF6C
    0x425B5AF0,
    0x65F1,
    0x11D1,
    { 0x96, 0x11, 0x00, 0x00, 0xF8, 0x1E, 0x0D, 0x0D }
};

extern "C" const __declspec(selectany) GUID IID_IAxWinHostWindowLic = { // 0x006FAF7C
    0x3935BDA8,
    0x4ED9,
    0x495C,
    { 0x86, 0x50, 0xE0, 0x1F, 0xC1, 0xE3, 0x8A, 0x4B }
};

extern "C" const __declspec(selectany) GUID IID_IAxWinAmbientDispatchEx = { // 0x006FAF8C
    0xB2D0778B,
    0xAC99,
    0x4C58,
    { 0xA5, 0xC8, 0xE7, 0x72, 0x4E, 0x53, 0x16, 0xB5 }
};

__declspec(selectany) const char* const ATL::CRegParser::szStringVal = "S"; // 0x006FAF9C

__declspec(selectany) const char* const ATL::CRegParser::multiszStringVal = "M"; // 0x006FAFA0

__declspec(selectany) const char* const ATL::CRegParser::szDwordVal = "D"; // 0x006FAFA4

__declspec(selectany) const char* const ATL::CRegParser::szBinaryVal = "B"; // 0x006FAFA8

__declspec(selectany) const char* const ATL::CRegParser::szValToken = "Val"; // 0x006FAFAC

__declspec(selectany) const char* const ATL::CRegParser::szForceRemove = "ForceRemove"; // 0x006FAFB0

__declspec(selectany) const char* const ATL::CRegParser::szNoRemove = "NoRemove"; // 0x006FAFB4

__declspec(selectany) const char* const ATL::CRegParser::szDelete = "Delete"; // 0x006FAFB8

__declspec(selectany) const int ATL::CRegParser::MAX_VALUE = 4096; // 0x006FAFBC

__declspec(selectany) const int ATL::CRegParser::MAX_TYPE = 4096; // 0x006FAFC0

__declspec(selectany) const char* const ATL::CRegParser::rgszNeverDelete[12] = { // 0x006FAFC4
    "AppID",
    "CLSID",
    "Component Categories",
    "FileType",
    "Interface",
    "Hardware",
    "Mime",
    "SAM",
    "SECURITY",
    "SYSTEM",
    "Software",
    "TypeLib"
};

__declspec(selectany) const int ATL::CRegParser::cbNeverDelete = 12; // 0x006FAFF4

extern "C" const char gData_006FB130[28] = "Failed to lock dest surface"; // 0x006FB130
#pragma comment(linker, "/alternatename:_gszFailedToLockDest=_gData_006FB130")

extern "C" const char gData_006FB14C[32] = "Failed to lock source surface"; // 0x006FB14C
#pragma comment(linker, "/alternatename:_gszFailedToLockSource=_gData_006FB14C")

extern "C" const unsigned char gData_006FB77B[1] = { 0 }; // 0x006FB77B

extern "C" const char gData_006FB77C[48] = "Create 3D HAL Device (mode enumeration) failed!"; // 0x006FB77C
#pragma comment(linker, "/alternatename:?gszCreateHalDeviceFailed@@3QBDB=_gData_006FB77C")

extern "C" const char gData_006FB7AC[48] = "GetAttachedSurface (mode enumeration) failed!"; // 0x006FB7AC
#pragma comment(linker, "/alternatename:?gszAttached@@3QBDB=_gData_006FB7AC")

extern "C" const char gData_006FB7DC[52] = "CreateSurface (primary, mode enumeration) failed!"; // 0x006FB7DC
#pragma comment(linker, "/alternatename:?gszPrimary@@3QBDB=_gData_006FB7DC")

extern "C" const char gData_006FB810[44] = "SetDisplayMode (mode enumeration) failed!"; // 0x006FB810
#pragma comment(linker, "/alternatename:?gszSetDisplayModeFailed@@3QBDB=_gData_006FB810")

extern "C" const char gData_006FB83C[48] = "SetCooperativeLevel (mode enumeration) failed!"; // 0x006FB83C
#pragma comment(linker, "/alternatename:?gszCoop@@3QBDB=_gData_006FB83C")

extern "C" const char gData_006FB86C[56] = "***** Exceeded Maximum Display Mode Count (%d >= %d)"; // 0x006FB86C
#pragma comment(linker, "/alternatename:?gszTooMany@@3QBDB=_gData_006FB86C")

extern "C" const char gData_006FB8A4[48] = " ** Couldn't clean up sEnumerateD3DDevices ** "; // 0x006FB8A4
#pragma comment(linker, "/alternatename:?gszEnumD3DCleanupFailed@@3QBDB=_gData_006FB8A4")

extern "C" const char gData_006FB8D4[52] = " ** Caught a failure in sEnumerateD3DDevices ** "; // 0x006FB8D4
#pragma comment(linker, "/alternatename:?gszEnumD3DCaughtFailure@@3QBDB=_gData_006FB8D4")

extern "C" const char gData_006FB908[32] = "\t\tDoes not support triangles!"; // 0x006FB908
#pragma comment(linker, "/alternatename:?gszNoTriangleSupport@@3QBDB=_gData_006FB908")

extern "C" const char gData_006FB928[40] = "\t\tPassed requirements for Diablo II."; // 0x006FB928
#pragma comment(linker, "/alternatename:?gszPassedRequirements@@3QBDB=_gData_006FB928")

extern "C" const char gData_006FB950[60] = "\t\tDoes not support any of the necessary texture formats!"; // 0x006FB950
#pragma comment(linker, "/alternatename:?gszNoTextureFormats@@3QBDB=_gData_006FB950")

extern "C" const char gData_006FB98C[28] = "\t\tSupports 1555 textures."; // 0x006FB98C
#pragma comment(linker, "/alternatename:?gszSupports1555Textures@@3QBDB=_gData_006FB98C")

extern "C" const char gData_006FB9A8[28] = "EnumTextureFormats() failed"; // 0x006FB9A8
#pragma comment(linker, "/alternatename:?gszEnumTextureFormatsFailed@@3QBDB=_gData_006FB9A8")

extern "C" const char gData_006FB9C4[48] = "\t\t\tDoes not support texturing from AGP memory."; // 0x006FB9C4
#pragma comment(linker, "/alternatename:?gszNoAgpTexturing@@3QBDB=_gData_006FB9C4")

extern "C" const char gData_006FB9F4[40] = "\t\t\tAGP Total= %2.3f MB, Free= %2.3f MB"; // 0x006FB9F4
#pragma comment(linker, "/alternatename:?gszAgpMemoryFormat@@3QBDB=_gData_006FB9F4")

extern "C" const char gData_006FBA1C[44] = "Failed to get available AGP texture memory"; // 0x006FBA1C
#pragma comment(linker, "/alternatename:?gszAgpMemoryFailed@@3QBDB=_gData_006FBA1C")

extern "C" const char gData_006FBA48[44] = "\t\t\tLocal Total= %2.3f MB, Free= %2.3f MB"; // 0x006FBA48
#pragma comment(linker, "/alternatename:?gszLocalMemoryFormat@@3QBDB=_gData_006FBA48")

extern "C" const char gData_006FBA74[48] = "Failed to get available local texture memory"; // 0x006FBA74
#pragma comment(linker, "/alternatename:?gszLocalMemoryFailed@@3QBDB=_gData_006FBA74")

extern "C" const char gData_006FBAA4[52] = "\t\tTexture Memory Total= %2.3f MB, Free= %2.3f MB"; // 0x006FBAA4
#pragma comment(linker, "/alternatename:?gszTextureMemoryFormat@@3QBDB=_gData_006FBAA4")

extern "C" const char gData_006FBAD8[40] = "Failed to get available texture memory"; // 0x006FBAD8
#pragma comment(linker, "/alternatename:?gszTextureMemoryFailed@@3QBDB=_gData_006FBAD8")

extern "C" const char gData_006FBB00[48] = "\t\tVideo Memory Total= %2.3f MB, Free= %2.3f MB"; // 0x006FBB00
#pragma comment(linker, "/alternatename:?gszVideoMemoryFormat@@3QBDB=_gData_006FBB00")

extern "C" const char gData_006FBB30[32] = "\t\tDoesn't support mipmapping."; // 0x006FBB30
#pragma comment(linker, "/alternatename:?gszNoMipmapping@@3QBDB=_gData_006FBB30")

extern "C" const char gData_006FBB50[28] = "\t\tRequires square textures!"; // 0x006FBB50
#pragma comment(linker, "/alternatename:?gszRequiresSquareTextures@@3QBDB=_gData_006FBB50")

extern "C" const char gData_006FBB6C[52] = "\t\tDoes not support perspective correct textures!"; // 0x006FBB6C
#pragma comment(linker, "/alternatename:?gszNoPerspectiveTextures@@3QBDB=_gData_006FBB6C")

extern "C" const char gData_006FBBA0[40] = "\t\tSupports non-power of two textures."; // 0x006FBBA0
#pragma comment(linker, "/alternatename:?gszSupportsNonPow2Textures@@3QBDB=_gData_006FBBA0")

extern "C" const char gData_006FBBC8[44] = "\t\tDoesn't support textures in video memory!"; // 0x006FBBC8
#pragma comment(linker, "/alternatename:?gszNoVideoMemoryTextures@@3QBDB=_gData_006FBBC8")

extern "C" const char gData_006FBBF4[32] = "Failed to get D3D device caps"; // 0x006FBBF4
#pragma comment(linker, "/alternatename:?gszGetD3DDeviceCapsFailed@@3QBDB=_gData_006FBBF4")

extern "C" const char gData_006FBC14[48] = "\t\tDoesn't appear to have hardware 3D support"; // 0x006FBC14
#pragma comment(linker, "/alternatename:?gszNoHardware3D@@3QBDB=_gData_006FBC14")

extern "C" const char gData_006FBC44[32] = "\t\tSupports gamma calibration."; // 0x006FBC44
#pragma comment(linker, "/alternatename:?gszSupportsGammaCalibration@@3QBDB=_gData_006FBC44")

extern "C" const char gData_006FBC64[36] = "\t\tDoesn't support gamma control."; // 0x006FBC64
#pragma comment(linker, "/alternatename:?gszNoGammaControl@@3QBDB=_gData_006FBC64")

extern "C" const char gData_006FBC88[32] = "\t\tDoesn't appear to support 3D."; // 0x006FBC88
#pragma comment(linker, "/alternatename:?gszNo3DSupport@@3QBDB=_gData_006FBC88")

extern "C" const char gData_006FBCA8[24] = "Failed to get DD4 Caps"; // 0x006FBCA8
#pragma comment(linker, "/alternatename:?gszGetDD4CapsFailed@@3QBDB=_gData_006FBCA8")

extern "C" const char gData_006FBCC0[36] = "Failed to get backbuffer surface"; // 0x006FBCC0
#pragma comment(linker, "/alternatename:?gszGetBackbufferFailed@@3QBDB=_gData_006FBCC0")

extern "C" const char gData_006FBCE4[36] = "Failed to create primary surface"; // 0x006FBCE4
#pragma comment(linker, "/alternatename:?gszCreatePrimarySurfaceFailed@@3QBDB=_gData_006FBCE4")

extern "C" const char gData_006FBD08[28] = "IDirectDraw4_SetDisplayMode"; // 0x006FBD08
#pragma comment(linker, "/alternatename:?gszSetDisplayModeCall@@3QBDB=_gData_006FBD08")

extern "C" const char gData_006FBD24[56] = "\t\tCouldn't find valid display mode for game screens."; // 0x006FBD24
#pragma comment(linker, "/alternatename:?gszNoGameDisplayMode@@3QBDB=_gData_006FBD24")

extern "C" const char gData_006FBD5C[64] = "\t\tCouldn't find valid display mode for user interface screens."; // 0x006FBD5C
#pragma comment(linker, "/alternatename:?gszNoUIDisplayMode@@3QBDB=_gData_006FBD5C")

extern "C" const char gData_006FBD9C[32] = "\t\tSupports 24 bit cutscenes."; // 0x006FBD9C
#pragma comment(linker, "/alternatename:?gszSupports24BitCutscenes@@3QBDB=_gData_006FBD9C")

extern "C" const char gData_006FBDBC[32] = "\t\tSupports 32 bit cutscenes."; // 0x006FBDBC
#pragma comment(linker, "/alternatename:?gszSupports32BitCutscenes@@3QBDB=_gData_006FBDBC")

extern "C" const char gData_006FBDDC[44] = "\t\tCouldn't find any valid display modes."; // 0x006FBDDC
#pragma comment(linker, "/alternatename:?gszNoValidDisplayModes@@3QBDB=_gData_006FBDDC")

extern "C" const char gData_006FBE08[32] = "IDirectDraw_EnumDisplayModes"; // 0x006FBE08
#pragma comment(linker, "/alternatename:?gszEnumDisplayModesCall@@3QBDB=_gData_006FBE08")

extern "C" const char gData_006FBE28[28] = "SetCooperativeLevel failed"; // 0x006FBE28
#pragma comment(linker, "/alternatename:?gszSetCooperativeLevelFailed@@3QBDB=_gData_006FBE28")

extern "C" const char gData_006FBE44[28] = "Failed to get D3D interface"; // 0x006FBE44
#pragma comment(linker, "/alternatename:?gszGetD3DInterfaceFailed@@3QBDB=_gData_006FBE44")

extern "C" const char gData_006FBE60[40] = "\t\tVendorID = 0x%08x, DeviceID = 0x%08x"; // 0x006FBE60
#pragma comment(linker, "/alternatename:?gszVendorDeviceIdFormat@@3QBDB=_gData_006FBE60")

extern "C" const char gData_006FBE88[32] = "\tChecking capabilities of %s..."; // 0x006FBE88
#pragma comment(linker, "/alternatename:?gszCheckingCapabilitiesFormat@@3QBDB=_gData_006FBE88")

extern "C" const char gData_006FBEA8[48] = "Enumeration failed to get DirectDraw4 interface"; // 0x006FBEA8
#pragma comment(linker, "/alternatename:?gszEnumGetDirectDraw4Failed@@3QBDB=_gData_006FBEA8")

extern "C" const char gData_006FBED8[36] = "Enumeration DirectDrawCreate failed"; // 0x006FBED8
#pragma comment(linker, "/alternatename:?gszEnumDirectDrawCreateFailed@@3QBDB=_gData_006FBED8")

extern "C" const char gData_006FBEFC[48] = "***** Exceeded Maximum Display Count (%d >= %d)"; // 0x006FBEFC
#pragma comment(linker, "/alternatename:?gszMaxDisplayCountFormat@@3QBDB=_gData_006FBEFC")

extern "C" const char gData_006FC010[28] = "SetCurrentViewport failed!"; // 0x006FC010
#pragma comment(linker, "/alternatename:?gCurrentViewError@@3QBDB=_gData_006FC010")

extern "C" const char gData_006FC02C[20] = "SetViewport failed!"; // 0x006FC02C
#pragma comment(linker, "/alternatename:?gSetViewError@@3QBDB=_gData_006FC02C")

extern "C" const char gData_006FC040[36] = "Failed to add viewport to device!"; // 0x006FC040
#pragma comment(linker, "/alternatename:?gAddViewError@@3QBDB=_gData_006FC040")

extern "C" const char gData_006FC064[28] = "Failed to create viewport!"; // 0x006FC064
#pragma comment(linker, "/alternatename:?gCreateViewError@@3QBDB=_gData_006FC064")

extern "C" const char gData_006FC080[32] = "Failed to create D3D device!"; // 0x006FC080
#pragma comment(linker, "/alternatename:?gDeviceError@@3QBDB=_gData_006FC080")

extern "C" const char gData_006FC0A0[36] = "Failed to get original gamma ramp"; // 0x006FC0A0
#pragma comment(linker, "/alternatename:?gGammaError@@3QBDB=_gData_006FC0A0")

extern "C" const char gData_006FC0C4[40] = "Failed to get gamma control interface!"; // 0x006FC0C4
#pragma comment(linker, "/alternatename:?gGammaInterfaceError@@3QBDB=_gData_006FC0C4")

extern "C" const char gData_006FC0EC[28] = "GetAttachedSurface failed!"; // 0x006FC0EC
#pragma comment(linker, "/alternatename:?gAttachedError@@3QBDB=_gData_006FC0EC")

extern "C" const char gData_006FC108[24] = "CreateSurface failed!"; // 0x006FC108
#pragma comment(linker, "/alternatename:?gSurfaceError@@3QBDB=_gData_006FC108")

extern "C" const unsigned char gData_006FF478[16] = { // 0x006FF478
    0x02, 0x15, 0x28, 0x93, 0xF8, 0x8C, 0xD0, 0x11, 0x89, 0xAB, 0x00, 0xA0, 0xC9, 0x05, 0x41, 0x29
};
#pragma comment(linker, "/alternatename:?gabIidTexture@@3QBEB=_gData_006FF478")

extern "C" const unsigned char gData_006FF488[144] = { // 0x006FF488
    0xE0, 0xD9, 0xDC, 0x2C, 0xA0, 0x25, 0xCF, 0x11, 0xA3, 0x1A, 0x00, 0xAA, 0x00, 0xB9, 0x33, 0x56,
    0x79, 0x9E, 0x04, 0xF5, 0x61, 0x48, 0xD2, 0x11, 0xA4, 0x07, 0x00, 0xA0, 0xC9, 0x06, 0x29, 0xA8,
    0x60, 0x3B, 0xAB, 0xB0, 0xD7, 0x33, 0xD1, 0x11, 0xA9, 0x81, 0x00, 0xC0, 0x4F, 0xD7, 0xB1, 0x74,
    0x01, 0x15, 0x28, 0x93, 0xF8, 0x8C, 0xD0, 0x11, 0x89, 0xAB, 0x00, 0xA0, 0xC9, 0x05, 0x41, 0x29,
    0x00, 0x88, 0x10, 0x64, 0x7D, 0x95, 0xD0, 0x11, 0x89, 0xAB, 0x00, 0xA0, 0xC9, 0x05, 0x41, 0x29,
    0x78, 0x9E, 0x04, 0xF5, 0x61, 0x48, 0xD2, 0x11, 0xA4, 0x07, 0x00, 0xA0, 0xC9, 0x06, 0x29, 0xA8,
    0x22, 0xDF, 0x67, 0x87, 0xCC, 0xBA, 0xD1, 0x11, 0x89, 0x69, 0x00, 0xA0, 0xC9, 0x06, 0x29, 0xA8,
    0x43, 0x66, 0x93, 0x50, 0xE9, 0x13, 0xD1, 0x11, 0x89, 0xAA, 0x00, 0xA0, 0xC9, 0x05, 0x41, 0x29,
    0xA1, 0x49, 0x19, 0x88, 0xF3, 0xD6, 0xD0, 0x11, 0x89, 0xAB, 0x00, 0xA0, 0xC9, 0x05, 0x41, 0x29
};

extern "C" const unsigned int gData_006FF518[4] = { 0x84E63DE0, 0x11CF46AA, 0x00006F81, 0x6E1520C0 }; // 0x006FF518
#pragma comment(linker, "/alternatename:?gadwHalGuid@@3QBIB=_gData_006FF518")

extern "C" const unsigned char gData_006FF528[48] = { // 0x006FF528
    0x60, 0x5C, 0x66, 0xA4, 0x73, 0x26, 0xCF, 0x11, 0xA3, 0x1A, 0x00, 0xAA, 0x00, 0xB9, 0x33, 0x56,
    0x20, 0x6B, 0x08, 0xF2, 0x9F, 0x25, 0xCF, 0x11, 0xA3, 0x1A, 0x00, 0xAA, 0x00, 0xB9, 0x33, 0x56,
    0x77, 0x9E, 0x04, 0xF5, 0x61, 0x48, 0xD2, 0x11, 0xA4, 0x07, 0x00, 0xA0, 0xC9, 0x06, 0x29, 0xA8
};

extern "C" const D2GuidStrc gData_006FF558 = { 0xBB223240, 0xE72B, 0x11D0, { 0xA9, 0xB4, 0x00, 0xAA, 0x00, 0xC0, 0x99, 0x3E } }; // 0x006FF558
#pragma comment(linker, "/alternatename:?gtIidDirect3D3@@3UD2GuidStrc@@B=_gData_006FF558")

extern "C" const unsigned char gData_006FF568[608] = { // 0x006FF568
    0xC1, 0x1E, 0xAE, 0x6A, 0x2A, 0x66, 0xD0, 0x11, 0x88, 0x9D, 0x00, 0xAA, 0x00, 0xBB, 0xB7, 0x6A,
    0x80, 0x00, 0xBA, 0x3B, 0x21, 0x24, 0xCF, 0x11, 0xA3, 0x1A, 0x00, 0xAA, 0x00, 0xB9, 0x33, 0x56,
    0x60, 0xF1, 0x2C, 0x33, 0x61, 0xDA, 0xCF, 0x11, 0x9B, 0x06, 0x00, 0xA0, 0xC9, 0x03, 0xA3, 0xB8,
    0x60, 0xA5, 0x52, 0x13, 0x61, 0xDA, 0xCF, 0x11, 0x9B, 0x06, 0x00, 0xA0, 0xC9, 0x03, 0xA3, 0xB8,
    0xA0, 0x26, 0xA3, 0xFC, 0x60, 0xDA, 0xCF, 0x11, 0x9B, 0x06, 0x00, 0xA0, 0xC9, 0x03, 0xA3, 0xB8,
    0xE0, 0x77, 0x9C, 0xE0, 0x60, 0xDA, 0xCF, 0x11, 0x9B, 0x06, 0x00, 0xA0, 0xC9, 0x03, 0xA3, 0xB8,
    0xE0, 0x02, 0x7A, 0xA0, 0x60, 0xDA, 0xCF, 0x11, 0x9B, 0x06, 0x00, 0xA0, 0xC9, 0x03, 0xA3, 0xB8,
    0x20, 0x32, 0x78, 0x92, 0x60, 0xDA, 0xCF, 0x11, 0x9B, 0x06, 0x00, 0xA0, 0xC9, 0x03, 0xA3, 0xB8,
    0x80, 0x99, 0xF3, 0x54, 0x60, 0xDA, 0xCF, 0x11, 0x9B, 0x06, 0x00, 0xA0, 0xC9, 0x03, 0xA3, 0xB8,
    0x94, 0xFB, 0x55, 0xA6, 0x89, 0x05, 0x57, 0x4E, 0xB3, 0x33, 0x56, 0x7A, 0x89, 0x46, 0x8C, 0x88,
    0xE0, 0x93, 0x6D, 0xB3, 0x43, 0x2B, 0xCF, 0x11, 0xA2, 0xDE, 0x00, 0xAA, 0x00, 0xB9, 0x33, 0x56,
    0x60, 0x27, 0x14, 0x6C, 0x33, 0xA7, 0xCE, 0x11, 0xA5, 0x21, 0x00, 0x20, 0xAF, 0x0B, 0xE5, 0x60,
    0xA0, 0x00, 0xA0, 0x0A, 0x04, 0xF4, 0xD9, 0x11, 0xBD, 0x7A, 0x00, 0x10, 0xDC, 0x4F, 0x8F, 0x81,
    0xAC, 0x00, 0xA0, 0x0A, 0x04, 0xF4, 0xD9, 0x11, 0xBD, 0x7A, 0x00, 0x10, 0xDC, 0x4F, 0x8F, 0x81,
    0xAB, 0x00, 0xA0, 0x0A, 0x04, 0xF4, 0xD9, 0x11, 0xBD, 0x7A, 0x00, 0x10, 0xDC, 0x4F, 0x8F, 0x81,
    0xAA, 0x00, 0xA0, 0x0A, 0x04, 0xF4, 0xD9, 0x11, 0xBD, 0x7A, 0x00, 0x10, 0xDC, 0x4F, 0x8F, 0x81,
    0x30, 0xAF, 0x0B, 0x88, 0x30, 0xB0, 0xD0, 0x11, 0x8E, 0xA7, 0x00, 0x60, 0x97, 0x97, 0xEA, 0x5B,
    0x00, 0x2F, 0x6B, 0x40, 0x5A, 0x3E, 0xD1, 0x11, 0xB6, 0x40, 0x00, 0xAA, 0x00, 0xA1, 0xF9, 0x6A,
    0xDE, 0xEC, 0xE9, 0x6F, 0x89, 0xDF, 0xD1, 0x11, 0x9D, 0xB0, 0x00, 0x60, 0x08, 0x27, 0x71, 0xBA,
    0x40, 0x2B, 0x12, 0xB1, 0xA5, 0x5D, 0xD1, 0x11, 0x8F, 0xCF, 0x00, 0xC0, 0x4F, 0xC2, 0x9B, 0x4E,
    0xA0, 0xFF, 0x04, 0x2E, 0xE4, 0x98, 0xD1, 0x11, 0x8C, 0xE1, 0x00, 0xA0, 0xC9, 0x06, 0x29, 0xA8,
    0xB6, 0x61, 0xF8, 0x97, 0xA1, 0x60, 0xD1, 0x11, 0x8C, 0xD0, 0x00, 0xA0, 0xC9, 0x06, 0x29, 0xA8,
    0xE2, 0xE8, 0xB0, 0xF0, 0x97, 0x5F, 0xD1, 0x11, 0x8C, 0xD0, 0x00, 0xA0, 0xC9, 0x06, 0x29, 0xA8,
    0x04, 0x28, 0x79, 0x9D, 0xA8, 0x5F, 0xD1, 0x11, 0x8C, 0xD0, 0x00, 0xA0, 0xC9, 0x06, 0x29, 0xA8,
    0x72, 0x84, 0x5C, 0xE0, 0xD4, 0x51, 0xD1, 0x11, 0x8C, 0xCE, 0x00, 0xA0, 0xC9, 0x06, 0x29, 0xA8,
    0x9C, 0x16, 0x28, 0xF8, 0xE8, 0xA8, 0xD2, 0x11, 0xA1, 0xF2, 0x00, 0xA0, 0xC9, 0x83, 0xEA, 0xF6,
    0x66, 0x04, 0x8A, 0x3B, 0x69, 0xF2, 0xD1, 0x11, 0x88, 0x0B, 0x00, 0xC0, 0x4F, 0xD9, 0x30, 0xC5,
    0x80, 0x98, 0x86, 0x93, 0xCF, 0x36, 0xD1, 0x11, 0x9B, 0x1B, 0x00, 0xAA, 0x00, 0xBB, 0xB8, 0xAE,
    0x80, 0x1F, 0xE4, 0x7D, 0x93, 0x9D, 0xD0, 0x11, 0x89, 0xAB, 0x00, 0xA0, 0xC9, 0x05, 0x41, 0x29,
    0x40, 0x75, 0xAA, 0xFF, 0xA8, 0x7A, 0xD0, 0x11, 0x9B, 0x06, 0x00, 0xA0, 0xC9, 0x03, 0xA3, 0xB8,
    0x00, 0x38, 0x86, 0x80, 0x06, 0x6B, 0xD0, 0x11, 0x9B, 0x06, 0x00, 0xA0, 0xC9, 0x03, 0xA3, 0xB8,
    0x80, 0xFA, 0xC4, 0x86, 0x84, 0x8D, 0xD0, 0x11, 0x94, 0xE8, 0x00, 0xC0, 0x4F, 0xC3, 0x41, 0x37,
    0x30, 0x12, 0xF4, 0xDD, 0x0A, 0xEC, 0xD0, 0x11, 0xA9, 0xB6, 0x00, 0xAA, 0x00, 0xC0, 0x99, 0x3E,
    0xE1, 0x84, 0xA5, 0x0B, 0xB6, 0x70, 0xD0, 0x11, 0x88, 0x9D, 0x00, 0xAA, 0x00, 0xBB, 0xB7, 0x6A,
    0xC3, 0x0C, 0xD6, 0xEF, 0xE7, 0x49, 0xD0, 0x11, 0x88, 0x9D, 0x00, 0xAA, 0x00, 0xBB, 0xB7, 0x6A,
    0xC2, 0x0C, 0xD6, 0xEF, 0xE7, 0x49, 0xD0, 0x11, 0x88, 0x9D, 0x00, 0xAA, 0x00, 0xBB, 0xB7, 0x6A,
    0xC1, 0x0C, 0xD6, 0xEF, 0xE7, 0x49, 0xD0, 0x11, 0x88, 0x9D, 0x00, 0xAA, 0x00, 0xBB, 0xB7, 0x6A,
    0xC0, 0x0C, 0xD6, 0xEF, 0xE7, 0x49, 0xD0, 0x11, 0x88, 0x9D, 0x00, 0xAA, 0x00, 0xBB, 0xB7, 0x6A
};

extern "C" const Guid gData_006FF7C8 = { 0x69C11C3E, 0xB46B, 0x11D1, { 0xAD, 0x7A, 0x00, 0xC0, 0x4F, 0xC2, 0x9B, 0x4E } }; // 0x006FF7C8
#pragma comment(linker, "/alternatename:?gGammaGuid@@3UGuid@@B=_gData_006FF7C8")

extern "C" const unsigned char gData_006FF7D8[256] = { // 0x006FF7D8
    0xE0, 0x0E, 0x9F, 0x4B, 0x7E, 0x0D, 0xD0, 0x11, 0x9B, 0x06, 0x00, 0xA0, 0xC9, 0x03, 0xA3, 0xB8,
    0x85, 0xDB, 0x14, 0x6C, 0x33, 0xA7, 0xCE, 0x11, 0xA5, 0x21, 0x00, 0x20, 0xAF, 0x0B, 0xE5, 0x60,
    0x84, 0xDB, 0x14, 0x6C, 0x33, 0xA7, 0xCE, 0x11, 0xA5, 0x21, 0x00, 0x20, 0xAF, 0x0B, 0xE5, 0x60,
    0x7E, 0x47, 0x3C, 0xC0, 0x19, 0x65, 0xD1, 0x11, 0x8C, 0x52, 0x00, 0xC0, 0x4F, 0xD9, 0x30, 0xC5,
    0x1E, 0x1F, 0x19, 0x51, 0x2B, 0x4F, 0xD1, 0x11, 0x8C, 0xC3, 0x00, 0xA0, 0xC9, 0x06, 0x29, 0xA8,
    0xFC, 0x7F, 0x0C, 0x73, 0x47, 0x53, 0xD1, 0x11, 0x8C, 0x4D, 0x00, 0xC0, 0x4F, 0xD9, 0x30, 0xC5,
    0x46, 0xBC, 0x43, 0xE0, 0x17, 0x53, 0xD1, 0x11, 0x8C, 0x4D, 0x00, 0xC0, 0x4F, 0xD9, 0x30, 0xC5,
    0x88, 0xC4, 0xB2, 0x89, 0xF4, 0x4A, 0xD1, 0x11, 0x8C, 0x4C, 0x00, 0xC0, 0x4F, 0xD9, 0x30, 0xC5,
    0x90, 0x47, 0xDC, 0xB9, 0xF1, 0x4A, 0xD1, 0x11, 0x8C, 0x4C, 0x00, 0xC0, 0x4F, 0xD9, 0x30, 0xC5,
    0x96, 0x8E, 0xAB, 0x1B, 0xFE, 0x9C, 0xE3, 0x4C, 0xBC, 0x72, 0xD7, 0xE9, 0xE9, 0x9A, 0x21, 0x75,
    0x80, 0x5A, 0x67, 0x06, 0x9B, 0x3B, 0xD2, 0x11, 0xB9, 0x2F, 0x00, 0x60, 0x97, 0x97, 0xEA, 0x5B,
    0x30, 0x86, 0x2B, 0x0B, 0x35, 0xAD, 0xD0, 0x11, 0x8E, 0xA6, 0x00, 0x60, 0x97, 0x97, 0xEA, 0x5B,
    0x00, 0x4E, 0x04, 0xDA, 0xB2, 0x69, 0xD0, 0x11, 0xA1, 0xD5, 0x00, 0xAA, 0x00, 0xB8, 0xDF, 0xBB,
    0x85, 0x58, 0x80, 0x57, 0xEC, 0x6E, 0xCF, 0x11, 0x94, 0x41, 0xA8, 0x23, 0x03, 0xC1, 0x0E, 0x27,
    0x81, 0xDB, 0x14, 0x6C, 0x33, 0xA7, 0xCE, 0x11, 0xA5, 0x21, 0x00, 0x20, 0xAF, 0x0B, 0xE5, 0x60,
    0xC0, 0x5E, 0xE6, 0x15, 0x9C, 0x3B, 0xD2, 0x11, 0xB9, 0x2F, 0x00, 0x60, 0x97, 0x97, 0xEA, 0x5B
};

extern "C" const D2GuidStrc gData_006FF8D8 = { 0x9C59509A, 0x39BD, 0x11D1, { 0x8C, 0x4A, 0x00, 0xC0, 0x4F, 0xD9, 0x30, 0xC5 } }; // 0x006FF8D8
#pragma comment(linker, "/alternatename:?gtIidDirectDraw4@@3UD2GuidStrc@@B=_gData_006FF8D8")

extern "C" const unsigned char gData_006FF8E8[88] = { // 0x006FF8E8
    0xE0, 0xF3, 0xA6, 0xB3, 0x43, 0x2B, 0xCF, 0x11, 0xA2, 0xDE, 0x00, 0xAA, 0x00, 0xB9, 0x33, 0x56,
    0x80, 0xDB, 0x14, 0x6C, 0x33, 0xA7, 0xCE, 0x11, 0xA5, 0x21, 0x00, 0x20, 0xAF, 0x0B, 0xE5, 0x60,
    0xA0, 0x17, 0x38, 0x59, 0xB3, 0x7D, 0xCF, 0x11, 0xA2, 0xDE, 0x00, 0xAA, 0x00, 0xB9, 0x33, 0x56,
    0x96, 0x51, 0x30, 0x3C, 0xDB, 0x50, 0xD3, 0x11, 0x9C, 0xFE, 0x00, 0xC0, 0x4F, 0xD9, 0x30, 0xC5,
    0xE0, 0x0E, 0xB7, 0xD7, 0x40, 0x43, 0xCF, 0x11, 0xB0, 0x63, 0x00, 0x20, 0xAF, 0xC2, 0xCD, 0x35,
    0x10, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00
};

unsigned int ganWidths[2] = { 640, 800 }; // 0x0074C000

extern "C" unsigned char gData_0074C008[8] = { 0x20, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; // 0x0074C008

unsigned int ganHeights[2] = { 480, 600 }; // 0x0074C010

extern "C" unsigned char gData_0074C018[8] = { 0x58, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; // 0x0074C018

int gnGammaScale = 100; // 0x0074C020

D2PixelFormat006B1B60Strc gtWantedFormat = { 32, 0x41, 0, 0x10, 0x7C00, 0x3E0, 0x1F, 0x8000 }; // 0x0074C024

char gszEnumerationClass[20] = "Enumeration Class"; // 0x0074C044

char gszEnumerationWindow[24] = "Direct3D Enumeration"; // 0x0074C058

extern "C" void __cdecl D3DSMACK_CloseSmacker(); // 0x006B9BB0
extern "C" void __cdecl D3DSMACK_DecodeSmacker(); // 0x006BA010
extern "C" void __cdecl D3DSMACK_PlaySmacker(); // 0x006BA390
extern "C" void __cdecl D3DSPRITE_CelDrawHilight(); // 0x006B7090
extern "C" void __cdecl D3DSPRITE_DebugFillBackBuffer(); // 0x006B7100
extern "C" void __cdecl D3DSPRITE_DrawFlatSprite(); // 0x006B6730
extern "C" void __cdecl D3DSPRITE_DrawSpriteClipped(); // 0x006B6EE0
extern "C" void __cdecl D3DSPRITE_DrawSpriteRows(); // 0x006B6C90
extern "C" void __cdecl D3DSPRITE_DrawSpriteShadow(); // 0x006B7000
extern "C" void __cdecl sub_006B7630_DrawTextV(); // 0x006B7630
extern "C" void __cdecl sub_006B76C0_Nop(); // 0x006B76C0
extern "C" void __cdecl sub_006B77B0_Call(); // 0x006B77B0
extern "C" void __cdecl sub_006B7980_DrawRectangle(); // 0x006B7980
extern "C" void __cdecl sub_006B7B30_DrawLine(); // 0x006B7B30
extern "C" void __cdecl sub_006B7C90_DrawDiamond(); // 0x006B7C90
extern "C" void __cdecl sub_006B7D80_DrawRectangle(); // 0x006B7D80
extern "C" void __cdecl sub_006B7ED0_CallRect(); // 0x006B7ED0
extern "C" void __cdecl sub_006B7F20_CallSquare(); // 0x006B7F20
extern "C" void __cdecl sub_006B86F0_DrawShadow(); // 0x006B86F0
extern "C" void __cdecl sub_006B8E60_DrawRelay(); // 0x006B8E60
extern "C" void __cdecl sub_006B8E90_DrawWallTile(); // 0x006B8E90
extern "C" void __cdecl sub_006B9170_DrawGrid(); // 0x006B9170
extern "C" void __cdecl sub_006B9850_SetOrigin(); // 0x006B9850
extern "C" void __cdecl sub_006B9860_Project(); // 0x006B9860
extern "C" void __cdecl sub_006B9910_ProjectPoint(); // 0x006B9910
extern "C" void __cdecl sub_006B9A00_ResetScale(); // 0x006B9A00
extern "C" void __cdecl D3DSPRITE_CelDraw(); // 0x006B6B40
extern "C" void __cdecl D3DSPRITE_CelDrawColor(); // 0x006B6BF0

extern const char gszCutscene[47] = "Failed to create primary surface for cutscenes"; // 0x006DE0F4

extern D2GraphicsInterfaceStrc gtD3DGraphicsInterface = { (int (__fastcall*)(void* hInstance))&D3DCORE_LoadVideoConfiguration, (int (__fastcall*)(D2GfxSettingsStrc* pSettings, const void* pHelpers))&D3DCORE_Init, (int (__fastcall*)())&D3DCORE_Close, (int (__fastcall*)(void* hWnd, int nResolutionMode))&D3DCORE_CreateSurface, (int (__fastcall*)())&D3DCORE_ReleaseWindow, (void (__fastcall*)(void* hWnd, int nResolutionMode, int nWindowState))&D3DCORE_PauseSurface, (int (__fastcall*)(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue))&D3DCORE_StartDraw, (int (__fastcall*)())&D3DCORE_EndDraw, (int (__fastcall*)())&D3DCORE_FlipPrimary, (int (__fastcall*)(void* hWnd, int nResolutionMode))&D3DCORE_ChangeRes, (int (__fastcall*)(unsigned char* pBuffer))&D3DCORE_GetBackBuffer, (int (__fastcall*)(int bActive, int bWindowed))&D3DCORE_ActivateWindow, (int (__fastcall*)(int nOption, int nValue))&D3DCORE_SetOption, (int (__fastcall*)())&D3DCORE_BeginCutScene, (void (__fastcall*)(const char* szFile, int nResolutionMode, void* pfFrame))&D3DCORE_OpenSmackCutscene, (int (__fastcall*)())&D3DCORE_CheckCutScene, (void (__fastcall*)(const char* szSmacker, unsigned char* pBuffer, int nVersion))&D3DSMACK_DecodeSmacker, (void (__fastcall*)(void* pContext))&D3DSMACK_PlaySmacker, (void (__fastcall*)(void* pContext))&D3DSMACK_CloseSmacker, (D2CacheStatsStrc* (__fastcall*)())&QSERVER_GetFloorCacheSize, (int (__fastcall*)(int* pWidth, int* pHeight))&D3DCORE_GetScreenSize, (void (__fastcall*)(int nScaleFactor))&D3DCORE_SetGlobalScale, (int (__fastcall*)(int nGamma))&D3DCORE_SetGamma, (int (__fastcall*)())&D3DCORE_GetMaskedFlags, (void (__fastcall*)(int nScaleX, int nScaleY))&sub_006B9850_SetOrigin, (void (__fastcall*)(int nPosX, int nPosY, int nBias, int* pXAdjust, int* pYAdjust))&sub_006B9860_Project, (void (__fastcall*)(int nPosX, int nPosY, int nAngle, int* pXAdjust, int* pYAdjust, int bOrder))&sub_006B9910_ProjectPoint, (void (__fastcall*)())&sub_006B9A00_ResetScale, (void (__fastcall*)(tagPALETTEENTRY* pPalette))&D3DCORE_SetPalette, (void (__fastcall*)(D2PaletteTableStrc* pPaletteTables))&D3DCORE_SetPaletteView, (void (__fastcall*)(int nRed, int nGreen, int nBlue))&sub_006B9710_SetColorComponents, (int (__fastcall*)(D2TileLibraryEntryStrc* pTile, D2GfxLightExStrc* pLight, int nPosX, int nPosY, int nWorldXpos, int nWorldYpos, unsigned char nAlpha, int nScreenPanels, void* pTileData))&sub_006B9170_DrawGrid, (void (__fastcall*)(D2GfxDataStrc* pData, int nPosX, int nPosY, unsigned int dwGamma, int eDrawMode, int nScreenMode, unsigned char* pPalette))&D3DSPRITE_DrawFlatSprite, (void (__fastcall*)(D2GfxDataStrc* pData, int nPosX, int nPosY, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette))&D3DSPRITE_CelDraw, (void (__fastcall*)(D2GfxDataStrc* pData, int nPosX, int nPosY, unsigned int dwGamma, int eDrawMode, int nGlobalPaletteShift))&D3DSPRITE_CelDrawColor, (void (__fastcall*)(D2GfxDataStrc* pData, int nPosX, int nPosY, int nSkipLines, int nDrawLines, int eDrawMode))&D3DSPRITE_DrawSpriteRows, (void (__fastcall*)(D2GfxDataStrc* pData, int nPosX, int nPosY))&D3DSPRITE_DrawSpriteShadow, (void (__fastcall*)(D2GfxDataStrc* pData, int nPosX, int nPosY, unsigned char nPaletteIndex))&D3DSPRITE_CelDrawHilight, (void (__fastcall*)(D2GfxDataStrc* pData, int nPosX, int nPosY, void* pCropRect, int eDrawMode))&D3DSPRITE_DrawSpriteClipped, (int (__fastcall*)(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels))&sub_006B8E90_DrawWallTile, (int (__fastcall*)(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels, unsigned char nAlpha))&sub_006B8E60_DrawRelay, (int (__fastcall*)(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, int eDrawMode, int nScreenPanels))&sub_006B86F0_DrawShadow, (void (__fastcall*)(tagRECT* pRect, unsigned char nPaletteIndex))&sub_006B7C90_DrawDiamond, (void (__fastcall*)(tagRECT* pRect, unsigned char nPaletteIndex))&sub_006B7D80_DrawRectangle, (void (__fastcall*)(tagRECT* pRect, unsigned char nPaletteIndex))&sub_006B7ED0_CallRect, (void (__fastcall*)(tagPOINT* pPoint, unsigned char nSize, unsigned char nPaletteIndex))&sub_006B7F20_CallSquare, (void (__fastcall*)(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode))&sub_006B77B0_Call, (void (__fastcall*)(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha))&sub_006B7980_DrawRectangle, (void (__fastcall*)(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha))&sub_006B7B30_DrawLine, (void (__fastcall*)(int bPartial))&sub_006B7F70_ClearTarget, (void (__fastcall*)(int nPosX, int nPosY, const char* szFormat, char* va))&sub_006B7630_DrawTextV, (void (__fastcall*)(unsigned int* pLight, unsigned int* pPlayerLight, int nPosX, int nPosY))&sub_006B76C0_Nop, (void (__fastcall*)(int nPosX, int nPosY))&D3DSPRITE_DebugFillBackBuffer, (void (__fastcall*)())&D3DCORE_ClearCaches }; // 0x0074BF28

extern "C" const char gszD3DCoreFile[18] = ".\\Src\\d3dCore.cpp"; // 0x006FC120
