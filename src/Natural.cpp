#include "cas-proto/Natural.h"

using std::string;

#include <sstream>
using std::stringstream;



static const ConstantSymbol& lookup(const string& s)
{
    static int size = 0;
    static int next = 0;
    static const ConstantSymbol** table = 0;

    for (int n = 0; n < next; n++) {
        if (table[n]->getLexeme() == s) return *table[n];
    }

    if (next == size) {
        size += 10;
        const ConstantSymbol** temp = new const ConstantSymbol*[size];

        for (int n = 0; n < next; n++) {
            temp[n]  = table[n];
            table[n] = 0;
        }

        delete [] table;

        table = temp;
    }

    const ConstantSymbol& rv = ConstantSymbol::Create(s);

    table[next++] = &rv;

    return rv;
}

static const ConstantSymbol& lookup(int n)
{
    assert(n >= 0);

    stringstream ss;
    ss << n;

    return lookup(ss.str());
}

Natural& Natural::Create(int n)
{
    return *(new Natural(n));
}

Natural::Natural(int n)
    : Constant(lookup(n))
    , n(n)
{}

Natural& Natural::Copy() const
{
    return Create(n);
}

Natural& Natural::Deriv(const Variable&) const
{
    return Create(0);
}

string Natural::toString() const
{
    return getSymbol().getLexeme();
}

int Natural::get() const
{
    return n;
}
