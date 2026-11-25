#include "D2Common.h"
#include "D2Txt.h"
#include "D2Records.h"
struct D2TxtLinkStrc;



extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
extern D2ObjectsTxt* gpObjectsTxt;                                                                          // 0x0096D470
int gnObjectsTxtRecordCount;                                                                                // 0x0096D474
extern void* gpObjgroupTxt; // 0x0096D478
extern int gnObjgroupTxtRecordCount; // 0x0096D47C
void __stdcall DATATBLS_UnloadBin(void* pBinFile); // 0x006125C0
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
const unsigned short* __fastcall D2LANG_GetStringByReferenceString(const char* szReference);                // 0x00524E20
unsigned short* __fastcall sub_00526790(unsigned short* wszDest, const unsigned short* wszSrc, int nCount);// 0x00526790
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
#pragma function(memset)

// 0x0063F690
void __fastcall DATATBLS_LoadObjectsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Name", 1, 63, 0, 0 },
        { "Token", 1, 2, 192, 0 },
        { "SpawnMax", 4, 0, 195, 0 },
        { "Selectable0", 4, 0, 196, 0 },
        { "Selectable1", 4, 0, 197, 0 },
        { "Selectable2", 4, 0, 198, 0 },
        { "Selectable3", 4, 0, 199, 0 },
        { "Selectable4", 4, 0, 200, 0 },
        { "Selectable5", 4, 0, 201, 0 },
        { "Selectable6", 4, 0, 202, 0 },
        { "Selectable7", 4, 0, 203, 0 },
        { "TrapProb", 4, 0, 204, 0 },
        { "SizeX", 2, 0, 208, 0 },
        { "SizeY", 2, 0, 212, 0 },
        { "FrameCnt0", 2, 0, 216, 0 },
        { "FrameCnt1", 2, 0, 220, 0 },
        { "FrameCnt2", 2, 0, 224, 0 },
        { "FrameCnt3", 2, 0, 228, 0 },
        { "FrameCnt4", 2, 0, 232, 0 },
        { "FrameCnt5", 2, 0, 236, 0 },
        { "FrameCnt6", 2, 0, 240, 0 },
        { "FrameCnt7", 2, 0, 244, 0 },
        { "FrameDelta0", 3, 0, 248, 0 },
        { "FrameDelta1", 3, 0, 250, 0 },
        { "FrameDelta2", 3, 0, 252, 0 },
        { "FrameDelta3", 3, 0, 254, 0 },
        { "FrameDelta4", 3, 0, 256, 0 },
        { "FrameDelta5", 3, 0, 258, 0 },
        { "FrameDelta6", 3, 0, 260, 0 },
        { "FrameDelta7", 3, 0, 262, 0 },
        { "CycleAnim0", 4, 0, 264, 0 },
        { "CycleAnim1", 4, 0, 265, 0 },
        { "CycleAnim2", 4, 0, 266, 0 },
        { "CycleAnim3", 4, 0, 267, 0 },
        { "CycleAnim4", 4, 0, 268, 0 },
        { "CycleAnim5", 4, 0, 269, 0 },
        { "CycleAnim6", 4, 0, 270, 0 },
        { "CycleAnim7", 4, 0, 271, 0 },
        { "Lit0", 4, 0, 272, 0 },
        { "Lit1", 4, 0, 273, 0 },
        { "Lit2", 4, 0, 274, 0 },
        { "Lit3", 4, 0, 275, 0 },
        { "Lit4", 4, 0, 276, 0 },
        { "Lit5", 4, 0, 277, 0 },
        { "Lit6", 4, 0, 278, 0 },
        { "Lit7", 4, 0, 279, 0 },
        { "BlocksLight0", 4, 0, 280, 0 },
        { "BlocksLight1", 4, 0, 281, 0 },
        { "BlocksLight2", 4, 0, 282, 0 },
        { "BlocksLight3", 4, 0, 283, 0 },
        { "BlocksLight4", 4, 0, 284, 0 },
        { "BlocksLight5", 4, 0, 285, 0 },
        { "BlocksLight6", 4, 0, 286, 0 },
        { "BlocksLight7", 4, 0, 287, 0 },
        { "HasCollision0", 4, 0, 288, 0 },
        { "HasCollision1", 4, 0, 289, 0 },
        { "HasCollision2", 4, 0, 290, 0 },
        { "HasCollision3", 4, 0, 291, 0 },
        { "HasCollision4", 4, 0, 292, 0 },
        { "HasCollision5", 4, 0, 293, 0 },
        { "HasCollision6", 4, 0, 294, 0 },
        { "HasCollision7", 4, 0, 295, 0 },
        { "IsAttackable0", 4, 0, 296, 0 },
        { "Start0", 4, 0, 297, 0 },
        { "Start1", 4, 0, 298, 0 },
        { "Start2", 4, 0, 299, 0 },
        { "Start3", 4, 0, 300, 0 },
        { "Start4", 4, 0, 301, 0 },
        { "Start5", 4, 0, 302, 0 },
        { "Start6", 4, 0, 303, 0 },
        { "Start7", 4, 0, 304, 0 },
        { "OrderFlag0", 4, 0, 305, 0 },
        { "OrderFlag1", 4, 0, 306, 0 },
        { "OrderFlag2", 4, 0, 307, 0 },
        { "OrderFlag3", 4, 0, 308, 0 },
        { "OrderFlag4", 4, 0, 309, 0 },
        { "OrderFlag5", 4, 0, 310, 0 },
        { "OrderFlag6", 4, 0, 311, 0 },
        { "OrderFlag7", 4, 0, 312, 0 },
        { "EnvEffect", 4, 0, 313, 0 },
        { "IsDoor", 4, 0, 314, 0 },
        { "BlocksVis", 4, 0, 315, 0 },
        { "Orientation", 4, 0, 316, 0 },
        { "Trans", 4, 0, 318, 0 },
        { "PreOperate", 4, 0, 317, 0 },
        { "Mode0", 4, 0, 319, 0 },
        { "Mode1", 4, 0, 320, 0 },
        { "Mode2", 4, 0, 321, 0 },
        { "Mode3", 4, 0, 322, 0 },
        { "Mode4", 4, 0, 323, 0 },
        { "Mode5", 4, 0, 324, 0 },
        { "Mode6", 4, 0, 325, 0 },
        { "Mode7", 4, 0, 326, 0 },
        { "Xoffset", 2, 0, 328, 0 },
        { "Yoffset", 2, 0, 332, 0 },
        { "Draw", 4, 0, 336, 0 },
        { "HD", 4, 0, 337, 0 },
        { "TR", 4, 0, 338, 0 },
        { "LG", 4, 0, 339, 0 },
        { "RA", 4, 0, 340, 0 },
        { "LA", 4, 0, 341, 0 },
        { "RH", 4, 0, 342, 0 },
        { "LH", 4, 0, 343, 0 },
        { "SH", 4, 0, 344, 0 },
        { "S1", 4, 0, 345, 0 },
        { "S2", 4, 0, 346, 0 },
        { "S3", 4, 0, 347, 0 },
        { "S4", 4, 0, 348, 0 },
        { "S5", 4, 0, 349, 0 },
        { "S6", 4, 0, 350, 0 },
        { "S7", 4, 0, 351, 0 },
        { "S8", 4, 0, 352, 0 },
        { "TotalPieces", 4, 0, 353, 0 },
        { "XSpace", 4, 0, 354, 0 },
        { "YSpace", 4, 0, 355, 0 },
        { "Red", 4, 0, 356, 0 },
        { "Green", 4, 0, 357, 0 },
        { "Blue", 4, 0, 358, 0 },
        { "SubClass", 4, 0, 359, 0 },
        { "NameOffset", 2, 0, 360, 0 },
        { "MonsterOK", 4, 0, 365, 0 },
        { "OperateRange", 4, 0, 366, 0 },
        { "ShrineFunction", 4, 0, 367, 0 },
        { "Act", 4, 0, 368, 0 },
        { "Restore", 4, 0, 371, 0 },
        { "RestoreVirgins", 4, 0, 372, 0 },
        { "Parm0", 2, 0, 376, 0 },
        { "Parm1", 2, 0, 380, 0 },
        { "Parm2", 2, 0, 384, 0 },
        { "Parm3", 2, 0, 388, 0 },
        { "Parm4", 2, 0, 392, 0 },
        { "Parm5", 2, 0, 396, 0 },
        { "Parm6", 2, 0, 400, 0 },
        { "Parm7", 2, 0, 404, 0 },
        { "Lockable", 4, 0, 369, 0 },
        { "Gore", 4, 0, 370, 0 },
        { "Sync", 4, 0, 373, 0 },
        { "Beta", 4, 0, 432, 0 },
        { "nTgtFX", 4, 0, 408, 0 },
        { "nTgtFY", 4, 0, 409, 0 },
        { "nTgtBX", 4, 0, 410, 0 },
        { "nTgtBY", 4, 0, 411, 0 },
        { "Damage", 4, 0, 412, 0 },
        { "CollisionSubst", 4, 0, 413, 0 },
        { "Left", 2, 0, 416, 0 },
        { "Top", 2, 0, 420, 0 },
        { "Width", 2, 0, 424, 0 },
        { "Height", 2, 0, 428, 0 },
        { "OperateFn", 4, 0, 435, 0 },
        { "PopulateFn", 4, 0, 434, 0 },
        { "ClientFn", 4, 0, 436, 0 },
        { "InitFn", 4, 0, 433, 0 },
        { "Overlay", 4, 0, 437, 0 },
        { "BlockMissile", 4, 0, 438, 0 },
        { "DrawUnder", 4, 0, 439, 0 },
        { "OpenWarp", 4, 0, 440, 0 },
        { "AutoMap", 2, 0, 444, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpObjectsTxt = (D2ObjectsTxt*)DATATBLS_CompileTxt(hArchive, "objects", pTbl, &gnObjectsTxtRecordCount, 448);

    for (int i = 0; i < gnObjectsTxtRecordCount; ++i)
    {
        D2ObjectsTxt* pObjectsTxtRecord = &gpObjectsTxt[i];
        memset(pObjectsTxtRecord->wszName, 0, sizeof(pObjectsTxtRecord->wszName));
        sub_00526790(pObjectsTxtRecord->wszName, D2LANG_GetStringByReferenceString(pObjectsTxtRecord->szName), sizeof(pObjectsTxtRecord->szName));

        for (int j = 0; j < 8; ++j)
        {
            pObjectsTxtRecord->dwFrameCnt[j] <<= 8;
        }
    }
}

// 0x00640E90
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId)
{
    D2_ASSERT(nObjectId < gnObjectsTxtRecordCount, 221);
    D2_ASSERT(nObjectId >= 0, 222);
    return &gpObjectsTxt[nObjectId];
}

// 0x00640EE0
void __fastcall DATATBLS_UnloadObjectsTxt()
{
    DATATBLS_UnloadBin(gpObjectsTxt);
    gpObjectsTxt = 0;
    gnObjectsTxtRecordCount = 0;
}

// 0x00640F00
void __fastcall DATATBLS_UnloadObjGroupTxt()
{
    DATATBLS_UnloadBin(gpObjgroupTxt);
    gpObjgroupTxt = 0;
    gnObjgroupTxtRecordCount = 0;
}

#include "gen/data/Source/D2Common/Unknown_0063F690.inc"
