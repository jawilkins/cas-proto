#pragma once
#ifndef ConstantDefinition_h
#define ConstantDefinition_h

#ifndef Definition_h
#include "Definition.h"
#endif



class ConstantDefinition : public Definition {

public:

    CAS_PROTO_API std::string toString() const;

    CAS_PROTO_API static ConstantDefinition undef;

    CAS_PROTO_API static std::string genLexeme();

};



#endif // ConstantDefinition_h
