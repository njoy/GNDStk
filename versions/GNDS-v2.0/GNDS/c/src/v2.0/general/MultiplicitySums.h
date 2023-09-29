
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
// MultiplicitySums is the basic handle type in this file. Example:
//    // Create a default MultiplicitySums object:
//    MultiplicitySums handle = MultiplicitySumsDefault();
// Functions involving MultiplicitySums are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_MULTIPLICITYSUMS
#define C_INTERFACE_GNDS_V2_0_GENERAL_MULTIPLICITYSUMS

#include "GNDStk.h"
#include "v2.0/general/MultiplicitySum.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct MultiplicitySumsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ MultiplicitySums
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct MultiplicitySumsClass *MultiplicitySums;

// --- Const-aware handles.
typedef const struct MultiplicitySumsClass *const ConstHandle2ConstMultiplicitySums;
typedef       struct MultiplicitySumsClass *const ConstHandle2MultiplicitySums;
typedef const struct MultiplicitySumsClass *      Handle2ConstMultiplicitySums;
typedef       struct MultiplicitySumsClass *      Handle2MultiplicitySums;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstMultiplicitySums
MultiplicitySumsDefaultConst();

// +++ Create, default, non-const
extern_c Handle2MultiplicitySums
MultiplicitySumsDefault();

// --- Create, general, const
extern_c Handle2ConstMultiplicitySums
MultiplicitySumsCreateConst(
   ConstHandle2MultiplicitySum *const multiplicitySum, const size_t multiplicitySumSize
);

// +++ Create, general, non-const
extern_c Handle2MultiplicitySums
MultiplicitySumsCreate(
   ConstHandle2MultiplicitySum *const multiplicitySum, const size_t multiplicitySumSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
MultiplicitySumsAssign(ConstHandle2MultiplicitySums self, ConstHandle2ConstMultiplicitySums from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
MultiplicitySumsDelete(ConstHandle2ConstMultiplicitySums self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
MultiplicitySumsRead(ConstHandle2MultiplicitySums self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
MultiplicitySumsWrite(ConstHandle2ConstMultiplicitySums self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
MultiplicitySumsPrint(ConstHandle2ConstMultiplicitySums self);

// +++ Print to standard output, as XML
extern_c int
MultiplicitySumsPrintXML(ConstHandle2ConstMultiplicitySums self);

// +++ Print to standard output, as JSON
extern_c int
MultiplicitySumsPrintJSON(ConstHandle2ConstMultiplicitySums self);


// -----------------------------------------------------------------------------
// Child: multiplicitySum
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiplicitySumsMultiplicitySumHas(ConstHandle2ConstMultiplicitySums self);

// +++ Clear
extern_c void
MultiplicitySumsMultiplicitySumClear(ConstHandle2MultiplicitySums self);

// +++ Size
extern_c size_t
MultiplicitySumsMultiplicitySumSize(ConstHandle2ConstMultiplicitySums self);

// +++ Add
extern_c void
MultiplicitySumsMultiplicitySumAdd(ConstHandle2MultiplicitySums self, ConstHandle2ConstMultiplicitySum multiplicitySum);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstMultiplicitySum
MultiplicitySumsMultiplicitySumGetConst(ConstHandle2ConstMultiplicitySums self, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2MultiplicitySum
MultiplicitySumsMultiplicitySumGet(ConstHandle2MultiplicitySums self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
MultiplicitySumsMultiplicitySumSet(
   ConstHandle2MultiplicitySums self,
   const size_t index_,
   ConstHandle2ConstMultiplicitySum multiplicitySum
);

// ------------------------
// Re: metadatum label
// ------------------------

// +++ Has, by label
extern_c int
MultiplicitySumsMultiplicitySumHasByLabel(
   ConstHandle2ConstMultiplicitySums self,
   const char *const label
);

// --- Get, by label, const
extern_c Handle2ConstMultiplicitySum
MultiplicitySumsMultiplicitySumGetByLabelConst(
   ConstHandle2ConstMultiplicitySums self,
   const char *const label
);

// +++ Get, by label, non-const
extern_c Handle2MultiplicitySum
MultiplicitySumsMultiplicitySumGetByLabel(
   ConstHandle2MultiplicitySums self,
   const char *const label
);

// +++ Set, by label
extern_c void
MultiplicitySumsMultiplicitySumSetByLabel(
   ConstHandle2MultiplicitySums self,
   const char *const label,
   ConstHandle2ConstMultiplicitySum multiplicitySum
);

// ------------------------
// Re: metadatum ENDF_MT
// ------------------------

// +++ Has, by ENDF_MT
extern_c int
MultiplicitySumsMultiplicitySumHasByENDFMT(
   ConstHandle2ConstMultiplicitySums self,
   const int ENDF_MT
);

// --- Get, by ENDF_MT, const
extern_c Handle2ConstMultiplicitySum
MultiplicitySumsMultiplicitySumGetByENDFMTConst(
   ConstHandle2ConstMultiplicitySums self,
   const int ENDF_MT
);

// +++ Get, by ENDF_MT, non-const
extern_c Handle2MultiplicitySum
MultiplicitySumsMultiplicitySumGetByENDFMT(
   ConstHandle2MultiplicitySums self,
   const int ENDF_MT
);

// +++ Set, by ENDF_MT
extern_c void
MultiplicitySumsMultiplicitySumSetByENDFMT(
   ConstHandle2MultiplicitySums self,
   const int ENDF_MT,
   ConstHandle2ConstMultiplicitySum multiplicitySum
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/MultiplicitySums/src/custom.h"

#undef extern_c
#endif
