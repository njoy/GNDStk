
// -----------------------------------------------------------------------------
// Interface for C
// Declarations
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDSTK
#define C_INTERFACE_GNDSTK

// This file works in both C++ and C
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
// Definitions are in this file's .cpp
// -----------------------------------------------------------------------------

extern_C void indent(const int);
extern_C void align(const int);
extern_C void colors(const int);

extern_C void comments(const int);
extern_C void columns(const long);
extern_C void elements(const long);

extern_C void notes(const int);
extern_C void warnings(const int);
extern_C void debug(const int);
extern_C void context(const int);

extern_C void threads(const int);

// todo
// Obviously, we'll want much more here. I'll probably add additional
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
