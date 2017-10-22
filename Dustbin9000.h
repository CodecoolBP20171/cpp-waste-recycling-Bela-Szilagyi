//
// Created by en on 2017.10.22..
//

#ifndef CPP_WASTE_RECYCLING_DUSTBIN9000_H
#define CPP_WASTE_RECYCLING_DUSTBIN9000_H

#include "Dustbin.h"
#include "MetalGarbage.h"
#include "BottleCap.h"

class Dustbin9000 : public Dustbin {
public:
    Dustbin9000();

    void throwOutMetalGarbage(MetalGarbage &metal);
    std::unique_ptr<MetalGarbage[]> metalContent;
    int metalSize = 1;
    int metalCounter = 0;
    int metalWeight = 4;

    void throwOutBottleCap(BottleCap &cap);
    std::unique_ptr<BottleCap[]> capContent;
    int capSize = 1;
    int capCounter = 0;
    int capWeight = 1;

    virtual void emptyContents();
};



#endif //CPP_WASTE_RECYCLING_DUSTBIN9000_H
