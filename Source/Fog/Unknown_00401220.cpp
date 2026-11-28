typedef unsigned int size_t;
struct _iobuf;

extern "C" char* __cdecl strrchr(const char* szString, int nChar);                                          // 0x00682990
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, wchar_t* wszDest, int nDest); // 0x006CC29C
extern "C" __declspec(dllimport) int __stdcall CopyFileW(const wchar_t* wszExistingFile, const wchar_t* wszNewFile, int bFailIfExists); // 0x006CC2CC

namespace crashy
{
class Report
{
public:
    Report();                                                               // 0x00401070
    virtual ~Report();                                                      // 0x004010D0
    bool AddFile(const char* szPath, bool bCopy);              // 0x00401220

    _iobuf* m_pFile;
    char m_szText08[0x400];
    char m_szText408[0x400];
    int m_nLineCount;
    char m_aszLines[16][0x400];
};
}

static inline size_t StrLCopy(char* szDest, const char* szSource, size_t nSize)
{
    const char* p = szSource;
    if (nSize)
    {
        size_t n = nSize - 1;
        if (n)
        {
            do
            {
                const char c = *p;
                *szDest = c;
                szDest++;
                p++;
                if (!c)
                {
                    break;
                }
            } while (--n);
        }
        if (!n)
        {
            *szDest = 0;
        }
        else
        {
            return p - szSource - 1;
        }
    }
    while (*p++)
    {
    }
    return p - szSource - 1;
}

static inline size_t StrLCopyStart(char* szDest, const char* szSource, size_t nSize)
{
    const char* p = szSource;
    if (nSize)
    {
        if (--nSize)
        {
            do
            {
                const char c = *p;
                *szDest = c;
                szDest++;
                p++;
                if (!c)
                {
                    break;
                }
            } while (--nSize);
        }
        if (!nSize)
        {
            *szDest = 0;
        }
        else
        {
            return p - szSource - 1;
        }
    }
    while (*p++)
    {
    }
    return p - szSource - 1;
}

static inline const char* StrLCopyEnd(char* szDest, const char* szSource)
{
    const char* p = szSource;
    size_t n = 0x3FF;
    do
    {
        const char c = *p;
        *szDest = c;
        szDest++;
        p++;
        if (!c)
        {
            break;
        }
    } while (--n);
    if (!n)
    {
        *szDest = 0;
    }
    else
    {
        return p;
    }
    while (*p++)
    {
    }
    return p;
}

static bool __stdcall ERRORMANAGER_CopyFileName(const char* szPath, char* szOut, size_t nSize); // 0x00404010
static bool __stdcall ERRORMANAGER_CopyFileUtf8(const char* szSource, const char* szDest); // 0x00404450

// 0x00401220
bool crashy::Report::AddFile(const char* szPath, bool bCopy)
{
    if (m_nLineCount >= 16)
    {
        return false;
    }
    char szCopy[0x400];
    const char* szSource;
    if (bCopy)
    {
        if (!m_szText408[0])
        {
            return false;
        }
        const char* pDir = m_szText408;
        const size_t nLength = StrLCopyEnd(szCopy, pDir) - pDir - 1;
        if (nLength >= 0x400)
        {
            return false;
        }
        char* pName = szCopy + nLength;
        *pName++ = '/';
        if (!ERRORMANAGER_CopyFileName(szPath, pName, szCopy + 0x400 - pName))
        {
            return false;
        }
        ERRORMANAGER_CopyFileUtf8(szPath, szCopy);
        szSource = szCopy;
    }
    else
    {
        if (strlen(szPath) >= 0x400)
        {
            return false;
        }
        szSource = szPath;
    }
    StrLCopyStart(m_aszLines[m_nLineCount], szSource, 0x400);
    m_nLineCount++;
    return true;
}

// 0x00404010
static bool __stdcall ERRORMANAGER_CopyFileName(const char* szPath, char* szOut, size_t nSize)
{
    const char* pSep = 0;
    const char* p = strrchr(szPath, '/');
    if (p > pSep)
    {
        pSep = p;
    }
    p = strrchr(szPath, '\\');
    if (p && p > pSep)
    {
        pSep = p;
    }
    p = strrchr(szPath, ':');
    if (p && p > pSep)
    {
        pSep = p;
    }
    if (pSep)
    {
        szPath = pSep + 1;
    }
    return StrLCopy(szOut, szPath, nSize) < nSize ? true : false;
}

// 0x00404450
static bool __stdcall ERRORMANAGER_CopyFileUtf8(const char* szSource, const char* szDest)
{
    wchar_t wszSource[0x104];
    wchar_t wszDest[0x104];
    if (!MultiByteToWideChar(0xFDE9, 0, szSource, -1, wszSource, 0x104))
    {
        return false;
    }
    if (!MultiByteToWideChar(0xFDE9, 0, szDest, -1, wszDest, 0x104))
    {
        return false;
    }
    return CopyFileW(wszSource, wszDest, 1) != 0;
}
