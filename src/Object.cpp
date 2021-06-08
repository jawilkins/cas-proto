#include "cas-proto/Object.h"

#include <cassert>



Stat Object::refs("Reference Counts");
Stat Object::stat("Object");



CAS_PROTO_API Object::Object()
    : refcount(0)
{
    stat.Bump();
}

CAS_PROTO_API Object::~Object()
{
    assert(refcount == 0);

    stat.Unbump();
}

CAS_PROTO_API void Object::Acquire() const
{
    refs.Bump();

    refcount++;
}

CAS_PROTO_API void Object::Release() const
{
    assert(refcount > 0);

    refs.Unbump();

    refcount--;

    if (0 == refcount) {
        delete this;
    }
}
