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

    public:
    Navigation(string _i, map<string,pair<string,string>> _n)
    {
        instructions = _i;
        network = _n;
    }

    int countStepsFrom(string node, int currInstruction = 0)
    {
        return node[2] == 'Z' ? 0 : 1 + countStepsFrom(getNextNode(node, currInstruction), currInstruction + 1);
    }

    private:
    string getNextNode(string node, int currInstruction)
    {
        return isNextInstructionLeft(currInstruction) ? network[node].first : network[node].second;
    }

    char isNextInstructionLeft(int currInstruction)
    {
        return 'L' == instructions[currInstruction % instructions.size()];
    }
};

int Solution_08::part1(string instructions, map<string,pair<string,string>> network)
{
    Navigation *nav = new Navigation(instructions, network);

    return nav->countStepsFrom("AAA");
};

long Solution_08::part2(string instructions, map<string,pair<string,string>> network)
{
    Navigation *nav = new Navigation(instructions, network);

    long ans = 1;
    for (auto n : network)
        if (n.first[2] == 'A')
            ans = lcm(ans, nav->countStepsFrom(n.first));

    return ans;
};
