#include "cas-proto/Variable.h"

using std::string;

#include "cas-proto/Natural.h"



CAS_PROTO_API Variable& Variable::Create(const VariableSymbol& symbol)
{
    return *(new Variable(symbol));
}

CAS_PROTO_API Variable::Variable(const VariableSymbol& symbol)
    : Expression<Variable, VariableSymbol, VariableDefinition>(symbol)
{}

CAS_PROTO_API Variable& Variable::Copy() const
{
    return Create(getSymbol());
}

CAS_PROTO_API Constant& Variable::Deriv(const Variable& variable) const
{
    return IsSame(variable) ? Natural::Create(1) : Natural::Create(0);
}

CAS_PROTO_API string Variable::toString() const
{
    return getSymbol().getLexeme();
}

CAS_PROTO_API ExpressionBase& Variable::Substitute(const Variable& variable, const ExpressionBase& substitution) const
{
    return IsSame(variable) ? substitution.Copy() : Copy();
}
