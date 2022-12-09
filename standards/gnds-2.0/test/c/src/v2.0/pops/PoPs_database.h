
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
// PoPs_database is the basic handle type in this file. Example:
//    // Create a default PoPs_database object:
//    PoPs_database handle = PoPs_databaseDefault();
// Functions involving PoPs_database are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_POPS_POPS_DATABASE
#define C_INTERFACE_TEST_V2_0_POPS_POPS_DATABASE

#include "GNDStk.h"
#include "v2.0/styles/Styles.h"
#include "v2.0/documentation/Documentation.h"
#include "v2.0/pops/Aliases.h"
#include "v2.0/pops/GaugeBosons.h"
#include "v2.0/pops/Leptons.h"
#include "v2.0/pops/Baryons.h"
#include "v2.0/pops/ChemicalElements.h"
#include "v2.0/pops/Unorthodoxes.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct PoPs_databaseClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ PoPs_database
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct PoPs_databaseClass *PoPs_database;

// --- Const-aware handles.
typedef const struct PoPs_databaseClass *const ConstHandle2ConstPoPs_database;
typedef       struct PoPs_databaseClass *const ConstHandle2PoPs_database;
typedef const struct PoPs_databaseClass *      Handle2ConstPoPs_database;
typedef       struct PoPs_databaseClass *      Handle2PoPs_database;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstPoPs_database
PoPs_databaseDefaultConst();

// +++ Create, default
extern_c Handle2PoPs_database
PoPs_databaseDefault();

// --- Create, general, const
extern_c Handle2ConstPoPs_database
PoPs_databaseCreateConst(
   const XMLName name,
   const XMLName version,
   const XMLName format,
   ConstHandle2ConstStyles styles,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstAliases aliases,
   ConstHandle2ConstGaugeBosons gaugeBosons,
   ConstHandle2ConstLeptons leptons,
   ConstHandle2ConstBaryons baryons,
   ConstHandle2ConstChemicalElements chemicalElements,
   ConstHandle2ConstUnorthodoxes unorthodoxes
);

// +++ Create, general
extern_c Handle2PoPs_database
PoPs_databaseCreate(
   const XMLName name,
   const XMLName version,
   const XMLName format,
   ConstHandle2ConstStyles styles,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstAliases aliases,
   ConstHandle2ConstGaugeBosons gaugeBosons,
   ConstHandle2ConstLeptons leptons,
   ConstHandle2ConstBaryons baryons,
   ConstHandle2ConstChemicalElements chemicalElements,
   ConstHandle2ConstUnorthodoxes unorthodoxes
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
PoPs_databaseAssign(ConstHandle2PoPs_database This, ConstHandle2ConstPoPs_database from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
PoPs_databaseDelete(ConstHandle2ConstPoPs_database This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
PoPs_databaseRead(ConstHandle2PoPs_database This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
PoPs_databaseWrite(ConstHandle2ConstPoPs_database This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
PoPs_databasePrint(ConstHandle2ConstPoPs_database This);

// +++ Print to standard output, as XML
extern_c int
PoPs_databasePrintXML(ConstHandle2ConstPoPs_database This);

// +++ Print to standard output, as JSON
extern_c int
PoPs_databasePrintJSON(ConstHandle2ConstPoPs_database This);


// -----------------------------------------------------------------------------
// Metadatum: name
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PoPs_databaseNameHas(ConstHandle2ConstPoPs_database This);

// +++ Get
// +++ Returns by value
extern_c XMLName
PoPs_databaseNameGet(ConstHandle2ConstPoPs_database This);

// +++ Set
extern_c void
PoPs_databaseNameSet(ConstHandle2PoPs_database This, const XMLName name);


// -----------------------------------------------------------------------------
// Metadatum: version
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PoPs_databaseVersionHas(ConstHandle2ConstPoPs_database This);

// +++ Get
// +++ Returns by value
extern_c XMLName
PoPs_databaseVersionGet(ConstHandle2ConstPoPs_database This);

// +++ Set
extern_c void
PoPs_databaseVersionSet(ConstHandle2PoPs_database This, const XMLName version);


// -----------------------------------------------------------------------------
// Metadatum: format
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PoPs_databaseFormatHas(ConstHandle2ConstPoPs_database This);

// +++ Get
// +++ Returns by value
extern_c XMLName
PoPs_databaseFormatGet(ConstHandle2ConstPoPs_database This);

// +++ Set
extern_c void
PoPs_databaseFormatSet(ConstHandle2PoPs_database This, const XMLName format);


// -----------------------------------------------------------------------------
// Child: styles
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PoPs_databaseStylesHas(ConstHandle2ConstPoPs_database This);

// --- Get, const
extern_c Handle2ConstStyles
PoPs_databaseStylesGetConst(ConstHandle2ConstPoPs_database This);

// +++ Get, non-const
extern_c Handle2Styles
PoPs_databaseStylesGet(ConstHandle2PoPs_database This);

// +++ Set
extern_c void
PoPs_databaseStylesSet(ConstHandle2PoPs_database This, ConstHandle2ConstStyles styles);


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PoPs_databaseDocumentationHas(ConstHandle2ConstPoPs_database This);

// --- Get, const
extern_c Handle2ConstDocumentation
PoPs_databaseDocumentationGetConst(ConstHandle2ConstPoPs_database This);

// +++ Get, non-const
extern_c Handle2Documentation
PoPs_databaseDocumentationGet(ConstHandle2PoPs_database This);

// +++ Set
extern_c void
PoPs_databaseDocumentationSet(ConstHandle2PoPs_database This, ConstHandle2ConstDocumentation documentation);


// -----------------------------------------------------------------------------
// Child: aliases
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PoPs_databaseAliasesHas(ConstHandle2ConstPoPs_database This);

// --- Get, const
extern_c Handle2ConstAliases
PoPs_databaseAliasesGetConst(ConstHandle2ConstPoPs_database This);

// +++ Get, non-const
extern_c Handle2Aliases
PoPs_databaseAliasesGet(ConstHandle2PoPs_database This);

// +++ Set
extern_c void
PoPs_databaseAliasesSet(ConstHandle2PoPs_database This, ConstHandle2ConstAliases aliases);


// -----------------------------------------------------------------------------
// Child: gaugeBosons
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PoPs_databaseGaugeBosonsHas(ConstHandle2ConstPoPs_database This);

// --- Get, const
extern_c Handle2ConstGaugeBosons
PoPs_databaseGaugeBosonsGetConst(ConstHandle2ConstPoPs_database This);

// +++ Get, non-const
extern_c Handle2GaugeBosons
PoPs_databaseGaugeBosonsGet(ConstHandle2PoPs_database This);

// +++ Set
extern_c void
PoPs_databaseGaugeBosonsSet(ConstHandle2PoPs_database This, ConstHandle2ConstGaugeBosons gaugeBosons);


// -----------------------------------------------------------------------------
// Child: leptons
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PoPs_databaseLeptonsHas(ConstHandle2ConstPoPs_database This);

// --- Get, const
extern_c Handle2ConstLeptons
PoPs_databaseLeptonsGetConst(ConstHandle2ConstPoPs_database This);

// +++ Get, non-const
extern_c Handle2Leptons
PoPs_databaseLeptonsGet(ConstHandle2PoPs_database This);

// +++ Set
extern_c void
PoPs_databaseLeptonsSet(ConstHandle2PoPs_database This, ConstHandle2ConstLeptons leptons);


// -----------------------------------------------------------------------------
// Child: baryons
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PoPs_databaseBaryonsHas(ConstHandle2ConstPoPs_database This);

// --- Get, const
extern_c Handle2ConstBaryons
PoPs_databaseBaryonsGetConst(ConstHandle2ConstPoPs_database This);

// +++ Get, non-const
extern_c Handle2Baryons
PoPs_databaseBaryonsGet(ConstHandle2PoPs_database This);

// +++ Set
extern_c void
PoPs_databaseBaryonsSet(ConstHandle2PoPs_database This, ConstHandle2ConstBaryons baryons);


// -----------------------------------------------------------------------------
// Child: chemicalElements
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PoPs_databaseChemicalElementsHas(ConstHandle2ConstPoPs_database This);

// --- Get, const
extern_c Handle2ConstChemicalElements
PoPs_databaseChemicalElementsGetConst(ConstHandle2ConstPoPs_database This);

// +++ Get, non-const
extern_c Handle2ChemicalElements
PoPs_databaseChemicalElementsGet(ConstHandle2PoPs_database This);

// +++ Set
extern_c void
PoPs_databaseChemicalElementsSet(ConstHandle2PoPs_database This, ConstHandle2ConstChemicalElements chemicalElements);


// -----------------------------------------------------------------------------
// Child: unorthodoxes
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PoPs_databaseUnorthodoxesHas(ConstHandle2ConstPoPs_database This);

// --- Get, const
extern_c Handle2ConstUnorthodoxes
PoPs_databaseUnorthodoxesGetConst(ConstHandle2ConstPoPs_database This);

// +++ Get, non-const
extern_c Handle2Unorthodoxes
PoPs_databaseUnorthodoxesGet(ConstHandle2PoPs_database This);

// +++ Set
extern_c void
PoPs_databaseUnorthodoxesSet(ConstHandle2PoPs_database This, ConstHandle2ConstUnorthodoxes unorthodoxes);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
