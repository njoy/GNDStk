#!/bin/bash

# Specify your base GNDStk directory (as cloned from github) here.
GNDSTKDIR=/path/to/your/downloaded/GNDStk

# Example compilation command. -std=c++17, and the -Is, are needed.
COMPILE="
   g++
  -std=c++17
  -I$GNDSTKDIR/src
  -I$GNDSTKDIR/build/_deps/pugixml-adapter-src/src/src
  -I$GNDSTKDIR/build/_deps/json-src/include
  -I$GNDSTKDIR/build/_deps/json-src/include/nlohmann
  -I$GNDSTKDIR/build/_deps/log-src/src
  -I$GNDSTKDIR/build/_deps/spdlog-src/include
  -Wall -Wextra -Wpedantic"

# pugixml.cpp is the only C++ source file, other than your own,
# that needs to be compiled. We'll arrange to build it *once*:
if [ ! -f "pugixml.o" ]; then
$COMPILE \
   $GNDSTKDIR/build/_deps/pugixml-adapter-src/src/src/pugixml.cpp \
  -c -o pugixml.o
fi

# Compile your own C++ application, linking with the .o from above.
$COMPILE app.cpp pugixml.o -o app
