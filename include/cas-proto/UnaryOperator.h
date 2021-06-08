#ifndef UnaryOperator_h
#define UnaryOperator_h

#ifndef Function_h
#include "Function.h"
#endif



class UnaryOperator : public Function {

public:

    CAS_PROTO_API static UnaryOperator& Create(const FunctionSymbol&, const ExpressionBase&);
    CAS_PROTO_API static UnaryOperator& Create(const FunctionSymbol&);
    CAS_PROTO_API static UnaryOperator& Create(const std::string&, const ExpressionBase&);
    CAS_PROTO_API static UnaryOperator& Create(const std::string&);
    CAS_PROTO_API static UnaryOperator& Create();

    CAS_PROTO_API const ExpressionBase& get() const;

    CAS_PROTO_API const void bind(const ExpressionBase&);

    CAS_PROTO_API UnaryOperator& Copy() const;

    //CAS_PROTO_API void Accept(ExpressionVisitor&);

    CAS_PROTO_API UnaryOperator& Substitute(const Variable&, const ExpressionBase&) const;

    CAS_PROTO_API std::string toString() const;

protected:

    CAS_PROTO_API UnaryOperator(const FunctionSymbol&, const ExpressionBase**);

private:

    UnaryOperator(const UnaryOperator&);            // not implemented
    UnaryOperator& operator=(const UnaryOperator&); // not implemented

};



#endif // UnaryOperator_h
