#pragma once
#ifndef Object_h
#define Object_h

#ifndef Stat_h
#include "Stat.h"
#endif



class Object {

public:

    CAS_PROTO_API void Acquire() const;
    CAS_PROTO_API void Release() const;

protected:

    CAS_PROTO_API Object();

    CAS_PROTO_API virtual ~Object();

private:

    Object(const Object&);            // not implemented
    Object& operator=(const Object&); // not implemented

    mutable int refcount;

    static Stat stat;
    static Stat refs;

};



#endif // Object_h
