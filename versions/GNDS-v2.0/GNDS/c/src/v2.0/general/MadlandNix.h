
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
// MadlandNix is the basic handle type in this file. Example:
//    // Create a default MadlandNix object:
//    MadlandNix handle = MadlandNixDefault();
// Functions involving MadlandNix are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_MADLANDNIX
#define C_INTERFACE_GNDS_V2_0_GENERAL_MADLANDNIX

#include "GNDStk.h"
#include "v2.0/general/EFL.h"
#include "v2.0/general/EFH.h"
#include "v2.0/general/T_M.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct MadlandNixClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ MadlandNix
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct MadlandNixClass *MadlandNix;

// --- Const-aware handles.
typedef const struct MadlandNixClass *const ConstHandle2ConstMadlandNix;
typedef       struct MadlandNixClass *const ConstHandle2MadlandNix;
typedef const struct MadlandNixClass *      Handle2ConstMadlandNix;
typedef       struct MadlandNixClass *      Handle2MadlandNix;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstMadlandNix
MadlandNixDefaultConst();

// +++ Create, default, non-const
extern_c Handle2MadlandNix
MadlandNixDefault();

// --- Create, general, const
extern_c Handle2ConstMadlandNix
MadlandNixCreateConst(
   ConstHandle2ConstEFL EFL,
   ConstHandle2ConstEFH EFH,
   ConstHandle2ConstT_M T_M
);

// +++ Create, general, non-const
extern_c Handle2MadlandNix
MadlandNixCreate(
   ConstHandle2ConstEFL EFL,
   ConstHandle2ConstEFH EFH,
   ConstHandle2ConstT_M T_M
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
MadlandNixAssign(ConstHandle2MadlandNix self, ConstHandle2ConstMadlandNix from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
MadlandNixDelete(ConstHandle2ConstMadlandNix self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
MadlandNixRead(ConstHandle2MadlandNix self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
MadlandNixWrite(ConstHandle2ConstMadlandNix self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
MadlandNixPrint(ConstHandle2ConstMadlandNix self);

// +++ Print to standard output, as XML
extern_c int
MadlandNixPrintXML(ConstHandle2ConstMadlandNix self);

// +++ Print to standard output, as JSON
extern_c int
MadlandNixPrintJSON(ConstHandle2ConstMadlandNix self);


// -----------------------------------------------------------------------------
// Child: EFL
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MadlandNixEFLHas(ConstHandle2ConstMadlandNix self);

// --- Get, const
extern_c Handle2ConstEFL
MadlandNixEFLGetConst(ConstHandle2ConstMadlandNix self);

// +++ Get, non-const
extern_c Handle2EFL
MadlandNixEFLGet(ConstHandle2MadlandNix self);

// +++ Set
extern_c void
MadlandNixEFLSet(ConstHandle2MadlandNix self, ConstHandle2ConstEFL EFL);


// -----------------------------------------------------------------------------
// Child: EFH
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MadlandNixEFHHas(ConstHandle2ConstMadlandNix self);

// --- Get, const
extern_c Handle2ConstEFH
MadlandNixEFHGetConst(ConstHandle2ConstMadlandNix self);

// +++ Get, non-const
extern_c Handle2EFH
MadlandNixEFHGet(ConstHandle2MadlandNix self);

// +++ Set
extern_c void
MadlandNixEFHSet(ConstHandle2MadlandNix self, ConstHandle2ConstEFH EFH);


// -----------------------------------------------------------------------------
// Child: T_M
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MadlandNixT_MHas(ConstHandle2ConstMadlandNix self);

// --- Get, const
extern_c Handle2ConstT_M
MadlandNixT_MGetConst(ConstHandle2ConstMadlandNix self);

// +++ Get, non-const
extern_c Handle2T_M
MadlandNixT_MGet(ConstHandle2MadlandNix self);

// +++ Set
extern_c void
MadlandNixT_MSet(ConstHandle2MadlandNix self, ConstHandle2ConstT_M T_M);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/MadlandNix/src/custom.h"

#undef extern_c
#endif
