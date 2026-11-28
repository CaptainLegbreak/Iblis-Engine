#pragma once
// The record the launcher's worker thread carries (D2Launch, D2Multi and D2MCPClient each pass it on whole).

struct D2LaunchThreadRecordStrc
{
    int nData[0x52]; // 0x00
};
