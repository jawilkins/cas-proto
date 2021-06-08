#pragma once
#ifndef VariableDefinition_h
#define VariableDefinition_h

#ifndef Definition_h
#include "Definition.h"
#endif



class VariableDefinition : public Definition {

public:

    CAS_PROTO_API std::string toString() const;

    CAS_PROTO_API static VariableDefinition undef;

    CAS_PROTO_API static std::string genLexeme();

};



#endif // VariableDefinition_h
