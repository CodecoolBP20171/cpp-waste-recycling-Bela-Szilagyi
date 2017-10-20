#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Dustbin.h"
#include "Garbage.h"

int main(int argc, char* argv[]) {

    Dustbin d;
    Garbage garbage("garbage1");
    d.throwOutGarbage(garbage);
    std::cout<<d.houseWasteContent[0].getName()<<std::endl;
/*
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
*/
    return 0;
}