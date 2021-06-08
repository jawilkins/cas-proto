#include "cas-proto/Variable.h"
#include "cas-proto/Product.h"
#include "cas-proto/Ref.h"

#include <iostream>

int main()
{
    VARIABLE_DECL(x);
    PRODUCT_DECL(p1, *x, *x);
    NUMBER_DECL(neg2, -2);
    PRODUCT_DECL(p2, *neg2, *x);
    NUMBER_DECL(one, 1);
    SUM_DECL(s1, *p1, *p2);
    SUM_DECL(equation, *s1, *one);

    std::cout << equation->toString() << '\n';

    Ref<Function> deriv = equation->Deriv(*x);

    std::cout << deriv->toString() << '\n';

    Ref<ExpressionBase> simp = deriv->Simplify();

    std::cout << simp->toString() << '\n';

    VARIABLE_DECL(y);
    PRODUCT_DECL(p3, *y, *y);

    std::cout << p3->toString() << '\n';

    Ref<ExpressionBase> subst = simp->Substitute(*x, *p3);
    std::cout << subst->toString() << '\n';

    std::cout << x->getSymbol().getLexeme() << '\n';

    return 0;
}
