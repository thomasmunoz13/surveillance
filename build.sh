#!/bin/bash

mkdir build
cd build
cmake ../ && make -j8

cd ..
mv build/surveillance .
rm -Rf build
