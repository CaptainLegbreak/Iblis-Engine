#include "Fog.h"
#include "FogApi.h"
#include "StormApi.h"
#include "StormApi2.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText_006CC837, sub_00408090(), line); exit(-1); }

struct D2PoolSystemStrc;
struct D2SNameNodeStrc;

struct D2TxtLinkEntryStrc;

struct D2TxtLinkStrc;

struct D2TxtLinkNodeStrc;

struct D2BinFileStrc;

extern "C" const char gszEmptyAssertText_006CC837; // 0x006CC837

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize);

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

struct D2TxtLinkEntryStrc { union { char code[4]; unsigned int nCode; }; int index; };

struct D2TxtLinkStrc
{
    int count;
    int unk_04;
    union
    {
        D2TxtLinkEntryStrc* entries;
        void* pTbl;
    };
    D2TxtLinkNodeStrc* pFirstNode;
};

extern D2TxtLinkNodeStrc* const gpszFallback; // 0x0074C3D8

D2TxtLinkNodeStrc* __fastcall EXCEL_FindLinkNode(D2TxtLinkNodeStrc* pNode, int nId); // 0x006BD330

struct D2TxtLinkNodeStrc
{
    char szText[0x20];
    int nLinkIndex;
    D2TxtLinkNodeStrc* pPrevious;
    D2TxtLinkNodeStrc* pNext;
};

extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);

void __fastcall sub_004113C0(char* szText, int nLength); // 0x004113C0

void __fastcall FOG_FreePool(D2PoolSystemStrc* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

static void EXCEL_InsertLinkNode(D2TxtLinkNodeStrc** ppNode, D2TxtLinkNodeStrc* pNew); // 0x006BD490

struct D2BinFileStrc
{
    char* pDataBuffer;
    char* pFirstRow;
    int nRecordCount;
    unsigned int nColumns;
};

#pragma intrinsic(memset)

#define SKIP_CELL() {while(*input) ++input; ++input;}

#define READ_CODE() {*(unsigned*)small=0;int c=0;while(*input){if(c>=4){while(*input)++input;break;}small[c++]=*input++;}++input;}

#define PAD_CODE(dst) {(dst)[3]=' ';if(!small[0]){(dst)[0]=' ';(dst)[1]=' ';(dst)[2]=' ';}else{(dst)[0]=small[0];if(!small[1]){(dst)[1]=' ';(dst)[2]=' ';}else{(dst)[1]=small[1];if(!small[2]){(dst)[2]=' ';}else{(dst)[2]=small[2];if(small[3])(dst)[3]=small[3];}}}}

#define PAD9(dst) {if(!small[0]){(dst)[0]=' ';(dst)[1]=' ';(dst)[2]=' ';(dst)[3]=' ';}else{(dst)[0]=small[0];if(!small[1]){(dst)[1]=' ';(dst)[2]=' ';(dst)[3]=' ';}else{(dst)[1]=small[1];if(!small[2]){(dst)[2]=' ';(dst)[3]=' ';}else{(dst)[2]=small[2];if(!small[3])(dst)[3]=' ';else (dst)[3]=small[3];}}}}

struct D2BinFieldStrc;

struct D2BinFieldStrc { const char* name; unsigned type; int length,offset; void* link; };

static int __stdcall EXCEL_MapColumns(unsigned short* pOut, D2BinFileStrc* pList, D2BinFieldStrc* pEntries); // 0x006BCE20

int __stdcall sub_006BD230_AddCode(void*,unsigned); // 0x006BD230

void* __fastcall FOG_ReallocPool(D2PoolSystemStrc* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0

int __stdcall FOG_10216_AddRecordToLinkingTable(D2TxtLinkStrc* pLinker, const char* szCode); // 0x006BD500

int __fastcall EXCEL_GetOrAddLinkIndex(D2TxtLinkStrc* pLinker, const char* szText); // 0x006BD5A0

extern "C" int __stdcall FOG_GetLinkIndexByCode(D2TxtLinkStrc* pLink, unsigned int nCode, int bLogError); // 0x006BD130

void __stdcall sub_00410B10(void*,int); // 0x00410B10

void __stdcall sub_00410B50(void*,int); // 0x00410B50

typedef int (__fastcall* KeyCallback)(const char*);

typedef void (__fastcall* FieldCallback)(const char*,void*,int,int,int,int);

static void EXCEL_MakeCode(const char* szText, char* szCode); // 0x006BCD50

extern "C" double __cdecl pow(double,double);

// 0x006BCD50
static void EXCEL_MakeCode(const char* szText, char* szCode)
{
    if (!szText[0])
    {
        szCode[0] = ' ';
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[0] = szText[0];
    if (!szText[1])
    {
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[1] = szText[1];
    if (!szText[2])
    {
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[2] = szText[2];
    if (!szText[3])
    {
        szCode[3] = ' ';
        return;
    }
    szCode[3] = szText[3];
}

// calling-convention shim (not game code)
unsigned int __stdcall sub_006BCD50_Shim(const char* szText)
{
    unsigned int dwCode;
    EXCEL_MakeCode(szText, (char*)&dwCode);
    return dwCode;
}

// 0x006BCDA0
extern "C" void __stdcall FOG_FreeBinFile(D2BinFileStrc* pBinFile)
{
    FOG_Free(pBinFile->pDataBuffer, ".\\Src\\Excel\\Excel.cpp", 154, 0);
    FOG_FreePool(0, pBinFile, ".\\Src\\Excel\\Excel.cpp", 155, 0);
}

// 0x006BCDE0
int __stdcall FOG_GetRecordCountFromBinFile(D2BinFileStrc* pBinFile)
{
    return pBinFile->nRecordCount;
}

// 0x006BCDF0
static unsigned int __stdcall EXCEL_HashName(const char* szName)
{
    return SStrHash(szName, 0, 0);
}

unsigned int __stdcall sub_E01_Emit_006BCDF0(const char* szName)
{
    return EXCEL_HashName(szName);
}

// 0x006BCE00
unsigned int __fastcall EXCEL_XorFoldBytes(int nUnused, unsigned int dwValue)
{
    return (dwValue ^ (dwValue >> 8) ^ (dwValue >> 16) ^ (dwValue >> 24)) & 0xFF;
}

// 0x006BCE20
static int __stdcall EXCEL_MapColumns(unsigned short* pOut, D2BinFileStrc* pList, D2BinFieldStrc* pEntries)
{
    D2SNameNodeStrc* aBuckets[256];
    D2SNameNodeStrc aNodes[0x118];
    unsigned int nNodes = 0;
    int nOut = 0;

    D2BinFieldStrc* pCheck = pEntries;
    if (pCheck->type)
    {
        do
        {
            if (pCheck->type == 5)
            {
                for (unsigned int i = 1; i < pCheck->length; ++i)
                {
                    ++pCheck;
                    S_ASSERT(pCheck->type == 5, 0xC4);
                }
            }
            ++pCheck;
        } while (pCheck->type);
    }

    SMemZero(aBuckets, sizeof(aBuckets));

    D2BinFieldStrc* pEntry = pEntries;
    if (pEntry->type)
    {
        D2SNameNodeStrc* pCursor = aNodes;
        do
        {
        S_ASSERT(nNodes < 0x118, 0xCC);
        ++nNodes;
        D2SNameNodeStrc* pNode = pCursor++;
        const char* szName = pEntry->name;
        unsigned int nHash = SStrHash(szName, 0, 0);
        unsigned int nBucket = ((((nHash >> 8) ^ nHash) >> 16) ^ (nHash >> 8) ^ nHash) & 0xFF;
        pNode->nHash = nHash;
        pNode->pEntry = pEntry;
        pNode->pNext = aBuckets[nBucket];
        aBuckets[nBucket] = pNode;
            ++pEntry;
        } while (pEntry->type);
    }

    const char* szString = pList->pDataBuffer;
    for (unsigned int i = 0; i < pList->nColumns; ++i)
    {
        unsigned int nHash = SStrHash(szString, 0, 0);
        unsigned int nBucket = ((((((nHash >> 8) ^ nHash) >> 8) ^ nHash) >> 8) ^ nHash) & 0xFF;
        for (D2SNameNodeStrc* pNode = aBuckets[nBucket]; pNode; pNode = pNode->pNext)
        {
            if (pNode->nHash == nHash && !SStrCmpI(szString, pNode->pEntry->name, 0x7FFFFFFF))
            {
                pNode->nHash = 0;
                pOut[nOut++] = (unsigned short)(pNode->pEntry - pEntries);
                goto next;
            }
        }
        pOut[nOut++] = 0x7FFF;
next:
        while (*szString)
        {
            ++szString;
        }
        ++szString;
    }

    for (unsigned int j = 0; j < nNodes; ++j)
    {
        if (aNodes[j].nHash)
        {
            pOut[nOut] = (unsigned short)(aNodes[j].pEntry - pEntries);
            ++nOut;
        }
    }

    return nOut;
}

// 0x006BD640
D2BinFileStrc* __stdcall FOG_CreateBinFile(char* pDataBuffer, int nBufferSize)
{
    char* pCur = pDataBuffer;
    char* pEnd = pCur + nBufferSize;
    D2BinFileStrc* pBinFile = (D2BinFileStrc*)FOG_AllocPool(0, sizeof(D2BinFileStrc), ".\\Src\\Excel\\Excel.cpp", 0x4D, 0);
    pBinFile->pDataBuffer = pCur;
    pBinFile->pFirstRow = 0;
    pBinFile->nRecordCount = 0;
    pBinFile->nColumns = 0;

    while (pCur < pEnd)
    {
        const char c = *pCur++;
        if (c == '\t')
        {
            pCur[-1] = 0;
            ++pBinFile->nColumns;
        }
        else if (c == '\r')
        {
            pCur[-1] = 0;
            D2_ASSERT(*pCur == '\n', 0x5C);
            ++pBinFile->nColumns;
            ++pCur;
            break;
        }
    }

    if (pCur >= pEnd)
    {
        FOG_Free(pBinFile->pDataBuffer, ".\\Src\\Excel\\Excel.cpp", 0x9A, 0);
        FOG_FreePool(0, pBinFile, ".\\Src\\Excel\\Excel.cpp", 0x9B, 0);
        return 0;
    }

    D2_ASSERT(pBinFile->nColumns <= 0x118, 0x67);
    pBinFile->pFirstRow = pCur;

    while (pCur < pEnd)
    {
        pDataBuffer = pCur;
        while (pCur < pEnd)
        {
            const char c = *pCur++;
            if (c == '\t')
            {
                pCur[-1] = 0;
            }
            else if (c == '\r')
            {
                pCur[-1] = 0;
                D2_ASSERT(*pCur == '\n', 0x75);
                ++pCur;
                ++pBinFile->nRecordCount;
                break;
            }
        }

        if (!SStrCmp(pDataBuffer, "Expansion", 10))
        {
            --pBinFile->nRecordCount;
            SMemCopy(pDataBuffer, pCur, pEnd - pCur);
            char* pNew = pDataBuffer;
            pEnd += pNew - pCur;
            pCur = pNew;
        }
    }

    return pBinFile;
}

// 0x006BD780
void __stdcall FOG_10207(D2BinFileStrc* bin,D2BinFieldStrc* fields,char* output,unsigned records,unsigned stride)
{
 unsigned short columns[280];
 char small[32];
 char code[4];
 D2_ASSERT(records>0,0x112);
 D2_ASSERT(stride>0,0x113);
 int total=EXCEL_MapColumns(columns,bin,fields);
 int firstPass=0;
 for(int c=0;c<(int)bin->nColumns;++c) if(columns[c]!=0x7fff) {
  switch(fields[columns[c]].type) {case 10:case 12:case 14:case 16:case 17:case 18:firstPass=1;break;}
 }
 char* originalOutput=output;
 char* input;
 int row,c;
 if(firstPass) {
  input=bin->pFirstRow;
  for(row=0;row<bin->nRecordCount;output+=stride,++row) {
   for(c=0;c<(int)bin->nColumns;++c) {
    if(columns[c]==0x7fff){SKIP_CELL();continue;}
    D2BinFieldStrc* field=&fields[columns[c]];
    char* dst=output+field->offset;
    switch(field->type) {
    case 10:case 12:case 14: {
     READ_CODE(); PAD_CODE(code);
     int index=sub_006BD230_AddCode(*(void**)field->link,*(unsigned*)code);
     switch(field->type) {
      case 10:*(unsigned*)dst=*(unsigned*)code;break;
      case 12:D2_ASSERT(index<=255,0x156);*dst=code[0];break;
      case 14:D2_ASSERT(index<=65535,0x15a);*(unsigned short*)dst=*(unsigned short*)code;break;
     }break;
    }
    case 16:{char* start=dst;char* end=dst+field->length-1;while(*input&&dst<end)*dst++=*input++;*dst=0;while(*input)++input;++input;FOG_10216_AddRecordToLinkingTable(*(D2TxtLinkStrc**)field->link,start);break;}
    case 17:case 18:{char name[32];char* p=name;while(*input&&p<name+31)*p++=*input++;*p=0;while(*input)++input;++input;D2TxtLinkStrc* const tArg4 = *(D2TxtLinkStrc**)field->link;
    int index=EXCEL_GetOrAddLinkIndex(tArg4,name);char* rec=output+field->offset;if(field->type==17)*(unsigned short*)rec=(unsigned short)index;else *(int*)rec=index;break;}
    default:SKIP_CELL();break;
    }
   }
   D2_ASSERT(*input=='\n',0x185);++input;
  }
 }
 output=originalOutput;input=bin->pFirstRow;
 for(row=0;row<bin->nRecordCount;output+=stride,++row){
  for(c=0;c<(int)bin->nColumns;++c){
   if(columns[c]==0x7fff){SKIP_CELL();continue;}
   char* start=input;
   D2BinFieldStrc* field=&fields[columns[c]];
   int offset=field->offset;
   char* dst=output+field->offset;
   int length=field->length;
   unsigned type=field->type;
   char* end=dst+length;
   switch(type){
   case 1:case 7:{while(*input){if(dst>=end){while(*input)++input;break;}*dst++=*input++;}++input;*dst=0;break;}
   case 9:{READ_CODE();PAD9(dst);break;}
   case 10:case 12:case 14:case 16:case 17:case 18:SKIP_CELL();break;
   case 11:case 13:case 15:{READ_CODE();PAD_CODE(code);int index=FOG_GetLinkIndexByCode(*(D2TxtLinkStrc**)field->link,*(unsigned*)code,1);switch(field->type){case 11:*(int*)dst=index;break;case 13:*dst=(char)index;break;case 15:*(unsigned short*)dst=(unsigned short)index;break;}break;}
   case 19:case 20:case 21:{char* p=small;while(*input&&p<small+31)*p++=*input++;*p=0;while(*input)++input;++input;int index=FOG_GetLinkIndex(*(D2TxtLinkStrc**)field->link,small,1);switch(field->type){case 19:*(int*)dst=index;break;case 20:*(unsigned short*)dst=(unsigned short)index;break;case 21:*dst=(char)index;break;}break;}
   case 2:case 3:case 4:case 5:case 6:case 8:case 26:{if(*input=='-')++input;int value=0;while(*input)value=value*10+*input++-'0';if(*start=='-')value=-value;++input;switch(type){case 2:case 8:*(int*)dst=value;break;case 3:*(unsigned short*)dst=(unsigned short)value;break;case 4:case 6:*dst=(char)value;break;case 5:if(start+1!=input)*dst=(char)value;break;case 26:if(value)sub_00410B10(dst,length);else sub_00410B50(dst,length);break;}break;}
   case 22:{char callbackText[256];char* p=callbackText;while(*input){if(p>=callbackText+256){while(*input)++input;break;}*p++=*input++;}++input;*p=0;if(field->link)*(unsigned short*)dst=(unsigned short)((KeyCallback)field->link)(callbackText);break;}
   case 23:case 24:case 25:{char callbackText[256];char* p=callbackText;while(*input){if(p>=callbackText+256){while(*input)++input;break;}*p++=*input++;}if(field->link)++input;else ++input;*p=0;if(field->link)((FieldCallback)field->link)(callbackText,output,offset,length,row,c);break;}
   // every field type is a listed case
   default:DEFAULT_UNREACHABLE;
   }
  }
  for(;c<total;++c){
   D2BinFieldStrc* field=&fields[columns[c]];char* dst=output+field->offset;
   switch(field->type){
   case 1:*dst=0;break;
   case 2:*(int*)dst=0;break;
   case 3:*(unsigned short*)dst=0;break;
   case 4:*dst=0;break;
   case 5:*dst=0;break;
   case 6:*dst=0;break;
   case 7:*dst=0;break;
   case 8:*(int*)dst=0;break;
   case 9:*(int*)dst=0;break;
   case 10:*(int*)dst=0;break;
   case 11:*(int*)dst=-1;break;
   case 12:*dst=0;break;
   case 13:*dst=-1;break;
   case 14:*(unsigned short*)dst=0;break;
   case 15:*(unsigned short*)dst=65535;break;
   case 16:*dst=0;break;
   case 17:*(unsigned short*)dst=0;break;
   case 18:*(int*)dst=0;break;
   case 19:*(unsigned int*)dst=0xFFFFFFFF;break;
   case 20:*(unsigned short*)dst=65535;break;
   case 21:*dst=-1;break;
   case 22:*(unsigned short*)dst=0;break;
   case 23:case 24:case 25:if(field->link)((FieldCallback)field->link)(0,output,field->offset,field->length,row,c);break;
   case 26:break;
   // every field type is a listed case
   default:DEFAULT_UNREACHABLE;
   }
  }
  D2_ASSERT(*input=='\n',0x286);++input;
 }
}

// 0x006BD130
extern "C" int __stdcall FOG_GetLinkIndexByCode(D2TxtLinkStrc* pLink, unsigned int nCode, int bLogError)
{
    int nUpper = pLink->count;
    int nLower = 0;
    D2TxtLinkEntryStrc* pEntries = pLink->entries;
    while (nLower < nUpper)
    {
        int nMiddle = nLower + (nUpper - nLower) / 2;
        unsigned int nCurrent = pEntries[nMiddle].nCode;
        if (nCode > nCurrent)
            nLower = nMiddle + 1;
        else if (nCode < nCurrent)
            nUpper = nMiddle;
        else
            return pEntries[nMiddle].index;
    }
    return -1;
}

// 0x006BD180
int __stdcall FOG_GetStringFromLinkIndex(D2TxtLinkStrc* linker, int index, char* text)
{
    D2TxtLinkEntryStrc* entries = linker->entries;
    if (!entries)
        return 0;
    if (index >= 0 && index < linker->count)
    {
        for (int i = 0; i < linker->count; ++i)
        {
            if (index == entries[i].index)
            {
                text[0] = entries[i].code[0] != ' ' ? entries[i].code[0] : 0;
                text[1] = entries[i].code[1] != ' ' ? entries[i].code[1] : 0;
                text[2] = entries[i].code[2] != ' ' ? entries[i].code[2] : 0;
                text[3] = entries[i].code[3] != ' ' ? entries[i].code[3] : 0;
                text[4] = 0;
                return 1;
            }
        }
    }
    return 0;
}

// 0x006BD230
int __stdcall sub_006BD230_AddCode(void* pLinker, unsigned nCode)
{
    D2TxtLinkStrc* pLink = (D2TxtLinkStrc*)pLinker;
    // The code is read and advanced in the argument area itself, addressed from the handle argument.
    unsigned int& nKey = *(unsigned int*)(&pLinker + 1);
    D2_ASSERT(pLink, 0x3D1);
    D2_ASSERT(!pLink->pFirstNode, 0x3D8);

    if (pLink->unk_04 <= pLink->count)
    {
        const int nNewCapacity = pLink->unk_04 + 64;
        pLink->entries = (D2TxtLinkEntryStrc*)FOG_ReallocPool(0, pLink->entries, nNewCapacity * sizeof(D2TxtLinkEntryStrc), ".\\Src\\Excel\\Excel.cpp", 0x3DF, 0);
        memset(&pLink->entries[pLink->unk_04], 0, 64 * sizeof(D2TxtLinkEntryStrc));
        pLink->unk_04 = nNewCapacity;
    }

    int nLow;
    for (;;)
    {
        D2TxtLinkEntryStrc* pEntries = pLink->entries;
        nLow = 0;
        int nHigh = pLink->count;
        while (nLow < nHigh)
        {
            int nMid = nLow + (nHigh - nLow) / 2;
            unsigned int nMidCode = pEntries[nMid].nCode;
            if (nKey > nMidCode)
                nLow = nMid + 1;
            else if (nKey < nMidCode)
                nHigh = nMid;
            else
                goto found;
        }
        break;
    found:
        ++nKey;
    }

    if (nLow < pLink->count)
        memmove(&pLink->entries[nLow + 1], &pLink->entries[nLow], (pLink->count - nLow) * sizeof(D2TxtLinkEntryStrc));

    pLink->entries[nLow].nCode = nKey;
    pLink->entries[nLow].index = pLink->count;
    const int nIndex = pLink->entries[nLow].index;
    ++pLink->count;
    return nIndex;
}

// 0x006BD330
D2TxtLinkNodeStrc* __fastcall EXCEL_FindLinkNode(D2TxtLinkNodeStrc* pNode, int nId)
{
    if (!pNode)
    {
        return gpszFallback;
    }
    if (pNode->nLinkIndex == nId)
    {
        return pNode;
    }
    D2TxtLinkNodeStrc* pFound;
    if (pNode->pPrevious)
    {
        pFound = EXCEL_FindLinkNode(pNode->pPrevious, nId);
        if (pFound != gpszFallback)
        {
            return pFound;
        }
    }
    if (pNode->pNext)
    {
        pFound = EXCEL_FindLinkNode(pNode->pNext, nId);
        if (pFound != gpszFallback)
        {
            return pFound;
        }
    }
    return gpszFallback;
}

// 0x006BD500
int __stdcall FOG_10216_AddRecordToLinkingTable(D2TxtLinkStrc* pLinker, const char* szCode)
{
    D2_ASSERT(pLinker, 0x4B2);
    D2_ASSERT(!pLinker->pTbl, 0x4B6);

    D2TxtLinkNodeStrc* pNode = (D2TxtLinkNodeStrc*)FOG_AllocPool(0, sizeof(D2TxtLinkNodeStrc), ".\\Src\\Excel\\Excel.cpp", 0x4B9, 0);
    memset(pNode, 0, sizeof(D2TxtLinkNodeStrc));
    SStrCopy(pNode->szText, szCode, 0x20);
    sub_004113C0(pNode->szText, 0x20);
    pNode->nLinkIndex = pLinker->count;
    EXCEL_InsertLinkNode(&pLinker->pFirstNode, pNode);
    return pLinker->count++;
}

// 0x006BD5A0
int __fastcall EXCEL_GetOrAddLinkIndex(D2TxtLinkStrc* pLinker, const char* szText)
{
    D2_ASSERT(pLinker, 0x4CC);
    D2_ASSERT(!pLinker->pTbl, 0x4D0);

    const int nRow = FOG_GetLinkIndex(pLinker, szText, 0);
    if (nRow >= 0)
    {
        return nRow;
    }

    D2TxtLinkNodeStrc* pNode = (D2TxtLinkNodeStrc*)FOG_AllocPool(0, sizeof(D2TxtLinkNodeStrc), ".\\Src\\Excel\\Excel.cpp", 0x4D9, 0);
    memset(pNode, 0, sizeof(D2TxtLinkNodeStrc));
    SStrCopy(pNode->szText, szText, sizeof(pNode->szText));
    sub_004113C0(pNode->szText, sizeof(pNode->szText));
    pNode->nLinkIndex = pLinker->count;
    EXCEL_InsertLinkNode(&pLinker->pFirstNode, pNode);
    return pLinker->count++;
}

// 0x006BD380
const char* __stdcall FOG_10255(D2TxtLinkStrc* pLink, int nIndex, int bUseFallback)
{
    if (!pLink || nIndex < 0 || nIndex >= pLink->count)
        return gpszFallback->szText;
    D2TxtLinkNodeStrc* pNode = EXCEL_FindLinkNode(pLink->pFirstNode, nIndex);
    if ((!pNode || pNode == gpszFallback) && bUseFallback)
        return gpszFallback->szText;
    return pNode->szText;
}

// 0x006BD3C0
int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLink, const char* szText, int bLogError)
{
    char szKey[0x20];
    SStrCopy(szKey, szText, sizeof(szKey));
    sub_004113C0(szKey, sizeof(szKey));

    D2TxtLinkNodeStrc* pNode = pLink->pFirstNode;
    if (pLink->count && !pNode)
    {
        FOG_DisplayHalt(&gszEmptyAssertText_006CC837, sub_00408090(), 0x475);
        exit(-1);
    }

    while (pNode)
    {
        const int nCompare = strcmp(szKey, pNode->szText);
        if (!nCompare)
        {
            return pNode->nLinkIndex;
        }

        if (nCompare < 0)
        {
            pNode = pNode->pPrevious;
        }
        else
        {
            pNode = pNode->pNext;
        }
    }

    return -1;
}

// 0x006BD490
static void __cdecl EXCEL_InsertLinkNode(D2TxtLinkNodeStrc** ppLink, D2TxtLinkNodeStrc* pNode)
{
    while (*ppLink)
    {
        D2TxtLinkNodeStrc* pCurrent = *ppLink;
        const int nCompare = strcmp(pNode->szText, pCurrent->szText);
        if (nCompare < 0)
        {
            ppLink = &pCurrent->pPrevious;
        }
        else if (nCompare > 0)
        {
            ppLink = &pCurrent->pNext;
        }
        else
        {
            FOG_FreePool(0, pNode, ".\\Src\\Excel\\Excel.cpp", 1191, 0);
            return;
        }
    }

    *ppLink = pNode;
}

// 0x006BD040
D2TxtLinkStrc* __stdcall FOG_AllocLinker(const char* szFile, int nLine)
{
    D2TxtLinkStrc* pLink = (D2TxtLinkStrc*)FOG_AllocPool(0, sizeof(D2TxtLinkStrc), szFile, nLine, 0);
    memset(pLink, 0, sizeof(D2TxtLinkStrc));
    return pLink;
}

// 0x006BE190
void __fastcall EXCEL_BuildGammaTable(int gamma,void* table,double scale,int entrySize,int entries,int mask)
{
 D2_ASSERT(entrySize==1 || entrySize==2 || entrySize==4,14);
 D2_ASSERT(gamma>=0,15);
 D2_ASSERT(scale>=0.0 && scale<=100.0,16);
 unsigned char* bytes=(unsigned char*)table;
 unsigned short* words=(unsigned short*)table;
 unsigned int* dwords=(unsigned int*)table;
 double remainder=100.0-scale;
 double factor=gamma/100.0;
 double power=100.0/gamma;
 double last=entries-1.0;
 double maximum=mask;
 for(double i=0.0;i<=last;i+=1.0) {
  double linear=(i*factor*maximum/last<maximum)?i*factor*maximum/last:maximum;
  int value=(int)((pow(i/last,power)*maximum*remainder+linear*scale)/100.0);
  switch(entrySize) {
   case 1: *bytes++=(unsigned char)value; break;
   case 2: *words++=(unsigned short)value; break;
   case 4: *dwords++=value; break;
  }
 }
}

// 0x006BE2F0
void __cdecl sub_006BE2F0_Nop(const char* szTag, const char* szFormat, ...)
{
}

// 0x006BE300
void __cdecl sub_006BE300_Nop(const char* szTag, const char* szFormat, ...)
{
}

// 0x006BD070
void __fastcall EXCEL_FreeLinkTree(D2TxtLinkNodeStrc* pNode)
{
    if (pNode->pPrevious)
        EXCEL_FreeLinkTree(pNode->pPrevious);
    if (pNode->pNext)
        EXCEL_FreeLinkTree(pNode->pNext);
    FOG_FreeServerMemory(0, pNode, ".\\Src\\Excel\\Excel.cpp", 0x346, 0);
}

// 0x006BD0B0
extern "C" void __stdcall FOG_FreeLinker(D2TxtLinkStrc* pLinker)
{
    if (pLinker)
    {
        D2TxtLinkNodeStrc* pRoot = pLinker->pFirstNode;
        if (pRoot)
        {
            if (pRoot->pPrevious)
                EXCEL_FreeLinkTree(pRoot->pPrevious);
            if (pRoot->pNext)
                EXCEL_FreeLinkTree(pRoot->pNext);
            FOG_FreePool(0, pRoot, ".\\Src\\Excel\\Excel.cpp", 0x346, 0);
        }
        if (pLinker->entries)
            FOG_FreePool(0, pLinker->entries, ".\\Src\\Excel\\Excel.cpp", 0x35D, 0);
        FOG_FreePool(0, pLinker, ".\\Src\\Excel\\Excel.cpp", 0x360, 0);
    }
}

extern "C" D2TxtLinkNodeStrc* const gData_0074C3D8 = (D2TxtLinkNodeStrc* const)"?\?\?"; // 0x0074C3D8
#pragma comment(linker, "/alternatename:?gpszFallback@@3QAUD2TxtLinkNodeStrc@@A=_gData_0074C3D8")
