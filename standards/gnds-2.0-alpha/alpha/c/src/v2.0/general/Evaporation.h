
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
// Evaporation is the basic handle type in this file. Example:
//    // Create a default Evaporation object:
//    Evaporation handle = EvaporationDefault();
// Functions involving Evaporation are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_EVAPORATION
#define C_INTERFACE_ALPHA_V2_0_GENERAL_EVAPORATION

#include "GNDStk.h"
#include "v2.0/general/U.h"
#include "v2.0/general/Theta.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct EvaporationClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Evaporation
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct EvaporationClass *Evaporation;

// --- Const-aware handles.
typedef const struct EvaporationClass *const ConstHandle2ConstEvaporation;
typedef       struct EvaporationClass *const ConstHandle2Evaporation;
typedef const struct EvaporationClass *      Handle2ConstEvaporation;
typedef       struct EvaporationClass *      Handle2Evaporation;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstEvaporation
EvaporationDefaultConst();

// +++ Create, default
extern_c Handle2Evaporation
EvaporationDefault();

// --- Create, general, const
extern_c Handle2ConstEvaporation
EvaporationCreateConst(
   ConstHandle2ConstU U,
   ConstHandle2ConstTheta theta
);

// +++ Create, general
extern_c Handle2Evaporation
EvaporationCreate(
   ConstHandle2ConstU U,
   ConstHandle2ConstTheta theta
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
EvaporationAssign(ConstHandle2Evaporation This, ConstHandle2ConstEvaporation from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
EvaporationDelete(ConstHandle2ConstEvaporation This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
EvaporationRead(ConstHandle2Evaporation This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
EvaporationWrite(ConstHandle2ConstEvaporation This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
EvaporationPrint(ConstHandle2ConstEvaporation This);

// +++ Print to standard output, as XML
extern_c int
EvaporationPrintXML(ConstHandle2ConstEvaporation This);

// +++ Print to standard output, as JSON
extern_c int
EvaporationPrintJSON(ConstHandle2ConstEvaporation This);


// -----------------------------------------------------------------------------
// Child: U
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
EvaporationUHas(ConstHandle2ConstEvaporation This);

// --- Get, const
extern_c Handle2ConstU
EvaporationUGetConst(ConstHandle2ConstEvaporation This);

// +++ Get, non-const
extern_c Handle2U
EvaporationUGet(ConstHandle2Evaporation This);

// +++ Set
extern_c void
EvaporationUSet(ConstHandle2Evaporation This, ConstHandle2ConstU U);


// -----------------------------------------------------------------------------
// Child: theta
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
EvaporationThetaHas(ConstHandle2ConstEvaporation This);

// --- Get, const
extern_c Handle2ConstTheta
EvaporationThetaGetConst(ConstHandle2ConstEvaporation This);

// +++ Get, non-const
extern_c Handle2Theta
EvaporationThetaGet(ConstHandle2Evaporation This);

// +++ Set
extern_c void
EvaporationThetaSet(ConstHandle2Evaporation This, ConstHandle2ConstTheta theta);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Evaporation/src/custom.h"

#undef extern_c
#endif
