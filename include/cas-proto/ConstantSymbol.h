#pragma once
#ifndef ConstantSymbol_h
#define ConstantSymbol_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifndef Symbol_h
#include "Symbol.h"
#endif

#ifndef ConstantDefinition_h
#include "ConstantDefinition.h"
#endif

typedef Symbol<ConstantDefinition> ConstantSymbol;

#endif // ConsantSymbol_h
