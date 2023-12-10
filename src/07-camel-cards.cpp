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
        map<char,short> aCount, bCount;
        map<char,short> cardStrength = {
            { 'A', 13 },
            { 'K', 12 },
            { 'Q', 11 },
            { 'J', 10 },
            { 'T',  9 },
            { '9',  8 },
            { '8',  7 },
            { '7',  6 },
            { '6',  5 },
            { '5',  4 },
            { '4',  3 },
            { '3',  2 },
            { '2',  1 },
        };

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

        if (aPoint != bPoint) return aPoint < bPoint;

        for (int i = 0; i < 5; i++) {
            if (cardStrength[a.first[i]] != cardStrength[b.first[i]]) return cardStrength[a.first[i]] < cardStrength[b.first[i]];
        }

        return false;
    });

    for (int i = 0; i < hands.size(); i++) {
        sum += (i + 1) * hands[i].second;
    }

    return sum;
};
