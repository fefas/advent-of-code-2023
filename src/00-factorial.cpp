#include "00-factorial.h"

int Solution_00::fat(int n)
{
    return n <= 0 ? 1 : n * fat(n - 1);
}

