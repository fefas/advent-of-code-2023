#include <iostream>
#include <string>
#include <vector>

#include "10-pipe-maze.h"

using namespace std;

class PipePath
{
    private:
    const vector<string> m;
    int x, y;
    int prevX, prevY;
    int stepCount;

    public:
    PipePath(vector<string> _m, int _x, int _y) : m(_m), x(_x), y(_y)
    {
        stepCount = 1;
        prevX = 1;
        prevY = 1;
    }

    bool operator!=(const PipePath& that)
    {
        return x != that.x || y != that.y;
    }

    int length()
    {
        return stepCount;
    }

    void walk()
    {
        int currX = x, currY = y;

        if (isNextPipe(x - 1, y)) x--;
        else if (isNextPipe(x + 1, y)) x++;
        else if (isNextPipe(x, y - 1)) y--;
        else if (isNextPipe(x, y + 1)) y++;

        stepCount++;
        prevX = currX;
        prevY = currY;
    }

    void print()
    {
        cout << x << ',' << y << ": " << m[y][x] << " >>> " << stepCount << endl;
    }

    private:
    bool isNextPipe(int newX, int newY)
    {
        if (newX == prevX && newY == prevY) return false;

        char prevPipe = m[prevY][prevX];
        char candidatePipe = m[newY][newX];

        vector<char> allowedNextPipes = {};
        if (newX > x) allowedNextPipes = { '-', '7', 'J' };
        else if (newX < x) allowedNextPipes = { '-', 'F', 'L' };
        else if (newY > y) allowedNextPipes = { '|', 'L', 'J' };
        else if (newY < y) allowedNextPipes = { '|', 'F', '7' };

        for (auto p : allowedNextPipes)
            if (p == candidatePipe) return true;

        return false;
    }
};

int Solution_10::part1(vector<string> input)
{
    PipePath a(input, 2, 1);
    PipePath b(input, 1, 2);

    a.print();
    b.print();
    do {
        a.walk();
        b.walk();
        a.print();
        b.print();
    } while (a != b);

    return a.length();
};
