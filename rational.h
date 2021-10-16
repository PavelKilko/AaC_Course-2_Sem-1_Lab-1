//
// Created by Pavel on 10/16/2021.
//

#ifndef LAB1_RATIONAL_H
#define LAB1_RATIONAL_H

#include <iostream>

int gcd(int x, int y);
void reduction(int &x, int &y);

class Rational
{
public:
    int numerator;
    int denominator;

    Rational();

    explicit Rational(int n, int d = 1);

    void random(const int &n);

    friend std::ostream& operator<< (std::ostream &out, const Rational &r);

    friend Rational operator+ (const Rational &r1,const Rational &r2);
    friend Rational operator- (const Rational &r1,const Rational &r2);
    friend Rational operator* (const Rational &r1,const Rational &r2);
    friend Rational operator/ (const Rational &r1, const Rational &r2);

    friend bool operator== (const Rational &r1, const Rational &r2);
};

#endif //LAB1_RATIONAL_H
