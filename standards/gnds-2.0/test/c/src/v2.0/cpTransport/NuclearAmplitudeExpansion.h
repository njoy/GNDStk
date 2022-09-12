
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
// NuclearAmplitudeExpansion is the basic handle type in this file. Example:
//    // Create a default NuclearAmplitudeExpansion object:
//    NuclearAmplitudeExpansion handle = NuclearAmplitudeExpansionDefault();
// Functions involving NuclearAmplitudeExpansion are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_CPTRANSPORT_NUCLEARAMPLITUDEEXPANSION
#define C_INTERFACE_TEST_V2_0_CPTRANSPORT_NUCLEARAMPLITUDEEXPANSION

#include "GNDStk.h"
#include "v2.0/cpTransport/NuclearTerm.h"
#include "v2.0/cpTransport/RealInterferenceTerm.h"
#include "v2.0/cpTransport/ImaginaryInterferenceTerm.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct NuclearAmplitudeExpansionClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ NuclearAmplitudeExpansion
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct NuclearAmplitudeExpansionClass *NuclearAmplitudeExpansion;

// --- Const-aware handles.
typedef const struct NuclearAmplitudeExpansionClass *const ConstHandle2ConstNuclearAmplitudeExpansion;
typedef       struct NuclearAmplitudeExpansionClass *const ConstHandle2NuclearAmplitudeExpansion;
typedef const struct NuclearAmplitudeExpansionClass *      Handle2ConstNuclearAmplitudeExpansion;
typedef       struct NuclearAmplitudeExpansionClass *      Handle2NuclearAmplitudeExpansion;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstNuclearAmplitudeExpansion
NuclearAmplitudeExpansionDefaultConst();

// +++ Create, default
extern_c Handle2NuclearAmplitudeExpansion
NuclearAmplitudeExpansionDefault();

// --- Create, general, const
extern_c Handle2ConstNuclearAmplitudeExpansion
NuclearAmplitudeExpansionCreateConst(
   ConstHandle2ConstNuclearTerm nuclearTerm,
   ConstHandle2ConstRealInterferenceTerm realInterferenceTerm,
   ConstHandle2ConstImaginaryInterferenceTerm imaginaryInterferenceTerm
);

// +++ Create, general
extern_c Handle2NuclearAmplitudeExpansion
NuclearAmplitudeExpansionCreate(
   ConstHandle2ConstNuclearTerm nuclearTerm,
   ConstHandle2ConstRealInterferenceTerm realInterferenceTerm,
   ConstHandle2ConstImaginaryInterferenceTerm imaginaryInterferenceTerm
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
NuclearAmplitudeExpansionAssign(ConstHandle2NuclearAmplitudeExpansion This, ConstHandle2ConstNuclearAmplitudeExpansion from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
NuclearAmplitudeExpansionDelete(ConstHandle2ConstNuclearAmplitudeExpansion This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
NuclearAmplitudeExpansionRead(ConstHandle2NuclearAmplitudeExpansion This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
NuclearAmplitudeExpansionWrite(ConstHandle2ConstNuclearAmplitudeExpansion This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
NuclearAmplitudeExpansionPrint(ConstHandle2ConstNuclearAmplitudeExpansion This);

// +++ Print to standard output, as XML
extern_c int
NuclearAmplitudeExpansionPrintXML(ConstHandle2ConstNuclearAmplitudeExpansion This);

// +++ Print to standard output, as JSON
extern_c int
NuclearAmplitudeExpansionPrintJSON(ConstHandle2ConstNuclearAmplitudeExpansion This);


// -----------------------------------------------------------------------------
// Child: nuclearTerm
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclearAmplitudeExpansionNuclearTermHas(ConstHandle2ConstNuclearAmplitudeExpansion This);

// --- Get, const
extern_c Handle2ConstNuclearTerm
NuclearAmplitudeExpansionNuclearTermGetConst(ConstHandle2ConstNuclearAmplitudeExpansion This);

// +++ Get, non-const
extern_c Handle2NuclearTerm
NuclearAmplitudeExpansionNuclearTermGet(ConstHandle2NuclearAmplitudeExpansion This);

// +++ Set
extern_c void
NuclearAmplitudeExpansionNuclearTermSet(ConstHandle2NuclearAmplitudeExpansion This, ConstHandle2ConstNuclearTerm nuclearTerm);


// -----------------------------------------------------------------------------
// Child: realInterferenceTerm
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclearAmplitudeExpansionRealInterferenceTermHas(ConstHandle2ConstNuclearAmplitudeExpansion This);

// --- Get, const
extern_c Handle2ConstRealInterferenceTerm
NuclearAmplitudeExpansionRealInterferenceTermGetConst(ConstHandle2ConstNuclearAmplitudeExpansion This);

// +++ Get, non-const
extern_c Handle2RealInterferenceTerm
NuclearAmplitudeExpansionRealInterferenceTermGet(ConstHandle2NuclearAmplitudeExpansion This);

// +++ Set
extern_c void
NuclearAmplitudeExpansionRealInterferenceTermSet(ConstHandle2NuclearAmplitudeExpansion This, ConstHandle2ConstRealInterferenceTerm realInterferenceTerm);


// -----------------------------------------------------------------------------
// Child: imaginaryInterferenceTerm
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclearAmplitudeExpansionImaginaryInterferenceTermHas(ConstHandle2ConstNuclearAmplitudeExpansion This);

// --- Get, const
extern_c Handle2ConstImaginaryInterferenceTerm
NuclearAmplitudeExpansionImaginaryInterferenceTermGetConst(ConstHandle2ConstNuclearAmplitudeExpansion This);

// +++ Get, non-const
extern_c Handle2ImaginaryInterferenceTerm
NuclearAmplitudeExpansionImaginaryInterferenceTermGet(ConstHandle2NuclearAmplitudeExpansion This);

// +++ Set
extern_c void
NuclearAmplitudeExpansionImaginaryInterferenceTermSet(ConstHandle2NuclearAmplitudeExpansion This, ConstHandle2ConstImaginaryInterferenceTerm imaginaryInterferenceTerm);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif