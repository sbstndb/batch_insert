cmake_minimum_required(VERSION 3.10)
project(batch_insert)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Google Test
find_package(GTest REQUIRED)

# Google Benchmark
find_package(benchmark REQUIRED)

# Library
add_library(batch_insert_lib
    src/batch_insert.cpp
)
target_include_directories(batch_insert_lib PUBLIC include)

# Tests
enable_testing()
add_executable(batch_insert_test tests/batch_insert_test.cpp)
target_link_libraries(batch_insert_test
    PRIVATE
    batch_insert_lib
    GTest::GTest
    GTest::Main
)
include(GoogleTest)
gtest_discover_tests(batch_insert_test)

# Benchmark
add_executable(batch_insert_benchmark benchmarks/batch_insert_benchmark.cpp)
target_link_libraries(batch_insert_benchmark
    PRIVATE
    batch_insert_lib
    benchmark::benchmark
) 
