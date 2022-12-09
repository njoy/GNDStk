
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
// FissionComponent is the basic handle type in this file. Example:
//    // Create a default FissionComponent object:
//    FissionComponent handle = FissionComponentDefault();
// Functions involving FissionComponent are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_FISSIONTRANSPORT_FISSIONCOMPONENT
#define C_INTERFACE_TEST_V2_0_FISSIONTRANSPORT_FISSIONCOMPONENT

#include "GNDStk.h"
#include "v2.0/transport/CrossSection.h"
#include "v2.0/transport/OutputChannel.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct FissionComponentClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ FissionComponent
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct FissionComponentClass *FissionComponent;

// --- Const-aware handles.
typedef const struct FissionComponentClass *const ConstHandle2ConstFissionComponent;
typedef       struct FissionComponentClass *const ConstHandle2FissionComponent;
typedef const struct FissionComponentClass *      Handle2ConstFissionComponent;
typedef       struct FissionComponentClass *      Handle2FissionComponent;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstFissionComponent
FissionComponentDefaultConst();

// +++ Create, default
extern_c Handle2FissionComponent
FissionComponentDefault();

// --- Create, general, const
extern_c Handle2ConstFissionComponent
FissionComponentCreateConst(
   const Integer32 ENDF_MT,
   const XMLName fissionGenre,
   const XMLName label,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstOutputChannel outputChannel
);

// +++ Create, general
extern_c Handle2FissionComponent
FissionComponentCreate(
   const Integer32 ENDF_MT,
   const XMLName fissionGenre,
   const XMLName label,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstOutputChannel outputChannel
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
FissionComponentAssign(ConstHandle2FissionComponent This, ConstHandle2ConstFissionComponent from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
FissionComponentDelete(ConstHandle2ConstFissionComponent This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
FissionComponentRead(ConstHandle2FissionComponent This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
FissionComponentWrite(ConstHandle2ConstFissionComponent This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
FissionComponentPrint(ConstHandle2ConstFissionComponent This);

// +++ Print to standard output, as XML
extern_c int
FissionComponentPrintXML(ConstHandle2ConstFissionComponent This);

// +++ Print to standard output, as JSON
extern_c int
FissionComponentPrintJSON(ConstHandle2ConstFissionComponent This);


// -----------------------------------------------------------------------------
// Metadatum: ENDF_MT
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
FissionComponentENDFMTHas(ConstHandle2ConstFissionComponent This);

// +++ Get
// +++ Returns by value
extern_c Integer32
FissionComponentENDFMTGet(ConstHandle2ConstFissionComponent This);

// +++ Set
extern_c void
FissionComponentENDFMTSet(ConstHandle2FissionComponent This, const Integer32 ENDF_MT);


// -----------------------------------------------------------------------------
// Metadatum: fissionGenre
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
FissionComponentFissionGenreHas(ConstHandle2ConstFissionComponent This);

// +++ Get
// +++ Returns by value
extern_c XMLName
FissionComponentFissionGenreGet(ConstHandle2ConstFissionComponent This);

// +++ Set
extern_c void
FissionComponentFissionGenreSet(ConstHandle2FissionComponent This, const XMLName fissionGenre);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
FissionComponentLabelHas(ConstHandle2ConstFissionComponent This);

// +++ Get
// +++ Returns by value
extern_c XMLName
FissionComponentLabelGet(ConstHandle2ConstFissionComponent This);

// +++ Set
extern_c void
FissionComponentLabelSet(ConstHandle2FissionComponent This, const XMLName label);


// -----------------------------------------------------------------------------
// Child: crossSection
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
FissionComponentCrossSectionHas(ConstHandle2ConstFissionComponent This);

// --- Get, const
extern_c Handle2ConstCrossSection
FissionComponentCrossSectionGetConst(ConstHandle2ConstFissionComponent This);

// +++ Get, non-const
extern_c Handle2CrossSection
FissionComponentCrossSectionGet(ConstHandle2FissionComponent This);

// +++ Set
extern_c void
FissionComponentCrossSectionSet(ConstHandle2FissionComponent This, ConstHandle2ConstCrossSection crossSection);


// -----------------------------------------------------------------------------
// Child: outputChannel
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
FissionComponentOutputChannelHas(ConstHandle2ConstFissionComponent This);

// --- Get, const
extern_c Handle2ConstOutputChannel
FissionComponentOutputChannelGetConst(ConstHandle2ConstFissionComponent This);

// +++ Get, non-const
extern_c Handle2OutputChannel
FissionComponentOutputChannelGet(ConstHandle2FissionComponent This);

// +++ Set
extern_c void
FissionComponentOutputChannelSet(ConstHandle2FissionComponent This, ConstHandle2ConstOutputChannel outputChannel);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
