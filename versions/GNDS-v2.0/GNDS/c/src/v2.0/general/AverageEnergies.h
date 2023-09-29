
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
// AverageEnergies is the basic handle type in this file. Example:
//    // Create a default AverageEnergies object:
//    AverageEnergies handle = AverageEnergiesDefault();
// Functions involving AverageEnergies are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_AVERAGEENERGIES
#define C_INTERFACE_GNDS_V2_0_GENERAL_AVERAGEENERGIES

#include "GNDStk.h"
#include "v2.0/general/AverageEnergy.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AverageEnergiesClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ AverageEnergies
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AverageEnergiesClass *AverageEnergies;

// --- Const-aware handles.
typedef const struct AverageEnergiesClass *const ConstHandle2ConstAverageEnergies;
typedef       struct AverageEnergiesClass *const ConstHandle2AverageEnergies;
typedef const struct AverageEnergiesClass *      Handle2ConstAverageEnergies;
typedef       struct AverageEnergiesClass *      Handle2AverageEnergies;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAverageEnergies
AverageEnergiesDefaultConst();

// +++ Create, default
extern_c Handle2AverageEnergies
AverageEnergiesDefault();

// --- Create, general, const
extern_c Handle2ConstAverageEnergies
AverageEnergiesCreateConst(
   ConstHandle2AverageEnergy *const averageEnergy, const size_t averageEnergySize
);

// +++ Create, general
extern_c Handle2AverageEnergies
AverageEnergiesCreate(
   ConstHandle2AverageEnergy *const averageEnergy, const size_t averageEnergySize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AverageEnergiesAssign(ConstHandle2AverageEnergies self, ConstHandle2ConstAverageEnergies from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AverageEnergiesDelete(ConstHandle2ConstAverageEnergies self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AverageEnergiesRead(ConstHandle2AverageEnergies self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AverageEnergiesWrite(ConstHandle2ConstAverageEnergies self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AverageEnergiesPrint(ConstHandle2ConstAverageEnergies self);

// +++ Print to standard output, as XML
extern_c int
AverageEnergiesPrintXML(ConstHandle2ConstAverageEnergies self);

// +++ Print to standard output, as JSON
extern_c int
AverageEnergiesPrintJSON(ConstHandle2ConstAverageEnergies self);


// -----------------------------------------------------------------------------
// Child: averageEnergy
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AverageEnergiesAverageEnergyHas(ConstHandle2ConstAverageEnergies self);

// +++ Clear
extern_c void
AverageEnergiesAverageEnergyClear(ConstHandle2AverageEnergies self);

// +++ Size
extern_c size_t
AverageEnergiesAverageEnergySize(ConstHandle2ConstAverageEnergies self);

// +++ Add
extern_c void
AverageEnergiesAverageEnergyAdd(ConstHandle2AverageEnergies self, ConstHandle2ConstAverageEnergy averageEnergy);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstAverageEnergy
AverageEnergiesAverageEnergyGetConst(ConstHandle2ConstAverageEnergies self, const size_t index_);

// +++ Get, by index \in [0,size)
extern_c Handle2AverageEnergy
AverageEnergiesAverageEnergyGet(ConstHandle2AverageEnergies self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
AverageEnergiesAverageEnergySet(
   ConstHandle2AverageEnergies self,
   const size_t index_,
   ConstHandle2ConstAverageEnergy averageEnergy
);

// ------------------------
// Re: metadatum label
// ------------------------

// +++ Has, by label
extern_c int
AverageEnergiesAverageEnergyHasByLabel(
   ConstHandle2ConstAverageEnergies self,
   const char *const label
);

// --- Get, by label, const
extern_c Handle2ConstAverageEnergy
AverageEnergiesAverageEnergyGetByLabelConst(
   ConstHandle2ConstAverageEnergies self,
   const char *const label
);

// +++ Get, by label
extern_c Handle2AverageEnergy
AverageEnergiesAverageEnergyGetByLabel(
   ConstHandle2AverageEnergies self,
   const char *const label
);

// +++ Set, by label
extern_c void
AverageEnergiesAverageEnergySetByLabel(
   ConstHandle2AverageEnergies self,
   const char *const label,
   ConstHandle2ConstAverageEnergy averageEnergy
);

// ------------------------
// Re: metadatum value
// ------------------------

// +++ Has, by value
extern_c int
AverageEnergiesAverageEnergyHasByValue(
   ConstHandle2ConstAverageEnergies self,
   const double value
);

// --- Get, by value, const
extern_c Handle2ConstAverageEnergy
AverageEnergiesAverageEnergyGetByValueConst(
   ConstHandle2ConstAverageEnergies self,
   const double value
);

// +++ Get, by value
extern_c Handle2AverageEnergy
AverageEnergiesAverageEnergyGetByValue(
   ConstHandle2AverageEnergies self,
   const double value
);

// +++ Set, by value
extern_c void
AverageEnergiesAverageEnergySetByValue(
   ConstHandle2AverageEnergies self,
   const double value,
   ConstHandle2ConstAverageEnergy averageEnergy
);

// ------------------------
// Re: metadatum unit
// ------------------------

// +++ Has, by unit
extern_c int
AverageEnergiesAverageEnergyHasByUnit(
   ConstHandle2ConstAverageEnergies self,
   const char *const unit
);

// --- Get, by unit, const
extern_c Handle2ConstAverageEnergy
AverageEnergiesAverageEnergyGetByUnitConst(
   ConstHandle2ConstAverageEnergies self,
   const char *const unit
);

// +++ Get, by unit
extern_c Handle2AverageEnergy
AverageEnergiesAverageEnergyGetByUnit(
   ConstHandle2AverageEnergies self,
   const char *const unit
);

// +++ Set, by unit
extern_c void
AverageEnergiesAverageEnergySetByUnit(
   ConstHandle2AverageEnergies self,
   const char *const unit,
   ConstHandle2ConstAverageEnergy averageEnergy
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/AverageEnergies/src/custom.h"

#undef extern_c
#endif
