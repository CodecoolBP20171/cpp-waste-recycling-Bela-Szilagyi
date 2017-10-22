//
// Created by en on 2017.10.22..
//

#ifndef CPP_WASTE_RECYCLING_METALGARBAGE_H
#define CPP_WASTE_RECYCLING_METALGARBAGE_H

#include "Garbage.h"

class MetalGarbage : public Garbage {
public:
    MetalGarbage() {}
    MetalGarbage(std::string name)
    : Garbage(name)
    {}

    virtual ~MetalGarbage(){}
};


#endif //CPP_WASTE_RECYCLING_METALGARBAGE_H
