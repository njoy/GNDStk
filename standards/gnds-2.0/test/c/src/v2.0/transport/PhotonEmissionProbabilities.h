
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
// PhotonEmissionProbabilities is the basic handle type in this file. Example:
//    // Create a default PhotonEmissionProbabilities object:
//    PhotonEmissionProbabilities handle = PhotonEmissionProbabilitiesDefault();
// Functions involving PhotonEmissionProbabilities are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TRANSPORT_PHOTONEMISSIONPROBABILITIES
#define C_INTERFACE_TEST_V2_0_TRANSPORT_PHOTONEMISSIONPROBABILITIES

#include "GNDStk.h"
#include "v2.0/pops/Shell.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct PhotonEmissionProbabilitiesClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ PhotonEmissionProbabilities
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct PhotonEmissionProbabilitiesClass *PhotonEmissionProbabilities;

// --- Const-aware handles.
typedef const struct PhotonEmissionProbabilitiesClass *const ConstHandle2ConstPhotonEmissionProbabilities;
typedef       struct PhotonEmissionProbabilitiesClass *const ConstHandle2PhotonEmissionProbabilities;
typedef const struct PhotonEmissionProbabilitiesClass *      Handle2ConstPhotonEmissionProbabilities;
typedef       struct PhotonEmissionProbabilitiesClass *      Handle2PhotonEmissionProbabilities;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstPhotonEmissionProbabilities
PhotonEmissionProbabilitiesDefaultConst();

// +++ Create, default
extern_c Handle2PhotonEmissionProbabilities
PhotonEmissionProbabilitiesDefault();

// --- Create, general, const
extern_c Handle2ConstPhotonEmissionProbabilities
PhotonEmissionProbabilitiesCreateConst(
   ConstHandle2ConstShell shell
);

// +++ Create, general
extern_c Handle2PhotonEmissionProbabilities
PhotonEmissionProbabilitiesCreate(
   ConstHandle2ConstShell shell
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
PhotonEmissionProbabilitiesAssign(ConstHandle2PhotonEmissionProbabilities self, ConstHandle2ConstPhotonEmissionProbabilities from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
PhotonEmissionProbabilitiesDelete(ConstHandle2ConstPhotonEmissionProbabilities self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
PhotonEmissionProbabilitiesRead(ConstHandle2PhotonEmissionProbabilities self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
PhotonEmissionProbabilitiesWrite(ConstHandle2ConstPhotonEmissionProbabilities self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
PhotonEmissionProbabilitiesPrint(ConstHandle2ConstPhotonEmissionProbabilities self);

// +++ Print to standard output, as XML
extern_c int
PhotonEmissionProbabilitiesPrintXML(ConstHandle2ConstPhotonEmissionProbabilities self);

// +++ Print to standard output, as JSON
extern_c int
PhotonEmissionProbabilitiesPrintJSON(ConstHandle2ConstPhotonEmissionProbabilities self);


// -----------------------------------------------------------------------------
// Child: shell
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PhotonEmissionProbabilitiesShellHas(ConstHandle2ConstPhotonEmissionProbabilities self);

// --- Get, const
extern_c Handle2ConstShell
PhotonEmissionProbabilitiesShellGetConst(ConstHandle2ConstPhotonEmissionProbabilities self);

// +++ Get, non-const
extern_c Handle2Shell
PhotonEmissionProbabilitiesShellGet(ConstHandle2PhotonEmissionProbabilities self);

// +++ Set
extern_c void
PhotonEmissionProbabilitiesShellSet(ConstHandle2PhotonEmissionProbabilities self, ConstHandle2ConstShell shell);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/PhotonEmissionProbabilities/src/custom.h"

#undef extern_c
#endif
