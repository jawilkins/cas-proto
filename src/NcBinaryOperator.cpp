#include "cas-proto/NcBinaryOperator.h"

#ifndef Blank_h
#include "cas-proto/Blank.h"
#endif



CAS_PROTO_API NcBinaryOperator& NcBinaryOperator::Create(const FunctionSymbol& symbol, int precedence, const ExpressionBase& a, const ExpressionBase& b)
{
    assert(symbol.getDefinition().IsSame(FunctionDefinition::undef) || symbol.getDefinition().getArity() == 2);

    const ExpressionBase* arguments[2];

    arguments[0] = &a;
    arguments[1] = &b;

    return *(new NcBinaryOperator(symbol, precedence, arguments));
}

CAS_PROTO_API NcBinaryOperator& NcBinaryOperator::Create(const FunctionSymbol& symbol, int precedence)
{
    assert(symbol.getDefinition().IsSame(FunctionDefinition::undef) || symbol.getDefinition().getArity() == 2);

    return Create(symbol, precedence, Blank::Create(), Blank::Create());
}

CAS_PROTO_API NcBinaryOperator& NcBinaryOperator::Create(const std::string& lexeme, int precedence, const ExpressionBase& a, const ExpressionBase& b)
{
    return Create(FunctionSymbol::Create(lexeme), precedence, a, b);
}

CAS_PROTO_API NcBinaryOperator& NcBinaryOperator::Create(const std::string& lexeme, int precedence)
{
    return Create(FunctionSymbol::Create(lexeme), precedence, Blank::Create(), Blank::Create());
}

CAS_PROTO_API NcBinaryOperator& NcBinaryOperator::Create(int precedence)
{
    return Create(FunctionSymbol::Create(), precedence, Blank::Create(), Blank::Create());
}

CAS_PROTO_API NcBinaryOperator::NcBinaryOperator(const FunctionSymbol& symbol, int precedence, const ExpressionBase** arguments)
    : BinaryOperator(symbol, precedence, arguments)
{}

//CAS_PROTO_API void NcBinaryOperator::Accept(ExpressionVisitor& visitor)
//{
//    visitor.visit(*this);
//}

CAS_PROTO_API std::string NcBinaryOperator::toString() const
{
    std::string rv;

    const BinaryOperator* a = dynamic_cast<const BinaryOperator*>(&getA());

    if (a && getPrecedence() > a->getPrecedence()) {
        rv = rv + "(" + getA().toString() + ")";
    }
    else {
        rv = rv + getA().toString();
    }

    rv = rv + getSymbol().getLexeme();

    const BinaryOperator* b = dynamic_cast<const BinaryOperator*>(&getB());

    if (b && getPrecedence() >= b->getMinPrecedence()) {
        rv = rv + "(" + getB().toString() + ")";
    }
    else {
        rv = rv + getB().toString();
    }

    return rv;
}

CAS_PROTO_API NcBinaryOperator& NcBinaryOperator::Copy() const
{
    return Create(getSymbol(), getPrecedence(), getA().Copy(), getB().Copy());
}
