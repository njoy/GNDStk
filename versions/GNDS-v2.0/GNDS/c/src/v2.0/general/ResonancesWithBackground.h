
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
// ResonancesWithBackground is the basic handle type in this file. Example:
//    // Create a default ResonancesWithBackground object:
//    ResonancesWithBackground handle = ResonancesWithBackgroundDefault();
// Functions involving ResonancesWithBackground are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_RESONANCESWITHBACKGROUND
#define C_INTERFACE_GNDS_V2_0_GENERAL_RESONANCESWITHBACKGROUND

#include "GNDStk.h"
#include "v2.0/general/Resonances.h"
#include "v2.0/general/Background.h"
#include "v2.0/general/Uncertainty.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ResonancesWithBackgroundClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ResonancesWithBackground
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ResonancesWithBackgroundClass *ResonancesWithBackground;

// --- Const-aware handles.
typedef const struct ResonancesWithBackgroundClass *const ConstHandle2ConstResonancesWithBackground;
typedef       struct ResonancesWithBackgroundClass *const ConstHandle2ResonancesWithBackground;
typedef const struct ResonancesWithBackgroundClass *      Handle2ConstResonancesWithBackground;
typedef       struct ResonancesWithBackgroundClass *      Handle2ResonancesWithBackground;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstResonancesWithBackground
ResonancesWithBackgroundDefaultConst();

// +++ Create, default
extern_c Handle2ResonancesWithBackground
ResonancesWithBackgroundDefault();

// --- Create, general, const
extern_c Handle2ConstResonancesWithBackground
ResonancesWithBackgroundCreateConst(
   const char *const label,
   ConstHandle2ConstResonances resonances,
   ConstHandle2ConstBackground background,
   ConstHandle2ConstUncertainty uncertainty
);

// +++ Create, general
extern_c Handle2ResonancesWithBackground
ResonancesWithBackgroundCreate(
   const char *const label,
   ConstHandle2ConstResonances resonances,
   ConstHandle2ConstBackground background,
   ConstHandle2ConstUncertainty uncertainty
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ResonancesWithBackgroundAssign(ConstHandle2ResonancesWithBackground self, ConstHandle2ConstResonancesWithBackground from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ResonancesWithBackgroundDelete(ConstHandle2ConstResonancesWithBackground self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ResonancesWithBackgroundRead(ConstHandle2ResonancesWithBackground self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ResonancesWithBackgroundWrite(ConstHandle2ConstResonancesWithBackground self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ResonancesWithBackgroundPrint(ConstHandle2ConstResonancesWithBackground self);

// +++ Print to standard output, as XML
extern_c int
ResonancesWithBackgroundPrintXML(ConstHandle2ConstResonancesWithBackground self);

// +++ Print to standard output, as JSON
extern_c int
ResonancesWithBackgroundPrintJSON(ConstHandle2ConstResonancesWithBackground self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResonancesWithBackgroundLabelHas(ConstHandle2ConstResonancesWithBackground self);

// +++ Get
// +++ Returns by value
extern_c const char *
ResonancesWithBackgroundLabelGet(ConstHandle2ConstResonancesWithBackground self);

// +++ Set
extern_c void
ResonancesWithBackgroundLabelSet(ConstHandle2ResonancesWithBackground self, const char *const label);


// -----------------------------------------------------------------------------
// Child: resonances
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResonancesWithBackgroundResonancesHas(ConstHandle2ConstResonancesWithBackground self);

// --- Get, const
extern_c Handle2ConstResonances
ResonancesWithBackgroundResonancesGetConst(ConstHandle2ConstResonancesWithBackground self);

// +++ Get
extern_c Handle2Resonances
ResonancesWithBackgroundResonancesGet(ConstHandle2ResonancesWithBackground self);

// +++ Set
extern_c void
ResonancesWithBackgroundResonancesSet(ConstHandle2ResonancesWithBackground self, ConstHandle2ConstResonances resonances);


// -----------------------------------------------------------------------------
// Child: background
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResonancesWithBackgroundBackgroundHas(ConstHandle2ConstResonancesWithBackground self);

// --- Get, const
extern_c Handle2ConstBackground
ResonancesWithBackgroundBackgroundGetConst(ConstHandle2ConstResonancesWithBackground self);

// +++ Get
extern_c Handle2Background
ResonancesWithBackgroundBackgroundGet(ConstHandle2ResonancesWithBackground self);

// +++ Set
extern_c void
ResonancesWithBackgroundBackgroundSet(ConstHandle2ResonancesWithBackground self, ConstHandle2ConstBackground background);


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResonancesWithBackgroundUncertaintyHas(ConstHandle2ConstResonancesWithBackground self);

// --- Get, const
extern_c Handle2ConstUncertainty
ResonancesWithBackgroundUncertaintyGetConst(ConstHandle2ConstResonancesWithBackground self);

// +++ Get
extern_c Handle2Uncertainty
ResonancesWithBackgroundUncertaintyGet(ConstHandle2ResonancesWithBackground self);

// +++ Set
extern_c void
ResonancesWithBackgroundUncertaintySet(ConstHandle2ResonancesWithBackground self, ConstHandle2ConstUncertainty uncertainty);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ResonancesWithBackground/src/custom.h"

#undef extern_c
#endif
