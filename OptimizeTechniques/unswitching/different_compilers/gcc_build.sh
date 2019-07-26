#!/bin/bash

cd bin_gcc
rm -rf bin
mkdir bin
cd bin

export CC=/usr/bin/gcc
export CXX=/usr/bin/g++

cmake ..
make

