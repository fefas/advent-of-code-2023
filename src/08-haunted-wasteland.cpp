#include <map>
#include <string>
#include <vector>

#include "08-haunted-wasteland.h"

using namespace std;

int Solution_08::part1(string instructions, map<string,pair<string,string>> network)
{
    int stepCount = 0;
    int instructionI = 0;
    string currNode = "AAA";

    while (currNode != "ZZZ") {
        currNode = network[currNode].first;
        stepCount++;
    }

    return stepCount;
};
