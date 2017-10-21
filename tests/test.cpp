//
// Created by en on 2017.10.16..
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../Dustbin.h"

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

TEST_F(ClassDeclaration, test1) {
    d.setColor("orange");
    ASSERT_EQ("orange", d.getColor());
}
