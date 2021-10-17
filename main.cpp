#include "rationalmatrix.h"
#include <chrono>

int main() {
    int kMax = 512;
    int d = 5;

    for (int k = 1; k < kMax; k++)
    {
        std::cout << "Test#" << k << std::endl;
        std::cout << "####################################################################################################" << std::endl;
        RationalMatrix mTest1(k, k);
        mTest1.random(d);
//        std::cout << "mTest1:\n" << mTest1 << std::endl;

        RationalMatrix mTest2(k, k);
        mTest2.random(d);
//        std::cout << "mTest2:\n" << mTest2 << std::endl;

        RationalMatrix mTest3(k, k);
        auto start1 = std::chrono::high_resolution_clock::now();
        normal_matrix_mul(mTest1, mTest2, mTest3);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto time1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);

        RationalMatrix mTest4(k, k);
        auto start2 = std::chrono::high_resolution_clock::now();
        strassen_matrix_mul(mTest1, mTest2, mTest4);
        auto end2 = std::chrono::high_resolution_clock::now();
        auto time2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);

//        std::cout << "mTest3:\n" << mTest3 << std::endl;
//        std::cout << "mTest4:\n" << mTest4 << std::endl;

        std::cout << "Execution time of multiplication by normal algorithm: " << time1.count() << std::endl;
        std::cout << "Execution time of multiplication by Strassen's algorithm: " << time2.count() << std::endl;

        std::cout << "Equality: " << ((mTest3==mTest4)?"true":"false") << std::endl;

        std::cout << "####################################################################################################" << std::endl;
    }
    return 0;
}
