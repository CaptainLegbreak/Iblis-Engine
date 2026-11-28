#include "D2Common.h"
#include "D2CommonInternal.h"

#include "D2TxtTables.h"

#include "D2Records.h"

#include "D2Unicode.h"
#include "D2Txt.h"
#include "FogApi.h"

struct D2PoolSystemStrc;
struct D2BinFieldStrc;

struct D2SkillsTxt;

struct D2PetTypeTxt;

typedef unsigned int size_t;

struct D2PetTypeTxt
{
    char unk0x00[0xBC];
    int nSkillCount;
    short wSkillIds[15];
    short unk0xDE;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern D2TxtLinkStrc* gpPettypeLinker; // 0x0096C81C




extern int gnPettypeTxtRecordCount; // 0x0096C820

extern void* gpSkillsCode; // 0x0096BC70

extern void* gpSkillDescCode; // 0x0096BC7C



void __stdcall sub_006BD230_AddRecordToLinker(D2TxtLinkStrc* pLinker, int nCode); // 0x006BD230

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

extern D2TxtLinkStrc* gpPlayerClassLinker_0096BC34; // 0x0096BC34

extern D2TxtLinkStrc* gpElemTypesLinker; // 0x0096BC4C

extern D2TxtLinkStrc* gpPlrModeLinker; // 0x0096BC64

extern D2TxtLinkStrc* gpEventsLinker_0096BCA8; // 0x0096BCA8

extern D2TxtLinkStrc* gpStatesLinker_0096BCF0; // 0x0096BCF0

extern D2TxtLinkStrc* gpSoundsLinker_0096BDC8; // 0x0096BDC8

extern D2TxtLinkStrc* gpMissilesLinker; // 0x0096C798

extern D2TxtLinkStrc* gpSkillDescLinker; // 0x0096C7C0

extern D2TxtLinkStrc* gpSkillsLinker_0096C7CC; // 0x0096C7CC

extern D2TxtLinkStrc* gpOverlayLinker; // 0x0096C7E8

extern D2TxtLinkStrc* gpItemStatCostLinker_0096C800; // 0x0096C800

extern D2TxtLinkStrc* gpItemTypesLinker_0096C824; // 0x0096C824

extern int gbCompileTxt; // 0x0096C8B4

extern void* gpSkillDescTxt; // 0x0096C7BC

extern int gnSkillDescTxtRecordCount; // 0x0096C7C4

extern D2SkillsTxt* gpSkillsTxt; // 0x0096C7C8

extern int gnSkillsTxtRecordCount; // 0x0096C7D0

extern int* gpClassSkillCount; // 0x0096C7D4

extern int gnHighestClassSkillCount; // 0x0096C7D8

extern short* gpClassSkillList; // 0x0096C7DC

extern int gnPassiveSkills; // 0x0096C7E0

extern short* gpPassiveSkills; // 0x0096C7E4

extern D2PetTypeTxt* gpPettypeTxt_0096C818; // 0x0096C818

extern int gnSkillsCodeSize; // 0x0096BC74

extern int gnSkillsCodeSizeEx; // 0x0096BC78

extern int gnSkillDescCodeSize; // 0x0096BC80

extern int gnSkillDescCodeSizeEx; // 0x0096BC84

// 0x00613F80
void __stdcall DATATBLS_LoadSkills_SkillDescTxt(void* hArchive)
{
    D2TxtLinkStrc* pRangeLinker = 0;
    D2TxtLinkStrc* pMonStatsLinker = 0;
    D2TxtLinkStrc* pSkillDescLinker = 0;
    int nRecordCount;
    void* pMonStats = 0;
    void* pSkillDesc = 0;
    D2SkillsTxt* pSkillsTxtRecord = 0;

    D2BinFieldStrc pSkillDescTbl[] =
    {
        { "skilldesc", 17, 0, 0, &gpSkillDescLinker },
        { "skillpage", 4, 0, 2, 0 },
        { "skillrow", 4, 0, 3, 0 },
        { "skillcolumn", 4, 0, 4, 0 },
        { "ListRow", 4, 0, 5, 0 },
        { "ListPool", 4, 0, 6, 0 },
        { "iconcel", 4, 0, 7, 0 },
        { "str name", 22, 0, 8, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "str short", 22, 0, 10, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "str long", 22, 0, 12, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "str alt", 22, 0, 14, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "str mana", 22, 0, 16, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "descdam", 3, 0, 18, 0 },
        { "descatt", 3, 0, 20, 0 },
        { "ddam calc1", 25, 0, 24, (void*)DATATBLS_SkillDescCalcLinker },
        { "ddam calc2", 25, 0, 28, (void*)DATATBLS_SkillDescCalcLinker },
        { "p1dmelem", 13, 0, 32, &gpElemTypesLinker },
        { "p1dmmin", 25, 0, 36, (void*)DATATBLS_SkillDescCalcLinker },
        { "p1dmmax", 25, 0, 48, (void*)DATATBLS_SkillDescCalcLinker },
        { "p2dmelem", 13, 0, 33, &gpElemTypesLinker },
        { "p2dmmin", 25, 0, 40, (void*)DATATBLS_SkillDescCalcLinker },
        { "p2dmmax", 25, 0, 52, (void*)DATATBLS_SkillDescCalcLinker },
        { "p3dmelem", 13, 0, 34, &gpElemTypesLinker },
        { "p3dmmin", 25, 0, 44, (void*)DATATBLS_SkillDescCalcLinker },
        { "p3dmmax", 25, 0, 56, (void*)DATATBLS_SkillDescCalcLinker },
        { "descmissile1", 20, 0, 60, &gpMissilesLinker },
        { "descmissile2", 20, 0, 62, &gpMissilesLinker },
        { "descmissile3", 20, 0, 64, &gpMissilesLinker },
        { "descline1", 4, 0, 66, 0 },
        { "desctexta1", 22, 0, 84, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "desctextb1", 22, 0, 118, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "desccalca1", 25, 0, 152, (void*)DATATBLS_SkillDescCalcLinker },
        { "desccalcb1", 25, 0, 220, (void*)DATATBLS_SkillDescCalcLinker },
        { "descline2", 4, 0, 67, 0 },
        { "desctexta2", 22, 0, 86, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "desctextb2", 22, 0, 120, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "desccalca2", 25, 0, 156, (void*)DATATBLS_SkillDescCalcLinker },
        { "desccalcb2", 25, 0, 224, (void*)DATATBLS_SkillDescCalcLinker },
        { "descline3", 4, 0, 68, 0 },
        { "desctexta3", 22, 0, 88, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "desctextb3", 22, 0, 122, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "desccalca3", 25, 0, 160, (void*)DATATBLS_SkillDescCalcLinker },
        { "desccalcb3", 25, 0, 228, (void*)DATATBLS_SkillDescCalcLinker },
        { "descline4", 4, 0, 69, 0 },
        { "desctexta4", 22, 0, 90, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "desctextb4", 22, 0, 124, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "desccalca4", 25, 0, 164, (void*)DATATBLS_SkillDescCalcLinker },
        { "desccalcb4", 25, 0, 232, (void*)DATATBLS_SkillDescCalcLinker },
        { "descline5", 4, 0, 70, 0 },
        { "desctexta5", 22, 0, 92, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "desctextb5", 22, 0, 126, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "desccalca5", 25, 0, 168, (void*)DATATBLS_SkillDescCalcLinker },
        { "desccalcb5", 25, 0, 236, (void*)DATATBLS_SkillDescCalcLinker },
        { "descline6", 4, 0, 71, 0 },
        { "desctexta6", 22, 0, 94, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "desctextb6", 22, 0, 128, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "desccalca6", 25, 0, 172, (void*)DATATBLS_SkillDescCalcLinker },
        { "desccalcb6", 25, 0, 240, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc2line1", 4, 0, 72, 0 },
        { "dsc2texta1", 22, 0, 96, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc2textb1", 22, 0, 130, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc2calca1", 25, 0, 176, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc2calcb1", 25, 0, 244, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc2line2", 4, 0, 73, 0 },
        { "dsc2texta2", 22, 0, 98, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc2textb2", 22, 0, 132, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc2calca2", 25, 0, 180, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc2calcb2", 25, 0, 248, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc2line3", 4, 0, 74, 0 },
        { "dsc2texta3", 22, 0, 100, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc2textb3", 22, 0, 134, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc2calca3", 25, 0, 184, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc2calcb3", 25, 0, 252, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc2line4", 4, 0, 75, 0 },
        { "dsc2texta4", 22, 0, 102, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc2textb4", 22, 0, 136, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc2calca4", 25, 0, 188, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc2calcb4", 25, 0, 256, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc3line1", 4, 0, 76, 0 },
        { "dsc3texta1", 22, 0, 104, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc3textb1", 22, 0, 138, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc3calca1", 25, 0, 192, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc3calcb1", 25, 0, 260, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc3line2", 4, 0, 77, 0 },
        { "dsc3texta2", 22, 0, 106, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc3textb2", 22, 0, 140, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc3calca2", 25, 0, 196, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc3calcb2", 25, 0, 264, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc3line3", 4, 0, 78, 0 },
        { "dsc3texta3", 22, 0, 108, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc3textb3", 22, 0, 142, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc3calca3", 25, 0, 200, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc3calcb3", 25, 0, 268, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc3line4", 4, 0, 79, 0 },
        { "dsc3texta4", 22, 0, 110, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc3textb4", 22, 0, 144, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc3calca4", 25, 0, 204, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc3calcb4", 25, 0, 272, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc3line5", 4, 0, 80, 0 },
        { "dsc3texta5", 22, 0, 112, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc3textb5", 22, 0, 146, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc3calca5", 25, 0, 208, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc3calcb5", 25, 0, 276, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc3line6", 4, 0, 81, 0 },
        { "dsc3texta6", 22, 0, 114, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc3textb6", 22, 0, 148, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc3calca6", 25, 0, 212, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc3calcb6", 25, 0, 280, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc3line7", 4, 0, 82, 0 },
        { "dsc3texta7", 22, 0, 116, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc3textb7", 22, 0, 150, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dsc3calca7", 25, 0, 216, (void*)DATATBLS_SkillDescCalcLinker },
        { "dsc3calcb7", 25, 0, 284, (void*)DATATBLS_SkillDescCalcLinker },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    D2BinFieldStrc pSkillsTbl[] =
    {
        { "skill", 17, 0, 0, &gpSkillsLinker_0096C7CC },
        { "charclass", 13, 0, 12, &gpPlayerClassLinker_0096BC34 },
        { "skilldesc", 20, 0, 404, &pSkillDescLinker },
        { "srvstfunc", 3, 0, 44, 0 },
        { "srvdofunc", 3, 0, 46, 0 },
        { "srvprgfunc1", 3, 0, 48, 0 },
        { "srvprgfunc2", 3, 0, 50, 0 },
        { "srvprgfunc3", 3, 0, 52, 0 },
        { "prgcalc1", 25, 0, 56, (void*)DATATBLS_SkillCalcLinker },
        { "prgcalc2", 25, 0, 60, (void*)DATATBLS_SkillCalcLinker },
        { "prgcalc3", 25, 0, 64, (void*)DATATBLS_SkillCalcLinker },
        { "prgdam", 4, 0, 68, 0 },
        { "srvmissile", 20, 0, 70, &gpMissilesLinker },
        { "srvmissilea", 20, 0, 72, &gpMissilesLinker },
        { "srvmissileb", 20, 0, 74, &gpMissilesLinker },
        { "srvmissilec", 20, 0, 76, &gpMissilesLinker },
        { "srvoverlay", 20, 0, 78, &gpOverlayLinker },
        { "lob", 26, 1, 4, 0 },
        { "decquant", 26, 0, 4, 0 },
        { "immediate", 26, 15, 4, 0 },
        { "aurafilter", 2, 0, 80, 0 },
        { "aurastate", 20, 0, 128, &gpStatesLinker_0096BCF0 },
        { "auratargetstate", 20, 0, 130, &gpStatesLinker_0096BCF0 },
        { "auralencalc", 25, 0, 96, (void*)DATATBLS_SkillCalcLinker },
        { "aurarangecalc", 25, 0, 100, (void*)DATATBLS_SkillCalcLinker },
        { "aurastat1", 20, 0, 84, &gpItemStatCostLinker_0096C800 },
        { "aurastatcalc1", 25, 0, 104, (void*)DATATBLS_SkillCalcLinker },
        { "aurastat2", 20, 0, 86, &gpItemStatCostLinker_0096C800 },
        { "aurastatcalc2", 25, 0, 108, (void*)DATATBLS_SkillCalcLinker },
        { "aurastat3", 20, 0, 88, &gpItemStatCostLinker_0096C800 },
        { "aurastatcalc3", 25, 0, 112, (void*)DATATBLS_SkillCalcLinker },
        { "aurastat4", 20, 0, 90, &gpItemStatCostLinker_0096C800 },
        { "aurastatcalc4", 25, 0, 116, (void*)DATATBLS_SkillCalcLinker },
        { "aurastat5", 20, 0, 92, &gpItemStatCostLinker_0096C800 },
        { "aurastatcalc5", 25, 0, 120, (void*)DATATBLS_SkillCalcLinker },
        { "aurastat6", 20, 0, 94, &gpItemStatCostLinker_0096C800 },
        { "aurastatcalc6", 25, 0, 124, (void*)DATATBLS_SkillCalcLinker },
        { "auraevent1", 20, 0, 132, &gpEventsLinker_0096BCA8 },
        { "auraeventfunc1", 3, 0, 138, 0 },
        { "auraevent2", 20, 0, 134, &gpEventsLinker_0096BCA8 },
        { "auraeventfunc2", 3, 0, 140, 0 },
        { "auraevent3", 20, 0, 136, &gpEventsLinker_0096BCA8 },
        { "auraeventfunc3", 3, 0, 142, 0 },
        { "auratgtevent", 20, 0, 144, &gpEventsLinker_0096BCA8 },
        { "auratgteventfunc", 3, 0, 146, 0 },
        { "passivestate", 20, 0, 148, &gpStatesLinker_0096BCF0 },
        { "passiveitype", 15, 0, 150, &gpItemTypesLinker_0096C824 },
        { "passivestat1", 20, 0, 152, &gpItemStatCostLinker_0096C800 },
        { "passivecalc1", 25, 0, 164, (void*)DATATBLS_SkillCalcLinker },
        { "passivestat2", 20, 0, 154, &gpItemStatCostLinker_0096C800 },
        { "passivecalc2", 25, 0, 168, (void*)DATATBLS_SkillCalcLinker },
        { "passivestat3", 20, 0, 156, &gpItemStatCostLinker_0096C800 },
        { "passivecalc3", 25, 0, 172, (void*)DATATBLS_SkillCalcLinker },
        { "passivestat4", 20, 0, 158, &gpItemStatCostLinker_0096C800 },
        { "passivecalc4", 25, 0, 176, (void*)DATATBLS_SkillCalcLinker },
        { "passivestat5", 20, 0, 160, &gpItemStatCostLinker_0096C800 },
        { "passivecalc5", 25, 0, 180, (void*)DATATBLS_SkillCalcLinker },
        { "passiveevent", 20, 0, 184, &gpEventsLinker_0096BCA8 },
        { "passiveeventfunc", 3, 0, 186, 0 },
        { "summon", 20, 0, 188, &pMonStatsLinker },
        { "pettype", 21, 0, 190, &gpPettypeLinker },
        { "summode", 13, 0, 191, &gpMonModeLinker },
        { "petmax", 25, 0, 192, (void*)DATATBLS_SkillCalcLinker },
        { "sumskill1", 20, 0, 196, &gpSkillsLinker_0096C7CC },
        { "sumsk1calc", 25, 0, 208, (void*)DATATBLS_SkillCalcLinker },
        { "sumskill2", 20, 0, 198, &gpSkillsLinker_0096C7CC },
        { "sumsk2calc", 25, 0, 212, (void*)DATATBLS_SkillCalcLinker },
        { "sumskill3", 20, 0, 200, &gpSkillsLinker_0096C7CC },
        { "sumsk3calc", 25, 0, 216, (void*)DATATBLS_SkillCalcLinker },
        { "sumskill4", 20, 0, 202, &gpSkillsLinker_0096C7CC },
        { "sumsk4calc", 25, 0, 220, (void*)DATATBLS_SkillCalcLinker },
        { "sumskill5", 20, 0, 204, &gpSkillsLinker_0096C7CC },
        { "sumsk5calc", 25, 0, 224, (void*)DATATBLS_SkillCalcLinker },
        { "sumumod", 3, 0, 228, 0 },
        { "sumoverlay", 20, 0, 230, &gpOverlayLinker },
        { "cltmissile", 20, 0, 232, &gpMissilesLinker },
        { "cltmissilea", 20, 0, 234, &gpMissilesLinker },
        { "cltmissileb", 20, 0, 236, &gpMissilesLinker },
        { "cltmissilec", 20, 0, 238, &gpMissilesLinker },
        { "cltmissiled", 20, 0, 240, &gpMissilesLinker },
        { "cltstfunc", 3, 0, 242, 0 },
        { "cltdofunc", 3, 0, 244, 0 },
        { "cltprgfunc1", 3, 0, 246, 0 },
        { "cltprgfunc2", 3, 0, 248, 0 },
        { "cltprgfunc3", 3, 0, 250, 0 },
        { "stsuccessonly", 26, 12, 4, 0 },
        { "stsound", 20, 0, 252, &gpSoundsLinker_0096BDC8 },
        { "stsoundclass", 20, 0, 254, &gpSoundsLinker_0096BDC8 },
        { "stsounddelay", 26, 13, 4, 0 },
        { "weaponsnd", 26, 14, 4, 0 },
        { "dosound", 20, 0, 256, &gpSoundsLinker_0096BDC8 },
        { "dosound a", 20, 0, 258, &gpSoundsLinker_0096BDC8 },
        { "dosound b", 20, 0, 260, &gpSoundsLinker_0096BDC8 },
        { "tgtsound", 20, 0, 266, &gpSoundsLinker_0096BDC8 },
        { "tgtoverlay", 20, 0, 264, &gpOverlayLinker },
        { "castoverlay", 20, 0, 262, &gpOverlayLinker },
        { "cltoverlaya", 20, 0, 272, &gpOverlayLinker },
        { "cltoverlayb", 20, 0, 274, &gpOverlayLinker },
        { "prgsound", 20, 0, 270, &gpSoundsLinker_0096BDC8 },
        { "prgoverlay", 20, 0, 268, &gpOverlayLinker },
        { "cltcalc1", 25, 0, 276, (void*)DATATBLS_SkillCalcLinker },
        { "cltcalc2", 25, 0, 280, (void*)DATATBLS_SkillCalcLinker },
        { "cltcalc3", 25, 0, 284, (void*)DATATBLS_SkillCalcLinker },
        { "warp", 26, 38, 4, 0 },
        { "anim", 13, 0, 16, &gpPlrModeLinker },
        { "seqtrans", 13, 0, 18, &gpPlrModeLinker },
        { "monanim", 13, 0, 17, &gpMonModeLinker },
        { "seqnum", 4, 0, 19, 0 },
        { "seqinput", 4, 0, 22, 0 },
        { "range", 13, 0, 20, &pRangeLinker },
        { "weapsel", 4, 0, 360, 0 },
        { "itypea1", 15, 0, 24, &gpItemTypesLinker_0096C824 },
        { "itypea2", 15, 0, 26, &gpItemTypesLinker_0096C824 },
        { "itypea3", 15, 0, 28, &gpItemTypesLinker_0096C824 },
        { "etypea1", 15, 0, 36, &gpItemTypesLinker_0096C824 },
        { "etypea2", 15, 0, 38, &gpItemTypesLinker_0096C824 },
        { "itypeb1", 15, 0, 30, &gpItemTypesLinker_0096C824 },
        { "itypeb2", 15, 0, 32, &gpItemTypesLinker_0096C824 },
        { "itypeb3", 15, 0, 34, &gpItemTypesLinker_0096C824 },
        { "etypeb1", 15, 0, 40, &gpItemTypesLinker_0096C824 },
        { "etypeb2", 15, 0, 42, &gpItemTypesLinker_0096C824 },
        { "maxlvl", 3, 0, 300, 0 },
        { "progressive", 26, 2, 4, 0 },
        { "finishing", 26, 3, 4, 0 },
        { "prgstack", 26, 7, 4, 0 },
        { "InTown", 26, 8, 4, 0 },
        { "ResultFlags", 3, 0, 302, 0 },
        { "HitFlags", 8, 0, 304, 0 },
        { "HitClass", 8, 0, 308, 0 },
        { "Kick", 26, 9, 4, 0 },
        { "passive", 26, 4, 4, 0 },
        { "aura", 26, 5, 4, 0 },
        { "periodic", 26, 6, 4, 0 },
        { "perdelay", 25, 0, 296, (void*)DATATBLS_SkillCalcLinker },
        { "general", 26, 35, 4, 0 },
        { "scroll", 26, 36, 4, 0 },
        { "ItemEffect", 3, 0, 362, 0 },
        { "ItemCltEffect", 3, 0, 364, 0 },
        { "ItemTgtDo", 26, 29, 4, 0 },
        { "ItemCheckStart", 26, 33, 4, 0 },
        { "ItemCltCheckStart", 26, 34, 4, 0 },
        { "ItemTarget", 4, 0, 288, 0 },
        { "ItemCastSound", 20, 0, 290, &gpSoundsLinker_0096BDC8 },
        { "ItemCastOverlay", 20, 0, 292, &gpOverlayLinker },
        { "InGame", 26, 10, 4, 0 },
        { "lineofsight", 4, 0, 399, 0 },
        { "attackrank", 4, 0, 398, 0 },
        { "noammo", 26, 16, 4, 0 },
        { "enhanceable", 26, 17, 4, 0 },
        { "durability", 26, 18, 4, 0 },
        { "UseAttackRate", 26, 19, 4, 0 },
        { "SelectProc", 4, 0, 21, 0 },
        { "TargetableOnly", 26, 20, 4, 0 },
        { "SearchEnemyXY", 26, 21, 4, 0 },
        { "SearchEnemyNear", 26, 22, 4, 0 },
        { "SearchOpenXY", 26, 23, 4, 0 },
        { "TargetCorpse", 26, 24, 4, 0 },
        { "TargetPet", 26, 25, 4, 0 },
        { "TargetAlly", 26, 26, 4, 0 },
        { "TargetItem", 26, 27, 4, 0 },
        { "AttackNoMana", 26, 28, 4, 0 },
        { "leftskill", 26, 30, 4, 0 },
        { "interrupt", 26, 31, 4, 0 },
        { "TgtPlaceCheck", 26, 32, 4, 0 },
        { "repeat", 26, 11, 4, 0 },
        { "skpoints", 25, 0, 368, (void*)DATATBLS_SkillCalcLinker },
        { "reqlevel", 3, 0, 372, 0 },
        { "reqstr", 3, 0, 374, 0 },
        { "reqdex", 3, 0, 376, 0 },
        { "reqint", 3, 0, 378, 0 },
        { "reqvit", 3, 0, 380, 0 },
        { "reqskill1", 20, 0, 382, &gpSkillsLinker_0096C7CC },
        { "reqskill2", 20, 0, 384, &gpSkillsLinker_0096C7CC },
        { "reqskill3", 20, 0, 386, &gpSkillsLinker_0096C7CC },
        { "delay", 25, 0, 400, (void*)DATATBLS_SkillCalcLinker },
        { "usemanaondo", 26, 37, 4, 0 },
        { "startmana", 3, 0, 388, 0 },
        { "minmana", 3, 0, 390, 0 },
        { "manashift", 3, 0, 392, 0 },
        { "mana", 3, 0, 394, 0 },
        { "lvlmana", 3, 0, 396, 0 },
        { "Param1", 2, 0, 328, 0 },
        { "Param2", 2, 0, 332, 0 },
        { "Param3", 2, 0, 336, 0 },
        { "Param4", 2, 0, 340, 0 },
        { "Param5", 2, 0, 344, 0 },
        { "Param6", 2, 0, 348, 0 },
        { "Param7", 2, 0, 352, 0 },
        { "Param8", 2, 0, 356, 0 },
        { "calc1", 25, 0, 312, (void*)DATATBLS_SkillCalcLinker },
        { "calc2", 25, 0, 316, (void*)DATATBLS_SkillCalcLinker },
        { "calc3", 25, 0, 320, (void*)DATATBLS_SkillCalcLinker },
        { "calc4", 25, 0, 324, (void*)DATATBLS_SkillCalcLinker },
        { "ToHit", 2, 0, 408, 0 },
        { "LevToHit", 2, 0, 412, 0 },
        { "ToHitCalc", 25, 0, 416, (void*)DATATBLS_SkillCalcLinker },
        { "HitShift", 4, 0, 420, 0 },
        { "SrcDam", 4, 0, 421, 0 },
        { "MinDam", 2, 0, 424, 0 },
        { "MinLevDam1", 2, 0, 432, 0 },
        { "MinLevDam2", 2, 0, 436, 0 },
        { "MinLevDam3", 2, 0, 440, 0 },
        { "MinLevDam4", 2, 0, 444, 0 },
        { "MinLevDam5", 2, 0, 448, 0 },
        { "MaxDam", 2, 0, 428, 0 },
        { "MaxLevDam1", 2, 0, 452, 0 },
        { "MaxLevDam2", 2, 0, 456, 0 },
        { "MaxLevDam3", 2, 0, 460, 0 },
        { "MaxLevDam4", 2, 0, 464, 0 },
        { "MaxLevDam5", 2, 0, 468, 0 },
        { "DmgSymPerCalc", 25, 0, 472, (void*)DATATBLS_SkillCalcLinker },
        { "EType", 13, 0, 476, &gpElemTypesLinker },
        { "EMin", 2, 0, 480, 0 },
        { "EMinLev1", 2, 0, 488, 0 },
        { "EMinLev2", 2, 0, 492, 0 },
        { "EMinLev3", 2, 0, 496, 0 },
        { "EMinLev4", 2, 0, 500, 0 },
        { "EMinLev5", 2, 0, 504, 0 },
        { "EMax", 2, 0, 484, 0 },
        { "EMaxLev1", 2, 0, 508, 0 },
        { "EMaxLev2", 2, 0, 512, 0 },
        { "EMaxLev3", 2, 0, 516, 0 },
        { "EMaxLev4", 2, 0, 520, 0 },
        { "EMaxLev5", 2, 0, 524, 0 },
        { "EDmgSymPerCalc", 25, 0, 528, (void*)DATATBLS_SkillCalcLinker },
        { "ELen", 2, 0, 532, 0 },
        { "ELevLen1", 2, 0, 536, 0 },
        { "ELevLen2", 2, 0, 540, 0 },
        { "ELevLen3", 2, 0, 544, 0 },
        { "ELenSymPerCalc", 25, 0, 548, (void*)DATATBLS_SkillCalcLinker },
        { "restrict", 4, 0, 552, 0 },
        { "state1", 20, 0, 554, &gpStatesLinker_0096BCF0 },
        { "state2", 20, 0, 556, &gpStatesLinker_0096BCF0 },
        { "state3", 20, 0, 558, &gpStatesLinker_0096BCF0 },
        { "aitype", 4, 0, 560, 0 },
        { "aibonus", 3, 0, 562, 0 },
        { "cost mult", 2, 0, 564, 0 },
        { "cost add", 2, 0, 568, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    if (gbCompileTxt)
    {
        pRangeLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 1311);
        sub_006BD230_AddRecordToLinker(pRangeLinker, 0x656E6F6E);
        sub_006BD230_AddRecordToLinker(pRangeLinker, 0x20683268);
        sub_006BD230_AddRecordToLinker(pRangeLinker, 0x20676E72);
        sub_006BD230_AddRecordToLinker(pRangeLinker, 0x68746F62);
        sub_006BD230_AddRecordToLinker(pRangeLinker, 0x20636F6C);

        D2BinFieldStrc pMonStatsTbl[] =
        {
            { "Id", 17, 0, 0, &pMonStatsLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        pMonStatsLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 1324);
        pMonStats = DATATBLS_CompileTxt(hArchive, "monstats", pMonStatsTbl, &nRecordCount, 2);

        D2BinFieldStrc pSkillDescLinkTbl[] =
        {
            { "skilldesc", 17, 0, 0, &pSkillDescLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        pSkillDescLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 1333);
        pSkillDesc = DATATBLS_CompileTxt(hArchive, "skilldesc", pSkillDescLinkTbl, &nRecordCount, 2);
    }

    gpSkillsLinker_0096C7CC = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 1340);
    gpSkillsTxt = (D2SkillsTxt*)DATATBLS_CompileTxt(hArchive, "skills", pSkillsTbl, &gnSkillsTxtRecordCount, sizeof(D2SkillsTxt));
    D2_ASSERT(gnSkillsTxtRecordCount < 32767, 1342);

    gnPassiveSkills = 0;

    gpSkillDescLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 1346);
    gpSkillDescTxt = DATATBLS_CompileTxt(hArchive, "skilldesc", pSkillDescTbl, &gnSkillDescTxtRecordCount, 288);
    D2_ASSERT(gnSkillDescTxtRecordCount < 32767, 1348);

    if (gbCompileTxt)
    {
        FOG_FreeLinker(pRangeLinker);
        FOG_FreeLinker(pMonStatsLinker);
        DATATBLS_UnloadBin(pMonStats);
        FOG_FreeLinker(pSkillDescLinker);
        DATATBLS_UnloadBin(pSkillDesc);
    }

    DATATBLS_GetBinFileHandle(hArchive, "skillscode", &gpSkillsCode, &gnSkillsCodeSize, &gnSkillsCodeSizeEx);
    DATATBLS_GetBinFileHandle(hArchive, "skilldesccode", &gpSkillDescCode, &gnSkillDescCodeSize, &gnSkillDescCodeSizeEx);

    gpClassSkillCount = (int*)FOG_AllocPool(0, 7 * sizeof(int), ".\\DATATBLS\\DataTbls.cpp", 1366, 0);
    for (int nClass = 0; nClass < 7; ++nClass)
    {
        gpClassSkillCount[nClass] = 0;
    }

    int nSkillId;
    for (nSkillId = 0; nSkillId < gnSkillsTxtRecordCount; ++nSkillId)
    {
        pSkillsTxtRecord = &gpSkillsTxt[nSkillId];
        if (pSkillsTxtRecord->nCharClass >= 0 && pSkillsTxtRecord->nCharClass < 7)
        {
            ++gpClassSkillCount[pSkillsTxtRecord->nCharClass];
        }

        if (nSkillId > 0)
        {
            if (pSkillsTxtRecord->nPassiveState < 0)
            {
                goto NextSkill;
            }
        }
        else
        {
            if (pSkillsTxtRecord->nPassiveState < 0)
            {
                goto NextSkill;
            }
        }
        ++gnPassiveSkills;
NextSkill:
        ;
    }

    gnHighestClassSkillCount = 0;
    for (int nClass = 0; nClass < 7; ++nClass)
    {
        if (gpClassSkillCount[nClass] > gnHighestClassSkillCount)
        {
            gnHighestClassSkillCount = gpClassSkillCount[nClass];
        }
    }

    gpClassSkillList = (short*)FOG_AllocPool(0, sizeof(short) * 7 * gnHighestClassSkillCount, ".\\DATATBLS\\DataTbls.cpp", 1398, 0);
    memset(gpClassSkillList, 0, sizeof(short) * 7 * gnHighestClassSkillCount);

    for (int nClass = 0; nClass < 7; ++nClass)
    {
        gpClassSkillCount[nClass] = 0;
    }

    gpPassiveSkills = (short*)FOG_AllocPool(0, sizeof(short) * gnPassiveSkills, ".\\DATATBLS\\DataTbls.cpp", 1402, 0);
    memset(gpPassiveSkills, 0, sizeof(short) * gnPassiveSkills);
    gnPassiveSkills = 0;

    for (int i = 0; i < gnSkillsTxtRecordCount; ++i)
    {
        pSkillsTxtRecord = &gpSkillsTxt[i];
        if (pSkillsTxtRecord->nCharClass >= 0 && pSkillsTxtRecord->nCharClass < 7)
        {
            gpClassSkillList[pSkillsTxtRecord->nCharClass * gnHighestClassSkillCount + gpClassSkillCount[pSkillsTxtRecord->nCharClass]] = i;
            ++gpClassSkillCount[pSkillsTxtRecord->nCharClass];
        }

        if (pSkillsTxtRecord->nPassiveState >= 0)
        {
            gpPassiveSkills[gnPassiveSkills] = i;
            ++gnPassiveSkills;
        }
    }

    for (nSkillId = 0; nSkillId < gnSkillsTxtRecordCount; ++nSkillId)
    {
        if (gpSkillsTxt[nSkillId].nPetType >= 0 && gpSkillsTxt[nSkillId].nPetType < gnPettypeTxtRecordCount)
        {
            D2PetTypeTxt* pPetTypeTxtRecord = &gpPettypeTxt_0096C818[gpSkillsTxt[nSkillId].nPetType];
            if (pPetTypeTxtRecord->nSkillCount < 15)
            {
                pPetTypeTxtRecord->wSkillIds[pPetTypeTxtRecord->nSkillCount] = nSkillId;
                ++pPetTypeTxtRecord->nSkillCount;
            }
        }
    }
}
