#pragma once

#include <string>

// Function declarations for all mathematical constant calculations
// Each function takes precision as parameter and returns string representation

// Basic constants
std::string calculate_pi(int precision);
std::string calculate_e(int precision);

// Golden ratio and related
std::string calculate_phi(int precision);

// Euler-Mascheroni constant
std::string calculate_gamma(int precision);

// Square roots
std::string calculate_sqrt2(int precision);
std::string calculate_sqrt3(int precision);
std::string calculate_sqrt5(int precision);

// Advanced constants
std::string calculate_apery(int precision);
std::string calculate_catalan(int precision);

// Natural logarithms
std::string calculate_ln2(int precision);
std::string calculate_ln10(int precision);