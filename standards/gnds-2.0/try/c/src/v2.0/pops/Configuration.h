
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
// Configuration is the basic handle type in this file. Example:
//    // Create a default Configuration object:
//    Configuration handle = ConfigurationDefault();
// Functions involving Configuration are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_POPS_CONFIGURATION
#define C_INTERFACE_TRY_V2_0_POPS_CONFIGURATION

#include "GNDStk.h"
#include "v2.0/pops/BindingEnergy.h"
#include "v2.0/pops/DecayData.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ConfigurationClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Configuration
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ConfigurationClass *Configuration;

// --- Const-aware handles.
typedef const struct ConfigurationClass *const ConstHandle2ConstConfiguration;
typedef       struct ConfigurationClass *const ConstHandle2Configuration;
typedef const struct ConfigurationClass *      Handle2ConstConfiguration;
typedef       struct ConfigurationClass *      Handle2Configuration;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstConfiguration
ConfigurationDefaultConst();

// +++ Create, default
extern_c Handle2Configuration
ConfigurationDefault();

// --- Create, general, const
extern_c Handle2ConstConfiguration
ConfigurationCreateConst(
   const char *const subshell,
   const Float64 electronNumber,
   ConstHandle2ConstBindingEnergy bindingEnergy,
   ConstHandle2ConstDecayData decayData
);

// +++ Create, general
extern_c Handle2Configuration
ConfigurationCreate(
   const char *const subshell,
   const Float64 electronNumber,
   ConstHandle2ConstBindingEnergy bindingEnergy,
   ConstHandle2ConstDecayData decayData
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ConfigurationAssign(ConstHandle2Configuration This, ConstHandle2ConstConfiguration from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ConfigurationDelete(ConstHandle2ConstConfiguration This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ConfigurationRead(ConstHandle2Configuration This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ConfigurationWrite(ConstHandle2ConstConfiguration This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ConfigurationPrint(ConstHandle2ConstConfiguration This);

// +++ Print to standard output, as XML
extern_c int
ConfigurationPrintXML(ConstHandle2ConstConfiguration This);

// +++ Print to standard output, as JSON
extern_c int
ConfigurationPrintJSON(ConstHandle2ConstConfiguration This);


// -----------------------------------------------------------------------------
// Metadatum: subshell
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ConfigurationSubshellHas(ConstHandle2ConstConfiguration This);

// +++ Get
// +++ Returns by value
extern_c const char *
ConfigurationSubshellGet(ConstHandle2ConstConfiguration This);

// +++ Set
extern_c void
ConfigurationSubshellSet(ConstHandle2Configuration This, const char *const subshell);


// -----------------------------------------------------------------------------
// Metadatum: electronNumber
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ConfigurationElectronNumberHas(ConstHandle2ConstConfiguration This);

// +++ Get
// +++ Returns by value
extern_c Float64
ConfigurationElectronNumberGet(ConstHandle2ConstConfiguration This);

// +++ Set
extern_c void
ConfigurationElectronNumberSet(ConstHandle2Configuration This, const Float64 electronNumber);


// -----------------------------------------------------------------------------
// Child: bindingEnergy
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ConfigurationBindingEnergyHas(ConstHandle2ConstConfiguration This);

// --- Get, const
extern_c Handle2ConstBindingEnergy
ConfigurationBindingEnergyGetConst(ConstHandle2ConstConfiguration This);

// +++ Get, non-const
extern_c Handle2BindingEnergy
ConfigurationBindingEnergyGet(ConstHandle2Configuration This);

// +++ Set
extern_c void
ConfigurationBindingEnergySet(ConstHandle2Configuration This, ConstHandle2ConstBindingEnergy bindingEnergy);


// -----------------------------------------------------------------------------
// Child: decayData
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ConfigurationDecayDataHas(ConstHandle2ConstConfiguration This);

// --- Get, const
extern_c Handle2ConstDecayData
ConfigurationDecayDataGetConst(ConstHandle2ConstConfiguration This);

// +++ Get, non-const
extern_c Handle2DecayData
ConfigurationDecayDataGet(ConstHandle2Configuration This);

// +++ Set
extern_c void
ConfigurationDecayDataSet(ConstHandle2Configuration This, ConstHandle2ConstDecayData decayData);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
