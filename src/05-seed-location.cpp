#include <vector>

#include "05-seed-location.h"

using namespace std;

int Solution_05::part1(vector<int> seeds, vector<vector<vector<int>>> mappings)
{
    for (auto mapping : mappings) {
        for (int i = 0; i < seeds.size(); i++) {
            for (auto ml : mapping ) {
                int destinationStart = ml[0];
                int sourceStart = ml[1];
                int sourceEnd = sourceStart + ml[2];

                if (sourceStart <= seeds[i] && seeds[i] <= sourceEnd) {
                    seeds[i] += destinationStart - sourceStart;
                    break;
                }
            }
        }
    }

    int min = seeds[0];

    for (int i = 0; i < seeds.size(); i++) {
        if (min > seeds[i]) min = seeds[i];
    }

    return min;
}
