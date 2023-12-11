#include <map>
#include <string>
#include <vector>

#include "08-haunted-wasteland.h"

using namespace std;

class Navigation
{
    private:
    bool ghostMode;
    string instructions;
    map<string,pair<string,string>> network;

    int currInstruction = 0;
    vector<string> currNodes = {};

    public:
    Navigation(string _i, map<string,pair<string,string>> _n, bool _g)
    {
        instructions = _i;
        network = _n;
        ghostMode = _g;

        if (!ghostMode) currNodes.push_back("AAA");
        else for (auto node : network)
            if (node.first[2] == 'A') currNodes.push_back(node.first);
    }

    int countSteps()
    {
        int stepCount = 0;

        while (!isEndReached()) {
            char direction = getNextInstruction();
            for (int i = 0; i < currNodes.size(); i++) currNodes[i] = getNextNode(currNodes[i], direction);

            stepCount++;
        }

        return stepCount;
    }

    private:
    bool isEndReached()
    {
        if (!ghostMode)
            return currNodes[0] == "ZZZ";
        else for (auto node : currNodes) if (node[2] != 'Z')
            return false;

        return true;
    }

    char getNextInstruction()
    {
        return instructions[(currInstruction++) % instructions.size()];
    }

    string getNextNode(string node, char direction)
    {
        return direction == 'L' ? network[node].first : network[node].second;
    }
};

int Solution_08::part1(string instructions, map<string,pair<string,string>> network)
{
    Navigation *nav = new Navigation(instructions, network, false);

    return nav->countSteps();
};

int Solution_08::part2(string instructions, map<string,pair<string,string>> network)
{
    Navigation *nav = new Navigation(instructions, network, true);

    return nav->countSteps();
};
