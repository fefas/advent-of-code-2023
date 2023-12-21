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
    int stepCount;
    char prevPipe;

    public:
    PipePath(vector<string> _m, int _x, int _y) : m(_m), x(_x), y(_y)
    {
        stepCount = 1;
        prevPipe = 'S';
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
        char currPipe = m[x][y];

        if (isNext(x - 1, y)) x--;
        else if (isNext(x + 1, y)) x++;
        else if (isNext(x, y - 1)) y--;
        else if (isNext(x, y + 1)) y++;

        stepCount++;
        prevPipe = currPipe;
    }
//
//    void print()
//    {
//        cout << x << ',' << y << ": " << m[x][y] << " >>> " << stepCount << endl;
//    }

    private:
    bool isNext(int newX, int newY)
    {
        return m[newX][newY] != '.' && m[newX][newY] != prevPipe;
    }
};

int Solution_10::part1(vector<string> input)
{
    PipePath a(input, 2, 1);
    PipePath b(input, 1, 2);

//    a.print();
//    b.print();
    do {
        a.walk();
        b.walk();
//        a.print();
//        b.print();
    } while (a != b);

    return a.length();
};
