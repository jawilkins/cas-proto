#pragma once
#ifndef Constant_h
#define Constant_h

#ifndef Expression_h
#include "Expression.h"
#endif

#ifndef ConstantSymbol_h
#include "ConstantSymbol.h"
#endif

#ifndef ConstantDefinition_h
#include "ConstantDefinition.h"
#endif



class Constant : public Expression<Constant, ConstantSymbol, ConstantDefinition> {

public:

    using Expression<Constant, ConstantSymbol, ConstantDefinition>::Create;

    CAS_PROTO_API static Constant& Create(const ConstantSymbol& symbol);

    CAS_PROTO_API static Constant& getImaginary();

    CAS_PROTO_API Constant& Copy() const;

    CAS_PROTO_API Constant& Deriv(const Variable&) const;

    CAS_PROTO_API std::string toString() const;

protected:

    CAS_PROTO_API Constant(const ConstantSymbol&);

private:

    Constant(const Constant&);            // not implemented
    Constant& operator=(const Constant&); // not implemented

};



#endif // Blank_h
