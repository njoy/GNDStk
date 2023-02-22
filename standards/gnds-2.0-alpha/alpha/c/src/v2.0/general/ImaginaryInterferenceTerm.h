
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
// ImaginaryInterferenceTerm is the basic handle type in this file. Example:
//    // Create a default ImaginaryInterferenceTerm object:
//    ImaginaryInterferenceTerm handle = ImaginaryInterferenceTermDefault();
// Functions involving ImaginaryInterferenceTerm are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_IMAGINARYINTERFERENCETERM
#define C_INTERFACE_ALPHA_V2_0_GENERAL_IMAGINARYINTERFERENCETERM

#include "GNDStk.h"
#include "v2.0/general/Regions2d.h"
#include "v2.0/general/XYs2d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ImaginaryInterferenceTermClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ImaginaryInterferenceTerm
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ImaginaryInterferenceTermClass *ImaginaryInterferenceTerm;

// --- Const-aware handles.
typedef const struct ImaginaryInterferenceTermClass *const ConstHandle2ConstImaginaryInterferenceTerm;
typedef       struct ImaginaryInterferenceTermClass *const ConstHandle2ImaginaryInterferenceTerm;
typedef const struct ImaginaryInterferenceTermClass *      Handle2ConstImaginaryInterferenceTerm;
typedef       struct ImaginaryInterferenceTermClass *      Handle2ImaginaryInterferenceTerm;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstImaginaryInterferenceTerm
ImaginaryInterferenceTermDefaultConst();

// +++ Create, default
extern_c Handle2ImaginaryInterferenceTerm
ImaginaryInterferenceTermDefault();

// --- Create, general, const
extern_c Handle2ConstImaginaryInterferenceTerm
ImaginaryInterferenceTermCreateConst(
   ConstHandle2ConstRegions2d regions2d,
   ConstHandle2ConstXYs2d XYs2d
);

// +++ Create, general
extern_c Handle2ImaginaryInterferenceTerm
ImaginaryInterferenceTermCreate(
   ConstHandle2ConstRegions2d regions2d,
   ConstHandle2ConstXYs2d XYs2d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ImaginaryInterferenceTermAssign(ConstHandle2ImaginaryInterferenceTerm self, ConstHandle2ConstImaginaryInterferenceTerm from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ImaginaryInterferenceTermDelete(ConstHandle2ConstImaginaryInterferenceTerm self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ImaginaryInterferenceTermRead(ConstHandle2ImaginaryInterferenceTerm self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ImaginaryInterferenceTermWrite(ConstHandle2ConstImaginaryInterferenceTerm self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ImaginaryInterferenceTermPrint(ConstHandle2ConstImaginaryInterferenceTerm self);

// +++ Print to standard output, as XML
extern_c int
ImaginaryInterferenceTermPrintXML(ConstHandle2ConstImaginaryInterferenceTerm self);

// +++ Print to standard output, as JSON
extern_c int
ImaginaryInterferenceTermPrintJSON(ConstHandle2ConstImaginaryInterferenceTerm self);


// -----------------------------------------------------------------------------
// Child: regions2d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ImaginaryInterferenceTermRegions2dHas(ConstHandle2ConstImaginaryInterferenceTerm self);

// --- Get, const
extern_c Handle2ConstRegions2d
ImaginaryInterferenceTermRegions2dGetConst(ConstHandle2ConstImaginaryInterferenceTerm self);

// +++ Get, non-const
extern_c Handle2Regions2d
ImaginaryInterferenceTermRegions2dGet(ConstHandle2ImaginaryInterferenceTerm self);

// +++ Set
extern_c void
ImaginaryInterferenceTermRegions2dSet(ConstHandle2ImaginaryInterferenceTerm self, ConstHandle2ConstRegions2d regions2d);


// -----------------------------------------------------------------------------
// Child: XYs2d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ImaginaryInterferenceTermXYs2dHas(ConstHandle2ConstImaginaryInterferenceTerm self);

// --- Get, const
extern_c Handle2ConstXYs2d
ImaginaryInterferenceTermXYs2dGetConst(ConstHandle2ConstImaginaryInterferenceTerm self);

// +++ Get, non-const
extern_c Handle2XYs2d
ImaginaryInterferenceTermXYs2dGet(ConstHandle2ImaginaryInterferenceTerm self);

// +++ Set
extern_c void
ImaginaryInterferenceTermXYs2dSet(ConstHandle2ImaginaryInterferenceTerm self, ConstHandle2ConstXYs2d XYs2d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ImaginaryInterferenceTerm/src/custom.h"

#undef extern_c
#endif