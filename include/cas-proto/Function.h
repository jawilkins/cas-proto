#ifndef Function_h
#define Function_h

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

    static Function& Create(const FunctionSymbol&, const ExpressionBase**);
    static Function& Create(const std::string&, const ExpressionBase**);
    static Function& Create(const ExpressionBase**);

    Function& Copy() const;

    //void Accept(ExpressionVisitor&);

    bool IsSame(const ExpressionBase&) const;

    void Bind(const FunctionSymbol&);

    const ExpressionBase& getArgument(int) const;
    void bindArgument(int i, const ExpressionBase&);

    FunctionDefinition& getDefinition() const;
    int getArity() const;

    Function& Deriv(const Variable&) const;

    Function& Substitute(const Variable&, const ExpressionBase&) const;

    std::string toString() const;

    //Function& Limit(const Variable&, const Constant&);

protected:

    Function(const FunctionSymbol&);
    Function(const FunctionSymbol&, const ExpressionBase**);

    ~Function();

private:

    Function(const Function&); // not implememented
    Function& operator = (const Function&); // not implemented

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



#endif
