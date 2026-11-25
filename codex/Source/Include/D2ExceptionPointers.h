#pragma once
// Fog: the exception information an unhandled-exception filter receives (EXCEPTION_POINTERS): the exception
// record and the thread context at the fault.

#include "D2Check.h"

struct D2ExceptionRecordStrc;
struct D2ThreadContextStrc;

struct D2ExceptionPointersStrc
{
    D2ExceptionRecordStrc* pExceptionRecord; // 0x00
    D2ThreadContextStrc* pContextRecord; // 0x04
};
