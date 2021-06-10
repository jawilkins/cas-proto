#pragma once
#ifndef Rational_h
#define Rational_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifndef Natural_h
#include "Natural.h"
#endif



class Rational : public Constant {

public:

    CAS_PROTO_API static Rational& Create(int, int);

    CAS_PROTO_API Rational& Copy() const;

    CAS_PROTO_API Natural& Deriv(const Variable&) const;

    CAS_PROTO_API std::string toString() const;

    CAS_PROTO_API int getNumerator() const;
    CAS_PROTO_API int getDenominator() const;

    CAS_PROTO_API ExpressionBase& Simplify() const;

protected:

    CAS_PROTO_API Rational(int, int);

private:

    Rational(const Rational&);            // not implemented
    Rational& operator=(const Rational&); // not implemented

    int n, d;

};



#endif // Rational_h
