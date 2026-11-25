#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

#define CP_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define COF_PAD 0x20
#define TOKEN_CHAR(c) ((char)(c) == COF_PAD ? 0 : (char)(c))

struct D2InventoryStrc;
struct D2CompositStrc;
struct D2UnitStrc;
struct D2ModeTypeTxt;
struct D2MonStatsTxt;
struct D2DataTablesStrc;


struct D2CompositStrc
{
    union
    {
        int nWeaponClassCode;
        unsigned int code;
    };
    int nWeaponClassId;
};

int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
int __stdcall COMPOSIT_GetWeaponClassCode(D2UnitStrc* pUnit, int nUnitType, int nClass, int nMode, D2InventoryStrc* pInventory, int* pWeaponClassId); // 0x0064F060
extern const D2CompositStrc gaWeaponClassCodeTable[13]; // 0x006EB748
extern "C" const char gszCompositSourceFile[]; // 0x006EB7B0
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2ModeTypeTxt {char pad[0x20]; unsigned int token;};



extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern D2CompositStrc gaCompositPlayerModes[]; // 0x00745900
extern unsigned int gnCompositPlayerModeCount; // 0x00745910
extern D2CompositStrc gaCompositMonsterModes[]; // 0x00745914
extern unsigned int gnCompositMonsterModeCount; // 0x0074591C
extern const char gChars_006DCC34[]; // 0x006DCC34
extern const char gMonsters_006D6CAC[]; // 0x006D6CAC
extern const char gObjects_006E3628[]; // 0x006E3628
extern const char gFormatPath_006D6C94[]; // 0x006D6C94
extern const char gszCofTokenFormat[]; // 0x006D5514
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char*,const char*,...); // 0x006CC468
D2ModeTypeTxt* __stdcall DATATBLS_GetPlrModeTypeTxtRecord(int,int); // 0x0065B480
D2ModeTypeTxt* __stdcall DATATBLS_GetMonModeTxtRecord(int,int); // 0x0065B500
D2ModeTypeTxt* __stdcall DATATBLS_GetObjModeTypeTxtRecord(int,int); // 0x0065B570
int __fastcall MONSTERREGION_CheckMonStats2Flag(int,int); // 0x004638A0

// 0x0064F020
int __stdcall COMPOSIT_GetWeaponClassIdFromCode(int nWeaponClassCode)
{
    for (int i = 0; i < 13; ++i)
    {
        if (gaWeaponClassCodeTable[i].nWeaponClassCode == nWeaponClassCode)
        {
            return gaWeaponClassCodeTable[i].nWeaponClassId;
        }
    }

    return 0;
}

inline int STATES_IsUnitShapeShiftedInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 3) & 1;
}

// 0x0064F380
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int bUseConvertedMode)
{
    if (!pUnit)
    {
        return ' hth';
    }

    int nType = pUnit->dwUnitType;
    int nClass = pUnit->dwClassId;

    if (nAnimMode == -1)
    {
        nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
    }

    if (STATES_IsUnitShapeShiftedInline(pUnit))
    {
        const int nMode = nAnimMode;
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, ".\\COMPOSIT\\Composit.cpp", 566);

        if (!bUseConvertedMode)
        {
            nAnimMode = nMode;
        }
    }

    return COMPOSIT_GetWeaponClassCode(pUnit, nType, nClass, nAnimMode, pInventory, pWeaponClassId);
}

// 0x0064F420
int __stdcall COMPOSIT_IsArmorComponent(int nComponent)
{
    return nComponent == 1 || nComponent == 2 || nComponent == 3 || nComponent == 4 || nComponent == 8 || nComponent == 9;
}

// 0x0064F460
int __stdcall COMPOSIT_IsWeaponBowOrXBow(D2UnitStrc* pUnit)
{
    int nWeaponClassId = 0;
    int nMode = -1;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    int nType = pUnit->dwUnitType;
    int nClass = pUnit->dwClassId;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);

    if (STATES_IsUnitShapeShiftedInline(pUnit))
    {
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\COMPOSIT\\Composit.cpp", 566);
    }

    COMPOSIT_GetWeaponClassCode(pUnit, nType, nClass, nMode, pInventory, &nWeaponClassId);

    return nWeaponClassId == 1 || nWeaponClassId == 7;
}

// 0x0064F500
unsigned int __stdcall COMPOSIT_GetArmorTypeFromComponent(int eComponent, unsigned char* pArmorComponents)
{
    CP_ASSERT(eComponent < 16, 613);

    switch (eComponent)
    {
    case 1:
        return pArmorComponents[2];

    case 2:
        return pArmorComponents[3];

    case 3:
        return pArmorComponents[0];

    case 4:
        return pArmorComponents[1];

    case 8:
        return pArmorComponents[4];

    case 9:
        return pArmorComponents[5];

    default:
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 628);
        exit(-1);
    }
}

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int id) {if(id>=0 && id<sgptDataTables->nMonStatsTxtRecordCount)return &sgptDataTables->pMonStatsTxt[id];return 0;}

static __forceinline void COMPOSIT_FormatPathInto(char* path,unsigned int classCode,unsigned int modeCode,int* weapon,const char* prefix,int full,char* w,char* c,char* m) {
 w[0]=TOKEN_CHAR(((char*)weapon)[0]);
 w[1]=TOKEN_CHAR(((char*)weapon)[1]);
 w[2]=TOKEN_CHAR(((char*)weapon)[2]);
 w[3]=0;
 c[0]=TOKEN_CHAR(((char*)&classCode)[0]);
 c[1]=TOKEN_CHAR(((char*)&classCode)[1]);
 c[2]=TOKEN_CHAR(((char*)&classCode)[2]);
 c[3]=0;
 m[0]=TOKEN_CHAR(((char*)&modeCode)[0]);
 m[1]=TOKEN_CHAR(((char*)&modeCode)[1]);
 m[2]=TOKEN_CHAR(((char*)&modeCode)[2]);
 m[3]=0;
 if(full)wsprintfA(path,gFormatPath_006D6C94,prefix,c,c,m,w);else wsprintfA(path,gszCofTokenFormat,c,m,w);
}

// 0x0064F5B0
void __stdcall D2Common_10884_COMPOSIT_unk(D2UnitStrc* unit,int cls,int mode,int type,D2InventoryStrc* inv,char* path,int* weapon,int full,int determine) {
 unsigned int clsCode;
 unsigned int modeCode;
 char wo[4],co[4],mo[4];
 switch(type){
 case 0:{
  char w[4],c[4],m[4];
  clsCode=DATATBLS_GetPlrModeTypeTxtRecord(cls,0)->token;
  modeCode=DATATBLS_GetPlrModeTypeTxtRecord(mode,1)->token;
  if(determine){if(mode && mode!=17){int weaponId;*weapon=COMPOSIT_GetWeaponClassCode(unit,0,cls,mode,inv,&weaponId);}else *weapon=0x20687468;}
  for(unsigned int i=0;i<gnCompositPlayerModeCount;++i)if(mode==gaCompositPlayerModes[i].nWeaponClassId)modeCode=gaCompositPlayerModes[i].code;
  if(mode==11 && *weapon!=0x20736831 && *weapon!=0x20746831 && *weapon!=0x20736A31 && *weapon!=0x20746A31 && *weapon!=0x20737331 && *weapon!=0x20747331)*weapon=0x20687468;
  COMPOSIT_FormatPathInto(path,clsCode,modeCode,weapon,gChars_006DCC34,full,w,c,m);return;
 }
 case 1:{
  char w[4],c[4],m[4];
  D2MonStatsTxt* record=DATATBLS_GetMonStatsTxtRecord(cls);if(!record)return;
  clsCode=record->dwCode;
  modeCode=DATATBLS_GetMonModeTxtRecord(mode,1)->token;
  if(mode && mode!=12){int weaponId;*weapon=COMPOSIT_GetWeaponClassCode(unit,1,cls,mode,inv,&weaponId);}
  else{if(MONSTERREGION_CheckMonStats2Flag(cls,16)){int weaponId;*weapon=COMPOSIT_GetWeaponClassCode(unit,1,cls,mode,inv,&weaponId);}else *weapon=0x20687468;}
  for(unsigned int i=0;i<gnCompositMonsterModeCount;++i)if(mode==gaCompositMonsterModes[i].nWeaponClassId)modeCode=gaCompositMonsterModes[i].code;
  COMPOSIT_FormatPathInto(path,clsCode,modeCode,weapon,gMonsters_006D6CAC,full,w,c,m);return;
 }
 case 2:
  clsCode=DATATBLS_GetObjModeTypeTxtRecord(cls,0)->token;
  modeCode=DATATBLS_GetObjModeTypeTxtRecord(mode,1)->token;
  {int weaponId;*weapon=COMPOSIT_GetWeaponClassCode(unit,2,cls,mode,inv,&weaponId);}
  break;
 default:
  return;
 }
 COMPOSIT_FormatPathInto(path,clsCode,modeCode,weapon,gObjects_006E3628,full,wo,co,mo);
}

// 0x0064FA00
void __stdcall D2Common_10885_COMPOSIT_unk(D2UnitStrc* hUnit, char* szPath, int* pWeaponClassCode, int bAddPathPrefix, int a5, D2InventoryStrc* pInventory, int nAnimMode)
{
    int nClass;
    int nType;
    int nMode;

    D2_ASSERT(hUnit, 262);

    nType = hUnit->dwUnitType;
    nClass = hUnit->dwClassId;
    nMode = UNITS_GetAnimOrSeqMode(hUnit);

    D2COMMON_11013_ConvertMode(hUnit, &nType, &nClass, &nMode, ".\\COMPOSIT\\Composit.cpp", 268);

    if (nAnimMode == -1)
    {
        nAnimMode = nMode;
    }

    D2Common_10884_COMPOSIT_unk(hUnit, nClass, nAnimMode, nType, pInventory, szPath, pWeaponClassCode, bAddPathPrefix, a5);
}

#include "gen/data/Source/D2Common/COMPOSIT/Composit.inc"
