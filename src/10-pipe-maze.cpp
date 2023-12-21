#include <iostream>
#include <exception>
#include <string>
#include <vector>

#include "10-pipe-maze.h"

using namespace std;

class PipePath
{
    private:
    const vector<string> m;
    const int xLen, yLen;
    int x, y;
    int prevX, prevY;
    int stepCount;

    public:
    PipePath(vector<string> _m) : m(_m), xLen(m[0].size()), yLen(m.size())
    {
        stepCount = 0;
        prevX = -1;
        prevY = -1;

        for (y = 0; y < yLen; y++)
            for (x = 0; x < xLen; x++)
                if (m[y][x] == 'S') return;
    }

    bool operator!=(const PipePath& that)
    {
        return x != that.x || y != that.y;
    }

    bool endReached()
    {
        return m[y][x] == 'S';
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
        else throw "could not walk";

        stepCount++;
        prevX = currX;
        prevY = currY;
    }

    private:
    bool isNextPipe(int newX, int newY)
    {
        if (newX < 0 || newY < 0 || newX >= xLen || newY >= yLen) return false;
        if (newX == prevX && newY == prevY) return false;

        char currPipe = m[y][x];
        char nextPipe = m[newY][newX];

        vector<char> allowedNextPipes = {};
        if (newX > x && (currPipe == 'S' || currPipe == '-' || currPipe == 'L' || currPipe == 'F')) // moving right
            allowedNextPipes = { 'S', '-', '7', 'J' };
        else if (newX < x && (currPipe == 'S' || currPipe == '-' || currPipe == 'J' || currPipe == '7')) // moving left
            allowedNextPipes = { 'S', '-', 'F', 'L' };
        else if (newY > y && (currPipe == 'S' || currPipe == '|' || currPipe == '7' || currPipe == 'F')) // moving down
            allowedNextPipes = { 'S', '|', 'L', 'J' };
        else if (newY < y && (currPipe == 'S' || currPipe == '|' || currPipe == 'J' || currPipe == 'L')) // moving up
            allowedNextPipes = { 'S', '|', 'F', '7' };

        for (auto p : allowedNextPipes)
            if (p == nextPipe) return true;

        return false;
    }
};

int Solution_10::part1(vector<string> input)
{
    PipePath path(input);

    do {
        path.walk();
    } while (!path.endReached());

    return path.length() / 2;
};
