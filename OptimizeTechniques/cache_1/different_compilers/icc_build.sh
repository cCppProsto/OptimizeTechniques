#!/bin/bash

cd bin_icc
rm -rf bin
mkdir bin
cd bin

source /opt/intel/system_studio_2019/compilers_and_libraries_2019/linux/bin/compilervars.sh -arch intel64 -platform linux

export CC=/opt/intel/system_studio_2019/compilers_and_libraries_2019/linux/bin/intel64/icc
export CXX=/opt/intel/system_studio_2019/compilers_and_libraries_2019/linux/bin/intel64/icpc

cmake ..
make

