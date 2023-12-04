#include <gtest/gtest.h>
#include <vector>

#include "../src/04-scratchcards.h"

using namespace std;

namespace {
    Solution_04 *solution = new Solution_04();

    TEST(Scratchcards, oneCardAndNoMatchingNumber) {
        ASSERT_EQ(0, solution->part1({ 2, 4, 5 }, { 3 }));
    }

    TEST(Scratchcards, oneCardAndOneMatchingNumber) {
        ASSERT_EQ(1, solution->part1({ 2, 3, 5 }, { 3 }));
    }

    TEST(Scratchcards, oneSortedCardAndTwoMatchingNumbers) {
        ASSERT_EQ(2, solution->part1({ 2, 3, 5 }, { 3, 5 }));
    }
}
