#ifndef ExponentDefinition_h
#define ExponentDefinition_h

#ifndef FunctionDefinition_h
#include "FunctionDefinition.h"
#endif



class ExponentDefinition : public FunctionDefinition {

public:

    static ExponentDefinition& getInstance();

private:

    ExponentDefinition();

    ExponentDefinition(const ExponentDefinition&); // not implemented
    ExponentDefinition& operator = (const ExponentDefinition&); // not implemented

};



#endif
