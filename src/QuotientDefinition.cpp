#include "cas-proto/QuotientDefinition.h"



CAS_PROTO_API QuotientDefinition::QuotientDefinition()
    : FunctionDefinition(2)
{}

CAS_PROTO_API QuotientDefinition& QuotientDefinition::getInstance()
{
    static QuotientDefinition* instance = 0;

    if (!instance) {
        instance = new QuotientDefinition();
    }

    return *instance;
}
