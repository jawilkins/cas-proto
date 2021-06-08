#include "cas-proto/Object.h"

#include <assert.h>



Stat Object::refs("Reference Counts");
Stat Object::stat("Object");



Object::Object()
    : refcount(0)
{
    stat.Bump();
}

Object::~Object()
{
    assert(refcount == 0);

    stat.Unbump();
}

void Object::Acquire() const
{
    refs.Bump();

    refcount++;
}

void Object::Release() const
{
    assert(refcount > 0);

    refs.Unbump();

    refcount--;

    if (0 == refcount) {
        delete this;
    }
}
