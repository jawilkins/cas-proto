#include "cas-proto/OneDefinition.h"



OneDefinition::OneDefinition()
    : ConstantDefinition()
{}

OneDefinition& OneDefinition::getInstance()
{
    static OneDefinition* instance = 0;

    if (!instance) {
        instance = new OneDefinition();
    }

    return *instance;
}
