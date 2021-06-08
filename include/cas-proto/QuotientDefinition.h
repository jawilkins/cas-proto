#pragma once
#ifndef QuotientDefinition_h
#define QuotientDefinition_h

#ifndef FunctionDefinition_h
#include "FunctionDefinition.h"
#endif



class QuotientDefinition : public FunctionDefinition {

public:

    CAS_PROTO_API static QuotientDefinition& getInstance();

private:

    CAS_PROTO_API QuotientDefinition();

    QuotientDefinition(const QuotientDefinition&);            // not implemented
    QuotientDefinition& operator=(const QuotientDefinition&); // not implemented

};



#endif // QuotientDefinition_h
