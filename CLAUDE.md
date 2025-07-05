# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a C++ command-line tool for calculating mathematical constants (e, π, etc.) with user-specified precision. The project uses a modular architecture with separate implementation files for each constant calculation.

## Dependencies

- CLI11 (header-only library) - automatically downloaded to `lib/` by CMake
- C++11 compatible compiler
- CMake 3.15 or higher

## Build Commands

```bash
# Release build (optimized, recommended for production)
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .

# Debug build (with debugging symbols and sanitizers)
mkdir build-debug && cd build-debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .

# Quick build (defaults to Release)
mkdir build && cd build
cmake .. && make

# Clean targets
cd build && make clean        # Clean build artifacts only
cd build && make clean-all    # Clean everything including lib/ dependencies

# Run the program
./build/bin/constants --constant <name> --precision <digits>
./build/bin/constants -c <name> -p <digits>
./build/bin/constants <name> <digits>  # positional args
```

## Code Structure

- `main.cpp` - Main entry point with CLI11 integration, command-line parsing, and console output
- `lib/` - External dependencies directory:
  - `CLI11.hpp` - Header-only command-line parsing library
- `constants/` - Directory containing modular implementation files:
  - `constants.h` - Header file with function declarations for all constants
  - `pi.cpp` - Implementation for π calculation
  - `e.cpp` - Implementation for e calculation
  - `phi.cpp` - Implementation for golden ratio calculation
  - `gamma.cpp` - Implementation for Euler-Mascheroni constant
  - `sqrt.cpp` - Implementation for square root calculations (√2, √3, √5)
  - `apery.cpp` - Implementation for Apéry's constant
  - `catalan.cpp` - Implementation for Catalan's constant
  - `ln.cpp` - Implementation for natural logarithm calculations

## Architecture Guidelines

- Each constant has its own implementation file for maintainability
- `main.cpp` handles only CLI parsing, logging, and orchestration
- All constant calculation functions should have consistent signatures
- Use header file (`constants.h`) to declare all calculation functions
- Each implementation file should contain the most appropriate algorithm for that constant

## Command-Line Interface

Uses CLI11 for standardized argument parsing. Supports:
- Named arguments: `--constant`, `--precision` (short: `-c`, `-p`)
- Positional arguments: `<constant> <precision>`
- Help: `--help` or `-h`

## Supported Constants

Constant names: `pi`, `e`, `phi`, `gamma`, `sqrt2`, `sqrt3`, `sqrt5`, `apery`, `catalan`, `ln2`, `ln10`

## Expected Usage Pattern

```bash
./build/bin/constants pi 10              # Calculate π to 10 decimal places
./build/bin/constants --constant e --precision 15
./build/bin/constants -c gamma -p 8
```

## CMake Build System

- Uses modern CMake practices (3.15+)
- Automatic CLI11 header download
- Separate Release and Debug configurations
- Release: `-O3 -DNDEBUG` optimization
- Debug: `-O0 -g` with AddressSanitizer and UBSanitizer
- Output directory: `build/bin/` or `build-debug/bin/`
- Automatic discovery of `constants/*.cpp` files