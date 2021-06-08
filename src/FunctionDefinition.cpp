#include "cas-proto/FunctionDefinition.h"

using std::string;



FunctionDefinition FunctionDefinition::undef(0);



CAS_PROTO_API FunctionDefinition::FunctionDefinition(int arity)
    : arity(arity)
{}

CAS_PROTO_API string FunctionDefinition::toString() const
{
    return "<undefined-function>";
}

CAS_PROTO_API int FunctionDefinition::getArity() const
{
    return arity;
}

CAS_PROTO_API string FunctionDefinition::genLexeme()
{
    return "_Unamed";
}
