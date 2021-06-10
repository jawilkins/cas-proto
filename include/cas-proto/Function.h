#pragma once
#ifndef Function_h
#define Function_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifndef Expression_h
#include "Expression.h"
#endif

#ifndef FunctionSymbol_h
#include "FunctionSymbol.h"
#endif

#ifndef FunctionDefinition_h
#include "FunctionDefinition.h"
#endif

#ifndef Constant_h
#include "Constant.h"
#endif

class Variable;



class Function : public Expression<Function, FunctionSymbol, FunctionDefinition> {

public:

    CAS_PROTO_API static Function& Create(const FunctionSymbol&, const ExpressionBase**);
    CAS_PROTO_API static Function& Create(const std::string&, const ExpressionBase**);
    CAS_PROTO_API static Function& Create(const ExpressionBase**);

    CAS_PROTO_API Function& Copy() const;

    //CAS_PROTO_API void Accept(ExpressionVisitor&);

    CAS_PROTO_API bool IsSame(const ExpressionBase&) const;

    CAS_PROTO_API void Bind(const FunctionSymbol&);

    CAS_PROTO_API const ExpressionBase& getArgument(int) const;
    CAS_PROTO_API void bindArgument(int i, const ExpressionBase&);

    CAS_PROTO_API FunctionDefinition& getDefinition() const;
    CAS_PROTO_API int getArity() const;

    CAS_PROTO_API Function& Deriv(const Variable&) const;

    CAS_PROTO_API Function& Substitute(const Variable&, const ExpressionBase&) const;

    CAS_PROTO_API std::string toString() const;

    //CAS_PROTO_API Function& Limit(const Variable&, const Constant&);

protected:

    CAS_PROTO_API explicit Function(const FunctionSymbol&);
    CAS_PROTO_API Function(const FunctionSymbol&, const ExpressionBase**);

    CAS_PROTO_API virtual ~Function();

private:

    Function(const Function&);            // not implemented
    Function& operator=(const Function&); // not implemented

    const ExpressionBase** arguments;

};



//class Function : public ExpressionBase {
//
//public:
//
//    static Function& Create(int arity, ExpressionBase**);
//    static Function& Create(const FunctionSymbol&, ExpressionBase**);
//    static Function& Create(const std::string&, ExpressionBase**);
//
//    Function& Copy() const;
//
//    void Accept(ExpressionVisitor&);
//
//    void Bind(const FunctionSymbol&);
//
//    const FunctionSymbol& getSymbol() const;
//
//    Function* Deriv();
//    Function* Deriv(const FunctionSymbol&);
//
//    Function* Limit(Variable&, Constant&);
//    Function* Limit(const FunctionSymbol&, Variable&, Constant&);
//
//protected:
//
//    Function(int arity, ExpressionBase**);
//    Function(const FunctionSymbol&, ExpressionBase**);
//
//    ~Function();
//
//private:
//
//    Function(const Function&); // not implemented
//    Function& operator = (const Function&); // not implemented
//
//    const FunctionSymbol* symbol_ptr;
//    int arity;
//    ExpressionBase** arg;
//
//    static Stat stat;
//
//};



#endif // Function_h
