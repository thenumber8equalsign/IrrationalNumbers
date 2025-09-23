#include "main_header.hpp"
#include <iostream>

namespace IrrationalNumbers {
    BigFloat euler(const uint64_t DIGITS) {
        const BigInt TERMS = DIGITS * 2 + 2;
        const BigFloat ONE = 1;

        BigInt factorial = 1; // k!
        BigFloat result = 1;

        for (BigInt k = 1; k <= TERMS; ++k) {
            factorial = factorial * k;
            result = result + ONE / BigFloat(factorial);

            std::cout << "\x1b[2K\r" << floor((double)k / (double)TERMS * 100 * 100) / 100 << std::flush;
        }
        std::cout << "\x1b[2K\r100.00%" << std::endl;
        return result;
    }
}
