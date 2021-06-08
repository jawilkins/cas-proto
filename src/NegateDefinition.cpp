#include "cas-proto/NegateDefinition.h"



NegateDefinition::NegateDefinition()
    : FunctionDefinition(1)
{}

NegateDefinition& NegateDefinition::getInstance()
{
    static NegateDefinition* instance = 0;

    if (!instance) {
        instance = new NegateDefinition();
    }

    return *instance;
}
