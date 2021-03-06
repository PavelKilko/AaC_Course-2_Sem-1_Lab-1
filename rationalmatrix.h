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

    void resize(const size_t &n, const size_t &m);

    void make(const size_t &n, const size_t &m);

    void random(const long long &n);

    void copy(const RationalMatrix &m, const size_t &v0, const size_t &h0, const size_t &v1, const size_t &h1);

    friend std::ostream& operator << (std::ostream &out, const RationalMatrix &m);

    friend bool operator == (const RationalMatrix &m1, const RationalMatrix &m2);
};

bool matrix_sum (const RationalMatrix &a, const RationalMatrix &b, RationalMatrix &c);

bool matrix_sub (const RationalMatrix &a, const RationalMatrix &b, RationalMatrix &c);

bool check(RationalMatrix &a, RationalMatrix &b, RationalMatrix &c);

void quad_matrix_fusion(RationalMatrix &m, const RationalMatrix &a, const RationalMatrix &b, const RationalMatrix &c, const RationalMatrix &d, const size_t &k);

bool normal_matrix_mul(const RationalMatrix &a, const RationalMatrix &b, RationalMatrix &c);

void quick_matrix_mul(const RationalMatrix &a, const RationalMatrix &b, RationalMatrix &c, const size_t &k);

bool strassen_matrix_mul(RationalMatrix &a, RationalMatrix &b, RationalMatrix &c);

#endif //LAB1_RATIONALMATRIX_H
