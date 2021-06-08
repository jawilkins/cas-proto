#pragma once
#ifndef ExpressionBase_h
#define ExpressionBase_h

#ifndef Object_h
#include "Object.h"
#endif

class Variable;



class ExpressionBase : public Object {

public:

    CAS_PROTO_API virtual ExpressionBase& Copy() const = 0;

    //CAS_PROTO_API virtual void Accept(ExpressionVisitor&) = 0;

    CAS_PROTO_API virtual ExpressionBase& Deriv(const Variable&) const = 0;

    CAS_PROTO_API virtual std::string toString() const = 0;

    CAS_PROTO_API virtual ExpressionBase& Simplify() const;

    CAS_PROTO_API virtual bool IsSame(const ExpressionBase&) const = 0;

    CAS_PROTO_API virtual ExpressionBase& Substitute(const Variable&, const ExpressionBase&) const;

    //CAS_PROTO_API virtual const class SymbolBase& getSymbol() const = 0;

    //CAS_PROTO_API virtual ExpressionBase& Limit(const Variable&, const Constant&) = 0;

protected:

    CAS_PROTO_API ExpressionBase();

    CAS_PROTO_API virtual ~ExpressionBase();

private:

    ExpressionBase(const ExpressionBase&);            // not implemented
    ExpressionBase& operator=(const ExpressionBase&); // not implemented

    static Stat stat;

};



#endif // ExpressionBase_h
