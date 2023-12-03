#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "../src/03-gear-ratios.h"

namespace {
    Solution_03 *solution = new Solution_03();

    TEST(GearRatios, noNumber) {
        ASSERT_EQ(0, solution->part1({ "......*.." }));
    }

    TEST(GearRatios, oneNumberOfOneDigit) {
        ASSERT_EQ(2, solution->part1({ ".....2*.." }));
    }
}
