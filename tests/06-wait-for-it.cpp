#include <gtest/gtest.h>

#include "../src/06-wait-for-it.h"

namespace {
    Solution_06 *solution = new Solution_06();

    TEST(WaitForIt, oneRaceWithOddTime) {
        ASSERT_EQ(4, solution->part1(7, 9));
    }
}
