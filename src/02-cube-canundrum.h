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
        return blue >= that->blue;
    }
};

class Solution_02
{
    public:
    int findPossibleGames(NumberOfCubes *config, vector<NumberOfCubes*> rounds);
};

