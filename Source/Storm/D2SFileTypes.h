#pragma once
// Storm SFILE: archive, file, block, stream and request records shared by the SFILE pieces.

#include "D2StormLink.h"
#include "stpl.h"
#include "D2Win32Base.h"

struct D2StormMpqHeaderStrc;
struct D2StormHashEntryStrc;
struct D2StormArchiveFileStrc;
struct D2StormRequestCallbackStrc;
namespace Storm { namespace SFile { struct ARCHIVEREC; } }
using Storm::SFile::ARCHIVEREC;
struct FILEREC;
struct AUDIOSTREAM;


// One block-table entry (0x2C bytes).
struct D2StormBlockStrc
{
    unsigned int nOffset;                       // 0x00
    unsigned int nPackedSize;                   // 0x04
    unsigned int nFileSize;                     // 0x08
    unsigned int dwFlags;                       // 0x0C
    D2FileTimeStrc tFileTime;                   // 0x10
    unsigned int nCrc;                          // 0x18
    unsigned int aMd5[4];                       // 0x1C

    void ExpandBlockEntries(unsigned int nCount);                                                    // 0x004156A0
};

namespace Storm
{
namespace SFile
{
// An open archive (0x25C bytes).
struct ARCHIVEREC : TSLinkedNode<ARCHIVEREC>
{
    union
    {
        char szFileName[0x108];                 // 0x008
        struct
        {
            char szName[0x104];                 // 0x008
            void* hFile;                        // 0x10C
        };
    };
    union
    {
        int nMode;                              // 0x110
        int nKind;
    };
    int bNoDiskSearch;                          // 0x114
    union
    {
        int nPriority;                          // 0x118
        int nInfo;
    };
    FILEREC* pCachedFile;                       // 0x11C
    unsigned int nCachedOffset;                 // 0x120
    unsigned int sectorsize;                    // 0x124
    unsigned char* pBlockBuffer;                // 0x128
    unsigned int nCachedSize;                   // 0x12C
    unsigned int nArchiveOffset;                // 0x130
    unsigned int nArchiveLimit;                 // 0x134
    D2StormMpqHeaderStrc* pHeader;              // 0x138
    D2StormBlockStrc* pBlockTable;              // 0x13C
    union
    {
        D2StormHashEntryStrc* pHashTable;       // 0x140
        void* pBuffer0x140;
    };
    unsigned int nFilePos;                      // 0x144
    union
    {
        int bNested;                            // 0x148
        int nRefCount;
        int nOpenFiles;
    };
    union
    {
        void* hNestedFile;                      // 0x14C
        void* hParentFile;
        int bNoClose;
    };
    union
    {
        ARCHIVEREC* pPatch;          // 0x150
        ARCHIVEREC* pParent;
        int bMapped;
    };
    char szPrefix[0x104];                       // 0x154
    int nRefs;                                  // 0x258

    ~ARCHIVEREC();                                                                                // 0x00418A50
    void ReadAdditionalAttributes(D2StormBlockStrc* pBlockTable, unsigned int nCount);                    // 0x0041B0B0
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};
}
}

// An open file (0x158 bytes).
struct FILEREC : TSLinkedNode<FILEREC>
{
    union
    {
        char szName[0x108];                     // 0x008
        struct
        {
            char name[260];                     // 0x008
            const char* fullName;               // 0x10C
        };
        struct
        {
            unsigned char unk_08[0x104];        // 0x008
            void* pBuffer0x10C;                 // 0x10C
        };
        struct
        {
            char szShortName[0x104];            // 0x008
            char* szLocalPath;                  // 0x10C
        };
    };
    union
    {
        void* hFile;                            // 0x110
        int nKind;
    };
    union
    {
        ARCHIVEREC* archive;        // 0x114
        int nValue;
    };
    union
    {
        D2StormBlockStrc* pBlock;               // 0x118
        D2StormArchiveFileStrc* pArchiveFile;
        unsigned int* pBlockWords;
    };
    unsigned int nKey;                          // 0x11C
    unsigned int nPosition;                     // 0x120
    int unk0x124;                               // 0x124
    unsigned int nBlocks;                       // 0x128
    union
    {
        unsigned int* pBlockOffsets;            // 0x12C
        void* pBuffer0x12C;
    };
    int bOffsetsLoaded;                         // 0x130
    union
    {
        unsigned char unk_134[0x4];             // 0x134
        int bDdaActive;
    };
    union
    {
        void* pBuffer0x138;                     // 0x138
        unsigned char* pBuffer;
    };
    unsigned int nCachePos;                     // 0x13C
    unsigned int nCacheSize;                    // 0x140
    union
    {
        int nRequests;                          // 0x144
        int nRefCount;
    };
    unsigned int nCrc;                          // 0x148
    union
    {
        int bCrc;                               // 0x14C
        unsigned int nCrcValue;
    };
    int nCrcState;                              // 0x150
    unsigned int nCrcPos;                       // 0x154

    FILEREC();                                                                                   // 0x00418E60
    ~FILEREC();                                                                                  // 0x00419070
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

// The DirectSound buffer interface the stream player writes through.
struct D2StormSoundBufferStrc
{
    virtual long __stdcall QueryInterface(const void* pIid, void** ppObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetCaps(void* pCaps) = 0;
    virtual long __stdcall GetCurrentPosition(unsigned long* pnPlay, unsigned long* pnWrite) = 0;
    virtual long __stdcall GetFormat(void* pFormat, unsigned long nSize, unsigned long* pnWritten) = 0;
    virtual long __stdcall GetVolume(long* pnVolume) = 0;
    virtual long __stdcall GetPan(long* pnPan) = 0;
    virtual long __stdcall GetFrequency(unsigned long* pnFrequency) = 0;
    virtual long __stdcall GetStatus(unsigned long* pnStatus) = 0;
    virtual long __stdcall Initialize(void* pDirectSound, const void* pDesc) = 0;
    virtual long __stdcall Lock(unsigned long nOffset, unsigned long nBytes, void** ppPtr1, unsigned long* pnBytes1, void** ppPtr2, unsigned long* pnBytes2, unsigned long nFlags) = 0;
    virtual long __stdcall Play(unsigned long nReserved, unsigned long nPriority, unsigned long nFlags) = 0;
    virtual long __stdcall SetCurrentPosition(unsigned long nPosition) = 0;
    virtual long __stdcall SetFormat(const void* pFormat) = 0;
    virtual long __stdcall SetVolume(long nVolume) = 0;
    virtual long __stdcall SetPan(long nPan) = 0;
    virtual long __stdcall SetFrequency(unsigned long nFrequency) = 0;
    virtual long __stdcall Stop() = 0;
    virtual long __stdcall Unlock(void* pPtr1, unsigned long nBytes1, void* pPtr2, unsigned long nBytes2) = 0;
};

// A streamed sound (0x50 bytes).
struct AUDIOSTREAM : TSLinkedNode<AUDIOSTREAM>
{
    FILEREC* pFile;                  // 0x08
    unsigned int nextwrite;                     // 0x0C
    int nBytesPerSec;                           // 0x10
    int bRestart;                               // 0x14
    int fillstatus;                                 // 0x18
    unsigned int nCounter;                      // 0x1C
    unsigned int waveheadersize;                        // 0x20
    unsigned int nSize;                         // 0x24
    unsigned int nOffset;                       // 0x28
    unsigned int nPlayed;                       // 0x2C
    unsigned int writecursor;                      // 0x30
    int nVolume;                                // 0x34
    int nPan;                                   // 0x38
    D2StormSoundBufferStrc* pBuffer;            // 0x3C
    unsigned int soundbuffersize;                   // 0x40
    int bBufferOwned;                           // 0x44
    unsigned char nFill;                        // 0x48
    char pad0x49[3];                            // 0x49
    union
    {
        int nRefs;                              // 0x4C
        int nRefCount;
    };

    ~AUDIOSTREAM();                                                                                   // 0x004199A0
    static void operator delete(void* pMemory);
};

// A pending read request (0x44 bytes).
struct REQUEST : TSLinkedNode<REQUEST>
{
    union
    {
        void* hEvent;                           // 0x08
        int nUser;
    };
    FILEREC* pFile;                  // 0x0C
    unsigned int location;                     // 0x10
    unsigned int nFileOffset;                   // 0x14
    unsigned int nDueTime;                      // 0x18
    int nArg9;                                  // 0x1C
    unsigned char* pDest;                       // 0x20
    unsigned int nDestSize;                     // 0x24
    D2StormSoundBufferStrc* pBuffer;            // 0x28
    unsigned int soundbufferoffset;                 // 0x2C
    AUDIOSTREAM* stream;                 // 0x30
    unsigned int nBytes;                        // 0x34
    int bDelete;                                // 0x38
    unsigned int nRead;                         // 0x3C
    D2StormRequestCallbackStrc* pCallback;      // 0x40

    ~REQUEST();                                                                                  // 0x0041A020
    static void operator delete(void* pMemory);
};

// A request-completion event.
struct EVENTREC : TSLinkedNode<EVENTREC>
{
    void* hEvent;
};

// The fixed-type node lists (one record for each list of the file).
struct D2StormFixedListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    D2StormLinkStrc* sub_0041C560_Link(char* pNode);
    void sub_0041C580_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode);
    char* sub_00417E30_Next(char* pNode);
    char* sub_0041C630_Next(char* pNode);
    void sub_00417E90_UnlinkNode(char* pNode);
    void sub_00418560_UnlinkNode(char* pNode);
    void sub_004185F0_UnlinkNode(char* pNode);
    void sub_00418660_UnlinkNode(char* pNode);
    void sub_00418710_UnlinkNode(char* pNode);
    void sub_0041C690_UnlinkNode(char* pNode);
    char* sub_004185D0_RawNext(char* pNode);
    char* sub_004186D0_RawNext(char* pNode);
    char* sub_004186F0_RawNext(char* pNode);
    char* sub_0041C700_RawNext(char* pNode);
    char* sub_0041C840_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
    char* sub_0041CA10_DeleteNode(char* pNode);
};

struct D2StormListBaseStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_00417B40_Initialize();                                                                          // 0x00417B40
    void sub_00417D40_Initialize();                                                                          // 0x00417D40
};

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }
};

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return m_terminator.Next();
    }
};

struct D2Storm4167B0Strc
{
    D2StormLinkStrc tLink;

    ~D2Storm4167B0Strc();
};

struct D2Storm4168F0Strc
{
    D2StormLinkStrc tLink;

    ~D2Storm4168F0Strc();
};

// The file's global lists.
