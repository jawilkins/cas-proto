#include "Expression.h"

#include "ExpressionVisitor.h"



template <class P, class S, class D>
P& Expression<P, S, D>::Create(const std::string& lexeme, D& definition)
{
    return P::Create(S::Create(lexeme, definition));
}

template <class P, class S, class D>
P& Expression<P, S, D>::Create(const std::string& lexeme)
{
    return P::Create(S::Create(lexeme));
}

template <class P, class S, class D>
P& Expression<P, S, D>::Create()
{
    return P::Create(S::Create());
}

//template <class P, class S, class D>
//void Expression<P, S, D>::Accept(ExpressionVisitor& visitor)
//{
//    visitor.visit(*reinterpret_cast<P*>(this));
//}

template <class P, class S, class D>
void Expression<P, S, D>::Bind(const S& symbol)
{
    symbol_ptr->Release();
    symbol_ptr = &symbol;
    symbol_ptr->Acquire();
}

//template <class P, class S, class D>
//bool Expression<P, S, D>::IsSame(const P& rhs) const
//{
//    return symbol_ptr == rhs.symbol_ptr;
//}

template <class P, class S, class D>
bool Expression<P, S, D>::IsSame(const ExpressionBase& rhs) const
{
    const P* p = dynamic_cast<const P*>(&rhs);

    return p ? symbol_ptr == p->symbol_ptr : false;
}

template <class P, class S, class D>
const S& Expression<P, S, D>::getSymbol() const
{
    return *symbol_ptr;
}

template <class P, class S, class D>
std::string Expression<P, S, D>::getLexeme() const
{
    return symbol_ptr->getLexeme();
}

template <class P, class S, class D>
Expression<P, S, D>::Expression(const S& symbol)
    : symbol_ptr(&symbol)
{
    symbol_ptr->Acquire();
}

template <class P, class S, class D>
Expression<P, S, D>::~Expression()
{
    symbol_ptr->Release();
    symbol_ptr = 0;
}
