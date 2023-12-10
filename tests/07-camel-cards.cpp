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

    TEST(CamelCards, rankedMultipleHands) {
        ASSERT_EQ(7231, solution->part1({
            { "12345", 12 },
            { "AAA11", 1505 },
            { "AAAAA", 1403 },
        }));
    }

    TEST(CamelCards, unrankedMultipleHands) {
        ASSERT_EQ(7231, solution->part1({
            { "AAA11", 1505 },
            { "AAAAA", 1403 },
            { "12345", 12 },
        }));
    }

    TEST(CamelCards, unrankedAllHandTypes) {
        ASSERT_EQ(56, solution->part1({
            { "AAA11", 2 },
            { "12AAA", 3 },
            { "1BBAA", 4 },
            { "AAAAA", 1 },
            { "1AA45", 5 },
            { "12345", 6 },
        }));
    }
}
