
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
// InternalConversionCoefficients is the basic handle type in this file. Example:
//    // Create a default InternalConversionCoefficients object:
//    InternalConversionCoefficients handle = InternalConversionCoefficientsDefault();
// Functions involving InternalConversionCoefficients are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_POPS_INTERNALCONVERSIONCOEFFICIENTS
#define C_INTERFACE_TRY_V2_0_POPS_INTERNALCONVERSIONCOEFFICIENTS

#include "GNDStk.h"
#include "v2.0/pops/Shell.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct InternalConversionCoefficientsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ InternalConversionCoefficients
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct InternalConversionCoefficientsClass *InternalConversionCoefficients;

// --- Const-aware handles.
typedef const struct InternalConversionCoefficientsClass *const ConstHandle2ConstInternalConversionCoefficients;
typedef       struct InternalConversionCoefficientsClass *const ConstHandle2InternalConversionCoefficients;
typedef const struct InternalConversionCoefficientsClass *      Handle2ConstInternalConversionCoefficients;
typedef       struct InternalConversionCoefficientsClass *      Handle2InternalConversionCoefficients;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstInternalConversionCoefficients
InternalConversionCoefficientsDefaultConst();

// +++ Create, default
extern_c Handle2InternalConversionCoefficients
InternalConversionCoefficientsDefault();

// --- Create, general, const
extern_c Handle2ConstInternalConversionCoefficients
InternalConversionCoefficientsCreateConst(
   ConstHandle2Shell *const shell, const size_t shellSize
);

// +++ Create, general
extern_c Handle2InternalConversionCoefficients
InternalConversionCoefficientsCreate(
   ConstHandle2Shell *const shell, const size_t shellSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
InternalConversionCoefficientsAssign(ConstHandle2InternalConversionCoefficients This, ConstHandle2ConstInternalConversionCoefficients from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
InternalConversionCoefficientsDelete(ConstHandle2ConstInternalConversionCoefficients This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
InternalConversionCoefficientsRead(ConstHandle2InternalConversionCoefficients This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
InternalConversionCoefficientsWrite(ConstHandle2ConstInternalConversionCoefficients This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
InternalConversionCoefficientsPrint(ConstHandle2ConstInternalConversionCoefficients This);

// +++ Print to standard output, as XML
extern_c int
InternalConversionCoefficientsPrintXML(ConstHandle2ConstInternalConversionCoefficients This);

// +++ Print to standard output, as JSON
extern_c int
InternalConversionCoefficientsPrintJSON(ConstHandle2ConstInternalConversionCoefficients This);


// -----------------------------------------------------------------------------
// Child: shell
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
InternalConversionCoefficientsShellHas(ConstHandle2ConstInternalConversionCoefficients This);

// +++ Clear
extern_c void
InternalConversionCoefficientsShellClear(ConstHandle2InternalConversionCoefficients This);

// +++ Size
extern_c size_t
InternalConversionCoefficientsShellSize(ConstHandle2ConstInternalConversionCoefficients This);

// +++ Add
extern_c void
InternalConversionCoefficientsShellAdd(ConstHandle2InternalConversionCoefficients This, ConstHandle2ConstShell shell);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstShell
InternalConversionCoefficientsShellGetConst(ConstHandle2ConstInternalConversionCoefficients This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Shell
InternalConversionCoefficientsShellGet(ConstHandle2InternalConversionCoefficients This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
InternalConversionCoefficientsShellSet(
   ConstHandle2InternalConversionCoefficients This,
   const size_t index_,
   ConstHandle2ConstShell shell
);

// +++ Has, by label
extern_c int
InternalConversionCoefficientsShellHasByLabel(
   ConstHandle2ConstInternalConversionCoefficients This,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstShell
InternalConversionCoefficientsShellGetByLabelConst(
   ConstHandle2ConstInternalConversionCoefficients This,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2Shell
InternalConversionCoefficientsShellGetByLabel(
   ConstHandle2InternalConversionCoefficients This,
   const XMLName label
);

// +++ Set, by label
extern_c void
InternalConversionCoefficientsShellSetByLabel(
   ConstHandle2InternalConversionCoefficients This,
   const XMLName label,
   ConstHandle2ConstShell shell
);

// +++ Has, by value
extern_c int
InternalConversionCoefficientsShellHasByValue(
   ConstHandle2ConstInternalConversionCoefficients This,
   const Float64 value
);

// --- Get, by value, const
extern_c Handle2ConstShell
InternalConversionCoefficientsShellGetByValueConst(
   ConstHandle2ConstInternalConversionCoefficients This,
   const Float64 value
);

// +++ Get, by value, non-const
extern_c Handle2Shell
InternalConversionCoefficientsShellGetByValue(
   ConstHandle2InternalConversionCoefficients This,
   const Float64 value
);

// +++ Set, by value
extern_c void
InternalConversionCoefficientsShellSetByValue(
   ConstHandle2InternalConversionCoefficients This,
   const Float64 value,
   ConstHandle2ConstShell shell
);

// +++ Has, by unit
extern_c int
InternalConversionCoefficientsShellHasByUnit(
   ConstHandle2ConstInternalConversionCoefficients This,
   const XMLName unit
);

// --- Get, by unit, const
extern_c Handle2ConstShell
InternalConversionCoefficientsShellGetByUnitConst(
   ConstHandle2ConstInternalConversionCoefficients This,
   const XMLName unit
);

// +++ Get, by unit, non-const
extern_c Handle2Shell
InternalConversionCoefficientsShellGetByUnit(
   ConstHandle2InternalConversionCoefficients This,
   const XMLName unit
);

// +++ Set, by unit
extern_c void
InternalConversionCoefficientsShellSetByUnit(
   ConstHandle2InternalConversionCoefficients This,
   const XMLName unit,
   ConstHandle2ConstShell shell
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
