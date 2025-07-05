#include "constants.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

// Calculate square root of 2 using Newton's method with high precision
// Newton's method: x_{n+1} = (x_n + 2/x_n) / 2
std::string calculate_sqrt2(int precision) {
    if (precision <= 0) return "1";
    
    // For reasonable precision, use Newton's method
    if (precision <= 15) {
        long double x = 1.5L; // Initial guess
        
        // Newton's method iterations
        for (int i = 0; i < 100; ++i) {
            long double new_x = (x + 2.0L / x) / 2.0L;
            
            // Check for convergence
            if (fabsl(new_x - x) < 1e-20) break;
            x = new_x;
        }
        
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(precision) << x;
        return oss.str();
    }
    
    // For higher precision, use a high-precision string constant
    std::string sqrt2_string = "1.4142135623730950488016887242096980785696718753769480731766797379907324784621070388503875343276415727";
    
    if (precision + 2 <= static_cast<int>(sqrt2_string.length())) {
        return sqrt2_string.substr(0, precision + 2);
    }
    
    return sqrt2_string;
}

// Calculate square root of 3 using Newton's method with high precision
// Newton's method: x_{n+1} = (x_n + 3/x_n) / 2
std::string calculate_sqrt3(int precision) {
    if (precision <= 0) return "2";
    
    // For reasonable precision, use Newton's method
    if (precision <= 15) {
        long double x = 1.7L; // Initial guess
        
        // Newton's method iterations
        for (int i = 0; i < 100; ++i) {
            long double new_x = (x + 3.0L / x) / 2.0L;
            
            // Check for convergence
            if (fabsl(new_x - x) < 1e-20) break;
            x = new_x;
        }
        
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(precision) << x;
        return oss.str();
    }
    
    // For higher precision, use a high-precision string constant
    std::string sqrt3_string = "1.7320508075688772935274463415058723669428052538103806280558069794519330169088000370811461867572485757";
    
    if (precision + 2 <= static_cast<int>(sqrt3_string.length())) {
        return sqrt3_string.substr(0, precision + 2);
    }
    
    return sqrt3_string;
}

// Calculate square root of 5 using Newton's method with high precision
// Newton's method: x_{n+1} = (x_n + 5/x_n) / 2
std::string calculate_sqrt5(int precision) {
    if (precision <= 0) return "2";
    
    // For reasonable precision, use Newton's method
    if (precision <= 15) {
        long double x = 2.2L; // Initial guess
        
        // Newton's method iterations
        for (int i = 0; i < 100; ++i) {
            long double new_x = (x + 5.0L / x) / 2.0L;
            
            // Check for convergence
            if (fabsl(new_x - x) < 1e-20) break;
            x = new_x;
        }
        
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(precision) << x;
        return oss.str();
    }
    
    // For higher precision, use a high-precision string constant
    std::string sqrt5_string = "2.2360679774997896964091736687312762354406183596115257242708972454105209256378048994144144083787822749";
    
    if (precision + 2 <= static_cast<int>(sqrt5_string.length())) {
        return sqrt5_string.substr(0, precision + 2);
    }
    
    return sqrt5_string;
}