#include "cas-proto/Sum.h"

#ifndef Blank_h
#include "cas-proto/Blank.h"
#endif

#ifndef Constant_h
#include "cas-proto/Constant.h"
#endif

#ifndef SumDefinition_h
#include "cas-proto/SumDefinition.h"
#endif

#ifndef precedence_h
#include "cas-proto/precedence.h"
#endif

#ifndef Negate_h
#include "cas-proto/Negate.h"
#endif

#ifndef Natural_h
#include "cas-proto/Natural.h"
#endif

#ifndef Rational_h
#include "cas-proto/Rational.h"
#endif



FunctionSymbol& Sum::symbol = FunctionSymbol::Create("+", SumDefinition::getInstance());



CAS_PROTO_API Sum& Sum::Create()
{
    return Create(Blank::Create(), Blank::Create());
}

CAS_PROTO_API Sum& Sum::Create(const ExpressionBase& addend, const ExpressionBase& augend)
{
    const ExpressionBase* arguments[2];

    arguments[0] = &addend;
    arguments[1] = &augend;

    return *(new Sum(arguments));
}

CAS_PROTO_API Sum::Sum(const ExpressionBase** arguments)
    : BinaryOperator(symbol, ADD, arguments)
{}

CAS_PROTO_API const ExpressionBase& Sum::getAddend() const
{
    return getA();
}

CAS_PROTO_API const ExpressionBase& Sum::getAugend() const
{
    return getB();
}

CAS_PROTO_API const void Sum::bindAddend(const ExpressionBase& addend)
{
    bindA(addend);
}

CAS_PROTO_API const void Sum::bindAugend(const ExpressionBase& augend)
{
    bindB(augend);
}

CAS_PROTO_API Sum& Sum::Deriv(const Variable& variable) const
{
    return Sum::Create(getAddend().Deriv(variable), getAugend().Deriv(variable));
}

CAS_PROTO_API ExpressionBase& Sum::Simplify() const
{
    ExpressionBase& A = getA().Simplify();
    ExpressionBase& B = getB().Simplify();

    if (A.IsSame(Natural::Create(0)) && B.IsSame(Natural::Create(0))) {
        return Natural::Create(0);
    }
    else if (A.IsSame(Natural::Create(0))) {
        return B;
    }
    else if (B.IsSame(Natural::Create(0))) {
        return A;
    }
    else {
        const Negate* na = dynamic_cast<const Negate*>(&A);
        const Negate* nb = dynamic_cast<const Negate*>(&B);

        if (na && na->get().IsSame(B)) {
            return Natural::Create(0);
        }
        else if (nb && nb->get().IsSame(A)) {
            return Natural::Create(0);
        }
        else {
            const Natural* sa = dynamic_cast<const Natural*>(&A);
            const Natural* sb = dynamic_cast<const Natural*>(&B);

            const Rational* ra = dynamic_cast<const Rational*>(&A);
            const Rational* rb = dynamic_cast<const Rational*>(&B);

            if (sa && sb) {
                return Natural::Create(sa->get() + sb->get());
            }
            else if (sa && rb) {
                return Rational::Create(sa->get()*rb->getDenominator() + rb->getNumerator(), rb->getDenominator()).Simplify();
            }
            else if (ra && sb) {
                return Rational::Create(sb->get()*ra->getDenominator() + ra->getNumerator(), ra->getDenominator()).Simplify();
            }
            else if (ra && rb) {
                return Rational::Create(ra->getNumerator()*rb->getDenominator() + rb->getNumerator()*ra->getDenominator(), ra->getDenominator() * rb->getDenominator()).Simplify();
            }

            return Create(A, B);
        }
    }
}
