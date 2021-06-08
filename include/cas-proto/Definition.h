#ifndef Definition_h
#define Definition_h

#ifndef Object_h
#include "Object.h"
#endif



class Definition : public Object {

public:

    virtual std::string toString() const = 0;

    bool IsSame(const Definition&) const;

};



#endif
