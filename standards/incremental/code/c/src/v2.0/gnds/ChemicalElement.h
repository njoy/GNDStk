
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
// ChemicalElement is the basic handle type in this file. Example:
//    // Create a default ChemicalElement object:
//    ChemicalElement handle = ChemicalElementDefault();
// Functions involving ChemicalElement are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_CODE_V2_0_GNDS_CHEMICALELEMENT
#define C_INTERFACE_CODE_V2_0_GNDS_CHEMICALELEMENT

#include "GNDStk.h"
#include "v2.0/gnds/Atomic.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ChemicalElementClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ChemicalElement
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ChemicalElementClass *ChemicalElement;

// --- Const-aware handles.
typedef const struct ChemicalElementClass *const ConstHandle2ConstChemicalElement;
typedef       struct ChemicalElementClass *const ConstHandle2ChemicalElement;
typedef const struct ChemicalElementClass *      Handle2ConstChemicalElement;
typedef       struct ChemicalElementClass *      Handle2ChemicalElement;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstChemicalElement
ChemicalElementDefaultConst();

// +++ Create, default
extern_c Handle2ChemicalElement
ChemicalElementDefault();

// --- Create, general, const
extern_c Handle2ConstChemicalElement
ChemicalElementCreateConst(
   const char *const symbol,
   const int Z,
   const char *const name,
   ConstHandle2ConstAtomic atomic
);

// +++ Create, general
extern_c Handle2ChemicalElement
ChemicalElementCreate(
   const char *const symbol,
   const int Z,
   const char *const name,
   ConstHandle2ConstAtomic atomic
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ChemicalElementAssign(ConstHandle2ChemicalElement This, ConstHandle2ConstChemicalElement from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ChemicalElementDelete(ConstHandle2ConstChemicalElement This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ChemicalElementRead(ConstHandle2ChemicalElement This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ChemicalElementWrite(ConstHandle2ConstChemicalElement This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ChemicalElementPrint(ConstHandle2ConstChemicalElement This);

// +++ Print to standard output, as XML
extern_c int
ChemicalElementPrintXML(ConstHandle2ConstChemicalElement This);

// +++ Print to standard output, as JSON
extern_c int
ChemicalElementPrintJSON(ConstHandle2ConstChemicalElement This);


// -----------------------------------------------------------------------------
// Metadatum: symbol
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ChemicalElementSymbolHas(ConstHandle2ConstChemicalElement This);

// +++ Get
// +++ Returns by value
extern_c const char *
ChemicalElementSymbolGet(ConstHandle2ConstChemicalElement This);

// +++ Set
extern_c void
ChemicalElementSymbolSet(ConstHandle2ChemicalElement This, const char *const symbol);


// -----------------------------------------------------------------------------
// Metadatum: Z
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ChemicalElementZHas(ConstHandle2ConstChemicalElement This);

// +++ Get
// +++ Returns by value
extern_c int
ChemicalElementZGet(ConstHandle2ConstChemicalElement This);

// +++ Set
extern_c void
ChemicalElementZSet(ConstHandle2ChemicalElement This, const int Z);


// -----------------------------------------------------------------------------
// Metadatum: name
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ChemicalElementNameHas(ConstHandle2ConstChemicalElement This);

// +++ Get
// +++ Returns by value
extern_c const char *
ChemicalElementNameGet(ConstHandle2ConstChemicalElement This);

// +++ Set
extern_c void
ChemicalElementNameSet(ConstHandle2ChemicalElement This, const char *const name);


// -----------------------------------------------------------------------------
// Child: atomic
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ChemicalElementAtomicHas(ConstHandle2ConstChemicalElement This);

// --- Get, const
extern_c Handle2ConstAtomic
ChemicalElementAtomicGetConst(ConstHandle2ConstChemicalElement This);

// +++ Get, non-const
extern_c Handle2Atomic
ChemicalElementAtomicGet(ConstHandle2ChemicalElement This);

// +++ Set
extern_c void
ChemicalElementAtomicSet(ConstHandle2ChemicalElement This, ConstHandle2ConstAtomic atomic);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
