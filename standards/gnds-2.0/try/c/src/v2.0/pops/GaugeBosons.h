
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
//    // +++ comment
// Constructs you're LESS likely to care about are preceded with:
//    // --- comment
// Anything not marked as above can be ignored by most users.
//
// GaugeBosons is the basic handle type in this file. Example:
//    // Create a default GaugeBosons object:
//    GaugeBosons handle = GaugeBosonsDefault();
// Functions involving GaugeBosons are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_POPS_GAUGEBOSONS
#define C_INTERFACE_TRY_V2_0_POPS_GAUGEBOSONS

#include "GNDStk.h"
#include "v2.0/pops/GaugeBoson.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct GaugeBosonsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ GaugeBosons
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct GaugeBosonsClass *GaugeBosons;

// --- Const-aware handles.
typedef const struct GaugeBosonsClass *const ConstHandle2ConstGaugeBosons;
typedef       struct GaugeBosonsClass *const ConstHandle2GaugeBosons;
typedef const struct GaugeBosonsClass *      Handle2ConstGaugeBosons;
typedef       struct GaugeBosonsClass *      Handle2GaugeBosons;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstGaugeBosons
GaugeBosonsDefaultConst();

// +++ Create, default
extern_c Handle2GaugeBosons
GaugeBosonsDefault();

// --- Create, general, const
extern_c Handle2ConstGaugeBosons
GaugeBosonsCreateConst(
   ConstHandle2GaugeBoson *const gaugeBoson, const size_t gaugeBosonSize
);

// +++ Create, general
extern_c Handle2GaugeBosons
GaugeBosonsCreate(
   ConstHandle2GaugeBoson *const gaugeBoson, const size_t gaugeBosonSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
GaugeBosonsAssign(ConstHandle2GaugeBosons This, ConstHandle2ConstGaugeBosons from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
GaugeBosonsDelete(ConstHandle2ConstGaugeBosons This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
GaugeBosonsRead(ConstHandle2GaugeBosons This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
GaugeBosonsWrite(ConstHandle2ConstGaugeBosons This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
GaugeBosonsPrint(ConstHandle2ConstGaugeBosons This);

// +++ Print to standard output, as XML
extern_c int
GaugeBosonsPrintXML(ConstHandle2ConstGaugeBosons This);

// +++ Print to standard output, as JSON
extern_c int
GaugeBosonsPrintJSON(ConstHandle2ConstGaugeBosons This);


// -----------------------------------------------------------------------------
// Child: gaugeBoson
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GaugeBosonsGaugeBosonHas(ConstHandle2ConstGaugeBosons This);

// +++ Clear
extern_c void
GaugeBosonsGaugeBosonClear(ConstHandle2GaugeBosons This);

// +++ Size
extern_c size_t
GaugeBosonsGaugeBosonSize(ConstHandle2ConstGaugeBosons This);

// +++ Add
extern_c void
GaugeBosonsGaugeBosonAdd(ConstHandle2GaugeBosons This, ConstHandle2ConstGaugeBoson gaugeBoson);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstGaugeBoson
GaugeBosonsGaugeBosonGetConst(ConstHandle2ConstGaugeBosons This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2GaugeBoson
GaugeBosonsGaugeBosonGet(ConstHandle2GaugeBosons This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
GaugeBosonsGaugeBosonSet(
   ConstHandle2GaugeBosons This,
   const size_t index_,
   ConstHandle2ConstGaugeBoson gaugeBoson
);

// +++ Has, by id
extern_c int
GaugeBosonsGaugeBosonHasById(
   ConstHandle2ConstGaugeBosons This,
   const XMLName id
);

// --- Get, by id, const
extern_c Handle2ConstGaugeBoson
GaugeBosonsGaugeBosonGetByIdConst(
   ConstHandle2ConstGaugeBosons This,
   const XMLName id
);

// +++ Get, by id, non-const
extern_c Handle2GaugeBoson
GaugeBosonsGaugeBosonGetById(
   ConstHandle2GaugeBosons This,
   const XMLName id
);

// +++ Set, by id
extern_c void
GaugeBosonsGaugeBosonSetById(
   ConstHandle2GaugeBosons This,
   const XMLName id,
   ConstHandle2ConstGaugeBoson gaugeBoson
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
