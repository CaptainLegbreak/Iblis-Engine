#include "Fog.h"

extern "C" int __cdecl isalpha(int); // 0x00686DA5
extern "C" int __cdecl isdigit(int); // 0x00686F0F
extern "C" int __cdecl isspace(int); // 0x00687006
extern "C" int __cdecl isalnum(int); // 0x006870FB

union FOGASTNodeStrc;
struct D2CalcCallbackInfoStrc;
struct FOGExpressionParserContextStrc;

enum FOGCalcExpressionParserTokenValues
{
	TOKEN_PAREN_OPEN = 0,
	TOKEN_PAREN_CLOSE = 1,
	TOKEN_COMMA = 2,
	TOKEN_PLUS = 3,
	TOKEN_MINUS = 4,
	TOKEN_ASTERISK = 5,
	TOKEN_SLASH = 6,
	TOKEN_QUESTION_MARK = 7,
	TOKEN_COLON = 8,
	TOKEN_CIRCUM = 9,
	TOKEN_LESS_OR_EQ = 10,
	TOKEN_LESS = 11,
	TOKEN_GREATER_OR_EQ = 12,
	TOKEN_GREATER = 13,
	TOKEN_LOGIC_EQUALS = 14,
	TOKEN_LOGIC_DIFFERENT = 15,
	TOKEN_CUSTOM_RAW_CONSTANT = 16,
	TOKEN_CUSTOM_FUNCTION_PARAMETER_CONSTANT = 17,
	TOKEN_CUSTOM_FUNCTION_TABLE = 18,
};

enum FOGASTValues
{
	AST_None = 0,
	AST_CallbackTable = 1,
	AST_Parenthesis_Open = 2,
	AST_Callback_Param_Separator = 3,
	AST_Callback_Param_UInt8 = 4,
	AST_Callback_Param_UInt16 = 5,
	AST_Callback_Param_UInt32 = 6,
	AST_Raw_Int8 = 7,
	AST_Raw_Int16 = 8,
	AST_Raw_Int32 = 9,
	AST_LessThan = 10,
	AST_GreaterThan = 11,
	AST_LessOrEqualThan = 12,
	AST_GreaterOrEqualThan = 13,
	AST_Equal = 14,
	AST_NotEqual = 15,
	AST_Addition = 16,
	AST_Substraction = 17,
	AST_Multipliction = 18,
	AST_Division = 19,
	AST_Power = 20,
	AST_Negate = 21,
	AST_Ternary = 22,
	AST_Ternary_Colon = 23,
	AST_COUNT = 24,
};

union FOGASTNodeStrc
{
	FOGASTType nType;
	unsigned char nRawValue;
};

struct FOGExpressionParserContextStrc
{
	FOGASTType tPendingOperationsASTs[64];
	int tLinkerIndex[64];
	int nPendingOps;
	int nPendingParameters;
};

static const char* __stdcall DATATABLS_ParseExpressionToken(FOGExpressionParserContextStrc* pCalc, const char* szExpression, FOGCalcExpressionParserTokenType* pOutTokenType, int* pTokenAssociatedValue, CalcGetKeyWordToNumber_t pfnFunctionNameToId, CalcGetLinkerIndex_t pfnLinkParse);
int __stdcall DATATBLS_CalcEvaluateExpression(const FOGASTNodeStrc*, int, CalcFogCallBack2_t, D2CalcCallbackInfoStrc*, int, void*); // 0x006C0BC0
static FOGASTNodeStrc* __stdcall DATATBLS_Evaluate_HandleNewOp(FOGASTNodeStrc* pASTBufferPos, FOGASTNodeStrc* pASTBufferStart, int nASTBufferSize, FOGExpressionParserContextStrc* pContext, unsigned char nNewASTType, CalcGetFunctionParameterCount_t pfnGetFunctionParametersCount, int nTokenAssociatedValue); // 0x006C18A0


struct D2CalcStackStrc
{
    int nValues[64];
    int nCount;
};

// 0x006C0B80
static void DATATBLS_CalcPush(D2CalcStackStrc* pStack, int nValue)
{
    if (pStack->nCount < 64)
    {
        pStack->nValues[pStack->nCount] = nValue;
        ++pStack->nCount;
    }
}

// 0x006C0BA0
static int __fastcall DATATBLS_CalcPop(D2CalcStackStrc* pStack)
{
    if (pStack->nCount <= 0)
    {
        return 0;
    }
    return pStack->nValues[--pStack->nCount];
}

// 0x006C0BC0
int __stdcall DATATBLS_CalcEvaluateExpression(const FOGASTNodeStrc* start, int length, CalcFogCallBack2_t param, D2CalcCallbackInfoStrc* table, int tableSize, void* userData)
{
    if (length <= 0) return 0;
    const FOGASTNodeStrc* p = start;
    D2CalcStackStrc stack;
    stack.nCount = 0;
    if (p - start >= length) goto Done;
    do
    {
        unsigned char op = (p++)->nType;
        switch (op)
        {
        case 4:
            if (!param) goto Done;
            if (p - start >= length) goto Done;
            DATATBLS_CalcPush(&stack, param(*(unsigned char*)p, userData));
            p += 1;
            break;
        case 5:
            if (!param) goto Done;
            if (p - start >= length) goto Done;
            DATATBLS_CalcPush(&stack, param(*(short*)p, userData));
            p += 2;
            break;
        case 6:
            if (!param) goto Done;
            if (p - start >= length) goto Done;
            DATATBLS_CalcPush(&stack, param(*(int*)p, userData));
            p += 4;
            break;
        case 7:
            if (p - start >= length) goto Done;
            DATATBLS_CalcPush(&stack, *(signed char*)p);
            p += 1;
            break;
        case 8:
            if (p - start >= length) goto Done;
            DATATBLS_CalcPush(&stack, *(short*)p);
            p += 2;
            break;
        case 9:
            if (p - start >= length) goto Done;
            DATATBLS_CalcPush(&stack, *(int*)p);
            p += 4;
            break;
        case 1:
        {
            int index = (p++)->nRawValue;
            if (index >= tableSize) { DATATBLS_CalcPush(&stack, 0); break; }
            int count = table[index].nParameters;
            if (count == 3)
            {
                int c = DATATBLS_CalcPop(&stack);
                int b = DATATBLS_CalcPop(&stack);
                int a = DATATBLS_CalcPop(&stack);
                DATATBLS_CalcPush(&stack, table[index].fpCallBack(a, b, c, userData));
            }
            else if (count == 2) goto Two;
            else if (count == 1)
            {
                int a = DATATBLS_CalcPop(&stack);
                DATATBLS_CalcPush(&stack, table[index].fpCallBack(a, 0, 0, userData));
            }
            else if (count == 0)
                DATATBLS_CalcPush(&stack, table[index].fpCallBack(0, 0, 0, userData));
            else DATATBLS_CalcPush(&stack, 0);
            break;
        Two:
            {
                int b = DATATBLS_CalcPop(&stack);
                int a = DATATBLS_CalcPop(&stack);
                DATATBLS_CalcPush(&stack, table[index].fpCallBack(a, b, 0, userData));
            }
            break;
        }
        case 16:
        {
            int b = DATATBLS_CalcPop(&stack);
            int a = DATATBLS_CalcPop(&stack);
            DATATBLS_CalcPush(&stack, a + b);
            break;
        }
        case 17:
        {
            int b = DATATBLS_CalcPop(&stack);
            int a = DATATBLS_CalcPop(&stack);
            DATATBLS_CalcPush(&stack, a - b);
            break;
        }
        case 18:
        {
            int b = DATATBLS_CalcPop(&stack);
            int a = DATATBLS_CalcPop(&stack);
            DATATBLS_CalcPush(&stack, a * b);
            break;
        }
        case 19:
        {
            int b = DATATBLS_CalcPop(&stack);
            int a = DATATBLS_CalcPop(&stack);
            if (b) DATATBLS_CalcPush(&stack, a / b);
            else DATATBLS_CalcPush(&stack, 0);
            break;
        }
        case 21:
            DATATBLS_CalcPush(&stack, -DATATBLS_CalcPop(&stack));
            break;
        case 22:
        {
            int ifFalse = DATATBLS_CalcPop(&stack);
            int ifTrue = DATATBLS_CalcPop(&stack);
            int condition = DATATBLS_CalcPop(&stack);
            DATATBLS_CalcPush(&stack, condition ? ifTrue : ifFalse);
            break;
        }
        case 20:
        {
            int exponent = DATATBLS_CalcPop(&stack);
            int base = DATATBLS_CalcPop(&stack);
            int result = base;
            if (exponent > 0)
            {
                for (int i = 1; i < exponent; ++i) result *= base;
            }
            else result = 1;
            DATATBLS_CalcPush(&stack, result);
            break;
        }
        case 10:
        {
            int b = DATATBLS_CalcPop(&stack);
            int a = DATATBLS_CalcPop(&stack);
            DATATBLS_CalcPush(&stack, a < b);
            break;
        }
        case 12:
        {
            int b = DATATBLS_CalcPop(&stack);
            int a = DATATBLS_CalcPop(&stack);
            DATATBLS_CalcPush(&stack, a <= b);
            break;
        }
        case 11:
        {
            int b = DATATBLS_CalcPop(&stack);
            int a = DATATBLS_CalcPop(&stack);
            DATATBLS_CalcPush(&stack, a > b);
            break;
        }
        case 13:
        {
            int b = DATATBLS_CalcPop(&stack);
            int a = DATATBLS_CalcPop(&stack);
            DATATBLS_CalcPush(&stack, a >= b);
            break;
        }
        case 14:
        {
            int b = DATATBLS_CalcPop(&stack);
            int a = DATATBLS_CalcPop(&stack);
            DATATBLS_CalcPush(&stack, a == b);
            break;
        }
        case 15:
        {
            int b = DATATBLS_CalcPop(&stack);
            int a = DATATBLS_CalcPop(&stack);
            DATATBLS_CalcPush(&stack, a != b);
            break;
        }
        default:
            if (stack.nCount) return DATATBLS_CalcPop(&stack);
            return 0;
        }
    } while (p - start < length);
Done:
    return 0;
}

// 0x006C11C0
static const char* __stdcall DATATABLS_ParseExpressionToken(FOGExpressionParserContextStrc* pCalc, const char* szExpression, FOGCalcExpressionParserTokenType* pOutTokenType, int* pTokenAssociatedValue, CalcGetKeyWordToNumber_t pfnFunctionNameToId, CalcGetLinkerIndex_t pfnLinkParse)
{
    *pTokenAssociatedValue = 0;
    while (*szExpression && (isspace(*szExpression) || *szExpression == '"')) ++szExpression;
    if (isdigit(*szExpression))
    {
        *pOutTokenType = 16;
        *pTokenAssociatedValue = *szExpression - '0';
        while (isdigit(*++szExpression)) *pTokenAssociatedValue = *pTokenAssociatedValue * 10 + *szExpression - '0';
        return szExpression;
    }
    if (*szExpression == '\'')
    {
        ++szExpression;
        char tLinkNameBuffer[256];
        int nLinkNameSize = 0;
        tLinkNameBuffer[nLinkNameSize++] = *szExpression;
        szExpression += nLinkNameSize;
        while (*szExpression && *szExpression != '\'')
        {
            if (nLinkNameSize < 255) tLinkNameBuffer[nLinkNameSize++] = *szExpression;
            ++szExpression;
        }
        if (*szExpression) ++szExpression;
        tLinkNameBuffer[nLinkNameSize] = 0;
        BOOL bHasResolvedToConstant = 0;
        const int nAST = pCalc->tPendingOperationsASTs[pCalc->nPendingOps-1];
        const int nKeywordNumber = pCalc->tLinkerIndex[pCalc->nPendingOps-1];
        int nLinkerIndex = pfnLinkParse(tLinkNameBuffer, &bHasResolvedToConstant, nAST, nKeywordNumber);
        if (nLinkerIndex >= 0)
        {
            *pOutTokenType = bHasResolvedToConstant ? 16 : 17;
            *pTokenAssociatedValue = nLinkerIndex;
        }
        else { *pOutTokenType = 16; *pTokenAssociatedValue = 0; }
        return szExpression;
    }
    if (isalpha(*szExpression))
    {
        char tSubExpressionBuffer[256];
        int nSubExpressionSize = 0;
        tSubExpressionBuffer[nSubExpressionSize++] = *szExpression;
        szExpression += nSubExpressionSize;
        while (isalnum(*szExpression))
        {
            if (nSubExpressionSize < 255) tSubExpressionBuffer[nSubExpressionSize++] = *szExpression;
            ++szExpression;
        }
        tSubExpressionBuffer[nSubExpressionSize] = 0;
        while (*szExpression && isspace(*szExpression)) ++szExpression;
        if (*szExpression && *szExpression == '(')
        {
            int nFunctionId = pfnFunctionNameToId(tSubExpressionBuffer);
            if (nFunctionId >= 0) { *pOutTokenType = 18; *pTokenAssociatedValue = nFunctionId; return szExpression+1; }
        }
        BOOL bHasResolvedToConstant = 0;
        const int nAST = pCalc->tPendingOperationsASTs[pCalc->nPendingOps-1];
        const int nKeywordNumber = pCalc->tLinkerIndex[pCalc->nPendingOps-1];
        int nLinkerIndex = pfnLinkParse(tSubExpressionBuffer, &bHasResolvedToConstant, nAST, nKeywordNumber);
        if (nLinkerIndex >= 0) { *pOutTokenType = bHasResolvedToConstant ? 16 : 17; *pTokenAssociatedValue = nLinkerIndex; }
        else { *pOutTokenType = 16; *pTokenAssociatedValue = 0; }
        return szExpression;
    }
    switch (*szExpression)
    {
    case '(': *pOutTokenType = 0; return szExpression+1;
    case ')': *pOutTokenType = 1; return szExpression+1;
    case '+': *pOutTokenType = 3; return szExpression+1;
    case '-': *pOutTokenType = 4; return szExpression+1;
    case '*': *pOutTokenType = 5; return szExpression+1;
    case '/': *pOutTokenType = 6; return szExpression+1;
    case '?': *pOutTokenType = 7; return szExpression+1;
    case ':': *pOutTokenType = 8; return szExpression+1;
    case '^': *pOutTokenType = 9; return szExpression+1;
    case ',': *pOutTokenType = 2; return szExpression+1;
    case '<':
        ++szExpression;
        if (*szExpression == '=') { *pOutTokenType = 10; return szExpression+1; }
        *pOutTokenType = 11; return szExpression;
    case '>':
        ++szExpression;
        if (*szExpression == '=') { *pOutTokenType = 13; return szExpression+1; }
        *pOutTokenType = 12; return szExpression;
    case '!':
        ++szExpression;
        if (*szExpression != '=') return 0;
        *pOutTokenType = 15; return szExpression+1;
    case '=':
        ++szExpression;
        if (*szExpression != '=') return 0;
        *pOutTokenType = 14; return szExpression+1;
    case '.':
    {
        ++szExpression;
        char tLinkNameBuffer[256];
        int nLinkNameSize = 0;
        tLinkNameBuffer[nLinkNameSize++] = *szExpression;
        szExpression += nLinkNameSize;
        while (isalnum(*szExpression))
        {
            if (nLinkNameSize < 255) tLinkNameBuffer[nLinkNameSize++] = *szExpression;
            ++szExpression;
        }
        tLinkNameBuffer[nLinkNameSize] = 0;
        BOOL bHasResolvedToConstant = 0;
        const int nAST = pCalc->tPendingOperationsASTs[pCalc->nPendingOps-1];
        int nLinkerIndex = pfnLinkParse(tLinkNameBuffer, &bHasResolvedToConstant, nAST, pCalc->tLinkerIndex[pCalc->nPendingOps-1]);
        if (nLinkerIndex >= 0) { *pOutTokenType = 16; *pTokenAssociatedValue = nLinkerIndex; return szExpression; }
        return 0;
    }
    case 0: return 0;
    default: return 0;
    }
}


int __stdcall sub_006C1820_GetOperandCount( unsigned char nToken, CalcGetFunctionParameterCount_t pfnGetOperandCount, int nFunctionId); // 0x006C1820
int DATATABLS_CheckPrecendence(unsigned char nPreviousCalcType, unsigned char nNewCalcType); // 0x006C1800

FOGASTNodeStrc* __stdcall DATATBLS_ExpressionBuffer_PushRawConstant(FOGASTNodeStrc* pExpressionBufferPos, FOGASTNodeStrc* pExpressionBufferStart, int szBufferSize, FOGExpressionParserContextStrc* pCalc, int nValue); // 0x006C19C0
FOGASTNodeStrc* __stdcall DATATBLS_ExpressionBuffer_PushCallbackConstant(FOGASTNodeStrc* pExpressionBufferPos, FOGASTNodeStrc* pExpressionBufferStart, int szBufferSize, FOGExpressionParserContextStrc* pCalc, int nValue); // 0x006C1A50

// 0x006C1820
static int __stdcall sub_006C1820_GetOperandCount(
    unsigned char nToken, CalcGetFunctionParameterCount_t pfnGetOperandCount, int nFunctionId)
{
    switch (nToken)
    {
    case 22:
        return 3;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
        return 2;
    case 21:
        return 1;
    case 1:
        if (pfnGetOperandCount)
            return pfnGetOperandCount(nFunctionId);
        return 2;
    default:
        return 0;
    }
}

// 0x006C1800
static int DATATABLS_CheckPrecendence(unsigned char nPreviousCalcType, unsigned char nNewCalcType)
{
    if (nPreviousCalcType == 1 || nNewCalcType == 1 || nPreviousCalcType >= 23)
    {
        return 0;
    }
    else
    {
// build: symbol ?gaASTOperatorPrecedence@* 0x006FC874
        return gaASTOperatorPrecedence[nPreviousCalcType] >= nNewCalcType;
    }
}

// 0x006C19C0
static FOGASTNodeStrc* __stdcall DATATBLS_ExpressionBuffer_PushRawConstant(FOGASTNodeStrc* pExpressionBufferPos, FOGASTNodeStrc* pExpressionBufferStart, int szBufferSize, FOGExpressionParserContextStrc* pCalc, int nValue)
{
    if (nValue >= -128 && nValue <= 127)
    {
        if (pExpressionBufferPos - pExpressionBufferStart >= szBufferSize)
        {
            pExpressionBufferStart->nType = AST_None;
            return 0;
        }
        pExpressionBufferPos->nType = AST_Raw_Int8;
        ++pExpressionBufferPos;
        pExpressionBufferPos->nRawValue = nValue;
        ++pExpressionBufferPos;
    }
    else if (nValue >= -32768 && nValue <= 32767)
    {
        if (pExpressionBufferPos - pExpressionBufferStart + 3 >= szBufferSize)
        {
            pExpressionBufferStart->nType = AST_None;
            return 0;
        }
        pExpressionBufferPos->nType = AST_Raw_Int16;
        ++pExpressionBufferPos;
        *(short*)pExpressionBufferPos = nValue;
        pExpressionBufferPos += 2;
    }
    else
    {
        if (pExpressionBufferPos - pExpressionBufferStart + 5 >= szBufferSize)
        {
            pExpressionBufferStart->nType = AST_None;
            return 0;
        }
        pExpressionBufferPos->nType = AST_Raw_Int32;
        ++pExpressionBufferPos;
        *(int*)pExpressionBufferPos = nValue;
        pExpressionBufferPos += 4;
    }
    ++pCalc->nPendingParameters;
    return pExpressionBufferPos;
}

// 0x006C1A50
static FOGASTNodeStrc* __stdcall DATATBLS_ExpressionBuffer_PushCallbackConstant(FOGASTNodeStrc* pExpressionBufferPos, FOGASTNodeStrc* pExpressionBufferStart, int szBufferSize, FOGExpressionParserContextStrc* pCalc, int nValue)
{
    if (nValue >= -128 && nValue <= 127)
    {
        if (pExpressionBufferPos - pExpressionBufferStart >= szBufferSize)
        {
            pExpressionBufferStart->nType = AST_None;
            return 0;
        }
        pExpressionBufferPos->nType = AST_Callback_Param_UInt8;
        ++pExpressionBufferPos;
        pExpressionBufferPos->nRawValue = nValue;
        ++pExpressionBufferPos;
    }
    else if (nValue >= -32768 && nValue <= 32767)
    {
        if (pExpressionBufferPos - pExpressionBufferStart + 3 >= szBufferSize)
        {
            pExpressionBufferStart->nType = AST_None;
            return 0;
        }
        pExpressionBufferPos->nType = AST_Callback_Param_UInt16;
        ++pExpressionBufferPos;
        *(short*)pExpressionBufferPos = nValue;
        pExpressionBufferPos += 2;
    }
    else
    {
        if (pExpressionBufferPos - pExpressionBufferStart + 5 >= szBufferSize)
        {
            pExpressionBufferStart->nType = AST_None;
            return 0;
        }
        pExpressionBufferPos->nType = AST_Callback_Param_UInt32;
        ++pExpressionBufferPos;
        *(int*)pExpressionBufferPos = nValue;
        pExpressionBufferPos += 4;
    }
    ++pCalc->nPendingParameters;
    return pExpressionBufferPos;
}

#include "gen/data/Source/Fog/Unknown_006C0B80.inc"

// 0x006C18A0
static FOGASTNodeStrc* __stdcall DATATBLS_Evaluate_HandleNewOp(FOGASTNodeStrc* pASTBufferPos, FOGASTNodeStrc* pASTBufferStart, int nASTBufferSize, FOGExpressionParserContextStrc* pContext, unsigned char nNewASTType, CalcGetFunctionParameterCount_t pfnGetFunctionParametersCount, int nTokenAssociatedValue)
{
    while (pContext->nPendingOps > 0)
    {
        const unsigned char nPreviousASTType = pContext->tPendingOperationsASTs[pContext->nPendingOps - 1];
        if (!DATATABLS_CheckPrecendence(nPreviousASTType, nNewASTType))
        {
            break;
        }

        const int nParams = sub_006C1820_GetOperandCount(nPreviousASTType, pfnGetFunctionParametersCount, nTokenAssociatedValue);
        if (pContext->nPendingParameters < nParams)
        {
            pASTBufferStart->nType = 0;
            return 0;
        }
        if (pASTBufferPos - pASTBufferStart >= nASTBufferSize)
        {
            pASTBufferStart->nType = 0;
            return 0;
        }

        pASTBufferPos->nType = nPreviousASTType;
        pContext->nPendingOps--;
        pContext->nPendingParameters += 1 - nParams;
        pASTBufferPos++;
    }

    if (nNewASTType != 23 && nNewASTType != 3)
    {
        if (nNewASTType)
        {
            if (pContext->nPendingOps >= 64)
            {
                pASTBufferStart->nType = 0;
                return 0;
            }
            pContext->tPendingOperationsASTs[pContext->nPendingOps] = nNewASTType;
            pContext->tLinkerIndex[pContext->nPendingOps] = nTokenAssociatedValue;
            pContext->nPendingOps++;
        }
    }

    if (!nNewASTType)
    {
        if (pASTBufferPos == pASTBufferStart)
        {
            return 0;
        }
        if (pASTBufferPos - pASTBufferStart >= nASTBufferSize)
        {
            pASTBufferStart->nType = 0;
            return 0;
        }
        pASTBufferPos->nType = 0;
        pASTBufferPos++;
    }

    return pASTBufferPos;
}

// 0x006C1AE0
int __stdcall DATATBLS_CompileExpression(const char* szFormulaString, FOGASTNodeStrc* pOutASTBuffer, int nOutASTBufferSize, CalcGetKeyWordToNumber_t pfnFunctionNameToId, CalcGetFunctionParameterCount_t pfnGetFunctionParameterCount, CalcGetLinkerIndex_t pfnLinkParse)
{
	int bPendingValue = 0;
	int bHasAnyFunctionCall = 0;

	const char* szRemainingExpression = szFormulaString;
	FOGASTNodeStrc* pASTBufferPos = pOutASTBuffer;
	int nTokenAssociatedValue;
	FOGExpressionParserContextStrc tContext;
	tContext.nPendingOps = 0;
	tContext.nPendingParameters = 0;
	for (;;)
	{
		int nDispatchToken;
		{
			FOGCalcExpressionParserTokenType nToken = TOKEN_PAREN_OPEN;
			szRemainingExpression = DATATABLS_ParseExpressionToken(&tContext, szRemainingExpression, &nToken, &nTokenAssociatedValue, pfnFunctionNameToId, pfnLinkParse);
			if (!szRemainingExpression)
				break;
			nDispatchToken = nToken;
		}
		switch (nDispatchToken)
		{
		case TOKEN_PAREN_OPEN:
			if (tContext.nPendingOps >= 64)
			{
				goto Error;
			}
			tContext.tPendingOperationsASTs[tContext.nPendingOps++] = AST_Parenthesis_Open;
			break;
		case TOKEN_PAREN_CLOSE:
		{
			int nPendingOps = tContext.nPendingOps;
			if (nPendingOps <= 0)
			{
				goto Error;
			}

			FOGASTType* pPendingAST = &tContext.tPendingOperationsASTs[-1];
			do
			{
				const FOGASTType nPreviousASTType = pPendingAST[nPendingOps];
				if (nPreviousASTType == AST_Parenthesis_Open)
				{
					break;
				}
				const int nLinkerIndex = tContext.tLinkerIndex[nPendingOps - 1];
				const int nParams = sub_006C1820_GetOperandCount(nPreviousASTType, pfnGetFunctionParameterCount, nLinkerIndex);
				if (tContext.nPendingParameters < nParams || (pASTBufferPos - pOutASTBuffer) >= nOutASTBufferSize)
				{
					goto Error;
				}
				tContext.nPendingParameters = tContext.nPendingParameters + 1 - nParams;
				pASTBufferPos->nType = nPreviousASTType;
				pASTBufferPos++;
				if (nPreviousASTType == AST_CallbackTable)
				{
					if ((pASTBufferPos - pOutASTBuffer) >= nOutASTBufferSize)
					{
						goto Error;
					}
					pASTBufferPos->nRawValue = nLinkerIndex;
					pASTBufferPos++;
					break;
				}
				tContext.nPendingOps = --nPendingOps;
			} while (nPendingOps > 0);
			if (nPendingOps <= 0)
			{
				goto Error;
			}
			{
				const FOGASTType nPreviousASTType = pPendingAST[nPendingOps];
				if (nPreviousASTType == AST_Parenthesis_Open)
				{
					--nPendingOps;
				}
				else if (nPreviousASTType == AST_CallbackTable)
				{
					--nPendingOps;
				}
				else
				{
					goto Error;
				}
				tContext.nPendingOps = nPendingOps;
			}
			break;
		}
		case TOKEN_CUSTOM_RAW_CONSTANT:
			pASTBufferPos = DATATBLS_ExpressionBuffer_PushRawConstant(
				pASTBufferPos,
				pOutASTBuffer,
				nOutASTBufferSize,
				&tContext,
				nTokenAssociatedValue
			);
			bPendingValue = true;
			break;
		case TOKEN_CUSTOM_FUNCTION_PARAMETER_CONSTANT:
			pASTBufferPos = DATATBLS_ExpressionBuffer_PushCallbackConstant(
				pASTBufferPos,
				pOutASTBuffer,
				nOutASTBufferSize,
				&tContext,
				nTokenAssociatedValue
			);
			bPendingValue = true;
			bHasAnyFunctionCall = true;
			break;
        case TOKEN_CUSTOM_FUNCTION_TABLE:
            if (tContext.nPendingOps >= 64)
            {
                pOutASTBuffer->nRawValue = 0;
                pASTBufferPos = 0;
            }
            else
            {
                tContext.tPendingOperationsASTs[tContext.nPendingOps] = AST_CallbackTable;
                tContext.tLinkerIndex[tContext.nPendingOps] = nTokenAssociatedValue;
                tContext.nPendingOps++;
            }
            bPendingValue = true;
            bHasAnyFunctionCall = true;
            break;
		case TOKEN_PLUS:
			pASTBufferPos = DATATBLS_Evaluate_HandleNewOp(pASTBufferPos, pOutASTBuffer, nOutASTBufferSize, &tContext,
				AST_Addition, 0, 0
			);
			bPendingValue = false;
			break;
		case TOKEN_MINUS:
			if (bPendingValue)
                pASTBufferPos = DATATBLS_Evaluate_HandleNewOp(pASTBufferPos, pOutASTBuffer, nOutASTBufferSize, &tContext, AST_Substraction, 0, 0);
            else
                pASTBufferPos = DATATBLS_Evaluate_HandleNewOp(pASTBufferPos, pOutASTBuffer, nOutASTBufferSize, &tContext, AST_Negate, 0, 0);
			bPendingValue = false;
			break;
		case TOKEN_ASTERISK:
			pASTBufferPos = DATATBLS_Evaluate_HandleNewOp(pASTBufferPos, pOutASTBuffer, nOutASTBufferSize, &tContext,
				AST_Multipliction, 0, 0
			);
			bPendingValue = false;
			break;
		case TOKEN_SLASH:
			pASTBufferPos = DATATBLS_Evaluate_HandleNewOp(pASTBufferPos, pOutASTBuffer, nOutASTBufferSize, &tContext,
				AST_Division, 0, 0
			);
			bPendingValue = false;
			break;
		case TOKEN_CIRCUM:
			pASTBufferPos = DATATBLS_Evaluate_HandleNewOp(pASTBufferPos, pOutASTBuffer, nOutASTBufferSize, &tContext,
				AST_Power, 0, 0
			);
			bPendingValue = false;
			break;
		case TOKEN_LESS:
			pASTBufferPos = DATATBLS_Evaluate_HandleNewOp(pASTBufferPos, pOutASTBuffer, nOutASTBufferSize, &tContext,
				AST_LessThan, 0, 0
			);
			bPendingValue = false;
			break;
		case TOKEN_LESS_OR_EQ:
			pASTBufferPos = DATATBLS_Evaluate_HandleNewOp(pASTBufferPos, pOutASTBuffer, nOutASTBufferSize, &tContext,
				AST_LessOrEqualThan, 0, 0
			);
			bPendingValue = false;
			break;

		case TOKEN_GREATER_OR_EQ:
			pASTBufferPos = DATATBLS_Evaluate_HandleNewOp(pASTBufferPos, pOutASTBuffer, nOutASTBufferSize, &tContext,
				AST_GreaterThan, 0, 0
			);
			bPendingValue = false;
			break;
		case TOKEN_GREATER:
			pASTBufferPos = DATATBLS_Evaluate_HandleNewOp(pASTBufferPos, pOutASTBuffer, nOutASTBufferSize, &tContext,
				AST_GreaterOrEqualThan, 0, 0
			);
			bPendingValue = false;
			break;
		case TOKEN_LOGIC_EQUALS:
			pASTBufferPos = DATATBLS_Evaluate_HandleNewOp(pASTBufferPos, pOutASTBuffer, nOutASTBufferSize, &tContext,
				AST_Equal, 0, 0
			);
			bPendingValue = false;
			break;
		case TOKEN_LOGIC_DIFFERENT:
			pASTBufferPos = DATATBLS_Evaluate_HandleNewOp(pASTBufferPos, pOutASTBuffer, nOutASTBufferSize, &tContext,
				AST_NotEqual, 0, 0
			);
			bPendingValue = false;
			break;
		case TOKEN_QUESTION_MARK:
			pASTBufferPos = DATATBLS_Evaluate_HandleNewOp(pASTBufferPos, pOutASTBuffer, nOutASTBufferSize, &tContext,
				AST_Ternary, 0, 0
			);
			break;
		case TOKEN_COLON:
			pASTBufferPos = DATATBLS_Evaluate_HandleNewOp(pASTBufferPos, pOutASTBuffer, nOutASTBufferSize, &tContext,
				AST_Ternary_Colon, 0, 0
			);
			break;
		case TOKEN_COMMA:
			pASTBufferPos = DATATBLS_Evaluate_HandleNewOp(pASTBufferPos, pOutASTBuffer, nOutASTBufferSize, &tContext,
				AST_Callback_Param_Separator, 0, 0
			);
			break;
		default:
			break;
		}

		if (pASTBufferPos == 0)
		{
			goto Error;
		}
	}

	pASTBufferPos = DATATBLS_Evaluate_HandleNewOp(pASTBufferPos, pOutASTBuffer, nOutASTBufferSize, &tContext,
		AST_None, 0, 0
	);
	if (pASTBufferPos)
	{
		if (!bHasAnyFunctionCall)
		{
			const int nEvaluatedValue = DATATBLS_CalcEvaluateExpression(pOutASTBuffer, pASTBufferPos - pOutASTBuffer, 0, 0, 0, 0);
			pASTBufferPos = DATATBLS_ExpressionBuffer_PushRawConstant(pOutASTBuffer, pOutASTBuffer, nOutASTBufferSize, &tContext, nEvaluatedValue);
			pASTBufferPos = DATATBLS_Evaluate_HandleNewOp(pASTBufferPos, pOutASTBuffer, nOutASTBufferSize, &tContext,
				AST_None, 0, 0
			);
		}
		return pASTBufferPos - pOutASTBuffer;
	}
Error:
    pOutASTBuffer->nType = 0;
    return 0;
}
