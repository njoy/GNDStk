
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
// PoPs is the basic handle type in this file. Example:
//    // Create a default PoPs object:
//    PoPs handle = PoPsDefault();
// Functions involving PoPs are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_TOP_POPS
#define C_INTERFACE_ALPHA_V2_0_TOP_POPS

#include "GNDStk.h"
#include "v2.0/general/Styles.h"
#include "v2.0/general/ChemicalElements.h"
#include "v2.0/general/Aliases.h"
#include "v2.0/general/Baryons.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct PoPsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ PoPs
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct PoPsClass *PoPs;

// --- Const-aware handles.
typedef const struct PoPsClass *const ConstHandle2ConstPoPs;
typedef       struct PoPsClass *const ConstHandle2PoPs;
typedef const struct PoPsClass *      Handle2ConstPoPs;
typedef       struct PoPsClass *      Handle2PoPs;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstPoPs
PoPsDefaultConst();

// +++ Create, default
extern_c Handle2PoPs
PoPsDefault();

// --- Create, general, const
extern_c Handle2ConstPoPs
PoPsCreateConst(
   const char *const name,
   const char *const version,
   const char *const format,
   ConstHandle2ConstStyles styles,
   ConstHandle2ConstChemicalElements chemicalElements,
   ConstHandle2ConstAliases aliases,
   ConstHandle2ConstBaryons baryons
);

// +++ Create, general
extern_c Handle2PoPs
PoPsCreate(
   const char *const name,
   const char *const version,
   const char *const format,
   ConstHandle2ConstStyles styles,
   ConstHandle2ConstChemicalElements chemicalElements,
   ConstHandle2ConstAliases aliases,
   ConstHandle2ConstBaryons baryons
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
PoPsAssign(ConstHandle2PoPs This, ConstHandle2ConstPoPs from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
PoPsDelete(ConstHandle2ConstPoPs This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
PoPsRead(ConstHandle2PoPs This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
PoPsWrite(ConstHandle2ConstPoPs This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
PoPsPrint(ConstHandle2ConstPoPs This);

// +++ Print to standard output, as XML
extern_c int
PoPsPrintXML(ConstHandle2ConstPoPs This);

// +++ Print to standard output, as JSON
extern_c int
PoPsPrintJSON(ConstHandle2ConstPoPs This);


// -----------------------------------------------------------------------------
// Metadatum: name
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PoPsNameHas(ConstHandle2ConstPoPs This);

// +++ Get
// +++ Returns by value
extern_c const char *
PoPsNameGet(ConstHandle2ConstPoPs This);

// +++ Set
extern_c void
PoPsNameSet(ConstHandle2PoPs This, const char *const name);


// -----------------------------------------------------------------------------
// Metadatum: version
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PoPsVersionHas(ConstHandle2ConstPoPs This);

// +++ Get
// +++ Returns by value
extern_c const char *
PoPsVersionGet(ConstHandle2ConstPoPs This);

// +++ Set
extern_c void
PoPsVersionSet(ConstHandle2PoPs This, const char *const version);


// -----------------------------------------------------------------------------
// Metadatum: format
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PoPsFormatHas(ConstHandle2ConstPoPs This);

// +++ Get
// +++ Returns by value
extern_c const char *
PoPsFormatGet(ConstHandle2ConstPoPs This);

// +++ Set
extern_c void
PoPsFormatSet(ConstHandle2PoPs This, const char *const format);


// -----------------------------------------------------------------------------
// Child: styles
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PoPsStylesHas(ConstHandle2ConstPoPs This);

// --- Get, const
extern_c Handle2ConstStyles
PoPsStylesGetConst(ConstHandle2ConstPoPs This);

// +++ Get, non-const
extern_c Handle2Styles
PoPsStylesGet(ConstHandle2PoPs This);

// +++ Set
extern_c void
PoPsStylesSet(ConstHandle2PoPs This, ConstHandle2ConstStyles styles);


// -----------------------------------------------------------------------------
// Child: chemicalElements
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PoPsChemicalElementsHas(ConstHandle2ConstPoPs This);

// --- Get, const
extern_c Handle2ConstChemicalElements
PoPsChemicalElementsGetConst(ConstHandle2ConstPoPs This);

// +++ Get, non-const
extern_c Handle2ChemicalElements
PoPsChemicalElementsGet(ConstHandle2PoPs This);

// +++ Set
extern_c void
PoPsChemicalElementsSet(ConstHandle2PoPs This, ConstHandle2ConstChemicalElements chemicalElements);


// -----------------------------------------------------------------------------
// Child: aliases
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PoPsAliasesHas(ConstHandle2ConstPoPs This);

// --- Get, const
extern_c Handle2ConstAliases
PoPsAliasesGetConst(ConstHandle2ConstPoPs This);

// +++ Get, non-const
extern_c Handle2Aliases
PoPsAliasesGet(ConstHandle2PoPs This);

// +++ Set
extern_c void
PoPsAliasesSet(ConstHandle2PoPs This, ConstHandle2ConstAliases aliases);


// -----------------------------------------------------------------------------
// Child: baryons
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PoPsBaryonsHas(ConstHandle2ConstPoPs This);

// --- Get, const
extern_c Handle2ConstBaryons
PoPsBaryonsGetConst(ConstHandle2ConstPoPs This);

// +++ Get, non-const
extern_c Handle2Baryons
PoPsBaryonsGet(ConstHandle2PoPs This);

// +++ Set
extern_c void
PoPsBaryonsSet(ConstHandle2PoPs This, ConstHandle2ConstBaryons baryons);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/top/PoPs/src/custom.h"

#undef extern_c
#endif
