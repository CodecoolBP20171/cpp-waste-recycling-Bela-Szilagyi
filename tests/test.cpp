//
// Created by en on 2017.10.16..
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../Dustbin.h"
#include "../Exceptions.hpp"

using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test {
    public:
        Dustbin d;
        ClassDeclaration() {
            d;
        }
    };
}

TEST_F(ClassDeclaration, testDustbinColor) {
    d.setColor("orange");
    ASSERT_EQ("orange", d.getColor());
}

TEST_F(ClassDeclaration, testThrowOutGarbage) {
    Garbage garbage("garbage1");
    d.throwOutGarbage(garbage);
    ASSERT_EQ("garbage1", d.houseWasteContent[0].getName());
}

TEST_F(ClassDeclaration, testThrowOutSqueezedPaper) {
    PaperGarbage paper("paper1");
    paper.squeeze();
    d.throwOutPaperGarbage(paper);
    ASSERT_EQ("paper1", d.paperContent[0].getName());
}

TEST_F(ClassDeclaration, testFillAfterEmptyContents) {
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
