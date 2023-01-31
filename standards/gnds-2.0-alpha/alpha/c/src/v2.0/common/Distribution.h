
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
// Distribution is the basic handle type in this file. Example:
//    // Create a default Distribution object:
//    Distribution handle = DistributionDefault();
// Functions involving Distribution are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_COMMON_DISTRIBUTION
#define C_INTERFACE_ALPHA_V2_0_COMMON_DISTRIBUTION

#include "GNDStk.h"
#include "v2.0/mean/AngularTwoBody.h"
#include "v2.0/mean/Uncorrelated.h"
#include "v2.0/mean/Unspecified.h"
#include "v2.0/mean/EnergyAngular.h"
#include "v2.0/mean/KalbachMann.h"
#include "v2.0/mean/AngularEnergy.h"
#include "v2.0/mean/Branching3d.h"
#include "v2.0/dfiles/CoulombPlusNuclearElastic.h"
#include "v2.0/mean/CoherentPhotonScattering.h"
#include "v2.0/mean/IncoherentPhotonScattering.h"
#include "v2.0/tsl/ThermalNeutronScatteringLaw.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct DistributionClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Distribution
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct DistributionClass *Distribution;

// --- Const-aware handles.
typedef const struct DistributionClass *const ConstHandle2ConstDistribution;
typedef       struct DistributionClass *const ConstHandle2Distribution;
typedef const struct DistributionClass *      Handle2ConstDistribution;
typedef       struct DistributionClass *      Handle2Distribution;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstDistribution
DistributionDefaultConst();

// +++ Create, default
extern_c Handle2Distribution
DistributionDefault();

// --- Create, general, const
extern_c Handle2ConstDistribution
DistributionCreateConst(
   ConstHandle2ConstAngularTwoBody angularTwoBody,
   ConstHandle2ConstUncorrelated uncorrelated,
   ConstHandle2ConstUnspecified unspecified,
   ConstHandle2ConstEnergyAngular energyAngular,
   ConstHandle2ConstKalbachMann KalbachMann,
   ConstHandle2ConstAngularEnergy angularEnergy,
   ConstHandle2ConstBranching3d branching3d,
   ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic,
   ConstHandle2ConstCoherentPhotonScattering coherentPhotonScattering,
   ConstHandle2ConstIncoherentPhotonScattering incoherentPhotonScattering,
   ConstHandle2ConstThermalNeutronScatteringLaw thermalNeutronScatteringLaw
);

// +++ Create, general
extern_c Handle2Distribution
DistributionCreate(
   ConstHandle2ConstAngularTwoBody angularTwoBody,
   ConstHandle2ConstUncorrelated uncorrelated,
   ConstHandle2ConstUnspecified unspecified,
   ConstHandle2ConstEnergyAngular energyAngular,
   ConstHandle2ConstKalbachMann KalbachMann,
   ConstHandle2ConstAngularEnergy angularEnergy,
   ConstHandle2ConstBranching3d branching3d,
   ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic,
   ConstHandle2ConstCoherentPhotonScattering coherentPhotonScattering,
   ConstHandle2ConstIncoherentPhotonScattering incoherentPhotonScattering,
   ConstHandle2ConstThermalNeutronScatteringLaw thermalNeutronScatteringLaw
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
DistributionAssign(ConstHandle2Distribution This, ConstHandle2ConstDistribution from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
DistributionDelete(ConstHandle2ConstDistribution This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
DistributionRead(ConstHandle2Distribution This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
DistributionWrite(ConstHandle2ConstDistribution This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
DistributionPrint(ConstHandle2ConstDistribution This);

// +++ Print to standard output, as XML
extern_c int
DistributionPrintXML(ConstHandle2ConstDistribution This);

// +++ Print to standard output, as JSON
extern_c int
DistributionPrintJSON(ConstHandle2ConstDistribution This);


// -----------------------------------------------------------------------------
// Child: angularTwoBody
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DistributionAngularTwoBodyHas(ConstHandle2ConstDistribution This);

// --- Get, const
extern_c Handle2ConstAngularTwoBody
DistributionAngularTwoBodyGetConst(ConstHandle2ConstDistribution This);

// +++ Get, non-const
extern_c Handle2AngularTwoBody
DistributionAngularTwoBodyGet(ConstHandle2Distribution This);

// +++ Set
extern_c void
DistributionAngularTwoBodySet(ConstHandle2Distribution This, ConstHandle2ConstAngularTwoBody angularTwoBody);


// -----------------------------------------------------------------------------
// Child: uncorrelated
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DistributionUncorrelatedHas(ConstHandle2ConstDistribution This);

// --- Get, const
extern_c Handle2ConstUncorrelated
DistributionUncorrelatedGetConst(ConstHandle2ConstDistribution This);

// +++ Get, non-const
extern_c Handle2Uncorrelated
DistributionUncorrelatedGet(ConstHandle2Distribution This);

// +++ Set
extern_c void
DistributionUncorrelatedSet(ConstHandle2Distribution This, ConstHandle2ConstUncorrelated uncorrelated);


// -----------------------------------------------------------------------------
// Child: unspecified
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DistributionUnspecifiedHas(ConstHandle2ConstDistribution This);

// --- Get, const
extern_c Handle2ConstUnspecified
DistributionUnspecifiedGetConst(ConstHandle2ConstDistribution This);

// +++ Get, non-const
extern_c Handle2Unspecified
DistributionUnspecifiedGet(ConstHandle2Distribution This);

// +++ Set
extern_c void
DistributionUnspecifiedSet(ConstHandle2Distribution This, ConstHandle2ConstUnspecified unspecified);


// -----------------------------------------------------------------------------
// Child: energyAngular
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DistributionEnergyAngularHas(ConstHandle2ConstDistribution This);

// --- Get, const
extern_c Handle2ConstEnergyAngular
DistributionEnergyAngularGetConst(ConstHandle2ConstDistribution This);

// +++ Get, non-const
extern_c Handle2EnergyAngular
DistributionEnergyAngularGet(ConstHandle2Distribution This);

// +++ Set
extern_c void
DistributionEnergyAngularSet(ConstHandle2Distribution This, ConstHandle2ConstEnergyAngular energyAngular);


// -----------------------------------------------------------------------------
// Child: KalbachMann
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DistributionKalbachMannHas(ConstHandle2ConstDistribution This);

// --- Get, const
extern_c Handle2ConstKalbachMann
DistributionKalbachMannGetConst(ConstHandle2ConstDistribution This);

// +++ Get, non-const
extern_c Handle2KalbachMann
DistributionKalbachMannGet(ConstHandle2Distribution This);

// +++ Set
extern_c void
DistributionKalbachMannSet(ConstHandle2Distribution This, ConstHandle2ConstKalbachMann KalbachMann);


// -----------------------------------------------------------------------------
// Child: angularEnergy
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DistributionAngularEnergyHas(ConstHandle2ConstDistribution This);

// --- Get, const
extern_c Handle2ConstAngularEnergy
DistributionAngularEnergyGetConst(ConstHandle2ConstDistribution This);

// +++ Get, non-const
extern_c Handle2AngularEnergy
DistributionAngularEnergyGet(ConstHandle2Distribution This);

// +++ Set
extern_c void
DistributionAngularEnergySet(ConstHandle2Distribution This, ConstHandle2ConstAngularEnergy angularEnergy);


// -----------------------------------------------------------------------------
// Child: branching3d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DistributionBranching3dHas(ConstHandle2ConstDistribution This);

// --- Get, const
extern_c Handle2ConstBranching3d
DistributionBranching3dGetConst(ConstHandle2ConstDistribution This);

// +++ Get, non-const
extern_c Handle2Branching3d
DistributionBranching3dGet(ConstHandle2Distribution This);

// +++ Set
extern_c void
DistributionBranching3dSet(ConstHandle2Distribution This, ConstHandle2ConstBranching3d branching3d);


// -----------------------------------------------------------------------------
// Child: CoulombPlusNuclearElastic
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DistributionCoulombPlusNuclearElasticHas(ConstHandle2ConstDistribution This);

// --- Get, const
extern_c Handle2ConstCoulombPlusNuclearElastic
DistributionCoulombPlusNuclearElasticGetConst(ConstHandle2ConstDistribution This);

// +++ Get, non-const
extern_c Handle2CoulombPlusNuclearElastic
DistributionCoulombPlusNuclearElasticGet(ConstHandle2Distribution This);

// +++ Set
extern_c void
DistributionCoulombPlusNuclearElasticSet(ConstHandle2Distribution This, ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic);


// -----------------------------------------------------------------------------
// Child: coherentPhotonScattering
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DistributionCoherentPhotonScatteringHas(ConstHandle2ConstDistribution This);

// --- Get, const
extern_c Handle2ConstCoherentPhotonScattering
DistributionCoherentPhotonScatteringGetConst(ConstHandle2ConstDistribution This);

// +++ Get, non-const
extern_c Handle2CoherentPhotonScattering
DistributionCoherentPhotonScatteringGet(ConstHandle2Distribution This);

// +++ Set
extern_c void
DistributionCoherentPhotonScatteringSet(ConstHandle2Distribution This, ConstHandle2ConstCoherentPhotonScattering coherentPhotonScattering);


// -----------------------------------------------------------------------------
// Child: incoherentPhotonScattering
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DistributionIncoherentPhotonScatteringHas(ConstHandle2ConstDistribution This);

// --- Get, const
extern_c Handle2ConstIncoherentPhotonScattering
DistributionIncoherentPhotonScatteringGetConst(ConstHandle2ConstDistribution This);

// +++ Get, non-const
extern_c Handle2IncoherentPhotonScattering
DistributionIncoherentPhotonScatteringGet(ConstHandle2Distribution This);

// +++ Set
extern_c void
DistributionIncoherentPhotonScatteringSet(ConstHandle2Distribution This, ConstHandle2ConstIncoherentPhotonScattering incoherentPhotonScattering);


// -----------------------------------------------------------------------------
// Child: thermalNeutronScatteringLaw
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DistributionThermalNeutronScatteringLawHas(ConstHandle2ConstDistribution This);

// --- Get, const
extern_c Handle2ConstThermalNeutronScatteringLaw
DistributionThermalNeutronScatteringLawGetConst(ConstHandle2ConstDistribution This);

// +++ Get, non-const
extern_c Handle2ThermalNeutronScatteringLaw
DistributionThermalNeutronScatteringLawGet(ConstHandle2Distribution This);

// +++ Set
extern_c void
DistributionThermalNeutronScatteringLawSet(ConstHandle2Distribution This, ConstHandle2ConstThermalNeutronScatteringLaw thermalNeutronScatteringLaw);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/common/Distribution/src/custom.h"

#undef extern_c
#endif
