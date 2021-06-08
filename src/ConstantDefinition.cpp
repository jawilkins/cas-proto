#include "cas-proto/ConstantDefinition.h"

using std::string;



ConstantDefinition ConstantDefinition::undef;



string ConstantDefinition::toString() const
{
    return "<undefined-constant>";
}

string ConstantDefinition::genLexeme()
{
    return "_UNNAMED";
}
