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
