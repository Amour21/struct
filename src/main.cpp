#include <gtest/gtest.h>
#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include "stack.h"
#include "queue.h"
#include "stack_min.h"


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::FLAGS_gtest_color = "yes";
    return RUN_ALL_TESTS();
}