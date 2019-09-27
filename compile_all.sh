#!/bin/bash


echo "Compile library and then test aplication"
make clean
make
echo "Now Compile test"
cd test
make clean
make

