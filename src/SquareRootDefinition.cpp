#include "cas-proto/SquareRootDefinition.h"



CAS_PROTO_API SquareRootDefinition::SquareRootDefinition()
    : FunctionDefinition(1)
{}

CAS_PROTO_API SquareRootDefinition& SquareRootDefinition::getInstance()
{
    static SquareRootDefinition* instance = 0;

    if (!instance) {
        instance = new SquareRootDefinition();
    }

    return *instance;
}
