
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
// Multiplicity is the basic handle type in this file. Example:
//    // Create a default Multiplicity object:
//    Multiplicity handle = MultiplicityDefault();
// Functions involving Multiplicity are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_MULTIPLICITY
#define C_INTERFACE_GNDS_V2_0_GENERAL_MULTIPLICITY

#include "GNDStk.h"
#include "v2.0/general/Constant1d.h"
#include "v2.0/general/XYs1d.h"
#include "v2.0/general/Regions1d.h"
#include "v2.0/general/Polynomial1d.h"
#include "v2.0/general/Reference.h"
#include "v2.0/general/Branching1d.h"
#include "v2.0/general/Branching3d.h"
#include "v2.0/general/Unspecified.h"

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

// +++ Create, default, non-const
extern_c Handle2Multiplicity
MultiplicityDefault();

// --- Create, general, const
extern_c Handle2ConstMultiplicity
MultiplicityCreateConst(
   ConstHandle2ConstConstant1d constant1d,
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d,
   ConstHandle2ConstPolynomial1d polynomial1d,
   ConstHandle2ConstReference reference,
   ConstHandle2ConstBranching1d branching1d,
   ConstHandle2ConstBranching3d branching3d,
   ConstHandle2ConstUnspecified unspecified
);

// +++ Create, general, non-const
extern_c Handle2Multiplicity
MultiplicityCreate(
   ConstHandle2ConstConstant1d constant1d,
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d,
   ConstHandle2ConstPolynomial1d polynomial1d,
   ConstHandle2ConstReference reference,
   ConstHandle2ConstBranching1d branching1d,
   ConstHandle2ConstBranching3d branching3d,
   ConstHandle2ConstUnspecified unspecified
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
MultiplicityAssign(ConstHandle2Multiplicity self, ConstHandle2ConstMultiplicity from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
MultiplicityDelete(ConstHandle2ConstMultiplicity self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
MultiplicityRead(ConstHandle2Multiplicity self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
MultiplicityWrite(ConstHandle2ConstMultiplicity self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
MultiplicityPrint(ConstHandle2ConstMultiplicity self);

// +++ Print to standard output, as XML
extern_c int
MultiplicityPrintXML(ConstHandle2ConstMultiplicity self);

// +++ Print to standard output, as JSON
extern_c int
MultiplicityPrintJSON(ConstHandle2ConstMultiplicity self);


// -----------------------------------------------------------------------------
// Child: constant1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiplicityConstant1dHas(ConstHandle2ConstMultiplicity self);

// --- Get, const
extern_c Handle2ConstConstant1d
MultiplicityConstant1dGetConst(ConstHandle2ConstMultiplicity self);

// +++ Get, non-const
extern_c Handle2Constant1d
MultiplicityConstant1dGet(ConstHandle2Multiplicity self);

// +++ Set
extern_c void
MultiplicityConstant1dSet(ConstHandle2Multiplicity self, ConstHandle2ConstConstant1d constant1d);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiplicityXYs1dHas(ConstHandle2ConstMultiplicity self);

// --- Get, const
extern_c Handle2ConstXYs1d
MultiplicityXYs1dGetConst(ConstHandle2ConstMultiplicity self);

// +++ Get, non-const
extern_c Handle2XYs1d
MultiplicityXYs1dGet(ConstHandle2Multiplicity self);

// +++ Set
extern_c void
MultiplicityXYs1dSet(ConstHandle2Multiplicity self, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Child: regions1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiplicityRegions1dHas(ConstHandle2ConstMultiplicity self);

// --- Get, const
extern_c Handle2ConstRegions1d
MultiplicityRegions1dGetConst(ConstHandle2ConstMultiplicity self);

// +++ Get, non-const
extern_c Handle2Regions1d
MultiplicityRegions1dGet(ConstHandle2Multiplicity self);

// +++ Set
extern_c void
MultiplicityRegions1dSet(ConstHandle2Multiplicity self, ConstHandle2ConstRegions1d regions1d);


// -----------------------------------------------------------------------------
// Child: polynomial1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiplicityPolynomial1dHas(ConstHandle2ConstMultiplicity self);

// --- Get, const
extern_c Handle2ConstPolynomial1d
MultiplicityPolynomial1dGetConst(ConstHandle2ConstMultiplicity self);

// +++ Get, non-const
extern_c Handle2Polynomial1d
MultiplicityPolynomial1dGet(ConstHandle2Multiplicity self);

// +++ Set
extern_c void
MultiplicityPolynomial1dSet(ConstHandle2Multiplicity self, ConstHandle2ConstPolynomial1d polynomial1d);


// -----------------------------------------------------------------------------
// Child: reference
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiplicityReferenceHas(ConstHandle2ConstMultiplicity self);

// --- Get, const
extern_c Handle2ConstReference
MultiplicityReferenceGetConst(ConstHandle2ConstMultiplicity self);

// +++ Get, non-const
extern_c Handle2Reference
MultiplicityReferenceGet(ConstHandle2Multiplicity self);

// +++ Set
extern_c void
MultiplicityReferenceSet(ConstHandle2Multiplicity self, ConstHandle2ConstReference reference);


// -----------------------------------------------------------------------------
// Child: branching1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiplicityBranching1dHas(ConstHandle2ConstMultiplicity self);

// --- Get, const
extern_c Handle2ConstBranching1d
MultiplicityBranching1dGetConst(ConstHandle2ConstMultiplicity self);

// +++ Get, non-const
extern_c Handle2Branching1d
MultiplicityBranching1dGet(ConstHandle2Multiplicity self);

// +++ Set
extern_c void
MultiplicityBranching1dSet(ConstHandle2Multiplicity self, ConstHandle2ConstBranching1d branching1d);


// -----------------------------------------------------------------------------
// Child: branching3d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiplicityBranching3dHas(ConstHandle2ConstMultiplicity self);

// --- Get, const
extern_c Handle2ConstBranching3d
MultiplicityBranching3dGetConst(ConstHandle2ConstMultiplicity self);

// +++ Get, non-const
extern_c Handle2Branching3d
MultiplicityBranching3dGet(ConstHandle2Multiplicity self);

// +++ Set
extern_c void
MultiplicityBranching3dSet(ConstHandle2Multiplicity self, ConstHandle2ConstBranching3d branching3d);


// -----------------------------------------------------------------------------
// Child: unspecified
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiplicityUnspecifiedHas(ConstHandle2ConstMultiplicity self);

// --- Get, const
extern_c Handle2ConstUnspecified
MultiplicityUnspecifiedGetConst(ConstHandle2ConstMultiplicity self);

// +++ Get, non-const
extern_c Handle2Unspecified
MultiplicityUnspecifiedGet(ConstHandle2Multiplicity self);

// +++ Set
extern_c void
MultiplicityUnspecifiedSet(ConstHandle2Multiplicity self, ConstHandle2ConstUnspecified unspecified);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Multiplicity/src/custom.h"

#undef extern_c
#endif