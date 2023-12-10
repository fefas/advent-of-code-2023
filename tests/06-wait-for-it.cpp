#include <gtest/gtest.h>

#include "../src/06-wait-for-it.h"

namespace {
    Solution_06 *solution = new Solution_06();

    TEST(WaitForIt, zero) {
        ASSERT_EQ(0, solution->part1());
    }
}

