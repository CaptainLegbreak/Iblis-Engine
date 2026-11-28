#include "D2Win.h"
#include "D2MultiTypes.h"
#include "FogApi.h"
#include "StormApi.h"
#include "FogApi.h"
#include "D2GfxApi.h"
#include "D2CMPApi.h"
#include "D2HellApi.h"

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);


// 0x004FA9B0
D2CelFileStrc* __fastcall ARCHIVE_LoadCellFile(const char* szFile, int nType)
{
    char szPath[260];
    strcpy(szPath, szFile);
    strcat(szPath, D2CMPGetGfxFileExtension(nType));
    void* pFile = sub_00517079_LoadFile(0, szPath, 0, ".\\Src\\D2WinArchive.cpp", 0x41);
    D2CelFileStrc* pCellFile;
    CelFileNormalize((D2CelFileStrc*)pFile, &pCellFile, ".\\Src\\D2WinArchive.cpp", 0x42, -1, 0);
    return pCellFile;
}

// 0x004FAA40
D2CelFileStrc* __fastcall ARCHIVE_LoadCellFileWithFileSize(const char* szFile, unsigned int* pFileSize, int nType)
{
    char szPath[260];
    strcpy(szPath, szFile);
    strcat(szPath, D2CMPGetGfxFileExtension(nType));
    void* pFile = sub_00517079_LoadFile(0, szPath, pFileSize, ".\\Src\\D2WinArchive.cpp", 0x52);
    D2CelFileStrc* pCellFile;
    CelFileNormalize((D2CelFileStrc*)pFile, &pCellFile, ".\\Src\\D2WinArchive.cpp", 0x53, -1, 0);
    return pCellFile;
}

// 0x004FAAE0
void __fastcall ARCHIVE_FreeCellFile(D2CelFileStrc* pCellFile)
{
    CelFileFreeHardware(pCellFile);
    if (pCellFile)
    {
        FOG_Free(pCellFile, ".\\Src\\D2WinArchive.cpp", 0x5C, 0);
    }
}

extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* szText, const char* szCaption, unsigned int nType); // 0x006CC464

D2ArchiveHandleStrc* __fastcall ARCHIVE_LoadMPQFile(const char* szFileName, void* hFile, void* pfShowMessage, int nPriority); // 0x00517332

extern "C" const char gszExpansionMpq[]; // 0x006CD3A0

extern "C" const char gszPatchD2Mpq[]; // 0x006DC728

extern "C" const char gszD2SfxMpq[]; // 0x006DC764

extern "C" const char gszD2DataMpq[]; // 0x006DC770

D2ArchiveHandleStrc* gpD2SfxMPQ; // 0x007D5608

D2ArchiveHandleStrc* gpD2DeltaMPQ; // 0x007D560C

D2ArchiveHandleStrc* gpD2DataMPQ; // 0x007D561C

D2ArchiveHandleStrc* gpD2kfixupMPQ; // 0x007D5620

D2ArchiveHandleStrc* gpD2SpeechMPQ; // 0x007D5624

D2ArchiveHandleStrc* gpD2PatchMPQ; // 0x007D5630

D2ArchiveHandleStrc* gpD2ExpMPQ; // 0x007D5634

// 0x004FAB00
int __cdecl ARCHIVE_ShowInsertExpansionDiscMessage()
{
    return MessageBoxA((void*)WINDOW_GetWindow(), "Insert Expansion Disc", "Diablo II", 0x31) == 1;
}

// 0x004FAB30
int __cdecl ARCHIVE_ShowInsertPlayDiscMessage()
{
    return MessageBoxA((void*)WINDOW_GetWindow(), "Insert Play Disc", "Diablo II", 0x31) == 1;
}

// 0x004FAB60
int __cdecl ARCHIVE_ShowInsertCinematicsDisc()
{
    return MessageBoxA((void*)WINDOW_GetWindow(), "Insert Cinematics Disc", "Diablo II", 0x31) == 1;
}

// 0x004FAB90
int __cdecl ARCHIVE_LoadArchives()
{
    gpD2DataMPQ = ARCHIVE_LoadMPQFile("d2data.mpq", 0, 0, 1000);
    gpD2SfxMPQ = ARCHIVE_LoadMPQFile("d2sfx.mpq", 0, 0, 1000);
    gpD2SpeechMPQ = ARCHIVE_LoadMPQFile("d2speech.mpq", 0, 0, 1000);
    gpD2DeltaMPQ = ARCHIVE_LoadMPQFile("d2delta.mpq", 0, 0, 1000);
    gpD2kfixupMPQ = ARCHIVE_LoadMPQFile("d2kfixup.mpq", 0, 0, 1000);
    gpD2PatchMPQ = ARCHIVE_LoadMPQFile("patch_d2.mpq", 0, 0, 5000);
    gpD2ExpMPQ = ARCHIVE_LoadMPQFile(gszExpansionMpq, 0, 0, 3000);

    return FOG_UseDirect() || gpD2DataMPQ && gpD2SfxMPQ && gpD2SpeechMPQ && (!FOG_IsExpansion() || gpD2ExpMPQ);
}

// 0x004FAC80
void* __stdcall D2Win_GetArchive()
{
    return 0;
}

extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName); // 0x006CC1B0




extern "C" const char gszD2CharMpq[]; // 0x006DC77C

// 0x004FAC90
int __cdecl D2Win_10185_CheckCharMpq()
{
    char szPath[0x104];
    FOG_GetInstallPath(szPath, sizeof(szPath));
    SStrPack(szPath, "d2char.mpq", sizeof(szPath));
    if (GetFileAttributesA(szPath) != -1)
    {
        return 0;
    }

    SStrCopy(szPath, "d2char.mpq", sizeof(szPath));
    if (GetFileAttributesA(szPath) != -1)
    {
        return 0;
    }

    return !FOG_UseDirect();
}

extern "C" const char gszD2XVideoMpq[]; // 0x006DC788
extern D2ArchiveHandleStrc* gpD2VideoMPQ; // 0x007D5614
extern D2ArchiveHandleStrc* gpD2CharMPQ; // 0x007D5610
extern D2ArchiveHandleStrc* gpD2XTalkMPQ; // 0x007D5618
extern D2ArchiveHandleStrc* gpD2MusicMPQ; // 0x007D5628
extern D2ArchiveHandleStrc* gpD2XMusicMPQ; // 0x007D5604
typedef int (__cdecl* DiscCallback)();
extern void* ghXMusicMpq; // 0x007D5604
extern void* ghCharMpq; // 0x007D5610
extern void* ghMusicMpq; // 0x007D5628
extern void* ghXTalkMpq; // 0x007D5618
extern void* ghXVideoMpq; // 0x007D562C

// 0x004FAD10
int __fastcall ARCHIVE_LoadVideoArchives(void* pfShowMessage, void* hFile, int bExpansion)
{
    if (FOG_UseDirect())
    {
        pfShowMessage = 0;
    }

    if (bExpansion)
    {
        gpD2XVideoMPQ = ARCHIVE_LoadMPQFile("d2Xvideo.mpq", hFile, pfShowMessage, 1000);
        if (!gpD2XVideoMPQ)
        {
            return 0;
        }
    }
    else
    {
        gpD2VideoMPQ = ARCHIVE_LoadMPQFile("d2video.mpq", hFile, pfShowMessage, 1000);
        if (!gpD2VideoMPQ)
        {
            return 0;
        }
    }

    return 1;
}

// 0x004FAD70
void __cdecl ARCHIVE_UnloadExpansionArchives()
{
    if (gpD2MusicMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2MusicMPQ);
        gpD2MusicMPQ = 0;
    }

    if (gpD2CharMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2CharMPQ);
        gpD2CharMPQ = 0;
    }

    if (gpD2VideoMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2VideoMPQ);
        gpD2VideoMPQ = 0;
    }

    if (gpD2XMusicMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2XMusicMPQ);
        gpD2XMusicMPQ = 0;
    }

    if (gpD2XTalkMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2XTalkMPQ);
        gpD2XTalkMPQ = 0;
    }

    if (gpD2XVideoMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2XVideoMPQ);
        gpD2XVideoMPQ = 0;
    }
}

// 0x004FAE00
void __cdecl ARCHIVE_FreeArchives()
{
    if (gpD2DataMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2DataMPQ);
        gpD2DataMPQ = 0;
    }

    if (gpD2SpeechMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2SpeechMPQ);
        gpD2SpeechMPQ = 0;
    }

    if (gpD2SfxMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2SfxMPQ);
        gpD2SfxMPQ = 0;
    }

    if (gpD2DeltaMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2DeltaMPQ);
        gpD2DeltaMPQ = 0;
    }

    if (gpD2kfixupMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2kfixupMPQ);
        gpD2kfixupMPQ = 0;
    }

    if (gpD2ExpMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2ExpMPQ);
        gpD2ExpMPQ = 0;
    }

    if (gpD2XMusicMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2XMusicMPQ);
        gpD2XMusicMPQ = 0;
    }

    if (gpD2PatchMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2PatchMPQ);
        gpD2PatchMPQ = 0;
    }

    ARCHIVE_UnloadExpansionArchives();
}

// 0x004FAEC0
int __fastcall ARCHIVE_LoadExpansionArchives(DiscCallback play,DiscCallback expansion,void* file,D2ConfigStrc* config) {
    if (FOG_UseDirect()) { play=0; expansion=0; }
    ghXVideoMpq=0;
    int bOk;
    if (!(FOG_IsExpansion() && (!config || config->pfnAllowExpansion()))) {
        ghCharMpq=ARCHIVE_LoadMPQFile("d2char.mpq",file,play,1000);
        ghMusicMpq=ARCHIVE_LoadMPQFile("d2music.mpq",file,play,1000);
        ghXMusicMpq=0;
        ghXTalkMpq=0;
        bOk = ghCharMpq && ghMusicMpq;
    } else {
        ghCharMpq=ARCHIVE_LoadMPQFile("d2char.mpq",0,play,1000);
        ghMusicMpq=ARCHIVE_LoadMPQFile("d2music.mpq",0,play,1000);
        ghXMusicMpq=ARCHIVE_LoadMPQFile("d2Xmusic.mpq",file,expansion,3000);
        ghXTalkMpq=ARCHIVE_LoadMPQFile("d2Xtalk.mpq",file,expansion,3000);
        ghXVideoMpq=ARCHIVE_LoadMPQFile("d2Xvideo.mpq",file,expansion,3000);
        bOk = ghCharMpq && ghMusicMpq && ghXMusicMpq && ghXTalkMpq && ghXVideoMpq;
    }
    if (!bOk) { ARCHIVE_UnloadExpansionArchives(); return 0; }
    return 1;
}

extern "C" const char* gData_0072DDD8[15] = { // 0x0072DDD8
    "English",
    "Spanish",
    "German",
    "French",
    "Portuguese",
    "Italian",
    "Japanese",
    "Korean",
    "Simplified Chinese",
    "Traditional Chinese",
    "Polish",
    "Russian",
    "English with Korean Chat",
    "Unknown",
    "14"
};
