#include <vector>

#include <iostream>

#include "09-mirage-maintenance.h"

using namespace std;

long Solution_09::part1(vector<vector<long>> input)
{
    int ans = 0;

    for (auto i : input) {
        vector<vector<long>> prediction = { i };

        bool allZero;
        int level = 0;
        do {
            level++;
            allZero = true;
            prediction.push_back({});

            for (int col = 1; col < prediction[level-1].size(); col++) {
                prediction[level].push_back(prediction[level-1][col] - prediction[level-1][col-1]);
                allZero = allZero && prediction[level].back() == 0;
            }
        } while (!allZero);

        while (--level >= 0) ans += prediction[level].back();
    }

    return ans;
};

long Solution_09::part2(vector<vector<long>> input)
{
    int ans = 0;

    for (auto i : input) {
        vector<vector<long>> prediction = { i };

        bool allZero;
        int level = 0;
        do {
            level++;
            allZero = true;
            prediction.push_back({});

            for (int col = 1; col < prediction[level-1].size(); col++) {
                prediction[level].push_back(prediction[level-1][col] - prediction[level-1][col-1]);
                allZero = allZero && prediction[level].back() == 0;
            }
        } while (!allZero);

        int pred = 0;
        while (--level >= 0) pred = prediction[level].front() - pred;
        ans += pred;
    }

    return ans;
};
