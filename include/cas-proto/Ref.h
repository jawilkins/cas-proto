#pragma once
#ifndef Ref_h
#define Ref_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

template <class T>
class Ref {

public:

    Ref(T& ref)
        : ref(ref)
    {
        ref.Acquire();
    }

    T* operator -> ()
    {
        return &ref;
    }

    T& operator * ()
    {
        return ref;
    }

    ~Ref()
    {
        ref.Release();
    }

private:

    T& ref;

};



#define CONSTANT_DECL(lexeme) Ref<Constant> lexeme = Constant::Create(#lexeme)
#define VARIABLE_DECL(lexeme) Ref<Variable> lexeme = Variable::Create(#lexeme)

#define NUMBER_DECL(e, a)      Ref<Constant>    e = Constant   ::Create(#a);
#define SUM_DECL(e, a, b)      Ref<Sum>         e = Sum        ::Create((a), (b))
#define PRODUCT_DECL(e, a, b)  Ref<Product>     e = Product    ::Create((a), (b))
#define QUOTIENT_DECL(e, a, b) Ref<Quotient>    e = Quotient   ::Create((a), (b))
#define SQRT_DECL(e, a)        Ref<SquareRoot>  e = SquareRoot ::Create(a)



#endif // Ref_h
