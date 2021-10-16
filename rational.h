//
// Created by Pavel on 10/16/2021.
//

#ifndef LAB1_RATIONAL_H
#define LAB1_RATIONAL_H

int gcd(int x, int y);
void reduction(int &x, int &y);

class Rational
{
public:
    int numerator;
    int denominator;

    Rational();

    explicit Rational(int n, int d = 1);
};

#endif //LAB1_RATIONAL_H
