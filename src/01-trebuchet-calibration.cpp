#include <iostream>
#include <string>

#include "01-trebuchet-calibration.h"

using namespace std;

int Solution_01::sumCalibrations(string input)
{
    long ans = 0;
    short lastDig = -1;

    for (int i = 0; i < input.size(); i++) {


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

