#include <gtest/gtest.h>
#include <vector>

#include "../src/09-mirage-maintenance.h"

using namespace std;

namespace {
    Solution_09 *solution = new Solution_09();

    TEST(MirageMaintenance, firstSample) {
        ASSERT_EQ(18, solution->part1({ 0, 3, 6, 9, 12, 15 }));
    }
}
