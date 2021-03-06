#include "cas-proto/Rational.h"

#include <sstream>



static const ConstantSymbol& lookup(const std::string& s)
{
    static int size = 0;
    static int next = 0;
    static const ConstantSymbol** table = 0;

    for (int i = 0; i < next; i++) {
        if (table[i]->getLexeme() == s) return *table[i];
    }

    if (next == size) {
        size += 10;
        const ConstantSymbol** temp = new const ConstantSymbol*[size];

        for (int i = 0; i < next; i++) {
            temp[i]  = table[i];
            table[i] = 0;
        }

        delete [] table;

        table = temp;
    }

    const ConstantSymbol& rv = ConstantSymbol::Create(s);

    table[next++] = &rv;

    return rv;
}

int gcd(int m, int n)
{
    assert(m > 0);
    assert(n > 0);

    while(m > 0) {
        if( n > m ) {
            int t = m;
            m = n;
            n = t;
        }

        m -= n;
    }

    return n;
}

static const ConstantSymbol& lookup(int n, int d)
{
    assert(d > 0);
    assert(n >= 0);

    std::stringstream ss;

    if (n == 1 && d == 2) {
        ss << "\xAB";
    }
    else if (n == 1 && d == 4) {
        ss << "\xAC";
    }
    else {
        ss << n << '/' << d;
    }

    return lookup(ss.str());
}

CAS_PROTO_API Rational& Rational::Create(int n, int d)
{
    return *(new Rational(n, d));
}

CAS_PROTO_API Rational::Rational(int n, int d)
    : Constant(lookup(n, d))
    , n(n)
    , d(d)
{}

CAS_PROTO_API Rational& Rational::Copy() const
{
    return Create(n, d);
}

CAS_PROTO_API Natural& Rational::Deriv(const Variable&) const
{
    return Natural::Create(0);
}

CAS_PROTO_API std::string Rational::toString() const
{
    return getSymbol().getLexeme();
}

CAS_PROTO_API ExpressionBase& Rational::Simplify() const
{
   const int g = gcd(n, d);

   const int sn = n / g;
   const int sd = d / g;

   if (1 == sd) {
       return Natural::Create(sn);
   }
   else if (0 == sn) {
       return Natural::Create(0);
   }
   else if (sn == sd) {
       return Natural::Create(1);
   }
   else {
       return Create(sn, sd);
   }
}

CAS_PROTO_API int Rational::getNumerator() const
{
    return n;
}

CAS_PROTO_API int Rational::getDenominator() const
{
    return d;
}
