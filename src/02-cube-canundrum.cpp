#include <iostream>
#include <vector>
#include "02-cube-canundrum.h"

using namespace std;

int Solution_02::findPossibleGames(NumberOfCubes *config, vector<NumberOfCubes*> rounds)
{
    int ans = 0;

    for (int game = 0; game < rounds.size(); game++) {
        if (config->fit(rounds[game])) ans += game + 1;
    }

    return ans;
};
