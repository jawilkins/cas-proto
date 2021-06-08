#include "cas-proto/TwoDefinition.h"



TwoDefinition::TwoDefinition()
    : ConstantDefinition()
{}

TwoDefinition& TwoDefinition::getInstance()
{
    static TwoDefinition* instance = 0;

    if (!instance) {
        instance = new TwoDefinition();
    }

    return *instance;
}
