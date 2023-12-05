#include <gtest/gtest.h>
#include <vector>

#include "../src/05-seed-location.h"

using namespace std;

namespace {
    Solution_05 *solution = new Solution_05();

    TEST(SeedLocation, oneSeedAndWithNoMapping) {
        ASSERT_EQ(10, solution->part1({ 10 }, {}));
    }

    TEST(SeedLocation, threeSeedsAndWithNoMapping) {
        ASSERT_EQ(14, solution->part1({ 79, 23, 14 }, {}));
    }
}
