//
// Created by en on 2017.10.16..
//

#ifndef CPP_WASTE_RECYCLING_PLASTICGARBAGE_H
#define CPP_WASTE_RECYCLING_PLASTICGARBAGE_H

#include "Garbage.h"

class PlasticGarbage : Garbage {
public:
    PlasticGarbage(std::string name)
        : Garbage(name)
        , isClean(false)
        {}

    virtual ~PlasticGarbage(){}

    void clean(){}

    bool isClean;

};


#endif //CPP_WASTE_RECYCLING_PLASTICGARBAGE_H
