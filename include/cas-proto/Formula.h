#pragma once
#ifndef Formula_h
#define Formula_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifndef Function_h
#include "Function.h"
#endif



class Formula : public Function {

public:

    CAS_PROTO_API Formula(int arity, Expression[]);
    CAS_PROTO_API Formula(const Symbol&, Expression[]);

    CAS_PROTO_API virtual ~Formula();

    CAS_PROTO_API Formula* Substitute(Variable*, Formula*);
    CAS_PROTO_API Formula* Substitute(const Symbol&, Variable*, Formula*);

    CAS_PROTO_API Formula* Solve(Variable&);
    CAS_PROTO_API Formula* Solve(const Symbol&, const Symbol&, Variable&);

};



#endif // Formula_h
