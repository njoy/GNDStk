
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// Interface for C
// This header file is designed to work with both C and C++
// Function definitions are in this file's .cpp source

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
// Multiplicity is the basic handle type in this file. Example:
//    // Create a default Multiplicity object:
//    Multiplicity handle = MultiplicityDefault();
// Functions involving Multiplicity are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_TRANSPORT_MULTIPLICITY
#define C_INTERFACE_TRY_V2_0_TRANSPORT_MULTIPLICITY

#include "GNDStk.h"
#include "v2.0/unknownNamespace/XYs1d.h"
#include "v2.0/unknownNamespace/Constant1d.h"
#include "v2.0/unknownNamespace/Polynomial1d.h"
#include "v2.0/transport/Branching1d.h"
#include "v2.0/transport/Reference.h"
#include "v2.0/unknownNamespace/Gridded1d.h"
#include "v2.0/unknownNamespace/Regions1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct MultiplicityClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Multiplicity
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct MultiplicityClass *Multiplicity;

// --- Const-aware handles.
typedef const struct MultiplicityClass *const ConstHandle2ConstMultiplicity;
typedef       struct MultiplicityClass *const ConstHandle2Multiplicity;
typedef const struct MultiplicityClass *      Handle2ConstMultiplicity;
typedef       struct MultiplicityClass *      Handle2Multiplicity;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstMultiplicity
MultiplicityDefaultConst();

// +++ Create, default
extern_c Handle2Multiplicity
MultiplicityDefault();

// --- Create, general, const
extern_c Handle2ConstMultiplicity
MultiplicityCreateConst(
);

// +++ Create, general
extern_c Handle2Multiplicity
MultiplicityCreate(
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
MultiplicityAssign(ConstHandle2Multiplicity This, ConstHandle2ConstMultiplicity from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
MultiplicityDelete(ConstHandle2ConstMultiplicity This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
MultiplicityRead(ConstHandle2Multiplicity This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
MultiplicityWrite(ConstHandle2ConstMultiplicity This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
MultiplicityPrint(ConstHandle2ConstMultiplicity This);

// +++ Print to standard output, as XML
extern_c int
MultiplicityPrintXML(ConstHandle2ConstMultiplicity This);

// +++ Print to standard output, as JSON
extern_c int
MultiplicityPrintJSON(ConstHandle2ConstMultiplicity This);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
