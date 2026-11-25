#include "D2StatIds.h"

#include "D2Client.h"

#include "D2Structs.h"

#include "D2LevelTxt.h"

#include "D2DataTbls.h"

#include "D2PlayerModes.h"

#include "D2MonModes.h"

struct D2StatesTxt;

typedef void (__fastcall* CLIENTSTATEFN)(D2UnitStrc* pUnit, int nState);

int __fastcall SKILLS_CallClientStateEvent(void* pArg1, int nArg2, int nArg3, int nArg4, unsigned int nIndex, int nArg6, int nArg7); // 0x004C7C40

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern CLIENTSTATEFN gpfnClientStateSetFuncs[]; // 0x0072A690

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

void __fastcall CUNITEVENT_RemoveCltUnitEvents(D2UnitStrc* pUnit, int nParam4, int nParam5); // 0x004DC190

extern CLIENTSTATEFN gpfnClientStateRemFuncs[]; // 0x0072A710

typedef char check_pointer_width[sizeof(void*)==4?1:-1];

typedef char check_scalar_width[sizeof(unsigned int)==4?1:-1];

extern "C" int __stdcall SKILLS_GetUseState(D2UnitStrc* unit,D2SkillStrc* skill); // 0x00647960

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

int __cdecl sub_0044DA90(); // 0x0044DA90

int __cdecl GAME_GetSkillDelayUntil(); // 0x0044CE50

// 0x004D9FC0
extern "C" int __fastcall sub_004D9FC0(D2UnitStrc* unit,D2SkillStrc* skill)
{
    int status = SKILLS_GetUseState(unit,skill);
    if (status)
        return status;
    if (unit == sub_00463DE0_GetPlayerUnit())
    {
        unsigned int first = sub_0044DA90();
        unsigned int second = GAME_GetSkillDelayUntil();
        if (first < second)
            return 8;
    }
    return 0;
}
