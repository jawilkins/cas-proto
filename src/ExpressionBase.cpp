#include "cas-proto/ExpressionBase.h"

#include <assert.h>



Stat ExpressionBase::stat("Expression");



ExpressionBase::ExpressionBase()
{
    stat.Bump();
}

ExpressionBase::~ExpressionBase()
{
    stat.Unbump();
}

ExpressionBase& ExpressionBase::Simplify() const
{
    return Copy();
}

ExpressionBase& ExpressionBase::Substitute(const Variable&, const ExpressionBase&) const
{
    return Copy();
}

