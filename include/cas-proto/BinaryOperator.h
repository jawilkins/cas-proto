#ifndef BinaryOperator_h
#define BinaryOperator_h

#ifndef Function_h
#include "Function.h"
#endif



class BinaryOperator : public Function {

public:

    static BinaryOperator& Create(const FunctionSymbol&, int, const ExpressionBase&, const ExpressionBase&);
    static BinaryOperator& Create(const FunctionSymbol&, int);
    static BinaryOperator& Create(const std::string&, int, const ExpressionBase&, const ExpressionBase&);
    static BinaryOperator& Create(const std::string&, int);
    static BinaryOperator& Create(int);

    const ExpressionBase& getA() const;
    const ExpressionBase& getB() const;

    const void bindA(const ExpressionBase&);
    const void bindB(const ExpressionBase&);

    BinaryOperator& Copy() const;

    //void Accept(ExpressionVisitor&);

    BinaryOperator& Substitute(const Variable&, const ExpressionBase&) const;

    std::string toString() const;

    int getPrecedence() const;
    int getMinPrecedence() const;

    const ExpressionBase& getRightmostTerm() const;
    const ExpressionBase& getLeftmostTerm() const;

protected:

    BinaryOperator(const FunctionSymbol&, int, const ExpressionBase**);

private:

    BinaryOperator(const BinaryOperator&); // not implememented
    BinaryOperator& operator = (const BinaryOperator&); // not implemented

    int precedence;

};



#endif
