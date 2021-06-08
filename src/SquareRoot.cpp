//#include "SquareRoot.h"
//
//#include "Blank.h"
//#include "Constant.h"
//#include "SquareRootDefinition.h"
//#include "Product.h"
//#include "Negate.h"
//#include "Natural.h"
//
//
//
//FunctionSymbol& SquareRoot::symbol = FunctionSymbol::Create("\xFB", SquareRootDefinition::getInstance());
//
//
//
//SquareRoot& SquareRoot::Create()
//{
//    return Create(Blank::Create());
//}
//
//SquareRoot& SquareRoot::Create(const ExpressionBase& radicand)
//{
//    const ExpressionBase* arguments[1];
//
//    arguments[0] = &radicand;
//
//    return *(new SquareRoot(arguments));
//}
//
//SquareRoot::SquareRoot(const ExpressionBase** arguments)
//    : UnaryOperator(symbol, arguments)
//{}
//
//const ExpressionBase& SquareRoot::getRadicand() const
//{
//    return get();
//}
//
//const void SquareRoot::bindRadicand(const ExpressionBase& radicand)
//{
//    bind(radicand);
//}
//
//Quotient& SquareRoot::Deriv(const Variable& variable) const
//{
//    // 1/2 * sqrt(variable)
//    assert(false);
//    throw 0;
//}
//
//ExpressionBase& SquareRoot::Simplify() const
//{
//    ExpressionBase& R = get().Simplify();
//
//    if (R.IsSame(Natural::Create(0))) {
//        return Natural::Create(0);
//    }
//    else if (R.IsSame(Natural::Create(1))) {
//        return Natural::Create(1);
//    }
//    else {
//        const Product* p = dynamic_cast<const Product*>(&R);
//        const Negate*  n = dynamic_cast<const Negate*>(&R);
//
//        if (p && p->getMultiplier().IsSame(p->getMultiplicand())) {
//            return p->getMultiplier().Copy();
//        }
//        else if (n && n->get().IsSame(Natural::Create(1))) {
//            return Constant::getImaginary();
//        }
//        else {
//            return Create(R);
//        }
//    }
//    // else if the radicand is an integer perfect square
//        // return just the square root of that integer
//    // else if the radicand is a rational perfect square
//        // return just the square root of that rational
//    // else the radicand is a product and the multiplier and multiplicand are equivalent
//        // return just the multiplier
//
//    //else {
//    //    return Create(R);
//    //}
//}
