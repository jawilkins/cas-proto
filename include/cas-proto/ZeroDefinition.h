#ifndef ZeroDefinition_h
#define ZeroDefinition_h

#ifndef ConstantDefinition_h
#include "ConstantDefinition.h"
#endif



class ZeroDefinition : public ConstantDefinition {

public:

    static ZeroDefinition& getInstance();

private:

    ZeroDefinition();

    ZeroDefinition(const ZeroDefinition&);
    ZeroDefinition& operator = (const ZeroDefinition&);

};



#endif
