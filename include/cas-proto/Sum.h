#pragma once
#ifndef Sum_h
#define Sum_h

#ifndef BinaryOperator_h
#include "BinaryOperator.h"
#endif



class Sum : public BinaryOperator {

public:

    CAS_PROTO_API static Sum& Create();
    CAS_PROTO_API static Sum& Create(const ExpressionBase&, const ExpressionBase&);

    CAS_PROTO_API const ExpressionBase& getAddend() const;
    CAS_PROTO_API const ExpressionBase& getAugend() const;

    CAS_PROTO_API const void bindAddend(const ExpressionBase&);
    CAS_PROTO_API const void bindAugend(const ExpressionBase&);

    CAS_PROTO_API Sum& Deriv(const Variable& variable) const;

    CAS_PROTO_API ExpressionBase& Simplify() const;

protected:

    CAS_PROTO_API explicit Sum(const ExpressionBase**);

private:

    Sum(const Sum&);            // not implemented
    Sum& operator=(const Sum&); // not implemented

    static FunctionSymbol& symbol;

};



#endif // Sum_h
