#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#include "04-scratchcards.h"

int Solution_04::part1(vector<vector<vector<int>>> cards)
{
    vector<int> winningNumbers = cards[0][0], gottenNumbers = cards[0][1];
    int ans = 0;

    sort(winningNumbers.begin(), winningNumbers.end());
    sort(gottenNumbers.begin(), gottenNumbers.end());

    int i = 0, j = 0, count = 0;
    while (i < gottenNumbers.size() && j < winningNumbers.size()) {
        if (gottenNumbers[i] > winningNumbers[j]) j++;
        else if (gottenNumbers[i] < winningNumbers[j]) i++;
        else {
            count++;
            j++;
            i++;
        }
    }

    ans += count ? pow(2, count - 1) : 0;

    return ans;
}
