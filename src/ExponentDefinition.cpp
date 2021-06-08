#include "cas-proto/ExponentDefinition.h"



CAS_PROTO_API ExponentDefinition::ExponentDefinition()
    : FunctionDefinition(2)
{}

CAS_PROTO_API ExponentDefinition& ExponentDefinition::getInstance()
{
    static ExponentDefinition* instance = 0;

    if (!instance) {
        instance = new ExponentDefinition();
    }

    return *instance;
}
