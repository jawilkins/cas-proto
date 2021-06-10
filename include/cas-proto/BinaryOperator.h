#pragma once
#ifndef BinaryOperator_h
#define BinaryOperator_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifndef Function_h
#include "Function.h"
#endif



class BinaryOperator : public Function {

public:

    CAS_PROTO_API static BinaryOperator& Create(const FunctionSymbol&, int, const ExpressionBase&, const ExpressionBase&);
    CAS_PROTO_API static BinaryOperator& Create(const FunctionSymbol&, int);
    CAS_PROTO_API static BinaryOperator& Create(const std::string&, int, const ExpressionBase&, const ExpressionBase&);
    CAS_PROTO_API static BinaryOperator& Create(const std::string&, int);
    CAS_PROTO_API static BinaryOperator& Create(int);

    CAS_PROTO_API const ExpressionBase& getA() const;
    CAS_PROTO_API const ExpressionBase& getB() const;

    CAS_PROTO_API const void bindA(const ExpressionBase&);
    CAS_PROTO_API const void bindB(const ExpressionBase&);

    CAS_PROTO_API BinaryOperator& Copy() const;

    //CAS_PROTO_API void Accept(ExpressionVisitor&);

    CAS_PROTO_API BinaryOperator& Substitute(const Variable&, const ExpressionBase&) const;

    CAS_PROTO_API std::string toString() const;

    CAS_PROTO_API int getPrecedence() const;
    CAS_PROTO_API int getMinPrecedence() const;

    CAS_PROTO_API const ExpressionBase& getRightmostTerm() const;
    CAS_PROTO_API const ExpressionBase& getLeftmostTerm() const;

protected:

    CAS_PROTO_API BinaryOperator(const FunctionSymbol&, int, const ExpressionBase**);

private:

    BinaryOperator(const BinaryOperator&);            // not implemented
    BinaryOperator& operator=(const BinaryOperator&); // not implemented

    int precedence;

};



#endif // BinaryOperator_h
