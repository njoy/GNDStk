
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
// ScatteringAtom is the basic handle type in this file. Example:
//    // Create a default ScatteringAtom object:
//    ScatteringAtom handle = ScatteringAtomDefault();
// Functions involving ScatteringAtom are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_TSL_SCATTERINGATOM
#define C_INTERFACE_ALPHA_V2_0_TSL_SCATTERINGATOM

#include "GNDStk.h"
#include "v2.0/common/Mass.h"
#include "v2.0/tsl/E_critical.h"
#include "v2.0/tsl/E_max.h"
#include "v2.0/tsl/BoundAtomCrossSection.h"
#include "v2.0/tsl/SelfScatteringKernel.h"
#include "v2.0/tsl/T_effective.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ScatteringAtomClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ScatteringAtom
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ScatteringAtomClass *ScatteringAtom;

// --- Const-aware handles.
typedef const struct ScatteringAtomClass *const ConstHandle2ConstScatteringAtom;
typedef       struct ScatteringAtomClass *const ConstHandle2ScatteringAtom;
typedef const struct ScatteringAtomClass *      Handle2ConstScatteringAtom;
typedef       struct ScatteringAtomClass *      Handle2ScatteringAtom;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstScatteringAtom
ScatteringAtomDefaultConst();

// +++ Create, default
extern_c Handle2ScatteringAtom
ScatteringAtomDefault();

// --- Create, general, const
extern_c Handle2ConstScatteringAtom
ScatteringAtomCreateConst(
   const char *const pid,
   const int numberPerMolecule,
   const bool primaryScatterer,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstE_critical e_critical,
   ConstHandle2ConstE_max e_max,
   ConstHandle2ConstBoundAtomCrossSection boundAtomCrossSection,
   ConstHandle2ConstSelfScatteringKernel selfScatteringKernel,
   ConstHandle2ConstT_effective T_effective
);

// +++ Create, general
extern_c Handle2ScatteringAtom
ScatteringAtomCreate(
   const char *const pid,
   const int numberPerMolecule,
   const bool primaryScatterer,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstE_critical e_critical,
   ConstHandle2ConstE_max e_max,
   ConstHandle2ConstBoundAtomCrossSection boundAtomCrossSection,
   ConstHandle2ConstSelfScatteringKernel selfScatteringKernel,
   ConstHandle2ConstT_effective T_effective
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ScatteringAtomAssign(ConstHandle2ScatteringAtom This, ConstHandle2ConstScatteringAtom from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ScatteringAtomDelete(ConstHandle2ConstScatteringAtom This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ScatteringAtomRead(ConstHandle2ScatteringAtom This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ScatteringAtomWrite(ConstHandle2ConstScatteringAtom This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ScatteringAtomPrint(ConstHandle2ConstScatteringAtom This);

// +++ Print to standard output, as XML
extern_c int
ScatteringAtomPrintXML(ConstHandle2ConstScatteringAtom This);

// +++ Print to standard output, as JSON
extern_c int
ScatteringAtomPrintJSON(ConstHandle2ConstScatteringAtom This);


// -----------------------------------------------------------------------------
// Metadatum: pid
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ScatteringAtomPidHas(ConstHandle2ConstScatteringAtom This);

// +++ Get
// +++ Returns by value
extern_c const char *
ScatteringAtomPidGet(ConstHandle2ConstScatteringAtom This);

// +++ Set
extern_c void
ScatteringAtomPidSet(ConstHandle2ScatteringAtom This, const char *const pid);


// -----------------------------------------------------------------------------
// Metadatum: numberPerMolecule
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ScatteringAtomNumberPerMoleculeHas(ConstHandle2ConstScatteringAtom This);

// +++ Get
// +++ Returns by value
extern_c int
ScatteringAtomNumberPerMoleculeGet(ConstHandle2ConstScatteringAtom This);

// +++ Set
extern_c void
ScatteringAtomNumberPerMoleculeSet(ConstHandle2ScatteringAtom This, const int numberPerMolecule);


// -----------------------------------------------------------------------------
// Metadatum: primaryScatterer
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ScatteringAtomPrimaryScattererHas(ConstHandle2ConstScatteringAtom This);

// +++ Get
// +++ Returns by value
extern_c bool
ScatteringAtomPrimaryScattererGet(ConstHandle2ConstScatteringAtom This);

// +++ Set
extern_c void
ScatteringAtomPrimaryScattererSet(ConstHandle2ScatteringAtom This, const bool primaryScatterer);


// -----------------------------------------------------------------------------
// Child: mass
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ScatteringAtomMassHas(ConstHandle2ConstScatteringAtom This);

// --- Get, const
extern_c Handle2ConstMass
ScatteringAtomMassGetConst(ConstHandle2ConstScatteringAtom This);

// +++ Get, non-const
extern_c Handle2Mass
ScatteringAtomMassGet(ConstHandle2ScatteringAtom This);

// +++ Set
extern_c void
ScatteringAtomMassSet(ConstHandle2ScatteringAtom This, ConstHandle2ConstMass mass);


// -----------------------------------------------------------------------------
// Child: e_critical
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ScatteringAtomE_criticalHas(ConstHandle2ConstScatteringAtom This);

// --- Get, const
extern_c Handle2ConstE_critical
ScatteringAtomE_criticalGetConst(ConstHandle2ConstScatteringAtom This);

// +++ Get, non-const
extern_c Handle2E_critical
ScatteringAtomE_criticalGet(ConstHandle2ScatteringAtom This);

// +++ Set
extern_c void
ScatteringAtomE_criticalSet(ConstHandle2ScatteringAtom This, ConstHandle2ConstE_critical e_critical);


// -----------------------------------------------------------------------------
// Child: e_max
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ScatteringAtomE_maxHas(ConstHandle2ConstScatteringAtom This);

// --- Get, const
extern_c Handle2ConstE_max
ScatteringAtomE_maxGetConst(ConstHandle2ConstScatteringAtom This);

// +++ Get, non-const
extern_c Handle2E_max
ScatteringAtomE_maxGet(ConstHandle2ScatteringAtom This);

// +++ Set
extern_c void
ScatteringAtomE_maxSet(ConstHandle2ScatteringAtom This, ConstHandle2ConstE_max e_max);


// -----------------------------------------------------------------------------
// Child: boundAtomCrossSection
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ScatteringAtomBoundAtomCrossSectionHas(ConstHandle2ConstScatteringAtom This);

// --- Get, const
extern_c Handle2ConstBoundAtomCrossSection
ScatteringAtomBoundAtomCrossSectionGetConst(ConstHandle2ConstScatteringAtom This);

// +++ Get, non-const
extern_c Handle2BoundAtomCrossSection
ScatteringAtomBoundAtomCrossSectionGet(ConstHandle2ScatteringAtom This);

// +++ Set
extern_c void
ScatteringAtomBoundAtomCrossSectionSet(ConstHandle2ScatteringAtom This, ConstHandle2ConstBoundAtomCrossSection boundAtomCrossSection);


// -----------------------------------------------------------------------------
// Child: selfScatteringKernel
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ScatteringAtomSelfScatteringKernelHas(ConstHandle2ConstScatteringAtom This);

// --- Get, const
extern_c Handle2ConstSelfScatteringKernel
ScatteringAtomSelfScatteringKernelGetConst(ConstHandle2ConstScatteringAtom This);

// +++ Get, non-const
extern_c Handle2SelfScatteringKernel
ScatteringAtomSelfScatteringKernelGet(ConstHandle2ScatteringAtom This);

// +++ Set
extern_c void
ScatteringAtomSelfScatteringKernelSet(ConstHandle2ScatteringAtom This, ConstHandle2ConstSelfScatteringKernel selfScatteringKernel);


// -----------------------------------------------------------------------------
// Child: T_effective
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ScatteringAtomT_effectiveHas(ConstHandle2ConstScatteringAtom This);

// --- Get, const
extern_c Handle2ConstT_effective
ScatteringAtomT_effectiveGetConst(ConstHandle2ConstScatteringAtom This);

// +++ Get, non-const
extern_c Handle2T_effective
ScatteringAtomT_effectiveGet(ConstHandle2ScatteringAtom This);

// +++ Set
extern_c void
ScatteringAtomT_effectiveSet(ConstHandle2ScatteringAtom This, ConstHandle2ConstT_effective T_effective);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/tsl/ScatteringAtom/src/custom.h"

#undef extern_c
#endif
