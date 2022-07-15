
// -----------------------------------------------------------------------------
// Interface for C
// This file works in both C++ and C
// -----------------------------------------------------------------------------

#ifndef GNDSTK_CINTERFACE
#define GNDSTK_CINTERFACE

#ifdef __cplusplus
   // For C++
   #include "GNDStk.hpp"
   #define extern_C extern "C"
#else
   // For C
   #define extern_C
#endif


// -----------------------------------------------------------------------------
// Function declarations
// Function definitions are in this file's .cpp
// -----------------------------------------------------------------------------

// colors
extern_C
void color(const int);

// todo
// Obviously, we'll want much, much more here. I'll probably add additional
// C-style interfaces to GNDStk's C++ code gradually, as we discover what
// our C language users want. Note that we're speaking here about the C
// interface to the overarching GNDStk library, not a C interface to some
// particular set of generated C++ classes that somebody might have created
// with our code generator. Those C interfaces are (or will be) created
// automatically, by the code generator, just as the C++ classes are.


// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

#undef extern_C
#endif
