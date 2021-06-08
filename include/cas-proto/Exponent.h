#pragma once
#ifndef Exponent_h
#define Exponent_h

#ifndef Product_h
#include "Product.h"
#endif



class Exponent : public BinaryOperator {

public:

    CAS_PROTO_API static Exponent& Create();
    CAS_PROTO_API static Exponent& Create(const ExpressionBase&, const ExpressionBase&);

    CAS_PROTO_API static Exponent& Square(const ExpressionBase&);
    CAS_PROTO_API static Exponent& Root(const ExpressionBase&, int);
    CAS_PROTO_API static Exponent& SquareRoot(const ExpressionBase&);
    CAS_PROTO_API static Exponent& CubeRoot(const ExpressionBase&);

    CAS_PROTO_API const ExpressionBase& getBase() const;
    CAS_PROTO_API const ExpressionBase& getExponent() const;

    CAS_PROTO_API const void bindBase(const ExpressionBase&);
    CAS_PROTO_API const void bindExponent(const ExpressionBase&);

    CAS_PROTO_API Product& Deriv(const Variable& variable) const;

    CAS_PROTO_API ExpressionBase& Simplify() const;

    CAS_PROTO_API std::string toString() const;

protected:

    CAS_PROTO_API explicit Exponent(const ExpressionBase**);

private:

    Exponent(const Exponent&);            // not implemented
    Exponent& operator=(const Exponent&); // not implemented

    static FunctionSymbol& symbol;

};



#endif // Exponent_h
