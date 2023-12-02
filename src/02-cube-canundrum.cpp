#include <iostream>
#include <vector>
#include "02-cube-canundrum.h"

using namespace std;

int Solution_02::findPossibleGames(NumberOfCubes *config, vector<Game*> games)
{
    int ans = 0;

    for (int i = 0; i < games.size(); i++) {
        if (config->fit(games[i]->rounds[0])) ans += i + 1;
    }

    return ans;
};
