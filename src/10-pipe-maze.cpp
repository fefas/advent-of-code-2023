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
    vector<string> pm;
    int x, y;
    int prevX, prevY;
    int stepCount;

    public:
    PipePath(vector<string> _m) : m(_m), xLen(m[0].size()), yLen(m.size())
    {
        pm = vector<string>(yLen, string(xLen, '.'));
        stepCount = 0;
        prevX = -1;
        prevY = -1;

        moveToStartingPosition();
        discoverPath();
    }

    void print()
    {
        for (int line = 0; line < yLen; line++) {
            cout << m[line] << " > ";
            for (int i = 0; i < m[line].size(); i++) {
                if (pm[line][i] == '*') cout << m[line][i];
                else cout << pm[line][i];
            }
            cout << endl;
        }
    }

    int countStepsToFarthestPoint()
    {
        return stepCount / 2;
    }

    int countTilesInEnclosedLoop()
    {
        identifyOuterAreas();

        int count = 0;
        for (int dy = 0; dy < yLen; dy++)
            for (int dx = 0; dx < xLen; dx++)
                if (pm[dy][dx] != '*' && pm[dy][dx] != 'S' && pm[dy][dx] != 'O') {
                    count++;
                    pm[dy][dx] = '+';
                }
//        print();

        return count;
    }

    private:
    void moveToStartingPosition()
    {
        for (y = 0; y < yLen; y++)
            for (x = 0; x < xLen; x++)
                if (m[y][x] == 'S') return;
    }

    void discoverPath()
    {
        do {
            pm[y][x] = 'x';
            walk();
        } while (m[y][x] != 'S');
    }

    void identifyOuterAreas()
    {
        for (y = 0; y < yLen; y++) {
            for (x = 0; x < xLen; x++)
                if ('x' == pm[y][x]) break;
            if ('x' == pm[y][x]) break;
        }

        int dx = -1, dy = 0;

        do {
            pm[y][x] = '*';
            markAsOuterArea(x + dx, y + dy);

//            if (x+dx < xLen && x+dx > 0 && y+dy > 0 && count > 30) pm[y+dy][x+dx] = '@';

            walk();

            if (x > prevX) {
                if (dx == 1) { dx = 0; dy = -1; }
                if (dx == -1) { dx = 0; dy = -1; }
            }
            else if (x < prevX) {
                if (dx == 1) { dx = 0; dy = 1; }
                if (dx == -1) { dx = 0; dy = 1; }
            }
            else if (y > prevY) {
                if (dy == 1) { dx = 1; dy = 0; }
                if (dy == -1) { dx = 1; dy = 0; }
            }
            else if (y < prevY) {
                if (dy == 1) { dx = -1; dy = 0; }
                if (dy == -1) { dx = -1; dy = 0; }
            }

//            cout << " -> dx,dy = " << dx << ',' << dy << endl;

//            count++;
        } while (pm[y][x] != '*');
    }

    void markAsOuterArea(const int x, const int y)
    {
        if (isOutOfRange(x, y) || isOneOf(x, y, "Ox*")) return;

        pm[y][x] = 'O';
        markAsOuterArea(x - 1, y);
        markAsOuterArea(x + 1, y);
        markAsOuterArea(x, y - 1);
        markAsOuterArea(x, y + 1);
    }

    void walk()
    {
        const int currX = x, currY = y;

//        cout << "walk: " << m[y][x] << " (" << x << ',' << y << ')' << endl;

        if (isNextConnection(x - 1, y)) x--;
        else if (isNextConnection(x + 1, y)) x++;
        else if (isNextConnection(x, y - 1)) y--;
        else if (isNextConnection(x, y + 1)) y++;
        else throw "could not walk";

//        cout << endl << " >>> walked to: " << m[y][x] << " (" << x << ',' << y << ')' << endl << endl;

        stepCount++;
        prevX = currX;
        prevY = currY;
    }

    bool isNextConnection(const int newX, const int newY)
    {
        if (isOutOfRange(newX, newY) || (newX == prevX && newY == prevY)) return false;

        const char currPipe = m[y][x];
        const char nextPipe = m[newY][newX];

//        cout << " > try: " << nextPipe << " (x:" << x << "->" << newX << ") (y:" << y << "->" << newY << ")";

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

    bool isPath(const int x, const int y)
    {
        return !isOutOfRange(x, y) && 'x' == pm[y][x];
    }

    bool isOneOf(const int x, const int y, const string chars)
    {
        for (auto c : chars)
            if (pm[y][x] == c) return true;

        return false;
    }

    bool isOutOfRange(const int x, const int y)
    {
        return x < 0 || y < 0 || x >= xLen || y >= yLen;
    }
};

int Solution_10::part1(vector<string> input)
{
    PipePath *path = new PipePath(input);

    return path->countStepsToFarthestPoint();
};

int Solution_10::part2(vector<string> input)
{
    PipePath path(input);

    return path.countTilesInEnclosedLoop();
};
