#include "D2Common.h"
#include "D2Records.h"
#include "D2ClientTypes.h"
#include "D2TxtItems.h"

D2BeltsTxt* sgptBeltInitStats;                                                                                       // 0x0096D4F8

void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                               // 0x006125C0

#define BELTS_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00660290
void __fastcall DATATBLS_LoadBeltsTxt(void* hArchive)
{
    int nRecordCount;
    D2BinFieldStrc pTbl[] =
    {
        { "numboxes", 4, 0, 4, 0 },
        { "box1left", 2, 0, 8, 0 },
        { "box1right", 2, 0, 12, 0 },
        { "box1top", 2, 0, 16, 0 },
        { "box1bottom", 2, 0, 20, 0 },
        { "box2left", 2, 0, 24, 0 },
        { "box2right", 2, 0, 28, 0 },
        { "box2top", 2, 0, 32, 0 },
        { "box2bottom", 2, 0, 36, 0 },
        { "box3left", 2, 0, 40, 0 },
        { "box3right", 2, 0, 44, 0 },
        { "box3top", 2, 0, 48, 0 },
        { "box3bottom", 2, 0, 52, 0 },
        { "box4left", 2, 0, 56, 0 },
        { "box4right", 2, 0, 60, 0 },
        { "box4top", 2, 0, 64, 0 },
        { "box4bottom", 2, 0, 68, 0 },
        { "box5left", 2, 0, 72, 0 },
        { "box5right", 2, 0, 76, 0 },
        { "box5top", 2, 0, 80, 0 },
        { "box5bottom", 2, 0, 84, 0 },
        { "box6left", 2, 0, 88, 0 },
        { "box6right", 2, 0, 92, 0 },
        { "box6top", 2, 0, 96, 0 },
        { "box6bottom", 2, 0, 100, 0 },
        { "box7left", 2, 0, 104, 0 },
        { "box7right", 2, 0, 108, 0 },
        { "box7top", 2, 0, 112, 0 },
        { "box7bottom", 2, 0, 116, 0 },
        { "box8left", 2, 0, 120, 0 },
        { "box8right", 2, 0, 124, 0 },
        { "box8top", 2, 0, 128, 0 },
        { "box8bottom", 2, 0, 132, 0 },
        { "box9left", 2, 0, 136, 0 },
        { "box9right", 2, 0, 140, 0 },
        { "box9top", 2, 0, 144, 0 },
        { "box9bottom", 2, 0, 148, 0 },
        { "box10left", 2, 0, 152, 0 },
        { "box10right", 2, 0, 156, 0 },
        { "box10top", 2, 0, 160, 0 },
        { "box10bottom", 2, 0, 164, 0 },
        { "box11left", 2, 0, 168, 0 },
        { "box11right", 2, 0, 172, 0 },
        { "box11top", 2, 0, 176, 0 },
        { "box11bottom", 2, 0, 180, 0 },
        { "box12left", 2, 0, 184, 0 },
        { "box12right", 2, 0, 188, 0 },
        { "box12top", 2, 0, 192, 0 },
        { "box12bottom", 2, 0, 196, 0 },
        { "box13left", 2, 0, 200, 0 },
        { "box13right", 2, 0, 204, 0 },
        { "box13top", 2, 0, 208, 0 },
        { "box13bottom", 2, 0, 212, 0 },
        { "box14left", 2, 0, 216, 0 },
        { "box14right", 2, 0, 220, 0 },
        { "box14top", 2, 0, 224, 0 },
        { "box14bottom", 2, 0, 228, 0 },
        { "box15left", 2, 0, 232, 0 },
        { "box15right", 2, 0, 236, 0 },
        { "box15top", 2, 0, 240, 0 },
        { "box15bottom", 2, 0, 244, 0 },
        { "box16left", 2, 0, 248, 0 },
        { "box16right", 2, 0, 252, 0 },
        { "box16top", 2, 0, 256, 0 },
        { "box16bottom", 2, 0, 260, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    sgptBeltInitStats = (D2BeltsTxt*)DATATBLS_CompileTxt(hArchive, "belts", pTbl, &nRecordCount, 0x108);
    TBL_ASSERT(nRecordCount / 2 == 7, 106);
}

// 0x00660C60
void __fastcall DATATBLS_UnloadBeltsTxt()
{
    DATATBLS_UnloadBin(sgptBeltInitStats);
}

// 0x00660C70
static D2BeltsTxt* DATATBLS_GetBeltsTxtRecordFromIndex(int nIndex)
{
    BELTS_ASSERT(sgptBeltInitStats, 121);
    D2BeltsTxt* pBeltsTxtRecord = &sgptBeltInitStats[nIndex];
    BELTS_ASSERT(&sgptBeltInitStats[nIndex], 122);
    return pBeltsTxtRecord;
}

// 0x00660CB0
void __stdcall DATATBLS_GetBeltsTxtRecord(int nIndex, int bHigherRes, D2BeltsTxt* pRecord)
{
    BELTS_ASSERT(&sgptBeltInitStats[nIndex], 131);
    *pRecord = sgptBeltInitStats[nIndex + 7 * bHigherRes];
}
// 0x00660D10
void __stdcall DATATBLS_GetInvRectFromBeltsTxt(int nIndex, int bHigherRes, D2InvRectStrc* pInvRect, int nBoxId)
{
    D2BeltsTxt* pBeltsTxtRecord = DATATBLS_GetBeltsTxtRecordFromIndex(nIndex + 7 * bHigherRes);
    const D2InvRectStrc* pBoxStats = &pBeltsTxtRecord->beltBoxes[nBoxId];
    BELTS_ASSERT(pBoxStats, 143);

    pInvRect->nLeft = pBoxStats->nLeft;
    pInvRect->nRight = pBoxStats->nRight;
    pInvRect->nTop = pBoxStats->nTop;
    pInvRect->nBottom = pBoxStats->nBottom;
}


#include "gen/data/Source/D2Common/DATATBLS/BeltTbls.inc"
