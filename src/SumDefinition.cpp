#include "cas-proto/SumDefinition.h"



CAS_PROTO_API SumDefinition::SumDefinition()
    : FunctionDefinition(2)
{}

CAS_PROTO_API SumDefinition& SumDefinition::getInstance()
{
    static SumDefinition* instance = 0;

    if (!instance) {
        instance = new SumDefinition();
    }

    return *instance;
}
