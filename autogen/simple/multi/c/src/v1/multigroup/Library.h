
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
// Library is the basic handle type in this file. Example:
//    // Create a default Library object:
//    Library handle = LibraryDefault();
// Functions involving Library are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_MULTI_V1_MULTIGROUP_LIBRARY
#define C_INTERFACE_MULTI_V1_MULTIGROUP_LIBRARY

#include "GNDStk.h"
#include "v1/multigroup/Element.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct LibraryClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Library
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct LibraryClass *Library;

// --- Const-aware handles.
typedef const struct LibraryClass *const ConstHandle2ConstLibrary;
typedef       struct LibraryClass *const ConstHandle2Library;
typedef const struct LibraryClass *      Handle2ConstLibrary;
typedef       struct LibraryClass *      Handle2Library;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstLibrary
LibraryDefaultConst();

// +++ Create, default
extern_c Handle2Library
LibraryDefault();

// --- Create, general, const
extern_c Handle2ConstLibrary
LibraryCreateConst(
   const char *const name,
   ConstHandle2Element *const element, const size_t elementSize
);

// +++ Create, general
extern_c Handle2Library
LibraryCreate(
   const char *const name,
   ConstHandle2Element *const element, const size_t elementSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
LibraryAssign(ConstHandle2Library This, ConstHandle2ConstLibrary from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
LibraryDelete(ConstHandle2ConstLibrary This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
LibraryRead(ConstHandle2Library This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
LibraryWrite(ConstHandle2ConstLibrary This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
LibraryPrint(ConstHandle2ConstLibrary This);

// +++ Print to standard output, as XML
extern_c int
LibraryPrintXML(ConstHandle2ConstLibrary This);

// +++ Print to standard output, as JSON
extern_c int
LibraryPrintJSON(ConstHandle2ConstLibrary This);


// -----------------------------------------------------------------------------
// Metadatum: name
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LibraryNameHas(ConstHandle2ConstLibrary This);

// +++ Get
// +++ Returns by value
extern_c const char *
LibraryNameGet(ConstHandle2ConstLibrary This);

// +++ Set
extern_c void
LibraryNameSet(ConstHandle2Library This, const char *const name);


// -----------------------------------------------------------------------------
// Child: element
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LibraryElementHas(ConstHandle2ConstLibrary This);

// +++ Clear
extern_c void
LibraryElementClear(ConstHandle2Library This);

// +++ Size
extern_c size_t
LibraryElementSize(ConstHandle2ConstLibrary This);

// +++ Add
extern_c void
LibraryElementAdd(ConstHandle2Library This, ConstHandle2ConstElement element);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstElement
LibraryElementGetConst(ConstHandle2ConstLibrary This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Element
LibraryElementGet(ConstHandle2Library This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
LibraryElementSet(
   ConstHandle2Library This,
   const size_t index_,
   ConstHandle2ConstElement element
);

// +++ Has, by symbol
extern_c int
LibraryElementHasBySymbol(
   ConstHandle2ConstLibrary This,
   const char *const symbol
);

// --- Get, by symbol, const
extern_c Handle2ConstElement
LibraryElementGetBySymbolConst(
   ConstHandle2ConstLibrary This,
   const char *const symbol
);

// +++ Get, by symbol, non-const
extern_c Handle2Element
LibraryElementGetBySymbol(
   ConstHandle2Library This,
   const char *const symbol
);

// +++ Set, by symbol
extern_c void
LibraryElementSetBySymbol(
   ConstHandle2Library This,
   const char *const symbol,
   ConstHandle2ConstElement element
);

// +++ Has, by atomic_number
extern_c int
LibraryElementHasByAtomicNumber(
   ConstHandle2ConstLibrary This,
   const int atomic_number
);

// --- Get, by atomic_number, const
extern_c Handle2ConstElement
LibraryElementGetByAtomicNumberConst(
   ConstHandle2ConstLibrary This,
   const int atomic_number
);

// +++ Get, by atomic_number, non-const
extern_c Handle2Element
LibraryElementGetByAtomicNumber(
   ConstHandle2Library This,
   const int atomic_number
);

// +++ Set, by atomic_number
extern_c void
LibraryElementSetByAtomicNumber(
   ConstHandle2Library This,
   const int atomic_number,
   ConstHandle2ConstElement element
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v1/multigroup/Library/src/custom.h"

#undef extern_c
#endif
