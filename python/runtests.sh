#!/bin/bash

# this script copies the dynamic library for the GNDStk python module
# and runs all the unit tests it can find

rm GNDStk.*.so
cp ../build/GNDStk.*.so .
python -m unittest discover -v -p "Test*"
