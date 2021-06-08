#include "cas-proto/Negate.h"

#ifndef Blank_h
#include "cas-proto/Blank.h"
#endif

#ifndef Constant_h
#include "cas-proto/Constant.h"
#endif

#ifndef NegateDefinition_h
#include "cas-proto/NegateDefinition.h"
#endif

#ifndef Natural_h
#include "cas-proto/Natural.h"
#endif



FunctionSymbol& Negate::symbol = FunctionSymbol::Create("-", NegateDefinition::getInstance());



CAS_PROTO_API Negate& Negate::Create()
{
    return Create(Blank::Create());
}

CAS_PROTO_API Negate& Negate::Create(const ExpressionBase& a)
{
    const ExpressionBase* arguments[1];

    arguments[0] = &a;

    return *(new Negate(arguments));
}

CAS_PROTO_API Negate::Negate(const ExpressionBase** arguments)
    : UnaryOperator(symbol, arguments)
{}

CAS_PROTO_API Negate& Negate::Deriv(const Variable& variable) const
{
    assert(false);
    throw 0;
}

CAS_PROTO_API ExpressionBase& Negate::Simplify() const
{
    ExpressionBase& A = get().Simplify();

    if (A.IsSame(Natural::Create(0))) {
        return Natural::Create(0);
    }
    else {
        const Negate* n = dynamic_cast<const Negate*>(&A);

        if (n) {
            return n->get().Copy();
        }
        else {
            return Create(A);
        }
    }
}
