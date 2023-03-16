
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
// Energy_uncorrelated is the basic handle type in this file. Example:
//    // Create a default Energy_uncorrelated object:
//    Energy_uncorrelated handle = Energy_uncorrelatedDefault();
// Functions involving Energy_uncorrelated are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TRANSPORT_ENERGY_UNCORRELATED
#define C_INTERFACE_TEST_V2_0_TRANSPORT_ENERGY_UNCORRELATED

#include "GNDStk.h"
#include "v2.0/containers/XYs2d.h"
#include "v2.0/containers/Regions2d.h"
#include "v2.0/transport/GeneralEvaporation.h"
#include "v2.0/transport/DiscreteGamma.h"
#include "v2.0/transport/PrimaryGamma.h"
#include "v2.0/transport/NBodyPhaseSpace.h"
#include "v2.0/transport/Evaporation.h"
#include "v2.0/transport/WeightedFunctionals.h"
#include "v2.0/fissionTransport/SimpleMaxwellianFission.h"
#include "v2.0/fissionTransport/Watt.h"
#include "v2.0/fissionTransport/MadlandNix.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct Energy_uncorrelatedClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Energy_uncorrelated
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct Energy_uncorrelatedClass *Energy_uncorrelated;

// --- Const-aware handles.
typedef const struct Energy_uncorrelatedClass *const ConstHandle2ConstEnergy_uncorrelated;
typedef       struct Energy_uncorrelatedClass *const ConstHandle2Energy_uncorrelated;
typedef const struct Energy_uncorrelatedClass *      Handle2ConstEnergy_uncorrelated;
typedef       struct Energy_uncorrelatedClass *      Handle2Energy_uncorrelated;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstEnergy_uncorrelated
Energy_uncorrelatedDefaultConst();

// +++ Create, default
extern_c Handle2Energy_uncorrelated
Energy_uncorrelatedDefault();

// --- Create, general, const
extern_c Handle2ConstEnergy_uncorrelated
Energy_uncorrelatedCreateConst(
   ConstHandle2ConstXYs2d XYs2d,
   ConstHandle2ConstRegions2d regions2d,
   ConstHandle2ConstGeneralEvaporation generalEvaporation,
   ConstHandle2ConstDiscreteGamma discreteGamma,
   ConstHandle2ConstPrimaryGamma primaryGamma,
   ConstHandle2ConstNBodyPhaseSpace NBodyPhaseSpace,
   ConstHandle2ConstEvaporation evaporation,
   ConstHandle2ConstWeightedFunctionals weightedFunctionals,
   ConstHandle2ConstSimpleMaxwellianFission simpleMaxwellianFission,
   ConstHandle2ConstWatt Watt,
   ConstHandle2ConstMadlandNix MadlandNix
);

// +++ Create, general
extern_c Handle2Energy_uncorrelated
Energy_uncorrelatedCreate(
   ConstHandle2ConstXYs2d XYs2d,
   ConstHandle2ConstRegions2d regions2d,
   ConstHandle2ConstGeneralEvaporation generalEvaporation,
   ConstHandle2ConstDiscreteGamma discreteGamma,
   ConstHandle2ConstPrimaryGamma primaryGamma,
   ConstHandle2ConstNBodyPhaseSpace NBodyPhaseSpace,
   ConstHandle2ConstEvaporation evaporation,
   ConstHandle2ConstWeightedFunctionals weightedFunctionals,
   ConstHandle2ConstSimpleMaxwellianFission simpleMaxwellianFission,
   ConstHandle2ConstWatt Watt,
   ConstHandle2ConstMadlandNix MadlandNix
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
Energy_uncorrelatedAssign(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstEnergy_uncorrelated from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
Energy_uncorrelatedDelete(ConstHandle2ConstEnergy_uncorrelated self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
Energy_uncorrelatedRead(ConstHandle2Energy_uncorrelated self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
Energy_uncorrelatedWrite(ConstHandle2ConstEnergy_uncorrelated self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
Energy_uncorrelatedPrint(ConstHandle2ConstEnergy_uncorrelated self);

// +++ Print to standard output, as XML
extern_c int
Energy_uncorrelatedPrintXML(ConstHandle2ConstEnergy_uncorrelated self);

// +++ Print to standard output, as JSON
extern_c int
Energy_uncorrelatedPrintJSON(ConstHandle2ConstEnergy_uncorrelated self);


// -----------------------------------------------------------------------------
// Child: XYs2d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Energy_uncorrelatedXYs2dHas(ConstHandle2ConstEnergy_uncorrelated self);

// --- Get, const
extern_c Handle2ConstXYs2d
Energy_uncorrelatedXYs2dGetConst(ConstHandle2ConstEnergy_uncorrelated self);

// +++ Get, non-const
extern_c Handle2XYs2d
Energy_uncorrelatedXYs2dGet(ConstHandle2Energy_uncorrelated self);

// +++ Set
extern_c void
Energy_uncorrelatedXYs2dSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstXYs2d XYs2d);


// -----------------------------------------------------------------------------
// Child: regions2d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Energy_uncorrelatedRegions2dHas(ConstHandle2ConstEnergy_uncorrelated self);

// --- Get, const
extern_c Handle2ConstRegions2d
Energy_uncorrelatedRegions2dGetConst(ConstHandle2ConstEnergy_uncorrelated self);

// +++ Get, non-const
extern_c Handle2Regions2d
Energy_uncorrelatedRegions2dGet(ConstHandle2Energy_uncorrelated self);

// +++ Set
extern_c void
Energy_uncorrelatedRegions2dSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstRegions2d regions2d);


// -----------------------------------------------------------------------------
// Child: generalEvaporation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Energy_uncorrelatedGeneralEvaporationHas(ConstHandle2ConstEnergy_uncorrelated self);

// --- Get, const
extern_c Handle2ConstGeneralEvaporation
Energy_uncorrelatedGeneralEvaporationGetConst(ConstHandle2ConstEnergy_uncorrelated self);

// +++ Get, non-const
extern_c Handle2GeneralEvaporation
Energy_uncorrelatedGeneralEvaporationGet(ConstHandle2Energy_uncorrelated self);

// +++ Set
extern_c void
Energy_uncorrelatedGeneralEvaporationSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstGeneralEvaporation generalEvaporation);


// -----------------------------------------------------------------------------
// Child: discreteGamma
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Energy_uncorrelatedDiscreteGammaHas(ConstHandle2ConstEnergy_uncorrelated self);

// --- Get, const
extern_c Handle2ConstDiscreteGamma
Energy_uncorrelatedDiscreteGammaGetConst(ConstHandle2ConstEnergy_uncorrelated self);

// +++ Get, non-const
extern_c Handle2DiscreteGamma
Energy_uncorrelatedDiscreteGammaGet(ConstHandle2Energy_uncorrelated self);

// +++ Set
extern_c void
Energy_uncorrelatedDiscreteGammaSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstDiscreteGamma discreteGamma);


// -----------------------------------------------------------------------------
// Child: primaryGamma
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Energy_uncorrelatedPrimaryGammaHas(ConstHandle2ConstEnergy_uncorrelated self);

// --- Get, const
extern_c Handle2ConstPrimaryGamma
Energy_uncorrelatedPrimaryGammaGetConst(ConstHandle2ConstEnergy_uncorrelated self);

// +++ Get, non-const
extern_c Handle2PrimaryGamma
Energy_uncorrelatedPrimaryGammaGet(ConstHandle2Energy_uncorrelated self);

// +++ Set
extern_c void
Energy_uncorrelatedPrimaryGammaSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstPrimaryGamma primaryGamma);


// -----------------------------------------------------------------------------
// Child: NBodyPhaseSpace
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Energy_uncorrelatedNBodyPhaseSpaceHas(ConstHandle2ConstEnergy_uncorrelated self);

// --- Get, const
extern_c Handle2ConstNBodyPhaseSpace
Energy_uncorrelatedNBodyPhaseSpaceGetConst(ConstHandle2ConstEnergy_uncorrelated self);

// +++ Get, non-const
extern_c Handle2NBodyPhaseSpace
Energy_uncorrelatedNBodyPhaseSpaceGet(ConstHandle2Energy_uncorrelated self);

// +++ Set
extern_c void
Energy_uncorrelatedNBodyPhaseSpaceSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstNBodyPhaseSpace NBodyPhaseSpace);


// -----------------------------------------------------------------------------
// Child: evaporation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Energy_uncorrelatedEvaporationHas(ConstHandle2ConstEnergy_uncorrelated self);

// --- Get, const
extern_c Handle2ConstEvaporation
Energy_uncorrelatedEvaporationGetConst(ConstHandle2ConstEnergy_uncorrelated self);

// +++ Get, non-const
extern_c Handle2Evaporation
Energy_uncorrelatedEvaporationGet(ConstHandle2Energy_uncorrelated self);

// +++ Set
extern_c void
Energy_uncorrelatedEvaporationSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstEvaporation evaporation);


// -----------------------------------------------------------------------------
// Child: weightedFunctionals
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Energy_uncorrelatedWeightedFunctionalsHas(ConstHandle2ConstEnergy_uncorrelated self);

// --- Get, const
extern_c Handle2ConstWeightedFunctionals
Energy_uncorrelatedWeightedFunctionalsGetConst(ConstHandle2ConstEnergy_uncorrelated self);

// +++ Get, non-const
extern_c Handle2WeightedFunctionals
Energy_uncorrelatedWeightedFunctionalsGet(ConstHandle2Energy_uncorrelated self);

// +++ Set
extern_c void
Energy_uncorrelatedWeightedFunctionalsSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstWeightedFunctionals weightedFunctionals);


// -----------------------------------------------------------------------------
// Child: simpleMaxwellianFission
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Energy_uncorrelatedSimpleMaxwellianFissionHas(ConstHandle2ConstEnergy_uncorrelated self);

// --- Get, const
extern_c Handle2ConstSimpleMaxwellianFission
Energy_uncorrelatedSimpleMaxwellianFissionGetConst(ConstHandle2ConstEnergy_uncorrelated self);

// +++ Get, non-const
extern_c Handle2SimpleMaxwellianFission
Energy_uncorrelatedSimpleMaxwellianFissionGet(ConstHandle2Energy_uncorrelated self);

// +++ Set
extern_c void
Energy_uncorrelatedSimpleMaxwellianFissionSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstSimpleMaxwellianFission simpleMaxwellianFission);


// -----------------------------------------------------------------------------
// Child: Watt
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Energy_uncorrelatedWattHas(ConstHandle2ConstEnergy_uncorrelated self);

// --- Get, const
extern_c Handle2ConstWatt
Energy_uncorrelatedWattGetConst(ConstHandle2ConstEnergy_uncorrelated self);

// +++ Get, non-const
extern_c Handle2Watt
Energy_uncorrelatedWattGet(ConstHandle2Energy_uncorrelated self);

// +++ Set
extern_c void
Energy_uncorrelatedWattSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstWatt Watt);


// -----------------------------------------------------------------------------
// Child: MadlandNix
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Energy_uncorrelatedMadlandNixHas(ConstHandle2ConstEnergy_uncorrelated self);

// --- Get, const
extern_c Handle2ConstMadlandNix
Energy_uncorrelatedMadlandNixGetConst(ConstHandle2ConstEnergy_uncorrelated self);

// +++ Get, non-const
extern_c Handle2MadlandNix
Energy_uncorrelatedMadlandNixGet(ConstHandle2Energy_uncorrelated self);

// +++ Set
extern_c void
Energy_uncorrelatedMadlandNixSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstMadlandNix MadlandNix);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/Energy_uncorrelated/src/custom.h"

#undef extern_c
#endif
