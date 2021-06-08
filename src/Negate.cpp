#include "cas-proto/Negate.h"

#include "cas-proto/Blank.h"
#include "cas-proto/Constant.h"
#include "cas-proto/NegateDefinition.h"
#include "cas-proto/Natural.h"



FunctionSymbol& Negate::symbol = FunctionSymbol::Create("-", NegateDefinition::getInstance());



Negate& Negate::Create()
{
    return Create(Blank::Create());
}

Negate& Negate::Create(const ExpressionBase& a)
{
    const ExpressionBase* arguments[1];

    arguments[0] = &a;

    return *(new Negate(arguments));
}

Negate::Negate(const ExpressionBase** arguments)
    : UnaryOperator(symbol, arguments)
{}

Negate& Negate::Deriv(const Variable& variable) const
{
    assert(false);
    throw 0;
}

ExpressionBase& Negate::Simplify() const
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
