#include "cas-proto/ProductDefinition.h"



ProductDefinition::ProductDefinition()
    : FunctionDefinition(2)
{}

ProductDefinition& ProductDefinition::getInstance()
{
    static ProductDefinition* instance = 0;

    if (!instance) {
        instance = new ProductDefinition();
    }

    return *instance;
}
