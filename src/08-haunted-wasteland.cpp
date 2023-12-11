#include <map>
#include <numeric>
#include <string>
#include <vector>

#include "08-haunted-wasteland.h"

using namespace std;

class Navigation
{
    private:
    string instructions;
    map<string,pair<string,string>> network;

    string currNode;
    int currInstruction = 0;

    public:
    Navigation(string _i, map<string,pair<string,string>> _n, string _sn)
    {
        instructions = _i;
        currNode = _sn;
        network = _n;
    }

    int countSteps()
    {
        int stepCount = 0;

        while (!isEndReached()) {
            currNode = getNextNode(currNode);
            stepCount++;
        }

        return stepCount;
    }

    private:
    bool isEndReached()
    {
        return currNode[2] == 'Z';
    }

    string getNextNode(string node)
    {
        return isNextInstructionLeft() ? network[node].first : network[node].second;
    }

    char isNextInstructionLeft()
    {
        return 'L' == instructions[(currInstruction++) % instructions.size()];
    }
};

int Solution_08::part1(string instructions, map<string,pair<string,string>> network)
{
    Navigation *nav = new Navigation(instructions, network, "AAA");

    return nav->countSteps();
};

long Solution_08::part2(string instructions, map<string,pair<string,string>> network)
{
    long ans = 1;

    for (auto n : network) {
        if (n.first[2] != 'A') continue;

        Navigation *nav = new Navigation(instructions, network, n.first);
        ans = lcm(ans, nav->countSteps());
    }

    return ans;
};
