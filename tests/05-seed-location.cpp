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

    TEST(SeedLocation, threeSeedsAndWithOneSimpleMapping) {
        ASSERT_EQ(6, solution->part1({ 79, 23, 14 }, {
            { { 2, 75, 10 } },
        }));
    }

    TEST(SeedLocation, threeSeedsAndWithTwoSimpleMappings) {
        ASSERT_EQ(2, solution->part1({ 79, 23, 14 }, {
            { { 2, 75, 10 } },
            { { 1, 22, 10 } },
        }));
    }

    TEST(SeedLocation, threeSeedsAndMappings) {
        ASSERT_EQ(2, solution->part1({ 79, 23, 14 }, {
            { { 2, 75, 10 }, { 1, 22, 10 } },
        }));
    }

    TEST(SeedLocation, SampleInput) {
        ASSERT_EQ(35, solution->part1({ 79, 14, 55, 13 }, {
            {
                { 50, 98, 2 },
                { 52, 50, 48 },
            },
            {
                { 0, 15, 37 },
                { 37, 52, 2 },
                { 39, 0, 15 },
            },
            {
                { 49, 53, 8 },
                { 0, 11, 42 },
                { 42, 0, 7 },
                { 57, 7, 4 },
            },
            {
                { 88, 18, 7 },
                { 18, 25, 70 },
            },
            {
                { 45, 77, 23 },
                { 81, 45, 19 },
                { 68, 64, 13 },
            },
            {
                { 0, 69, 1 },
                { 1, 0, 69 },
            },
            {
                { 60, 56, 37 },
                { 56, 93, 4 },
            },
        }));
    }
}
