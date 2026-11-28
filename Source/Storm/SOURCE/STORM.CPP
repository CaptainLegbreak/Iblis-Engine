#include "Storm.h"
#include "D2StormAutoLink.h"
#include "D2GameTypes.h"

#define OPTION_BIAS 0

#define OUTPUT_BYTES 4

#define ERROR_INVALID 0x57

void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);

int gnErrorOutputMode_0077909C;         // 0x0077909C

int gnOption_007790A0;         // 0x007790A0

int gnLeakReportMode;         // 0x00779098

int gbAlignReads_007790A4;         // 0x007790A4

extern int gbSLogDebugOutput;  // 0x007790AC

#define INPUT_INDEX 0

void __cdecl SLogInitialize(); // 0x00420040

void __cdecl SMemInitialize(); // 0x00411CD0

extern "C" void __cdecl SStrInitialize(); // 0x00414360

struct D2StormInit0041C0C0Strc;

struct D2StormInit0041C0C0Strc
{
    D2StormInit0041C0C0Strc();
};

void __cdecl StormInitialize(); // 0x0041BEE0

// 0x0041BEE0
void __cdecl StormInitialize()
{
    SMemInitialize();
    SLogInitialize();
    SStrInitialize();
}

// 0x0041BEF0
void* __cdecl StormGetInstance()
{
    return GetModuleHandleA(0);
}

// 0x0041BF00
int __stdcall StormSetOption(unsigned int nOption, void* pOutput, unsigned int* pSize)
{
    VALIDATEBEGIN;
    VALIDATE(pOutput);
    VALIDATE(pSize);
    VALIDATEEND;
    sub_0041C340_SetLastError(ERROR_INVALID);
    switch (nOption)
    {
    case 1 + OPTION_BIAS:
        if (*pSize < OUTPUT_BYTES) return 0;
        *(int*)pOutput = gnErrorOutputMode_0077909C;
        *pSize = OUTPUT_BYTES;
        break;
    case 2 + OPTION_BIAS:
        if (*pSize < OUTPUT_BYTES) return 0;
        *(int*)pOutput = gnOption_007790A0;
        *pSize = OUTPUT_BYTES;
        break;
    case 3 + OPTION_BIAS:
        if (*pSize < OUTPUT_BYTES) return 0;
        *(int*)pOutput = gnLeakReportMode;
        *pSize = OUTPUT_BYTES;
        break;
    case 4 + OPTION_BIAS:
        if (*pSize < OUTPUT_BYTES) return 0;
        *(int*)pOutput = gbAlignReads_007790A4;
        *pSize = OUTPUT_BYTES;
        break;
    case 5 + OPTION_BIAS:
        if (*pSize < OUTPUT_BYTES) return 0;
        *(int*)pOutput = gbSLogDebugOutput;
        *pSize = OUTPUT_BYTES;
        break;
    }
    sub_0041C340_SetLastError(0);
    return nValid ? 1 : 0;
}

// 0x0041BFC0
int __stdcall StormGetOption(unsigned int nOption, const void* pInput, unsigned int nSize)
{
    VALIDATEBEGIN;
    VALIDATE(pInput);
    VALIDATEEND;
    sub_0041C340_SetLastError(ERROR_INVALID);
    switch (nOption)
    {
    case 1 + OPTION_BIAS:
        if (nSize != sizeof(int)) return 0;
        gnErrorOutputMode_0077909C = ((const int*)pInput)[INPUT_INDEX];
        break;
    case 2 + OPTION_BIAS:
        {
            if (nSize != sizeof(int)) return 0;
            unsigned int nValue = ((const unsigned int*)pInput)[INPUT_INDEX];
            if (!nValue || ((nValue - 1) ^ nValue) != (nValue + nValue - 1)) return 0;
            gnOption_007790A0 = nValue;
            break;
        }
    case 3 + OPTION_BIAS:
        if (nSize != sizeof(int)) return 0;
        gnLeakReportMode = ((const int*)pInput)[INPUT_INDEX];
        break;
    case 4 + OPTION_BIAS:
        if (nSize != sizeof(int)) return 0;
        gbAlignReads_007790A4 = ((const int*)pInput)[INPUT_INDEX];
        break;
    case 5 + OPTION_BIAS:
        if (nSize != sizeof(int)) return 0;
        gbSLogDebugOutput = ((const int*)pInput)[INPUT_INDEX];
        break;
    }
    sub_0041C340_SetLastError(0);
    return nValid ? 1 : 0;
}

// Initializes Storm before main.
struct D2StormStartupStrc
{
    D2StormStartupStrc() { StormInitialize(); }
};

// build: symbol ??__EgtStormStartup@@YAXXZ 0x006CA890
static D2StormStartupStrc gtStormStartup;

// 0x0041C0C0
D2StormInit0041C0C0Strc::D2StormInit0041C0C0Strc()
{
    StormInitialize();
}
