#include <string>
#include <vector>

#include "03-gear-ratios.h"

using namespace std;

static int isDigit(char c)
{
    return '0' <= c && c <= '9';
}

static int isSymbol(char c)
{
    return c != '.' && !isDigit(c);
}

static int isGear(char c)
{
    return c == '*';
}

class Number
{
    public:
    string val;
    const vector<string> m;
    const int iRow, iCol;

    public:
    Number(vector<string> _m, int _r, int _c) : m(_m), iRow(_r), iCol(_c)
    {
        for (int i = iCol; isDigit(m[iRow][i]); i++) val += m[iRow][i];
    }

    int length()
    {
        return val.size();
    }

    int toInt()
    {
        return stoi(val);
    }

    bool isAdjacent()
    {
        int lLimit = iCol - 1;
        int rLimit = iCol + length();

        if (isSymbol(m[iRow][lLimit])) return true;
        if (isSymbol(m[iRow][rLimit])) return true;

        if (iRow - 1 >= 0)
            for (int j = lLimit; j <= rLimit; j++)
                if (isSymbol(m[iRow-1][j])) return true;

        if (iRow + 1 < m.size())
            for (int j = lLimit; j <= rLimit; j++)
                if (isSymbol(m[iRow+1][j])) return true;

        return false;
    }
};

int Solution_03::part1(vector<string> m)
{
    int ans = 0;
    string currentNumber = "";

    vector<string> boxed = { string(m[0].size() + 2, '.') };
    for (int row = 0; row < m.size(); row++) {
        boxed.push_back('.' + m[row] + '.');
    }
    boxed.push_back({ string(m[0].size() + 2, '.') });

    for (int row = 1; row < boxed.size() - 1; row++) {
        for (int col = 1; col < boxed[row].size() - 1; col++) {
            if (!isDigit(boxed[row][col])) continue;

            Number *n = new Number(boxed, row, col);
            col += n->length() - 1;

            if (n->isAdjacent()) ans += n->toInt();
        }
    }

    return ans;
}

int Solution_03::part2(vector<string> m)
{
    int ans = 0;

    for (int col = 0; col < m[0].size(); col++) {
        if (isGear(m[0][col]) && isDigit(m[0][col-1]) && isDigit(m[0][col+1])) {
            return (m[0][col-1] - '0') * (m[0][col+1] - '0');
        }
    }

    return ans;
}
