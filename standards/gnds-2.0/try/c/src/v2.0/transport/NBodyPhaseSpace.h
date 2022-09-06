
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
// NBodyPhaseSpace is the basic handle type in this file. Example:
//    // Create a default NBodyPhaseSpace object:
//    NBodyPhaseSpace handle = NBodyPhaseSpaceDefault();
// Functions involving NBodyPhaseSpace are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_TRANSPORT_NBODYPHASESPACE
#define C_INTERFACE_TRY_V2_0_TRANSPORT_NBODYPHASESPACE

#include "GNDStk.h"
#include "v2.0/tsl/Mass.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct NBodyPhaseSpaceClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ NBodyPhaseSpace
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct NBodyPhaseSpaceClass *NBodyPhaseSpace;

// --- Const-aware handles.
typedef const struct NBodyPhaseSpaceClass *const ConstHandle2ConstNBodyPhaseSpace;
typedef       struct NBodyPhaseSpaceClass *const ConstHandle2NBodyPhaseSpace;
typedef const struct NBodyPhaseSpaceClass *      Handle2ConstNBodyPhaseSpace;
typedef       struct NBodyPhaseSpaceClass *      Handle2NBodyPhaseSpace;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstNBodyPhaseSpace
NBodyPhaseSpaceDefaultConst();

// +++ Create, default
extern_c Handle2NBodyPhaseSpace
NBodyPhaseSpaceDefault();

// --- Create, general, const
extern_c Handle2ConstNBodyPhaseSpace
NBodyPhaseSpaceCreateConst(
   const Integer32 numberOfProducts,
   ConstHandle2ConstMass mass
);

// +++ Create, general
extern_c Handle2NBodyPhaseSpace
NBodyPhaseSpaceCreate(
   const Integer32 numberOfProducts,
   ConstHandle2ConstMass mass
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
NBodyPhaseSpaceAssign(ConstHandle2NBodyPhaseSpace This, ConstHandle2ConstNBodyPhaseSpace from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
NBodyPhaseSpaceDelete(ConstHandle2ConstNBodyPhaseSpace This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
NBodyPhaseSpaceRead(ConstHandle2NBodyPhaseSpace This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
NBodyPhaseSpaceWrite(ConstHandle2ConstNBodyPhaseSpace This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
NBodyPhaseSpacePrint(ConstHandle2ConstNBodyPhaseSpace This);

// +++ Print to standard output, as XML
extern_c int
NBodyPhaseSpacePrintXML(ConstHandle2ConstNBodyPhaseSpace This);

// +++ Print to standard output, as JSON
extern_c int
NBodyPhaseSpacePrintJSON(ConstHandle2ConstNBodyPhaseSpace This);


// -----------------------------------------------------------------------------
// Metadatum: numberOfProducts
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NBodyPhaseSpaceNumberOfProductsHas(ConstHandle2ConstNBodyPhaseSpace This);

// +++ Get
// +++ Returns by value
extern_c Integer32
NBodyPhaseSpaceNumberOfProductsGet(ConstHandle2ConstNBodyPhaseSpace This);

// +++ Set
extern_c void
NBodyPhaseSpaceNumberOfProductsSet(ConstHandle2NBodyPhaseSpace This, const Integer32 numberOfProducts);


// -----------------------------------------------------------------------------
// Child: mass
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NBodyPhaseSpaceMassHas(ConstHandle2ConstNBodyPhaseSpace This);

// --- Get, const
extern_c Handle2ConstMass
NBodyPhaseSpaceMassGetConst(ConstHandle2ConstNBodyPhaseSpace This);

// +++ Get, non-const
extern_c Handle2Mass
NBodyPhaseSpaceMassGet(ConstHandle2NBodyPhaseSpace This);

// +++ Set
extern_c void
NBodyPhaseSpaceMassSet(ConstHandle2NBodyPhaseSpace This, ConstHandle2ConstMass mass);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif