#include "D2DataTbls.h"
#include "D2Records.h"
#pragma function(memset)

#define ARENA_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2TxtLinkStrc;
struct D2BinFieldStrc;
struct D2DataTablesStrc;
struct D2ArenaTxt;
struct D2CharTemplateTxt;



struct D2ArenaTxt
{
    int dwSuicide;
    int dwPlayerKill;
    int dwPlayerKillPercent;
    int dwMonsterKill;
    int dwPlayerDeath;
    int dwPlayerDeathPercent;
    int dwMonsterDeath;
};

struct D2CharTemplateTxt
{
    char szName[30];
    unsigned char nClass;
    unsigned char nLevel;
    char unk0x20[0xD0];
};

extern "C" const char gszTxtField_end[]; // 0x006D9060
extern "C" const char gszTxtField_int[]; // 0x006E67EC
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern D2ArenaTxt* gpArenaTxtTable; // 0x0096D608
extern D2CharTemplateTxt* gpCharTemplateTxtTable; // 0x0096D600
extern int gnCharTemplateTxtTableRecordCount; // 0x0096D604
extern int gnCharTemplateStartIds[64]; // 0x0096D500
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __stdcall DATATBLS_UnloadBin(void* pBinFile); // 0x006125C0

// 0x006649B0
void __fastcall DATATBLS_LoadArenaTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Suicide", 2, 0, 0, 0 },
        { "PlayerKill", 2, 0, 4, 0 },
        { "PlayerKillPercent", 2, 0, 8, 0 },
        { "MonsterKill", 2, 0, 12, 0 },
        { "PlayerDeath", 2, 0, 16, 0 },
        { "PlayerDeathPercent", 2, 0, 20, 0 },
        { "MonsterDeath", 2, 0, 24, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpArenaTxtTable = (D2ArenaTxt*)DATATBLS_CompileTxt(hArchive, "arena", pTbl, 0, sizeof(D2ArenaTxt));
}

D2ArenaTxt* gpArenaTxtTable; // 0x0096D608

D2CharTemplateTxt* gpCharTemplateTxtTable; // 0x0096D600

int gnCharTemplateTxtTableRecordCount; // 0x0096D604

int gnCharTemplateStartIds[64]; // 0x0096D500

// 0x00664AB0
D2ArenaTxt* __fastcall DATATBLS_GetArenaTxtRecord(int nArenaType)
{
    ARENA_ASSERT(nArenaType < 1, 65);

    return &gpArenaTxtTable[nArenaType];
}

// 0x00664AF0
void __fastcall DATATBLS_UnloadArenaTxt()
{
    DATATBLS_UnloadBin(gpArenaTxtTable);
    gpArenaTxtTable = 0;
}

// 0x00664B10
static void __stdcall DATATBLS_InitCharTemplateStartIds(D2CharTemplateTxt* pTemplateRecord, int nRecordCount)
{
    memset(gnCharTemplateStartIds, 0, sizeof(gnCharTemplateStartIds));

    int nMaxLevel = 0;
    for (int i = 0; i < nRecordCount; ++i)
    {
        int nLevel = pTemplateRecord[i].nLevel;
        ARENA_ASSERT(nLevel >= nMaxLevel, 92);

        if (nLevel > nMaxLevel)
        {
            gnCharTemplateStartIds[nLevel] = i;
            nMaxLevel = nLevel;
        }
    }
}

// 0x00664B80
void __fastcall DATATBLS_LoadCharTemplateTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Name", 1, 29, 0, 0 },
        { "class", 13, 0, 30, &sgptDataTables->pPlayerClassLinker },
        { "act", 4, 0, 32, 0 },
        { "level", 4, 0, 31, 0 },
        { "str", 4, 0, 33, 0 },
        { "dex", 4, 0, 34, 0 },
        { "vit", 4, 0, 36, 0 },
        { gszTxtField_int, 4, 0, 35, 0 },
        { "Hitpoints", 4, 0, 38, 0 },
        { "Mana", 4, 0, 37, 0 },
        { "ManaRegenBonus", 4, 0, 39, 0 },
        { "Velocity", 4, 0, 40, 0 },
        { "AttackRate", 4, 0, 41, 0 },
        { "OtherRate", 4, 0, 42, 0 },
        { "RightSkill", 2, 0, 44, 0 },
        { "Skill1", 2, 0, 48, 0 },
        { "SkillLevel1", 2, 0, 84, 0 },
        { "Skill2", 2, 0, 52, 0 },
        { "SkillLevel2", 2, 0, 88, 0 },
        { "Skill3", 2, 0, 56, 0 },
        { "SkillLevel3", 2, 0, 92, 0 },
        { "Skill4", 2, 0, 60, 0 },
        { "SkillLevel4", 2, 0, 96, 0 },
        { "Skill5", 2, 0, 64, 0 },
        { "SkillLevel5", 2, 0, 100, 0 },
        { "Skill6", 2, 0, 68, 0 },
        { "SkillLevel6", 2, 0, 104, 0 },
        { "Skill7", 2, 0, 72, 0 },
        { "SkillLevel7", 2, 0, 108, 0 },
        { "Skill8", 2, 0, 76, 0 },
        { "SkillLevel8", 2, 0, 112, 0 },
        { "Skill9", 2, 0, 80, 0 },
        { "SkillLevel9", 2, 0, 116, 0 },
        { "item1", 9, 0, 120, 0 },
        { "item1loc", 4, 0, 124, 0 },
        { "item1count", 4, 0, 125, 0 },
        { "item2", 9, 0, 128, 0 },
        { "item2loc", 4, 0, 132, 0 },
        { "item2count", 4, 0, 133, 0 },
        { "item3", 9, 0, 136, 0 },
        { "item3loc", 4, 0, 140, 0 },
        { "item3count", 4, 0, 141, 0 },
        { "item4", 9, 0, 144, 0 },
        { "item4loc", 4, 0, 148, 0 },
        { "item4count", 4, 0, 149, 0 },
        { "item5", 9, 0, 152, 0 },
        { "item5loc", 4, 0, 156, 0 },
        { "item5count", 4, 0, 157, 0 },
        { "item6", 9, 0, 160, 0 },
        { "item6loc", 4, 0, 164, 0 },
        { "item6count", 4, 0, 165, 0 },
        { "item7", 9, 0, 168, 0 },
        { "item7loc", 4, 0, 172, 0 },
        { "item7count", 4, 0, 173, 0 },
        { "item8", 9, 0, 176, 0 },
        { "item8loc", 4, 0, 180, 0 },
        { "item8count", 4, 0, 181, 0 },
        { "item9", 9, 0, 184, 0 },
        { "item9loc", 4, 0, 188, 0 },
        { "item9count", 4, 0, 189, 0 },
        { "item10", 9, 0, 192, 0 },
        { "item10loc", 4, 0, 196, 0 },
        { "item10count", 4, 0, 197, 0 },
        { "item11", 9, 0, 200, 0 },
        { "item11loc", 4, 0, 204, 0 },
        { "item11count", 4, 0, 205, 0 },
        { "item12", 9, 0, 208, 0 },
        { "item12loc", 4, 0, 212, 0 },
        { "item12count", 4, 0, 213, 0 },
        { "item13", 9, 0, 216, 0 },
        { "item13loc", 4, 0, 220, 0 },
        { "item13count", 4, 0, 221, 0 },
        { "item14", 9, 0, 224, 0 },
        { "item14loc", 4, 0, 228, 0 },
        { "item14count", 4, 0, 229, 0 },
        { "item15", 9, 0, 232, 0 },
        { "item15loc", 4, 0, 236, 0 },
        { "item15count", 4, 0, 237, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpCharTemplateTxtTable = (D2CharTemplateTxt*)DATATBLS_CompileTxt(hArchive, "chartemplate", pTbl, &gnCharTemplateTxtTableRecordCount, sizeof(D2CharTemplateTxt));
    DATATBLS_InitCharTemplateStartIds(gpCharTemplateTxtTable, gnCharTemplateTxtTableRecordCount);
}

// 0x00665740
void __fastcall DATATBLS_UnloadCharTemplateTxt()
{
    DATATBLS_UnloadBin(gpCharTemplateTxtTable);
    gpCharTemplateTxtTable = 0;
}

// 0x00665760
int __fastcall DATATBLS_GetCharTemplateTxtRecordCount()
{
    return gnCharTemplateTxtTableRecordCount;
}

// 0x00665770
D2CharTemplateTxt* __fastcall DATATBLS_GetCharTemplateTxtRecord(int nTemplate, int nLevel)
{
    ARENA_ASSERT(nTemplate > 0, 245);
    const int nIndex = gnCharTemplateStartIds[nLevel] + nTemplate - 1;
    ARENA_ASSERT(nIndex < gnCharTemplateTxtTableRecordCount, 248);

    return &gpCharTemplateTxtTable[nIndex];
}

// 0x006657C0
int __fastcall DATATBLS_GetClassFromCharTemplateTxtRecord(int nTemplate, int nLevel)
{
    return DATATBLS_GetCharTemplateTxtRecord(nTemplate, nLevel)->nClass;
}

#include "gen/data/Source/D2Common/DATATBLS/Arena.inc"
