//
// Created by en on 2017.10.22..
//

#include "Dustbin9000.h"
#include "Exceptions.hpp"

Dustbin9000::Dustbin9000() {
    try {
        metalContent = std::unique_ptr<MetalGarbage[]>(new MetalGarbage[metalSize]);
    } catch (std::bad_alloc &err) {
        std::cerr << "Sorry, bad alloc: " << err.what() << std::endl;
    }
    try {
        capContent = std::unique_ptr<BottleCap[]>(new BottleCap[metalSize]);
    } catch (std::bad_alloc &err) {
        std::cerr << "Sorry, bad alloc: " << err.what() << std::endl;
    }
}

void Dustbin9000::throwOutMetalGarbage(MetalGarbage &metalGarbage) {
    if (weight+metalWeight > maxWeight) {
        throw DustbinIsFull();
    }
    if (metalCounter >= metalSize) {
        try {
            std::unique_ptr<MetalGarbage[]> temp(new MetalGarbage[paperSize*2]);
            for (int i = 0; i< metalSize; ++i) {
                temp[i] = std::move(metalContent[i]);
            }
            metalContent = std::move(temp);
        } catch (std::bad_alloc& err) {
            std::cerr<<"sorry, bad alloc: "<<err.what()<<std::endl;
        }
    }
    metalContent[metalCounter] = std::move(metalGarbage);
    ++metalCounter;
    weight += metalWeight;
}

void Dustbin9000::throwOutBottleCap(BottleCap &cap) {
    if (weight+capWeight > maxWeight) {
        throw DustbinIsFull();
    }
    if ( cap.getColor() != "pink" ) {
        throw BottleCapException();
    }
    if (capCounter >= capSize) {
        try {
            std::unique_ptr<BottleCap[]> temp(new BottleCap[capSize * 2]);
            for (int i = 0; i < capSize; ++i) {
                temp[i] = std::move(capContent[i]);
            }
            capContent = std::move(temp);
        } catch (std::bad_alloc &err) {
            std::cerr << "sorry, bad alloc: " << err.what() << std::endl;
        }
    }
    capContent[capCounter] = std::move(cap);
    ++capCounter;
    weight += capWeight;
}

void Dustbin9000::emptyContents() {
    Dustbin::emptyContents();

    metalContent = std::unique_ptr<MetalGarbage[]>(new MetalGarbage[1]);
    capContent = std::unique_ptr<BottleCap[]>(new BottleCap[1]);

    metalSize = 1;
    metalCounter = 0;

    capSize = 1;
    capCounter = 0;
}
