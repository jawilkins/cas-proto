#include "cas-proto/ImaginaryDefinition.h"



ImaginaryDefinition::ImaginaryDefinition()
    : ConstantDefinition()
{}

ImaginaryDefinition& ImaginaryDefinition::getInstance()
{
    static ImaginaryDefinition* instance = 0;

    if (!instance) {
        instance = new ImaginaryDefinition();
    }

    return *instance;
}
