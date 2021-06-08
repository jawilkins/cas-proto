#include "cas-proto/VariableDefinition.h"

using std::string;



VariableDefinition VariableDefinition::undef;



string VariableDefinition::toString() const
{
    return "<undefined-variable>";
}

string VariableDefinition::genLexeme()
{
    return "_unnamed";
}
