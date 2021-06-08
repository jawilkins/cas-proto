#pragma once
#ifndef SumDefinition_h
#define SumDefinition_h

#ifndef FunctionDefinition_h
#include "FunctionDefinition.h"
#endif



class SumDefinition : public FunctionDefinition {

public:

    CAS_PROTO_API static SumDefinition& getInstance();

private:

    CAS_PROTO_API SumDefinition();

    SumDefinition(const SumDefinition&);            // not implemented
    SumDefinition& operator=(const SumDefinition&); // not implemented

};



#endif // SumDefinition_h
