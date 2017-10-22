//
// Created by en on 2017.10.22..
//

#ifndef CPP_WASTE_RECYCLING_DUSTBIN9000_H
#define CPP_WASTE_RECYCLING_DUSTBIN9000_H

#include "Dustbin.h"
#include "MetalGarbage.h"

class Dustbin9000 : public Dustbin {
public:
    void throwOutMetalGarbage(MetalGarbage &metal);
    std::unique_ptr<MetalGarbage[]> metalContent;
    int metalSize = 1;
    int metalCounter = 0;
    int metalWeight = 4;
};


#endif //CPP_WASTE_RECYCLING_DUSTBIN9000_H
