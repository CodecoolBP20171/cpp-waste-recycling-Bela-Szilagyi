#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ConsoleInterface.h"

int main(int argc, char* argv[]) {

    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    ConsoleInterface ci;
    ci.run();

    return 0;
}
