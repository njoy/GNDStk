
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
// Body is the basic handle type in this file. Example:
//    // Create a default Body object:
//    Body handle = BodyDefault();
// Functions involving Body are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_BODY
#define C_INTERFACE_ALPHA_V2_0_GENERAL_BODY

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct BodyClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Body
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct BodyClass *Body;

// --- Const-aware handles.
typedef const struct BodyClass *const ConstHandle2ConstBody;
typedef       struct BodyClass *const ConstHandle2Body;
typedef const struct BodyClass *      Handle2ConstBody;
typedef       struct BodyClass *      Handle2Body;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstBody
BodyDefaultConst();

// +++ Create, default
extern_c Handle2Body
BodyDefault();

// --- Create, general, const
extern_c Handle2ConstBody
BodyCreateConst();

// +++ Create, general
extern_c Handle2Body
BodyCreate();

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
BodyAssign(ConstHandle2Body This, ConstHandle2ConstBody from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
BodyDelete(ConstHandle2ConstBody This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
BodyRead(ConstHandle2Body This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
BodyWrite(ConstHandle2ConstBody This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
BodyPrint(ConstHandle2ConstBody This);

// +++ Print to standard output, as XML
extern_c int
BodyPrintXML(ConstHandle2ConstBody This);

// +++ Print to standard output, as JSON
extern_c int
BodyPrintJSON(ConstHandle2ConstBody This);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Body/src/custom.h"

#undef extern_c
#endif
