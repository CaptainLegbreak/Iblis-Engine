#include "Storm.h"

struct D2StormUIntArrayStrc;
struct D2StormUCharArrayStrc;
struct D2StormBigBufferStrc;
struct D2StormBigDataStrc;
extern "C" int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

struct D2StormUIntArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned int* m_data;
    unsigned int m_chunk;

    ~D2StormUIntArrayStrc()
    {
        if (m_data)
            SMemFree(m_data, gszTypeNameUInt_00708874, -2, 0);
    }
};

struct D2StormUCharArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned char* m_data;
    unsigned int m_chunk;

    ~D2StormUCharArrayStrc()
    {
        if (m_data)
            SMemFree(m_data, gszTypeNameUChar_00708880, -2, 0);
    }
};

struct D2StormBigBufferStrc
{
    D2StormUIntArrayStrc m_array;
    unsigned int m_offset;
};

struct D2StormBigDataStrc
{
    D2StormBigBufferStrc m_primary;
    D2StormBigBufferStrc m_stack[16];
    unsigned int m_used;
    D2StormUCharArrayStrc m_output;

    ~D2StormBigDataStrc();
};

// build: symbol ??1D2StormBigBufferStrc@@QAE@XZ 0x00421810
// 0x00421D80
D2StormBigDataStrc::~D2StormBigDataStrc()
{
}
