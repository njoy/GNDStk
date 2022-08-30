
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
// MultiGroup3d is the basic handle type in this file. Example:
//    // Create a default MultiGroup3d object:
//    MultiGroup3d handle = MultiGroup3dDefault();
// Functions involving MultiGroup3d are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_TRANSPORT_MULTIGROUP3D
#define C_INTERFACE_TRY_V2_0_TRANSPORT_MULTIGROUP3D

#include "GNDStk.h"
#include "v2.0/containers/Gridded3d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct MultiGroup3dClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ MultiGroup3d
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct MultiGroup3dClass *MultiGroup3d;

// --- Const-aware handles.
typedef const struct MultiGroup3dClass *const ConstHandle2ConstMultiGroup3d;
typedef       struct MultiGroup3dClass *const ConstHandle2MultiGroup3d;
typedef const struct MultiGroup3dClass *      Handle2ConstMultiGroup3d;
typedef       struct MultiGroup3dClass *      Handle2MultiGroup3d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstMultiGroup3d
MultiGroup3dDefaultConst();

// +++ Create, default
extern_c Handle2MultiGroup3d
MultiGroup3dDefault();

// --- Create, general, const
extern_c Handle2ConstMultiGroup3d
MultiGroup3dCreateConst(
   const XMLName label,
   const XMLName productFrame,
   ConstHandle2ConstGridded3d gridded3d
);

// +++ Create, general
extern_c Handle2MultiGroup3d
MultiGroup3dCreate(
   const XMLName label,
   const XMLName productFrame,
   ConstHandle2ConstGridded3d gridded3d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
MultiGroup3dAssign(ConstHandle2MultiGroup3d This, ConstHandle2ConstMultiGroup3d from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
MultiGroup3dDelete(ConstHandle2ConstMultiGroup3d This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
MultiGroup3dRead(ConstHandle2MultiGroup3d This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
MultiGroup3dWrite(ConstHandle2ConstMultiGroup3d This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
MultiGroup3dPrint(ConstHandle2ConstMultiGroup3d This);

// +++ Print to standard output, as XML
extern_c int
MultiGroup3dPrintXML(ConstHandle2ConstMultiGroup3d This);

// +++ Print to standard output, as JSON
extern_c int
MultiGroup3dPrintJSON(ConstHandle2ConstMultiGroup3d This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiGroup3dLabelHas(ConstHandle2ConstMultiGroup3d This);

// +++ Get
// +++ Returns by value
extern_c XMLName
MultiGroup3dLabelGet(ConstHandle2ConstMultiGroup3d This);

// +++ Set
extern_c void
MultiGroup3dLabelSet(ConstHandle2MultiGroup3d This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiGroup3dProductFrameHas(ConstHandle2ConstMultiGroup3d This);

// +++ Get
// +++ Returns by value
extern_c XMLName
MultiGroup3dProductFrameGet(ConstHandle2ConstMultiGroup3d This);

// +++ Set
extern_c void
MultiGroup3dProductFrameSet(ConstHandle2MultiGroup3d This, const XMLName productFrame);


// -----------------------------------------------------------------------------
// Child: gridded3d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiGroup3dGridded3dHas(ConstHandle2ConstMultiGroup3d This);

// --- Get, const
extern_c Handle2ConstGridded3d
MultiGroup3dGridded3dGetConst(ConstHandle2ConstMultiGroup3d This);

// +++ Get, non-const
extern_c Handle2Gridded3d
MultiGroup3dGridded3dGet(ConstHandle2MultiGroup3d This);

// +++ Set
extern_c void
MultiGroup3dGridded3dSet(ConstHandle2MultiGroup3d This, ConstHandle2ConstGridded3d gridded3d);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
