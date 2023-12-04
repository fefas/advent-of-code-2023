#include <vector>

using namespace std;

#include "04-scratchcards.h"

int Solution_04::part1(vector<int> winningNumbers, vector<int> gottenNumbers)
{
    int ans = 0;

    for (int i = 0; i < gottenNumbers.size(); i++) {
        for (int j = 0; j < winningNumbers.size(); j++)
            if (gottenNumbers[i] == winningNumbers[j]) ans++;
    }

    return ans;
}
