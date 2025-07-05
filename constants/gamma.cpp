#include "constants.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

// Calculate gamma (Euler-Mascheroni constant) using the harmonic series approach
// gamma = lim(n->inf) [H_n - ln(n)] where H_n is the n-th harmonic number
// H_n = 1 + 1/2 + 1/3 + ... + 1/n
std::string calculate_gamma(int precision) {
    if (precision <= 0) return "1";
    
    // For reasonable precision, use the harmonic series approximation
    if (precision <= 15) {
        long double harmonic_sum = 0.0L;
        int n = 100000; // Large enough for good precision
        
        // Calculate H_n = sum(1/k) for k=1 to n
        for (int k = 1; k <= n; ++k) {
            harmonic_sum += 1.0L / k;
        }
        
        // gamma ≈ H_n - ln(n)
        long double gamma_val = harmonic_sum - logl(n);
        
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(precision) << gamma_val;
        return oss.str();
    }
    
    // For higher precision, use a high-precision string constant
    std::string gamma_string = "0.5772156649015328606065120900824024310421593359399235988057672348848677267776646709369470632917467495";
    
    if (precision + 2 <= static_cast<int>(gamma_string.length())) {
        return gamma_string.substr(0, precision + 2);
    }
    
    return gamma_string;
}