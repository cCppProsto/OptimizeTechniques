#!/bin/bash

rm -rf bin_compare
mkdir bin_compare

./clang_build.sh
./gcc_build.sh
./icc_build.sh

cp -rf bin_clang/bin/clang_test bin_compare
cp -rf bin_gcc/bin/gcc_test bin_compare
cp -rf bin_icc/bin/icc_test bin_compare
