
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
// ColumnData is the basic handle type in this file. Example:
//    // Create a default ColumnData object:
//    ColumnData handle = ColumnDataDefault();
// Functions involving ColumnData are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_COVARIANCE_COLUMNDATA
#define C_INTERFACE_TEST_V2_0_COVARIANCE_COLUMNDATA

#include "GNDStk.h"
#include "v2.0/covariance/Slices.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ColumnDataClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ColumnData
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ColumnDataClass *ColumnData;

// --- Const-aware handles.
typedef const struct ColumnDataClass *const ConstHandle2ConstColumnData;
typedef       struct ColumnDataClass *const ConstHandle2ColumnData;
typedef const struct ColumnDataClass *      Handle2ConstColumnData;
typedef       struct ColumnDataClass *      Handle2ColumnData;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstColumnData
ColumnDataDefaultConst();

// +++ Create, default
extern_c Handle2ColumnData
ColumnDataDefault();

// --- Create, general, const
extern_c Handle2ConstColumnData
ColumnDataCreateConst(
   const XMLName ENDF_MFMT,
   const XMLName href,
   const Integer32 dimension,
   ConstHandle2ConstSlices slices
);

// +++ Create, general
extern_c Handle2ColumnData
ColumnDataCreate(
   const XMLName ENDF_MFMT,
   const XMLName href,
   const Integer32 dimension,
   ConstHandle2ConstSlices slices
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ColumnDataAssign(ConstHandle2ColumnData self, ConstHandle2ConstColumnData from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ColumnDataDelete(ConstHandle2ConstColumnData self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ColumnDataRead(ConstHandle2ColumnData self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ColumnDataWrite(ConstHandle2ConstColumnData self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ColumnDataPrint(ConstHandle2ConstColumnData self);

// +++ Print to standard output, as XML
extern_c int
ColumnDataPrintXML(ConstHandle2ConstColumnData self);

// +++ Print to standard output, as JSON
extern_c int
ColumnDataPrintJSON(ConstHandle2ConstColumnData self);


// -----------------------------------------------------------------------------
// Metadatum: ENDF_MFMT
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ColumnDataENDFMFMTHas(ConstHandle2ConstColumnData self);

// +++ Get
// +++ Returns by value
extern_c XMLName
ColumnDataENDFMFMTGet(ConstHandle2ConstColumnData self);

// +++ Set
extern_c void
ColumnDataENDFMFMTSet(ConstHandle2ColumnData self, const XMLName ENDF_MFMT);


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ColumnDataHrefHas(ConstHandle2ConstColumnData self);

// +++ Get
// +++ Returns by value
extern_c XMLName
ColumnDataHrefGet(ConstHandle2ConstColumnData self);

// +++ Set
extern_c void
ColumnDataHrefSet(ConstHandle2ColumnData self, const XMLName href);


// -----------------------------------------------------------------------------
// Metadatum: dimension
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ColumnDataDimensionHas(ConstHandle2ConstColumnData self);

// +++ Get
// +++ Returns by value
extern_c Integer32
ColumnDataDimensionGet(ConstHandle2ConstColumnData self);

// +++ Set
extern_c void
ColumnDataDimensionSet(ConstHandle2ColumnData self, const Integer32 dimension);


// -----------------------------------------------------------------------------
// Child: slices
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ColumnDataSlicesHas(ConstHandle2ConstColumnData self);

// --- Get, const
extern_c Handle2ConstSlices
ColumnDataSlicesGetConst(ConstHandle2ConstColumnData self);

// +++ Get, non-const
extern_c Handle2Slices
ColumnDataSlicesGet(ConstHandle2ColumnData self);

// +++ Set
extern_c void
ColumnDataSlicesSet(ConstHandle2ColumnData self, ConstHandle2ConstSlices slices);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/covariance/ColumnData/src/custom.h"

#undef extern_c
#endif
