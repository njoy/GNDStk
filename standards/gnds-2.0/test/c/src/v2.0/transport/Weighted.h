
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
// Weighted is the basic handle type in this file. Example:
//    // Create a default Weighted object:
//    Weighted handle = WeightedDefault();
// Functions involving Weighted are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TRANSPORT_WEIGHTED
#define C_INTERFACE_TEST_V2_0_TRANSPORT_WEIGHTED

#include "GNDStk.h"
#include "v2.0/containers/XYs1d.h"
#include "v2.0/containers/XYs2d.h"
#include "v2.0/transport/Evaporation.h"
#include "v2.0/transport/GeneralEvaporation.h"
#include "v2.0/fissionTransport/SimpleMaxwellianFission.h"
#include "v2.0/fissionTransport/Watt.h"
#include "v2.0/fissionTransport/MadlandNix.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct WeightedClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Weighted
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct WeightedClass *Weighted;

// --- Const-aware handles.
typedef const struct WeightedClass *const ConstHandle2ConstWeighted;
typedef       struct WeightedClass *const ConstHandle2Weighted;
typedef const struct WeightedClass *      Handle2ConstWeighted;
typedef       struct WeightedClass *      Handle2Weighted;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstWeighted
WeightedDefaultConst();

// +++ Create, default
extern_c Handle2Weighted
WeightedDefault();

// --- Create, general, const
extern_c Handle2ConstWeighted
WeightedCreateConst(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstXYs2d XYs2d,
   ConstHandle2ConstEvaporation evaporation,
   ConstHandle2ConstGeneralEvaporation generalEvaporation,
   ConstHandle2ConstSimpleMaxwellianFission simpleMaxwellianFission,
   ConstHandle2ConstWatt Watt,
   ConstHandle2ConstMadlandNix MadlandNix
);

// +++ Create, general
extern_c Handle2Weighted
WeightedCreate(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstXYs2d XYs2d,
   ConstHandle2ConstEvaporation evaporation,
   ConstHandle2ConstGeneralEvaporation generalEvaporation,
   ConstHandle2ConstSimpleMaxwellianFission simpleMaxwellianFission,
   ConstHandle2ConstWatt Watt,
   ConstHandle2ConstMadlandNix MadlandNix
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
WeightedAssign(ConstHandle2Weighted This, ConstHandle2ConstWeighted from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
WeightedDelete(ConstHandle2ConstWeighted This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
WeightedRead(ConstHandle2Weighted This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
WeightedWrite(ConstHandle2ConstWeighted This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
WeightedPrint(ConstHandle2ConstWeighted This);

// +++ Print to standard output, as XML
extern_c int
WeightedPrintXML(ConstHandle2ConstWeighted This);

// +++ Print to standard output, as JSON
extern_c int
WeightedPrintJSON(ConstHandle2ConstWeighted This);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
WeightedXYs1dHas(ConstHandle2ConstWeighted This);

// --- Get, const
extern_c Handle2ConstXYs1d
WeightedXYs1dGetConst(ConstHandle2ConstWeighted This);

// +++ Get, non-const
extern_c Handle2XYs1d
WeightedXYs1dGet(ConstHandle2Weighted This);

// +++ Set
extern_c void
WeightedXYs1dSet(ConstHandle2Weighted This, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Child: XYs2d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
WeightedXYs2dHas(ConstHandle2ConstWeighted This);

// --- Get, const
extern_c Handle2ConstXYs2d
WeightedXYs2dGetConst(ConstHandle2ConstWeighted This);

// +++ Get, non-const
extern_c Handle2XYs2d
WeightedXYs2dGet(ConstHandle2Weighted This);

// +++ Set
extern_c void
WeightedXYs2dSet(ConstHandle2Weighted This, ConstHandle2ConstXYs2d XYs2d);


// -----------------------------------------------------------------------------
// Child: evaporation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
WeightedEvaporationHas(ConstHandle2ConstWeighted This);

// --- Get, const
extern_c Handle2ConstEvaporation
WeightedEvaporationGetConst(ConstHandle2ConstWeighted This);

// +++ Get, non-const
extern_c Handle2Evaporation
WeightedEvaporationGet(ConstHandle2Weighted This);

// +++ Set
extern_c void
WeightedEvaporationSet(ConstHandle2Weighted This, ConstHandle2ConstEvaporation evaporation);


// -----------------------------------------------------------------------------
// Child: generalEvaporation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
WeightedGeneralEvaporationHas(ConstHandle2ConstWeighted This);

// --- Get, const
extern_c Handle2ConstGeneralEvaporation
WeightedGeneralEvaporationGetConst(ConstHandle2ConstWeighted This);

// +++ Get, non-const
extern_c Handle2GeneralEvaporation
WeightedGeneralEvaporationGet(ConstHandle2Weighted This);

// +++ Set
extern_c void
WeightedGeneralEvaporationSet(ConstHandle2Weighted This, ConstHandle2ConstGeneralEvaporation generalEvaporation);


// -----------------------------------------------------------------------------
// Child: simpleMaxwellianFission
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
WeightedSimpleMaxwellianFissionHas(ConstHandle2ConstWeighted This);

// --- Get, const
extern_c Handle2ConstSimpleMaxwellianFission
WeightedSimpleMaxwellianFissionGetConst(ConstHandle2ConstWeighted This);

// +++ Get, non-const
extern_c Handle2SimpleMaxwellianFission
WeightedSimpleMaxwellianFissionGet(ConstHandle2Weighted This);

// +++ Set
extern_c void
WeightedSimpleMaxwellianFissionSet(ConstHandle2Weighted This, ConstHandle2ConstSimpleMaxwellianFission simpleMaxwellianFission);


// -----------------------------------------------------------------------------
// Child: Watt
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
WeightedWattHas(ConstHandle2ConstWeighted This);

// --- Get, const
extern_c Handle2ConstWatt
WeightedWattGetConst(ConstHandle2ConstWeighted This);

// +++ Get, non-const
extern_c Handle2Watt
WeightedWattGet(ConstHandle2Weighted This);

// +++ Set
extern_c void
WeightedWattSet(ConstHandle2Weighted This, ConstHandle2ConstWatt Watt);


// -----------------------------------------------------------------------------
// Child: MadlandNix
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
WeightedMadlandNixHas(ConstHandle2ConstWeighted This);

// --- Get, const
extern_c Handle2ConstMadlandNix
WeightedMadlandNixGetConst(ConstHandle2ConstWeighted This);

// +++ Get, non-const
extern_c Handle2MadlandNix
WeightedMadlandNixGet(ConstHandle2Weighted This);

// +++ Set
extern_c void
WeightedMadlandNixSet(ConstHandle2Weighted This, ConstHandle2ConstMadlandNix MadlandNix);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
