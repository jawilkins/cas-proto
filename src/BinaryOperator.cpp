#include "cas-proto/BinaryOperator.h"

#include "cas-proto/Blank.h"

using std::string;



BinaryOperator& BinaryOperator::Create(const FunctionSymbol& symbol, int precedence, const ExpressionBase& a, const ExpressionBase& b)
{
    assert(symbol.getDefinition().IsSame(FunctionDefinition::undef) || symbol.getDefinition().getArity() == 2);

    const ExpressionBase* arguments[2];

    arguments[0] = &a;
    arguments[1] = &b;

    return *(new BinaryOperator(symbol, precedence, arguments));
}

BinaryOperator& BinaryOperator::Create(const FunctionSymbol& symbol, int precedence)
{
    assert(symbol.getDefinition().IsSame(FunctionDefinition::undef) || symbol.getDefinition().getArity() == 2);

    return Create(symbol, precedence, Blank::Create(), Blank::Create());
}

BinaryOperator& BinaryOperator::Create(const std::string& lexeme, int precedence, const ExpressionBase& a, const ExpressionBase& b)
{
    return Create(FunctionSymbol::Create(lexeme), precedence, a, b);
}

BinaryOperator& BinaryOperator::Create(const std::string& lexeme, int precedence)
{
    return Create(FunctionSymbol::Create(lexeme), precedence, Blank::Create(), Blank::Create());
}

BinaryOperator& BinaryOperator::Create(int precedence)
{
    return Create(FunctionSymbol::Create(), precedence, Blank::Create(), Blank::Create());
}

const ExpressionBase& BinaryOperator::getA() const
{
    return getArgument(0);
}

const ExpressionBase& BinaryOperator::getB() const
{
    return getArgument(1);
}

const void BinaryOperator::bindA(const ExpressionBase& a)
{
    bindArgument(0, a);
}

const void BinaryOperator::bindB(const ExpressionBase& b)
{
    bindArgument(1, b);
}

BinaryOperator::BinaryOperator(const FunctionSymbol& symbol, int precedence, const ExpressionBase** arguments)
    : Function(symbol, arguments)
    , precedence(precedence)
{}

//void BinaryOperator::Accept(ExpressionVisitor& visitor)
//{
//    visitor.visit(*this);
//}

string BinaryOperator::toString() const
{
    string rv;

    const BinaryOperator* a = dynamic_cast<const BinaryOperator*>(&getA());

    if (a && precedence > a->precedence ) {
        rv = rv + "(" + getA().toString() + ")";
    }
    else {
        rv = rv + getA().toString();
    }

    rv = rv + getSymbol().getLexeme();

    const BinaryOperator* b = dynamic_cast<const BinaryOperator*>(&getB());

    if (b && precedence > b->precedence ) {
        rv = rv + "(" + getB().toString() + ")";
    }
    else {
        rv = rv + getB().toString();
    }

    return rv;
}

BinaryOperator& BinaryOperator::Substitute(const Variable& variable, const ExpressionBase& substitution) const
{
    const ExpressionBase& A = getA().Substitute(variable, substitution);
    const ExpressionBase& B = getB().Substitute(variable, substitution);

    return Create(getSymbol(), precedence, A, B);
}

BinaryOperator& BinaryOperator::Copy() const
{
    return Create(getSymbol(), precedence, getA().Copy(), getB().Copy());
}

int BinaryOperator::getPrecedence() const
{
    return precedence;
}

int BinaryOperator::getMinPrecedence() const
{
    int min = precedence;

    const BinaryOperator* a = this;

    for(;;) {
        a = dynamic_cast<const BinaryOperator*>(&(a->getA()));

        if (!a) break;

        if (a->getPrecedence() < min) min = a->getPrecedence();
    }

    const BinaryOperator* b = this;

    for(;;) {
        b = dynamic_cast<const BinaryOperator*>(&(b->getB()));

        if (!b) break;

        if (b->getPrecedence() < min) min = b->getPrecedence();
    }

    //int min = precedence;

    //const BinaryOperator* a = dynamic_cast<const BinaryOperator*>(&getA());

    //if (a) {
    //    int minA = a->getMinPrecedence();

    //    if (minA < min) min = minA;
    //}

    //const BinaryOperator* b = dynamic_cast<const BinaryOperator*>(&getB());

    //if (b) {
    //    int minB = b->getMinPrecedence();

    //    if (minB < min) min = minB;
    //}

    return min;
}

const ExpressionBase& BinaryOperator::getLeftmostTerm() const
{
    const BinaryOperator* a = dynamic_cast<const BinaryOperator*>(&getA());

    if (a) {
        return a->getLeftmostTerm();
    }
    else {
        return getA();
    }
}

const ExpressionBase& BinaryOperator::getRightmostTerm() const
{
    const BinaryOperator* b = dynamic_cast<const BinaryOperator*>(&getB());

    if (b) {
        return b->getRightmostTerm();
    }
    else {
        return getB();
    }
}
