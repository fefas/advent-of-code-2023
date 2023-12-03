#include <string>
#include <vector>

#include "03-gear-ratios.h"

using namespace std;

int Solution_03::part1(vector<string> m)
{
    int ans = 0;

    for (int i = 0; i < m[0].size(); i++) {
        char c = m[0][i];

        if (c >= '0' && c <= '9') {
            ans = 10 * ans + (c - '0');
        }
    }

    return ans;
}
