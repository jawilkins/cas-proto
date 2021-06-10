#pragma once
#ifndef Pi_h
#define Pi_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifndef Constant_h
#include "Constant.h"
#endif

class Pi : public Constant {

public:

    void accept(const class ExpressionVisitor&);

};

#endif // Pi_h
