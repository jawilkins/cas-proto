#include "cas-proto/ProductDefinition.h"



CAS_PROTO_API ProductDefinition::ProductDefinition()
    : FunctionDefinition(2)
{}

CAS_PROTO_API ProductDefinition& ProductDefinition::getInstance()
{
    static ProductDefinition* instance = 0;

    if (!instance) {
        instance = new ProductDefinition();
    }

    return *instance;
}
