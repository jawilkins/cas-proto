#include "cas-proto/TwoDefinition.h"



CAS_PROTO_API TwoDefinition::TwoDefinition()
    : ConstantDefinition()
{}

CAS_PROTO_API TwoDefinition& TwoDefinition::getInstance()
{
    static TwoDefinition* instance = 0;

    if (!instance) {
        instance = new TwoDefinition();
    }

    return *instance;
}
