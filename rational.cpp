//
// Created by Pavel on 10/16/2021.
//

#include "rational.h"

int gcd(int x, int y) // Euclidean algorithm
{
    if (y == 0) return x;
    return gcd(y, x % y);
}

void reduction(int &x, int &y)
{
    int nod = gcd(x, y);
    if(!nod)
    {
        y = 1;
        return;
    }
    x /= nod;
    y /= nod;
    if(y < 0)
    {
        x *= -1;
        y *= -1;
    }
}
