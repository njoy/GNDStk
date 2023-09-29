
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
// T_effective is the basic handle type in this file. Example:
//    // Create a default T_effective object:
//    T_effective handle = T_effectiveDefault();
// Functions involving T_effective are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_T_EFFECTIVE
#define C_INTERFACE_GNDS_V2_0_GENERAL_T_EFFECTIVE

#include "GNDStk.h"
#include "v2.0/general/XYs1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct T_effectiveClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ T_effective
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct T_effectiveClass *T_effective;

// --- Const-aware handles.
typedef const struct T_effectiveClass *const ConstHandle2ConstT_effective;
typedef       struct T_effectiveClass *const ConstHandle2T_effective;
typedef const struct T_effectiveClass *      Handle2ConstT_effective;
typedef       struct T_effectiveClass *      Handle2T_effective;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstT_effective
T_effectiveDefaultConst();

// +++ Create, default, non-const
extern_c Handle2T_effective
T_effectiveDefault();

// --- Create, general, const
extern_c Handle2ConstT_effective
T_effectiveCreateConst(
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Create, general, non-const
extern_c Handle2T_effective
T_effectiveCreate(
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
T_effectiveAssign(ConstHandle2T_effective self, ConstHandle2ConstT_effective from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
T_effectiveDelete(ConstHandle2ConstT_effective self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
T_effectiveRead(ConstHandle2T_effective self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
T_effectiveWrite(ConstHandle2ConstT_effective self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
T_effectivePrint(ConstHandle2ConstT_effective self);

// +++ Print to standard output, as XML
extern_c int
T_effectivePrintXML(ConstHandle2ConstT_effective self);

// +++ Print to standard output, as JSON
extern_c int
T_effectivePrintJSON(ConstHandle2ConstT_effective self);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
T_effectiveXYs1dHas(ConstHandle2ConstT_effective self);

// --- Get, const
extern_c Handle2ConstXYs1d
T_effectiveXYs1dGetConst(ConstHandle2ConstT_effective self);

// +++ Get, non-const
extern_c Handle2XYs1d
T_effectiveXYs1dGet(ConstHandle2T_effective self);

// +++ Set
extern_c void
T_effectiveXYs1dSet(ConstHandle2T_effective self, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/T_effective/src/custom.h"

#undef extern_c
#endif
