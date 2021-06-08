#ifndef SumDefinition_h
#define SumDefinition_h

#ifndef FunctionDefinition_h
#include "FunctionDefinition.h"
#endif



class SumDefinition : public FunctionDefinition {

public:

    static SumDefinition& getInstance();

private:

    SumDefinition();

    SumDefinition(const SumDefinition&);
    SumDefinition& operator = (const SumDefinition&);

};



#endif
