
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
// SimpleMaxwellianFission is the basic handle type in this file. Example:
//    // Create a default SimpleMaxwellianFission object:
//    SimpleMaxwellianFission handle = SimpleMaxwellianFissionDefault();
// Functions involving SimpleMaxwellianFission are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_FISSIONTRANSPORT_SIMPLEMAXWELLIANFISSION
#define C_INTERFACE_TEST_V2_0_FISSIONTRANSPORT_SIMPLEMAXWELLIANFISSION

#include "GNDStk.h"
#include "v2.0/transport/U.h"
#include "v2.0/transport/Theta.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct SimpleMaxwellianFissionClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ SimpleMaxwellianFission
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct SimpleMaxwellianFissionClass *SimpleMaxwellianFission;

// --- Const-aware handles.
typedef const struct SimpleMaxwellianFissionClass *const ConstHandle2ConstSimpleMaxwellianFission;
typedef       struct SimpleMaxwellianFissionClass *const ConstHandle2SimpleMaxwellianFission;
typedef const struct SimpleMaxwellianFissionClass *      Handle2ConstSimpleMaxwellianFission;
typedef       struct SimpleMaxwellianFissionClass *      Handle2SimpleMaxwellianFission;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstSimpleMaxwellianFission
SimpleMaxwellianFissionDefaultConst();

// +++ Create, default
extern_c Handle2SimpleMaxwellianFission
SimpleMaxwellianFissionDefault();

// --- Create, general, const
extern_c Handle2ConstSimpleMaxwellianFission
SimpleMaxwellianFissionCreateConst(
   ConstHandle2ConstU U,
   ConstHandle2ConstTheta theta
);

// +++ Create, general
extern_c Handle2SimpleMaxwellianFission
SimpleMaxwellianFissionCreate(
   ConstHandle2ConstU U,
   ConstHandle2ConstTheta theta
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
SimpleMaxwellianFissionAssign(ConstHandle2SimpleMaxwellianFission self, ConstHandle2ConstSimpleMaxwellianFission from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
SimpleMaxwellianFissionDelete(ConstHandle2ConstSimpleMaxwellianFission self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
SimpleMaxwellianFissionRead(ConstHandle2SimpleMaxwellianFission self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
SimpleMaxwellianFissionWrite(ConstHandle2ConstSimpleMaxwellianFission self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
SimpleMaxwellianFissionPrint(ConstHandle2ConstSimpleMaxwellianFission self);

// +++ Print to standard output, as XML
extern_c int
SimpleMaxwellianFissionPrintXML(ConstHandle2ConstSimpleMaxwellianFission self);

// +++ Print to standard output, as JSON
extern_c int
SimpleMaxwellianFissionPrintJSON(ConstHandle2ConstSimpleMaxwellianFission self);


// -----------------------------------------------------------------------------
// Child: U
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SimpleMaxwellianFissionUHas(ConstHandle2ConstSimpleMaxwellianFission self);

// --- Get, const
extern_c Handle2ConstU
SimpleMaxwellianFissionUGetConst(ConstHandle2ConstSimpleMaxwellianFission self);

// +++ Get, non-const
extern_c Handle2U
SimpleMaxwellianFissionUGet(ConstHandle2SimpleMaxwellianFission self);

// +++ Set
extern_c void
SimpleMaxwellianFissionUSet(ConstHandle2SimpleMaxwellianFission self, ConstHandle2ConstU U);


// -----------------------------------------------------------------------------
// Child: theta
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SimpleMaxwellianFissionThetaHas(ConstHandle2ConstSimpleMaxwellianFission self);

// --- Get, const
extern_c Handle2ConstTheta
SimpleMaxwellianFissionThetaGetConst(ConstHandle2ConstSimpleMaxwellianFission self);

// +++ Get, non-const
extern_c Handle2Theta
SimpleMaxwellianFissionThetaGet(ConstHandle2SimpleMaxwellianFission self);

// +++ Set
extern_c void
SimpleMaxwellianFissionThetaSet(ConstHandle2SimpleMaxwellianFission self, ConstHandle2ConstTheta theta);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/fissionTransport/SimpleMaxwellianFission/src/custom.h"

#undef extern_c
#endif
