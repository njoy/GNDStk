
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
// FissionFragmentData is the basic handle type in this file. Example:
//    // Create a default FissionFragmentData object:
//    FissionFragmentData handle = FissionFragmentDataDefault();
// Functions involving FissionFragmentData are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_FISSIONFRAGMENTDATA_FISSIONFRAGMENTDATA
#define C_INTERFACE_TEST_V2_0_FISSIONFRAGMENTDATA_FISSIONFRAGMENTDATA

#include "GNDStk.h"
#include "v2.0/fissionFragmentData/DelayedNeutrons.h"
#include "v2.0/fissionTransport/FissionEnergyReleased.h"
#include "v2.0/fpy/ProductYields.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct FissionFragmentDataClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ FissionFragmentData
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct FissionFragmentDataClass *FissionFragmentData;

// --- Const-aware handles.
typedef const struct FissionFragmentDataClass *const ConstHandle2ConstFissionFragmentData;
typedef       struct FissionFragmentDataClass *const ConstHandle2FissionFragmentData;
typedef const struct FissionFragmentDataClass *      Handle2ConstFissionFragmentData;
typedef       struct FissionFragmentDataClass *      Handle2FissionFragmentData;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstFissionFragmentData
FissionFragmentDataDefaultConst();

// +++ Create, default
extern_c Handle2FissionFragmentData
FissionFragmentDataDefault();

// --- Create, general, const
extern_c Handle2ConstFissionFragmentData
FissionFragmentDataCreateConst(
   ConstHandle2ConstDelayedNeutrons delayedNeutrons,
   ConstHandle2ConstFissionEnergyReleased fissionEnergyReleased,
   ConstHandle2ConstProductYields productYields
);

// +++ Create, general
extern_c Handle2FissionFragmentData
FissionFragmentDataCreate(
   ConstHandle2ConstDelayedNeutrons delayedNeutrons,
   ConstHandle2ConstFissionEnergyReleased fissionEnergyReleased,
   ConstHandle2ConstProductYields productYields
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
FissionFragmentDataAssign(ConstHandle2FissionFragmentData This, ConstHandle2ConstFissionFragmentData from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
FissionFragmentDataDelete(ConstHandle2ConstFissionFragmentData This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
FissionFragmentDataRead(ConstHandle2FissionFragmentData This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
FissionFragmentDataWrite(ConstHandle2ConstFissionFragmentData This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
FissionFragmentDataPrint(ConstHandle2ConstFissionFragmentData This);

// +++ Print to standard output, as XML
extern_c int
FissionFragmentDataPrintXML(ConstHandle2ConstFissionFragmentData This);

// +++ Print to standard output, as JSON
extern_c int
FissionFragmentDataPrintJSON(ConstHandle2ConstFissionFragmentData This);


// -----------------------------------------------------------------------------
// Child: delayedNeutrons
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
FissionFragmentDataDelayedNeutronsHas(ConstHandle2ConstFissionFragmentData This);

// --- Get, const
extern_c Handle2ConstDelayedNeutrons
FissionFragmentDataDelayedNeutronsGetConst(ConstHandle2ConstFissionFragmentData This);

// +++ Get, non-const
extern_c Handle2DelayedNeutrons
FissionFragmentDataDelayedNeutronsGet(ConstHandle2FissionFragmentData This);

// +++ Set
extern_c void
FissionFragmentDataDelayedNeutronsSet(ConstHandle2FissionFragmentData This, ConstHandle2ConstDelayedNeutrons delayedNeutrons);


// -----------------------------------------------------------------------------
// Child: fissionEnergyReleased
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
FissionFragmentDataFissionEnergyReleasedHas(ConstHandle2ConstFissionFragmentData This);

// --- Get, const
extern_c Handle2ConstFissionEnergyReleased
FissionFragmentDataFissionEnergyReleasedGetConst(ConstHandle2ConstFissionFragmentData This);

// +++ Get, non-const
extern_c Handle2FissionEnergyReleased
FissionFragmentDataFissionEnergyReleasedGet(ConstHandle2FissionFragmentData This);

// +++ Set
extern_c void
FissionFragmentDataFissionEnergyReleasedSet(ConstHandle2FissionFragmentData This, ConstHandle2ConstFissionEnergyReleased fissionEnergyReleased);


// -----------------------------------------------------------------------------
// Child: productYields
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
FissionFragmentDataProductYieldsHas(ConstHandle2ConstFissionFragmentData This);

// --- Get, const
extern_c Handle2ConstProductYields
FissionFragmentDataProductYieldsGetConst(ConstHandle2ConstFissionFragmentData This);

// +++ Get, non-const
extern_c Handle2ProductYields
FissionFragmentDataProductYieldsGet(ConstHandle2FissionFragmentData This);

// +++ Set
extern_c void
FissionFragmentDataProductYieldsSet(ConstHandle2FissionFragmentData This, ConstHandle2ConstProductYields productYields);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
