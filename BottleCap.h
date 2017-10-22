//
// Created by en on 2017.10.22..
//

#ifndef CPP_WASTE_RECYCLING_BOTTLECAP_H
#define CPP_WASTE_RECYCLING_BOTTLECAP_H

#include <random>
#include "Garbage.h"

class BottleCap : public Garbage {
public:
    BottleCap() {}
    BottleCap(std::string name, std::string color)
    : Garbage(name)
    , color(color)
    {}

    virtual ~BottleCap(){}

    const std::string &getColor() const {
        return color;
    }

private:
    std::string color;
};


#endif //CPP_WASTE_RECYCLING_BOTTLECAP_H
