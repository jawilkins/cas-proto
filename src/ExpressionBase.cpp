#include "cas-proto/ExpressionBase.h"

#include <cassert>



Stat ExpressionBase::stat("Expression");



CAS_PROTO_API ExpressionBase::ExpressionBase()
{
    stat.Bump();
}

CAS_PROTO_API ExpressionBase::~ExpressionBase()
{
    stat.Unbump();
}

CAS_PROTO_API ExpressionBase& ExpressionBase::Simplify() const
{
    return Copy();
}

CAS_PROTO_API ExpressionBase& ExpressionBase::Substitute(const Variable&, const ExpressionBase&) const
{
    return Copy();
}
