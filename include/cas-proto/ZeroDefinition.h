#pragma once
#ifndef ZeroDefinition_h
#define ZeroDefinition_h

#ifndef ConstantDefinition_h
#include "ConstantDefinition.h"
#endif



class ZeroDefinition : public ConstantDefinition {

public:

    CAS_PROTO_API static ZeroDefinition& getInstance();

private:

    CAS_PROTO_API ZeroDefinition();

    ZeroDefinition(const ZeroDefinition&);            // not implemented
    ZeroDefinition& operator=(const ZeroDefinition&); // not implemented

};



#endif
