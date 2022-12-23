
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
// Transportables is the basic handle type in this file. Example:
//    // Create a default Transportables object:
//    Transportables handle = TransportablesDefault();
// Functions involving Transportables are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_STYLES_TRANSPORTABLES
#define C_INTERFACE_TEST_V2_0_STYLES_TRANSPORTABLES

#include "GNDStk.h"
#include "v2.0/styles/Transportable.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct TransportablesClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Transportables
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct TransportablesClass *Transportables;

// --- Const-aware handles.
typedef const struct TransportablesClass *const ConstHandle2ConstTransportables;
typedef       struct TransportablesClass *const ConstHandle2Transportables;
typedef const struct TransportablesClass *      Handle2ConstTransportables;
typedef       struct TransportablesClass *      Handle2Transportables;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstTransportables
TransportablesDefaultConst();

// +++ Create, default
extern_c Handle2Transportables
TransportablesDefault();

// --- Create, general, const
extern_c Handle2ConstTransportables
TransportablesCreateConst(
   const XMLName label,
   ConstHandle2Transportable *const transportable, const size_t transportableSize
);

// +++ Create, general
extern_c Handle2Transportables
TransportablesCreate(
   const XMLName label,
   ConstHandle2Transportable *const transportable, const size_t transportableSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
TransportablesAssign(ConstHandle2Transportables This, ConstHandle2ConstTransportables from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
TransportablesDelete(ConstHandle2ConstTransportables This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
TransportablesRead(ConstHandle2Transportables This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
TransportablesWrite(ConstHandle2ConstTransportables This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
TransportablesPrint(ConstHandle2ConstTransportables This);

// +++ Print to standard output, as XML
extern_c int
TransportablesPrintXML(ConstHandle2ConstTransportables This);

// +++ Print to standard output, as JSON
extern_c int
TransportablesPrintJSON(ConstHandle2ConstTransportables This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TransportablesLabelHas(ConstHandle2ConstTransportables This);

// +++ Get
// +++ Returns by value
extern_c XMLName
TransportablesLabelGet(ConstHandle2ConstTransportables This);

// +++ Set
extern_c void
TransportablesLabelSet(ConstHandle2Transportables This, const XMLName label);


// -----------------------------------------------------------------------------
// Child: transportable
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TransportablesTransportableHas(ConstHandle2ConstTransportables This);

// +++ Clear
extern_c void
TransportablesTransportableClear(ConstHandle2Transportables This);

// +++ Size
extern_c size_t
TransportablesTransportableSize(ConstHandle2ConstTransportables This);

// +++ Add
extern_c void
TransportablesTransportableAdd(ConstHandle2Transportables This, ConstHandle2ConstTransportable transportable);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstTransportable
TransportablesTransportableGetConst(ConstHandle2ConstTransportables This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Transportable
TransportablesTransportableGet(ConstHandle2Transportables This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
TransportablesTransportableSet(
   ConstHandle2Transportables This,
   const size_t index_,
   ConstHandle2ConstTransportable transportable
);

// +++ Has, by conserve
extern_c int
TransportablesTransportableHasByConserve(
   ConstHandle2ConstTransportables This,
   const XMLName conserve
);

// --- Get, by conserve, const
extern_c Handle2ConstTransportable
TransportablesTransportableGetByConserveConst(
   ConstHandle2ConstTransportables This,
   const XMLName conserve
);

// +++ Get, by conserve, non-const
extern_c Handle2Transportable
TransportablesTransportableGetByConserve(
   ConstHandle2Transportables This,
   const XMLName conserve
);

// +++ Set, by conserve
extern_c void
TransportablesTransportableSetByConserve(
   ConstHandle2Transportables This,
   const XMLName conserve,
   ConstHandle2ConstTransportable transportable
);

// +++ Has, by label
extern_c int
TransportablesTransportableHasByLabel(
   ConstHandle2ConstTransportables This,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstTransportable
TransportablesTransportableGetByLabelConst(
   ConstHandle2ConstTransportables This,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2Transportable
TransportablesTransportableGetByLabel(
   ConstHandle2Transportables This,
   const XMLName label
);

// +++ Set, by label
extern_c void
TransportablesTransportableSetByLabel(
   ConstHandle2Transportables This,
   const XMLName label,
   ConstHandle2ConstTransportable transportable
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
