#include "cas-proto/DifferenceDefinition.h"



CAS_PROTO_API DifferenceDefinition::DifferenceDefinition()
    : FunctionDefinition(2)
{}

CAS_PROTO_API DifferenceDefinition& DifferenceDefinition::getInstance()
{
    static DifferenceDefinition* instance = 0;

    if (!instance) {
        instance = new DifferenceDefinition();
    }

    return *instance;
}
