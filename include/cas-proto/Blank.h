#pragma once
#ifndef Blank_h
#define Blank_h

#ifndef ExpressionBase_h
#include "ExpressionBase.h"
#endif



class Blank : public ExpressionBase {

public:

    CAS_PROTO_API static Blank& Create();

    CAS_PROTO_API Blank& Copy() const;

    //CAS_PROTO_API void Accept(ExpressionVisitor&);

    CAS_PROTO_API Blank& Deriv(const Variable&) const;

    //CAS_PROTO_API Blank& Limit(const Variable&, const Constant&);

    CAS_PROTO_API std::string toString() const;

    CAS_PROTO_API bool IsSame(const ExpressionBase&) const;

private:

    CAS_PROTO_API Blank();

    Blank(const Blank&);            // not implemented
    Blank& operator=(const Blank&); // not implemented

};



#endif // Blank_h
