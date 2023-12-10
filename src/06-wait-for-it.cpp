#include <iostream>
#include <cmath>

#include "06-wait-for-it.h"

using namespace std;

int Solution_06::part1(int raceTime, int recordDistance)
{
    int ans = 0;
    float tBest = raceTime / 2.0;
    int t = floor(tBest);
    int currDistance = - t * t + raceTime * t;

    while (currDistance > recordDistance) {
        ans += 2;
        t--;
        currDistance = - t * t + raceTime * t;
    }

    return ans;
}
