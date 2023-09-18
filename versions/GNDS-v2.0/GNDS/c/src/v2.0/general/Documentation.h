
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
// Documentation is the basic handle type in this file. Example:
//    // Create a default Documentation object:
//    Documentation handle = DocumentationDefault();
// Functions involving Documentation are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_DOCUMENTATION
#define C_INTERFACE_GNDS_V2_0_GENERAL_DOCUMENTATION

#include "GNDStk.h"
#include "v2.0/general/Authors.h"
#include "v2.0/general/Dates.h"
#include "v2.0/general/Title.h"
#include "v2.0/general/Body.h"
#include "v2.0/general/EndfCompatible.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct DocumentationClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Documentation
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct DocumentationClass *Documentation;

// --- Const-aware handles.
typedef const struct DocumentationClass *const ConstHandle2ConstDocumentation;
typedef       struct DocumentationClass *const ConstHandle2Documentation;
typedef const struct DocumentationClass *      Handle2ConstDocumentation;
typedef       struct DocumentationClass *      Handle2Documentation;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstDocumentation
DocumentationDefaultConst();

// +++ Create, default
extern_c Handle2Documentation
DocumentationDefault();

// --- Create, general, const
extern_c Handle2ConstDocumentation
DocumentationCreateConst(
   ConstHandle2ConstAuthors authors,
   ConstHandle2ConstDates dates,
   ConstHandle2ConstTitle title,
   ConstHandle2ConstBody body,
   ConstHandle2ConstEndfCompatible endfCompatible
);

// +++ Create, general
extern_c Handle2Documentation
DocumentationCreate(
   ConstHandle2ConstAuthors authors,
   ConstHandle2ConstDates dates,
   ConstHandle2ConstTitle title,
   ConstHandle2ConstBody body,
   ConstHandle2ConstEndfCompatible endfCompatible
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
DocumentationAssign(ConstHandle2Documentation self, ConstHandle2ConstDocumentation from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
DocumentationDelete(ConstHandle2ConstDocumentation self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
DocumentationRead(ConstHandle2Documentation self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
DocumentationWrite(ConstHandle2ConstDocumentation self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
DocumentationPrint(ConstHandle2ConstDocumentation self);

// +++ Print to standard output, as XML
extern_c int
DocumentationPrintXML(ConstHandle2ConstDocumentation self);

// +++ Print to standard output, as JSON
extern_c int
DocumentationPrintJSON(ConstHandle2ConstDocumentation self);


// -----------------------------------------------------------------------------
// Child: authors
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationAuthorsHas(ConstHandle2ConstDocumentation self);

// --- Get, const
extern_c Handle2ConstAuthors
DocumentationAuthorsGetConst(ConstHandle2ConstDocumentation self);

// +++ Get
extern_c Handle2Authors
DocumentationAuthorsGet(ConstHandle2Documentation self);

// +++ Set
extern_c void
DocumentationAuthorsSet(ConstHandle2Documentation self, ConstHandle2ConstAuthors authors);


// -----------------------------------------------------------------------------
// Child: dates
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationDatesHas(ConstHandle2ConstDocumentation self);

// --- Get, const
extern_c Handle2ConstDates
DocumentationDatesGetConst(ConstHandle2ConstDocumentation self);

// +++ Get
extern_c Handle2Dates
DocumentationDatesGet(ConstHandle2Documentation self);

// +++ Set
extern_c void
DocumentationDatesSet(ConstHandle2Documentation self, ConstHandle2ConstDates dates);


// -----------------------------------------------------------------------------
// Child: title
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationTitleHas(ConstHandle2ConstDocumentation self);

// --- Get, const
extern_c Handle2ConstTitle
DocumentationTitleGetConst(ConstHandle2ConstDocumentation self);

// +++ Get
extern_c Handle2Title
DocumentationTitleGet(ConstHandle2Documentation self);

// +++ Set
extern_c void
DocumentationTitleSet(ConstHandle2Documentation self, ConstHandle2ConstTitle title);


// -----------------------------------------------------------------------------
// Child: body
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationBodyHas(ConstHandle2ConstDocumentation self);

// --- Get, const
extern_c Handle2ConstBody
DocumentationBodyGetConst(ConstHandle2ConstDocumentation self);

// +++ Get
extern_c Handle2Body
DocumentationBodyGet(ConstHandle2Documentation self);

// +++ Set
extern_c void
DocumentationBodySet(ConstHandle2Documentation self, ConstHandle2ConstBody body);


// -----------------------------------------------------------------------------
// Child: endfCompatible
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationEndfCompatibleHas(ConstHandle2ConstDocumentation self);

// --- Get, const
extern_c Handle2ConstEndfCompatible
DocumentationEndfCompatibleGetConst(ConstHandle2ConstDocumentation self);

// +++ Get
extern_c Handle2EndfCompatible
DocumentationEndfCompatibleGet(ConstHandle2Documentation self);

// +++ Set
extern_c void
DocumentationEndfCompatibleSet(ConstHandle2Documentation self, ConstHandle2ConstEndfCompatible endfCompatible);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Documentation/src/custom.h"

#undef extern_c
#endif
