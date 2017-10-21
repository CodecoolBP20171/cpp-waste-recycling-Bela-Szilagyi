#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Dustbin.h"
#include "Garbage.h"
#include "Exceptions.hpp"

int main(int argc, char* argv[]) {

    Dustbin d;
    std::cout<<d.houseWasteContent[0].getName()<<std::endl;
    Garbage garbage("garbage1");
    d.throwOutGarbage(garbage);
    std::cout<<d.houseWasteContent[0].getName()<<std::endl;
    Garbage garbage2("garbage2");
    d.throwOutGarbage(garbage2);
    std::cout<<d.houseWasteContent[1].getName()<<std::endl;
    PaperGarbage paper("paper1");
    try {
        d.throwOutPaperGarbage(paper);
    }
    catch (DustbinContentError &err) {
        std::cout<<"Exception: "<<err.what()<<std::endl;
    }
    paper.squeeze();
    d.throwOutPaperGarbage(paper);
    std::cout<<d.paperContent[0].getName()<<std::endl;
    PaperGarbage paper2("paper2");
    paper2.squeeze();
    d.throwOutPaperGarbage(paper2);
    std::cout<<d.paperContent[1].getName()<<std::endl;
    PlasticGarbage plastic("plastic1");
    plastic.clean();
    try {
        d.throwOutPlasticGarbage(plastic);
    } catch (DustbinIsFull &err) {
        std::cout<<"Exception: "<<err.what()<<std::endl;
    }
    d.emptyContents();
    d.throwOutPlasticGarbage(plastic);
    std::cout<<d.plasticContent[0].getName()<<std::endl;
    PlasticGarbage plastic2("plastic2");
    plastic2.clean();
    d.throwOutPlasticGarbage(plastic2);
    std::cout<<d.plasticContent[1].getName()<<std::endl;
    d.emptyContents();
    //std::cout<<d.houseWasteContent[0].getName()<<std::endl;
    //std::cout<<d.paperContent[0].getName()<<std::endl;
    //std::cout<<d.plasticContent[0].getName()<<std::endl;
    Garbage garbage3("garbage3");
    d.throwOutGarbage(garbage3);
    std::cout<<d.houseWasteContent[0].getName()<<std::endl;
    PaperGarbage paper3("paper3");
    paper3.squeeze();
    d.throwOutPaperGarbage(paper3);
    std::cout<<d.paperContent[0].getName()<<std::endl;
    PlasticGarbage plastic3("plastic3");
    plastic3.clean();
    d.throwOutPlasticGarbage(plastic3);
    std::cout<<d.plasticContent[0].getName()<<std::endl;

/*
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
*/
    return 0;
}