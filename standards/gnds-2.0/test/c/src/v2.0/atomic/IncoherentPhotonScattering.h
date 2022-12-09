
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
// IncoherentPhotonScattering is the basic handle type in this file. Example:
//    // Create a default IncoherentPhotonScattering object:
//    IncoherentPhotonScattering handle = IncoherentPhotonScatteringDefault();
// Functions involving IncoherentPhotonScattering are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_ATOMIC_INCOHERENTPHOTONSCATTERING
#define C_INTERFACE_TEST_V2_0_ATOMIC_INCOHERENTPHOTONSCATTERING

#include "GNDStk.h"
#include "v2.0/atomic/ScatteringFactor.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct IncoherentPhotonScatteringClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ IncoherentPhotonScattering
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct IncoherentPhotonScatteringClass *IncoherentPhotonScattering;

// --- Const-aware handles.
typedef const struct IncoherentPhotonScatteringClass *const ConstHandle2ConstIncoherentPhotonScattering;
typedef       struct IncoherentPhotonScatteringClass *const ConstHandle2IncoherentPhotonScattering;
typedef const struct IncoherentPhotonScatteringClass *      Handle2ConstIncoherentPhotonScattering;
typedef       struct IncoherentPhotonScatteringClass *      Handle2IncoherentPhotonScattering;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstIncoherentPhotonScattering
IncoherentPhotonScatteringDefaultConst();

// +++ Create, default
extern_c Handle2IncoherentPhotonScattering
IncoherentPhotonScatteringDefault();

// --- Create, general, const
extern_c Handle2ConstIncoherentPhotonScattering
IncoherentPhotonScatteringCreateConst(
   const char *const href,
   const XMLName label,
   const XMLName pid,
   const enums::Frame productFrame,
   ConstHandle2ConstScatteringFactor scatteringFactor
);

// +++ Create, general
extern_c Handle2IncoherentPhotonScattering
IncoherentPhotonScatteringCreate(
   const char *const href,
   const XMLName label,
   const XMLName pid,
   const enums::Frame productFrame,
   ConstHandle2ConstScatteringFactor scatteringFactor
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
IncoherentPhotonScatteringAssign(ConstHandle2IncoherentPhotonScattering This, ConstHandle2ConstIncoherentPhotonScattering from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
IncoherentPhotonScatteringDelete(ConstHandle2ConstIncoherentPhotonScattering This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
IncoherentPhotonScatteringRead(ConstHandle2IncoherentPhotonScattering This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
IncoherentPhotonScatteringWrite(ConstHandle2ConstIncoherentPhotonScattering This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
IncoherentPhotonScatteringPrint(ConstHandle2ConstIncoherentPhotonScattering This);

// +++ Print to standard output, as XML
extern_c int
IncoherentPhotonScatteringPrintXML(ConstHandle2ConstIncoherentPhotonScattering This);

// +++ Print to standard output, as JSON
extern_c int
IncoherentPhotonScatteringPrintJSON(ConstHandle2ConstIncoherentPhotonScattering This);


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
IncoherentPhotonScatteringHrefHas(ConstHandle2ConstIncoherentPhotonScattering This);

// +++ Get
// +++ Returns by value
extern_c const char *
IncoherentPhotonScatteringHrefGet(ConstHandle2ConstIncoherentPhotonScattering This);

// +++ Set
extern_c void
IncoherentPhotonScatteringHrefSet(ConstHandle2IncoherentPhotonScattering This, const char *const href);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
IncoherentPhotonScatteringLabelHas(ConstHandle2ConstIncoherentPhotonScattering This);

// +++ Get
// +++ Returns by value
extern_c XMLName
IncoherentPhotonScatteringLabelGet(ConstHandle2ConstIncoherentPhotonScattering This);

// +++ Set
extern_c void
IncoherentPhotonScatteringLabelSet(ConstHandle2IncoherentPhotonScattering This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: pid
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
IncoherentPhotonScatteringPidHas(ConstHandle2ConstIncoherentPhotonScattering This);

// +++ Get
// +++ Returns by value
extern_c XMLName
IncoherentPhotonScatteringPidGet(ConstHandle2ConstIncoherentPhotonScattering This);

// +++ Set
extern_c void
IncoherentPhotonScatteringPidSet(ConstHandle2IncoherentPhotonScattering This, const XMLName pid);


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
IncoherentPhotonScatteringProductFrameHas(ConstHandle2ConstIncoherentPhotonScattering This);

// +++ Get
// +++ Returns by value
extern_c enums::Frame
IncoherentPhotonScatteringProductFrameGet(ConstHandle2ConstIncoherentPhotonScattering This);

// +++ Set
extern_c void
IncoherentPhotonScatteringProductFrameSet(ConstHandle2IncoherentPhotonScattering This, const enums::Frame productFrame);


// -----------------------------------------------------------------------------
// Child: scatteringFactor
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
IncoherentPhotonScatteringScatteringFactorHas(ConstHandle2ConstIncoherentPhotonScattering This);

// --- Get, const
extern_c Handle2ConstScatteringFactor
IncoherentPhotonScatteringScatteringFactorGetConst(ConstHandle2ConstIncoherentPhotonScattering This);

// +++ Get, non-const
extern_c Handle2ScatteringFactor
IncoherentPhotonScatteringScatteringFactorGet(ConstHandle2IncoherentPhotonScattering This);

// +++ Set
extern_c void
IncoherentPhotonScatteringScatteringFactorSet(ConstHandle2IncoherentPhotonScattering This, ConstHandle2ConstScatteringFactor scatteringFactor);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
