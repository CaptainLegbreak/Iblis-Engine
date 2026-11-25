#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2CelContext.h"
#include "D2TxtTables.h"
#include "D2ClientGfx.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

D2GfxMotionStrc* __fastcall GFX_GetGfxMotion(D2UnitStrc* pUnit);                                   // 0x0046F060

D2TokRecord* __stdcall DATATBLS_GetMonModeTxtRecord(unsigned int nIndex, int bGetMode);                     // 0x0065B500

D2TokRecord* __stdcall DATATBLS_GetCompositTxtRecord(int nComposit);                                        // 0x0065B5E0

D2TokRecord* __stdcall DATATBLS_GetArmTypeTxtRecord(int nId);                                               // 0x0065B620

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380



#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))

struct B28Unit;

struct B28Waypoint;

extern "C" int __stdcall sub_004FB180_Palette(unsigned char red, unsigned char green, unsigned char blue);

extern "C" B28Waypoint* __stdcall WAYPOINTS_AllocWaypointData(void* pool); // 0x00660F30

extern "C" void __fastcall sub_004786D0_SendPacket(unsigned char command, unsigned int arg1, unsigned int arg2, unsigned int arg3);

extern "C" void __fastcall sub_004FAAE0_FreeArchive(void* archive);

extern "C" void* __fastcall sub_0040B380_Alloc(int size, const char* file, int line, int flags);

extern "C" void* __fastcall sub_0040B430_AllocPool(void* pool, int size, const char* file, int line, int flags);

extern "C" const char szB28SoundSource[];

extern "C" const char szB28AiSource[];

extern "C" unsigned char gB28Palette;

extern "C" B28Waypoint* gB28Waypoint;

extern "C" unsigned char gB28WaypointFlag;

extern "C" unsigned int gB28SubmitItem;

extern "C" unsigned int gB28SubmitFlag;

extern "C" void* gB28Archive;

struct B28GfxData
{
    unsigned char pad0[0x34];
    int offsetX;
};

extern "C" B28GfxData* __fastcall sub_0046F060_GetGfx(B28Unit* unit);

struct B28SoundNode
{
    unsigned int value;
    B28SoundNode* next;
};

struct B28AiCmd
{
    B28AiCmd* pNextCmd;
    B28AiCmd* pPrevCmd;
    int param0;
    int param1;
    int param2;
    int param3;
    int f_18;
};

struct B28AiControl
{
    unsigned char pad0[0x20];
    B28AiCmd* pCurrentCmd;
    B28AiCmd* pLastCmd;
};

struct B28MonsterData
{
    unsigned char pad0[0x28];
    B28AiControl* pAiControl;
};

struct B28Unit
{
    unsigned int type;
    unsigned char pad4[0x10];
    B28MonsterData* monsterData;
};

struct B28Game
{
    unsigned char pad0[0x1C];
    void* pool;
};

typedef char AssertGfx[(OFFSET(B28GfxData,offsetX)==0x34)?1:-1];

typedef char AssertSoundNext[(OFFSET(B28SoundNode,next)==4)?1:-1];

typedef char AssertSoundSize[(sizeof(B28SoundNode)==8)?1:-1];

typedef char AssertAiSize[(sizeof(B28AiCmd)==0x1C)?1:-1];

typedef char AssertAiPrev[(OFFSET(B28AiCmd,pPrevCmd)==4)?1:-1];

typedef char AssertAiLast[(OFFSET(B28AiControl,pLastCmd)==0x24)?1:-1];

typedef char AssertMonsterAi[(OFFSET(B28MonsterData,pAiControl)==0x28)?1:-1];

typedef char AssertUnitData[(OFFSET(B28Unit,monsterData)==0x14)?1:-1];

typedef char AssertGamePool[(OFFSET(B28Game,pool)==0x1C)?1:-1];

// 0x004DA000
void __stdcall PARTICLE_ResetGfxMotion(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (!pMotion)
    {
        pMotion = (D2GfxMotionStrc*)FOG_Alloc(sizeof(D2GfxMotionStrc), ".\\ENGINE\\Particle.cpp", 72, 0);
        D2_ASSERT(pMotion, 74);
    }
    memset(pMotion, 0, sizeof(D2GfxMotionStrc));
    sub_0046F070_SetGfxMotion(pUnit, pMotion);
}

// 0x004DA070
D2GfxMotionStrc* __fastcall PARTICLE_GetGfxMotion(D2UnitStrc* pUnit)
{
    return GFX_GetGfxMotion(pUnit);
}

// 0x004DA080
void __stdcall PARTICLE_FreeGfxMotion(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        FOG_Free(pMotion, ".\\ENGINE\\Particle.cpp", 100, 0);
        sub_0046F070_SetGfxMotion(pUnit, 0);
    }
}

extern "C" void __cdecl sub_00497250_SetPalette()
{
    gB28Palette = (unsigned char)sub_004FB180_Palette(255, 0, 0);
}

// build: symbol _TEXT_InitWaypointData 0x0049C6A0
extern "C" void __cdecl TEXT_InitWaypointData()
{
    gB28Waypoint = WAYPOINTS_AllocWaypointData(0);
    gB28WaypointFlag = 0;
}

// build: symbol @NPCMENU_SendNpcAction@* 0x004B2370
extern "C" void __fastcall NPCMENU_SendNpcAction(unsigned int value)
{
    gB28SubmitFlag = 0;
    sub_004786D0_SendPacket(0x38, 0, gB28SubmitItem, value);
}

// 0x004DA0B0
extern "C" int __stdcall PARTICLE_GetGfxOffsetX(B28Unit* unit)
{
    B28GfxData* gfx = sub_0046F060_GetGfx(unit);
    if (gfx)
        return gfx->offsetX;
    return 0;
}

// 0x004DA0D0
int __stdcall PARTICLE_GetGfxClientY(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->nClientY;
    }
    return 0;
}

// 0x004DA0F0
int __stdcall PARTICLE_GetGfxClientZ(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->nClientZ;
    }
    return 0;
}

// build: symbol _LIST_UnloadPentspinCellfile 0x00507140
extern "C" void __cdecl LIST_UnloadPentspinCellfile()
{
    sub_004FAAE0_FreeArchive(gB28Archive);
    gB28Archive = 0;
}
