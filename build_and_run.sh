#!/usr/bin/bash
./build.sh
if [ $? -ne 0 ]; then
    echo "Errors occurred while building"
else
    ./build/bin/IrrationalNumbers
fi
