#include <map>

#include "06-wait-for-it.h"

using namespace std;

long calcDistance(long raceTime, long holdingTime)
{
    return holdingTime * (raceTime - holdingTime);
}

int Solution_06::solve(map<long, long> input)
{
    int ans = 1;

    for (auto x : input) {
        long raceTime = x.first;
        long recordDistance = x.second;

        long count = 1 + raceTime % 2;
        for (long t = raceTime / 2 - 1; calcDistance(raceTime, t) > recordDistance; t--)
            count += 2;

        ans *= count;
    }

    return ans;
}
