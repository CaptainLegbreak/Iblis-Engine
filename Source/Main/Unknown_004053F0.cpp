#include "StormApi.h"
#include "D2MultiTypes.h"
#include "D2LanguageNames.h"
#include "D2FogTypes.h"
#include "D2CmdArg.h"
#include "FogApi.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi2.h"
#include "StormApi2.h"
#define CMD_BOOLEAN 0
#define CMD_INTEGER 1
#define CMD_STRING 2
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2ConfigStrc;
struct D2IniEntryStrc;
struct Character;
struct D2CmdArgStrc;

extern "C" const char gszNew[]; // 0x006CC82C

struct D2IniEntryStrc
{
    char szSection[0x1B];
    char szKey[0x36];
    unsigned char nType;
    char pad0x52[2];
    int nOffset;
    int nDefault;
};

extern D2IniEntryStrc gaIniEntries_00705040[58]; // 0x00705040
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(dllimport) unsigned int __stdcall GetPrivateProfileIntA(const char* szAppName, const char* szKeyName, int nDefault, const char* szFileName); // 0x006CC150
extern "C" __declspec(dllimport) unsigned long __stdcall GetPrivateProfileStringA(const char* szAppName, const char* szKeyName, const char* szDefault, char* szReturned, unsigned long nSize, const char* szFileName); // 0x006CC420

struct Character { signed char value; };

enum { UPPER_FIRST = 65, UPPER_LAST = 90, CASE_DELTA = 32 };

extern "C" size_t __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" int __cdecl strcmp(const char* szA, const char* szB);
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" int __cdecl atoi(const char* szString); // 0x00681EBB


extern D2CmdArgStrc gaCmdArguments[58]; // 0x00705040
void __stdcall sub_00405450_LoadIniSettings(char* pSettings); // 0x00405450
int __fastcall sub_00405710_ParseCmdArgument(char* szCommandNameTestBuf, const char* pszCommand, char* szCommandValueBuf); // 0x00405710

void __cdecl operator delete(void* pMemory);
void* __cdecl operator new(size_t nSize);

// build: symbol ??3@YAXPAX@Z 0x004053F0
void __cdecl operator delete(void* pMemory)
{
    if (pMemory)
    {
        SMemFree(pMemory, "delete", -1, 0);
    }
}

// build: symbol ??2@YAPAXI@Z 0x00405410
void* __cdecl operator new(size_t nSize)
{
    return SMemAlloc(nSize, gszNew, -1, 0);
}

// 0x00405430
static inline void sub_00405430_GetIniPath(char* szPath)
{
    ERRORMANAGER_GetModuleDirectory(szPath, 0x104);
    SStrPack(szPath, "D2.ini", 0x104);
}

void __stdcall sub_M114_Emit_00405430(char* szPath)
{
    sub_00405430_GetIniPath(szPath);
}

// 0x00405450
void __stdcall sub_00405450_LoadIniSettings(char* pSettings)
{
    char szIni[0x104];
    ERRORMANAGER_GetModuleDirectory(szIni, 0x104);
    SStrPack(szIni, "D2.ini", 0x104);
    for (int i = 0; i < sizeof(gaIniEntries_00705040) / sizeof(gaIniEntries_00705040[0]); i++)
    {
        char* pDest = pSettings + gaIniEntries_00705040[i].nOffset;
        switch (gaIniEntries_00705040[i].nType)
        {
        case 0:
            *pDest = GetPrivateProfileIntA(gaIniEntries_00705040[i].szSection, gaIniEntries_00705040[i].szKey, gaIniEntries_00705040[i].nDefault, szIni) != 0;
            break;
        case 1:
            *(int*)pDest = GetPrivateProfileIntA(gaIniEntries_00705040[i].szSection, gaIniEntries_00705040[i].szKey, gaIniEntries_00705040[i].nDefault, szIni);
            break;
        case 2:
            GetPrivateProfileStringA(gaIniEntries_00705040[i].szSection, gaIniEntries_00705040[i].szKey, &gszEmptyAssertText, pDest, 0x1B, szIni);
            break;
        }
    }
}

D2IniEntryStrc gaIniEntries_00705040[58] = { // 0x00705040
    { "DEBUG", "CRASHAPP\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0crash", 0, "", 4, 0 },
    { "VIDEO", "WINDOW\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0w", 0, "", 8, 0 },
    { "VIDEO", "WINDOW\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0window", 0, "", 8, 0 },
    { "VIDEO", "WINDOW\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0windowed", 0, "", 8, 0 },
    { "VIDEO", "ASPECT\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0nofixaspect", 0, "", 9, 0 },
    { "VIDEO", "3DFX\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0" "3dfx", 0, "", 10, 0 },
    { "VIDEO", "OPENGL\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0opengl", 0, "", 11, 0 },
    { "VIDEO", "D3D\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0d3d", 0, "", 13, 0 },
    { "VIDEO", "RAVE\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0rave", 0, "", 12, 0 },
    { "VIDEO", "PERSPECTIVE\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0per", 0, "", 14, 0 },
    { "VIDEO", "QUALITY\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0lq", 0, "", 15, 0 },
    { "VIDEO", "GAMMA\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0gamma", 1, "", 16, 0 },
    { "VIDEO", "VSYNC\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0vsync", 0, "", 20, 0 },
    { "VIDEO", "FRAMERATE\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0fr", 1, "", 21, 0 },
    { "NETWORK", "SERVERIP\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0s", 2, "", 55, 0 },
    { "NETWORK", "GAMETYPE\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0gametype", 1, "", 25, 0 },
    { "NETWORK", "ARENA\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0arena", 1, "", 519, 0 },
    { "NETWORK", "JOINID\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0joinid", 1, "", 29, 0 },
    { "NETWORK", "GAMENAME\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0gamename", 2, "", 31, 0 },
    { "NETWORK", "BATTLENETIP\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0bn", 2, "", 79, 0 },
    { "NETWORK", "MCPIP\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0mcpip", 2, "", 103, 0 },
    { "CHARACTER", "AMAZON\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0ama", 0, "", 133, 1 },
    { "CHARACTER", "PALADIN\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0pal", 0, "", 134, 0 },
    { "CHARACTER", "SORCERESS\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0sor", 0, "", 135, 0 },
    { "CHARACTER", "NECROMANCER\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0nec", 0, "", 136, 0 },
    { "CHARACTER", "BARBARIAN\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0bar", 0, "", 137, 0 },
    { "CHARACTER", "INVINCIBLE\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0i", 0, "", 140, 0 },
    { "CHARACTER", "NAME\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0name", 2, "", 189, 0 },
    { "CHARACTER", "REALM\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0realm", 2, "", 213, 0 },
    { "CHARACTER", "CTEMP\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0ctemp", 1, "", 493, 0 },
    { "MONSTER", "NOMONSTERS\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0nm", 0, "", 497, 0 },
    { "MONSTER", "MONSTERCLASS\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0m", 1, "", 498, 0 },
    { "MONSTER", "MONSTERINFO\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0minfo", 0, "", 502, 0 },
    { "MONSTER", "MONSTERDEBUG\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0md", 1, "", 503, 0 },
    { "ITEM", "RARE\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0rare", 0, "", 507, 0 },
    { "ITEM", "UNIQUE\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0unique", 0, "", 508, 0 },
    { "INTERFACE", "ACT\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0act", 1, "", 511, 1 },
    { "DEBUG", "LOG\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0log", 0, "", 534, 0 },
    { "DEBUG", "MSGLOG\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0msglog", 0, "", 535, 0 },
    { "DEBUG", "SAFEMODE\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0safe", 0, "", 536, 0 },
    { "DEBUG", "NOSAVE\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0nosave", 0, "", 537, 0 },
    { "DEBUG", "SEED\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0seed", 1, "", 538, 0 },
    { "NETWORK", "NOPK\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0nopk", 0, "", 131, 0 },
    { "DEBUG", "CHEATS\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0cheats", 0, "", 542, 0 },
    { "DEBUG", "TEEN\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0teen", 0, "", 543, 0 },
    { "DEBUG", "NOSOUND\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0ns", 0, "", 544, 0 },
    { "FILEIO", "NOPREDLOAD\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0npl", 0, "", 515, 0 },
    { "FILEIO", "DIRECT\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0direct", 0, "", 516, 0 },
    { "FILEIO", "LOWEND\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0lem", 0, "", 517, 0 },
    { "DEBUG", "QuEsTs\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0questall", 0, "", 545, 0 },
    { "NETWORK", "COMINT\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0comint", 1, "", 549, 0 },
    { "NETWORK", "SKIPTOBNET\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0skiptobnet", 0, "", 861, 0 },
    { "NETWORK", "OPENC\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0openc", 0, "", 132, 0 },
    { "FILEIO", "NOCOMPRESS\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0nocompress", 0, "", 518, 0 },
    { "TXT", "TXT\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0txt", 0, "", 533, 0 },
    { "BUILD", "BUILD\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0build", 0, "", 547, 0 },
    { "DEBUG", "NOSOUND\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0nosound", 0, "", 544, 0 },
    { "DEBUG", "SOUNDBKG\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0sndbkg", 0, "", 548, 0 }
};

// 0x00405550
void __fastcall MAIN_ToLowerInPlace(Character* text)
{
    while(text->value) {
        if(text->value>=UPPER_FIRST && text->value<=UPPER_LAST)
            text->value+=CASE_DELTA;
        ++text;
    }
}

// 0x00405570
int __stdcall GetCmdIndex(const char* s)
{
    for (size_t i = 0; i < ARRAY_SIZE(gaCmdArguments); i++)
    {
        if (0 == strcmp(gaCmdArguments[i].szCommand, s))
        {
            return (int)i;
        }
    }
    return -1;
}

// 0x004055D0
int __fastcall ERRORMANAGER_IsCmdSeparator(char c)
{
    const char aSeparators[4] = { ' ', '\t', '\n', ':' };
    for (int i = 0; i < 4; i++)
    {
        if (aSeparators[i] == c)
        {
            return 1;
        }
    }
    return 0;
}

static void __fastcall sub_00405550_stoLower_Inl(char* s)
{
    for (int i = 0; s[i]; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 'a' - 'A';
        }
    }
}

// 0x00405610
static void ParseCmdValue(char* s)
{
    char szBuf[0x100];
    strcpy(szBuf, s);
    const int nLen = strlen(s);
    int i = 0;
    for (; i < nLen; i++)
    {
        if (!ERRORMANAGER_IsCmdSeparator(s[i]))
        {
            break;
        }
    }
    int nOut = 0;
    for (; i < nLen; i++)
    {
        if (ERRORMANAGER_IsCmdSeparator(szBuf[i]))
        {
            break;
        }
        s[nOut++] = szBuf[i];
    }
    s[nOut] = 0;
}

// 0x00405710
int __fastcall sub_00405710_ParseCmdArgument(char* szCommandNameTestBuf, const char* pszCommand, char* szCommandValueBuf)
{
    char szCommand[0x100];
    const int nRemainingLen = strlen(pszCommand);
    int nCommandIndex = -1;
    int i = 0;
    D2_ASSERT(nRemainingLen < 0x100, 259);
    while (i < nRemainingLen && pszCommand[i] != '-' && pszCommand[i] != '\0')
    {
        szCommand[i] = pszCommand[i];
        i++;
    }
    szCommand[i] = '\0';
    szCommand[i + 1] = '\0';
    strcpy(szCommandNameTestBuf, szCommand);
    int nCommandLength = strlen(szCommandNameTestBuf);
    int bContinue = 1;
    sub_00405550_stoLower_Inl(szCommandNameTestBuf);
    for (; nCommandLength != 0 && bContinue; nCommandLength--)
    {
        szCommandNameTestBuf[nCommandLength] = '\0';
        nCommandIndex = GetCmdIndex(szCommandNameTestBuf);
        if (nCommandIndex != -1)
        {
            bContinue = 0;
        }
    }
    const int nCommandValueOffset = strlen(szCommandNameTestBuf);
    int nValueIdx = 0;
    for (; szCommand[nValueIdx]; nValueIdx++)
    {
        szCommandValueBuf[nValueIdx] = szCommand[nCommandValueOffset + nValueIdx];
    }
    szCommandValueBuf[nValueIdx] = '\0';
    ParseCmdValue(szCommandValueBuf);
    return nCommandIndex;
}

// 0x004058A0
static void __stdcall sub_004058A0_ParseCmdArgs(D2ConfigStrc* pCfg, const char* argv)
{
    char szCommandNameTestBuf[0x100];
    char szCommandValueBuf[0x100];

    const int nArgvLength = strlen(argv);
    for (int nCharIndex = 0; nCharIndex < nArgvLength; nCharIndex++)
    {
        if (argv[nCharIndex] != '-')
        {
            continue;
        }
        nCharIndex++;

        if (nCharIndex < nArgvLength)
        {
            const int nCommandIndex = sub_00405710_ParseCmdArgument(szCommandNameTestBuf, &argv[nCharIndex], szCommandValueBuf);
            if (nCommandIndex != -1)
            {
                void* pCfgMember = (char*)pCfg + gaCmdArguments[nCommandIndex].nIndex;

                switch (gaCmdArguments[nCommandIndex].nType)
                {
                case CMD_INTEGER:
                    *(int*)pCfgMember = atoi(szCommandValueBuf);
                    break;
                case CMD_STRING:
                    strcpy((char*)pCfgMember, szCommandValueBuf);
                    break;
                case CMD_BOOLEAN:
                    *(unsigned char*)pCfgMember = 1;
                    break;
                }
            }
        }
    }
}

// 0x004059A0
void __fastcall ParseCmdLine(D2ConfigStrc* pCfg, const char* argv)
{
    memset(pCfg, 0, 0x3CD);
    sub_00405450_LoadIniSettings((char*)pCfg);
    IGNORELIST_CreateIgnoreList();
    sub_004058A0_ParseCmdArgs(pCfg, argv);
}
