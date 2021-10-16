#include "rationalmatrix.h"
#include <chrono>

int main() {
    int k = 8;
    int d = 20;

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
    auto start1 = std::chrono::high_resolution_clock::now();
    strassen_matrix_mul(mTest, mTest1, mTest2);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto time1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
    std::cout << mTest2 << std::endl;

    RationalMatrix mTest3(k, k);
    auto start2 = std::chrono::high_resolution_clock::now();
    normal_matrix_mul(mTest, mTest1, mTest3);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto time2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
    std::cout << mTest3 << std::endl;

    std::cout << time1.count() << std::endl;
    std::cout << time2.count() << std::endl;

    std::cout << (mTest2==mTest3) << std::endl;

    return 0;
}
