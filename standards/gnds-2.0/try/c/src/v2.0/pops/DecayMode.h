
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
// DecayMode is the basic handle type in this file. Example:
//    // Create a default DecayMode object:
//    DecayMode handle = DecayModeDefault();
// Functions involving DecayMode are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_POPS_DECAYMODE
#define C_INTERFACE_TRY_V2_0_POPS_DECAYMODE

#include "GNDStk.h"
#include "v2.0/pops/Probability.h"
#include "v2.0/pops/InternalConversionCoefficients.h"
#include "v2.0/pops/PhotonEmissionProbabilities.h"
#include "v2.0/pops/Q.h"
#include "v2.0/pops/DecayPath.h"
#include "v2.0/pops/Spectra.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct DecayModeClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ DecayMode
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct DecayModeClass *DecayMode;

// --- Const-aware handles.
typedef const struct DecayModeClass *const ConstHandle2ConstDecayMode;
typedef       struct DecayModeClass *const ConstHandle2DecayMode;
typedef const struct DecayModeClass *      Handle2ConstDecayMode;
typedef       struct DecayModeClass *      Handle2DecayMode;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstDecayMode
DecayModeDefaultConst();

// +++ Create, default
extern_c Handle2DecayMode
DecayModeDefault();

// --- Create, general, const
extern_c Handle2ConstDecayMode
DecayModeCreateConst(
   const XMLName label,
   const enums::DecayType mode,
   ConstHandle2ConstProbability probability,
   ConstHandle2ConstInternalConversionCoefficients internalConversionCoefficients,
   ConstHandle2ConstPhotonEmissionProbabilities photonEmissionProbabilities,
   ConstHandle2ConstQ Q,
   ConstHandle2ConstDecayPath decayPath,
   ConstHandle2ConstSpectra spectra
);

// +++ Create, general
extern_c Handle2DecayMode
DecayModeCreate(
   const XMLName label,
   const enums::DecayType mode,
   ConstHandle2ConstProbability probability,
   ConstHandle2ConstInternalConversionCoefficients internalConversionCoefficients,
   ConstHandle2ConstPhotonEmissionProbabilities photonEmissionProbabilities,
   ConstHandle2ConstQ Q,
   ConstHandle2ConstDecayPath decayPath,
   ConstHandle2ConstSpectra spectra
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
DecayModeAssign(ConstHandle2DecayMode This, ConstHandle2ConstDecayMode from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
DecayModeDelete(ConstHandle2ConstDecayMode This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
DecayModeRead(ConstHandle2DecayMode This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
DecayModeWrite(ConstHandle2ConstDecayMode This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
DecayModePrint(ConstHandle2ConstDecayMode This);

// +++ Print to standard output, as XML
extern_c int
DecayModePrintXML(ConstHandle2ConstDecayMode This);

// +++ Print to standard output, as JSON
extern_c int
DecayModePrintJSON(ConstHandle2ConstDecayMode This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DecayModeLabelHas(ConstHandle2ConstDecayMode This);

// +++ Get
// +++ Returns by value
extern_c XMLName
DecayModeLabelGet(ConstHandle2ConstDecayMode This);

// +++ Set
extern_c void
DecayModeLabelSet(ConstHandle2DecayMode This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: mode
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DecayModeModeHas(ConstHandle2ConstDecayMode This);

// +++ Get
// +++ Returns by value
extern_c enums::DecayType
DecayModeModeGet(ConstHandle2ConstDecayMode This);

// +++ Set
extern_c void
DecayModeModeSet(ConstHandle2DecayMode This, const enums::DecayType mode);


// -----------------------------------------------------------------------------
// Child: probability
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DecayModeProbabilityHas(ConstHandle2ConstDecayMode This);

// --- Get, const
extern_c Handle2ConstProbability
DecayModeProbabilityGetConst(ConstHandle2ConstDecayMode This);

// +++ Get, non-const
extern_c Handle2Probability
DecayModeProbabilityGet(ConstHandle2DecayMode This);

// +++ Set
extern_c void
DecayModeProbabilitySet(ConstHandle2DecayMode This, ConstHandle2ConstProbability probability);


// -----------------------------------------------------------------------------
// Child: internalConversionCoefficients
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DecayModeInternalConversionCoefficientsHas(ConstHandle2ConstDecayMode This);

// --- Get, const
extern_c Handle2ConstInternalConversionCoefficients
DecayModeInternalConversionCoefficientsGetConst(ConstHandle2ConstDecayMode This);

// +++ Get, non-const
extern_c Handle2InternalConversionCoefficients
DecayModeInternalConversionCoefficientsGet(ConstHandle2DecayMode This);

// +++ Set
extern_c void
DecayModeInternalConversionCoefficientsSet(ConstHandle2DecayMode This, ConstHandle2ConstInternalConversionCoefficients internalConversionCoefficients);


// -----------------------------------------------------------------------------
// Child: photonEmissionProbabilities
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DecayModePhotonEmissionProbabilitiesHas(ConstHandle2ConstDecayMode This);

// --- Get, const
extern_c Handle2ConstPhotonEmissionProbabilities
DecayModePhotonEmissionProbabilitiesGetConst(ConstHandle2ConstDecayMode This);

// +++ Get, non-const
extern_c Handle2PhotonEmissionProbabilities
DecayModePhotonEmissionProbabilitiesGet(ConstHandle2DecayMode This);

// +++ Set
extern_c void
DecayModePhotonEmissionProbabilitiesSet(ConstHandle2DecayMode This, ConstHandle2ConstPhotonEmissionProbabilities photonEmissionProbabilities);


// -----------------------------------------------------------------------------
// Child: Q
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DecayModeQHas(ConstHandle2ConstDecayMode This);

// --- Get, const
extern_c Handle2ConstQ
DecayModeQGetConst(ConstHandle2ConstDecayMode This);

// +++ Get, non-const
extern_c Handle2Q
DecayModeQGet(ConstHandle2DecayMode This);

// +++ Set
extern_c void
DecayModeQSet(ConstHandle2DecayMode This, ConstHandle2ConstQ Q);


// -----------------------------------------------------------------------------
// Child: decayPath
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DecayModeDecayPathHas(ConstHandle2ConstDecayMode This);

// --- Get, const
extern_c Handle2ConstDecayPath
DecayModeDecayPathGetConst(ConstHandle2ConstDecayMode This);

// +++ Get, non-const
extern_c Handle2DecayPath
DecayModeDecayPathGet(ConstHandle2DecayMode This);

// +++ Set
extern_c void
DecayModeDecayPathSet(ConstHandle2DecayMode This, ConstHandle2ConstDecayPath decayPath);


// -----------------------------------------------------------------------------
// Child: spectra
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DecayModeSpectraHas(ConstHandle2ConstDecayMode This);

// --- Get, const
extern_c Handle2ConstSpectra
DecayModeSpectraGetConst(ConstHandle2ConstDecayMode This);

// +++ Get, non-const
extern_c Handle2Spectra
DecayModeSpectraGet(ConstHandle2DecayMode This);

// +++ Set
extern_c void
DecayModeSpectraSet(ConstHandle2DecayMode This, ConstHandle2ConstSpectra spectra);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
