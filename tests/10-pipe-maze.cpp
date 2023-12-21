#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "../src/10-pipe-maze.h"

using namespace std;

namespace {
    Solution_10 *solution = new Solution_10();

    TEST(PipeMaze, firstSampleStartingOn1comma1) {
        ASSERT_EQ(2, solution->part1({
            "....",
            ".S7.",
            ".LJ.",
            "....",
        }));
    }

    TEST(PipeMaze, secondSampleStartingOn1comma1) {
        ASSERT_EQ(4, solution->part1({
            ".....",
            ".S-7.",
            ".|.|.",
            ".L-J.",
            ".....",
        }));
    }

    TEST(PipeMaze, thirdSampleStartingOn1comma1) {
        ASSERT_EQ(6, solution->part1({
            ".......",
            ".S-7...",
            ".|.L-7.",
            ".L---J.",
            ".......",
        }));
    }

    TEST(PipeMaze, fourthSampleStartingOn1comma1) {
        ASSERT_EQ(15, solution->part1({
            "..........",
            ".S-7F---7.",
            ".|.LJ...|.",
            ".L-7F---J.",
            ".F-JL7....",
            ".L---J....",
            "..........",
        }));
    }

    TEST(PipeMaze, sampleWithDotBoxed) {
        ASSERT_EQ(8, solution->part1({
            "7-F7-",
            ".SJ|7",
            "FJLL7",
            "|F--J",
            "LJ.LJ",
        }));
    }

    TEST(PipeMaze, sampleFindRandomStartingPoint) {
        ASSERT_EQ(8, solution->part1({
            "7-F7-",
            ".FJ|7",
            "SJLL7",
            "|F--J",
            "LJ.LJ",
        }));
    }
}
