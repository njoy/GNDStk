
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


// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

#undef extern_C
#endif
