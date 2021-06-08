#include "cas-proto/Quotient.h"

#include "cas-proto/Blank.h"
#include "cas-proto/Constant.h"
#include "cas-proto/QuotientDefinition.h"
#include "cas-proto/precedence.h"
#include "cas-proto/Natural.h"



FunctionSymbol& Quotient::symbol = FunctionSymbol::Create("\xF6", QuotientDefinition::getInstance());



Quotient& Quotient::Create()
{
    return Create(Blank::Create(), Blank::Create());
}

Quotient& Quotient::Create(const ExpressionBase& numerator, const ExpressionBase& denominator)
{
    const ExpressionBase* arguments[2];

    arguments[0] = &numerator;
    arguments[1] = &denominator;

    return *(new Quotient(arguments));
}

Quotient::Quotient(const ExpressionBase** arguments)
    : NcBinaryOperator(symbol, MUL, arguments)
{}

const ExpressionBase& Quotient::getNumerator() const
{
    return getA();
}

const ExpressionBase& Quotient::getDenominator() const
{
    return getB();
}

const void Quotient::bindNumerator(const ExpressionBase& numerator)
{
    bindA(numerator);
}

const void Quotient::bindDenominator(const ExpressionBase& denominator)
{
    bindB(denominator);
}

Quotient& Quotient::Deriv(const Variable& variable) const
{
    assert(false);
    throw 0;
}

ExpressionBase& Quotient::Simplify() const
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
