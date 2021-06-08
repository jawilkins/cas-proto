#ifndef Formula_h
#define Formula_h

#ifndef Function_h
#include "Function.h"
#endif

class Formula : public Function {

public:

    Formula(int arity, Expression[]);
    Formula(const Symbol&, Expression[]);

    ~Formula();

    Formula* Substitute(Variable*, Formula*);
    Formula* Substitute(const Symbol&, Variable*, Formula*);

    Formula* Solve(Variable&);
    Formula* Solve(const Symbol&, const Symbol&, Variable&);

};

#endif
