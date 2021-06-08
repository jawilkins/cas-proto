#pragma once
#ifndef Quotient_h
#define Quotient_h

#ifndef NcBinaryOperator_h
#include "NcBinaryOperator.h"
#endif



class Quotient : public NcBinaryOperator {

public:

    CAS_PROTO_API static Quotient& Create();
    CAS_PROTO_API static Quotient& Create(const ExpressionBase&, const ExpressionBase&);

    CAS_PROTO_API const ExpressionBase& getNumerator() const;
    CAS_PROTO_API const ExpressionBase& getDenominator() const;

    CAS_PROTO_API const void bindNumerator(const ExpressionBase&);
    CAS_PROTO_API const void bindDenominator(const ExpressionBase&);

    CAS_PROTO_API Quotient& Deriv(const Variable& variable) const;

    CAS_PROTO_API ExpressionBase& Simplify() const;

protected:

    CAS_PROTO_API explicit Quotient(const ExpressionBase**);

private:

    Quotient(const Quotient&);            // not implemented
    Quotient& operator=(const Quotient&); // not implemented

    static FunctionSymbol& symbol;

};



#endif // Quotient_h
