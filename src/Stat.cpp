#include "cas-proto/Stat.h"

#include <iostream>

#include <cassert>



CAS_PROTO_API Stat::Stat(const std::string& name)
    : name(name)
    , created(0)
    , deleted(0)
    , count(0)
{}

CAS_PROTO_API void Stat::Bump()
{
    assert(created >= deleted);
    assert(count == created - deleted);

    created++;
    count++;
}

CAS_PROTO_API void Stat::Unbump()
{
    assert(deleted < created);
    assert(count > 0);
    assert(count == created - deleted);

    deleted++;
    count--;
}

CAS_PROTO_API void Stat::Report()
{
    std::cout << "Name:    " << name    << '\n'
              << "Created: " << created << '\n'
              << "Deleted: " << deleted << '\n'
              << "Count:   " << count   << '\n';
}
