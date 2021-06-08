#include "cas-proto/ZeroDefinition.h"



CAS_PROTO_API ZeroDefinition::ZeroDefinition()
    : ConstantDefinition()
{}

CAS_PROTO_API ZeroDefinition& ZeroDefinition::getInstance()
{
    static ZeroDefinition* instance = 0;

    if (!instance) {
        instance = new ZeroDefinition();
    }

    return *instance;
}
