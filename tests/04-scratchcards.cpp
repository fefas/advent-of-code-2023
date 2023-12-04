#include <gtest/gtest.h>
#include <vector>

#include "../src/04-scratchcards.h"

using namespace std;

namespace {
    Solution_04 *solution = new Solution_04();

    TEST(Scratchcards, oneCardAndNoMatchingNumber) {
        ASSERT_EQ(0, solution->part1({
            { { 2, 4, 5 }, { 3 } },
        }));
    }

    TEST(Scratchcards, oneCardAndOneMatchingNumber) {
        ASSERT_EQ(1, solution->part1({
            { { 2, 3, 5 }, { 3 } },
        }));
    }

    TEST(Scratchcards, oneSortedCardAndTwoMatchingNumbers) {
        ASSERT_EQ(2, solution->part1({
            { { 2, 3, 5 }, { 3, 5 } },
        }));
    }

    TEST(Scratchcards, oneSortedCardAndThreeMatchingNumbers) {
        ASSERT_EQ(4, solution->part1({
            { { 2, 3, 5, 7, 8 }, { 3, 5, 7 } },
        }));
    }

    TEST(Scratchcards, oneSortedCardAndFiveMatchingNumbers) {
        ASSERT_EQ(16, solution->part1({
            { { 1, 2, 3, 5, 7, 8, 11, 13 }, { 1, 3, 5, 7, 11 } },
        }));
    }

    TEST(Scratchcards, oneUnsortedCardAndFiveMatchingNumbers) {
        ASSERT_EQ(16, solution->part1({
            { { 7, 11, 1, 5, 2, 8, 13, 3 }, { 3, 1, 7, 5, 11 } },
        }));
    }

    TEST(Scratchcards, twoUnsortedCardWithMultipleMatchings) {
        ASSERT_EQ(18, solution->part1({
            { { 7, 11, 1, 5, 2, 8, 13, 3 }, { 3, 1, 7, 5, 11 } },
            { { 7, 3, 2, 8, 5 }, { 3, 8 } },
        }));
    }

    TEST(Scratchcards, sampleCards) {
        ASSERT_EQ(13, solution->part1({
            { { 41, 48, 83, 86, 17 }, { 83, 86,  6, 31, 17,  9, 48, 53 } },
            { { 13, 32, 20, 16, 61 }, { 61, 30, 68, 82, 17, 32, 24, 19 } },
            { {  1, 21, 53, 59, 44 }, { 69, 82, 63, 72, 16, 21, 14,  1 } },
            { { 41, 92, 73, 84, 69 }, { 59, 84, 76, 51, 58,  5, 54, 83 } },
            { { 87, 83, 26, 28, 32 }, { 88, 30, 70, 12, 93, 22, 82, 36 } },
            { { 31, 18, 13, 56, 72 }, { 74, 77, 10, 23, 35, 67, 36, 11 } },
        }));
    }
}
