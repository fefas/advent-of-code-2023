#include <string>
#include <vector>

#include "07-camel-cards.h"

using namespace std;

int Solution_07::part1(vector<pair<string,int>> hands)
{
    int sum = 0;

    for (int i = 0; i < hands.size(); i++) {
        sum += (i + 1) * hands[i].second;
    }

    return sum;
};
