#pragma once
#ifndef NegateDefinition_h
#define NegateDefinition_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifndef FunctionDefinition_h
#include "FunctionDefinition.h"
#endif



class NegateDefinition : public FunctionDefinition {

public:

    CAS_PROTO_API static NegateDefinition& getInstance();

private:

    CAS_PROTO_API NegateDefinition();

    NegateDefinition(const NegateDefinition&);            // not implemented
    NegateDefinition& operator=(const NegateDefinition&); // not implemented

};



#endif // NegateDefinition_h
