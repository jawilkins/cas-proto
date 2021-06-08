#ifndef Blank_h
#define Blank_h

#ifndef ExpressionBase_h
#include "ExpressionBase.h"
#endif



class Blank : public ExpressionBase {

public:

    static Blank& Create();

    Blank& Copy() const;

    //void Accept(ExpressionVisitor&);

    Blank& Deriv(const Variable&) const;

    //Blank& Limit(const Variable&, const Constant&);

    std::string toString() const;

    bool IsSame(const ExpressionBase&) const;

private:

    Blank();

    Blank(const Blank&); // not implemented
    Blank& operator = (const Blank&); // not implemented

};



#endif
