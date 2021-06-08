#include "cas-proto/BinaryOperator.h"

#ifndef Blank_h
#include "cas-proto/Blank.h"
#endif



CAS_PROTO_API BinaryOperator& BinaryOperator::Create(const FunctionSymbol& symbol, int precedence, const ExpressionBase& a, const ExpressionBase& b)
{
    assert(symbol.getDefinition().IsSame(FunctionDefinition::undef) || symbol.getDefinition().getArity() == 2);

    const ExpressionBase* arguments[2];

    arguments[0] = &a;
    arguments[1] = &b;

    return *(new BinaryOperator(symbol, precedence, arguments));
}

CAS_PROTO_API BinaryOperator& BinaryOperator::Create(const FunctionSymbol& symbol, int precedence)
{
    assert(symbol.getDefinition().IsSame(FunctionDefinition::undef) || symbol.getDefinition().getArity() == 2);

    return Create(symbol, precedence, Blank::Create(), Blank::Create());
}

CAS_PROTO_API BinaryOperator& BinaryOperator::Create(const std::string& lexeme, int precedence, const ExpressionBase& a, const ExpressionBase& b)
{
    return Create(FunctionSymbol::Create(lexeme), precedence, a, b);
}

CAS_PROTO_API BinaryOperator& BinaryOperator::Create(const std::string& lexeme, int precedence)
{
    return Create(FunctionSymbol::Create(lexeme), precedence, Blank::Create(), Blank::Create());
}

CAS_PROTO_API BinaryOperator& BinaryOperator::Create(int precedence)
{
    return Create(FunctionSymbol::Create(), precedence, Blank::Create(), Blank::Create());
}

CAS_PROTO_API const ExpressionBase& BinaryOperator::getA() const
{
    return getArgument(0);
}

CAS_PROTO_API const ExpressionBase& BinaryOperator::getB() const
{
    return getArgument(1);
}

CAS_PROTO_API const void BinaryOperator::bindA(const ExpressionBase& a)
{
    bindArgument(0, a);
}

CAS_PROTO_API const void BinaryOperator::bindB(const ExpressionBase& b)
{
    bindArgument(1, b);
}

CAS_PROTO_API BinaryOperator::BinaryOperator(const FunctionSymbol& symbol, int precedence, const ExpressionBase** arguments)
    : Function(symbol, arguments)
    , precedence(precedence)
{}

//CAS_PROTO_API void BinaryOperator::Accept(ExpressionVisitor& visitor)
//{
//    visitor.visit(*this);
//}

CAS_PROTO_API std::string BinaryOperator::toString() const
{
    std::string rv;

    const BinaryOperator* a = dynamic_cast<const BinaryOperator*>(&getA());

    if (a && precedence > a->precedence ) {
        rv = rv + "(" + getA().toString() + ")";
    }
    else {
        rv = rv + getA().toString();
    }

    rv = rv + getSymbol().getLexeme();

    const BinaryOperator* b = dynamic_cast<const BinaryOperator*>(&getB());

    if (b && precedence > b->precedence ) {
        rv = rv + "(" + getB().toString() + ")";
    }
    else {
        rv = rv + getB().toString();
    }

    return rv;
}

CAS_PROTO_API BinaryOperator& BinaryOperator::Substitute(const Variable& variable, const ExpressionBase& substitution) const
{
    const ExpressionBase& A = getA().Substitute(variable, substitution);
    const ExpressionBase& B = getB().Substitute(variable, substitution);

    return Create(getSymbol(), precedence, A, B);
}

CAS_PROTO_API BinaryOperator& BinaryOperator::Copy() const
{
    return Create(getSymbol(), precedence, getA().Copy(), getB().Copy());
}

CAS_PROTO_API int BinaryOperator::getPrecedence() const
{
    return precedence;
}

CAS_PROTO_API int BinaryOperator::getMinPrecedence() const
{
    int min = precedence;

    const BinaryOperator* a = this;

    for(;;) {
        a = dynamic_cast<const BinaryOperator*>(&(a->getA()));

        if (!a) break;

        if (a->getPrecedence() < min) min = a->getPrecedence();
    }

    const BinaryOperator* b = this;

    for(;;) {
        b = dynamic_cast<const BinaryOperator*>(&(b->getB()));

        if (!b) break;

        if (b->getPrecedence() < min) min = b->getPrecedence();
    }

    //int min = precedence;

    //const BinaryOperator* a = dynamic_cast<const BinaryOperator*>(&getA());

    //if (a) {
    //    int minA = a->getMinPrecedence();

    //    if (minA < min) min = minA;
    //}

    //const BinaryOperator* b = dynamic_cast<const BinaryOperator*>(&getB());

    //if (b) {
    //    int minB = b->getMinPrecedence();

    //    if (minB < min) min = minB;
    //}

    return min;
}

CAS_PROTO_API const ExpressionBase& BinaryOperator::getLeftmostTerm() const
{
    const BinaryOperator* a = dynamic_cast<const BinaryOperator*>(&getA());

    if (a) {
        return a->getLeftmostTerm();
    }
    else {
        return getA();
    }
}

CAS_PROTO_API const ExpressionBase& BinaryOperator::getRightmostTerm() const
{
    const BinaryOperator* b = dynamic_cast<const BinaryOperator*>(&getB());

    if (b) {
        return b->getRightmostTerm();
    }
    else {
        return getB();
    }
}
