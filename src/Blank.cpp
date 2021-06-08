#include "cas-proto/Blank.h"

#ifndef ExpressionVisitor_h
#include "cas-proto/ExpressionVisitor.h"
#endif



CAS_PROTO_API Blank& Blank::Create()
{
    return *(new Blank());
}

CAS_PROTO_API Blank::Blank()
    : ExpressionBase()
{}

CAS_PROTO_API Blank& Blank::Copy() const
{
    return Create();
}

//CAS_PROTO_API void Blank::Accept(ExpressionVisitor& visitor)
//{
//    visitor.visit(*this);
//}

CAS_PROTO_API Blank& Blank::Deriv(const Variable&) const
{
    return Copy();
}

//CAS_PROTO_API Blank& Blank::Limit(const Variable&, const Constant&)
//{
//    return Copy();
//}

CAS_PROTO_API std::string Blank::toString() const
{
    return "_";
}

CAS_PROTO_API bool Blank::IsSame(const ExpressionBase& rhs) const
{
    const Blank* b = dynamic_cast<const Blank*>(&rhs);

    return b != NULL;
}
