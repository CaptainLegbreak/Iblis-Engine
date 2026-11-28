#include "D2CMP.h"
#include "CELLIST.h"

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

// The cel list table's handle generator, a template instance this unit supplies. It calls InternalFind out
// of line and keeps the table in esi across the call, so it was compiled without InternalFind's body in view:
// it stays apart from CelCmp.cpp, which defines InternalFind.
template<>
CELLIST* TSHashTable<CELLIST, HASHKEY_NONE>::InternalFind(unsigned int hashval, const HASHKEY_NONE& key);   // 0x006030E0

// build: symbol ?GenerateHandle@?$TSExportTableSimple@UCELLIST@@PAUHCELLIST__@@$0A@@@QAEPAUHCELLIST__@@XZ 0x00603280
template<>
HCELLIST__* TSExportTableSimple<CELLIST, HCELLIST__*, 0>::GenerateHandle()
{
    for (;;)
    {
        ++m_sequence;
        if (!m_sequence)
        {
            m_wrapped = 1;
            continue;
        }
        if (!m_wrapped || !InternalFind(m_sequence, m_key))
            break;
    }
    return (HCELLIST__*)m_sequence;
}
