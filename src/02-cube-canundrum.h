#include <vector>

using namespace std;

class NumberOfCubes
{
    public:
    const short blue;
    const short red;
    const short green;

    NumberOfCubes(int _b, int _r, int _g) : blue(_b), red(_r), green(_g) {}

    bool fit(NumberOfCubes *that)
    {
        return blue >= that->blue && red >= that->red && green >= that->green;
    }
};

class Game
{
    private:
    NumberOfCubes* maxFromAllRounds;

    public:
    Game(vector<NumberOfCubes*> rounds)
    {
        short maxB = 0, maxR = 0, maxG = 0;
        for (auto r : rounds) {
            maxB = max(maxB, r->blue);
            maxR = max(maxR, r->red);
            maxG = max(maxG, r->green);
        }

        maxFromAllRounds = new NumberOfCubes(maxB, maxR, maxG);
    }

    bool comply(NumberOfCubes *config)
    {
        return config->fit(maxFromAllRounds);
    }

    int powerOfNeededCubesSet()
    {
        return maxFromAllRounds->blue * maxFromAllRounds->red * maxFromAllRounds->green;
    }
};

class Solution_02
{
    public:
    int part1(NumberOfCubes *config, vector<Game*> games);
    int part2(vector<Game*> games);
};

