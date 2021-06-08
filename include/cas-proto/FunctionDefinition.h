#pragma once
#ifndef FunctionDefinition_h
#define FunctionDefinition_h

#ifndef Definition_h
#include "Definition.h"
#endif



class FunctionDefinition : public Definition {

public:

    CAS_PROTO_API explicit FunctionDefinition(int);

    CAS_PROTO_API int getArity() const;

    CAS_PROTO_API std::string toString() const;

    CAS_PROTO_API static FunctionDefinition undef;

    CAS_PROTO_API static std::string genLexeme();

private:

    int arity;

};



#endif // FunctionDefinition_h
