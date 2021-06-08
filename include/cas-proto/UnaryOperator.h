#ifndef UnaryOperator_h
#define UnaryOperator_h

#ifndef Function_h
#include "Function.h"
#endif



class UnaryOperator : public Function {

public:

    static UnaryOperator& Create(const FunctionSymbol&, const ExpressionBase&);
    static UnaryOperator& Create(const FunctionSymbol&);
    static UnaryOperator& Create(const std::string&, const ExpressionBase&);
    static UnaryOperator& Create(const std::string&);
    static UnaryOperator& Create();

    const ExpressionBase& get() const;

    const void bind(const ExpressionBase&);

    UnaryOperator& Copy() const;

    //void Accept(ExpressionVisitor&);

    UnaryOperator& Substitute(const Variable&, const ExpressionBase&) const;

    std::string toString() const;

protected:

    UnaryOperator(const FunctionSymbol&, const ExpressionBase**);

private:

    UnaryOperator(const UnaryOperator&); // not implememented
    UnaryOperator& operator = (const UnaryOperator&); // not implemented

};



#endif
