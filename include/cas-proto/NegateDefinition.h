#pragma once
#ifndef NegateDefinition_h
#define NegateDefinition_h

#ifndef FunctionDefinition_h
#include "FunctionDefinition.h"
#endif



class NegateDefinition : public FunctionDefinition {

public:

    static NegateDefinition& getInstance();

private:

    NegateDefinition();

    NegateDefinition(const NegateDefinition&);
    NegateDefinition& operator = (const NegateDefinition&);

};



#endif // NegateDefinition_h
