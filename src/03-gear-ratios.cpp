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

static vector<string> boxInDots(vector<string> m)
{
    vector<string> boxed = { string(m[0].size() + 2, '.') };
    for (int row = 0; row < m.size(); row++) boxed.push_back('.' + m[row] + '.');
    boxed.push_back({ string(m[0].size() + 2, '.') });

    return boxed;
}

class Number
{
    public:
    string val;
    vector<string> m;
    int iRow, iCol;

    public:
    Number(vector<string> _m, int _r, int _c) : m(_m), iRow(_r), iCol(_c)
    {
        for (int i = iCol; isDigit(m[iRow][i]); i++) val += m[iRow][i];
        while (isDigit(m[iRow][--iCol])) val = m[iRow][iCol] + val;
        iCol++;
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

    bool isEqual(Number *that)
    {
        return iCol == that->iCol && iRow == that->iRow;
    }
};

class Gear
{
    private:
    const vector<string> m;
    const int iRow, iCol;
    vector<Number*> adjacents;

    public:
    Gear(vector<string> _m, int _r, int _c) : m(_m), iRow(_r), iCol(_c)
    {
        computeAdjacents();
    }

    int ratio()
    {
        return (adjacents.size() != 2) ? 0 : adjacents[0]->toInt() * adjacents[1]->toInt();
    }

    private:
    void computeAdjacents()
    {
        if (isDigit(m[iRow][iCol-1])) addAdjacent(new Number(m, iRow, iCol - 1));
        if (isDigit(m[iRow][iCol+1])) addAdjacent(new Number(m, iRow, iCol + 1));

        for (int i = -1; i <= 1; i++) {
            if (!isDigit(m[iRow-1][iCol+i])) continue;
            addAdjacent(new Number(m, iRow - 1, iCol + i));
            i++;
        }

        for (int i = -1; i <= 1; i++) {
            if (!isDigit(m[iRow+1][iCol+i])) continue;
            addAdjacent(new Number(m, iRow + 1, iCol + i));
            i++;
        }
    }

    void addAdjacent(Number *n)
    {
        for (auto a : adjacents)
            if (a->isEqual(n)) return;

        adjacents.push_back(n);
    }
};

int Solution_03::part1(vector<string> m)
{
    int ans = 0;
    string currentNumber = "";

    m = boxInDots(m);

    for (int row = 1; row < m.size() - 1; row++) {
        for (int col = 1; col < m[row].size() - 1; col++) {
            if (!isDigit(m[row][col])) continue;

            Number *n = new Number(m, row, col);
            col += n->length() - 1;

            if (n->isAdjacent()) ans += n->toInt();
        }
    }

    return ans;
}

int Solution_03::part2(vector<string> m)
{
    long long ans = 0;

    m = boxInDots(m);

    for (int row = 1; row < m.size() - 1; row++)
        for (int col = 1; col < m[1].size() - 1; col++) {
            if (!isGear(m[row][col])) continue;

            Gear *g = new Gear(m, row, col);
            ans += g->ratio();
        }

    return ans;
}
