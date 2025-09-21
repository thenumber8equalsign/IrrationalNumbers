#ifndef MAIN_HEADER_HPP
#define MAIN_HEADER_HPP

#include <cstdint>

#include <boost/multiprecision/mpfr.hpp>
#include <boost/multiprecision/cpp_int.hpp>


namespace IrrationalNumbers {
    // Type aliases
    using BigFloat = boost::multiprecision::mpfr_float;
    using BigInt = boost::multiprecision::cpp_int;

    // Commonly used functions
    inline BigFloat bigFloatPower(BigFloat base, BigInt exponent); // Inlined because this is called many times during the main for loops
    inline BigInt bigIntPower(BigInt base, BigInt exponent); // Inlined because this is called many times during the main for loops
    BigFloat bigFloatSqrt(const BigFloat NUMBER, const uint64_t DIGITS, BigInt initialGuess = 0);

    // Specific functions
    BigFloat pi(const uint64_t DIGITS);
    BigFloat euler(const uint64_t DIGITS);
    BigFloat ln2(const uint64_t DIGITS, const bool COMPUTE_TERMS);

    // Extra functions (not used by the program, but may be in the future)
    BigFloat bigFloatLn(const uint64_t X, const uint64_t DIGITS);
}


#endif
