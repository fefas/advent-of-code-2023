#include <gtest/gtest.h>
#include <vector>

#include "../src/04-scratchcards.h"

using namespace std;

namespace {
    Solution_04 *solution = new Solution_04();

    TEST(Scratchcards, oneCardsAndNoMatching) {
        ASSERT_EQ(0, solution->part1({ 2, 4, 5 }, { 3 }));
    }
}
