
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
// GeneralEvaporation is the basic handle type in this file. Example:
//    // Create a default GeneralEvaporation object:
//    GeneralEvaporation handle = GeneralEvaporationDefault();
// Functions involving GeneralEvaporation are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_GENERALEVAPORATION
#define C_INTERFACE_ALPHA_V2_0_GENERAL_GENERALEVAPORATION

#include "GNDStk.h"
#include "v2.0/general/U.h"
#include "v2.0/general/Theta.h"
#include "v2.0/general/G.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct GeneralEvaporationClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ GeneralEvaporation
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct GeneralEvaporationClass *GeneralEvaporation;

// --- Const-aware handles.
typedef const struct GeneralEvaporationClass *const ConstHandle2ConstGeneralEvaporation;
typedef       struct GeneralEvaporationClass *const ConstHandle2GeneralEvaporation;
typedef const struct GeneralEvaporationClass *      Handle2ConstGeneralEvaporation;
typedef       struct GeneralEvaporationClass *      Handle2GeneralEvaporation;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstGeneralEvaporation
GeneralEvaporationDefaultConst();

// +++ Create, default
extern_c Handle2GeneralEvaporation
GeneralEvaporationDefault();

// --- Create, general, const
extern_c Handle2ConstGeneralEvaporation
GeneralEvaporationCreateConst(
   ConstHandle2ConstU U,
   ConstHandle2ConstTheta theta,
   ConstHandle2ConstG g
);

// +++ Create, general
extern_c Handle2GeneralEvaporation
GeneralEvaporationCreate(
   ConstHandle2ConstU U,
   ConstHandle2ConstTheta theta,
   ConstHandle2ConstG g
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
GeneralEvaporationAssign(ConstHandle2GeneralEvaporation self, ConstHandle2ConstGeneralEvaporation from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
GeneralEvaporationDelete(ConstHandle2ConstGeneralEvaporation self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
GeneralEvaporationRead(ConstHandle2GeneralEvaporation self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
GeneralEvaporationWrite(ConstHandle2ConstGeneralEvaporation self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
GeneralEvaporationPrint(ConstHandle2ConstGeneralEvaporation self);

// +++ Print to standard output, as XML
extern_c int
GeneralEvaporationPrintXML(ConstHandle2ConstGeneralEvaporation self);

// +++ Print to standard output, as JSON
extern_c int
GeneralEvaporationPrintJSON(ConstHandle2ConstGeneralEvaporation self);


// -----------------------------------------------------------------------------
// Child: U
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GeneralEvaporationUHas(ConstHandle2ConstGeneralEvaporation self);

// --- Get, const
extern_c Handle2ConstU
GeneralEvaporationUGetConst(ConstHandle2ConstGeneralEvaporation self);

// +++ Get, non-const
extern_c Handle2U
GeneralEvaporationUGet(ConstHandle2GeneralEvaporation self);

// +++ Set
extern_c void
GeneralEvaporationUSet(ConstHandle2GeneralEvaporation self, ConstHandle2ConstU U);


// -----------------------------------------------------------------------------
// Child: theta
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GeneralEvaporationThetaHas(ConstHandle2ConstGeneralEvaporation self);

// --- Get, const
extern_c Handle2ConstTheta
GeneralEvaporationThetaGetConst(ConstHandle2ConstGeneralEvaporation self);

// +++ Get, non-const
extern_c Handle2Theta
GeneralEvaporationThetaGet(ConstHandle2GeneralEvaporation self);

// +++ Set
extern_c void
GeneralEvaporationThetaSet(ConstHandle2GeneralEvaporation self, ConstHandle2ConstTheta theta);


// -----------------------------------------------------------------------------
// Child: g
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GeneralEvaporationGHas(ConstHandle2ConstGeneralEvaporation self);

// --- Get, const
extern_c Handle2ConstG
GeneralEvaporationGGetConst(ConstHandle2ConstGeneralEvaporation self);

// +++ Get, non-const
extern_c Handle2G
GeneralEvaporationGGet(ConstHandle2GeneralEvaporation self);

// +++ Set
extern_c void
GeneralEvaporationGSet(ConstHandle2GeneralEvaporation self, ConstHandle2ConstG g);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/GeneralEvaporation/src/custom.h"

#undef extern_c
#endif
