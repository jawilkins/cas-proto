#pragma once
#ifndef NcBinaryOperator_h
#define NcBinaryOperator_h

#ifndef BinaryOperator_h
#include "BinaryOperator.h"
#endif



class NcBinaryOperator : public BinaryOperator {

public:

    CAS_PROTO_API static NcBinaryOperator& Create(const FunctionSymbol&, int, const ExpressionBase&, const ExpressionBase&);
    CAS_PROTO_API static NcBinaryOperator& Create(const FunctionSymbol&, int);
    CAS_PROTO_API static NcBinaryOperator& Create(const std::string&, int, const ExpressionBase&, const ExpressionBase&);
    CAS_PROTO_API static NcBinaryOperator& Create(const std::string&, int);
    CAS_PROTO_API static NcBinaryOperator& Create(int);

    CAS_PROTO_API NcBinaryOperator& Copy() const;

    //CAS_PROTO_API void Accept(ExpressionVisitor&);

    CAS_PROTO_API std::string toString() const;

protected:

    CAS_PROTO_API NcBinaryOperator(const FunctionSymbol&, int, const ExpressionBase**);

private:

    CAS_PROTO_API NcBinaryOperator(const NcBinaryOperator&);            // not implemented
    CAS_PROTO_API NcBinaryOperator& operator=(const NcBinaryOperator&); // not implemented

};



#endif // NcBinaryOperator_h
