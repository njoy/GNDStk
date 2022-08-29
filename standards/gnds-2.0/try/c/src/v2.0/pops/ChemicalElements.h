
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
// ChemicalElements is the basic handle type in this file. Example:
//    // Create a default ChemicalElements object:
//    ChemicalElements handle = ChemicalElementsDefault();
// Functions involving ChemicalElements are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_POPS_CHEMICALELEMENTS
#define C_INTERFACE_TRY_V2_0_POPS_CHEMICALELEMENTS

#include "GNDStk.h"
#include "v2.0/pops/ChemicalElement.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ChemicalElementsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ChemicalElements
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ChemicalElementsClass *ChemicalElements;

// --- Const-aware handles.
typedef const struct ChemicalElementsClass *const ConstHandle2ConstChemicalElements;
typedef       struct ChemicalElementsClass *const ConstHandle2ChemicalElements;
typedef const struct ChemicalElementsClass *      Handle2ConstChemicalElements;
typedef       struct ChemicalElementsClass *      Handle2ChemicalElements;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstChemicalElements
ChemicalElementsDefaultConst();

// +++ Create, default
extern_c Handle2ChemicalElements
ChemicalElementsDefault();

// --- Create, general, const
extern_c Handle2ConstChemicalElements
ChemicalElementsCreateConst(
   ConstHandle2ChemicalElement *const chemicalElement, const size_t chemicalElementSize
);

// +++ Create, general
extern_c Handle2ChemicalElements
ChemicalElementsCreate(
   ConstHandle2ChemicalElement *const chemicalElement, const size_t chemicalElementSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ChemicalElementsAssign(ConstHandle2ChemicalElements This, ConstHandle2ConstChemicalElements from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ChemicalElementsDelete(ConstHandle2ConstChemicalElements This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ChemicalElementsRead(ConstHandle2ChemicalElements This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ChemicalElementsWrite(ConstHandle2ConstChemicalElements This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ChemicalElementsPrint(ConstHandle2ConstChemicalElements This);

// +++ Print to standard output, as XML
extern_c int
ChemicalElementsPrintXML(ConstHandle2ConstChemicalElements This);

// +++ Print to standard output, as JSON
extern_c int
ChemicalElementsPrintJSON(ConstHandle2ConstChemicalElements This);


// -----------------------------------------------------------------------------
// Child: chemicalElement
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ChemicalElementsChemicalElementHas(ConstHandle2ConstChemicalElements This);

// +++ Clear
extern_c void
ChemicalElementsChemicalElementClear(ConstHandle2ChemicalElements This);

// +++ Size
extern_c size_t
ChemicalElementsChemicalElementSize(ConstHandle2ConstChemicalElements This);

// +++ Add
extern_c void
ChemicalElementsChemicalElementAdd(ConstHandle2ChemicalElements This, ConstHandle2ConstChemicalElement chemicalElement);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstChemicalElement
ChemicalElementsChemicalElementGetConst(ConstHandle2ConstChemicalElements This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2ChemicalElement
ChemicalElementsChemicalElementGet(ConstHandle2ChemicalElements This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ChemicalElementsChemicalElementSet(
   ConstHandle2ChemicalElements This,
   const size_t index_,
   ConstHandle2ConstChemicalElement chemicalElement
);

// +++ Has, by symbol
extern_c int
ChemicalElementsChemicalElementHasBySymbol(
   ConstHandle2ConstChemicalElements This,
   const XMLName symbol
);

// --- Get, by symbol, const
extern_c Handle2ConstChemicalElement
ChemicalElementsChemicalElementGetBySymbolConst(
   ConstHandle2ConstChemicalElements This,
   const XMLName symbol
);

// +++ Get, by symbol, non-const
extern_c Handle2ChemicalElement
ChemicalElementsChemicalElementGetBySymbol(
   ConstHandle2ChemicalElements This,
   const XMLName symbol
);

// +++ Set, by symbol
extern_c void
ChemicalElementsChemicalElementSetBySymbol(
   ConstHandle2ChemicalElements This,
   const XMLName symbol,
   ConstHandle2ConstChemicalElement chemicalElement
);

// +++ Has, by Z
extern_c int
ChemicalElementsChemicalElementHasByZ(
   ConstHandle2ConstChemicalElements This,
   const Integer32 Z
);

// --- Get, by Z, const
extern_c Handle2ConstChemicalElement
ChemicalElementsChemicalElementGetByZConst(
   ConstHandle2ConstChemicalElements This,
   const Integer32 Z
);

// +++ Get, by Z, non-const
extern_c Handle2ChemicalElement
ChemicalElementsChemicalElementGetByZ(
   ConstHandle2ChemicalElements This,
   const Integer32 Z
);

// +++ Set, by Z
extern_c void
ChemicalElementsChemicalElementSetByZ(
   ConstHandle2ChemicalElements This,
   const Integer32 Z,
   ConstHandle2ConstChemicalElement chemicalElement
);

// +++ Has, by name
extern_c int
ChemicalElementsChemicalElementHasByName(
   ConstHandle2ConstChemicalElements This,
   const XMLName name
);

// --- Get, by name, const
extern_c Handle2ConstChemicalElement
ChemicalElementsChemicalElementGetByNameConst(
   ConstHandle2ConstChemicalElements This,
   const XMLName name
);

// +++ Get, by name, non-const
extern_c Handle2ChemicalElement
ChemicalElementsChemicalElementGetByName(
   ConstHandle2ChemicalElements This,
   const XMLName name
);

// +++ Set, by name
extern_c void
ChemicalElementsChemicalElementSetByName(
   ConstHandle2ChemicalElements This,
   const XMLName name,
   ConstHandle2ConstChemicalElement chemicalElement
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
