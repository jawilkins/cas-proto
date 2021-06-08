#include "cas-proto/ImaginaryDefinition.h"



CAS_PROTO_API ImaginaryDefinition::ImaginaryDefinition()
    : ConstantDefinition()
{}

CAS_PROTO_API ImaginaryDefinition& ImaginaryDefinition::getInstance()
{
    static ImaginaryDefinition* instance = 0;

    if (!instance) {
        instance = new ImaginaryDefinition();
    }

    return *instance;
}
