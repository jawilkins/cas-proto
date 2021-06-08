#ifndef Expression_h
#define Expression_h

#include "ExpressionBase.h"



template <class P, class S, class D>
class Expression : public ExpressionBase {

public:

    static P& Create(const std::string&, D&);
    static P& Create(const std::string&);
    static P& Create();

    //void Accept(ExpressionVisitor&);

    virtual void Bind(const S&);

    const S& getSymbol() const;
    std::string getLexeme() const;

    bool IsSame(const ExpressionBase&) const;
    //bool IsSame(const P&) const;

protected:

    explicit Expression<P, S, D>(const S&);

    ~Expression<P, S, D>();

private:

    Expression<P, S, D>(const Expression<P, S, D>&); // not implemented
    Expression<P, S, D>& operator = (const Expression<P, S, D>&); // not implemented

    const S* symbol_ptr;

};



#include "Expression.hpp"



#endif
