#include "cas-proto/Difference.h"

#ifndef Blank_h
#include "cas-proto/Blank.h"
#endif

#ifndef Constant_h
#include "cas-proto/Constant.h"
#endif

#ifndef DifferenceDefinition_h
#include "cas-proto/DifferenceDefinition.h"
#endif

#ifndef Negate_h
#include "cas-proto/Negate.h"
#endif

#ifndef precedence_h
#include "cas-proto/precedence.h"
#endif

#ifndef Natural_h
#include "cas-proto/Natural.h"
#endif



FunctionSymbol& Difference::symbol = FunctionSymbol::Create("-", DifferenceDefinition::getInstance());



CAS_PROTO_API Difference& Difference::Create()
{
    return Create(Blank::Create(), Blank::Create());
}

CAS_PROTO_API Difference& Difference::Create(ExpressionBase& minuend, ExpressionBase& subtrahend)
{
    const ExpressionBase* arguments[2];

    arguments[0] = &minuend;
    arguments[1] = &subtrahend;

    return *(new Difference(arguments));
}

CAS_PROTO_API Difference::Difference(const ExpressionBase** arguments)
    : NcBinaryOperator(symbol, ADD, arguments)
{}

CAS_PROTO_API const ExpressionBase& Difference::getMinuend() const
{
    return getA();
}

CAS_PROTO_API const ExpressionBase& Difference::getSubtrahend() const
{
    return getB();
}

CAS_PROTO_API const void Difference::bindMinuend(const ExpressionBase& minuend)
{
    bindA(minuend);
}

CAS_PROTO_API const void Difference::bindSubtrahend(const ExpressionBase& subtrahend)
{
    bindB(subtrahend);
}

CAS_PROTO_API Difference& Difference::Deriv(const Variable& variable) const
{
    return Difference::Create(getMinuend().Deriv(variable), getSubtrahend().Deriv(variable));
}

CAS_PROTO_API ExpressionBase& Difference::Simplify() const
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
