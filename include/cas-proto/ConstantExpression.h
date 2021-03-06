#pragma once
#ifndef ConstantExpression_h
#define ConstantExpression_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifndef Expression_h
#include "Expression.h"
#endif

class ConstantExpression : public Expression {

public:

    CAS_PROTO_API void accept(const class ExpressionVisitor&);

};

#endif // ConstantExpression_h
