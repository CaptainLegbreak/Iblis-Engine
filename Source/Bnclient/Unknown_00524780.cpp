struct D2IdeaUserKeyStrc
{
    unsigned char aKey[16];
};

struct D2IdeaKeyScheduleStrc
{
    unsigned short aKey[52];
};

void __fastcall sub_00524360_ExpandKey(const D2IdeaUserKeyStrc* pUserKey, D2IdeaKeyScheduleStrc* pSchedule); // 0x00524360
void __fastcall sub_005243E0_InvertKey(const unsigned short* pEK, unsigned short* pDK);                    // 0x005243E0

D2IdeaKeyScheduleStrc gaIdeaKeySchedules[3];                                                      // 0x00882878

// 0x00524780
void __fastcall sub_00524780_SetKey(int nIndex, int bEncrypt, const D2IdeaUserKeyStrc* pUserKey)
{
    D2IdeaUserKeyStrc tUserKey = *pUserKey;
    if (bEncrypt)
    {
        sub_00524360_ExpandKey(&tUserKey, &gaIdeaKeySchedules[nIndex]);
    }
    else
    {
        D2IdeaKeyScheduleStrc tTemp;
        sub_00524360_ExpandKey(&tUserKey, &tTemp);
        sub_005243E0_InvertKey(tTemp.aKey, gaIdeaKeySchedules[nIndex].aKey);
    }
}
