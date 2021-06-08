#include "cas-proto/Function.h"

#include "cas-proto/Blank.h"

using std::string;



Function& Function::Create(const FunctionSymbol& symbol, const ExpressionBase** arguments)
{
    return *(new Function(symbol, arguments));
}

Function& Function::Create(const std::string& lexeme, const ExpressionBase** arguments)
{
    return Create(FunctionSymbol::Create(lexeme), arguments);
}

Function& Function::Create(const ExpressionBase** arguments)
{
    return Create(FunctionSymbol::Create(), arguments);
}

Function::Function(const FunctionSymbol& symbol)
    : Expression<Function, FunctionSymbol, FunctionDefinition>(symbol)
    , arguments(new const ExpressionBase*[symbol.getDefinition().getArity()])
{
    for (int i = 0; i < getArity(); i++) {
        arguments[i] = &Blank::Create();
        arguments[i]->Acquire();
    }
}

Function::Function(const FunctionSymbol& symbol, const ExpressionBase* arguments[])
    : Expression<Function, FunctionSymbol, FunctionDefinition>(symbol)
    , arguments(new const ExpressionBase*[symbol.getDefinition().getArity()])
{
    for (int i = 0; i < getArity(); i++) {
        this->arguments[i] = arguments[i];
        this->arguments[i]->Acquire();
    }
}

Function::~Function()
{
    for (int i = 0; i < getArity(); i++) {
        arguments[i]->Release();
        arguments[i] = 0;
    }

    delete [] arguments;
    arguments = 0;
}

Function& Function::Copy() const
{
    return Create(getSymbol(), arguments);
}

void Function::Bind(const FunctionSymbol& rhs)
{
    assert(!(getDefinition().IsSame(FunctionDefinition::undef) || getDefinition().getArity() == rhs.getDefinition().getArity()));

    Expression<Function, FunctionSymbol, FunctionDefinition>::Bind(rhs);
}

const ExpressionBase& Function::getArgument(int i) const
{
    assert(i >= 0);
    assert(i < getArity());

    return *arguments[i];
}

void Function::bindArgument(int i, const ExpressionBase& argument)
{
    assert(i >= 0);
    assert(i < getArity());

    arguments[i]->Release();
    arguments[i] = &argument;
    arguments[i]->Acquire();
}

FunctionDefinition& Function::getDefinition() const
{
    return getSymbol().getDefinition();
}

int Function::getArity() const
{
    return getSymbol().getDefinition().getArity();
}

//void Function::Accept(ExpressionVisitor& visitor)
//{
//    visitor.visit(*this);
//}

Function& Function::Deriv(const Variable& v) const
{
    assert(false);
    throw 0;
}

string Function::toString() const{
    bool is_first = true;
    string rv = getSymbol().getLexeme() + "(";

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

Function& Function::Substitute(const Variable& variable, const ExpressionBase& substitution) const
{
    const ExpressionBase** arguments = new const ExpressionBase*[getArity()];

    for (int i = 0; i < getArity(); i++) {
        arguments[i] = &(getArgument(i).Substitute(variable, substitution));
    }

    Function& rv = Function::Create(getSymbol(), arguments);

    delete [] arguments;

    return rv;
}

bool Function::IsSame(const ExpressionBase& rhs) const
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
