
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
// Isotope is the basic handle type in this file. Example:
//    // Create a default Isotope object:
//    Isotope handle = IsotopeDefault();
// Functions involving Isotope are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_POPS_ISOTOPE
#define C_INTERFACE_TEST_V2_0_POPS_ISOTOPE

#include "GNDStk.h"
#include "v2.0/pops/Nuclides.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct IsotopeClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Isotope
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct IsotopeClass *Isotope;

// --- Const-aware handles.
typedef const struct IsotopeClass *const ConstHandle2ConstIsotope;
typedef       struct IsotopeClass *const ConstHandle2Isotope;
typedef const struct IsotopeClass *      Handle2ConstIsotope;
typedef       struct IsotopeClass *      Handle2Isotope;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstIsotope
IsotopeDefaultConst();

// +++ Create, default
extern_c Handle2Isotope
IsotopeDefault();

// --- Create, general, const
extern_c Handle2ConstIsotope
IsotopeCreateConst(
   const Integer32 A,
   const XMLName symbol,
   ConstHandle2ConstNuclides nuclides
);

// +++ Create, general
extern_c Handle2Isotope
IsotopeCreate(
   const Integer32 A,
   const XMLName symbol,
   ConstHandle2ConstNuclides nuclides
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
IsotopeAssign(ConstHandle2Isotope This, ConstHandle2ConstIsotope from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
IsotopeDelete(ConstHandle2ConstIsotope This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
IsotopeRead(ConstHandle2Isotope This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
IsotopeWrite(ConstHandle2ConstIsotope This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
IsotopePrint(ConstHandle2ConstIsotope This);

// +++ Print to standard output, as XML
extern_c int
IsotopePrintXML(ConstHandle2ConstIsotope This);

// +++ Print to standard output, as JSON
extern_c int
IsotopePrintJSON(ConstHandle2ConstIsotope This);


// -----------------------------------------------------------------------------
// Metadatum: A
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
IsotopeAHas(ConstHandle2ConstIsotope This);

// +++ Get
// +++ Returns by value
extern_c Integer32
IsotopeAGet(ConstHandle2ConstIsotope This);

// +++ Set
extern_c void
IsotopeASet(ConstHandle2Isotope This, const Integer32 A);


// -----------------------------------------------------------------------------
// Metadatum: symbol
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
IsotopeSymbolHas(ConstHandle2ConstIsotope This);

// +++ Get
// +++ Returns by value
extern_c XMLName
IsotopeSymbolGet(ConstHandle2ConstIsotope This);

// +++ Set
extern_c void
IsotopeSymbolSet(ConstHandle2Isotope This, const XMLName symbol);


// -----------------------------------------------------------------------------
// Child: nuclides
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
IsotopeNuclidesHas(ConstHandle2ConstIsotope This);

// --- Get, const
extern_c Handle2ConstNuclides
IsotopeNuclidesGetConst(ConstHandle2ConstIsotope This);

// +++ Get, non-const
extern_c Handle2Nuclides
IsotopeNuclidesGet(ConstHandle2Isotope This);

// +++ Set
extern_c void
IsotopeNuclidesSet(ConstHandle2Isotope This, ConstHandle2ConstNuclides nuclides);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
