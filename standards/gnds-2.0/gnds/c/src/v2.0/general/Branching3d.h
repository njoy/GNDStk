
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
// Branching3d is the basic handle type in this file. Example:
//    // Create a default Branching3d object:
//    Branching3d handle = Branching3dDefault();
// Functions involving Branching3d are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_BRANCHING3D
#define C_INTERFACE_GNDS_V2_0_GENERAL_BRANCHING3D

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct Branching3dClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Branching3d
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct Branching3dClass *Branching3d;

// --- Const-aware handles.
typedef const struct Branching3dClass *const ConstHandle2ConstBranching3d;
typedef       struct Branching3dClass *const ConstHandle2Branching3d;
typedef const struct Branching3dClass *      Handle2ConstBranching3d;
typedef       struct Branching3dClass *      Handle2Branching3d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstBranching3d
Branching3dDefaultConst();

// +++ Create, default
extern_c Handle2Branching3d
Branching3dDefault();

// --- Create, general, const
extern_c Handle2ConstBranching3d
Branching3dCreateConst(
   const char *const label,
   const char *const productFrame
);

// +++ Create, general
extern_c Handle2Branching3d
Branching3dCreate(
   const char *const label,
   const char *const productFrame
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
Branching3dAssign(ConstHandle2Branching3d self, ConstHandle2ConstBranching3d from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
Branching3dDelete(ConstHandle2ConstBranching3d self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
Branching3dRead(ConstHandle2Branching3d self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
Branching3dWrite(ConstHandle2ConstBranching3d self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
Branching3dPrint(ConstHandle2ConstBranching3d self);

// +++ Print to standard output, as XML
extern_c int
Branching3dPrintXML(ConstHandle2ConstBranching3d self);

// +++ Print to standard output, as JSON
extern_c int
Branching3dPrintJSON(ConstHandle2ConstBranching3d self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Branching3dLabelHas(ConstHandle2ConstBranching3d self);

// +++ Get
// +++ Returns by value
extern_c const char *
Branching3dLabelGet(ConstHandle2ConstBranching3d self);

// +++ Set
extern_c void
Branching3dLabelSet(ConstHandle2Branching3d self, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Branching3dProductFrameHas(ConstHandle2ConstBranching3d self);

// +++ Get
// +++ Returns by value
extern_c const char *
Branching3dProductFrameGet(ConstHandle2ConstBranching3d self);

// +++ Set
extern_c void
Branching3dProductFrameSet(ConstHandle2Branching3d self, const char *const productFrame);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Branching3d/src/custom.h"

#undef extern_c
#endif
