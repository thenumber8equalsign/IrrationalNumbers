cmake_minimum_required(VERSION 4.1.1)

project(IrrationalNumbers)

include_directories(inludes)    # Include headers

file(GLOB SOURCES "*.cpp")      # Include app .cpp files in the current directory

add_executable(program ${SOURCES})

target_link_libraries(program gmp mpfr)
