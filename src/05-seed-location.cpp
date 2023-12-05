#include <vector>

#include "05-seed-location.h"

using namespace std;

int Solution_05::part1(vector<int> seeds, vector<vector<vector<int>>> mappings)
{
    int min = seeds[0];

    for (int i = 0; i < seeds.size(); i++) {
        if (min > seeds[i]) min = seeds[i];
    }

    return min;
}

