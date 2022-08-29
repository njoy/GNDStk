
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
// ParameterLink is the basic handle type in this file. Example:
//    // Create a default ParameterLink object:
//    ParameterLink handle = ParameterLinkDefault();
// Functions involving ParameterLink are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_COVARIANCE_PARAMETERLINK
#define C_INTERFACE_TRY_V2_0_COVARIANCE_PARAMETERLINK

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ParameterLinkClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ParameterLink
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ParameterLinkClass *ParameterLink;

// --- Const-aware handles.
typedef const struct ParameterLinkClass *const ConstHandle2ConstParameterLink;
typedef       struct ParameterLinkClass *const ConstHandle2ParameterLink;
typedef const struct ParameterLinkClass *      Handle2ConstParameterLink;
typedef       struct ParameterLinkClass *      Handle2ParameterLink;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstParameterLink
ParameterLinkDefaultConst();

// +++ Create, default
extern_c Handle2ParameterLink
ParameterLinkDefault();

// --- Create, general, const
extern_c Handle2ConstParameterLink
ParameterLinkCreateConst(
   const XMLName href,
   const XMLName label,
   const Integer32 matrixStartIndex,
   const Integer32 nParameters
);

// +++ Create, general
extern_c Handle2ParameterLink
ParameterLinkCreate(
   const XMLName href,
   const XMLName label,
   const Integer32 matrixStartIndex,
   const Integer32 nParameters
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ParameterLinkAssign(ConstHandle2ParameterLink This, ConstHandle2ConstParameterLink from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ParameterLinkDelete(ConstHandle2ConstParameterLink This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ParameterLinkRead(ConstHandle2ParameterLink This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ParameterLinkWrite(ConstHandle2ConstParameterLink This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ParameterLinkPrint(ConstHandle2ConstParameterLink This);

// +++ Print to standard output, as XML
extern_c int
ParameterLinkPrintXML(ConstHandle2ConstParameterLink This);

// +++ Print to standard output, as JSON
extern_c int
ParameterLinkPrintJSON(ConstHandle2ConstParameterLink This);


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ParameterLinkHrefHas(ConstHandle2ConstParameterLink This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ParameterLinkHrefGet(ConstHandle2ConstParameterLink This);

// +++ Set
extern_c void
ParameterLinkHrefSet(ConstHandle2ParameterLink This, const XMLName href);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ParameterLinkLabelHas(ConstHandle2ConstParameterLink This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ParameterLinkLabelGet(ConstHandle2ConstParameterLink This);

// +++ Set
extern_c void
ParameterLinkLabelSet(ConstHandle2ParameterLink This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: matrixStartIndex
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ParameterLinkMatrixStartIndexHas(ConstHandle2ConstParameterLink This);

// +++ Get
// +++ Returns by value
extern_c Integer32
ParameterLinkMatrixStartIndexGet(ConstHandle2ConstParameterLink This);

// +++ Set
extern_c void
ParameterLinkMatrixStartIndexSet(ConstHandle2ParameterLink This, const Integer32 matrixStartIndex);


// -----------------------------------------------------------------------------
// Metadatum: nParameters
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ParameterLinkNParametersHas(ConstHandle2ConstParameterLink This);

// +++ Get
// +++ Returns by value
extern_c Integer32
ParameterLinkNParametersGet(ConstHandle2ConstParameterLink This);

// +++ Set
extern_c void
ParameterLinkNParametersSet(ConstHandle2ParameterLink This, const Integer32 nParameters);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
