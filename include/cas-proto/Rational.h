#ifndef Rational_h
#define Rational_h

#ifndef Natural_h
#include "Natural.h"
#endif



class Rational : public Constant {

public:

    static Rational& Create(int, int);

    Rational& Copy() const;

    Natural& Deriv(const Variable&) const;

    std::string toString() const;

    int getNumerator() const;
    int getDenominator() const;

    ExpressionBase& Simplify() const;

protected:

    Rational(int, int);

private:

    Rational(const Rational&); // not implemented
    Rational& operator = (const Rational&); // not implemented

    int n, d;

};



#endif
