
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
// Summands is the basic handle type in this file. Example:
//    // Create a default Summands object:
//    Summands handle = SummandsDefault();
// Functions involving Summands are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TRANSPORT_SUMMANDS
#define C_INTERFACE_TEST_V2_0_TRANSPORT_SUMMANDS

#include "GNDStk.h"
#include "v2.0/transport/Add.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct SummandsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Summands
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct SummandsClass *Summands;

// --- Const-aware handles.
typedef const struct SummandsClass *const ConstHandle2ConstSummands;
typedef       struct SummandsClass *const ConstHandle2Summands;
typedef const struct SummandsClass *      Handle2ConstSummands;
typedef       struct SummandsClass *      Handle2Summands;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstSummands
SummandsDefaultConst();

// +++ Create, default
extern_c Handle2Summands
SummandsDefault();

// --- Create, general, const
extern_c Handle2ConstSummands
SummandsCreateConst(
   ConstHandle2Add *const add, const size_t addSize
);

// +++ Create, general
extern_c Handle2Summands
SummandsCreate(
   ConstHandle2Add *const add, const size_t addSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
SummandsAssign(ConstHandle2Summands This, ConstHandle2ConstSummands from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
SummandsDelete(ConstHandle2ConstSummands This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
SummandsRead(ConstHandle2Summands This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
SummandsWrite(ConstHandle2ConstSummands This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
SummandsPrint(ConstHandle2ConstSummands This);

// +++ Print to standard output, as XML
extern_c int
SummandsPrintXML(ConstHandle2ConstSummands This);

// +++ Print to standard output, as JSON
extern_c int
SummandsPrintJSON(ConstHandle2ConstSummands This);


// -----------------------------------------------------------------------------
// Child: add
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SummandsAddHas(ConstHandle2ConstSummands This);

// +++ Clear
extern_c void
SummandsAddClear(ConstHandle2Summands This);

// +++ Size
extern_c size_t
SummandsAddSize(ConstHandle2ConstSummands This);

// +++ Add
extern_c void
SummandsAddAdd(ConstHandle2Summands This, ConstHandle2ConstAdd add);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstAdd
SummandsAddGetConst(ConstHandle2ConstSummands This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Add
SummandsAddGet(ConstHandle2Summands This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
SummandsAddSet(
   ConstHandle2Summands This,
   const size_t index_,
   ConstHandle2ConstAdd add
);

// +++ Has, by href
extern_c int
SummandsAddHasByHref(
   ConstHandle2ConstSummands This,
   const char *const href
);

// --- Get, by href, const
extern_c Handle2ConstAdd
SummandsAddGetByHrefConst(
   ConstHandle2ConstSummands This,
   const char *const href
);

// +++ Get, by href, non-const
extern_c Handle2Add
SummandsAddGetByHref(
   ConstHandle2Summands This,
   const char *const href
);

// +++ Set, by href
extern_c void
SummandsAddSetByHref(
   ConstHandle2Summands This,
   const char *const href,
   ConstHandle2ConstAdd add
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
