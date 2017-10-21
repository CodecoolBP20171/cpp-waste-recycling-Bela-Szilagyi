//
// Created by en on 2017.10.16..
//

#include "Dustbin.h"
#include "DustbinContentError.hpp"

Dustbin::Dustbin() {
    try {
        houseWasteContent = std::unique_ptr<Garbage[]>(new Garbage[garbageSize]);
    } catch (std::bad_alloc& err) {
        std::cerr<<"sorry, bad alloc: "<<err.what()<<std::endl;
    }
    try {
        plasticContent = std::unique_ptr<PlasticGarbage[]>(new PlasticGarbage[plasticSize]);
    } catch (std::bad_alloc& err) {
        std::cerr<<"sorry, bad alloc: "<<err.what()<<std::endl;
    }
    try {
        paperContent = std::unique_ptr<PaperGarbage[]>(new PaperGarbage[paperSize]);
    } catch (std::bad_alloc& err) {
        std::cerr<<"sorry, bad alloc: "<<err.what()<<std::endl;
    }
}

void Dustbin::throwOutGarbage(Garbage &garbage) {
    if (garbageCounter >= garbageSize) {
        try {
            std::unique_ptr<Garbage[]> temp(new Garbage[garbageSize*2]);
            for (int i = 0; i< garbageSize; ++i) {
                temp[i] = std::move(houseWasteContent[i]);
            }
            houseWasteContent = std::move(temp);
        } catch (std::bad_alloc& err) {
            std::cerr<<"sorry, bad alloc: "<<err.what()<<std::endl;
        }
    }
    houseWasteContent[garbageCounter] = std::move(garbage);
    ++garbageCounter;
}

// the argument is an instance of the PaperGarbage class.
// If it's squeezed, then it puts that into the paperContent array.
// If the PaperGarbage instance is not squeezed, it raises a DustbinContentError exception
void Dustbin::throwOutPaperGarbage(PaperGarbage &paperGarbage) {
    if ( !paperGarbage.isSqueezed ) {
        throw DustbinContentError();
    }
    if (paperCounter >= paperSize) {
        try {
            std::unique_ptr<PaperGarbage[]> temp(new PaperGarbage[paperSize*2]);
            for (int i = 0; i< paperSize; ++i) {
                temp[i] = std::move(paperContent[i]);
            }
            paperContent = std::move(temp);
        } catch (std::bad_alloc& err) {
            std::cerr<<"sorry, bad alloc: "<<err.what()<<std::endl;
        }
    }
    paperContent[paperCounter] = std::move(paperGarbage);
    ++paperCounter;
}

// the argument is an instance of the PlasticGarbage class.
// If it's clean, then it puts that into the plasticContent array.
// If the PlasticGarbage instance is not clean, it raises a DustbinContentError exception
void Dustbin::throwOutPlasticGarbage(PlasticGarbage &plasticGarbage) {
    if ( !plasticGarbage.isClean ) {
        throw DustbinContentError();
    }
    if (plasticCounter >= plasticSize) {
        try {
            std::unique_ptr<PlasticGarbage[]> temp(new PlasticGarbage[plasticSize * 2]);
            for (int i = 0; i < plasticSize; ++i) {
                temp[i] = std::move(plasticContent[i]);
            }
            plasticContent = std::move(temp);
        } catch (std::bad_alloc &err) {
            std::cerr << "sorry, bad alloc: " << err.what() << std::endl;
        }
    }
    plasticContent[plasticCounter] = std::move(plasticGarbage);
    ++plasticCounter;
}

void Dustbin::emptyContents() {
    houseWasteContent = std::unique_ptr<Garbage[]>(new Garbage[1]);
    plasticContent = std::unique_ptr<PlasticGarbage[]>(new PlasticGarbage[1]);
    paperContent = std::unique_ptr<PaperGarbage[]>(new PaperGarbage[1]);

    paperSize = 1;
    paperCounter = 0;
    plasticSize = 1;
    plasticCounter = 0;
    garbageSize = 1;
    garbageCounter = 0;

    //houseWasteContent.erase(houseWasteContent.begin(), houseWasteContent.end());
    //paperContent.erase(paperContent.begin(), paperContent.end());
    //plasticContent.erase(plasticContent.begin(), plasticContent.end());
}