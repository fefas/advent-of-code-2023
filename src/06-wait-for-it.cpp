#include <iostream>
#include <cmath>

#include "06-wait-for-it.h"

using namespace std;

int Solution_06::part1(int raceTime, int recordDistance)
{
    int ans = (raceTime % 2) ? 2 : 1;
    int tBest = raceTime / 2;
    int t = tBest - 1;
    int currDistance = - t * t + raceTime * t;

    while (currDistance > recordDistance) {
        ans += 2;
        t--;
        currDistance = - t * t + raceTime * t;
    }

    return ans;
}
