
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
// RutherfordScattering is the basic handle type in this file. Example:
//    // Create a default RutherfordScattering object:
//    RutherfordScattering handle = RutherfordScatteringDefault();
// Functions involving RutherfordScattering are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_DFILES_RUTHERFORDSCATTERING
#define C_INTERFACE_ALPHA_V2_0_DFILES_RUTHERFORDSCATTERING

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct RutherfordScatteringClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ RutherfordScattering
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct RutherfordScatteringClass *RutherfordScattering;

// --- Const-aware handles.
typedef const struct RutherfordScatteringClass *const ConstHandle2ConstRutherfordScattering;
typedef       struct RutherfordScatteringClass *const ConstHandle2RutherfordScattering;
typedef const struct RutherfordScatteringClass *      Handle2ConstRutherfordScattering;
typedef       struct RutherfordScatteringClass *      Handle2RutherfordScattering;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstRutherfordScattering
RutherfordScatteringDefaultConst();

// +++ Create, default
extern_c Handle2RutherfordScattering
RutherfordScatteringDefault();

// --- Create, general, const
extern_c Handle2ConstRutherfordScattering
RutherfordScatteringCreateConst();

// +++ Create, general
extern_c Handle2RutherfordScattering
RutherfordScatteringCreate();

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
RutherfordScatteringAssign(ConstHandle2RutherfordScattering This, ConstHandle2ConstRutherfordScattering from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
RutherfordScatteringDelete(ConstHandle2ConstRutherfordScattering This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
RutherfordScatteringRead(ConstHandle2RutherfordScattering This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
RutherfordScatteringWrite(ConstHandle2ConstRutherfordScattering This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
RutherfordScatteringPrint(ConstHandle2ConstRutherfordScattering This);

// +++ Print to standard output, as XML
extern_c int
RutherfordScatteringPrintXML(ConstHandle2ConstRutherfordScattering This);

// +++ Print to standard output, as JSON
extern_c int
RutherfordScatteringPrintJSON(ConstHandle2ConstRutherfordScattering This);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/dfiles/RutherfordScattering/src/custom.h"

#undef extern_c
#endif
