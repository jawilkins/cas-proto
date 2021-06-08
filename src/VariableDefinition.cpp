#include "cas-proto/VariableDefinition.h"

using std::string;



VariableDefinition VariableDefinition::undef;



CAS_PROTO_API std::string VariableDefinition::toString() const
{
    return "<undefined-variable>";
}

CAS_PROTO_API std::string VariableDefinition::genLexeme()
{
    return "_unnamed";
}
