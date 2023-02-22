
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
// LevelSpacing is the basic handle type in this file. Example:
//    // Create a default LevelSpacing object:
//    LevelSpacing handle = LevelSpacingDefault();
// Functions involving LevelSpacing are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_LEVELSPACING
#define C_INTERFACE_ALPHA_V2_0_GENERAL_LEVELSPACING

#include "GNDStk.h"
#include "v2.0/general/XYs1d.h"
#include "v2.0/general/Constant1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct LevelSpacingClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ LevelSpacing
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct LevelSpacingClass *LevelSpacing;

// --- Const-aware handles.
typedef const struct LevelSpacingClass *const ConstHandle2ConstLevelSpacing;
typedef       struct LevelSpacingClass *const ConstHandle2LevelSpacing;
typedef const struct LevelSpacingClass *      Handle2ConstLevelSpacing;
typedef       struct LevelSpacingClass *      Handle2LevelSpacing;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstLevelSpacing
LevelSpacingDefaultConst();

// +++ Create, default
extern_c Handle2LevelSpacing
LevelSpacingDefault();

// --- Create, general, const
extern_c Handle2ConstLevelSpacing
LevelSpacingCreateConst(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstConstant1d constant1d
);

// +++ Create, general
extern_c Handle2LevelSpacing
LevelSpacingCreate(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstConstant1d constant1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
LevelSpacingAssign(ConstHandle2LevelSpacing self, ConstHandle2ConstLevelSpacing from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
LevelSpacingDelete(ConstHandle2ConstLevelSpacing self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
LevelSpacingRead(ConstHandle2LevelSpacing self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
LevelSpacingWrite(ConstHandle2ConstLevelSpacing self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
LevelSpacingPrint(ConstHandle2ConstLevelSpacing self);

// +++ Print to standard output, as XML
extern_c int
LevelSpacingPrintXML(ConstHandle2ConstLevelSpacing self);

// +++ Print to standard output, as JSON
extern_c int
LevelSpacingPrintJSON(ConstHandle2ConstLevelSpacing self);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LevelSpacingXYs1dHas(ConstHandle2ConstLevelSpacing self);

// --- Get, const
extern_c Handle2ConstXYs1d
LevelSpacingXYs1dGetConst(ConstHandle2ConstLevelSpacing self);

// +++ Get, non-const
extern_c Handle2XYs1d
LevelSpacingXYs1dGet(ConstHandle2LevelSpacing self);

// +++ Set
extern_c void
LevelSpacingXYs1dSet(ConstHandle2LevelSpacing self, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Child: constant1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LevelSpacingConstant1dHas(ConstHandle2ConstLevelSpacing self);

// --- Get, const
extern_c Handle2ConstConstant1d
LevelSpacingConstant1dGetConst(ConstHandle2ConstLevelSpacing self);

// +++ Get, non-const
extern_c Handle2Constant1d
LevelSpacingConstant1dGet(ConstHandle2LevelSpacing self);

// +++ Set
extern_c void
LevelSpacingConstant1dSet(ConstHandle2LevelSpacing self, ConstHandle2ConstConstant1d constant1d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/LevelSpacing/src/custom.h"

#undef extern_c
#endif