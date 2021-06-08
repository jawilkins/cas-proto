#ifndef ImaginaryDefinition_h
#define ImaginaryDefinition_h

#ifndef ConstantDefinition_h
#include "ConstantDefinition.h"
#endif



class ImaginaryDefinition : public ConstantDefinition {

public:

    static ImaginaryDefinition& getInstance();

private:

    ImaginaryDefinition();

    ImaginaryDefinition(const ImaginaryDefinition&);
    ImaginaryDefinition& operator = (const ImaginaryDefinition&);

};



#endif
