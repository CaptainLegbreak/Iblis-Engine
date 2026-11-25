#include "D2ClientUi.h"
#include "D2ClientSound.h"

#pragma pack(push, 1)
struct D2TimedHintEntryStrc
{
    int bUsed;
    int nHintId;
    int nKey;
    char unk0x0C[0x20];
    void* f_2C;
    int nState;
    char unk0x34[0x09];
    int f_3D;
    char unk0x41[0x18];
};
#pragma pack(pop)

typedef char check_size_hintentry[(sizeof(D2TimedHintEntryStrc) == 0x59) ? 1 : -1];

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall sub_004B9590(int nKey);                                                                      // 0x004B9590
int __fastcall sub_004DFA40_IsSoundPlaying(void* pSound);                                                   // 0x004DFA40
int __fastcall sub_004DF900_GetSoundPosition(void* pSound);                                                 // 0x004DF900
D2SoundsTxt* __fastcall SOUNDHDR_GetSoundRecord(int nId);                                                         // 0x00481860
void __fastcall SOUNDINST_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount);               // 0x004B9EF0
int __cdecl sub_004817F0();                                                                                 // 0x004817F0
int __cdecl sub_00481800();                                                                                 // 0x00481800

extern D2TimedHintNodeStrc* gpClientSoundList;                                                       // 0x007C5458


// 0x004B95C0
int __fastcall sub_004B95C0_IsHintPlaying(int nKey)
{
    if (nKey)
    {
        for (D2TimedHintNodeStrc* pNode = gpClientSoundList; pNode; pNode = pNode->pNext)
        {
            D2TimedHintEntryStrc* pEntry = pNode->pEntry;
            if (pEntry->nKey == nKey)
            {
                void* pSound = pEntry->f_2C;
                if (pSound && sub_004B9590(nKey) && sub_004DFA40_IsSoundPlaying(pSound))
                {
                    return 1;
                }

                break;
            }
        }
    }

    return 0;
}
