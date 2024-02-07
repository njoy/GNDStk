
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
// ShortRangeSelfScalingVariance is the basic handle type in this file. Example:
//    // Create a default ShortRangeSelfScalingVariance object:
//    ShortRangeSelfScalingVariance handle = ShortRangeSelfScalingVarianceDefault();
// Functions involving ShortRangeSelfScalingVariance are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_SHORTRANGESELFSCALINGVARIANCE
#define C_INTERFACE_GNDS_V2_0_GENERAL_SHORTRANGESELFSCALINGVARIANCE

#include "GNDStk.h"
#include "v2.0/general/Gridded2d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ShortRangeSelfScalingVarianceClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ShortRangeSelfScalingVariance
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ShortRangeSelfScalingVarianceClass *ShortRangeSelfScalingVariance;

// --- Const-aware handles.
typedef const struct ShortRangeSelfScalingVarianceClass *const ConstHandle2ConstShortRangeSelfScalingVariance;
typedef       struct ShortRangeSelfScalingVarianceClass *const ConstHandle2ShortRangeSelfScalingVariance;
typedef const struct ShortRangeSelfScalingVarianceClass *      Handle2ConstShortRangeSelfScalingVariance;
typedef       struct ShortRangeSelfScalingVarianceClass *      Handle2ShortRangeSelfScalingVariance;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstShortRangeSelfScalingVariance
ShortRangeSelfScalingVarianceDefaultConst();

// +++ Create, default, non-const
extern_c Handle2ShortRangeSelfScalingVariance
ShortRangeSelfScalingVarianceDefault();

// --- Create, general, const
extern_c Handle2ConstShortRangeSelfScalingVariance
ShortRangeSelfScalingVarianceCreateConst(
   const char *const label,
   const char *const type,
   const char *const dependenceOnProcessedGroupWidth,
   ConstHandle2ConstGridded2d gridded2d
);

// +++ Create, general, non-const
extern_c Handle2ShortRangeSelfScalingVariance
ShortRangeSelfScalingVarianceCreate(
   const char *const label,
   const char *const type,
   const char *const dependenceOnProcessedGroupWidth,
   ConstHandle2ConstGridded2d gridded2d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ShortRangeSelfScalingVarianceAssign(ConstHandle2ShortRangeSelfScalingVariance self, ConstHandle2ConstShortRangeSelfScalingVariance from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ShortRangeSelfScalingVarianceDelete(ConstHandle2ConstShortRangeSelfScalingVariance self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ShortRangeSelfScalingVarianceRead(ConstHandle2ShortRangeSelfScalingVariance self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ShortRangeSelfScalingVarianceWrite(ConstHandle2ConstShortRangeSelfScalingVariance self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ShortRangeSelfScalingVariancePrint(ConstHandle2ConstShortRangeSelfScalingVariance self);

// +++ Print to standard output, as XML
extern_c int
ShortRangeSelfScalingVariancePrintXML(ConstHandle2ConstShortRangeSelfScalingVariance self);

// +++ Print to standard output, as JSON
extern_c int
ShortRangeSelfScalingVariancePrintJSON(ConstHandle2ConstShortRangeSelfScalingVariance self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ShortRangeSelfScalingVarianceLabelHas(ConstHandle2ConstShortRangeSelfScalingVariance self);

// +++ Get
// +++ Returns by value
extern_c const char *
ShortRangeSelfScalingVarianceLabelGet(ConstHandle2ConstShortRangeSelfScalingVariance self);

// +++ Set
extern_c void
ShortRangeSelfScalingVarianceLabelSet(ConstHandle2ShortRangeSelfScalingVariance self, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: type
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ShortRangeSelfScalingVarianceTypeHas(ConstHandle2ConstShortRangeSelfScalingVariance self);

// +++ Get
// +++ Returns by value
extern_c const char *
ShortRangeSelfScalingVarianceTypeGet(ConstHandle2ConstShortRangeSelfScalingVariance self);

// +++ Set
extern_c void
ShortRangeSelfScalingVarianceTypeSet(ConstHandle2ShortRangeSelfScalingVariance self, const char *const type);


// -----------------------------------------------------------------------------
// Metadatum: dependenceOnProcessedGroupWidth
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ShortRangeSelfScalingVarianceDependenceOnProcessedGroupWidthHas(ConstHandle2ConstShortRangeSelfScalingVariance self);

// +++ Get
// +++ Returns by value
extern_c const char *
ShortRangeSelfScalingVarianceDependenceOnProcessedGroupWidthGet(ConstHandle2ConstShortRangeSelfScalingVariance self);

// +++ Set
extern_c void
ShortRangeSelfScalingVarianceDependenceOnProcessedGroupWidthSet(ConstHandle2ShortRangeSelfScalingVariance self, const char *const dependenceOnProcessedGroupWidth);


// -----------------------------------------------------------------------------
// Child: gridded2d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ShortRangeSelfScalingVarianceGridded2dHas(ConstHandle2ConstShortRangeSelfScalingVariance self);

// --- Get, const
extern_c Handle2ConstGridded2d
ShortRangeSelfScalingVarianceGridded2dGetConst(ConstHandle2ConstShortRangeSelfScalingVariance self);

// +++ Get, non-const
extern_c Handle2Gridded2d
ShortRangeSelfScalingVarianceGridded2dGet(ConstHandle2ShortRangeSelfScalingVariance self);

// +++ Set
extern_c void
ShortRangeSelfScalingVarianceGridded2dSet(ConstHandle2ShortRangeSelfScalingVariance self, ConstHandle2ConstGridded2d gridded2d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ShortRangeSelfScalingVariance/src/custom.h"

#undef extern_c
#endif
