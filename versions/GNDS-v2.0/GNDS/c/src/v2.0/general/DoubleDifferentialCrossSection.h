
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
// DoubleDifferentialCrossSection is the basic handle type in this file. Example:
//    // Create a default DoubleDifferentialCrossSection object:
//    DoubleDifferentialCrossSection handle = DoubleDifferentialCrossSectionDefault();
// Functions involving DoubleDifferentialCrossSection are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_DOUBLEDIFFERENTIALCROSSSECTION
#define C_INTERFACE_GNDS_V2_0_GENERAL_DOUBLEDIFFERENTIALCROSSSECTION

#include "GNDStk.h"
#include "v2.0/general/CoulombPlusNuclearElastic.h"
#include "v2.0/general/CoherentPhotonScattering.h"
#include "v2.0/general/IncoherentPhotonScattering.h"
#include "v2.0/general/ThermalNeutronScatteringLaw_coherentElastic.h"
#include "v2.0/general/ThermalNeutronScatteringLaw_incoherentElastic.h"
#include "v2.0/general/ThermalNeutronScatteringLaw_incoherentInelastic.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct DoubleDifferentialCrossSectionClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ DoubleDifferentialCrossSection
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct DoubleDifferentialCrossSectionClass *DoubleDifferentialCrossSection;

// --- Const-aware handles.
typedef const struct DoubleDifferentialCrossSectionClass *const ConstHandle2ConstDoubleDifferentialCrossSection;
typedef       struct DoubleDifferentialCrossSectionClass *const ConstHandle2DoubleDifferentialCrossSection;
typedef const struct DoubleDifferentialCrossSectionClass *      Handle2ConstDoubleDifferentialCrossSection;
typedef       struct DoubleDifferentialCrossSectionClass *      Handle2DoubleDifferentialCrossSection;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstDoubleDifferentialCrossSection
DoubleDifferentialCrossSectionDefaultConst();

// +++ Create, default
extern_c Handle2DoubleDifferentialCrossSection
DoubleDifferentialCrossSectionDefault();

// --- Create, general, const
extern_c Handle2ConstDoubleDifferentialCrossSection
DoubleDifferentialCrossSectionCreateConst(
   ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic,
   ConstHandle2ConstCoherentPhotonScattering coherentPhotonScattering,
   ConstHandle2ConstIncoherentPhotonScattering incoherentPhotonScattering,
   ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic thermalNeutronScatteringLaw_coherentElastic,
   ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic thermalNeutronScatteringLaw_incoherentElastic,
   ConstHandle2ConstThermalNeutronScatteringLaw_incoherentInelastic thermalNeutronScatteringLaw_incoherentInelastic
);

// +++ Create, general
extern_c Handle2DoubleDifferentialCrossSection
DoubleDifferentialCrossSectionCreate(
   ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic,
   ConstHandle2ConstCoherentPhotonScattering coherentPhotonScattering,
   ConstHandle2ConstIncoherentPhotonScattering incoherentPhotonScattering,
   ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic thermalNeutronScatteringLaw_coherentElastic,
   ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic thermalNeutronScatteringLaw_incoherentElastic,
   ConstHandle2ConstThermalNeutronScatteringLaw_incoherentInelastic thermalNeutronScatteringLaw_incoherentInelastic
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
DoubleDifferentialCrossSectionAssign(ConstHandle2DoubleDifferentialCrossSection self, ConstHandle2ConstDoubleDifferentialCrossSection from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
DoubleDifferentialCrossSectionDelete(ConstHandle2ConstDoubleDifferentialCrossSection self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
DoubleDifferentialCrossSectionRead(ConstHandle2DoubleDifferentialCrossSection self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
DoubleDifferentialCrossSectionWrite(ConstHandle2ConstDoubleDifferentialCrossSection self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
DoubleDifferentialCrossSectionPrint(ConstHandle2ConstDoubleDifferentialCrossSection self);

// +++ Print to standard output, as XML
extern_c int
DoubleDifferentialCrossSectionPrintXML(ConstHandle2ConstDoubleDifferentialCrossSection self);

// +++ Print to standard output, as JSON
extern_c int
DoubleDifferentialCrossSectionPrintJSON(ConstHandle2ConstDoubleDifferentialCrossSection self);


// -----------------------------------------------------------------------------
// Child: CoulombPlusNuclearElastic
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DoubleDifferentialCrossSectionCoulombPlusNuclearElasticHas(ConstHandle2ConstDoubleDifferentialCrossSection self);

// --- Get, const
extern_c Handle2ConstCoulombPlusNuclearElastic
DoubleDifferentialCrossSectionCoulombPlusNuclearElasticGetConst(ConstHandle2ConstDoubleDifferentialCrossSection self);

// +++ Get
extern_c Handle2CoulombPlusNuclearElastic
DoubleDifferentialCrossSectionCoulombPlusNuclearElasticGet(ConstHandle2DoubleDifferentialCrossSection self);

// +++ Set
extern_c void
DoubleDifferentialCrossSectionCoulombPlusNuclearElasticSet(ConstHandle2DoubleDifferentialCrossSection self, ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic);


// -----------------------------------------------------------------------------
// Child: coherentPhotonScattering
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DoubleDifferentialCrossSectionCoherentPhotonScatteringHas(ConstHandle2ConstDoubleDifferentialCrossSection self);

// --- Get, const
extern_c Handle2ConstCoherentPhotonScattering
DoubleDifferentialCrossSectionCoherentPhotonScatteringGetConst(ConstHandle2ConstDoubleDifferentialCrossSection self);

// +++ Get
extern_c Handle2CoherentPhotonScattering
DoubleDifferentialCrossSectionCoherentPhotonScatteringGet(ConstHandle2DoubleDifferentialCrossSection self);

// +++ Set
extern_c void
DoubleDifferentialCrossSectionCoherentPhotonScatteringSet(ConstHandle2DoubleDifferentialCrossSection self, ConstHandle2ConstCoherentPhotonScattering coherentPhotonScattering);


// -----------------------------------------------------------------------------
// Child: incoherentPhotonScattering
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DoubleDifferentialCrossSectionIncoherentPhotonScatteringHas(ConstHandle2ConstDoubleDifferentialCrossSection self);

// --- Get, const
extern_c Handle2ConstIncoherentPhotonScattering
DoubleDifferentialCrossSectionIncoherentPhotonScatteringGetConst(ConstHandle2ConstDoubleDifferentialCrossSection self);

// +++ Get
extern_c Handle2IncoherentPhotonScattering
DoubleDifferentialCrossSectionIncoherentPhotonScatteringGet(ConstHandle2DoubleDifferentialCrossSection self);

// +++ Set
extern_c void
DoubleDifferentialCrossSectionIncoherentPhotonScatteringSet(ConstHandle2DoubleDifferentialCrossSection self, ConstHandle2ConstIncoherentPhotonScattering incoherentPhotonScattering);


// -----------------------------------------------------------------------------
// Child: thermalNeutronScatteringLaw_coherentElastic
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_coherentElasticHas(ConstHandle2ConstDoubleDifferentialCrossSection self);

// --- Get, const
extern_c Handle2ConstThermalNeutronScatteringLaw_coherentElastic
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_coherentElasticGetConst(ConstHandle2ConstDoubleDifferentialCrossSection self);

// +++ Get
extern_c Handle2ThermalNeutronScatteringLaw_coherentElastic
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_coherentElasticGet(ConstHandle2DoubleDifferentialCrossSection self);

// +++ Set
extern_c void
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_coherentElasticSet(ConstHandle2DoubleDifferentialCrossSection self, ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic thermalNeutronScatteringLaw_coherentElastic);


// -----------------------------------------------------------------------------
// Child: thermalNeutronScatteringLaw_incoherentElastic
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentElasticHas(ConstHandle2ConstDoubleDifferentialCrossSection self);

// --- Get, const
extern_c Handle2ConstThermalNeutronScatteringLaw_incoherentElastic
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentElasticGetConst(ConstHandle2ConstDoubleDifferentialCrossSection self);

// +++ Get
extern_c Handle2ThermalNeutronScatteringLaw_incoherentElastic
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentElasticGet(ConstHandle2DoubleDifferentialCrossSection self);

// +++ Set
extern_c void
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentElasticSet(ConstHandle2DoubleDifferentialCrossSection self, ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic thermalNeutronScatteringLaw_incoherentElastic);


// -----------------------------------------------------------------------------
// Child: thermalNeutronScatteringLaw_incoherentInelastic
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentInelasticHas(ConstHandle2ConstDoubleDifferentialCrossSection self);

// --- Get, const
extern_c Handle2ConstThermalNeutronScatteringLaw_incoherentInelastic
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentInelasticGetConst(ConstHandle2ConstDoubleDifferentialCrossSection self);

// +++ Get
extern_c Handle2ThermalNeutronScatteringLaw_incoherentInelastic
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentInelasticGet(ConstHandle2DoubleDifferentialCrossSection self);

// +++ Set
extern_c void
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentInelasticSet(ConstHandle2DoubleDifferentialCrossSection self, ConstHandle2ConstThermalNeutronScatteringLaw_incoherentInelastic thermalNeutronScatteringLaw_incoherentInelastic);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/DoubleDifferentialCrossSection/src/custom.h"

#undef extern_c
#endif
