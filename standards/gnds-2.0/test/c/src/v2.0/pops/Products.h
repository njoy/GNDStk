
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
// Products is the basic handle type in this file. Example:
//    // Create a default Products object:
//    Products handle = ProductsDefault();
// Functions involving Products are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_POPS_PRODUCTS
#define C_INTERFACE_TEST_V2_0_POPS_PRODUCTS

#include "GNDStk.h"
#include "v2.0/pops/Product.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ProductsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Products
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ProductsClass *Products;

// --- Const-aware handles.
typedef const struct ProductsClass *const ConstHandle2ConstProducts;
typedef       struct ProductsClass *const ConstHandle2Products;
typedef const struct ProductsClass *      Handle2ConstProducts;
typedef       struct ProductsClass *      Handle2Products;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstProducts
ProductsDefaultConst();

// +++ Create, default
extern_c Handle2Products
ProductsDefault();

// --- Create, general, const
extern_c Handle2ConstProducts
ProductsCreateConst(
   ConstHandle2Product *const product, const size_t productSize
);

// +++ Create, general
extern_c Handle2Products
ProductsCreate(
   ConstHandle2Product *const product, const size_t productSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ProductsAssign(ConstHandle2Products This, ConstHandle2ConstProducts from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ProductsDelete(ConstHandle2ConstProducts This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ProductsRead(ConstHandle2Products This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ProductsWrite(ConstHandle2ConstProducts This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ProductsPrint(ConstHandle2ConstProducts This);

// +++ Print to standard output, as XML
extern_c int
ProductsPrintXML(ConstHandle2ConstProducts This);

// +++ Print to standard output, as JSON
extern_c int
ProductsPrintJSON(ConstHandle2ConstProducts This);


// -----------------------------------------------------------------------------
// Child: product
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ProductsProductHas(ConstHandle2ConstProducts This);

// +++ Clear
extern_c void
ProductsProductClear(ConstHandle2Products This);

// +++ Size
extern_c size_t
ProductsProductSize(ConstHandle2ConstProducts This);

// +++ Add
extern_c void
ProductsProductAdd(ConstHandle2Products This, ConstHandle2ConstProduct product);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstProduct
ProductsProductGetConst(ConstHandle2ConstProducts This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Product
ProductsProductGet(ConstHandle2Products This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ProductsProductSet(
   ConstHandle2Products This,
   const size_t index_,
   ConstHandle2ConstProduct product
);

// +++ Has, by label
extern_c int
ProductsProductHasByLabel(
   ConstHandle2ConstProducts This,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstProduct
ProductsProductGetByLabelConst(
   ConstHandle2ConstProducts This,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2Product
ProductsProductGetByLabel(
   ConstHandle2Products This,
   const XMLName label
);

// +++ Set, by label
extern_c void
ProductsProductSetByLabel(
   ConstHandle2Products This,
   const XMLName label,
   ConstHandle2ConstProduct product
);

// +++ Has, by pid
extern_c int
ProductsProductHasByPid(
   ConstHandle2ConstProducts This,
   const XMLName pid
);

// --- Get, by pid, const
extern_c Handle2ConstProduct
ProductsProductGetByPidConst(
   ConstHandle2ConstProducts This,
   const XMLName pid
);

// +++ Get, by pid, non-const
extern_c Handle2Product
ProductsProductGetByPid(
   ConstHandle2Products This,
   const XMLName pid
);

// +++ Set, by pid
extern_c void
ProductsProductSetByPid(
   ConstHandle2Products This,
   const XMLName pid,
   ConstHandle2ConstProduct product
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/pops/Products/src/custom.h"

#undef extern_c
#endif
