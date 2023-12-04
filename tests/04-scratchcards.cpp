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
}
