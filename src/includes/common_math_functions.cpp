#include "main_header.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

namespace IrrationalNumbers {
    /**
     * @brief given a positive integer calculate its square root to DIGITS precision
     * @param NUMBER the number to compute the square root
     * @param DIGITS number of decimal digits to return
     * @param initialGuess the initial guess for newton's method
     * @return the positive square root of NUMBER
     * @throw std::out_of_range if NUMBER is negative
     * @throw std::invalid_argument if DIGITS is negative
     * @throw std::invalid_argument if guess is negative
     */
    BigFloat bigFloatSqrt(const BigInt NUMBER, const uint64_t DIGITS, BigInt initialGuess) {
        // Check for valid arguments
        if (NUMBER < 0) {
            throw std::out_of_range("No support for complex numbers");
        } else if (DIGITS < 0) {
            throw std::invalid_argument("Negative DIGITS");
        } else if (initialGuess < 0) {
            throw std::invalid_argument("Negative guess");
        }

        // Variables
        const BigFloat TWO = BigFloat(2);
        const BigFloat F_NUMBER = BigFloat(NUMBER);

        BigFloat guess = BigFloat(initialGuess);


        for (uint64_t i = 0; i <= DIGITS; ++i) {
            guess += F_NUMBER / guess;
            guess /= TWO;

            // * 100 / 100 for two decimal places
            std::cout << "\x1b[2K\r" << std::floor(i / (double)DIGITS * 100 * 100) / 100 << "%" << std::flush;
        }
        std::cout << "\x1b[2K\r100.00%" << std::endl;
        return guess;
    }
}
