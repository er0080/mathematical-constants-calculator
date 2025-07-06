#include "constants/constants.h"
#include "lib/CLI11.hpp"
#include <functional>
#include <iostream>
#include <map>
#include <string>

int main(int argc, char *argv[]) {
  CLI::App app{"Mathematical Constants Calculator"};

  std::string constant_name;
  int precision = 10;

  // Add command line options (supports both positional and named arguments)
  app.add_option("constant,-c,--constant", constant_name,
                 "Name of the mathematical constant to calculate")
      ->required()
      ->check(CLI::IsMember({"pi", "e", "phi", "gamma", "sqrt2", "sqrt3",
                             "sqrt5", "apery", "catalan", "ln2", "ln10"}));

  app.add_option("precision,-p,--precision", precision,
                 "Number of decimal places to calculate")
      ->required()
      ->check(CLI::Range(1, 1000));

  // Parse command line arguments
  try {
    app.parse(argc, argv);
  } catch (const CLI::ParseError &e) {
    return app.exit(e);
  }

  // Map of constant names to calculation functions
  std::map<std::string, std::function<std::string(int)>> calculators = {
      {"pi", calculate_pi},
      {"e", calculate_e},
      {"phi", calculate_phi},
      {"gamma", calculate_gamma},
      {"sqrt2", calculate_sqrt2},
      {"sqrt3", calculate_sqrt3},
      {"sqrt5", calculate_sqrt5},
      {"apery", calculate_apery},
      {"catalan", [](int p) { return "Not yet implemented"; }},
      {"ln2", [](int p) { return "Not yet implemented"; }},
      {"ln10", [](int p) { return "Not yet implemented"; }}};

  // Calculate and display result
  std::cout << "Calculating " << constant_name << " to " << precision
            << " decimal places..." << std::endl;

  auto calculator = calculators.find(constant_name);
  if (calculator != calculators.end()) {
    std::string result = calculator->second(precision);
    std::cout << constant_name << " = " << result << std::endl;
  } else {
    std::cerr << "Error: Unknown constant '" << constant_name << "'"
              << std::endl;
    return 1;
  }

  return 0;
}
