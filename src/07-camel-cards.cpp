#include <algorithm>
#include <map>
#include <string>
#include <vector>

#include "07-camel-cards.h"

using namespace std;

class Cards
{
    private:
    const short FIVE_OF_KIND = 6;
    const short FOUR_OF_KIND = 5;
    const short FULL_HOUSE = 4;
    const short THREE_OF_KIND = 3;
    const short TWO_PAIR = 2;
    const short ONE_PAIR = 1;
    const short HIGH_CARD = 0;

    short type = HIGH_CARD;
    int strength = 0;
    const string cards;

    public:
    Cards(string _c) : cards(_c)
    {
        map<char,short> count;
        for (auto c : cards) count[c]++;

        for (auto c : count) {
            if (c.second == 5) { type = FIVE_OF_KIND; break; }
            if (c.second == 4) { type = FOUR_OF_KIND; break; }
            if (c.second == 3 && count.size() == 2) { type = FULL_HOUSE; break; }
            if (c.second == 3 && count.size() == 3) { type = THREE_OF_KIND; break; }
            if (c.second == 2 && count.size() == 2) { type = FULL_HOUSE; break; }
            if (c.second == 2 && count.size() == 3) { type = TWO_PAIR; break; }
            if (c.second == 2 && count.size() == 4) { type = ONE_PAIR; break; }
        }

        map<char,short> strengthMap = {
            { 'A', 13 }, { 'K', 12 }, { 'Q', 11 }, { 'J', 10 }, { 'T',  9 },
            { '9',  8 }, { '8',  7 }, { '7',  6 }, { '6',  5 }, { '5',  4 }, { '4',  3 }, { '3',  2 }, { '2',  1 } };

        for (auto c : cards) strength = 13 * strength + strengthMap[c];
    }

    bool isBetterThan(Cards *that)
    {
        return (type != that->type) ?  type > that->type : strength >= that->strength;
    }

    string toString()
    {
        return cards + " -> " + to_string(type);
    }
};

class Hand
{
    private:
    Cards *cards;
    int bid;

    public:
    Hand(pair<string,int> hand)
    {
        cards = new Cards(hand.first);
        bid = hand.second;
    }

    int calcPoints(int rank)
    {
        return rank * bid;
    }

    bool isBetterThan(Hand *that)
    {
        return cards->isBetterThan(that->cards);
    }

    string toString()
    {
        return cards->toString();
    }
};

long Solution_07::part1(vector<pair<string,int>> input)
{
    vector<Hand*> hands;
    for (int i = 0; i < input.size(); i++) {
        hands.push_back(new Hand(input[i]));
    }
    sort(hands.begin(), hands.end(), [](Hand *a, Hand *b) { return b->isBetterThan(a); });

    long sum = 0;
    for (int i = 0; i < hands.size(); i++) {
        sum += hands[i]->calcPoints(i + 1);
    }

    return sum;
};
