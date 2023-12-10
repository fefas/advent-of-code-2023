#include <map>

#include "06-wait-for-it.h"

using namespace std;

int Solution_06::part1(map<int, int> input)
{
    int ans = 1;

    for (auto x : input) {
        int raceTime = x.first;
        int recordDistance = x.second;

        int count = (raceTime % 2) ? 2 : 1;
        int t = raceTime / 2 - 1;
        int currDistance = - t * t + raceTime * t;

        while (currDistance > recordDistance) {
            count += 2;
            t--;
            currDistance = - t * t + raceTime * t;
        }

        ans *= count;
    }

    return ans;
}
