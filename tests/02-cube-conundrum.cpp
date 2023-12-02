#include <gtest/gtest.h>
#include <vector>
#include "../src/02-cube-canundrum.h"

using namespace std;

namespace {
    Solution_02 *solution = new Solution_02();

    TEST(CubeCanundrum, noPossibleGame) {
        vector<NumberOfCubes*> games = {};

        ASSERT_EQ(0, solution->findPossibleGames(new NumberOfCubes(1, 0, 0), games));
    }
}

