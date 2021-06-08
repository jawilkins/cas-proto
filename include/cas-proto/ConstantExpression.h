#ifndef ConstantExpression_h
#define ConstantExpression_h

#ifndef Expression_h
#include "Expression.h"
#endif

class ConstantExpression : public Expression {

public:

    void accept(const class ExpressionVisitor&);

};

#endif
