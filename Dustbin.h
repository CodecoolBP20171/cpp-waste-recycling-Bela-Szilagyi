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
    void throwOutGarbage(std::shared_ptr<Garbage>); // the argument is an instance of the Garbage class. It puts that into the houseWasteContent array
    void throwOutPaperGarbage(std::shared_ptr<PaperGarbage>); // the argument is an instance of the PaperGarbage class. If it's squeezed, then it puts that into the paperContent array. If the PaperGarbage instance is not squeezed, it raises a DustbinContentError exception
    void throwOutPlasticGarbage(std::shared_ptr<PlasticGarbage>); // the argument is an instance of the PlasticGarbage class. If it's clean, then it puts that into the plasticContent array. If the PlasticGarbage instance is not clean, it raises a DustbinContentError exception
    void emptyContents(); // If it's called, all the garbage containers gets emptied

//private:
    std::string color;
    std::vector<std::shared_ptr<PaperGarbage>> paperContent;
    std::vector<std::shared_ptr<PlasticGarbage>> plasticContent;
    std::vector<std::shared_ptr<Garbage>> houseWasteContent;
};


#endif //CPP_WASTE_RECYCLING_DUSTBIN_H
