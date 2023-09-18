
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
// Productions is the basic handle type in this file. Example:
//    // Create a default Productions object:
//    Productions handle = ProductionsDefault();
// Functions involving Productions are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_PRODUCTIONS
#define C_INTERFACE_GNDS_V2_0_GENERAL_PRODUCTIONS

#include "GNDStk.h"
#include "v2.0/general/Production.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ProductionsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Productions
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ProductionsClass *Productions;

// --- Const-aware handles.
typedef const struct ProductionsClass *const ConstHandle2ConstProductions;
typedef       struct ProductionsClass *const ConstHandle2Productions;
typedef const struct ProductionsClass *      Handle2ConstProductions;
typedef       struct ProductionsClass *      Handle2Productions;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstProductions
ProductionsDefaultConst();

// +++ Create, default
extern_c Handle2Productions
ProductionsDefault();

// --- Create, general, const
extern_c Handle2ConstProductions
ProductionsCreateConst(
   ConstHandle2Production *const production, const size_t productionSize
);

// +++ Create, general
extern_c Handle2Productions
ProductionsCreate(
   ConstHandle2Production *const production, const size_t productionSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ProductionsAssign(ConstHandle2Productions self, ConstHandle2ConstProductions from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ProductionsDelete(ConstHandle2ConstProductions self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ProductionsRead(ConstHandle2Productions self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ProductionsWrite(ConstHandle2ConstProductions self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ProductionsPrint(ConstHandle2ConstProductions self);

// +++ Print to standard output, as XML
extern_c int
ProductionsPrintXML(ConstHandle2ConstProductions self);

// +++ Print to standard output, as JSON
extern_c int
ProductionsPrintJSON(ConstHandle2ConstProductions self);


// -----------------------------------------------------------------------------
// Child: production
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ProductionsProductionHas(ConstHandle2ConstProductions self);

// +++ Clear
extern_c void
ProductionsProductionClear(ConstHandle2Productions self);

// +++ Size
extern_c size_t
ProductionsProductionSize(ConstHandle2ConstProductions self);

// +++ Add
extern_c void
ProductionsProductionAdd(ConstHandle2Productions self, ConstHandle2ConstProduction production);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstProduction
ProductionsProductionGetConst(ConstHandle2ConstProductions self, const size_t index_);

// +++ Get, by index \in [0,size)
extern_c Handle2Production
ProductionsProductionGet(ConstHandle2Productions self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ProductionsProductionSet(
   ConstHandle2Productions self,
   const size_t index_,
   ConstHandle2ConstProduction production
);

// +++ Has, by label
extern_c int
ProductionsProductionHasByLabel(
   ConstHandle2ConstProductions self,
   const char *const label
);

// --- Get, by label, const
extern_c Handle2ConstProduction
ProductionsProductionGetByLabelConst(
   ConstHandle2ConstProductions self,
   const char *const label
);

// +++ Get, by label
extern_c Handle2Production
ProductionsProductionGetByLabel(
   ConstHandle2Productions self,
   const char *const label
);

// +++ Set, by label
extern_c void
ProductionsProductionSetByLabel(
   ConstHandle2Productions self,
   const char *const label,
   ConstHandle2ConstProduction production
);

// +++ Has, by ENDF_MT
extern_c int
ProductionsProductionHasByENDFMT(
   ConstHandle2ConstProductions self,
   const int ENDF_MT
);

// --- Get, by ENDF_MT, const
extern_c Handle2ConstProduction
ProductionsProductionGetByENDFMTConst(
   ConstHandle2ConstProductions self,
   const int ENDF_MT
);

// +++ Get, by ENDF_MT
extern_c Handle2Production
ProductionsProductionGetByENDFMT(
   ConstHandle2Productions self,
   const int ENDF_MT
);

// +++ Set, by ENDF_MT
extern_c void
ProductionsProductionSetByENDFMT(
   ConstHandle2Productions self,
   const int ENDF_MT,
   ConstHandle2ConstProduction production
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Productions/src/custom.h"

#undef extern_c
#endif
