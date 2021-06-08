#ifndef DifferenceDefinition_h
#define DifferenceDefinition_h

#ifndef FunctionDefinition_h
#include "FunctionDefinition.h"
#endif



class DifferenceDefinition : public FunctionDefinition {

public:

    static DifferenceDefinition& getInstance();

private:

    DifferenceDefinition();

    DifferenceDefinition(const DifferenceDefinition&);
    DifferenceDefinition& operator = (const DifferenceDefinition&);

};



#endif
