#!/bin/bash

cd bin_clang
rm -rf bin
mkdir bin
cd bin
export CC=/usr/bin/clang
export CXX=/usr/bin/clang++
cmake ..
make

