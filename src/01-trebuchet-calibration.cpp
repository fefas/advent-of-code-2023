#include <iostream>
#include <string>
#include <vector>

#include "01-trebuchet-calibration.h"

using namespace std;

class CalibrationsWalker
{
    private:
    string messedCalibrations;
    vector<string> spelledNumbers = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    int i;

    public:
    static const short LINE_BREAK = -1;
    static const short NOT_A_NUMBER = -2;
    static const short END_OF_STRING = -3;

    CalibrationsWalker(string input)
    {
        messedCalibrations = input;
        i = 0;
    }

    short getNext()
    {
        if (i == messedCalibrations.size()) return END_OF_STRING;

        char c = messedCalibrations[i++];

        if ('\n' == c) return LINE_BREAK;
        if ('0' <= c && c <= '9') return c - '0';

        for (int j = 0; j < 9; j++) {
            string num = spelledNumbers[j];
            short len = num.size();

            if (messedCalibrations.substr(i - 1, len) == num) return j + 1;
        }

        return NOT_A_NUMBER;
    }
};

int Solution_01::sumCalibrations(string input)
{
    CalibrationsWalker *walker = new CalibrationsWalker(input);

    int ans = 0;
    short lastDigit = CalibrationsWalker::NOT_A_NUMBER;

    short iterator = walker->getNext();
    while (CalibrationsWalker::END_OF_STRING != iterator) {
        if (iterator >= 0) {
            if (lastDigit == CalibrationsWalker::NOT_A_NUMBER) ans += 10 * iterator;
            lastDigit = iterator;
        }
        else if (iterator == CalibrationsWalker::LINE_BREAK) {
            ans += lastDigit;
            lastDigit = CalibrationsWalker::NOT_A_NUMBER;
        }

        iterator = walker->getNext();
    }

    return ans + lastDigit;
}

