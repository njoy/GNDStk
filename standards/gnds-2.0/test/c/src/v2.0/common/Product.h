
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
// Product is the basic handle type in this file. Example:
//    // Create a default Product object:
//    Product handle = ProductDefault();
// Functions involving Product are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_COMMON_PRODUCT
#define C_INTERFACE_TEST_V2_0_COMMON_PRODUCT

#include "GNDStk.h"
#include "v2.0/transport/Multiplicity.h"
#include "v2.0/transport/Distribution.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ProductClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Product
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ProductClass *Product;

// --- Const-aware handles.
typedef const struct ProductClass *const ConstHandle2ConstProduct;
typedef       struct ProductClass *const ConstHandle2Product;
typedef const struct ProductClass *      Handle2ConstProduct;
typedef       struct ProductClass *      Handle2Product;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstProduct
ProductDefaultConst();

// +++ Create, default
extern_c Handle2Product
ProductDefault();

// --- Create, general, const
extern_c Handle2ConstProduct
ProductCreateConst(
   const XMLName label,
   const XMLName pid,
   ConstHandle2ConstMultiplicity multiplicity,
   ConstHandle2ConstDistribution distribution
);

// +++ Create, general
extern_c Handle2Product
ProductCreate(
   const XMLName label,
   const XMLName pid,
   ConstHandle2ConstMultiplicity multiplicity,
   ConstHandle2ConstDistribution distribution
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ProductAssign(ConstHandle2Product This, ConstHandle2ConstProduct from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ProductDelete(ConstHandle2ConstProduct This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ProductRead(ConstHandle2Product This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ProductWrite(ConstHandle2ConstProduct This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ProductPrint(ConstHandle2ConstProduct This);

// +++ Print to standard output, as XML
extern_c int
ProductPrintXML(ConstHandle2ConstProduct This);

// +++ Print to standard output, as JSON
extern_c int
ProductPrintJSON(ConstHandle2ConstProduct This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ProductLabelHas(ConstHandle2ConstProduct This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ProductLabelGet(ConstHandle2ConstProduct This);

// +++ Set
extern_c void
ProductLabelSet(ConstHandle2Product This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: pid
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ProductPidHas(ConstHandle2ConstProduct This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ProductPidGet(ConstHandle2ConstProduct This);

// +++ Set
extern_c void
ProductPidSet(ConstHandle2Product This, const XMLName pid);


// -----------------------------------------------------------------------------
// Child: multiplicity
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ProductMultiplicityHas(ConstHandle2ConstProduct This);

// --- Get, const
extern_c Handle2ConstMultiplicity
ProductMultiplicityGetConst(ConstHandle2ConstProduct This);

// +++ Get, non-const
extern_c Handle2Multiplicity
ProductMultiplicityGet(ConstHandle2Product This);

// +++ Set
extern_c void
ProductMultiplicitySet(ConstHandle2Product This, ConstHandle2ConstMultiplicity multiplicity);


// -----------------------------------------------------------------------------
// Child: distribution
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ProductDistributionHas(ConstHandle2ConstProduct This);

// --- Get, const
extern_c Handle2ConstDistribution
ProductDistributionGetConst(ConstHandle2ConstProduct This);

// +++ Get, non-const
extern_c Handle2Distribution
ProductDistributionGet(ConstHandle2Product This);

// +++ Set
extern_c void
ProductDistributionSet(ConstHandle2Product This, ConstHandle2ConstDistribution distribution);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
