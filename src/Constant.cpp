#include "cas-proto/Constant.h"

#include "cas-proto/ConstantSymbol.h"
#include "cas-proto/Natural.h"
#include "cas-proto/ImaginaryDefinition.h"

using std::string;



static ConstantSymbol& imaginary_symbol = ConstantSymbol::Create("\xAD", ImaginaryDefinition::getInstance());



Constant& Constant::Create(const ConstantSymbol& symbol)
{
    return *(new Constant(symbol));
}

Constant::Constant(const ConstantSymbol& symbol)
    : Expression<Constant, ConstantSymbol, ConstantDefinition>(symbol)
{}

Constant& Constant::Copy() const
{
    return Create(getSymbol());
}

Constant& Constant::Deriv(const Variable&) const
{
    return Natural::Create(0);
}

Constant& Constant::getImaginary()
{
    return Create(imaginary_symbol);
}

string Constant::toString() const
{
    return getSymbol().getLexeme();
}
