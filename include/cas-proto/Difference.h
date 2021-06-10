#pragma once
#ifndef Difference_h
#define Difference_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifndef NcBinaryOperator_h
#include "NcBinaryOperator.h"
#endif



class Difference : public NcBinaryOperator {

public:

    CAS_PROTO_API static Difference& Create();
    CAS_PROTO_API static Difference& Create(ExpressionBase&, ExpressionBase&);

    CAS_PROTO_API const ExpressionBase& getMinuend() const;
    CAS_PROTO_API const ExpressionBase& getSubtrahend() const;

    CAS_PROTO_API const void bindMinuend(const ExpressionBase&);
    CAS_PROTO_API const void bindSubtrahend(const ExpressionBase&);

    CAS_PROTO_API Difference& Deriv(const Variable& variable) const;

    CAS_PROTO_API ExpressionBase& Simplify() const;

protected:

    CAS_PROTO_API explicit Difference(const ExpressionBase**);

private:

    Difference(const Difference&);            // not implemented
    Difference& operator=(const Difference&); // not implemented

    static FunctionSymbol& symbol;

};



#endif // Difference_h
