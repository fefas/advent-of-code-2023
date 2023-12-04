#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#include "04-scratchcards.h"

class Card
{
    private:
    vector<int> winningNumbers;
    vector<int> gottenNumbers;

    public:
    static vector<Card*> processInput(vector<vector<vector<int>>> input)
    {
        vector<Card*> cards;

        for (auto i : input)
            cards.push_back(new Card(i));

        return cards;
    }

    Card(vector<vector<int>> input) : winningNumbers(input[0]), gottenNumbers(input[1])
    {
        sort(winningNumbers.begin(), winningNumbers.end());
        sort(gottenNumbers.begin(), gottenNumbers.end());
    }

    int countMatches()
    {
        int i = 0, j = 0, count = 0;

        while (i < gottenNumbers.size() && j < winningNumbers.size()) {
            if (gottenNumbers[i] > winningNumbers[j]) {
                j++;
                continue;
            }
            else if (gottenNumbers[i] < winningNumbers[j]) {
                i++;
                continue;
            }

            count++;
            j++;
            i++;
        }

        return count;
    }
};

static int countPoints(vector<Card*> cards)
{
    int ans = 0;

    for (auto c : cards) {
        int count = c->countMatches();
        ans += count ? pow(2, count - 1) : 0;
    }

    return ans;
};

int Solution_04::part1(vector<vector<vector<int>>> input)
{
    return countPoints(Card::processInput(input));
}
