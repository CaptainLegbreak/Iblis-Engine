#include "Storm.h"
#include "D2SFileTypes.h"
#include "D2GameTypes.h"
#include "D2StormTypes.h"
#include "D2StormLink.h"
#include "D2StormSha1.h"
#include "D2StormBitOutput.h"
#include "D2Win32SystemInfo.h"

struct D2FileStrc;

struct D2CriticalSectionStrc;

struct D2StormBufferInfoStrc;

struct D2Storm415140Strc;

struct D2SFileRecordViewStrc;

struct D2SFileOtherRecordViewStrc;

struct D2StormRequestCallbackStrc;

struct D2StormCryptFuncsStrc;

struct D2StormSignatureKeyStrc;

struct D2StormBlockEntryStrc;

struct D2StormQuadStrc;

struct D2Storm416A90Strc;

struct PairStrc_00416810;

struct PairStrc_00416890;

struct PairStrc_004168B0;

struct PairStrc_00416960;

struct PairStrc_004169A0;



struct D2IdentityView;

struct Link;

struct D2SFileStormLinkM114Strc;

struct D2SFileNodeM114Strc;

struct D2SFileStormListM114Strc;

struct D2SFileOwnerM114Strc;

struct D2SFileArchiveM114Strc;

struct D2ChatStormLinkStrc;

struct D2ChatStormLinkAStrc;

struct D2ChatStormLinkBStrc;

struct D2ChatStormNodeStrc;

struct D2ChatStormBaseArrayAStrc;

struct D2ChatStormBaseArrayBStrc;

struct D2ChatStormListAStrc;

struct D2ChatStormListBStrc;

struct D2ChatStormHashTableStrc;

struct D2ChatStormCtorLinkStrc;

struct D2ChatStormListCStrc;

struct D2ChatStormListDStrc;

struct D2ChatStormListEStrc;


struct D2CommonStormSlotListAStrc;

struct D2CommonStormSlotListBStrc;


struct D2CommonMappingEntryNodeStrc;

struct D2CommonStringEntryNodeStrc;

struct D2CommonStormHashTableAStrc;

struct D2StormList00418490Strc;

struct D2StormList004185B0Strc;

struct D2StormHashBufferStrc;

class THuffmannTree;

struct D2StormHuffLinkSlotStrc;

struct CHuffman;

struct HANDLER;


struct D2StormBufferInfoStrc
{
    char* pbInBuffer;
    unsigned int nInPos;
    char* pbOutBuffer;
    unsigned int nOutPos;
    unsigned int nInSize;
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210

// A critical section for the whole run: initialized before main, deleted at exit.
struct CCritSect : D2CriticalSectionStrc
{
    CCritSect() { InitializeCriticalSection(this); }
    ~CCritSect() { DeleteCriticalSection(this); }
};

// build: symbol ??__EgBasePathLock_00779068@@YAXXZ 0x006CA7F0
// build: symbol ??__FgBasePathLock_00779068@@YAXXZ 0x006CB0A0
CCritSect gBasePathLock_00779068; // 0x00779068

char gszBasePath_00778F28[260]; // 0x00778F28

unsigned short gwValue_0077905C; // 0x0077905C

void __cdecl InitBasePath(); // 0x004158E0

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

void __stdcall SMemCopy(void* pDst, const void* pSrc, unsigned int nSize); // 0x0041D2A0

struct Link {
    Link* previous;
    char* next;
    char* sub_00417770();
};

struct D2Storm415140Strc
{
    int f_0;
    int f_4;
    int f_8;
    int nFieldC;

    D2Storm415140Strc(int nValue0, int nValue4, int nValue8, int nValueC);
};

struct D2SFileRecordViewStrc
{
    char unk0x00[0x144];
    int dwField144;
    int dwField148;
    int dwField14C;
    int dwField150;
};

struct D2SFileOtherRecordViewStrc
{
    char unk0x00[0x4C];
    int dwField4C;
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x006CC1AC

extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4

extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent); // 0x006CC130

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long nMilliseconds); // 0x006CC230

#define WAIT_TIMEOUT 0x102

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

extern "C" char* __cdecl strstr(const char* szString, const char* szSubString); // 0x00686900

void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340

int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020

void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith); // 0x0041D2C0

const char* __stdcall SStrChrR(const char* szString, char nChar); // 0x004134D0

void __fastcall CrcBuffer(const unsigned char* pData, unsigned int nSize, unsigned int* pCrc, unsigned char nFlags); // 0x0041D810

int __cdecl GetDefaultOpenFlags(); // 0x00418B50

void* __cdecl StormGetInstance(); // 0x0041BEF0

void __cdecl StartCdThread(); // 0x0041A880

void __cdecl PumpStreams(); // 0x00419C00

int __stdcall SFileCloseFile(void* pArg); // 0x004198D0

int __stdcall SFileCloseArchive(void* hMpq); // 0x00419A80

static int __stdcall ReadAdditionalAttributes(ARCHIVEREC* pArchive, D2StormBlockStrc* pBlockTable, unsigned int nCount);

int __stdcall SFileOpenFileEx(void* hMpq, const char* szFileName, unsigned int dwFlags, void** phFile); // 0x004192F0

int __stdcall SFileOpenArchive(const char* szMpqName, int nPriority, unsigned int dwFlags, void** phMpq);

int __stdcall SFileAuthenticateArchiveEx(void* hArchive, unsigned int* pnResult, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00415BB0

int __stdcall DecompressLzw(char* pDest, const char* pSource, unsigned int nSourceSize); // 0x00415240

int __stdcall SCompDecompress(void* pDest, unsigned int* pdwDestSize, const void* pSource, unsigned int nSourceSize, const char* szName); // 0x0041E720

unsigned int __stdcall InternalReadAligned(FILEREC* pFile, unsigned int nOffset, unsigned char* pBuffer, unsigned int nSize); // 0x00416AD0

void __stdcall CheckRequests(ARCHIVEREC* pLastArchive, unsigned int nLastOffset, REQUEST** ppDue, REQUEST** ppNear, int* pnDistance); // 0x0041A450

unsigned int* gpCryptTable_00779048; // 0x00779048

extern int (__stdcall* gpfnReadErrorCallback_00779030)(const char* szName, unsigned long dwError, int nRetry); // 0x00779030

extern const D2StormSignatureKeyStrc gaSignatureKeys_006CF07C[]; // 0x006CF07C

extern TSList<ARCHIVEREC> gArchiveList_00708354; // 0x00708354

extern TSList<EVENTREC> gEventList_00708378; // 0x00708378

int gbThreadStop_00778F24; // 0x00778F24

void* ghStormEvent_00779054; // 0x00779054

static unsigned int gnStreamChunk_00779038; // 0x00779038

unsigned char* gpStreamBuffer_00779050; // 0x00779050

extern "C" const char gszSFileCpp_006CF084[]; // 0x006CF084

struct D2StormBlockEntryStrc
{
    unsigned int nOffset;
    unsigned int nPackedSize;
    unsigned int nFileSize;
    unsigned int dwFlags;
};

struct D2StormQuadStrc
{
    int n00;
    int n04;
    int n08;
    int n0C;
    D2StormQuadStrc& sub_00415160_Copy(const D2StormQuadStrc& source);
};

// build: symbol ??_R0?AUAUDIOSTREAM@@@8 0x00708400
// build: symbol ?LinkNode@?$TSList@UAUDIOSTREAM@@U?$TSGetLink@UAUDIOSTREAM@@@@@@QAEXPAUAUDIOSTREAM@@I0@Z 0x00417D80
// build: symbol ?UnlinkAll@?$TSList@UAUDIOSTREAM@@U?$TSGetLink@UAUDIOSTREAM@@@@@@QAEXXZ 0x00418A00
// build: symbol ??1?$TSList@UAUDIOSTREAM@@U?$TSGetLink@UAUDIOSTREAM@@@@@@QAE@XZ 0x00418DA0
// build: symbol ?NewNode@?$TSList@UAUDIOSTREAM@@U?$TSGetLink@UAUDIOSTREAM@@@@@@QAEPAUAUDIOSTREAM@@III@Z 0x00419700
// build: symbol ?DeleteNode@?$TSList@UAUDIOSTREAM@@U?$TSGetLink@UAUDIOSTREAM@@@@@@QAEPAUAUDIOSTREAM@@PAU2@@Z 0x00419B90
// build: symbol ??_R0?AUREQUEST@@@8 0x007083E8
// build: symbol ?LinkNode@?$TSList@UREQUEST@@U?$TSGetLink@UREQUEST@@@@@@QAEXPAUREQUEST@@I0@Z 0x00417A70
// build: symbol ?UnlinkAll@?$TSList@UREQUEST@@U?$TSGetLink@UREQUEST@@@@@@QAEXXZ 0x00418940
// build: symbol ??1?$TSList@UREQUEST@@U?$TSGetLink@UREQUEST@@@@@@QAE@XZ 0x00418CC0
// build: symbol ?NewNode@?$TSList@UREQUEST@@U?$TSGetLink@UREQUEST@@@@@@QAEPAUREQUEST@@III@Z 0x00419630
// build: symbol ?DeleteNode@?$TSList@UREQUEST@@U?$TSGetLink@UREQUEST@@@@@@QAEPAUREQUEST@@PAU2@@Z 0x0041A2C0
// build: symbol ??_R0?AUEVENTREC@@@8 0x007083D0
// build: symbol ?LinkNode@?$TSList@UEVENTREC@@U?$TSGetLink@UEVENTREC@@@@@@QAEXPAUEVENTREC@@I0@Z 0x00417C70
// build: symbol ?UnlinkAll@?$TSList@UEVENTREC@@U?$TSGetLink@UEVENTREC@@@@@@QAEXXZ 0x004189C0
// build: symbol ??1?$TSList@UEVENTREC@@U?$TSGetLink@UEVENTREC@@@@@@QAE@XZ 0x00418D40
// build: symbol ?NewNode@?$TSList@UEVENTREC@@U?$TSGetLink@UEVENTREC@@@@@@QAEPAUEVENTREC@@III@Z 0x00418F90
// build: symbol ?DeleteNode@?$TSList@UEVENTREC@@U?$TSGetLink@UEVENTREC@@@@@@QAEPAUEVENTREC@@PAU2@@Z 0x00419690
// build: symbol ??_R0?AUFILEREC@@@8 0x007083B8
// build: symbol ?LinkNode@?$TSList@UFILEREC@@U?$TSGetLink@UFILEREC@@@@@@QAEXPAUFILEREC@@I0@Z 0x00417B80
// build: symbol ?UnlinkAll@?$TSList@UFILEREC@@U?$TSGetLink@UFILEREC@@@@@@QAEXXZ 0x00418980
// build: symbol ??1?$TSList@UFILEREC@@U?$TSGetLink@UFILEREC@@@@@@QAE@XZ 0x00418D00
// build: symbol ?NewNode@?$TSList@UFILEREC@@U?$TSGetLink@UFILEREC@@@@@@QAEPAUFILEREC@@III@Z 0x00418F20
// build: symbol ??_R0?AUARCHIVEREC@SFile@Storm@@@8 0x00708390
// build: symbol ?LinkNode@?$TSList@UARCHIVEREC@SFile@Storm@@U?$TSGetLink@UARCHIVEREC@SFile@Storm@@@@@@QAEXPAUARCHIVEREC@SFile@Storm@@I0@Z 0x004184B0
// build: symbol ?UnlinkAll@?$TSList@UARCHIVEREC@SFile@Storm@@U?$TSGetLink@UARCHIVEREC@SFile@Storm@@@@@@QAEXXZ 0x00418900
// build: symbol ??1?$TSList@UARCHIVEREC@SFile@Storm@@U?$TSGetLink@UARCHIVEREC@SFile@Storm@@@@@@QAE@XZ 0x00418C60
// build: symbol ?NewNode@?$TSList@UARCHIVEREC@SFile@Storm@@U?$TSGetLink@UARCHIVEREC@SFile@Storm@@@@@@QAEPAUARCHIVEREC@SFile@Storm@@III@Z 0x00418EC0
// build: symbol ?Link@?$TSList@UARCHIVEREC@SFile@Storm@@U?$TSGetLink@UARCHIVEREC@SFile@Storm@@@@@@QAEPAU?$TSLink@UARCHIVEREC@SFile@Storm@@@@PBUARCHIVEREC@SFile@Storm@@@Z 0x00417A10
// build: symbol ?Link@?$TSList@UREQUEST@@U?$TSGetLink@UREQUEST@@@@@@QAEPAU?$TSLink@UREQUEST@@@@PBUREQUEST@@@Z 0x00417A50
// build: symbol ?Link@?$TSList@UFILEREC@@U?$TSGetLink@UFILEREC@@@@@@QAEPAU?$TSLink@UFILEREC@@@@PBUFILEREC@@@Z 0x00417B60
// build: symbol ?Link@?$TSList@UEVENTREC@@U?$TSGetLink@UEVENTREC@@@@@@QAEPAU?$TSLink@UEVENTREC@@@@PBUEVENTREC@@@Z 0x00417C50
// build: symbol ?Link@?$TSList@UAUDIOSTREAM@@U?$TSGetLink@UAUDIOSTREAM@@@@@@QAEPAU?$TSLink@UAUDIOSTREAM@@@@PBUAUDIOSTREAM@@@Z 0x00417D60
template TSLink<ARCHIVEREC>* TSList<ARCHIVEREC>::Link(const ARCHIVEREC*);
template TSLink<REQUEST>* TSList<REQUEST>::Link(const REQUEST*);
template TSLink<FILEREC>* TSList<FILEREC>::Link(const FILEREC*);
template TSLink<EVENTREC>* TSList<EVENTREC>::Link(const EVENTREC*);
template TSLink<AUDIOSTREAM>* TSList<AUDIOSTREAM>::Link(const AUDIOSTREAM*);
// build: symbol ?Next@?$TSList@UFILEREC@@U?$TSGetLink@UFILEREC@@@@@@QAEPAUFILEREC@@PBU2@@Z 0x00417B20
// build: symbol ?Next@?$TSList@UAUDIOSTREAM@@U?$TSGetLink@UAUDIOSTREAM@@@@@@QAEPAUAUDIOSTREAM@@PBU2@@Z 0x00417D20
template FILEREC* TSList<FILEREC>::Next(const FILEREC*);
template AUDIOSTREAM* TSList<AUDIOSTREAM>::Next(const AUDIOSTREAM*);
template TSList<FILEREC>::~TSList();
template TSList<EVENTREC>::~TSList();
template TSList<REQUEST>::~TSList();
template REQUEST* TSList<REQUEST>::DeleteNode(REQUEST*);
template TSList<AUDIOSTREAM>::~TSList();
template AUDIOSTREAM* TSList<AUDIOSTREAM>::DeleteNode(AUDIOSTREAM*);
extern TSList<AUDIOSTREAM> gDdaList_00708384; // 0x00708384

extern "C" __declspec(dllimport) int __stdcall GetFileTime(void* hFile, D2FileTimeStrc* pCreation, D2FileTimeStrc* pAccess, D2FileTimeStrc* pWrite);

unsigned int __stdcall SStrLen(const char* szString); // 0x00413750

unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800

struct PairStrc_00416810
{
    int nFirst;
    int nSecond;
};

struct PairStrc_00416890
{
    int nFirst;
    int nSecond;
};

struct PairStrc_004168B0
{
    int nFirst;
    int nSecond;
};

struct PairStrc_00416960
{
    int nFirst;
    int nSecond;
};

struct PairStrc_004169A0
{
    int nFirst;
    int nSecond;
};

struct D2IdentityView {
 D2StormLinkStrc link;
};

enum { NO_NODE = 0 };

struct D2SFileStormLinkM114Strc
{
    D2SFileStormLinkM114Strc* m_prevlink;
    char* m_next;

    char* MaskNext()
    {
        return (char*)((((int)m_next <= 0) - 1) & (int)m_next);
    }
    char* Next()
    {
        return (int)m_next > 0 ? m_next : 0;
    }
    char* sub_00417790_Next();
    char* sub_004178A0_Next();
    char* sub_004179A0_Next();
};

struct D2SFileNodeM114Strc
{
    char unk0x00[0x24];
    int nKey;
};

struct D2SFileStormListM114Strc
{
    D2SFileStormLinkM114Strc m_terminator;

    D2SFileNodeM114Strc* Head()
    {
        return (D2SFileNodeM114Strc*)m_terminator.Next();
    }
};

struct D2SFileOwnerM114Strc
{
    D2SFileStormListM114Strc* pList;
};

struct D2SFileArchiveM114Strc
{
    D2SFileOwnerM114Strc* pOwner;
    char unk0x04[0x20];
    int nKey;
};

extern "C" const char gszIgnoreListSourceFile_006E6290[];

struct D2StormList00418490Strc : D2StormListBaseStrc { int sub_00418490_IsEmpty(); };

struct D2StormList004185B0Strc : D2StormListBaseStrc { int sub_004185B0_IsEmpty(); };

extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void* pAttributes, int bManualReset, int bInitialState, const char* szName); // 0x006CC228

extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void* pParam), void* pParam, unsigned long dwFlags, unsigned long* pThreadId); // 0x006CC250

extern "C" __declspec(dllimport) int __stdcall SetThreadPriority(void* hThread, int nPriority); // 0x006CC264

unsigned long __stdcall CdThreadProc(void* pParam); // 0x0041A550

struct D2StormHashBufferStrc
{
    unsigned int nSignSize;
    int nModulusSize;
    unsigned int nUsed;
    unsigned int nWindow;
};

class THuffmannTree
{
public:
    THuffmannTree();                                                                                        // 0x0041F4A0

    unsigned int adwData[0x3474 / 4];
};

struct CHuffman : THuffmannTree
{
    D2StormHuffLinkSlotStrc aQuickLinks[0x80];

    CHuffman();
};

static void* ghStormThread_00779034; // 0x00779034

int gnStormDirectFlags_00779058;                                                                            // 0x00779058

struct HANDLER
{
    D2StormLinkStrc tLink;
    int unk0x08;

    HANDLER()
    {
        tLink.m_prevlink = 0;
        tLink.m_next = 0;
    }
    ~HANDLER();
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

int __stdcall SFileGetFileSize(void* hFile, unsigned int* pnSizeHigh); // 0x00416370

void __stdcall SMemZero(void* pDest, unsigned int nSize); // 0x0041D300

struct D2StormOverlappedStrc;

int __stdcall SFileReadFileEx2(void* hFile, unsigned char* buffer, unsigned int size, unsigned int* read, D2StormOverlappedStrc* overlap, int nArg6, void* callback); // 0x0041AAD0

inline void* operator new(unsigned int, void* pWhere) throw();

static int GetArchiveRec(void* hArchive, ARCHIVEREC** ppRec); // 0x00415930

static int GetFileRec(void* hFile, FILEREC** ppRec); // 0x00415950

D2SystemTimeStrc gLogStartTime_0075D288; // 0x0075D288

int gnValueA_00779060; // 0x00779060

int gnValueB_00779064; // 0x00779064

int gnValue_0077904C; // 0x0077904C

int gnValueB_00779030; // 0x00779030

template <class T>
inline T StormPowInt(T x, int nExp)
{
    unsigned int nBits;
    if (nExp >= 0)
        nBits = (unsigned int)nExp;
    else
        nBits = (unsigned int)-nExp;
    for (T z = T(1); ; x *= x)
    {
        if ((nBits & 1) != 0)
            z *= x;
        if ((nBits >>= 1) == 0)
            return nExp < 0 ? T(1) / z : z;
    }
}

extern "C" __declspec(dllimport) unsigned long __stdcall GetFileSize(void* hFile, unsigned long* pdwFileSizeHigh); // 0x006CC2F0

extern TSList<REQUEST> gRequestList_00708360; // 0x00708360

static int gbStreamsPaused_00779044;                                                                        // 0x00779044

struct D2FogBlockStrc;

struct D2StormRecord419000Strc;

struct D2FogBlockStrc
{
    D2FogBlockStrc* pNext;
    unsigned int dwSize;
    int unk0x08[3];
    int bInUse;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void* hModule, char* szFileName, unsigned long nSize); // 0x006CC1BC

static D2StormBlockStrc* GetBlockEntry(ARCHIVEREC* pArchive, int nHashIndex); // 0x004155B0

static int __stdcall FindHashEntry(unsigned short wLocale, unsigned char nPlatform, ARCHIVEREC* pArchive, const char* szName); // 0x004155D0

static int __stdcall FindDiskFile(unsigned int nFlags, const char* szName, char* szOut); // 0x00415B00

static int __stdcall GetFileBlockEntry(void* hArchive, const char* szName, unsigned int nFlags, ARCHIVEREC** ppArchive, D2StormBlockStrc** ppBlock, char* szFoundPath); // 0x00417F10

struct D2StormRecord419000Strc
{
    D2StormLinkStrc tLink;

    ~D2StormRecord419000Strc();
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};



extern "C" __declspec(dllimport) int __stdcall GetDiskFreeSpaceA(const char* lpRootPathName, unsigned long* lpSectorsPerCluster, unsigned long* lpBytesPerSector, unsigned long* lpNumberOfFreeClusters, unsigned long* lpTotalNumberOfClusters); // 0x006CC270

extern "C" __declspec(dllimport) int __stdcall GetVolumeInformationA(const char* lpRootPathName, char* lpVolumeNameBuffer, unsigned long nVolumeNameSize, unsigned long* lpVolumeSerialNumber, unsigned long* lpMaximumComponentLength, unsigned long* lpFileSystemFlags, char* lpFileSystemNameBuffer, unsigned long nFileSystemNameSize); // 0x006CC2E8

extern "C" __declspec(dllimport) unsigned int __stdcall GetDriveTypeA(const char* lpRootPathName);         // 0x006CC2EC

char* gpStormExplodeWork;                                                                                   // 0x0077903C

// build: symbol ??__EgStormExplodeLock@@YAXXZ 0x006CA870
// build: symbol ??__FgStormExplodeLock@@YAXXZ 0x006CB0B0
CCritSect gStormExplodeLock;                                                                    // 0x00779080

unsigned int __cdecl sub_004151D0_ExplodeRead(char* pBuffer, unsigned int* pnSize, void* pParam);          // 0x004151D0

void __cdecl sub_00415210_ExplodeWrite(char* pBuffer, unsigned int* pnSize, void* pParam);                 // 0x00415210

extern "C" unsigned int __cdecl sub_006B01B0_Explode(unsigned int (__cdecl* pRead)(char*, unsigned int*, void*), void (__cdecl* pWrite)(char*, unsigned int*, void*), char* pWork, void* pParam); // 0x006B01B0

int __stdcall SFileLoadFileEx2(void* hMpq, const char* szFileName, void** ppBuffer, unsigned int* pSize, unsigned int nExtraSize, int nFlags, void* pOverlapped, int nArg8); // 0x0041AF60

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile);

void __fastcall SSignatureVerifyStream_Begin(D2StormHashBufferStrc** ppBuffer, unsigned int nSignSize, int nModulusSize); // 0x0041D3B0

unsigned int __fastcall GetHashWindowSize(D2StormHashBufferStrc* pBuffer);                          // 0x0041D410

void __fastcall HashBufferedData(D2StormHashBufferStrc* pBuffer, const char* pData, int nSize); // 0x0041D420

int __fastcall SSignatureVerifyStream_Finish(D2StormHashBufferStrc* pBuffer, const void* pExponent, const void* pModulus); // 0x0041D6D0

extern "C" const unsigned char gabSignatureModulus_006CEF78[0x100];                                         // 0x006CEF78

extern "C" const unsigned char gabSignatureExponent_006CF078[4];                                            // 0x006CF078

struct D2StormLinkStrc;

extern TSList<FILEREC> gFileList_0070836C; // 0x0070836C

int __stdcall CheckCdVolume(const char* szPath);                                                 // 0x00415960

int __fastcall s_OpenArchive(ARCHIVEREC* pArchive, unsigned int nFlags, int bKeepOnFail, void** phArchive); // 0x0041B6B0

static int IsDiskFile(const char* szPath);                                // 0x00415940

static void __stdcall BuildBasePath(int bStripPath, const char* szName, char* szOut); // 0x00415A80

typedef void (__stdcall* SFILEOPENCALLBACK)(const char* szFileName, void* pParam);

extern "C" const char gszSFileSourceFile_006CF084[]; // 0x006CF084

extern SFILEOPENCALLBACK gpfnOpenFileCallback_00779060; // 0x00779060

extern void* gpOpenFileCallbackParam_00779064; // 0x00779064

extern unsigned int gnFileCrc_007790B0; // 0x007790B0

char* __stdcall SStrDup(const char* szString); // 0x00414310

static unsigned int __stdcall HashString(unsigned int nHashType, const char* szString); // 0x00415330

int __stdcall SFileOpenFileAsArchive(void* hMpq, const char* szName, int nPriority, unsigned int nFlags, void** phArchive);

// 0x00414260
double __cdecl sub_00414260_PowInt(double x, int nExp)
{
    return StormPowInt(x, nExp);
}

// 0x00415140
D2Storm415140Strc::D2Storm415140Strc(int nValue0, int nValue4, int nValue8, int nValueC)
{
    f_0 = nValue0;
    f_4 = nValue4;
    f_8 = nValue8;
    nFieldC = nValueC;
}

// 0x004151D0
unsigned int __cdecl DecompressLzw_BufferRead(char* pBuffer, unsigned int* pnSize, D2StormBufferInfoStrc* pInfo)
{
    unsigned int nAvail = pInfo->nInSize - pInfo->nInPos;
    unsigned int nToRead = *pnSize < nAvail ? *pnSize : nAvail;
    SMemCopy(pBuffer, pInfo->pbInBuffer + pInfo->nInPos, nToRead);
    pInfo->nInPos += nToRead;
    return nToRead;
}

// 0x00415210
void __cdecl DecompressLzw_BufferWrite(char* pBuffer, unsigned int* pnSize, D2StormBufferInfoStrc* pInfo)
{
    SMemCopy(pInfo->pbOutBuffer + pInfo->nOutPos, pBuffer, *pnSize);
    pInfo->nOutPos += *pnSize;
}

// 0x00415EC0
void __stdcall SetOpenFileCallback(int nValueA, int nValueB)
{
    gnValueA_00779060 = nValueA;
    gnValueB_00779064 = nValueB;
}

// 0x00415F90
void __stdcall SFileEnableSeekOptimization(int nValue)
{
    gnValue_00708350 = nValue;
}

// 0x004160A0
int __stdcall SFileGetBasePath(char* szBuffer, unsigned int nBufferSize)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    if (!gszBasePath_00778F28[0])
        InitBasePath();
    SStrCopy(szBuffer, gszBasePath_00778F28, nBufferSize);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x004164A0
void __stdcall SFileSetAsyncBudget(int nValue)
{
    gnValue_0077904C = nValue;
}

// 0x004166B0
int __stdcall SFileSetIoErrorMode(int nValueA, int nValueB)
{
    gnValueA_0070834C = nValueA;
    gnValueB_00779030 = nValueB;
    return 1;
}

// 0x004166D0
void __stdcall SFileSetLocale(unsigned short nValue)
{
    gwValue_0077905C = nValue;
}

// 0x00415160
D2StormQuadStrc& D2StormQuadStrc::sub_00415160_Copy(const D2StormQuadStrc& source)
{
    n00 = source.n00;
    n04 = source.n04;
    n08 = source.n08;
    n0C = source.n0C;
    return *this;
}

// 0x00415190
int __fastcall sub_00415190_HasField14C(D2SFileRecordViewStrc* pRecord)
{
    if (pRecord && pRecord->dwField14C)
    {
        return 1;
    }
    return 0;
}

// 0x004151B0
int __fastcall sub_004151B0_HasField150(D2SFileRecordViewStrc* pRecord)
{
    if (pRecord && pRecord->dwField150)
    {
        return 1;
    }
    return 0;
}

// 0x00415730
void __fastcall sub_00415730_IncField148(D2SFileRecordViewStrc* pRecord)
{
    if (pRecord)
    {
        ++pRecord->dwField148;
    }
}

// 0x00415740
static inline void sub_00415740_IncField144(D2SFileRecordViewStrc* pRecord)
{
    if (pRecord)
    {
        ++pRecord->dwField144;
    }
}

// 0x00415750
static inline void sub_00415750_IncField4C(D2SFileOtherRecordViewStrc* pRecord)
{
    if (pRecord)
    {
        ++pRecord->dwField4C;
    }
}

void __fastcall sub_M103_Emit_00415740(D2SFileRecordViewStrc* pRecord, D2SFileOtherRecordViewStrc* pOther)
{
    sub_00415740_IncField144(pRecord);
    sub_00415750_IncField4C(pOther);
}

static REQUEST* gpCurrentRequest_0077902C; // 0x0077902C

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

// 0x004152D0
static void DecryptBlock(unsigned int* pData, unsigned int nBytes, unsigned int nKey)
{
    unsigned int nSeed = 0xEEEEEEEE;
    unsigned int nCount = nBytes >> 2;
    while (nCount--)
    {
        nSeed += gpCryptTable_00779048[0x400 + (nKey & 0xFF)];
        *pData ^= nKey + nSeed;
        nSeed = *pData + nSeed + (nSeed << 5) + 3;
        ++pData;
        nKey = ((~nKey << 0x15) + 0x11111111) | (nKey >> 0x0B);
    }
}

// 0x00415330
static unsigned int __stdcall HashString(unsigned int nHashType, const char* szString)
{
    unsigned int nSeed1 = 0x7FED7FED;
    unsigned int nSeed2 = 0xEEEEEEEE;
    while (szString && *szString)
    {
        unsigned int nChar = (unsigned char)toupper(*szString++);
        nSeed1 = gpCryptTable_00779048[(nHashType << 8) + nChar] ^ (nSeed1 + nSeed2);
        nSeed2 = nChar + nSeed2 + (nSeed2 << 5) + nSeed1 + 3;
    }
    return nSeed1;
}

// 0x004154B0
static int __stdcall ReadFileChecked(unsigned int nOffset, unsigned int* pnFilePos, void* pBuffer, unsigned int nSize, const char* szName, void* hFile, unsigned long* pnRead)
{
    int nRetry = 0;
    for (;;)
    {
        if (nOffset != -1)
            SetFilePointer(hFile, nOffset, 0, 0);
        const int bRead = ReadFile(hFile, pBuffer, nSize, pnRead, 0);
        *pnFilePos = *pnRead + nOffset;
        if (bRead)
        {
            if (*pnRead == nSize)
                return 1;
            sub_0041C340_SetLastError(0x26);
            return 0;
        }
        const unsigned long dwError = GetLastError();
        switch (gnValueA_0070834C)
        {
        case 0:
            return 0;
        case 1:
            if (!gpfnReadErrorCallback_00779030)
                return 0;
            if (!gpfnReadErrorCallback_00779030(szName, dwError, nRetry++))
                return 0;
            break;
        case 2:
            SErrDisplayError(dwError, szName, -4, 0, 0, 1);
            break;
        }
    }
}

// 0x00415560
static int __stdcall ReadFileRec(void* pBuffer, unsigned int nSize, unsigned int* pnRead, FILEREC* pFile, unsigned int nOffset)
{
    unsigned int nFilePos;
    unsigned long nRead = 0;
    ReadFileChecked(nOffset, &nFilePos, pBuffer, nSize, pFile->szName, pFile->hFile, &nRead);
    if (pnRead)
        *pnRead = nRead;
    return nRead == nSize;
}

// 0x004155B0
static D2StormBlockStrc* GetBlockEntry(ARCHIVEREC* pArchive, int nHashIndex)
{
    return &pArchive->pBlockTable[pArchive->pHashTable[nHashIndex].nBlockIndex];
}

// 0x004155D0
static int __stdcall FindHashEntry(unsigned short wLocale, unsigned char nPlatform, ARCHIVEREC* pArchive, const char* szName)
{
    const unsigned int nHash = HashString(0, szName);
    const unsigned int nName1 = HashString(1, szName);
    const unsigned int nName2 = HashString(2, szName);
    const unsigned int nEntries = pArchive->pHeader->nHashEntries;
    unsigned int nIndex = (nEntries - 1) & nHash;
    const unsigned int nStart = nIndex;
    int nBest = -1;
    while (pArchive->pHashTable[nIndex].nBlockIndex != -1)
    {
        D2StormHashEntryStrc* pEntry = &pArchive->pHashTable[nIndex];
        if (pEntry->nName1 == nName1 && pEntry->nName2 == nName2 && pEntry->nBlockIndex != -2)
        {
            if (pEntry->wLocale == wLocale && pEntry->nPlatform == nPlatform)
                return nIndex;
            if ((!pEntry->wLocale || pEntry->wLocale == wLocale) && (!pEntry->nPlatform || pEntry->nPlatform == nPlatform))
                nBest = nIndex;
        }
        nIndex = (nIndex + 1) & (nEntries - 1);
        if (nIndex == nStart)
            break;
    }
    return nBest;
}

// 0x004157C0
static void FillStreamBuffer(REQUEST* pRequest)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    // a whole chunk fits in the sound buffer
    SASSERT(pRequest->stream->soundbuffersize - pRequest->soundbufferoffset >= gnStreamChunk_00779038);
    unsigned long nLocked;
    unsigned char** const ppDest = &pRequest->pDest;
    if (pRequest->pBuffer->Lock(pRequest->soundbufferoffset, gnStreamChunk_00779038, (void**)ppDest, &nLocked, 0, 0, 0) < 0
        || nLocked != gnStreamChunk_00779038)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return;
    }

    unsigned int nCopy = nLocked;
    if (pRequest->nRead < nCopy)
        nCopy = pRequest->nRead;
    SMemCopy(*ppDest, gpStreamBuffer_00779050, nCopy);
    if (nCopy < nLocked)
        SMemFill(*ppDest + nCopy, nLocked - nCopy, pRequest->stream->nFill);
    pRequest->pBuffer->Unlock(*ppDest, nLocked, 0, 0);
    pRequest->stream->writecursor = pRequest->location - pRequest->stream->waveheadersize + nLocked;
    if (pRequest->stream->writecursor > pRequest->stream->nSize)
        pRequest->stream->nCounter = pRequest->stream->writecursor - pRequest->stream->nSize;
    AUDIOSTREAM* pStream = pRequest->stream;
    if (pStream->fillstatus == 1)
    {
        const unsigned int nQueued = pRequest->nBytes - pRequest->stream->waveheadersize + pRequest->location;
        unsigned int nNeeded = pRequest->stream->nSize > 0x10000 ? 0x10000 : pStream->nSize;
        if (nNeeded >= pStream->soundbuffersize)
            nNeeded = pStream->soundbuffersize;
        if (nQueued >= nNeeded)
        {
            pRequest->stream->pBuffer->Play(0, 0, 1);
            pRequest->stream->fillstatus = 2;
        }
    }
    LeaveCriticalSection(&gBasePathLock_00779068);
}

// 0x00415940
static int IsDiskFile(const char* szPath)
{
    return ~(GetFileAttributesA(szPath) >> 4) & 1;
}

// 0x00415A80
static void __stdcall BuildBasePath(int bStripPath, const char* szName, char* szOut)
{
    if (!gszBasePath_00778F28[0])
        InitBasePath();
    if (bStripPath)
    {
        const char* szSlash = SStrChrR(szName, 0x5C);
        if (szSlash)
            szName = szSlash + 1;
    }
    char szBuffer[0x104];
    wsprintfA(szBuffer, "%s%s", gszBasePath_00778F28, szName);
    _fullpath(szOut, szBuffer, 0x104);
}

// 0x00415B00
static int __stdcall FindDiskFile(unsigned int nFlags, const char* szName, char* szOut)
{
    int bResult = 0;
    if (nFlags & 3)
    {
        if (nFlags & 2)
        {
            BuildBasePath(1, szName, szOut);
            bResult = IsDiskFile(szOut);
            if (bResult)
                return bResult;
        }
        if (nFlags & 1)
        {
            if (*szName != 0x5C && !strstr(szName, ":\\") && !strstr(szName, "\\\\"))
            {
                BuildBasePath(0, szName, szOut);
                return IsDiskFile(szOut);
            }
            SStrCopy(szOut, szName, 0x104);
            return IsDiskFile(szOut);
        }
    }
    return bResult;
}

// 0x00416FB0
static unsigned int LoadSector(unsigned int nOffset, FILEREC* pFile)
{
    if (pFile->archive->pCachedFile == pFile && pFile->archive->nCachedOffset == nOffset)
        return pFile->archive->nCachedSize;
    unsigned int nSize = pFile->archive->sectorsize;
    D2StormBlockStrc* pBlock = pFile->pBlock;
    if (nOffset + nSize > pBlock->nFileSize && !(pBlock->dwFlags & 0xFF00))
        nSize = pBlock->nFileSize - nOffset;
    pFile->archive->pCachedFile = pFile;
    pFile->archive->nCachedOffset = nOffset;
    pFile->archive->nCachedSize = InternalReadAligned(pFile, nOffset, pFile->archive->pBlockBuffer, nSize);
    return pFile->archive->nCachedSize;
}

// 0x00417040
static unsigned int __stdcall InternalReadUnaligned(unsigned char* pBuffer, unsigned int nSize, FILEREC* pFile, unsigned int nPosition)
{
    const unsigned int nFileSize = pFile->pBlock->nFileSize;
    if (nFileSize <= nPosition)
        return 0;
    nSize = D2_MIN(nSize, nFileSize - nPosition);
    if (pFile->bCrc && !nPosition)
    {
        CrcBuffer(0, 0, &pFile->nCrc, 1);
        pFile->nCrcPos = 0;
        pFile->nCrcState = 2;
    }
    unsigned int nHead = 0;
    if (nPosition & (pFile->archive->sectorsize - 1))
    {
        if (pFile->bCrc && pFile->nCrcState != 1 && pFile->nCrcPos != nPosition)
            pFile->nCrcState = 1;
        nHead = LoadSector(~(pFile->archive->sectorsize - 1) & nPosition, pFile);
        const unsigned int nCopy = D2_MIN(nSize, pFile->archive->sectorsize - ((pFile->archive->sectorsize - 1) & nPosition));
        SMemCopy(pBuffer, pFile->archive->pBlockBuffer + ((pFile->archive->sectorsize - 1) & nPosition), nCopy);
        if (pFile->bCrc && pFile->nCrcState == 2)
        {
            CrcBuffer(pBuffer, nCopy, &pFile->nCrc, 2);
            pFile->nCrcPos += nCopy;
        }
        pBuffer += nCopy;
        nSize -= nCopy;
        if (nHead != pFile->archive->sectorsize || !nSize)
        {
            const unsigned int nSkip = (pFile->archive->sectorsize - 1) & nPosition;
            if (nHead < nSkip)
                return 0;
            return nCopy < nHead - nSkip ? nCopy : nHead - nSkip;
        }
        nHead = nCopy;
        nPosition += nCopy;
    }
    unsigned int nMiddle = 0;
    if (nSize)
    {
        if (pFile->bCrc && pFile->nCrcState != 1 && pFile->nCrcPos != nPosition)
            pFile->nCrcState = 1;
        const unsigned int nAligned = ~(pFile->archive->sectorsize - 1) & nSize;
        nMiddle = InternalReadAligned(pFile, nPosition, pBuffer, nAligned);
        if (pFile->bCrc && pFile->nCrcState == 2)
        {
            CrcBuffer(pBuffer, nMiddle, &pFile->nCrc, 2);
            pFile->nCrcPos += nMiddle;
        }
        pBuffer += nAligned;
        nSize -= nAligned;
        nPosition += nAligned;
        if (nAligned != nMiddle || !nSize)
            return nMiddle + nHead;
    }
    unsigned int nTail = 0;
    if (nSize)
    {
        if (pFile->bCrc && pFile->nCrcState != 1 && pFile->nCrcPos != nPosition)
            pFile->nCrcState = 1;
        nTail = LoadSector(nPosition, pFile);
        SMemCopy(pBuffer, pFile->archive->pBlockBuffer, nSize);
        if (nSize < nTail)
            nTail = nSize;
        if (pFile->bCrc && pFile->nCrcState == 2)
        {
            CrcBuffer(pBuffer, nTail, &pFile->nCrc, 2);
            pFile->nCrcPos += nTail;
        }
    }
    return nMiddle + nTail + nHead;
}

int __stdcall SFileAuthenticateArchive(void* hArchive, unsigned int* pnResult);

extern int gnValue_00708350;                                                                                // 0x00708350

// 0x0041A450
void __stdcall CheckRequests(ARCHIVEREC* pLastArchive, unsigned int nLastOffset, REQUEST** ppDue, REQUEST** ppNear, int* pnDistance)
{
    *ppDue = 0;
    *ppNear = 0;
    *pnDistance = 0x7FFFFFFF;
    unsigned int nBest = 0xFFFFFFFF;
    unsigned long nNow = GetTickCount();
    REQUEST* pHead = gRequestList_00708360.Head();
    for (REQUEST* p = pHead; (int)p > 0; p = p->m_link.m_next)
    {
        if (p->nDestSize)
        {
            if (p->m_link.Prev() && p->nDestSize == p->m_link.Prev()->nDestSize)
                continue;
        }

        unsigned int nDistance = 0;
        if (gnValue_00708350 && !p->stream)
        {
            ARCHIVEREC* pArchive = p->pFile->archive;
            unsigned int nSkip = 0;
            if (pArchive && nLastOffset > pArchive->sectorsize)
                nSkip = nLastOffset - pArchive->sectorsize;
            if (pArchive == pLastArchive)
            {
                if (p->nFileOffset < nSkip)
                    nDistance = p->nFileOffset + 0x8000000;
                else
                    nDistance = p->nFileOffset - nSkip;
            }
            else
            {
                nDistance = 0xFFFFFFFE;
            }
        }
        if (nDistance <= nBest)
        {
            nBest = nDistance;
            *ppDue = p;
        }

        int nTime = p->nDueTime - nNow;
        if (p->nArg9 && nTime >= 1000)
            nTime = 1000;
        if (nTime < *pnDistance)
        {
            *pnDistance = nTime;
            *ppNear = p;
        }
    }
}

// 0x0041A550
unsigned long __stdcall CdThreadProc(void* pParam)
{
    ARCHIVEREC* pLastArchive = 0;
    unsigned int nLastOffset = 0;
    unsigned long nLastTime = GetTickCount();
    while (!gbThreadStop_00778F24)
    {
        const unsigned long nNow = GetTickCount();
        int nWait = 0;
        if (gnReadRate_0077904C)
            nWait = gnReadUnit_00708348 * 1000 / gnReadRate_0077904C;
        EnterCriticalSection(&gBasePathLock_00779068);
        EVENTREC* pHead = gEventList_00708378.Head();
        for (EVENTREC* pNode = pHead; (int)pNode > 0; )
        {
            SetEvent(pNode->hEvent);
            pNode = gEventList_00708378.DeleteNode(pNode);
        }
        PumpStreams();
        REQUEST* pNear;
        int nDistance;
        REQUEST* pDue;
        CheckRequests(pLastArchive, nLastOffset, &pDue, &pNear, &nDistance);
        REQUEST* pRequest = pNear;
        if (!pRequest || nDistance > 1000)
        {
            REQUEST* pNext = pDue;
            if (!pNext || nNow - nLastTime < nWait)
            {
                LeaveCriticalSection(&gBasePathLock_00779068);
                WaitForSingleObject(ghStormEvent_00779054, pNext ? nWait - nNow + nLastTime : 0xFA);
                continue;
            }
            pRequest = pNext;
        }
        gpCurrentRequest_0077902C = pRequest;
        nLastTime = nNow;
        pLastArchive = pRequest->pFile->archive;
        nLastOffset = pRequest->nFileOffset;
        pRequest->m_link.Unlink();
        LeaveCriticalSection(&gBasePathLock_00779068);
        unsigned char* pDest = gpCurrentRequest_0077902C->pDest;
        if (gpCurrentRequest_0077902C->pBuffer)
            pDest = gpStreamBuffer_00779050;
        if (pDest)
        {
            if (gpCurrentRequest_0077902C->pFile->hFile == INVALID_FILE_HANDLE)
            {
                gpCurrentRequest_0077902C->nRead = InternalReadUnaligned(pDest, gpCurrentRequest_0077902C->nBytes, gpCurrentRequest_0077902C->pFile, gpCurrentRequest_0077902C->location);
                FILEREC* pFile = gpCurrentRequest_0077902C->pFile;
                if (pFile->bCrc && pFile->nCrcState == 2 && pFile->nCrcPos == pFile->pBlock->nFileSize)
                {
                    CrcBuffer(0, 0, &pFile->nCrc, 4);
                    gpCurrentRequest_0077902C->pFile->nCrcState = 4;
                }
            }
            else
            {
                ReadFileRec(pDest, gpCurrentRequest_0077902C->nBytes, &gpCurrentRequest_0077902C->nRead, gpCurrentRequest_0077902C->pFile, gpCurrentRequest_0077902C->location);
            }
        }
        else
        {
            gpCurrentRequest_0077902C->nRead = 0;
        }
        if (gpCurrentRequest_0077902C->pBuffer)
        {
            if (gpCurrentRequest_0077902C->nRead)
            {
                FillStreamBuffer(gpCurrentRequest_0077902C);
            }
            else if (gpCurrentRequest_0077902C->nBytes)
            {
                gpCurrentRequest_0077902C->pBuffer->Stop();
                if (gpCurrentRequest_0077902C->stream)
                    gpCurrentRequest_0077902C->stream->fillstatus = 4;
            }
        }
        if (gpCurrentRequest_0077902C->pCallback && gpCurrentRequest_0077902C->pCallback->pfnDone)
        {
            if (gpCurrentRequest_0077902C->pFile->bCrc && gpCurrentRequest_0077902C->pFile->nCrcState == 4 && gpCurrentRequest_0077902C->pFile->nCrc != gpCurrentRequest_0077902C->pFile->pBlock->nCrc)
                SErrDisplayError(0x85100083, gpCurrentRequest_0077902C->pFile->szName, -4, 0, 0, 1);
            gpCurrentRequest_0077902C->pCallback->pfnDone(gpCurrentRequest_0077902C->nDestSize, gpCurrentRequest_0077902C->nRead + gpCurrentRequest_0077902C->pDest - gpCurrentRequest_0077902C->nDestSize, gpCurrentRequest_0077902C->pCallback);
        }
        void* hEvent = gpCurrentRequest_0077902C->hEvent;
        EnterCriticalSection(&gBasePathLock_00779068);
        if (gpCurrentRequest_0077902C->bDelete)
        {
            REQUEST* pDone = gpCurrentRequest_0077902C;
            pDone->~REQUEST();
            SMemFree(pDone, "delete", -1, 0);
        }
        gpCurrentRequest_0077902C = 0;
        LeaveCriticalSection(&gBasePathLock_00779068);
        if (hEvent)
            SetEvent(hEvent);
    }
    gbThreadStop_00778F24 = 0;
    return 0;
}

// 0x0041B6B0
int __fastcall s_OpenArchive(ARCHIVEREC* pArchive, unsigned int nFlags, int bKeepOnFail, void** phArchive)
{
    unsigned char* pBuffer = (unsigned char*)SMemAlloc(0x1000, ".\\SOURCE\\SFILE.CPP", 0x10C2, 0);
    unsigned int nBufferStart = 0;
    unsigned int nBufferSize = 0;
    for (;;)
    {
        if (pArchive->nArchiveOffset >= nBufferStart + nBufferSize)
        {
            nBufferStart = pArchive->nArchiveOffset;
            SetFilePointer(pArchive->hFile, pArchive->nArchiveOffset, 0, 0);
            unsigned long nRead = 0;
            ReadFile(pArchive->hFile, pBuffer, 0x1000, &nRead, 0);
            if (nRead < sizeof(D2StormMpqHeaderStrc) || pArchive->nArchiveOffset + sizeof(D2StormMpqHeaderStrc) >= pArchive->nArchiveLimit)
            {
                pArchive->~ARCHIVEREC();
                SMemFree(pArchive, "delete", -1, 0);
                sub_0041C340_SetLastError(0x8510006C);
                SMemFree(pBuffer, ".\\SOURCE\\SFILE.CPP", 0x10DF, 0);
                return 0;
            }
            nBufferSize = nRead;
        }
        SMemCopy(pArchive->pHeader, pBuffer + pArchive->nArchiveOffset - nBufferStart, sizeof(D2StormMpqHeaderStrc));
        if (pArchive->pHeader->dwSignature == 0x1A51504D && pArchive->pHeader->nHeaderSize >= sizeof(D2StormMpqHeaderStrc))
        {
            SMemFree(pBuffer, ".\\SOURCE\\SFILE.CPP", 0x1106, 0);
            break;
        }
        pArchive->nArchiveOffset += 0x200;
    }
    pArchive->sectorsize = 0x200 << pArchive->pHeader->nSectorShift;
    pArchive->pBlockBuffer = (unsigned char*)SMemAlloc(pArchive->sectorsize, ".\\SOURCE\\SFILE.CPP", 0x110B, 0);
    pArchive->pHashTable = (D2StormHashEntryStrc*)SMemAlloc(pArchive->pHeader->nHashEntries * sizeof(D2StormHashEntryStrc), ".\\SOURCE\\SFILE.CPP", 0x1114, 0);
    unsigned long nRead;
    ReadFileChecked(pArchive->pHeader->nHashOffset + pArchive->nArchiveOffset, &pArchive->nFilePos, pArchive->pHashTable, pArchive->pHeader->nHashEntries * sizeof(D2StormHashEntryStrc), pArchive->szName, pArchive->hFile, &nRead);
    DecryptBlock((unsigned int*)pArchive->pHashTable, pArchive->pHeader->nHashEntries * sizeof(D2StormHashEntryStrc), HashString(3, "(hash table)"));
    pArchive->pBlockTable = (D2StormBlockStrc*)SMemAlloc(pArchive->pHeader->nBlockEntries * sizeof(D2StormBlockStrc), ".\\SOURCE\\SFILE.CPP", 0x1133, 0);
    ReadFileChecked(pArchive->pHeader->nBlockOffset + pArchive->nArchiveOffset, &pArchive->nFilePos, pArchive->pBlockTable, pArchive->pHeader->nBlockEntries << 4, pArchive->szName, pArchive->hFile, &nRead);
    DecryptBlock((unsigned int*)pArchive->pBlockTable, pArchive->pHeader->nBlockEntries << 4, HashString(3, "(block table)"));
    pArchive->pBlockTable->ExpandBlockEntries(pArchive->pHeader->nBlockEntries);
    if (pArchive->nArchiveOffset)
    {
        for (unsigned int i = 0; i < pArchive->pHeader->nBlockEntries; ++i)
        {
            if (pArchive->pBlockTable[i].nOffset)
                pArchive->pBlockTable[i].nOffset += pArchive->nArchiveOffset;
        }
    }
    ARCHIVEREC* pExisting;
    for (pExisting = gArchiveList_00708354.Head(); pExisting; pExisting = pExisting->m_link.Next())
    {
        if (pExisting->nPriority <= pArchive->nPriority)
            break;
    }
    gArchiveList_00708354.LinkNode(pArchive, 2, pExisting);
    if (pArchive->nMode)
    {
        StartCdThread();
    }
    else if ((nFlags & 1) && !bKeepOnFail)
    {
        SFileCloseArchive(pArchive);
        sub_0041C340_SetLastError(0x0F);
        return 0;
    }
    *phArchive = pArchive;
    LeaveCriticalSection(&gBasePathLock_00779068);
    ReadAdditionalAttributes(pArchive, pArchive->pBlockTable, pArchive->pHeader->nBlockEntries);
    EnterCriticalSection(&gBasePathLock_00779068);
    return 1;
}

int __stdcall SFileOpenFileAsArchive(void* hMpq, const char* szName, int nPriority, unsigned int nFlags, void** phArchive);

// 0x00415390
static void PrepareCryptTable(unsigned int dwSeed)
{
    if (!gpCryptTable_00779048)
    {
        gpCryptTable_00779048 = (unsigned int*)SMemAlloc(0x1400, gszSFileCpp_006CF084, 832, 0);
    }

    unsigned int* pTable = gpCryptTable_00779048;
    for (unsigned int i = 0; i < 0x100; ++i)
    {
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwHigh = dwSeed & 0xFFFF;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwValue = dwHigh << 16;
            dwValue |= dwSeed & 0xFFFF;
            unsigned int* pEntry = &pTable[i];
            *pEntry = dwValue;
        }
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwHigh = dwSeed & 0xFFFF;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwValue = dwHigh << 16;
            dwValue |= dwSeed & 0xFFFF;
            unsigned int* pEntry = &pTable[i + 0x100];
            *pEntry = dwValue;
        }
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwHigh = dwSeed & 0xFFFF;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwValue = dwHigh << 16;
            dwValue |= dwSeed & 0xFFFF;
            unsigned int* pEntry = &pTable[i + 0x200];
            *pEntry = dwValue;
        }
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwHigh = dwSeed & 0xFFFF;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwValue = dwHigh << 16;
            dwValue |= dwSeed & 0xFFFF;
            unsigned int* pEntry = &pTable[i + 0x300];
            *pEntry = dwValue;
        }
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwHigh = dwSeed & 0xFFFF;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwValue = dwHigh << 16;
            dwValue |= dwSeed & 0xFFFF;
            unsigned int* pEntry = &pTable[i + 0x400];
            *pEntry = dwValue;
        }
    }
}

// 0x00415B90
void __cdecl InitCryptTable()
{
    if (!gpCryptTable_00779048)
    {
        PrepareCryptTable(0x100001);
    }
}

// 0x004156A0
void D2StormBlockStrc::ExpandBlockEntries(unsigned int nCount)
{
    D2StormBlockEntryStrc* pSrc = (D2StormBlockEntryStrc*)this + nCount - 1;
    D2StormBlockStrc* pRec = this + nCount - 1;
    if (nCount > 1)
    {
        unsigned int* pClear = &pRec->aMd5[2];
        unsigned int nLeft = nCount - 1;
        do
        {
            memmove(pRec, pSrc, sizeof(D2StormBlockEntryStrc));
            --pSrc;
            pClear[-4] = 0;
            pClear[-5] = 0;
            pClear[-3] = 0;
            pClear[-2] = 0;
            pClear[-1] = 0;
            pClear[0] = 0;
            pClear[1] = 0;
            --pRec;
            pClear -= sizeof(D2StormBlockStrc) / sizeof(unsigned int);
        } while (--nLeft);
    }
    if (nCount)
    {
        pRec->tFileTime.dwHighDateTime = 0;
        pRec->tFileTime.dwLowDateTime = 0;
        pRec->nCrc = 0;
        pRec->aMd5[0] = 0;
        pRec->aMd5[1] = 0;
        pRec->aMd5[2] = 0;
        pRec->aMd5[3] = 0;
    }
}

// 0x00415930
static int GetArchiveRec(void* hArchive, ARCHIVEREC** ppRec)
{
    *ppRec = (ARCHIVEREC*)hArchive;
    return 1;
}

// 0x00415950
static int GetFileRec(void* hFile, FILEREC** ppRec)
{
    *ppRec = (FILEREC*)hFile;
    return 1;
}

// 0x00415F10
int __stdcall AdjustArchiveRefs(void* hArchive, int bRelease)
{
    ARCHIVEREC* pRec;
    EnterCriticalSection(&gBasePathLock_00779068);
    if (!GetArchiveRec(hArchive, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    pRec->nRefs += bRelease ? -1 : 1;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x00415FA0
int __stdcall SFileGetArchiveInfo(void* hArchive, int* pnInfo, int* pbKind3)
{
    if (pnInfo)
        *pnInfo = 0;
    if (pbKind3)
        *pbKind3 = 0;
    EnterCriticalSection(&gBasePathLock_00779068);
    ARCHIVEREC* pRec;
    if (!GetArchiveRec(hArchive, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    if (pnInfo)
        *pnInfo = pRec->nInfo;
    if (pbKind3)
        *pbKind3 = pRec->nKind == 3;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x00416160
int __stdcall sub_00416160_GetFileSubValue(void* hFile)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (!GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    if (pRec->nKind != -1)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    const int nValue = pRec->pBlock->nCrc;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nValue;
}

// 0x004161C0
int __stdcall sub_004161C0_GetFileSubQuad(void* hFile, D2StormQuadStrc* pQuad)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (!GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    if (pRec->nKind != -1)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    *pQuad = *(D2StormQuadStrc*)pRec->pBlock->aMd5;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x00416320
int __stdcall SFileGetFileCompressedSize(void* hFile, int* pnSizeHigh)
{
    int nResult = 0;
    if (pnSizeHigh)
        *pnSizeHigh = 0;
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (GetFileRec(hFile, &pRec) && pRec->nKind == -1)
        nResult = pRec->pBlock->nPackedSize;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nResult;
}

// 0x004181F0
int __stdcall SFileDdaGetVolume(void* hFile, int* pnVolume, int* pnPan)
{
    if (pnVolume)
        *pnVolume = 0;
    if (pnPan)
        *pnPan = 0;
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (!GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    AUDIOSTREAM* pNode;
    for (pNode = gDdaList_00708384.m_terminator.Next(); pNode; pNode = pNode->m_link.Next())
    {
        if (pNode->pFile == pRec)
            break;
    }
    if (!pNode)
    {
        sub_0041C340_SetLastError(0x85100072);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    if (pNode->nVolume == 0x7FFFFFFF)
        pNode->pBuffer->GetVolume((long*)&pNode->nVolume);
    if (pNode->nPan == 0x7FFFFFFF)
        pNode->pBuffer->GetPan((long*)&pNode->nPan);
    if (pnVolume)
        *pnVolume = pNode->nVolume;
    if (pnPan)
        *pnPan = pNode->nPan;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x004182D0
int __stdcall SFileDdaSetVolume(void* hFile, int nVolume, int nPan)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (!GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    AUDIOSTREAM* pNode;
    for (pNode = gDdaList_00708384.m_terminator.Next(); pNode; pNode = pNode->m_link.Next())
    {
        if (pNode->pFile == pRec)
            break;
    }
    if (!pNode)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        sub_0041C340_SetLastError(0x85100072);
        return 0;
    }
    if (nVolume != 0x7FFFFFFF && nVolume != pNode->nVolume)
    {
        pNode->nVolume = nVolume;
        pNode->pBuffer->SetVolume(nVolume);
    }
    if (nPan != 0x7FFFFFFF && nPan != pNode->nPan)
    {
        pNode->nPan = nPan;
        pNode->pBuffer->SetPan(nPan);
    }
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x00416030
int __stdcall SFileGetArchiveName(void* hArchive, char* szBuffer, unsigned int nBufferSize)
{
    if (szBuffer)
        *szBuffer = 0;
    if (!szBuffer)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    EnterCriticalSection(&gBasePathLock_00779068);
    ARCHIVEREC* pRec;
    if (!GetArchiveRec(hArchive, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    SStrCopy(szBuffer, pRec->szFileName, nBufferSize);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x004160F0
int __stdcall SFileGetFileArchive(void* hFile, int* pValue)
{
    if (pValue) *pValue = 0;
    if (!pValue) {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (!GetFileRec(hFile, &pRec)) {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    *pValue = pRec->nValue;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x00416230
int __stdcall CopyFileRecName(void* hFile, char* szBuffer, unsigned int nSize)
{
    if (szBuffer)
        *szBuffer = 0;
    if (!szBuffer)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (!GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    SStrCopy(szBuffer, pRec->szName, nSize);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x004162A0
int __stdcall SFileGetFileName(void* hFile, char* dest, unsigned int size)
{
 if (dest)
  *dest = 0;
 if (!dest) { sub_0041C340_SetLastError(0x57); return 0; }
 EnterCriticalSection(&gBasePathLock_00779068);
 FILEREC* rec;
 if (!GetFileRec(hFile, &rec)) {
  LeaveCriticalSection(&gBasePathLock_00779068);
  return 0;
 }
 SStrCopy(dest, rec->fullName ? rec->fullName : rec->name, size);
 LeaveCriticalSection(&gBasePathLock_00779068);
 return 1;
}

// 0x00416400
int __stdcall SFileGetFileTime(void* hFile, D2FileTimeStrc* pFileTime)
{
    VALIDATEBEGIN;
    VALIDATE(pFileTime);
    VALIDATEEND;

    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (!GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }

    if (pRec->nKind != -1)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return GetFileTime((void*)pRec->nKind, 0, 0, pFileTime);
    }

    *pFileTime = pRec->pBlock->tFileTime;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nValid ? 1 : 0;
}

// 0x004164B0
int __stdcall SFileSetBasePath(const char* szPath)
{
    VALIDATEBEGIN;
    VALIDATE(szPath);
    VALIDATEEND;

    if (!*szPath)
    {
        gszBasePath_00778F28[0] = 0;
    }
    else
    {
        const int bBackslash = szPath[SStrLen(szPath) - 1] == '\\';
        if (SStrLen(szPath) + !bBackslash + 1 > 0x104)
        {
            sub_0041C340_SetLastError(0xA1);
            return 0;
        }

        EnterCriticalSection(&gBasePathLock_00779068);
        SStrCopy(gszBasePath_00778F28, szPath, 0x104);
        if (!bBackslash)
            SStrPack(gszBasePath_00778F28, "\\", 0x104);
        LeaveCriticalSection(&gBasePathLock_00779068);
    }

    return nValid ? 1 : 0;
}

// 0x00416570
void __stdcall SFileSetDataChunkSize(int nChunkSize)
{
    VALIDATEBEGIN;
    VALIDATE(!(nChunkSize & (nChunkSize - 1)));
    VALIDATEENDVOID;
    if (nValid)
        gnReadUnit_00708348 = nChunkSize;
}

// 0x00416710
int __stdcall SFileUnloadFile(void* pBuffer)
{
    VALIDATEBEGIN;
    VALIDATE(pBuffer);
    VALIDATEEND;
    SMemFree(pBuffer, ".\\SOURCE\\SFILE.CPP", 0x1407, 0);
    return nValid ? 1 : 0;
}

// 0x004165A0
unsigned long __stdcall SFileSetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod)
{
    if (pnDistanceHigh && *pnDistanceHigh)
    {
        sub_0041C340_SetLastError(0x57);
        return (unsigned long)-1;
    }

    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (!GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return (unsigned long)-1;
    }

    if (pRec->nKind != -1)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return SetFilePointer((void*)pRec->nKind, nDistance, 0, dwMoveMethod);
    }

    switch (dwMoveMethod)
    {
    case 0:
        pRec->nPosition = nDistance;
        break;

    case 1:
        if (nDistance < 0 && pRec->nPosition < (unsigned long)-nDistance)
        {
            pRec->nPosition = 0;
        }
        else
        {
            pRec->nPosition += nDistance;
        }
        break;

    case 2:
        if (nDistance < 0 && pRec->pBlock->nFileSize < (unsigned long)-nDistance)
        {
            pRec->nPosition = 0;
        }
        else
        {
            pRec->nPosition = pRec->pBlock->nFileSize + nDistance;
        }
        break;
    }

    pRec->nCachePos = 0;
    pRec->nCacheSize = 0;
    const unsigned long nResult = pRec->nPosition;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nResult;
}

// 0x004166F0
unsigned short __stdcall SFileGetLocale()
{
    return gwValue_0077905C;
}

// 0x00416750
void __stdcall sub_00416750_Nop()
{
}

// 0x00416760
void __stdcall sub_00416760_Nop()
{
}

// 0x004167A0
char* __fastcall sub_004167A0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x004167B0
D2Storm4167B0Strc::~D2Storm4167B0Strc()
{
    tLink.Unlink();
}

// 0x004167F0
char* __fastcall sub_004167F0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x00416800
char* __fastcall DRLGPRESET_GetLinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

// 0x00416820
char* __fastcall sub_00416820_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x00416830
char* __fastcall sub_00416830_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x00416840
char* __fastcall sub_00416840_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

// 0x00416850
char* __fastcall sub_00416850_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x00416860
char* __fastcall sub_00416860_LinkPrev(D2StormLinkStrc* pLink)
{
    D2StormLinkStrc* pPrev = pLink->m_prevlink->m_prevlink;
    return (int)pPrev->m_next > 0 ? pPrev->m_next : 0;
}

// 0x004177A0
char* __fastcall sub_004177A0_LinkPrev(D2StormLinkStrc* pLink)
{
    D2StormLinkStrc* pPrev = pLink->m_prevlink->m_prevlink;
    return (int)pPrev->m_next > 0 ? pPrev->m_next : 0;
}

// 0x00416880
char* __fastcall sub_00416880_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

// 0x004168F0
D2Storm4168F0Strc::~D2Storm4168F0Strc()
{
    tLink.Unlink();
}

// 0x004169F0
void __fastcall sub_004169F0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x00416A00
void __fastcall sub_00416A00_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x00416A10
void __fastcall sub_00416A10_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x00416A20
void __fastcall sub_00416A20_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x00416A30
void __fastcall sub_00416A30_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x00416A90
int __fastcall sub_00416A90_TestField150(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n150)
        return 1;
    return 0;
}

// 0x00416AB0
int __fastcall sub_00416AB0_TestField14C(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n14C)
        return 1;
    return 0;
}

// 0x00416770
D2StormLinkStrc* D2StormLinkStrc::sub_00416770_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x004168C0
D2StormLinkStrc* D2StormLinkStrc::sub_004168C0_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x00416930
D2StormLinkStrc* D2StormLinkStrc::sub_00416930_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x00416970
D2StormLinkStrc* D2StormLinkStrc::sub_00416970_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x004169B0
D2StormLinkStrc* D2StormLinkStrc::sub_004169B0_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x00417E30
char* D2StormFixedListStrc::sub_00417E30_Next(char* pNode)
{
    return Link(pNode)->Next();
}

// 0x00417E90
void D2StormFixedListStrc::sub_00417E90_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x00418560
void D2StormFixedListStrc::sub_00418560_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x004185D0
char* D2StormFixedListStrc::sub_004185D0_RawNext(char* pNode)
{
    return Link(pNode)->m_next;
}

// 0x004185F0
void D2StormFixedListStrc::sub_004185F0_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x00418660
void D2StormFixedListStrc::sub_00418660_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x004186D0
char* D2StormFixedListStrc::sub_004186D0_RawNext(char* pNode)
{
    return Link(pNode)->m_next;
}

// 0x004186F0
char* D2StormFixedListStrc::sub_004186F0_RawNext(char* pNode)
{
    return Link(pNode)->m_next;
}

// 0x00418710
void D2StormFixedListStrc::sub_00418710_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x00416810
void __fastcall sub_00416810(PairStrc_00416810* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x00416890
void __fastcall sub_00416890(PairStrc_00416890* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x004168B0
void __fastcall sub_004168B0(PairStrc_004168B0* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x00416960
void __fastcall sub_00416960(PairStrc_00416960* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x004169A0
void __fastcall sub_004169A0(PairStrc_004169A0* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x004168A0
D2StormLinkStrc* __fastcall sub_004168A0_Identity(D2IdentityView* value) {return &value->link;}

// 0x004169E0
D2StormLinkStrc* __fastcall sub_004169E0_Identity(D2IdentityView* value) {return &value->link;}

// 0x00416A40
D2StormLinkStrc* __fastcall sub_00416A40_Identity(D2IdentityView* value) {return &value->link;}

// 0x00416A50
extern "C" void* __fastcall sub_00416A50(void* value) { return value; }

// 0x00416A60
D2StormLinkStrc* __fastcall sub_00416A60_Identity(D2IdentityView* value) {return &value->link;}

// 0x00416A70
extern "C" void* __fastcall sub_00416A70(void* value) { return value; }

// 0x00416A80
D2StormLinkStrc* __fastcall sub_00416A80_Identity(D2IdentityView* value) {return &value->link;}

// 0x00417770
char* Link::sub_00417770() { return (int)next<=NO_NODE ? 0 : next; }

// 0x00417790
char* D2SFileStormLinkM114Strc::sub_00417790_Next()
{
    return MaskNext();
}

// 0x004178A0
char* D2SFileStormLinkM114Strc::sub_004178A0_Next()
{
    return MaskNext();
}

// 0x004179A0
char* D2SFileStormLinkM114Strc::sub_004179A0_Next()
{
    return MaskNext();
}

// 0x00417EE0
static inline int IsNotListHead(D2SFileArchiveM114Strc* pArchive)
{
    if (pArchive->nKey && pArchive->pOwner->pList->Head() && pArchive->nKey == pArchive->pOwner->pList->Head()->nKey)
    {
        return 0;
    }
    return 1;
}

int __stdcall sub_M114_Emit_00417EE0(D2SFileArchiveM114Strc* pArchive)
{
    return IsNotListHead(pArchive) + 5;
}

bool D2ChatStormLinkStrc::IGNORELIST_IsLinkLinked()
{
    return m_next != 0;
}

char* D2ChatStormLinkStrc::sub_0060E1A0_Next()
{
    return MaskNext();
}

char* D2ChatStormLinkStrc::sub_0060E240_Next()
{
    return MaskNext();
}

void D2ChatStormLinkStrc::sub_0060E3B0_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E400_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E690_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E760_Unlink()
{
    Unlink();
}

D2ChatStormLinkAStrc::D2ChatStormLinkAStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

D2ChatStormLinkBStrc::D2ChatStormLinkBStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

char* D2ChatStormNodeStrc::IGNORELIST_GetStringEntryKey()
{
    return m_key;
}

D2ChatStormBaseArrayAStrc::D2ChatStormBaseArrayAStrc()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

unsigned int D2ChatStormBaseArrayAStrc::IGNORELIST_GetStringSlotArrayCount()
{
    return m_count;
}

D2ChatStormBaseArrayBStrc::D2ChatStormBaseArrayBStrc()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

unsigned int D2ChatStormBaseArrayBStrc::IGNORELIST_GetMappingSlotArrayCount()
{
    return m_count;
}

void D2ChatStormListAStrc::IGNORELIST_InitStringListTerminator()
{
    InitializeTerminator();
}

// 0x004177C0
char* D2ChatStormListAStrc::IGNORELIST_GetStringListHead()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::IGNORELIST_InitMappingListTerminator()
{
    InitializeTerminator();
}

char* D2ChatStormListBStrc::IGNORELIST_GetMappingListHead()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::IGNORELIST_ResetMappingList()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

char* __fastcall sub_0060E280_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* __fastcall sub_0060E360_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* D2ChatStormHashTableStrc::IGNORELIST_GetStringTableHead()
{
    return m_fulllist.m_terminator.MaskNext();
}

D2ChatStormListDStrc::D2ChatStormListDStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2ChatStormListEStrc::D2ChatStormListEStrc()
{
    m_linkoffset = 0xDDDDDDDD;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2CommonStormSlotListAStrc::~D2CommonStormSlotListAStrc()
{
    UnlinkAll();
}

D2CommonStormSlotListBStrc::~D2CommonStormSlotListBStrc()
{
    UnlinkAll();
}

D2CommonMappingEntryNodeStrc::~D2CommonMappingEntryNodeStrc()
{
    if (pMapped)
        SMemFree(pMapped, gszIgnoreListSourceFile_006E6290, 0x11, 0);
}

void D2CommonStringEntryNodeStrc::IGNORELIST_DestroyStringEntryNode()
{
    this->~D2CommonStringEntryNodeStrc();
}

void D2CommonStormHashTableAStrc::IGNORELIST_ClearStringTable()
{
    IGNORELIST_InternalClearStringTable(0);
}

// 0x004179F0
void D2ChatStormListAStrc::IGNORELIST_ResetStringList()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x00417E50
void D2StormLinkStrc::sub_00417E50()
{
    Unlink();
}

// 0x00418470
D2ChatStormListCStrc::D2ChatStormListCStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// Four more lists whose node types are not known yet; each stands for one TSList<T>, whose head,
// reset and constructor the original emits here without calling them.
struct D2SFileList004177D0Strc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2SFileList004177D0Strc();
    char* sub_004177D0_Head();
    void sub_00417A30_Reset();
};

struct D2SFileList004177E0Strc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2SFileList004177E0Strc();
    char* sub_004177E0_Head();
    void sub_00417C30_Reset();
};

struct D2SFileList004177F0Strc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2SFileList004177F0Strc();
    char* sub_004177F0_Head();
};

struct D2SFileList00417800Strc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2SFileList00417800Strc();
    char* sub_00417800_Head();
};

// 0x004177D0
char* D2SFileList004177D0Strc::sub_004177D0_Head()
{
    return (char*)((((int)m_terminator.m_next <= 0) - 1) & (int)m_terminator.m_next);
}

// 0x00417A30
void D2SFileList004177D0Strc::sub_00417A30_Reset()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x00418640
D2SFileList004177D0Strc::D2SFileList004177D0Strc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x004177E0
char* D2SFileList004177E0Strc::sub_004177E0_Head()
{
    return (char*)((((int)m_terminator.m_next <= 0) - 1) & (int)m_terminator.m_next);
}

// 0x00417C30
void D2SFileList004177E0Strc::sub_00417C30_Reset()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x004186B0
D2SFileList004177E0Strc::D2SFileList004177E0Strc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x004177F0
char* D2SFileList004177F0Strc::sub_004177F0_Head()
{
    return (char*)((((int)m_terminator.m_next <= 0) - 1) & (int)m_terminator.m_next);
}

// 0x00418CA0
D2SFileList004177F0Strc::D2SFileList004177F0Strc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x00417800
char* D2SFileList00417800Strc::sub_00417800_Head()
{
    return (char*)((((int)m_terminator.m_next <= 0) - 1) & (int)m_terminator.m_next);
}

// 0x00418D80
D2SFileList00417800Strc::D2SFileList00417800Strc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x00417B40
void D2StormListBaseStrc::sub_00417B40_Initialize()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x00417D40
void D2StormListBaseStrc::sub_00417D40_Initialize()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// build: symbol ??1ARCHIVEREC@SFile@Storm@@QAE@XZ 0x00418A50
// 0x00418490
int D2StormList00418490Strc::sub_00418490_IsEmpty()
{
    return m_terminator.Next() == 0;
}

// 0x004185B0
int D2StormList004185B0Strc::sub_004185B0_IsEmpty()
{
    return m_terminator.Next() == 0;
}

// 0x00418E60
inline FILEREC::FILEREC()
{
    pBuffer0x10C = 0;
    hFile = (void*)-1;
    archive = 0;
    pBuffer0x12C = 0;
    pBuffer0x138 = 0;
}

// 0x00418E90
void __fastcall RemoveArchiveRef(ARCHIVEREC* pArch)
{
    if (pArch && !--pArch->nRefCount)
        delete pArch;
}

unsigned long gdwStormThreadId_00779040; // 0x00779040

// 0x00418A50
Storm::SFile::ARCHIVEREC::~ARCHIVEREC()
{
    if (!this || !bMapped)
    {
        if (hFile != (void*)-1 && !bNoClose)
            CloseHandle(hFile);
        if (pBlockBuffer)
            SMemFree(pBlockBuffer, ".\\SOURCE\\SFILE.CPP", 0x260, 0);
        if (pHeader)
            SMemFree(pHeader, ".\\SOURCE\\SFILE.CPP", 0x261, 0);
        if (pBlockTable)
            SMemFree(pBlockTable, ".\\SOURCE\\SFILE.CPP", 0x269, 0);
        if (pBuffer0x140)
            SMemFree(pBuffer0x140, ".\\SOURCE\\SFILE.CPP", 0x26A, 0);
    }
}

// 0x00418B50
int __cdecl GetDefaultOpenFlags()
{
    int nFlags = 0;
    if (gnStormDirectFlags_00779058 & 1)
        nFlags |= 1;
    if (gnStormDirectFlags_00779058 & 2)
        nFlags |= 2;
    if (!gArchiveList_00708354.Head() && !gnStormDirectFlags_00779058)
        nFlags |= 1;
    return nFlags;
}

// 0x00419070
FILEREC::~FILEREC()
{
    if (hFile != (void*)-1)
        CloseHandle(hFile);
    if (archive)
        archive->pCachedFile = 0;
    if (pBuffer0x12C)
        SMemFree(pBuffer0x12C, ".\\SOURCE\\SFILE.CPP", 0x14B, 0);
    if (pBuffer0x138)
        SMemFree(pBuffer0x138, ".\\SOURCE\\SFILE.CPP", 0x14C, 0);
    ARCHIVEREC* pArch = archive;
    if (pArch && !--pArch->nRefCount)
        delete pArch;
    if (pBuffer0x10C)
        SMemFree(pBuffer0x10C, ".\\SOURCE\\SFILE.CPP", 0x14E, 0);
}

// 0x0041A880
void __cdecl StartCdThread()
{
    if (!ghStormThread_00779034)
    {
        ghStormEvent_00779054 = CreateEventA(0, 0, 0, 0);
        ghStormThread_00779034 = CreateThread(0, 0, CdThreadProc, 0, 0, &gdwStormThreadId_00779040);
        SetThreadPriority(ghStormThread_00779034, 1);
    }
}

// 0x0041F950
CHuffman::CHuffman()
{
    for (int i = 0; i < 0x80; ++i)
        aQuickLinks[i].nData[0] = 0;
}

// build: symbol ??1?$TSLinkedNode@UAUDIOSTREAM@@@@QAE@XZ 0x00418BE0
// 0x004199A0
AUDIOSTREAM::~AUDIOSTREAM()
{
    FILEREC* pFileRec = pFile;
    if (pFileRec && --pFileRec->nRefCount == 0)
        delete pFileRec;
    if (pBuffer && bBufferOwned)
        pBuffer->Release();
}

// build: symbol ??1?$TSLinkedNode@UREQUEST@@@@QAE@XZ 0x00418C20
// 0x0041A020
REQUEST::~REQUEST()
{
    FILEREC* pFileRec = pFile;
    if (pFileRec && --pFileRec->nRefCount == 0)
        delete pFileRec;
    AUDIOSTREAM* pAudio = stream;
    if (pAudio && --pAudio->nRefCount == 0)
        delete pAudio;
}

// build: symbol ??_GAUDIOSTREAM@@QAEPAXI@Z 0x00419A50
// build: symbol ??_GREQUEST@@QAEPAXI@Z 0x0041A0E0
// 0x00419A50
inline void AUDIOSTREAM::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x0041A0E0
inline void REQUEST::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

inline HANDLER::~HANDLER()
{
    tLink.Unlink();
}

void __stdcall SErrReportResourceLeak(const char* szName); // 0x0041D1E0
void __stdcall SErrReportNamedResourceLeak(const char* szName, const char* szDetail); // 0x0041D010
int __cdecl SFileDdaDestroy(); // 0x00419F30

// 0x0041A110
int __cdecl SFileDestroy()
{
    SFileDdaDestroy();
    if (ghStormThread_00779034)
    {
        gbThreadStop_00778F24 = 1;
        SetEvent(ghStormEvent_00779054);
        WaitForSingleObject(ghStormThread_00779034, 1000);
        if (ghStormEvent_00779054)
        {
            CloseHandle(ghStormEvent_00779054);
            ghStormEvent_00779054 = 0;
        }
        if (ghStormThread_00779034)
        {
            CloseHandle(ghStormThread_00779034);
            ghStormThread_00779034 = 0;
        }
    }
    if (gpCurrentRequest_0077902C)
    {
        delete gpCurrentRequest_0077902C;
        gpCurrentRequest_0077902C = 0;
    }
    D2StormListStrc& tRequests = (D2StormListStrc&)gRequestList_00708360;
    while (tRequests.Head())
        delete (REQUEST*)tRequests.Head();
    while (AUDIOSTREAM* pStream = gDdaList_00708384.Head())
    {
        SErrReportResourceLeak("AUDIOSTREAM");
        delete pStream;
    }
    while (FILEREC* pFile = gFileList_0070836C.Head())
    {
        SErrReportNamedResourceLeak("HSFILE", pFile->szName);
        delete pFile;
    }
    while (ARCHIVEREC* pArchive = gArchiveList_00708354.Head())
    {
        SErrReportNamedResourceLeak("HSARCHIVE", pArchive->szName);
        delete pArchive;
    }
    if (gpCryptTable_00779048)
    {
        SMemFree(gpCryptTable_00779048, ".\\SOURCE\\SFILE.CPP", 0xE24, 0);
        gpCryptTable_00779048 = 0;
    }
    if (gpStormExplodeWork)
    {
        SMemFree(gpStormExplodeWork, ".\\SOURCE\\SFILE.CPP", 0xE2A, 0);
        gpStormExplodeWork = 0;
    }
    if (gpStreamBuffer_00779050)
    {
        SMemFree(gpStreamBuffer_00779050, ".\\SOURCE\\SFILE.CPP", 0xE30, 0);
        gpStreamBuffer_00779050 = 0;
    }
    return 1;
}

// 0x0041AF60
int __stdcall SFileLoadFileEx2(void* hMpq, const char* szFileName, void** ppBuffer, unsigned int* pSize, unsigned int nExtraSize, int nFlags, D2StormOverlappedStrc* pOverlapped, int nArg8)
{
    VALIDATEBEGIN;
    VALIDATE(szFileName);
    if (ppBuffer)
        *ppBuffer = 0;
    else
        nValid = 0;
    VALIDATEEND;
    if (pSize)
        *pSize = 0;
    void* pBuffer = 0;
    void* hFile = 0;
    if (SFileOpenFileEx(hMpq, szFileName, nFlags, &hFile))
    {
        unsigned int nSize = SFileGetFileSize(hFile, 0);
        pBuffer = SMemAlloc(nSize + nExtraSize, ".\\SOURCE\\SFILE.CPP", 0xFEA, 0);
        if (SFileReadFileEx2(hFile, (unsigned char*)pBuffer, nSize, 0, pOverlapped, nArg8, 0))
        {
            if (nExtraSize)
                SMemZero(nSize + (char*)pBuffer, nExtraSize);
            *ppBuffer = pBuffer;
            if (pSize)
                *pSize = nSize;
        }
        else if (pBuffer)
            SMemFree(pBuffer, ".\\SOURCE\\SFILE.CPP", 0x1000, 0);
    }
    if (hFile)
        SFileCloseFile(hFile);
    return *ppBuffer != 0;
}

unsigned char gnStormByteFlag_0077905E;                                                                     // 0x0077905E

int (__stdcall* gpfnStormNotify_007790B8)(int nArg);                                                        // 0x007790B8

int __stdcall SFileFileExistsEx(void* hArchive, const char* szFileName, int nFlags);                  // 0x00418390

void __stdcall SErrSuppressErrors(int bSuppress);                                                     // 0x0041C360

void __cdecl SLogFlushAll();                                                                       // 0x0041FFF0

// 0x00416700
void __stdcall SFileSetPlatform(unsigned char nValue)
{
    gnStormByteFlag_0077905E = nValue;
}

// 0x00418B80
int __stdcall SFileFileExists(const char* szFileName)
{
    return SFileFileExistsEx(0, szFileName, GetDefaultOpenFlags());
}

// 0x0041BEB0
int __stdcall FlushAndNotify(int nArg)
{
    SErrSuppressErrors(1);
    SLogFlushAll();
    if (gpfnStormNotify_007790B8)
        gpfnStormNotify_007790B8(nArg);
    return 0;
}

struct D2StormBlockStrc;

void __cdecl InitCryptTable(); // 0x00415B90

// 0x00418390
int __stdcall SFileFileExistsEx(void* hArchive, const char* szFileName, int nFlags)
{
    VALIDATEBEGIN;
    VALIDATE(szFileName);
    VALIDATE(*szFileName);
    VALIDATEEND;
    EnterCriticalSection(&gBasePathLock_00779068);
    InitCryptTable();
    int nResult = GetFileBlockEntry(hArchive, szFileName, nFlags, 0, 0, 0);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nResult;
}

struct D2WaveChunkHeaderStrc
{
    unsigned int dwTag;
    unsigned int dwSize;
};

#define FILE_CURRENT 1

#define INVALID_SET_FILE_POINTER (-1)

int __stdcall SFileReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped);       // 0x0041B050

// 0x0041B210
static int FindWaveChunk(void* hFile, unsigned int dwTag, unsigned int* pChunk)
{
    D2WaveChunkHeaderStrc tHeader;
    while (SFileReadFile(hFile, &tHeader, sizeof(tHeader), 0, 0))
    {
        if (tHeader.dwTag == dwTag)
        {
            pChunk[0] = tHeader.dwSize;
            const int nPosition = SFileSetFilePointer(hFile, 0, 0, FILE_CURRENT);
            pChunk[1] = nPosition;
            return nPosition != INVALID_SET_FILE_POINTER;
        }

        if (SFileSetFilePointer(hFile, tHeader.dwSize, 0, FILE_CURRENT) == INVALID_SET_FILE_POINTER)
        {
            break;
        }
    }

    return 0;
}

// 0x00416370
int __stdcall SFileGetFileSize(void* hFile, unsigned int* pdwFileSizeHigh)
{
    if (pdwFileSizeHigh)
    {
        *pdwFileSizeHigh = 0;
    }

    EnterCriticalSection(&gBasePathLock_00779068);

    FILEREC* pRec;
    if (!GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return -1;
    }

    if (pRec->hFile != (void*)-1)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return GetFileSize(pRec->hFile, (unsigned long*)pdwFileSizeHigh);
    }

    const int nFileSize = pRec->pBlock->nFileSize;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nFileSize;
}

// 0x0041B0B0
static int __stdcall ReadAdditionalAttributes(ARCHIVEREC* pArchive, D2StormBlockStrc* pBlockTable, unsigned int nCount)
{
    int bResult = 0;
    void* hFile;
    if (SFileOpenFileEx(pArchive, "(attributes)", 0, &hFile))
    {
        unsigned int nSize = SFileGetFileSize(hFile, 0);
        unsigned char* pData = (unsigned char*)SMemAlloc(nSize, gszSFileCpp_006CF084, 1411, 0);
        if (SFileReadFile(hFile, pData, nSize, 0, 0))
        {
            unsigned int nExpected = 8;
            if (nSize >= nExpected)
            {
                unsigned int dwFlags = ((unsigned int*)pData)[1];
                unsigned char* pCursor = pData + 8;
                unsigned int bChecksum = dwFlags & 1;
                if (dwFlags & 1)
                    nExpected += nCount * 4;
                unsigned int bTime = dwFlags & 2;
                if (bTime)
                    nExpected += nCount * 8;
                unsigned int bDigest = dwFlags & 4;
                if (bDigest)
                    nExpected += nCount * 16;
                if (nSize == nExpected)
                {
                    if (bChecksum)
                    {
                        for (unsigned int i = 0; i < nCount; ++i, pCursor += 4)
                            pBlockTable[i].nCrc = *(unsigned int*)pCursor;
                    }
                    if (bTime)
                    {
                        for (unsigned int i = 0; i < nCount; ++i, pCursor += 8)
                            pBlockTable[i].tFileTime = *(D2FileTimeStrc*)pCursor;
                    }
                    if (bDigest)
                    {
                        for (unsigned int i = 0; i < nCount; ++i, pCursor += 16)
                        {
                            unsigned int* pDigest = pBlockTable[i].aMd5;
                            const unsigned int* pSource = (const unsigned int*)pCursor;
                            pDigest[0] = pSource[0];
                            pDigest[1] = pSource[1];
                            pDigest[2] = pSource[2];
                            pDigest[3] = pSource[3];
                        }
                    }
                    bResult = 1;
                }
            }
        }
        if (pData)
            SMemFree(pData, gszSFileCpp_006CF084, 1450, 0);
        SFileCloseFile(hFile);
    }
    return bResult;
}

#pragma pack(push, 1)

struct D2WaveFormatStrc { unsigned short format, channels; unsigned int samplesPerSec, avgBytesPerSec; unsigned short blockAlign, bitsPerSample, extraSize; };

struct D2WaveHeaderStrc { unsigned int tag, size, type, dataOffset, flags; };

struct D2WaveBaseFormatStrc { unsigned short format, channels; unsigned int samplesPerSec, avgBytesPerSec; unsigned short blockAlign, bitsPerSample; };

#pragma pack(pop)

struct D2SoundBufferDescStrc { unsigned int size, flags, bufferBytes, reserved; D2WaveFormatStrc* pFormat; };

struct D2DirectSoundStrc {
    virtual long __stdcall QueryInterface() = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall CreateSoundBuffer(D2SoundBufferDescStrc*, D2StormSoundBufferStrc**, void*) = 0;
};

D2DirectSoundStrc* gpDirectSound_00778F20; // 0x00778F20

extern unsigned int gnBlock_007790A0; // 0x007790A0

int __stdcall SFileDdaEnd(void*); // 0x0041A990

// 0x0041B280
int __stdcall SFileDdaBeginEx(void* hFile, unsigned int nBufferSize, unsigned int nFlags, unsigned int nOffset, int nVolume, int nPan, D2StormSoundBufferStrc* pBuffer)
{
    VALIDATEBEGIN;
    VALIDATE(nBufferSize);
    VALIDATEEND;
    if (!gpDirectSound_00778F20) { sub_0041C340_SetLastError(0x85100071); return 0; }
    FILEREC* pFile;
    EnterCriticalSection(&gBasePathLock_00779068);
    if (!GetFileRec(hFile, &pFile)) { LeaveCriticalSection(&gBasePathLock_00779068); return 0; }
    if (pFile->bDdaActive) SFileDdaEnd(hFile);
    if (!((gnStormDirectFlags_00779058 | nFlags) & 1) && (pFile->nKind != -1 || !pFile->archive)) {
        sub_0041C340_SetLastError(0x8510006f);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    if (!gnBlock_007790A0) gnBlock_007790A0 = 0x4000;
    gnStreamChunk_00779038 = gnBlock_007790A0;
    if (!gpStreamBuffer_00779050) gpStreamBuffer_00779050 = (unsigned char*)SMemAlloc(gnStreamChunk_00779038, gszSFileCpp_006CF084, 0xc5d, 0);
    if (pFile->archive) {
        if (pFile->archive->nKind == 0 || pFile->archive->nKind == 1) pFile->archive->nKind = 2;
    }
    LeaveCriticalSection(&gBasePathLock_00779068);
    unsigned int remainder = (gnStreamChunk_00779038 - 1) & nBufferSize;
    if (remainder) nBufferSize += gnStreamChunk_00779038 - remainder;
    if (nBufferSize < 2 * gnStreamChunk_00779038) nBufferSize = 2 * gnStreamChunk_00779038;
    SFileSetFilePointer(hFile, 0, 0, 0);
    D2WaveHeaderStrc riff;
    if (!SFileReadFileEx2(hFile, (unsigned char*)&riff, 12, 0, 0, 0, 0) || riff.tag != 0x46464952 || riff.type != 0x45564157) goto invalid;
    {
        unsigned int chunk[2] = {0, 0};
        if (!FindWaveChunk(hFile, 0x20746d66, chunk) || chunk[0] < 16) goto invalid;
        D2WaveFormatStrc format;
        {
            D2WaveBaseFormatStrc rawFormat;
            unsigned int formatSize = chunk[0];
            if (!SFileReadFileEx2(hFile, (unsigned char*)&rawFormat, 16, 0, 0, 0, 0) || SFileSetFilePointer(hFile, formatSize - 16, 0, 1) == -1) goto invalid;
            format.format = rawFormat.format;
            format.channels = rawFormat.channels;
            format.samplesPerSec = rawFormat.samplesPerSec;
            format.avgBytesPerSec = rawFormat.avgBytesPerSec;
            format.blockAlign = rawFormat.blockAlign;
            format.bitsPerSample = rawFormat.bitsPerSample;
            format.extraSize = 0;
            if (!FindWaveChunk(hFile, 0x61746164, chunk)) goto invalid;
        }
        if (nOffset) nOffset %= chunk[0];
        unsigned int offset = nOffset;
        int ownsBuffer = pBuffer == 0;
        if (ownsBuffer) {
            D2SoundBufferDescStrc desc;
            SMemZero(&desc, sizeof(desc));
            desc.size = 20;
            desc.flags = 0x80;
            if (nFlags & 0x20) desc.flags = 0xa0;
            if (nFlags & 0x40) desc.flags |= 0x40;
            desc.bufferBytes = nBufferSize;
            desc.pFormat = &format;
            gpDirectSound_00778F20->CreateSoundBuffer(&desc, &pBuffer, 0);
            if (!pBuffer) return 0;
        }
        if (nVolume && nVolume != 0x7fffffff) pBuffer->SetVolume(nVolume);
        if (nPan && nPan != 0x7fffffff) pBuffer->SetPan(nPan);
        EnterCriticalSection(&gBasePathLock_00779068);
        AUDIOSTREAM* node = gDdaList_00708384.NewNode(2, 0, 0);
        node->pFile = pFile;
        node->soundbuffersize = nBufferSize;
        node->nBytesPerSec = format.avgBytesPerSec;
        node->bRestart = (nFlags >> 18) & 1;
        node->waveheadersize = chunk[1];
        node->nSize = chunk[0];
        node->nVolume = nVolume;
        node->nPan = nPan;
        node->fillstatus = 0;
        node->nOffset = offset;
        node->nPlayed = offset;
        node->writecursor = offset;
        node->pBuffer = pBuffer;
        node->bBufferOwned = ownsBuffer;
        node->nFill = format.bitsPerSample == 8 ? 0x80 : 0;
        node->nRefs = 1;
        ++pFile->nRefCount;
        pBuffer->SetCurrentPosition(0);
        pFile->bDdaActive = 1;
        LeaveCriticalSection(&gBasePathLock_00779068);
        StartCdThread();
        SetEvent(ghStormEvent_00779054);
        return 1;
    }
invalid:
    sub_0041C340_SetLastError(0xd);
    return 0;
}

// 0x00419F30
int __cdecl SFileDdaDestroy()
{
    EnterCriticalSection(&gBasePathLock_00779068);
    gbStreamsPaused_00779044 = 1;
    LeaveCriticalSection(&gBasePathLock_00779068);

    while (ghStormThread_00779034 && (gpCurrentRequest_0077902C || gRequestList_00708360.Head()))
    {
        if (WaitForSingleObject(ghStormThread_00779034, 10) != WAIT_TIMEOUT)
            break;
    }

    EnterCriticalSection(&gBasePathLock_00779068);
    AUDIOSTREAM* pStream = gDdaList_00708384.m_terminator.m_next;
    if ((int)pStream > 0)
    {
        do
        {
            AUDIOSTREAM* pNext = pStream->m_link.Next();
            gDdaList_00708384.UnlinkNode(pStream);
            if (!--pStream->nRefCount)
                delete pStream;
            pStream = pNext;
        } while (pStream);
    }
    gpDirectSound_00778F20 = 0;
    gbStreamsPaused_00779044 = 0;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x00416AD0
unsigned int __stdcall InternalReadAligned(FILEREC* file, unsigned int offset, unsigned char* buffer, unsigned int size)
{
    VALIDATEBEGIN;
    VALIDATE(!((file->archive->sectorsize - 1) & offset));
    VALIDATEEND;
    if (!size) return 0;
    if ((file->pBlock->dwFlags & 0xFF00) && !file->bOffsetsLoaded) {
        unsigned long tableRead = 0;
        if (!ReadFileChecked(file->pBlock->nOffset, &file->archive->nFilePos, file->pBlockOffsets, 4 * file->nBlocks + 4, file->archive->szName, file->archive->hFile, &tableRead)) return 0;
        if (file->pBlock->dwFlags & 0x10000)
            DecryptBlock(file->pBlockOffsets, tableRead, file->nKey - 1);
        for (unsigned int i = 0; i < file->nBlocks; ++i) {
            if (file->pBlockOffsets[i] > file->pBlockOffsets[i + 1]) return 0;
        }
        file->bOffsetsLoaded = 1;
    }
    unsigned int packedOffset = offset;
    unsigned int packedSize = size;
    if (file->pBlock->dwFlags & 0xFF00) {
        packedOffset = file->pBlockOffsets[offset / file->archive->sectorsize];
        packedSize = file->pBlockOffsets[(offset + size) / file->archive->sectorsize] - packedOffset;
    }
    unsigned char* packed = buffer;
    if (file->pBlock->dwFlags & 0xFF00)
        packed = (unsigned char*)SMemAlloc(packedSize + 4, ".\\SOURCE\\SFILE.CPP", 0x382, 0);
    unsigned long bytesRead = 0;
    ReadFileChecked(file->pBlock->nOffset + packedOffset, &file->archive->nFilePos, packed, packedSize, file->archive->szName, file->archive->hFile, &bytesRead);
    unsigned int result = size;
    if (bytesRead < packedSize) {
        if (file->pBlock->dwFlags & 0xFF00) {
            unsigned int blockSize = file->archive->sectorsize;
            result = 0;
            for (unsigned int i = offset / blockSize + 1; i <= file->nBlocks; ++i) {
                if (bytesRead < file->pBlockOffsets[i] - packedOffset) break;
                result += blockSize;
            }
        } else result = bytesRead;
    }
    if (file->pBlock->dwFlags & 0x10000) {
        unsigned int blockSize = file->archive->sectorsize;
        unsigned int i = offset / blockSize;
        unsigned int count = (blockSize + result - 1) / blockSize;
        unsigned int position = 0;
        while (i < file->nBlocks && count--) {
            unsigned int bytes;
            if (file->pBlock->dwFlags & 0xFF00) {
                bytes = file->pBlockOffsets[i + 1] - file->pBlockOffsets[i];
            } else {
                bytes = (file->archive->sectorsize < result - position) ? file->archive->sectorsize : result - position;
                if (i == file->nBlocks - 1 && (file->pBlock->nFileSize & (file->archive->sectorsize - 1)))
                    bytes = (bytes < (file->pBlock->nFileSize & (file->archive->sectorsize - 1))) ? bytes : (file->pBlock->nFileSize & (file->archive->sectorsize - 1));
            }
            DecryptBlock((unsigned int*)(packed + position), bytes & ~3u, file->nKey + i);
            ++i;
            position += bytes;
        }
    }
    if (file->pBlock->dwFlags & 0xFF00) {
        unsigned int blockSize = file->archive->sectorsize;
        unsigned int destOffset = 0;
        unsigned int sourceOffset = 0;
        unsigned int i = offset / blockSize;
        unsigned int count = (blockSize + result - 1) / blockSize;
        for (; i < file->nBlocks && count--; ++i) {
            unsigned int sourceSize = file->pBlockOffsets[i + 1] - file->pBlockOffsets[i];
            unsigned int destSize;
            if (i == file->nBlocks - 1) {
                if (!file->pBlock->nFileSize || (file->pBlock->nFileSize & (file->archive->sectorsize - 1)))
                    destSize = file->pBlock->nFileSize & (file->archive->sectorsize - 1);
                else destSize = file->archive->sectorsize;
            } else destSize = file->archive->sectorsize;
            if (destSize > sourceSize) {
                switch (file->pBlock->dwFlags & 0xFF00) {
                case 0x100:
                    DecompressLzw((char*)(buffer + destOffset), (const char*)(packed + sourceOffset), sourceSize);
                    break;
                case 0x200:
                    {
                        unsigned int outputSize = destSize;
                        if (file->bCrc && file->nCrcState != 1 && (packed[sourceOffset] & 0xC0)) file->nCrcState = 1;
                        if (!SCompDecompress(buffer + destOffset, &outputSize, packed + sourceOffset, sourceSize, file->archive->szName))
                            SErrDisplayError(0x85100083, file->archive->szName, -4, 0, 0, 1);
                    }
                    break;
                }
            } else if (packed != buffer) {
                SMemCopy(buffer + destOffset, packed + sourceOffset, destSize);
            }
            destOffset += destSize;
            sourceOffset += sourceSize;
        }
    }
    if (packed != buffer) SMemFree(packed, ".\\SOURCE\\SFILE.CPP", 0x3EF, 0);
    return nValid ? result : 0;
}

// 0x0041A8F0
static void MarkRequestPriority(int nValue, void* pBuffer)
{
    if (!pBuffer)
        return;
    EnterCriticalSection(&gBasePathLock_00779068);
    REQUEST* pHead = gRequestList_00708360.Head();
    for (REQUEST* p = pHead; (int)p > 0; p = p->m_link.m_next)
    {
        if ((void*)p->nDestSize == pBuffer)
            p->nArg9 = nValue;
    }
    LeaveCriticalSection(&gBasePathLock_00779068);
}

// 0x0041A300
int __stdcall CancelRequest(void* pBuffer, void* pOther)
{
    if (!pBuffer && !pOther)
        return 0;
    EnterCriticalSection(&gBasePathLock_00779068);
    int bResult = 0;
    REQUEST* pHead = gRequestList_00708360.Head();
    REQUEST* pRequest = pHead;
    while ((int)pRequest > 0)
    {
        if ((pBuffer && (void*)pRequest->nDestSize == pBuffer) || (pOther && pRequest->pBuffer == pOther))
        {
            bResult = 1;
            if (pRequest->hEvent)
            {
                EVENTREC* pEvent = gEventList_00708378.NewNode(2, 0, 0);
                pEvent->hEvent = pRequest->hEvent;
            }
            REQUEST* pNext = pRequest->m_link.Next();
            pRequest->~REQUEST();
            SMemFree(pRequest, STORM_TYPENAME(REQUEST), -2, 0);
            pRequest = pNext;
        }
        else
        {
            pRequest = gRequestList_00708360.Link(pRequest)->m_next;
        }
    }
    LeaveCriticalSection(&gBasePathLock_00779068);
    return bResult;
}

// 0x0041A8D0
void __fastcall GetCdThread(unsigned long* pdwThreadId, void** phThread)
{
    StartCdThread();
    *pdwThreadId = gdwStormThreadId_00779040;
    *phThread = ghStormThread_00779034;
}

// 0x0041A930
void __stdcall SFileCancelRequest(void* pBuffer)
{
    VALIDATEBEGIN;
    VALIDATE(pBuffer);
    VALIDATEENDVOID;

    if (nValid)
        CancelRequest(pBuffer, 0);
}

// 0x0041A960
int __stdcall SFileCancelRequestEx(void* pBuffer)
{
    VALIDATEBEGIN;
    VALIDATE(pBuffer);
    VALIDATEEND;

    if (nValid)
        return CancelRequest(pBuffer, 0);
    return 0;
}

// 0x0041A990
int __stdcall SFileDdaEnd(void* hFile)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pFile;
    if (!GetFileRec(hFile, &pFile))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    AUDIOSTREAM* pStream = gDdaList_00708384.m_terminator.m_next;
    if ((int)pStream > 0)
    {
        do
        {
            AUDIOSTREAM* pNext = pStream->m_link.Next();
            if (pStream->pFile == pFile)
            {
                if (gpCurrentRequest_0077902C && gpCurrentRequest_0077902C->pBuffer && gpCurrentRequest_0077902C->pBuffer == pStream->pBuffer)
                    gpCurrentRequest_0077902C->pBuffer = 0;
                CancelRequest(0, pStream->pBuffer);
                pStream->m_link.Unlink();
                if (!--pStream->nRefCount)
                    delete pStream;
            }
            pStream = pNext;
        } while (pStream);
    }
    pFile->bDdaActive = 0;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x0041AA80
void __stdcall SFilePrioritizeRequest(void* pBuffer, int nValue)
{
    VALIDATEBEGIN;
    VALIDATE(pBuffer);
    VALIDATEENDVOID;
    if (nValid)
    {
        MarkRequestPriority(nValue > 0, pBuffer);
        if (nValue >= 1)
            SetEvent(ghStormEvent_00779054);
    }
}

// 0x00419790
static REQUEST* __stdcall IssueRequest(FILEREC* pFile, unsigned int nPosition, void* pDest, unsigned int nDestSize, D2StormSoundBufferStrc* pBuffer, unsigned int nBufferOffset, AUDIOSTREAM* pStream, unsigned int nBytes, unsigned int nDelay, int nArg9, int nUser, int bDelete, int bSignal, D2StormRequestCallbackStrc* pCallback)
{
    VALIDATEBEGIN;
    VALIDATE(pDest || pBuffer);
    VALIDATEEND;
    EnterCriticalSection(&gBasePathLock_00779068);
    REQUEST* pRequest = gRequestList_00708360.NewNode(2, 0, 0);
    pRequest->nUser = nUser;
    pRequest->pFile = pFile;
    pRequest->location = nPosition;
    if (pFile->hFile == INVALID_FILE_HANDLE)
        nPosition = (nPosition >> 1) + pFile->pBlock->nOffset;
    pRequest->nFileOffset = nPosition;
    pRequest->nDueTime = GetTickCount() + nDelay;
    pRequest->nArg9 = nArg9;
    pRequest->pDest = (unsigned char*)pDest;
    pRequest->nDestSize = nDestSize;
    pRequest->pBuffer = pBuffer;
    pRequest->soundbufferoffset = nBufferOffset;
    pRequest->stream = pStream;
    pRequest->nBytes = nBytes;
    pRequest->bDelete = bDelete;
    pRequest->pCallback = pCallback;
    pFile->nRequests += 1;
    if (pStream)
        pStream->nRefs += 1;
    LeaveCriticalSection(&gBasePathLock_00779068);
    if (bSignal)
        SetEvent(ghStormEvent_00779054);
    return pRequest;
}

struct D2StormOverlappedStrc
{
    unsigned int nInternal;
    unsigned int nInternalHigh;
    unsigned int nOffset;
    unsigned int nOffsetHigh;
    void* hEvent;
};

// 0x0041AAD0
int __stdcall SFileReadFileEx2(void* hFile, unsigned char* buffer, unsigned int size, unsigned int* read, D2StormOverlappedStrc* overlap, int nArg6, void* callback)
{
    if (read)
        *read = 0;
    VALIDATEBEGIN;
    VALIDATE(buffer);
    VALIDATEEND;
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* file;
    if (!GetFileRec(hFile, &file))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    if (!size)
    {
        if (overlap && overlap->hEvent)
            SetEvent(overlap->hEvent);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 1;
    }
    if (file->hFile != INVALID_FILE_HANDLE && !overlap)
    {
        int result = ReadFileRec(buffer, size, read, file, -1);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return result;
    }
    if (file->pBuffer && file->nCachePos < file->nCacheSize && !overlap)
    {
        unsigned int n = (size < (file->nCacheSize - file->nCachePos)) ? size : file->nCacheSize - file->nCachePos;
        SMemCopy(buffer, file->pBuffer + file->nCachePos, n);
        file->nPosition += n;
        file->nCachePos += n;
        buffer += n;
        size -= n;
        if (read)
            *read = n;
        if (!size)
        {
            if (file->bCrc && file->nCrcState == 4 && file->nCrc != file->pBlock->nCrc)
                SErrDisplayError(0x85100083, file->szName, -4, 0, 0, 1);
            LeaveCriticalSection(&gBasePathLock_00779068);
            return 1;
        }
    }
    unsigned char* dest = buffer;
    unsigned int count = size;
    if (!overlap)
    {
        unsigned int limit = 0x1000 < file->archive->sectorsize - (file->nPosition & (file->archive->sectorsize - 1)) ? 0x1000 : file->archive->sectorsize - (file->nPosition & (file->archive->sectorsize - 1));
        if (size < limit)
        {
            dest = file->pBuffer;
            count = limit;
        }
    }
    if (!count)
    {
        if (overlap && overlap->hEvent)
            SetEvent(overlap->hEvent);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 1;
    }
    unsigned int pos = overlap ? overlap->nOffset : file->nPosition;
    unsigned int total = 0;
    unsigned int chunk = gnReadUnit_00708348;
    if (file->hFile == INVALID_FILE_HANDLE && !file->archive->nMode)
    {
        total = InternalReadUnaligned(dest, count, file, pos);
        if (file->bCrc && file->nCrcState == 2 && file->nCrcPos == file->pBlock->nFileSize)
        {
            CrcBuffer(0, 0, &file->nCrc, 4);
            file->nCrcState = 4;
        }
        if (overlap && overlap->hEvent)
            SetEvent(overlap->hEvent);
    }
    else
    {
        StartCdThread();
        REQUEST* request = 0;
        void* event = overlap ? overlap->hEvent : CreateEventA(0, 1, 0, 0);
        unsigned int parts = (count + chunk - 1) / chunk;
        for (unsigned int i = 0; i < parts; ++i)
        {
            int last = i == parts - 1;
            unsigned int offset = i * chunk;
            unsigned int n = chunk < count - offset ? chunk : count - offset;
            request = IssueRequest(file, pos + i * chunk, dest + offset, (unsigned int)dest, 0, 0, 0, n, 0x7FFFFFFF, !overlap, (int)(last ? event : 0), (overlap || !last) ? 1 : 0, last, last ? (D2StormRequestCallbackStrc*)callback : 0);
            if (!last)
                total += n;
        }
        LeaveCriticalSection(&gBasePathLock_00779068);
        if (overlap)
            return 1;
        WaitForSingleObject(event, -1);
        EnterCriticalSection(&gBasePathLock_00779068);
        CloseHandle(event);
        total += request->nRead;
        request->~REQUEST();
        SMemFree(request, "delete", -1, 0);
    }
    unsigned int n = size < total ? size : total;
    if (dest != buffer)
    {
        SMemCopy(buffer, dest, n);
        file->nCachePos = n;
        file->nCacheSize = total;
    }
    if (!overlap)
        file->nPosition += n;
    if (read)
        *read += n;
    if (n == size)
    {
        if (file->bCrc && file->nCrcState == 4 && file->nCrc != file->pBlock->nCrc)
            SErrDisplayError(0x85100083, file->szName, -4, 0, 0, 1);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return nValid ? 1 : 0;
    }
    sub_0041C340_SetLastError(0x26);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 0;
}

static unsigned int UpdateStreamPosition(AUDIOSTREAM* pStream); // 0x00415760

// 0x00419C00
void __cdecl PumpStreams()
{
    if (gbStreamsPaused_00779044)
        return;
    AUDIOSTREAM* pHead = gDdaList_00708384.Head();
    for (AUDIOSTREAM* pStream = pHead; (int)pStream > 0; pStream = pStream->m_link.m_next)
    {
        if (pStream->fillstatus == 3 || (pStream->fillstatus == 2 && pStream->pFile->nPosition >= pStream->waveheadersize + pStream->nSize))
        {
            if (pStream->bRestart)
            {
                pStream->pFile->nPosition = pStream->waveheadersize;
                pStream->writecursor = 0;
                pStream->nCounter = 0;
            }
            else
            {
                unsigned int nPlay = UpdateStreamPosition(pStream);
                if (nPlay == -1)
                    continue;
                if (pStream->nPlayed >= pStream->nSize)
                {
                    pStream->pBuffer->Stop();
                    pStream->fillstatus = 4;
                    continue;
                }
                if ((nPlay - pStream->nextwrite) % pStream->soundbuffersize >= gnStreamChunk_00779038)
                {
                    unsigned int nCount;
                    if (gnStreamChunk_00779038 >= pStream->soundbuffersize - pStream->nextwrite)
                        nCount = pStream->soundbuffersize - pStream->nextwrite;
                    else
                        nCount = gnStreamChunk_00779038;
                    void* pLocked = 0;
                    unsigned long nLocked = nCount;
                    if (pStream->pBuffer->Lock(pStream->nextwrite, nCount, &pLocked, &nLocked, 0, 0, 0) >= 0)
                    {
                        SMemFill(pLocked, nLocked, pStream->nFill);
                        pStream->pBuffer->Unlock(pLocked, nLocked, 0, 0);
                        pStream->writecursor += nLocked;
                        pStream->nCounter += nLocked;
                        pStream->nextwrite += nLocked;
                        if (pStream->nextwrite >= pStream->soundbuffersize)
                            pStream->nextwrite -= pStream->soundbuffersize;
                    }
                }
                pStream->fillstatus = 3;
            }
        }
        if (pStream->fillstatus == 2)
        {
            unsigned int nPlay = UpdateStreamPosition(pStream);
            if (nPlay == -1)
                continue;
            if ((nPlay - pStream->nextwrite) % pStream->soundbuffersize < gnStreamChunk_00779038)
                continue;
            unsigned int nCount = pStream->soundbuffersize - pStream->nextwrite;
            if (gnStreamChunk_00779038 < nCount)
                nCount = gnStreamChunk_00779038;
            unsigned int nLeft = pStream->nSize + pStream->waveheadersize - pStream->pFile->nPosition;
            if (nCount >= nLeft)
                nCount = nLeft;
            if (gbAlignReads_007790A4)
            {
                unsigned int nOver = (pStream->pFile->archive->sectorsize - 1) & (pStream->pFile->nPosition + nCount);
                if (nOver && nOver < nCount)
                    nCount -= nOver;
            }
            IssueRequest(pStream->pFile, pStream->pFile->nPosition, 0, 0, pStream->pBuffer, pStream->nextwrite, pStream, nCount, 0, 0, 0, 1, 0, 0);
            pStream->pFile->nPosition += nCount;
            pStream->nextwrite += gnStreamChunk_00779038;
            if (pStream->nextwrite >= pStream->soundbuffersize)
                pStream->nextwrite -= pStream->soundbuffersize;
        }
        else if (pStream->fillstatus == 0)
        {
            unsigned int nDone = 0;
            unsigned int nTotal;
            if (pStream->soundbuffersize < pStream->nSize - pStream->nOffset)
                nTotal = pStream->soundbuffersize;
            else
                nTotal = pStream->nSize - pStream->nOffset;
            pStream->pFile->nPosition = pStream->waveheadersize + pStream->nOffset;
            unsigned int nIndex = 0;
            if (gbAlignReads_007790A4)
            {
                nDone = gnStreamChunk_00779038 < nTotal ? gnStreamChunk_00779038 : nTotal;
                unsigned int nOver = (pStream->pFile->archive->sectorsize - 1) & (pStream->pFile->nPosition + nDone);
                if (nOver && nOver < nDone)
                    nDone -= nOver;
                IssueRequest(pStream->pFile, pStream->pFile->nPosition, 0, 0, pStream->pBuffer, 0, pStream, nDone, 0, 0, 0, 1, 0, 0);
                pStream->pFile->nPosition += nDone;
                nIndex = 1;
            }
            for (; nDone < nTotal; nDone += gnStreamChunk_00779038)
            {
                unsigned int nCount = gnStreamChunk_00779038;
                if (nCount >= nTotal - nDone)
                    nCount = nTotal - nDone;
                IssueRequest(pStream->pFile, pStream->pFile->nPosition, 0, 0, pStream->pBuffer, nDone, pStream, nCount, nIndex, 0, 0, 1, 0, 0);
                ++nIndex;
                pStream->pFile->nPosition += nCount;
            }
            pStream->fillstatus = 1;
            pStream->nextwrite = nDone % pStream->soundbuffersize;
        }
    }
}

// 0x004158E0
void __cdecl InitBasePath()
{
    GetModuleFileNameA(GetModuleHandleA(0), gszBasePath_00778F28, 0x104);
    char* pSeparator = (char*)SStrChrR(gszBasePath_00778F28, '\\');
    if (pSeparator)
        *pSeparator = 0;
    SStrPack(gszBasePath_00778F28, "\\", 0x104);
}

unsigned short __stdcall SFileGetLocale();

void __stdcall sub_00416750_Nop();

void __stdcall sub_00416760_Nop();

char* __fastcall sub_004167A0_LinkNext(D2StormLinkStrc* pLink);

char* __fastcall sub_004167F0_LinkNext(D2StormLinkStrc* pLink);

char* __fastcall DRLGPRESET_GetLinkRawNext(D2StormLinkStrc* pLink);

char* __fastcall sub_00416820_LinkNext(D2StormLinkStrc* pLink);

char* __fastcall sub_00416830_LinkNext(D2StormLinkStrc* pLink);

char* __fastcall sub_00416840_LinkRawNext(D2StormLinkStrc* pLink);

char* __fastcall sub_00416850_LinkNext(D2StormLinkStrc* pLink);

char* __fastcall sub_00416880_LinkRawNext(D2StormLinkStrc* pLink);

void __fastcall sub_004169F0_InitTerminator(D2StormListStrc* pList);

void __fastcall sub_00416A00_InitTerminator(D2StormListStrc* pList);

void __fastcall sub_00416A10_InitTerminator(D2StormListStrc* pList);

void __fastcall sub_00416A20_InitTerminator(D2StormListStrc* pList);

void __fastcall sub_00416A30_InitTerminator(D2StormListStrc* pList);

int __fastcall sub_00416A90_TestField150(D2Storm416A90Strc* pRecord);

int __fastcall sub_00416AB0_TestField14C(D2Storm416A90Strc* pRecord);

// 0x00417F10
static int __stdcall GetFileBlockEntry(void* hArchive, const char* szName, unsigned int nFlags, ARCHIVEREC** ppArchive, D2StormBlockStrc** ppBlock, char* szFoundPath)
{
    if (ppArchive)
        *ppArchive = 0;
    if (ppBlock)
        *ppBlock = 0;
    int bResult = 0;
    ARCHIVEREC* pOnly = 0;
    if (!hArchive || GetArchiveRec(hArchive, &pOnly))
    {
        ARCHIVEREC* pArchive = gArchiveList_00708354.Head();
        do
        {
            if (pOnly && pArchive != pOnly)
                continue;
            if (pArchive && pArchive->nRefs > 0)
                continue;
            ARCHIVEREC* pSearch = pArchive;
            if (pArchive && pArchive->pPatch)
                pSearch = pArchive->pPatch;
            const char* szLookup = szName;
            char szPrefixed[0x104];
            if (pArchive && pArchive->szPrefix[0])
            {
                char* szEnd = szPrefixed + SStrCopy(szPrefixed, pArchive->szPrefix, 0x104);
                szEnd += SStrCopy(szEnd, gszBackslash_006FF9B8, 0x104);
                SStrCopy(szEnd, szName, 0x104);
                szLookup = szPrefixed;
            }
            char szDiskPath[0x104];
            if ((nFlags & 3) && (!pSearch || !pSearch->bNoDiskSearch)
                && FindDiskFile(nFlags, szLookup, szDiskPath))
            {
                if (szFoundPath)
                    SStrCopy(szFoundPath, szDiskPath, 0x104);
                bResult = 2;
                goto Done;
            }
            if (pArchive)
            {
                const int nIndex = FindHashEntry(gwLocale_0077905C, gnPlatform_0077905E, pSearch, szLookup);
                if (nIndex != -1)
                {
                    bResult = 1;
                    D2StormBlockStrc* pBlock = GetBlockEntry(pSearch, nIndex);
                    const int bValid = (pBlock->dwFlags & 0x80000000) && (!(nFlags & 4) || !(pBlock->dwFlags & 0x1FF00));
                    if (!bValid)
                    {
                        bResult = 0;
                        sub_0041C340_SetLastError(0x3EE);
                    }
                    else
                    {
                        if (ppArchive)
                            *ppArchive = pSearch;
                        if (ppBlock)
                            *ppBlock = pBlock;
                    }
                    goto Done;
                }
            }
        }
        while (pArchive && (pArchive = pArchive->m_link.Next()) != 0);
        sub_0041C340_SetLastError(2);
    }
Done:
    return bResult;
}

// build: symbol ??_GARCHIVEREC@SFile@Storm@@QAEPAXI@Z 0x00418B20
// build: symbol ??_GFILEREC@@QAEPAXI@Z 0x00419150
// build: symbol ??_GD2StormRecord419000Strc@@QAEPAXI@Z 0x00419000
inline D2StormRecord419000Strc::~D2StormRecord419000Strc()
{
    tLink.Unlink();
}

void sub_F21_EmitScalarDeletingDestructors(ARCHIVEREC* pArchive, FILEREC* pFile, D2StormRecord419000Strc* pRecord)
{
    delete pArchive;
    delete pFile;
    delete pRecord;
}

static void DecryptBlock(unsigned int nKey, unsigned int* pData, unsigned int nBytes); // 0x004152D0

static int __stdcall ReadFileChecked(unsigned int* pnFilePos, void* pBuffer, unsigned int nSize, const char* szName, unsigned long* pnRead, unsigned int nOffset, void* hFile);

static int __stdcall ReadFileRec(void* pBuffer, unsigned int nSize, unsigned int* pnRead, unsigned int nOffset, FILEREC* pFile); // 0x00415560

static void FillStreamBuffer(REQUEST* pRequest); // 0x004157C0

static unsigned int LoadSector(unsigned int nOffset, FILEREC* pFile); // 0x00416FB0

static unsigned int __stdcall InternalReadUnaligned(unsigned char* pBuffer, unsigned int nSize, FILEREC* pFile, unsigned int nPosition);

// 0x004172F0
int __stdcall SFileAuthenticateArchive(void* hArchive, unsigned int* pnResult)
{
    if (SFileAuthenticateArchiveEx(hArchive, pnResult, 0, 0, 0, 0))
        return 1;
    if (pnResult)
        *pnResult = 0;
    ARCHIVEREC* pArchive;
    if (!GetArchiveRec(hArchive, &pArchive))
        return 0;
    int bResult = 0;
    if (FindHashEntry(0, 0, pArchive, "(signature)") == -1)
    {
        if (pnResult)
            *pnResult = 1;
        sub_0041C340_SetLastError(0x4DC);
        return 0;
    }
    D2StormCryptFuncsStrc* pFuncs = 0;
    unsigned int hHash = 0;
    unsigned int hKey = 0;
    void* hMapping = 0;
    unsigned int hProv = 0;
    unsigned char* pView = 0;
    void* hLibrary = LoadLibraryA("advapi32.dll");
    if (hLibrary)
    {
        pFuncs = (D2StormCryptFuncsStrc*)SMemAlloc(sizeof(D2StormCryptFuncsStrc), ".\\SOURCE\\SFILE.CPP", 0xA74, 0);
        if (!(pFuncs->pfnAcquireContext = (D2CryptAcquireContextFn)GetProcAddress(hLibrary, "CryptAcquireContextA")))
            goto cleanup;
        if (!(pFuncs->pfnCreateHash = (D2CryptCreateHashFn)GetProcAddress(hLibrary, "CryptCreateHash")))
            goto cleanup;
        if (!(pFuncs->pfnDestroyHash = (D2CryptDestroyFn)GetProcAddress(hLibrary, "CryptDestroyHash")))
            goto cleanup;
        if (!(pFuncs->pfnDestroyKey = (D2CryptDestroyFn)GetProcAddress(hLibrary, "CryptDestroyKey")))
            goto cleanup;
        if (!(pFuncs->pfnHashData = (D2CryptHashDataFn)GetProcAddress(hLibrary, "CryptHashData")))
            goto cleanup;
        if (!(pFuncs->pfnImportKey = (D2CryptImportKeyFn)GetProcAddress(hLibrary, "CryptImportKey")))
            goto cleanup;
        if (!(pFuncs->pfnReleaseContext = (D2CryptReleaseContextFn)GetProcAddress(hLibrary, "CryptReleaseContext")))
            goto cleanup;
        if (!(pFuncs->pfnSignHash = (D2CryptSignHashFn)GetProcAddress(hLibrary, "CryptSignHashA")))
            goto cleanup;
        if (!(pFuncs->pfnVerifySignature = (D2CryptVerifySignatureFn)GetProcAddress(hLibrary, "CryptVerifySignatureA")))
            goto cleanup;
        if (!pFuncs->pfnAcquireContext(&hProv, "Blizzard_Storm", "Microsoft Base Cryptographic Provider v1.0", 1, 0)
            && !pFuncs->pfnAcquireContext(&hProv, "Blizzard_Storm", "Microsoft Base Cryptographic Provider v1.0", 1, 8))
            goto cleanup;
        hMapping = CreateFileMappingA(pArchive->hFile, 0, 0x8000002, 0, 0, 0);
        if (!hMapping)
            goto cleanup;
        pView = (unsigned char*)MapViewOfFile(hMapping, 4, 0, 0, 0);
        if (!pView)
            goto cleanup;
        const int nIndex = FindHashEntry(0, 0, pArchive, "(signature)");
        if (nIndex == -1)
            goto cleanup;
        D2StormBlockStrc* pBlock = GetBlockEntry(pArchive, nIndex);
        if ((pBlock->dwFlags & 0x1FF00) || pBlock->nFileSize <= 8 || !pBlock->nOffset)
        {
            if (pnResult)
                *pnResult = 2;
            goto cleanup;
        }
        const unsigned int nKeyIndex = *(unsigned int*)(pBlock->nOffset + pView);
        if (nKeyIndex >= 1)
        {
            if (pnResult)
                *pnResult = 3;
            goto cleanup;
        }
        void* hResInfo = FindResourceA(StormGetInstance(), gaSignatureKeys_006CF07C[nKeyIndex].szResourceName, "#256");
        void* hResData = LoadResource(StormGetInstance(), hResInfo);
        void* pKey = LockResource(hResData);
        if (pKey)
            pFuncs->pfnImportKey(hProv, pKey, SizeofResource(StormGetInstance(), hResInfo), 0, 0, &hKey);
        FreeResource(hResData);
        if (!hKey)
            goto cleanup;
        if (!pFuncs->pfnCreateHash(hProv, 0x8003, 0, 0, &hHash))
            goto cleanup;
        if (!pFuncs->pfnHashData(hHash, pView + pArchive->nArchiveOffset, pBlock->nOffset - pArchive->nArchiveOffset, 0))
            goto cleanup;
        unsigned char* pZero = (unsigned char*)SMemAlloc(pBlock->nFileSize, ".\\SOURCE\\SFILE.CPP", 0xACA, 8);
        const int bHashed = pFuncs->pfnHashData(hHash, pZero, pBlock->nFileSize, 0);
        SMemFree(pZero, ".\\SOURCE\\SFILE.CPP", 0xACF, 0);
        if (!bHashed)
            goto cleanup;
        if (pBlock->nOffset + pBlock->nFileSize < pArchive->pHeader->nArchiveSize + pArchive->nArchiveOffset)
        {
            if (!pFuncs->pfnHashData(hHash, pView + pBlock->nOffset + pBlock->nFileSize, pArchive->pHeader->nArchiveSize - pBlock->nOffset - pBlock->nFileSize + pArchive->nArchiveOffset, 0))
                goto cleanup;
        }
        if (pFuncs->pfnVerifySignature(hHash, pView + pBlock->nOffset + 8, pBlock->nFileSize - 8, hKey, 0, 0))
        {
            bResult = 1;
            if (pnResult)
                *pnResult = gaSignatureKeys_006CF07C[nKeyIndex].nResult;
        }
        else
        {
            if (pnResult)
                *pnResult = 2;
        }
    }
cleanup:
    if (hHash)
        pFuncs->pfnDestroyHash(hHash);
    if (hKey)
        pFuncs->pfnDestroyKey(hKey);
    if (pView)
        UnmapViewOfFile(pView);
    if (hMapping)
        CloseHandle(hMapping);
    if (hProv)
    {
        pFuncs->pfnReleaseContext(hProv, 0);
        pFuncs->pfnAcquireContext(&hProv, "Blizzard_Storm", "Microsoft Base Cryptographic Provider v1.0", 1, 0x10);
    }
    if (pFuncs)
        SMemFree(pFuncs, ".\\SOURCE\\SFILE.CPP", 0xAF8, 0);
    if (hLibrary)
        FreeLibrary(hLibrary);
    if (!bResult)
        sub_0041C340_SetLastError(0x4DC);
    return bResult;
}

struct D2StormExplodeParamStrc
{
    const char* pSource;
    unsigned int nSourcePos;
    char* pDest;
    unsigned int nDestPos;
    unsigned int nSourceSize;
};

// 0x00415240
int __stdcall DecompressLzw(char* pDest, const char* pSource, unsigned int nSourceSize)
{
    EnterCriticalSection(&gStormExplodeLock);
    if (!gpStormExplodeWork)
        gpStormExplodeWork = (char*)SMemAlloc(0x3134, ".\\SOURCE\\SFILE.CPP", 0x2C9, 0);
    D2StormExplodeParamStrc tParam;
    tParam.pSource = pSource;
    tParam.nSourcePos = 0;
    tParam.pDest = pDest;
    tParam.nDestPos = 0;
    tParam.nSourceSize = nSourceSize;
    sub_006B01B0_Explode(sub_004151D0_ExplodeRead, sub_00415210_ExplodeWrite, gpStormExplodeWork, &tParam);
    LeaveCriticalSection(&gStormExplodeLock);
    return 1;
}

// 0x00415960
int __stdcall CheckCdVolume(const char* szPath)
{
    char szRoot[4];
    SStrCopy(szRoot, szPath, 4);
    unsigned int nDriveType = GetDriveTypeA(szRoot);
    char szFileSystem[0x104];
    unsigned long dwFlags = 0;
    SMemZero(szFileSystem, 0x104);
    if (!GetVolumeInformationA(szRoot, 0, 0, 0, 0, &dwFlags, szFileSystem, 0x104))
        return 0;
    unsigned long dwSectorsPerCluster = 0;
    unsigned long dwBytesPerSector = 0;
    unsigned long dwFreeClusters = 0;
    unsigned long dwTotalClusters = 0;
    if (!GetDiskFreeSpaceA(szRoot, &dwSectorsPerCluster, &dwBytesPerSector, &dwFreeClusters, &dwTotalClusters))
        return 0;
    unsigned int nKey = (dwFlags & 4) ^ *(unsigned int*)szFileSystem ^ dwFreeClusters ^ dwBytesPerSector ^ nDriveType;
    unsigned short wKey = (unsigned short)((nKey >> 16) ^ nKey);
    return wKey == 0x1F00 || wKey == 0x805;
}

// 0x00415760
static unsigned int UpdateStreamPosition(AUDIOSTREAM* pStream)
{
    unsigned long nPlay = 0;
    unsigned long nWrite = 0;
    if (pStream->pBuffer->GetCurrentPosition(&nPlay, &nWrite) < 0)
        return -1;
    unsigned int nWritten = pStream->writecursor;
    int nAhead = nWritten % pStream->soundbuffersize - nPlay;
    if (nAhead <= 0)
        nAhead += pStream->soundbuffersize;
    unsigned int nPlayed = nWritten - nAhead;
    if (nPlayed >= pStream->nSize)
        nPlayed = pStream->nSize;
    pStream->nPlayed = nPlayed;
    return nPlay;
}

// 0x00418140
int __stdcall SFileDdaGetPos(void* hFile, unsigned int* pnPlayed, unsigned int* pnSize)
{
    int bResult = 0;
    unsigned int nSize = 0;
    unsigned int nPlayed = 0;
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (GetFileRec(hFile, &pRec))
    {
        AUDIOSTREAM* pStream;
        for (pStream = gDdaList_00708384.m_terminator.Next(); pStream; pStream = pStream->m_link.Next())
        {
            if (pStream->pFile == pRec)
                break;
        }
        if (!pStream)
        {
            sub_0041C340_SetLastError(0x85100072);
        }
        else
        {
            nSize = pStream->nSize;
            const int nState = pStream->fillstatus;
            if (nState == 4)
            {
                sub_0041C340_SetLastError(0x85100072);
            }
            else
            {
                bResult = 1;
                if (nState != 0 && nState != 1)
                {
                    UpdateStreamPosition(pStream);
                    nPlayed = pStream->nPlayed;
                }
            }
        }
    }
    if (pnPlayed)
        *pnPlayed = nPlayed;
    if (pnSize)
        *pnSize = nSize;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return bResult;
}

// 0x00415EE0
extern "C" int __stdcall SFileDdaInitialize(int nValue)
{
    VALIDATEBEGIN;
    VALIDATE(nValue);
    if (!nValid)
    {
        sub_0041C340_SetLastError(0x57);
        return nValid;
    }
    gpDirectSound_00778F20 = (D2DirectSoundStrc*)nValue;
    return nValid ? 1 : 0;
}

// 0x00415F70
int __stdcall SFileEnableDirectAccess(int nFlags)
{
    gnStormDirectFlags_00779058 = nFlags;
    return 1;
}

// 0x00419980
int __stdcall SFileOpenFile(const char* szFileName, void** phFile)
{
    return SFileOpenFileEx(0, szFileName, GetDefaultOpenFlags(), phFile);
}

// 0x0041B650
int __stdcall SFileLoadFile(const char* szFileName, void** ppBuffer, unsigned int* pSize, unsigned int nExtraSize, void* pOverlapped)
{
    return SFileLoadFileEx2(0, szFileName, ppBuffer, pSize, nExtraSize, GetDefaultOpenFlags(), pOverlapped, 0);
}

// 0x0041BA30
int __stdcall SFileDdaBegin(void* hFile, int nBufferSize, unsigned int nFlags)
{
    return SFileDdaBeginEx(hFile, nBufferSize, nFlags, 0, 0x7FFFFFFF, 0x7FFFFFFF, 0);
}

// 0x00415BB0
int __stdcall SFileAuthenticateArchiveEx(void* hArchive, unsigned int* pnResult, int nArg3, int nArg4, int nArg5, int nArg6)
{
    if (!nArg3 && !nArg5)
    {
        nArg3 = (int)gabSignatureModulus_006CEF78;
        nArg4 = 0x100;
        nArg5 = (int)gabSignatureExponent_006CF078;
        nArg6 = 4;
    }
    if (!pnResult)
    {
        unsigned int nDummy;
        pnResult = &nDummy;
    }
    *pnResult = 0;
    ARCHIVEREC* pArchive;
    if (!GetArchiveRec(hArchive, &pArchive))
    {
        return 0;
    }
    D2StormHashBufferStrc* pHash = 0;
    SSignatureVerifyStream_Begin(&pHash, nArg4, nArg6);
    EnterCriticalSection(&gBasePathLock_00779068);
    char* pBuffer = (char*)SMemAlloc(0x10000, ".\\SOURCE\\SFILE.CPP", 0xB33, 0);
    unsigned long nPosition = SetFilePointer(pArchive->hFile, 0, 0, 1);
    if (nPosition != (unsigned long)-1 && SetFilePointer(pArchive->hFile, pArchive->nArchiveOffset, 0, 0) != (unsigned long)-1)
    {
        unsigned int nRemaining = GetHashWindowSize(pHash) + pArchive->pHeader->nArchiveSize;
        while (nRemaining)
        {
            unsigned int nChunk = nRemaining > 0x10000 ? 0x10000 : nRemaining;
            unsigned long nRead = 0;
            nRemaining -= nChunk;
            if (!ReadFile(pArchive->hFile, pBuffer, nChunk, &nRead, 0) || nRead != nChunk)
            {
                goto done;
            }
            HashBufferedData(pHash, pBuffer, nChunk);
        }
        SetFilePointer(pArchive->hFile, nPosition, 0, 0);
    }
done:
    SMemFree(pBuffer, ".\\SOURCE\\SFILE.CPP", 0xB59, 0);
    LeaveCriticalSection(&gBasePathLock_00779068);
    unsigned int nResult = SSignatureVerifyStream_Finish(pHash, (const void*)nArg3, (const void*)nArg5) ? 5 : 1;
    *pnResult = nResult;
    return nResult == 5;
}

// 0x00415D50
unsigned int __stdcall CalcFileCrc(const char* szFileName)
{
    VALIDATEBEGIN;
    VALIDATE(szFileName);
    VALIDATE(*szFileName);
    VALIDATEEND;
    EnterCriticalSection(&gBasePathLock_00779068);
    void* hFile = CreateFileA(szFileName, 0x80000000, 1, 0, 3, 0x8000000, 0);
    if (hFile == (void*)-1)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    unsigned int nCrc = 0;
    unsigned long nSize = GetFileSize(hFile, 0);
    if (nSize != (unsigned long)-1)
    {
        unsigned char* pBuffer = (unsigned char*)SMemAlloc(0x1000, ".\\SOURCE\\SFILE.CPP", 0xB83, 0);
        CrcBuffer(0, 0, &nCrc, 1);
        while (nSize > 0)
        {
            unsigned long nChunk = nSize < 0x1000 ? nSize : 0x1000;
            unsigned long nRead;
            ReadFile(hFile, pBuffer, nChunk, &nRead, 0);
            if (nChunk != nRead)
            {
                if (pBuffer)
                {
                    SMemFree(pBuffer, ".\\SOURCE\\SFILE.CPP", 0xB8D, 0);
                }
                CloseHandle(hFile);
                LeaveCriticalSection(&gBasePathLock_00779068);
                return 0;
            }
            CrcBuffer(pBuffer, nChunk, &nCrc, 2);
            nSize -= nChunk;
        }
        CrcBuffer(0, 0, &nCrc, 4);
        if (pBuffer)
        {
            SMemFree(pBuffer, ".\\SOURCE\\SFILE.CPP", 0xB97, 0);
        }
    }
    CloseHandle(hFile);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nCrc;
}

// 0x0041B680
int __stdcall SFileLoadFileEx(void* hMpq, const char* szFileName, void** ppBuffer, int* pnSize, int nExtraBytes, int nFlags, void* pOverlapped)
{
    return SFileLoadFileEx2(hMpq, szFileName, ppBuffer, (unsigned int*)pnSize, nExtraBytes, nFlags, pOverlapped, 0);
}

// 0x0041B050
int __stdcall SFileReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped)
{
    return SFileReadFileEx2(hFile, (unsigned char*)pBuffer, nToRead, (unsigned int*)pnRead, (D2StormOverlappedStrc*)pOverlapped, 0, 0);
}

// 0x0041B080
int __stdcall SFileReadFileEx(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg6)
{
    return SFileReadFileEx2(hFile, (unsigned char*)pBuffer, nToRead, (unsigned int*)pnRead, (D2StormOverlappedStrc*)pOverlapped, 0, (void*)nArg6);
}

static REQUEST* __stdcall IssueRequest(unsigned int nPosition, void* pDest, unsigned int nDestSize, D2StormSoundBufferStrc* pBuffer, unsigned int nBufferOffset, AUDIOSTREAM* pStream, unsigned int nBytes, unsigned int nDelay, int nArg9, int nUser, int nArg11, int bSignal, void* pCallback, FILEREC* pFile);

// 0x00419760
static void RemoveFileRef(FILEREC* pFile)
{
    if (pFile && !--pFile->nRefCount)
        delete pFile;
}

void __fastcall sub_M126_Emit_00419760(int a, FILEREC* pFile, int nUnused)
{
    RemoveFileRef(pFile);
}

// 0x00419A80
int __stdcall SFileCloseArchive(void* hArchive)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    ARCHIVEREC* pRec;
    if (!GetArchiveRec(hArchive, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    ARCHIVEREC* pHandle = (ARCHIVEREC*)hArchive;
    if (pHandle)
    {
        if (pHandle->hParentFile)
        {
            FILEREC* pFile;
            if (GetFileRec(pRec->hParentFile, &pFile))
                SFileCloseFile(pRec->hParentFile);
        }
        else if (pHandle->pParent)
        {
            ARCHIVEREC* pParent = pRec->pParent;
            if (pParent && !--pParent->nRefCount)
                delete pParent;
        }
    }
    gArchiveList_00708354.UnlinkNode(pRec);
    if (pRec && !--pRec->nRefCount)
        delete pRec;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x004198D0
int __stdcall SFileCloseFile(void* hFile)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (!GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    gFileList_0070836C.UnlinkNode(pRec);
    if (pRec && !--pRec->nRefCount)
        delete pRec;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x00419BD0
static inline void RemoveStreamRef(AUDIOSTREAM* stream)
{
    if (stream && --stream->nRefCount == 0)
        delete stream;
}

void __stdcall emit_release_00419BD0(AUDIOSTREAM* stream) { RemoveStreamRef(stream); }

// 0x0041BA60
int __stdcall SFileOpenArchive(const char* szMpqName, int nPriority, unsigned int dwFlags, void** phMpq)
{
    void* hFile;
    VALIDATEBEGIN;
    if (!phMpq)
        nValid = 0;
    else
        *phMpq = 0;
    VALIDATE(szMpqName);
    VALIDATE(*szMpqName);
    VALIDATEEND;

    EnterCriticalSection(&gBasePathLock_00779068);
    InitCryptTable();

    char szPath[0x104];
    SStrCopy(szPath, szMpqName, 0x104);
    szPath[0x103] = 0;
    if (!IsDiskFile(szPath))
    {
        if (*szMpqName != 0x5C && !strstr(szMpqName, ":\\") && !strstr(szMpqName, "\\\\"))
            BuildBasePath(0, szMpqName, szPath);
        else
            SStrCopy(szPath, szMpqName, 0x104);
    }

    const int nVolume = CheckCdVolume(szPath);
    if ((dwFlags & 1) && !nVolume)
    {
        sub_0041C340_SetLastError(0xF);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }

    hFile = CreateFileA(szPath, 0x80000000, 1, 0, 3, 0, 0);
    if (hFile == (void*)-1)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }

    ARCHIVEREC* pArchive = gArchiveList_00708354.NewNode(0, 0, 0);
    SStrCopy(pArchive->szName, szPath, 0x104);
    pArchive->hFile = hFile;
    pArchive->nMode = nVolume ? 3 : 0;
    pArchive->nPriority = nPriority;
    pArchive->bNested = 1;
    if (nVolume)
        pArchive->nMode = 3;
    else
        pArchive->nMode = ((unsigned char)dwFlags >> 1) & 1;
    pArchive->bNoDiskSearch = (dwFlags >> 2) & 1;
    pArchive->pHeader = (D2StormMpqHeaderStrc*)SMemAlloc(sizeof(D2StormMpqHeaderStrc), ".\\SOURCE\\SFILE.CPP", 0x1052, 0);
    pArchive->nArchiveOffset = 0;
    pArchive->nArchiveLimit = GetFileSize(hFile, 0);
    pArchive->nRefs = 0;
    const int nResult = s_OpenArchive(pArchive, dwFlags, nVolume, phMpq);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nResult;
}

static __forceinline int sub_004192F0_OpenDiskFile(const char* szFileName, unsigned int dwFlags, void** phFile, const char* szPath)
{
    void* hFile = CreateFileA(szPath, 0x80000000, 1, 0, 3, 0x8000000, 0);
    if (hFile != (void*)-1)
    {
        if (dwFlags & 4)
        {
            *phFile = hFile;
        }
        else
        {
            FILEREC* pFile = gFileList_0070836C.NewNode(1, 0, 0);
            SStrCopy(pFile->name, szFileName, 0x104);
            pFile->szLocalPath = SStrDup(szPath);
            pFile->hFile = hFile;
            pFile->nRefCount = 1;
            pFile->nCrcValue = 0;
            *phFile = pFile;
        }

        return 2;
    }

    return 0;
}

// 0x00419180
int __stdcall SFileOpenPathAsArchive(void* hArchive, const char* szPrefix, int nPriority, unsigned int nFlags, void** phArchive)
{
    VALIDATEBEGIN;
    if (!phArchive)
        nValid = 0;
    else
        *phArchive = 0;
    VALIDATE(szPrefix);
    VALIDATE(*szPrefix);
    VALIDATEEND;
    EnterCriticalSection(&gBasePathLock_00779068);
    InitCryptTable();
    ARCHIVEREC* pParent = (ARCHIVEREC*)hArchive;
    if (!pParent)
    {
        sub_0041C340_SetLastError(0x57);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    ARCHIVEREC* pArchive = gArchiveList_00708354.NewNode(0, 0, 0);
    SStrCopy(pArchive->szName, pParent->szName, 0x104);
    pArchive->hFile = pParent->hFile;
    pArchive->pParent = pParent;
    pArchive->nPriority = nPriority;
    pArchive->nRefs = 0;
    SStrCopy(pArchive->szPrefix, szPrefix, 0x7FFFFFFF);
    pArchive->nRefCount = 1;
    ++pParent->nRefCount;
    ARCHIVEREC* pExisting;
    for (pExisting = gArchiveList_00708354.Head(); pExisting; pExisting = pExisting->m_link.Next())
    {
        if (pExisting->nPriority <= pArchive->nPriority)
            break;
    }
    pArchive->m_link.Unlink();
    TSLink<ARCHIVEREC>* pExistingLink = &pExisting->m_link;
    if (!pExisting)
        pExistingLink = &gArchiveList_00708354.m_terminator;
    TSLink<ARCHIVEREC>* pPrevLink = pExistingLink->m_prevlink;
    pArchive->m_link.m_prevlink = pPrevLink;
    pArchive->m_link.m_next = pPrevLink->m_next;
    pPrevLink->m_next = pArchive;
    pExistingLink->m_prevlink = &pArchive->m_link;
    *phArchive = pArchive;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x004192F0
int __stdcall SFileOpenFileEx(void* hMpq, const char* szFileName, unsigned int dwFlags, void** phFile)
{
    VALIDATEBEGIN;
    if (!phFile)
        nValid = 0;
    else
        *phFile = 0;
    VALIDATE(szFileName);
    VALIDATE(*szFileName);
    VALIDATEEND;

    EnterCriticalSection(&gBasePathLock_00779068);
    InitCryptTable();

    D2StormBlockStrc* pBlock;
    ARCHIVEREC* pArchive;
    char szPath[0x104];
    int nResult = 0;
    const int nFound = GetFileBlockEntry(hMpq, szFileName, dwFlags, &pArchive, &pBlock, szPath);
    if (nFound)
    {
        if (nFound == 2)
        {
            nResult = sub_004192F0_OpenDiskFile(szFileName, dwFlags, phFile, szPath);
        }
        else if (dwFlags & 4)
        {
            void* hFile = CreateFileA(pArchive->szName, 0x80000000, 1, 0, 3, 0x8000000, 0);
            nResult = hFile != (void*)-1;
            *phFile = hFile;
            if (nResult)
                SetFilePointer(hFile, pBlock->nOffset, 0, 0);
            else
                sub_0041C340_SetLastError(2);
        }
        else
        {
            const char* szBaseName = szFileName;
            const char* szSeparator = SStrChrR(szBaseName, ':');
            if (szSeparator)
                szBaseName = szSeparator + 1;
            szSeparator = SStrChrR(szBaseName, '\\');
            if (szSeparator)
                szBaseName = szSeparator + 1;

            unsigned int nKey = HashString(3, szBaseName);
            D2StormBlockStrc* pFileBlock = pBlock;
            const unsigned int dwBlockFlags = pFileBlock->dwFlags;
            ARCHIVEREC* pFileArchive = pArchive;
            if (dwBlockFlags & 0x20000)
                nKey = (pFileBlock->nOffset - pFileArchive->nArchiveOffset + nKey) ^ pFileBlock->nFileSize;

            const unsigned int nBlocks = (pFileBlock->nFileSize + pFileArchive->sectorsize - 1) / pFileArchive->sectorsize;
            unsigned int* pBlockOffsets = 0;
            if (dwBlockFlags & 0xFF00)
                pBlockOffsets = (unsigned int*)SMemAlloc((nBlocks + 1) * sizeof(unsigned int), gszSFileSourceFile_006CF084, 0x1231, 0);

            FILEREC* pFile = gFileList_0070836C.NewNode(1, 0, 0);
            SStrCopy(pFile->name, szFileName, 0x104);
            pFile->hFile = (void*)-1;
            pFile->archive = pFileArchive;
            pFile->pBlock = pFileBlock;
            pFile->nKey = nKey;
            pFile->nBlocks = nBlocks;
            pFile->pBlockOffsets = pBlockOffsets;
            pFile->pBuffer = (unsigned char*)SMemAlloc(0x1000, gszSFileSourceFile_006CF084, 0x123C, 0);
            pFile->nRefCount = 1;
            pFile->nCrcValue = pFileBlock->nCrc ? gnFileCrc_007790B0 : 0;
            pFile->nCrcState = 1;
            ++pFileArchive->nOpenFiles;
            *phFile = pFile;
            nResult = 1;
        }
    }

    LeaveCriticalSection(&gBasePathLock_00779068);
    if (nResult && gpfnOpenFileCallback_00779060)
        gpfnOpenFileCallback_00779060(szFileName, gpOpenFileCallbackParam_00779064);

    return nResult;
}

// 0x0041BCA0
int __stdcall SFileOpenFileAsArchive(unsigned int hMpq, const char* szName, int nPriority, unsigned int nFlags, void** phArchive)
{
    void* hFile;
    if (!SFileOpenFileEx((void*)hMpq, szName, GetDefaultOpenFlags(), &hFile))
        return 0;
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pFile;
    GetFileRec(hFile, &pFile);
    if (pFile->hFile != INVALID_FILE_HANDLE)
    {
        SFileCloseFile(hFile);
        LeaveCriticalSection(&gBasePathLock_00779068);
        char szPath[0x104];
        FindDiskFile(GetDefaultOpenFlags(), szName, szPath);
        return SFileOpenArchive(szName, nPriority, nFlags, phArchive);
    }
    if (!(pFile->pBlock->dwFlags & 0x1FF00))
    {
        ARCHIVEREC* pArchive = gArchiveList_00708354.NewNode(0, 0, 0);
        SStrCopy(pArchive->szName, szName, 0x104);
        pArchive->hFile = pFile->archive->hFile;
        pArchive->nMode = pFile->archive->nMode;
        pArchive->bNoDiskSearch = (nFlags >> 2) & 1;
        pArchive->nPriority = nPriority;
        pArchive->nRefs = 0;
        pArchive->nOpenFiles = 1;
        pArchive->hNestedFile = hFile;
        pArchive->pHeader = (D2StormMpqHeaderStrc*)SMemAlloc(sizeof(D2StormMpqHeaderStrc), gszSFileSourceFile_006CF084, 0x11AD, 0);
        pArchive->nArchiveOffset = pFile->pBlock->nOffset;
        pArchive->nArchiveLimit = pFile->pBlock->nFileSize + pFile->pBlock->nOffset;
        s_OpenArchive(pArchive, nFlags, pArchive->nMode, phArchive);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 1;
    }
    SFileCloseFile(hFile);
    sub_0041C340_SetLastError(0x3EE);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 0;
}

// Link holders of the run whose types are not known yet: each constructor zeroes, each destructor unlinks.
struct sub_00417780
{
    D2StormLinkStrc tLink;
    sub_00417780();
};

struct sub_00417810
{
    D2StormLinkStrc tLink;
    ~sub_00417810();
};

struct sub_00417850
{
    D2StormLinkStrc tLink;
    sub_00417850();
};

struct sub_00417860
{
    D2StormLinkStrc tLink;
    ~sub_00417860();
};

struct sub_004178B0
{
    D2StormLinkStrc tLink;
    sub_004178B0();
};

struct sub_004178C0
{
    D2StormLinkStrc tLink;
    ~sub_004178C0();
};

struct sub_00417900
{
    D2StormLinkStrc tLink;
    ~sub_00417900();
};

struct sub_00417940
{
    D2StormLinkStrc tLink;
    sub_00417940();
};

struct sub_00417950
{
    D2StormLinkStrc tLink;
    ~sub_00417950();
};

struct sub_00417990
{
    D2StormLinkStrc tLink;
    sub_00417990();
};

struct sub_004179B0
{
    D2StormLinkStrc tLink;
    ~sub_004179B0();
};

struct sub_004183F0
{
    D2StormLinkStrc tLink;
    ~sub_004183F0();
};

struct sub_00418430
{
    D2StormLinkStrc tLink;
    ~sub_00418430();
};

struct sub_00418760
{
    D2StormLinkStrc tLink;
    sub_00418760();
};

struct sub_00418770
{
    D2StormLinkStrc tLink;
    sub_00418770();
};

struct sub_00418780
{
    D2StormLinkStrc tLink;
    ~sub_00418780();
};

struct sub_004187C0
{
    D2StormLinkStrc tLink;
    ~sub_004187C0();
};

struct sub_00418800
{
    D2StormLinkStrc tLink;
    ~sub_00418800();
};

struct sub_00418840
{
    D2StormLinkStrc tLink;
    ~sub_00418840();
};

struct sub_00418880
{
    D2StormLinkStrc tLink;
    ~sub_00418880();
};

struct sub_004188C0
{
    D2StormLinkStrc tLink;
    ~sub_004188C0();
};

struct sub_00418A40
{
    D2StormLinkStrc tLink;
    sub_00418A40();
};

struct sub_00418BA0
{
    D2StormLinkStrc tLink;
    ~sub_00418BA0();
};

struct sub_00418DE0
{
    D2StormLinkStrc tLink;
    sub_00418DE0();
};

struct sub_00418DF0
{
    D2StormLinkStrc tLink;
    sub_00418DF0();
};

struct sub_00418E00
{
    D2StormLinkStrc tLink;
    sub_00418E00();
};

struct sub_00418E10
{
    D2StormLinkStrc tLink;
    ~sub_00418E10();
};

struct sub_00418E50
{
    D2StormLinkStrc tLink;
    sub_00418E50();
};

struct sub_00418FF0
{
    D2StormLinkStrc tLink;
    sub_00418FF0();
};

struct sub_00419060
{
    D2StormLinkStrc tLink;
    sub_00419060();
};

// 0x00417780
sub_00417780::sub_00417780()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
}

// 0x00417810
sub_00417810::~sub_00417810()
{
    tLink.Unlink();
}

// 0x00417850
sub_00417850::sub_00417850()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
}

// 0x00417860
sub_00417860::~sub_00417860()
{
    tLink.Unlink();
}

// 0x004178B0
sub_004178B0::sub_004178B0()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
}

// 0x004178C0
sub_004178C0::~sub_004178C0()
{
    tLink.Unlink();
}

// 0x00417900
sub_00417900::~sub_00417900()
{
    tLink.Unlink();
}

// 0x00417940
sub_00417940::sub_00417940()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
}

// 0x00417950
sub_00417950::~sub_00417950()
{
    tLink.Unlink();
}

// 0x00417990
sub_00417990::sub_00417990()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
}

// 0x004179B0
sub_004179B0::~sub_004179B0()
{
    tLink.Unlink();
}

// 0x004183F0
sub_004183F0::~sub_004183F0()
{
    tLink.Unlink();
}

// 0x00418430
sub_00418430::~sub_00418430()
{
    tLink.Unlink();
}

// 0x00418760
sub_00418760::sub_00418760()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
}

// 0x00418770
sub_00418770::sub_00418770()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
}

// 0x00418780
sub_00418780::~sub_00418780()
{
    tLink.Unlink();
}

// 0x004187C0
sub_004187C0::~sub_004187C0()
{
    tLink.Unlink();
}

// 0x00418800
sub_00418800::~sub_00418800()
{
    tLink.Unlink();
}

// 0x00418840
sub_00418840::~sub_00418840()
{
    tLink.Unlink();
}

// 0x00418880
sub_00418880::~sub_00418880()
{
    tLink.Unlink();
}

// 0x004188C0
sub_004188C0::~sub_004188C0()
{
    tLink.Unlink();
}

// 0x00418A40
sub_00418A40::sub_00418A40()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
}

// 0x00418BA0
sub_00418BA0::~sub_00418BA0()
{
    tLink.Unlink();
}

// 0x00418DE0
sub_00418DE0::sub_00418DE0()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
}

// 0x00418DF0
sub_00418DF0::sub_00418DF0()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
}

// 0x00418E00
sub_00418E00::sub_00418E00()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
}

// 0x00418E10
sub_00418E10::~sub_00418E10()
{
    tLink.Unlink();
}

// 0x00418E50
sub_00418E50::sub_00418E50()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
}

// 0x00418FF0
sub_00418FF0::sub_00418FF0()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
}

// 0x00419060
sub_00419060::sub_00419060()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
}

#include "gen/data/Source/Storm/SOURCE/SFILE.inc"

// build: symbol ??__EgRequestList_00708360@@YAXXZ 0x006CA7D0
// build: symbol ??__FgRequestList_00708360@@YAXXZ 0x006CB120
TSList<REQUEST> gRequestList_00708360; // 0x00708360

// build: symbol ??__EgDdaList_00708384@@YAXXZ 0x006CA850
// build: symbol ??__FgDdaList_00708384@@YAXXZ 0x006CB240
TSList<AUDIOSTREAM> gDdaList_00708384; // 0x00708384

// build: symbol ??__EgEventList_00708378@@YAXXZ 0x006CA830
// build: symbol ??__FgEventList_00708378@@YAXXZ 0x006CB1E0
TSList<EVENTREC> gEventList_00708378; // 0x00708378

// build: symbol ??__EgFileList_0070836C@@YAXXZ 0x006CA810
// build: symbol ??__FgFileList_0070836C@@YAXXZ 0x006CB180
TSList<FILEREC> gFileList_0070836C; // 0x0070836C

// build: symbol ??__EgArchiveList_00708354@@YAXXZ 0x006CA7B0
// build: symbol ??__FgArchiveList_00708354@@YAXXZ 0x006CB0C0
TSList<ARCHIVEREC> gArchiveList_00708354; // 0x00708354
