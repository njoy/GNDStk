
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
// ExternalRMatrix is the basic handle type in this file. Example:
//    // Create a default ExternalRMatrix object:
//    ExternalRMatrix handle = ExternalRMatrixDefault();
// Functions involving ExternalRMatrix are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_RESONANCES_EXTERNALRMATRIX
#define C_INTERFACE_TRY_V2_0_RESONANCES_EXTERNALRMATRIX

#include "GNDStk.h"
#include "v2.0/unknownNamespace/Double.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ExternalRMatrixClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ExternalRMatrix
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ExternalRMatrixClass *ExternalRMatrix;

// --- Const-aware handles.
typedef const struct ExternalRMatrixClass *const ConstHandle2ConstExternalRMatrix;
typedef       struct ExternalRMatrixClass *const ConstHandle2ExternalRMatrix;
typedef const struct ExternalRMatrixClass *      Handle2ConstExternalRMatrix;
typedef       struct ExternalRMatrixClass *      Handle2ExternalRMatrix;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstExternalRMatrix
ExternalRMatrixDefaultConst();

// +++ Create, default
extern_c Handle2ExternalRMatrix
ExternalRMatrixDefault();

// --- Create, general, const
extern_c Handle2ConstExternalRMatrix
ExternalRMatrixCreateConst(
   const XMLName type,
   ConstHandle2Double *const Double, const size_t DoubleSize
);

// +++ Create, general
extern_c Handle2ExternalRMatrix
ExternalRMatrixCreate(
   const XMLName type,
   ConstHandle2Double *const Double, const size_t DoubleSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ExternalRMatrixAssign(ConstHandle2ExternalRMatrix This, ConstHandle2ConstExternalRMatrix from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ExternalRMatrixDelete(ConstHandle2ConstExternalRMatrix This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ExternalRMatrixRead(ConstHandle2ExternalRMatrix This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ExternalRMatrixWrite(ConstHandle2ConstExternalRMatrix This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ExternalRMatrixPrint(ConstHandle2ConstExternalRMatrix This);

// +++ Print to standard output, as XML
extern_c int
ExternalRMatrixPrintXML(ConstHandle2ConstExternalRMatrix This);

// +++ Print to standard output, as JSON
extern_c int
ExternalRMatrixPrintJSON(ConstHandle2ConstExternalRMatrix This);


// -----------------------------------------------------------------------------
// Metadatum: type
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ExternalRMatrixTypeHas(ConstHandle2ConstExternalRMatrix This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ExternalRMatrixTypeGet(ConstHandle2ConstExternalRMatrix This);

// +++ Set
extern_c void
ExternalRMatrixTypeSet(ConstHandle2ExternalRMatrix This, const XMLName type);


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ExternalRMatrixDoubleHas(ConstHandle2ConstExternalRMatrix This);

// +++ Clear
extern_c void
ExternalRMatrixDoubleClear(ConstHandle2ExternalRMatrix This);

// +++ Size
extern_c size_t
ExternalRMatrixDoubleSize(ConstHandle2ConstExternalRMatrix This);

// +++ Add
extern_c void
ExternalRMatrixDoubleAdd(ConstHandle2ExternalRMatrix This, ConstHandle2ConstDouble Double);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstDouble
ExternalRMatrixDoubleGetConst(ConstHandle2ConstExternalRMatrix This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Double
ExternalRMatrixDoubleGet(ConstHandle2ExternalRMatrix This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ExternalRMatrixDoubleSet(
   ConstHandle2ExternalRMatrix This,
   const size_t index_,
   ConstHandle2ConstDouble Double
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
