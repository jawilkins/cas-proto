#ifndef DifferenceDefinition_h
#define DifferenceDefinition_h

#pragma once
#ifndef FunctionDefinition_h
#include "FunctionDefinition.h"
#endif



class DifferenceDefinition : public FunctionDefinition {

public:

    CAS_PROTO_API static DifferenceDefinition& getInstance();

private:

    CAS_PROTO_API DifferenceDefinition();

    DifferenceDefinition(const DifferenceDefinition&);            // not implemented
    DifferenceDefinition& operator=(const DifferenceDefinition&); // not implemented

};



#endif // DifferenceDefinition_h
