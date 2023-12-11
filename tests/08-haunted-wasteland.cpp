#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "../src/08-haunted-wasteland.h"

using namespace std;

namespace {
    Solution_08 *solution = new Solution_08();

    TEST(HauntedWasteland, oneStep) {
        ASSERT_EQ(1, solution->part1("L", {
            { "AAA", { "ZZZ" , "AAA" } },
        }));
    }

    TEST(HauntedWasteland, twoStepGoingOnlyLeft) {
        ASSERT_EQ(2, solution->part1("L", {
            { "AAA", { "BBB" , "AAA" } },
            { "BBB", { "ZZZ" , "AAA" } },
        }));
    }

    TEST(HauntedWasteland, stepsGoingRightAndLeft) {
        ASSERT_EQ(4, solution->part1("RL", {
            { "AAA", { "BBB" , "AAA" } },
            { "BBB", { "ZZZ" , "BBB" } },
        }));
    }

    TEST(HauntedWasteland, sampleInput1) {
        ASSERT_EQ(2, solution->part1("RL", {
            { "AAA", { "BBB", "CCC" } },
            { "BBB", { "DDD", "EEE" } },
            { "CCC", { "ZZZ", "GGG" } },
            { "DDD", { "DDD", "DDD" } },
            { "EEE", { "EEE", "EEE" } },
            { "GGG", { "GGG", "GGG" } },
            { "ZZZ", { "ZZZ", "ZZZ" } },
        }));
    }

    TEST(HauntedWasteland, sampleInput2) {
        ASSERT_EQ(6, solution->part1("LLR", {
            { "AAA", { "BBB", "BBB" } },
            { "BBB", { "AAA", "ZZZ" } },
            { "ZZZ", { "ZZZ", "ZZZ" } },
        }));
    }
}
