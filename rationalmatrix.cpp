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

void RationalMatrix::resize(const size_t &n, const size_t &m)
{
    vSize = n;
    hSize = m;
    field.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        field[i].resize(m);
    }
}

void RationalMatrix::make(const size_t &n, const size_t &m)
{
    vSize = n;
    hSize = m;
    field.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        field[i].resize(m);
        for (size_t j = 0; j < m; j++)
        {
            int a, b;
            char c;
            while(true)
            {
                std::cin >> a >> c >> b;
                if (c == '/') break;
            }
            Rational r(a, b);
            field[i][j] = r;
        }
    }
}

void RationalMatrix::copy(const RationalMatrix &m, const size_t &v0, const size_t &h0, const size_t &v1, const size_t &h1)
{
    if(v0 < 0 || v0 >= m.vSize || v1 < 0 || v1 >= m.vSize || v0 > v1)
        return;
    if(h0 < 0 || h0 >= m.hSize || h1 < 0 || h1 >= m.hSize || h0 > h1)
        return;
    size_t v01 = v1 - v0 + 1;
    size_t h01 = h1 - h0 + 1;
    vSize = v01;
    hSize = h01;
    field.resize(v01);
    for (size_t i = 0; i < v01; i++)
    {
        field[i].assign(m.field[v0+i].begin() + h0, m.field[v0+i].begin() + h1 + 1);
    }
}