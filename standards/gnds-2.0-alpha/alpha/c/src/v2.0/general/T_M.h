
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
// T_M is the basic handle type in this file. Example:
//    // Create a default T_M object:
//    T_M handle = T_MDefault();
// Functions involving T_M are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_T_M
#define C_INTERFACE_ALPHA_V2_0_GENERAL_T_M

#include "GNDStk.h"
#include "v2.0/general/XYs1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct T_MClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ T_M
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct T_MClass *T_M;

// --- Const-aware handles.
typedef const struct T_MClass *const ConstHandle2ConstT_M;
typedef       struct T_MClass *const ConstHandle2T_M;
typedef const struct T_MClass *      Handle2ConstT_M;
typedef       struct T_MClass *      Handle2T_M;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstT_M
T_MDefaultConst();

// +++ Create, default
extern_c Handle2T_M
T_MDefault();

// --- Create, general, const
extern_c Handle2ConstT_M
T_MCreateConst(
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Create, general
extern_c Handle2T_M
T_MCreate(
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
T_MAssign(ConstHandle2T_M This, ConstHandle2ConstT_M from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
T_MDelete(ConstHandle2ConstT_M This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
T_MRead(ConstHandle2T_M This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
T_MWrite(ConstHandle2ConstT_M This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
T_MPrint(ConstHandle2ConstT_M This);

// +++ Print to standard output, as XML
extern_c int
T_MPrintXML(ConstHandle2ConstT_M This);

// +++ Print to standard output, as JSON
extern_c int
T_MPrintJSON(ConstHandle2ConstT_M This);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
T_MXYs1dHas(ConstHandle2ConstT_M This);

// --- Get, const
extern_c Handle2ConstXYs1d
T_MXYs1dGetConst(ConstHandle2ConstT_M This);

// +++ Get, non-const
extern_c Handle2XYs1d
T_MXYs1dGet(ConstHandle2T_M This);

// +++ Set
extern_c void
T_MXYs1dSet(ConstHandle2T_M This, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/T_M/src/custom.h"

#undef extern_c
#endif
