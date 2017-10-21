//
// Created by en on 2017.10.16..
//

#ifndef CPP_WASTE_RECYCLING_DUSTBIN_H
#define CPP_WASTE_RECYCLING_DUSTBIN_H

#include <iostream>
#include <memory>
#include <vector>
#include "PaperGarbage.h"
#include "PlasticGarbage.h"

class Dustbin {
public:
    Dustbin();
    void throwOutGarbage(Garbage &garbage);
    void throwOutPaperGarbage(PaperGarbage &paper);
    void throwOutPlasticGarbage(PlasticGarbage &plastic);
    void emptyContents();

//private:
    std::string color;

    const std::string &getColor() const;

    void setColor(const std::string &color);

    std::unique_ptr<PaperGarbage[]> paperContent;
    int paperSize = 1;
    int paperCounter = 0;
    int paperWeight = 3;
    std::unique_ptr<PlasticGarbage[]> plasticContent;
    int plasticSize = 1;
    int plasticCounter = 0;
    int plasticWeight = 1;
    std::unique_ptr<Garbage[]> houseWasteContent;
    int garbageSize = 1;
    int garbageCounter = 0;
    int garbageWeight = 2;
    int weight = 0;
    int maxWeight = 10;
};


#endif //CPP_WASTE_RECYCLING_DUSTBIN_H
