#ifndef VariableDefinition_h
#define VariableDefinition_h

#ifndef Definition_h
#include "Definition.h"
#endif



class VariableDefinition : public Definition {

public:

    std::string toString() const;

    static VariableDefinition undef;

    static std::string genLexeme();

};



#endif
