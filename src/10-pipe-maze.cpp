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

    void print()
    {
        for (auto l : m)
            cout << l << endl;
    }

    int countStepsToFarthestPoint()
    {
        markPath();
//        print();

        return stepCount / 2;
    }

    int countTilesInEnclosedLoop()
    {
        markPath();

        for (int dx = 0; dx < xLen; dx++) {
            identifyOutsideTiles(dx, 0);
            identifyOutsideTiles(dx, yLen - 1);
        }
        for (int dy = 0; dy < yLen; dy++) {
            identifyOutsideTiles(0, dy);
            identifyOutsideTiles(xLen - 1, dy);
        }

        int count = 0;
        for (int dy = 0; dy < yLen; dy++)
            for (int dx = 0; dx < xLen; dx++)
                if (m[dy][dx] != 'x' && m[dy][dx] != 'S' && m[dy][dx] != 'O')
                    count++;

//        print();

        return count;
    }

    private:
    void markPath()
    {
        do {
            walk();
        } while (m[y][x] != 'S');
    }

    void identifyOutsideTiles(int x, int y)
    {
        if (x < 0 || y < 0 || x >= xLen || y >= yLen) return;
        if (m[y][x] == 'x' || m[y][x] == 'S' || m[y][x] == 'O') return;

//        m[y][x] = 'O';
//        print();
//        cout << endl;
        identifyOutsideTiles(x - 1, y);
        identifyOutsideTiles(x + 1, y);
        identifyOutsideTiles(x, y - 1);
        identifyOutsideTiles(x, y + 1);
    }

    void walk()
    {
        const int currX = x, currY = y;

        if (isNextPipe(x - 1, y)) x--;
        else if (isNextPipe(x + 1, y)) x++;
        else if (isNextPipe(x, y - 1)) y--;
        else if (isNextPipe(x, y + 1)) y++;
        else throw "could not walk";

        makeStep(currX, currY);
    }

    bool isNextPipe(const int newX, const int newY)
    {
        if (newX < 0 || newY < 0 || newX >= xLen || newY >= yLen) return false;
        if (newX == prevX && newY == prevY) return false;

        const char currPipe = m[y][x];
        const char nextPipe = m[newY][newX];

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

    void makeStep(const int x, const int y)
    {
        stepCount++;
        prevX = x;
        prevY = y;

        if (m[prevY][prevX] == 'S') return;

//        m[prevY][prevX] = 'x';
    }
};

int Solution_10::part1(vector<string> input)
{
    PipePath path(input);

    return path.countStepsToFarthestPoint();
};

int Solution_10::part2(vector<string> input)
{
    PipePath path(input);

    return path.countTilesInEnclosedLoop();
};
