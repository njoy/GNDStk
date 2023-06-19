
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
// Nuclides is the basic handle type in this file. Example:
//    // Create a default Nuclides object:
//    Nuclides handle = NuclidesDefault();
// Functions involving Nuclides are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_FPY_NUCLIDES
#define C_INTERFACE_TEST_V2_0_FPY_NUCLIDES

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct NuclidesClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Nuclides
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct NuclidesClass *Nuclides;

// --- Const-aware handles.
typedef const struct NuclidesClass *const ConstHandle2ConstNuclides;
typedef       struct NuclidesClass *const ConstHandle2Nuclides;
typedef const struct NuclidesClass *      Handle2ConstNuclides;
typedef       struct NuclidesClass *      Handle2Nuclides;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstNuclides
NuclidesDefaultConst();

// +++ Create, default
extern_c Handle2Nuclides
NuclidesDefault();

// --- Create, general, const
extern_c Handle2ConstNuclides
NuclidesCreateConst(
   const char *const href
);

// +++ Create, general
extern_c Handle2Nuclides
NuclidesCreate(
   const char *const href
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
NuclidesAssign(ConstHandle2Nuclides self, ConstHandle2ConstNuclides from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
NuclidesDelete(ConstHandle2ConstNuclides self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
NuclidesRead(ConstHandle2Nuclides self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
NuclidesWrite(ConstHandle2ConstNuclides self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
NuclidesPrint(ConstHandle2ConstNuclides self);

// +++ Print to standard output, as XML
extern_c int
NuclidesPrintXML(ConstHandle2ConstNuclides self);

// +++ Print to standard output, as JSON
extern_c int
NuclidesPrintJSON(ConstHandle2ConstNuclides self);


// -----------------------------------------------------------------------------
// Data vector
// -----------------------------------------------------------------------------

// ------------------------
// int
// ------------------------

// +++ Clear
extern_c void
NuclidesIntsClear(ConstHandle2Nuclides self);

// +++ Get size
extern_c size_t
NuclidesIntsSize(ConstHandle2ConstNuclides self);

// +++ Get value
// +++ By index \in [0,size)
extern_c int
NuclidesIntsGet(ConstHandle2ConstNuclides self, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
NuclidesIntsSet(ConstHandle2Nuclides self, const size_t index, const int value);

// --- Get pointer to existing values, const
extern_c const int *
NuclidesIntsGetArrayConst(ConstHandle2ConstNuclides self);

// +++ Get pointer to existing values, non-const
extern_c int *
NuclidesIntsGetArray(ConstHandle2Nuclides self);

// +++ Set completely new values and size
extern_c void
NuclidesIntsSetArray(ConstHandle2Nuclides self, const int *const values, const size_t size);

// ------------------------
// unsigned
// ------------------------

// +++ Clear
extern_c void
NuclidesUnsignedsClear(ConstHandle2Nuclides self);

// +++ Get size
extern_c size_t
NuclidesUnsignedsSize(ConstHandle2ConstNuclides self);

// +++ Get value
// +++ By index \in [0,size)
extern_c unsigned
NuclidesUnsignedsGet(ConstHandle2ConstNuclides self, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
NuclidesUnsignedsSet(ConstHandle2Nuclides self, const size_t index, const unsigned value);

// --- Get pointer to existing values, const
extern_c const unsigned *
NuclidesUnsignedsGetArrayConst(ConstHandle2ConstNuclides self);

// +++ Get pointer to existing values, non-const
extern_c unsigned *
NuclidesUnsignedsGetArray(ConstHandle2Nuclides self);

// +++ Set completely new values and size
extern_c void
NuclidesUnsignedsSetArray(ConstHandle2Nuclides self, const unsigned *const values, const size_t size);

// ------------------------
// float
// ------------------------

// +++ Clear
extern_c void
NuclidesFloatsClear(ConstHandle2Nuclides self);

// +++ Get size
extern_c size_t
NuclidesFloatsSize(ConstHandle2ConstNuclides self);

// +++ Get value
// +++ By index \in [0,size)
extern_c float
NuclidesFloatsGet(ConstHandle2ConstNuclides self, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
NuclidesFloatsSet(ConstHandle2Nuclides self, const size_t index, const float value);

// --- Get pointer to existing values, const
extern_c const float *
NuclidesFloatsGetArrayConst(ConstHandle2ConstNuclides self);

// +++ Get pointer to existing values, non-const
extern_c float *
NuclidesFloatsGetArray(ConstHandle2Nuclides self);

// +++ Set completely new values and size
extern_c void
NuclidesFloatsSetArray(ConstHandle2Nuclides self, const float *const values, const size_t size);

// ------------------------
// double
// ------------------------

// +++ Clear
extern_c void
NuclidesDoublesClear(ConstHandle2Nuclides self);

// +++ Get size
extern_c size_t
NuclidesDoublesSize(ConstHandle2ConstNuclides self);

// +++ Get value
// +++ By index \in [0,size)
extern_c double
NuclidesDoublesGet(ConstHandle2ConstNuclides self, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
NuclidesDoublesSet(ConstHandle2Nuclides self, const size_t index, const double value);

// --- Get pointer to existing values, const
extern_c const double *
NuclidesDoublesGetArrayConst(ConstHandle2ConstNuclides self);

// +++ Get pointer to existing values, non-const
extern_c double *
NuclidesDoublesGetArray(ConstHandle2Nuclides self);

// +++ Set completely new values and size
extern_c void
NuclidesDoublesSetArray(ConstHandle2Nuclides self, const double *const values, const size_t size);


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclidesHrefHas(ConstHandle2ConstNuclides self);

// +++ Get
// +++ Returns by value
extern_c const char *
NuclidesHrefGet(ConstHandle2ConstNuclides self);

// +++ Set
extern_c void
NuclidesHrefSet(ConstHandle2Nuclides self, const char *const href);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/fpy/Nuclides/src/custom.h"

#undef extern_c
#endif
