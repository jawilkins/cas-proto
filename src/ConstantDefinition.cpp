#include "cas-proto/ConstantDefinition.h"



ConstantDefinition ConstantDefinition::undef;



CAS_PROTO_API std::string ConstantDefinition::toString() const
{
    return "<undefined-constant>";
}

CAS_PROTO_API std::string ConstantDefinition::genLexeme()
{
    return "_UNNAMED";
}
