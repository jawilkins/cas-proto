#ifndef Constant_h
#define Constant_h

#include "Expression.h"
#include "ConstantSymbol.h"
#include "ConstantDefinition.h"



class Constant : public Expression<Constant, ConstantSymbol, ConstantDefinition> {

public:

    using Expression<Constant, ConstantSymbol, ConstantDefinition>::Create;

    static Constant& Create(const ConstantSymbol& symbol);

    static Constant& getImaginary();

    Constant& Copy() const;

    Constant& Deriv(const Variable&) const;

    std::string toString() const;

protected:

    Constant(const ConstantSymbol&);

private:

    Constant(const Constant&); // not implemented
    Constant& operator = (const Constant&); // not implemented

};



#endif
