
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
// CrossSectionSum is the basic handle type in this file. Example:
//    // Create a default CrossSectionSum object:
//    CrossSectionSum handle = CrossSectionSumDefault();
// Functions involving CrossSectionSum are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TRANSPORT_CROSSSECTIONSUM
#define C_INTERFACE_TEST_V2_0_TRANSPORT_CROSSSECTIONSUM

#include "GNDStk.h"
#include "v2.0/common/Q.h"
#include "v2.0/transport/CrossSection.h"
#include "v2.0/transport/Summands.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct CrossSectionSumClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ CrossSectionSum
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct CrossSectionSumClass *CrossSectionSum;

// --- Const-aware handles.
typedef const struct CrossSectionSumClass *const ConstHandle2ConstCrossSectionSum;
typedef       struct CrossSectionSumClass *const ConstHandle2CrossSectionSum;
typedef const struct CrossSectionSumClass *      Handle2ConstCrossSectionSum;
typedef       struct CrossSectionSumClass *      Handle2CrossSectionSum;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstCrossSectionSum
CrossSectionSumDefaultConst();

// +++ Create, default
extern_c Handle2CrossSectionSum
CrossSectionSumDefault();

// --- Create, general, const
extern_c Handle2ConstCrossSectionSum
CrossSectionSumCreateConst(
   const Integer32 ENDF_MT,
   const XMLName label,
   ConstHandle2ConstQ Q,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstSummands summands
);

// +++ Create, general
extern_c Handle2CrossSectionSum
CrossSectionSumCreate(
   const Integer32 ENDF_MT,
   const XMLName label,
   ConstHandle2ConstQ Q,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstSummands summands
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
CrossSectionSumAssign(ConstHandle2CrossSectionSum self, ConstHandle2ConstCrossSectionSum from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
CrossSectionSumDelete(ConstHandle2ConstCrossSectionSum self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
CrossSectionSumRead(ConstHandle2CrossSectionSum self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
CrossSectionSumWrite(ConstHandle2ConstCrossSectionSum self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
CrossSectionSumPrint(ConstHandle2ConstCrossSectionSum self);

// +++ Print to standard output, as XML
extern_c int
CrossSectionSumPrintXML(ConstHandle2ConstCrossSectionSum self);

// +++ Print to standard output, as JSON
extern_c int
CrossSectionSumPrintJSON(ConstHandle2ConstCrossSectionSum self);


// -----------------------------------------------------------------------------
// Metadatum: ENDF_MT
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CrossSectionSumENDFMTHas(ConstHandle2ConstCrossSectionSum self);

// +++ Get
// +++ Returns by value
extern_c Integer32
CrossSectionSumENDFMTGet(ConstHandle2ConstCrossSectionSum self);

// +++ Set
extern_c void
CrossSectionSumENDFMTSet(ConstHandle2CrossSectionSum self, const Integer32 ENDF_MT);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CrossSectionSumLabelHas(ConstHandle2ConstCrossSectionSum self);

// +++ Get
// +++ Returns by value
extern_c XMLName
CrossSectionSumLabelGet(ConstHandle2ConstCrossSectionSum self);

// +++ Set
extern_c void
CrossSectionSumLabelSet(ConstHandle2CrossSectionSum self, const XMLName label);


// -----------------------------------------------------------------------------
// Child: Q
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CrossSectionSumQHas(ConstHandle2ConstCrossSectionSum self);

// --- Get, const
extern_c Handle2ConstQ
CrossSectionSumQGetConst(ConstHandle2ConstCrossSectionSum self);

// +++ Get, non-const
extern_c Handle2Q
CrossSectionSumQGet(ConstHandle2CrossSectionSum self);

// +++ Set
extern_c void
CrossSectionSumQSet(ConstHandle2CrossSectionSum self, ConstHandle2ConstQ Q);


// -----------------------------------------------------------------------------
// Child: crossSection
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CrossSectionSumCrossSectionHas(ConstHandle2ConstCrossSectionSum self);

// --- Get, const
extern_c Handle2ConstCrossSection
CrossSectionSumCrossSectionGetConst(ConstHandle2ConstCrossSectionSum self);

// +++ Get, non-const
extern_c Handle2CrossSection
CrossSectionSumCrossSectionGet(ConstHandle2CrossSectionSum self);

// +++ Set
extern_c void
CrossSectionSumCrossSectionSet(ConstHandle2CrossSectionSum self, ConstHandle2ConstCrossSection crossSection);


// -----------------------------------------------------------------------------
// Child: summands
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CrossSectionSumSummandsHas(ConstHandle2ConstCrossSectionSum self);

// --- Get, const
extern_c Handle2ConstSummands
CrossSectionSumSummandsGetConst(ConstHandle2ConstCrossSectionSum self);

// +++ Get, non-const
extern_c Handle2Summands
CrossSectionSumSummandsGet(ConstHandle2CrossSectionSum self);

// +++ Set
extern_c void
CrossSectionSumSummandsSet(ConstHandle2CrossSectionSum self, ConstHandle2ConstSummands summands);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/CrossSectionSum/src/custom.h"

#undef extern_c
#endif
