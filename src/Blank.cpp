#include "cas-proto/Blank.h"

#include "cas-proto/ExpressionVisitor.h"

using std::string;



Blank& Blank::Create()
{
    return *(new Blank());
}

Blank::Blank()
    : ExpressionBase()
{}

Blank& Blank::Copy() const
{
    return Create();
}

//void Blank::Accept(ExpressionVisitor& visitor)
//{
//    visitor.visit(*this);
//}

Blank& Blank::Deriv(const Variable&) const
{
    return Copy();
}

//Blank& Blank::Limit(const Variable&, const Constant&)
//{
//    return Copy();
//}

string Blank::toString() const
{
    return "_";
}

bool Blank::IsSame(const ExpressionBase& rhs) const
{
    const Blank* b = dynamic_cast<const Blank*>(&rhs);

    return b != 0;
}
