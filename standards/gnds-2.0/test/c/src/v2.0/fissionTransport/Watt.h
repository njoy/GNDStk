
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
// Watt is the basic handle type in this file. Example:
//    // Create a default Watt object:
//    Watt handle = WattDefault();
// Functions involving Watt are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_FISSIONTRANSPORT_WATT
#define C_INTERFACE_TEST_V2_0_FISSIONTRANSPORT_WATT

#include "GNDStk.h"
#include "v2.0/transport/U.h"
#include "v2.0/fissionTransport/A.h"
#include "v2.0/fissionTransport/B.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct WattClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Watt
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct WattClass *Watt;

// --- Const-aware handles.
typedef const struct WattClass *const ConstHandle2ConstWatt;
typedef       struct WattClass *const ConstHandle2Watt;
typedef const struct WattClass *      Handle2ConstWatt;
typedef       struct WattClass *      Handle2Watt;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstWatt
WattDefaultConst();

// +++ Create, default
extern_c Handle2Watt
WattDefault();

// --- Create, general, const
extern_c Handle2ConstWatt
WattCreateConst(
   ConstHandle2ConstU U,
   ConstHandle2ConstA a,
   ConstHandle2ConstB b
);

// +++ Create, general
extern_c Handle2Watt
WattCreate(
   ConstHandle2ConstU U,
   ConstHandle2ConstA a,
   ConstHandle2ConstB b
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
WattAssign(ConstHandle2Watt This, ConstHandle2ConstWatt from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
WattDelete(ConstHandle2ConstWatt This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
WattRead(ConstHandle2Watt This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
WattWrite(ConstHandle2ConstWatt This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
WattPrint(ConstHandle2ConstWatt This);

// +++ Print to standard output, as XML
extern_c int
WattPrintXML(ConstHandle2ConstWatt This);

// +++ Print to standard output, as JSON
extern_c int
WattPrintJSON(ConstHandle2ConstWatt This);


// -----------------------------------------------------------------------------
// Child: U
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
WattUHas(ConstHandle2ConstWatt This);

// --- Get, const
extern_c Handle2ConstU
WattUGetConst(ConstHandle2ConstWatt This);

// +++ Get, non-const
extern_c Handle2U
WattUGet(ConstHandle2Watt This);

// +++ Set
extern_c void
WattUSet(ConstHandle2Watt This, ConstHandle2ConstU U);


// -----------------------------------------------------------------------------
// Child: a
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
WattAHas(ConstHandle2ConstWatt This);

// --- Get, const
extern_c Handle2ConstA
WattAGetConst(ConstHandle2ConstWatt This);

// +++ Get, non-const
extern_c Handle2A
WattAGet(ConstHandle2Watt This);

// +++ Set
extern_c void
WattASet(ConstHandle2Watt This, ConstHandle2ConstA a);


// -----------------------------------------------------------------------------
// Child: b
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
WattBHas(ConstHandle2ConstWatt This);

// --- Get, const
extern_c Handle2ConstB
WattBGetConst(ConstHandle2ConstWatt This);

// +++ Get, non-const
extern_c Handle2B
WattBGet(ConstHandle2Watt This);

// +++ Set
extern_c void
WattBSet(ConstHandle2Watt This, ConstHandle2ConstB b);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
