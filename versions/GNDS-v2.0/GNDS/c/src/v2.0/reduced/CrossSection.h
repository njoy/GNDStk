
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
// CrossSection is the basic handle type in this file. Example:
//    // Create a default CrossSection object:
//    CrossSection handle = CrossSectionDefault();
// Functions involving CrossSection are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_REDUCED_CROSSSECTION
#define C_INTERFACE_GNDS_V2_0_REDUCED_CROSSSECTION

#include "GNDStk.h"
#include "v2.0/general/XYs1d.h"
#include "v2.0/general/Regions1d.h"
#include "v2.0/general/Reference.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct CrossSectionClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ CrossSection
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct CrossSectionClass *CrossSection;

// --- Const-aware handles.
typedef const struct CrossSectionClass *const ConstHandle2ConstCrossSection;
typedef       struct CrossSectionClass *const ConstHandle2CrossSection;
typedef const struct CrossSectionClass *      Handle2ConstCrossSection;
typedef       struct CrossSectionClass *      Handle2CrossSection;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstCrossSection
CrossSectionDefaultConst();

// +++ Create, default
extern_c Handle2CrossSection
CrossSectionDefault();

// --- Create, general, const
extern_c Handle2ConstCrossSection
CrossSectionCreateConst(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d,
   ConstHandle2ConstReference reference
);

// +++ Create, general
extern_c Handle2CrossSection
CrossSectionCreate(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d,
   ConstHandle2ConstReference reference
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
CrossSectionAssign(ConstHandle2CrossSection self, ConstHandle2ConstCrossSection from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
CrossSectionDelete(ConstHandle2ConstCrossSection self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
CrossSectionRead(ConstHandle2CrossSection self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
CrossSectionWrite(ConstHandle2ConstCrossSection self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
CrossSectionPrint(ConstHandle2ConstCrossSection self);

// +++ Print to standard output, as XML
extern_c int
CrossSectionPrintXML(ConstHandle2ConstCrossSection self);

// +++ Print to standard output, as JSON
extern_c int
CrossSectionPrintJSON(ConstHandle2ConstCrossSection self);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CrossSectionXYs1dHas(ConstHandle2ConstCrossSection self);

// --- Get, const
extern_c Handle2ConstXYs1d
CrossSectionXYs1dGetConst(ConstHandle2ConstCrossSection self);

// +++ Get
extern_c Handle2XYs1d
CrossSectionXYs1dGet(ConstHandle2CrossSection self);

// +++ Set
extern_c void
CrossSectionXYs1dSet(ConstHandle2CrossSection self, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Child: regions1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CrossSectionRegions1dHas(ConstHandle2ConstCrossSection self);

// --- Get, const
extern_c Handle2ConstRegions1d
CrossSectionRegions1dGetConst(ConstHandle2ConstCrossSection self);

// +++ Get
extern_c Handle2Regions1d
CrossSectionRegions1dGet(ConstHandle2CrossSection self);

// +++ Set
extern_c void
CrossSectionRegions1dSet(ConstHandle2CrossSection self, ConstHandle2ConstRegions1d regions1d);


// -----------------------------------------------------------------------------
// Child: reference
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CrossSectionReferenceHas(ConstHandle2ConstCrossSection self);

// --- Get, const
extern_c Handle2ConstReference
CrossSectionReferenceGetConst(ConstHandle2ConstCrossSection self);

// +++ Get
extern_c Handle2Reference
CrossSectionReferenceGet(ConstHandle2CrossSection self);

// +++ Set
extern_c void
CrossSectionReferenceSet(ConstHandle2CrossSection self, ConstHandle2ConstReference reference);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/reduced/CrossSection/src/custom.h"

#undef extern_c
#endif
