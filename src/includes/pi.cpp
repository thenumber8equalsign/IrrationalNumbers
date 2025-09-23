#include "main_header.hpp"
#include <iomanip>
#include <iostream>

namespace IrrationalNumbers {
    BigFloat pi(const uint64_t DIGITS) {
        const BigInt TERMS = DIGITS / 14ULL + 1ULL;
        const BigInt O = BigInt("13591409");
        const BigInt T = BigInt("545140134");
        const BigInt TH = BigInt("-640320");

        // Factorials
        BigInt kF = 1; // k!
        BigInt tKF = 1; // (3k)!
        BigInt sKF = 1; // (6k)!

        BigFloat result = BigFloat(O);
        BigInt threeK, sixK;

        std::cout << "Computing π (Pi) to " << DIGITS << " decimal digits" << std::endl;
        for (BigInt k = 1; k < TERMS; ++k) {
            sixK = k * 6;
            threeK = k * 3;

            // Factorials
            sKF *= (sixK - 5) * (sixK - 4) * (sixK - 3) * (sixK - 2) * (sixK - 1) * sixK;
            tKF *= (threeK - 2) * (threeK - 1) * threeK;
            kF *= k;

            result += BigFloat((k * T + O) * sKF) / BigFloat(bigIntPower(TH, threeK) * kF * kF * kF * tKF);

            std::cout << "\x1b[2K\r" << std::floor((double)k / (double)TERMS * 100 * 100) / 100 << "%" << std::flush;
        }
        std::cout << "\x1b[2K\r100.00%" << std::endl;
        std::cout << "Calculating √10005 (Square root of 10005)" << std::endl;
        result = 1 / (result * bigFloatSqrt(10005ULL, DIGITS + 10ULL, 100) / BigFloat("4270934400"));
        return result;
    }
}
