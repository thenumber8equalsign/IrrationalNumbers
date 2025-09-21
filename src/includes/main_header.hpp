#ifndef MAIN_HEADER_HPP
#define MAIN_HEADER_HPP

#include <cstdint>
#include <map>
#include <functional>
#include <stdexcept>

#include <boost/multiprecision/mpfr.hpp>
#include <boost/multiprecision/cpp_int.hpp>



namespace IrrationalNumbers {
    // NotImplemented exception type
    class NotImplemented : public std::logic_error {
        public:
        NotImplemented() : std::logic_error("Function not yet implemented") { };
    };

    // Type aliases
    using BigFloat = boost::multiprecision::mpfr_float;
    using BigInt = boost::multiprecision::cpp_int;

    // Commonly used functions
    inline BigFloat bigFloatPower(BigFloat base, BigInt exponent); // Inlined because this is called many times during the main for loops
    inline BigInt bigIntPower(BigInt base, BigInt exponent); // Inlined because this is called many times during the main for loops
    BigFloat bigFloatSqrt(const BigInt NUMBER, const uint64_t DIGITS, BigInt initialGuess = 0);

    // Specific functions
    BigFloat pi(const uint64_t DIGITS);
    BigFloat euler(const uint64_t DIGITS);
    BigFloat ln2(const uint64_t DIGITS, const bool COMPUTE_TERMS = false);

    // Extra functions (not used by the program, but may be in the future)
    BigFloat bigFloatLn(const uint64_t X, const uint64_t DIGITS);

    // User Input Function map
    const std::map<int, std::function<BigFloat(const uint64_t)>> commandMap = {
        {1, pi},
        {2, euler}
    };

    // Inline function definitions
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
}
#endif
