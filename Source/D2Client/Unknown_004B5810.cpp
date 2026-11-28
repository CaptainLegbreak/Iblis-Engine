#include "D2Client.h"
#include "D2ClientFuncs.h"

#include "D2ClientMenus.h"
#include "FogApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }



int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

#include "D2ClientNpcMenu.h"

typedef char check_size_npcentry[(sizeof(D2NpcEntryStrc) == 0x16) ? 1 : -1];



extern D2NpcEntryStrc gaNpcEntries[]; // 0x00726850


void __cdecl sub_004B5140(); // 0x004B5140



class D2NpcTradeObjStrc
{
public:
    virtual ~D2NpcTradeObjStrc();
    virtual void Draw(); virtual void Slot02(); virtual void Slot03(); virtual void Slot04(); virtual void Slot05();
    virtual void Slot06(); virtual void Slot07(); virtual void Slot08(); virtual void Slot09(); virtual void Slot10();
    virtual int GetCount();
    virtual void sub_004BBFB0_GetRepeatStep();
    virtual unsigned int GetAt(int nIndex);
};

extern "C" const char gszEmptyAssertText; // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09

// 0x004B5BC0
int __cdecl sub_004B5BC0_SelectNpcEntry()
{
    gtNpcMenu.nMenuState = 1;
    int nIndex = sub_004B1D70_FindNpcEntry();
    gtNpcMenu.pEntry = &gaNpcEntries[nIndex];
    NPCMENU_OpenNpcPanel(0xD35, nIndex);
    return 1;
}

