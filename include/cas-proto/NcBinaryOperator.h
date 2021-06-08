#ifndef NcBinaryOperator_h
#define NcBinaryOperator_h

#ifndef BinaryOperator_h
#include "BinaryOperator.h"
#endif



class NcBinaryOperator : public BinaryOperator {

public:

    static NcBinaryOperator& Create(const FunctionSymbol&, int, const ExpressionBase&, const ExpressionBase&);
    static NcBinaryOperator& Create(const FunctionSymbol&, int);
    static NcBinaryOperator& Create(const std::string&, int, const ExpressionBase&, const ExpressionBase&);
    static NcBinaryOperator& Create(const std::string&, int);
    static NcBinaryOperator& Create(int);

    NcBinaryOperator& Copy() const;

    //void Accept(ExpressionVisitor&);

    std::string toString() const;

protected:

    NcBinaryOperator(const FunctionSymbol&, int, const ExpressionBase**);

private:

    NcBinaryOperator(const NcBinaryOperator&); // not implememented
    NcBinaryOperator& operator = (const NcBinaryOperator&); // not implemented

};



#endif
