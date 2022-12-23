
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
// Slice is the basic handle type in this file. Example:
//    // Create a default Slice object:
//    Slice handle = SliceDefault();
// Functions involving Slice are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_COVARIANCE_SLICE
#define C_INTERFACE_TEST_V2_0_COVARIANCE_SLICE

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct SliceClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Slice
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct SliceClass *Slice;

// --- Const-aware handles.
typedef const struct SliceClass *const ConstHandle2ConstSlice;
typedef       struct SliceClass *const ConstHandle2Slice;
typedef const struct SliceClass *      Handle2ConstSlice;
typedef       struct SliceClass *      Handle2Slice;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstSlice
SliceDefaultConst();

// +++ Create, default
extern_c Handle2Slice
SliceDefault();

// --- Create, general, const
extern_c Handle2ConstSlice
SliceCreateConst(
   const Float64 domainMin,
   const Float64 domainMax,
   const Float64 domainValue,
   const XMLName domainUnit,
   const Integer32 dimension
);

// +++ Create, general
extern_c Handle2Slice
SliceCreate(
   const Float64 domainMin,
   const Float64 domainMax,
   const Float64 domainValue,
   const XMLName domainUnit,
   const Integer32 dimension
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
SliceAssign(ConstHandle2Slice This, ConstHandle2ConstSlice from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
SliceDelete(ConstHandle2ConstSlice This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
SliceRead(ConstHandle2Slice This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
SliceWrite(ConstHandle2ConstSlice This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
SlicePrint(ConstHandle2ConstSlice This);

// +++ Print to standard output, as XML
extern_c int
SlicePrintXML(ConstHandle2ConstSlice This);

// +++ Print to standard output, as JSON
extern_c int
SlicePrintJSON(ConstHandle2ConstSlice This);


// -----------------------------------------------------------------------------
// Metadatum: domainMin
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SliceDomainMinHas(ConstHandle2ConstSlice This);

// +++ Get
// +++ Returns by value
extern_c Float64
SliceDomainMinGet(ConstHandle2ConstSlice This);

// +++ Set
extern_c void
SliceDomainMinSet(ConstHandle2Slice This, const Float64 domainMin);


// -----------------------------------------------------------------------------
// Metadatum: domainMax
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SliceDomainMaxHas(ConstHandle2ConstSlice This);

// +++ Get
// +++ Returns by value
extern_c Float64
SliceDomainMaxGet(ConstHandle2ConstSlice This);

// +++ Set
extern_c void
SliceDomainMaxSet(ConstHandle2Slice This, const Float64 domainMax);


// -----------------------------------------------------------------------------
// Metadatum: domainValue
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SliceDomainValueHas(ConstHandle2ConstSlice This);

// +++ Get
// +++ Returns by value
extern_c Float64
SliceDomainValueGet(ConstHandle2ConstSlice This);

// +++ Set
extern_c void
SliceDomainValueSet(ConstHandle2Slice This, const Float64 domainValue);


// -----------------------------------------------------------------------------
// Metadatum: domainUnit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SliceDomainUnitHas(ConstHandle2ConstSlice This);

// +++ Get
// +++ Returns by value
extern_c XMLName
SliceDomainUnitGet(ConstHandle2ConstSlice This);

// +++ Set
extern_c void
SliceDomainUnitSet(ConstHandle2Slice This, const XMLName domainUnit);


// -----------------------------------------------------------------------------
// Metadatum: dimension
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SliceDimensionHas(ConstHandle2ConstSlice This);

// +++ Get
// +++ Returns by value
extern_c Integer32
SliceDimensionGet(ConstHandle2ConstSlice This);

// +++ Set
extern_c void
SliceDimensionSet(ConstHandle2Slice This, const Integer32 dimension);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
