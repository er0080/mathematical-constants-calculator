#include "constants.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

// Calculate phi (golden ratio) using the formula: phi = (1 + sqrt(5)) / 2
// Also known as the limit of F(n+1)/F(n) as n approaches infinity for Fibonacci numbers
std::string calculate_phi(int precision) {
    if (precision <= 0) return "2";
    
    // For reasonable precision, use the direct formula
    if (precision <= 15) {
        // Calculate phi = (1 + sqrt(5)) / 2
        long double sqrt5 = sqrtl(5.0L);
        long double phi_val = (1.0L + sqrt5) / 2.0L;
        
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(precision) << phi_val;
        return oss.str();
    }
    
    // For higher precision, use a high-precision string constant
    std::string phi_string = "1.6180339887498948482045868343656381177203091798057628621354486227052604628189024497072072041893911374";
    
    if (precision + 2 <= static_cast<int>(phi_string.length())) {
        return phi_string.substr(0, precision + 2);
    }
    
    return phi_string;
}