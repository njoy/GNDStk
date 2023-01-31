
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
// Baryons is the basic handle type in this file. Example:
//    // Create a default Baryons object:
//    Baryons handle = BaryonsDefault();
// Functions involving Baryons are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_COMMON_BARYONS
#define C_INTERFACE_ALPHA_V2_0_COMMON_BARYONS

#include "GNDStk.h"
#include "v2.0/common/Baryon.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct BaryonsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Baryons
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct BaryonsClass *Baryons;

// --- Const-aware handles.
typedef const struct BaryonsClass *const ConstHandle2ConstBaryons;
typedef       struct BaryonsClass *const ConstHandle2Baryons;
typedef const struct BaryonsClass *      Handle2ConstBaryons;
typedef       struct BaryonsClass *      Handle2Baryons;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstBaryons
BaryonsDefaultConst();

// +++ Create, default
extern_c Handle2Baryons
BaryonsDefault();

// --- Create, general, const
extern_c Handle2ConstBaryons
BaryonsCreateConst(
   ConstHandle2Baryon *const baryon, const size_t baryonSize
);

// +++ Create, general
extern_c Handle2Baryons
BaryonsCreate(
   ConstHandle2Baryon *const baryon, const size_t baryonSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
BaryonsAssign(ConstHandle2Baryons This, ConstHandle2ConstBaryons from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
BaryonsDelete(ConstHandle2ConstBaryons This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
BaryonsRead(ConstHandle2Baryons This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
BaryonsWrite(ConstHandle2ConstBaryons This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
BaryonsPrint(ConstHandle2ConstBaryons This);

// +++ Print to standard output, as XML
extern_c int
BaryonsPrintXML(ConstHandle2ConstBaryons This);

// +++ Print to standard output, as JSON
extern_c int
BaryonsPrintJSON(ConstHandle2ConstBaryons This);


// -----------------------------------------------------------------------------
// Child: baryon
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BaryonsBaryonHas(ConstHandle2ConstBaryons This);

// +++ Clear
extern_c void
BaryonsBaryonClear(ConstHandle2Baryons This);

// +++ Size
extern_c size_t
BaryonsBaryonSize(ConstHandle2ConstBaryons This);

// +++ Add
extern_c void
BaryonsBaryonAdd(ConstHandle2Baryons This, ConstHandle2ConstBaryon baryon);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstBaryon
BaryonsBaryonGetConst(ConstHandle2ConstBaryons This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Baryon
BaryonsBaryonGet(ConstHandle2Baryons This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
BaryonsBaryonSet(
   ConstHandle2Baryons This,
   const size_t index_,
   ConstHandle2ConstBaryon baryon
);

// +++ Has, by id
extern_c int
BaryonsBaryonHasById(
   ConstHandle2ConstBaryons This,
   const char *const id
);

// --- Get, by id, const
extern_c Handle2ConstBaryon
BaryonsBaryonGetByIdConst(
   ConstHandle2ConstBaryons This,
   const char *const id
);

// +++ Get, by id, non-const
extern_c Handle2Baryon
BaryonsBaryonGetById(
   ConstHandle2Baryons This,
   const char *const id
);

// +++ Set, by id
extern_c void
BaryonsBaryonSetById(
   ConstHandle2Baryons This,
   const char *const id,
   ConstHandle2ConstBaryon baryon
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/common/Baryons/src/custom.h"

#undef extern_c
#endif
