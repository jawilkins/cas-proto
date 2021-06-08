#include "cas-proto/Stat.h"

#include <iostream>
using std::cout;
using std::endl;

#include <assert.h>



Stat::Stat(const std::string& name)
    : name(name)
    , created(0)
    , deleted(0)
    , count(0)
{}

void Stat::Bump()
{
    assert(created >= deleted);
    assert(count == created - deleted);

    created++;
    count++;
}

void Stat::Unbump()
{
    assert(deleted < created);
    assert(count > 0);
    assert(count == created - deleted);

    deleted++;
    count--;
}

void Stat::Report()
{
    cout << "Name:    " << name    << endl;
    cout << "Created: " << created << endl;
    cout << "Deleted: " << deleted << endl;
    cout << "Count:   " << count   << endl;
}
