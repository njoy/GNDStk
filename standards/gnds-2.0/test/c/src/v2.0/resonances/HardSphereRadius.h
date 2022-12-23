
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
// HardSphereRadius is the basic handle type in this file. Example:
//    // Create a default HardSphereRadius object:
//    HardSphereRadius handle = HardSphereRadiusDefault();
// Functions involving HardSphereRadius are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_RESONANCES_HARDSPHERERADIUS
#define C_INTERFACE_TEST_V2_0_RESONANCES_HARDSPHERERADIUS

#include "GNDStk.h"
#include "v2.0/containers/Constant1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct HardSphereRadiusClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ HardSphereRadius
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct HardSphereRadiusClass *HardSphereRadius;

// --- Const-aware handles.
typedef const struct HardSphereRadiusClass *const ConstHandle2ConstHardSphereRadius;
typedef       struct HardSphereRadiusClass *const ConstHandle2HardSphereRadius;
typedef const struct HardSphereRadiusClass *      Handle2ConstHardSphereRadius;
typedef       struct HardSphereRadiusClass *      Handle2HardSphereRadius;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstHardSphereRadius
HardSphereRadiusDefaultConst();

// +++ Create, default
extern_c Handle2HardSphereRadius
HardSphereRadiusDefault();

// --- Create, general, const
extern_c Handle2ConstHardSphereRadius
HardSphereRadiusCreateConst(
   ConstHandle2ConstConstant1d constant1d
);

// +++ Create, general
extern_c Handle2HardSphereRadius
HardSphereRadiusCreate(
   ConstHandle2ConstConstant1d constant1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
HardSphereRadiusAssign(ConstHandle2HardSphereRadius This, ConstHandle2ConstHardSphereRadius from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
HardSphereRadiusDelete(ConstHandle2ConstHardSphereRadius This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
HardSphereRadiusRead(ConstHandle2HardSphereRadius This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
HardSphereRadiusWrite(ConstHandle2ConstHardSphereRadius This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
HardSphereRadiusPrint(ConstHandle2ConstHardSphereRadius This);

// +++ Print to standard output, as XML
extern_c int
HardSphereRadiusPrintXML(ConstHandle2ConstHardSphereRadius This);

// +++ Print to standard output, as JSON
extern_c int
HardSphereRadiusPrintJSON(ConstHandle2ConstHardSphereRadius This);


// -----------------------------------------------------------------------------
// Child: constant1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
HardSphereRadiusConstant1dHas(ConstHandle2ConstHardSphereRadius This);

// --- Get, const
extern_c Handle2ConstConstant1d
HardSphereRadiusConstant1dGetConst(ConstHandle2ConstHardSphereRadius This);

// +++ Get, non-const
extern_c Handle2Constant1d
HardSphereRadiusConstant1dGet(ConstHandle2HardSphereRadius This);

// +++ Set
extern_c void
HardSphereRadiusConstant1dSet(ConstHandle2HardSphereRadius This, ConstHandle2ConstConstant1d constant1d);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
