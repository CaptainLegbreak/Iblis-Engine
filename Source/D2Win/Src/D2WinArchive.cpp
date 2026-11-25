#include "D2Win.h"
#include "D2MultiTypes.h"

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

const char* __stdcall D2CMPGetGfxFileExtension(int bAllowCompressed);                                      // 0x005FE1F0

void __stdcall CelFileNormalize(D2CelFileStrc* pFile, D2CelFileStrc** ppOutFile, const char* szFile, int nLine, int nSpecVersion, int nUnused); // 0x00601340

int __stdcall CelFileFreeHardware(D2CelFileStrc* pCelFile);                                           // 0x00601A50

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

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

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* szText, const char* szCaption, unsigned int nType); // 0x006CC464

D2ArchiveHandleStrc* __fastcall sub_00517332_LoadMpqFile(const char* szFileName, void* hFile, void* pfShowMessage, int nPriority); // 0x00517332

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
    gpD2DataMPQ = sub_00517332_LoadMpqFile(gszD2DataMpq, 0, 0, 1000);
    gpD2SfxMPQ = sub_00517332_LoadMpqFile(gszD2SfxMpq, 0, 0, 1000);
    gpD2SpeechMPQ = sub_00517332_LoadMpqFile("d2speech.mpq", 0, 0, 1000);
    gpD2DeltaMPQ = sub_00517332_LoadMpqFile("d2delta.mpq", 0, 0, 1000);
    gpD2kfixupMPQ = sub_00517332_LoadMpqFile("d2kfixup.mpq", 0, 0, 1000);
    gpD2PatchMPQ = sub_00517332_LoadMpqFile(gszPatchD2Mpq, 0, 0, 5000);
    gpD2ExpMPQ = sub_00517332_LoadMpqFile(gszExpansionMpq, 0, 0, 3000);

// build: symbol ?FOG_IsExpansion@* 0x00408F20
// build: symbol ?FOG_UseDirect@* 0x00406D20
    return FOG_UseDirect() || gpD2DataMPQ && gpD2SfxMPQ && gpD2SpeechMPQ && (!FOG_IsExpansion() || gpD2ExpMPQ);
}

// 0x004FAC80
void* __stdcall D2Win_GetArchive()
{
    return 0;
}

extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName); // 0x006CC1B0

int __fastcall FOG_GetInstallPath(char* szPath, unsigned int nSize); // 0x00406BA0

unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

extern "C" const char gszD2CharMpq[]; // 0x006DC77C

// 0x004FAC90
int __cdecl D2Win_10185_CheckCharMpq()
{
    char szPath[0x104];
    FOG_GetInstallPath(szPath, sizeof(szPath));
    SStrPack(szPath, gszD2CharMpq, sizeof(szPath));
    if (GetFileAttributesA(szPath) != -1)
    {
        return 0;
    }

    SStrCopy(szPath, gszD2CharMpq, sizeof(szPath));
    if (GetFileAttributesA(szPath) != -1)
    {
        return 0;
    }

    return !FOG_UseDirect();
}

extern "C" const char gszD2XVideoMpq[]; // 0x006DC788
extern D2ArchiveHandleStrc* gpD2VideoMPQ; // 0x007D5614
void __fastcall ARCHIVE_UnloadMPQFile(D2ArchiveHandleStrc* pMPQHandle); // 0x005173AC
extern D2ArchiveHandleStrc* gpD2CharMPQ; // 0x007D5610
extern D2ArchiveHandleStrc* gpD2XTalkMPQ; // 0x007D5618
extern D2ArchiveHandleStrc* gpD2MusicMPQ; // 0x007D5628
extern D2ArchiveHandleStrc* gpD2XMusicMPQ; // 0x007D5604
typedef int (__cdecl* DiscCallback)();
void __cdecl ARCHIVE_UnloadExpansionArchives(); // 0x004FAD70
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
        gpD2XVideoMPQ = sub_00517332_LoadMpqFile(gszD2XVideoMpq, hFile, pfShowMessage, 1000);
        if (!gpD2XVideoMPQ)
        {
            return 0;
        }
    }
    else
    {
        gpD2VideoMPQ = sub_00517332_LoadMpqFile("d2video.mpq", hFile, pfShowMessage, 1000);
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
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (!(FOG_IsExpansion() && (!config || config->pfnAllowExpansion()))) {
        ghCharMpq=sub_00517332_LoadMpqFile("d2char.mpq",file,play,1000);
        ghMusicMpq=sub_00517332_LoadMpqFile("d2music.mpq",file,play,1000);
        ghXMusicMpq=0;
        ghXTalkMpq=0;
        bOk = ghCharMpq && ghMusicMpq;
    } else {
        ghCharMpq=sub_00517332_LoadMpqFile("d2char.mpq",0,play,1000);
        ghMusicMpq=sub_00517332_LoadMpqFile("d2music.mpq",0,play,1000);
        ghXMusicMpq=sub_00517332_LoadMpqFile("d2Xmusic.mpq",file,expansion,3000);
        ghXTalkMpq=sub_00517332_LoadMpqFile("d2Xtalk.mpq",file,expansion,3000);
        ghXVideoMpq=sub_00517332_LoadMpqFile("d2Xvideo.mpq",file,expansion,3000);
        bOk = ghCharMpq && ghMusicMpq && ghXMusicMpq && ghXTalkMpq && ghXVideoMpq;
    }
    if (!bOk) { ARCHIVE_UnloadExpansionArchives(); return 0; }
    return 1;
}

#include "gen/data/Source/D2Win/Src/D2WinArchive.inc"
