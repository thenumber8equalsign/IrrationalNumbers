cmake_minimum_required(VERSION 4.1.1)

project(IrrationalNumbers)

add_executable(IrrationalNumbers src/main.cpp)

target_link_libraries(main PRIVATE mpfr gmp)
