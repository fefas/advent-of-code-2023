#include <gtest/gtest.h>

#include "../src/00-factorial.h"

namespace {
    Solution_00 *solution = new Solution_00();

    TEST(Factorial, zero) {
        ASSERT_EQ(1, solution->fat(0));
    }

    TEST(Factorial, one) {
        ASSERT_EQ(1, solution->fat(1));
    }

    TEST(Factorial, two) {
        ASSERT_EQ(2, solution->fat(2));
    }

    TEST(Factorial, three) {
        ASSERT_EQ(6, solution->fat(3));
    }
}

