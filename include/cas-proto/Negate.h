#pragma once
#ifndef Negate_h
#define Negate_h

#ifndef UnaryOperator_h
#include "UnaryOperator.h"
#endif



class Negate : public UnaryOperator {

public:

    CAS_PROTO_API static Negate& Create();
    CAS_PROTO_API static Negate& Create(const ExpressionBase&);

    CAS_PROTO_API Negate& Deriv(const Variable& variable) const;

    CAS_PROTO_API ExpressionBase& Simplify() const;

protected:

    CAS_PROTO_API explicit Negate(const ExpressionBase**);

private:

    CAS_PROTO_API Negate(const Negate&);            // not implemented
    CAS_PROTO_API Negate& operator=(const Negate&); // not implemented

    static FunctionSymbol& symbol;

};



#endif // Negate_h
