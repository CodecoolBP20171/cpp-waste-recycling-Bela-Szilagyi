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
    virtual void emptyContents();
    void throwOutMetalGarbage(MetalGarbage &metal);
    void throwOutBottleCap(BottleCap &cap);
private:
    std::unique_ptr<MetalGarbage[]> metalContent;
    int metalSize = 1;
    int metalCounter = 0;
    int metalWeight = 4;

    std::unique_ptr<BottleCap[]> capContent;
    int capSize = 1;
    int capCounter = 0;
    int capWeight = 1;
};



#endif //CPP_WASTE_RECYCLING_DUSTBIN9000_H
