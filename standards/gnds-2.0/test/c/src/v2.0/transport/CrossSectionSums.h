
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
// CrossSectionSums is the basic handle type in this file. Example:
//    // Create a default CrossSectionSums object:
//    CrossSectionSums handle = CrossSectionSumsDefault();
// Functions involving CrossSectionSums are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TRANSPORT_CROSSSECTIONSUMS
#define C_INTERFACE_TEST_V2_0_TRANSPORT_CROSSSECTIONSUMS

#include "GNDStk.h"
#include "v2.0/transport/CrossSectionSum.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct CrossSectionSumsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ CrossSectionSums
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct CrossSectionSumsClass *CrossSectionSums;

// --- Const-aware handles.
typedef const struct CrossSectionSumsClass *const ConstHandle2ConstCrossSectionSums;
typedef       struct CrossSectionSumsClass *const ConstHandle2CrossSectionSums;
typedef const struct CrossSectionSumsClass *      Handle2ConstCrossSectionSums;
typedef       struct CrossSectionSumsClass *      Handle2CrossSectionSums;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstCrossSectionSums
CrossSectionSumsDefaultConst();

// +++ Create, default
extern_c Handle2CrossSectionSums
CrossSectionSumsDefault();

// --- Create, general, const
extern_c Handle2ConstCrossSectionSums
CrossSectionSumsCreateConst(
   ConstHandle2CrossSectionSum *const crossSectionSum, const size_t crossSectionSumSize
);

// +++ Create, general
extern_c Handle2CrossSectionSums
CrossSectionSumsCreate(
   ConstHandle2CrossSectionSum *const crossSectionSum, const size_t crossSectionSumSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
CrossSectionSumsAssign(ConstHandle2CrossSectionSums This, ConstHandle2ConstCrossSectionSums from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
CrossSectionSumsDelete(ConstHandle2ConstCrossSectionSums This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
CrossSectionSumsRead(ConstHandle2CrossSectionSums This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
CrossSectionSumsWrite(ConstHandle2ConstCrossSectionSums This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
CrossSectionSumsPrint(ConstHandle2ConstCrossSectionSums This);

// +++ Print to standard output, as XML
extern_c int
CrossSectionSumsPrintXML(ConstHandle2ConstCrossSectionSums This);

// +++ Print to standard output, as JSON
extern_c int
CrossSectionSumsPrintJSON(ConstHandle2ConstCrossSectionSums This);


// -----------------------------------------------------------------------------
// Child: crossSectionSum
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CrossSectionSumsCrossSectionSumHas(ConstHandle2ConstCrossSectionSums This);

// +++ Clear
extern_c void
CrossSectionSumsCrossSectionSumClear(ConstHandle2CrossSectionSums This);

// +++ Size
extern_c size_t
CrossSectionSumsCrossSectionSumSize(ConstHandle2ConstCrossSectionSums This);

// +++ Add
extern_c void
CrossSectionSumsCrossSectionSumAdd(ConstHandle2CrossSectionSums This, ConstHandle2ConstCrossSectionSum crossSectionSum);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstCrossSectionSum
CrossSectionSumsCrossSectionSumGetConst(ConstHandle2ConstCrossSectionSums This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2CrossSectionSum
CrossSectionSumsCrossSectionSumGet(ConstHandle2CrossSectionSums This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
CrossSectionSumsCrossSectionSumSet(
   ConstHandle2CrossSectionSums This,
   const size_t index_,
   ConstHandle2ConstCrossSectionSum crossSectionSum
);

// +++ Has, by ENDF_MT
extern_c int
CrossSectionSumsCrossSectionSumHasByENDFMT(
   ConstHandle2ConstCrossSectionSums This,
   const Integer32 ENDF_MT
);

// --- Get, by ENDF_MT, const
extern_c Handle2ConstCrossSectionSum
CrossSectionSumsCrossSectionSumGetByENDFMTConst(
   ConstHandle2ConstCrossSectionSums This,
   const Integer32 ENDF_MT
);

// +++ Get, by ENDF_MT, non-const
extern_c Handle2CrossSectionSum
CrossSectionSumsCrossSectionSumGetByENDFMT(
   ConstHandle2CrossSectionSums This,
   const Integer32 ENDF_MT
);

// +++ Set, by ENDF_MT
extern_c void
CrossSectionSumsCrossSectionSumSetByENDFMT(
   ConstHandle2CrossSectionSums This,
   const Integer32 ENDF_MT,
   ConstHandle2ConstCrossSectionSum crossSectionSum
);

// +++ Has, by label
extern_c int
CrossSectionSumsCrossSectionSumHasByLabel(
   ConstHandle2ConstCrossSectionSums This,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstCrossSectionSum
CrossSectionSumsCrossSectionSumGetByLabelConst(
   ConstHandle2ConstCrossSectionSums This,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2CrossSectionSum
CrossSectionSumsCrossSectionSumGetByLabel(
   ConstHandle2CrossSectionSums This,
   const XMLName label
);

// +++ Set, by label
extern_c void
CrossSectionSumsCrossSectionSumSetByLabel(
   ConstHandle2CrossSectionSums This,
   const XMLName label,
   ConstHandle2ConstCrossSectionSum crossSectionSum
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
