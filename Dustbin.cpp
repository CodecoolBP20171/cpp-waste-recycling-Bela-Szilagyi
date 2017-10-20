//
// Created by en on 2017.10.16..
//

#include "Dustbin.h"
#include "DustbinContentError.hpp"

void Dustbin::throwOutGarbage(Garbage &garbage) {
    houseWasteContent[0] = std::move(garbage);
}

// the argument is an instance of the PaperGarbage class.
// If it's squeezed, then it puts that into the paperContent array.
// If the PaperGarbage instance is not squeezed, it raises a DustbinContentError exception
void Dustbin::throwOutPaperGarbage(std::shared_ptr<PaperGarbage> paperGarbage) {
    if ( !paperGarbage->isSqueezed ) {
        throw DustbinContentError();
    }
    paperContent.push_back(paperGarbage);
}

// the argument is an instance of the PlasticGarbage class.
// If it's clean, then it puts that into the plasticContent array.
// If the PlasticGarbage instance is not clean, it raises a DustbinContentError exception
void Dustbin::throwOutPlasticGarbage(std::shared_ptr<PlasticGarbage> plasticGarbage) {
    if ( !plasticGarbage->isClean ) {
        throw DustbinContentError();
    }
    plasticContent.push_back(plasticGarbage);
}


void Dustbin::emptyContents() {
    //houseWasteContent.erase(houseWasteContent.begin(), houseWasteContent.end());
    paperContent.erase(paperContent.begin(), paperContent.end());
    plasticContent.erase(plasticContent.begin(), plasticContent.end());
}