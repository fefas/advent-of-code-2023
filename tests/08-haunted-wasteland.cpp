#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "../src/08-haunted-wasteland.h"

using namespace std;

namespace {
    Solution_08 *solution = new Solution_08();

    TEST(HauntedWasteland, oneStep) {
        ASSERT_EQ(1, solution->part1("L", {
            { "AAA", { "ZZZ" , "AAA" } }
        }));
    }
}
