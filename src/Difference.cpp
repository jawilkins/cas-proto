#include "cas-proto/Difference.h"

#include "cas-proto/Blank.h"
#include "cas-proto/Constant.h"
#include "cas-proto/DifferenceDefinition.h"
#include "cas-proto/Negate.h"
#include "cas-proto/precedence.h"
#include "cas-proto/Natural.h"



FunctionSymbol& Difference::symbol = FunctionSymbol::Create("-", DifferenceDefinition::getInstance());



Difference& Difference::Create()
{
    return Create(Blank::Create(), Blank::Create());
}

Difference& Difference::Create(ExpressionBase& minuend, ExpressionBase& subtrahend)
{
    const ExpressionBase* arguments[2];

    arguments[0] = &minuend;
    arguments[1] = &subtrahend;

    return *(new Difference(arguments));
}

Difference::Difference(const ExpressionBase** arguments)
    : NcBinaryOperator(symbol, ADD, arguments)
{}

const ExpressionBase& Difference::getMinuend() const
{
    return getA();
}

const ExpressionBase& Difference::getSubtrahend() const
{
    return getB();
}

const void Difference::bindMinuend(const ExpressionBase& minuend)
{
    bindA(minuend);
}

const void Difference::bindSubtrahend(const ExpressionBase& subtrahend)
{
    bindB(subtrahend);
}

Difference& Difference::Deriv(const Variable& variable) const
{
    return Difference::Create(getMinuend().Deriv(variable), getSubtrahend().Deriv(variable));
}

ExpressionBase& Difference::Simplify() const
{
    ExpressionBase& A = getA().Simplify();
    ExpressionBase& B = getB().Simplify();

    if (A.IsSame(B)) {
        return Natural::Create(0);
    }
    else if (A.IsSame(Natural::Create(0))) {
        return Negate::Create(B);
    }
    else if (B.IsSame(Natural::Create(0))) {
        return A;
    }
    else {
        return Create(A, B);
    }
}
