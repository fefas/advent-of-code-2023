#include <iostream>
#include <vector>
#include "02-cube-canundrum.h"

using namespace std;

int Solution_02::part1(NumberOfCubes *config, vector<Game*> games)
{
    int ans = 0;

    for (int i = 0; i < games.size(); i++) {
        if (games[i]->comply(config)) ans += i + 1;
    }

    return ans;
};

int Solution_02::part2(vector<Game*> games)
{
    return 0;
};
