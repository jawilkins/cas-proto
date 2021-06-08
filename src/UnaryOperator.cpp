#include "cas-proto/UnaryOperator.h"

#ifndef Blank_h
#include "cas-proto/Blank.h"
#endif

#ifndef BinaryOperator_h
#include "cas-proto/BinaryOperator.h"
#endif



CAS_PROTO_API UnaryOperator& UnaryOperator::Create(const FunctionSymbol& symbol, const ExpressionBase& a)
{
    assert(symbol.getDefinition().IsSame(FunctionDefinition::undef) || symbol.getDefinition().getArity() == 1);

    const ExpressionBase* arguments[1];

    arguments[0] = &a;

    return *(new UnaryOperator(symbol, arguments));
}

CAS_PROTO_API UnaryOperator& UnaryOperator::Create(const FunctionSymbol& symbol)
{
    assert(symbol.getDefinition().IsSame(FunctionDefinition::undef) || symbol.getDefinition().getArity() == 1);

    return Create(symbol, Blank::Create());
}

CAS_PROTO_API UnaryOperator& UnaryOperator::Create(const std::string& lexeme, const ExpressionBase& a)
{
    return Create(FunctionSymbol::Create(lexeme), a);
}

CAS_PROTO_API UnaryOperator& UnaryOperator::Create(const std::string& lexeme)
{
    return Create(FunctionSymbol::Create(lexeme), Blank::Create());
}

CAS_PROTO_API UnaryOperator& UnaryOperator::Create()
{
    return Create(FunctionSymbol::Create(), Blank::Create());
}

CAS_PROTO_API const ExpressionBase& UnaryOperator::get() const
{
    return getArgument(0);
}

CAS_PROTO_API const void UnaryOperator::bind(const ExpressionBase& a)
{
    bindArgument(0, a);
}

CAS_PROTO_API UnaryOperator::UnaryOperator(const FunctionSymbol& symbol, const ExpressionBase** arguments)
    : Function(symbol, arguments)
{}

//CAS_PROTO_API void UnaryOperator::Accept(ExpressionVisitor& visitor)
//{
//    visitor.visit(*this);
//}

CAS_PROTO_API std::string UnaryOperator::toString() const
{
    const BinaryOperator* f = dynamic_cast<const BinaryOperator*>(&get());

    if (f) {
        return getSymbol().getLexeme() + "(" + get().toString() + ")";
    }
    else {
        return getSymbol().getLexeme() + get().toString();
    }
}

CAS_PROTO_API UnaryOperator& UnaryOperator::Substitute(const Variable& variable, const ExpressionBase& substitution) const
{
    const ExpressionBase& A = get().Substitute(variable, substitution);

    return Create(getSymbol(), A);
}

CAS_PROTO_API UnaryOperator& UnaryOperator::Copy() const
{
    return Create(getSymbol(), get().Copy());
}
