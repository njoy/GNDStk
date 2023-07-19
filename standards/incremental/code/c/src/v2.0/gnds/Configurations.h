
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
// Configurations is the basic handle type in this file. Example:
//    // Create a default Configurations object:
//    Configurations handle = ConfigurationsDefault();
// Functions involving Configurations are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_CODE_V2_0_GNDS_CONFIGURATIONS
#define C_INTERFACE_CODE_V2_0_GNDS_CONFIGURATIONS

#include "GNDStk.h"
#include "v2.0/gnds/Configuration.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ConfigurationsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Configurations
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ConfigurationsClass *Configurations;

// --- Const-aware handles.
typedef const struct ConfigurationsClass *const ConstHandle2ConstConfigurations;
typedef       struct ConfigurationsClass *const ConstHandle2Configurations;
typedef const struct ConfigurationsClass *      Handle2ConstConfigurations;
typedef       struct ConfigurationsClass *      Handle2Configurations;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstConfigurations
ConfigurationsDefaultConst();

// +++ Create, default
extern_c Handle2Configurations
ConfigurationsDefault();

// --- Create, general, const
extern_c Handle2ConstConfigurations
ConfigurationsCreateConst(
   ConstHandle2Configuration *const configuration, const size_t configurationSize
);

// +++ Create, general
extern_c Handle2Configurations
ConfigurationsCreate(
   ConstHandle2Configuration *const configuration, const size_t configurationSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ConfigurationsAssign(ConstHandle2Configurations self, ConstHandle2ConstConfigurations from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ConfigurationsDelete(ConstHandle2ConstConfigurations self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ConfigurationsRead(ConstHandle2Configurations self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ConfigurationsWrite(ConstHandle2ConstConfigurations self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ConfigurationsPrint(ConstHandle2ConstConfigurations self);

// +++ Print to standard output, as XML
extern_c int
ConfigurationsPrintXML(ConstHandle2ConstConfigurations self);

// +++ Print to standard output, as JSON
extern_c int
ConfigurationsPrintJSON(ConstHandle2ConstConfigurations self);


// -----------------------------------------------------------------------------
// Child: configuration
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ConfigurationsConfigurationHas(ConstHandle2ConstConfigurations self);

// +++ Clear
extern_c void
ConfigurationsConfigurationClear(ConstHandle2Configurations self);

// +++ Size
extern_c size_t
ConfigurationsConfigurationSize(ConstHandle2ConstConfigurations self);

// +++ Add
extern_c void
ConfigurationsConfigurationAdd(ConstHandle2Configurations self, ConstHandle2ConstConfiguration configuration);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstConfiguration
ConfigurationsConfigurationGetConst(ConstHandle2ConstConfigurations self, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Configuration
ConfigurationsConfigurationGet(ConstHandle2Configurations self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ConfigurationsConfigurationSet(
   ConstHandle2Configurations self,
   const size_t index_,
   ConstHandle2ConstConfiguration configuration
);

// +++ Has, by subshell
extern_c int
ConfigurationsConfigurationHasBySubshell(
   ConstHandle2ConstConfigurations self,
   const char *const subshell
);

// --- Get, by subshell, const
extern_c Handle2ConstConfiguration
ConfigurationsConfigurationGetBySubshellConst(
   ConstHandle2ConstConfigurations self,
   const char *const subshell
);

// +++ Get, by subshell, non-const
extern_c Handle2Configuration
ConfigurationsConfigurationGetBySubshell(
   ConstHandle2Configurations self,
   const char *const subshell
);

// +++ Set, by subshell
extern_c void
ConfigurationsConfigurationSetBySubshell(
   ConstHandle2Configurations self,
   const char *const subshell,
   ConstHandle2ConstConfiguration configuration
);

// +++ Has, by electronNumber
extern_c int
ConfigurationsConfigurationHasByElectronNumber(
   ConstHandle2ConstConfigurations self,
   const char *const electronNumber
);

// --- Get, by electronNumber, const
extern_c Handle2ConstConfiguration
ConfigurationsConfigurationGetByElectronNumberConst(
   ConstHandle2ConstConfigurations self,
   const char *const electronNumber
);

// +++ Get, by electronNumber, non-const
extern_c Handle2Configuration
ConfigurationsConfigurationGetByElectronNumber(
   ConstHandle2Configurations self,
   const char *const electronNumber
);

// +++ Set, by electronNumber
extern_c void
ConfigurationsConfigurationSetByElectronNumber(
   ConstHandle2Configurations self,
   const char *const electronNumber,
   ConstHandle2ConstConfiguration configuration
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/gnds/Configurations/src/custom.h"

#undef extern_c
#endif
