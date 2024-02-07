
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
// IncidentEnergy is the basic handle type in this file. Example:
//    // Create a default IncidentEnergy object:
//    IncidentEnergy handle = IncidentEnergyDefault();
// Functions involving IncidentEnergy are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_INCIDENTENERGY
#define C_INTERFACE_GNDS_V2_0_GENERAL_INCIDENTENERGY

#include "GNDStk.h"
#include "v2.0/general/Energy.h"
#include "v2.0/general/Yields.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct IncidentEnergyClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ IncidentEnergy
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct IncidentEnergyClass *IncidentEnergy;

// --- Const-aware handles.
typedef const struct IncidentEnergyClass *const ConstHandle2ConstIncidentEnergy;
typedef       struct IncidentEnergyClass *const ConstHandle2IncidentEnergy;
typedef const struct IncidentEnergyClass *      Handle2ConstIncidentEnergy;
typedef       struct IncidentEnergyClass *      Handle2IncidentEnergy;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstIncidentEnergy
IncidentEnergyDefaultConst();

// +++ Create, default, non-const
extern_c Handle2IncidentEnergy
IncidentEnergyDefault();

// --- Create, general, const
extern_c Handle2ConstIncidentEnergy
IncidentEnergyCreateConst(
   const char *const label,
   ConstHandle2ConstEnergy energy,
   ConstHandle2ConstYields yields
);

// +++ Create, general, non-const
extern_c Handle2IncidentEnergy
IncidentEnergyCreate(
   const char *const label,
   ConstHandle2ConstEnergy energy,
   ConstHandle2ConstYields yields
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
IncidentEnergyAssign(ConstHandle2IncidentEnergy self, ConstHandle2ConstIncidentEnergy from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
IncidentEnergyDelete(ConstHandle2ConstIncidentEnergy self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
IncidentEnergyRead(ConstHandle2IncidentEnergy self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
IncidentEnergyWrite(ConstHandle2ConstIncidentEnergy self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
IncidentEnergyPrint(ConstHandle2ConstIncidentEnergy self);

// +++ Print to standard output, as XML
extern_c int
IncidentEnergyPrintXML(ConstHandle2ConstIncidentEnergy self);

// +++ Print to standard output, as JSON
extern_c int
IncidentEnergyPrintJSON(ConstHandle2ConstIncidentEnergy self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
IncidentEnergyLabelHas(ConstHandle2ConstIncidentEnergy self);

// +++ Get
// +++ Returns by value
extern_c const char *
IncidentEnergyLabelGet(ConstHandle2ConstIncidentEnergy self);

// +++ Set
extern_c void
IncidentEnergyLabelSet(ConstHandle2IncidentEnergy self, const char *const label);


// -----------------------------------------------------------------------------
// Child: energy
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
IncidentEnergyEnergyHas(ConstHandle2ConstIncidentEnergy self);

// --- Get, const
extern_c Handle2ConstEnergy
IncidentEnergyEnergyGetConst(ConstHandle2ConstIncidentEnergy self);

// +++ Get, non-const
extern_c Handle2Energy
IncidentEnergyEnergyGet(ConstHandle2IncidentEnergy self);

// +++ Set
extern_c void
IncidentEnergyEnergySet(ConstHandle2IncidentEnergy self, ConstHandle2ConstEnergy energy);


// -----------------------------------------------------------------------------
// Child: yields
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
IncidentEnergyYieldsHas(ConstHandle2ConstIncidentEnergy self);

// --- Get, const
extern_c Handle2ConstYields
IncidentEnergyYieldsGetConst(ConstHandle2ConstIncidentEnergy self);

// +++ Get, non-const
extern_c Handle2Yields
IncidentEnergyYieldsGet(ConstHandle2IncidentEnergy self);

// +++ Set
extern_c void
IncidentEnergyYieldsSet(ConstHandle2IncidentEnergy self, ConstHandle2ConstYields yields);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/IncidentEnergy/src/custom.h"

#undef extern_c
#endif
