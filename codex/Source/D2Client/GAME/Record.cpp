#include "D2Client.h"
#include "D2MsgRecord.h"
#include "D2WinSplitText.h"
#include "D2ClientUiRecords.h"

#define gpMsgRecordChunkHead_007A2760 (gtMsgRecordChunkFirst.pNext)
#define FILE_ATTRIBUTE_NORMAL 0x00000080
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define gnRecordCount_007A2758 (gFirstRecordBlock_007A0818.nCount)

struct D2MsgRecordStrc;
struct D2RecordFileHeaderStrc;
struct D2MsgRecordChunkStrc;
struct D2RecordBlockStrc;
struct D2RecordHeaderStrc;


int __stdcall SCmdRegisterArgument(unsigned int dwFlags, unsigned int dwId, const char* szName, void* pVariable, unsigned int nBytes, int bSet, void* pfnCallback, void* pParam); // 0x006C4580
int __fastcall FOG_Free(void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B3C0
extern D2MsgRecordChunkStrc gtMsgRecordChunkFirst; // 0x007A0818


struct D2RecordFileHeaderStrc
{
    int nVersion;
    int nBlocks;
    int nEntries;
    int nTick;
    int nSeed;
};

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C
int __cdecl sub_0044DA90(); // 0x0044DA90
int __stdcall DUNGEON_GetInitSeedFromAct(D2DrlgActStrc* pAct); // 0x0061AAC0
extern D2DrlgActStrc* gpAct; // 0x007A0634
void __stdcall RECORD_RecordMessage(unsigned int uMessage, unsigned int wParam, int lParam); // 0x00451450
int gbRecordHandlerInstalled; // 0x007A2780

struct D2RecordBlockStrc
{
    char aRecords[500 * 16];
    int nCount;
    int nPos;
    D2RecordBlockStrc* pNext;
};

struct D2RecordHeaderStrc
{
    int nVersion;
    int nBlocks;
    int nLastCount;
    int unk0x0C[2];
};
extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nBytes, unsigned long* pRead, void* pOverlapped);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
extern D2RecordBlockStrc gFirstRecordBlock_007A0818; // 0x007A0818
extern D2RecordHeaderStrc sgtReadFileHeader; // 0x007A2768
extern int gnRecordPos_007A2784; // 0x007A2784
extern int gbRecordPlaying_007A2788; // 0x007A2788

int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam, int* pbUseResult, int* plResult); // 0x00420B00

void* __cdecl WINDOW_GetWindow(); // 0x004F59A0

int gbPlaybackRequested;                                                                                     // 0x007A277C
int gnRecordPos; // 0x007A2784
int gnRecordInitSeed;                                                                              // 0x007A2778



// 0x00451400
void __cdecl RECORD_AddRecordChunk()
{
    D2MsgRecordChunkStrc* pChunk = (D2MsgRecordChunkStrc*)FOG_Alloc(sizeof(D2MsgRecordChunkStrc), ".\\GAME\\Record.cpp", 0x35, 0);
    D2MsgRecordChunkStrc* pOld = gpMsgRecordChunk_0070F7A0;
    pChunk->nCount = 0;
    pChunk->nIndex = 0;
    pOld->pNext = pChunk;
    pChunk->pNext = 0;
    gpMsgRecordChunk_0070F7A0 = pChunk;
}

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual void VirtSlot3();
    virtual void VirtSlot4();
    virtual int IsFiltered(const char* szText);
};

struct D2ChatMessageStrc { D2WinControlStrc* pControl; unsigned int nMessage; };

// 0x00451450
void __stdcall RECORD_RecordMessage(unsigned int uMessage, unsigned int wParam, int lParam)
{
    if (gpMsgRecordChunk_0070F7A0->nCount >= 500)
        RECORD_AddRecordChunk();
    D2MsgRecordStrc* pRecord = &gpMsgRecordChunk_0070F7A0->tRecords[gpMsgRecordChunk_0070F7A0->nCount++];
    pRecord->nTick = sub_0044DA90();
    pRecord->uMessage = uMessage;
    pRecord->wParam = wParam;
    pRecord->lParam = lParam;
}

// 0x004514B0
void __fastcall RECORD_RecordInputMessage(unsigned int uMessage, unsigned int wParam, int lParam)
{
    if (gbRecordHandlerInstalled)
    {
        switch (uMessage)
        {
        case 0x100:
        case 0x200:
            RECORD_RecordMessage(uMessage, wParam, lParam);
            return;
        case 0x10:
        case 0x101:
        case 0x102:
        case 0x111:
        case 0x201:
        case 0x202:
        case 0x204:
        case 0x205:
            RECORD_RecordMessage(uMessage, wParam, lParam);
            break;
        }
    }
}

D2MsgRecordChunkStrc gtMsgRecordChunkFirst; // 0x007A0818

// 0x00451620
void __cdecl RECORD_WriteRecordFile()
{
    void* hFile = CreateFileA("Record.dr1", GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

    D2MsgRecordChunkStrc* pChunk = &gtMsgRecordChunkFirst;
    D2RecordFileHeaderStrc tHeader;
    tHeader.nVersion = 1;
    tHeader.nBlocks = 1;
    while (pChunk->pNext)
    {
        ++tHeader.nBlocks;
        pChunk = pChunk->pNext;
    }
    tHeader.nEntries = pChunk->nCount + 500 * (tHeader.nBlocks - 1);
    tHeader.nTick = sub_0044DA90();
    tHeader.nSeed = DUNGEON_GetInitSeedFromAct(gpAct);

    unsigned long nSize = sizeof(tHeader);
    unsigned long nWritten;
    WriteFile(hFile, &nSize, sizeof(nSize), &nWritten, 0);
    WriteFile(hFile, &tHeader, sizeof(tHeader), &nWritten, 0);
    for (pChunk = &gtMsgRecordChunkFirst; pChunk; pChunk = pChunk->pNext)
    {
        WriteFile(hFile, pChunk, pChunk->nCount * sizeof(D2MsgRecordStrc), &nWritten, 0);
    }
    CloseHandle(hFile);
}

static D2RecordBlockStrc* gpMsgRecordChunk; // 0x0070F7A0

// 0x00451710
void __cdecl RECORD_LoadRecordFile()
{
    unsigned long nMagic;
    unsigned long nRead;
    void* hFile = CreateFileA("Record.dr1", 0x80000000, 0, 0, 3, 0x80, 0);
    ReadFile(hFile, &nMagic, 4, &nRead, 0);
    ReadFile(hFile, &sgtReadFileHeader, sizeof(D2RecordHeaderStrc), &nRead, 0);
    if (sgtReadFileHeader.nVersion != 1)
    {
        gnRecordPos_007A2784 = 0;
        gbRecordPlaying_007A2788 = 0;
        CloseHandle(hFile);
        return;
    }

    for (int i = 0; i < sgtReadFileHeader.nBlocks; ++i)
    {
        if (i)
        {
            D2RecordBlockStrc* pBlock = (D2RecordBlockStrc*)FOG_Alloc(sizeof(D2RecordBlockStrc), ".\\GAME\\Record.cpp", 0x35, 0);
            pBlock->nCount = 0;
            pBlock->nPos = 0;
            gpMsgRecordChunk->pNext = pBlock;
            pBlock->pNext = 0;
            gpMsgRecordChunk = pBlock;
        }

        if (sgtReadFileHeader.nLastCount <= 500)
        {
            gnRecordCount_007A2758 = sgtReadFileHeader.nLastCount;
            D2_ASSERT(i + 1 == sgtReadFileHeader.nBlocks, 0x100);
        }
        else
        {
            gnRecordCount_007A2758 = 500;
        }

        ReadFile(hFile, gpMsgRecordChunk, gnRecordCount_007A2758 * 16, &nRead, 0);
    }

    gpMsgRecordChunk = &gFirstRecordBlock_007A0818;
    CloseHandle(hFile);
}

// 0x00451850
void __cdecl RECORD_FreeMsgRecordChunks()
{
    D2MsgRecordChunkStrc* pChunk = gpMsgRecordChunkHead_007A2760;
    while (pChunk)
    {
        D2MsgRecordChunkStrc* pFree = pChunk;
        pChunk = pChunk->pNext;
        FOG_Free(pFree, ".\\GAME\\Record.cpp", 0x120, 0);
    }
}

// 0x00451880
int __fastcall RECORD_DispatchRecordedMessage(D2MsgRecordStrc* pMsg)
{
    int bUseResult = 0;
    int lResult = 0;
    D2_ASSERT(pMsg->nTick == sub_0044DA90(), 0x12A);
    return SMsgDispatchMessage(WINDOW_GetWindow(), pMsg->uMessage, pMsg->wParam, pMsg->lParam, &bUseResult, &lResult);
}


// 0x004518E0
void __cdecl RECORD_StartPlayback()
{
    if (gbPlaybackRequested)
        gbPlaybackRequested = 0;
    else
    {
        gnRecordPos = 1;
        RECORD_LoadRecordFile();
        GAME_SetInitSeed(gnRecordInitSeed);
    }
}


struct Unicode;

// 0x00451910
int __cdecl RECORD_IsRecordingEnabled()
{
    return gbPlaybackRequested;
}

typedef void (__stdcall* D2RecordHandlerFn)(int nArg1, int nArg2, int nArg3);

D2RecordHandlerFn gpfnPrevHandler; // 0x007A2764

// 0x00451920
void __stdcall RECORD_RecordHandler(int nArg1, int nArg2, int nArg3)
{
    RECORD_WriteRecordFile();
    if (gpfnPrevHandler)
        gpfnPrevHandler(nArg1, nArg2, nArg3);
}

D2RecordHandlerFn __fastcall sub_005173D3_SetRecordHandler(D2RecordHandlerFn pfnHandler);                  // 0x005173D3

// 0x00451940
void __cdecl RECORD_InstallRecordHandler()
{
    gbRecordHandlerInstalled = 1;
    gpfnPrevHandler = sub_005173D3_SetRecordHandler(RECORD_RecordHandler);
}

// 0x00451960
int __cdecl RECORD_IsRecordHandlerInstalled()
{
    return gbRecordHandlerInstalled;
}

int gbRecordPlaying;                                                                                     // 0x007A2788

// 0x00451970
void __cdecl RECORD_SetRecordPlaying()
{
    gbRecordPlaying = 1;
}

// 0x00451980
int __cdecl RECORD_IsPlaybackEnabled()
{
    return gnRecordPos;
}

// 0x00451990
int __cdecl RECORD_IsReplayActive()
{
    return gbRecordPlaying;
}

// 0x004519A0
void __cdecl RECORD_ToggleRecordPlayback()
{
    if (gnRecordPos)
        gnRecordPos = 0;
    else
        gbPlaybackRequested = 1;
}

int gnReplayEndTick;                                                                               // 0x007A2774

// 0x004519C0
void __cdecl RECORD_ReplayRecords()
{
    if (!gbRecordPlaying)
        return;
    if (!gpMsgRecordChunk_0070F7A0)
        return;
    const int nNow = sub_0044DA90();
    if (nNow >= gnReplayEndTick)
    {
        gbRecordPlaying = 0;
        return;
    }
    D2MsgRecordChunkStrc* pChunk = gpMsgRecordChunk_0070F7A0;
    D2_ASSERT(pChunk->nIndex < 500, 0x189);
    if (!pChunk->pNext && pChunk->nCount == pChunk->nIndex)
        return;
    D2MsgRecordStrc* pRecord = &pChunk->tRecords[pChunk->nIndex];
    while (pRecord->nTick <= nNow)
    {
        RECORD_DispatchRecordedMessage(pRecord);
        pChunk = gpMsgRecordChunk_0070F7A0;
        pChunk->nIndex++;
        if (!pChunk->pNext && pChunk->nCount == pChunk->nIndex)
            return;
        if (pChunk->nIndex >= 500)
        {
            pChunk = pChunk->pNext;
            gpMsgRecordChunk_0070F7A0 = pChunk;
        }
        if (!pChunk)
            return;
        pRecord = &pChunk->tRecords[pChunk->nIndex];
    }
}

#include "gen/data/Source/D2Client/GAME/Record.inc"
