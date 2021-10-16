//
// Created by Pavel on 10/16/2021.
//

#ifndef LAB1_RATIONALMATRIX_H
#define LAB1_RATIONALMATRIX_H

#include "rational.h"
#include <vector>

class RationalMatrix
{
public:
    std::vector<std::vector<Rational>> field;
    size_t vSize, hSize;

    RationalMatrix();

    RationalMatrix(const size_t &n, const size_t &m);
};

#endif //LAB1_RATIONALMATRIX_H
