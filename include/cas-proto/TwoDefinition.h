#ifndef TwoDefinition_h
#define TwoDefinition_h

#ifndef ConstantDefinition_h
#include "ConstantDefinition.h"
#endif



class TwoDefinition : public ConstantDefinition {

public:

    static TwoDefinition& getInstance();

private:

    TwoDefinition();

    TwoDefinition(const TwoDefinition&);
    TwoDefinition& operator = (const TwoDefinition&);

};



#endif
