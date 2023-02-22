
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
// Discrete is the basic handle type in this file. Example:
//    // Create a default Discrete object:
//    Discrete handle = DiscreteDefault();
// Functions involving Discrete are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_DISCRETE
#define C_INTERFACE_ALPHA_V2_0_GENERAL_DISCRETE

#include "GNDStk.h"
#include "v2.0/general/Intensity.h"
#include "v2.0/general/Energy.h"
#include "v2.0/general/InternalConversionCoefficients.h"
#include "v2.0/general/PositronEmissionIntensity.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct DiscreteClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Discrete
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct DiscreteClass *Discrete;

// --- Const-aware handles.
typedef const struct DiscreteClass *const ConstHandle2ConstDiscrete;
typedef       struct DiscreteClass *const ConstHandle2Discrete;
typedef const struct DiscreteClass *      Handle2ConstDiscrete;
typedef       struct DiscreteClass *      Handle2Discrete;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstDiscrete
DiscreteDefaultConst();

// +++ Create, default
extern_c Handle2Discrete
DiscreteDefault();

// --- Create, general, const
extern_c Handle2ConstDiscrete
DiscreteCreateConst(
   const char *const type,
   ConstHandle2ConstIntensity intensity,
   ConstHandle2ConstEnergy energy,
   ConstHandle2ConstInternalConversionCoefficients internalConversionCoefficients,
   ConstHandle2ConstPositronEmissionIntensity positronEmissionIntensity
);

// +++ Create, general
extern_c Handle2Discrete
DiscreteCreate(
   const char *const type,
   ConstHandle2ConstIntensity intensity,
   ConstHandle2ConstEnergy energy,
   ConstHandle2ConstInternalConversionCoefficients internalConversionCoefficients,
   ConstHandle2ConstPositronEmissionIntensity positronEmissionIntensity
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
DiscreteAssign(ConstHandle2Discrete self, ConstHandle2ConstDiscrete from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
DiscreteDelete(ConstHandle2ConstDiscrete self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
DiscreteRead(ConstHandle2Discrete self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
DiscreteWrite(ConstHandle2ConstDiscrete self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
DiscretePrint(ConstHandle2ConstDiscrete self);

// +++ Print to standard output, as XML
extern_c int
DiscretePrintXML(ConstHandle2ConstDiscrete self);

// +++ Print to standard output, as JSON
extern_c int
DiscretePrintJSON(ConstHandle2ConstDiscrete self);


// -----------------------------------------------------------------------------
// Metadatum: type
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DiscreteTypeHas(ConstHandle2ConstDiscrete self);

// +++ Get
// +++ Returns by value
extern_c const char *
DiscreteTypeGet(ConstHandle2ConstDiscrete self);

// +++ Set
extern_c void
DiscreteTypeSet(ConstHandle2Discrete self, const char *const type);


// -----------------------------------------------------------------------------
// Child: intensity
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DiscreteIntensityHas(ConstHandle2ConstDiscrete self);

// --- Get, const
extern_c Handle2ConstIntensity
DiscreteIntensityGetConst(ConstHandle2ConstDiscrete self);

// +++ Get, non-const
extern_c Handle2Intensity
DiscreteIntensityGet(ConstHandle2Discrete self);

// +++ Set
extern_c void
DiscreteIntensitySet(ConstHandle2Discrete self, ConstHandle2ConstIntensity intensity);


// -----------------------------------------------------------------------------
// Child: energy
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DiscreteEnergyHas(ConstHandle2ConstDiscrete self);

// --- Get, const
extern_c Handle2ConstEnergy
DiscreteEnergyGetConst(ConstHandle2ConstDiscrete self);

// +++ Get, non-const
extern_c Handle2Energy
DiscreteEnergyGet(ConstHandle2Discrete self);

// +++ Set
extern_c void
DiscreteEnergySet(ConstHandle2Discrete self, ConstHandle2ConstEnergy energy);


// -----------------------------------------------------------------------------
// Child: internalConversionCoefficients
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DiscreteInternalConversionCoefficientsHas(ConstHandle2ConstDiscrete self);

// --- Get, const
extern_c Handle2ConstInternalConversionCoefficients
DiscreteInternalConversionCoefficientsGetConst(ConstHandle2ConstDiscrete self);

// +++ Get, non-const
extern_c Handle2InternalConversionCoefficients
DiscreteInternalConversionCoefficientsGet(ConstHandle2Discrete self);

// +++ Set
extern_c void
DiscreteInternalConversionCoefficientsSet(ConstHandle2Discrete self, ConstHandle2ConstInternalConversionCoefficients internalConversionCoefficients);


// -----------------------------------------------------------------------------
// Child: positronEmissionIntensity
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DiscretePositronEmissionIntensityHas(ConstHandle2ConstDiscrete self);

// --- Get, const
extern_c Handle2ConstPositronEmissionIntensity
DiscretePositronEmissionIntensityGetConst(ConstHandle2ConstDiscrete self);

// +++ Get, non-const
extern_c Handle2PositronEmissionIntensity
DiscretePositronEmissionIntensityGet(ConstHandle2Discrete self);

// +++ Set
extern_c void
DiscretePositronEmissionIntensitySet(ConstHandle2Discrete self, ConstHandle2ConstPositronEmissionIntensity positronEmissionIntensity);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Discrete/src/custom.h"

#undef extern_c
#endif