#ifndef QuotientDefinition_h
#define QuotientDefinition_h

#ifndef FunctionDefinition_h
#include "FunctionDefinition.h"
#endif



class QuotientDefinition : public FunctionDefinition {

public:

    static QuotientDefinition& getInstance();

private:

    QuotientDefinition();

    QuotientDefinition(const QuotientDefinition&);
    QuotientDefinition& operator = (const QuotientDefinition&);

};



#endif
