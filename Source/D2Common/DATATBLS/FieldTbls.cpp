#include "D2DataTbls.h"
#include "FogApi.h"
#pragma function(memcpy)
#pragma intrinsic(memset)

#define FIELD_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2PoolSystemStrc;
#define FIELD_CELL(pFieldArg, nPosX, nPosY) \
    *reinterpret_cast<unsigned char*>(gtCollisionField.nCenterX \
        + ((((nPosY - (pFieldArg)->nY + gtCollisionField.nCenterY) << 8) - (pFieldArg)->nX + nPosX) \
        + reinterpret_cast<unsigned int>(gpFieldData)))

struct D2ActiveRoomStrc;
struct D2FieldStrc;
struct D2CollisionFieldStrc;
struct D2DataTablesStrc;

struct D2FieldStrc
{
    int nX;
    int nY;
};



extern D2DataTablesStrc sgtDataTables; // 0x0096BC30
extern const int gnFieldXOffsets[9]; // 0x00749780
extern const int gnFieldYOffsets[9]; // 0x007497A4
void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall sub_0040B480(D2PoolSystemStrc* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __stdcall D2Common_11098(D2FieldStrc* pField, int* pX, int* pY); // 0x0066A5D0
extern "C" const char gszDataGlobalPath[]; // 0x006D4118
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...); // 0x006CC468
void* __fastcall sub_00517079(void* hArchive, const char* szPath, int* pSize, const char* szFile, int nLine); // 0x00517079

// 0x0066A2B0
int __stdcall DATATBLS_InitializeCollisionFieldTable(char* pExpField, int nSize)
{
    char* pFile = pExpField;
    pExpField += 2;
    const int nHeight = *(int*)pExpField;
    pExpField += 4;
    const int nWidth = *(int*)pExpField;
    pExpField += 4;
    const int nArea = nWidth * nHeight;

    unsigned char* pFieldData = (unsigned char*)FOG_AllocPool(0, nArea, ".\\DATATBLS\\FieldTbls.cpp", 62, 0);
    FIELD_ASSERT(pFieldData, 64);
    memcpy(pFieldData, pExpField, nArea);
    sgtDataTables.pFieldData = pFieldData;

    sgtDataTables.pCollisionField.nWidth = nWidth;
    sgtDataTables.pCollisionField.nHeight = nHeight;
    sgtDataTables.pCollisionField.nArea = nArea;
    sgtDataTables.pCollisionField.nCenterX = nWidth >> 1;
    sgtDataTables.pCollisionField.nCenterY = nHeight >> 1;

    for (int i = 0; i < 9; ++i)
    {
        sgtDataTables.ExpFieldI[i] = gnFieldXOffsets[i] + nWidth * gnFieldYOffsets[i];
    }

    FOG_Free(pFile, ".\\DATATBLS\\FieldTbls.cpp", 80, 0);
    return 1;
}

// 0x0066A420
int __stdcall DATATBLS_FreeCollisionFieldTable()
{
    if (sgtDataTables.pFieldData)
    {
        sub_0040B480(0, sgtDataTables.pFieldData, ".\\DATATBLS\\FieldTbls.cpp", 91, 0);
    }

    sgtDataTables.pFieldData = 0;
    sgtDataTables.pCollisionField.nHeight = 0;
    sgtDataTables.pCollisionField.nWidth = 0;
    sgtDataTables.pCollisionField.nArea = 0;
    sgtDataTables.pCollisionField.nCenterX = 0;
    sgtDataTables.pCollisionField.nCenterY = 0;
    return 1;
}

// 0x0066A470
void __stdcall DATATBLS_GetCollisionFieldCenter(int* pCenterX, int* pCenterY)
{
    *pCenterX = sgtDataTables.pCollisionField.nCenterX;
    *pCenterY = sgtDataTables.pCollisionField.nCenterY;
}

// 0x0066A490
int __stdcall DATATBLS_GetCollisionFieldWidth()
{
    return sgtDataTables.pCollisionField.nWidth;
}

// 0x0066A4A0
int __stdcall DATATBLS_GetCollisionFieldHeight()
{
    return sgtDataTables.pCollisionField.nHeight;
}

// 0x0066A4B0
D2FieldStrc* __stdcall DATATBLS_AllocField()
{
    D2FieldStrc* pField = (D2FieldStrc*)FOG_AllocPool(0, sizeof(D2FieldStrc), ".\\DATATBLS\\FieldTbls.cpp", 135, 0);
    FIELD_ASSERT(pField, 136);

    memset(pField, 0, sizeof(D2FieldStrc));
    return pField;
}

// 0x0066A500
void __stdcall DATATBLS_FreeField(D2FieldStrc* pField)
{
    FIELD_ASSERT(pField, 147);

    sub_0040B480(0, pField, ".\\DATATBLS\\FieldTbls.cpp", 148, 0);
}

// 0x0066A540
void __stdcall DATATBLS_SetFieldCoordinates(D2FieldStrc* pField, int nX, int nY)
{
    FIELD_ASSERT(pField, 161);

    pField->nX = nX;
    pField->nY = nY;
}

// 0x0066A580
int __stdcall D2Common_11097(D2FieldStrc* pField, int nX, int nY)
{
    FIELD_ASSERT(pField, 176);

    return *(&sgtDataTables.pFieldData[((nY - pField->nY) << 8) - pField->nX] + nX);
}

unsigned char* gpFieldData; // 0x0096D654

D2CollisionFieldStrc gtCollisionField; // 0x0096D658

// 0x0066A5D0
int __stdcall D2Common_11098(D2FieldStrc* pField, int* pX, int* pY)
{
    FIELD_ASSERT(pField, 191);

    const int nIndex = FIELD_CELL(pField, *pX, *pY);

    *pX += gnFieldXOffsets[nIndex];
    *pY += gnFieldYOffsets[nIndex];

    return FIELD_CELL(pField, *pX, *pY) != 8;
}

// 0x0066A670
int __stdcall D2Common_11099(D2FieldStrc* pField, D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short fMask)
{
    if (!pRoom)
    {
        return 0;
    }

    if (COLLISION_CheckMask(pRoom, nX, nY, fMask))
    {
        return 1;
    }

    while (D2Common_11098(pField, &nX, &nY))
    {
        if (COLLISION_CheckMask(pRoom, nX, nY, fMask))
        {
            return 1;
        }
    }

    return 0;
}

#pragma pack(push, 1)
struct d2data_00749744_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

extern "C" struct d2data_00749744_t gData_00749744; // 0x00749744
extern "C" const int gData_00749780[9]; // 0x00749780
extern "C" const int gData_007497A4[9]; // 0x007497A4

extern "C" struct d2data_00749744_t gData_00749744 = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x00749744

extern "C" const int gData_00749780[9] = { 0, 1, 1, 1, 0, -1, -1, -1 }; // 0x00749780
#pragma comment(linker, "/alternatename:?gnFieldXOffsets@@3QBHB=_gData_00749780")

extern "C" const int gData_007497A4[9] = { -1, -1, 0, 1, 1, 1, 0, -1 }; // 0x007497A4
#pragma comment(linker, "/alternatename:?gnFieldYOffsets@@3QBHB=_gData_007497A4")

// 0x0066A700
int __fastcall DATATBLS_LoadExpFieldD2(void* hArchive)
{
    char szPath[260];
    int nSize;
    wsprintfA(szPath, "%s\\expfield.d2", gszDataGlobalPath);
    char* pExpField = (char*)sub_00517079(hArchive, szPath, &nSize, ".\\DATATBLS\\FieldTbls.cpp", 40);
    return DATATBLS_InitializeCollisionFieldTable(pExpField, nSize);
}
