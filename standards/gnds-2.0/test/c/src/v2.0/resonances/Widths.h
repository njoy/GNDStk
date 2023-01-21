
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
// Widths is the basic handle type in this file. Example:
//    // Create a default Widths object:
//    Widths handle = WidthsDefault();
// Functions involving Widths are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_RESONANCES_WIDTHS
#define C_INTERFACE_TEST_V2_0_RESONANCES_WIDTHS

#include "GNDStk.h"
#include "v2.0/resonances/Width.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct WidthsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Widths
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct WidthsClass *Widths;

// --- Const-aware handles.
typedef const struct WidthsClass *const ConstHandle2ConstWidths;
typedef       struct WidthsClass *const ConstHandle2Widths;
typedef const struct WidthsClass *      Handle2ConstWidths;
typedef       struct WidthsClass *      Handle2Widths;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstWidths
WidthsDefaultConst();

// +++ Create, default
extern_c Handle2Widths
WidthsDefault();

// --- Create, general, const
extern_c Handle2ConstWidths
WidthsCreateConst(
   ConstHandle2Width *const width, const size_t widthSize
);

// +++ Create, general
extern_c Handle2Widths
WidthsCreate(
   ConstHandle2Width *const width, const size_t widthSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
WidthsAssign(ConstHandle2Widths This, ConstHandle2ConstWidths from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
WidthsDelete(ConstHandle2ConstWidths This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
WidthsRead(ConstHandle2Widths This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
WidthsWrite(ConstHandle2ConstWidths This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
WidthsPrint(ConstHandle2ConstWidths This);

// +++ Print to standard output, as XML
extern_c int
WidthsPrintXML(ConstHandle2ConstWidths This);

// +++ Print to standard output, as JSON
extern_c int
WidthsPrintJSON(ConstHandle2ConstWidths This);


// -----------------------------------------------------------------------------
// Child: width
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
WidthsWidthHas(ConstHandle2ConstWidths This);

// +++ Clear
extern_c void
WidthsWidthClear(ConstHandle2Widths This);

// +++ Size
extern_c size_t
WidthsWidthSize(ConstHandle2ConstWidths This);

// +++ Add
extern_c void
WidthsWidthAdd(ConstHandle2Widths This, ConstHandle2ConstWidth width);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstWidth
WidthsWidthGetConst(ConstHandle2ConstWidths This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Width
WidthsWidthGet(ConstHandle2Widths This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
WidthsWidthSet(
   ConstHandle2Widths This,
   const size_t index_,
   ConstHandle2ConstWidth width
);

// +++ Has, by resonanceReaction
extern_c int
WidthsWidthHasByResonanceReaction(
   ConstHandle2ConstWidths This,
   const char *const resonanceReaction
);

// --- Get, by resonanceReaction, const
extern_c Handle2ConstWidth
WidthsWidthGetByResonanceReactionConst(
   ConstHandle2ConstWidths This,
   const char *const resonanceReaction
);

// +++ Get, by resonanceReaction, non-const
extern_c Handle2Width
WidthsWidthGetByResonanceReaction(
   ConstHandle2Widths This,
   const char *const resonanceReaction
);

// +++ Set, by resonanceReaction
extern_c void
WidthsWidthSetByResonanceReaction(
   ConstHandle2Widths This,
   const char *const resonanceReaction,
   ConstHandle2ConstWidth width
);

// +++ Has, by degreesOfFreedom
extern_c int
WidthsWidthHasByDegreesOfFreedom(
   ConstHandle2ConstWidths This,
   const Float64 degreesOfFreedom
);

// --- Get, by degreesOfFreedom, const
extern_c Handle2ConstWidth
WidthsWidthGetByDegreesOfFreedomConst(
   ConstHandle2ConstWidths This,
   const Float64 degreesOfFreedom
);

// +++ Get, by degreesOfFreedom, non-const
extern_c Handle2Width
WidthsWidthGetByDegreesOfFreedom(
   ConstHandle2Widths This,
   const Float64 degreesOfFreedom
);

// +++ Set, by degreesOfFreedom
extern_c void
WidthsWidthSetByDegreesOfFreedom(
   ConstHandle2Widths This,
   const Float64 degreesOfFreedom,
   ConstHandle2ConstWidth width
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/resonances/Widths/src/custom.h"

#undef extern_c
#endif
