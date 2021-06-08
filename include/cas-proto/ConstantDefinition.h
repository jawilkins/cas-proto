#ifndef ConstantDefinition_h
#define ConstantDefinition_h

#ifndef Definition_h
#include "Definition.h"
#endif



class ConstantDefinition : public Definition {

public:

    std::string toString() const;

    static ConstantDefinition undef;

    static std::string genLexeme();

};



#endif
