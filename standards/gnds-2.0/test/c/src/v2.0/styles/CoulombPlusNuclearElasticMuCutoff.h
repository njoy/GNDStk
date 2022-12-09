
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
// CoulombPlusNuclearElasticMuCutoff is the basic handle type in this file. Example:
//    // Create a default CoulombPlusNuclearElasticMuCutoff object:
//    CoulombPlusNuclearElasticMuCutoff handle = CoulombPlusNuclearElasticMuCutoffDefault();
// Functions involving CoulombPlusNuclearElasticMuCutoff are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_STYLES_COULOMBPLUSNUCLEARELASTICMUCUTOFF
#define C_INTERFACE_TEST_V2_0_STYLES_COULOMBPLUSNUCLEARELASTICMUCUTOFF

#include "GNDStk.h"
#include "v2.0/documentation/Documentation.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct CoulombPlusNuclearElasticMuCutoffClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ CoulombPlusNuclearElasticMuCutoff
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct CoulombPlusNuclearElasticMuCutoffClass *CoulombPlusNuclearElasticMuCutoff;

// --- Const-aware handles.
typedef const struct CoulombPlusNuclearElasticMuCutoffClass *const ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff;
typedef       struct CoulombPlusNuclearElasticMuCutoffClass *const ConstHandle2CoulombPlusNuclearElasticMuCutoff;
typedef const struct CoulombPlusNuclearElasticMuCutoffClass *      Handle2ConstCoulombPlusNuclearElasticMuCutoff;
typedef       struct CoulombPlusNuclearElasticMuCutoffClass *      Handle2CoulombPlusNuclearElasticMuCutoff;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstCoulombPlusNuclearElasticMuCutoff
CoulombPlusNuclearElasticMuCutoffDefaultConst();

// +++ Create, default
extern_c Handle2CoulombPlusNuclearElasticMuCutoff
CoulombPlusNuclearElasticMuCutoffDefault();

// --- Create, general, const
extern_c Handle2ConstCoulombPlusNuclearElasticMuCutoff
CoulombPlusNuclearElasticMuCutoffCreateConst(
   const char *const date,
   const XMLName derivedFrom,
   const XMLName label,
   const Float64 muCutoff,
   ConstHandle2ConstDocumentation documentation
);

// +++ Create, general
extern_c Handle2CoulombPlusNuclearElasticMuCutoff
CoulombPlusNuclearElasticMuCutoffCreate(
   const char *const date,
   const XMLName derivedFrom,
   const XMLName label,
   const Float64 muCutoff,
   ConstHandle2ConstDocumentation documentation
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
CoulombPlusNuclearElasticMuCutoffAssign(ConstHandle2CoulombPlusNuclearElasticMuCutoff This, ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
CoulombPlusNuclearElasticMuCutoffDelete(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
CoulombPlusNuclearElasticMuCutoffRead(ConstHandle2CoulombPlusNuclearElasticMuCutoff This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
CoulombPlusNuclearElasticMuCutoffWrite(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
CoulombPlusNuclearElasticMuCutoffPrint(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff This);

// +++ Print to standard output, as XML
extern_c int
CoulombPlusNuclearElasticMuCutoffPrintXML(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff This);

// +++ Print to standard output, as JSON
extern_c int
CoulombPlusNuclearElasticMuCutoffPrintJSON(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff This);


// -----------------------------------------------------------------------------
// Metadatum: date
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CoulombPlusNuclearElasticMuCutoffDateHas(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff This);

// +++ Get
// +++ Returns by value
extern_c const char *
CoulombPlusNuclearElasticMuCutoffDateGet(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff This);

// +++ Set
extern_c void
CoulombPlusNuclearElasticMuCutoffDateSet(ConstHandle2CoulombPlusNuclearElasticMuCutoff This, const char *const date);


// -----------------------------------------------------------------------------
// Metadatum: derivedFrom
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CoulombPlusNuclearElasticMuCutoffDerivedFromHas(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff This);

// +++ Get
// +++ Returns by value
extern_c XMLName
CoulombPlusNuclearElasticMuCutoffDerivedFromGet(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff This);

// +++ Set
extern_c void
CoulombPlusNuclearElasticMuCutoffDerivedFromSet(ConstHandle2CoulombPlusNuclearElasticMuCutoff This, const XMLName derivedFrom);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CoulombPlusNuclearElasticMuCutoffLabelHas(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff This);

// +++ Get
// +++ Returns by value
extern_c XMLName
CoulombPlusNuclearElasticMuCutoffLabelGet(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff This);

// +++ Set
extern_c void
CoulombPlusNuclearElasticMuCutoffLabelSet(ConstHandle2CoulombPlusNuclearElasticMuCutoff This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: muCutoff
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CoulombPlusNuclearElasticMuCutoffMuCutoffHas(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff This);

// +++ Get
// +++ Returns by value
extern_c Float64
CoulombPlusNuclearElasticMuCutoffMuCutoffGet(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff This);

// +++ Set
extern_c void
CoulombPlusNuclearElasticMuCutoffMuCutoffSet(ConstHandle2CoulombPlusNuclearElasticMuCutoff This, const Float64 muCutoff);


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CoulombPlusNuclearElasticMuCutoffDocumentationHas(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff This);

// --- Get, const
extern_c Handle2ConstDocumentation
CoulombPlusNuclearElasticMuCutoffDocumentationGetConst(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff This);

// +++ Get, non-const
extern_c Handle2Documentation
CoulombPlusNuclearElasticMuCutoffDocumentationGet(ConstHandle2CoulombPlusNuclearElasticMuCutoff This);

// +++ Set
extern_c void
CoulombPlusNuclearElasticMuCutoffDocumentationSet(ConstHandle2CoulombPlusNuclearElasticMuCutoff This, ConstHandle2ConstDocumentation documentation);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
