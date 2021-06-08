#ifndef Object_h
#define Object_h

#ifndef Stat_h
#include "Stat.h"
#endif



class Object {

public:

    void Acquire() const;
    void Release() const;

protected:

    Object();

    virtual ~Object();

private:

    Object(const Object&); // not implemented
    Object& operator = (const Object&); // not implemented

    mutable int refcount;

    static Stat stat;
    static Stat refs;

};



#endif
