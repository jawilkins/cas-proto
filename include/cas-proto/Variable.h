#pragma once
#ifndef Variable_h
#define Variable_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifndef Expression_h
#include "Expression.h"
#endif

#ifndef VariableSymbol_h
#include "VariableSymbol.h"
#endif

#ifndef VariableDefinition_h
#include "VariableDefinition.h"
#endif

#ifndef Constant_h
#include "Constant.h"
#endif



class Variable : public Expression<Variable, VariableSymbol, VariableDefinition> {

public:

    using Expression<Variable, VariableSymbol, VariableDefinition>::Create;

    CAS_PROTO_API static Variable& Create(const VariableSymbol& symbol);

    CAS_PROTO_API Variable& Copy() const;

    CAS_PROTO_API Constant& Deriv(const Variable&) const;

    CAS_PROTO_API ExpressionBase& Substitute(const Variable&, const ExpressionBase&) const;

    CAS_PROTO_API std::string toString() const;

    //CAS_PROTO_API Variable& Limit(const Variable&, const Constant&);

protected:

    CAS_PROTO_API explicit Variable(const VariableSymbol&);

private:

    Variable(const Variable&);            // not implemented
    Variable& operator=(const Variable&); // not implemented

};



#endif // Variable_h
