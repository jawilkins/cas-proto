#pragma once
#ifndef OneDefinition_h
#define OneDefinition_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifndef ConstantDefinition_h
#include "ConstantDefinition.h"
#endif



class OneDefinition : public ConstantDefinition {

public:

    CAS_PROTO_API static OneDefinition& getInstance();

private:

    CAS_PROTO_API OneDefinition();

    OneDefinition(const OneDefinition&);            // not implemented
    OneDefinition& operator=(const OneDefinition&); // not implemented

};



#endif // OneDefinition_h
