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

void RationalMatrix::random(const int &n)
{
    for (size_t i = 0; i < vSize; i++){
        for (size_t j = 0; j < hSize; j++)
        {
            field[i][j].random(abs(n));
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

std::ostream& operator<< (std::ostream &out, const RationalMatrix &m)
{
    for (size_t i = 0; i < m.vSize; i++){
        for (size_t j = 0; j < m.hSize; j++)
        {
            out << m.field[i][j] << ' ';
        }
        out << std::endl;
    }
    return out;
}

bool matrix_sum (const RationalMatrix &a, const RationalMatrix &b, RationalMatrix &c)
{
    if (a.vSize != b.vSize || a.hSize != b.hSize)
        return false;

    c.vSize = a.vSize;
    c.hSize = a.hSize;

    c.field.resize(c.vSize);
    for (size_t i = 0; i < c.vSize; i++)
    {
        c.field[i].resize(c.hSize);
        for (size_t j = 0; j < c.hSize; j++)
        {
            c.field[i][j] = a.field[i][j] + b.field[i][j];
        }
    }
    return true;
}

bool matrix_sub (const RationalMatrix &a, const RationalMatrix &b, RationalMatrix &c)
{
    if (a.vSize != b.vSize || a.hSize != b.hSize)
        return false;

    c.vSize = a.vSize;
    c.hSize = a.hSize;

    c.field.resize(c.vSize);
    for (size_t i = 0; i < c.vSize; i++)
    {
        c.field[i].resize(c.hSize);
        for (size_t j = 0; j < c.hSize; j++)
        {
            c.field[i][j] = a.field[i][j] - b.field[i][j];
        }
    }
    return true;
}

bool check(RationalMatrix &a, RationalMatrix &b, RationalMatrix &c)
{
    if (a.hSize != b.vSize)
        return false;

    size_t k = std::max(std::max(a.vSize, b.hSize), a.hSize);

    if ((k & (k - 1)))
    {
        size_t t = 1;
        while (k > t) t <<= 1;
        k = t;
    }

    a.resize(k, k);
    b.resize(k, k);
    c.resize(k, k);

    return true;
}

void quad_matrix_fusion(RationalMatrix &m, const RationalMatrix &a, const RationalMatrix &b, const RationalMatrix &c, const RationalMatrix &d, const size_t &k)
{
    for (size_t i = 0; i < k/2; i++)
        for (size_t j = 0; j < k/2; j++)
            m.field[i][j] = a.field[i][j];
    for (size_t i = 0; i < k/2; i++)
        for (size_t j = 0; j < k/2; j++)
            m.field[i][j+k/2] = b.field[i][j];
    for (size_t i = 0; i < k/2; i++)
        for (int j = 0; j < k/2; j++)
            m.field[i+k/2][j] = c.field[i][j];
    for (size_t i = 0; i < k/2; i++)
        for (int j = 0; j < k/2; j++)
            m.field[i+k/2][j+k/2] = d.field[i][j];
}

bool normal_matrix_mul(const RationalMatrix &a, const RationalMatrix &b, RationalMatrix &c)
{
    if (a.hSize != b.vSize)
        return false;

    for (size_t i = 0; i < c.vSize; i++)
    {
        for (size_t j = 0; j < c.hSize; j++)
        {
            Rational r;
            c.field[i][j] = c.field[i][j] * r;
            for (size_t t = 0; t < c.hSize; t++)
                c.field[i][j] = c.field[i][j] + a.field[i][t] * b.field[t][j];
        }
    }

    return true;
}

void quick_matrix_mul(const RationalMatrix &a, const RationalMatrix &b, RationalMatrix &c, const size_t &k)
{
    if(k <= 32) // k can range from 32 to 128 depending on the computing power
    {
        // Normal multiplication
        normal_matrix_mul(a, b, c);
        return;
    }

    RationalMatrix a11, a12, a21, a22;
    RationalMatrix b11, b12, b21, b22;
    RationalMatrix c11, c12, c21, c22;
    RationalMatrix d1, d2; // additional sub-matrices for calculations
    RationalMatrix p1, p2, p3, p4, p5, p6, p7;

    // Division of matrices A and B into 4 sub-matrices
    a11.copy(a, 0, 0, k/2-1, k/2-1);
    a12.copy(a, 0, k/2, k/2-1, k-1);
    a21.copy(a, k/2, 0, k-1, k/2-1);
    a22.copy(a, k/2, k/2, k-1, k-1);

    b11.copy(b, 0, 0, k/2-1, k/2-1);
    b12.copy(b, 0, k/2, k/2-1, k-1);
    b21.copy(b, k/2, 0, k-1, k/2-1);
    b22.copy(b, k/2, k/2, k-1, k-1);

    // These calculations can be parallelized across multiple processor cores
    matrix_sum(a11, a22, d1);
    matrix_sum(b11, b22, d2);
    quick_matrix_mul(d1, d2, p1, k/2);

    matrix_sum(a21, a22, d1);
    quick_matrix_mul(d1, b11, p2, k/2);

    matrix_sub(b12, b22, d2);
    quick_matrix_mul(a11, d2, p3, k/2);

    matrix_sub(b21, b11, d2);
    quick_matrix_mul(a22, d2, p4, k/2);

    matrix_sum(a11, a12, d1);
    quick_matrix_mul(d1, b22, p5, k/2);

    matrix_sub(a21, a11, d1);
    matrix_sum(b11, b12, d2);
    quick_matrix_mul(d1, d2, p6, k/2);

    matrix_sub(a12, a22, d1);
    matrix_sum(b21, b22, d2);
    quick_matrix_mul(d1, d2, p7, k/2);

    matrix_sum(p1, p4, d1);
    matrix_sum(p5, p7, d2);
    matrix_sub(d1, d2, c11);

    matrix_sum(p3, p5, c12);

    matrix_sum(p2, p4, c21);

    matrix_sub(p1, p2, d1);
    matrix_sum(p3, p6, d2);
    matrix_sum(d1, d2, c22);

    // Merging 4 submatrices into one
    quad_matrix_fusion(c, c11, c12, c21, c22, k);
}

bool strassen_matrix_mul(RationalMatrix &a, RationalMatrix &b, RationalMatrix &c)
{
    // Maintain the initial sizes of matrices to return their previous configurations after multiplication.
    size_t n = a.vSize;
    size_t m = a.hSize;
    size_t p = b.hSize;

    // Testing the criterion for matrix multiplication.
    // Function when returning true, matrix sizes will be powers of two
    if(!check(a, b, c))
        return false;

    // Quick multiplication
    quick_matrix_mul(a, b, c, a.hSize);

    // Return to original dimensions
    a.resize(n, m);
    b.resize(m, p);
    c.resize(n, p);

    return true;
}