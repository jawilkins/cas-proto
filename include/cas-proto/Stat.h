#pragma once
#ifndef Stat_h
#define Stat_h

#include "api.h"

#include <string>



class Stat {

public:

    CAS_PROTO_API explicit Stat(const std::string&);

    CAS_PROTO_API void Bump();
    CAS_PROTO_API void Unbump();
    CAS_PROTO_API void Report();

private:

    std::string name;

    int created;
    int deleted;
    int count;

};



#endif // Stat_h
