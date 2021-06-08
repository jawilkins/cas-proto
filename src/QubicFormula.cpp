#include "cas-proto/Variable.h"
#include "cas-proto/Constant.h"
#include "cas-proto/Product.h"
#include "cas-proto/Sum.h"
#include "cas-proto/Exponent.h"
#include "cas-proto/Quotient.h"
#include "cas-proto/Negate.h"
#include "cas-proto/Difference.h"
#include "cas-proto/Natural.h"
#include "cas-proto/Rational.h"

#include "cas-proto/Ref.h"

ExpressionBase& getCubicEquation(
    const ExpressionBase& A,
    const ExpressionBase& B,
    const ExpressionBase& C,
    const ExpressionBase& D)
{
    Ref<Natural>  t0 = Natural::Create(2);              // 2

    Ref<Natural>  t1 = Natural::Create(3);              // 3

    Ref<Product>  t2 = Product::Create(*t1, A);         // 3A

    Ref<Quotient> t3 = Quotient::Create(B, *t2);        // B\3A

    Ref<Negate>   t4 = Negate::Create(*t3);             // -(B\3A)

    Ref<Product>  t5 = Product::Create(A, C);           // AC

    Ref<Product>  t6 = Product::Create(*t1, *t5);         // 3AC

    Ref<Exponent> t7 = Exponent::Create(B, *t0);          // B^2

    Ref<Difference> t8 = Difference::Create(*t7, *t6);    // B^2 - 3AC

    Ref<Exponent> t9 = Exponent::Create(*t8, *t1);         // (B^2 - 3AC)^3

    Ref<Natural> t10 = Natural::Create(4);              // 4

    Ref<Product> t11 = Product::Create(*t10, *t9);        // 4(B^2 - 3AC)^3

    Ref<Exponent> t12 = Exponent::Create(A, *t0);         // A^2

    Ref<Product> t13 = Product::Create(*t12, D);         // A^2D

    Ref<Natural> t14 = Natural::Create(27);             // 27

    Ref<Product> t15 = Product::Create(*t14, *t13);       // 27A^2D

    Ref<Product> t16 = Product::Create(B, C);           // BC

    Ref<Product> t17 = Product::Create(A, *t16);         // ABC

    Ref<Natural> t18 = Natural::Create(9);              // 9

    Ref<Product> t19 = Product::Create(*t18, *t17);       // 9ABC

    Ref<Exponent> t20 = Exponent::Create(B, *t1);         // B^3

    Ref<Natural> t21 = Natural::Create(2);              // 2

    Ref<Product> t22 = Product::Create(*t21, *t20);       // 2B^3

    Ref<Difference> t23 = Difference::Create(*t22, *t19); // 2B^3 - 9ABC

    Ref<Sum> t24 = Sum::Create(*t23, *t15);               // 2B^3 - 9ABC + 27A^2D

    Ref<Exponent> t25 = Exponent::Create(*t24, *t0);       // (2B^3 - 9ABC + 27A^2D)^2

    Ref<Difference> t26 = Difference::Create(*t25, *t11); // (2B^3 - 9ABC + 27A^2D)^2 - 4(B^2 - 3AC)^3

    Ref<Rational> t27 = Rational::Create(1, 2);         // 1/2

    Ref<Exponent> t28 = Exponent::Create(*t26, *t27);     // ((2B^3 - 9ABC + 27A^2D)^2 - 4(B^2 - 3AC)^3)^1/2

    Ref<Sum> t29 = Sum::Create(*t24 ,*t28);               // 2B^3 - 9ABC + 27A^2D + ((2B^3 - 9ABC + 27A^2D)^2 - 4(B^2 - 3AC)^3)^1/2

    Ref<Quotient> t30 = Quotient::Create(*t29, *t21);             // (2B^3 - 9ABC + 27A^2D + ((2B^3 - 9ABC + 27A^2D)^2 - 4(B^2 - 3AC)^3)^1/2) \ 2

    Ref<Rational> t31 = Rational::Create(1, 3);         // 1/3

    Ref<Exponent> t32 = Exponent::Create(*t30, *t31);     // ((2B^3 - 9ABC + 27A^2D + ((2B^3 - 9ABC + 27A^2D)^2 - 4(B^2 - 3AC)^3)^1/2) \ 2)^1/3

    Ref<Natural> t33 = Natural::Create(1);              // 1

    Ref<Quotient> t34 = Quotient::Create(*t33, *t2);      // 1\(3A)

    Ref<Product> t35 = Product::Create(*t34, *t32);       // (1\(3A))*((2B^3 - 9ABC + 27A^2D + ((2B^3 - 9ABC + 27A^2D)^2 - 4(B^2 - 3AC)^3)^1/2) \ 2)^1/3

    Ref<Difference> t36 = Difference::Create(*t4,*t35);   // -(B\3A)-((1\(3A))*((2B^3 - 9ABC + 27A^2D + ((2B^3 - 9ABC + 27A^2D)^2 - 4(B^2 - 3AC)^3)^1/2) \ 2)^1/3)



    Ref<Difference> t37 = Difference::Create(*t24, *t28);               // 2B^3 - 9ABC + 27A^2D - ((2B^3 - 9ABC + 27A^2D)^2 - 4(B^2 - 3AC)^3)^1/2

    Ref<Quotient> t38 = Quotient::Create(*t37, *t21);             // (2B^3 - 9ABC + 27A^2D - ((2B^3 - 9ABC + 27A^2D)^2 - 4(B^2 - 3AC)^3)^1/2) \ 2

    Ref<Exponent> t39 = Exponent::Create(*t38, *t31);     // ((2B^3 - 9ABC + 27A^2D - ((2B^3 - 9ABC + 27A^2D)^2 - 4(B^2 - 3AC)^3)^1/2) \ 2)^1/3

    Ref<Product> t40 = Product::Create(*t34, *t39);       // (1\(3A))*((2B^3 - 9ABC + 27A^2D - ((2B^3 - 9ABC + 27A^2D)^2 - 4(B^2 - 3AC)^3)^1/2) \ 2)^1/3

    Ref<Difference> t41 = Difference::Create(*t36, *t40);   // -(B\3A)-((1\(3A))*((2B^3 - 9ABC + 27A^2D - ((2B^3 - 9ABC + 27A^2D)^2 - 4(B^2 - 3AC)^3)^1/2) \ 2)^1/3)-(1\(3A))*((2B^3 - 9ABC + 27A^2D - ((2B^3 - 9ABC + 27A^2D)^2 - 4(B^2 - 3AC)^3)^1/2) \ 2)^1/3

    ExpressionBase& QE = *t41;
    QE.Acquire();

    return QE;
}
