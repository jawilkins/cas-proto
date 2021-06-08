#include "cas-proto/Constant.h"

#ifndef ConstantSymbol_h
#include "cas-proto/ConstantSymbol.h"
#endif

#ifndef Natural_h
#include "cas-proto/Natural.h"
#endif

#ifndef ImaginaryDefinition_h
#include "cas-proto/ImaginaryDefinition.h"
#endif



static ConstantSymbol& imaginary_symbol = ConstantSymbol::Create("\xAD", ImaginaryDefinition::getInstance());



CAS_PROTO_API Constant& Constant::Create(const ConstantSymbol& symbol)
{
    return *(new Constant(symbol));
}

CAS_PROTO_API Constant::Constant(const ConstantSymbol& symbol)
    : Expression<Constant, ConstantSymbol, ConstantDefinition>(symbol)
{}

CAS_PROTO_API Constant& Constant::Copy() const
{
    return Create(getSymbol());
}

CAS_PROTO_API Constant& Constant::Deriv(const Variable&) const
{
    return Natural::Create(0);
}

CAS_PROTO_API Constant& Constant::getImaginary()
{
    return Create(imaginary_symbol);
}

CAS_PROTO_API std::string Constant::toString() const
{
    return getSymbol().getLexeme();
}
