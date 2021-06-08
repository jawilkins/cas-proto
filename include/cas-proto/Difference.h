#ifndef Difference_h
#define Difference_h

#ifndef NcBinaryOperator_h
#include "NcBinaryOperator.h"
#endif



class Difference : public NcBinaryOperator {

public:

    static Difference& Create();
    static Difference& Create(ExpressionBase&, ExpressionBase&);

    const ExpressionBase& getMinuend() const;
    const ExpressionBase& getSubtrahend() const;

    const void bindMinuend(const ExpressionBase&);
    const void bindSubtrahend(const ExpressionBase&);

    Difference& Deriv(const Variable& variable) const;

    ExpressionBase& Simplify() const;

protected:

    Difference(const ExpressionBase**);

private:

    Difference(const Difference&); // not implememented
    Difference& operator = (const Difference&); // not implemented

    static FunctionSymbol& symbol;

};



#endif
