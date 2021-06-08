#ifndef Product_h
#define Product_h

#ifndef Sum_h
#include "Sum.h"
#endif



class Product : public BinaryOperator {

public:

    static Product& Create();
    static Product& Create(const ExpressionBase&, const ExpressionBase&);

    const ExpressionBase& getMultiplier() const;
    const ExpressionBase& getMultiplicand() const;

    const void bindMultiplier(const ExpressionBase&);
    const void bindMultiplicand(const ExpressionBase&);

    Sum& Deriv(const Variable& variable) const;

    ExpressionBase& Simplify() const;

    std::string toString() const;

    ExpressionBase& Multiply() const;

protected:

    Product(const ExpressionBase**);

private:

    Product(const Product&); // not implememented
    Product& operator = (const Product&); // not implemented

    static FunctionSymbol& symbol;

};



#endif
