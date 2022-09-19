
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
// TNSL is the basic handle type in this file. Example:
//    // Create a default TNSL object:
//    TNSL handle = TNSLDefault();
// Functions involving TNSL are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_MAP_TNSL
#define C_INTERFACE_TEST_V2_0_MAP_TNSL

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct TNSLClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ TNSL
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct TNSLClass *TNSL;

// --- Const-aware handles.
typedef const struct TNSLClass *const ConstHandle2ConstTNSL;
typedef       struct TNSLClass *const ConstHandle2TNSL;
typedef const struct TNSLClass *      Handle2ConstTNSL;
typedef       struct TNSLClass *      Handle2TNSL;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstTNSL
TNSLDefaultConst();

// +++ Create, default
extern_c Handle2TNSL
TNSLDefault();

// --- Create, general, const
extern_c Handle2ConstTNSL
TNSLCreateConst(
   const XMLName projectile,
   const XMLName target,
   const XMLName evaluation,
   const XMLName path,
   const XMLName interaction,
   const char *const checksum,
   const enums::HashAlgorithm algorithm,
   const XMLName standardTarget,
   const XMLName standardEvaluation
);

// +++ Create, general
extern_c Handle2TNSL
TNSLCreate(
   const XMLName projectile,
   const XMLName target,
   const XMLName evaluation,
   const XMLName path,
   const XMLName interaction,
   const char *const checksum,
   const enums::HashAlgorithm algorithm,
   const XMLName standardTarget,
   const XMLName standardEvaluation
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
TNSLAssign(ConstHandle2TNSL This, ConstHandle2ConstTNSL from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
TNSLDelete(ConstHandle2ConstTNSL This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
TNSLRead(ConstHandle2TNSL This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
TNSLWrite(ConstHandle2ConstTNSL This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
TNSLPrint(ConstHandle2ConstTNSL This);

// +++ Print to standard output, as XML
extern_c int
TNSLPrintXML(ConstHandle2ConstTNSL This);

// +++ Print to standard output, as JSON
extern_c int
TNSLPrintJSON(ConstHandle2ConstTNSL This);


// -----------------------------------------------------------------------------
// Metadatum: projectile
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TNSLProjectileHas(ConstHandle2ConstTNSL This);

// +++ Get
// +++ Returns by value
extern_c XMLName
TNSLProjectileGet(ConstHandle2ConstTNSL This);

// +++ Set
extern_c void
TNSLProjectileSet(ConstHandle2TNSL This, const XMLName projectile);


// -----------------------------------------------------------------------------
// Metadatum: target
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TNSLTargetHas(ConstHandle2ConstTNSL This);

// +++ Get
// +++ Returns by value
extern_c XMLName
TNSLTargetGet(ConstHandle2ConstTNSL This);

// +++ Set
extern_c void
TNSLTargetSet(ConstHandle2TNSL This, const XMLName target);


// -----------------------------------------------------------------------------
// Metadatum: evaluation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TNSLEvaluationHas(ConstHandle2ConstTNSL This);

// +++ Get
// +++ Returns by value
extern_c XMLName
TNSLEvaluationGet(ConstHandle2ConstTNSL This);

// +++ Set
extern_c void
TNSLEvaluationSet(ConstHandle2TNSL This, const XMLName evaluation);


// -----------------------------------------------------------------------------
// Metadatum: path
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TNSLPathHas(ConstHandle2ConstTNSL This);

// +++ Get
// +++ Returns by value
extern_c XMLName
TNSLPathGet(ConstHandle2ConstTNSL This);

// +++ Set
extern_c void
TNSLPathSet(ConstHandle2TNSL This, const XMLName path);


// -----------------------------------------------------------------------------
// Metadatum: interaction
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TNSLInteractionHas(ConstHandle2ConstTNSL This);

// +++ Get
// +++ Returns by value
extern_c XMLName
TNSLInteractionGet(ConstHandle2ConstTNSL This);

// +++ Set
extern_c void
TNSLInteractionSet(ConstHandle2TNSL This, const XMLName interaction);


// -----------------------------------------------------------------------------
// Metadatum: checksum
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TNSLChecksumHas(ConstHandle2ConstTNSL This);

// +++ Get
// +++ Returns by value
extern_c const char *
TNSLChecksumGet(ConstHandle2ConstTNSL This);

// +++ Set
extern_c void
TNSLChecksumSet(ConstHandle2TNSL This, const char *const checksum);


// -----------------------------------------------------------------------------
// Metadatum: algorithm
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TNSLAlgorithmHas(ConstHandle2ConstTNSL This);

// +++ Get
// +++ Returns by value
extern_c enums::HashAlgorithm
TNSLAlgorithmGet(ConstHandle2ConstTNSL This);

// +++ Set
extern_c void
TNSLAlgorithmSet(ConstHandle2TNSL This, const enums::HashAlgorithm algorithm);


// -----------------------------------------------------------------------------
// Metadatum: standardTarget
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TNSLStandardTargetHas(ConstHandle2ConstTNSL This);

// +++ Get
// +++ Returns by value
extern_c XMLName
TNSLStandardTargetGet(ConstHandle2ConstTNSL This);

// +++ Set
extern_c void
TNSLStandardTargetSet(ConstHandle2TNSL This, const XMLName standardTarget);


// -----------------------------------------------------------------------------
// Metadatum: standardEvaluation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TNSLStandardEvaluationHas(ConstHandle2ConstTNSL This);

// +++ Get
// +++ Returns by value
extern_c XMLName
TNSLStandardEvaluationGet(ConstHandle2ConstTNSL This);

// +++ Set
extern_c void
TNSLStandardEvaluationSet(ConstHandle2TNSL This, const XMLName standardEvaluation);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
