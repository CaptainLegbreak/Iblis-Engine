typedef unsigned int size_t;
typedef char* va_list;

extern "C" char* __cdecl strrchr(const char* szString, int nChar);                                          // 0x00682990
extern "C" wchar_t* __cdecl wcsrchr(const wchar_t* szString, wchar_t nChar);
extern "C" int __cdecl _vsnprintf(char* szDest, size_t nCount, const char* szFormat, va_list args);         // 0x00682F22
extern "C" unsigned long __readfsdword(unsigned long nOffset);
#pragma intrinsic(__readfsdword)

static inline wchar_t* wcsrchr(wchar_t* szString, wchar_t nChar)
{
    return wcsrchr((const wchar_t*)szString, nChar);
}

// 0x004041D0
static inline int ERRORMANAGER_VFormatText(char* szDest, size_t nSize, const char* szFormat, va_list args)
{
    const int nResult = _vsnprintf(szDest, nSize - 1, szFormat, args);
    szDest[nSize - 1] = 0;
    return nResult;
}

// 0x004046D0
void* __cdecl ERRORMANAGER_GetCurrentTeb()
{
    return (void*)__readfsdword(0x18);
}

// 0x004046E0
static inline const char* ERRORMANAGER_GetFileName(const char* szPath)
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
    return pSep ? pSep + 1 : szPath;
}

wchar_t* sub_M123_Emit_00404100(wchar_t* szString)
{
    return wcsrchr(szString, L'.');
}

int sub_M123_Emit_004041D0(char* szDest, const char* szFormat, ...)
{
    return ERRORMANAGER_VFormatText(szDest, 0x100, szFormat, (va_list)(&szFormat + 1));
}

const char* sub_M123_Emit_004046E0(const char* szPath)
{
    return ERRORMANAGER_GetFileName(szPath);
}
