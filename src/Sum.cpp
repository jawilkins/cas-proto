#include "cas-proto/Sum.h"

#include "cas-proto/Blank.h"
#include "cas-proto/Constant.h"
#include "cas-proto/SumDefinition.h"
#include "cas-proto/precedence.h"
#include "cas-proto/Negate.h"
#include "cas-proto/Natural.h"
#include "cas-proto/Rational.h"



FunctionSymbol& Sum::symbol = FunctionSymbol::Create("+", SumDefinition::getInstance());



Sum& Sum::Create()
{
    return Create(Blank::Create(), Blank::Create());
}

Sum& Sum::Create(const ExpressionBase& addend, const ExpressionBase& augend)
{
    const ExpressionBase* arguments[2];

    arguments[0] = &addend;
    arguments[1] = &augend;

    return *(new Sum(arguments));
}

Sum::Sum(const ExpressionBase** arguments)
    : BinaryOperator(symbol, ADD, arguments)
{}

const ExpressionBase& Sum::getAddend() const
{
    return getA();
}

const ExpressionBase& Sum::getAugend() const
{
    return getB();
}

const void Sum::bindAddend(const ExpressionBase& addend)
{
    bindA(addend);
}

const void Sum::bindAugend(const ExpressionBase& augend)
{
    bindB(augend);
}

Sum& Sum::Deriv(const Variable& variable) const
{
    return Sum::Create(getAddend().Deriv(variable), getAugend().Deriv(variable));
}

ExpressionBase& Sum::Simplify() const
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
