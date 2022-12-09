
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
// Yields is the basic handle type in this file. Example:
//    // Create a default Yields object:
//    Yields handle = YieldsDefault();
// Functions involving Yields are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_FPY_YIELDS
#define C_INTERFACE_TEST_V2_0_FPY_YIELDS

#include "GNDStk.h"
#include "v2.0/fpy/Nuclides.h"
#include "v2.0/containers/Values.h"
#include "v2.0/containers/Uncertainty.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct YieldsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Yields
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct YieldsClass *Yields;

// --- Const-aware handles.
typedef const struct YieldsClass *const ConstHandle2ConstYields;
typedef       struct YieldsClass *const ConstHandle2Yields;
typedef const struct YieldsClass *      Handle2ConstYields;
typedef       struct YieldsClass *      Handle2Yields;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstYields
YieldsDefaultConst();

// +++ Create, default
extern_c Handle2Yields
YieldsDefault();

// --- Create, general, const
extern_c Handle2ConstYields
YieldsCreateConst(
   ConstHandle2ConstNuclides nuclides,
   ConstHandle2ConstValues values,
   ConstHandle2ConstUncertainty uncertainty
);

// +++ Create, general
extern_c Handle2Yields
YieldsCreate(
   ConstHandle2ConstNuclides nuclides,
   ConstHandle2ConstValues values,
   ConstHandle2ConstUncertainty uncertainty
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
YieldsAssign(ConstHandle2Yields This, ConstHandle2ConstYields from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
YieldsDelete(ConstHandle2ConstYields This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
YieldsRead(ConstHandle2Yields This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
YieldsWrite(ConstHandle2ConstYields This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
YieldsPrint(ConstHandle2ConstYields This);

// +++ Print to standard output, as XML
extern_c int
YieldsPrintXML(ConstHandle2ConstYields This);

// +++ Print to standard output, as JSON
extern_c int
YieldsPrintJSON(ConstHandle2ConstYields This);


// -----------------------------------------------------------------------------
// Child: nuclides
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
YieldsNuclidesHas(ConstHandle2ConstYields This);

// --- Get, const
extern_c Handle2ConstNuclides
YieldsNuclidesGetConst(ConstHandle2ConstYields This);

// +++ Get, non-const
extern_c Handle2Nuclides
YieldsNuclidesGet(ConstHandle2Yields This);

// +++ Set
extern_c void
YieldsNuclidesSet(ConstHandle2Yields This, ConstHandle2ConstNuclides nuclides);


// -----------------------------------------------------------------------------
// Child: values
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
YieldsValuesHas(ConstHandle2ConstYields This);

// --- Get, const
extern_c Handle2ConstValues
YieldsValuesGetConst(ConstHandle2ConstYields This);

// +++ Get, non-const
extern_c Handle2Values
YieldsValuesGet(ConstHandle2Yields This);

// +++ Set
extern_c void
YieldsValuesSet(ConstHandle2Yields This, ConstHandle2ConstValues values);


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
YieldsUncertaintyHas(ConstHandle2ConstYields This);

// --- Get, const
extern_c Handle2ConstUncertainty
YieldsUncertaintyGetConst(ConstHandle2ConstYields This);

// +++ Get, non-const
extern_c Handle2Uncertainty
YieldsUncertaintyGet(ConstHandle2Yields This);

// +++ Set
extern_c void
YieldsUncertaintySet(ConstHandle2Yields This, ConstHandle2ConstUncertainty uncertainty);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
