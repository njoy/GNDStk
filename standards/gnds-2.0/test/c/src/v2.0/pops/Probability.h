
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
// Probability is the basic handle type in this file. Example:
//    // Create a default Probability object:
//    Probability handle = ProbabilityDefault();
// Functions involving Probability are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_POPS_PROBABILITY
#define C_INTERFACE_TEST_V2_0_POPS_PROBABILITY

#include "GNDStk.h"
#include "v2.0/containers/Double.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ProbabilityClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Probability
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ProbabilityClass *Probability;

// --- Const-aware handles.
typedef const struct ProbabilityClass *const ConstHandle2ConstProbability;
typedef       struct ProbabilityClass *const ConstHandle2Probability;
typedef const struct ProbabilityClass *      Handle2ConstProbability;
typedef       struct ProbabilityClass *      Handle2Probability;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstProbability
ProbabilityDefaultConst();

// +++ Create, default
extern_c Handle2Probability
ProbabilityDefault();

// --- Create, general, const
extern_c Handle2ConstProbability
ProbabilityCreateConst(
   ConstHandle2Double *const Double, const size_t DoubleSize
);

// +++ Create, general
extern_c Handle2Probability
ProbabilityCreate(
   ConstHandle2Double *const Double, const size_t DoubleSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ProbabilityAssign(ConstHandle2Probability self, ConstHandle2ConstProbability from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ProbabilityDelete(ConstHandle2ConstProbability self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ProbabilityRead(ConstHandle2Probability self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ProbabilityWrite(ConstHandle2ConstProbability self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ProbabilityPrint(ConstHandle2ConstProbability self);

// +++ Print to standard output, as XML
extern_c int
ProbabilityPrintXML(ConstHandle2ConstProbability self);

// +++ Print to standard output, as JSON
extern_c int
ProbabilityPrintJSON(ConstHandle2ConstProbability self);


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ProbabilityDoubleHas(ConstHandle2ConstProbability self);

// +++ Clear
extern_c void
ProbabilityDoubleClear(ConstHandle2Probability self);

// +++ Size
extern_c size_t
ProbabilityDoubleSize(ConstHandle2ConstProbability self);

// +++ Add
extern_c void
ProbabilityDoubleAdd(ConstHandle2Probability self, ConstHandle2ConstDouble Double);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstDouble
ProbabilityDoubleGetConst(ConstHandle2ConstProbability self, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Double
ProbabilityDoubleGet(ConstHandle2Probability self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ProbabilityDoubleSet(
   ConstHandle2Probability self,
   const size_t index_,
   ConstHandle2ConstDouble Double
);

// +++ Has, by label
extern_c int
ProbabilityDoubleHasByLabel(
   ConstHandle2ConstProbability self,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstDouble
ProbabilityDoubleGetByLabelConst(
   ConstHandle2ConstProbability self,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2Double
ProbabilityDoubleGetByLabel(
   ConstHandle2Probability self,
   const XMLName label
);

// +++ Set, by label
extern_c void
ProbabilityDoubleSetByLabel(
   ConstHandle2Probability self,
   const XMLName label,
   ConstHandle2ConstDouble Double
);

// +++ Has, by unit
extern_c int
ProbabilityDoubleHasByUnit(
   ConstHandle2ConstProbability self,
   const XMLName unit
);

// --- Get, by unit, const
extern_c Handle2ConstDouble
ProbabilityDoubleGetByUnitConst(
   ConstHandle2ConstProbability self,
   const XMLName unit
);

// +++ Get, by unit, non-const
extern_c Handle2Double
ProbabilityDoubleGetByUnit(
   ConstHandle2Probability self,
   const XMLName unit
);

// +++ Set, by unit
extern_c void
ProbabilityDoubleSetByUnit(
   ConstHandle2Probability self,
   const XMLName unit,
   ConstHandle2ConstDouble Double
);

// +++ Has, by value
extern_c int
ProbabilityDoubleHasByValue(
   ConstHandle2ConstProbability self,
   const Float64 value
);

// --- Get, by value, const
extern_c Handle2ConstDouble
ProbabilityDoubleGetByValueConst(
   ConstHandle2ConstProbability self,
   const Float64 value
);

// +++ Get, by value, non-const
extern_c Handle2Double
ProbabilityDoubleGetByValue(
   ConstHandle2Probability self,
   const Float64 value
);

// +++ Set, by value
extern_c void
ProbabilityDoubleSetByValue(
   ConstHandle2Probability self,
   const Float64 value,
   ConstHandle2ConstDouble Double
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/pops/Probability/src/custom.h"

#undef extern_c
#endif
