//
// Created by en on 2017.10.16..
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../Dustbin.h"
#include "../Exceptions.hpp"
#include "../Dustbin9000.h"

using testing::Eq;

namespace {
    class dustbin : public testing::Test {
    public:
        Dustbin d;
        dustbin() {
            d;
        }
    };
}

TEST_F(dustbin, testDustbinColor) {
    d.setColor("orange");
    ASSERT_EQ("orange", d.getColor());
}

TEST_F(dustbin, createGarbage) {
    Garbage garbage("garbage1");
    ASSERT_EQ("garbage1", garbage.getName());
}

TEST_F(dustbin, squeezePaper) {
    PaperGarbage paper("paper1");
    paper.squeeze();
    ASSERT_EQ(true, paper.isSqueezed);
}

TEST(paperNotSqueezed, what)
{
    Dustbin d;
    PaperGarbage paper("paper1");
    try {
        d.throwOutPaperGarbage(paper);
    } catch (DustbinContentError &err) {
        EXPECT_STREQ("The alarm is switched on because of DustbinContentError", err.what());
    }
}

TEST(plasticNotCleaned, what)
{
    Dustbin d;
    PlasticGarbage plastic("plastic1");
    try {
        d.throwOutPlasticGarbage(plastic);
    } catch (DustbinContentError &err) {
        EXPECT_STREQ("The alarm is switched on because of DustbinContentError", err.what());
    }
}

TEST(dustbinIsFull, what)
{
    Dustbin d;
    Garbage garbage("garbage1");
    d.throwOutGarbage(garbage);
    Garbage garbage2("garbage2");
    d.throwOutGarbage(garbage2);
    PaperGarbage paper("paper1");
    paper.squeeze();
    d.throwOutPaperGarbage(paper);
    PaperGarbage paper2("paper2");
    paper2.squeeze();
    d.throwOutPaperGarbage(paper2);
    PlasticGarbage plastic("plastic1");
    plastic.clean();
    try {
        d.throwOutPlasticGarbage(plastic);
    } catch (DustbinIsFull &err) {
        EXPECT_STREQ("Dustbin is full! You have to empty it before throwing out any more garbage!", err.what());
    }
}

namespace {
    class dustbin9000 : public testing::Test {
    public:
        Dustbin9000 d9000;
        dustbin9000() {
            d9000;
        }
    };
}

TEST_F(dustbin9000, testDustbinColor) {
    d9000.setColor("red");
    ASSERT_EQ("red", d9000.getColor());
}

TEST_F(dustbin9000, testCreateMetalGarbage) {
    MetalGarbage metal("metal9000");
    ASSERT_EQ("metal9000", metal.getName());
}

TEST(capNotPink, what)
{
    Dustbin9000 d9000;
    BottleCap redCap("KetchupCap", "red");
    try {
        d9000.throwOutBottleCap(redCap);
    } catch (BottleCapException &err) {
        EXPECT_STREQ("Sorry, but it is a non-pink cap, therefore I have to fire it back to your face. You should run!", err.what());
    }
}

TEST(dustbin9000IsFull, what)
{
    Dustbin9000 d9000;
    PaperGarbage paper9001("paper9001");
    paper9001.squeeze();
    d9000.throwOutPaperGarbage(paper9001);
    MetalGarbage metal9001("metal9001");
    d9000.throwOutMetalGarbage(metal9001);
    MetalGarbage metal9002("metal9002");
    try {
        d9000.throwOutMetalGarbage(metal9002);;
    } catch (DustbinIsFull &err) {
        EXPECT_STREQ("Dustbin is full! You have to empty it before throwing out any more garbage!", err.what());
    }
}
