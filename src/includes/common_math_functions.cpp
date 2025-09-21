#include "main_header.hpp"
#include <stdexcept>

namespace IrrationalNumbers {
    /**
     * @brief Calculates base^exponent
     *
     * This function takes a float as the base, and a positive integer as the exponent
     *
     * @param base the base of the power
     * @param exponent the exponent of the power (non-negative)
     * @return the value of base^exponent
     * @throw std::invalid_argument if exponent is negative
     */
    inline BigFloat bigFloatPower(BigFloat base, BigInt exponent) {
        // Check for valid arguments
        if (exponent < 0) throw std::invalid_argument("Negative exponent");

        // Variables
        BigFloat result = 1;

        while (exponent > 0) {
            // If exponent is odd
            if (exponent & 1) {
                result *= base;
            }

            base *= base; // Square the base
            exponent >>= 1; // Faster way of dividing by 2
        }
        return result;
    }

    /**
     * @brief Calculates base^exponent
     *
     * This function takes an integer as the base, and a positive integer as the exponent
     *
     * @param base the base of the power
     * @param exponent the exponent of the power (non-negative)
     * @return the value of base^exponent
     * @throw std::invalid_argument if exponent is negative
     */
    inline BigInt bigIntPower(BigInt base, BigInt exponent) {
        // Check for valid arguments
        if (exponent < 0) throw std::invalid_argument("Negative exponent");

        // Variables
        BigInt result = 1;

        while (exponent > 0) {
            // If exponent is odd
            if (exponent & 1) {
                result *= base;
            }

            base *= base;
            exponent >>= 1; // Faster way of dividing by 2
        }
        return result;
    }

    BigFloat bigFloatSqrt(const BigFloat NUMBER, const uint64_t DIGITS) {
        throw NotImplemented();
    }
}
