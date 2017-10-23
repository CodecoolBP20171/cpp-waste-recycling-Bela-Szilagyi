//
// Created by en on 2017.10.16..
//

#include "Dustbin.h"
#include "Exceptions.hpp"

Dustbin::Dustbin() {
    try {
        houseWasteContent = std::unique_ptr<Garbage[]>(new Garbage[garbageSize]);
    } catch (std::bad_alloc& err) {
        std::cerr<<"Sorry, bad alloc: "<<err.what()<<std::endl;
    }
    try {
        plasticContent = std::unique_ptr<PlasticGarbage[]>(new PlasticGarbage[plasticSize]);
    } catch (std::bad_alloc& err) {
        std::cerr<<"Sorry, bad alloc: "<<err.what()<<std::endl;
    }
    try {
        paperContent = std::unique_ptr<PaperGarbage[]>(new PaperGarbage[paperSize]);
    } catch (std::bad_alloc& err) {
        std::cerr<<"Sorry, bad alloc: "<<err.what()<<std::endl;
    }
}

void Dustbin::throwOutGarbage(Garbage &garbage) {
    if (weight+garbageWeight > maxWeight) {
        throw DustbinIsFull();
    }
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
    weight += garbageWeight;
}

void Dustbin::throwOutPaperGarbage(PaperGarbage &paperGarbage) {
    if (weight+paperWeight > maxWeight) {
        throw DustbinIsFull();
    }
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
    weight += paperWeight;
}

void Dustbin::throwOutPlasticGarbage(PlasticGarbage &plasticGarbage) {
    if (weight+plasticWeight > maxWeight) {
        throw DustbinIsFull();
    }
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
    weight += plasticWeight;
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
    weight = 0;
}

const std::string &Dustbin::getColor() const {
    return color;
}

void Dustbin::setColor(const std::string &color) {
    Dustbin::color = color;
}
