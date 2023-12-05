#include <vector>

#include "05-seed-location.h"

using namespace std;

int Solution_05::part1(vector<int> seeds, vector<vector<vector<int>>> mappings)
{
    for (auto mapping : mappings) {
        for (auto ml : mapping ) {
            int sourceStart = ml[0];
            int sourceEnd = sourceStart + ml[2];
            int destinationStart = ml[1];

            for (int i = 0; i < seeds.size(); i++) {
                if (seeds[i] >= sourceStart && seeds[0] <= sourceEnd)
                    seeds[i] += destinationStart - sourceStart;
            }
        }
    }

    int min = seeds[0];

    for (int i = 0; i < seeds.size(); i++) {
        if (min > seeds[i]) min = seeds[i];
    }

    return min;
}

