
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
// Transportable is the basic handle type in this file. Example:
//    // Create a default Transportable object:
//    Transportable handle = TransportableDefault();
// Functions involving Transportable are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_STYLES_TRANSPORTABLE
#define C_INTERFACE_TEST_V2_0_STYLES_TRANSPORTABLE

#include "GNDStk.h"
#include "v2.0/styles/MultiGroup.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct TransportableClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Transportable
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct TransportableClass *Transportable;

// --- Const-aware handles.
typedef const struct TransportableClass *const ConstHandle2ConstTransportable;
typedef       struct TransportableClass *const ConstHandle2Transportable;
typedef const struct TransportableClass *      Handle2ConstTransportable;
typedef       struct TransportableClass *      Handle2Transportable;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstTransportable
TransportableDefaultConst();

// +++ Create, default
extern_c Handle2Transportable
TransportableDefault();

// --- Create, general, const
extern_c Handle2ConstTransportable
TransportableCreateConst(
   const XMLName conserve,
   const XMLName label,
   ConstHandle2ConstMultiGroup multiGroup
);

// +++ Create, general
extern_c Handle2Transportable
TransportableCreate(
   const XMLName conserve,
   const XMLName label,
   ConstHandle2ConstMultiGroup multiGroup
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
TransportableAssign(ConstHandle2Transportable This, ConstHandle2ConstTransportable from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
TransportableDelete(ConstHandle2ConstTransportable This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
TransportableRead(ConstHandle2Transportable This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
TransportableWrite(ConstHandle2ConstTransportable This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
TransportablePrint(ConstHandle2ConstTransportable This);

// +++ Print to standard output, as XML
extern_c int
TransportablePrintXML(ConstHandle2ConstTransportable This);

// +++ Print to standard output, as JSON
extern_c int
TransportablePrintJSON(ConstHandle2ConstTransportable This);


// -----------------------------------------------------------------------------
// Metadatum: conserve
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TransportableConserveHas(ConstHandle2ConstTransportable This);

// +++ Get
// +++ Returns by value
extern_c XMLName
TransportableConserveGet(ConstHandle2ConstTransportable This);

// +++ Set
extern_c void
TransportableConserveSet(ConstHandle2Transportable This, const XMLName conserve);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TransportableLabelHas(ConstHandle2ConstTransportable This);

// +++ Get
// +++ Returns by value
extern_c XMLName
TransportableLabelGet(ConstHandle2ConstTransportable This);

// +++ Set
extern_c void
TransportableLabelSet(ConstHandle2Transportable This, const XMLName label);


// -----------------------------------------------------------------------------
// Child: multiGroup
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TransportableMultiGroupHas(ConstHandle2ConstTransportable This);

// --- Get, const
extern_c Handle2ConstMultiGroup
TransportableMultiGroupGetConst(ConstHandle2ConstTransportable This);

// +++ Get, non-const
extern_c Handle2MultiGroup
TransportableMultiGroupGet(ConstHandle2Transportable This);

// +++ Set
extern_c void
TransportableMultiGroupSet(ConstHandle2Transportable This, ConstHandle2ConstMultiGroup multiGroup);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
