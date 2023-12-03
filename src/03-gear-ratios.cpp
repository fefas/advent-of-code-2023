#include <string>
#include <vector>

#include "03-gear-ratios.h"

using namespace std;

int Solution_03::part1(vector<string> m)
{
    int ans = 0;
    string currentNumber = "";

    for (int row = 0; row < m.size(); row++) {
        for (int i = 0; i < m[0].size(); i++) {
            char c = m[row][i];

            if (c >= '0' && c <= '9') {
                currentNumber += c;
            } else if (currentNumber != "") {
                bool isAdjacent = false;
                int rLimit = i;
                int lLimit = i - currentNumber.size() - 1;

                if (m[row][rLimit] != '.' || m[row][lLimit] != '.') isAdjacent = true;

                if (!isAdjacent && row > 0) {
                    string prevRow = m[row-1];
                    for (int j = rLimit; j >= lLimit && j >= 0; j--) {
                        if (prevRow[j] != '.' && (prevRow[j] < '0' || prevRow[j] > '9')) {
                            isAdjacent = true;
                            break;
                        }
                    }
                }

                if (!isAdjacent && row + 1 < m.size()) {
                    string nextRow = m[row+1];
                    for (int j = rLimit; j >= lLimit && j >= 0; j--) {
                        if (nextRow[j] != '.' && (nextRow[j] < '0' || nextRow[j] > '9')) {
                            isAdjacent = true;
                            break;
                        }
                    }
                }

                if (isAdjacent) ans += stoi(currentNumber);
                currentNumber = "";
            }
        }
    }

    return ans;
}
