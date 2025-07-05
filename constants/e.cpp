#include "constants.h"
#include <string>
#include <sstream>
#include <iomanip>

// Calculate e using the Taylor series expansion
// e = 1 + 1/1! + 1/2! + 1/3! + ... = sum(1/n!) for n=0 to infinity
std::string calculate_e(int precision) {
    if (precision <= 0) return "3";
    
    // For reasonable precision, use Taylor series
    if (precision <= 15) {
        long double e_val = 1.0L; // Start with 1 (first term)
        long double factorial = 1.0L;
        
        // Calculate series: e = 1 + 1/1! + 1/2! + 1/3! + ...
        for (int n = 1; n <= 100; ++n) {
            factorial *= n;
            long double term = 1.0L / factorial;
            e_val += term;
            
            // Stop when term becomes negligible
            if (term < 1e-20) break;
        }
        
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(precision) << e_val;
        return oss.str();
    }
    
    // For higher precision, use a high-precision string constant
    std::string e_string = "2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274";
    
    if (precision + 2 <= static_cast<int>(e_string.length())) {
        return e_string.substr(0, precision + 2);
    }
    
    return e_string;
}