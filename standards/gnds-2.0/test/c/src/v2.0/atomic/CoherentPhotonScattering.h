
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
// CoherentPhotonScattering is the basic handle type in this file. Example:
//    // Create a default CoherentPhotonScattering object:
//    CoherentPhotonScattering handle = CoherentPhotonScatteringDefault();
// Functions involving CoherentPhotonScattering are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_ATOMIC_COHERENTPHOTONSCATTERING
#define C_INTERFACE_TEST_V2_0_ATOMIC_COHERENTPHOTONSCATTERING

#include "GNDStk.h"
#include "v2.0/atomic/FormFactor.h"
#include "v2.0/atomic/RealAnomalousFactor.h"
#include "v2.0/atomic/ImaginaryAnomalousFactor.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct CoherentPhotonScatteringClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ CoherentPhotonScattering
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct CoherentPhotonScatteringClass *CoherentPhotonScattering;

// --- Const-aware handles.
typedef const struct CoherentPhotonScatteringClass *const ConstHandle2ConstCoherentPhotonScattering;
typedef       struct CoherentPhotonScatteringClass *const ConstHandle2CoherentPhotonScattering;
typedef const struct CoherentPhotonScatteringClass *      Handle2ConstCoherentPhotonScattering;
typedef       struct CoherentPhotonScatteringClass *      Handle2CoherentPhotonScattering;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstCoherentPhotonScattering
CoherentPhotonScatteringDefaultConst();

// +++ Create, default
extern_c Handle2CoherentPhotonScattering
CoherentPhotonScatteringDefault();

// --- Create, general, const
extern_c Handle2ConstCoherentPhotonScattering
CoherentPhotonScatteringCreateConst(
   const char *const href,
   const XMLName label,
   const XMLName pid,
   const enums::Frame productFrame,
   ConstHandle2ConstFormFactor formFactor,
   ConstHandle2ConstRealAnomalousFactor realAnomalousFactor,
   ConstHandle2ConstImaginaryAnomalousFactor imaginaryAnomalousFactor
);

// +++ Create, general
extern_c Handle2CoherentPhotonScattering
CoherentPhotonScatteringCreate(
   const char *const href,
   const XMLName label,
   const XMLName pid,
   const enums::Frame productFrame,
   ConstHandle2ConstFormFactor formFactor,
   ConstHandle2ConstRealAnomalousFactor realAnomalousFactor,
   ConstHandle2ConstImaginaryAnomalousFactor imaginaryAnomalousFactor
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
CoherentPhotonScatteringAssign(ConstHandle2CoherentPhotonScattering This, ConstHandle2ConstCoherentPhotonScattering from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
CoherentPhotonScatteringDelete(ConstHandle2ConstCoherentPhotonScattering This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
CoherentPhotonScatteringRead(ConstHandle2CoherentPhotonScattering This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
CoherentPhotonScatteringWrite(ConstHandle2ConstCoherentPhotonScattering This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
CoherentPhotonScatteringPrint(ConstHandle2ConstCoherentPhotonScattering This);

// +++ Print to standard output, as XML
extern_c int
CoherentPhotonScatteringPrintXML(ConstHandle2ConstCoherentPhotonScattering This);

// +++ Print to standard output, as JSON
extern_c int
CoherentPhotonScatteringPrintJSON(ConstHandle2ConstCoherentPhotonScattering This);


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CoherentPhotonScatteringHrefHas(ConstHandle2ConstCoherentPhotonScattering This);

// +++ Get
// +++ Returns by value
extern_c const char *
CoherentPhotonScatteringHrefGet(ConstHandle2ConstCoherentPhotonScattering This);

// +++ Set
extern_c void
CoherentPhotonScatteringHrefSet(ConstHandle2CoherentPhotonScattering This, const char *const href);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CoherentPhotonScatteringLabelHas(ConstHandle2ConstCoherentPhotonScattering This);

// +++ Get
// +++ Returns by value
extern_c XMLName
CoherentPhotonScatteringLabelGet(ConstHandle2ConstCoherentPhotonScattering This);

// +++ Set
extern_c void
CoherentPhotonScatteringLabelSet(ConstHandle2CoherentPhotonScattering This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: pid
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CoherentPhotonScatteringPidHas(ConstHandle2ConstCoherentPhotonScattering This);

// +++ Get
// +++ Returns by value
extern_c XMLName
CoherentPhotonScatteringPidGet(ConstHandle2ConstCoherentPhotonScattering This);

// +++ Set
extern_c void
CoherentPhotonScatteringPidSet(ConstHandle2CoherentPhotonScattering This, const XMLName pid);


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CoherentPhotonScatteringProductFrameHas(ConstHandle2ConstCoherentPhotonScattering This);

// +++ Get
// +++ Returns by value
extern_c enums::Frame
CoherentPhotonScatteringProductFrameGet(ConstHandle2ConstCoherentPhotonScattering This);

// +++ Set
extern_c void
CoherentPhotonScatteringProductFrameSet(ConstHandle2CoherentPhotonScattering This, const enums::Frame productFrame);


// -----------------------------------------------------------------------------
// Child: formFactor
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CoherentPhotonScatteringFormFactorHas(ConstHandle2ConstCoherentPhotonScattering This);

// --- Get, const
extern_c Handle2ConstFormFactor
CoherentPhotonScatteringFormFactorGetConst(ConstHandle2ConstCoherentPhotonScattering This);

// +++ Get, non-const
extern_c Handle2FormFactor
CoherentPhotonScatteringFormFactorGet(ConstHandle2CoherentPhotonScattering This);

// +++ Set
extern_c void
CoherentPhotonScatteringFormFactorSet(ConstHandle2CoherentPhotonScattering This, ConstHandle2ConstFormFactor formFactor);


// -----------------------------------------------------------------------------
// Child: realAnomalousFactor
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CoherentPhotonScatteringRealAnomalousFactorHas(ConstHandle2ConstCoherentPhotonScattering This);

// --- Get, const
extern_c Handle2ConstRealAnomalousFactor
CoherentPhotonScatteringRealAnomalousFactorGetConst(ConstHandle2ConstCoherentPhotonScattering This);

// +++ Get, non-const
extern_c Handle2RealAnomalousFactor
CoherentPhotonScatteringRealAnomalousFactorGet(ConstHandle2CoherentPhotonScattering This);

// +++ Set
extern_c void
CoherentPhotonScatteringRealAnomalousFactorSet(ConstHandle2CoherentPhotonScattering This, ConstHandle2ConstRealAnomalousFactor realAnomalousFactor);


// -----------------------------------------------------------------------------
// Child: imaginaryAnomalousFactor
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CoherentPhotonScatteringImaginaryAnomalousFactorHas(ConstHandle2ConstCoherentPhotonScattering This);

// --- Get, const
extern_c Handle2ConstImaginaryAnomalousFactor
CoherentPhotonScatteringImaginaryAnomalousFactorGetConst(ConstHandle2ConstCoherentPhotonScattering This);

// +++ Get, non-const
extern_c Handle2ImaginaryAnomalousFactor
CoherentPhotonScatteringImaginaryAnomalousFactorGet(ConstHandle2CoherentPhotonScattering This);

// +++ Set
extern_c void
CoherentPhotonScatteringImaginaryAnomalousFactorSet(ConstHandle2CoherentPhotonScattering This, ConstHandle2ConstImaginaryAnomalousFactor imaginaryAnomalousFactor);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
