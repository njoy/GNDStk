
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
// Slices is the basic handle type in this file. Example:
//    // Create a default Slices object:
//    Slices handle = SlicesDefault();
// Functions involving Slices are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_SLICES
#define C_INTERFACE_GNDS_V2_0_GENERAL_SLICES

#include "GNDStk.h"
#include "v2.0/general/Slice.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct SlicesClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Slices
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct SlicesClass *Slices;

// --- Const-aware handles.
typedef const struct SlicesClass *const ConstHandle2ConstSlices;
typedef       struct SlicesClass *const ConstHandle2Slices;
typedef const struct SlicesClass *      Handle2ConstSlices;
typedef       struct SlicesClass *      Handle2Slices;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstSlices
SlicesDefaultConst();

// +++ Create, default
extern_c Handle2Slices
SlicesDefault();

// --- Create, general, const
extern_c Handle2ConstSlices
SlicesCreateConst(
   ConstHandle2Slice *const slice, const size_t sliceSize
);

// +++ Create, general
extern_c Handle2Slices
SlicesCreate(
   ConstHandle2Slice *const slice, const size_t sliceSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
SlicesAssign(ConstHandle2Slices self, ConstHandle2ConstSlices from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
SlicesDelete(ConstHandle2ConstSlices self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
SlicesRead(ConstHandle2Slices self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
SlicesWrite(ConstHandle2ConstSlices self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
SlicesPrint(ConstHandle2ConstSlices self);

// +++ Print to standard output, as XML
extern_c int
SlicesPrintXML(ConstHandle2ConstSlices self);

// +++ Print to standard output, as JSON
extern_c int
SlicesPrintJSON(ConstHandle2ConstSlices self);


// -----------------------------------------------------------------------------
// Child: slice
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SlicesSliceHas(ConstHandle2ConstSlices self);

// +++ Clear
extern_c void
SlicesSliceClear(ConstHandle2Slices self);

// +++ Size
extern_c size_t
SlicesSliceSize(ConstHandle2ConstSlices self);

// +++ Add
extern_c void
SlicesSliceAdd(ConstHandle2Slices self, ConstHandle2ConstSlice slice);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstSlice
SlicesSliceGetConst(ConstHandle2ConstSlices self, const size_t index_);

// +++ Get, by index \in [0,size)
extern_c Handle2Slice
SlicesSliceGet(ConstHandle2Slices self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
SlicesSliceSet(
   ConstHandle2Slices self,
   const size_t index_,
   ConstHandle2ConstSlice slice
);

// ------------------------
// Re: metadatum dimension
// ------------------------

// +++ Has, by dimension
extern_c int
SlicesSliceHasByDimension(
   ConstHandle2ConstSlices self,
   const int dimension
);

// --- Get, by dimension, const
extern_c Handle2ConstSlice
SlicesSliceGetByDimensionConst(
   ConstHandle2ConstSlices self,
   const int dimension
);

// +++ Get, by dimension
extern_c Handle2Slice
SlicesSliceGetByDimension(
   ConstHandle2Slices self,
   const int dimension
);

// +++ Set, by dimension
extern_c void
SlicesSliceSetByDimension(
   ConstHandle2Slices self,
   const int dimension,
   ConstHandle2ConstSlice slice
);

// ------------------------
// Re: metadatum domainValue
// ------------------------

// +++ Has, by domainValue
extern_c int
SlicesSliceHasByDomainValue(
   ConstHandle2ConstSlices self,
   const int domainValue
);

// --- Get, by domainValue, const
extern_c Handle2ConstSlice
SlicesSliceGetByDomainValueConst(
   ConstHandle2ConstSlices self,
   const int domainValue
);

// +++ Get, by domainValue
extern_c Handle2Slice
SlicesSliceGetByDomainValue(
   ConstHandle2Slices self,
   const int domainValue
);

// +++ Set, by domainValue
extern_c void
SlicesSliceSetByDomainValue(
   ConstHandle2Slices self,
   const int domainValue,
   ConstHandle2ConstSlice slice
);

// ------------------------
// Re: metadatum domainMin
// ------------------------

// +++ Has, by domainMin
extern_c int
SlicesSliceHasByDomainMin(
   ConstHandle2ConstSlices self,
   const double domainMin
);

// --- Get, by domainMin, const
extern_c Handle2ConstSlice
SlicesSliceGetByDomainMinConst(
   ConstHandle2ConstSlices self,
   const double domainMin
);

// +++ Get, by domainMin
extern_c Handle2Slice
SlicesSliceGetByDomainMin(
   ConstHandle2Slices self,
   const double domainMin
);

// +++ Set, by domainMin
extern_c void
SlicesSliceSetByDomainMin(
   ConstHandle2Slices self,
   const double domainMin,
   ConstHandle2ConstSlice slice
);

// ------------------------
// Re: metadatum domainMax
// ------------------------

// +++ Has, by domainMax
extern_c int
SlicesSliceHasByDomainMax(
   ConstHandle2ConstSlices self,
   const double domainMax
);

// --- Get, by domainMax, const
extern_c Handle2ConstSlice
SlicesSliceGetByDomainMaxConst(
   ConstHandle2ConstSlices self,
   const double domainMax
);

// +++ Get, by domainMax
extern_c Handle2Slice
SlicesSliceGetByDomainMax(
   ConstHandle2Slices self,
   const double domainMax
);

// +++ Set, by domainMax
extern_c void
SlicesSliceSetByDomainMax(
   ConstHandle2Slices self,
   const double domainMax,
   ConstHandle2ConstSlice slice
);

// ------------------------
// Re: metadatum domainUnit
// ------------------------

// +++ Has, by domainUnit
extern_c int
SlicesSliceHasByDomainUnit(
   ConstHandle2ConstSlices self,
   const char *const domainUnit
);

// --- Get, by domainUnit, const
extern_c Handle2ConstSlice
SlicesSliceGetByDomainUnitConst(
   ConstHandle2ConstSlices self,
   const char *const domainUnit
);

// +++ Get, by domainUnit
extern_c Handle2Slice
SlicesSliceGetByDomainUnit(
   ConstHandle2Slices self,
   const char *const domainUnit
);

// +++ Set, by domainUnit
extern_c void
SlicesSliceSetByDomainUnit(
   ConstHandle2Slices self,
   const char *const domainUnit,
   ConstHandle2ConstSlice slice
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Slices/src/custom.h"

#undef extern_c
#endif
