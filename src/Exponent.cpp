#include "cas-proto/Exponent.h"

#ifndef Blank_h
#include "cas-proto/Blank.h"
#endif

#ifndef Constant_h
#include "cas-proto/Constant.h"
#endif

#ifndef ExponentDefinition_h
#include "cas-proto/ExponentDefinition.h"
#endif

#ifndef Difference_h
#include "cas-proto/Difference.h"
#endif

#ifndef precedence_h
#include "cas-proto/precedence.h"
#endif

#ifndef Natural_h
#include "cas-proto/Natural.h"
#endif

#ifndef Rational_h
#include "cas-proto/Rational.h"
#endif

#ifndef Negate_h
#include "cas-proto/Negate.h"
#endif



FunctionSymbol& Exponent::symbol = FunctionSymbol::Create("^", ExponentDefinition::getInstance());



CAS_PROTO_API Exponent& Exponent::Create()
{
    return Create(Blank::Create(), Blank::Create());
}

CAS_PROTO_API Exponent& Exponent::Create(const ExpressionBase& base, const ExpressionBase& exponent)
{
    const ExpressionBase* arguments[2];

    arguments[0] = &base;
    arguments[1] = &exponent;

    return *(new Exponent(arguments));
}

CAS_PROTO_API Exponent& Exponent::Square(const ExpressionBase& base)
{
    return Create(base, Natural::Create(2));
}

CAS_PROTO_API Exponent& Exponent::Root(const ExpressionBase& base, int root)
{
    return Create(base, Rational::Create(1, root));
}

CAS_PROTO_API Exponent& Exponent::SquareRoot(const ExpressionBase& base)
{
    return Root(base, 2);
}

CAS_PROTO_API Exponent& Exponent::CubeRoot(const ExpressionBase& base)
{
    return Root(base, 3);
}

CAS_PROTO_API Exponent::Exponent(const ExpressionBase** arguments)
    : BinaryOperator(symbol, EXP, arguments)
{}

CAS_PROTO_API const ExpressionBase& Exponent::getBase() const
{
    return getA();
}

CAS_PROTO_API const ExpressionBase& Exponent::getExponent() const
{
    return getB();
}

CAS_PROTO_API const void Exponent::bindBase(const ExpressionBase& base)
{
    bindA(base);
}

CAS_PROTO_API const void Exponent::bindExponent(const ExpressionBase& exponent)
{
    bindB(exponent);
}

CAS_PROTO_API Product& Exponent::Deriv(const Variable& variable) const
{
    return Product::Create(getExponent().Copy(), Exponent::Create(getBase().Copy(), Difference::Create(getExponent().Copy(), Natural::Create(1))));
}

CAS_PROTO_API ExpressionBase& Exponent::Simplify() const
{
    ExpressionBase& B = getBase().Simplify();
    ExpressionBase& E = getExponent().Simplify();

    if (E.IsSame(Natural::Create(1))) {
        return B;
    }
    else if (E.IsSame(Natural::Create(0))) {
        return Natural::Create(1);
    }
    else if (B.IsSame(Natural::Create(1))) {
        return Natural::Create(1);
    }
    else if (B.IsSame(Natural::Create(0))) {
        return Natural::Create(0);
    }
    else if (E.IsSame(Rational::Create(1, 2))) {
        const Product* p = dynamic_cast<const Product*>(&B);
        const Negate*  n = dynamic_cast<const Negate*>(&B);

        if (p && p->getMultiplier().IsSame(p->getMultiplicand())) {
            return p->getMultiplier().Copy();
        }
        else if (n && n->get().IsSame(Natural::Create(1))) {
            return Constant::getImaginary();
        }
        else {
            return Create(B, E);
        }
    }
    else {
        return Create(B, E);
    }
}

CAS_PROTO_API std::string Exponent::toString() const
{
    if (getExponent().IsSame(Natural::Create(2))) {
        const BinaryOperator* f = dynamic_cast<const BinaryOperator*>(&getBase());

        if (f) {
            return "(" + f->toString() + ")\xFD";
        }
        else {
            return getA().toString() + "\xFD";
        }
    }
    else if (getExponent().IsSame(Rational::Create(1, 2))) {
        const BinaryOperator* f = dynamic_cast<const BinaryOperator*>(&getBase());

        if (f) {
            return "\xFB(" + f->toString() + ")";
        }
        else {
            return "\xFB" + getBase().toString();
        }
    }
    else {
        return BinaryOperator::toString();
    }
}
