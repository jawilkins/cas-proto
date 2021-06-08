#include "cas-proto/Function.h"

#ifndef Blank_h
#include "cas-proto/Blank.h"
#endif



CAS_PROTO_API Function& Function::Create(const FunctionSymbol& symbol, const ExpressionBase** arguments)
{
    return *(new Function(symbol, arguments));
}

CAS_PROTO_API Function& Function::Create(const std::string& lexeme, const ExpressionBase** arguments)
{
    return Create(FunctionSymbol::Create(lexeme), arguments);
}

CAS_PROTO_API Function& Function::Create(const ExpressionBase** arguments)
{
    return Create(FunctionSymbol::Create(), arguments);
}

CAS_PROTO_API Function::Function(const FunctionSymbol& symbol_)
    : Expression<Function, FunctionSymbol, FunctionDefinition>(symbol_)
    , arguments(new const ExpressionBase*[getArity()])
{
    assert(arguments != NULL);

    for (int i = 0; i < getArity(); i++) {
        arguments[i] = &Blank::Create();
        arguments[i]->Acquire();
    }
}

CAS_PROTO_API Function::Function(const FunctionSymbol& symbol, const ExpressionBase* arguments_[])
    : Expression<Function, FunctionSymbol, FunctionDefinition>(symbol)
    , arguments(new const ExpressionBase*[getArity()])
{
    assert(arguments != NULL);

    for (int i = 0; i < getArity(); i++) {
        arguments[i] = arguments_[i];
        arguments[i]->Acquire();
    }
}

CAS_PROTO_API Function::~Function()
{
    for (int i = 0; i < getArity(); i++) {
        arguments[i]->Release();
        arguments[i] = 0;
    }

    delete [] arguments;
    arguments = 0;
}

CAS_PROTO_API Function& Function::Copy() const
{
    return Create(getSymbol(), arguments);
}

CAS_PROTO_API void Function::Bind(const FunctionSymbol& rhs)
{
    assert(!(getDefinition().IsSame(FunctionDefinition::undef) || getDefinition().getArity() == rhs.getDefinition().getArity()));

    Expression<Function, FunctionSymbol, FunctionDefinition>::Bind(rhs);
}

CAS_PROTO_API const ExpressionBase& Function::getArgument(int i) const
{
    assert(i >= 0);
    assert(i < getArity());

    return *arguments[i];
}

CAS_PROTO_API void Function::bindArgument(int i, const ExpressionBase& argument)
{
    assert(i >= 0);
    assert(i < getArity());

    arguments[i]->Release();
    arguments[i] = &argument;
    arguments[i]->Acquire();
}

CAS_PROTO_API FunctionDefinition& Function::getDefinition() const
{
    return getSymbol().getDefinition();
}

CAS_PROTO_API int Function::getArity() const
{
    return getSymbol().getDefinition().getArity();
}

//CAS_PROTO_API void Function::Accept(ExpressionVisitor& visitor)
//{
//    visitor.visit(*this);
//}

CAS_PROTO_API Function& Function::Deriv(const Variable& v) const
{
    assert(false);
    throw 0;
}

CAS_PROTO_API std::string Function::toString() const{
    bool is_first = true;
    std::string rv = getSymbol().getLexeme() + "(";

    for (int i = 0; i < getArity(); i++) {
        if (!is_first) {
            rv = rv + ",";
        } else {
            is_first = false;
        }

        rv = rv + getArgument(i).toString();
    }

    return rv + ")";
}

CAS_PROTO_API Function& Function::Substitute(const Variable& variable, const ExpressionBase& substitution) const
{
    const int n = getArity();
    const ExpressionBase** subst_args = new const ExpressionBase*[n];

    for (int i = 0; i < n; i++) {
        subst_args[i] = &(getArgument(i).Substitute(variable, substitution));
    }

    Function& rv = Function::Create(getSymbol(), subst_args);

    delete [] subst_args;

    return rv;
}

CAS_PROTO_API bool Function::IsSame(const ExpressionBase& rhs) const
{
    const Function* f = dynamic_cast<const Function*>(&rhs);

    if (f && getArity() == f->getArity()) {
        for (int i = 0; i < getArity(); i++) {
            if (!getArgument(i).IsSame(f->getArgument(i))) {
                return false;
            }
        }

        return true;
    }

    return false;
}
