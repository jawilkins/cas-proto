#ifndef Negate_h
#define Negate_h

#ifndef UnaryOperator_h
#include "UnaryOperator.h"
#endif



class Negate : public UnaryOperator {

public:

    static Negate& Create();
    static Negate& Create(const ExpressionBase&);

    Negate& Deriv(const Variable& variable) const;

    ExpressionBase& Simplify() const;

protected:

    Negate(const ExpressionBase**);

private:

    Negate(const Negate&); // not implememented
    Negate& operator = (const Negate&); // not implemented

    static FunctionSymbol& symbol;

};



#endif
