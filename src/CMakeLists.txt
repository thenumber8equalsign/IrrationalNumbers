cmake_minimum_required(VERSION 4.1.1)

project(IrrationalNumbers)

include_directories(includes)    # Include headers

file(GLOB SOURCES "*.cpp" "includes/*.cpp")      # Include app .cpp files in the current directory

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_CFG_INTDIR}/bin")
add_executable(program ${SOURCES})

target_link_libraries(program gmp mpfr m)
