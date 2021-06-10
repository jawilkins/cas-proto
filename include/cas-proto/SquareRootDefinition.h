#pragma once
#ifndef SquareRootDefinition_h
#define SquareRootDefinition_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifndef FunctionDefinition_h
#include "FunctionDefinition.h"
#endif



class SquareRootDefinition : public FunctionDefinition {

public:

    CAS_PROTO_API static SquareRootDefinition& getInstance();

private:

    CAS_PROTO_API SquareRootDefinition();

    SquareRootDefinition(const SquareRootDefinition&);            // not implemented
    SquareRootDefinition& operator=(const SquareRootDefinition&); // not implemented

};



#endif // SquareRootDefinition_h
