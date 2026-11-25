#pragma intrinsic(strlen, strcpy)

struct D2HoverTextStrc;

typedef unsigned int size_t;

struct D2HoverTextStrc
{
    unsigned int dwDisplayTime;
    unsigned int dwExpireTime;
    unsigned char nLangId;
    unsigned char pad0x09[3];
    int bUsed;
    char szMsg[256];
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, size_t nCount); // 0x00687330
int __cdecl STRTABLE_GetLanguage(); // 0x00525150

// 0x00661110
D2HoverTextStrc* __stdcall CHAT_AllocHoverMsg(void* pMemPool, const char* szText, int nTimeout)
{
    const int nTextLength = strlen(szText);
    if (!nTextLength)
    {
        return 0;
    }

    const int nLength = nTextLength >= 255 ? 255 - 1 : nTextLength;

    D2HoverTextStrc* pHoverMsg = (D2HoverTextStrc*)sub_0040B430(pMemPool, sizeof(D2HoverTextStrc), ".\\Chat\\Chat.cpp", 50, 0);
    pHoverMsg->dwDisplayTime = 8 * nLength + 125;
    pHoverMsg->dwExpireTime = pHoverMsg->dwDisplayTime + nTimeout;
    pHoverMsg->bUsed = 0;
    strncpy(pHoverMsg->szMsg, szText, nLength + 1);
    pHoverMsg->szMsg[nLength + 1] = '\0';
    pHoverMsg->nLangId = STRTABLE_GetLanguage();
    return pHoverMsg;
}

// 0x006611A0
void __stdcall CHAT_FreeHoverMsg(void* pMemPool, D2HoverTextStrc* pHoverMsg)
{
    if (pHoverMsg)
    {
        sub_0040B480(pMemPool, pHoverMsg, ".\\Chat\\Chat.cpp", 68, 0);
    }
}

// 0x006611C0
unsigned int __stdcall CHAT_GetDisplayTimeFromHoverMsg(D2HoverTextStrc* pHoverMsg)
{
    return pHoverMsg->dwDisplayTime;
}

// 0x006611D0
unsigned int __stdcall CHAT_GetTimeoutFromHoverMsg(D2HoverTextStrc* pHoverMsg)
{
    return pHoverMsg->dwExpireTime;
}

// 0x006611E0
void __stdcall CHAT_CopyHoverMsgToBuffer(D2HoverTextStrc* pHoverMsg, char* szMessage)
{
    strcpy(szMessage, pHoverMsg->szMsg);
}

// 0x00661200
int __stdcall CHAT_GetUsedFromHoverMsg(D2HoverTextStrc* pHoverMsg)
{
    return pHoverMsg->bUsed;
}

// 0x00661210
void __stdcall CHAT_SetUsedInHoverMsg(D2HoverTextStrc* pHoverMsg, int bUsed)
{
    pHoverMsg->bUsed = bUsed;
}

// 0x00661220
unsigned char __stdcall CHAT_GetLangIdFromHoverMsg(D2HoverTextStrc* pHoverMsg)
{
    return pHoverMsg->nLangId;
}

// 0x00661230
void __stdcall CHAT_SetLangIdInHoverMsg(D2HoverTextStrc* pHoverMsg, unsigned char nLangId)
{
    pHoverMsg->nLangId = nLangId;
}

#pragma pack(push, 1)
struct d2data_007465E8_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

extern "C" struct d2data_007465E8_t gData_007465E8; // 0x007465E8

extern "C" struct d2data_007465E8_t gData_007465E8 = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x007465E8
