
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
// KalbachMann is the basic handle type in this file. Example:
//    // Create a default KalbachMann object:
//    KalbachMann handle = KalbachMannDefault();
// Functions involving KalbachMann are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TRANSPORT_KALBACHMANN
#define C_INTERFACE_TEST_V2_0_TRANSPORT_KALBACHMANN

#include "GNDStk.h"
#include "v2.0/transport/F.h"
#include "v2.0/transport/R.h"
#include "v2.0/transport/A.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct KalbachMannClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ KalbachMann
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct KalbachMannClass *KalbachMann;

// --- Const-aware handles.
typedef const struct KalbachMannClass *const ConstHandle2ConstKalbachMann;
typedef       struct KalbachMannClass *const ConstHandle2KalbachMann;
typedef const struct KalbachMannClass *      Handle2ConstKalbachMann;
typedef       struct KalbachMannClass *      Handle2KalbachMann;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstKalbachMann
KalbachMannDefaultConst();

// +++ Create, default
extern_c Handle2KalbachMann
KalbachMannDefault();

// --- Create, general, const
extern_c Handle2ConstKalbachMann
KalbachMannCreateConst(
   const XMLName label,
   const XMLName productFrame,
   ConstHandle2ConstF f,
   ConstHandle2ConstR r,
   ConstHandle2ConstA a
);

// +++ Create, general
extern_c Handle2KalbachMann
KalbachMannCreate(
   const XMLName label,
   const XMLName productFrame,
   ConstHandle2ConstF f,
   ConstHandle2ConstR r,
   ConstHandle2ConstA a
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
KalbachMannAssign(ConstHandle2KalbachMann This, ConstHandle2ConstKalbachMann from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
KalbachMannDelete(ConstHandle2ConstKalbachMann This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
KalbachMannRead(ConstHandle2KalbachMann This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
KalbachMannWrite(ConstHandle2ConstKalbachMann This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
KalbachMannPrint(ConstHandle2ConstKalbachMann This);

// +++ Print to standard output, as XML
extern_c int
KalbachMannPrintXML(ConstHandle2ConstKalbachMann This);

// +++ Print to standard output, as JSON
extern_c int
KalbachMannPrintJSON(ConstHandle2ConstKalbachMann This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
KalbachMannLabelHas(ConstHandle2ConstKalbachMann This);

// +++ Get
// +++ Returns by value
extern_c XMLName
KalbachMannLabelGet(ConstHandle2ConstKalbachMann This);

// +++ Set
extern_c void
KalbachMannLabelSet(ConstHandle2KalbachMann This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
KalbachMannProductFrameHas(ConstHandle2ConstKalbachMann This);

// +++ Get
// +++ Returns by value
extern_c XMLName
KalbachMannProductFrameGet(ConstHandle2ConstKalbachMann This);

// +++ Set
extern_c void
KalbachMannProductFrameSet(ConstHandle2KalbachMann This, const XMLName productFrame);


// -----------------------------------------------------------------------------
// Child: f
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
KalbachMannFHas(ConstHandle2ConstKalbachMann This);

// --- Get, const
extern_c Handle2ConstF
KalbachMannFGetConst(ConstHandle2ConstKalbachMann This);

// +++ Get, non-const
extern_c Handle2F
KalbachMannFGet(ConstHandle2KalbachMann This);

// +++ Set
extern_c void
KalbachMannFSet(ConstHandle2KalbachMann This, ConstHandle2ConstF f);


// -----------------------------------------------------------------------------
// Child: r
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
KalbachMannRHas(ConstHandle2ConstKalbachMann This);

// --- Get, const
extern_c Handle2ConstR
KalbachMannRGetConst(ConstHandle2ConstKalbachMann This);

// +++ Get, non-const
extern_c Handle2R
KalbachMannRGet(ConstHandle2KalbachMann This);

// +++ Set
extern_c void
KalbachMannRSet(ConstHandle2KalbachMann This, ConstHandle2ConstR r);


// -----------------------------------------------------------------------------
// Child: a
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
KalbachMannAHas(ConstHandle2ConstKalbachMann This);

// --- Get, const
extern_c Handle2ConstA
KalbachMannAGetConst(ConstHandle2ConstKalbachMann This);

// +++ Get, non-const
extern_c Handle2A
KalbachMannAGet(ConstHandle2KalbachMann This);

// +++ Set
extern_c void
KalbachMannASet(ConstHandle2KalbachMann This, ConstHandle2ConstA a);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/KalbachMann/src/custom.h"

#undef extern_c
#endif
