//
// Created by Pavel on 10/16/2021.
//

#include "rationalmatrix.h"

RationalMatrix::RationalMatrix()
{
    vSize = 0;
    hSize = 0;
}

RationalMatrix::RationalMatrix(const size_t &n, const size_t &m)
{
    vSize = n;
    hSize = m;
    field.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        field[i].resize(m);
    }
}