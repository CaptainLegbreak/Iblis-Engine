#include "D2Client.h"

#include "D2ClientMenus.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall DIALOG_DestroyDialog(void* pRes); // 0x004B8020

void __cdecl NPCMENU_BuildNpcMenu(); // 0x004B4830

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

extern char gbNpcMessageShown; // 0x007C0C69

typedef char check_size_npcentry[(sizeof(D2NpcEntryStrc) == 0x16) ? 1 : -1];

int __cdecl sub_004B1D70_FindNpcEntry(); // 0x004B1D70

void __stdcall NPCMENU_OpenNpcPanel(int nStringIndex, int nEntryIndex); // 0x004B5890

extern D2NpcEntryStrc gaNpcEntries[]; // 0x00726850

void __stdcall NPCMENU_OpenConfirmDialog(int nStringIndex); // 0x004B5AD0

void __cdecl sub_004B5140(); // 0x004B5140

extern void (__cdecl* gpfnCallback_00726E59)(); // 0x00726E59

extern unsigned short gwGlobal_00726E4D; // 0x00726E4D

class D2NpcTradeObjStrc
{
public:
    virtual ~D2NpcTradeObjStrc();
    virtual void Draw(); virtual void Slot02(); virtual void Slot03(); virtual void Slot04(); virtual void Slot05();
    virtual void Slot06(); virtual void Slot07(); virtual void Slot08(); virtual void Slot09(); virtual void Slot10();
    virtual int GetCount();
    virtual void sub_004BBFB0();
    virtual unsigned int GetAt(int nIndex);
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char*, const char*, int); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09

// 0x004B5BC0
int __cdecl sub_004B5BC0_SelectNpcEntry()
{
// build: symbol ?gnNpcMenuState@* 0x007C0C6B
    gnNpcMenuState = 1;
    int nIndex = sub_004B1D70_FindNpcEntry();
// build: symbol ?gpNpcEntry@* 0x007C0C7D
    gpNpcEntry = &gaNpcEntries[nIndex];
    NPCMENU_OpenNpcPanel(0xD35, nIndex);
    return 1;
}

