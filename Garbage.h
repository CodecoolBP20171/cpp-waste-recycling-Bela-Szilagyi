//
// Created by en on 2017.10.16..
//

#ifndef CPP_WASTE_RECYCLING_GARBAGE_H
#define CPP_WASTE_RECYCLING_GARBAGE_H

#include <iostream>

class Garbage {
public:
    Garbage() {}
    Garbage(std::string);

    virtual ~Garbage() {};

    std::string getName();

private:
    std::string name;
};


#endif //CPP_WASTE_RECYCLING_GARBAGE_H
