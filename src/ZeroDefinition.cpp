#include "cas-proto/ZeroDefinition.h"



ZeroDefinition::ZeroDefinition()
    : ConstantDefinition()
{}

ZeroDefinition& ZeroDefinition::getInstance()
{
    static ZeroDefinition* instance = 0;

    if (!instance) {
        instance = new ZeroDefinition();
    }

    return *instance;
}
