#include <gtest/gtest.h>
#include <vector>

#include "../src/06-wait-for-it.h"

namespace {
    Solution_06 *solution = new Solution_06();
//    vector<vector<int>> input;

    TEST(WaitForIt, oneRaceWithOddTime) {
        ASSERT_EQ(4, solution->part1({ { 7, 9 } }));
    }

    TEST(WaitForIt, oneRaceWithEvenTime) {
        ASSERT_EQ(9, solution->part1({ { 30, 200 } }));
    }

    TEST(WaitForIt, oneRaceWithEvenTimasdasd) {
        ASSERT_EQ(71503, solution->part1({ { 71530, 940200 } }));
    }

    TEST(WaitForIt, sampleInput) {
        ASSERT_EQ(288, solution->part1({
            { 7, 9 },
            { 15, 40 },
            { 30, 200 },
        }));
    }

    TEST(WaitForIt, myPuzzleInput) {
        ASSERT_EQ(6209190, solution->part1({
            { 40, 215 },
            { 92, 1064 },
            { 97, 1505 },
            { 90, 1100 },
        }));

        ASSERT_EQ(28545089, solution->part1({
            { 40929790, 215106415051100 },
        }));
    }
}
