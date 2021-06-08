#ifndef Exponent_h
#define Exponent_h

#ifndef Product_h
#include "Product.h"
#endif



class Exponent : public BinaryOperator {

public:

    static Exponent& Create();
    static Exponent& Create(const ExpressionBase&, const ExpressionBase&);

    static Exponent& Square(const ExpressionBase&);
    static Exponent& Root(const ExpressionBase&, int);
    static Exponent& SquareRoot(const ExpressionBase&);
    static Exponent& CubeRoot(const ExpressionBase&);

    const ExpressionBase& getBase() const;
    const ExpressionBase& getExponent() const;

    const void bindBase(const ExpressionBase&);
    const void bindExponent(const ExpressionBase&);

    Product& Deriv(const Variable& variable) const;

    ExpressionBase& Simplify() const;

    std::string toString() const;

protected:

    Exponent(const ExpressionBase**);

private:

    Exponent(const Exponent&); // not implememented
    Exponent& operator = (const Exponent&); // not implemented

    static FunctionSymbol& symbol;

};



#endif
