#include "D2BnCryptTypes.h"

void __fastcall sub_00524360_ExpandKey(const D2IdeaUserKeyStrc* pUserKey, D2IdeaKeyScheduleStrc* pSchedule); // 0x00524360
void __fastcall sub_005243E0_InvertKey(const unsigned short* pEK, unsigned short* pDK);                    // 0x005243E0
void __fastcall sub_00524540_Cipher(const unsigned short* pIn, unsigned short* pOut, const unsigned short* pKey); // 0x00524540

extern D2IdeaKeyScheduleStrc gaIdeaKeySchedules[];                                                // 0x00882878

// 0x00524760
void __fastcall sub_00524760_CipherBlock(int nIndex, const unsigned short* pIn, unsigned short* pOut)
{
    sub_00524540_Cipher(pIn, pOut, gaIdeaKeySchedules[nIndex].aKey);
}

void __fastcall sub_00524780_SetKey(int nIndex, int bEncrypt, const D2IdeaUserKeyStrc* pUserKey); // 0x00524780
