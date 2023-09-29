
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
// Mass is the basic handle type in this file. Example:
//    // Create a default Mass object:
//    Mass handle = MassDefault();
// Functions involving Mass are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_MASS
#define C_INTERFACE_GNDS_V2_0_GENERAL_MASS

#include "GNDStk.h"
#include "v2.0/general/Double.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct MassClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Mass
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct MassClass *Mass;

// --- Const-aware handles.
typedef const struct MassClass *const ConstHandle2ConstMass;
typedef       struct MassClass *const ConstHandle2Mass;
typedef const struct MassClass *      Handle2ConstMass;
typedef       struct MassClass *      Handle2Mass;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstMass
MassDefaultConst();

// +++ Create, default, non-const
extern_c Handle2Mass
MassDefault();

// --- Create, general, const
extern_c Handle2ConstMass
MassCreateConst(
   const double value,
   const char *const unit,
   ConstHandle2ConstDouble Double
);

// +++ Create, general, non-const
extern_c Handle2Mass
MassCreate(
   const double value,
   const char *const unit,
   ConstHandle2ConstDouble Double
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
MassAssign(ConstHandle2Mass self, ConstHandle2ConstMass from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
MassDelete(ConstHandle2ConstMass self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
MassRead(ConstHandle2Mass self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
MassWrite(ConstHandle2ConstMass self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
MassPrint(ConstHandle2ConstMass self);

// +++ Print to standard output, as XML
extern_c int
MassPrintXML(ConstHandle2ConstMass self);

// +++ Print to standard output, as JSON
extern_c int
MassPrintJSON(ConstHandle2ConstMass self);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MassValueHas(ConstHandle2ConstMass self);

// +++ Get
// +++ Returns by value
extern_c double
MassValueGet(ConstHandle2ConstMass self);

// +++ Set
extern_c void
MassValueSet(ConstHandle2Mass self, const double value);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MassUnitHas(ConstHandle2ConstMass self);

// +++ Get
// +++ Returns by value
extern_c const char *
MassUnitGet(ConstHandle2ConstMass self);

// +++ Set
extern_c void
MassUnitSet(ConstHandle2Mass self, const char *const unit);


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MassDoubleHas(ConstHandle2ConstMass self);

// --- Get, const
extern_c Handle2ConstDouble
MassDoubleGetConst(ConstHandle2ConstMass self);

// +++ Get, non-const
extern_c Handle2Double
MassDoubleGet(ConstHandle2Mass self);

// +++ Set
extern_c void
MassDoubleSet(ConstHandle2Mass self, ConstHandle2ConstDouble Double);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Mass/src/custom.h"

#undef extern_c
#endif
