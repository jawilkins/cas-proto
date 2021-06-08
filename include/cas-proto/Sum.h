#ifndef Sum_h
#define Sum_h

#ifndef BinaryOperator_h
#include "BinaryOperator.h"
#endif



class Sum : public BinaryOperator {

public:

    static Sum& Create();
    static Sum& Create(const ExpressionBase&, const ExpressionBase&);

    const ExpressionBase& getAddend() const;
    const ExpressionBase& getAugend() const;

    const void bindAddend(const ExpressionBase&);
    const void bindAugend(const ExpressionBase&);

    Sum& Deriv(const Variable& variable) const;

    ExpressionBase& Simplify() const;

protected:

    Sum(const ExpressionBase**);

private:

    Sum(const Sum&); // not implememented
    Sum& operator = (const Sum&); // not implemented

    static FunctionSymbol& symbol;

};



#endif
