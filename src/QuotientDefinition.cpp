#include "cas-proto/QuotientDefinition.h"



QuotientDefinition::QuotientDefinition()
    : FunctionDefinition(2)
{}

QuotientDefinition& QuotientDefinition::getInstance()
{
    static QuotientDefinition* instance = 0;

    if (!instance) {
        instance = new QuotientDefinition();
    }

    return *instance;
}
