#include "cas-proto/ExponentDefinition.h"



ExponentDefinition::ExponentDefinition()
    : FunctionDefinition(2)
{}

ExponentDefinition& ExponentDefinition::getInstance()
{
    static ExponentDefinition* instance = 0;

    if (!instance) {
        instance = new ExponentDefinition();
    }

    return *instance;
}
