#include "includes/main_header.hpp"
#include <iostream>


int main() {
    // Variables
    IrrationalNumbers::BigFloat base;
    IrrationalNumbers::BigInt exponent;
    IrrationalNumbers::BigInt iBase;

    std::cout << "Hello, World!" << std::endl;
    std::cout << "Give me a base: " << std::flush;
    std::cin >> base;
    std::cout << "Give me an exponent: " << std::flush;
    std::cin >> exponent;

    std::cout << "Power: " << IrrationalNumbers::bigFloatPower(base, exponent) << std::endl;

    std::cout << "Give me a base: " << std::flush;
    std::cin >> iBase;
    std::cout << "Give me an exponent: " << std::flush;
    std::cin >> exponent;

    std::cout << "Power: " << IrrationalNumbers::bigIntPower(iBase, exponent) << std::endl;

    return 0;
}
