#include "rationalmatrix.h"

int main() {
    int k = 4;
    int d = 100;

    Rational rTest;
    std::cout << rTest << std::endl;
    for (int i = 0; i < 10; i++)
    {
        rTest.random(d);
        std::cout << rTest << std::endl;
    }
    std::cout << std::endl;

    RationalMatrix mTest(k, k);
    std::cout << mTest << std::endl;

    mTest.random(d);
    std::cout << mTest << std::endl;

    RationalMatrix mTest1(k, k);
    mTest1.random(d);
    std::cout << mTest1 << std::endl;

    RationalMatrix mTest2;
    strassen_matrix_mul(mTest, mTest1, mTest2);
    std::cout << mTest2 << std::endl;

    RationalMatrix mTest3(k, k);
    normal_matrix_mul(mTest, mTest1, mTest3);
    std::cout << mTest3 << std::endl;
    return 0;
}
