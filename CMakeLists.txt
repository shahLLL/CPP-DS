cmake_minimum_required(VERSION 3.12)
project(shapes LANGUAGES CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable CMake's built-in testing features (CTest)
include(CTest)

# Fetch Catch2 Framework
include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.2 # Use a stable Catch2 v3 release tag
)
FetchContent_MakeAvailable(Catch2)

# Collect all C++ src and test files
file(GLOB TESTS "tests/*.cpp")
# file(GLOB SOURCES "src/*.cpp")

# Create the test executable
add_executable(unit_tests ${TESTS})

# Apply compiler warning flags
target_compile_options(unit_tests PRIVATE -Wall -Wextra)

# Link against the Catch2 v3 main entry point target
target_link_libraries(unit_tests PRIVATE Catch2::Catch2WithMain)

# Automatically register test cases with CTest
include(Catch)
catch_discover_tests(unit_tests)