#include "cas-proto/SquareRoot.h"
//
//#include "cas-proto/Blank.h"
//#include "cas-proto/Constant.h"
//#include "cas-proto/SquareRootDefinition.h"
//#include "cas-proto/Product.h"
//#include "cas-proto/Negate.h"
//#include "cas-proto/Natural.h"
//
//
//
//FunctionSymbol& SquareRoot::symbol = FunctionSymbol::Create("\xFB", SquareRootDefinition::getInstance());
//
//
//
//CAS_PROTO_API SquareRoot& SquareRoot::Create()
//{
//    return Create(Blank::Create());
//}
//
//CAS_PROTO_API SquareRoot& SquareRoot::Create(const ExpressionBase& radicand)
//{
//    const ExpressionBase* arguments[1];
//
//    arguments[0] = &radicand;
//
//    return *(new SquareRoot(arguments));
//}
//
//CAS_PROTO_API SquareRoot::SquareRoot(const ExpressionBase** arguments)
//    : UnaryOperator(symbol, arguments)
//{}
//
//CAS_PROTO_API const ExpressionBase& SquareRoot::getRadicand() const
//{
//    return get();
//}
//
//CAS_PROTO_API const void SquareRoot::bindRadicand(const ExpressionBase& radicand)
//{
//    bind(radicand);
//}
//
//CAS_PROTO_API Quotient& SquareRoot::Deriv(const Variable& variable) const
//{
//    // 1/2 * sqrt(variable)
//    assert(false);
//    throw 0;
//}
//
//CAS_PROTO_API ExpressionBase& SquareRoot::Simplify() const
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
