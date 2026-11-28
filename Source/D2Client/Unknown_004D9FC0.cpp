#include "D2StatIds.h"

#include "D2Client.h"
#include "D2ClientFuncs.h"

#include "D2Structs.h"

#include "D2LevelTxt.h"

#include "D2DataTbls.h"

#include "D2PlayerModes.h"

#include "D2MonModes.h"
#include "D2CommonApi.h"
#include "D2CommonApi2.h"

struct D2StatesTxt;

typedef void (__fastcall* CLIENTSTATEFN)(D2UnitStrc* pUnit, int nState);




extern unsigned int gdwBitMasks[]; // 0x006CE268

extern CLIENTSTATEFN gpfnClientStateSetFuncs[]; // 0x0072A690

extern D2DataTablesStrc* sgptDataTables; // 0x00744304


extern CLIENTSTATEFN gpfnClientStateRemFuncs[]; // 0x0072A710

typedef char check_pointer_width[sizeof(void*)==4?1:-1];

typedef char check_scalar_width[sizeof(unsigned int)==4?1:-1];


int __cdecl sub_0044DA90_GetTickCounter(); // 0x0044DA90


// 0x004D9FC0
extern "C" int __fastcall sub_004D9FC0_GetSkillUseState(D2UnitStrc* unit,D2SkillStrc* skill)
{
    int status = SKILLS_GetUseState(unit,skill);
    if (status)
        return status;
    if (unit == sub_00463DE0_GetPlayerUnit())
    {
        unsigned int first = sub_0044DA90_GetTickCounter();
        unsigned int second = GAME_GetSkillDelayUntil();
        if (first < second)
            return 8;
    }
    return 0;
}
