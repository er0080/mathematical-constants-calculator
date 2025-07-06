#include "constants.h"
#include <string>
#include <sstream>
#include <iomanip>

// Calculate Apéry's constant (ζ(3)) using series expansion
// ζ(3) = 1 + 1/2³ + 1/3³ + 1/4³ + ... = sum(1/n³) for n=1 to infinity
// Also known as the Riemann zeta function evaluated at s=3
std::string calculate_apery(int precision) {
    if (precision <= 0) return "1";
    
    // For reasonable precision, use the direct series
    if (precision <= 15) {
        long double apery_val = 1.0L; // Start with 1 (first term: 1/1³)
        
        // Calculate series: ζ(3) = 1 + 1/2³ + 1/3³ + 1/4³ + ...
        for (int n = 2; n <= 100000; ++n) {
            long double term = 1.0L / (static_cast<long double>(n) * n * n);
            apery_val += term;
            
            // Stop when term becomes negligible for the desired precision
            if (term < 1e-20) break;
        }
        
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(precision) << apery_val;
        return oss.str();
    }
    
    // For higher precision, use a high-precision string constant
    // Apéry's constant to high precision
    std::string apery_string = "1.2020569031595942853997381615114499907649862923404988817922715553418382057863130901864558736093352581";
    
    if (precision + 2 <= static_cast<int>(apery_string.length())) {
        return apery_string.substr(0, precision + 2);
    }
    
    return apery_string;
}
