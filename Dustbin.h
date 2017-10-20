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
        houseWasteContent = std::unique_ptr<Garbage[]>(new Garbage[1]) ;
    }
    void throwOutGarbage(Garbage &garbage);
    void throwOutPaperGarbage(std::shared_ptr<PaperGarbage>);
    void throwOutPlasticGarbage(std::shared_ptr<PlasticGarbage>);
    void emptyContents();

//private:
    std::string color;
    std::vector<std::shared_ptr<PaperGarbage>> paperContent;
    std::vector<std::shared_ptr<PlasticGarbage>> plasticContent;
    std::unique_ptr<Garbage[]> houseWasteContent;
};


#endif //CPP_WASTE_RECYCLING_DUSTBIN_H
