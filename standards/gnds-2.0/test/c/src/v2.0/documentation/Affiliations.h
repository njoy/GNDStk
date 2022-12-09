
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
// Affiliations is the basic handle type in this file. Example:
//    // Create a default Affiliations object:
//    Affiliations handle = AffiliationsDefault();
// Functions involving Affiliations are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_DOCUMENTATION_AFFILIATIONS
#define C_INTERFACE_TEST_V2_0_DOCUMENTATION_AFFILIATIONS

#include "GNDStk.h"
#include "v2.0/documentation/Affiliation.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AffiliationsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Affiliations
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AffiliationsClass *Affiliations;

// --- Const-aware handles.
typedef const struct AffiliationsClass *const ConstHandle2ConstAffiliations;
typedef       struct AffiliationsClass *const ConstHandle2Affiliations;
typedef const struct AffiliationsClass *      Handle2ConstAffiliations;
typedef       struct AffiliationsClass *      Handle2Affiliations;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAffiliations
AffiliationsDefaultConst();

// +++ Create, default
extern_c Handle2Affiliations
AffiliationsDefault();

// --- Create, general, const
extern_c Handle2ConstAffiliations
AffiliationsCreateConst(
   ConstHandle2Affiliation *const affiliation, const size_t affiliationSize
);

// +++ Create, general
extern_c Handle2Affiliations
AffiliationsCreate(
   ConstHandle2Affiliation *const affiliation, const size_t affiliationSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AffiliationsAssign(ConstHandle2Affiliations This, ConstHandle2ConstAffiliations from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AffiliationsDelete(ConstHandle2ConstAffiliations This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AffiliationsRead(ConstHandle2Affiliations This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AffiliationsWrite(ConstHandle2ConstAffiliations This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AffiliationsPrint(ConstHandle2ConstAffiliations This);

// +++ Print to standard output, as XML
extern_c int
AffiliationsPrintXML(ConstHandle2ConstAffiliations This);

// +++ Print to standard output, as JSON
extern_c int
AffiliationsPrintJSON(ConstHandle2ConstAffiliations This);


// -----------------------------------------------------------------------------
// Child: affiliation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AffiliationsAffiliationHas(ConstHandle2ConstAffiliations This);

// +++ Clear
extern_c void
AffiliationsAffiliationClear(ConstHandle2Affiliations This);

// +++ Size
extern_c size_t
AffiliationsAffiliationSize(ConstHandle2ConstAffiliations This);

// +++ Add
extern_c void
AffiliationsAffiliationAdd(ConstHandle2Affiliations This, ConstHandle2ConstAffiliation affiliation);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstAffiliation
AffiliationsAffiliationGetConst(ConstHandle2ConstAffiliations This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Affiliation
AffiliationsAffiliationGet(ConstHandle2Affiliations This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
AffiliationsAffiliationSet(
   ConstHandle2Affiliations This,
   const size_t index_,
   ConstHandle2ConstAffiliation affiliation
);

// +++ Has, by name
extern_c int
AffiliationsAffiliationHasByName(
   ConstHandle2ConstAffiliations This,
   const UTF8Text name
);

// --- Get, by name, const
extern_c Handle2ConstAffiliation
AffiliationsAffiliationGetByNameConst(
   ConstHandle2ConstAffiliations This,
   const UTF8Text name
);

// +++ Get, by name, non-const
extern_c Handle2Affiliation
AffiliationsAffiliationGetByName(
   ConstHandle2Affiliations This,
   const UTF8Text name
);

// +++ Set, by name
extern_c void
AffiliationsAffiliationSetByName(
   ConstHandle2Affiliations This,
   const UTF8Text name,
   ConstHandle2ConstAffiliation affiliation
);

// +++ Has, by href
extern_c int
AffiliationsAffiliationHasByHref(
   ConstHandle2ConstAffiliations This,
   const UTF8Text href
);

// --- Get, by href, const
extern_c Handle2ConstAffiliation
AffiliationsAffiliationGetByHrefConst(
   ConstHandle2ConstAffiliations This,
   const UTF8Text href
);

// +++ Get, by href, non-const
extern_c Handle2Affiliation
AffiliationsAffiliationGetByHref(
   ConstHandle2Affiliations This,
   const UTF8Text href
);

// +++ Set, by href
extern_c void
AffiliationsAffiliationSetByHref(
   ConstHandle2Affiliations This,
   const UTF8Text href,
   ConstHandle2ConstAffiliation affiliation
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
