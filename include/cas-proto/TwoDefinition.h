#pragma once
#ifndef TwoDefinition_h
#define TwoDefinition_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifndef ConstantDefinition_h
#include "ConstantDefinition.h"
#endif



class TwoDefinition : public ConstantDefinition {

public:

    CAS_PROTO_API static TwoDefinition& getInstance();

private:

    CAS_PROTO_API TwoDefinition();

    TwoDefinition(const TwoDefinition&);            // not implemented
    TwoDefinition& operator=(const TwoDefinition&); // not implemented

};



#endif // TwoDefinition_h
