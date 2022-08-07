
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// Interface for C.
// Note that this header file is designed to work with both C and C++.
// Function definitions are in this file's .cpp source.

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Instructions for Users
//
// Constructs you're MORE likely to care about are preceded with:
//    // +++ comment
// Constructs you're LESS likely to care about are preceded with:
//    // --- comment
// Anything not marked as above can be ignored by most users.
//
// Isotope is the basic handle type in this file:
//    Isotope isotope = IsotopeDefault();
// Functions for Isotope are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_MULTI_V1_MULTIGROUP_ISOTOPE
#define C_INTERFACE_MULTI_V1_MULTIGROUP_ISOTOPE

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct IsotopeClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Isotope
// +++ General handle, suitable for many users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct IsotopeClass *Isotope;

// --- Const-aware handles, re: constness of handle vs. handled object.
typedef const struct IsotopeClass *const ConstHandle2ConstIsotope;
typedef       struct IsotopeClass *const ConstHandle2Isotope;
typedef const struct IsotopeClass *      Handle2ConstIsotope;
typedef       struct IsotopeClass *      Handle2Isotope;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create: default, const
extern_c Handle2ConstIsotope
IsotopeDefaultConst();

// +++ Create: default
extern_c Handle2Isotope
IsotopeDefault();

// --- Create: general, const
extern_c Handle2ConstIsotope
IsotopeCreateConst(
   const int mass_number
);

// +++ Create: general
extern_c Handle2Isotope
IsotopeCreate(
   const int mass_number
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
IsotopeAssign(ConstHandle2Isotope This, ConstHandle2ConstIsotope from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
IsotopeDelete(ConstHandle2ConstIsotope This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
IsotopeRead(ConstHandle2Isotope This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
IsotopeWrite(ConstHandle2ConstIsotope This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
IsotopePrint(ConstHandle2ConstIsotope This);

// +++ Print to standard output, as XML
extern_c int
IsotopePrintXML(ConstHandle2ConstIsotope This);

// +++ Print to standard output, as JSON
extern_c int
IsotopePrintJSON(ConstHandle2ConstIsotope This);


// -----------------------------------------------------------------------------
// Re: mass_number
// -----------------------------------------------------------------------------

// +++ Has, Get, Set
// +++ Get returns by value
extern_c int
IsotopeMassNumberHas(ConstHandle2ConstIsotope This);
extern_c int
IsotopeMassNumberGet(ConstHandle2ConstIsotope This);
extern_c void
IsotopeMassNumberSet(ConstHandle2Isotope This, const int mass_number);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif