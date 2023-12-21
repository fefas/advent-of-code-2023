#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "../src/10-pipe-maze.h"

using namespace std;

namespace {
    Solution_10 *solution = new Solution_10();

    TEST(PipeMaze, firstSample) {
        ASSERT_EQ(2, solution->part1({
            "....",
            ".F7.",
            ".LJ.",
            "....",
        }));
    }
}
