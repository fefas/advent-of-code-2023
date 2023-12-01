#include <iostream>
#include <string>

#include "01-trebuchet-calibration.h"

using namespace std;

int Solution_01::sumCalibrations(string input)
{
    long ans = 0;
    short lastDig = -1;

    for (int i = 0; i < input.size(); i++) {
        if (input.substr(i, 3) ==  "one") {
            input[i] = '1';
        } else if (input.substr(i, 3) ==  "two") {
            input[i] = '2';
        } else if (input.substr(i, 5) ==  "three") {
            input[i] = '3';
        } else if (input.substr(i, 4) ==  "four") {
            input[i] = '4';
        } else if (input.substr(i, 4) ==  "five") {
            input[i] = '5';
        } else if (input.substr(i, 3) ==  "six") {
            input[i] = '6';
        } else if (input.substr(i, 5) ==  "seven") {
            input[i] = '7';
        } else if (input.substr(i, 5) ==  "eight") {
            input[i] = '8';
        } else if (input.substr(i, 4) ==  "nine") {
            input[i] = '9';
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

