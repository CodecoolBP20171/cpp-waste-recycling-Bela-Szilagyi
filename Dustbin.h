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
    std::unique_ptr<PaperGarbage[]> paperContent;
    int paperSize = 1;
    int paperCounter = 0;
    std::unique_ptr<PlasticGarbage[]> plasticContent;
    int plasticSize = 1;
    int plasticCounter = 0;
    std::unique_ptr<Garbage[]> houseWasteContent;
    int garbageSize = 1;
    int garbageCounter = 0;
};


#endif //CPP_WASTE_RECYCLING_DUSTBIN_H
