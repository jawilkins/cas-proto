#ifndef Quotient_h
#define Quotient_h

#ifndef NcBinaryOperator_h
#include "NcBinaryOperator.h"
#endif



class Quotient : public NcBinaryOperator {

public:

    static Quotient& Create();
    static Quotient& Create(const ExpressionBase&, const ExpressionBase&);

    const ExpressionBase& getNumerator() const;
    const ExpressionBase& getDenominator() const;

    const void bindNumerator(const ExpressionBase&);
    const void bindDenominator(const ExpressionBase&);

    Quotient& Deriv(const Variable& variable) const;

    ExpressionBase& Simplify() const;

protected:

    Quotient(const ExpressionBase**);

private:

    Quotient(const Quotient&); // not implememented
    Quotient& operator = (const Quotient&); // not implemented

    static FunctionSymbol& symbol;

};



#endif
