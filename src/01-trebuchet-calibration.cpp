#include <iostream>
#include <string>
#include <vector>

#include "01-trebuchet-calibration.h"

using namespace std;

int Solution_01::sumCalibrations(string input)
{
    vector<string> spelledNumbers = {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
    };

    long ans = 0;
    short lastDig = -1;

    for (int i = 0; i < input.size(); i++) {

        for (int j = 0; j < 9; j++) {
            if (input.substr(i, spelledNumbers[j].size()) ==  spelledNumbers[j]) {
                input[i] = (char) (j + 1 + '0');
            }
        }

        char c = input[i];
        if (c == '\n') {
            ans += lastDig;
            lastDig = -1;
        } else if (c >= '0' && c <= '9') {
            int val = c - '0';
            if (lastDig == -1) ans += 10 * val;
            lastDig = val;
        }
    }

    return ans + lastDig;
}

