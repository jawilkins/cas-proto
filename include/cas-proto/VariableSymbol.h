#pragma once
#ifndef VariableSymbol_h
#define VariableSymbol_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifndef Symbol_h
#include "Symbol.h"
#endif

#ifndef VariableDefinition_h
#include "VariableDefinition.h"
#endif

typedef Symbol<VariableDefinition> VariableSymbol;

#endif
