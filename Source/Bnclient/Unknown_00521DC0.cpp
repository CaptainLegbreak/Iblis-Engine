#include "Bnclient.h"
#include "D2BnCryptTypes.h"

struct D2CDKeyInfoStrc;

struct D2AuthCheckPacketStrc;

struct D2CDKeyInfoStrc
{
    unsigned int dwKeyLength;
    unsigned int dwProductValue;
    unsigned int f_8;
    unsigned int f_C;
    unsigned int dwHash[5];
};

struct D2AuthCheckPacketStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int f_8;
    unsigned int nKeys;
    unsigned int bSpawn;
    D2CDKeyInfoStrc pKeys[2];
    char szData[0x200];
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" long __cdecl _time32(long* pTime); // 0x006850E6

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

int __cdecl sub_0051BEC0_IsExpansion(); // 0x0051BEC0

int __fastcall sub_0051E340_BuildCDKeyInfoForSlot(D2CDKeyInfoStrc* pInfo, unsigned int dwClientToken, int nSlot); // 0x0051E340

int __fastcall BNDOWNLOAD_RunCheckRevision(unsigned int* pExeVersion, unsigned int* pExeHash, char* szText); // 0x0051E6D0

int __cdecl BNDOWNLOAD_HasArchiveName(); // 0x0051EAA0

int __fastcall BNMESSQUEUE_SetError(int nError); // 0x005204A0

int __cdecl GAME_GetAbortFlag(); // 0x00520AE0

void __cdecl GRID_LockCDKeys(); // 0x005234D0

void __cdecl GRID_UnlockCDKeys(); // 0x005239C0

const char* __cdecl GAME_GetExeInfo(); // 0x00523AA0

extern "C" const char* __fastcall sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

unsigned int __fastcall sub_00523020_GetAlignedData(unsigned int nSize); // 0x00523020

void __fastcall sub_005241C0_GetDigest(int nIndex, unsigned int* pDigest); // 0x005241C0

void __fastcall sub_00524200_HashBlock(int nIndex, const void* pBlock, unsigned int* pDigest); // 0x00524200

void __fastcall sub_00524760_CipherBlock(int nIndex, const unsigned short* pIn, unsigned short* pOut); // 0x00524760

void __cdecl sub_00524740_ClearKeySchedules(); // 0x00524740

void __cdecl sub_005241A0_ClearHashContexts(); // 0x005241A0

unsigned int gdwBnClientToken; // 0x00882530

// 0x00521DC0
int __cdecl sub_00521DC0_SendAuthCheck()
{
    D2AuthCheckPacketStrc tPacket;
    memset(&tPacket, 0, sizeof(tPacket));

    const long nTime = _time32(0);
    gdwBnClientToken += GetTickCount() + nTime;
    tPacket.f_0 = gdwBnClientToken;

    if (!BNDOWNLOAD_HasArchiveName())
    {
        do
        {
            if (GAME_GetAbortFlag())
            {
                return 0;
            }

            Sleep(10);
        }
        while (!BNDOWNLOAD_HasArchiveName());
    }

    char szText[0x100];
    if (!BNDOWNLOAD_RunCheckRevision(&tPacket.f_4, &tPacket.f_8, szText))
    {
        BNMESSQUEUE_SetError(1);
        return 0;
    }

    tPacket.bSpawn = 0;
    GRID_LockCDKeys();

    char* pString;
    if (sub_0051BEC0_IsExpansion())
    {
        pString = &tPacket.szData[SStrCopy(tPacket.szData, szText, 0x200) + 1];
        tPacket.nKeys = 2;
        sub_0051E340_BuildCDKeyInfoForSlot(&tPacket.pKeys[0], gdwBnClientToken, 0);
        sub_0051E340_BuildCDKeyInfoForSlot(&tPacket.pKeys[1], gdwBnClientToken, 1);
        SStrCopy(pString, GAME_GetExeInfo(), &tPacket.szData[0x200] - pString);
    }
    else
    {
        char* pData = (char*)&tPacket.pKeys[1];
        pString = &pData[SStrCopy(pData, szText, 0x200) + 1];
        tPacket.nKeys = 1;
        sub_0051E340_BuildCDKeyInfoForSlot(&tPacket.pKeys[0], gdwBnClientToken, 0);
        SStrCopy(pString, GAME_GetExeInfo(), &pData[0x200] - pString);
    }

    GRID_UnlockCDKeys();
// build: symbol ?BNSEND_SendPacket@* 0x0051C5C0
    BNSEND_SendPacket(0x51, &tPacket, (pString - (char*)&tPacket) + SStrLen(pString) + 1);
    return 1;
}
