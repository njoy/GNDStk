
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
// AngularTwoBody is the basic handle type in this file. Example:
//    // Create a default AngularTwoBody object:
//    AngularTwoBody handle = AngularTwoBodyDefault();
// Functions involving AngularTwoBody are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TRANSPORT_ANGULARTWOBODY
#define C_INTERFACE_TEST_V2_0_TRANSPORT_ANGULARTWOBODY

#include "GNDStk.h"
#include "v2.0/containers/XYs2d.h"
#include "v2.0/containers/Regions2d.h"
#include "v2.0/transport/Isotropic2d.h"
#include "v2.0/transport/Recoil.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AngularTwoBodyClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ AngularTwoBody
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AngularTwoBodyClass *AngularTwoBody;

// --- Const-aware handles.
typedef const struct AngularTwoBodyClass *const ConstHandle2ConstAngularTwoBody;
typedef       struct AngularTwoBodyClass *const ConstHandle2AngularTwoBody;
typedef const struct AngularTwoBodyClass *      Handle2ConstAngularTwoBody;
typedef       struct AngularTwoBodyClass *      Handle2AngularTwoBody;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAngularTwoBody
AngularTwoBodyDefaultConst();

// +++ Create, default
extern_c Handle2AngularTwoBody
AngularTwoBodyDefault();

// --- Create, general, const
extern_c Handle2ConstAngularTwoBody
AngularTwoBodyCreateConst(
   const XMLName label,
   const XMLName productFrame,
   ConstHandle2ConstXYs2d XYs2d,
   ConstHandle2ConstRegions2d regions2d,
   ConstHandle2ConstIsotropic2d isotropic2d,
   ConstHandle2ConstRecoil recoil
);

// +++ Create, general
extern_c Handle2AngularTwoBody
AngularTwoBodyCreate(
   const XMLName label,
   const XMLName productFrame,
   ConstHandle2ConstXYs2d XYs2d,
   ConstHandle2ConstRegions2d regions2d,
   ConstHandle2ConstIsotropic2d isotropic2d,
   ConstHandle2ConstRecoil recoil
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AngularTwoBodyAssign(ConstHandle2AngularTwoBody self, ConstHandle2ConstAngularTwoBody from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AngularTwoBodyDelete(ConstHandle2ConstAngularTwoBody self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AngularTwoBodyRead(ConstHandle2AngularTwoBody self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AngularTwoBodyWrite(ConstHandle2ConstAngularTwoBody self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AngularTwoBodyPrint(ConstHandle2ConstAngularTwoBody self);

// +++ Print to standard output, as XML
extern_c int
AngularTwoBodyPrintXML(ConstHandle2ConstAngularTwoBody self);

// +++ Print to standard output, as JSON
extern_c int
AngularTwoBodyPrintJSON(ConstHandle2ConstAngularTwoBody self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AngularTwoBodyLabelHas(ConstHandle2ConstAngularTwoBody self);

// +++ Get
// +++ Returns by value
extern_c XMLName
AngularTwoBodyLabelGet(ConstHandle2ConstAngularTwoBody self);

// +++ Set
extern_c void
AngularTwoBodyLabelSet(ConstHandle2AngularTwoBody self, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AngularTwoBodyProductFrameHas(ConstHandle2ConstAngularTwoBody self);

// +++ Get
// +++ Returns by value
extern_c XMLName
AngularTwoBodyProductFrameGet(ConstHandle2ConstAngularTwoBody self);

// +++ Set
extern_c void
AngularTwoBodyProductFrameSet(ConstHandle2AngularTwoBody self, const XMLName productFrame);


// -----------------------------------------------------------------------------
// Child: XYs2d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AngularTwoBodyXYs2dHas(ConstHandle2ConstAngularTwoBody self);

// --- Get, const
extern_c Handle2ConstXYs2d
AngularTwoBodyXYs2dGetConst(ConstHandle2ConstAngularTwoBody self);

// +++ Get, non-const
extern_c Handle2XYs2d
AngularTwoBodyXYs2dGet(ConstHandle2AngularTwoBody self);

// +++ Set
extern_c void
AngularTwoBodyXYs2dSet(ConstHandle2AngularTwoBody self, ConstHandle2ConstXYs2d XYs2d);


// -----------------------------------------------------------------------------
// Child: regions2d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AngularTwoBodyRegions2dHas(ConstHandle2ConstAngularTwoBody self);

// --- Get, const
extern_c Handle2ConstRegions2d
AngularTwoBodyRegions2dGetConst(ConstHandle2ConstAngularTwoBody self);

// +++ Get, non-const
extern_c Handle2Regions2d
AngularTwoBodyRegions2dGet(ConstHandle2AngularTwoBody self);

// +++ Set
extern_c void
AngularTwoBodyRegions2dSet(ConstHandle2AngularTwoBody self, ConstHandle2ConstRegions2d regions2d);


// -----------------------------------------------------------------------------
// Child: isotropic2d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AngularTwoBodyIsotropic2dHas(ConstHandle2ConstAngularTwoBody self);

// --- Get, const
extern_c Handle2ConstIsotropic2d
AngularTwoBodyIsotropic2dGetConst(ConstHandle2ConstAngularTwoBody self);

// +++ Get, non-const
extern_c Handle2Isotropic2d
AngularTwoBodyIsotropic2dGet(ConstHandle2AngularTwoBody self);

// +++ Set
extern_c void
AngularTwoBodyIsotropic2dSet(ConstHandle2AngularTwoBody self, ConstHandle2ConstIsotropic2d isotropic2d);


// -----------------------------------------------------------------------------
// Child: recoil
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AngularTwoBodyRecoilHas(ConstHandle2ConstAngularTwoBody self);

// --- Get, const
extern_c Handle2ConstRecoil
AngularTwoBodyRecoilGetConst(ConstHandle2ConstAngularTwoBody self);

// +++ Get, non-const
extern_c Handle2Recoil
AngularTwoBodyRecoilGet(ConstHandle2AngularTwoBody self);

// +++ Set
extern_c void
AngularTwoBodyRecoilSet(ConstHandle2AngularTwoBody self, ConstHandle2ConstRecoil recoil);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/AngularTwoBody/src/custom.h"

#undef extern_c
#endif
