#include "cas-proto/FunctionDefinition.h"

using std::string;



FunctionDefinition FunctionDefinition::undef(0);



FunctionDefinition::FunctionDefinition(int arity)
    : arity(arity)
{}

string FunctionDefinition::toString() const
{
    return "<undefined-function>";
}

int FunctionDefinition::getArity() const
{
    return arity;
}

string FunctionDefinition::genLexeme()
{
    return "_Unamed";
}
