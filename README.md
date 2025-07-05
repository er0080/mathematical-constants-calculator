# Mathematical Constants Calculator

A command-line tool for calculating various mathematical constants (e, π, etc.) with user-specified precision.

## Features

- Calculate mathematical constants with arbitrary precision
- Command-line interface for easy integration
- Support for multiple mathematical constants:
  - π (pi) - Archimedes' constant
  - e - Euler's number
  - φ (phi) - Golden ratio
  - γ (gamma) - Euler-Mascheroni constant
  - √2 - Pythagoras' constant
  - √3, √5 - Square roots
  - ζ(3) - Apéry's constant
  - G - Catalan's constant
  - δ, α - Feigenbaum constants
  - ln(2), ln(10) - Natural logarithms

## Dependencies

- CLI11 (header-only library for command-line parsing) - automatically downloaded by CMake
- C++11 compatible compiler
- CMake 3.15 or higher

## Building

### Release Build (Optimized)
```bash
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

### Debug Build (With Debugging Symbols and Sanitizers)
```bash
mkdir build-debug && cd build-debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
```

### Quick Build (Default Release)
```bash
mkdir build && cd build
cmake .. && make
```

Executable will be located in `build/bin/constants` or `build-debug/bin/constants`

## Usage

```bash
./constants --constant <name> --precision <digits>
# or using short forms:
./constants -c <name> -p <digits>
# or positional arguments:
./constants <name> <digits>
```

### Available Constants

| Name | Symbol | Description |
|------|--------|--------------|
| `pi` | π | Archimedes' constant (3.14159...) |
| `e` | e | Euler's number (2.71828...) |
| `phi` | φ | Golden ratio (1.61803...) |
| `gamma` | γ | Euler-Mascheroni constant (0.57721...) |
| `sqrt2` | √2 | Pythagoras' constant (1.41421...) |
| `sqrt3` | √3 | Square root of 3 (1.73205...) |
| `sqrt5` | √5 | Square root of 5 (2.23606...) |
| `apery` | ζ(3) | Apéry's constant (1.20205...) |
| `catalan` | G | Catalan's constant (0.91596...) |
| `ln2` | ln(2) | Natural logarithm of 2 (0.69314...) |
| `ln10` | ln(10) | Natural logarithm of 10 (2.30258...) |

### Examples

```bash
# Using named arguments
./build/bin/constants --constant pi --precision 10
./build/bin/constants -c e -p 15

# Using positional arguments
./build/bin/constants pi 10              # Calculate π to 10 decimal places
./build/bin/constants e 15               # Calculate e to 15 decimal places
./build/bin/constants phi 12             # Calculate golden ratio to 12 decimal places
./build/bin/constants gamma 8            # Calculate Euler-Mascheroni constant to 8 decimal places
./build/bin/constants sqrt2 20           # Calculate √2 to 20 decimal places

# Get help
./build/bin/constants --help
./build/bin/constants -h
```

## Implementation

The main entry point is in `main.cpp`, which handles command-line parsing and coordinates the calculation of mathematical constants. Individual constant algorithms are implemented in separate files within the `constants/` directory.