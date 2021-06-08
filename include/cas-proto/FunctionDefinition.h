#ifndef FunctionDefinition_h
#define FunctionDefinition_h

#ifndef Definition_h
#include "Definition.h"
#endif



class FunctionDefinition : public Definition {

public:

    explicit FunctionDefinition(int);

    int getArity() const;

    std::string toString() const;

    static FunctionDefinition undef;

    static std::string genLexeme();

private:

    int arity;

};



#endif
