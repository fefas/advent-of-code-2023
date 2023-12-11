#include <algorithm>
#include <cmath>
#include <map>
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

        for (int i = 0; i < input.size(); i++) cards.push_back(new Card(input[i]));

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

    int countPoints()
    {
        int nMatches = countMatches();

        return nMatches ? pow(2, nMatches - 1) : 0;
    }
};

static int countPoints(vector<Card*> cards)
{
    int ans = 0;

    for (auto c : cards) ans += c->countPoints();

    return ans;
};

static int countCopies(vector<Card*> cards)
{
    map<int, int> occurences;

    for (int i = 0; i < cards.size(); i++) {
        int nOccurences = ++occurences[i];
        int nMatches = cards[i]->countMatches();

        for (int j = 1; j <= nMatches; j++) occurences[i+j] += nOccurences;
    }

    int ans = 0;
    for (int i = 0; i < cards.size(); i++) ans += occurences[i];

    return ans;
};

int Solution_04::part1(vector<vector<vector<int>>> input)
{
    return countPoints(Card::processInput(input));
}

int Solution_04::part2(vector<vector<vector<int>>> input)
{
    return countCopies(Card::processInput(input));
}
