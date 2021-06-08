#pragma once
#ifndef Natural_h
#define Natural_h

#ifndef Constant_h
#include "Constant.h"
#endif



class Natural : public Constant {

public:

    CAS_PROTO_API static Natural& Create(int);

    CAS_PROTO_API Natural& Copy() const;

    CAS_PROTO_API Natural& Deriv(const Variable&) const;

    CAS_PROTO_API std::string toString() const;

    CAS_PROTO_API int get() const;

protected:

    CAS_PROTO_API Natural(int n);

private:

    Natural(const Natural&);            // not implemented
    Natural& operator=(const Natural&); // not implemented

    int n;

};



#endif // Natural_h
