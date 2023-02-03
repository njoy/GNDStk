
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
// SpinGroups is the basic handle type in this file. Example:
//    // Create a default SpinGroups object:
//    SpinGroups handle = SpinGroupsDefault();
// Functions involving SpinGroups are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_SPINGROUPS
#define C_INTERFACE_ALPHA_V2_0_GENERAL_SPINGROUPS

#include "GNDStk.h"
#include "v2.0/general/SpinGroup.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct SpinGroupsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ SpinGroups
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct SpinGroupsClass *SpinGroups;

// --- Const-aware handles.
typedef const struct SpinGroupsClass *const ConstHandle2ConstSpinGroups;
typedef       struct SpinGroupsClass *const ConstHandle2SpinGroups;
typedef const struct SpinGroupsClass *      Handle2ConstSpinGroups;
typedef       struct SpinGroupsClass *      Handle2SpinGroups;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstSpinGroups
SpinGroupsDefaultConst();

// +++ Create, default
extern_c Handle2SpinGroups
SpinGroupsDefault();

// --- Create, general, const
extern_c Handle2ConstSpinGroups
SpinGroupsCreateConst(
   ConstHandle2SpinGroup *const spinGroup, const size_t spinGroupSize
);

// +++ Create, general
extern_c Handle2SpinGroups
SpinGroupsCreate(
   ConstHandle2SpinGroup *const spinGroup, const size_t spinGroupSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
SpinGroupsAssign(ConstHandle2SpinGroups This, ConstHandle2ConstSpinGroups from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
SpinGroupsDelete(ConstHandle2ConstSpinGroups This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
SpinGroupsRead(ConstHandle2SpinGroups This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
SpinGroupsWrite(ConstHandle2ConstSpinGroups This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
SpinGroupsPrint(ConstHandle2ConstSpinGroups This);

// +++ Print to standard output, as XML
extern_c int
SpinGroupsPrintXML(ConstHandle2ConstSpinGroups This);

// +++ Print to standard output, as JSON
extern_c int
SpinGroupsPrintJSON(ConstHandle2ConstSpinGroups This);


// -----------------------------------------------------------------------------
// Child: spinGroup
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SpinGroupsSpinGroupHas(ConstHandle2ConstSpinGroups This);

// +++ Clear
extern_c void
SpinGroupsSpinGroupClear(ConstHandle2SpinGroups This);

// +++ Size
extern_c size_t
SpinGroupsSpinGroupSize(ConstHandle2ConstSpinGroups This);

// +++ Add
extern_c void
SpinGroupsSpinGroupAdd(ConstHandle2SpinGroups This, ConstHandle2ConstSpinGroup spinGroup);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstSpinGroup
SpinGroupsSpinGroupGetConst(ConstHandle2ConstSpinGroups This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2SpinGroup
SpinGroupsSpinGroupGet(ConstHandle2SpinGroups This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
SpinGroupsSpinGroupSet(
   ConstHandle2SpinGroups This,
   const size_t index_,
   ConstHandle2ConstSpinGroup spinGroup
);

// +++ Has, by label
extern_c int
SpinGroupsSpinGroupHasByLabel(
   ConstHandle2ConstSpinGroups This,
   const char *const label
);

// --- Get, by label, const
extern_c Handle2ConstSpinGroup
SpinGroupsSpinGroupGetByLabelConst(
   ConstHandle2ConstSpinGroups This,
   const char *const label
);

// +++ Get, by label, non-const
extern_c Handle2SpinGroup
SpinGroupsSpinGroupGetByLabel(
   ConstHandle2SpinGroups This,
   const char *const label
);

// +++ Set, by label
extern_c void
SpinGroupsSpinGroupSetByLabel(
   ConstHandle2SpinGroups This,
   const char *const label,
   ConstHandle2ConstSpinGroup spinGroup
);

// +++ Has, by spin
extern_c int
SpinGroupsSpinGroupHasBySpin(
   ConstHandle2ConstSpinGroups This,
   const int spin
);

// --- Get, by spin, const
extern_c Handle2ConstSpinGroup
SpinGroupsSpinGroupGetBySpinConst(
   ConstHandle2ConstSpinGroups This,
   const int spin
);

// +++ Get, by spin, non-const
extern_c Handle2SpinGroup
SpinGroupsSpinGroupGetBySpin(
   ConstHandle2SpinGroups This,
   const int spin
);

// +++ Set, by spin
extern_c void
SpinGroupsSpinGroupSetBySpin(
   ConstHandle2SpinGroups This,
   const int spin,
   ConstHandle2ConstSpinGroup spinGroup
);

// +++ Has, by parity
extern_c int
SpinGroupsSpinGroupHasByParity(
   ConstHandle2ConstSpinGroups This,
   const int parity
);

// --- Get, by parity, const
extern_c Handle2ConstSpinGroup
SpinGroupsSpinGroupGetByParityConst(
   ConstHandle2ConstSpinGroups This,
   const int parity
);

// +++ Get, by parity, non-const
extern_c Handle2SpinGroup
SpinGroupsSpinGroupGetByParity(
   ConstHandle2SpinGroups This,
   const int parity
);

// +++ Set, by parity
extern_c void
SpinGroupsSpinGroupSetByParity(
   ConstHandle2SpinGroups This,
   const int parity,
   ConstHandle2ConstSpinGroup spinGroup
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/SpinGroups/src/custom.h"

#undef extern_c
#endif
