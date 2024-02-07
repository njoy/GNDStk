
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
// Title is the basic handle type in this file. Example:
//    // Create a default Title object:
//    Title handle = TitleDefault();
// Functions involving Title are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_TITLE
#define C_INTERFACE_GNDS_V2_0_GENERAL_TITLE

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct TitleClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Title
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct TitleClass *Title;

// --- Const-aware handles.
typedef const struct TitleClass *const ConstHandle2ConstTitle;
typedef       struct TitleClass *const ConstHandle2Title;
typedef const struct TitleClass *      Handle2ConstTitle;
typedef       struct TitleClass *      Handle2Title;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstTitle
TitleDefaultConst();

// +++ Create, default, non-const
extern_c Handle2Title
TitleDefault();

// --- Create, general, const
extern_c Handle2ConstTitle
TitleCreateConst();

// +++ Create, general, non-const
extern_c Handle2Title
TitleCreate();

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
TitleAssign(ConstHandle2Title self, ConstHandle2ConstTitle from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
TitleDelete(ConstHandle2ConstTitle self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
TitleRead(ConstHandle2Title self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
TitleWrite(ConstHandle2ConstTitle self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
TitlePrint(ConstHandle2ConstTitle self);

// +++ Print to standard output, as XML
extern_c int
TitlePrintXML(ConstHandle2ConstTitle self);

// +++ Print to standard output, as JSON
extern_c int
TitlePrintJSON(ConstHandle2ConstTitle self);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Title/src/custom.h"

#undef extern_c
#endif
