#ifndef OneDefinition_h
#define OneDefinition_h

#ifndef ConstantDefinition_h
#include "ConstantDefinition.h"
#endif



class OneDefinition : public ConstantDefinition {

public:

    static OneDefinition& getInstance();

private:

    OneDefinition();

    OneDefinition(const OneDefinition&);
    OneDefinition& operator = (const OneDefinition&);

};



#endif
