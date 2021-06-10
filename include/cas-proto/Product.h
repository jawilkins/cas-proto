#pragma once
#ifndef Product_h
#define Product_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifndef Sum_h
#include "Sum.h"
#endif



class Product : public BinaryOperator {

public:

    CAS_PROTO_API static Product& Create();
    CAS_PROTO_API static Product& Create(const ExpressionBase&, const ExpressionBase&);

    CAS_PROTO_API const ExpressionBase& getMultiplier() const;
    CAS_PROTO_API const ExpressionBase& getMultiplicand() const;

    CAS_PROTO_API const void bindMultiplier(const ExpressionBase&);
    CAS_PROTO_API const void bindMultiplicand(const ExpressionBase&);

    CAS_PROTO_API Sum& Deriv(const Variable& variable) const;

    CAS_PROTO_API ExpressionBase& Simplify() const;

    CAS_PROTO_API std::string toString() const;

    CAS_PROTO_API ExpressionBase& Multiply() const;

protected:

    CAS_PROTO_API explicit Product(const ExpressionBase**);

private:

    Product(const Product&);            // not implemented
    Product& operator=(const Product&); // not implemented

    static FunctionSymbol& symbol;

};



#endif // Product_h
