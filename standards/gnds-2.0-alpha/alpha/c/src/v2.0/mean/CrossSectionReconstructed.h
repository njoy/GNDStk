
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
// CrossSectionReconstructed is the basic handle type in this file. Example:
//    // Create a default CrossSectionReconstructed object:
//    CrossSectionReconstructed handle = CrossSectionReconstructedDefault();
// Functions involving CrossSectionReconstructed are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_MEAN_CROSSSECTIONRECONSTRUCTED
#define C_INTERFACE_ALPHA_V2_0_MEAN_CROSSSECTIONRECONSTRUCTED

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct CrossSectionReconstructedClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ CrossSectionReconstructed
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct CrossSectionReconstructedClass *CrossSectionReconstructed;

// --- Const-aware handles.
typedef const struct CrossSectionReconstructedClass *const ConstHandle2ConstCrossSectionReconstructed;
typedef       struct CrossSectionReconstructedClass *const ConstHandle2CrossSectionReconstructed;
typedef const struct CrossSectionReconstructedClass *      Handle2ConstCrossSectionReconstructed;
typedef       struct CrossSectionReconstructedClass *      Handle2CrossSectionReconstructed;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstCrossSectionReconstructed
CrossSectionReconstructedDefaultConst();

// +++ Create, default
extern_c Handle2CrossSectionReconstructed
CrossSectionReconstructedDefault();

// --- Create, general, const
extern_c Handle2ConstCrossSectionReconstructed
CrossSectionReconstructedCreateConst(
   const char *const label,
   const char *const derivedFrom,
   const char *const date
);

// +++ Create, general
extern_c Handle2CrossSectionReconstructed
CrossSectionReconstructedCreate(
   const char *const label,
   const char *const derivedFrom,
   const char *const date
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
CrossSectionReconstructedAssign(ConstHandle2CrossSectionReconstructed This, ConstHandle2ConstCrossSectionReconstructed from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
CrossSectionReconstructedDelete(ConstHandle2ConstCrossSectionReconstructed This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
CrossSectionReconstructedRead(ConstHandle2CrossSectionReconstructed This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
CrossSectionReconstructedWrite(ConstHandle2ConstCrossSectionReconstructed This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
CrossSectionReconstructedPrint(ConstHandle2ConstCrossSectionReconstructed This);

// +++ Print to standard output, as XML
extern_c int
CrossSectionReconstructedPrintXML(ConstHandle2ConstCrossSectionReconstructed This);

// +++ Print to standard output, as JSON
extern_c int
CrossSectionReconstructedPrintJSON(ConstHandle2ConstCrossSectionReconstructed This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CrossSectionReconstructedLabelHas(ConstHandle2ConstCrossSectionReconstructed This);

// +++ Get
// +++ Returns by value
extern_c const char *
CrossSectionReconstructedLabelGet(ConstHandle2ConstCrossSectionReconstructed This);

// +++ Set
extern_c void
CrossSectionReconstructedLabelSet(ConstHandle2CrossSectionReconstructed This, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: derivedFrom
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CrossSectionReconstructedDerivedFromHas(ConstHandle2ConstCrossSectionReconstructed This);

// +++ Get
// +++ Returns by value
extern_c const char *
CrossSectionReconstructedDerivedFromGet(ConstHandle2ConstCrossSectionReconstructed This);

// +++ Set
extern_c void
CrossSectionReconstructedDerivedFromSet(ConstHandle2CrossSectionReconstructed This, const char *const derivedFrom);


// -----------------------------------------------------------------------------
// Metadatum: date
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CrossSectionReconstructedDateHas(ConstHandle2ConstCrossSectionReconstructed This);

// +++ Get
// +++ Returns by value
extern_c const char *
CrossSectionReconstructedDateGet(ConstHandle2ConstCrossSectionReconstructed This);

// +++ Set
extern_c void
CrossSectionReconstructedDateSet(ConstHandle2CrossSectionReconstructed This, const char *const date);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/mean/CrossSectionReconstructed/src/custom.h"

#undef extern_c
#endif
