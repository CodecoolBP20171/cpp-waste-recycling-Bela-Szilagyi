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

TEST_F(dustbin, testThrowOutGarbage) {
    Garbage garbage("garbage1");
    d.throwOutGarbage(garbage);
    ASSERT_EQ("garbage1", d.houseWasteContent[0].getName());
}

TEST_F(dustbin, testThrowOutSqueezedPaper) {
    PaperGarbage paper("paper1");
    paper.squeeze();
    d.throwOutPaperGarbage(paper);
    ASSERT_EQ("paper1", d.paperContent[0].getName());
}

TEST_F(dustbin, testFillAfterEmptyContents) {
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
    d.emptyContents();
    d.throwOutPlasticGarbage(plastic);
    ASSERT_EQ("plastic1", d.plasticContent[0].getName());
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

TEST_F(dustbin9000, testThrowOutGarbage) {
    Garbage garbage("garbage9000");
    d9000.throwOutGarbage(garbage);
    ASSERT_EQ("garbage9000", d9000.houseWasteContent[0].getName());
}

TEST_F(dustbin9000, testThrowOutMetalGarbage) {
    MetalGarbage metal("metal9000");
    d9000.throwOutMetalGarbage(metal);
    ASSERT_EQ("metal9000", d9000.metalContent[0].getName());
}
