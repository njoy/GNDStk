
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
// ReactionSuite is the basic handle type in this file. Example:
//    // Create a default ReactionSuite object:
//    ReactionSuite handle = ReactionSuiteDefault();
// Functions involving ReactionSuite are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_TOP_REACTIONSUITE
#define C_INTERFACE_GNDS_V2_0_TOP_REACTIONSUITE

#include "GNDStk.h"
#include "v2.0/general/Styles.h"
#include "v2.0/top/PoPs.h"
#include "v2.0/general/Reactions.h"
#include "v2.0/general/ApplicationData.h"
#include "v2.0/general/ExternalFiles.h"
#include "v2.0/general/Resonances.h"
#include "v2.0/general/Sums.h"
#include "v2.0/general/Productions.h"
#include "v2.0/general/FissionComponents.h"
#include "v2.0/general/OrphanProducts.h"
#include "v2.0/general/IncompleteReactions.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ReactionSuiteClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ReactionSuite
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ReactionSuiteClass *ReactionSuite;

// --- Const-aware handles.
typedef const struct ReactionSuiteClass *const ConstHandle2ConstReactionSuite;
typedef       struct ReactionSuiteClass *const ConstHandle2ReactionSuite;
typedef const struct ReactionSuiteClass *      Handle2ConstReactionSuite;
typedef       struct ReactionSuiteClass *      Handle2ReactionSuite;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstReactionSuite
ReactionSuiteDefaultConst();

// +++ Create, default
extern_c Handle2ReactionSuite
ReactionSuiteDefault();

// --- Create, general, const
extern_c Handle2ConstReactionSuite
ReactionSuiteCreateConst(
   const char *const projectile,
   const char *const target,
   const char *const evaluation,
   const char *const format,
   const char *const projectileFrame,
   const char *const interaction,
   ConstHandle2ConstStyles styles,
   ConstHandle2ConstPoPs PoPs,
   ConstHandle2ConstReactions reactions,
   ConstHandle2ConstApplicationData applicationData,
   ConstHandle2ConstExternalFiles externalFiles,
   ConstHandle2ConstResonances resonances,
   ConstHandle2ConstSums sums,
   ConstHandle2ConstProductions productions,
   ConstHandle2ConstFissionComponents fissionComponents,
   ConstHandle2ConstOrphanProducts orphanProducts,
   ConstHandle2ConstIncompleteReactions incompleteReactions
);

// +++ Create, general
extern_c Handle2ReactionSuite
ReactionSuiteCreate(
   const char *const projectile,
   const char *const target,
   const char *const evaluation,
   const char *const format,
   const char *const projectileFrame,
   const char *const interaction,
   ConstHandle2ConstStyles styles,
   ConstHandle2ConstPoPs PoPs,
   ConstHandle2ConstReactions reactions,
   ConstHandle2ConstApplicationData applicationData,
   ConstHandle2ConstExternalFiles externalFiles,
   ConstHandle2ConstResonances resonances,
   ConstHandle2ConstSums sums,
   ConstHandle2ConstProductions productions,
   ConstHandle2ConstFissionComponents fissionComponents,
   ConstHandle2ConstOrphanProducts orphanProducts,
   ConstHandle2ConstIncompleteReactions incompleteReactions
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ReactionSuiteAssign(ConstHandle2ReactionSuite self, ConstHandle2ConstReactionSuite from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ReactionSuiteDelete(ConstHandle2ConstReactionSuite self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ReactionSuiteRead(ConstHandle2ReactionSuite self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ReactionSuiteWrite(ConstHandle2ConstReactionSuite self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ReactionSuitePrint(ConstHandle2ConstReactionSuite self);

// +++ Print to standard output, as XML
extern_c int
ReactionSuitePrintXML(ConstHandle2ConstReactionSuite self);

// +++ Print to standard output, as JSON
extern_c int
ReactionSuitePrintJSON(ConstHandle2ConstReactionSuite self);


// -----------------------------------------------------------------------------
// Metadatum: projectile
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionSuiteProjectileHas(ConstHandle2ConstReactionSuite self);

// +++ Get
// +++ Returns by value
extern_c const char *
ReactionSuiteProjectileGet(ConstHandle2ConstReactionSuite self);

// +++ Set
extern_c void
ReactionSuiteProjectileSet(ConstHandle2ReactionSuite self, const char *const projectile);


// -----------------------------------------------------------------------------
// Metadatum: target
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionSuiteTargetHas(ConstHandle2ConstReactionSuite self);

// +++ Get
// +++ Returns by value
extern_c const char *
ReactionSuiteTargetGet(ConstHandle2ConstReactionSuite self);

// +++ Set
extern_c void
ReactionSuiteTargetSet(ConstHandle2ReactionSuite self, const char *const target);


// -----------------------------------------------------------------------------
// Metadatum: evaluation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionSuiteEvaluationHas(ConstHandle2ConstReactionSuite self);

// +++ Get
// +++ Returns by value
extern_c const char *
ReactionSuiteEvaluationGet(ConstHandle2ConstReactionSuite self);

// +++ Set
extern_c void
ReactionSuiteEvaluationSet(ConstHandle2ReactionSuite self, const char *const evaluation);


// -----------------------------------------------------------------------------
// Metadatum: format
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionSuiteFormatHas(ConstHandle2ConstReactionSuite self);

// +++ Get
// +++ Returns by value
extern_c const char *
ReactionSuiteFormatGet(ConstHandle2ConstReactionSuite self);

// +++ Set
extern_c void
ReactionSuiteFormatSet(ConstHandle2ReactionSuite self, const char *const format);


// -----------------------------------------------------------------------------
// Metadatum: projectileFrame
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionSuiteProjectileFrameHas(ConstHandle2ConstReactionSuite self);

// +++ Get
// +++ Returns by value
extern_c const char *
ReactionSuiteProjectileFrameGet(ConstHandle2ConstReactionSuite self);

// +++ Set
extern_c void
ReactionSuiteProjectileFrameSet(ConstHandle2ReactionSuite self, const char *const projectileFrame);


// -----------------------------------------------------------------------------
// Metadatum: interaction
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionSuiteInteractionHas(ConstHandle2ConstReactionSuite self);

// +++ Get
// +++ Returns by value
extern_c const char *
ReactionSuiteInteractionGet(ConstHandle2ConstReactionSuite self);

// +++ Set
extern_c void
ReactionSuiteInteractionSet(ConstHandle2ReactionSuite self, const char *const interaction);


// -----------------------------------------------------------------------------
// Child: styles
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionSuiteStylesHas(ConstHandle2ConstReactionSuite self);

// --- Get, const
extern_c Handle2ConstStyles
ReactionSuiteStylesGetConst(ConstHandle2ConstReactionSuite self);

// +++ Get, non-const
extern_c Handle2Styles
ReactionSuiteStylesGet(ConstHandle2ReactionSuite self);

// +++ Set
extern_c void
ReactionSuiteStylesSet(ConstHandle2ReactionSuite self, ConstHandle2ConstStyles styles);


// -----------------------------------------------------------------------------
// Child: PoPs
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionSuitePoPsHas(ConstHandle2ConstReactionSuite self);

// --- Get, const
extern_c Handle2ConstPoPs
ReactionSuitePoPsGetConst(ConstHandle2ConstReactionSuite self);

// +++ Get, non-const
extern_c Handle2PoPs
ReactionSuitePoPsGet(ConstHandle2ReactionSuite self);

// +++ Set
extern_c void
ReactionSuitePoPsSet(ConstHandle2ReactionSuite self, ConstHandle2ConstPoPs PoPs);


// -----------------------------------------------------------------------------
// Child: reactions
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionSuiteReactionsHas(ConstHandle2ConstReactionSuite self);

// --- Get, const
extern_c Handle2ConstReactions
ReactionSuiteReactionsGetConst(ConstHandle2ConstReactionSuite self);

// +++ Get, non-const
extern_c Handle2Reactions
ReactionSuiteReactionsGet(ConstHandle2ReactionSuite self);

// +++ Set
extern_c void
ReactionSuiteReactionsSet(ConstHandle2ReactionSuite self, ConstHandle2ConstReactions reactions);


// -----------------------------------------------------------------------------
// Child: applicationData
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionSuiteApplicationDataHas(ConstHandle2ConstReactionSuite self);

// --- Get, const
extern_c Handle2ConstApplicationData
ReactionSuiteApplicationDataGetConst(ConstHandle2ConstReactionSuite self);

// +++ Get, non-const
extern_c Handle2ApplicationData
ReactionSuiteApplicationDataGet(ConstHandle2ReactionSuite self);

// +++ Set
extern_c void
ReactionSuiteApplicationDataSet(ConstHandle2ReactionSuite self, ConstHandle2ConstApplicationData applicationData);


// -----------------------------------------------------------------------------
// Child: externalFiles
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionSuiteExternalFilesHas(ConstHandle2ConstReactionSuite self);

// --- Get, const
extern_c Handle2ConstExternalFiles
ReactionSuiteExternalFilesGetConst(ConstHandle2ConstReactionSuite self);

// +++ Get, non-const
extern_c Handle2ExternalFiles
ReactionSuiteExternalFilesGet(ConstHandle2ReactionSuite self);

// +++ Set
extern_c void
ReactionSuiteExternalFilesSet(ConstHandle2ReactionSuite self, ConstHandle2ConstExternalFiles externalFiles);


// -----------------------------------------------------------------------------
// Child: resonances
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionSuiteResonancesHas(ConstHandle2ConstReactionSuite self);

// --- Get, const
extern_c Handle2ConstResonances
ReactionSuiteResonancesGetConst(ConstHandle2ConstReactionSuite self);

// +++ Get, non-const
extern_c Handle2Resonances
ReactionSuiteResonancesGet(ConstHandle2ReactionSuite self);

// +++ Set
extern_c void
ReactionSuiteResonancesSet(ConstHandle2ReactionSuite self, ConstHandle2ConstResonances resonances);


// -----------------------------------------------------------------------------
// Child: sums
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionSuiteSumsHas(ConstHandle2ConstReactionSuite self);

// --- Get, const
extern_c Handle2ConstSums
ReactionSuiteSumsGetConst(ConstHandle2ConstReactionSuite self);

// +++ Get, non-const
extern_c Handle2Sums
ReactionSuiteSumsGet(ConstHandle2ReactionSuite self);

// +++ Set
extern_c void
ReactionSuiteSumsSet(ConstHandle2ReactionSuite self, ConstHandle2ConstSums sums);


// -----------------------------------------------------------------------------
// Child: productions
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionSuiteProductionsHas(ConstHandle2ConstReactionSuite self);

// --- Get, const
extern_c Handle2ConstProductions
ReactionSuiteProductionsGetConst(ConstHandle2ConstReactionSuite self);

// +++ Get, non-const
extern_c Handle2Productions
ReactionSuiteProductionsGet(ConstHandle2ReactionSuite self);

// +++ Set
extern_c void
ReactionSuiteProductionsSet(ConstHandle2ReactionSuite self, ConstHandle2ConstProductions productions);


// -----------------------------------------------------------------------------
// Child: fissionComponents
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionSuiteFissionComponentsHas(ConstHandle2ConstReactionSuite self);

// --- Get, const
extern_c Handle2ConstFissionComponents
ReactionSuiteFissionComponentsGetConst(ConstHandle2ConstReactionSuite self);

// +++ Get, non-const
extern_c Handle2FissionComponents
ReactionSuiteFissionComponentsGet(ConstHandle2ReactionSuite self);

// +++ Set
extern_c void
ReactionSuiteFissionComponentsSet(ConstHandle2ReactionSuite self, ConstHandle2ConstFissionComponents fissionComponents);


// -----------------------------------------------------------------------------
// Child: orphanProducts
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionSuiteOrphanProductsHas(ConstHandle2ConstReactionSuite self);

// --- Get, const
extern_c Handle2ConstOrphanProducts
ReactionSuiteOrphanProductsGetConst(ConstHandle2ConstReactionSuite self);

// +++ Get, non-const
extern_c Handle2OrphanProducts
ReactionSuiteOrphanProductsGet(ConstHandle2ReactionSuite self);

// +++ Set
extern_c void
ReactionSuiteOrphanProductsSet(ConstHandle2ReactionSuite self, ConstHandle2ConstOrphanProducts orphanProducts);


// -----------------------------------------------------------------------------
// Child: incompleteReactions
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionSuiteIncompleteReactionsHas(ConstHandle2ConstReactionSuite self);

// --- Get, const
extern_c Handle2ConstIncompleteReactions
ReactionSuiteIncompleteReactionsGetConst(ConstHandle2ConstReactionSuite self);

// +++ Get, non-const
extern_c Handle2IncompleteReactions
ReactionSuiteIncompleteReactionsGet(ConstHandle2ReactionSuite self);

// +++ Set
extern_c void
ReactionSuiteIncompleteReactionsSet(ConstHandle2ReactionSuite self, ConstHandle2ConstIncompleteReactions incompleteReactions);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/top/ReactionSuite/src/custom.h"

#undef extern_c
#endif
