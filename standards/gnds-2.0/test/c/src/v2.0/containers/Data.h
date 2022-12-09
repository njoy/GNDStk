
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
// Data is the basic handle type in this file. Example:
//    // Create a default Data object:
//    Data handle = DataDefault();
// Functions involving Data are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_CONTAINERS_DATA
#define C_INTERFACE_TEST_V2_0_CONTAINERS_DATA

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
DataCreateConst(
   const UTF8Text sep
);

// +++ Create, general
extern_c Handle2Data
DataCreate(
   const UTF8Text sep
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
DataAssign(ConstHandle2Data This, ConstHandle2ConstData from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
DataDelete(ConstHandle2ConstData This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
DataRead(ConstHandle2Data This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
DataWrite(ConstHandle2ConstData This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
DataPrint(ConstHandle2ConstData This);

// +++ Print to standard output, as XML
extern_c int
DataPrintXML(ConstHandle2ConstData This);

// +++ Print to standard output, as JSON
extern_c int
DataPrintJSON(ConstHandle2ConstData This);


// -----------------------------------------------------------------------------
// Data vector
// -----------------------------------------------------------------------------

// ------------------------
// int
// ------------------------

// +++ Clear
extern_c void
DataIntsClear(ConstHandle2Data This);

// +++ Get size
extern_c size_t
DataIntsSize(ConstHandle2ConstData This);

// +++ Get value
// +++ By index \in [0,size)
extern_c int
DataIntsGet(ConstHandle2ConstData This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
DataIntsSet(ConstHandle2Data This, const size_t index, const int value);

// --- Get pointer to existing values, const
extern_c const int *
DataIntsGetArrayConst(ConstHandle2ConstData This);

// +++ Get pointer to existing values, non-const
extern_c int *
DataIntsGetArray(ConstHandle2Data This);

// +++ Set completely new values and size
extern_c void
DataIntsSetArray(ConstHandle2Data This, const int *const values, const size_t size);

// ------------------------
// unsigned
// ------------------------

// +++ Clear
extern_c void
DataUnsignedsClear(ConstHandle2Data This);

// +++ Get size
extern_c size_t
DataUnsignedsSize(ConstHandle2ConstData This);

// +++ Get value
// +++ By index \in [0,size)
extern_c unsigned
DataUnsignedsGet(ConstHandle2ConstData This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
DataUnsignedsSet(ConstHandle2Data This, const size_t index, const unsigned value);

// --- Get pointer to existing values, const
extern_c const unsigned *
DataUnsignedsGetArrayConst(ConstHandle2ConstData This);

// +++ Get pointer to existing values, non-const
extern_c unsigned *
DataUnsignedsGetArray(ConstHandle2Data This);

// +++ Set completely new values and size
extern_c void
DataUnsignedsSetArray(ConstHandle2Data This, const unsigned *const values, const size_t size);

// ------------------------
// float
// ------------------------

// +++ Clear
extern_c void
DataFloatsClear(ConstHandle2Data This);

// +++ Get size
extern_c size_t
DataFloatsSize(ConstHandle2ConstData This);

// +++ Get value
// +++ By index \in [0,size)
extern_c float
DataFloatsGet(ConstHandle2ConstData This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
DataFloatsSet(ConstHandle2Data This, const size_t index, const float value);

// --- Get pointer to existing values, const
extern_c const float *
DataFloatsGetArrayConst(ConstHandle2ConstData This);

// +++ Get pointer to existing values, non-const
extern_c float *
DataFloatsGetArray(ConstHandle2Data This);

// +++ Set completely new values and size
extern_c void
DataFloatsSetArray(ConstHandle2Data This, const float *const values, const size_t size);

// ------------------------
// double
// ------------------------

// +++ Clear
extern_c void
DataDoublesClear(ConstHandle2Data This);

// +++ Get size
extern_c size_t
DataDoublesSize(ConstHandle2ConstData This);

// +++ Get value
// +++ By index \in [0,size)
extern_c double
DataDoublesGet(ConstHandle2ConstData This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
DataDoublesSet(ConstHandle2Data This, const size_t index, const double value);

// --- Get pointer to existing values, const
extern_c const double *
DataDoublesGetArrayConst(ConstHandle2ConstData This);

// +++ Get pointer to existing values, non-const
extern_c double *
DataDoublesGetArray(ConstHandle2Data This);

// +++ Set completely new values and size
extern_c void
DataDoublesSetArray(ConstHandle2Data This, const double *const values, const size_t size);


// -----------------------------------------------------------------------------
// Metadatum: sep
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DataSepHas(ConstHandle2ConstData This);

// +++ Get
// +++ Returns by value
extern_c UTF8Text
DataSepGet(ConstHandle2ConstData This);

// +++ Set
extern_c void
DataSepSet(ConstHandle2Data This, const UTF8Text sep);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
