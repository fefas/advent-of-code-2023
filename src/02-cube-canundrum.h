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
    public:
    const vector<NumberOfCubes*> rounds;

    Game(vector<NumberOfCubes*> _r) : rounds(_r) {}
};

class Solution_02
{
    public:
    int findPossibleGames(NumberOfCubes *config, vector<Game*> games);
};

