
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
//    // +++ remark
// Constructs you're LESS likely to care about are preceded with:
//    // --- remark
// Anything not marked as above can be ignored by most users.
//
// Isotropic2d is the basic handle type in this file. Example:
//    // Create a default Isotropic2d object:
//    Isotropic2d handle = Isotropic2dDefault();
// Functions involving Isotropic2d are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_ISOTROPIC2D
#define C_INTERFACE_GNDS_V2_0_GENERAL_ISOTROPIC2D

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct Isotropic2dClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Isotropic2d
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct Isotropic2dClass *Isotropic2d;

// --- Const-aware handles.
typedef const struct Isotropic2dClass *const ConstHandle2ConstIsotropic2d;
typedef       struct Isotropic2dClass *const ConstHandle2Isotropic2d;
typedef const struct Isotropic2dClass *      Handle2ConstIsotropic2d;
typedef       struct Isotropic2dClass *      Handle2Isotropic2d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstIsotropic2d
Isotropic2dDefaultConst();

// +++ Create, default, non-const
extern_c Handle2Isotropic2d
Isotropic2dDefault();

// --- Create, general, const
extern_c Handle2ConstIsotropic2d
Isotropic2dCreateConst();

// +++ Create, general, non-const
extern_c Handle2Isotropic2d
Isotropic2dCreate();

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
Isotropic2dAssign(ConstHandle2Isotropic2d self, ConstHandle2ConstIsotropic2d from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
Isotropic2dDelete(ConstHandle2ConstIsotropic2d self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
Isotropic2dRead(ConstHandle2Isotropic2d self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
Isotropic2dWrite(ConstHandle2ConstIsotropic2d self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
Isotropic2dPrint(ConstHandle2ConstIsotropic2d self);

// +++ Print to standard output, as XML
extern_c int
Isotropic2dPrintXML(ConstHandle2ConstIsotropic2d self);

// +++ Print to standard output, as JSON
extern_c int
Isotropic2dPrintJSON(ConstHandle2ConstIsotropic2d self);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Isotropic2d/src/custom.h"

#undef extern_c
#endif