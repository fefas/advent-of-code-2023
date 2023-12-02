#include <gtest/gtest.h>
#include <vector>
#include "../src/02-cube-canundrum.h"

using namespace std;

namespace {
    Solution_02 *solution = new Solution_02();

    TEST(CubeCanundrum, noPossibleGame) {
        vector<NumberOfCubes*> games = { new NumberOfCubes(2, 0, 0) };

        ASSERT_EQ(0, solution->findPossibleGames(new NumberOfCubes(1, 0, 0), games));
    }

    TEST(CubeCanundrum, onePossibleGame) {
        vector<NumberOfCubes*> games = { new NumberOfCubes(1, 0, 0) };

        ASSERT_EQ(1, solution->findPossibleGames(new NumberOfCubes(1, 0, 0), games));
    }

    TEST(CubeCanundrum, twoPossibleGames) {
        vector<NumberOfCubes*> games = {
            new NumberOfCubes(2, 0, 0),
            new NumberOfCubes(10, 0, 0),
            new NumberOfCubes(5, 0 , 0),
        };

        ASSERT_EQ(4, solution->findPossibleGames(new NumberOfCubes(7, 0, 0), games));
    }
}

