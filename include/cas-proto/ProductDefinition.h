#pragma once
#ifndef ProductDefinition_h
#define ProductDefinition_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifndef FunctionDefinition_h
#include "FunctionDefinition.h"
#endif



class ProductDefinition : public FunctionDefinition {

public:

    CAS_PROTO_API static ProductDefinition& getInstance();

private:

    CAS_PROTO_API ProductDefinition();

    ProductDefinition(const ProductDefinition&);              // not implemented
    ProductDefinition& operator = (const ProductDefinition&); // not implemented

};



#endif // ProductDefinition_h
