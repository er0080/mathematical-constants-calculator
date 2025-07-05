cmake_minimum_required(VERSION 3.15)
project(MathConstants VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set default build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Compiler-specific options
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    # Common flags for GCC and Clang
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
    
    # Release flags
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")
    
    # Debug flags
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g -fsanitize=address,undefined")
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fsanitize=address,undefined")
endif()

# Create directories if they don't exist
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/constants)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# Download CLI11 header if not present
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/lib/CLI11.hpp)
    message(STATUS "Downloading CLI11 header...")
    file(DOWNLOAD 
        https://github.com/CLIUtils/CLI11/releases/latest/download/CLI11.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/CLI11.hpp
        SHOW_PROGRESS)
endif()

# Find all source files in constants directory
file(GLOB_RECURSE CONSTANTS_SOURCES "constants/*.cpp")

# Create the main executable
add_executable(constants
    main.cpp
    ${CONSTANTS_SOURCES}
)

# Include lib directory for external dependencies
target_include_directories(constants PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# Set output directory
set_target_properties(constants PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Install target
install(TARGETS constants
    RUNTIME DESTINATION bin
)

# Custom clean target that removes build artifacts and downloaded dependencies
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_SOURCE_DIR}/lib
    COMMENT "Cleaning build directory and external dependencies"
)

# Print build information
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "C++ standard: ${CMAKE_CXX_STANDARD}")