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
    Dustbin() {
        houseWasteContent = std::unique_ptr<Garbage[]>(new Garbage[1]);
        plasticContent = std::unique_ptr<PlasticGarbage[]>(new PlasticGarbage[1]);
        paperContent = std::unique_ptr<PaperGarbage[]>(new PaperGarbage[1]);
    }
    void throwOutGarbage(Garbage &garbage);
    void throwOutPaperGarbage(PaperGarbage &paper);
    void throwOutPlasticGarbage(PlasticGarbage &plastic);
    void emptyContents();

//private:
    std::string color;
    std::unique_ptr<PaperGarbage[]> paperContent;
    std::unique_ptr<PlasticGarbage[]> plasticContent;
    std::unique_ptr<Garbage[]> houseWasteContent;
};


#endif //CPP_WASTE_RECYCLING_DUSTBIN_H
