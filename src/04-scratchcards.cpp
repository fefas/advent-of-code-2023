#include <vector>
#include <cmath>

using namespace std;

#include "04-scratchcards.h"

int Solution_04::part1(vector<int> winningNumbers, vector<int> gottenNumbers)
{
    int ans = 0;

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
