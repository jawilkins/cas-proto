#pragma once
#ifndef Definition_h
#define Definition_h

#ifndef Object_h
#include "Object.h"
#endif



class Definition : public Object {

public:

    CAS_PROTO_API virtual std::string toString() const = 0;

    CAS_PROTO_API bool IsSame(const Definition&) const;

};



#endif // Definition_h
