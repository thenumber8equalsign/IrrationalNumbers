#!/bin/bash

if command -v cmake &> /dev/null && command -v make &> /dev/null && command -v g++ &> /dev/null; then
    echo "cmake, make, and g++ are installed"
else
fi
    echo "You need to install cmake, make and g++ on your system"

#cmake -DCMAKE_BUILD_TYPE=Debug ../src
#make