#pragma once
#ifndef ExponentDefinition_h
#define ExponentDefinition_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifndef FunctionDefinition_h
#include "FunctionDefinition.h"
#endif



class ExponentDefinition : public FunctionDefinition {

public:

    CAS_PROTO_API static ExponentDefinition& getInstance();

private:

    CAS_PROTO_API ExponentDefinition();

    ExponentDefinition(const ExponentDefinition&);            // not implemented
    ExponentDefinition& operator=(const ExponentDefinition&); // not implemented

};



#endif // ExponentDefinition_h
