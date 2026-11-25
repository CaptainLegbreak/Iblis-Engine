#include "D2LevelTxt.h"
#include "D2DataTbls.h"
#pragma intrinsic(memset)

#define WP_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2WaypointDataStrc;
struct D2WaypointBitStrc;
struct D2LevelsTxt;
struct D2DataTablesStrc;

struct D2WaypointDataStrc
{
    unsigned short nFlags[8];
};

struct D2WaypointBitStrc
{
    unsigned short nIndex;
    unsigned short nMask;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" int gnWaypointBits; // 0x00746424
extern "C" D2WaypointBitStrc gaWaypointBits[]; // 0x00746428
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70

static void WAYPOINTS_ValidateWaypointData(D2WaypointDataStrc* pData)
{
    if (pData->nFlags[0] != 0x102)
    {
        WP_ASSERT(pData->nFlags[0] == 0 || pData->nFlags[0] == 0x101, 275);
        pData->nFlags[0] = 0x102;
    }
}

static void WAYPOINTS_SetWaypointBit(D2WaypointDataStrc* pData, unsigned short nField)
{
    pData->nFlags[gaWaypointBits[nField].nIndex] |= gaWaypointBits[nField].nMask;
}

// 0x00660D90
int __stdcall WAYPOINTS_GetLevelIdFromWaypointNo(unsigned short nWaypointNo, int* pLevelId)
{
    *pLevelId = 0;

    if (nWaypointNo < 255)
    {
        for (int i = 1; i < sgptDataTables->nLevelsTxtRecordCount; ++i)
        {
            if (DATATBLS_GetLevelsTxtRecord(i)->nWaypoint == nWaypointNo)
            {
                *pLevelId = i;
                return 1;
            }
        }
    }

    return 0;
}

// 0x00660E00
int __stdcall WAYPOINTS_GetWaypointNoFromLevelId(int nLevelId, unsigned short* pWaypointNo)
{
    *pWaypointNo = 255;

    if (nLevelId < sgptDataTables->nLevelsTxtRecordCount)
    {
        D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(nLevelId);
        if (pLevelsTxtRecord)
        {
            *pWaypointNo = pLevelsTxtRecord->nWaypoint;
            if (*pWaypointNo != 255)
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x00660E50
int __stdcall WAYPOINTS_IsActivated(D2WaypointDataStrc* pData, unsigned short wField)
{
    WP_ASSERT(pData, 221);
    WP_ASSERT(gnWaypointBits == 112, 222);
    WP_ASSERT(wField < 112, 225);

    return pData->nFlags[gaWaypointBits[wField].nIndex] & gaWaypointBits[wField].nMask;
}

// 0x00660EC0
void __stdcall WAYPOINTS_ActivateWaypoint(D2WaypointDataStrc* pData, unsigned short wField)
{
    WP_ASSERT(pData, 237);
    WP_ASSERT(gnWaypointBits == 112, 238);
    WP_ASSERT(wField < 112, 241);

    WAYPOINTS_SetWaypointBit(pData, wField);
}

// 0x00660F30
D2WaypointDataStrc* __stdcall WAYPOINTS_AllocWaypointData(void* pMemPool)
{
    D2WaypointDataStrc* pData = (D2WaypointDataStrc*)sub_0040B430(pMemPool, sizeof(D2WaypointDataStrc), ".\\WayPoint\\Waypoint.cpp", 252, 0);
    memset(pData, 0, sizeof(D2WaypointDataStrc));
    pData->nFlags[0] = 0x102;
    WAYPOINTS_SetWaypointBit(pData, 0);
    return pData;
}

#include "gen/data/Source/D2Common/Waypoint/Waypoint.inc"

// 0x00660F80
int __fastcall WAYPOINTS_ValidateWaypointHeader(D2WaypointDataStrc* pData)
{
    if (pData->nFlags[0] != 0x102)
    {
        D2_ASSERT(pData->nFlags[0] == 0 || pData->nFlags[0] == 0x101, 0x113);
        pData->nFlags[0] = 0x102;
        return 0;
    }
    return 1;
}

// 0x00660FD0
void __stdcall WAYPOINTS_FreeWaypointData(void* pMemPool, D2WaypointDataStrc* pData)
{
    WAYPOINTS_ValidateWaypointData(pData);
    sub_0040B480(pMemPool, pData, ".\\WayPoint\\Waypoint.cpp", 289, 0);
}

// 0x00661030
void __stdcall WAYPOINTS_CopyAndValidateWaypointData(D2WaypointDataStrc* pDestination, D2WaypointDataStrc* pSource)
{
    *pDestination = *pSource;

    if (pDestination->nFlags[0] != 0x102)
    {
        WP_ASSERT(pDestination->nFlags[0] == 0 || pDestination->nFlags[0] == 0x101, 275);
        pDestination->nFlags[0] = 0x102;
        memset(pDestination, 0, sizeof(D2WaypointDataStrc));
    }

    WAYPOINTS_SetWaypointBit(pDestination, 0);
}

// 0x006610B0
void __stdcall WAYPOINTS_ValidateAndCopyWaypointData(D2WaypointDataStrc* pSource, D2WaypointDataStrc* pDestination)
{
    WAYPOINTS_ValidateWaypointData(pSource);
    *pDestination = *pSource;
}
