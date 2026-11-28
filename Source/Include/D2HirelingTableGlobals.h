#pragma once
// hireling.txt: records, record count, and two tables of 256 record indices.

struct D2HirelingTxt;

struct D2HirelingTableGlobals
{
    D2HirelingTxt* pHirelingTxt; // 0x00
    int nCount; // 0x04
    int indices[2][256]; // 0x08
};
