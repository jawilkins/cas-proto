#ifndef Natural_h
#define Natural_h

#ifndef Constant_h
#include "Constant.h"
#endif



class Natural : public Constant {

public:

    static Natural& Create(int);

    Natural& Copy() const;

    Natural& Deriv(const Variable&) const;

    std::string toString() const;

    int get() const;

protected:

    Natural(int n);

private:

    Natural(const Natural&); // not implemented
    Natural& operator = (const Natural&); // not implemented

    int n;

};



#endif
