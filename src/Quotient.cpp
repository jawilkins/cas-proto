#include "cas-proto/Quotient.h"

#ifndef Blank_h
#include "cas-proto/Blank.h"
#endif

#ifndef Constant_h
#include "cas-proto/Constant.h"
#endif

#ifndef QuotientDefinition_h
#include "cas-proto/QuotientDefinition.h"
#endif

#ifndef precedence_h
#include "cas-proto/precedence.h"
#endif

#ifndef Natural_h
#include "cas-proto/Natural.h"
#endif



FunctionSymbol& Quotient::symbol = FunctionSymbol::Create("\xF6", QuotientDefinition::getInstance());



CAS_PROTO_API Quotient& Quotient::Create()
{
    return Create(Blank::Create(), Blank::Create());
}

CAS_PROTO_API Quotient& Quotient::Create(const ExpressionBase& numerator, const ExpressionBase& denominator)
{
    const ExpressionBase* arguments[2];

    arguments[0] = &numerator;
    arguments[1] = &denominator;

    return *(new Quotient(arguments));
}

CAS_PROTO_API Quotient::Quotient(const ExpressionBase** arguments)
    : NcBinaryOperator(symbol, MUL, arguments)
{}

CAS_PROTO_API const ExpressionBase& Quotient::getNumerator() const
{
    return getA();
}

CAS_PROTO_API const ExpressionBase& Quotient::getDenominator() const
{
    return getB();
}

CAS_PROTO_API const void Quotient::bindNumerator(const ExpressionBase& numerator)
{
    bindA(numerator);
}

CAS_PROTO_API const void Quotient::bindDenominator(const ExpressionBase& denominator)
{
    bindB(denominator);
}

CAS_PROTO_API Quotient& Quotient::Deriv(const Variable& variable) const
{
    assert(false);
    throw 0;
}

CAS_PROTO_API ExpressionBase& Quotient::Simplify() const
{
    ExpressionBase& N = getA().Simplify();
    ExpressionBase& D = getB().Simplify();

    if (N.IsSame(Natural::Create(0))) {
        return Natural::Create(0);
    }
    else if (D.IsSame(Natural::Create(1))) {
        return N;
    }
    else if (N.IsSame(D)) {
        return Natural::Create(1);
    }
    // else if N is equivalent to D
        // return 1
    else {
        return Create(N, D);
    }
}
