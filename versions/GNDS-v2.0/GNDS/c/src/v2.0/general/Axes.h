
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
// Axes is the basic handle type in this file. Example:
//    // Create a default Axes object:
//    Axes handle = AxesDefault();
// Functions involving Axes are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_AXES
#define C_INTERFACE_GNDS_V2_0_GENERAL_AXES

#include "GNDStk.h"
#include "v2.0/general/Axis.h"
#include "v2.0/general/Grid.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AxesClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Axes
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AxesClass *Axes;

// --- Const-aware handles.
typedef const struct AxesClass *const ConstHandle2ConstAxes;
typedef       struct AxesClass *const ConstHandle2Axes;
typedef const struct AxesClass *      Handle2ConstAxes;
typedef       struct AxesClass *      Handle2Axes;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAxes
AxesDefaultConst();

// +++ Create, default
extern_c Handle2Axes
AxesDefault();

// --- Create, general, const
extern_c Handle2ConstAxes
AxesCreateConst(
   ConstHandle2Axis *const axis, const size_t axisSize,
   ConstHandle2Grid *const grid, const size_t gridSize
);

// +++ Create, general
extern_c Handle2Axes
AxesCreate(
   ConstHandle2Axis *const axis, const size_t axisSize,
   ConstHandle2Grid *const grid, const size_t gridSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AxesAssign(ConstHandle2Axes self, ConstHandle2ConstAxes from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AxesDelete(ConstHandle2ConstAxes self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AxesRead(ConstHandle2Axes self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AxesWrite(ConstHandle2ConstAxes self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AxesPrint(ConstHandle2ConstAxes self);

// +++ Print to standard output, as XML
extern_c int
AxesPrintXML(ConstHandle2ConstAxes self);

// +++ Print to standard output, as JSON
extern_c int
AxesPrintJSON(ConstHandle2ConstAxes self);


// -----------------------------------------------------------------------------
// Child: axis
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AxesAxisHas(ConstHandle2ConstAxes self);

// +++ Clear
extern_c void
AxesAxisClear(ConstHandle2Axes self);

// +++ Size
extern_c size_t
AxesAxisSize(ConstHandle2ConstAxes self);

// +++ Add
extern_c void
AxesAxisAdd(ConstHandle2Axes self, ConstHandle2ConstAxis axis);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstAxis
AxesAxisGetConst(ConstHandle2ConstAxes self, const size_t index_);

// +++ Get, by index \in [0,size)
extern_c Handle2Axis
AxesAxisGet(ConstHandle2Axes self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
AxesAxisSet(
   ConstHandle2Axes self,
   const size_t index_,
   ConstHandle2ConstAxis axis
);

// +++ Has, by index
extern_c int
AxesAxisHasByIndex(
   ConstHandle2ConstAxes self,
   const int index
);

// --- Get, by index, const
extern_c Handle2ConstAxis
AxesAxisGetByIndexConst(
   ConstHandle2ConstAxes self,
   const int index
);

// +++ Get, by index
extern_c Handle2Axis
AxesAxisGetByIndex(
   ConstHandle2Axes self,
   const int index
);

// +++ Set, by index
extern_c void
AxesAxisSetByIndex(
   ConstHandle2Axes self,
   const int index,
   ConstHandle2ConstAxis axis
);

// +++ Has, by label
extern_c int
AxesAxisHasByLabel(
   ConstHandle2ConstAxes self,
   const char *const label
);

// --- Get, by label, const
extern_c Handle2ConstAxis
AxesAxisGetByLabelConst(
   ConstHandle2ConstAxes self,
   const char *const label
);

// +++ Get, by label
extern_c Handle2Axis
AxesAxisGetByLabel(
   ConstHandle2Axes self,
   const char *const label
);

// +++ Set, by label
extern_c void
AxesAxisSetByLabel(
   ConstHandle2Axes self,
   const char *const label,
   ConstHandle2ConstAxis axis
);

// +++ Has, by unit
extern_c int
AxesAxisHasByUnit(
   ConstHandle2ConstAxes self,
   const char *const unit
);

// --- Get, by unit, const
extern_c Handle2ConstAxis
AxesAxisGetByUnitConst(
   ConstHandle2ConstAxes self,
   const char *const unit
);

// +++ Get, by unit
extern_c Handle2Axis
AxesAxisGetByUnit(
   ConstHandle2Axes self,
   const char *const unit
);

// +++ Set, by unit
extern_c void
AxesAxisSetByUnit(
   ConstHandle2Axes self,
   const char *const unit,
   ConstHandle2ConstAxis axis
);


// -----------------------------------------------------------------------------
// Child: grid
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AxesGridHas(ConstHandle2ConstAxes self);

// +++ Clear
extern_c void
AxesGridClear(ConstHandle2Axes self);

// +++ Size
extern_c size_t
AxesGridSize(ConstHandle2ConstAxes self);

// +++ Add
extern_c void
AxesGridAdd(ConstHandle2Axes self, ConstHandle2ConstGrid grid);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstGrid
AxesGridGetConst(ConstHandle2ConstAxes self, const size_t index_);

// +++ Get, by index \in [0,size)
extern_c Handle2Grid
AxesGridGet(ConstHandle2Axes self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
AxesGridSet(
   ConstHandle2Axes self,
   const size_t index_,
   ConstHandle2ConstGrid grid
);

// +++ Has, by index
extern_c int
AxesGridHasByIndex(
   ConstHandle2ConstAxes self,
   const int index
);

// --- Get, by index, const
extern_c Handle2ConstGrid
AxesGridGetByIndexConst(
   ConstHandle2ConstAxes self,
   const int index
);

// +++ Get, by index
extern_c Handle2Grid
AxesGridGetByIndex(
   ConstHandle2Axes self,
   const int index
);

// +++ Set, by index
extern_c void
AxesGridSetByIndex(
   ConstHandle2Axes self,
   const int index,
   ConstHandle2ConstGrid grid
);

// +++ Has, by label
extern_c int
AxesGridHasByLabel(
   ConstHandle2ConstAxes self,
   const char *const label
);

// --- Get, by label, const
extern_c Handle2ConstGrid
AxesGridGetByLabelConst(
   ConstHandle2ConstAxes self,
   const char *const label
);

// +++ Get, by label
extern_c Handle2Grid
AxesGridGetByLabel(
   ConstHandle2Axes self,
   const char *const label
);

// +++ Set, by label
extern_c void
AxesGridSetByLabel(
   ConstHandle2Axes self,
   const char *const label,
   ConstHandle2ConstGrid grid
);

// +++ Has, by unit
extern_c int
AxesGridHasByUnit(
   ConstHandle2ConstAxes self,
   const char *const unit
);

// --- Get, by unit, const
extern_c Handle2ConstGrid
AxesGridGetByUnitConst(
   ConstHandle2ConstAxes self,
   const char *const unit
);

// +++ Get, by unit
extern_c Handle2Grid
AxesGridGetByUnit(
   ConstHandle2Axes self,
   const char *const unit
);

// +++ Set, by unit
extern_c void
AxesGridSetByUnit(
   ConstHandle2Axes self,
   const char *const unit,
   ConstHandle2ConstGrid grid
);

// +++ Has, by style
extern_c int
AxesGridHasByStyle(
   ConstHandle2ConstAxes self,
   const char *const style
);

// --- Get, by style, const
extern_c Handle2ConstGrid
AxesGridGetByStyleConst(
   ConstHandle2ConstAxes self,
   const char *const style
);

// +++ Get, by style
extern_c Handle2Grid
AxesGridGetByStyle(
   ConstHandle2Axes self,
   const char *const style
);

// +++ Set, by style
extern_c void
AxesGridSetByStyle(
   ConstHandle2Axes self,
   const char *const style,
   ConstHandle2ConstGrid grid
);

// +++ Has, by interpolation
extern_c int
AxesGridHasByInterpolation(
   ConstHandle2ConstAxes self,
   const char *const interpolation
);

// --- Get, by interpolation, const
extern_c Handle2ConstGrid
AxesGridGetByInterpolationConst(
   ConstHandle2ConstAxes self,
   const char *const interpolation
);

// +++ Get, by interpolation
extern_c Handle2Grid
AxesGridGetByInterpolation(
   ConstHandle2Axes self,
   const char *const interpolation
);

// +++ Set, by interpolation
extern_c void
AxesGridSetByInterpolation(
   ConstHandle2Axes self,
   const char *const interpolation,
   ConstHandle2ConstGrid grid
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Axes/src/custom.h"

#undef extern_c
#endif
