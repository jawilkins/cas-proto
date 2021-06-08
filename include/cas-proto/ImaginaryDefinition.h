#pragma once
#ifndef ImaginaryDefinition_h
#define ImaginaryDefinition_h

#ifndef ConstantDefinition_h
#include "ConstantDefinition.h"
#endif



class ImaginaryDefinition : public ConstantDefinition {

public:

    CAS_PROTO_API static ImaginaryDefinition& getInstance();

private:

    CAS_PROTO_API ImaginaryDefinition();

    ImaginaryDefinition(const ImaginaryDefinition&);            // not implemented
    ImaginaryDefinition& operator=(const ImaginaryDefinition&); // not implemented

};



#endif // ImaginaryDefinition_h
