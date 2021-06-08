#ifndef ExpressionBase_h
#define ExpressionBase_h

#include "Object.h"

class Variable;



class ExpressionBase : public Object {

public:

    virtual ExpressionBase& Copy() const = 0;

    //virtual void Accept(ExpressionVisitor&) = 0;

    virtual ExpressionBase& Deriv(const Variable&) const = 0;

    virtual std::string toString() const = 0;

    virtual ExpressionBase& Simplify() const;

    virtual bool IsSame(const ExpressionBase&) const = 0;

    virtual ExpressionBase& Substitute(const Variable&, const ExpressionBase&) const;

    //virtual const class SymbolBase& getSymbol() const = 0;

    //virtual ExpressionBase& Limit(const Variable&, const Constant&) = 0;

protected:

    ExpressionBase();

    virtual ~ExpressionBase();

private:

    ExpressionBase(const ExpressionBase&); // not implemented
    ExpressionBase& operator = (const ExpressionBase&); // not implemented

    static Stat stat;

};



#endif
