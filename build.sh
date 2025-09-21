#!/bin/bash

if command -v cmake &> /dev/null && command -v make &> /dev/null && command -v g++ &> /dev/null; then
    echo "i"
    exit 1
    echo "CMake, Make, and g++ are installed, running CMake"
    mkdir build
    cd build
    cmake -DCMAKE_BUILD_TYPE=Release ../src
    make
else
    echo "You need to install CMake, Make and g++ on your system"
    exit 1
fi
