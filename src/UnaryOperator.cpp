#include "cas-proto/UnaryOperator.h"
#include "cas-proto/BinaryOperator.h"

#include "cas-proto/Blank.h"

using std::string;



UnaryOperator& UnaryOperator::Create(const FunctionSymbol& symbol, const ExpressionBase& a)
{
    assert(symbol.getDefinition().IsSame(FunctionDefinition::undef) || symbol.getDefinition().getArity() == 1);

    const ExpressionBase* arguments[1];

    arguments[0] = &a;

    return *(new UnaryOperator(symbol, arguments));
}

UnaryOperator& UnaryOperator::Create(const FunctionSymbol& symbol)
{
    assert(symbol.getDefinition().IsSame(FunctionDefinition::undef) || symbol.getDefinition().getArity() == 1);

    return Create(symbol, Blank::Create());
}

UnaryOperator& UnaryOperator::Create(const std::string& lexeme, const ExpressionBase& a)
{
    return Create(FunctionSymbol::Create(lexeme), a);
}

UnaryOperator& UnaryOperator::Create(const std::string& lexeme)
{
    return Create(FunctionSymbol::Create(lexeme), Blank::Create());
}

UnaryOperator& UnaryOperator::Create()
{
    return Create(FunctionSymbol::Create(), Blank::Create());
}

const ExpressionBase& UnaryOperator::get() const
{
    return getArgument(0);
}

const void UnaryOperator::bind(const ExpressionBase& a)
{
    bindArgument(0, a);
}

UnaryOperator::UnaryOperator(const FunctionSymbol& symbol, const ExpressionBase** arguments)
    : Function(symbol, arguments)
{}

//void UnaryOperator::Accept(ExpressionVisitor& visitor)
//{
//    visitor.visit(*this);
//}

string UnaryOperator::toString() const
{
    const BinaryOperator* f = dynamic_cast<const BinaryOperator*>(&get());

    if (f) {
        return getSymbol().getLexeme() + "(" + get().toString() + ")";
    }
    else {
        return getSymbol().getLexeme() + get().toString();
    }
}

UnaryOperator& UnaryOperator::Substitute(const Variable& variable, const ExpressionBase& substitution) const
{
    const ExpressionBase& A = get().Substitute(variable, substitution);

    return Create(getSymbol(), A);
}

UnaryOperator& UnaryOperator::Copy() const
{
    return Create(getSymbol(), get().Copy());
}
