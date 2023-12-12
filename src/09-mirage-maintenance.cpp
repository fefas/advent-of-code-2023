#include <vector>

#include <iostream>

#include "09-mirage-maintenance.h"

using namespace std;

int Solution_09::part1(vector<vector<int>> input)
{
    int ans = 0;

    for (auto i : input) {
        vector<vector<int>> prediction = { i };

        int levelSum, level = 0;
        do {
            level++;
            levelSum = 0;
            prediction.push_back({});

            for (int col = 1; col < prediction[level-1].size(); col++) {
                prediction[level].push_back(prediction[level-1][col] - prediction[level-1][col-1]);
                levelSum += prediction[level].back();
            }
        } while (levelSum);

        prediction.back().push_back(0);
        while (--level >= 0) prediction[level].push_back(prediction[level].back() + prediction[level+1].back());

        ans += prediction[0].back();
    }

    return ans;
};
