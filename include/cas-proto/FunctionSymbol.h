#pragma once
#ifndef FunctionSymbol_h
#define FunctionSymbol_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifndef Symbol_h
#include "Symbol.h"
#endif

#ifndef FunctionDefinition_h
#include "FunctionDefinition.h"
#endif

typedef Symbol<FunctionDefinition> FunctionSymbol;

#endif // FunctionSymbol_h
