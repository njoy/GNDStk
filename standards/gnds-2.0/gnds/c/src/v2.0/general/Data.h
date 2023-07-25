
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
// Data is the basic handle type in this file. Example:
//    // Create a default Data object:
//    Data handle = DataDefault();
// Functions involving Data are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_DATA
#define C_INTERFACE_GNDS_V2_0_GENERAL_DATA

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct DataClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Data
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct DataClass *Data;

// --- Const-aware handles.
typedef const struct DataClass *const ConstHandle2ConstData;
typedef       struct DataClass *const ConstHandle2Data;
typedef const struct DataClass *      Handle2ConstData;
typedef       struct DataClass *      Handle2Data;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstData
DataDefaultConst();

// +++ Create, default
extern_c Handle2Data
DataDefault();

// --- Create, general, const
extern_c Handle2ConstData
DataCreateConst();

// +++ Create, general
extern_c Handle2Data
DataCreate();

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
DataAssign(ConstHandle2Data self, ConstHandle2ConstData from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
DataDelete(ConstHandle2ConstData self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
DataRead(ConstHandle2Data self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
DataWrite(ConstHandle2ConstData self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
DataPrint(ConstHandle2ConstData self);

// +++ Print to standard output, as XML
extern_c int
DataPrintXML(ConstHandle2ConstData self);

// +++ Print to standard output, as JSON
extern_c int
DataPrintJSON(ConstHandle2ConstData self);


// -----------------------------------------------------------------------------
// Data vector
// -----------------------------------------------------------------------------

// +++ Clear
extern_c void
DataDoublesClear(ConstHandle2Data self);

// +++ Get size
extern_c size_t
DataDoublesSize(ConstHandle2ConstData self);

// +++ Get value
// +++ By index \in [0,size)
extern_c double
DataDoublesGet(ConstHandle2ConstData self, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
DataDoublesSet(ConstHandle2Data self, const size_t index, const double value);

// --- Get pointer to existing values, const
extern_c const double *
DataDoublesGetArrayConst(ConstHandle2ConstData self);

// +++ Get pointer to existing values, non-const
extern_c double *
DataDoublesGetArray(ConstHandle2Data self);

// +++ Set completely new values and size
extern_c void
DataDoublesSetArray(ConstHandle2Data self, const double *const values, const size_t size);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Data/src/custom.h"

#undef extern_c
#endif
