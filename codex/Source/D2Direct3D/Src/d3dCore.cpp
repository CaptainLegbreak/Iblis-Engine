#include "D2Direct3D.h"

#include "D2DDrawTypes.h"

#include "D2Win32Types.h"
#include "D2D3DTypes.h"
#include "D2FogSystemInfo.h"

extern "C" __declspec(dllimport) int __stdcall lstrlenA(const char* sz); // 0x006CC154
extern "C" __declspec(dllimport) long __stdcall RegSetValueExA(void* hKey, const char* szValueName, unsigned long nReserved, unsigned long dwType, const unsigned char* pData, unsigned long cbData); // 0x006CC034
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey);
extern "C" __declspec(dllimport) long __stdcall RegCreateKeyExA(void* hKey, const char* lpSubKey, unsigned long Reserved, char* lpClass, unsigned long dwOptions, unsigned long samDesired, void* lpSecurityAttributes, void** phkResult, unsigned long* lpdwDisposition);

namespace Define_the_symbol__ATL_MIXED
{
// build: symbol ??0Thank_you@Define_the_symbol__ATL_MIXED@@QAE@XZ 0x006B1A00
// build: symbol ?sub_006B1A10_Nop@Thank_you@Define_the_symbol__ATL_MIXED@@UAEXXZ 0x006B1A10
struct Thank_you
{
    Thank_you() {}
    virtual void sub_006B1A10_Nop() {}
};
// build: symbol ?clash@Define_the_symbol__ATL_MIXED@@3UThank_you@1@A 0x0074C0C8
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

void __cdecl sub_006B1A30_ThrowAtlException(long error);

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

extern D2PixelFormat006B1B60Strc gtWantedFormat_0074C024; // 0x0074C024
extern const unsigned long gnFormatCap_006CE28C; // 0x006CE28C

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

extern const unsigned long gdwGammaMask; // 0x006CE278

extern const unsigned long gdwAgpMask; // 0x006CE26C

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

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char*, const char*, int); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09

extern "C" void* __cdecl memset(void*,int,unsigned int); // 0x00681EF0

extern "C" __declspec(dllimport) int __stdcall MoveWindow(void*,int,int,int,int,int); // 0x006CC444

void __fastcall D3DCORE_LogDDrawError(const char* szWhere, int hResult); // 0x006B20E0

void __fastcall D3DCORE_ShowD3DError(const char*,long); // 0x006B39B0

void __cdecl D3DCORE_ReleaseResources(); // 0x006B3320

void __cdecl sub_006B3080(); // 0x006B3080

void __cdecl D3DFLOORCACHE_CreateTileSurfaces(); // 0x006BB5E0

void __cdecl sub_006B8F10(); // 0x006B8F10

void __fastcall D3DCORE_SetTextureFilterMode(int); // 0x006B2030

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

struct D2GuidStrc
{
    unsigned int dwData[4];
};

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* pCriticalSection);

extern "C" int __cdecl atexit(void (__cdecl* pfnExit)()); // 0x00683824

int __stdcall sub_006B1350_DirectDrawCreate(D2GuidStrc* pGuid, D2ComObjectStrc** ppDD, void* pUnkOuter); // 0x006B1350

void __cdecl D3DCORE_CloseAtExit(); // 0x006B5990

void __cdecl sub_006B80A0_InitializeDrawingGeometry(); // 0x006B80A0

void __cdecl sub_006B96C0_BuildScaleTable(); // 0x006B96C0

void __cdecl sub_006B97D0_BuildScaleTable(); // 0x006B97D0

void __cdecl D3DSMACK_SmackInit(); // 0x006B9A10

extern const unsigned int gnDeviceFlagMask_006CE268; // 0x006CE268

extern const D2GuidStrc gtIidDirectDraw4; // 0x006FF8D8

extern const D2GuidStrc gtIidDirect3D3; // 0x006FF558

extern "C" const char gszD3DCoreFile[]; // 0x006FC120

extern int gnD3DArg1_007C9148; // 0x007C9148

extern unsigned int gnDeviceFlags_0096F3A8; // 0x0096F3A8

extern D2GuidStrc gDeviceGuid_0096F3AC; // 0x0096F3AC

extern D2ComObjectStrc* gpDirect3D3; // 0x00970E64

extern D2GfxSettingsStrc* gpConfig_007C9148; // 0x007C9148

extern D2DDrawSurfaceStrc* gpDevice_00970E68; // 0x00970E68

void __fastcall sub_006BBCE0_Run(int a, int b, int c); // 0x006BBCE0

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);

D2D3DDeviceStrc* gpDevice_00970E78; // 0x00970E78

int __cdecl D3DCORE_Close(); // 0x006B5550

struct D2ComObject006B5550Strc;

struct D2ComObjectVtbl006B5550Strc;

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pCriticalSection);

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

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

extern "C" void __cdecl D3DSMACK_SmackFree(); // 0x006B9B00

extern D2CriticalSectionStrc* gpCriticalSection_007C9134; // 0x007C9134

extern int gnPaused_007C9144; // 0x007C9144

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);

int __fastcall D3DCORE_CreateSurface(void* window,int mode); // 0x006B55E0

int gnState_00970E54; // 0x00970E54

int gnFilterMode; // 0x00970E5C

int gnState_00970E58; // 0x00970E58

void __fastcall sub_006B7F70_ClearTarget(int); // 0x006B7F70

void __fastcall sub_006B9710_SetColorComponents(int, int, int); // 0x006B9710

extern D2ComObjectStrc* gpInterface_00970E78; // 0x00970E78

void __cdecl D3DCORE_ReleaseRenderer(); // 0x006B32B0

void __cdecl sub_006B9150_ReleaseResource(); // 0x006B9150

void __cdecl D3DFLOORCACHE_ReleaseTileSurfaces(); // 0x006BB640

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

extern int gdwGlobal_007B57E4; // 0x007B57E4

extern D2PaletteTableStrc* gpGfxPaletteView_007C9150; // 0x007C9150

D2PaletteTableStrc gPaletteView_0096F280; // 0x0096F280

extern D2ComObjectStrc* gpRenderSurface; // 0x00970E6C

extern D2ComObjectStrc* gpInterface; // 0x00970E70

extern D2ComObjectStrc* gpGammaControl; // 0x00970E74

extern D2ComObjectStrc* gpViewport; // 0x00970E7C

extern char gabGammaRamp[1536]; // 0x0096FCB8

typedef long (__stdcall* D2DDSetGammaRampFn)(D2ComObjectStrc* pThis, unsigned long dwFlags, void* pRamp);

extern unsigned int gnCapabilities_0096F3A8;                                                                // 0x0096F3A8

extern const unsigned int gdwBitMask7_006CE284;                                                             // 0x006CE284

extern const unsigned int gdwBitMask8;                                                             // 0x006CE288

void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...);                                          // 0x00410610

extern const unsigned int gnGammaMask_006CE278;                                                             // 0x006CE278

extern int gnGammaScale_0074C020;                                                                           // 0x0074C020

void __fastcall EXCEL_BuildGammaTable(int nGamma, void* pTable, double dScale, int nStride, int nEntries, int nMask); // 0x006BE190

extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, unsigned int nBytes);

D2ComObject006B5550Strc* gpObject_00970E64; // 0x00970E64

int gbD3DBusy; // 0x00970E50

int gnDeviceTextureFlag; // 0x00970E4C

int gpTileDrawFunctions; // 0x007C914C

int gbD3DInitialized_00970E48; // 0x00970E48

D2ComObjectStrc* gpDirectDraw4_00970E60; // 0x00970E60

int __cdecl D3DCORE_InitCutsceneMode(); // 0x006B3420

extern unsigned int gnRenderFlags_0096F3A8; // 0x0096F3A8

extern const unsigned int gnRenderFlag_006CE284; // 0x006CE284

extern const unsigned int gnRenderFlag_006CE288; // 0x006CE288

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

void __cdecl D3DSPRITE_ReleaseSprites(); // 0x006B5B10

void __cdecl sub_006B7250_ReleaseAll(); // 0x006B7250

void __cdecl D3DSMACK_ReleaseSmackSurfaces(); // 0x006B9B30

void __fastcall sub_006BA830_FreeCache(D2Cache006BA830Strc* pCache, int bFree); // 0x006BA830

void __fastcall D3DSUBTILECACHE_SubtileCacheDestroy(D2Object006BADC0Strc* pObject, int bFree); // 0x006BADC0

void __fastcall D3DFLOORCACHE_FloorCacheDestroy(D2Object006BB3E0Strc* pObject, int bFree); // 0x006BB3E0


extern D2Object006BADC0Strc gObject_0096FC80; // 0x0096FC80

extern D2Object006BB3E0Strc gObject_0096FC9C; // 0x0096FC9C

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

extern const unsigned int gnGammaMask_006CE278; // 0x006CE278

extern unsigned int gnCapabilities_0096F3A8; // 0x0096F3A8

extern int gnGammaScale_0074C020; // 0x0074C020

extern D2GammaControlStrc* gpGammaControl_00970E74; // 0x00970E74

void __fastcall EXCEL_BuildGammaTable(int nGamma, void* pTable, double dScale, int nStride, int nEntries, int nMask); // 0x006BE190

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
    D2Surface006B3570VtableStrc* f_0;
};

extern D2Surface006B3570Strc* gpPrimarySurface_00970E68; // 0x00970E68

extern D2Surface006B3570Strc* gpRenderSurface_00970E6C; // 0x00970E6C

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

__declspec(noreturn) void __cdecl exit(int); // 0x00681E09

int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned long nBufferSize); // 0x00414E50

int __stdcall SRegLoadValue(const char*,const char*,unsigned int,unsigned long*); // 0x00414F10

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

void __cdecl sub_0051793E_FormatAndRaise(unsigned long dwError, ...); // 0x0051793E

void __fastcall D3DCORE_LogDDrawError(const char* szMessage, long hResult) throw();                      // 0x006B20E0

void __fastcall D3DCORE_SaveVideoConfig(int nRender, int nDevice);                                     // 0x006B2F60

int __stdcall sub_006B42F0_DDrawEnumCallback(void* pGuid, char* szDescription, char* szName, void* pContext); // 0x006B42F0

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
void __fastcall D3DCORE_ShowD3DError(const char* text,long result); // 0x006B39B0
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
extern const DWORD gFlag_006CE268; // 0x006CE268
extern const DWORD gdwBitMask1; // 0x006CE26C
extern const DWORD gFlag_006CE270; // 0x006CE270
extern const DWORD gdwBitMask3; // 0x006CE274
extern const DWORD gFlag_006CE278; // 0x006CE278
extern const DWORD gFlag_006CE27C; // 0x006CE27C
extern const DWORD gFlag_006CE284; // 0x006CE284
extern const DWORD gFlag_006CE288; // 0x006CE288
extern const DWORD gFlag_006CE28C; // 0x006CE28C
extern const DWORD gFlag_006CE2E8; // 0x006CE2E8
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

// build: symbol ??_7Thank_you@Define_the_symbol__ATL_MIXED@@6B@ 0x006FAFFC
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

extern int gdwGlobal_00970E50; // 0x00970E50
extern char gnFloorCacheSize[]; // 0x007C90C8

// build: symbol ??0CAtlException@ATL@@QAE@J@Z 0x006B1A20
// build: symbol __TI1?AVCAtlException@ATL@@ 0x007020B4
// 0x006B1A30
void __cdecl ATL::sub_006B1A30_ThrowAtlException(long error)
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
        sub_006B1A30_ThrowAtlException(0x80004005);
    return RegSetValueExA(m_hKey, pszValueName, 0, dwType, (const unsigned char*)pszValue, (lstrlenA(pszValue) + 1) * sizeof(char));
}

// 0x006B1B60
int __stdcall D3D_EnumTextureFormatCallback(D2PixelFormat006B1B60Strc* pFormat, unsigned long* pFlags)
{
    if (!pFlags)
    {
        return 1;
    }
    if (pFormat->dwFlags != gtWantedFormat_0074C024.dwFlags)
    {
        return 1;
    }
    if (pFormat->dwRGBBitCount != gtWantedFormat_0074C024.dwRGBBitCount)
    {
        return 1;
    }
    if (pFormat->dwRBitMask != gtWantedFormat_0074C024.dwRBitMask)
    {
        return 1;
    }
    if (pFormat->dwGBitMask != gtWantedFormat_0074C024.dwGBitMask)
    {
        return 1;
    }
    if (pFormat->dwBBitMask != gtWantedFormat_0074C024.dwBBitMask)
    {
        return 1;
    }
    if (pFormat->dwRGBAlphaBitMask != gtWantedFormat_0074C024.dwRGBAlphaBitMask)
    {
        return 1;
    }
    *pFlags |= gnFormatCap_006CE28C;
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
    return gdwGlobal_00970E50;
}

// 0x006B1C10
void __fastcall D3DCORE_SetGlobalScale(int nValue)
{
    gdwGlobal_007B57E4 = nValue;
}

// 0x006B1C20
unsigned int __cdecl D3DCORE_GetMaskedFlags()
{
    return gnDeviceFlags_0096F3A8 & gnGammaMask_006CE278;
}

// 0x006B1C30
int __cdecl D3DCORE_FlipPrimary()
{
    if (gpConfig_007C9148->bVSync)
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
    gPaletteView_0096F280 = *pSource;
    gpGfxPaletteView_007C9150 = &gPaletteView_0096F280;
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
    if (gnState_00970E54 && nState == gnState_00970E54)
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
    gnState_00970E54 = nState;
}

// 0x006B1F40
void __fastcall D3DCORE_SetAlphaBlendMode(int nState)
{
    if (gnState_00970E58 && nState == gnState_00970E58)
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
    gnState_00970E58 = nState;
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

// build: symbol ?gnRenderWidth@* 0x007C9138
    gnRenderWidth = 640;
// build: symbol ?gnRenderHeight@* 0x007C913C
    gnRenderHeight = 480;

    unsigned int nBpp = 16;
    if (gdwBitMask7_006CE284 & gnCapabilities_0096F3A8)
    {
        nBpp = 32;
    }
    else if (gdwBitMask8 & gnCapabilities_0096F3A8)
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
// build: symbol ?gbRenderPaused@* 0x007C9144
    if (gbRenderPaused)
    {
        return 0;
    }

    if (!(gnRenderFlags_0096F3A8 & gnRenderFlag_006CE284) && !(gnRenderFlags_0096F3A8 & gnRenderFlag_006CE288))
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
    if (gnCapabilities_0096F3A8 & gnGammaMask_006CE278)
    {
        EXCEL_BuildGammaTable(nGamma, (unsigned short*)ramp.red, gnGammaScale_0074C020, 2, 256, 65535);
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
    tDesc.tPixelFormat = gtWantedFormat_0074C024;
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
    int nResult = pSurface->f_0->Lock(pSurface, 0, &desc, 0x21, 0);
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
    pSurface->f_0->Unlock(pSurface, 0);
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
extern void* ghWindow_00970E84; // 0x00970E84
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
    result=gpDraw_00970E60->SetCooperativeLevel(ghWindow_00970E84,0x11);
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
  if(!guid) display->flags|=gFlag_006CE268;
  else { display->flags&=gFlag_006CE2E8; display->guid=*guid; }
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
   if(display->modes[i].flags&gFlag_006CE270) has32=1;
   if(display->modes[i].flags&gdwBitMask3) has24=1;
   if(display->modes[i].flags&gFlag_006CE268) hasUI=1;
   if(display->modes[i].flags&gdwBitMask1) hasGame=1;
  }
  if(has32) { LOGMANAGER_WriteLogLine(gszSupports32BitCutscenes); display->flags|=gFlag_006CE284; }
  if(has24) { LOGMANAGER_WriteLogLine(gszSupports24BitCutscenes); display->flags|=gFlag_006CE288; }
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
  if(caps.caps2&0x20000) display->flags|=gFlag_006CE278;
  else LOGMANAGER_WriteLogLine(gszNoGammaControl);
  if(caps.caps2&0x100000) { display->flags|=gFlag_006CE27C; LOGMANAGER_WriteLogLine(gszSupportsGammaCalibration); }
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
  if(hardware.textureCaps&0x20) { LOGMANAGER_WriteLogLine(gszRequiresSquareTextures); display->flags|=gFlag_006CE270; goto Cleanup; }
  if(hardware.textureFilterCaps&0x20) display->flags|=gdwBitMask3;
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
   display->flags|=gdwBitMask1;
   memset(&memoryCaps,0,sizeof(memoryCaps));memoryCaps.caps=0x20005000;
   hr=gpIDirectDraw4_00970E60->vtbl->GetAvailableVidMem(gpIDirectDraw4_00970E60,&memoryCaps,&display->agpTotal,&display->agpFree);
   if(hr) D3DCORE_LogDDrawError(gszAgpMemoryFailed,hr);
   else LOGMANAGER_WriteLogLine(gszAgpMemoryFormat,display->agpTotal/1048576.0f,display->agpFree/1048576.0f);
  } else LOGMANAGER_WriteLogLine(gszNoAgpTexturing);
  hr=device->vtbl->EnumTextureFormats(device,D3D_EnumTextureFormatCallback,display);
  if(hr) { D3DCORE_ShowD3DError(gszEnumTextureFormatsFailed,hr); goto Cleanup; }

  int textures=0;
  if(display->flags&gFlag_006CE28C) { LOGMANAGER_WriteLogLine(gszSupports1555Textures); textures=1; }
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

        const HRESULT hResult = DirectDrawEnumerateA(sub_006B42F0_DDrawEnumCallback, 0);
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
// build: symbol ?FOG_GetSystemInfo@* 0x00407360
    D2FogSystemInfoStrc* info=FOG_GetSystemInfo();
// build: symbol ?gszEmptyString@* 0x006CC837
    if (!info) { FOG_DisplayHalt(gszEmptyString,sub_00408090(),1032); exit(-1); }
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
    if(gnInitialized) { FOG_DisplayHalt(&gszEmptyAssertText,sub_00408090(),0x50F); exit(-1); }
    long error;
    const char* msg;
    ghWindow=window;
    if(mode==0) { gnWidth=640; gnHeight=480; } else { gnWidth=800; gnHeight=600; }
    switch(mode) { case 0: case 2: gnModeFlag=1; break; default: gnModeFlag=0; break; }
    DD_CHECK(gpDraw->SetCooperativeLevel(window,0x411),gCoopError);
    error=gpDraw->SetDisplayMode(gnWidth,gnHeight,32,0,0);
    if(error) { D3DCORE_LogDDrawError(gDisplayError,error); return 0; }
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
    if(gnFlags & gdwGammaMask)
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
    if(gnFlags & gdwAgpMask)
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
    sub_006B3080(); D3DFLOORCACHE_CreateTileSurfaces(); sub_006B8F10();
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
    if (gpConfig_007C9148->bVSync)
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
        if (gpLock_007C9134)
        {
            DeleteCriticalSection(gpLock_007C9134);
            FOG_Free(gpLock_007C9134, ".\\Src\\d3dCore.cpp", 0x71D, 0);
            gpLock_007C9134 = 0;
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
    if (!gpCriticalSection_007C9134) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x7b0); exit(-1); }
    EnterCriticalSection(gpCriticalSection_007C9134);
    if (paused) {
        gnPaused_007C9144 = 1;
        D3DCORE_ReleaseResources();
        gn_007C9140 = 0;
    }
    else {
        gnPaused_007C9144 = 0;
        D3DCORE_CreateSurface(window, mode);
    }
    LeaveCriticalSection(gpCriticalSection_007C9134);
}

// 0x006B56C0
void __fastcall D3DCORE_OpenSmackCutscene(int a, int b, int c)
{
    if (!gnWindowed)
    {
        gbD3DBusy = 1;
        D3DCORE_Flush();
        if (gpConfig_007C9148->bVSync)
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
    if (gnPaused_007C9144) return 0;
    if (!gpCriticalSection_007C9134) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x842); exit(-1); }
    EnterCriticalSection(gpCriticalSection_007C9134);
    if (clear) sub_006B7F70_ClearTarget(0);
    gnState_00970E54 = 0;
    gnState_00970E58 = 0;
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
    D2_ASSERT(gpLock_007C9134, 0x8B3);
    LeaveCriticalSection(gpLock_007C9134);
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
    tDesc.tPixelFormat = gtWantedFormat_0074C024;
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

    D2_ASSERT(!gbD3DInitialized_00970E48, 0x687);

    gnD3DArg1_007C9148 = nArg1;
    gpTileDrawFunctions = nArg2;

    int hResult;
    if (gnDeviceFlags_0096F3A8 & gnDeviceFlagMask_006CE268)
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
    gbD3DInitialized_00970E48 = 1;
    sub_006B96C0_BuildScaleTable();
    sub_006B97D0_BuildScaleTable();
    sub_006B80A0_InitializeDrawingGeometry();
    D3DSMACK_SmackInit();
    gpCriticalSection_007C9134 = (D2CriticalSectionStrc*)FOG_Alloc(0x18, gszD3DCoreFile, 0x6EA, 0);
    InitializeCriticalSection(gpCriticalSection_007C9134);
    return 1;
}

// 0x006B20C0
int __fastcall D3DCORE_SetOption(int nId, int nValue)
{
    if (nId != 11)
        return 0;
    gnGammaScale_0074C020 = nValue;
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
int __cdecl sub_006B2F20()
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



void __cdecl D3DSPRITE_ReleaseSprites(); // 0x006B5B10

void __cdecl sub_006B7250_ReleaseAll(); // 0x006B7250

void __cdecl D3DSMACK_ReleaseSmackSurfaces(); // 0x006B9B30

void __fastcall sub_006BA830_FreeCache(D2Cache006BA830Strc* pCache, int bFree); // 0x006BA830

void __fastcall D3DSUBTILECACHE_SubtileCacheDestroy(D2Object006BADC0Strc* pObject, int bFree); // 0x006BADC0

void __fastcall D3DFLOORCACHE_FloorCacheDestroy(D2Object006BB3E0Strc* pObject, int bFree); // 0x006BB3E0


extern D2Object006BADC0Strc gObject_0096FC80; // 0x0096FC80

extern D2Object006BB3E0Strc gObject_0096FC9C; // 0x0096FC9C

extern D2Cache006BA830Strc gtTextureCache1; // 0x00970EC8

extern D2Cache006BA830Strc gtTextureCache2; // 0x00970EE4

extern D2Cache006BA830Strc gtTextureCache3; // 0x00970F00

void __cdecl D3DCORE_ReleaseResources(); // 0x006B3320

extern void* ghDDrawWindow_007C9140; // 0x007C9140




extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...); // 0x00410610

void __fastcall D3DCORE_LogDDrawError(const char* szWhere, int hResult); // 0x006B20E0

extern int gbVideoUp; // 0x00970E40

extern int gnVideoState; // 0x00970E44


extern D2ComObject006B3420Strc* gpPrimary_00970E68; // 0x00970E68

extern const unsigned int gdwBitMask7_006CE284; // 0x006CE284

extern const unsigned int gdwBitMask8; // 0x006CE288

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
extern const unsigned int gPrimaryRenderMask; // 0x006CE26C
extern const unsigned int gCompactRenderMask; // 0x006CE280
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
char* __fastcall D3DSMACK_CreateSmackSurfaces(char*); // 0x006B9A50
char* __fastcall D3DFLOORCACHE_FloorCacheInit(BufferPool*,char*,char*,unsigned int); // 0x006BAFC0
char* __fastcall D3DSUBTILECACHE_SubtileCacheInit(BufferPool*,char*,char*,unsigned int); // 0x006BA9A0
char* __fastcall sub_006BA420(BufferPool*,char*,char*,unsigned int,unsigned int); // 0x006BA420
void __cdecl D3DSPRITE_InitSprites(); // 0x006B7110
void __fastcall D3DFLOORCACHE_InvalidateTileCaches(D2TileLibraryEntryStrc* pTile); // 0x006BBB90
void __stdcall TileSetHardwareFreeCallback(void*); // 0x00604A30
extern D2ComObjectStrc* gpInterface_00970E78; // 0x00970E78
void __cdecl sub_006B9150_ReleaseResource(); // 0x006B9150
void __cdecl D3DFLOORCACHE_ReleaseTileSurfaces(); // 0x006BB640
int gbVideoUp; // 0x00970E40
int gnVideoState; // 0x00970E44
D2ComObjectStrc* gpPrimarySurface; // 0x00970E68
D2ComObjectStrc* gpRenderSurface; // 0x00970E6C
D2ComObjectStrc* gpInterface; // 0x00970E70
D2ComObjectStrc* gpGammaControl; // 0x00970E74
D2ComObjectStrc* gpViewport; // 0x00970E7C
char gabGammaRamp[1536]; // 0x0096FCB8

// 0x006B3080
void __cdecl sub_006B3080()
{
 unsigned int memory;
 gBufferCopies=2;
 gUsePreferredMemory=0;
 if((gRenderFlags&gPrimaryRenderMask) && gAvailableMemory<0xD00000) {
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
  if(gRenderFlags&gCompactRenderMask){width=160;height=80;}else{width=256;height=128;}
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
  current=sub_006BA420(&gLargePool,current,current+remaining*20/100,256,256);
  gLargeBudget=gLargePool.count*gBufferCopies*65536;
  current=sub_006BA420(&gMediumPool,current,start+remaining*75/100,128,128);
 } else {
  gPrimaryBudget=0;gSecondaryBudget=0;
  current=D3DSMACK_CreateSmackSurfaces(current);
  start=current;remaining=memory-(unsigned int)current;
  current=sub_006BA420(&gLargePool,current,current+remaining*70/100,256,256);
  gLargeBudget=gLargePool.count*gBufferCopies*65536;
  current=sub_006BA420(&gMediumPool,current,start+remaining*80/100,128,128);
 }
 gMediumBudget=gMediumPool.count*gBufferCopies*16384;
 sub_006BA420(&gSmallPool,current,(char*)memory,32,32);
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
        D3DFLOORCACHE_FloorCacheDestroy(&gObject_0096FC9C, 1);
        D3DSUBTILECACHE_SubtileCacheDestroy(&gObject_0096FC80, 1);
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

#include "gen/data/Source/D2Direct3D/Src/d3dCore.inc"
