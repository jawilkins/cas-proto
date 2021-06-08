#ifndef Stat_h
#define Stat_h

#include <string>



class Stat {

public:

    Stat(const std::string&);

    void Bump();
    void Unbump();
    void Report();

private:

    std::string name;

    int created;
    int deleted;
    int count;

};



#endif
