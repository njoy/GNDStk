
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
// OutputChannel is the basic handle type in this file. Example:
//    // Create a default OutputChannel object:
//    OutputChannel handle = OutputChannelDefault();
// Functions involving OutputChannel are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_REDUCED_OUTPUTCHANNEL
#define C_INTERFACE_ALPHA_V2_0_REDUCED_OUTPUTCHANNEL

#include "GNDStk.h"
#include "v2.0/general/Q.h"
#include "v2.0/reduced/Products.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct OutputChannelClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ OutputChannel
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct OutputChannelClass *OutputChannel;

// --- Const-aware handles.
typedef const struct OutputChannelClass *const ConstHandle2ConstOutputChannel;
typedef       struct OutputChannelClass *const ConstHandle2OutputChannel;
typedef const struct OutputChannelClass *      Handle2ConstOutputChannel;
typedef       struct OutputChannelClass *      Handle2OutputChannel;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstOutputChannel
OutputChannelDefaultConst();

// +++ Create, default
extern_c Handle2OutputChannel
OutputChannelDefault();

// --- Create, general, const
extern_c Handle2ConstOutputChannel
OutputChannelCreateConst(
   const char *const genre,
   const char *const process,
   ConstHandle2ConstQ Q,
   ConstHandle2ConstProducts products
);

// +++ Create, general
extern_c Handle2OutputChannel
OutputChannelCreate(
   const char *const genre,
   const char *const process,
   ConstHandle2ConstQ Q,
   ConstHandle2ConstProducts products
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
OutputChannelAssign(ConstHandle2OutputChannel self, ConstHandle2ConstOutputChannel from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
OutputChannelDelete(ConstHandle2ConstOutputChannel self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
OutputChannelRead(ConstHandle2OutputChannel self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
OutputChannelWrite(ConstHandle2ConstOutputChannel self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
OutputChannelPrint(ConstHandle2ConstOutputChannel self);

// +++ Print to standard output, as XML
extern_c int
OutputChannelPrintXML(ConstHandle2ConstOutputChannel self);

// +++ Print to standard output, as JSON
extern_c int
OutputChannelPrintJSON(ConstHandle2ConstOutputChannel self);


// -----------------------------------------------------------------------------
// Metadatum: genre
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
OutputChannelGenreHas(ConstHandle2ConstOutputChannel self);

// +++ Get
// +++ Returns by value
extern_c const char *
OutputChannelGenreGet(ConstHandle2ConstOutputChannel self);

// +++ Set
extern_c void
OutputChannelGenreSet(ConstHandle2OutputChannel self, const char *const genre);


// -----------------------------------------------------------------------------
// Metadatum: process
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
OutputChannelProcessHas(ConstHandle2ConstOutputChannel self);

// +++ Get
// +++ Returns by value
extern_c const char *
OutputChannelProcessGet(ConstHandle2ConstOutputChannel self);

// +++ Set
extern_c void
OutputChannelProcessSet(ConstHandle2OutputChannel self, const char *const process);


// -----------------------------------------------------------------------------
// Child: Q
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
OutputChannelQHas(ConstHandle2ConstOutputChannel self);

// --- Get, const
extern_c Handle2ConstQ
OutputChannelQGetConst(ConstHandle2ConstOutputChannel self);

// +++ Get, non-const
extern_c Handle2Q
OutputChannelQGet(ConstHandle2OutputChannel self);

// +++ Set
extern_c void
OutputChannelQSet(ConstHandle2OutputChannel self, ConstHandle2ConstQ Q);


// -----------------------------------------------------------------------------
// Child: products
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
OutputChannelProductsHas(ConstHandle2ConstOutputChannel self);

// --- Get, const
extern_c Handle2ConstProducts
OutputChannelProductsGetConst(ConstHandle2ConstOutputChannel self);

// +++ Get, non-const
extern_c Handle2Products
OutputChannelProductsGet(ConstHandle2OutputChannel self);

// +++ Set
extern_c void
OutputChannelProductsSet(ConstHandle2OutputChannel self, ConstHandle2ConstProducts products);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/reduced/OutputChannel/src/custom.h"

#undef extern_c
#endif
