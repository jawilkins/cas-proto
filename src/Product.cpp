#include "cas-proto/Product.h"

#ifndef Blank_h
#include "cas-proto/Blank.h"
#endif

#ifndef Constant_h
#include "cas-proto/Constant.h"
#endif

#ifndef ProductDefinition_h
#include "cas-proto/ProductDefinition.h"
#endif

#ifndef precedence_h
#include "cas-proto/precedence.h"
#endif

#ifndef Exponent_h
#include "cas-proto/Exponent.h"
#endif

#ifndef Negate_h
#include "cas-proto/Negate.h"
#endif

#ifndef Natural_h
#include "cas-proto/Natural.h"
#endif

#ifndef Variable_h
#include "cas-proto/Variable.h"
#endif

using std::string;



FunctionSymbol& Product::symbol = FunctionSymbol::Create("\xFA", ProductDefinition::getInstance());



CAS_PROTO_API Product& Product::Create()
{
    return Create(Blank::Create(), Blank::Create());
}

CAS_PROTO_API Product& Product::Create(const ExpressionBase& multiplier, const ExpressionBase& multiplicand)
{
    const ExpressionBase* arguments[2];

    arguments[0] = &multiplier;
    arguments[1] = &multiplicand;

    return *(new Product(arguments));
}

CAS_PROTO_API Product::Product(const ExpressionBase** arguments)
    : BinaryOperator(symbol, MUL, arguments)
{}

CAS_PROTO_API const ExpressionBase& Product::getMultiplier() const
{
    return getA();
}

CAS_PROTO_API const ExpressionBase& Product::getMultiplicand() const
{
    return getB();
}

CAS_PROTO_API const void Product::bindMultiplier(const ExpressionBase& multiplier)
{
    bindA(multiplier);
}

CAS_PROTO_API const void Product::bindMultiplicand(const ExpressionBase& multiplicand)
{
    bindB(multiplicand);
}

CAS_PROTO_API Sum& Product::Deriv(const Variable& variable) const
{
    return Sum::Create(Product::Create(getA().Copy(), getB().Deriv(variable)), Product::Create(getB().Copy(), getA().Deriv(variable)));
}

CAS_PROTO_API ExpressionBase& Product::Simplify() const
{
    ExpressionBase& A = getA().Simplify();
    ExpressionBase& B = getB().Simplify();

    if (A.IsSame(Natural::Create(1))) {
        return B;
    }
    else if (B.IsSame(Natural::Create(1))) {
        return A;
    }
    else if (A.IsSame(Natural::Create(0)) || B.IsSame(Natural::Create(0))) {
        return Natural::Create(0);
    }
    else if (A.IsSame(Constant::getImaginary()) && B.IsSame(Constant::getImaginary())) {
        return Negate::Create(Natural::Create(1));
    }
    else {
        const Exponent* ae = dynamic_cast<const Exponent*>(&A);
        const Exponent* be = dynamic_cast<const Exponent*>(&B);

        if (ae && be && ae->getBase().IsSame(be->getBase())) {
            return Exponent::Create(ae->getBase().Copy(), Sum::Create(ae->getExponent(), be->getExponent()).Simplify());
        }
        else if (ae && ae->getBase().IsSame(B)) {
            return Exponent::Create(ae->getBase().Copy(), Sum::Create(ae->getExponent(), Natural::Create(1)).Simplify());
        }
        else if (be && be->getBase().IsSame(A)) {
            return Exponent::Create(be->getBase().Copy(), Sum::Create(be->getExponent(), Natural::Create(1)).Simplify());
        }
        else if (A.IsSame(B)) {
            return Exponent::Create(A, Natural::Create(2)).Simplify();
        }
        else {
            return Create(A, B);
        }
    }
}

CAS_PROTO_API string Product::toString() const
{
    string rv;

    const BinaryOperator* a = dynamic_cast<const BinaryOperator*>(&getA());
    const BinaryOperator* b = dynamic_cast<const BinaryOperator*>(&getB());

    if (a && getPrecedence() > a->getPrecedence() ) {
        rv = rv + "(" + getA().toString() + ")";
    }
    else {
        rv = rv + getA().toString();
    }

    const ExpressionBase& l = a ? a->getRightmostTerm() : getA();
    const ExpressionBase& r = b ? b->getLeftmostTerm()  : getB();

    const Variable* va = dynamic_cast<const Variable*>(&l);
    const Constant* ca = dynamic_cast<const Constant*>(&l);
    const Variable* vb = dynamic_cast<const Variable*>(&r);
    const Constant* cb = dynamic_cast<const Constant*>(&r);

    if (!(a || b || (va && vb) || (ca && vb))) {
        rv = rv + getSymbol().getLexeme();
    }

    if (b && getPrecedence() > b->getPrecedence() ) {
        rv = rv + "(" + getB().toString() + ")";
    }
    else {
        rv = rv + getB().toString();
    }

    return rv;
}
