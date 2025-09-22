#include "includes/main_header.hpp"
#include <cstdio>
#include <exception>
#include <ios>
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>


int main() {
    // Variables
    const std::vector<int> VALID_CHOICES = { 1, 2, 3, 4 };

    uint64_t digits;
    int chosenConstant;
    size_t resultStrDecimalPos;
    size_t numIterations; // Name will be explained on line 101

    std::string resultStr;
    std::string resultStrFromDecimalAfter;
    std::stringstream resultStringstream;
    // Declared later due to us needing to set default precision
    //IrrationalNumbers::BigFloat result = 0;
    //IrrationalNumbers::BigFloat tenToDigits;

    // Safely get input
    for (;;) {
        std::cout << "Number of digits >> " << std::flush;
        // If the input was a valid integer
        if (std::cin >> digits) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid characters
            break;
        } else {
            // Input failed
            std::cout << "Invalid input. Input must be an integer." << std::endl;
            std::cin.clear(); // Clear error flag on cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid characters
        }
    }

    for (;;) {
        std::cout << "Which constant would you like to compute?\n1) π (Pi)\n2) e (Euler's number)\n3) √2 (Square root of 2)\n4) ln(2) (Natural logarithm of 2)" << std::endl;
        // If the input was a valid integer
        if (std::cin >> chosenConstant) {
            // If validChoices contains chosenConstant
            if (std::find(VALID_CHOICES.begin(), VALID_CHOICES.end(), chosenConstant) != VALID_CHOICES.end()) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid characters
                break;
            } else {
                std::cout << "Not a valid option" << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid characters
            }
        } else {
            std::cout << "Invalid input. Input must be an integer." << std::endl;
            std::cin.clear(); // Clear error flag on cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid characters
        }
    }

    // Set the precision for the BigFloat type
    IrrationalNumbers::BigFloat::default_precision(4ULL * digits + 400ULL); // 4 being ceil(log(10, 2)), thus meaning ~4 bits per decimal digit, add 400 for extra safety

    IrrationalNumbers::BigFloat result = 0;
    IrrationalNumbers::BigFloat tenToDigits = IrrationalNumbers::bigFloatPower(10, digits);


    // Special cases for sqrt 2 and ln(2) as they take different parameters, and can not use the function map
    try {
        if (chosenConstant == 3) {
            std::cout << "Computing √2 (Square root of 2) to " << digits << " decimal digits" << std::endl; // Since the sqrt function is used by others, we must print this here and not in the sqrt function
            result = IrrationalNumbers::bigFloatSqrt(2, digits, 1); // With initial guess set to 1
        } else if (chosenConstant == 4) {
            result = IrrationalNumbers::ln2(digits);
        } else {
            auto it = IrrationalNumbers::commandMap.find(chosenConstant);
            if (it != IrrationalNumbers::commandMap.end()) {
                result = it->second(digits);
            }
        }
    } catch (const IrrationalNumbers::NotImplemented& ni) {
        std::cerr << "An error occurred: Function not implemented" << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return 1;
    }

    // Format the output
    // Due to std::setprecision doing half-even rounding, and us wanting floor rounding, we need to handle that
    // We can not multiply by 10^digits, floor it, then divide by 10^digits due to the possibility that 10^digits may be too large to store
    resultStringstream << std::setprecision(4ULL * digits + 399ULL) << result; // 399 just in case
    resultStr = resultStringstream.str();

    resultStrDecimalPos = resultStr.find('.');
    resultStrFromDecimalAfter = resultStr.substr(resultStrDecimalPos);

    // Variable: numIterations, the number of iterations for the following for loop that trims the output string
    numIterations = resultStrFromDecimalAfter.length() - (digits + 1); // + 1 for the '.' character included

    std::cout << "Trimming output" << std::endl;

    for (size_t i = 0; i < numIterations; ++i) {
        resultStr.pop_back();

        // * 100 / 100 for 2 decimal places
        std::cout << "\x1b[2K\r" << std::floor(i / (double)numIterations * 100 * 100) / 100 << std::flush;
    }
    std::cout << "\x1b[2K\r100%" << std::endl;

    std::cout << resultStr << std::endl;

    return 0;
}
