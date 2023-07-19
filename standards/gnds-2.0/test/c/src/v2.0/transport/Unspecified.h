
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
// Unspecified is the basic handle type in this file. Example:
//    // Create a default Unspecified object:
//    Unspecified handle = UnspecifiedDefault();
// Functions involving Unspecified are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TRANSPORT_UNSPECIFIED
#define C_INTERFACE_TEST_V2_0_TRANSPORT_UNSPECIFIED

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct UnspecifiedClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Unspecified
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct UnspecifiedClass *Unspecified;

// --- Const-aware handles.
typedef const struct UnspecifiedClass *const ConstHandle2ConstUnspecified;
typedef       struct UnspecifiedClass *const ConstHandle2Unspecified;
typedef const struct UnspecifiedClass *      Handle2ConstUnspecified;
typedef       struct UnspecifiedClass *      Handle2Unspecified;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstUnspecified
UnspecifiedDefaultConst();

// +++ Create, default
extern_c Handle2Unspecified
UnspecifiedDefault();

// --- Create, general, const
extern_c Handle2ConstUnspecified
UnspecifiedCreateConst(
   const XMLName label,
   const XMLName productFrame
);

// +++ Create, general
extern_c Handle2Unspecified
UnspecifiedCreate(
   const XMLName label,
   const XMLName productFrame
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
UnspecifiedAssign(ConstHandle2Unspecified self, ConstHandle2ConstUnspecified from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
UnspecifiedDelete(ConstHandle2ConstUnspecified self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
UnspecifiedRead(ConstHandle2Unspecified self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
UnspecifiedWrite(ConstHandle2ConstUnspecified self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
UnspecifiedPrint(ConstHandle2ConstUnspecified self);

// +++ Print to standard output, as XML
extern_c int
UnspecifiedPrintXML(ConstHandle2ConstUnspecified self);

// +++ Print to standard output, as JSON
extern_c int
UnspecifiedPrintJSON(ConstHandle2ConstUnspecified self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
UnspecifiedLabelHas(ConstHandle2ConstUnspecified self);

// +++ Get
// +++ Returns by value
extern_c XMLName
UnspecifiedLabelGet(ConstHandle2ConstUnspecified self);

// +++ Set
extern_c void
UnspecifiedLabelSet(ConstHandle2Unspecified self, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
UnspecifiedProductFrameHas(ConstHandle2ConstUnspecified self);

// +++ Get
// +++ Returns by value
extern_c XMLName
UnspecifiedProductFrameGet(ConstHandle2ConstUnspecified self);

// +++ Set
extern_c void
UnspecifiedProductFrameSet(ConstHandle2Unspecified self, const XMLName productFrame);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/Unspecified/src/custom.h"

#undef extern_c
#endif
