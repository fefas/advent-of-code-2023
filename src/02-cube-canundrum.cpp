#include <iostream>
#include <vector>
#include "02-cube-canundrum.h"

using namespace std;

int Solution_02::findPossibleGames(NumberOfCubes *config, vector<NumberOfCubes*> rounds)
{
    return config->blue >= rounds[0]->blue ? 1 : 0;
};
