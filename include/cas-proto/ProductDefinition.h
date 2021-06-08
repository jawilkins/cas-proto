#pragma once
#ifndef ProductDefinition_h
#define ProductDefinition_h

#ifndef FunctionDefinition_h
#include "FunctionDefinition.h"
#endif



class ProductDefinition : public FunctionDefinition {

public:

    static ProductDefinition& getInstance();

private:

    ProductDefinition();

    ProductDefinition(const ProductDefinition&); // not implemented
    ProductDefinition& operator = (const ProductDefinition&); // not implemented

};



#endif // ProductDefinition_h
