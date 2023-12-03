#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "../src/03-gear-ratios.h"

namespace {
    Solution_03 *solution = new Solution_03();

    TEST(GearRatios, noNumber) {
        ASSERT_EQ(0, solution->part1({ "......*.." }));
    }

    TEST(GearRatios, oneAdjacentNumberOfOneDigit) {
        ASSERT_EQ(2, solution->part1({ ".....2*.." }));
    }

    TEST(GearRatios, oneAdjacentNumberOfMultipleDigit) {
        ASSERT_EQ(1403, solution->part1({ "...1403*.." }));
    }

    TEST(GearRatios, twoNumbersButOnlyOneIsAdjacentFromBehing) {
        ASSERT_EQ(1403, solution->part1({ "...1403*.2.." }));
    }

    TEST(GearRatios, twoNumbersButOnlyOneIsAdjacentFromTheFront) {
        ASSERT_EQ(1403, solution->part1({ "..#1403..2.." }));
    }

    TEST(GearRatios, twoAdjacentNumbers) {
        ASSERT_EQ(1405, solution->part1({ "..#1403..2*." }));
    }

    TEST(GearRatios, adjacentNumbersInMultipleRows) {
        ASSERT_EQ(1455, solution->part1({
            ".87....*.2*.",
            "...1403.....",
            "..44......3.",
            "...*....5.@.",
            "....3.......",
        }));
    }

    TEST(GearRatios, exampleScenario) {
        ASSERT_EQ(4361, solution->part1({
            "467..114..",
            "...*......",
            "..35..633.",
            "......#...",
            "617*......",
            ".....+.58.",
            "..592.....",
            "......755.",
            "...$.*....",
            ".664.598..",
        }));
    }
}
