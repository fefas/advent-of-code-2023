#include <algorithm>
#include <map>
#include <string>
#include <vector>

#include "07-camel-cards.h"

using namespace std;

int Solution_07::part1(vector<pair<string,int>> hands)
{
    int sum = 0;

    sort(hands.begin(), hands.end(), [](pair<string,int> a, pair<string, int> b) {
        map<char, short> aCount, bCount;

        for (auto c : a.first) aCount[c]++;
        for (auto c : b.first) bCount[c]++;

        short aPoint = 0, bPoint = 0;

        for (auto c : aCount) {
            if (c.second == 5) {
                aPoint = c.second;
                break;
            }
            if (c.second == 3) {
                aPoint = (aCount.size() == 2) ? 4 : 3;
                break;
            }
            if (c.second == 2) {
                aPoint = (aCount.size() == 2) ? 4 : ((aCount.size() == 3) ? 2 : 1);
                break;
            }
        }

        for (auto c : bCount) {
            if (c.second == 5) {
                bPoint = c.second;
                break;
            }
            if (c.second == 3) {
                bPoint = (bCount.size() == 2) ? 4 : 3;
                break;
            }
            if (c.second == 2) {
                bPoint = (bCount.size() == 2) ? 4 : ((bCount.size() == 3) ? 2 : 1);
                break;
            }
        }

        return aPoint < bPoint;
    });

    for (int i = 0; i < hands.size(); i++) {
        sum += (i + 1) * hands[i].second;
    }

    return sum;
};
