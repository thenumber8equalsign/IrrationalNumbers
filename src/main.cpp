#include "includes/main_header.hpp"
#include <exception>
#include <ios>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>


int main() {
    // Variables
    const std::vector<int8_t> VALID_CHOICES = { 1, 2, 3, 4 };

    uint64_t digits;
    int8_t chosenConstant;

    IrrationalNumbers::BigFloat result;

    // Safely get input
    for (;;) {
        std::cout << "Number of digits >> " << std::flush;
        // If the input was a valid integer
        if (std::cin >> digits) {
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
            if (std::find(VALID_CHOICES.begin(), VALID_CHOICES.end(), chosenConstant) == VALID_CHOICES.end()) {
                break;
            } else {
                std::cout << "Not a valid option" << std::endl;
            }
        } else {
            std::cout << "Invalid input. Input must be an integer." << std::endl;
            std::cin.clear(); // Clear error flag on cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid characters
        }
    }

    // Set the precision for the BigFloat type
    IrrationalNumbers::BigFloat::default_precision(4ULL * digits + 400ULL); // 4 being ceil(log(10, 2)), thus meaning ~4 bits per decimal digit, add 400 for extra safety

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
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "An unexpected error occurred." << std::endl;
    }



    return 0;
}
