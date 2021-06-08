#include "cas-proto/Variable.h"

using std::string;

#include "cas-proto/Natural.h"



Variable& Variable::Create(const VariableSymbol& symbol)
{
    return *(new Variable(symbol));
}

Variable::Variable(const VariableSymbol& symbol)
    : Expression<Variable, VariableSymbol, VariableDefinition>(symbol)
{}

Variable& Variable::Copy() const
{
    return Create(getSymbol());
}

Constant& Variable::Deriv(const Variable& variable) const
{
    return IsSame(variable) ? Natural::Create(1) : Natural::Create(0);
}

string Variable::toString() const
{
    return getSymbol().getLexeme();
}

ExpressionBase& Variable::Substitute(const Variable& variable, const ExpressionBase& substitution) const
{
    return IsSame(variable) ? substitution.Copy() : Copy();
}
