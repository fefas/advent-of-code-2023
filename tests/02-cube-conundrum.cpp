#include <gtest/gtest.h>
#include <vector>
#include "../src/02-cube-canundrum.h"

using namespace std;

namespace {
    Solution_02 *solution = new Solution_02();

    TEST(CubeCanundrum, noPossibleGameWithBlueCubesOnly) {
        vector<Game*> games = { new Game({ new NumberOfCubes(2, 0, 0) }) };

        ASSERT_EQ(0, solution->findPossibleGames(new NumberOfCubes(1, 0, 0), games));
    }

    TEST(CubeCanundrum, onePossibleGameWithBlueCubesOnly) {
        vector<Game*> games = { new Game({ new NumberOfCubes(1, 0, 0) }) };

        ASSERT_EQ(1, solution->findPossibleGames(new NumberOfCubes(1, 0, 0), games));
    }

    TEST(CubeCanundrum, twoPossibleGamesWithBlueCubes) {
        vector<Game*> games = {
            new Game({ new NumberOfCubes(2, 0, 0) }),
            new Game({ new NumberOfCubes(10, 0, 0) }),
            new Game({ new NumberOfCubes(5, 0 , 0) }),
        };

        ASSERT_EQ(4, solution->findPossibleGames(new NumberOfCubes(7, 0, 0), games));
    }

    TEST(CubeCanundrum, threePossibleGamesWithCubesOfAllColors) {
        vector<Game*> games = {
            new Game({ new NumberOfCubes(2, 0, 4) }),
            new Game({ new NumberOfCubes(10, 4, 0) }),
            new Game({ new NumberOfCubes(5, 3, 10) }),
            new Game({ new NumberOfCubes(5, 10, 0) }),
            new Game({ new NumberOfCubes(2, 5, 0) }),
            new Game({ new NumberOfCubes(5, 6, 0) }),
        };

        ASSERT_EQ(9, solution->findPossibleGames(new NumberOfCubes(7, 5, 10), games));
    }

    TEST(CubeCanundrum, threePossibleGamesWithMultipleRoundsAndAllColors) {
        vector<Game*> games = {
            new Game({ new NumberOfCubes(2, 0, 4), new NumberOfCubes(10, 4, 0) }),
            new Game({ new NumberOfCubes(2, 0, 4), new NumberOfCubes(6, 4, 0) }),
            new Game({ new NumberOfCubes(4, 0, 3), new NumberOfCubes(5, 10, 0) }),
            new Game({ new NumberOfCubes(5, 2, 0), new NumberOfCubes(5, 0, 10) }),
        };

        ASSERT_EQ(6, solution->findPossibleGames(new NumberOfCubes(7, 5, 10), games));
    }
}

