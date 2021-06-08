#include "cas-proto/Variable.h"
#include "cas-proto/Constant.h"
#include "cas-proto/Product.h"
#include "cas-proto/Sum.h"
#include "cas-proto/Exponent.h"
#include "cas-proto/Quotient.h"
#include "cas-proto/Negate.h"
#include "cas-proto/Difference.h"

#include "cas-proto/Ref.h"

ExpressionBase& getQuadraticEquation(
    const ExpressionBase& A,
    const ExpressionBase& B,
    const ExpressionBase& C)
{
    //Ref<Constant> one = Natural::Create(1);
    //Ref<Negate> neg1 = Negate::Create(*one);

    
    //NUMBER_DECL(neg1, -1);
    //NUMBER_DECL(neg4, -4);
    //NUMBER_DECL(two, 2);
    //PRODUCT_DECL(negB, *neg1, B);
    //SUM_DECL(BB4AC, *BB, *AC4);
    //PRODUCT_DECL(AC, A, C);
    //PRODUCT_DECL(AC4, *four, *AC);
    //SQRT_DECL(SQRTBB4AC, *BB4AC);
    //SUM_DECL(negBSQRTBB4AC, *negB, *SQRTBB4AC);
    //PRODUCT_DECL(a2, *two, A);
    //QUOTIENT_DECL(Q, *negBSQRTBB4AC, *a2);

    Ref<Constant> four = Constant::Create("4");

    Ref<Negate> negB = Negate::Create(B);

    Ref<Product> BB = Product::Create(B, B);

    Ref<Product> AC  = Product::Create(A, C);
    Ref<Product> AC4 = Product::Create(*four, *AC);

    Ref<Difference> BB4AC = Difference::Create(*BB, *AC4);

    Ref<Exponent> SQRTBB4AC = Exponent::SquareRoot(*BB4AC);

    Ref<Sum> negBSQRTBB4AC = Sum::Create(*negB, *SQRTBB4AC);

    Ref<Constant> two = Constant::Create("2");

    Ref<Product> a2 = Product::Create(*two, A);

    Ref<Quotient> q = Quotient::Create(*negBSQRTBB4AC, *a2);

    q->Acquire();

    return *q;
}
