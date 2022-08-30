
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
// Parity is the basic handle type in this file. Example:
//    // Create a default Parity object:
//    Parity handle = ParityDefault();
// Functions involving Parity are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_POPS_PARITY
#define C_INTERFACE_TRY_V2_0_POPS_PARITY

#include "GNDStk.h"
#include "v2.0/documentation/Documentation.h"
#include "v2.0/pops/Uncertainty.h"
#include "v2.0/containers/Integer.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ParityClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Parity
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ParityClass *Parity;

// --- Const-aware handles.
typedef const struct ParityClass *const ConstHandle2ConstParity;
typedef       struct ParityClass *const ConstHandle2Parity;
typedef const struct ParityClass *      Handle2ConstParity;
typedef       struct ParityClass *      Handle2Parity;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstParity
ParityDefaultConst();

// +++ Create, default
extern_c Handle2Parity
ParityDefault();

// --- Create, general, const
extern_c Handle2ConstParity
ParityCreateConst(
   const XMLName label,
   const XMLName unit,
   const XMLName value,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2Integer *const integer, const size_t integerSize
);

// +++ Create, general
extern_c Handle2Parity
ParityCreate(
   const XMLName label,
   const XMLName unit,
   const XMLName value,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2Integer *const integer, const size_t integerSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ParityAssign(ConstHandle2Parity This, ConstHandle2ConstParity from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ParityDelete(ConstHandle2ConstParity This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ParityRead(ConstHandle2Parity This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ParityWrite(ConstHandle2ConstParity This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ParityPrint(ConstHandle2ConstParity This);

// +++ Print to standard output, as XML
extern_c int
ParityPrintXML(ConstHandle2ConstParity This);

// +++ Print to standard output, as JSON
extern_c int
ParityPrintJSON(ConstHandle2ConstParity This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ParityLabelHas(ConstHandle2ConstParity This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ParityLabelGet(ConstHandle2ConstParity This);

// +++ Set
extern_c void
ParityLabelSet(ConstHandle2Parity This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ParityUnitHas(ConstHandle2ConstParity This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ParityUnitGet(ConstHandle2ConstParity This);

// +++ Set
extern_c void
ParityUnitSet(ConstHandle2Parity This, const XMLName unit);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ParityValueHas(ConstHandle2ConstParity This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ParityValueGet(ConstHandle2ConstParity This);

// +++ Set
extern_c void
ParityValueSet(ConstHandle2Parity This, const XMLName value);


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ParityDocumentationHas(ConstHandle2ConstParity This);

// --- Get, const
extern_c Handle2ConstDocumentation
ParityDocumentationGetConst(ConstHandle2ConstParity This);

// +++ Get, non-const
extern_c Handle2Documentation
ParityDocumentationGet(ConstHandle2Parity This);

// +++ Set
extern_c void
ParityDocumentationSet(ConstHandle2Parity This, ConstHandle2ConstDocumentation documentation);


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ParityUncertaintyHas(ConstHandle2ConstParity This);

// --- Get, const
extern_c Handle2ConstUncertainty
ParityUncertaintyGetConst(ConstHandle2ConstParity This);

// +++ Get, non-const
extern_c Handle2Uncertainty
ParityUncertaintyGet(ConstHandle2Parity This);

// +++ Set
extern_c void
ParityUncertaintySet(ConstHandle2Parity This, ConstHandle2ConstUncertainty uncertainty);


// -----------------------------------------------------------------------------
// Child: integer
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ParityIntegerHas(ConstHandle2ConstParity This);

// +++ Clear
extern_c void
ParityIntegerClear(ConstHandle2Parity This);

// +++ Size
extern_c size_t
ParityIntegerSize(ConstHandle2ConstParity This);

// +++ Add
extern_c void
ParityIntegerAdd(ConstHandle2Parity This, ConstHandle2ConstInteger integer);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstInteger
ParityIntegerGetConst(ConstHandle2ConstParity This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Integer
ParityIntegerGet(ConstHandle2Parity This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ParityIntegerSet(
   ConstHandle2Parity This,
   const size_t index_,
   ConstHandle2ConstInteger integer
);

// +++ Has, by label
extern_c int
ParityIntegerHasByLabel(
   ConstHandle2ConstParity This,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstInteger
ParityIntegerGetByLabelConst(
   ConstHandle2ConstParity This,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2Integer
ParityIntegerGetByLabel(
   ConstHandle2Parity This,
   const XMLName label
);

// +++ Set, by label
extern_c void
ParityIntegerSetByLabel(
   ConstHandle2Parity This,
   const XMLName label,
   ConstHandle2ConstInteger integer
);

// +++ Has, by unit
extern_c int
ParityIntegerHasByUnit(
   ConstHandle2ConstParity This,
   const XMLName unit
);

// --- Get, by unit, const
extern_c Handle2ConstInteger
ParityIntegerGetByUnitConst(
   ConstHandle2ConstParity This,
   const XMLName unit
);

// +++ Get, by unit, non-const
extern_c Handle2Integer
ParityIntegerGetByUnit(
   ConstHandle2Parity This,
   const XMLName unit
);

// +++ Set, by unit
extern_c void
ParityIntegerSetByUnit(
   ConstHandle2Parity This,
   const XMLName unit,
   ConstHandle2ConstInteger integer
);

// +++ Has, by value
extern_c int
ParityIntegerHasByValue(
   ConstHandle2ConstParity This,
   const Integer32 value
);

// --- Get, by value, const
extern_c Handle2ConstInteger
ParityIntegerGetByValueConst(
   ConstHandle2ConstParity This,
   const Integer32 value
);

// +++ Get, by value, non-const
extern_c Handle2Integer
ParityIntegerGetByValue(
   ConstHandle2Parity This,
   const Integer32 value
);

// +++ Set, by value
extern_c void
ParityIntegerSetByValue(
   ConstHandle2Parity This,
   const Integer32 value,
   ConstHandle2ConstInteger integer
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
