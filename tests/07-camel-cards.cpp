#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "../src/07-camel-cards.h"

using namespace std;

namespace {
    Solution_07 *solution = new Solution_07();

    TEST(CamelCards, noHands) {
        ASSERT_EQ(0, solution->part1({}));
    }

    TEST(CamelCards, oneHand) {
        ASSERT_EQ(1403, solution->part1({ { "AAAAA", 1403 } }));
    }
}
