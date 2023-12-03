#include <string>
#include <vector>

#include "03-gear-ratios.h"

using namespace std;

int Solution_03::part1(vector<string> m)
{
    for (int i = 0; i < m[0].size(); i++) {
        if (m[0][i] >= '0' && m[0][i] <= '9') {
            return m[0][i] - '0';
        }
    }

    return 0;
}
