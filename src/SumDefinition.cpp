#include "cas-proto/SumDefinition.h"



SumDefinition::SumDefinition()
    : FunctionDefinition(2)
{}

SumDefinition& SumDefinition::getInstance()
{
    static SumDefinition* instance = 0;

    if (!instance) {
        instance = new SumDefinition();
    }

    return *instance;
}
