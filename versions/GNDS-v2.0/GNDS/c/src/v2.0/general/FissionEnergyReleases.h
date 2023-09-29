
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
// FissionEnergyReleases is the basic handle type in this file. Example:
//    // Create a default FissionEnergyReleases object:
//    FissionEnergyReleases handle = FissionEnergyReleasesDefault();
// Functions involving FissionEnergyReleases are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_FISSIONENERGYRELEASES
#define C_INTERFACE_GNDS_V2_0_GENERAL_FISSIONENERGYRELEASES

#include "GNDStk.h"
#include "v2.0/general/FissionEnergyRelease.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct FissionEnergyReleasesClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ FissionEnergyReleases
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct FissionEnergyReleasesClass *FissionEnergyReleases;

// --- Const-aware handles.
typedef const struct FissionEnergyReleasesClass *const ConstHandle2ConstFissionEnergyReleases;
typedef       struct FissionEnergyReleasesClass *const ConstHandle2FissionEnergyReleases;
typedef const struct FissionEnergyReleasesClass *      Handle2ConstFissionEnergyReleases;
typedef       struct FissionEnergyReleasesClass *      Handle2FissionEnergyReleases;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstFissionEnergyReleases
FissionEnergyReleasesDefaultConst();

// +++ Create, default, non-const
extern_c Handle2FissionEnergyReleases
FissionEnergyReleasesDefault();

// --- Create, general, const
extern_c Handle2ConstFissionEnergyReleases
FissionEnergyReleasesCreateConst(
   ConstHandle2FissionEnergyRelease *const fissionEnergyRelease, const size_t fissionEnergyReleaseSize
);

// +++ Create, general, non-const
extern_c Handle2FissionEnergyReleases
FissionEnergyReleasesCreate(
   ConstHandle2FissionEnergyRelease *const fissionEnergyRelease, const size_t fissionEnergyReleaseSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
FissionEnergyReleasesAssign(ConstHandle2FissionEnergyReleases self, ConstHandle2ConstFissionEnergyReleases from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
FissionEnergyReleasesDelete(ConstHandle2ConstFissionEnergyReleases self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
FissionEnergyReleasesRead(ConstHandle2FissionEnergyReleases self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
FissionEnergyReleasesWrite(ConstHandle2ConstFissionEnergyReleases self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
FissionEnergyReleasesPrint(ConstHandle2ConstFissionEnergyReleases self);

// +++ Print to standard output, as XML
extern_c int
FissionEnergyReleasesPrintXML(ConstHandle2ConstFissionEnergyReleases self);

// +++ Print to standard output, as JSON
extern_c int
FissionEnergyReleasesPrintJSON(ConstHandle2ConstFissionEnergyReleases self);


// -----------------------------------------------------------------------------
// Child: fissionEnergyRelease
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
FissionEnergyReleasesFissionEnergyReleaseHas(ConstHandle2ConstFissionEnergyReleases self);

// +++ Clear
extern_c void
FissionEnergyReleasesFissionEnergyReleaseClear(ConstHandle2FissionEnergyReleases self);

// +++ Size
extern_c size_t
FissionEnergyReleasesFissionEnergyReleaseSize(ConstHandle2ConstFissionEnergyReleases self);

// +++ Add
extern_c void
FissionEnergyReleasesFissionEnergyReleaseAdd(ConstHandle2FissionEnergyReleases self, ConstHandle2ConstFissionEnergyRelease fissionEnergyRelease);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstFissionEnergyRelease
FissionEnergyReleasesFissionEnergyReleaseGetConst(ConstHandle2ConstFissionEnergyReleases self, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2FissionEnergyRelease
FissionEnergyReleasesFissionEnergyReleaseGet(ConstHandle2FissionEnergyReleases self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
FissionEnergyReleasesFissionEnergyReleaseSet(
   ConstHandle2FissionEnergyReleases self,
   const size_t index_,
   ConstHandle2ConstFissionEnergyRelease fissionEnergyRelease
);

// ------------------------
// Re: metadatum label
// ------------------------

// +++ Has, by label
extern_c int
FissionEnergyReleasesFissionEnergyReleaseHasByLabel(
   ConstHandle2ConstFissionEnergyReleases self,
   const char *const label
);

// --- Get, by label, const
extern_c Handle2ConstFissionEnergyRelease
FissionEnergyReleasesFissionEnergyReleaseGetByLabelConst(
   ConstHandle2ConstFissionEnergyReleases self,
   const char *const label
);

// +++ Get, by label, non-const
extern_c Handle2FissionEnergyRelease
FissionEnergyReleasesFissionEnergyReleaseGetByLabel(
   ConstHandle2FissionEnergyReleases self,
   const char *const label
);

// +++ Set, by label
extern_c void
FissionEnergyReleasesFissionEnergyReleaseSetByLabel(
   ConstHandle2FissionEnergyReleases self,
   const char *const label,
   ConstHandle2ConstFissionEnergyRelease fissionEnergyRelease
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/FissionEnergyReleases/src/custom.h"

#undef extern_c
#endif
