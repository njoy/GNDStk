
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
// NuclearPlusInterference is the basic handle type in this file. Example:
//    // Create a default NuclearPlusInterference object:
//    NuclearPlusInterference handle = NuclearPlusInterferenceDefault();
// Functions involving NuclearPlusInterference are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_DFILES_NUCLEARPLUSINTERFERENCE
#define C_INTERFACE_ALPHA_V2_0_DFILES_NUCLEARPLUSINTERFERENCE

#include "GNDStk.h"
#include "v2.0/reduced/CrossSection.h"
#include "v2.0/dfiles/Distribution.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct NuclearPlusInterferenceClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ NuclearPlusInterference
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct NuclearPlusInterferenceClass *NuclearPlusInterference;

// --- Const-aware handles.
typedef const struct NuclearPlusInterferenceClass *const ConstHandle2ConstNuclearPlusInterference;
typedef       struct NuclearPlusInterferenceClass *const ConstHandle2NuclearPlusInterference;
typedef const struct NuclearPlusInterferenceClass *      Handle2ConstNuclearPlusInterference;
typedef       struct NuclearPlusInterferenceClass *      Handle2NuclearPlusInterference;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstNuclearPlusInterference
NuclearPlusInterferenceDefaultConst();

// +++ Create, default
extern_c Handle2NuclearPlusInterference
NuclearPlusInterferenceDefault();

// --- Create, general, const
extern_c Handle2ConstNuclearPlusInterference
NuclearPlusInterferenceCreateConst(
   const double muCutoff,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstDistribution distribution
);

// +++ Create, general
extern_c Handle2NuclearPlusInterference
NuclearPlusInterferenceCreate(
   const double muCutoff,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstDistribution distribution
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
NuclearPlusInterferenceAssign(ConstHandle2NuclearPlusInterference This, ConstHandle2ConstNuclearPlusInterference from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
NuclearPlusInterferenceDelete(ConstHandle2ConstNuclearPlusInterference This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
NuclearPlusInterferenceRead(ConstHandle2NuclearPlusInterference This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
NuclearPlusInterferenceWrite(ConstHandle2ConstNuclearPlusInterference This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
NuclearPlusInterferencePrint(ConstHandle2ConstNuclearPlusInterference This);

// +++ Print to standard output, as XML
extern_c int
NuclearPlusInterferencePrintXML(ConstHandle2ConstNuclearPlusInterference This);

// +++ Print to standard output, as JSON
extern_c int
NuclearPlusInterferencePrintJSON(ConstHandle2ConstNuclearPlusInterference This);


// -----------------------------------------------------------------------------
// Metadatum: muCutoff
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclearPlusInterferenceMuCutoffHas(ConstHandle2ConstNuclearPlusInterference This);

// +++ Get
// +++ Returns by value
extern_c double
NuclearPlusInterferenceMuCutoffGet(ConstHandle2ConstNuclearPlusInterference This);

// +++ Set
extern_c void
NuclearPlusInterferenceMuCutoffSet(ConstHandle2NuclearPlusInterference This, const double muCutoff);


// -----------------------------------------------------------------------------
// Child: crossSection
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclearPlusInterferenceCrossSectionHas(ConstHandle2ConstNuclearPlusInterference This);

// --- Get, const
extern_c Handle2ConstCrossSection
NuclearPlusInterferenceCrossSectionGetConst(ConstHandle2ConstNuclearPlusInterference This);

// +++ Get, non-const
extern_c Handle2CrossSection
NuclearPlusInterferenceCrossSectionGet(ConstHandle2NuclearPlusInterference This);

// +++ Set
extern_c void
NuclearPlusInterferenceCrossSectionSet(ConstHandle2NuclearPlusInterference This, ConstHandle2ConstCrossSection crossSection);


// -----------------------------------------------------------------------------
// Child: distribution
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclearPlusInterferenceDistributionHas(ConstHandle2ConstNuclearPlusInterference This);

// --- Get, const
extern_c Handle2ConstDistribution
NuclearPlusInterferenceDistributionGetConst(ConstHandle2ConstNuclearPlusInterference This);

// +++ Get, non-const
extern_c Handle2Distribution
NuclearPlusInterferenceDistributionGet(ConstHandle2NuclearPlusInterference This);

// +++ Set
extern_c void
NuclearPlusInterferenceDistributionSet(ConstHandle2NuclearPlusInterference This, ConstHandle2ConstDistribution distribution);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/dfiles/NuclearPlusInterference/src/custom.h"

#undef extern_c
#endif
