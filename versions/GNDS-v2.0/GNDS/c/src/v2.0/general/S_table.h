
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
// S_table is the basic handle type in this file. Example:
//    // Create a default S_table object:
//    S_table handle = S_tableDefault();
// Functions involving S_table are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_S_TABLE
#define C_INTERFACE_GNDS_V2_0_GENERAL_S_TABLE

#include "GNDStk.h"
#include "v2.0/general/Gridded2d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct S_tableClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ S_table
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct S_tableClass *S_table;

// --- Const-aware handles.
typedef const struct S_tableClass *const ConstHandle2ConstS_table;
typedef       struct S_tableClass *const ConstHandle2S_table;
typedef const struct S_tableClass *      Handle2ConstS_table;
typedef       struct S_tableClass *      Handle2S_table;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstS_table
S_tableDefaultConst();

// +++ Create, default
extern_c Handle2S_table
S_tableDefault();

// --- Create, general, const
extern_c Handle2ConstS_table
S_tableCreateConst(
   ConstHandle2ConstGridded2d gridded2d
);

// +++ Create, general
extern_c Handle2S_table
S_tableCreate(
   ConstHandle2ConstGridded2d gridded2d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
S_tableAssign(ConstHandle2S_table self, ConstHandle2ConstS_table from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
S_tableDelete(ConstHandle2ConstS_table self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
S_tableRead(ConstHandle2S_table self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
S_tableWrite(ConstHandle2ConstS_table self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
S_tablePrint(ConstHandle2ConstS_table self);

// +++ Print to standard output, as XML
extern_c int
S_tablePrintXML(ConstHandle2ConstS_table self);

// +++ Print to standard output, as JSON
extern_c int
S_tablePrintJSON(ConstHandle2ConstS_table self);


// -----------------------------------------------------------------------------
// Child: gridded2d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
S_tableGridded2dHas(ConstHandle2ConstS_table self);

// --- Get, const
extern_c Handle2ConstGridded2d
S_tableGridded2dGetConst(ConstHandle2ConstS_table self);

// +++ Get
extern_c Handle2Gridded2d
S_tableGridded2dGet(ConstHandle2S_table self);

// +++ Set
extern_c void
S_tableGridded2dSet(ConstHandle2S_table self, ConstHandle2ConstGridded2d gridded2d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/S_table/src/custom.h"

#undef extern_c
#endif
