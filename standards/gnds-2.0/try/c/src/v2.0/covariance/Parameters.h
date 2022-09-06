
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
// Parameters is the basic handle type in this file. Example:
//    // Create a default Parameters object:
//    Parameters handle = ParametersDefault();
// Functions involving Parameters are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_COVARIANCE_PARAMETERS
#define C_INTERFACE_TRY_V2_0_COVARIANCE_PARAMETERS

#include "GNDStk.h"
#include "v2.0/covariance/ParameterLink.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ParametersClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Parameters
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ParametersClass *Parameters;

// --- Const-aware handles.
typedef const struct ParametersClass *const ConstHandle2ConstParameters;
typedef       struct ParametersClass *const ConstHandle2Parameters;
typedef const struct ParametersClass *      Handle2ConstParameters;
typedef       struct ParametersClass *      Handle2Parameters;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstParameters
ParametersDefaultConst();

// +++ Create, default
extern_c Handle2Parameters
ParametersDefault();

// --- Create, general, const
extern_c Handle2ConstParameters
ParametersCreateConst(
   ConstHandle2ParameterLink *const parameterLink, const size_t parameterLinkSize
);

// +++ Create, general
extern_c Handle2Parameters
ParametersCreate(
   ConstHandle2ParameterLink *const parameterLink, const size_t parameterLinkSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ParametersAssign(ConstHandle2Parameters This, ConstHandle2ConstParameters from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ParametersDelete(ConstHandle2ConstParameters This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ParametersRead(ConstHandle2Parameters This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ParametersWrite(ConstHandle2ConstParameters This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ParametersPrint(ConstHandle2ConstParameters This);

// +++ Print to standard output, as XML
extern_c int
ParametersPrintXML(ConstHandle2ConstParameters This);

// +++ Print to standard output, as JSON
extern_c int
ParametersPrintJSON(ConstHandle2ConstParameters This);


// -----------------------------------------------------------------------------
// Child: parameterLink
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ParametersParameterLinkHas(ConstHandle2ConstParameters This);

// +++ Clear
extern_c void
ParametersParameterLinkClear(ConstHandle2Parameters This);

// +++ Size
extern_c size_t
ParametersParameterLinkSize(ConstHandle2ConstParameters This);

// +++ Add
extern_c void
ParametersParameterLinkAdd(ConstHandle2Parameters This, ConstHandle2ConstParameterLink parameterLink);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstParameterLink
ParametersParameterLinkGetConst(ConstHandle2ConstParameters This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2ParameterLink
ParametersParameterLinkGet(ConstHandle2Parameters This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ParametersParameterLinkSet(
   ConstHandle2Parameters This,
   const size_t index_,
   ConstHandle2ConstParameterLink parameterLink
);

// +++ Has, by href
extern_c int
ParametersParameterLinkHasByHref(
   ConstHandle2ConstParameters This,
   const XMLName href
);

// --- Get, by href, const
extern_c Handle2ConstParameterLink
ParametersParameterLinkGetByHrefConst(
   ConstHandle2ConstParameters This,
   const XMLName href
);

// +++ Get, by href, non-const
extern_c Handle2ParameterLink
ParametersParameterLinkGetByHref(
   ConstHandle2Parameters This,
   const XMLName href
);

// +++ Set, by href
extern_c void
ParametersParameterLinkSetByHref(
   ConstHandle2Parameters This,
   const XMLName href,
   ConstHandle2ConstParameterLink parameterLink
);

// +++ Has, by label
extern_c int
ParametersParameterLinkHasByLabel(
   ConstHandle2ConstParameters This,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstParameterLink
ParametersParameterLinkGetByLabelConst(
   ConstHandle2ConstParameters This,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2ParameterLink
ParametersParameterLinkGetByLabel(
   ConstHandle2Parameters This,
   const XMLName label
);

// +++ Set, by label
extern_c void
ParametersParameterLinkSetByLabel(
   ConstHandle2Parameters This,
   const XMLName label,
   ConstHandle2ConstParameterLink parameterLink
);

// +++ Has, by matrixStartIndex
extern_c int
ParametersParameterLinkHasByMatrixStartIndex(
   ConstHandle2ConstParameters This,
   const Integer32 matrixStartIndex
);

// --- Get, by matrixStartIndex, const
extern_c Handle2ConstParameterLink
ParametersParameterLinkGetByMatrixStartIndexConst(
   ConstHandle2ConstParameters This,
   const Integer32 matrixStartIndex
);

// +++ Get, by matrixStartIndex, non-const
extern_c Handle2ParameterLink
ParametersParameterLinkGetByMatrixStartIndex(
   ConstHandle2Parameters This,
   const Integer32 matrixStartIndex
);

// +++ Set, by matrixStartIndex
extern_c void
ParametersParameterLinkSetByMatrixStartIndex(
   ConstHandle2Parameters This,
   const Integer32 matrixStartIndex,
   ConstHandle2ConstParameterLink parameterLink
);

// +++ Has, by nParameters
extern_c int
ParametersParameterLinkHasByNParameters(
   ConstHandle2ConstParameters This,
   const Integer32 nParameters
);

// --- Get, by nParameters, const
extern_c Handle2ConstParameterLink
ParametersParameterLinkGetByNParametersConst(
   ConstHandle2ConstParameters This,
   const Integer32 nParameters
);

// +++ Get, by nParameters, non-const
extern_c Handle2ParameterLink
ParametersParameterLinkGetByNParameters(
   ConstHandle2Parameters This,
   const Integer32 nParameters
);

// +++ Set, by nParameters
extern_c void
ParametersParameterLinkSetByNParameters(
   ConstHandle2Parameters This,
   const Integer32 nParameters,
   ConstHandle2ConstParameterLink parameterLink
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif