
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
// Element is the basic handle type in this file. Example:
//    // Create a default Element object:
//    Element handle = ElementDefault();
// Functions involving Element are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_MULTI_V1_MULTIGROUP_ELEMENT
#define C_INTERFACE_MULTI_V1_MULTIGROUP_ELEMENT

#include "GNDStk.h"
#include "v1/multigroup/Isotope.h"
#include "v1/multigroup/Foobar.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ElementClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Element
// +++ General handle, suitable for many users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ElementClass *Element;

// --- Const-aware handles, re: constness of handle vs. handled object.
typedef const struct ElementClass *const ConstHandle2ConstElement;
typedef       struct ElementClass *const ConstHandle2Element;
typedef const struct ElementClass *      Handle2ConstElement;
typedef       struct ElementClass *      Handle2Element;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstElement
ElementDefaultConst();

// +++ Create, default
extern_c Handle2Element
ElementDefault();

// --- Create, general, const
extern_c Handle2ConstElement
ElementCreateConst(
   const char *const symbol,
   const int atomic_number,
   ConstHandle2ConstIsotope *const isotope, const size_t isotopeSize,
   ConstHandle2ConstFoobar foobar
);

// +++ Create, general
extern_c Handle2Element
ElementCreate(
   const char *const symbol,
   const int atomic_number,
   ConstHandle2ConstIsotope *const isotope, const size_t isotopeSize,
   ConstHandle2ConstFoobar foobar
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ElementAssign(ConstHandle2Element This, ConstHandle2ConstElement from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ElementDelete(ConstHandle2ConstElement This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ElementRead(ConstHandle2Element This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ElementWrite(ConstHandle2ConstElement This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ElementPrint(ConstHandle2ConstElement This);

// +++ Print to standard output, as XML
extern_c int
ElementPrintXML(ConstHandle2ConstElement This);

// +++ Print to standard output, as JSON
extern_c int
ElementPrintJSON(ConstHandle2ConstElement This);


// -----------------------------------------------------------------------------
// Re: symbol
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ElementSymbolHas(ConstHandle2ConstElement This);

// +++ Get
// +++ Returns by value
extern_c const char *
ElementSymbolGet(ConstHandle2ConstElement This);

// +++ Set
extern_c void
ElementSymbolSet(ConstHandle2Element This, const char *const symbol);


// -----------------------------------------------------------------------------
// Re: atomic_number
// -----------------------------------------------------------------------------

// +++ Get
// +++ Returns by value
extern_c int
ElementAtomicNumberGet(ConstHandle2ConstElement This);

// +++ Set
extern_c void
ElementAtomicNumberSet(ConstHandle2Element This, const int atomic_number);


// -----------------------------------------------------------------------------
// Re: isotope
// -----------------------------------------------------------------------------

// +++ Clear
extern_c void
ElementIsotopeClear(ConstHandle2Element This);

// +++ Size
extern_c size_t
ElementIsotopeSize(ConstHandle2ConstElement This);

// +++ Add
extern_c void
ElementIsotopeAdd(ConstHandle2Element This, ConstHandle2ConstIsotope isotope);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstIsotope
ElementIsotopeGetConst(ConstHandle2ConstElement This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Isotope
ElementIsotopeGet(ConstHandle2Element This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ElementIsotopeSet(
   ConstHandle2Element This,
   const size_t index_,
   ConstHandle2ConstIsotope isotope
);

// +++ Has, by mass_number
extern_c int
ElementIsotopeHasByMassNumber(
   ConstHandle2ConstElement This,
   const int mass_number
);

// --- Get, by mass_number, const
extern_c Handle2ConstIsotope
ElementIsotopeGetByMassNumberConst(
   ConstHandle2ConstElement This,
   const int mass_number
);

// +++ Get, by mass_number, non-const
extern_c Handle2Isotope
ElementIsotopeGetByMassNumber(
   ConstHandle2Element This,
   const int mass_number
);

// +++ Set, by mass_number
extern_c void
ElementIsotopeSetByMassNumber(
   ConstHandle2Element This,
   const int mass_number,
   ConstHandle2ConstIsotope isotope
);


// -----------------------------------------------------------------------------
// Re: foobar
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ElementFoobarHas(ConstHandle2ConstElement This);

// --- Get, const
extern_c Handle2ConstFoobar
ElementFoobarGetConst(ConstHandle2ConstElement This);

// +++ Get, non-const
extern_c Handle2Foobar
ElementFoobarGet(ConstHandle2Element This);

// +++ Set
extern_c void
ElementFoobarSet(ConstHandle2Element This, ConstHandle2ConstFoobar foobar);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
