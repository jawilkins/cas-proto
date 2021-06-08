#ifndef Variable_h
#define Variable_h

#include "Expression.h"
#include "VariableSymbol.h"
#include "VariableDefinition.h"
#include "Constant.h"



class Variable : public Expression<Variable, VariableSymbol, VariableDefinition> {

public:

    using Expression<Variable, VariableSymbol, VariableDefinition>::Create;

    static Variable& Create(const VariableSymbol& symbol);

    Variable& Copy() const;

    Constant& Deriv(const Variable&) const;

    ExpressionBase& Substitute(const Variable&, const ExpressionBase&) const;

    std::string toString() const;

    //Variable& Limit(const Variable&, const Constant&);

protected:

    Variable(const VariableSymbol&);

private:

    Variable(const Variable&); // not implemented
    Variable& operator = (const Variable&); // not implemented

};



#endif
