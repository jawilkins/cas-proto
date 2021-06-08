#include "cas-proto/DifferenceDefinition.h"



DifferenceDefinition::DifferenceDefinition()
    : FunctionDefinition(2)
{}

DifferenceDefinition& DifferenceDefinition::getInstance()
{
    static DifferenceDefinition* instance = 0;

    if (!instance) {
        instance = new DifferenceDefinition();
    }

    return *instance;
}
