#include "D2Primitives.h"
#include "D2DataTbls.h"

int __stdcall sub_00410B30(unsigned char* pBitBuffer, int nBit);                                    // 0x00410B30
void __stdcall sub_00410B10(unsigned char* pBitBuffer, int nBit);                                   // 0x00410B10
void __stdcall sub_00410B50(unsigned char* pBitBuffer, int nBit);                                  // 0x00410B50
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBitBuffer, unsigned char* pBuffer, int nBufferSize);   // 0x00410E40
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
#pragma intrinsic(memcpy)

#define QR_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0065C310
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* hQuestRecord, int nQuest, int nState)
{
    QR_ASSERT(hQuestRecord, 31);

    return sub_00410B30(hQuestRecord->pBuffer, nState + 16 * nQuest) != 0;
}

// 0x0065C360
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* hQuestRecord, int nQuest, int nState)
{
    QR_ASSERT(hQuestRecord, 41);

    sub_00410B10(hQuestRecord->pBuffer, nState + 16 * nQuest);
}

// 0x0065C3A0
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* hQuestRecord, int nQuest, int nState)
{
    QR_ASSERT(hQuestRecord, 52);

    sub_00410B50(hQuestRecord->pBuffer, nState + 16 * nQuest);
}

// 0x0065C3E0
void __stdcall QUESTRECORD_ResetIntermediateStateFlags(D2BitBufferStrc* hQuestRecord, int nQuest)
{
    QR_ASSERT(hQuestRecord, 62);

    for (int i = 2; i <= 11; ++i)
    {
        sub_00410B50(hQuestRecord->pBuffer, 16 * nQuest + i);
    }
}

// 0x0065C430
D2BitBufferStrc* __stdcall QUESTRECORD_AllocRecord(void* pMemPool)
{
    D2BitBufferStrc* pBitBuffer = (D2BitBufferStrc*)sub_0040B430(pMemPool, sizeof(D2BitBufferStrc), ".\\QuestRecord\\QuestRecord.cpp", 80, 0);
    unsigned char* pBuffer = (unsigned char*)sub_0040B430(pMemPool, sizeof(unsigned short) * 48, ".\\QuestRecord\\QuestRecord.cpp", 81, 0);
    memset(pBuffer, 0, sizeof(unsigned short) * 48);

    BITMANIP_Initialize(pBitBuffer, pBuffer, sizeof(unsigned short) * 48);

    return pBitBuffer;
}

// 0x0065C490
void __stdcall QUESTRECORD_FreeRecord(void* pMemPool, D2BitBufferStrc* pQuestRecord)
{
    if (pQuestRecord)
    {
        sub_0040B480(pMemPool, pQuestRecord->pBuffer, ".\\QuestRecord\\QuestRecord.cpp", 96, 0);
        sub_0040B480(pMemPool, pQuestRecord, ".\\QuestRecord\\QuestRecord.cpp", 97, 0);
    }
}

// 0x0065C4D0
void __stdcall QUESTRECORD_CopyBufferToRecord(D2BitBufferStrc* pQuestRecord, unsigned char* pBuffer, unsigned short wBufSize, int bResetStates)
{
    QR_ASSERT(wBufSize == (sizeof(unsigned short) * 48), 110);

    memcpy(pQuestRecord->pBuffer, pBuffer, sizeof(unsigned short) * 48);

    if (bResetStates)
    {
        for (int i = 0; i < 42; ++i)
        {
            sub_00410B50(pQuestRecord->pBuffer, 16 * i + 13);
            sub_00410B50(pQuestRecord->pBuffer, 16 * i + 14);

            if (sub_00410B30(pQuestRecord->pBuffer, 16 * i + 1))
            {
                sub_00410B10(pQuestRecord->pBuffer, 16 * i + 15);
            }
        }
    }
}

// 0x0065C560
void __stdcall QUESTRECORD_CopyRecordToBuffer(D2BitBufferStrc* pQuestRecord, unsigned char* pBuffer, unsigned short wBufSize, int nUnused)
{
    QR_ASSERT(wBufSize == (sizeof(unsigned short) * 48), 132);

    memcpy(pBuffer, pQuestRecord->pBuffer, sizeof(unsigned short) * 48);
}
struct D2PropertiesTxt
{
    unsigned short wProp;
    unsigned char nSet[7];
    char unk0x09;
    unsigned short wVal[7];
    unsigned char nFunc[7];
    char unk0x1F;
    unsigned short wStat[7];
};

extern D2DataTablesStrc* sgptDataTables;  // 0x00744304

// 0x0065C5A0
const D2PropertiesTxt* __fastcall QUESTRECORD_GetPropertiesTxtRecord(int nProperty)
{
    if (nProperty >= 0 && nProperty < sgptDataTables->nPropertiesTxtRecordCount)
    {
        return &sgptDataTables->pPropertiesTxt[nProperty];
    }
    return 0;
}


#include "gen/data/Source/D2Common/QuestRecord/QuestRecord.inc"
