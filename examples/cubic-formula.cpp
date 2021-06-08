#include "cas-proto/Variable.h"
#include "cas-proto/Exponent.h"
#include "cas-proto/Rational.h"

#include "cas-proto/Product.h"
#include "cas-proto/Negate.h"
#include "cas-proto/Ref.h"

#include <iostream>

extern ExpressionBase& getQuadraticEquation(
    const ExpressionBase& A,
    const ExpressionBase& B,
    const ExpressionBase& C);

extern ExpressionBase& getCubicEquation(
    const ExpressionBase& A,
    const ExpressionBase& B,
    const ExpressionBase& C,
    const ExpressionBase& D);

int main(void)
{
    VARIABLE_DECL(A);
    VARIABLE_DECL(B);
    VARIABLE_DECL(C);

    Ref<ExpressionBase> quad = getQuadraticEquation(*A, *B, *C);

    std::cout << quad->toString() << '\n';

    Ref<ExpressionBase> quad_simp = quad->Simplify();

    std::cout << quad_simp->toString() << '\n';

    PRODUCT_DECL(e1, *A, *A);
    PRODUCT_DECL(e2, *e1, *A);
    PRODUCT_DECL(e3, *e2, *A);
    PRODUCT_DECL(e4, *e3, *A);

    std::cout << e4->toString() << '\n';

    Ref<ExpressionBase> e5 = e4->Simplify();

    std::cout << e5->toString() << '\n';

    Ref<Constant> imag = Constant::getImaginary();

    std::cout << imag->toString() << '\n';

    Ref<Negate> neg1 = Negate::Create(Natural::Create(1));

#if 0
    Ref<SquareRoot> sqrt1 = SquareRoot::Create(*neg1);
#else
    Ref<Exponent> sqrt1 = Exponent::Create(*neg1, Rational::Create(1, 2));
#endif

    std::cout << sqrt1->toString() << '\n';

    Ref<ExpressionBase> imag2 = sqrt1->Simplify();

    std::cout << imag2->toString() << '\n';

    VARIABLE_DECL(D);

    Ref<ExpressionBase> cube = getCubicEquation(*A, *B, *C, *D);

    std::cout << cube->toString() << '\n';

    return 0;
}
