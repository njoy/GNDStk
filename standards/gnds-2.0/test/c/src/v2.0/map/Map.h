
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
// Map is the basic handle type in this file. Example:
//    // Create a default Map object:
//    Map handle = MapDefault();
// Functions involving Map are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_MAP_MAP
#define C_INTERFACE_TEST_V2_0_MAP_MAP

#include "GNDStk.h"
#include "v2.0/map/Import.h"
#include "v2.0/map/Protare.h"
#include "v2.0/map/TNSL.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct MapClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Map
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct MapClass *Map;

// --- Const-aware handles.
typedef const struct MapClass *const ConstHandle2ConstMap;
typedef       struct MapClass *const ConstHandle2Map;
typedef const struct MapClass *      Handle2ConstMap;
typedef       struct MapClass *      Handle2Map;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstMap
MapDefaultConst();

// +++ Create, default
extern_c Handle2Map
MapDefault();

// --- Create, general, const
extern_c Handle2ConstMap
MapCreateConst(
   const XMLName library,
   const XMLName format,
   const char *const checksum,
   const enums::HashAlgorithm algorithm,
   ConstHandle2Import *const import, const size_t importSize,
   ConstHandle2Protare *const protare, const size_t protareSize,
   ConstHandle2TNSL *const TNSL, const size_t TNSLSize
);

// +++ Create, general
extern_c Handle2Map
MapCreate(
   const XMLName library,
   const XMLName format,
   const char *const checksum,
   const enums::HashAlgorithm algorithm,
   ConstHandle2Import *const import, const size_t importSize,
   ConstHandle2Protare *const protare, const size_t protareSize,
   ConstHandle2TNSL *const TNSL, const size_t TNSLSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
MapAssign(ConstHandle2Map This, ConstHandle2ConstMap from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
MapDelete(ConstHandle2ConstMap This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
MapRead(ConstHandle2Map This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
MapWrite(ConstHandle2ConstMap This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
MapPrint(ConstHandle2ConstMap This);

// +++ Print to standard output, as XML
extern_c int
MapPrintXML(ConstHandle2ConstMap This);

// +++ Print to standard output, as JSON
extern_c int
MapPrintJSON(ConstHandle2ConstMap This);


// -----------------------------------------------------------------------------
// Metadatum: library
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MapLibraryHas(ConstHandle2ConstMap This);

// +++ Get
// +++ Returns by value
extern_c XMLName
MapLibraryGet(ConstHandle2ConstMap This);

// +++ Set
extern_c void
MapLibrarySet(ConstHandle2Map This, const XMLName library);


// -----------------------------------------------------------------------------
// Metadatum: format
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MapFormatHas(ConstHandle2ConstMap This);

// +++ Get
// +++ Returns by value
extern_c XMLName
MapFormatGet(ConstHandle2ConstMap This);

// +++ Set
extern_c void
MapFormatSet(ConstHandle2Map This, const XMLName format);


// -----------------------------------------------------------------------------
// Metadatum: checksum
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MapChecksumHas(ConstHandle2ConstMap This);

// +++ Get
// +++ Returns by value
extern_c const char *
MapChecksumGet(ConstHandle2ConstMap This);

// +++ Set
extern_c void
MapChecksumSet(ConstHandle2Map This, const char *const checksum);


// -----------------------------------------------------------------------------
// Metadatum: algorithm
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MapAlgorithmHas(ConstHandle2ConstMap This);

// +++ Get
// +++ Returns by value
extern_c enums::HashAlgorithm
MapAlgorithmGet(ConstHandle2ConstMap This);

// +++ Set
extern_c void
MapAlgorithmSet(ConstHandle2Map This, const enums::HashAlgorithm algorithm);


// -----------------------------------------------------------------------------
// Child: import
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MapImportHas(ConstHandle2ConstMap This);

// +++ Clear
extern_c void
MapImportClear(ConstHandle2Map This);

// +++ Size
extern_c size_t
MapImportSize(ConstHandle2ConstMap This);

// +++ Add
extern_c void
MapImportAdd(ConstHandle2Map This, ConstHandle2ConstImport import);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstImport
MapImportGetConst(ConstHandle2ConstMap This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Import
MapImportGet(ConstHandle2Map This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
MapImportSet(
   ConstHandle2Map This,
   const size_t index_,
   ConstHandle2ConstImport import
);

// +++ Has, by path
extern_c int
MapImportHasByPath(
   ConstHandle2ConstMap This,
   const XMLName path
);

// --- Get, by path, const
extern_c Handle2ConstImport
MapImportGetByPathConst(
   ConstHandle2ConstMap This,
   const XMLName path
);

// +++ Get, by path, non-const
extern_c Handle2Import
MapImportGetByPath(
   ConstHandle2Map This,
   const XMLName path
);

// +++ Set, by path
extern_c void
MapImportSetByPath(
   ConstHandle2Map This,
   const XMLName path,
   ConstHandle2ConstImport import
);

// +++ Has, by checksum
extern_c int
MapImportHasByChecksum(
   ConstHandle2ConstMap This,
   const char *const checksum
);

// --- Get, by checksum, const
extern_c Handle2ConstImport
MapImportGetByChecksumConst(
   ConstHandle2ConstMap This,
   const char *const checksum
);

// +++ Get, by checksum, non-const
extern_c Handle2Import
MapImportGetByChecksum(
   ConstHandle2Map This,
   const char *const checksum
);

// +++ Set, by checksum
extern_c void
MapImportSetByChecksum(
   ConstHandle2Map This,
   const char *const checksum,
   ConstHandle2ConstImport import
);

// +++ Has, by algorithm
extern_c int
MapImportHasByAlgorithm(
   ConstHandle2ConstMap This,
   const enums::HashAlgorithm algorithm
);

// --- Get, by algorithm, const
extern_c Handle2ConstImport
MapImportGetByAlgorithmConst(
   ConstHandle2ConstMap This,
   const enums::HashAlgorithm algorithm
);

// +++ Get, by algorithm, non-const
extern_c Handle2Import
MapImportGetByAlgorithm(
   ConstHandle2Map This,
   const enums::HashAlgorithm algorithm
);

// +++ Set, by algorithm
extern_c void
MapImportSetByAlgorithm(
   ConstHandle2Map This,
   const enums::HashAlgorithm algorithm,
   ConstHandle2ConstImport import
);


// -----------------------------------------------------------------------------
// Child: protare
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MapProtareHas(ConstHandle2ConstMap This);

// +++ Clear
extern_c void
MapProtareClear(ConstHandle2Map This);

// +++ Size
extern_c size_t
MapProtareSize(ConstHandle2ConstMap This);

// +++ Add
extern_c void
MapProtareAdd(ConstHandle2Map This, ConstHandle2ConstProtare protare);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstProtare
MapProtareGetConst(ConstHandle2ConstMap This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Protare
MapProtareGet(ConstHandle2Map This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
MapProtareSet(
   ConstHandle2Map This,
   const size_t index_,
   ConstHandle2ConstProtare protare
);

// +++ Has, by projectile
extern_c int
MapProtareHasByProjectile(
   ConstHandle2ConstMap This,
   const XMLName projectile
);

// --- Get, by projectile, const
extern_c Handle2ConstProtare
MapProtareGetByProjectileConst(
   ConstHandle2ConstMap This,
   const XMLName projectile
);

// +++ Get, by projectile, non-const
extern_c Handle2Protare
MapProtareGetByProjectile(
   ConstHandle2Map This,
   const XMLName projectile
);

// +++ Set, by projectile
extern_c void
MapProtareSetByProjectile(
   ConstHandle2Map This,
   const XMLName projectile,
   ConstHandle2ConstProtare protare
);

// +++ Has, by target
extern_c int
MapProtareHasByTarget(
   ConstHandle2ConstMap This,
   const XMLName target
);

// --- Get, by target, const
extern_c Handle2ConstProtare
MapProtareGetByTargetConst(
   ConstHandle2ConstMap This,
   const XMLName target
);

// +++ Get, by target, non-const
extern_c Handle2Protare
MapProtareGetByTarget(
   ConstHandle2Map This,
   const XMLName target
);

// +++ Set, by target
extern_c void
MapProtareSetByTarget(
   ConstHandle2Map This,
   const XMLName target,
   ConstHandle2ConstProtare protare
);

// +++ Has, by evaluation
extern_c int
MapProtareHasByEvaluation(
   ConstHandle2ConstMap This,
   const XMLName evaluation
);

// --- Get, by evaluation, const
extern_c Handle2ConstProtare
MapProtareGetByEvaluationConst(
   ConstHandle2ConstMap This,
   const XMLName evaluation
);

// +++ Get, by evaluation, non-const
extern_c Handle2Protare
MapProtareGetByEvaluation(
   ConstHandle2Map This,
   const XMLName evaluation
);

// +++ Set, by evaluation
extern_c void
MapProtareSetByEvaluation(
   ConstHandle2Map This,
   const XMLName evaluation,
   ConstHandle2ConstProtare protare
);

// +++ Has, by path
extern_c int
MapProtareHasByPath(
   ConstHandle2ConstMap This,
   const XMLName path
);

// --- Get, by path, const
extern_c Handle2ConstProtare
MapProtareGetByPathConst(
   ConstHandle2ConstMap This,
   const XMLName path
);

// +++ Get, by path, non-const
extern_c Handle2Protare
MapProtareGetByPath(
   ConstHandle2Map This,
   const XMLName path
);

// +++ Set, by path
extern_c void
MapProtareSetByPath(
   ConstHandle2Map This,
   const XMLName path,
   ConstHandle2ConstProtare protare
);

// +++ Has, by interaction
extern_c int
MapProtareHasByInteraction(
   ConstHandle2ConstMap This,
   const XMLName interaction
);

// --- Get, by interaction, const
extern_c Handle2ConstProtare
MapProtareGetByInteractionConst(
   ConstHandle2ConstMap This,
   const XMLName interaction
);

// +++ Get, by interaction, non-const
extern_c Handle2Protare
MapProtareGetByInteraction(
   ConstHandle2Map This,
   const XMLName interaction
);

// +++ Set, by interaction
extern_c void
MapProtareSetByInteraction(
   ConstHandle2Map This,
   const XMLName interaction,
   ConstHandle2ConstProtare protare
);

// +++ Has, by checksum
extern_c int
MapProtareHasByChecksum(
   ConstHandle2ConstMap This,
   const char *const checksum
);

// --- Get, by checksum, const
extern_c Handle2ConstProtare
MapProtareGetByChecksumConst(
   ConstHandle2ConstMap This,
   const char *const checksum
);

// +++ Get, by checksum, non-const
extern_c Handle2Protare
MapProtareGetByChecksum(
   ConstHandle2Map This,
   const char *const checksum
);

// +++ Set, by checksum
extern_c void
MapProtareSetByChecksum(
   ConstHandle2Map This,
   const char *const checksum,
   ConstHandle2ConstProtare protare
);

// +++ Has, by algorithm
extern_c int
MapProtareHasByAlgorithm(
   ConstHandle2ConstMap This,
   const enums::HashAlgorithm algorithm
);

// --- Get, by algorithm, const
extern_c Handle2ConstProtare
MapProtareGetByAlgorithmConst(
   ConstHandle2ConstMap This,
   const enums::HashAlgorithm algorithm
);

// +++ Get, by algorithm, non-const
extern_c Handle2Protare
MapProtareGetByAlgorithm(
   ConstHandle2Map This,
   const enums::HashAlgorithm algorithm
);

// +++ Set, by algorithm
extern_c void
MapProtareSetByAlgorithm(
   ConstHandle2Map This,
   const enums::HashAlgorithm algorithm,
   ConstHandle2ConstProtare protare
);


// -----------------------------------------------------------------------------
// Child: TNSL
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MapTNSLHas(ConstHandle2ConstMap This);

// +++ Clear
extern_c void
MapTNSLClear(ConstHandle2Map This);

// +++ Size
extern_c size_t
MapTNSLSize(ConstHandle2ConstMap This);

// +++ Add
extern_c void
MapTNSLAdd(ConstHandle2Map This, ConstHandle2ConstTNSL TNSL);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstTNSL
MapTNSLGetConst(ConstHandle2ConstMap This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2TNSL
MapTNSLGet(ConstHandle2Map This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
MapTNSLSet(
   ConstHandle2Map This,
   const size_t index_,
   ConstHandle2ConstTNSL TNSL
);

// +++ Has, by projectile
extern_c int
MapTNSLHasByProjectile(
   ConstHandle2ConstMap This,
   const XMLName projectile
);

// --- Get, by projectile, const
extern_c Handle2ConstTNSL
MapTNSLGetByProjectileConst(
   ConstHandle2ConstMap This,
   const XMLName projectile
);

// +++ Get, by projectile, non-const
extern_c Handle2TNSL
MapTNSLGetByProjectile(
   ConstHandle2Map This,
   const XMLName projectile
);

// +++ Set, by projectile
extern_c void
MapTNSLSetByProjectile(
   ConstHandle2Map This,
   const XMLName projectile,
   ConstHandle2ConstTNSL TNSL
);

// +++ Has, by target
extern_c int
MapTNSLHasByTarget(
   ConstHandle2ConstMap This,
   const XMLName target
);

// --- Get, by target, const
extern_c Handle2ConstTNSL
MapTNSLGetByTargetConst(
   ConstHandle2ConstMap This,
   const XMLName target
);

// +++ Get, by target, non-const
extern_c Handle2TNSL
MapTNSLGetByTarget(
   ConstHandle2Map This,
   const XMLName target
);

// +++ Set, by target
extern_c void
MapTNSLSetByTarget(
   ConstHandle2Map This,
   const XMLName target,
   ConstHandle2ConstTNSL TNSL
);

// +++ Has, by evaluation
extern_c int
MapTNSLHasByEvaluation(
   ConstHandle2ConstMap This,
   const XMLName evaluation
);

// --- Get, by evaluation, const
extern_c Handle2ConstTNSL
MapTNSLGetByEvaluationConst(
   ConstHandle2ConstMap This,
   const XMLName evaluation
);

// +++ Get, by evaluation, non-const
extern_c Handle2TNSL
MapTNSLGetByEvaluation(
   ConstHandle2Map This,
   const XMLName evaluation
);

// +++ Set, by evaluation
extern_c void
MapTNSLSetByEvaluation(
   ConstHandle2Map This,
   const XMLName evaluation,
   ConstHandle2ConstTNSL TNSL
);

// +++ Has, by path
extern_c int
MapTNSLHasByPath(
   ConstHandle2ConstMap This,
   const XMLName path
);

// --- Get, by path, const
extern_c Handle2ConstTNSL
MapTNSLGetByPathConst(
   ConstHandle2ConstMap This,
   const XMLName path
);

// +++ Get, by path, non-const
extern_c Handle2TNSL
MapTNSLGetByPath(
   ConstHandle2Map This,
   const XMLName path
);

// +++ Set, by path
extern_c void
MapTNSLSetByPath(
   ConstHandle2Map This,
   const XMLName path,
   ConstHandle2ConstTNSL TNSL
);

// +++ Has, by interaction
extern_c int
MapTNSLHasByInteraction(
   ConstHandle2ConstMap This,
   const XMLName interaction
);

// --- Get, by interaction, const
extern_c Handle2ConstTNSL
MapTNSLGetByInteractionConst(
   ConstHandle2ConstMap This,
   const XMLName interaction
);

// +++ Get, by interaction, non-const
extern_c Handle2TNSL
MapTNSLGetByInteraction(
   ConstHandle2Map This,
   const XMLName interaction
);

// +++ Set, by interaction
extern_c void
MapTNSLSetByInteraction(
   ConstHandle2Map This,
   const XMLName interaction,
   ConstHandle2ConstTNSL TNSL
);

// +++ Has, by checksum
extern_c int
MapTNSLHasByChecksum(
   ConstHandle2ConstMap This,
   const char *const checksum
);

// --- Get, by checksum, const
extern_c Handle2ConstTNSL
MapTNSLGetByChecksumConst(
   ConstHandle2ConstMap This,
   const char *const checksum
);

// +++ Get, by checksum, non-const
extern_c Handle2TNSL
MapTNSLGetByChecksum(
   ConstHandle2Map This,
   const char *const checksum
);

// +++ Set, by checksum
extern_c void
MapTNSLSetByChecksum(
   ConstHandle2Map This,
   const char *const checksum,
   ConstHandle2ConstTNSL TNSL
);

// +++ Has, by algorithm
extern_c int
MapTNSLHasByAlgorithm(
   ConstHandle2ConstMap This,
   const enums::HashAlgorithm algorithm
);

// --- Get, by algorithm, const
extern_c Handle2ConstTNSL
MapTNSLGetByAlgorithmConst(
   ConstHandle2ConstMap This,
   const enums::HashAlgorithm algorithm
);

// +++ Get, by algorithm, non-const
extern_c Handle2TNSL
MapTNSLGetByAlgorithm(
   ConstHandle2Map This,
   const enums::HashAlgorithm algorithm
);

// +++ Set, by algorithm
extern_c void
MapTNSLSetByAlgorithm(
   ConstHandle2Map This,
   const enums::HashAlgorithm algorithm,
   ConstHandle2ConstTNSL TNSL
);

// +++ Has, by standardTarget
extern_c int
MapTNSLHasByStandardTarget(
   ConstHandle2ConstMap This,
   const XMLName standardTarget
);

// --- Get, by standardTarget, const
extern_c Handle2ConstTNSL
MapTNSLGetByStandardTargetConst(
   ConstHandle2ConstMap This,
   const XMLName standardTarget
);

// +++ Get, by standardTarget, non-const
extern_c Handle2TNSL
MapTNSLGetByStandardTarget(
   ConstHandle2Map This,
   const XMLName standardTarget
);

// +++ Set, by standardTarget
extern_c void
MapTNSLSetByStandardTarget(
   ConstHandle2Map This,
   const XMLName standardTarget,
   ConstHandle2ConstTNSL TNSL
);

// +++ Has, by standardEvaluation
extern_c int
MapTNSLHasByStandardEvaluation(
   ConstHandle2ConstMap This,
   const XMLName standardEvaluation
);

// --- Get, by standardEvaluation, const
extern_c Handle2ConstTNSL
MapTNSLGetByStandardEvaluationConst(
   ConstHandle2ConstMap This,
   const XMLName standardEvaluation
);

// +++ Get, by standardEvaluation, non-const
extern_c Handle2TNSL
MapTNSLGetByStandardEvaluation(
   ConstHandle2Map This,
   const XMLName standardEvaluation
);

// +++ Set, by standardEvaluation
extern_c void
MapTNSLSetByStandardEvaluation(
   ConstHandle2Map This,
   const XMLName standardEvaluation,
   ConstHandle2ConstTNSL TNSL
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
