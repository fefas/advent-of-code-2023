#include <gtest/gtest.h>
#include <vector>

#include "../src/09-mirage-maintenance.h"

using namespace std;

namespace {
    Solution_09 *solution = new Solution_09();

    TEST(MirageMaintenance, firstSample) {
        ASSERT_EQ(18, solution->part1({ { 0, 3, 6, 9, 12, 15 } }));
    }

    TEST(MirageMaintenance, secondSample) {
        ASSERT_EQ(28, solution->part1({ { 1, 3, 6, 10, 15, 21 } }));
    }

    TEST(MirageMaintenance, thirdSample) {
        ASSERT_EQ(68, solution->part1({ { 10, 13, 16, 21, 30, 45 } }));
    }

    TEST(MirageMaintenance, sampleInput) {
        ASSERT_EQ(114, solution->part1({
            {  0,  3,  6,  9, 12, 15 },
            {  1,  3,  6, 10, 15, 21 },
            { 10, 13, 16, 21, 30, 45 },
        }));
    }
}
