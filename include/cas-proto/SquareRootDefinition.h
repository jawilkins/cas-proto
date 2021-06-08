#ifndef SquareRootDefinition_h
#define SquareRootDefinition_h

#ifndef FunctionDefinition_h
#include "FunctionDefinition.h"
#endif



class SquareRootDefinition : public FunctionDefinition {

public:

    static SquareRootDefinition& getInstance();

private:

    SquareRootDefinition();

    SquareRootDefinition(const SquareRootDefinition&);
    SquareRootDefinition& operator = (const SquareRootDefinition&);

};



#endif
