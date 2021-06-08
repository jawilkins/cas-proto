#include "cas-proto/OneDefinition.h"



CAS_PROTO_API OneDefinition::OneDefinition()
    : ConstantDefinition()
{}

CAS_PROTO_API OneDefinition& OneDefinition::getInstance()
{
    static OneDefinition* instance = 0;

    if (!instance) {
        instance = new OneDefinition();
    }

    return *instance;
}
