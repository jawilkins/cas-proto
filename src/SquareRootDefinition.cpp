#include "cas-proto/SquareRootDefinition.h"



SquareRootDefinition::SquareRootDefinition()
    : FunctionDefinition(1)
{}

SquareRootDefinition& SquareRootDefinition::getInstance()
{
    static SquareRootDefinition* instance = 0;

    if (!instance) {
        instance = new SquareRootDefinition();
    }

    return *instance;
}
